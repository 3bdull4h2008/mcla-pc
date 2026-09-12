#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_823C0594"))) PPC_WEAK_FUNC(sub_823C0594);
PPC_FUNC_IMPL(__imp__sub_823C0594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C0598"))) PPC_WEAK_FUNC(sub_823C0598);
PPC_FUNC_IMPL(__imp__sub_823C0598) {
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
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x823ca198
	ctx.lr = 0x823C05C4;
	sub_823CA198(ctx, base);
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

__attribute__((alias("__imp__sub_823C05E4"))) PPC_WEAK_FUNC(sub_823C05E4);
PPC_FUNC_IMPL(__imp__sub_823C05E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C05E8"))) PPC_WEAK_FUNC(sub_823C05E8);
PPC_FUNC_IMPL(__imp__sub_823C05E8) {
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
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x823ca8b0
	ctx.lr = 0x823C0614;
	sub_823CA8B0(ctx, base);
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

__attribute__((alias("__imp__sub_823C0634"))) PPC_WEAK_FUNC(sub_823C0634);
PPC_FUNC_IMPL(__imp__sub_823C0634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C0638"))) PPC_WEAK_FUNC(sub_823C0638);
PPC_FUNC_IMPL(__imp__sub_823C0638) {
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
	ctx.lr = 0x823C0640;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r31,1
	r31.s64 = 1;
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r26,4(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823c0690
	if (cr6.eq) goto loc_823C0690;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823bba48
	ctx.lr = 0x823C0678;
	sub_823BBA48(ctx, base);
	// lwz r11,-4960(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823ca8b0
	ctx.lr = 0x823C068C;
	sub_823CA8B0(ctx, base);
	// clrlwi r31,r3,31
	r31.u64 = ctx.r3.u32 & 0x1;
loc_823C0690:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823ca8b0
	ctx.lr = 0x823C06A0;
	sub_823CA8B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// and r8,r11,r10
	ctx.r8.u64 = r11.u64 & ctx.r10.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823C06C0"))) PPC_WEAK_FUNC(sub_823C06C0);
PPC_FUNC_IMPL(__imp__sub_823C06C0) {
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
	ctx.lr = 0x823C06C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r31,1
	r31.s64 = 1;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r27,4(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// beq cr6,0x823c0708
	if (cr6.eq) goto loc_823C0708;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c0708
	if (cr6.eq) goto loc_823C0708;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// bl 0x823ca8b0
	ctx.lr = 0x823C0704;
	sub_823CA8B0(ctx, base);
	// clrlwi r31,r3,31
	r31.u64 = ctx.r3.u32 & 0x1;
loc_823C0708:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823ca8b0
	ctx.lr = 0x823C0718;
	sub_823CA8B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// and r8,r11,r10
	ctx.r8.u64 = r11.u64 & ctx.r10.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823C0738"))) PPC_WEAK_FUNC(sub_823C0738);
PPC_FUNC_IMPL(__imp__sub_823C0738) {
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
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x823bf5f0
	ctx.lr = 0x823C076C;
	sub_823BF5F0(ctx, base);
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

__attribute__((alias("__imp__sub_823C0788"))) PPC_WEAK_FUNC(sub_823C0788);
PPC_FUNC_IMPL(__imp__sub_823C0788) {
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
	// bl 0x823bf3b8
	ctx.lr = 0x823C07B4;
	sub_823BF3B8(ctx, base);
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

__attribute__((alias("__imp__sub_823C07D4"))) PPC_WEAK_FUNC(sub_823C07D4);
PPC_FUNC_IMPL(__imp__sub_823C07D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C07D8"))) PPC_WEAK_FUNC(sub_823C07D8);
PPC_FUNC_IMPL(__imp__sub_823C07D8) {
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
	// bl 0x823bf4a8
	ctx.lr = 0x823C0804;
	sub_823BF4A8(ctx, base);
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

__attribute__((alias("__imp__sub_823C0824"))) PPC_WEAK_FUNC(sub_823C0824);
PPC_FUNC_IMPL(__imp__sub_823C0824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C0828"))) PPC_WEAK_FUNC(sub_823C0828);
PPC_FUNC_IMPL(__imp__sub_823C0828) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x823C0830;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r31,48(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r30,44(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r29,40(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r28,36(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r27,32(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r26,28(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r3,-4960(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4960);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r29.u32);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// bl 0x823cab80
	ctx.lr = 0x823C0890;
	sub_823CAB80(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823C0898"))) PPC_WEAK_FUNC(sub_823C0898);
PPC_FUNC_IMPL(__imp__sub_823C0898) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x823cafd8
	sub_823CAFD8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C08BC"))) PPC_WEAK_FUNC(sub_823C08BC);
PPC_FUNC_IMPL(__imp__sub_823C08BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C08C0"))) PPC_WEAK_FUNC(sub_823C08C0);
PPC_FUNC_IMPL(__imp__sub_823C08C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823bf7b0
	sub_823BF7B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C08CC"))) PPC_WEAK_FUNC(sub_823C08CC);
PPC_FUNC_IMPL(__imp__sub_823C08CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C08D0"))) PPC_WEAK_FUNC(sub_823C08D0);
PPC_FUNC_IMPL(__imp__sub_823C08D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823bf8f0
	sub_823BF8F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C08DC"))) PPC_WEAK_FUNC(sub_823C08DC);
PPC_FUNC_IMPL(__imp__sub_823C08DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C08E0"))) PPC_WEAK_FUNC(sub_823C08E0);
PPC_FUNC_IMPL(__imp__sub_823C08E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823bfa18
	sub_823BFA18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C08EC"))) PPC_WEAK_FUNC(sub_823C08EC);
PPC_FUNC_IMPL(__imp__sub_823C08EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C08F0"))) PPC_WEAK_FUNC(sub_823C08F0);
PPC_FUNC_IMPL(__imp__sub_823C08F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823bc4e0
	sub_823BC4E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C0900"))) PPC_WEAK_FUNC(sub_823C0900);
PPC_FUNC_IMPL(__imp__sub_823C0900) {
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
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r4,r7,24
	ctx.r4.u64 = ctx.r7.u32 & 0xFF;
	// bl 0x823bc348
	ctx.lr = 0x823C0934;
	sub_823BC348(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_823C0950"))) PPC_WEAK_FUNC(sub_823C0950);
PPC_FUNC_IMPL(__imp__sub_823C0950) {
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
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r4,r7,24
	ctx.r4.u64 = ctx.r7.u32 & 0xFF;
	// bl 0x823bc268
	ctx.lr = 0x823C0984;
	sub_823BC268(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_823C09A0"))) PPC_WEAK_FUNC(sub_823C09A0);
PPC_FUNC_IMPL(__imp__sub_823C09A0) {
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
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27436(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27436);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// bl 0x823d3df8
	ctx.lr = 0x823C09DC;
	sub_823D3DF8(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// stw r4,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r4.u32);
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

__attribute__((alias("__imp__sub_823C09FC"))) PPC_WEAK_FUNC(sub_823C09FC);
PPC_FUNC_IMPL(__imp__sub_823C09FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C0A00"))) PPC_WEAK_FUNC(sub_823C0A00);
PPC_FUNC_IMPL(__imp__sub_823C0A00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-27436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27436);
	// b 0x823d3818
	sub_823D3818(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C0A10"))) PPC_WEAK_FUNC(sub_823C0A10);
PPC_FUNC_IMPL(__imp__sub_823C0A10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-27436(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27436);
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823c0a30
	if (cr6.eq) goto loc_823C0A30;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x823c0a34
	if (!cr6.eq) goto loc_823C0A34;
loc_823C0A30:
	// li r11,1
	r11.s64 = 1;
loc_823C0A34:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C0A44"))) PPC_WEAK_FUNC(sub_823C0A44);
PPC_FUNC_IMPL(__imp__sub_823C0A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C0A48"))) PPC_WEAK_FUNC(sub_823C0A48);
PPC_FUNC_IMPL(__imp__sub_823C0A48) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27432);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x823d5c60
	ctx.lr = 0x823C0A74;
	sub_823D5C60(ctx, base);
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

__attribute__((alias("__imp__sub_823C0A94"))) PPC_WEAK_FUNC(sub_823C0A94);
PPC_FUNC_IMPL(__imp__sub_823C0A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C0A98"))) PPC_WEAK_FUNC(sub_823C0A98);
PPC_FUNC_IMPL(__imp__sub_823C0A98) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27432);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x823d5f60
	ctx.lr = 0x823C0AC4;
	sub_823D5F60(ctx, base);
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

__attribute__((alias("__imp__sub_823C0AE4"))) PPC_WEAK_FUNC(sub_823C0AE4);
PPC_FUNC_IMPL(__imp__sub_823C0AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C0AE8"))) PPC_WEAK_FUNC(sub_823C0AE8);
PPC_FUNC_IMPL(__imp__sub_823C0AE8) {
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
	ctx.lr = 0x823C0AF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r29,-32120
	r29.s64 = -2105016320;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r31,336(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r31,1
	ctx.r9.s64 = r31.s64 + 1;
	// lwz r28,4(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r9.u32);
	// lwz r3,-27432(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -27432);
	// bl 0x823d6478
	ctx.lr = 0x823C0B24;
	sub_823D6478(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c0b48
	if (cr6.eq) goto loc_823C0B48;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-27432(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -27432);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823d4a30
	ctx.lr = 0x823C0B48;
	sub_823D4A30(ctx, base);
loc_823C0B48:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823C0B58"))) PPC_WEAK_FUNC(sub_823C0B58);
PPC_FUNC_IMPL(__imp__sub_823C0B58) {
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
	ctx.lr = 0x823C0B60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r29,-32120
	r29.s64 = -2105016320;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r31,336(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r31,1
	ctx.r9.s64 = r31.s64 + 1;
	// stw r9,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r9.u32);
	// lwz r3,-27432(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -27432);
	// bl 0x823d6478
	ctx.lr = 0x823C0B90;
	sub_823D6478(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c0bb8
	if (cr6.eq) goto loc_823C0BB8;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-27432(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -27432);
	// addi r6,r11,36
	ctx.r6.s64 = r11.s64 + 36;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823d4a30
	ctx.lr = 0x823C0BB8;
	sub_823D4A30(ctx, base);
loc_823C0BB8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823C0BC8"))) PPC_WEAK_FUNC(sub_823C0BC8);
PPC_FUNC_IMPL(__imp__sub_823C0BC8) {
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
	// bl 0x823bc650
	ctx.lr = 0x823C0BE8;
	sub_823BC650(ctx, base);
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

__attribute__((alias("__imp__sub_823C0C08"))) PPC_WEAK_FUNC(sub_823C0C08);
PPC_FUNC_IMPL(__imp__sub_823C0C08) {
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
	// bl 0x823bc6e0
	ctx.lr = 0x823C0C28;
	sub_823BC6E0(ctx, base);
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

__attribute__((alias("__imp__sub_823C0C48"))) PPC_WEAK_FUNC(sub_823C0C48);
PPC_FUNC_IMPL(__imp__sub_823C0C48) {
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
	// bl 0x823bc8c0
	ctx.lr = 0x823C0C6C;
	sub_823BC8C0(ctx, base);
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

__attribute__((alias("__imp__sub_823C0C8C"))) PPC_WEAK_FUNC(sub_823C0C8C);
PPC_FUNC_IMPL(__imp__sub_823C0C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C0C90"))) PPC_WEAK_FUNC(sub_823C0C90);
PPC_FUNC_IMPL(__imp__sub_823C0C90) {
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
	// bl 0x823bc998
	ctx.lr = 0x823C0CB0;
	sub_823BC998(ctx, base);
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

__attribute__((alias("__imp__sub_823C0CD0"))) PPC_WEAK_FUNC(sub_823C0CD0);
PPC_FUNC_IMPL(__imp__sub_823C0CD0) {
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
	// bl 0x823bca28
	ctx.lr = 0x823C0CF0;
	sub_823BCA28(ctx, base);
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

__attribute__((alias("__imp__sub_823C0D10"))) PPC_WEAK_FUNC(sub_823C0D10);
PPC_FUNC_IMPL(__imp__sub_823C0D10) {
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
	PPCRegister f31{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
	PPCVRegister v50{};
	PPCVRegister v51{};
	PPCVRegister v52{};
	PPCVRegister v53{};
	PPCVRegister v54{};
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823C0D18;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lbz r11,289(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 289);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c0f78
	if (cr6.eq) goto loc_823C0F78;
	// bl 0x823bd180
	ctx.lr = 0x823C0D4C;
	sub_823BD180(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c0e94
	if (cr6.eq) goto loc_823C0E94;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r11,368(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c0d84
	if (cr6.eq) goto loc_823C0D84;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823c0d88
	if (cr6.eq) goto loc_823C0D88;
loc_823C0D84:
	// li r11,0
	r11.s64 = 0;
loc_823C0D88:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c0f78
	if (cr6.eq) goto loc_823C0F78;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r4,r11,-26472
	ctx.r4.s64 = r11.s64 + -26472;
	// addi r3,r10,-11344
	ctx.r3.s64 = ctx.r10.s64 + -11344;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x823bf2f0
	ctx.lr = 0x823C0DAC;
	sub_823BF2F0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823c0f78
	if (cr6.eq) goto loc_823C0F78;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cdd20
	ctx.lr = 0x823C0DCC;
	sub_823CDD20(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r29,36
	ctx.r3.s64 = r29.s64 + 36;
	// bl 0x823a3f00
	ctx.lr = 0x823C0DD8;
	sub_823A3F00(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,48
	ctx.r9.s64 = r31.s64 + 48;
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// vspltw128 v8,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// vspltw128 v1,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v62,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v11,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvx128 v10,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v6,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v9,v0,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// vspltw128 v4,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vmulfp128 v7,v0,v59
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v2,v58,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xAA));
	// vmulfp128 v5,v0,v57
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v3,v0,v11,v10
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vspltw128 v31,v62,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// li r3,1
	ctx.r3.s64 = 1;
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vspltw128 v29,v58,2
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// lvx128 v12,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v28,v13,v8,v9
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v27,v13,v6,v7
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v26,v13,v4,v5
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v25,v13,v2,v3
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v24,v12,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v12,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v12,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// vmaddfp v21,v12,v29,v25
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(v25.f32)));
	// stvx128 v24,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_823C0E94:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cdce8
	ctx.lr = 0x823C0EB0;
	sub_823CDCE8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r29,36
	ctx.r3.s64 = r29.s64 + 36;
	// bl 0x823a3f00
	ctx.lr = 0x823C0EBC;
	sub_823A3F00(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// lvx128 v56,r0,r31
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,48
	ctx.r9.s64 = r31.s64 + 48;
	// vspltw128 v54,v56,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// vspltw128 v8,v56,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xAA));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// vspltw128 v1,v56,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x55));
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v52,v55,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v50,v53,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// vspltw128 v11,v51,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// lvx128 v10,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v6,v55,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xAA));
	// vmulfp128 v9,v0,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v54.f32)));
	// vspltw128 v4,v53,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xAA));
	// vmulfp128 v7,v0,v52
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v52.f32)));
	// vspltw128 v2,v51,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xAA));
	// vmulfp128 v5,v0,v50
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v50.f32)));
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v3,v0,v11,v10
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vspltw128 v31,v55,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x55));
	// li r3,1
	ctx.r3.s64 = 1;
	// vspltw128 v30,v53,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x55));
	// vspltw128 v29,v51,2
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x55));
	// lvx128 v12,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v28,v13,v8,v9
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v27,v13,v6,v7
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v26,v13,v4,v5
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v25,v13,v2,v3
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v24,v12,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v12,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v12,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// vmaddfp v21,v12,v29,v25
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(v25.f32)));
	// stvx128 v24,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_823C0F78:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823C0F88"))) PPC_WEAK_FUNC(sub_823C0F88);
PPC_FUNC_IMPL(__imp__sub_823C0F88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCVRegister v32{};
	PPCVRegister v33{};
	PPCVRegister v34{};
	PPCVRegister v35{};
	PPCVRegister v36{};
	PPCVRegister v37{};
	PPCVRegister v38{};
	PPCVRegister v39{};
	PPCVRegister v40{};
	PPCVRegister v41{};
	PPCVRegister v42{};
	PPCVRegister v43{};
	PPCVRegister v44{};
	PPCVRegister v45{};
	PPCVRegister v46{};
	PPCVRegister v47{};
	PPCVRegister v48{};
	PPCVRegister v49{};
	PPCVRegister v50{};
	PPCVRegister v51{};
	PPCVRegister v52{};
	PPCVRegister v53{};
	PPCVRegister v54{};
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C0F90;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lbz r11,289(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 289);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c1138
	if (cr6.eq) goto loc_823C1138;
	// bl 0x823bd180
	ctx.lr = 0x823C0FBC;
	sub_823BD180(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c10ac
	if (cr6.eq) goto loc_823C10AC;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r11,368(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c0ff4
	if (cr6.eq) goto loc_823C0FF4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823c0ff8
	if (cr6.eq) goto loc_823C0FF8;
loc_823C0FF4:
	// li r11,0
	r11.s64 = 0;
loc_823C0FF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c1138
	if (cr6.eq) goto loc_823C1138;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r4,r11,-26472
	ctx.r4.s64 = r11.s64 + -26472;
	// addi r3,r10,-11344
	ctx.r3.s64 = ctx.r10.s64 + -11344;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x823bf2f0
	ctx.lr = 0x823C101C;
	sub_823BF2F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c1138
	if (cr6.eq) goto loc_823C1138;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823cde60
	ctx.lr = 0x823C1034;
	sub_823CDE60(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r29,36
	ctx.r3.s64 = r29.s64 + 36;
	// bl 0x823a3f00
	ctx.lr = 0x823C1040;
	sub_823A3F00(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v52,r0,r31
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// li r3,1
	ctx.r3.s64 = 1;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v59,v63,v62
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v58,v63,v62
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v57,v61,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrglw128 v56,v61,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v55,v59,v57
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v54,v58,v56
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v53,v59,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmsum3fp128 v51,v52,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmsum3fp128 v50,v52,v54
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v49,v52,v53
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmrghw128 v48,v51,v50
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v47,v49,v48
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v46,v48,v47
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// stvx128 v46,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_823C10AC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cdd60
	ctx.lr = 0x823C10C0;
	sub_823CDD60(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r29,36
	ctx.r3.s64 = r29.s64 + 36;
	// bl 0x823a3f00
	ctx.lr = 0x823C10CC;
	sub_823A3F00(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v38,r0,r31
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// li r3,1
	ctx.r3.s64 = 1;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v45,v63,v62
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v44,v63,v62
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v43,v61,v60
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrglw128 v42,v61,v60
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v41,v45,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v40,v44,v42
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrglw128 v39,v45,v43
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmsum3fp128 v37,v38,v41
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v41.f32), 0xEF));
	// vmsum3fp128 v36,v38,v40
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v40.f32), 0xEF));
	// vmsum3fp128 v35,v38,v39
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v39.f32), 0xEF));
	// vmrghw128 v34,v37,v36
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v33,v35,v34
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v32,v34,v33
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// stvx128 v32,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_823C1138:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C1148"))) PPC_WEAK_FUNC(sub_823C1148);
PPC_FUNC_IMPL(__imp__sub_823C1148) {
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
	ctx.lr = 0x823C1150;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lwz r31,368(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c118c
	if (cr6.eq) goto loc_823C118C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823c1190
	if (cr6.eq) goto loc_823C1190;
loc_823C118C:
	// li r11,0
	r11.s64 = 0;
loc_823C1190:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c1214
	if (cr6.eq) goto loc_823C1214;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C11AC;
	sub_823BF2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x823c11e4
	if (!cr6.eq) goto loc_823C11E4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C11C4;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-26456
	ctx.r3.s64 = ctx.r10.s64 + -26456;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x823C11DC;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823C11E4:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r5,r11,36
	ctx.r5.s64 = r11.s64 + 36;
	// lfs f2,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// lwz r3,-10008(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10008);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// lfs f3,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x823cee48
	ctx.lr = 0x823C120C;
	sub_823CEE48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823C1214:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10008(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10008);
	// bl 0x823ce2d0
	ctx.lr = 0x823C1228;
	sub_823CE2D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823c1258
	if (cr6.eq) goto loc_823C1258;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,-10008(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10008);
	// addi r5,r11,36
	ctx.r5.s64 = r11.s64 + 36;
	// lfs f2,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x823cedb8
	ctx.lr = 0x823C1258;
	sub_823CEDB8(ctx, base);
loc_823C1258:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823C1260"))) PPC_WEAK_FUNC(sub_823C1260);
PPC_FUNC_IMPL(__imp__sub_823C1260) {
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
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r6,r11,-11344
	ctx.r6.s64 = r11.s64 + -11344;
	// addi r5,r10,-26384
	ctx.r5.s64 = ctx.r10.s64 + -26384;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823C128C;
	sub_82137A08(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,-10000(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// lwz r8,368(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c12c0
	if (cr6.eq) goto loc_823C12C0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823c12c4
	if (cr6.eq) goto loc_823C12C4;
loc_823C12C0:
	// li r11,0
	r11.s64 = 0;
loc_823C12C4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c12f8
	if (cr6.eq) goto loc_823C12F8;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-26472
	ctx.r4.s64 = r11.s64 + -26472;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823bf2f0
	ctx.lr = 0x823C12E4;
	sub_823BF2F0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823C12F8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r5,r10,-26472
	ctx.r5.s64 = ctx.r10.s64 + -26472;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823ce2d0
	ctx.lr = 0x823C1310;
	sub_823CE2D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c1330
	if (cr6.eq) goto loc_823C1330;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823C1330:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C1348"))) PPC_WEAK_FUNC(sub_823C1348);
PPC_FUNC_IMPL(__imp__sub_823C1348) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x823C1350;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r30,336(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r28,360(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c13a4
	if (cr6.eq) goto loc_823C13A4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823c13a8
	if (cr6.eq) goto loc_823C13A8;
loc_823C13A4:
	// li r11,0
	r11.s64 = 0;
loc_823C13A8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// beq cr6,0x823c1480
	if (cr6.eq) goto loc_823C1480;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// lwz r3,-4960(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C13C8;
	sub_823CA248(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x823c1514
	if (cr6.eq) goto loc_823C1514;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r5,360(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// bl 0x823bf250
	ctx.lr = 0x823C13E8;
	sub_823BF250(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x823c1418
	if (!cr6.eq) goto loc_823C1418;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C1400;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-26368
	ctx.r3.s64 = ctx.r10.s64 + -26368;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82130000
	ctx.lr = 0x823C1418;
	sub_82130000(ctx, base);
loc_823C1418:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c0268
	ctx.lr = 0x823C1424;
	sub_823C0268(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// lwz r3,-4960(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823ca370
	ctx.lr = 0x823C144C;
	sub_823CA370(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c1518
	if (!cr6.lt) goto loc_823C1518;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_823C1480:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,-4960(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C148C;
	sub_823CA248(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823c1514
	if (cr6.eq) goto loc_823C1514;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,-4960(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4960);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C14A8;
	sub_823CAAB8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c0268
	ctx.lr = 0x823C14B8;
	sub_823C0268(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// lwz r3,-4960(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4960);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823ca2e8
	ctx.lr = 0x823C14E0;
	sub_823CA2E8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c1518
	if (!cr6.lt) goto loc_823C1518;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_823C1514:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823C1518:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_823C1520"))) PPC_WEAK_FUNC(sub_823C1520);
PPC_FUNC_IMPL(__imp__sub_823C1520) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x823C1528;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r22,r8
	r22.u64 = ctx.r8.u64;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r21,r9
	r21.u64 = ctx.r9.u64;
	// lwz r28,336(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r27,360(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c1580
	if (cr6.eq) goto loc_823C1580;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823c1584
	if (cr6.eq) goto loc_823C1584;
loc_823C1580:
	// li r11,0
	r11.s64 = 0;
loc_823C1584:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// beq cr6,0x823c16b8
	if (cr6.eq) goto loc_823C16B8;
	// lis r19,-32121
	r19.s64 = -2105081856;
	// lwz r3,-4960(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C15A4;
	sub_823CA248(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x823c177c
	if (cr6.eq) goto loc_823C177C;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,360(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// bl 0x823bf250
	ctx.lr = 0x823C15C4;
	sub_823BF250(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// addi r23,r11,-26288
	r23.s64 = r11.s64 + -26288;
	// bne cr6,0x823c15f8
	if (!cr6.eq) goto loc_823C15F8;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C15E4;
	sub_823B8690(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82130000
	ctx.lr = 0x823C15F8;
	sub_82130000(ctx, base);
loc_823C15F8:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823bba48
	ctx.lr = 0x823C1608;
	sub_823BBA48(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r5,360(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// bl 0x823bf250
	ctx.lr = 0x823C161C;
	sub_823BF250(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x823c1650
	if (cr6.eq) goto loc_823C1650;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x823c1650
	if (!cr6.eq) goto loc_823C1650;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C163C;
	sub_823B8690(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82130000
	ctx.lr = 0x823C1650;
	sub_82130000(ctx, base);
loc_823C1650:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c0268
	ctx.lr = 0x823C165C;
	sub_823C0268(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// lwz r3,-4960(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -4960);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823ca370
	ctx.lr = 0x823C1684;
	sub_823CA370(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c1780
	if (!cr6.lt) goto loc_823C1780;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r28.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d9224
	return;
loc_823C16B8:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C16C4;
	sub_823CA248(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c177c
	if (cr6.eq) goto loc_823C177C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823bba48
	ctx.lr = 0x823C16E0;
	sub_823BBA48(ctx, base);
	// lwz r11,-4960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C16F8;
	sub_823CAAB8(ctx, base);
	// lwz r11,-4960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C1710;
	sub_823CAAB8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c0268
	ctx.lr = 0x823C1720;
	sub_823C0268(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823ca2e8
	ctx.lr = 0x823C1748;
	sub_823CA2E8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c1780
	if (!cr6.lt) goto loc_823C1780;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r28.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d9224
	return;
loc_823C177C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_823C1780:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_823C1788"))) PPC_WEAK_FUNC(sub_823C1788);
PPC_FUNC_IMPL(__imp__sub_823C1788) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x823C1790;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r21,r10
	r21.u64 = ctx.r10.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r20,r7
	r20.u64 = ctx.r7.u64;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// lwz r29,336(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r26,360(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c17ec
	if (cr6.eq) goto loc_823C17EC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823c17f0
	if (cr6.eq) goto loc_823C17F0;
loc_823C17EC:
	// li r11,0
	r11.s64 = 0;
loc_823C17F0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// beq cr6,0x823c1914
	if (cr6.eq) goto loc_823C1914;
	// lis r18,-32121
	r18.s64 = -2105081856;
	// lwz r3,-4960(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C1810;
	sub_823CA248(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x823c19c0
	if (cr6.eq) goto loc_823C19C0;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,360(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// bl 0x823bf250
	ctx.lr = 0x823C1830;
	sub_823BF250(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// addi r23,r11,-26200
	r23.s64 = r11.s64 + -26200;
	// bne cr6,0x823c1864
	if (!cr6.eq) goto loc_823C1864;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C1850;
	sub_823B8690(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82130000
	ctx.lr = 0x823C1864;
	sub_82130000(ctx, base);
loc_823C1864:
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,360(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// bl 0x823bf250
	ctx.lr = 0x823C1878;
	sub_823BF250(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x823c18ac
	if (cr6.eq) goto loc_823C18AC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823c18ac
	if (!cr6.eq) goto loc_823C18AC;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C1898;
	sub_823B8690(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82130000
	ctx.lr = 0x823C18AC;
	sub_82130000(ctx, base);
loc_823C18AC:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c0268
	ctx.lr = 0x823C18B8;
	sub_823C0268(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// lwz r3,-4960(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + -4960);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823ca370
	ctx.lr = 0x823C18E0;
	sub_823CA370(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c19c4
	if (!cr6.lt) goto loc_823C19C4;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r29.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9220
	return;
loc_823C1914:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C1920;
	sub_823CA248(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x823c19c0
	if (cr6.eq) goto loc_823C19C0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C193C;
	sub_823CAAB8(ctx, base);
	// lwz r11,-4960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C1954;
	sub_823CAAB8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c0268
	ctx.lr = 0x823C1964;
	sub_823C0268(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823ca2e8
	ctx.lr = 0x823C198C;
	sub_823CA2E8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c19c4
	if (!cr6.lt) goto loc_823C19C4;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r29.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9220
	return;
loc_823C19C0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_823C19C4:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_823C19CC"))) PPC_WEAK_FUNC(sub_823C19CC);
PPC_FUNC_IMPL(__imp__sub_823C19CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C19D0"))) PPC_WEAK_FUNC(sub_823C19D0);
PPC_FUNC_IMPL(__imp__sub_823C19D0) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,-10000(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r11,360(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 360);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c1a18
	if (cr6.eq) goto loc_823C1A18;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823c1a1c
	if (cr6.eq) goto loc_823C1A1C;
loc_823C1A18:
	// li r11,0
	r11.s64 = 0;
loc_823C1A1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x823c1a44
	if (!cr6.eq) goto loc_823C1A44;
	// lwz r11,372(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 372);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c1a60
	if (cr6.eq) goto loc_823C1A60;
loc_823C1A44:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-26104
	ctx.r3.s64 = r11.s64 + -26104;
	// bl 0x821bd618
	ctx.lr = 0x823C1A54;
	sub_821BD618(ctx, base);
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// stw r31,372(r11)
	PPC_STORE_U32(r11.u32 + 372, r31.u32);
	// b 0x823c1a64
	goto loc_823C1A64;
loc_823C1A60:
	// stw r31,372(r10)
	PPC_STORE_U32(ctx.r10.u32 + 372, r31.u32);
loc_823C1A64:
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_823C1A80"))) PPC_WEAK_FUNC(sub_823C1A80);
PPC_FUNC_IMPL(__imp__sub_823C1A80) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x823C1A88;
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f29.u64);
	// stfd f30,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-6384(r1)
	ea = -6384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lbz r11,72(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c1b78
	if (cr6.eq) goto loc_823C1B78;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r31,0
	r31.s64 = 0;
	// lfs f0,27636(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27636);
	f0.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// mr r26,r31
	r26.u64 = r31.u64;
	// lfs f31,-31400(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31400);
	f31.f64 = double(temp.f32);
	// li r29,-32
	r29.s64 = -32;
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r30,-16
	r30.s64 = -16;
	// lfs f29,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f29.f64 = double(temp.f32);
	// addi r28,r11,2256
	r28.s64 = r11.s64 + 2256;
loc_823C1B00:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,56(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 56);
	// bl 0x823bdf38
	ctx.lr = 0x823C1B0C;
	sub_823BDF38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c1b60
	if (cr6.eq) goto loc_823C1B60;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,127
	ctx.r10.s64 = 127;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
loc_823C1B20:
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stfs f30,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stb r31,12(r11)
	PPC_STORE_U8(r11.u32 + 12, r31.u8);
	// stfs f30,8(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// bge 0x823c1b20
	if (!cr0.lt) goto loc_823C1B20;
	// li r7,255
	ctx.r7.s64 = 255;
	// li r6,128
	ctx.r6.s64 = 128;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823bff28
	ctx.lr = 0x823C1B58;
	sub_823BFF28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x823c1b90
	if (cr6.gt) goto loc_823C1B90;
loc_823C1B60:
	// lfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	f0.f64 = double(temp.f32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// fmuls f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 * f29.f64));
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// cmpwi cr6,r26,5
	cr6.compare<int32_t>(r26.s32, 5, xer);
	// blt cr6,0x823c1b00
	if (cr6.lt) goto loc_823C1B00;
loc_823C1B78:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,6384
	ctx.r1.s64 = ctx.r1.s64 + 6384;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_823C1B90:
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// blt cr6,0x823c1c90
	if (cr6.lt) goto loc_823C1C90;
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// lfs f13,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r31,r9,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_823C1BB4:
	// lwz r10,-48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -48);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f10,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f0,f9,f9,f8
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823c1be8
	if (!cr6.gt) goto loc_823C1BE8;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f31,f0
	f31.f64 = f0.f64;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823C1BE8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f10,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f0,f9,f9,f8
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823c1c1c
	if (!cr6.gt) goto loc_823C1C1C;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f31,f0
	f31.f64 = f0.f64;
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823C1C1C:
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f10,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f0,f9,f9,f8
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823c1c50
	if (!cr6.gt) goto loc_823C1C50;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f31,f0
	f31.f64 = f0.f64;
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823C1C50:
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f10,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f0,f9,f9,f8
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823c1c84
	if (!cr6.gt) goto loc_823C1C84;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f31,f0
	f31.f64 = f0.f64;
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823C1C84:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// bne 0x823c1bb4
	if (!cr0.eq) goto loc_823C1BB4;
loc_823C1C90:
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// bge cr6,0x823c1cf8
	if (!cr6.lt) goto loc_823C1CF8;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lfs f12,8(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// subf r9,r31,r3
	ctx.r9.s64 = ctx.r3.s64 - r31.s64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_823C1CB8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f10,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f0,f9,f9,f8
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823c1cec
	if (!cr6.gt) goto loc_823C1CEC;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f31,f0
	f31.f64 = f0.f64;
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823C1CEC:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// bne 0x823c1cb8
	if (!cr0.eq) goto loc_823C1CB8;
loc_823C1CF8:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,0(r24)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r24.u32 + 0, temp.u32);
	// stfs f13,4(r24)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r24.u32 + 4, temp.u32);
	// stfs f12,8(r24)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r24.u32 + 8, temp.u32);
	// stfs f11,0(r23)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
	// addi r1,r1,6384
	ctx.r1.s64 = ctx.r1.s64 + 6384;
	// lfd f29,-104(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823C1D30"))) PPC_WEAK_FUNC(sub_823C1D30);
PPC_FUNC_IMPL(__imp__sub_823C1D30) {
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
	// lhz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823c1d6c
	if (!cr6.gt) goto loc_823C1D6C;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
loc_823C1D50:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// beq cr6,0x823c1d8c
	if (cr6.eq) goto loc_823C1D8C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x823c1d50
	if (cr6.lt) goto loc_823C1D50;
loc_823C1D6C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-26008
	ctx.r3.s64 = r11.s64 + -26008;
	// bl 0x82130000
	ctx.lr = 0x823C1D78;
	sub_82130000(ctx, base);
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
loc_823C1D8C:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x823c1d6c
	if (!cr6.gt) goto loc_823C1D6C;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// bl 0x823c01c8
	ctx.lr = 0x823C1DAC;
	sub_823C01C8(ctx, base);
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c1dcc
	if (cr6.eq) goto loc_823C1DCC;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823C1DCC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C1DE4"))) PPC_WEAK_FUNC(sub_823C1DE4);
PPC_FUNC_IMPL(__imp__sub_823C1DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C1DE8"))) PPC_WEAK_FUNC(sub_823C1DE8);
PPC_FUNC_IMPL(__imp__sub_823C1DE8) {
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
	ctx.lr = 0x823C1DF0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r11,0
	r11.s64 = 0;
	// lhz r9,16(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823c1e30
	if (!cr6.gt) goto loc_823C1E30;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
loc_823C1E14:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r8,r25
	cr6.compare<int32_t>(ctx.r8.s32, r25.s32, xer);
	// beq cr6,0x823c1e50
	if (cr6.eq) goto loc_823C1E50;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x823c1e14
	if (cr6.lt) goto loc_823C1E14;
loc_823C1E30:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// clrlwi r5,r24,24
	ctx.r5.u64 = r24.u32 & 0xFF;
	// addi r3,r11,-25896
	ctx.r3.s64 = r11.s64 + -25896;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82130000
	ctx.lr = 0x823C1E44;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823C1E50:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x823c1e30
	if (!cr6.gt) goto loc_823C1E30;
	// clrlwi r10,r24,24
	ctx.r10.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823c1f58
	if (!cr6.eq) goto loc_823C1F58;
	// lbz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 28);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c1f28
	if (cr6.eq) goto loc_823C1F28;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c1ee4
	if (cr6.eq) goto loc_823C1EE4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c1e90
	if (!cr6.gt) goto loc_823C1E90;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// blt cr6,0x823c1e94
	if (cr6.lt) goto loc_823C1E94;
loc_823C1E90:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823C1E94:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c1ee4
	if (cr6.eq) goto loc_823C1EE4;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,20(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// li r4,4
	ctx.r4.s64 = 4;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// bl 0x823c00e0
	ctx.lr = 0x823C1EBC;
	sub_823C00E0(ctx, base);
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c1ed4
	if (cr6.eq) goto loc_823C1ED4;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823C1ED4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823C1EE4:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c1f28
	if (cr6.eq) goto loc_823C1F28;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c1f28
	if (cr6.eq) goto loc_823C1F28;
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// bne cr6,0x823c1f28
	if (!cr6.eq) goto loc_823C1F28;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r11,140
	ctx.r3.s64 = r11.s64 + 140;
	// bl 0x823c00e0
	ctx.lr = 0x823C1F10;
	sub_823C00E0(ctx, base);
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c1ed4
	if (cr6.eq) goto loc_823C1ED4;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823C1F28:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823c01c8
	ctx.lr = 0x823C1F40;
	sub_823C01C8(ctx, base);
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c1ed4
	if (cr6.eq) goto loc_823C1ED4;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823C1F58:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r31,0
	r31.s64 = 0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// rlwinm r28,r10,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// lhz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c1e30
	if (cr6.eq) goto loc_823C1E30;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r27,r10,3998
	r27.s64 = ctx.r10.s64 + 3998;
	// addi r26,r11,-25912
	r26.s64 = r11.s64 + -25912;
loc_823C1F8C:
	// bl 0x823c01c8
	ctx.lr = 0x823C1F90;
	sub_823C01C8(ctx, base);
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c1fa4
	if (cr6.eq) goto loc_823C1FA4;
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x823c1fa8
	goto loc_823C1FA8;
loc_823C1FA4:
	// mr r30,r27
	r30.u64 = r27.u64;
loc_823C1FA8:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823C1FB4;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c1fd8
	if (cr6.eq) goto loc_823C1FD8;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x823c1f8c
	if (cr6.lt) goto loc_823C1F8C;
	// b 0x823c1e30
	goto loc_823C1E30;
loc_823C1FD8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823C1FE4"))) PPC_WEAK_FUNC(sub_823C1FE4);
PPC_FUNC_IMPL(__imp__sub_823C1FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C1FE8"))) PPC_WEAK_FUNC(sub_823C1FE8);
PPC_FUNC_IMPL(__imp__sub_823C1FE8) {
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
	// lhz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823c2028
	if (!cr6.gt) goto loc_823C2028;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
loc_823C200C:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// beq cr6,0x823c203c
	if (cr6.eq) goto loc_823C203C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x823c200c
	if (cr6.lt) goto loc_823C200C;
loc_823C2028:
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
loc_823C203C:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x823c2028
	if (!cr6.gt) goto loc_823C2028;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823c01c8
	ctx.lr = 0x823C205C;
	sub_823C01C8(ctx, base);
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c207c
	if (cr6.eq) goto loc_823C207C;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823C207C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C2094"))) PPC_WEAK_FUNC(sub_823C2094);
PPC_FUNC_IMPL(__imp__sub_823C2094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C2098"))) PPC_WEAK_FUNC(sub_823C2098);
PPC_FUNC_IMPL(__imp__sub_823C2098) {
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
	ctx.lr = 0x823C20A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823c215c
	if (!cr6.eq) goto loc_823C215C;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r4.u16);
	// bl 0x823bded0
	ctx.lr = 0x823C20C8;
	sub_823BDED0(ctx, base);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2128
	if (cr6.eq) goto loc_823C2128;
	// li r28,0
	r28.s64 = 0;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_823C20E0:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r9,r10,r29
	ctx.r9.u64 = ctx.r10.u64 + r29.u64;
	// addi r3,r9,4
	ctx.r3.s64 = ctx.r9.s64 + 4;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stwx r8,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + r29.u32, ctx.r8.u32);
	// sth r28,8(r9)
	PPC_STORE_U16(ctx.r9.u32 + 8, r28.u16);
	// lhz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c9650
	ctx.lr = 0x823C2114;
	sub_821C9650(ctx, base);
	// addi r7,r31,1
	ctx.r7.s64 = r31.s64 + 1;
	// lhz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// clrlwi r31,r7,16
	r31.u64 = ctx.r7.u32 & 0xFFFF;
	// cmplw cr6,r31,r6
	cr6.compare<uint32_t>(r31.u32, ctx.r6.u32, xer);
	// blt cr6,0x823c20e0
	if (cr6.lt) goto loc_823C20E0;
loc_823C2128:
	// lhz r31,4(r30)
	r31.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r27,0(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x823c2150
	if (!cr6.gt) goto loc_823C2150;
	// addi r28,r27,4
	r28.s64 = r27.s64 + 4;
loc_823C213C:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C2144;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r28,r28,12
	r28.s64 = r28.s64 + 12;
	// bne 0x823c213c
	if (!cr0.eq) goto loc_823C213C;
loc_823C2150:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x823C2158;
	sub_82130588(ctx, base);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
loc_823C215C:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823C2184"))) PPC_WEAK_FUNC(sub_823C2184);
PPC_FUNC_IMPL(__imp__sub_823C2184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C2188"))) PPC_WEAK_FUNC(sub_823C2188);
PPC_FUNC_IMPL(__imp__sub_823C2188) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-25780
	ctx.r10.s64 = r11.s64 + -25780;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x823C21B0;
	sub_821B5A60(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821b5a60
	ctx.lr = 0x823C21B8;
	sub_821B5A60(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821b5a60
	ctx.lr = 0x823C21C0;
	sub_821B5A60(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
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

__attribute__((alias("__imp__sub_823C21E8"))) PPC_WEAK_FUNC(sub_823C21E8);
PPC_FUNC_IMPL(__imp__sub_823C21E8) {
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
	ctx.lr = 0x823C21F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x823c2224
	if (cr6.eq) goto loc_823C2224;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x823c2218
	if (cr6.eq) goto loc_823C2218;
	// bl 0x822d32f8
	ctx.lr = 0x823C2218;
	sub_822D32F8(ctx, base);
loc_823C2218:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823bb818
	ctx.lr = 0x823C2224;
	sub_823BB818(ctx, base);
loc_823C2224:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r29,r30,12
	r29.s64 = r30.s64 + 12;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// beq cr6,0x823c226c
	if (cr6.eq) goto loc_823C226C;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x823c2260
	if (cr6.eq) goto loc_823C2260;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c2260
	if (cr6.eq) goto loc_823C2260;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C2260;
	sub_82130588(ctx, base);
loc_823C2260:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c7480
	ctx.lr = 0x823C226C;
	sub_826C7480(ctx, base);
loc_823C226C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C2278"))) PPC_WEAK_FUNC(sub_823C2278);
PPC_FUNC_IMPL(__imp__sub_823C2278) {
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
	// addi r10,r11,-25764
	ctx.r10.s64 = r11.s64 + -25764;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,10(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c22b4
	if (cr6.eq) goto loc_823C22B4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823C22B4;
	sub_82130588(ctx, base);
loc_823C22B4:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c22cc
	if (cr6.eq) goto loc_823C22CC;
	// bl 0x82130588
	ctx.lr = 0x823C22C8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823C22CC:
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

__attribute__((alias("__imp__sub_823C22E4"))) PPC_WEAK_FUNC(sub_823C22E4);
PPC_FUNC_IMPL(__imp__sub_823C22E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C22E8"))) PPC_WEAK_FUNC(sub_823C22E8);
PPC_FUNC_IMPL(__imp__sub_823C22E8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x823C230C;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x823c234c
	if (!cr6.gt) goto loc_823C234C;
	// addi r11,r3,18
	r11.s64 = ctx.r3.s64 + 18;
	// li r10,0
	ctx.r10.s64 = 0;
loc_823C231C:
	// addic. r9,r11,-18
	xer.ca = r11.u32 > 17;
	ctx.r9.s64 = r11.s64 + -18;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823c2340
	if (cr0.eq) goto loc_823C2340;
	// stw r10,-18(r11)
	PPC_STORE_U32(r11.u32 + -18, ctx.r10.u32);
	// sth r10,-14(r11)
	PPC_STORE_U16(r11.u32 + -14, ctx.r10.u16);
	// sth r10,-12(r11)
	PPC_STORE_U16(r11.u32 + -12, ctx.r10.u16);
	// stw r10,-10(r11)
	PPC_STORE_U32(r11.u32 + -10, ctx.r10.u32);
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
loc_823C2340:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// bne 0x823c231c
	if (!cr0.eq) goto loc_823C231C;
loc_823C234C:
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

__attribute__((alias("__imp__sub_823C2360"))) PPC_WEAK_FUNC(sub_823C2360);
PPC_FUNC_IMPL(__imp__sub_823C2360) {
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
	ctx.lr = 0x823C2368;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-25756
	ctx.r10.s64 = r11.s64 + -25756;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// addi r29,r28,4
	r29.s64 = r28.s64 + 4;
	// stw r30,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r30.u32);
	// li r25,20
	r25.s64 = 20;
	// stw r30,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r30.u32);
	// li r26,3
	r26.s64 = 3;
	// stw r30,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r30.u32);
	// addi r27,r11,-15264
	r27.s64 = r11.s64 + -15264;
	// stw r30,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r30.u32);
loc_823C23A4:
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x82130528
	ctx.lr = 0x823C23AC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c23d4
	if (cr6.eq) goto loc_823C23D4;
	// bl 0x824905e0
	ctx.lr = 0x823C23BC;
	sub_824905E0(ctx, base);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// stb r26,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r26.u8);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// b 0x823c23d8
	goto loc_823C23D8;
loc_823C23D4:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823C23D8:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2408
	if (cr6.eq) goto loc_823C2408;
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r9,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r9.u32);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c2400
	if (cr6.eq) goto loc_823C2400;
	// stw r11,52(r9)
	PPC_STORE_U32(ctx.r9.u32 + 52, r11.u32);
loc_823C2400:
	// stw r11,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, r11.u32);
	// b 0x823c240c
	goto loc_823C240C;
loc_823C2408:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823C240C:
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// bne 0x823c23a4
	if (!cr0.eq) goto loc_823C23A4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823C2424"))) PPC_WEAK_FUNC(sub_823C2424);
PPC_FUNC_IMPL(__imp__sub_823C2424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C2428"))) PPC_WEAK_FUNC(sub_823C2428);
PPC_FUNC_IMPL(__imp__sub_823C2428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2450
	if (!cr6.eq) goto loc_823C2450;
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_823C2450:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2464
	if (!cr6.eq) goto loc_823C2464;
	// lwz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_823C2464:
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c2478
	if (cr6.eq) goto loc_823C2478;
	// lwz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// stw r9,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r9.u32);
loc_823C2478:
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c248c
	if (cr6.eq) goto loc_823C248C;
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stw r9,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r9.u32);
loc_823C248C:
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// li r11,0
	r11.s64 = 0;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c24d0
	if (cr6.eq) goto loc_823C24D0;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c24c4
	if (cr6.eq) goto loc_823C24C4;
	// stw r3,52(r9)
	PPC_STORE_U32(ctx.r9.u32 + 52, ctx.r3.u32);
loc_823C24C4:
	// stw r3,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r3.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// blr 
	return;
loc_823C24D0:
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C24DC"))) PPC_WEAK_FUNC(sub_823C24DC);
PPC_FUNC_IMPL(__imp__sub_823C24DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C24E0"))) PPC_WEAK_FUNC(sub_823C24E0);
PPC_FUNC_IMPL(__imp__sub_823C24E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c259c
	if (cr6.eq) goto loc_823C259C;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2504
	if (!cr6.eq) goto loc_823C2504;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_823C2504:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2518
	if (!cr6.eq) goto loc_823C2518;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_823C2518:
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c252c
	if (cr6.eq) goto loc_823C252C;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// stw r9,52(r10)
	PPC_STORE_U32(ctx.r10.u32 + 52, ctx.r9.u32);
loc_823C252C:
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2540
	if (cr6.eq) goto loc_823C2540;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r9,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r9.u32);
loc_823C2540:
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// stw r8,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r8.u32);
	// stw r8,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r8.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// beq cr6,0x823c258c
	if (cr6.eq) goto loc_823C258C;
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r7,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r7.u32);
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823c257c
	if (cr6.eq) goto loc_823C257C;
	// stw r11,52(r7)
	PPC_STORE_U32(ctx.r7.u32 + 52, r11.u32);
loc_823C257C:
	// stw r11,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_823C258C:
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_823C259C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C25A8"))) PPC_WEAK_FUNC(sub_823C25A8);
PPC_FUNC_IMPL(__imp__sub_823C25A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r3,12
	ctx.r6.s64 = ctx.r3.s64 + 12;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823C25C0:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r8,48
	ctx.r9.s64 = ctx.r8.s64 + 48;
	// lwz r8,48(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c25e0
	if (!cr6.eq) goto loc_823C25E0;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_823C25E0:
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c25f4
	if (!cr6.eq) goto loc_823C25F4;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
loc_823C25F4:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2608
	if (cr6.eq) goto loc_823C2608;
	// lwz r4,52(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// stw r4,52(r10)
	PPC_STORE_U32(ctx.r10.u32 + 52, ctx.r4.u32);
loc_823C2608:
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c261c
	if (cr6.eq) goto loc_823C261C;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r4,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r4.u32);
loc_823C261C:
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stw r5,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r5.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2654
	if (cr6.eq) goto loc_823C2654;
	// lwz r4,48(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c264c
	if (cr6.eq) goto loc_823C264C;
	// stw r11,52(r9)
	PPC_STORE_U32(ctx.r9.u32 + 52, r11.u32);
loc_823C264C:
	// stw r11,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, r11.u32);
	// b 0x823c2658
	goto loc_823C2658;
loc_823C2654:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_823C2658:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823c25c0
	if (!cr6.eq) goto loc_823C25C0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C2668"))) PPC_WEAK_FUNC(sub_823C2668);
PPC_FUNC_IMPL(__imp__sub_823C2668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r6,r3,4
	ctx.r6.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,12
	ctx.r7.s64 = ctx.r3.s64 + 12;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823C2680:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r8,48
	ctx.r9.s64 = ctx.r8.s64 + 48;
	// lwz r8,48(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c26a0
	if (!cr6.eq) goto loc_823C26A0;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_823C26A0:
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c26b4
	if (!cr6.eq) goto loc_823C26B4;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
loc_823C26B4:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c26c8
	if (cr6.eq) goto loc_823C26C8;
	// lwz r4,52(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// stw r4,52(r10)
	PPC_STORE_U32(ctx.r10.u32 + 52, ctx.r4.u32);
loc_823C26C8:
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c26dc
	if (cr6.eq) goto loc_823C26DC;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r4,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r4.u32);
loc_823C26DC:
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stw r5,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r5.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2714
	if (cr6.eq) goto loc_823C2714;
	// lwz r4,48(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c270c
	if (cr6.eq) goto loc_823C270C;
	// stw r11,52(r9)
	PPC_STORE_U32(ctx.r9.u32 + 52, r11.u32);
loc_823C270C:
	// stw r11,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, r11.u32);
	// b 0x823c2718
	goto loc_823C2718;
loc_823C2714:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_823C2718:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823c2680
	if (!cr6.eq) goto loc_823C2680;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C2728"))) PPC_WEAK_FUNC(sub_823C2728);
PPC_FUNC_IMPL(__imp__sub_823C2728) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823C2730;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-25748
	ctx.r10.s64 = r11.s64 + -25748;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r30.u32);
	// addi r29,r27,4
	r29.s64 = r27.s64 + 4;
	// stw r30,8(r27)
	PPC_STORE_U32(r27.u32 + 8, r30.u32);
	// li r25,20
	r25.s64 = 20;
	// stw r30,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r30.u32);
	// li r26,1
	r26.s64 = 1;
	// stw r30,16(r27)
	PPC_STORE_U32(r27.u32 + 16, r30.u32);
	// addi r28,r11,-15184
	r28.s64 = r11.s64 + -15184;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_823C2778:
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x823C2780;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c27c8
	if (cr6.eq) goto loc_823C27C8;
	// bl 0x824905e0
	ctx.lr = 0x823C2790;
	sub_824905E0(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// stfs f31,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stfs f31,72(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stfs f31,68(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// addi r11,r31,56
	r11.s64 = r31.s64 + 56;
	// stfs f31,64(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stfs f31,76(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stb r26,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r26.u8);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// b 0x823c27cc
	goto loc_823C27CC;
loc_823C27C8:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823C27CC:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c27fc
	if (cr6.eq) goto loc_823C27FC;
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// stw r10,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r10.u32);
	// stw r9,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r9.u32);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c27f4
	if (cr6.eq) goto loc_823C27F4;
	// stw r11,88(r9)
	PPC_STORE_U32(ctx.r9.u32 + 88, r11.u32);
loc_823C27F4:
	// stw r11,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, r11.u32);
	// b 0x823c2800
	goto loc_823C2800;
loc_823C27FC:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823C2800:
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// bne 0x823c2778
	if (!cr0.eq) goto loc_823C2778;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823C281C"))) PPC_WEAK_FUNC(sub_823C281C);
PPC_FUNC_IMPL(__imp__sub_823C281C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C2820"))) PPC_WEAK_FUNC(sub_823C2820);
PPC_FUNC_IMPL(__imp__sub_823C2820) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2848
	if (!cr6.eq) goto loc_823C2848;
	// lwz r9,84(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_823C2848:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c285c
	if (!cr6.eq) goto loc_823C285C;
	// lwz r9,88(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_823C285C:
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c2870
	if (cr6.eq) goto loc_823C2870;
	// lwz r9,88(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// stw r9,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r9.u32);
loc_823C2870:
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c2884
	if (cr6.eq) goto loc_823C2884;
	// lwz r9,84(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// stw r9,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r9.u32);
loc_823C2884:
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// li r11,0
	r11.s64 = 0;
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r11.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c28c8
	if (cr6.eq) goto loc_823C28C8;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r11.u32);
	// stw r9,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r9.u32);
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c28bc
	if (cr6.eq) goto loc_823C28BC;
	// stw r3,88(r9)
	PPC_STORE_U32(ctx.r9.u32 + 88, ctx.r3.u32);
loc_823C28BC:
	// stw r3,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r3.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// blr 
	return;
loc_823C28C8:
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C28D4"))) PPC_WEAK_FUNC(sub_823C28D4);
PPC_FUNC_IMPL(__imp__sub_823C28D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C28D8"))) PPC_WEAK_FUNC(sub_823C28D8);
PPC_FUNC_IMPL(__imp__sub_823C28D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c2994
	if (cr6.eq) goto loc_823C2994;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c28fc
	if (!cr6.eq) goto loc_823C28FC;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_823C28FC:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2910
	if (!cr6.eq) goto loc_823C2910;
	// lwz r9,88(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_823C2910:
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2924
	if (cr6.eq) goto loc_823C2924;
	// lwz r9,88(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// stw r9,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, ctx.r9.u32);
loc_823C2924:
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2938
	if (cr6.eq) goto loc_823C2938;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stw r9,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r9.u32);
loc_823C2938:
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// stw r8,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r8.u32);
	// stw r8,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r8.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// beq cr6,0x823c2984
	if (cr6.eq) goto loc_823C2984;
	// lwz r7,84(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// stw r10,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r10.u32);
	// stw r7,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r7.u32);
	// lwz r7,84(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823c2974
	if (cr6.eq) goto loc_823C2974;
	// stw r11,88(r7)
	PPC_STORE_U32(ctx.r7.u32 + 88, r11.u32);
loc_823C2974:
	// stw r11,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_823C2984:
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_823C2994:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C29A0"))) PPC_WEAK_FUNC(sub_823C29A0);
PPC_FUNC_IMPL(__imp__sub_823C29A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r3,12
	ctx.r6.s64 = ctx.r3.s64 + 12;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823C29B8:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r8,84
	ctx.r9.s64 = ctx.r8.s64 + 84;
	// lwz r8,84(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c29d8
	if (!cr6.eq) goto loc_823C29D8;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_823C29D8:
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c29ec
	if (!cr6.eq) goto loc_823C29EC;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
loc_823C29EC:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2a00
	if (cr6.eq) goto loc_823C2A00;
	// lwz r4,88(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// stw r4,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, ctx.r4.u32);
loc_823C2A00:
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2a14
	if (cr6.eq) goto loc_823C2A14;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r4,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r4.u32);
loc_823C2A14:
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stw r5,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r5.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2a4c
	if (cr6.eq) goto loc_823C2A4C;
	// lwz r4,84(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// stw r10,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r10.u32);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c2a44
	if (cr6.eq) goto loc_823C2A44;
	// stw r11,88(r9)
	PPC_STORE_U32(ctx.r9.u32 + 88, r11.u32);
loc_823C2A44:
	// stw r11,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, r11.u32);
	// b 0x823c2a50
	goto loc_823C2A50;
loc_823C2A4C:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_823C2A50:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823c29b8
	if (!cr6.eq) goto loc_823C29B8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C2A60"))) PPC_WEAK_FUNC(sub_823C2A60);
PPC_FUNC_IMPL(__imp__sub_823C2A60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r6,r3,4
	ctx.r6.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,12
	ctx.r7.s64 = ctx.r3.s64 + 12;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823C2A78:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r8,84
	ctx.r9.s64 = ctx.r8.s64 + 84;
	// lwz r8,84(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c2a98
	if (!cr6.eq) goto loc_823C2A98;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_823C2A98:
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c2aac
	if (!cr6.eq) goto loc_823C2AAC;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
loc_823C2AAC:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2ac0
	if (cr6.eq) goto loc_823C2AC0;
	// lwz r4,88(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// stw r4,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, ctx.r4.u32);
loc_823C2AC0:
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2ad4
	if (cr6.eq) goto loc_823C2AD4;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r4,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r4.u32);
loc_823C2AD4:
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stw r5,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r5.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2b0c
	if (cr6.eq) goto loc_823C2B0C;
	// lwz r4,84(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// stw r10,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r10.u32);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c2b04
	if (cr6.eq) goto loc_823C2B04;
	// stw r11,88(r9)
	PPC_STORE_U32(ctx.r9.u32 + 88, r11.u32);
loc_823C2B04:
	// stw r11,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, r11.u32);
	// b 0x823c2b10
	goto loc_823C2B10;
loc_823C2B0C:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_823C2B10:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823c2a78
	if (!cr6.eq) goto loc_823C2A78;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C2B20"))) PPC_WEAK_FUNC(sub_823C2B20);
PPC_FUNC_IMPL(__imp__sub_823C2B20) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823C2B28;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-25740
	ctx.r10.s64 = r11.s64 + -25740;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r30.u32);
	// addi r29,r27,4
	r29.s64 = r27.s64 + 4;
	// stw r30,8(r27)
	PPC_STORE_U32(r27.u32 + 8, r30.u32);
	// li r25,16
	r25.s64 = 16;
	// stw r30,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r30.u32);
	// li r26,2
	r26.s64 = 2;
	// stw r30,16(r27)
	PPC_STORE_U32(r27.u32 + 16, r30.u32);
	// addi r28,r11,-15164
	r28.s64 = r11.s64 + -15164;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_823C2B70:
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x823C2B78;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c2bc0
	if (cr6.eq) goto loc_823C2BC0;
	// bl 0x824905e0
	ctx.lr = 0x823C2B88;
	sub_824905E0(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// stfs f31,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stfs f31,64(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stfs f31,60(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// stfs f31,56(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stfs f31,68(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stb r26,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r26.u8);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// b 0x823c2bc4
	goto loc_823C2BC4;
loc_823C2BC0:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823C2BC4:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2bf4
	if (cr6.eq) goto loc_823C2BF4;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// stw r10,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r10.u32);
	// stw r9,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r9.u32);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c2bec
	if (cr6.eq) goto loc_823C2BEC;
	// stw r11,80(r9)
	PPC_STORE_U32(ctx.r9.u32 + 80, r11.u32);
loc_823C2BEC:
	// stw r11,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, r11.u32);
	// b 0x823c2bf8
	goto loc_823C2BF8;
loc_823C2BF4:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823C2BF8:
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// bne 0x823c2b70
	if (!cr0.eq) goto loc_823C2B70;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823C2C14"))) PPC_WEAK_FUNC(sub_823C2C14);
PPC_FUNC_IMPL(__imp__sub_823C2C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C2C18"))) PPC_WEAK_FUNC(sub_823C2C18);
PPC_FUNC_IMPL(__imp__sub_823C2C18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2c40
	if (!cr6.eq) goto loc_823C2C40;
	// lwz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_823C2C40:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2c54
	if (!cr6.eq) goto loc_823C2C54;
	// lwz r9,80(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_823C2C54:
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c2c68
	if (cr6.eq) goto loc_823C2C68;
	// lwz r9,80(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// stw r9,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r9.u32);
loc_823C2C68:
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c2c7c
	if (cr6.eq) goto loc_823C2C7C;
	// lwz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// stw r9,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r9.u32);
loc_823C2C7C:
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// li r11,0
	r11.s64 = 0;
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c2cc0
	if (cr6.eq) goto loc_823C2CC0;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// stw r9,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r9.u32);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c2cb4
	if (cr6.eq) goto loc_823C2CB4;
	// stw r3,80(r9)
	PPC_STORE_U32(ctx.r9.u32 + 80, ctx.r3.u32);
loc_823C2CB4:
	// stw r3,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r3.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// blr 
	return;
loc_823C2CC0:
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C2CCC"))) PPC_WEAK_FUNC(sub_823C2CCC);
PPC_FUNC_IMPL(__imp__sub_823C2CCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C2CD0"))) PPC_WEAK_FUNC(sub_823C2CD0);
PPC_FUNC_IMPL(__imp__sub_823C2CD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c2d8c
	if (cr6.eq) goto loc_823C2D8C;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2cf4
	if (!cr6.eq) goto loc_823C2CF4;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_823C2CF4:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c2d08
	if (!cr6.eq) goto loc_823C2D08;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_823C2D08:
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2d1c
	if (cr6.eq) goto loc_823C2D1C;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r9,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, ctx.r9.u32);
loc_823C2D1C:
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2d30
	if (cr6.eq) goto loc_823C2D30;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stw r9,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r9.u32);
loc_823C2D30:
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// stw r8,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r8.u32);
	// stw r8,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r8.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// beq cr6,0x823c2d7c
	if (cr6.eq) goto loc_823C2D7C;
	// lwz r7,76(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// stw r10,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r10.u32);
	// stw r7,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r7.u32);
	// lwz r7,76(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823c2d6c
	if (cr6.eq) goto loc_823C2D6C;
	// stw r11,80(r7)
	PPC_STORE_U32(ctx.r7.u32 + 80, r11.u32);
loc_823C2D6C:
	// stw r11,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_823C2D7C:
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_823C2D8C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C2D98"))) PPC_WEAK_FUNC(sub_823C2D98);
PPC_FUNC_IMPL(__imp__sub_823C2D98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r3,12
	ctx.r6.s64 = ctx.r3.s64 + 12;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823C2DB0:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r8,76
	ctx.r9.s64 = ctx.r8.s64 + 76;
	// lwz r8,76(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c2dd0
	if (!cr6.eq) goto loc_823C2DD0;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_823C2DD0:
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c2de4
	if (!cr6.eq) goto loc_823C2DE4;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
loc_823C2DE4:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2df8
	if (cr6.eq) goto loc_823C2DF8;
	// lwz r4,80(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r4,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, ctx.r4.u32);
loc_823C2DF8:
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2e0c
	if (cr6.eq) goto loc_823C2E0C;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r4,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r4.u32);
loc_823C2E0C:
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stw r5,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r5.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2e44
	if (cr6.eq) goto loc_823C2E44;
	// lwz r4,76(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// stw r10,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r10.u32);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c2e3c
	if (cr6.eq) goto loc_823C2E3C;
	// stw r11,80(r9)
	PPC_STORE_U32(ctx.r9.u32 + 80, r11.u32);
loc_823C2E3C:
	// stw r11,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, r11.u32);
	// b 0x823c2e48
	goto loc_823C2E48;
loc_823C2E44:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_823C2E48:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823c2db0
	if (!cr6.eq) goto loc_823C2DB0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C2E58"))) PPC_WEAK_FUNC(sub_823C2E58);
PPC_FUNC_IMPL(__imp__sub_823C2E58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r6,r3,4
	ctx.r6.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,12
	ctx.r7.s64 = ctx.r3.s64 + 12;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823C2E70:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r8,76
	ctx.r9.s64 = ctx.r8.s64 + 76;
	// lwz r8,76(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c2e90
	if (!cr6.eq) goto loc_823C2E90;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_823C2E90:
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c2ea4
	if (!cr6.eq) goto loc_823C2EA4;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
loc_823C2EA4:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2eb8
	if (cr6.eq) goto loc_823C2EB8;
	// lwz r4,80(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r4,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, ctx.r4.u32);
loc_823C2EB8:
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2ecc
	if (cr6.eq) goto loc_823C2ECC;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r4,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r4.u32);
loc_823C2ECC:
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stw r5,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r5.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2f04
	if (cr6.eq) goto loc_823C2F04;
	// lwz r4,76(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// stw r10,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r10.u32);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c2efc
	if (cr6.eq) goto loc_823C2EFC;
	// stw r11,80(r9)
	PPC_STORE_U32(ctx.r9.u32 + 80, r11.u32);
loc_823C2EFC:
	// stw r11,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, r11.u32);
	// b 0x823c2f08
	goto loc_823C2F08;
loc_823C2F04:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_823C2F08:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823c2e70
	if (!cr6.eq) goto loc_823C2E70;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C2F18"))) PPC_WEAK_FUNC(sub_823C2F18);
PPC_FUNC_IMPL(__imp__sub_823C2F18) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823C2F20;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-25732
	ctx.r10.s64 = r11.s64 + -25732;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r30.u32);
	// addi r29,r28,4
	r29.s64 = r28.s64 + 4;
	// stw r30,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r30.u32);
	// li r26,16
	r26.s64 = 16;
	// stw r30,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r30.u32);
	// addi r27,r11,-15144
	r27.s64 = r11.s64 + -15144;
	// stw r30,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r30.u32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_823C2F64:
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x82130528
	ctx.lr = 0x823C2F6C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c2fb4
	if (cr6.eq) goto loc_823C2FB4;
	// bl 0x824905e0
	ctx.lr = 0x823C2F7C;
	sub_824905E0(ctx, base);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// stfs f31,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stfs f31,56(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stfs f31,52(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// stfs f31,48(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stfs f31,60(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stb r30,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r30.u8);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// b 0x823c2fb8
	goto loc_823C2FB8;
loc_823C2FB4:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823C2FB8:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c2fe8
	if (cr6.eq) goto loc_823C2FE8;
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// stw r10,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r10.u32);
	// stw r9,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r9.u32);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c2fe0
	if (cr6.eq) goto loc_823C2FE0;
	// stw r11,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, r11.u32);
loc_823C2FE0:
	// stw r11,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, r11.u32);
	// b 0x823c2fec
	goto loc_823C2FEC;
loc_823C2FE8:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823C2FEC:
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// bne 0x823c2f64
	if (!cr0.eq) goto loc_823C2F64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823C3008"))) PPC_WEAK_FUNC(sub_823C3008);
PPC_FUNC_IMPL(__imp__sub_823C3008) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c3030
	if (!cr6.eq) goto loc_823C3030;
	// lwz r9,80(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_823C3030:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x823c3044
	if (!cr6.eq) goto loc_823C3044;
	// lwz r9,84(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_823C3044:
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c3058
	if (cr6.eq) goto loc_823C3058;
	// lwz r9,84(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// stw r9,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r9.u32);
loc_823C3058:
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c306c
	if (cr6.eq) goto loc_823C306C;
	// lwz r9,80(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// stw r9,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r9.u32);
loc_823C306C:
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c30b0
	if (cr6.eq) goto loc_823C30B0;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r9,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r9.u32);
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c30a4
	if (cr6.eq) goto loc_823C30A4;
	// stw r3,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, ctx.r3.u32);
loc_823C30A4:
	// stw r3,80(r11)
	PPC_STORE_U32(r11.u32 + 80, ctx.r3.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// blr 
	return;
loc_823C30B0:
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C30BC"))) PPC_WEAK_FUNC(sub_823C30BC);
PPC_FUNC_IMPL(__imp__sub_823C30BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C30C0"))) PPC_WEAK_FUNC(sub_823C30C0);
PPC_FUNC_IMPL(__imp__sub_823C30C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r3,12
	ctx.r6.s64 = ctx.r3.s64 + 12;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823C30D8:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r8,80
	ctx.r9.s64 = ctx.r8.s64 + 80;
	// lwz r8,80(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c30f8
	if (!cr6.eq) goto loc_823C30F8;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_823C30F8:
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c310c
	if (!cr6.eq) goto loc_823C310C;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
loc_823C310C:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c3120
	if (cr6.eq) goto loc_823C3120;
	// lwz r4,84(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stw r4,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r4.u32);
loc_823C3120:
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c3134
	if (cr6.eq) goto loc_823C3134;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r4,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, ctx.r4.u32);
loc_823C3134:
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stw r5,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r5.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c316c
	if (cr6.eq) goto loc_823C316C;
	// lwz r4,80(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// stw r10,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r10.u32);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c3164
	if (cr6.eq) goto loc_823C3164;
	// stw r11,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, r11.u32);
loc_823C3164:
	// stw r11,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, r11.u32);
	// b 0x823c3170
	goto loc_823C3170;
loc_823C316C:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_823C3170:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823c30d8
	if (!cr6.eq) goto loc_823C30D8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C3180"))) PPC_WEAK_FUNC(sub_823C3180);
PPC_FUNC_IMPL(__imp__sub_823C3180) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r6,r3,4
	ctx.r6.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,12
	ctx.r7.s64 = ctx.r3.s64 + 12;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823C3198:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r8,80
	ctx.r9.s64 = ctx.r8.s64 + 80;
	// lwz r8,80(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c31b8
	if (!cr6.eq) goto loc_823C31B8;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_823C31B8:
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c31cc
	if (!cr6.eq) goto loc_823C31CC;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
loc_823C31CC:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c31e0
	if (cr6.eq) goto loc_823C31E0;
	// lwz r4,84(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stw r4,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r4.u32);
loc_823C31E0:
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c31f4
	if (cr6.eq) goto loc_823C31F4;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r4,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, ctx.r4.u32);
loc_823C31F4:
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stw r5,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r5.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c322c
	if (cr6.eq) goto loc_823C322C;
	// lwz r4,80(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// stw r10,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r10.u32);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c3224
	if (cr6.eq) goto loc_823C3224;
	// stw r11,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, r11.u32);
loc_823C3224:
	// stw r11,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, r11.u32);
	// b 0x823c3230
	goto loc_823C3230;
loc_823C322C:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_823C3230:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823c3198
	if (!cr6.eq) goto loc_823C3198;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C3240"))) PPC_WEAK_FUNC(sub_823C3240);
PPC_FUNC_IMPL(__imp__sub_823C3240) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x823C3248;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-25764
	ctx.r10.s64 = r11.s64 + -25764;
	// addi r22,r31,24
	r22.s64 = r31.s64 + 24;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// sth r30,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r30.u16);
	// sth r30,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r30.u16);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// bl 0x821b5a60
	ctx.lr = 0x823C3280;
	sub_821B5A60(ctx, base);
	// addi r26,r31,28
	r26.s64 = r31.s64 + 28;
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r24,60
	r24.s64 = 60;
	// mr r29,r26
	r29.u64 = r26.u64;
	// li r23,3
	r23.s64 = 3;
loc_823C3294:
	// lwzx r28,r24,r25
	r28.u64 = PPC_LOAD_U32(r24.u32 + r25.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823c32ec
	if (cr6.eq) goto loc_823C32EC;
	// lwz r27,0(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c32ec
	if (cr6.eq) goto loc_823C32EC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823C32B8;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823c32ec
	if (cr6.eq) goto loc_823C32EC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x823C32CC;
	sub_8217D890(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c32f0
	if (cr6.eq) goto loc_823C32F0;
	// lwzx r4,r24,r25
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + r25.u32);
	// bl 0x823c5d98
	ctx.lr = 0x823C32E8;
	sub_823C5D98(ctx, base);
	// b 0x823c32f0
	goto loc_823C32F0;
loc_823C32EC:
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_823C32F0:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bge 0x823c3294
	if (!cr0.lt) goto loc_823C3294;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r30,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r30.u32);
	// stw r30,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r30.u32);
	// stw r30,8(r26)
	PPC_STORE_U32(r26.u32 + 8, r30.u32);
	// stw r30,12(r26)
	PPC_STORE_U32(r26.u32 + 12, r30.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_823C3340"))) PPC_WEAK_FUNC(sub_823C3340);
PPC_FUNC_IMPL(__imp__sub_823C3340) {
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
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r11,-10000(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10000);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r11,3908
	ctx.r3.s64 = r11.s64 + 3908;
	// bl 0x823bfe38
	ctx.lr = 0x823C3368;
	sub_823BFE38(ctx, base);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C3380"))) PPC_WEAK_FUNC(sub_823C3380);
PPC_FUNC_IMPL(__imp__sub_823C3380) {
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
	// bl 0x823c19d0
	ctx.lr = 0x823C33A0;
	sub_823C19D0(ctx, base);
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

__attribute__((alias("__imp__sub_823C33C0"))) PPC_WEAK_FUNC(sub_823C33C0);
PPC_FUNC_IMPL(__imp__sub_823C33C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823c1148
	sub_823C1148(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C33D0"))) PPC_WEAK_FUNC(sub_823C33D0);
PPC_FUNC_IMPL(__imp__sub_823C33D0) {
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
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x823c1348
	ctx.lr = 0x823C3404;
	sub_823C1348(ctx, base);
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

__attribute__((alias("__imp__sub_823C3420"))) PPC_WEAK_FUNC(sub_823C3420);
PPC_FUNC_IMPL(__imp__sub_823C3420) {
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
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x823c1520
	ctx.lr = 0x823C3458;
	sub_823C1520(ctx, base);
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

__attribute__((alias("__imp__sub_823C3474"))) PPC_WEAK_FUNC(sub_823C3474);
PPC_FUNC_IMPL(__imp__sub_823C3474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C3478"))) PPC_WEAK_FUNC(sub_823C3478);
PPC_FUNC_IMPL(__imp__sub_823C3478) {
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
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// bl 0x823c1788
	ctx.lr = 0x823C34B4;
	sub_823C1788(ctx, base);
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

__attribute__((alias("__imp__sub_823C34D0"))) PPC_WEAK_FUNC(sub_823C34D0);
PPC_FUNC_IMPL(__imp__sub_823C34D0) {
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
	// lwz r11,272(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 272);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bne cr6,0x823c3504
	if (!cr6.eq) goto loc_823C3504;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// beq cr6,0x823c3528
	if (cr6.eq) goto loc_823C3528;
loc_823C3504:
	// lwz r3,264(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// bl 0x824a3478
	ctx.lr = 0x823C350C;
	sub_824A3478(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c351c
	if (cr6.eq) goto loc_823C351C;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_823C351C:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c3504
	if (!cr6.eq) goto loc_823C3504;
loc_823C3528:
	// lwz r3,272(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 272);
	// bl 0x823c25a8
	ctx.lr = 0x823C3530;
	sub_823C25A8(ctx, base);
	// lwz r11,276(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bne cr6,0x823c354c
	if (!cr6.eq) goto loc_823C354C;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// beq cr6,0x823c3570
	if (cr6.eq) goto loc_823C3570;
loc_823C354C:
	// lwz r3,264(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// bl 0x824a3478
	ctx.lr = 0x823C3554;
	sub_824A3478(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c3564
	if (cr6.eq) goto loc_823C3564;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_823C3564:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c354c
	if (!cr6.eq) goto loc_823C354C;
loc_823C3570:
	// lwz r3,276(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// bl 0x823c29a0
	ctx.lr = 0x823C3578;
	sub_823C29A0(ctx, base);
	// lwz r11,280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bne cr6,0x823c3594
	if (!cr6.eq) goto loc_823C3594;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// beq cr6,0x823c35b8
	if (cr6.eq) goto loc_823C35B8;
loc_823C3594:
	// lwz r3,264(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// bl 0x824a3478
	ctx.lr = 0x823C359C;
	sub_824A3478(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c35ac
	if (cr6.eq) goto loc_823C35AC;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_823C35AC:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c3594
	if (!cr6.eq) goto loc_823C3594;
loc_823C35B8:
	// lwz r3,280(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// bl 0x823c2d98
	ctx.lr = 0x823C35C0;
	sub_823C2D98(ctx, base);
	// lwz r11,284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bne cr6,0x823c35dc
	if (!cr6.eq) goto loc_823C35DC;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// beq cr6,0x823c3600
	if (cr6.eq) goto loc_823C3600;
loc_823C35DC:
	// lwz r3,264(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// bl 0x824a3478
	ctx.lr = 0x823C35E4;
	sub_824A3478(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c35f4
	if (cr6.eq) goto loc_823C35F4;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_823C35F4:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c35dc
	if (!cr6.eq) goto loc_823C35DC;
loc_823C3600:
	// lwz r3,284(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// bl 0x823c30c0
	ctx.lr = 0x823C3608;
	sub_823C30C0(ctx, base);
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

__attribute__((alias("__imp__sub_823C3620"))) PPC_WEAK_FUNC(sub_823C3620);
PPC_FUNC_IMPL(__imp__sub_823C3620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
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
	ctx.lr = 0x823C3628;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823c34d0
	ctx.lr = 0x823C3634;
	sub_823C34D0(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r10,r31,96
	ctx.r10.s64 = r31.s64 + 96;
	// li r11,0
	r11.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// li r6,32
	ctx.r6.s64 = 32;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// li r7,48
	ctx.r7.s64 = 48;
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// addi r9,r31,160
	ctx.r9.s64 = r31.s64 + 160;
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lis r29,-32256
	r29.s64 = -2113929216;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r4,-11472
	r30.s64 = ctx.r4.s64 + -11472;
	// stvx128 v60,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,-32115
	r28.s64 = -2104688640;
	// stvx128 v59,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r27,1
	r27.s64 = 1;
	// stvx128 v63,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r31,36
	ctx.r10.s64 = r31.s64 + 36;
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// stvx128 v57,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,272(r30)
	PPC_STORE_U8(r30.u32 + 272, r11.u8);
	// stvx128 v56,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,228(r31)
	PPC_STORE_U8(r31.u32 + 228, r11.u8);
	// lfs f13,21528(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 21528);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,288(r31)
	PPC_STORE_U8(r31.u32 + 288, r11.u8);
	// stfs f0,296(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 296, temp.u32);
	// stb r11,341(r31)
	PPC_STORE_U8(r31.u32 + 341, r11.u8);
	// stfs f13,224(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// stw r11,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r11.u32);
	// stw r8,300(r31)
	PPC_STORE_U32(r31.u32 + 300, ctx.r8.u32);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// stw r11,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r11.u32);
	// stw r11,352(r31)
	PPC_STORE_U32(r31.u32 + 352, r11.u32);
	// stb r11,356(r31)
	PPC_STORE_U8(r31.u32 + 356, r11.u8);
	// stb r11,292(r31)
	PPC_STORE_U8(r31.u32 + 292, r11.u8);
	// stb r11,293(r31)
	PPC_STORE_U8(r31.u32 + 293, r11.u8);
	// stb r11,289(r31)
	PPC_STORE_U8(r31.u32 + 289, r11.u8);
	// stb r11,290(r31)
	PPC_STORE_U8(r31.u32 + 290, r11.u8);
	// stb r11,291(r31)
	PPC_STORE_U8(r31.u32 + 291, r11.u8);
	// stb r11,304(r31)
	PPC_STORE_U8(r31.u32 + 304, r11.u8);
	// stb r11,305(r31)
	PPC_STORE_U8(r31.u32 + 305, r11.u8);
	// stb r11,316(r31)
	PPC_STORE_U8(r31.u32 + 316, r11.u8);
	// stb r11,317(r31)
	PPC_STORE_U8(r31.u32 + 317, r11.u8);
	// stfs f0,308(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 308, temp.u32);
	// stw r8,312(r31)
	PPC_STORE_U32(r31.u32 + 312, ctx.r8.u32);
	// lfs f0,14192(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,324(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 324, temp.u32);
	// stb r11,318(r31)
	PPC_STORE_U8(r31.u32 + 318, r11.u8);
	// stfs f0,328(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 328, temp.u32);
	// stb r11,319(r31)
	PPC_STORE_U8(r31.u32 + 319, r11.u8);
	// stb r11,320(r31)
	PPC_STORE_U8(r31.u32 + 320, r11.u8);
	// stb r11,332(r31)
	PPC_STORE_U8(r31.u32 + 332, r11.u8);
	// stb r11,333(r31)
	PPC_STORE_U8(r31.u32 + 333, r11.u8);
	// stb r11,334(r31)
	PPC_STORE_U8(r31.u32 + 334, r11.u8);
	// stb r11,335(r31)
	PPC_STORE_U8(r31.u32 + 335, r11.u8);
	// stb r27,3892(r31)
	PPC_STORE_U8(r31.u32 + 3892, r27.u8);
	// stb r11,128(r30)
	PPC_STORE_U8(r30.u32 + 128, r11.u8);
	// stb r10,-11472(r4)
	PPC_STORE_U8(ctx.r4.u32 + -11472, ctx.r10.u8);
	// stb r9,-11756(r28)
	PPC_STORE_U8(r28.u32 + -11756, ctx.r9.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823C3770"))) PPC_WEAK_FUNC(sub_823C3770);
PPC_FUNC_IMPL(__imp__sub_823C3770) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// bl 0x823d6a00
	ctx.lr = 0x823C3790;
	sub_823D6A00(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,268(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,364(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 364, temp.u32);
	// bl 0x823c34d0
	ctx.lr = 0x823C37AC;
	sub_823C34D0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lfs f0,14192(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,324(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 324, temp.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stfs f0,328(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 328, temp.u32);
	// bl 0x823bbe80
	ctx.lr = 0x823C37C8;
	sub_823BBE80(ctx, base);
	// bl 0x823bb520
	ctx.lr = 0x823C37CC;
	sub_823BB520(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823c37e4
	if (cr6.eq) goto loc_823C37E4;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,319(r11)
	PPC_STORE_U8(r11.u32 + 319, ctx.r10.u8);
loc_823C37E4:
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

__attribute__((alias("__imp__sub_823C37F8"))) PPC_WEAK_FUNC(sub_823C37F8);
PPC_FUNC_IMPL(__imp__sub_823C37F8) {
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
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823C3800;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r28,r11,-11200
	r28.s64 = r11.s64 + -11200;
	// addi r3,r10,-25632
	ctx.r3.s64 = ctx.r10.s64 + -25632;
	// addi r4,r28,-144
	ctx.r4.s64 = r28.s64 + -144;
	// bl 0x82130000
	ctx.lr = 0x823C381C;
	sub_82130000(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r11,r30
	r11.u64 = r30.u64;
	// stb r11,-11756(r9)
	PPC_STORE_U8(ctx.r9.u32 + -11756, r11.u8);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r11,236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 236);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823c3850
	if (cr6.eq) goto loc_823C3850;
	// bctrl 
	ctx.lr = 0x823C384C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823c3854
	goto loc_823C3854;
loc_823C3850:
	// bctrl 
	ctx.lr = 0x823C3854;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C3854:
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 240);
	// lwz r11,244(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 244);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823c3874
	if (cr6.eq) goto loc_823C3874;
	// bctrl 
	ctx.lr = 0x823C3870;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823c3878
	goto loc_823C3878;
loc_823C3874:
	// bctrl 
	ctx.lr = 0x823C3878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C3878:
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// addi r9,r10,0
	ctx.r9.s64 = ctx.r10.s64 + 0;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,240(r11)
	PPC_STORE_U64(r11.u32 + 240, ctx.r8.u64);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lbz r7,316(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 316);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823c38c0
	if (cr6.eq) goto loc_823C38C0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12560(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12560);
	// bl 0x821f6238
	ctx.lr = 0x823C38B4;
	sub_821F6238(ctx, base);
	// lwz r3,-12012(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x823C38BC;
	sub_821F15C8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
loc_823C38C0:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stb r30,317(r11)
	PPC_STORE_U8(r11.u32 + 317, r30.u8);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r29,-1
	r29.s64 = -1;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// li r3,1
	ctx.r3.s64 = 1;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r30,228(r11)
	PPC_STORE_U8(r11.u32 + 228, r30.u8);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r30,318(r11)
	PPC_STORE_U8(r11.u32 + 318, r30.u8);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r30,319(r11)
	PPC_STORE_U8(r11.u32 + 319, r30.u8);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r7,300(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 300);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r10,r8,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// addi r7,r10,3
	ctx.r7.s64 = ctx.r10.s64 + 3;
	// stw r7,436(r11)
	PPC_STORE_U32(r11.u32 + 436, ctx.r7.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stw r29,300(r11)
	PPC_STORE_U32(r11.u32 + 300, r29.u32);
	// bl 0x822f1720
	ctx.lr = 0x823C3954;
	sub_822F1720(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823bbee0
	ctx.lr = 0x823C395C;
	sub_823BBEE0(ctx, base);
	// addi r3,r28,-144
	ctx.r3.s64 = r28.s64 + -144;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x823bef90
	ctx.lr = 0x823C3968;
	sub_823BEF90(ctx, base);
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lwz r11,-18004(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18004);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c3988
	if (cr6.eq) goto loc_823C3988;
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lbz r10,333(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 333);
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
loc_823C3988:
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// bl 0x823d6a00
	ctx.lr = 0x823C3994;
	sub_823D6A00(ctx, base);
	// mr r11,r30
	r11.u64 = r30.u64;
	// lwz r3,-10000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r11,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r11.u8);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r9,268(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// stfs f0,364(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 364, temp.u32);
	// bl 0x823c34d0
	ctx.lr = 0x823C39B8;
	sub_823C34D0(ctx, base);
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r30,828(r10)
	PPC_STORE_U32(ctx.r10.u32 + 828, r30.u32);
	// lwz r9,-10000(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// addi r10,r9,2512
	ctx.r10.s64 = ctx.r9.s64 + 2512;
	// addi r8,r9,832
	ctx.r8.s64 = ctx.r9.s64 + 832;
	// addi r9,r9,3792
	ctx.r9.s64 = ctx.r9.s64 + 3792;
loc_823C39D4:
	// stw r29,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r29.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// stb r30,-1280(r10)
	PPC_STORE_U8(ctx.r10.u32 + -1280, r30.u8);
	// stb r30,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r30.u8);
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// stbx r30,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, r30.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,20
	cr6.compare<int32_t>(r11.s32, 20, xer);
	// blt cr6,0x823c39d4
	if (cr6.lt) goto loc_823C39D4;
	// lwz r9,-10000(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r10,r9,3812
	ctx.r10.s64 = ctx.r9.s64 + 3812;
	// addi r9,r9,3876
	ctx.r9.s64 = ctx.r9.s64 + 3876;
loc_823C3A08:
	// stw r29,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r29.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stbx r30,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, r30.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// blt cr6,0x823c3a08
	if (cr6.lt) goto loc_823C3A08;
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r27,1
	r27.s64 = 1;
	// stb r11,-144(r28)
	PPC_STORE_U8(r28.u32 + -144, r11.u8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stb r27,3892(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3892, r27.u8);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r27,444(r11)
	PPC_STORE_U8(r11.u32 + 444, r27.u8);
	// lwz r3,-10008(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10008);
	// bl 0x823ce958
	ctx.lr = 0x823C3A48;
	sub_823CE958(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-27436(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27436);
	// bl 0x823d3818
	ctx.lr = 0x823C3A58;
	sub_823D3818(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,17268(r7)
	r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17268);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e80f8
	ctx.lr = 0x823C3A6C;
	sub_821E80F8(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823c3a8c
	if (cr6.eq) goto loc_823C3A8C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a3998
	ctx.lr = 0x823C3A84;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a93a8
	ctx.lr = 0x823C3A8C;
	sub_822A93A8(ctx, base);
loc_823C3A8C:
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,3896(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3896);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c3aa4
	if (cr6.eq) goto loc_823C3AA4;
	// bl 0x821f5ed8
	ctx.lr = 0x823C3AA0;
	sub_821F5ED8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
loc_823C3AA4:
	// lwz r3,3896(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3896);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c3ab8
	if (cr6.eq) goto loc_823C3AB8;
	// bl 0x821f5ed8
	ctx.lr = 0x823C3AB4;
	sub_821F5ED8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
loc_823C3AB8:
	// lbz r10,341(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 341);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c3b94
	if (cr6.eq) goto loc_823C3B94;
	// lwz r11,344(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c3ad8
	if (cr6.eq) goto loc_823C3AD8;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x823c3ae0
	goto loc_823C3AE0;
loc_823C3AD8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
loc_823C3AE0:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25728
	ctx.r3.s64 = r11.s64 + -25728;
	// bl 0x82130000
	ctx.lr = 0x823C3AEC;
	sub_82130000(ctx, base);
	// lwz r3,-12012(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -12012);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r9,2260(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x823c3b5c
	if (!cr6.eq) goto loc_823C3B5C;
	// lwz r10,2256(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c3b20
	if (cr6.eq) goto loc_823C3B20;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// bne cr6,0x823c3b24
	if (!cr6.eq) goto loc_823C3B24;
loc_823C3B20:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_823C3B24:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c3b44
	if (cr6.eq) goto loc_823C3B44;
	// lwz r10,2256(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// lbz r9,467(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 467);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c3b48
	if (cr6.eq) goto loc_823C3B48;
loc_823C3B44:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_823C3B48:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823c3b5c
	if (!cr6.eq) goto loc_823C3B5C;
	// bl 0x821f15c8
	ctx.lr = 0x823C3B58;
	sub_821F15C8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
loc_823C3B5C:
	// stb r30,341(r11)
	PPC_STORE_U8(r11.u32 + 341, r30.u8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stw r30,344(r11)
	PPC_STORE_U32(r11.u32 + 344, r30.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stw r30,352(r11)
	PPC_STORE_U32(r11.u32 + 352, r30.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stw r30,348(r11)
	PPC_STORE_U32(r11.u32 + 348, r30.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r30,356(r11)
	PPC_STORE_U8(r11.u32 + 356, r30.u8);
	// lwz r11,-12288(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12288);
	// stb r27,1079(r11)
	PPC_STORE_U8(r11.u32 + 1079, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823C3B94:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12288(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// stb r27,1079(r11)
	PPC_STORE_U8(r11.u32 + 1079, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823C3BA8"))) PPC_WEAK_FUNC(sub_823C3BA8);
PPC_FUNC_IMPL(__imp__sub_823C3BA8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823C3BB0;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r25,0
	r25.s64 = 0;
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r26,368(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 368);
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c3bf8
	if (cr6.eq) goto loc_823C3BF8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823c3bfc
	if (cr6.eq) goto loc_823C3BFC;
loc_823C3BF8:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C3BFC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r3,284(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c3cc0
	if (cr6.eq) goto loc_823C3CC0;
	// bl 0x823c3008
	ctx.lr = 0x823C3C10;
	sub_823C3008(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c3d54
	if (cr6.eq) goto loc_823C3D54;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C3C2C;
	sub_823BF2F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823c3cb4
	if (!cr6.eq) goto loc_823C3CB4;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C3C44;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-25528
	ctx.r3.s64 = ctx.r10.s64 + -25528;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x823C3C5C;
	sub_82130000(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f4,f31,f0
	ctx.f4.f64 = double(float(f31.f64 + f0.f64));
loc_823C3C68:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// addi r5,r11,36
	ctx.r5.s64 = r11.s64 + 36;
	// stb r25,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r25.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f2,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// lfs f5,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x823d6cf8
	ctx.lr = 0x823C3C98;
	sub_823D6CF8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C3CA8;
	sub_824A3410(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_823C3CB4:
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// fadds f4,f0,f31
	ctx.f4.f64 = double(float(f0.f64 + f31.f64));
	// b 0x823c3c68
	goto loc_823C3C68;
loc_823C3CC0:
	// bl 0x823c3008
	ctx.lr = 0x823C3CC4;
	sub_823C3008(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823c3d54
	if (cr6.eq) goto loc_823C3D54;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823ce2d0
	ctx.lr = 0x823C3CE4;
	sub_823CE2D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823c3d00
	if (cr6.eq) goto loc_823C3D00;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fadds f4,f0,f31
	ctx.f4.f64 = double(float(f0.f64 + f31.f64));
	// b 0x823c3d0c
	goto loc_823C3D0C;
loc_823C3D00:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f4,f31,f0
	ctx.f4.f64 = double(float(f31.f64 + f0.f64));
loc_823C3D0C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// addi r5,r11,36
	ctx.r5.s64 = r11.s64 + 36;
	// stb r25,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r25.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f2,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// lfs f5,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x823d6ca0
	ctx.lr = 0x823C3D38;
	sub_823D6CA0(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C3D48;
	sub_824A3410(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_823C3D54:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25592
	ctx.r3.s64 = r11.s64 + -25592;
	// bl 0x82130000
	ctx.lr = 0x823C3D60;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823C3D6C"))) PPC_WEAK_FUNC(sub_823C3D6C);
PPC_FUNC_IMPL(__imp__sub_823C3D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C3D70"))) PPC_WEAK_FUNC(sub_823C3D70);
PPC_FUNC_IMPL(__imp__sub_823C3D70) {
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
	ctx.lr = 0x823C3D78;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// li r24,0
	r24.s64 = 0;
	// lwz r10,-10000(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -10000);
	// lwz r27,368(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 368);
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c3dc4
	if (cr6.eq) goto loc_823C3DC4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823c3dc8
	if (cr6.eq) goto loc_823C3DC8;
loc_823C3DC4:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_823C3DC8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r3,284(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c3e88
	if (cr6.eq) goto loc_823C3E88;
	// bl 0x823c3008
	ctx.lr = 0x823C3DDC;
	sub_823C3008(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823c3f18
	if (cr6.eq) goto loc_823C3F18;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C3DF8;
	sub_823BF2F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823c3e7c
	if (!cr6.eq) goto loc_823C3E7C;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C3E10;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-25376
	ctx.r3.s64 = ctx.r10.s64 + -25376;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x823C3E28;
	sub_82130000(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f4,f31,f0
	ctx.f4.f64 = double(float(f31.f64 + f0.f64));
loc_823C3E34:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r24,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r24.u8);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f2,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// lfs f5,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x823d6cf8
	ctx.lr = 0x823C3E60;
	sub_823D6CF8(ctx, base);
	// lwz r11,-10000(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10000);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C3E70;
	sub_824A3410(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823C3E7C:
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// fadds f4,f0,f31
	ctx.f4.f64 = double(float(f0.f64 + f31.f64));
	// b 0x823c3e34
	goto loc_823C3E34;
loc_823C3E88:
	// bl 0x823c3008
	ctx.lr = 0x823C3E8C;
	sub_823C3008(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c3f18
	if (cr6.eq) goto loc_823C3F18;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823ce2d0
	ctx.lr = 0x823C3EAC;
	sub_823CE2D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823c3ec8
	if (cr6.eq) goto loc_823C3EC8;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fadds f4,f0,f31
	ctx.f4.f64 = double(float(f0.f64 + f31.f64));
	// b 0x823c3ed4
	goto loc_823C3ED4;
loc_823C3EC8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f4,f31,f0
	ctx.f4.f64 = double(float(f31.f64 + f0.f64));
loc_823C3ED4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r24,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r24.u8);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f2,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// lfs f5,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x823d6ca0
	ctx.lr = 0x823C3EFC;
	sub_823D6CA0(ctx, base);
	// lwz r11,-10000(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10000);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C3F0C;
	sub_824A3410(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823C3F18:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25448
	ctx.r3.s64 = r11.s64 + -25448;
	// bl 0x82130000
	ctx.lr = 0x823C3F24;
	sub_82130000(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823C3F30"))) PPC_WEAK_FUNC(sub_823C3F30);
PPC_FUNC_IMPL(__imp__sub_823C3F30) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823C3F38;
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// li r25,0
	r25.s64 = 0;
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r26,368(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 368);
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c3f90
	if (cr6.eq) goto loc_823C3F90;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823c3f94
	if (cr6.eq) goto loc_823C3F94;
loc_823C3F90:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C3F94:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r3,284(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c4060
	if (cr6.eq) goto loc_823C4060;
	// bl 0x823c3008
	ctx.lr = 0x823C3FA8;
	sub_823C3008(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c40fc
	if (cr6.eq) goto loc_823C40FC;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C3FC4;
	sub_823BF2F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823c4054
	if (!cr6.eq) goto loc_823C4054;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C3FDC;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-25376
	ctx.r3.s64 = ctx.r10.s64 + -25376;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x823C3FF4;
	sub_82130000(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f0,f31,f0
	f0.f64 = double(float(f31.f64 + f0.f64));
loc_823C4000:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f5,f30
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = f30.f64;
	// addi r5,r11,36
	ctx.r5.s64 = r11.s64 + 36;
	// fsubs f4,f0,f29
	ctx.f4.f64 = double(float(f0.f64 - f29.f64));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r25,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r25.u8);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f2,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x823d6cf8
	ctx.lr = 0x823C4030;
	sub_823D6CF8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C4040;
	sub_824A3410(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_823C4054:
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	f0.f64 = double(float(f0.f64 + f31.f64));
	// b 0x823c4000
	goto loc_823C4000;
loc_823C4060:
	// bl 0x823c3008
	ctx.lr = 0x823C4064;
	sub_823C3008(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823c40fc
	if (cr6.eq) goto loc_823C40FC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823ce2d0
	ctx.lr = 0x823C4084;
	sub_823CE2D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823c40a0
	if (cr6.eq) goto loc_823C40A0;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	f0.f64 = double(float(f0.f64 + f31.f64));
	// b 0x823c40ac
	goto loc_823C40AC;
loc_823C40A0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f0,f31,f0
	f0.f64 = double(float(f31.f64 + f0.f64));
loc_823C40AC:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f5,f30
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = f30.f64;
	// addi r5,r11,36
	ctx.r5.s64 = r11.s64 + 36;
	// fsubs f4,f0,f29
	ctx.f4.f64 = double(float(f0.f64 - f29.f64));
	// stb r25,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r25.u8);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f2,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x823d6ca0
	ctx.lr = 0x823C40D8;
	sub_823D6CA0(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C40E8;
	sub_824A3410(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_823C40FC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25296
	ctx.r3.s64 = r11.s64 + -25296;
	// bl 0x82130000
	ctx.lr = 0x823C4108;
	sub_82130000(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823C411C"))) PPC_WEAK_FUNC(sub_823C411C);
PPC_FUNC_IMPL(__imp__sub_823C411C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C4120"))) PPC_WEAK_FUNC(sub_823C4120);
PPC_FUNC_IMPL(__imp__sub_823C4120) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C4128;
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f29.u64);
	// stfd f30,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r3,284(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 284);
	// bl 0x823c3008
	ctx.lr = 0x823C4158;
	sub_823C3008(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c41b8
	if (cr6.eq) goto loc_823C41B8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f4,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f31.f64 + f29.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r9,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r9.u8);
	// lfs f5,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// lfs f2,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823d6cf8
	ctx.lr = 0x823C4194;
	sub_823D6CF8(ctx, base);
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C41A4;
	sub_824A3410(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_823C41B8:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25592
	ctx.r3.s64 = r11.s64 + -25592;
	// bl 0x82130000
	ctx.lr = 0x823C41C4;
	sub_82130000(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C41D8"))) PPC_WEAK_FUNC(sub_823C41D8);
PPC_FUNC_IMPL(__imp__sub_823C41D8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x823C41E0;
	// stfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r17,r9
	r17.u64 = ctx.r9.u64;
	// lis r24,12288
	r24.s64 = 805306368;
	// lwz r23,336(r11)
	r23.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r23,1
	ctx.r10.s64 = r23.s64 + 1;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// lwz r10,-10000(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lwz r21,368(r10)
	r21.u64 = PPC_LOAD_U32(ctx.r10.u32 + 368);
	// lwz r11,12(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c4244
	if (cr6.eq) goto loc_823C4244;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r24
	cr6.compare<int32_t>(ctx.r9.s32, r24.s32, xer);
	// beq cr6,0x823c4248
	if (cr6.eq) goto loc_823C4248;
loc_823C4244:
	// li r11,0
	r11.s64 = 0;
loc_823C4248:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r3,276(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c4570
	if (cr6.eq) goto loc_823C4570;
	// bl 0x823c2820
	ctx.lr = 0x823C425C;
	sub_823C2820(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x823c4554
	if (cr6.eq) goto loc_823C4554;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C427C;
	sub_823CA248(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x823c4530
	if (cr6.eq) goto loc_823C4530;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C4298;
	sub_823BF2F0(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// addi r29,r11,-24840
	r29.s64 = r11.s64 + -24840;
	// bne cr6,0x823c42cc
	if (!cr6.eq) goto loc_823C42CC;
	// lwz r11,12(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C42B8;
	sub_823B8690(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x823C42CC;
	sub_82130000(ctx, base);
loc_823C42CC:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823bba48
	ctx.lr = 0x823C42DC;
	sub_823BBA48(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C42EC;
	sub_823BF2F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x823c4324
	if (cr6.eq) goto loc_823C4324;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823c448c
	if (!cr6.eq) goto loc_823C448C;
	// lwz r11,12(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C430C;
	sub_823B8690(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x823C4320;
	sub_82130000(ctx, base);
	// b 0x823c432c
	goto loc_823C432C;
loc_823C4324:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823c448c
	if (!cr6.eq) goto loc_823C448C;
loc_823C432C:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x823c448c
	if (cr6.eq) goto loc_823C448C;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lwz r10,364(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c435c
	if (cr6.eq) goto loc_823C435C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,0,2,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r10,r24
	cr6.compare<int32_t>(ctx.r10.s32, r24.s32, xer);
	// beq cr6,0x823c4360
	if (cr6.eq) goto loc_823C4360;
loc_823C435C:
	// li r11,0
	r11.s64 = 0;
loc_823C4360:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c448c
	if (cr6.eq) goto loc_823C448C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r4,r11,-27776
	ctx.r4.s64 = r11.s64 + -27776;
	// bl 0x823d90b0
	ctx.lr = 0x823C437C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c446c
	if (cr6.eq) goto loc_823C446C;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,-22544
	r30.s64 = r11.s64 + -22544;
	// addi r31,r30,-20
	r31.s64 = r30.s64 + -20;
loc_823C4394:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823d90b0
	ctx.lr = 0x823C43A0;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r30,-20
	r11.s64 = r30.s64 + -20;
	// bne cr6,0x823c4454
	if (!cr6.eq) goto loc_823C4454;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x823c4394
	if (cr6.lt) goto loc_823C4394;
	// li r27,0
	r27.s64 = 0;
loc_823C43C4:
	// mr r31,r30
	r31.u64 = r30.u64;
	// li r29,0
	r29.s64 = 0;
loc_823C43CC:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823d90b0
	ctx.lr = 0x823C43D8;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823c4460
	if (!cr6.eq) goto loc_823C4460;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r30,20
	r11.s64 = r30.s64 + 20;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x823c43cc
	if (cr6.lt) goto loc_823C43CC;
	// li r31,0
	r31.s64 = 0;
loc_823C43F8:
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r5,364(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// bl 0x823bf250
	ctx.lr = 0x823C440C;
	sub_823BF250(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823c448c
	if (!cr6.eq) goto loc_823C448C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c446c
	if (cr6.eq) goto loc_823C446C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c446c
	if (cr6.eq) goto loc_823C446C;
	// lwz r11,12(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C4434;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-24952
	ctx.r3.s64 = ctx.r10.s64 + -24952;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// bl 0x82130000
	ctx.lr = 0x823C4450;
	sub_82130000(ctx, base);
	// b 0x823c448c
	goto loc_823C448C;
loc_823C4454:
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r10,r11
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// b 0x823c43c4
	goto loc_823C43C4;
loc_823C4460:
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r30
	r31.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// b 0x823c43f8
	goto loc_823C43F8;
loc_823C446C:
	// lwz r11,12(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C4478;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r10,-25056
	ctx.r3.s64 = ctx.r10.s64 + -25056;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x82130000
	ctx.lr = 0x823C448C;
	sub_82130000(ctx, base);
loc_823C448C:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x823c44b4
	if (cr6.eq) goto loc_823C44B4;
	// extsw r11,r17
	r11.s64 = r17.s32;
	// lfs f0,12(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r20.u32 + 12);
	f0.f64 = double(temp.f32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f2,f0,f11,f31
	ctx.f2.f64 = double(float(f0.f64 * ctx.f11.f64 + f31.f64));
	// b 0x823c44c0
	goto loc_823C44C0;
loc_823C44B4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C44C0:
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// mr r9,r17
	ctx.r9.u64 = r17.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r8,r11,36
	ctx.r8.s64 = r11.s64 + 36;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823d6a68
	ctx.lr = 0x823C44E8;
	sub_823D6A68(ctx, base);
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C44F8;
	sub_824A3410(ctx, base);
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c46bc
	if (!cr6.lt) goto loc_823C46BC;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r23,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r23.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
loc_823C4530:
	// stw r19,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r19.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lwz r3,276(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// bl 0x823c28d8
	ctx.lr = 0x823C4544;
	sub_823C28D8(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
loc_823C4554:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25144
	ctx.r3.s64 = r11.s64 + -25144;
	// bl 0x82130000
	ctx.lr = 0x823C4560;
	sub_82130000(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
loc_823C4570:
	// bl 0x823c2820
	ctx.lr = 0x823C4574;
	sub_823C2820(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c46ac
	if (cr6.eq) goto loc_823C46AC;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-4960(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C4594;
	sub_823CA248(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c4688
	if (cr6.eq) goto loc_823C4688;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823bba48
	ctx.lr = 0x823C45B0;
	sub_823BBA48(ctx, base);
	// lwz r11,-4960(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4960);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C45C8;
	sub_823CAAB8(ctx, base);
	// lwz r11,-4960(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4960);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C45E0;
	sub_823CAAB8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c4610
	if (cr6.eq) goto loc_823C4610;
	// extsw r11,r17
	r11.s64 = r17.s32;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfs f0,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f2,f0,f11,f31
	ctx.f2.f64 = double(float(f0.f64 * ctx.f11.f64 + f31.f64));
	// b 0x823c461c
	goto loc_823C461C;
loc_823C4610:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C461C:
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// mr r9,r17
	ctx.r9.u64 = r17.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r8,r11,36
	ctx.r8.s64 = r11.s64 + 36;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d6a18
	ctx.lr = 0x823C4640;
	sub_823D6A18(ctx, base);
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C4650;
	sub_824A3410(ctx, base);
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c46b8
	if (!cr6.lt) goto loc_823C46B8;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r23,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r23.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
loc_823C4688:
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lwz r3,276(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// bl 0x823c28d8
	ctx.lr = 0x823C469C;
	sub_823C28D8(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
loc_823C46AC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25224
	ctx.r3.s64 = r11.s64 + -25224;
	// bl 0x82130000
	ctx.lr = 0x823C46B8;
	sub_82130000(ctx, base);
loc_823C46B8:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_823C46BC:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_823C46C8"))) PPC_WEAK_FUNC(sub_823C46C8);
PPC_FUNC_IMPL(__imp__sub_823C46C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x823C46D0;
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r19,r10
	r19.u64 = ctx.r10.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// mr r20,r9
	r20.u64 = ctx.r9.u64;
	// lwz r29,336(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r30,368(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 368);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c4738
	if (cr6.eq) goto loc_823C4738;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823c473c
	if (cr6.eq) goto loc_823C473C;
loc_823C4738:
	// li r11,0
	r11.s64 = 0;
loc_823C473C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r3,276(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c48f4
	if (cr6.eq) goto loc_823C48F4;
	// bl 0x823c2820
	ctx.lr = 0x823C4750;
	sub_823C2820(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x823c48d8
	if (cr6.eq) goto loc_823C48D8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C4770;
	sub_823CA248(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x823c48b4
	if (cr6.eq) goto loc_823C48B4;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C478C;
	sub_823BF2F0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// addi r25,r11,-24840
	r25.s64 = r11.s64 + -24840;
	// bne cr6,0x823c47c0
	if (!cr6.eq) goto loc_823C47C0;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C47AC;
	sub_823B8690(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130000
	ctx.lr = 0x823C47C0;
	sub_82130000(ctx, base);
loc_823C47C0:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823bba48
	ctx.lr = 0x823C47D0;
	sub_823BBA48(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C47E0;
	sub_823BF2F0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x823c4814
	if (cr6.eq) goto loc_823C4814;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x823c4814
	if (!cr6.eq) goto loc_823C4814;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C4800;
	sub_823B8690(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130000
	ctx.lr = 0x823C4814;
	sub_82130000(ctx, base);
loc_823C4814:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c483c
	if (cr6.eq) goto loc_823C483C;
	// extsw r11,r20
	r11.s64 = r20.s32;
	// lfs f0,12(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 12);
	f0.f64 = double(temp.f32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f2,f0,f11,f31
	ctx.f2.f64 = double(float(f0.f64 * ctx.f11.f64 + f31.f64));
	// b 0x823c4848
	goto loc_823C4848;
loc_823C483C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C4848:
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823d6a68
	ctx.lr = 0x823C486C;
	sub_823D6A68(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C487C;
	sub_824A3410(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c4a3c
	if (!cr6.lt) goto loc_823C4A3C;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r29.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_823C48B4:
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r22.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,276(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// bl 0x823c28d8
	ctx.lr = 0x823C48C8;
	sub_823C28D8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_823C48D8:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25144
	ctx.r3.s64 = r11.s64 + -25144;
	// bl 0x82130000
	ctx.lr = 0x823C48E4;
	sub_82130000(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_823C48F4:
	// bl 0x823c2820
	ctx.lr = 0x823C48F8;
	sub_823C2820(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c4a2c
	if (cr6.eq) goto loc_823C4A2C;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C4918;
	sub_823CA248(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x823c4a08
	if (cr6.eq) goto loc_823C4A08;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823bba48
	ctx.lr = 0x823C4934;
	sub_823BBA48(ctx, base);
	// lwz r11,-4960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C494C;
	sub_823CAAB8(ctx, base);
	// lwz r11,-4960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C4964;
	sub_823CAAB8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823c4994
	if (cr6.eq) goto loc_823C4994;
	// extsw r11,r20
	r11.s64 = r20.s32;
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfs f0,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f2,f0,f11,f31
	ctx.f2.f64 = double(float(f0.f64 * ctx.f11.f64 + f31.f64));
	// b 0x823c49a0
	goto loc_823C49A0;
loc_823C4994:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C49A0:
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823d6a18
	ctx.lr = 0x823C49C0;
	sub_823D6A18(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C49D0;
	sub_824A3410(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c4a38
	if (!cr6.lt) goto loc_823C4A38;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r29.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_823C4A08:
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,276(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// bl 0x823c28d8
	ctx.lr = 0x823C4A1C;
	sub_823C28D8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_823C4A2C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25224
	ctx.r3.s64 = r11.s64 + -25224;
	// bl 0x82130000
	ctx.lr = 0x823C4A38;
	sub_82130000(ctx, base);
loc_823C4A38:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_823C4A3C:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_823C4A48"))) PPC_WEAK_FUNC(sub_823C4A48);
PPC_FUNC_IMPL(__imp__sub_823C4A48) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x823C4A50;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// lwz r30,336(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r25,368(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 368);
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c4ab0
	if (cr6.eq) goto loc_823C4AB0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823c4ab4
	if (cr6.eq) goto loc_823C4AB4;
loc_823C4AB0:
	// li r11,0
	r11.s64 = 0;
loc_823C4AB4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r3,276(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c4bf4
	if (cr6.eq) goto loc_823C4BF4;
	// bl 0x823c2820
	ctx.lr = 0x823C4AC8;
	sub_823C2820(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c4cdc
	if (cr6.eq) goto loc_823C4CDC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C4AE8;
	sub_823CA248(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c4bd0
	if (cr6.eq) goto loc_823C4BD0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C4B04;
	sub_823BF2F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823c4bb0
	if (!cr6.eq) goto loc_823C4BB0;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C4B1C;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-24744
	ctx.r3.s64 = ctx.r10.s64 + -24744;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x82130000
	ctx.lr = 0x823C4B34;
	sub_82130000(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C4B40:
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r8,r11,36
	ctx.r8.s64 = r11.s64 + 36;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d6a68
	ctx.lr = 0x823C4B68;
	sub_823D6A68(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C4B78;
	sub_824A3410(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c4cec
	if (!cr6.lt) goto loc_823C4CEC;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_823C4BB0:
	// extsw r11,r24
	r11.s64 = r24.s32;
	// lfs f0,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	f0.f64 = double(temp.f32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f2,f0,f11,f31
	ctx.f2.f64 = double(float(f0.f64 * ctx.f11.f64 + f31.f64));
	// b 0x823c4b40
	goto loc_823C4B40;
loc_823C4BD0:
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,276(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// bl 0x823c28d8
	ctx.lr = 0x823C4BE4;
	sub_823C28D8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_823C4BF4:
	// bl 0x823c2820
	ctx.lr = 0x823C4BF8;
	sub_823C2820(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c4cdc
	if (cr6.eq) goto loc_823C4CDC;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C4C18;
	sub_823CA248(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c4bd0
	if (cr6.eq) goto loc_823C4BD0;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C4C34;
	sub_823CAAB8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823c4c64
	if (cr6.eq) goto loc_823C4C64;
	// extsw r11,r24
	r11.s64 = r24.s32;
	// lwz r10,16(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfs f11,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmadds f2,f11,f12,f31
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + f31.f64));
	// b 0x823c4c70
	goto loc_823C4C70;
loc_823C4C64:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C4C70:
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r8,r11,36
	ctx.r8.s64 = r11.s64 + 36;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d6a18
	ctx.lr = 0x823C4C94;
	sub_823D6A18(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C4CA4;
	sub_824A3410(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c4ce8
	if (!cr6.lt) goto loc_823C4CE8;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_823C4CDC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-25224
	ctx.r3.s64 = r11.s64 + -25224;
	// bl 0x82130000
	ctx.lr = 0x823C4CE8;
	sub_82130000(ctx, base);
loc_823C4CE8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823C4CEC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_823C4CF8"))) PPC_WEAK_FUNC(sub_823C4CF8);
PPC_FUNC_IMPL(__imp__sub_823C4CF8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x823C4D00;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r21,r9
	r21.u64 = ctx.r9.u64;
	// lwz r30,336(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r27,368(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 368);
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c4d64
	if (cr6.eq) goto loc_823C4D64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823c4d68
	if (cr6.eq) goto loc_823C4D68;
loc_823C4D64:
	// li r11,0
	r11.s64 = 0;
loc_823C4D68:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r3,276(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c4ea4
	if (cr6.eq) goto loc_823C4EA4;
	// bl 0x823c2820
	ctx.lr = 0x823C4D7C;
	sub_823C2820(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c4f88
	if (cr6.eq) goto loc_823C4F88;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C4D9C;
	sub_823CA248(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x823c4e80
	if (cr6.eq) goto loc_823C4E80;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C4DB8;
	sub_823BF2F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823c4e60
	if (!cr6.eq) goto loc_823C4E60;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C4DD0;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-24576
	ctx.r3.s64 = ctx.r10.s64 + -24576;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x82130000
	ctx.lr = 0x823C4DE8;
	sub_82130000(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C4DF4:
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d6a68
	ctx.lr = 0x823C4E18;
	sub_823D6A68(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C4E28;
	sub_824A3410(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c4f98
	if (!cr6.lt) goto loc_823C4F98;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_823C4E60:
	// extsw r11,r24
	r11.s64 = r24.s32;
	// lfs f0,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	f0.f64 = double(temp.f32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f2,f0,f11,f31
	ctx.f2.f64 = double(float(f0.f64 * ctx.f11.f64 + f31.f64));
	// b 0x823c4df4
	goto loc_823C4DF4;
loc_823C4E80:
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,276(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// bl 0x823c28d8
	ctx.lr = 0x823C4E94;
	sub_823C28D8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_823C4EA4:
	// bl 0x823c2820
	ctx.lr = 0x823C4EA8;
	sub_823C2820(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c4f88
	if (cr6.eq) goto loc_823C4F88;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823C4EC8;
	sub_823CA248(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c4e80
	if (cr6.eq) goto loc_823C4E80;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x823caab8
	ctx.lr = 0x823C4EE4;
	sub_823CAAB8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823c4f14
	if (cr6.eq) goto loc_823C4F14;
	// extsw r11,r24
	r11.s64 = r24.s32;
	// lwz r10,16(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f11,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f2,f11,f12,f31
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + f31.f64));
	// b 0x823c4f20
	goto loc_823C4F20;
loc_823C4F14:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C4F20:
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d6a18
	ctx.lr = 0x823C4F40;
	sub_823D6A18(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C4F50;
	sub_824A3410(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823c4f94
	if (!cr6.lt) goto loc_823C4F94;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_823C4F88:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-24656
	ctx.r3.s64 = r11.s64 + -24656;
	// bl 0x82130000
	ctx.lr = 0x823C4F94;
	sub_82130000(ctx, base);
loc_823C4F94:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823C4F98:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_823C4FA4"))) PPC_WEAK_FUNC(sub_823C4FA4);
PPC_FUNC_IMPL(__imp__sub_823C4FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C4FA8"))) PPC_WEAK_FUNC(sub_823C4FA8);
PPC_FUNC_IMPL(__imp__sub_823C4FA8) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C4FB0;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d8
	ctx.lr = 0x823C4FB8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f29,f2
	f29.f64 = ctx.f2.f64;
	// fmr f28,f3
	f28.f64 = ctx.f3.f64;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r3,272(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 272);
	// bl 0x823c2428
	ctx.lr = 0x823C4FDC;
	sub_823C2428(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c510c
	if (cr6.eq) goto loc_823C510C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d7460
	ctx.lr = 0x823C4FF0;
	sub_823D7460(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,73
	cr6.compare<int32_t>(r31.s32, 73, xer);
	// beq cr6,0x823c5004
	if (cr6.eq) goto loc_823C5004;
	// cmpwi cr6,r31,72
	cr6.compare<int32_t>(r31.s32, 72, xer);
	// bne cr6,0x823c5028
	if (!cr6.eq) goto loc_823C5028;
loc_823C5004:
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r3,248(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 248);
	// lwz r11,252(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 252);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823c5024
	if (cr6.eq) goto loc_823C5024;
	// bctrl 
	ctx.lr = 0x823C5020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823c5028
	goto loc_823C5028;
loc_823C5024:
	// bctrl 
	ctx.lr = 0x823C5028;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C5028:
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lbz r10,319(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 319);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c5050
	if (cr6.eq) goto loc_823C5050;
	// cmpwi cr6,r31,72
	cr6.compare<int32_t>(r31.s32, 72, xer);
	// bne cr6,0x823c5050
	if (!cr6.eq) goto loc_823C5050;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-24416
	ctx.r3.s64 = r11.s64 + -24416;
	// bl 0x82130000
	ctx.lr = 0x823C504C;
	sub_82130000(ctx, base);
	// li r31,74
	r31.s64 = 74;
loc_823C5050:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r31,58
	cr6.compare<int32_t>(r31.s32, 58, xer);
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// beq cr6,0x823c5070
	if (cr6.eq) goto loc_823C5070;
	// cmpwi cr6,r31,72
	cr6.compare<int32_t>(r31.s32, 72, xer);
	// beq cr6,0x823c5070
	if (cr6.eq) goto loc_823C5070;
	// cmpwi cr6,r31,74
	cr6.compare<int32_t>(r31.s32, 74, xer);
	// bne cr6,0x823c50a4
	if (!cr6.eq) goto loc_823C50A4;
loc_823C5070:
	// bl 0x823c1260
	ctx.lr = 0x823C5074;
	sub_823C1260(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c50a4
	if (cr6.eq) goto loc_823C50A4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f13,f0
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// fcmpu cr6,f31,f11
	cr6.compare(f31.f64, ctx.f11.f64);
	// blt cr6,0x823c50a4
	if (cr6.lt) goto loc_823C50A4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// fsubs f31,f31,f0
	f31.f64 = double(float(f31.f64 - f0.f64));
	// lfs f30,-15876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15876);
	f30.f64 = double(temp.f32);
loc_823C50A4:
	// cmpwi cr6,r31,58
	cr6.compare<int32_t>(r31.s32, 58, xer);
	// beq cr6,0x823c50b4
	if (cr6.eq) goto loc_823C50B4;
	// cmpwi cr6,r31,61
	cr6.compare<int32_t>(r31.s32, 61, xer);
	// bne cr6,0x823c50d0
	if (!cr6.eq) goto loc_823C50D0;
loc_823C50B4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,-10000(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lfs f0,30712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	f0.f64 = double(temp.f32);
	// fadds f0,f31,f0
	f0.f64 = double(float(f31.f64 + f0.f64));
	// stfs f0,324(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 324, temp.u32);
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// stfs f30,328(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 328, temp.u32);
loc_823C50D0:
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f3,f28
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f28.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823d7388
	ctx.lr = 0x823C50EC;
	sub_823D7388(ctx, base);
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C50FC;
	sub_824A3410(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba24
	ctx.lr = 0x823C5108;
	// b 0x823d924c
	return;
loc_823C510C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-24488
	ctx.r3.s64 = r11.s64 + -24488;
	// bl 0x82130000
	ctx.lr = 0x823C5118;
	sub_82130000(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba24
	ctx.lr = 0x823C5124;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C5128"))) PPC_WEAK_FUNC(sub_823C5128);
PPC_FUNC_IMPL(__imp__sub_823C5128) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823C5130;
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r3,272(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 272);
	// bl 0x823c2428
	ctx.lr = 0x823C5164;
	sub_823C2428(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c5200
	if (cr6.eq) goto loc_823C5200;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-27432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27432);
	// bl 0x823d6478
	ctx.lr = 0x823C5180;
	sub_823D6478(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c51d8
	if (cr6.eq) goto loc_823C51D8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823d7460
	ctx.lr = 0x823C5198;
	sub_823D7460(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// bl 0x823d7388
	ctx.lr = 0x823C51B4;
	sub_823D7388(ctx, base);
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C51C4;
	sub_824A3410(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_823C51D8:
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r3,272(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 272);
	// bl 0x823c24e0
	ctx.lr = 0x823C51EC;
	sub_823C24E0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_823C5200:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-24304
	ctx.r3.s64 = r11.s64 + -24304;
	// bl 0x82130000
	ctx.lr = 0x823C520C;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823C5220"))) PPC_WEAK_FUNC(sub_823C5220);
PPC_FUNC_IMPL(__imp__sub_823C5220) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823C5228;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d8
	ctx.lr = 0x823C5230;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// fmr f29,f2
	f29.f64 = ctx.f2.f64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f28,f3
	f28.f64 = ctx.f3.f64;
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// lwz r3,272(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 272);
	// bl 0x823c2428
	ctx.lr = 0x823C5258;
	sub_823C2428(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823c5354
	if (cr6.eq) goto loc_823C5354;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bge cr6,0x823c52c0
	if (!cr6.lt) goto loc_823C52C0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r4,r11,-27788
	ctx.r4.s64 = r11.s64 + -27788;
	// addi r3,r10,-11344
	ctx.r3.s64 = ctx.r10.s64 + -11344;
	// bl 0x823d90b0
	ctx.lr = 0x823C5288;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c52c0
	if (cr6.eq) goto loc_823C52C0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823d7460
	ctx.lr = 0x823C5298;
	sub_823D7460(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x823c52ac
	if (cr6.eq) goto loc_823C52AC;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x823c52b0
	if (!cr6.eq) goto loc_823C52B0;
loc_823C52AC:
	// li r11,1
	r11.s64 = 1;
loc_823C52B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c52c0
	if (cr6.eq) goto loc_823C52C0;
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = f30.f64;
loc_823C52C0:
	// addi r11,r31,953
	r11.s64 = r31.s64 + 953;
	// lwz r10,-10000(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// li r31,0
	r31.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823c5324
	if (!cr6.gt) goto loc_823C5324;
	// bl 0x822a86d8
	ctx.lr = 0x823C52E0;
	sub_822A86D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823c5324
	if (cr6.eq) goto loc_823C5324;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r31,1
	r31.s64 = 1;
	// bl 0x823d7460
	ctx.lr = 0x823C52F8;
	sub_823D7460(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// bl 0x823d7388
	ctx.lr = 0x823C5314;
	sub_823D7388(ctx, base);
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C5324;
	sub_824A3410(ctx, base);
loc_823C5324:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c5360
	if (!cr6.eq) goto loc_823C5360;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// lwz r3,272(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 272);
	// bl 0x823c24e0
	ctx.lr = 0x823C5344;
	sub_823C24E0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x823C5350;
	// b 0x823d9244
	return;
loc_823C5354:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-24224
	ctx.r3.s64 = r11.s64 + -24224;
	// bl 0x82130000
	ctx.lr = 0x823C5360;
	sub_82130000(ctx, base);
loc_823C5360:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x823C536C;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823C5370"))) PPC_WEAK_FUNC(sub_823C5370);
PPC_FUNC_IMPL(__imp__sub_823C5370) {
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
	ctx.lr = 0x823C5378;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r30,336(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r27,368(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 368);
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c53d0
	if (cr6.eq) goto loc_823C53D0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823c53d4
	if (cr6.eq) goto loc_823C53D4;
loc_823C53D0:
	// li r11,0
	r11.s64 = 0;
loc_823C53D4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r3,280(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c54d0
	if (cr6.eq) goto loc_823C54D0;
	// bl 0x823c2c18
	ctx.lr = 0x823C53E8;
	sub_823C2C18(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c5598
	if (cr6.eq) goto loc_823C5598;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-27432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27432);
	// bl 0x823d6478
	ctx.lr = 0x823C5404;
	sub_823D6478(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x823c54ac
	if (cr6.eq) goto loc_823C54AC;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823bf2f0
	ctx.lr = 0x823C5420;
	sub_823BF2F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823c54a0
	if (!cr6.eq) goto loc_823C54A0;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823C5438;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-24072
	ctx.r3.s64 = ctx.r10.s64 + -24072;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82130000
	ctx.lr = 0x823C5450;
	sub_82130000(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C545C:
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r7,r11,36
	ctx.r7.s64 = r11.s64 + 36;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d6bc8
	ctx.lr = 0x823C5480;
	sub_823D6BC8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C5490;
	sub_824A3410(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823C54A0:
	// lfs f0,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	f0.f64 = double(temp.f32);
	// fadds f2,f0,f31
	ctx.f2.f64 = double(float(f0.f64 + f31.f64));
	// b 0x823c545c
	goto loc_823C545C;
loc_823C54AC:
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 280);
	// bl 0x823c2cd0
	ctx.lr = 0x823C54C0;
	sub_823C2CD0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823C54D0:
	// bl 0x823c2c18
	ctx.lr = 0x823C54D4;
	sub_823C2C18(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823c5598
	if (cr6.eq) goto loc_823C5598;
	// lis r29,-32120
	r29.s64 = -2105016320;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-27432(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -27432);
	// bl 0x823d6478
	ctx.lr = 0x823C54F0;
	sub_823D6478(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c5574
	if (cr6.eq) goto loc_823C5574;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// lwz r3,-27432(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -27432);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x823d6388
	ctx.lr = 0x823C550C;
	sub_823D6388(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823c5528
	if (cr6.eq) goto loc_823C5528;
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fadds f2,f0,f31
	ctx.f2.f64 = double(float(f0.f64 + f31.f64));
	// b 0x823c5534
	goto loc_823C5534;
loc_823C5528:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f2,f31,f0
	ctx.f2.f64 = double(float(f31.f64 + f0.f64));
loc_823C5534:
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r7,r11,36
	ctx.r7.s64 = r11.s64 + 36;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823d6b78
	ctx.lr = 0x823C5554;
	sub_823D6B78(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// bl 0x824a3410
	ctx.lr = 0x823C5564;
	sub_824A3410(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823C5574:
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 280);
	// bl 0x823c2cd0
	ctx.lr = 0x823C5588;
	sub_823C2CD0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823C5598:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-24144
	ctx.r3.s64 = r11.s64 + -24144;
	// bl 0x82130000
	ctx.lr = 0x823C55A4;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823C55B4"))) PPC_WEAK_FUNC(sub_823C55B4);
PPC_FUNC_IMPL(__imp__sub_823C55B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C55B8"))) PPC_WEAK_FUNC(sub_823C55B8);
PPC_FUNC_IMPL(__imp__sub_823C55B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C55C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,2176
	ctx.r7.s64 = ctx.r9.s64 + 2176;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r6,r8,64167
	ctx.r6.u64 = ctx.r8.u64 | 64167;
	// lwz r3,2176(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2176);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r3,r6
	ctx.r10.s64 = ctx.r3.s64 * ctx.r6.s64;
	// lfs f0,14348(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// lfs f13,27148(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27148);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,2176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2176, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bgt cr6,0x823c5634
	if (cr6.gt) goto loc_823C5634;
	// li r31,1
	r31.s64 = 1;
loc_823C5634:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-11036
	ctx.r10.s64 = r11.s64 + -11036;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c5650
	if (cr6.eq) goto loc_823C5650;
	// li r31,1
	r31.s64 = 1;
	// b 0x823c565c
	goto loc_823C565C;
loc_823C5650:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x823c565c
	if (!cr6.eq) goto loc_823C565C;
	// li r31,0
	r31.s64 = 0;
loc_823C565C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-11056
	ctx.r10.s64 = r11.s64 + -11056;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c5680
	if (!cr6.eq) goto loc_823C5680;
	// bl 0x82387a18
	ctx.lr = 0x823C5674;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c5684
	if (cr6.eq) goto loc_823C5684;
loc_823C5680:
	// li r31,0
	r31.s64 = 0;
loc_823C5684:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c5694
	if (cr6.eq) goto loc_823C5694;
	// li r30,7
	r30.s64 = 7;
loc_823C5694:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,-10000(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823bcf60
	ctx.lr = 0x823C56A4;
	sub_823BCF60(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,3908
	ctx.r3.s64 = r31.s64 + 3908;
	// bl 0x823c1de8
	ctx.lr = 0x823C56B8;
	sub_823C1DE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C56C0"))) PPC_WEAK_FUNC(sub_823C56C0);
PPC_FUNC_IMPL(__imp__sub_823C56C0) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C56C8;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f1,-12072(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12072);
	ctx.f1.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x823bd5c0
	ctx.lr = 0x823C5704;
	sub_823BD5C0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,-10000(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// addi r3,r11,3952
	ctx.r3.s64 = r11.s64 + 3952;
	// bl 0x823c1a80
	ctx.lr = 0x823C5724;
	sub_823C1A80(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c582c
	if (cr6.eq) goto loc_823C582C;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c580c
	if (cr6.eq) goto loc_823C580C;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f9,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// addi r3,r11,-23960
	ctx.r3.s64 = r11.s64 + -23960;
	// lfs f7,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fsubs f5,f7,f9
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmuls f3,f10,f10
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f31,f6,f6,f4
	f31.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fmadds f30,f5,f5,f3
	f30.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x82130000
	ctx.lr = 0x823C5798;
	sub_82130000(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f31.f64);
	// bge cr6,0x823c57b4
	if (!cr6.lt) goto loc_823C57B4;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823c5848
	goto loc_823C5848;
loc_823C57B4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x823c57d8
	if (!cr6.lt) goto loc_823C57D8;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823c584c
	goto loc_823C584C;
loc_823C57D8:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f0,-23964(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -23964);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bge cr6,0x823c57f8
	if (!cr6.lt) goto loc_823C57F8;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823c5848
	goto loc_823C5848;
loc_823C57F8:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823c584c
	goto loc_823C584C;
loc_823C580C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c582c
	if (cr6.eq) goto loc_823C582C;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823c584c
	goto loc_823C584C;
loc_823C582C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c58ac
	if (cr6.eq) goto loc_823C58AC;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823C5848:
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
loc_823C584C:
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r30,8
	ctx.r9.s64 = r30.s64 + 8;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r8,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r8.u32);
	// stw r6,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r6.u32);
	// stw r7,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r7.u32);
	// stw r5,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r5.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_823C58AC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-23996
	ctx.r3.s64 = r11.s64 + -23996;
	// bl 0x82130000
	ctx.lr = 0x823C58B8;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C58CC"))) PPC_WEAK_FUNC(sub_823C58CC);
PPC_FUNC_IMPL(__imp__sub_823C58CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C58D0"))) PPC_WEAK_FUNC(sub_823C58D0);
PPC_FUNC_IMPL(__imp__sub_823C58D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C58D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-25756
	ctx.r10.s64 = r11.s64 + -25756;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823c25a8
	ctx.lr = 0x823C58F0;
	sub_823C25A8(ctx, base);
	// li r30,20
	r30.s64 = 20;
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823C58F8:
	// mr r29,r31
	r29.u64 = r31.u64;
	// lwz r31,48(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x823C5908;
	sub_821D2028(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x823C5910;
	sub_82130588(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823c58f8
	if (!cr0.eq) goto loc_823C58F8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C5920"))) PPC_WEAK_FUNC(sub_823C5920);
PPC_FUNC_IMPL(__imp__sub_823C5920) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C5928;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-25748
	ctx.r10.s64 = r11.s64 + -25748;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823c29a0
	ctx.lr = 0x823C5940;
	sub_823C29A0(ctx, base);
	// li r30,20
	r30.s64 = 20;
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823C5948:
	// mr r29,r31
	r29.u64 = r31.u64;
	// lwz r31,84(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x823C5958;
	sub_821D2028(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x823C5960;
	sub_82130588(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823c5948
	if (!cr0.eq) goto loc_823C5948;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C5970"))) PPC_WEAK_FUNC(sub_823C5970);
PPC_FUNC_IMPL(__imp__sub_823C5970) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C5978;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-25740
	ctx.r10.s64 = r11.s64 + -25740;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823c2d98
	ctx.lr = 0x823C5990;
	sub_823C2D98(ctx, base);
	// li r30,16
	r30.s64 = 16;
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823C5998:
	// mr r29,r31
	r29.u64 = r31.u64;
	// lwz r31,76(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x823C59A8;
	sub_821D2028(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x823C59B0;
	sub_82130588(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823c5998
	if (!cr0.eq) goto loc_823C5998;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C59C0"))) PPC_WEAK_FUNC(sub_823C59C0);
PPC_FUNC_IMPL(__imp__sub_823C59C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C59C8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-25732
	ctx.r10.s64 = r11.s64 + -25732;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823c30c0
	ctx.lr = 0x823C59E0;
	sub_823C30C0(ctx, base);
	// li r30,16
	r30.s64 = 16;
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823C59E8:
	// mr r29,r31
	r29.u64 = r31.u64;
	// lwz r31,80(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x823C59F8;
	sub_821D2028(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x823C5A00;
	sub_82130588(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823c59e8
	if (!cr0.eq) goto loc_823C59E8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C5A10"))) PPC_WEAK_FUNC(sub_823C5A10);
PPC_FUNC_IMPL(__imp__sub_823C5A10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823C5A18;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,-12720(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C5A44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c5a54
	if (cr6.eq) goto loc_823C5A54;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
loc_823C5A54:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r7,-32137
	ctx.r7.s64 = -2106130432;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lis r6,-32196
	ctx.r6.s64 = -2109997056;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// addi r7,r7,-11448
	ctx.r7.s64 = ctx.r7.s64 + -11448;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// addi r6,r6,608
	ctx.r6.s64 = ctx.r6.s64 + 608;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// oris r3,r5,2048
	ctx.r3.u64 = ctx.r5.u64 | 134217728;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// lwz r3,-12720(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C5AAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12720(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12720);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823C5AC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C5ACC"))) PPC_WEAK_FUNC(sub_823C5ACC);
PPC_FUNC_IMPL(__imp__sub_823C5ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C5AD0"))) PPC_WEAK_FUNC(sub_823C5AD0);
PPC_FUNC_IMPL(__imp__sub_823C5AD0) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12720(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C5B00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c5b14
	if (cr6.eq) goto loc_823C5B14;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_823C5B14:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c5b28
	if (cr6.eq) goto loc_823C5B28;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_823C5B28:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x823c5b5c
	if (!cr6.eq) goto loc_823C5B5C;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823c5b5c
	if (!cr6.eq) goto loc_823C5B5C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,0,5,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
loc_823C5B5C:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32137
	ctx.r10.s64 = -2106130432;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lwz r3,-12720(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12720);
	// addi r6,r10,-11448
	ctx.r6.s64 = ctx.r10.s64 + -11448;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r9,608
	ctx.r5.s64 = ctx.r9.s64 + 608;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823C5B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12720(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12720);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823C5BA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_823C5BC0"))) PPC_WEAK_FUNC(sub_823C5BC0);
PPC_FUNC_IMPL(__imp__sub_823C5BC0) {
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
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x823c5c40
	if (cr6.eq) goto loc_823C5C40;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c5c24
	if (cr6.eq) goto loc_823C5C24;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c5c18
	if (!cr6.eq) goto loc_823C5C18;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c5c18
	if (!cr6.eq) goto loc_823C5C18;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x823c5c1c
	if (!cr6.eq) goto loc_823C5C1C;
loc_823C5C18:
	// li r11,1
	r11.s64 = 1;
loc_823C5C1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823c5c28
	goto loc_823C5C28;
loc_823C5C24:
	// li r11,0
	r11.s64 = 0;
loc_823C5C28:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c5c3c
	if (cr6.eq) goto loc_823C5C3C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823c5ad0
	ctx.lr = 0x823C5C3C;
	sub_823C5AD0(ctx, base);
loc_823C5C3C:
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_823C5C40:
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

__attribute__((alias("__imp__sub_823C5C58"))) PPC_WEAK_FUNC(sub_823C5C58);
PPC_FUNC_IMPL(__imp__sub_823C5C58) {
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
	// bl 0x823c58d0
	ctx.lr = 0x823C5C78;
	sub_823C58D0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c5c90
	if (cr6.eq) goto loc_823C5C90;
	// bl 0x82130588
	ctx.lr = 0x823C5C8C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823C5C90:
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

__attribute__((alias("__imp__sub_823C5CA8"))) PPC_WEAK_FUNC(sub_823C5CA8);
PPC_FUNC_IMPL(__imp__sub_823C5CA8) {
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
	// bl 0x823c5920
	ctx.lr = 0x823C5CC8;
	sub_823C5920(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c5ce0
	if (cr6.eq) goto loc_823C5CE0;
	// bl 0x82130588
	ctx.lr = 0x823C5CDC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823C5CE0:
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

__attribute__((alias("__imp__sub_823C5CF8"))) PPC_WEAK_FUNC(sub_823C5CF8);
PPC_FUNC_IMPL(__imp__sub_823C5CF8) {
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
	// bl 0x823c5970
	ctx.lr = 0x823C5D18;
	sub_823C5970(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c5d30
	if (cr6.eq) goto loc_823C5D30;
	// bl 0x82130588
	ctx.lr = 0x823C5D2C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823C5D30:
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

__attribute__((alias("__imp__sub_823C5D48"))) PPC_WEAK_FUNC(sub_823C5D48);
PPC_FUNC_IMPL(__imp__sub_823C5D48) {
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
	// bl 0x823c59c0
	ctx.lr = 0x823C5D68;
	sub_823C59C0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c5d80
	if (cr6.eq) goto loc_823C5D80;
	// bl 0x82130588
	ctx.lr = 0x823C5D7C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823C5D80:
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

__attribute__((alias("__imp__sub_823C5D98"))) PPC_WEAK_FUNC(sub_823C5D98);
PPC_FUNC_IMPL(__imp__sub_823C5D98) {
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
	ctx.lr = 0x823C5DA0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r10,r11,-25764
	ctx.r10.s64 = r11.s64 + -25764;
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82249380
	ctx.lr = 0x823C5DC4;
	sub_82249380(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x826e1090
	ctx.lr = 0x823C5DD4;
	sub_826E1090(ctx, base);
	// addi r3,r28,24
	ctx.r3.s64 = r28.s64 + 24;
	// bl 0x821b5a60
	ctx.lr = 0x823C5DDC;
	sub_821B5A60(ctx, base);
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,60
	r26.s64 = 60;
	// addi r31,r28,28
	r31.s64 = r28.s64 + 28;
	// li r25,3
	r25.s64 = 3;
	// li r24,0
	r24.s64 = 0;
loc_823C5DF0:
	// lwzx r30,r26,r27
	r30.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823c5e48
	if (cr6.eq) goto loc_823C5E48;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823c5e48
	if (cr6.eq) goto loc_823C5E48;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823C5E14;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823c5e48
	if (cr6.eq) goto loc_823C5E48;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823C5E28;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c5e4c
	if (cr6.eq) goto loc_823C5E4C;
	// lwzx r4,r26,r27
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// bl 0x823c5d98
	ctx.lr = 0x823C5E44;
	sub_823C5D98(ctx, base);
	// b 0x823c5e4c
	goto loc_823C5E4C;
loc_823C5E48:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_823C5E4C:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bge 0x823c5df0
	if (!cr0.lt) goto loc_823C5DF0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823C5E64"))) PPC_WEAK_FUNC(sub_823C5E64);
PPC_FUNC_IMPL(__imp__sub_823C5E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C5E68"))) PPC_WEAK_FUNC(sub_823C5E68);
PPC_FUNC_IMPL(__imp__sub_823C5E68) {
	PPC_FUNC_PROLOGUE();
	// b 0x823c3770
	sub_823C3770(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C5E6C"))) PPC_WEAK_FUNC(sub_823C5E6C);
PPC_FUNC_IMPL(__imp__sub_823C5E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C5E70"))) PPC_WEAK_FUNC(sub_823C5E70);
PPC_FUNC_IMPL(__imp__sub_823C5E70) {
	PPC_FUNC_PROLOGUE();
	// b 0x823c37f8
	sub_823C37F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C5E74"))) PPC_WEAK_FUNC(sub_823C5E74);
PPC_FUNC_IMPL(__imp__sub_823C5E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C5E78"))) PPC_WEAK_FUNC(sub_823C5E78);
PPC_FUNC_IMPL(__imp__sub_823C5E78) {
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
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// addi r3,r11,3908
	ctx.r3.s64 = r11.s64 + 3908;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823c1d30
	ctx.lr = 0x823C5EA4;
	sub_823C1D30(ctx, base);
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

__attribute__((alias("__imp__sub_823C5EC0"))) PPC_WEAK_FUNC(sub_823C5EC0);
PPC_FUNC_IMPL(__imp__sub_823C5EC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32196
	r11.s64 = -2109997056;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,21944
	ctx.r3.s64 = r11.s64 + 21944;
	// b 0x823bfeb0
	sub_823BFEB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C5ED0"))) PPC_WEAK_FUNC(sub_823C5ED0);
PPC_FUNC_IMPL(__imp__sub_823C5ED0) {
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
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// addi r3,r11,3908
	ctx.r3.s64 = r11.s64 + 3908;
	// bl 0x823c1fe8
	ctx.lr = 0x823C5EF4;
	sub_823C1FE8(ctx, base);
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

__attribute__((alias("__imp__sub_823C5F10"))) PPC_WEAK_FUNC(sub_823C5F10);
PPC_FUNC_IMPL(__imp__sub_823C5F10) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x823c56c0
	ctx.lr = 0x823C5F50;
	sub_823C56C0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_823C5F70"))) PPC_WEAK_FUNC(sub_823C5F70);
PPC_FUNC_IMPL(__imp__sub_823C5F70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823c3ba8
	sub_823C3BA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C5F84"))) PPC_WEAK_FUNC(sub_823C5F84);
PPC_FUNC_IMPL(__imp__sub_823C5F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C5F88"))) PPC_WEAK_FUNC(sub_823C5F88);
PPC_FUNC_IMPL(__imp__sub_823C5F88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823c3d70
	sub_823C3D70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C5FA0"))) PPC_WEAK_FUNC(sub_823C5FA0);
PPC_FUNC_IMPL(__imp__sub_823C5FA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f3,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f2,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// b 0x823c3f30
	sub_823C3F30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C5FBC"))) PPC_WEAK_FUNC(sub_823C5FBC);
PPC_FUNC_IMPL(__imp__sub_823C5FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C5FC0"))) PPC_WEAK_FUNC(sub_823C5FC0);
PPC_FUNC_IMPL(__imp__sub_823C5FC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f3,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// b 0x823c4120
	sub_823C4120(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C5FD8"))) PPC_WEAK_FUNC(sub_823C5FD8);
PPC_FUNC_IMPL(__imp__sub_823C5FD8) {
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
	// lfs f1,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x823c4a48
	ctx.lr = 0x823C600C;
	sub_823C4A48(ctx, base);
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

__attribute__((alias("__imp__sub_823C6028"))) PPC_WEAK_FUNC(sub_823C6028);
PPC_FUNC_IMPL(__imp__sub_823C6028) {
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
	// lfs f1,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x823c4cf8
	ctx.lr = 0x823C6060;
	sub_823C4CF8(ctx, base);
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

__attribute__((alias("__imp__sub_823C607C"))) PPC_WEAK_FUNC(sub_823C607C);
PPC_FUNC_IMPL(__imp__sub_823C607C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C6080"))) PPC_WEAK_FUNC(sub_823C6080);
PPC_FUNC_IMPL(__imp__sub_823C6080) {
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
	// lfs f1,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x823c41d8
	ctx.lr = 0x823C60B8;
	sub_823C41D8(ctx, base);
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

__attribute__((alias("__imp__sub_823C60D4"))) PPC_WEAK_FUNC(sub_823C60D4);
PPC_FUNC_IMPL(__imp__sub_823C60D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C60D8"))) PPC_WEAK_FUNC(sub_823C60D8);
PPC_FUNC_IMPL(__imp__sub_823C60D8) {
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
	// lfs f1,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// bl 0x823c46c8
	ctx.lr = 0x823C6114;
	sub_823C46C8(ctx, base);
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

__attribute__((alias("__imp__sub_823C6130"))) PPC_WEAK_FUNC(sub_823C6130);
PPC_FUNC_IMPL(__imp__sub_823C6130) {
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
	// bl 0x823c5370
	ctx.lr = 0x823C615C;
	sub_823C5370(ctx, base);
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

__attribute__((alias("__imp__sub_823C6178"))) PPC_WEAK_FUNC(sub_823C6178);
PPC_FUNC_IMPL(__imp__sub_823C6178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f3,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// b 0x823c4fa8
	sub_823C4FA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C6190"))) PPC_WEAK_FUNC(sub_823C6190);
PPC_FUNC_IMPL(__imp__sub_823C6190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f3,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f2,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// b 0x823c5128
	sub_823C5128(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C61AC"))) PPC_WEAK_FUNC(sub_823C61AC);
PPC_FUNC_IMPL(__imp__sub_823C61AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C61B0"))) PPC_WEAK_FUNC(sub_823C61B0);
PPC_FUNC_IMPL(__imp__sub_823C61B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f2,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// b 0x823c5220
	sub_823C5220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C61CC"))) PPC_WEAK_FUNC(sub_823C61CC);
PPC_FUNC_IMPL(__imp__sub_823C61CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C61D0"))) PPC_WEAK_FUNC(sub_823C61D0);
PPC_FUNC_IMPL(__imp__sub_823C61D0) {
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
	ctx.lr = 0x823C61D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r3,368(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 368);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c6268
	if (cr6.eq) goto loc_823C6268;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c6230
	if (cr6.eq) goto loc_823C6230;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c6224
	if (!cr6.eq) goto loc_823C6224;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c6224
	if (!cr6.eq) goto loc_823C6224;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bne cr6,0x823c6228
	if (!cr6.eq) goto loc_823C6228;
loc_823C6224:
	// li r11,1
	r11.s64 = 1;
loc_823C6228:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823c6234
	goto loc_823C6234;
loc_823C6230:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823C6234:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c6244
	if (cr6.eq) goto loc_823C6244;
	// bl 0x823c5ad0
	ctx.lr = 0x823C6244;
	sub_823C5AD0(ctx, base);
loc_823C6244:
	// lwz r3,368(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 368);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c6264
	if (cr6.eq) goto loc_823C6264;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C6264;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C6264:
	// stw r29,368(r30)
	PPC_STORE_U32(r30.u32 + 368, r29.u32);
loc_823C6268:
	// lwz r3,364(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 364);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c62ec
	if (cr6.eq) goto loc_823C62EC;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c62b4
	if (cr6.eq) goto loc_823C62B4;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c62a8
	if (!cr6.eq) goto loc_823C62A8;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c62a8
	if (!cr6.eq) goto loc_823C62A8;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bne cr6,0x823c62ac
	if (!cr6.eq) goto loc_823C62AC;
loc_823C62A8:
	// li r11,1
	r11.s64 = 1;
loc_823C62AC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823c62b8
	goto loc_823C62B8;
loc_823C62B4:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823C62B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c62c8
	if (cr6.eq) goto loc_823C62C8;
	// bl 0x823c5ad0
	ctx.lr = 0x823C62C8;
	sub_823C5AD0(ctx, base);
loc_823C62C8:
	// lwz r3,364(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 364);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c62e8
	if (cr6.eq) goto loc_823C62E8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C62E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C62E8:
	// stw r29,364(r30)
	PPC_STORE_U32(r30.u32 + 364, r29.u32);
loc_823C62EC:
	// lwz r3,360(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 360);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c6370
	if (cr6.eq) goto loc_823C6370;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c6338
	if (cr6.eq) goto loc_823C6338;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c632c
	if (!cr6.eq) goto loc_823C632C;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c632c
	if (!cr6.eq) goto loc_823C632C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bne cr6,0x823c6330
	if (!cr6.eq) goto loc_823C6330;
loc_823C632C:
	// li r11,1
	r11.s64 = 1;
loc_823C6330:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823c633c
	goto loc_823C633C;
loc_823C6338:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823C633C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c634c
	if (cr6.eq) goto loc_823C634C;
	// bl 0x823c5ad0
	ctx.lr = 0x823C634C;
	sub_823C5AD0(ctx, base);
loc_823C634C:
	// lwz r3,360(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 360);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c636c
	if (cr6.eq) goto loc_823C636C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C636C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C636C:
	// stw r29,360(r30)
	PPC_STORE_U32(r30.u32 + 360, r29.u32);
loc_823C6370:
	// lwz r31,264(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c638c
	if (cr6.eq) goto loc_823C638C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82324580
	ctx.lr = 0x823C6384;
	sub_82324580(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823C638C;
	sub_82130588(ctx, base);
loc_823C638C:
	// lwz r3,284(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// stw r29,264(r30)
	PPC_STORE_U32(r30.u32 + 264, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c63b0
	if (cr6.eq) goto loc_823C63B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C63B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C63B0:
	// lwz r3,280(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// stw r29,284(r30)
	PPC_STORE_U32(r30.u32 + 284, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c63d4
	if (cr6.eq) goto loc_823C63D4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C63D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C63D4:
	// lwz r3,276(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// stw r29,280(r30)
	PPC_STORE_U32(r30.u32 + 280, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c63f8
	if (cr6.eq) goto loc_823C63F8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C63F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C63F8:
	// lwz r3,272(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 272);
	// stw r29,276(r30)
	PPC_STORE_U32(r30.u32 + 276, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c641c
	if (cr6.eq) goto loc_823C641C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C641C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823C641C:
	// lwz r31,268(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 268);
	// stw r29,272(r30)
	PPC_STORE_U32(r30.u32 + 272, r29.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c643c
	if (cr6.eq) goto loc_823C643C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a53f8
	ctx.lr = 0x823C6434;
	sub_824A53F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823C643C;
	sub_82130588(ctx, base);
loc_823C643C:
	// stw r29,268(r30)
	PPC_STORE_U32(r30.u32 + 268, r29.u32);
	// bl 0x823d7698
	ctx.lr = 0x823C6444;
	sub_823D7698(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,4032(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4032);
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x823C6458;
	sub_8268B6D0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C6460"))) PPC_WEAK_FUNC(sub_823C6460);
PPC_FUNC_IMPL(__imp__sub_823C6460) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823C6468;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r10,-27180
	ctx.r4.s64 = ctx.r10.s64 + -27180;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x821ca540
	ctx.lr = 0x823C6490;
	sub_821CA540(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823bb5e8
	ctx.lr = 0x823C6498;
	sub_823BB5E8(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r6,r9,-27184
	ctx.r6.s64 = ctx.r9.s64 + -27184;
	// addi r5,r8,-27188
	ctx.r5.s64 = ctx.r8.s64 + -27188;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823C64B8;
	sub_82137A08(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821ca778
	ctx.lr = 0x823C64C8;
	sub_821CA778(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823c6524
	if (cr6.eq) goto loc_823C6524;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823cb6b0
	ctx.lr = 0x823C64E4;
	sub_823CB6B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823c6524
	if (cr6.eq) goto loc_823C6524;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-23912
	ctx.r3.s64 = r11.s64 + -23912;
	// bl 0x82130000
	ctx.lr = 0x823C6500;
	sub_82130000(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823c5bc0
	ctx.lr = 0x823C650C;
	sub_823C5BC0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823c5a10
	ctx.lr = 0x823C6520;
	sub_823C5A10(ctx, base);
	// li r27,1
	r27.s64 = 1;
loc_823C6524:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823C652C;
	sub_821C9A90(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823C6538"))) PPC_WEAK_FUNC(sub_823C6538);
PPC_FUNC_IMPL(__imp__sub_823C6538) {
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
	ctx.lr = 0x823C6540;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r4,380(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823c6584
	if (cr6.eq) goto loc_823C6584;
	// lwz r11,424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x823c656c
	if (cr6.gt) goto loc_823C656C;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823C656C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c6584
	if (!cr6.eq) goto loc_823C6584;
	// lwz r3,384(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// bl 0x823c6460
	ctx.lr = 0x823C6580;
	sub_823C6460(ctx, base);
	// stw r28,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r28.u32);
loc_823C6584:
	// lwz r4,396(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823c65bc
	if (cr6.eq) goto loc_823C65BC;
	// lwz r11,432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x823c65a4
	if (cr6.gt) goto loc_823C65A4;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823C65A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c65bc
	if (!cr6.eq) goto loc_823C65BC;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x823c6460
	ctx.lr = 0x823C65B8;
	sub_823C6460(ctx, base);
	// stw r28,396(r31)
	PPC_STORE_U32(r31.u32 + 396, r28.u32);
loc_823C65BC:
	// lwz r4,412(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823c65f4
	if (cr6.eq) goto loc_823C65F4;
	// lwz r11,440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 440);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x823c65dc
	if (cr6.gt) goto loc_823C65DC;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823C65DC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c65f4
	if (!cr6.eq) goto loc_823C65F4;
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// bl 0x823c6460
	ctx.lr = 0x823C65F0;
	sub_823C6460(ctx, base);
	// stw r28,412(r31)
	PPC_STORE_U32(r31.u32 + 412, r28.u32);
loc_823C65F4:
	// lwz r11,424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c6610
	if (!cr6.gt) goto loc_823C6610;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r11.u32);
	// li r11,1
	r11.s64 = 1;
	// beq 0x823c6614
	if (cr0.eq) goto loc_823C6614;
loc_823C6610:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823C6614:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r29,-1
	r29.s64 = -1;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c66a0
	if (cr6.eq) goto loc_823C66A0;
	// lwz r11,360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c66a0
	if (cr6.eq) goto loc_823C66A0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823c6674
	if (cr6.eq) goto loc_823C6674;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823c6668
	if (!cr6.eq) goto loc_823C6668;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823c6668
	if (!cr6.eq) goto loc_823C6668;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne cr6,0x823c666c
	if (!cr6.eq) goto loc_823C666C;
loc_823C6668:
	// li r11,1
	r11.s64 = 1;
loc_823C666C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823c6678
	goto loc_823C6678;
loc_823C6674:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823C6678:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c66a0
	if (cr6.eq) goto loc_823C66A0;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r3,360(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// bl 0x823c5ad0
	ctx.lr = 0x823C6690;
	sub_823C5AD0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stw r29,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r29.u32);
	// addi r3,r11,-23720
	ctx.r3.s64 = r11.s64 + -23720;
	// bl 0x82130000
	ctx.lr = 0x823C66A0;
	sub_82130000(ctx, base);
loc_823C66A0:
	// lwz r11,432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c66bc
	if (!cr6.gt) goto loc_823C66BC;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,432(r31)
	PPC_STORE_U32(r31.u32 + 432, r11.u32);
	// li r11,1
	r11.s64 = 1;
	// beq 0x823c66c0
	if (cr0.eq) goto loc_823C66C0;
loc_823C66BC:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823C66C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c6744
	if (cr6.eq) goto loc_823C6744;
	// lwz r11,364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c6744
	if (cr6.eq) goto loc_823C6744;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823c6718
	if (cr6.eq) goto loc_823C6718;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823c670c
	if (!cr6.eq) goto loc_823C670C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823c670c
	if (!cr6.eq) goto loc_823C670C;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne cr6,0x823c6710
	if (!cr6.eq) goto loc_823C6710;
loc_823C670C:
	// li r11,1
	r11.s64 = 1;
loc_823C6710:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823c671c
	goto loc_823C671C;
loc_823C6718:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823C671C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c6744
	if (cr6.eq) goto loc_823C6744;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r3,364(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// bl 0x823c5ad0
	ctx.lr = 0x823C6734;
	sub_823C5AD0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stw r29,432(r31)
	PPC_STORE_U32(r31.u32 + 432, r29.u32);
	// addi r3,r11,-23792
	ctx.r3.s64 = r11.s64 + -23792;
	// bl 0x82130000
	ctx.lr = 0x823C6744;
	sub_82130000(ctx, base);
loc_823C6744:
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r10,300(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 300);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x823c67b8
	if (cr6.eq) goto loc_823C67B8;
	// lwz r11,440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 440);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c6770
	if (!cr6.gt) goto loc_823C6770;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,440(r31)
	PPC_STORE_U32(r31.u32 + 440, r11.u32);
	// li r11,1
	r11.s64 = 1;
	// beq 0x823c6774
	if (cr0.eq) goto loc_823C6774;
loc_823C6770:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823C6774:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c67b8
	if (cr6.eq) goto loc_823C67B8;
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c67b8
	if (cr6.eq) goto loc_823C67B8;
	// bl 0x823bdfd8
	ctx.lr = 0x823C6790;
	sub_823BDFD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c67b8
	if (cr6.eq) goto loc_823C67B8;
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x823c5ad0
	ctx.lr = 0x823C67A8;
	sub_823C5AD0(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r29,440(r31)
	PPC_STORE_U32(r31.u32 + 440, r29.u32);
	// addi r3,r10,-23864
	ctx.r3.s64 = ctx.r10.s64 + -23864;
	// bl 0x82130000
	ctx.lr = 0x823C67B8;
	sub_82130000(ctx, base);
loc_823C67B8:
	// lbz r11,445(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 445);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c67d4
	if (cr6.eq) goto loc_823C67D4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823c9c48
	ctx.lr = 0x823C67D0;
	sub_823C9C48(ctx, base);
	// stb r28,445(r31)
	PPC_STORE_U8(r31.u32 + 445, r28.u8);
loc_823C67D4:
	// lwz r4,452(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 452);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// ble cr6,0x823c67ec
	if (!cr6.gt) goto loc_823C67EC;
	// lwz r3,-10000(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// bl 0x823bbde8
	ctx.lr = 0x823C67E8;
	sub_823BBDE8(ctx, base);
	// stw r29,452(r31)
	PPC_STORE_U32(r31.u32 + 452, r29.u32);
loc_823C67EC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823C67F4"))) PPC_WEAK_FUNC(sub_823C67F4);
PPC_FUNC_IMPL(__imp__sub_823C67F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C67F8"))) PPC_WEAK_FUNC(sub_823C67F8);
PPC_FUNC_IMPL(__imp__sub_823C67F8) {
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
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r10,-25780
	ctx.r9.s64 = ctx.r10.s64 + -25780;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823c6858
	if (cr6.eq) goto loc_823C6858;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c684c
	if (!cr6.eq) goto loc_823C684C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823c684c
	if (!cr6.eq) goto loc_823C684C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x823c6850
	if (!cr6.eq) goto loc_823C6850;
loc_823C684C:
	// li r11,1
	r11.s64 = 1;
loc_823C6850:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823c685c
	goto loc_823C685C;
loc_823C6858:
	// li r11,0
	r11.s64 = 0;
loc_823C685C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c6870
	if (cr6.eq) goto loc_823C6870;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823c5ad0
	ctx.lr = 0x823C6870;
	sub_823C5AD0(ctx, base);
loc_823C6870:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-27808
	ctx.r10.s64 = r11.s64 + -27808;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_823C6890"))) PPC_WEAK_FUNC(sub_823C6890);
PPC_FUNC_IMPL(__imp__sub_823C6890) {
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
	// bl 0x823c67f8
	ctx.lr = 0x823C68B0;
	sub_823C67F8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c68c8
	if (cr6.eq) goto loc_823C68C8;
	// bl 0x82130588
	ctx.lr = 0x823C68C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823C68C8:
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

__attribute__((alias("__imp__sub_823C68E0"))) PPC_WEAK_FUNC(sub_823C68E0);
PPC_FUNC_IMPL(__imp__sub_823C68E0) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x823C68E8;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823db9d4
	ctx.lr = 0x823C68F0;
	// stwu r1,-592(r1)
	ea = -592 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// fmr f27,f2
	f27.f64 = ctx.f2.f64;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r20,r9
	r20.u64 = ctx.r9.u64;
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r19,r10
	r19.u64 = ctx.r10.u64;
	// cmpw cr6,r11,r21
	cr6.compare<int32_t>(r11.s32, r21.s32, xer);
	// bgt cr6,0x823c6924
	if (cr6.gt) goto loc_823C6924;
	// mr r11,r21
	r11.u64 = r21.u64;
loc_823C6924:
	// stw r11,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r11.u32);
	// lhz r30,4(r28)
	r30.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823c6ee8
	if (cr6.eq) goto loc_823C6EE8;
	// lfs f0,60(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 60);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,52(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// li r24,0
	r24.s64 = 0;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f31,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f31.f64 = double(temp.f32);
	// fdivs f11,f12,f28
	ctx.f11.f64 = double(float(ctx.f12.f64 / f28.f64));
	// fmuls f30,f11,f31
	f30.f64 = double(float(ctx.f11.f64 * f31.f64));
	// fmuls f29,f30,f28
	f29.f64 = double(float(f30.f64 * f28.f64));
	// fcmpu cr6,f29,f27
	cr6.compare(f29.f64, f27.f64);
	// ble cr6,0x823c6970
	if (!cr6.gt) goto loc_823C6970;
	// addi r11,r20,1
	r11.s64 = r20.s64 + 1;
	// li r27,1
	r27.s64 = 1;
	// cmpw cr6,r21,r11
	cr6.compare<int32_t>(r21.s32, r11.s32, xer);
	// blt cr6,0x823c6974
	if (cr6.lt) goto loc_823C6974;
loc_823C6970:
	// mr r27,r24
	r27.u64 = r24.u64;
loc_823C6974:
	// addi r29,r1,160
	r29.s64 = ctx.r1.s64 + 160;
	// li r31,3
	r31.s64 = 3;
loc_823C697C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823c3240
	ctx.lr = 0x823C6984;
	sub_823C3240(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,68
	r29.s64 = r29.s64 + 68;
	// bge 0x823c697c
	if (!cr0.lt) goto loc_823C697C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f11,44(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// fmr f7,f11
	ctx.f7.f64 = ctx.f11.f64;
	// lfs f9,48(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f13,f30,f31
	ctx.f13.f64 = double(float(f30.f64 * f31.f64));
	// stw r23,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r23.u32);
	// fmr f2,f9
	ctx.f2.f64 = ctx.f9.f64;
	// stw r23,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, r23.u32);
	// fmuls f12,f30,f31
	ctx.f12.f64 = double(float(f30.f64 * f31.f64));
	// stw r23,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r23.u32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fmr f1,f11
	ctx.f1.f64 = ctx.f11.f64;
	// fmuls f10,f30,f31
	ctx.f10.f64 = double(float(f30.f64 * f31.f64));
	// addi r11,r23,44
	r11.s64 = r23.s64 + 44;
	// fmuls f4,f30,f0
	ctx.f4.f64 = double(float(f30.f64 * f0.f64));
	// stw r23,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, r23.u32);
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// fmuls f8,f30,f31
	ctx.f8.f64 = double(float(f30.f64 * f31.f64));
	// fmuls f5,f29,f31
	ctx.f5.f64 = double(float(f29.f64 * f31.f64));
	// fmr f6,f9
	ctx.f6.f64 = ctx.f9.f64;
	// fadds f13,f13,f7
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f7.f64));
	// stfs f13,272(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// fmr f3,f11
	ctx.f3.f64 = ctx.f11.f64;
	// fadds f12,f2,f12
	ctx.f12.f64 = double(float(ctx.f2.f64 + ctx.f12.f64));
	// stfs f12,344(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// fadds f10,f1,f10
	ctx.f10.f64 = double(float(ctx.f1.f64 + ctx.f10.f64));
	// stfs f10,408(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// fmuls f7,f4,f31
	ctx.f7.f64 = double(float(ctx.f4.f64 * f31.f64));
	// fmuls f2,f4,f31
	ctx.f2.f64 = double(float(ctx.f4.f64 * f31.f64));
	// fmuls f1,f4,f31
	ctx.f1.f64 = double(float(ctx.f4.f64 * f31.f64));
	// fadds f8,f0,f8
	ctx.f8.f64 = double(float(f0.f64 + ctx.f8.f64));
	// stfs f8,412(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// fmuls f0,f4,f31
	f0.f64 = double(float(ctx.f4.f64 * f31.f64));
	// fsubs f4,f13,f5
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f5.f64));
	// stfs f4,280(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// fadds f13,f5,f13
	ctx.f13.f64 = double(float(ctx.f5.f64 + ctx.f13.f64));
	// stfs f13,288(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// fsubs f4,f12,f5
	ctx.f4.f64 = double(float(ctx.f12.f64 - ctx.f5.f64));
	// stfs f4,352(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// fadds f13,f5,f12
	ctx.f13.f64 = double(float(ctx.f5.f64 + ctx.f12.f64));
	// stfs f13,360(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// fsubs f12,f10,f5
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f5.f64));
	// stfs f12,416(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// fadds f13,f11,f7
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f7.f64));
	// stfs f13,204(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// fadds f12,f9,f2
	ctx.f12.f64 = double(float(ctx.f9.f64 + ctx.f2.f64));
	// stfs f12,208(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// fadds f11,f6,f1
	ctx.f11.f64 = double(float(ctx.f6.f64 + ctx.f1.f64));
	// stfs f11,276(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// fsubs f4,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 - ctx.f5.f64));
	// stfs f4,420(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// fadds f9,f3,f0
	ctx.f9.f64 = double(float(ctx.f3.f64 + f0.f64));
	// stfs f9,340(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// fadds f7,f5,f10
	ctx.f7.f64 = double(float(ctx.f5.f64 + ctx.f10.f64));
	// stfs f7,424(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// fadds f6,f5,f8
	ctx.f6.f64 = double(float(ctx.f5.f64 + ctx.f8.f64));
	// stfs f6,428(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// fsubs f4,f13,f5
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f5.f64));
	// stfs f4,212(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// fadds f2,f5,f13
	ctx.f2.f64 = double(float(ctx.f5.f64 + ctx.f13.f64));
	// stfs f2,220(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// fsubs f3,f12,f5
	ctx.f3.f64 = double(float(ctx.f12.f64 - ctx.f5.f64));
	// stfs f3,216(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// fadds f1,f5,f12
	ctx.f1.f64 = double(float(ctx.f5.f64 + ctx.f12.f64));
	// stfs f1,224(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// fsubs f0,f11,f5
	f0.f64 = double(float(ctx.f11.f64 - ctx.f5.f64));
	// stfs f0,284(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// fadds f13,f5,f11
	ctx.f13.f64 = double(float(ctx.f5.f64 + ctx.f11.f64));
	// stfs f13,292(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// fsubs f12,f9,f5
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// stfs f12,348(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// fadds f11,f5,f9
	ctx.f11.f64 = double(float(ctx.f5.f64 + ctx.f9.f64));
	// stfs f11,356(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// bl 0x821bbea8
	ctx.lr = 0x823C6AB8;
	sub_821BBEA8(ctx, base);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// mr r26,r24
	r26.u64 = r24.u64;
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// stw r24,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r24.u32);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// stw r24,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r24.u32);
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
	// ble cr6,0x823c6ae8
	if (!cr6.gt) goto loc_823C6AE8;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_823C6AE8:
	// bl 0x82130528
	ctx.lr = 0x823C6AEC;
	sub_82130528(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x823c6bc8
	if (!cr6.gt) goto loc_823C6BC8;
	// clrlwi r5,r27,24
	ctx.r5.u64 = r27.u32 & 0xFF;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
loc_823C6B04:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// addi r11,r1,212
	r11.s64 = ctx.r1.s64 + 212;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
loc_823C6B20:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c6b6c
	if (cr6.eq) goto loc_823C6B6C;
	// lfs f12,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x823c6b5c
	if (!cr6.lt) goto loc_823C6B5C;
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x823c6b5c
	if (cr6.lt) goto loc_823C6B5C;
	// lfs f12,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x823c6b5c
	if (!cr6.lt) goto loc_823C6B5C;
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x823c6b60
	if (!cr6.lt) goto loc_823C6B60;
loc_823C6B5C:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_823C6B60:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823c6b80
	if (!cr6.eq) goto loc_823C6B80;
loc_823C6B6C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,68
	r11.s64 = r11.s64 + 68;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// blt cr6,0x823c6b20
	if (cr6.lt) goto loc_823C6B20;
	// b 0x823c6ba4
	goto loc_823C6BA4;
loc_823C6B80:
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// stwx r9,r8,r25
	PPC_STORE_U32(ctx.r8.u32 + r25.u32, ctx.r9.u32);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stwx r4,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r4.u32);
	// lwz r26,80(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_823C6BA4:
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c6bbc
	if (!cr6.eq) goto loc_823C6BBC;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// stwx r24,r8,r25
	PPC_STORE_U32(ctx.r8.u32 + r25.u32, r24.u32);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
loc_823C6BBC:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x823c6b04
	if (!cr0.eq) goto loc_823C6B04;
loc_823C6BC8:
	// sth r24,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, r24.u16);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// sth r24,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, r24.u16);
	// stw r24,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r24.u32);
	// sth r24,124(r1)
	PPC_STORE_U16(ctx.r1.u32 + 124, r24.u16);
	// sth r24,126(r1)
	PPC_STORE_U16(ctx.r1.u32 + 126, r24.u16);
	// stw r24,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r24.u32);
	// sth r24,132(r1)
	PPC_STORE_U16(ctx.r1.u32 + 132, r24.u16);
	// sth r24,134(r1)
	PPC_STORE_U16(ctx.r1.u32 + 134, r24.u16);
	// stw r24,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r24.u32);
	// sth r24,140(r1)
	PPC_STORE_U16(ctx.r1.u32 + 140, r24.u16);
	// sth r24,142(r1)
	PPC_STORE_U16(ctx.r1.u32 + 142, r24.u16);
	// stw r24,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r24.u32);
	// stw r24,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r24.u32);
	// sth r24,148(r1)
	PPC_STORE_U16(ctx.r1.u32 + 148, r24.u16);
	// sth r24,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, r24.u16);
	// ble cr6,0x823c6c40
	if (!cr6.gt) goto loc_823C6C40;
	// mr r31,r24
	r31.u64 = r24.u64;
loc_823C6C10:
	// lwzx r9,r31,r25
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r25.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,16
	ctx.r4.s64 = 16;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwzx r29,r31,r11
	r29.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x8262e420
	ctx.lr = 0x823C6C30;
	sub_8262E420(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823c6c10
	if (!cr0.eq) goto loc_823C6C10;
loc_823C6C40:
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c6d10
	if (cr6.eq) goto loc_823C6D10;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c6d10
	if (cr6.eq) goto loc_823C6D10;
	// addi r29,r1,84
	r29.s64 = ctx.r1.s64 + 84;
	// addi r28,r1,120
	r28.s64 = ctx.r1.s64 + 120;
	// li r27,4
	r27.s64 = 4;
loc_823C6C64:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c6cb8
	if (!cr6.gt) goto loc_823C6CB8;
	// mr r30,r24
	r30.u64 = r24.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x823c6cb8
	if (!cr6.gt) goto loc_823C6CB8;
	// mr r31,r24
	r31.u64 = r24.u64;
loc_823C6C80:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r26,r31,r11
	r26.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x8262e420
	ctx.lr = 0x823C6C94;
	sub_8262E420(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r26,80(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// blt cr6,0x823c6c80
	if (cr6.lt) goto loc_823C6C80;
loc_823C6CB8:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x823c6c64
	if (!cr0.eq) goto loc_823C6C64;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c6d10
	if (!cr6.gt) goto loc_823C6D10;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c6d10
	if (!cr6.gt) goto loc_823C6D10;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c6d10
	if (!cr6.gt) goto loc_823C6D10;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c6d10
	if (!cr6.gt) goto loc_823C6D10;
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// bl 0x82130588
	ctx.lr = 0x823C6D04;
	sub_82130588(ctx, base);
	// stw r24,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r24.u32);
	// sth r24,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, r24.u16);
	// sth r24,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, r24.u16);
loc_823C6D10:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x823C6D18;
	sub_82130588(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x823C6D1C;
	sub_821BBF00(ctx, base);
	// addi r29,r1,120
	r29.s64 = ctx.r1.s64 + 120;
	// addi r27,r1,84
	r27.s64 = ctx.r1.s64 + 84;
	// addi r30,r23,28
	r30.s64 = r23.s64 + 28;
	// addi r31,r1,208
	r31.s64 = ctx.r1.s64 + 208;
	// li r28,4
	r28.s64 = 4;
loc_823C6D30:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823c6dcc
	if (!cr6.gt) goto loc_823C6DCC;
	// li r3,68
	ctx.r3.s64 = 68;
	// bl 0x82130528
	ctx.lr = 0x823C6D44;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c6d54
	if (cr6.eq) goto loc_823C6D54;
	// bl 0x823c3240
	ctx.lr = 0x823C6D50;
	sub_823C3240(ctx, base);
	// b 0x823c6d58
	goto loc_823C6D58;
loc_823C6D54:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_823C6D58:
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// rotlwi r11,r3,0
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,-24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -24);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,-4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// stfs f11,44(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 44, temp.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stfs f10,48(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 48, temp.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// mr r10,r19
	ctx.r10.u64 = r19.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r5,r21,1
	ctx.r5.s64 = r21.s64 + 1;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// fmuls f9,f12,f31
	ctx.f9.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fsubs f8,f11,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// stfs f8,52(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
	// fsubs f7,f10,f9
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// stfs f7,56(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// fadds f6,f9,f11
	ctx.f6.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// stfs f6,60(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// fadds f5,f9,f10
	ctx.f5.f64 = double(float(ctx.f9.f64 + ctx.f10.f64));
	// stfs f5,64(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// bl 0x823c68e0
	ctx.lr = 0x823C6DCC;
	sub_823C68E0(ctx, base);
loc_823C6DCC:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r31,r31,68
	r31.s64 = r31.s64 + 68;
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bne 0x823c6d30
	if (!cr0.eq) goto loc_823C6D30;
	// lhz r30,116(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 116);
	// addi r31,r23,4
	r31.s64 = r23.s64 + 4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823c6e04
	if (cr6.eq) goto loc_823C6E04;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82504778
	ctx.lr = 0x823C6E00;
	sub_82504778(ctx, base);
	// b 0x823c6e08
	goto loc_823C6E08;
loc_823C6E04:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_823C6E08:
	// lhz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 116);
	// mr r11,r24
	r11.u64 = r24.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823c6e5c
	if (cr6.eq) goto loc_823C6E5C;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_823C6E24:
	// lhz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// sth r5,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r5.u16);
	// lwzx r3,r6,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stwx r3,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r3.u32);
	// lhz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 116);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x823c6e24
	if (cr6.lt) goto loc_823C6E24;
loc_823C6E5C:
	// bl 0x821bbea8
	ctx.lr = 0x823C6E60;
	sub_821BBEA8(ctx, base);
	// addi r31,r1,112
	r31.s64 = ctx.r1.s64 + 112;
	// li r30,5
	r30.s64 = 5;
loc_823C6E68:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C6E70;
	sub_82130588(ctx, base);
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// sth r24,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r24.u16);
	// sth r24,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r24.u16);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x823c6e68
	if (!cr0.eq) goto loc_823C6E68;
	// bl 0x821bbf00
	ctx.lr = 0x823C6E8C;
	sub_821BBF00(ctx, base);
	// addi r31,r1,152
	r31.s64 = ctx.r1.s64 + 152;
	// li r30,4
	r30.s64 = 4;
loc_823C6E94:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c6eac
	if (cr6.eq) goto loc_823C6EAC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C6EAC;
	sub_82130588(ctx, base);
loc_823C6EAC:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x823c6e94
	if (!cr0.lt) goto loc_823C6E94;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r29,3
	r29.s64 = 3;
	// addi r31,r1,436
	r31.s64 = ctx.r1.s64 + 436;
	// addi r30,r11,-25764
	r30.s64 = r11.s64 + -25764;
loc_823C6EC4:
	// addi r31,r31,-68
	r31.s64 = r31.s64 + -68;
	// stw r30,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r30.u32);
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c6ee0
	if (cr6.eq) goto loc_823C6EE0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C6EE0;
	sub_82130588(ctx, base);
loc_823C6EE0:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x823c6ec4
	if (!cr0.lt) goto loc_823C6EC4;
loc_823C6EE8:
	// addi r1,r1,592
	ctx.r1.s64 = ctx.r1.s64 + 592;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dba20
	ctx.lr = 0x823C6EF4;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_823C6EF8"))) PPC_WEAK_FUNC(sub_823C6EF8);
PPC_FUNC_IMPL(__imp__sub_823C6EF8) {
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
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,24168
	ctx.r4.s64 = r11.s64 + 24168;
	// addi r3,r10,-19124
	ctx.r3.s64 = ctx.r10.s64 + -19124;
	// bl 0x82554798
	ctx.lr = 0x823C6F18;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,816
	ctx.r4.s64 = ctx.r9.s64 + 816;
	// addi r3,r8,-19164
	ctx.r3.s64 = ctx.r8.s64 + -19164;
	// bl 0x82554798
	ctx.lr = 0x823C6F2C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-4512
	ctx.r4.s64 = ctx.r7.s64 + -4512;
	// addi r3,r6,-19200
	ctx.r3.s64 = ctx.r6.s64 + -19200;
	// bl 0x82554798
	ctx.lr = 0x823C6F40;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-7344
	ctx.r4.s64 = ctx.r5.s64 + -7344;
	// addi r3,r3,-19232
	ctx.r3.s64 = ctx.r3.s64 + -19232;
	// bl 0x82554798
	ctx.lr = 0x823C6F54;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-7320
	ctx.r4.s64 = r11.s64 + -7320;
	// addi r3,r10,-19264
	ctx.r3.s64 = ctx.r10.s64 + -19264;
	// bl 0x82554798
	ctx.lr = 0x823C6F68;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-7248
	ctx.r4.s64 = ctx.r9.s64 + -7248;
	// addi r3,r8,-19296
	ctx.r3.s64 = ctx.r8.s64 + -19296;
	// bl 0x82554798
	ctx.lr = 0x823C6F7C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-7192
	ctx.r4.s64 = ctx.r7.s64 + -7192;
	// addi r3,r6,-19324
	ctx.r3.s64 = ctx.r6.s64 + -19324;
	// bl 0x82554798
	ctx.lr = 0x823C6F90;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-7168
	ctx.r4.s64 = ctx.r5.s64 + -7168;
	// addi r3,r3,-19360
	ctx.r3.s64 = ctx.r3.s64 + -19360;
	// bl 0x82554798
	ctx.lr = 0x823C6FA4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-7104
	ctx.r4.s64 = r11.s64 + -7104;
	// addi r3,r10,-19388
	ctx.r3.s64 = ctx.r10.s64 + -19388;
	// bl 0x82554798
	ctx.lr = 0x823C6FB8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-7048
	ctx.r4.s64 = ctx.r9.s64 + -7048;
	// addi r3,r8,-19424
	ctx.r3.s64 = ctx.r8.s64 + -19424;
	// bl 0x82554798
	ctx.lr = 0x823C6FCC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-7024
	ctx.r4.s64 = ctx.r7.s64 + -7024;
	// addi r3,r6,-19460
	ctx.r3.s64 = ctx.r6.s64 + -19460;
	// bl 0x82554798
	ctx.lr = 0x823C6FE0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,824
	ctx.r4.s64 = ctx.r5.s64 + 824;
	// addi r3,r3,-19504
	ctx.r3.s64 = ctx.r3.s64 + -19504;
	// bl 0x82554798
	ctx.lr = 0x823C6FF4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,840
	ctx.r4.s64 = r11.s64 + 840;
	// addi r3,r10,-19552
	ctx.r3.s64 = ctx.r10.s64 + -19552;
	// bl 0x82554798
	ctx.lr = 0x823C7008;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-6968
	ctx.r4.s64 = ctx.r9.s64 + -6968;
	// addi r3,r8,-19576
	ctx.r3.s64 = ctx.r8.s64 + -19576;
	// bl 0x82554798
	ctx.lr = 0x823C701C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-6944
	ctx.r4.s64 = ctx.r7.s64 + -6944;
	// addi r3,r6,-19604
	ctx.r3.s64 = ctx.r6.s64 + -19604;
	// bl 0x82554798
	ctx.lr = 0x823C7030;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-6880
	ctx.r4.s64 = ctx.r5.s64 + -6880;
	// addi r3,r3,-19636
	ctx.r3.s64 = ctx.r3.s64 + -19636;
	// bl 0x82554798
	ctx.lr = 0x823C7044;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-16568
	ctx.r4.s64 = r11.s64 + -16568;
	// addi r3,r10,-19660
	ctx.r3.s64 = ctx.r10.s64 + -19660;
	// bl 0x82554798
	ctx.lr = 0x823C7058;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,24176
	ctx.r4.s64 = ctx.r9.s64 + 24176;
	// addi r3,r8,-19684
	ctx.r3.s64 = ctx.r8.s64 + -19684;
	// bl 0x82554798
	ctx.lr = 0x823C706C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,880
	ctx.r4.s64 = ctx.r7.s64 + 880;
	// addi r3,r6,-19728
	ctx.r3.s64 = ctx.r6.s64 + -19728;
	// bl 0x82554798
	ctx.lr = 0x823C7080;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-6824
	ctx.r4.s64 = ctx.r5.s64 + -6824;
	// addi r3,r3,-19764
	ctx.r3.s64 = ctx.r3.s64 + -19764;
	// bl 0x82554798
	ctx.lr = 0x823C7094;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-6768
	ctx.r4.s64 = r11.s64 + -6768;
	// addi r3,r10,-19800
	ctx.r3.s64 = ctx.r10.s64 + -19800;
	// bl 0x82554798
	ctx.lr = 0x823C70A8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-6688
	ctx.r4.s64 = ctx.r9.s64 + -6688;
	// addi r3,r8,-19832
	ctx.r3.s64 = ctx.r8.s64 + -19832;
	// bl 0x82554798
	ctx.lr = 0x823C70BC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-6648
	ctx.r4.s64 = ctx.r7.s64 + -6648;
	// addi r3,r6,-19864
	ctx.r3.s64 = ctx.r6.s64 + -19864;
	// bl 0x82554798
	ctx.lr = 0x823C70D0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,896
	ctx.r4.s64 = ctx.r5.s64 + 896;
	// addi r3,r3,-19888
	ctx.r3.s64 = ctx.r3.s64 + -19888;
	// bl 0x82554798
	ctx.lr = 0x823C70E4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-6592
	ctx.r4.s64 = r11.s64 + -6592;
	// addi r3,r10,-19912
	ctx.r3.s64 = ctx.r10.s64 + -19912;
	// bl 0x82554798
	ctx.lr = 0x823C70F8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-6568
	ctx.r4.s64 = ctx.r9.s64 + -6568;
	// addi r3,r8,-19948
	ctx.r3.s64 = ctx.r8.s64 + -19948;
	// bl 0x82554798
	ctx.lr = 0x823C710C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-6552
	ctx.r4.s64 = ctx.r7.s64 + -6552;
	// addi r3,r6,-19976
	ctx.r3.s64 = ctx.r6.s64 + -19976;
	// bl 0x82554798
	ctx.lr = 0x823C7120;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-6432
	ctx.r4.s64 = ctx.r5.s64 + -6432;
	// addi r3,r3,-20004
	ctx.r3.s64 = ctx.r3.s64 + -20004;
	// bl 0x82554798
	ctx.lr = 0x823C7134;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-6408
	ctx.r4.s64 = r11.s64 + -6408;
	// addi r3,r10,-20036
	ctx.r3.s64 = ctx.r10.s64 + -20036;
	// bl 0x82554798
	ctx.lr = 0x823C7148;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-6368
	ctx.r4.s64 = ctx.r9.s64 + -6368;
	// addi r3,r8,-20068
	ctx.r3.s64 = ctx.r8.s64 + -20068;
	// bl 0x82554798
	ctx.lr = 0x823C715C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,24184
	ctx.r4.s64 = ctx.r7.s64 + 24184;
	// addi r3,r6,-20116
	ctx.r3.s64 = ctx.r6.s64 + -20116;
	// bl 0x82554798
	ctx.lr = 0x823C7170;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,24256
	ctx.r4.s64 = ctx.r5.s64 + 24256;
	// addi r3,r3,-20168
	ctx.r3.s64 = ctx.r3.s64 + -20168;
	// bl 0x82554798
	ctx.lr = 0x823C7184;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// addi r4,r11,24272
	ctx.r4.s64 = r11.s64 + 24272;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r3,r10,-20208
	ctx.r3.s64 = ctx.r10.s64 + -20208;
	// bl 0x82554798
	ctx.lr = 0x823C7198;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,13120
	ctx.r4.s64 = ctx.r9.s64 + 13120;
	// addi r3,r8,-20260
	ctx.r3.s64 = ctx.r8.s64 + -20260;
	// bl 0x82554798
	ctx.lr = 0x823C71AC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,24336
	ctx.r4.s64 = ctx.r7.s64 + 24336;
	// addi r3,r6,-20296
	ctx.r3.s64 = ctx.r6.s64 + -20296;
	// bl 0x82554798
	ctx.lr = 0x823C71C0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,912
	ctx.r4.s64 = ctx.r5.s64 + 912;
	// addi r3,r3,-20328
	ctx.r3.s64 = ctx.r3.s64 + -20328;
	// bl 0x82554798
	ctx.lr = 0x823C71D4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-6328
	ctx.r4.s64 = r11.s64 + -6328;
	// addi r3,r10,-20368
	ctx.r3.s64 = ctx.r10.s64 + -20368;
	// bl 0x82554798
	ctx.lr = 0x823C71E8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-6272
	ctx.r4.s64 = ctx.r9.s64 + -6272;
	// addi r3,r8,-20408
	ctx.r3.s64 = ctx.r8.s64 + -20408;
	// bl 0x82554798
	ctx.lr = 0x823C71FC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,13184
	ctx.r4.s64 = ctx.r7.s64 + 13184;
	// addi r3,r6,-20444
	ctx.r3.s64 = ctx.r6.s64 + -20444;
	// bl 0x82554798
	ctx.lr = 0x823C7210;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,976
	ctx.r4.s64 = ctx.r5.s64 + 976;
	// addi r3,r3,-20484
	ctx.r3.s64 = ctx.r3.s64 + -20484;
	// bl 0x82554798
	ctx.lr = 0x823C7224;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,1016
	ctx.r4.s64 = r11.s64 + 1016;
	// addi r3,r10,-20520
	ctx.r3.s64 = ctx.r10.s64 + -20520;
	// bl 0x82554798
	ctx.lr = 0x823C7238;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-6216
	ctx.r4.s64 = ctx.r9.s64 + -6216;
	// addi r3,r8,-20556
	ctx.r3.s64 = ctx.r8.s64 + -20556;
	// bl 0x82554798
	ctx.lr = 0x823C724C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,1104
	ctx.r4.s64 = ctx.r7.s64 + 1104;
	// addi r3,r6,-20596
	ctx.r3.s64 = ctx.r6.s64 + -20596;
	// bl 0x82554798
	ctx.lr = 0x823C7260;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,1192
	ctx.r4.s64 = ctx.r5.s64 + 1192;
	// addi r3,r3,-20632
	ctx.r3.s64 = ctx.r3.s64 + -20632;
	// bl 0x82554798
	ctx.lr = 0x823C7274;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-6176
	ctx.r4.s64 = r11.s64 + -6176;
	// addi r3,r10,-20668
	ctx.r3.s64 = ctx.r10.s64 + -20668;
	// bl 0x82554798
	ctx.lr = 0x823C7288;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-6152
	ctx.r4.s64 = ctx.r9.s64 + -6152;
	// addi r3,r8,-20704
	ctx.r3.s64 = ctx.r8.s64 + -20704;
	// bl 0x82554798
	ctx.lr = 0x823C729C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,1248
	ctx.r4.s64 = ctx.r7.s64 + 1248;
	// addi r3,r6,-20736
	ctx.r3.s64 = ctx.r6.s64 + -20736;
	// bl 0x82554798
	ctx.lr = 0x823C72B0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,13248
	ctx.r4.s64 = ctx.r5.s64 + 13248;
	// addi r3,r3,-20764
	ctx.r3.s64 = ctx.r3.s64 + -20764;
	// bl 0x82554798
	ctx.lr = 0x823C72C4;
	sub_82554798(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32196
	ctx.r10.s64 = -2109997056;
	// addi r3,r11,-20796
	ctx.r3.s64 = r11.s64 + -20796;
	// addi r4,r10,24432
	ctx.r4.s64 = ctx.r10.s64 + 24432;
	// bl 0x82554798
	ctx.lr = 0x823C72D8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,24456
	ctx.r4.s64 = ctx.r9.s64 + 24456;
	// addi r3,r8,-20832
	ctx.r3.s64 = ctx.r8.s64 + -20832;
	// bl 0x82554798
	ctx.lr = 0x823C72EC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,24480
	ctx.r4.s64 = ctx.r7.s64 + 24480;
	// addi r3,r6,-20872
	ctx.r3.s64 = ctx.r6.s64 + -20872;
	// bl 0x82554798
	ctx.lr = 0x823C7300;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,24512
	ctx.r4.s64 = ctx.r5.s64 + 24512;
	// addi r3,r3,-20912
	ctx.r3.s64 = ctx.r3.s64 + -20912;
	// bl 0x82554798
	ctx.lr = 0x823C7314;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-6128
	ctx.r4.s64 = r11.s64 + -6128;
	// addi r3,r10,-20936
	ctx.r3.s64 = ctx.r10.s64 + -20936;
	// bl 0x82554798
	ctx.lr = 0x823C7328;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-6112
	ctx.r4.s64 = ctx.r9.s64 + -6112;
	// addi r3,r8,-20972
	ctx.r3.s64 = ctx.r8.s64 + -20972;
	// bl 0x82554798
	ctx.lr = 0x823C733C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-6048
	ctx.r4.s64 = ctx.r7.s64 + -6048;
	// addi r3,r6,-21008
	ctx.r3.s64 = ctx.r6.s64 + -21008;
	// bl 0x82554798
	ctx.lr = 0x823C7350;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,1320
	ctx.r4.s64 = ctx.r5.s64 + 1320;
	// addi r3,r3,-21040
	ctx.r3.s64 = ctx.r3.s64 + -21040;
	// bl 0x82554798
	ctx.lr = 0x823C7364;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-5984
	ctx.r4.s64 = r11.s64 + -5984;
	// addi r3,r10,-21092
	ctx.r3.s64 = ctx.r10.s64 + -21092;
	// bl 0x82554798
	ctx.lr = 0x823C7378;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,1432
	ctx.r4.s64 = ctx.r9.s64 + 1432;
	// addi r3,r8,-21124
	ctx.r3.s64 = ctx.r8.s64 + -21124;
	// bl 0x82554798
	ctx.lr = 0x823C738C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,1512
	ctx.r4.s64 = ctx.r7.s64 + 1512;
	// addi r3,r6,-21160
	ctx.r3.s64 = ctx.r6.s64 + -21160;
	// bl 0x82554798
	ctx.lr = 0x823C73A0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,1592
	ctx.r4.s64 = ctx.r5.s64 + 1592;
	// addi r3,r3,-21204
	ctx.r3.s64 = ctx.r3.s64 + -21204;
	// bl 0x82554798
	ctx.lr = 0x823C73B4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,1728
	ctx.r4.s64 = r11.s64 + 1728;
	// addi r3,r10,-21252
	ctx.r3.s64 = ctx.r10.s64 + -21252;
	// bl 0x82554798
	ctx.lr = 0x823C73C8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,13264
	ctx.r4.s64 = ctx.r9.s64 + 13264;
	// addi r3,r8,-21288
	ctx.r3.s64 = ctx.r8.s64 + -21288;
	// bl 0x82554798
	ctx.lr = 0x823C73DC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,13344
	ctx.r4.s64 = ctx.r7.s64 + 13344;
	// addi r3,r6,-21332
	ctx.r3.s64 = ctx.r6.s64 + -21332;
	// bl 0x82554798
	ctx.lr = 0x823C73F0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,13432
	ctx.r4.s64 = ctx.r5.s64 + 13432;
	// addi r3,r3,-21380
	ctx.r3.s64 = ctx.r3.s64 + -21380;
	// bl 0x82554798
	ctx.lr = 0x823C7404;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,1848
	ctx.r4.s64 = r11.s64 + 1848;
	// addi r3,r10,-21420
	ctx.r3.s64 = ctx.r10.s64 + -21420;
	// bl 0x82554798
	ctx.lr = 0x823C7418;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,24536
	ctx.r4.s64 = ctx.r9.s64 + 24536;
	// addi r3,r8,-21460
	ctx.r3.s64 = ctx.r8.s64 + -21460;
	// bl 0x82554798
	ctx.lr = 0x823C742C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,24616
	ctx.r4.s64 = ctx.r7.s64 + 24616;
	// addi r3,r6,-21504
	ctx.r3.s64 = ctx.r6.s64 + -21504;
	// bl 0x82554798
	ctx.lr = 0x823C7440;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,24704
	ctx.r4.s64 = ctx.r5.s64 + 24704;
	// addi r3,r3,-21552
	ctx.r3.s64 = ctx.r3.s64 + -21552;
	// bl 0x82554798
	ctx.lr = 0x823C7454;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,24792
	ctx.r4.s64 = r11.s64 + 24792;
	// addi r3,r10,-21604
	ctx.r3.s64 = ctx.r10.s64 + -21604;
	// bl 0x82554798
	ctx.lr = 0x823C7468;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-5960
	ctx.r4.s64 = ctx.r9.s64 + -5960;
	// addi r3,r8,-21648
	ctx.r3.s64 = ctx.r8.s64 + -21648;
	// bl 0x82554798
	ctx.lr = 0x823C747C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,1928
	ctx.r4.s64 = ctx.r7.s64 + 1928;
	// addi r3,r6,-21684
	ctx.r3.s64 = ctx.r6.s64 + -21684;
	// bl 0x82554798
	ctx.lr = 0x823C7490;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,2008
	ctx.r4.s64 = ctx.r5.s64 + 2008;
	// addi r3,r3,-21720
	ctx.r3.s64 = ctx.r3.s64 + -21720;
	// bl 0x82554798
	ctx.lr = 0x823C74A4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,2088
	ctx.r4.s64 = r11.s64 + 2088;
	// addi r3,r10,-21768
	ctx.r3.s64 = ctx.r10.s64 + -21768;
	// bl 0x82554798
	ctx.lr = 0x823C74B8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,2200
	ctx.r4.s64 = ctx.r9.s64 + 2200;
	// addi r3,r8,-21816
	ctx.r3.s64 = ctx.r8.s64 + -21816;
	// bl 0x82554798
	ctx.lr = 0x823C74CC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,2240
	ctx.r4.s64 = ctx.r7.s64 + 2240;
	// addi r3,r6,-21856
	ctx.r3.s64 = ctx.r6.s64 + -21856;
	// bl 0x82554798
	ctx.lr = 0x823C74E0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,2256
	ctx.r4.s64 = ctx.r5.s64 + 2256;
	// addi r3,r3,-21896
	ctx.r3.s64 = ctx.r3.s64 + -21896;
	// bl 0x82554798
	ctx.lr = 0x823C74F4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,2272
	ctx.r4.s64 = r11.s64 + 2272;
	// addi r3,r10,-21936
	ctx.r3.s64 = ctx.r10.s64 + -21936;
	// bl 0x82554798
	ctx.lr = 0x823C7508;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,2288
	ctx.r4.s64 = ctx.r9.s64 + 2288;
	// addi r3,r8,-21976
	ctx.r3.s64 = ctx.r8.s64 + -21976;
	// bl 0x82554798
	ctx.lr = 0x823C751C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-5888
	ctx.r4.s64 = ctx.r7.s64 + -5888;
	// addi r3,r6,-22028
	ctx.r3.s64 = ctx.r6.s64 + -22028;
	// bl 0x82554798
	ctx.lr = 0x823C7530;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-5856
	ctx.r4.s64 = ctx.r5.s64 + -5856;
	// addi r3,r3,-22064
	ctx.r3.s64 = ctx.r3.s64 + -22064;
	// bl 0x82554798
	ctx.lr = 0x823C7544;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-5816
	ctx.r4.s64 = r11.s64 + -5816;
	// addi r3,r10,-22100
	ctx.r3.s64 = ctx.r10.s64 + -22100;
	// bl 0x82554798
	ctx.lr = 0x823C7558;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-5776
	ctx.r4.s64 = ctx.r9.s64 + -5776;
	// addi r3,r8,-22152
	ctx.r3.s64 = ctx.r8.s64 + -22152;
	// bl 0x82554798
	ctx.lr = 0x823C756C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,2304
	ctx.r4.s64 = ctx.r7.s64 + 2304;
	// addi r3,r6,-22204
	ctx.r3.s64 = ctx.r6.s64 + -22204;
	// bl 0x82554798
	ctx.lr = 0x823C7580;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,2384
	ctx.r4.s64 = ctx.r5.s64 + 2384;
	// addi r3,r3,-22256
	ctx.r3.s64 = ctx.r3.s64 + -22256;
	// bl 0x82554798
	ctx.lr = 0x823C7594;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-5736
	ctx.r4.s64 = r11.s64 + -5736;
	// addi r3,r10,-22288
	ctx.r3.s64 = ctx.r10.s64 + -22288;
	// bl 0x82554798
	ctx.lr = 0x823C75A8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-5648
	ctx.r4.s64 = ctx.r9.s64 + -5648;
	// addi r3,r8,-22324
	ctx.r3.s64 = ctx.r8.s64 + -22324;
	// bl 0x82554798
	ctx.lr = 0x823C75BC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-5600
	ctx.r4.s64 = ctx.r7.s64 + -5600;
	// addi r3,r6,-22360
	ctx.r3.s64 = ctx.r6.s64 + -22360;
	// bl 0x82554798
	ctx.lr = 0x823C75D0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,2464
	ctx.r4.s64 = ctx.r5.s64 + 2464;
	// addi r3,r3,-22392
	ctx.r3.s64 = ctx.r3.s64 + -22392;
	// bl 0x82554798
	ctx.lr = 0x823C75E4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,2560
	ctx.r4.s64 = r11.s64 + 2560;
	// addi r3,r10,-22428
	ctx.r3.s64 = ctx.r10.s64 + -22428;
	// bl 0x82554798
	ctx.lr = 0x823C75F8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,2576
	ctx.r4.s64 = ctx.r9.s64 + 2576;
	// addi r3,r8,-22468
	ctx.r3.s64 = ctx.r8.s64 + -22468;
	// bl 0x82554798
	ctx.lr = 0x823C760C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,2632
	ctx.r4.s64 = ctx.r7.s64 + 2632;
	// addi r3,r6,-22500
	ctx.r3.s64 = ctx.r6.s64 + -22500;
	// bl 0x82554798
	ctx.lr = 0x823C7620;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,2712
	ctx.r4.s64 = ctx.r5.s64 + 2712;
	// addi r3,r3,-22536
	ctx.r3.s64 = ctx.r3.s64 + -22536;
	// bl 0x82554798
	ctx.lr = 0x823C7634;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,24880
	ctx.r4.s64 = r11.s64 + 24880;
	// addi r3,r10,-22564
	ctx.r3.s64 = ctx.r10.s64 + -22564;
	// bl 0x82554798
	ctx.lr = 0x823C7648;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,2792
	ctx.r4.s64 = ctx.r9.s64 + 2792;
	// addi r3,r8,-22592
	ctx.r3.s64 = ctx.r8.s64 + -22592;
	// bl 0x82554798
	ctx.lr = 0x823C765C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,2904
	ctx.r4.s64 = ctx.r7.s64 + 2904;
	// addi r3,r6,-22628
	ctx.r3.s64 = ctx.r6.s64 + -22628;
	// bl 0x82554798
	ctx.lr = 0x823C7670;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,3016
	ctx.r4.s64 = ctx.r5.s64 + 3016;
	// addi r3,r3,-22668
	ctx.r3.s64 = ctx.r3.s64 + -22668;
	// bl 0x82554798
	ctx.lr = 0x823C7684;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,3080
	ctx.r4.s64 = r11.s64 + 3080;
	// addi r3,r10,-22704
	ctx.r3.s64 = ctx.r10.s64 + -22704;
	// bl 0x82554798
	ctx.lr = 0x823C7698;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-5560
	ctx.r4.s64 = ctx.r9.s64 + -5560;
	// addi r3,r8,-22740
	ctx.r3.s64 = ctx.r8.s64 + -22740;
	// bl 0x82554798
	ctx.lr = 0x823C76AC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-5496
	ctx.r4.s64 = ctx.r7.s64 + -5496;
	// addi r3,r6,-22772
	ctx.r3.s64 = ctx.r6.s64 + -22772;
	// bl 0x82554798
	ctx.lr = 0x823C76C0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-5432
	ctx.r4.s64 = ctx.r5.s64 + -5432;
	// addi r3,r3,-22808
	ctx.r3.s64 = ctx.r3.s64 + -22808;
	// bl 0x82554798
	ctx.lr = 0x823C76D4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,3144
	ctx.r4.s64 = r11.s64 + 3144;
	// addi r3,r10,-22844
	ctx.r3.s64 = ctx.r10.s64 + -22844;
	// bl 0x82554798
	ctx.lr = 0x823C76E8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-5368
	ctx.r4.s64 = ctx.r9.s64 + -5368;
	// addi r3,r8,-22888
	ctx.r3.s64 = ctx.r8.s64 + -22888;
	// bl 0x82554798
	ctx.lr = 0x823C76FC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-5264
	ctx.r4.s64 = ctx.r7.s64 + -5264;
	// addi r3,r6,-22920
	ctx.r3.s64 = ctx.r6.s64 + -22920;
	// bl 0x82554798
	ctx.lr = 0x823C7710;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-5224
	ctx.r4.s64 = ctx.r5.s64 + -5224;
	// addi r3,r3,-22948
	ctx.r3.s64 = ctx.r3.s64 + -22948;
	// bl 0x82554798
	ctx.lr = 0x823C7724;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-5096
	ctx.r4.s64 = r11.s64 + -5096;
	// addi r3,r10,-22976
	ctx.r3.s64 = ctx.r10.s64 + -22976;
	// bl 0x82554798
	ctx.lr = 0x823C7738;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,24952
	ctx.r4.s64 = ctx.r9.s64 + 24952;
	// addi r3,r8,-23008
	ctx.r3.s64 = ctx.r8.s64 + -23008;
	// bl 0x82554798
	ctx.lr = 0x823C774C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,24976
	ctx.r4.s64 = ctx.r7.s64 + 24976;
	// addi r3,r6,-23052
	ctx.r3.s64 = ctx.r6.s64 + -23052;
	// bl 0x82554798
	ctx.lr = 0x823C7760;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,25008
	ctx.r4.s64 = ctx.r5.s64 + 25008;
	// addi r3,r3,-23096
	ctx.r3.s64 = ctx.r3.s64 + -23096;
	// bl 0x82554798
	ctx.lr = 0x823C7774;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,3216
	ctx.r4.s64 = r11.s64 + 3216;
	// addi r3,r10,-23128
	ctx.r3.s64 = ctx.r10.s64 + -23128;
	// bl 0x82554798
	ctx.lr = 0x823C7788;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,3280
	ctx.r4.s64 = ctx.r9.s64 + 3280;
	// addi r3,r8,-23168
	ctx.r3.s64 = ctx.r8.s64 + -23168;
	// bl 0x82554798
	ctx.lr = 0x823C779C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-5040
	ctx.r4.s64 = ctx.r7.s64 + -5040;
	// addi r3,r6,-23204
	ctx.r3.s64 = ctx.r6.s64 + -23204;
	// bl 0x82554798
	ctx.lr = 0x823C77B0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-4984
	ctx.r4.s64 = ctx.r5.s64 + -4984;
	// addi r3,r3,-23232
	ctx.r3.s64 = ctx.r3.s64 + -23232;
	// bl 0x82554798
	ctx.lr = 0x823C77C4;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-4928
	ctx.r4.s64 = r11.s64 + -4928;
	// addi r3,r10,-23272
	ctx.r3.s64 = ctx.r10.s64 + -23272;
	// bl 0x82554798
	ctx.lr = 0x823C77D8;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// addi r4,r9,-4872
	ctx.r4.s64 = ctx.r9.s64 + -4872;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r3,r8,-23308
	ctx.r3.s64 = ctx.r8.s64 + -23308;
	// bl 0x82554798
	ctx.lr = 0x823C77EC;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-4840
	ctx.r4.s64 = ctx.r7.s64 + -4840;
	// addi r3,r6,-23348
	ctx.r3.s64 = ctx.r6.s64 + -23348;
	// bl 0x82554798
	ctx.lr = 0x823C7800;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-4808
	ctx.r4.s64 = ctx.r5.s64 + -4808;
	// addi r3,r3,-23380
	ctx.r3.s64 = ctx.r3.s64 + -23380;
	// bl 0x82554798
	ctx.lr = 0x823C7814;
	sub_82554798(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// addi r3,r10,-23400
	ctx.r3.s64 = ctx.r10.s64 + -23400;
	// bl 0x82554798
	ctx.lr = 0x823C7828;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-4784
	ctx.r4.s64 = ctx.r9.s64 + -4784;
	// addi r3,r8,-23444
	ctx.r3.s64 = ctx.r8.s64 + -23444;
	// bl 0x82554798
	ctx.lr = 0x823C783C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-4720
	ctx.r4.s64 = ctx.r7.s64 + -4720;
	// addi r3,r6,-23496
	ctx.r3.s64 = ctx.r6.s64 + -23496;
	// bl 0x82554798
	ctx.lr = 0x823C7850;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-17928
	ctx.r4.s64 = ctx.r5.s64 + -17928;
	// addi r3,r3,-23532
	ctx.r3.s64 = ctx.r3.s64 + -23532;
	// bl 0x82554798
	ctx.lr = 0x823C7864;
	sub_82554798(ctx, base);
	// lis r11,-32196
	r11.s64 = -2109997056;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-4656
	ctx.r4.s64 = r11.s64 + -4656;
	// addi r3,r10,-23568
	ctx.r3.s64 = ctx.r10.s64 + -23568;
	// bl 0x82554798
	ctx.lr = 0x823C7878;
	sub_82554798(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r4,r9,-4512
	ctx.r4.s64 = ctx.r9.s64 + -4512;
	// addi r3,r8,-23604
	ctx.r3.s64 = ctx.r8.s64 + -23604;
	// bl 0x82554798
	ctx.lr = 0x823C788C;
	sub_82554798(ctx, base);
	// lis r7,-32196
	ctx.r7.s64 = -2109997056;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r7,-4456
	ctx.r4.s64 = ctx.r7.s64 + -4456;
	// addi r3,r6,-23620
	ctx.r3.s64 = ctx.r6.s64 + -23620;
	// bl 0x82554798
	ctx.lr = 0x823C78A0;
	sub_82554798(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r4,r5,-17888
	ctx.r4.s64 = ctx.r5.s64 + -17888;
	// addi r3,r3,-23648
	ctx.r3.s64 = ctx.r3.s64 + -23648;
	// bl 0x82554798
	ctx.lr = 0x823C78B4;
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

__attribute__((alias("__imp__sub_823C78C4"))) PPC_WEAK_FUNC(sub_823C78C4);
PPC_FUNC_IMPL(__imp__sub_823C78C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C78C8"))) PPC_WEAK_FUNC(sub_823C78C8);
PPC_FUNC_IMPL(__imp__sub_823C78C8) {
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
	ctx.lr = 0x823C78D0;
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
	// bne cr6,0x823c7950
	if (!cr6.eq) goto loc_823C7950;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x823c22e8
	ctx.lr = 0x823C78F8;
	sub_823C22E8(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c793c
	if (cr6.eq) goto loc_823C793C;
	// li r30,0
	r30.s64 = 0;
loc_823C790C:
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x823c21e8
	ctx.lr = 0x823C7928;
	sub_823C21E8(ctx, base);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r10,16
	r30.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// blt cr6,0x823c790c
	if (cr6.lt) goto loc_823C790C;
loc_823C793C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822d3650
	ctx.lr = 0x823C794C;
	sub_822D3650(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_823C7950:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C7978"))) PPC_WEAK_FUNC(sub_823C7978);
PPC_FUNC_IMPL(__imp__sub_823C7978) {
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
	// bl 0x823d91e8
	ctx.lr = 0x823C7980;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d0
	ctx.lr = 0x823C7988;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r28,28
	r28.s64 = 28;
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f10,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fsubs f8,f12,f10
	ctx.f8.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 + f0.f64));
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// lwzx r3,r28,r29
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// fadds f7,f10,f12
	ctx.f7.f64 = double(float(ctx.f10.f64 + ctx.f12.f64));
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// fmr f26,f1
	f26.f64 = ctx.f1.f64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// fmr f28,f2
	f28.f64 = ctx.f2.f64;
	// lfs f29,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f29.f64 = double(temp.f32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fsubs f6,f8,f11
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f11.f64));
	// fmuls f30,f9,f29
	f30.f64 = double(float(ctx.f9.f64 * f29.f64));
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// fmuls f31,f7,f29
	f31.f64 = double(float(ctx.f7.f64 * f29.f64));
	// fsel f27,f6,f8,f11
	f27.f64 = ctx.f6.f64 >= 0.0 ? ctx.f8.f64 : ctx.f11.f64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823C79F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r27,0
	r27.s64 = 0;
	// stb r30,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r30.u8);
	// stfs f26,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r27,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r27.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r3,68
	ctx.r3.s64 = 68;
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// bl 0x82130528
	ctx.lr = 0x823C7A18;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c7a28
	if (cr6.eq) goto loc_823C7A28;
	// bl 0x823c3240
	ctx.lr = 0x823C7A24;
	sub_823C3240(ctx, base);
	// b 0x823c7a2c
	goto loc_823C7A2C;
loc_823C7A28:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_823C7A2C:
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// fmuls f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 * f27.f64));
	// stfs f31,44(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f30,48(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stw r27,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r27.u32);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmuls f12,f13,f29
	ctx.f12.f64 = double(float(ctx.f13.f64 * f29.f64));
	// fsubs f11,f31,f12
	ctx.f11.f64 = double(float(f31.f64 - ctx.f12.f64));
	// stfs f11,52(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fsubs f10,f30,f12
	ctx.f10.f64 = double(float(f30.f64 - ctx.f12.f64));
	// stfs f10,56(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// fadds f9,f12,f31
	ctx.f9.f64 = double(float(ctx.f12.f64 + f31.f64));
	// stfs f9,60(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// fadds f8,f12,f30
	ctx.f8.f64 = double(float(ctx.f12.f64 + f30.f64));
	// stfs f8,64(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lbz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// lfs f1,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823c68e0
	ctx.lr = 0x823C7A8C;
	sub_823C68E0(ctx, base);
	// lwzx r3,r28,r29
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C7AA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823be148
	ctx.lr = 0x823C7AB0;
	sub_823BE148(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823be100
	ctx.lr = 0x823C7ABC;
	sub_823BE100(ctx, base);
	// subf r9,r29,r24
	ctx.r9.s64 = r24.s64 - r29.s64;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f7,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// addi r4,r6,-19096
	ctx.r4.s64 = ctx.r6.s64 + -19096;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// lfs f0,-18280(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18280);
	f0.f64 = double(temp.f32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x82130000
	ctx.lr = 0x823C7B04;
	sub_82130000(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba1c
	ctx.lr = 0x823C7B10;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823C7B14"))) PPC_WEAK_FUNC(sub_823C7B14);
PPC_FUNC_IMPL(__imp__sub_823C7B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C7B18"))) PPC_WEAK_FUNC(sub_823C7B18);
PPC_FUNC_IMPL(__imp__sub_823C7B18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,-21868
	ctx.r9.s64 = r11.s64 + -21868;
	// addi r4,r10,-19028
	ctx.r4.s64 = ctx.r10.s64 + -19028;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x823C7B50;
	sub_823DB670(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,-16008
	ctx.r7.s64 = ctx.r8.s64 + -16008;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// addi r10,r31,36
	ctx.r10.s64 = r31.s64 + 36;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// addi r10,r31,60
	ctx.r10.s64 = r31.s64 + 60;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stw r11,232(r31)
	PPC_STORE_U32(r31.u32 + 232, r11.u32);
	// stw r11,236(r31)
	PPC_STORE_U32(r31.u32 + 236, r11.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stw r11,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r11.u32);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stw r11,244(r31)
	PPC_STORE_U32(r31.u32 + 244, r11.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stw r11,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r11.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stw r11,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r11.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stw r11,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r11.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stw r11,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r11.u32);
	// stfs f0,296(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 296, temp.u32);
	// stw r11,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r11.u32);
	// stw r11,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r11.u32);
	// lfs f13,14192(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
	// stw r11,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r11.u32);
	// stw r11,284(r31)
	PPC_STORE_U32(r31.u32 + 284, r11.u32);
	// stb r11,288(r31)
	PPC_STORE_U8(r31.u32 + 288, r11.u8);
	// stb r11,289(r31)
	PPC_STORE_U8(r31.u32 + 289, r11.u8);
	// stb r11,290(r31)
	PPC_STORE_U8(r31.u32 + 290, r11.u8);
	// stb r11,291(r31)
	PPC_STORE_U8(r31.u32 + 291, r11.u8);
	// stb r11,292(r31)
	PPC_STORE_U8(r31.u32 + 292, r11.u8);
	// stb r11,293(r31)
	PPC_STORE_U8(r31.u32 + 293, r11.u8);
	// stw r9,300(r31)
	PPC_STORE_U32(r31.u32 + 300, ctx.r9.u32);
	// stb r11,304(r31)
	PPC_STORE_U8(r31.u32 + 304, r11.u8);
	// stb r11,305(r31)
	PPC_STORE_U8(r31.u32 + 305, r11.u8);
	// stfs f0,308(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 308, temp.u32);
	// stw r9,312(r31)
	PPC_STORE_U32(r31.u32 + 312, ctx.r9.u32);
	// stfs f13,324(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 324, temp.u32);
	// stfs f13,328(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 328, temp.u32);
	// stb r11,316(r31)
	PPC_STORE_U8(r31.u32 + 316, r11.u8);
	// stb r11,317(r31)
	PPC_STORE_U8(r31.u32 + 317, r11.u8);
	// stb r11,318(r31)
	PPC_STORE_U8(r31.u32 + 318, r11.u8);
	// stb r11,319(r31)
	PPC_STORE_U8(r31.u32 + 319, r11.u8);
	// stb r11,320(r31)
	PPC_STORE_U8(r31.u32 + 320, r11.u8);
	// stb r11,332(r31)
	PPC_STORE_U8(r31.u32 + 332, r11.u8);
	// stb r11,333(r31)
	PPC_STORE_U8(r31.u32 + 333, r11.u8);
	// stb r11,334(r31)
	PPC_STORE_U8(r31.u32 + 334, r11.u8);
	// stb r11,335(r31)
	PPC_STORE_U8(r31.u32 + 335, r11.u8);
	// stw r11,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r11.u32);
	// stb r11,340(r31)
	PPC_STORE_U8(r31.u32 + 340, r11.u8);
	// stb r11,341(r31)
	PPC_STORE_U8(r31.u32 + 341, r11.u8);
	// stw r11,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r11.u32);
	// stw r11,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r11.u32);
	// stw r11,352(r31)
	PPC_STORE_U32(r31.u32 + 352, r11.u32);
	// stb r11,356(r31)
	PPC_STORE_U8(r31.u32 + 356, r11.u8);
	// stw r11,360(r31)
	PPC_STORE_U32(r31.u32 + 360, r11.u32);
	// stw r11,364(r31)
	PPC_STORE_U32(r31.u32 + 364, r11.u32);
	// stw r11,368(r31)
	PPC_STORE_U32(r31.u32 + 368, r11.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// stw r11,372(r31)
	PPC_STORE_U32(r31.u32 + 372, r11.u32);
	// stw r11,376(r31)
	PPC_STORE_U32(r31.u32 + 376, r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r11.u32);
	// addi r6,r4,-16016
	ctx.r6.s64 = ctx.r4.s64 + -16016;
	// stw r11,384(r31)
	PPC_STORE_U32(r31.u32 + 384, r11.u32);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// stw r11,388(r31)
	PPC_STORE_U32(r31.u32 + 388, r11.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stw r11,392(r31)
	PPC_STORE_U32(r31.u32 + 392, r11.u32);
	// addi r4,r5,-26916
	ctx.r4.s64 = ctx.r5.s64 + -26916;
	// stw r11,396(r31)
	PPC_STORE_U32(r31.u32 + 396, r11.u32);
	// addi r10,r31,3952
	ctx.r10.s64 = r31.s64 + 3952;
	// stw r11,400(r31)
	PPC_STORE_U32(r31.u32 + 400, r11.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r11,404(r31)
	PPC_STORE_U32(r31.u32 + 404, r11.u32);
	// li r30,32
	r30.s64 = 32;
	// stw r11,408(r31)
	PPC_STORE_U32(r31.u32 + 408, r11.u32);
	// addi r8,r31,3908
	ctx.r8.s64 = r31.s64 + 3908;
	// stw r11,412(r31)
	PPC_STORE_U32(r31.u32 + 412, r11.u32);
	// addi r7,r31,444
	ctx.r7.s64 = r31.s64 + 444;
	// stw r11,416(r31)
	PPC_STORE_U32(r31.u32 + 416, r11.u32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// stw r11,828(r31)
	PPC_STORE_U32(r31.u32 + 828, r11.u32);
	// stw r11,3896(r31)
	PPC_STORE_U32(r31.u32 + 3896, r11.u32);
	// stw r11,3900(r31)
	PPC_STORE_U32(r31.u32 + 3900, r11.u32);
	// stb r3,3892(r31)
	PPC_STORE_U8(r31.u32 + 3892, ctx.r3.u8);
	// stw r9,3904(r31)
	PPC_STORE_U32(r31.u32 + 3904, ctx.r9.u32);
	// stw r6,3908(r31)
	PPC_STORE_U32(r31.u32 + 3908, ctx.r6.u32);
	// stw r11,3912(r31)
	PPC_STORE_U32(r31.u32 + 3912, r11.u32);
	// sth r11,3916(r31)
	PPC_STORE_U16(r31.u32 + 3916, r11.u16);
	// sth r11,3918(r31)
	PPC_STORE_U16(r31.u32 + 3918, r11.u16);
	// stw r11,3920(r31)
	PPC_STORE_U32(r31.u32 + 3920, r11.u32);
	// sth r11,3924(r31)
	PPC_STORE_U16(r31.u32 + 3924, r11.u16);
	// sth r11,3926(r31)
	PPC_STORE_U16(r31.u32 + 3926, r11.u16);
	// stw r11,3928(r31)
	PPC_STORE_U32(r31.u32 + 3928, r11.u32);
	// sth r11,3932(r31)
	PPC_STORE_U16(r31.u32 + 3932, r11.u16);
	// sth r11,3934(r31)
	PPC_STORE_U16(r31.u32 + 3934, r11.u16);
	// stb r11,3936(r31)
	PPC_STORE_U8(r31.u32 + 3936, r11.u8);
	// stw r4,3952(r31)
	PPC_STORE_U32(r31.u32 + 3952, ctx.r4.u32);
	// stw r11,4000(r31)
	PPC_STORE_U32(r31.u32 + 4000, r11.u32);
	// sth r11,4004(r31)
	PPC_STORE_U16(r31.u32 + 4004, r11.u16);
	// sth r11,4006(r31)
	PPC_STORE_U16(r31.u32 + 4006, r11.u16);
	// stfs f0,4012(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4012, temp.u32);
	// stw r11,4008(r31)
	PPC_STORE_U32(r31.u32 + 4008, r11.u32);
	// stw r11,4016(r31)
	PPC_STORE_U32(r31.u32 + 4016, r11.u32);
	// stb r11,4020(r31)
	PPC_STORE_U8(r31.u32 + 4020, r11.u8);
	// stvx128 v63,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,4024(r31)
	PPC_STORE_U8(r31.u32 + 4024, r11.u8);
	// stw r11,4032(r31)
	PPC_STORE_U32(r31.u32 + 4032, r11.u32);
	// addi r10,r31,428
	ctx.r10.s64 = r31.s64 + 428;
loc_823C7D44:
	// stw r9,-8(r10)
	PPC_STORE_U32(ctx.r10.u32 + -8, ctx.r9.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// stbx r11,r7,r8
	PPC_STORE_U8(ctx.r7.u32 + ctx.r8.u32, r11.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// blt cr6,0x823c7d44
	if (cr6.lt) goto loc_823C7D44;
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

__attribute__((alias("__imp__sub_823C7D84"))) PPC_WEAK_FUNC(sub_823C7D84);
PPC_FUNC_IMPL(__imp__sub_823C7D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C7D88"))) PPC_WEAK_FUNC(sub_823C7D88);
PPC_FUNC_IMPL(__imp__sub_823C7D88) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x823C7D90;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d8
	ctx.lr = 0x823C7D98;
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r24,r11,30576
	r24.s64 = r11.s64 + 30576;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r10,-18948
	ctx.r4.s64 = ctx.r10.s64 + -18948;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x821ca540
	ctx.lr = 0x823C7DC0;
	sub_821CA540(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r5,r9,-18956
	ctx.r5.s64 = ctx.r9.s64 + -18956;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x823C7DDC;
	sub_821CA6A8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x823c7f78
	if (cr6.eq) goto loc_823C7F78;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1cd0
	ctx.lr = 0x823C7DF0;
	sub_821D1CD0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r4,r11,-18980
	ctx.r4.s64 = r11.s64 + -18980;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x823C7E04;
	sub_821CF7B8(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-18996
	ctx.r4.s64 = ctx.r10.s64 + -18996;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cff40
	ctx.lr = 0x823C7E18;
	sub_821CFF40(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c7f64
	if (cr6.eq) goto loc_823C7F64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19012
	ctx.r4.s64 = r11.s64 + -19012;
	// bl 0x821d0bc8
	ctx.lr = 0x823C7E34;
	sub_821D0BC8(ctx, base);
	// li r25,1
	r25.s64 = 1;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x823c7f34
	if (!cr6.gt) goto loc_823C7F34;
	// addi r27,r30,48
	r27.s64 = r30.s64 + 48;
	// addi r28,r30,32
	r28.s64 = r30.s64 + 32;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_823C7E50:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0490
	ctx.lr = 0x823C7E5C;
	sub_821D0490(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0528
	ctx.lr = 0x823C7E6C;
	sub_821D0528(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x821d0528
	ctx.lr = 0x823C7E7C;
	sub_821D0528(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// bl 0x821d0528
	ctx.lr = 0x823C7E8C;
	sub_821D0528(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// bl 0x821d0528
	ctx.lr = 0x823C7E9C;
	sub_821D0528(ctx, base);
	// li r3,32
	ctx.r3.s64 = 32;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// bl 0x82130528
	ctx.lr = 0x823C7EA8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c7ed0
	if (cr6.eq) goto loc_823C7ED0;
	// stw r31,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r31.u32);
	// stfs f31,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f30,4(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r25,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r25.u32);
	// stfs f29,8(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stfs f28,12(r3)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// b 0x823c7ed4
	goto loc_823C7ED4;
loc_823C7ED0:
	// li r31,0
	r31.s64 = 0;
loc_823C7ED4:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262e420
	ctx.lr = 0x823C7EE0;
	sub_8262E420(ctx, base);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// ble cr6,0x823c7ef8
	if (!cr6.gt) goto loc_823C7EF8;
	// stfs f31,0(r29)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// b 0x823c7f08
	goto loc_823C7F08;
loc_823C7EF8:
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x823c7f08
	if (!cr6.lt) goto loc_823C7F08;
	// stfs f31,0(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
loc_823C7F08:
	// lfs f0,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x823c7f1c
	if (!cr6.gt) goto loc_823C7F1C;
	// stfs f29,8(r29)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r29.u32 + 8, temp.u32);
	// b 0x823c7f2c
	goto loc_823C7F2C;
loc_823C7F1C:
	// lfs f0,8(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x823c7f2c
	if (!cr6.lt) goto loc_823C7F2C;
	// stfs f29,8(r28)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r28.u32 + 8, temp.u32);
loc_823C7F2C:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// bne 0x823c7e50
	if (!cr0.eq) goto loc_823C7E50;
loc_823C7F34:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,10
	ctx.r9.s64 = 10;
	// addi r6,r30,32
	ctx.r6.s64 = r30.s64 + 32;
	// addi r5,r30,16
	ctx.r5.s64 = r30.s64 + 16;
	// lfs f2,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f2.f64 = double(temp.f32);
	// addi r4,r30,48
	ctx.r4.s64 = r30.s64 + 48;
	// lfs f1,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r30,56
	ctx.r3.s64 = r30.s64 + 56;
	// bl 0x823c7978
	ctx.lr = 0x823C7F60;
	sub_823C7978(ctx, base);
	// mr r31,r25
	r31.u64 = r25.u64;
loc_823C7F64:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821be610
	ctx.lr = 0x823C7F6C;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_823C7F78:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823C7F80;
	sub_821C9A90(ctx, base);
	// stb r31,72(r30)
	PPC_STORE_U8(r30.u32 + 72, r31.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x823C7F94;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823C7F98"))) PPC_WEAK_FUNC(sub_823C7F98);
PPC_FUNC_IMPL(__imp__sub_823C7F98) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x823C7FA0;
	// stwu r1,-896(r1)
	ea = -896 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r19,r11,30576
	r19.s64 = r11.s64 + 30576;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// addi r4,r10,-18948
	ctx.r4.s64 = ctx.r10.s64 + -18948;
	// mr r17,r5
	r17.u64 = ctx.r5.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// bl 0x821ca540
	ctx.lr = 0x823C7FD0;
	sub_821CA540(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// addi r5,r9,-18848
	ctx.r5.s64 = ctx.r9.s64 + -18848;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x823C7FEC;
	sub_821CA6A8(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x823c8204
	if (cr6.eq) goto loc_823C8204;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d1cd0
	ctx.lr = 0x823C8000;
	sub_821D1CD0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// addi r4,r11,-18872
	ctx.r4.s64 = r11.s64 + -18872;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cf7b8
	ctx.lr = 0x823C8014;
	sub_821CF7B8(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-18900
	ctx.r4.s64 = ctx.r10.s64 + -18900;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cff40
	ctx.lr = 0x823C8028;
	sub_821CFF40(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c81f0
	if (cr6.eq) goto loc_823C81F0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r24,r11,-29624
	r24.s64 = r11.s64 + -29624;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d0898
	ctx.lr = 0x823C8048;
	sub_821D0898(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,-18912
	ctx.r4.s64 = r11.s64 + -18912;
	// bl 0x821d0bc8
	ctx.lr = 0x823C8058;
	sub_821D0BC8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x823c81e0
	if (!cr6.gt) goto loc_823C81E0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r22,r20,12
	r22.s64 = r20.s64 + 12;
	// addi r21,r20,4
	r21.s64 = r20.s64 + 4;
	// addi r29,r20,20
	r29.s64 = r20.s64 + 20;
	// mr r28,r27
	r28.u64 = r27.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r26,r11,-18924
	r26.s64 = r11.s64 + -18924;
	// addi r23,r10,-18932
	r23.s64 = ctx.r10.s64 + -18932;
loc_823C8084:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe20
	ctx.lr = 0x823C8090;
	sub_821CFE20(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x823C80A0;
	sub_821CFAA8(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823c2098
	ctx.lr = 0x823C80AC;
	sub_823C2098(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// sth r27,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r27.u16);
loc_823C80C0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823c80c0
	if (!cr6.eq) goto loc_823C80C0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823C80E4;
	sub_821C9650(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0490
	ctx.lr = 0x823C80F0;
	sub_821D0490(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823c78c8
	ctx.lr = 0x823C8100;
	sub_823C78C8(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x823C810C;
	sub_821D0898(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// mr r30,r27
	r30.u64 = r27.u64;
	// bl 0x821cff40
	ctx.lr = 0x823C8120;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c81ac
	if (cr6.eq) goto loc_823C81AC;
loc_823C812C:
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x823C813C;
	sub_821CFAA8(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,16
	ctx.r4.s64 = 16;
	// add r31,r28,r11
	r31.u64 = r28.u64 + r11.u64;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x8262e420
	ctx.lr = 0x823C8150;
	sub_8262E420(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823886b0
	ctx.lr = 0x823C815C;
	sub_823886B0(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// sth r27,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r27.u16);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_823C8168:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823c8168
	if (!cr6.eq) goto loc_823C8168;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823C818C;
	sub_821C9650(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x821cff40
	ctx.lr = 0x823C81A0;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823c812c
	if (!cr6.eq) goto loc_823C812C;
loc_823C81AC:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8262e420
	ctx.lr = 0x823C81B8;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// bl 0x821d0260
	ctx.lr = 0x823C81C8;
	sub_821D0260(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r3,r28,r11
	ctx.r3.u64 = r28.u64 + r11.u64;
	// bl 0x823be020
	ctx.lr = 0x823C81D4;
	sub_823BE020(ctx, base);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r28,r28,20
	r28.s64 = r28.s64 + 20;
	// bne 0x823c8084
	if (!cr0.eq) goto loc_823C8084;
loc_823C81E0:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0260
	ctx.lr = 0x823C81E8;
	sub_821D0260(ctx, base);
	// stb r17,28(r20)
	PPC_STORE_U8(r20.u32 + 28, r17.u8);
	// li r31,1
	r31.s64 = 1;
loc_823C81F0:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821be610
	ctx.lr = 0x823C81F8;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r10.u32);
loc_823C8204:
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823C820C;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,896
	ctx.r1.s64 = ctx.r1.s64 + 896;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_823C8218"))) PPC_WEAK_FUNC(sub_823C8218);
PPC_FUNC_IMPL(__imp__sub_823C8218) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x823C8220;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// addi r9,r11,0
	ctx.r9.s64 = r11.s64 + 0;
	// li r25,0
	r25.s64 = 0;
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r8,0
	r11.s64 = ctx.r8.s64 + 0;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// ld r8,96(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// addi r9,r9,0
	ctx.r9.s64 = ctx.r9.s64 + 0;
	// ld r31,96(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// addi r5,r6,-18544
	ctx.r5.s64 = ctx.r6.s64 + -18544;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// li r6,10
	ctx.r6.s64 = 10;
	// ld r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// stw r23,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, r23.u32);
	// std r9,232(r11)
	PPC_STORE_U64(r11.u32 + 232, ctx.r9.u64);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// std r3,240(r11)
	PPC_STORE_U64(r11.u32 + 240, ctx.r3.u64);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// std r8,248(r11)
	PPC_STORE_U64(r11.u32 + 248, ctx.r8.u64);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// std r31,256(r11)
	PPC_STORE_U64(r11.u32 + 256, r31.u64);
	// lwz r3,-10224(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x823C82C4;
	sub_8268B960(ctx, base);
	// stw r3,4032(r23)
	PPC_STORE_U32(r23.u32 + 4032, ctx.r3.u32);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r31,r23,3952
	r31.s64 = r23.s64 + 3952;
	// addi r4,r8,-18468
	ctx.r4.s64 = ctx.r8.s64 + -18468;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823c7d88
	ctx.lr = 0x823C82DC;
	sub_823C7D88(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823c82f4
	if (cr6.eq) goto loc_823C82F4;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-18536
	ctx.r3.s64 = r11.s64 + -18536;
	// b 0x823c8318
	goto loc_823C8318;
loc_823C82F4:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-18552
	ctx.r4.s64 = r11.s64 + -18552;
	// bl 0x823c7d88
	ctx.lr = 0x823C8304;
	sub_823C7D88(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c831c
	if (cr6.eq) goto loc_823C831C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-18616
	ctx.r3.s64 = r11.s64 + -18616;
loc_823C8318:
	// bl 0x82130000
	ctx.lr = 0x823C831C;
	sub_82130000(ctx, base);
loc_823C831C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r31,r23,3908
	r31.s64 = r23.s64 + 3908;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-18640
	ctx.r4.s64 = r11.s64 + -18640;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823c7f98
	ctx.lr = 0x823C8334;
	sub_823C7F98(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c834c
	if (cr6.eq) goto loc_823C834C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-18728
	ctx.r3.s64 = r11.s64 + -18728;
	// b 0x823c8374
	goto loc_823C8374;
loc_823C834C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-18756
	ctx.r4.s64 = r11.s64 + -18756;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823c7f98
	ctx.lr = 0x823C8360;
	sub_823C7F98(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c8378
	if (cr6.eq) goto loc_823C8378;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-18840
	ctx.r3.s64 = r11.s64 + -18840;
loc_823C8374:
	// bl 0x82130000
	ctx.lr = 0x823C8378;
	sub_82130000(ctx, base);
loc_823C8378:
	// bl 0x82130000
	ctx.lr = 0x823C837C;
	sub_82130000(ctx, base);
	// li r3,368
	ctx.r3.s64 = 368;
	// bl 0x82130528
	ctx.lr = 0x823C8384;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8398
	if (cr6.eq) goto loc_823C8398;
	// bl 0x823d69a8
	ctx.lr = 0x823C8390;
	sub_823D69A8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x823c839c
	goto loc_823C839C;
loc_823C8398:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C839C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,268(r23)
	PPC_STORE_U32(r23.u32 + 268, r11.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r9,-14976
	ctx.r3.s64 = ctx.r9.s64 + -14976;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,364(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 364, temp.u32);
	// bl 0x82490890
	ctx.lr = 0x823C83B8;
	sub_82490890(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r8,-14992
	ctx.r3.s64 = ctx.r8.s64 + -14992;
	// bl 0x82490890
	ctx.lr = 0x823C83C8;
	sub_82490890(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r7,-15004
	ctx.r3.s64 = ctx.r7.s64 + -15004;
	// bl 0x82490890
	ctx.lr = 0x823C83D8;
	sub_82490890(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r6,-15016
	ctx.r3.s64 = ctx.r6.s64 + -15016;
	// bl 0x82490890
	ctx.lr = 0x823C83E8;
	sub_82490890(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823C83F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8404
	if (cr6.eq) goto loc_823C8404;
	// bl 0x823c2360
	ctx.lr = 0x823C8400;
	sub_823C2360(ctx, base);
	// b 0x823c8408
	goto loc_823C8408;
loc_823C8404:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_823C8408:
	// stw r3,272(r23)
	PPC_STORE_U32(r23.u32 + 272, ctx.r3.u32);
	// bl 0x823c2668
	ctx.lr = 0x823C8410;
	sub_823C2668(ctx, base);
	// lwz r11,272(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 272);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bne cr6,0x823c842c
	if (!cr6.eq) goto loc_823C842C;
	// lwz r31,96(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// beq cr6,0x823c8450
	if (cr6.eq) goto loc_823C8450;
loc_823C842C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824905a8
	ctx.lr = 0x823C8434;
	sub_824905A8(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c8444
	if (cr6.eq) goto loc_823C8444;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_823C8444:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c842c
	if (!cr6.eq) goto loc_823C842C;
loc_823C8450:
	// lwz r3,272(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 272);
	// bl 0x823c25a8
	ctx.lr = 0x823C8458;
	sub_823C25A8(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823C8460;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8470
	if (cr6.eq) goto loc_823C8470;
	// bl 0x823c2728
	ctx.lr = 0x823C846C;
	sub_823C2728(ctx, base);
	// b 0x823c8474
	goto loc_823C8474;
loc_823C8470:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_823C8474:
	// stw r3,276(r23)
	PPC_STORE_U32(r23.u32 + 276, ctx.r3.u32);
	// bl 0x823c2a60
	ctx.lr = 0x823C847C;
	sub_823C2A60(ctx, base);
	// lwz r11,276(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 276);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bne cr6,0x823c8498
	if (!cr6.eq) goto loc_823C8498;
	// lwz r31,96(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// beq cr6,0x823c84bc
	if (cr6.eq) goto loc_823C84BC;
loc_823C8498:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824905a8
	ctx.lr = 0x823C84A0;
	sub_824905A8(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c84b0
	if (cr6.eq) goto loc_823C84B0;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_823C84B0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8498
	if (!cr6.eq) goto loc_823C8498;
loc_823C84BC:
	// lwz r3,276(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 276);
	// bl 0x823c29a0
	ctx.lr = 0x823C84C4;
	sub_823C29A0(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823C84CC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c84dc
	if (cr6.eq) goto loc_823C84DC;
	// bl 0x823c2b20
	ctx.lr = 0x823C84D8;
	sub_823C2B20(ctx, base);
	// b 0x823c84e0
	goto loc_823C84E0;
loc_823C84DC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_823C84E0:
	// stw r3,280(r23)
	PPC_STORE_U32(r23.u32 + 280, ctx.r3.u32);
	// bl 0x823c2e58
	ctx.lr = 0x823C84E8;
	sub_823C2E58(ctx, base);
	// lwz r11,280(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 280);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bne cr6,0x823c8504
	if (!cr6.eq) goto loc_823C8504;
	// lwz r31,96(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// beq cr6,0x823c8528
	if (cr6.eq) goto loc_823C8528;
loc_823C8504:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824905a8
	ctx.lr = 0x823C850C;
	sub_824905A8(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c851c
	if (cr6.eq) goto loc_823C851C;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_823C851C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8504
	if (!cr6.eq) goto loc_823C8504;
loc_823C8528:
	// lwz r3,280(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 280);
	// bl 0x823c2d98
	ctx.lr = 0x823C8530;
	sub_823C2D98(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823C8538;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8548
	if (cr6.eq) goto loc_823C8548;
	// bl 0x823c2f18
	ctx.lr = 0x823C8544;
	sub_823C2F18(ctx, base);
	// b 0x823c854c
	goto loc_823C854C;
loc_823C8548:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_823C854C:
	// stw r3,284(r23)
	PPC_STORE_U32(r23.u32 + 284, ctx.r3.u32);
	// bl 0x823c3180
	ctx.lr = 0x823C8554;
	sub_823C3180(ctx, base);
	// lwz r11,284(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 284);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bne cr6,0x823c8570
	if (!cr6.eq) goto loc_823C8570;
	// lwz r31,96(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// beq cr6,0x823c8594
	if (cr6.eq) goto loc_823C8594;
loc_823C8570:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x824905a8
	ctx.lr = 0x823C8578;
	sub_824905A8(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c8588
	if (cr6.eq) goto loc_823C8588;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_823C8588:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8570
	if (!cr6.eq) goto loc_823C8570;
loc_823C8594:
	// lwz r3,284(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 284);
	// bl 0x823c30c0
	ctx.lr = 0x823C859C;
	sub_823C30C0(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823C85A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c85b4
	if (cr6.eq) goto loc_823C85B4;
	// bl 0x824a33e8
	ctx.lr = 0x823C85B0;
	sub_824A33E8(ctx, base);
	// b 0x823c85b8
	goto loc_823C85B8;
loc_823C85B4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_823C85B8:
	// stw r3,264(r23)
	PPC_STORE_U32(r23.u32 + 264, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824a3e98
	ctx.lr = 0x823C85C4;
	sub_824A3E98(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,264(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 264);
	// lwz r3,268(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 268);
	// bl 0x824a5438
	ctx.lr = 0x823C85D4;
	sub_824A5438(ctx, base);
	// stb r25,288(r23)
	PPC_STORE_U8(r23.u32 + 288, r25.u8);
	// li r3,16
	ctx.r3.s64 = 16;
	// stb r25,341(r23)
	PPC_STORE_U8(r23.u32 + 341, r25.u8);
	// stw r25,344(r23)
	PPC_STORE_U32(r23.u32 + 344, r25.u32);
	// stw r25,348(r23)
	PPC_STORE_U32(r23.u32 + 348, r25.u32);
	// stw r25,352(r23)
	PPC_STORE_U32(r23.u32 + 352, r25.u32);
	// stb r25,356(r23)
	PPC_STORE_U8(r23.u32 + 356, r25.u8);
	// bl 0x82130528
	ctx.lr = 0x823C85F4;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// addi r24,r11,-26560
	r24.s64 = r11.s64 + -26560;
	// addi r26,r10,-25780
	r26.s64 = ctx.r10.s64 + -25780;
	// beq cr6,0x823c89c4
	if (cr6.eq) goto loc_823C89C4;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// stw r26,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r26.u32);
	// addi r28,r27,4
	r28.s64 = r27.s64 + 4;
	// lwzx r3,r29,r31
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8688
	if (cr6.eq) goto loc_823C8688;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x823c8688
	if (!cr0.gt) goto loc_823C8688;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_823C8648:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x823c8668
	if (cr6.lt) goto loc_823C8668;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c866c
	if (cr6.lt) goto loc_823C866C;
loc_823C8668:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C866C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8780
	if (!cr6.eq) goto loc_823C8780;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x823c8648
	if (cr6.lt) goto loc_823C8648;
loc_823C8688:
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
loc_823C868C:
	// lwzx r3,r29,r31
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// addi r30,r27,8
	r30.s64 = r27.s64 + 8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c86f8
	if (cr6.eq) goto loc_823C86F8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x823c86f8
	if (!cr0.gt) goto loc_823C86F8;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_823C86B8:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823c86d8
	if (cr6.lt) goto loc_823C86D8;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c86dc
	if (cr6.lt) goto loc_823C86DC;
loc_823C86D8:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C86DC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8840
	if (!cr6.eq) goto loc_823C8840;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x823c86b8
	if (cr6.lt) goto loc_823C86B8;
loc_823C86F8:
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
loc_823C86FC:
	// lwzx r3,r29,r31
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// addi r31,r27,12
	r31.s64 = r27.s64 + 12;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8768
	if (cr6.eq) goto loc_823C8768;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x823c8768
	if (!cr0.gt) goto loc_823C8768;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_823C8728:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x823c8748
	if (cr6.lt) goto loc_823C8748;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c874c
	if (cr6.lt) goto loc_823C874C;
loc_823C8748:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C874C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8900
	if (!cr6.eq) goto loc_823C8900;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x823c8728
	if (cr6.lt) goto loc_823C8728;
loc_823C8768:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_823C876C:
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// b 0x823c89c8
	goto loc_823C89C8;
loc_823C8780:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8688
	if (cr6.eq) goto loc_823C8688;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c868c
	if (cr6.eq) goto loc_823C868C;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r10,2(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r11,0(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x823c87f0
	if (!cr0.gt) goto loc_823C87F0;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_823C87B0:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x823c87d0
	if (cr6.lt) goto loc_823C87D0;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c87d4
	if (cr6.lt) goto loc_823C87D4;
loc_823C87D0:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C87D4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c880c
	if (!cr6.eq) goto loc_823C880C;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x823c87b0
	if (cr6.lt) goto loc_823C87B0;
loc_823C87F0:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x823C87F8;
	sub_821D2378(ctx, base);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r25
	r11.u64 = r25.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x823c868c
	goto loc_823C868C;
loc_823C880C:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c87f0
	if (cr6.eq) goto loc_823C87F0;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x823c868c
	goto loc_823C868C;
loc_823C8840:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c86f8
	if (cr6.eq) goto loc_823C86F8;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c86fc
	if (cr6.eq) goto loc_823C86FC;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r10,2(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r11,0(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x823c88b0
	if (!cr0.gt) goto loc_823C88B0;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_823C8870:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x823c8890
	if (cr6.lt) goto loc_823C8890;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8894
	if (cr6.lt) goto loc_823C8894;
loc_823C8890:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8894:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c88cc
	if (!cr6.eq) goto loc_823C88CC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x823c8870
	if (cr6.lt) goto loc_823C8870;
loc_823C88B0:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x823C88B8;
	sub_821D2378(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r11,r25
	r11.u64 = r25.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x823c86fc
	goto loc_823C86FC;
loc_823C88CC:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c88b0
	if (cr6.eq) goto loc_823C88B0;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x823c86fc
	goto loc_823C86FC;
loc_823C8900:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8768
	if (cr6.eq) goto loc_823C8768;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c876c
	if (cr6.eq) goto loc_823C876C;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x823c8970
	if (!cr0.gt) goto loc_823C8970;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_823C8930:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x823c8950
	if (cr6.lt) goto loc_823C8950;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8954
	if (cr6.lt) goto loc_823C8954;
loc_823C8950:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8954:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c899c
	if (!cr6.eq) goto loc_823C899C;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x823c8930
	if (cr6.lt) goto loc_823C8930;
loc_823C8970:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x823C8978;
	sub_821D2378(ctx, base);
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C897C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// b 0x823c89c8
	goto loc_823C89C8;
loc_823C899C:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8970
	if (cr6.eq) goto loc_823C8970;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x823c897c
	goto loc_823C897C;
loc_823C89C4:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C89C8:
	// stw r11,360(r23)
	PPC_STORE_U32(r23.u32 + 360, r11.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823C89D4;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c8d94
	if (cr6.eq) goto loc_823C8D94;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,60
	r31.s64 = 60;
	// stw r26,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r26.u32);
	// addi r28,r27,4
	r28.s64 = r27.s64 + 4;
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8a58
	if (cr6.eq) goto loc_823C8A58;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x823c8a58
	if (!cr0.gt) goto loc_823C8A58;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_823C8A18:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x823c8a38
	if (cr6.lt) goto loc_823C8A38;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8a3c
	if (cr6.lt) goto loc_823C8A3C;
loc_823C8A38:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8A3C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8b50
	if (!cr6.eq) goto loc_823C8B50;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x823c8a18
	if (cr6.lt) goto loc_823C8A18;
loc_823C8A58:
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
loc_823C8A5C:
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// addi r30,r27,8
	r30.s64 = r27.s64 + 8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8ac8
	if (cr6.eq) goto loc_823C8AC8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x823c8ac8
	if (!cr0.gt) goto loc_823C8AC8;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_823C8A88:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823c8aa8
	if (cr6.lt) goto loc_823C8AA8;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8aac
	if (cr6.lt) goto loc_823C8AAC;
loc_823C8AA8:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8AAC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8c10
	if (!cr6.eq) goto loc_823C8C10;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x823c8a88
	if (cr6.lt) goto loc_823C8A88;
loc_823C8AC8:
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
loc_823C8ACC:
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// addi r31,r27,12
	r31.s64 = r27.s64 + 12;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8b38
	if (cr6.eq) goto loc_823C8B38;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x823c8b38
	if (!cr0.gt) goto loc_823C8B38;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_823C8AF8:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x823c8b18
	if (cr6.lt) goto loc_823C8B18;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8b1c
	if (cr6.lt) goto loc_823C8B1C;
loc_823C8B18:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8B1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8cd0
	if (!cr6.eq) goto loc_823C8CD0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x823c8af8
	if (cr6.lt) goto loc_823C8AF8;
loc_823C8B38:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_823C8B3C:
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// b 0x823c8d98
	goto loc_823C8D98;
loc_823C8B50:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8a58
	if (cr6.eq) goto loc_823C8A58;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c8a5c
	if (cr6.eq) goto loc_823C8A5C;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x823c8bc0
	if (!cr0.gt) goto loc_823C8BC0;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_823C8B80:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x823c8ba0
	if (cr6.lt) goto loc_823C8BA0;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8ba4
	if (cr6.lt) goto loc_823C8BA4;
loc_823C8BA0:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8BA4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8bdc
	if (!cr6.eq) goto loc_823C8BDC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x823c8b80
	if (cr6.lt) goto loc_823C8B80;
loc_823C8BC0:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x823C8BC8;
	sub_821D2378(ctx, base);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r25
	r11.u64 = r25.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x823c8a5c
	goto loc_823C8A5C;
loc_823C8BDC:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8bc0
	if (cr6.eq) goto loc_823C8BC0;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x823c8a5c
	goto loc_823C8A5C;
loc_823C8C10:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8ac8
	if (cr6.eq) goto loc_823C8AC8;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c8acc
	if (cr6.eq) goto loc_823C8ACC;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x823c8c80
	if (!cr0.gt) goto loc_823C8C80;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_823C8C40:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x823c8c60
	if (cr6.lt) goto loc_823C8C60;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8c64
	if (cr6.lt) goto loc_823C8C64;
loc_823C8C60:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8C64:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8c9c
	if (!cr6.eq) goto loc_823C8C9C;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x823c8c40
	if (cr6.lt) goto loc_823C8C40;
loc_823C8C80:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x823C8C88;
	sub_821D2378(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r11,r25
	r11.u64 = r25.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x823c8acc
	goto loc_823C8ACC;
loc_823C8C9C:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8c80
	if (cr6.eq) goto loc_823C8C80;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x823c8acc
	goto loc_823C8ACC;
loc_823C8CD0:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8b38
	if (cr6.eq) goto loc_823C8B38;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c8b3c
	if (cr6.eq) goto loc_823C8B3C;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x823c8d40
	if (!cr0.gt) goto loc_823C8D40;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_823C8D00:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x823c8d20
	if (cr6.lt) goto loc_823C8D20;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8d24
	if (cr6.lt) goto loc_823C8D24;
loc_823C8D20:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8D24:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8d6c
	if (!cr6.eq) goto loc_823C8D6C;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x823c8d00
	if (cr6.lt) goto loc_823C8D00;
loc_823C8D40:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x823C8D48;
	sub_821D2378(ctx, base);
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8D4C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// b 0x823c8d98
	goto loc_823C8D98;
loc_823C8D6C:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8d40
	if (cr6.eq) goto loc_823C8D40;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x823c8d4c
	goto loc_823C8D4C;
loc_823C8D94:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8D98:
	// stw r11,364(r23)
	PPC_STORE_U32(r23.u32 + 364, r11.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823C8DA4;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823c9164
	if (cr6.eq) goto loc_823C9164;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,60
	r31.s64 = 60;
	// stw r26,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r26.u32);
	// addi r28,r27,4
	r28.s64 = r27.s64 + 4;
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8e28
	if (cr6.eq) goto loc_823C8E28;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x823c8e28
	if (!cr0.gt) goto loc_823C8E28;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_823C8DE8:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x823c8e08
	if (cr6.lt) goto loc_823C8E08;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8e0c
	if (cr6.lt) goto loc_823C8E0C;
loc_823C8E08:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8E0C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8f20
	if (!cr6.eq) goto loc_823C8F20;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x823c8de8
	if (cr6.lt) goto loc_823C8DE8;
loc_823C8E28:
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
loc_823C8E2C:
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// addi r30,r27,8
	r30.s64 = r27.s64 + 8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8e98
	if (cr6.eq) goto loc_823C8E98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x823c8e98
	if (!cr0.gt) goto loc_823C8E98;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_823C8E58:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823c8e78
	if (cr6.lt) goto loc_823C8E78;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8e7c
	if (cr6.lt) goto loc_823C8E7C;
loc_823C8E78:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8E7C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8fe0
	if (!cr6.eq) goto loc_823C8FE0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x823c8e58
	if (cr6.lt) goto loc_823C8E58;
loc_823C8E98:
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
loc_823C8E9C:
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// addi r31,r27,12
	r31.s64 = r27.s64 + 12;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c8f08
	if (cr6.eq) goto loc_823C8F08;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble 0x823c8f08
	if (!cr0.gt) goto loc_823C8F08;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_823C8EC8:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x823c8ee8
	if (cr6.lt) goto loc_823C8EE8;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8eec
	if (cr6.lt) goto loc_823C8EEC;
loc_823C8EE8:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8EEC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c90a0
	if (!cr6.eq) goto loc_823C90A0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x823c8ec8
	if (cr6.lt) goto loc_823C8EC8;
loc_823C8F08:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_823C8F0C:
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// b 0x823c9168
	goto loc_823C9168;
loc_823C8F20:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8e28
	if (cr6.eq) goto loc_823C8E28;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c8e2c
	if (cr6.eq) goto loc_823C8E2C;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x823c8f90
	if (!cr0.gt) goto loc_823C8F90;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_823C8F50:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x823c8f70
	if (cr6.lt) goto loc_823C8F70;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c8f74
	if (cr6.lt) goto loc_823C8F74;
loc_823C8F70:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C8F74:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c8fac
	if (!cr6.eq) goto loc_823C8FAC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x823c8f50
	if (cr6.lt) goto loc_823C8F50;
loc_823C8F90:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x823C8F98;
	sub_821D2378(ctx, base);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r25
	r11.u64 = r25.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x823c8e2c
	goto loc_823C8E2C;
loc_823C8FAC:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8f90
	if (cr6.eq) goto loc_823C8F90;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x823c8e2c
	goto loc_823C8E2C;
loc_823C8FE0:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8e98
	if (cr6.eq) goto loc_823C8E98;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c8e9c
	if (cr6.eq) goto loc_823C8E9C;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x823c9050
	if (!cr0.gt) goto loc_823C9050;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_823C9010:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x823c9030
	if (cr6.lt) goto loc_823C9030;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c9034
	if (cr6.lt) goto loc_823C9034;
loc_823C9030:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C9034:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c906c
	if (!cr6.eq) goto loc_823C906C;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x823c9010
	if (cr6.lt) goto loc_823C9010;
loc_823C9050:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x823C9058;
	sub_821D2378(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r11,r25
	r11.u64 = r25.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x823c8e9c
	goto loc_823C8E9C;
loc_823C906C:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c9050
	if (cr6.eq) goto loc_823C9050;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x823c8e9c
	goto loc_823C8E9C;
loc_823C90A0:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c8f08
	if (cr6.eq) goto loc_823C8F08;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823c8f0c
	if (cr6.eq) goto loc_823C8F0C;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x823c9110
	if (!cr0.gt) goto loc_823C9110;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_823C90D0:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x823c90f0
	if (cr6.lt) goto loc_823C90F0;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823c90f4
	if (cr6.lt) goto loc_823C90F4;
loc_823C90F0:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C90F4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c913c
	if (!cr6.eq) goto loc_823C913C;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x823c90d0
	if (cr6.lt) goto loc_823C90D0;
loc_823C9110:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x823C9118;
	sub_821D2378(ctx, base);
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C911C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// b 0x823c9168
	goto loc_823C9168;
loc_823C913C:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x823c9110
	if (cr6.eq) goto loc_823C9110;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x823c911c
	goto loc_823C911C;
loc_823C9164:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823C9168:
	// lwz r9,360(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 360);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r11,368(r23)
	PPC_STORE_U32(r23.u32 + 368, r11.u32);
	// addi r11,r23,60
	r11.s64 = r23.s64 + 60;
	// lwz r7,212(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r25,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r25.u8);
	// addi r11,r7,456
	r11.s64 = ctx.r7.s64 + 456;
	// stw r9,376(r23)
	PPC_STORE_U32(r23.u32 + 376, ctx.r9.u32);
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r9,384(r23)
	PPC_STORE_U32(r23.u32 + 384, ctx.r9.u32);
	// lfs f0,14192(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lwz r3,364(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 364);
	// clrlwi r8,r25,24
	ctx.r8.u64 = r25.u32 & 0xFF;
	// addi r9,r11,2512
	ctx.r9.s64 = r11.s64 + 2512;
	// addi r7,r11,832
	ctx.r7.s64 = r11.s64 + 832;
	// stw r3,400(r11)
	PPC_STORE_U32(r11.u32 + 400, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,392(r11)
	PPC_STORE_U32(r11.u32 + 392, ctx.r3.u32);
	// addi r5,r11,3792
	ctx.r5.s64 = r11.s64 + 3792;
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// stw r3,416(r11)
	PPC_STORE_U32(r11.u32 + 416, ctx.r3.u32);
	// stw r3,408(r11)
	PPC_STORE_U32(r11.u32 + 408, ctx.r3.u32);
	// stfs f31,296(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 296, temp.u32);
	// stb r8,292(r11)
	PPC_STORE_U8(r11.u32 + 292, ctx.r8.u8);
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stb r10,293(r11)
	PPC_STORE_U8(r11.u32 + 293, ctx.r10.u8);
	// stb r10,289(r11)
	PPC_STORE_U8(r11.u32 + 289, ctx.r10.u8);
	// stb r10,290(r11)
	PPC_STORE_U8(r11.u32 + 290, ctx.r10.u8);
	// stb r10,291(r11)
	PPC_STORE_U8(r11.u32 + 291, ctx.r10.u8);
	// stw r6,300(r11)
	PPC_STORE_U32(r11.u32 + 300, ctx.r6.u32);
	// stb r10,304(r11)
	PPC_STORE_U8(r11.u32 + 304, ctx.r10.u8);
	// stb r10,305(r11)
	PPC_STORE_U8(r11.u32 + 305, ctx.r10.u8);
	// stb r10,316(r11)
	PPC_STORE_U8(r11.u32 + 316, ctx.r10.u8);
	// stb r10,317(r11)
	PPC_STORE_U8(r11.u32 + 317, ctx.r10.u8);
	// stfs f31,308(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 308, temp.u32);
	// stw r6,312(r11)
	PPC_STORE_U32(r11.u32 + 312, ctx.r6.u32);
	// stfs f0,324(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 324, temp.u32);
	// stfs f0,328(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 328, temp.u32);
	// stb r10,318(r11)
	PPC_STORE_U8(r11.u32 + 318, ctx.r10.u8);
	// stb r10,319(r11)
	PPC_STORE_U8(r11.u32 + 319, ctx.r10.u8);
	// stb r10,320(r11)
	PPC_STORE_U8(r11.u32 + 320, ctx.r10.u8);
	// stb r10,332(r11)
	PPC_STORE_U8(r11.u32 + 332, ctx.r10.u8);
	// stb r10,333(r11)
	PPC_STORE_U8(r11.u32 + 333, ctx.r10.u8);
	// stb r10,334(r11)
	PPC_STORE_U8(r11.u32 + 334, ctx.r10.u8);
	// stb r10,335(r11)
	PPC_STORE_U8(r11.u32 + 335, ctx.r10.u8);
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// stb r10,340(r11)
	PPC_STORE_U8(r11.u32 + 340, ctx.r10.u8);
	// stfs f31,76(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 76, temp.u32);
	// stw r10,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r10.u32);
	// stfs f31,72(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 72, temp.u32);
	// stfs f31,68(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// stw r10,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r10.u32);
	// stfs f31,80(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 80, temp.u32);
	// stw r10,456(r11)
	PPC_STORE_U32(r11.u32 + 456, ctx.r10.u32);
	// stw r10,460(r11)
	PPC_STORE_U32(r11.u32 + 460, ctx.r10.u32);
	// stw r10,464(r11)
	PPC_STORE_U32(r11.u32 + 464, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// rotlwi r9,r4,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// stw r10,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r10.u32);
loc_823C9268:
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// stb r10,-1280(r8)
	PPC_STORE_U8(ctx.r8.u32 + -1280, ctx.r10.u8);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// addi r8,r8,64
	ctx.r8.s64 = ctx.r8.s64 + 64;
	// stbx r10,r9,r5
	PPC_STORE_U8(ctx.r9.u32 + ctx.r5.u32, ctx.r10.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r9,20
	cr6.compare<int32_t>(ctx.r9.s32, 20, xer);
	// blt cr6,0x823c9268
	if (cr6.lt) goto loc_823C9268;
	// addi r8,r11,3812
	ctx.r8.s64 = r11.s64 + 3812;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,3876
	r11.s64 = r11.s64 + 3876;
loc_823C9298:
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r10.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// blt cr6,0x823c9298
	if (cr6.lt) goto loc_823C9298;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// addi r6,r8,-11472
	ctx.r6.s64 = ctx.r8.s64 + -11472;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stb r9,-11472(r8)
	PPC_STORE_U8(ctx.r8.u32 + -11472, ctx.r9.u8);
	// stb r11,128(r6)
	PPC_STORE_U8(ctx.r6.u32 + 128, r11.u8);
	// stb r10,-11756(r7)
	PPC_STORE_U8(ctx.r7.u32 + -11756, ctx.r10.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823C92DC"))) PPC_WEAK_FUNC(sub_823C92DC);
PPC_FUNC_IMPL(__imp__sub_823C92DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C92E0"))) PPC_WEAK_FUNC(sub_823C92E0);
PPC_FUNC_IMPL(__imp__sub_823C92E0) {
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
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lbz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// stb r7,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r7.u8);
	// lbz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// stb r6,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r6.u8);
	// lbz r5,9(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// stb r5,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r5.u8);
	// lbz r11,10(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// stb r11,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r11.u8);
	// lbz r10,11(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// stb r10,11(r31)
	PPC_STORE_U8(r31.u32 + 11, ctx.r10.u8);
	// sth r8,16(r31)
	PPC_STORE_U16(r31.u32 + 16, ctx.r8.u16);
	// lhz r5,16(r4)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + 16);
	// lwz r4,12(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x821c9650
	ctx.lr = 0x823C9344;
	sub_821C9650(ctx, base);
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

__attribute__((alias("__imp__sub_823C935C"))) PPC_WEAK_FUNC(sub_823C935C);
PPC_FUNC_IMPL(__imp__sub_823C935C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9360"))) PPC_WEAK_FUNC(sub_823C9360);
PPC_FUNC_IMPL(__imp__sub_823C9360) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// b 0x8246caf0
	sub_8246CAF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C9368"))) PPC_WEAK_FUNC(sub_823C9368);
PPC_FUNC_IMPL(__imp__sub_823C9368) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// b 0x8246cd60
	sub_8246CD60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C9370"))) PPC_WEAK_FUNC(sub_823C9370);
PPC_FUNC_IMPL(__imp__sub_823C9370) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10996
	ctx.r10.s64 = r11.s64 + -10996;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r3,220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// b 0x8246cb80
	sub_8246CB80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C938C"))) PPC_WEAK_FUNC(sub_823C938C);
PPC_FUNC_IMPL(__imp__sub_823C938C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9390"))) PPC_WEAK_FUNC(sub_823C9390);
PPC_FUNC_IMPL(__imp__sub_823C9390) {
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
	// lwz r11,17432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17432);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c93f8
	if (!cr6.eq) goto loc_823C93F8;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x823C93B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823c93dc
	if (cr6.eq) goto loc_823C93DC;
	// bl 0x823cf040
	ctx.lr = 0x823C93C4;
	sub_823CF040(ctx, base);
	// stw r3,17432(r31)
	PPC_STORE_U32(r31.u32 + 17432, ctx.r3.u32);
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
loc_823C93DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,17432(r31)
	PPC_STORE_U32(r31.u32 + 17432, ctx.r3.u32);
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
loc_823C93F8:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r3,17432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17432);
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

__attribute__((alias("__imp__sub_823C941C"))) PPC_WEAK_FUNC(sub_823C941C);
PPC_FUNC_IMPL(__imp__sub_823C941C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9420"))) PPC_WEAK_FUNC(sub_823C9420);
PPC_FUNC_IMPL(__imp__sub_823C9420) {
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
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r4,20
	r11.s64 = ctx.r4.s64 + 20;
	// addi r10,r31,20
	ctx.r10.s64 = r31.s64 + 20;
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// lbz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// stb r6,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r6.u8);
	// lwz r5,12(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// lwz r3,16(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823C946C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823c946c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823C946C;
	// addi r4,r4,44
	ctx.r4.s64 = ctx.r4.s64 + 44;
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x823c92e0
	ctx.lr = 0x823C948C;
	sub_823C92E0(ctx, base);
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

__attribute__((alias("__imp__sub_823C94A4"))) PPC_WEAK_FUNC(sub_823C94A4);
PPC_FUNC_IMPL(__imp__sub_823C94A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C94A8"))) PPC_WEAK_FUNC(sub_823C94A8);
PPC_FUNC_IMPL(__imp__sub_823C94A8) {
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
	// addi r10,r11,-17996
	ctx.r10.s64 = r11.s64 + -17996;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823C94D8;
	sub_82130588(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c94f0
	if (cr6.eq) goto loc_823C94F0;
	// bl 0x82130588
	ctx.lr = 0x823C94EC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823C94F0:
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

__attribute__((alias("__imp__sub_823C9508"))) PPC_WEAK_FUNC(sub_823C9508);
PPC_FUNC_IMPL(__imp__sub_823C9508) {
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
	ctx.lr = 0x823C9510;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c9594
	if (cr6.eq) goto loc_823C9594;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c95a0
	ctx.lr = 0x823C9530;
	sub_821C95A0(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// divwu r9,r3,r11
	ctx.r9.u32 = ctx.r3.u32 / r11.u32;
	// twllei r11,0
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r6,r10
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c9594
	if (cr6.eq) goto loc_823C9594;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
loc_823C9560:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c9574
	if (cr6.eq) goto loc_823C9574;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x823c9578
	goto loc_823C9578;
loc_823C9574:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_823C9578:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x823C9580;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823c95a0
	if (cr6.eq) goto loc_823C95A0;
	// lwz r31,16(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823c9560
	if (!cr6.eq) goto loc_823C9560;
loc_823C9594:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823C95A0:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C95AC"))) PPC_WEAK_FUNC(sub_823C95AC);
PPC_FUNC_IMPL(__imp__sub_823C95AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C95B0"))) PPC_WEAK_FUNC(sub_823C95B0);
PPC_FUNC_IMPL(__imp__sub_823C95B0) {
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
	ctx.lr = 0x823C95B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c963c
	if (cr6.eq) goto loc_823C963C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c95a0
	ctx.lr = 0x823C95D8;
	sub_821C95A0(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// divwu r9,r3,r11
	ctx.r9.u32 = ctx.r3.u32 / r11.u32;
	// twllei r11,0
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r6,r10
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c963c
	if (cr6.eq) goto loc_823C963C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
loc_823C9608:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c961c
	if (cr6.eq) goto loc_823C961C;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x823c9620
	goto loc_823C9620;
loc_823C961C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_823C9620:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x823C9628;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823c9648
	if (cr6.eq) goto loc_823C9648;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823c9608
	if (!cr6.eq) goto loc_823C9608;
loc_823C963C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823C9648:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C9654"))) PPC_WEAK_FUNC(sub_823C9654);
PPC_FUNC_IMPL(__imp__sub_823C9654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9658"))) PPC_WEAK_FUNC(sub_823C9658);
PPC_FUNC_IMPL(__imp__sub_823C9658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x823C9660;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// lbz r11,11(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c9748
	if (cr6.eq) goto loc_823C9748;
	// rlwinm r3,r22,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r28,r22,16
	r28.u64 = r22.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x823C9684;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823c96a8
	if (cr6.eq) goto loc_823C96A8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r28
	ctr.u64 = r28.u64;
loc_823C969C:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x823c969c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823C969C;
loc_823C96A8:
	// lhz r11,4(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c9738
	if (cr6.eq) goto loc_823C9738;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r26,0
	r26.s64 = 0;
	// addi r23,r11,3998
	r23.s64 = r11.s64 + 3998;
loc_823C96C4:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwzx r31,r26,r11
	r31.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c9724
	if (cr6.eq) goto loc_823C9724;
loc_823C96D4:
	// mr r30,r31
	r30.u64 = r31.u64;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c96f4
	if (cr6.eq) goto loc_823C96F4;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823c96f8
	goto loc_823C96F8;
loc_823C96F4:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_823C96F8:
	// bl 0x821c95a0
	ctx.lr = 0x823C96FC;
	sub_821C95A0(ctx, base);
	// divwu r11,r3,r28
	r11.u32 = ctx.r3.u32 / r28.u32;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mullw r10,r11,r28
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r28.s32);
	// subf r9,r10,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r10.s64;
	// twllei r28,0
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r27
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// stwx r30,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, r30.u32);
	// bne cr6,0x823c96d4
	if (!cr6.eq) goto loc_823C96D4;
loc_823C9724:
	// lhz r11,4(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// blt cr6,0x823c96c4
	if (cr6.lt) goto loc_823C96C4;
loc_823C9738:
	// sth r22,4(r24)
	PPC_STORE_U16(r24.u32 + 4, r22.u16);
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C9744;
	sub_82130588(ctx, base);
	// stw r27,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r27.u32);
loc_823C9748:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_823C9750"))) PPC_WEAK_FUNC(sub_823C9750);
PPC_FUNC_IMPL(__imp__sub_823C9750) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x823C9758;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// lbz r11,11(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c9840
	if (cr6.eq) goto loc_823C9840;
	// rlwinm r3,r22,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r28,r22,16
	r28.u64 = r22.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x823C977C;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823c97a0
	if (cr6.eq) goto loc_823C97A0;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r28
	ctr.u64 = r28.u64;
loc_823C9794:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x823c9794
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823C9794;
loc_823C97A0:
	// lhz r11,4(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c9830
	if (cr6.eq) goto loc_823C9830;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r26,0
	r26.s64 = 0;
	// addi r23,r11,3998
	r23.s64 = r11.s64 + 3998;
loc_823C97BC:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwzx r31,r26,r11
	r31.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823c981c
	if (cr6.eq) goto loc_823C981C;
loc_823C97CC:
	// mr r30,r31
	r30.u64 = r31.u64;
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// lwz r31,16(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c97ec
	if (cr6.eq) goto loc_823C97EC;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823c97f0
	goto loc_823C97F0;
loc_823C97EC:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_823C97F0:
	// bl 0x821c95a0
	ctx.lr = 0x823C97F4;
	sub_821C95A0(ctx, base);
	// divwu r11,r3,r28
	r11.u32 = ctx.r3.u32 / r28.u32;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mullw r10,r11,r28
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r28.s32);
	// subf r9,r10,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r10.s64;
	// twllei r28,0
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r27
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// stwx r30,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, r30.u32);
	// bne cr6,0x823c97cc
	if (!cr6.eq) goto loc_823C97CC;
loc_823C981C:
	// lhz r11,4(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// blt cr6,0x823c97bc
	if (cr6.lt) goto loc_823C97BC;
loc_823C9830:
	// sth r22,4(r24)
	PPC_STORE_U16(r24.u32 + 4, r22.u16);
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C983C;
	sub_82130588(ctx, base);
	// stw r27,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r27.u32);
loc_823C9840:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_823C9848"))) PPC_WEAK_FUNC(sub_823C9848);
PPC_FUNC_IMPL(__imp__sub_823C9848) {
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
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r11,-11548(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11548, r11.u32);
	// lwz r3,17432(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17432);
	// bl 0x821d6468
	ctx.lr = 0x823C986C;
	sub_821D6468(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// addi r7,r8,-10996
	ctx.r7.s64 = ctx.r8.s64 + -10996;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c9890
	if (!cr6.eq) goto loc_823C9890;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-4960(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// lwz r3,220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 220);
	// bl 0x8246cb80
	ctx.lr = 0x823C9890;
	sub_8246CB80(ctx, base);
loc_823C9890:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C98A0"))) PPC_WEAK_FUNC(sub_823C98A0);
PPC_FUNC_IMPL(__imp__sub_823C98A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d1be0
	sub_823D1BE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C98AC"))) PPC_WEAK_FUNC(sub_823C98AC);
PPC_FUNC_IMPL(__imp__sub_823C98AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C98B0"))) PPC_WEAK_FUNC(sub_823C98B0);
PPC_FUNC_IMPL(__imp__sub_823C98B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,216(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 216);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823c98ec
	if (!cr6.gt) goto loc_823C98EC;
	// lwz r11,212(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
loc_823C98C4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// bne cr6,0x823c98dc
	if (!cr6.eq) goto loc_823C98DC;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// beq cr6,0x823c98f8
	if (cr6.eq) goto loc_823C98F8;
loc_823C98DC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823c98c4
	if (cr6.lt) goto loc_823C98C4;
loc_823C98EC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d0d18
	sub_823D0D18(ctx, base);
	return;
loc_823C98F8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9910"))) PPC_WEAK_FUNC(sub_823C9910);
PPC_FUNC_IMPL(__imp__sub_823C9910) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d0dd0
	sub_823D0DD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C991C"))) PPC_WEAK_FUNC(sub_823C991C);
PPC_FUNC_IMPL(__imp__sub_823C991C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9920"))) PPC_WEAK_FUNC(sub_823C9920);
PPC_FUNC_IMPL(__imp__sub_823C9920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d0e88
	sub_823D0E88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C992C"))) PPC_WEAK_FUNC(sub_823C992C);
PPC_FUNC_IMPL(__imp__sub_823C992C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9930"))) PPC_WEAK_FUNC(sub_823C9930);
PPC_FUNC_IMPL(__imp__sub_823C9930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d1018
	sub_823D1018(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C993C"))) PPC_WEAK_FUNC(sub_823C993C);
PPC_FUNC_IMPL(__imp__sub_823C993C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9940"))) PPC_WEAK_FUNC(sub_823C9940);
PPC_FUNC_IMPL(__imp__sub_823C9940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d0f58
	sub_823D0F58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C994C"))) PPC_WEAK_FUNC(sub_823C994C);
PPC_FUNC_IMPL(__imp__sub_823C994C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9950"))) PPC_WEAK_FUNC(sub_823C9950);
PPC_FUNC_IMPL(__imp__sub_823C9950) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823d1088
	sub_823D1088(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C9964"))) PPC_WEAK_FUNC(sub_823C9964);
PPC_FUNC_IMPL(__imp__sub_823C9964) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9968"))) PPC_WEAK_FUNC(sub_823C9968);
PPC_FUNC_IMPL(__imp__sub_823C9968) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823d10e8
	sub_823D10E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C997C"))) PPC_WEAK_FUNC(sub_823C997C);
PPC_FUNC_IMPL(__imp__sub_823C997C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9980"))) PPC_WEAK_FUNC(sub_823C9980);
PPC_FUNC_IMPL(__imp__sub_823C9980) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,68
	ctx.r3.s64 = ctx.r3.s64 + 68;
	// bl 0x823c9508
	ctx.lr = 0x823C999C;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C99AC"))) PPC_WEAK_FUNC(sub_823C99AC);
PPC_FUNC_IMPL(__imp__sub_823C99AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C99B0"))) PPC_WEAK_FUNC(sub_823C99B0);
PPC_FUNC_IMPL(__imp__sub_823C99B0) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// bl 0x823c9508
	ctx.lr = 0x823C99CC;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C99DC"))) PPC_WEAK_FUNC(sub_823C99DC);
PPC_FUNC_IMPL(__imp__sub_823C99DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C99E0"))) PPC_WEAK_FUNC(sub_823C99E0);
PPC_FUNC_IMPL(__imp__sub_823C99E0) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,92
	ctx.r3.s64 = ctx.r3.s64 + 92;
	// bl 0x823c9508
	ctx.lr = 0x823C99FC;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9A0C"))) PPC_WEAK_FUNC(sub_823C9A0C);
PPC_FUNC_IMPL(__imp__sub_823C9A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9A10"))) PPC_WEAK_FUNC(sub_823C9A10);
PPC_FUNC_IMPL(__imp__sub_823C9A10) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,104
	ctx.r3.s64 = ctx.r3.s64 + 104;
	// bl 0x823c9508
	ctx.lr = 0x823C9A2C;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9A3C"))) PPC_WEAK_FUNC(sub_823C9A3C);
PPC_FUNC_IMPL(__imp__sub_823C9A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9A40"))) PPC_WEAK_FUNC(sub_823C9A40);
PPC_FUNC_IMPL(__imp__sub_823C9A40) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,116
	ctx.r3.s64 = ctx.r3.s64 + 116;
	// bl 0x823c9508
	ctx.lr = 0x823C9A5C;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9A6C"))) PPC_WEAK_FUNC(sub_823C9A6C);
PPC_FUNC_IMPL(__imp__sub_823C9A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9A70"))) PPC_WEAK_FUNC(sub_823C9A70);
PPC_FUNC_IMPL(__imp__sub_823C9A70) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// bl 0x823c9508
	ctx.lr = 0x823C9A8C;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9A9C"))) PPC_WEAK_FUNC(sub_823C9A9C);
PPC_FUNC_IMPL(__imp__sub_823C9A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9AA0"))) PPC_WEAK_FUNC(sub_823C9AA0);
PPC_FUNC_IMPL(__imp__sub_823C9AA0) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,140
	ctx.r3.s64 = ctx.r3.s64 + 140;
	// bl 0x823c9508
	ctx.lr = 0x823C9ABC;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9ACC"))) PPC_WEAK_FUNC(sub_823C9ACC);
PPC_FUNC_IMPL(__imp__sub_823C9ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9AD0"))) PPC_WEAK_FUNC(sub_823C9AD0);
PPC_FUNC_IMPL(__imp__sub_823C9AD0) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,152
	ctx.r3.s64 = ctx.r3.s64 + 152;
	// bl 0x823c9508
	ctx.lr = 0x823C9AEC;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9AFC"))) PPC_WEAK_FUNC(sub_823C9AFC);
PPC_FUNC_IMPL(__imp__sub_823C9AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9B00"))) PPC_WEAK_FUNC(sub_823C9B00);
PPC_FUNC_IMPL(__imp__sub_823C9B00) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,164
	ctx.r3.s64 = ctx.r3.s64 + 164;
	// bl 0x823c9508
	ctx.lr = 0x823C9B1C;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9B2C"))) PPC_WEAK_FUNC(sub_823C9B2C);
PPC_FUNC_IMPL(__imp__sub_823C9B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9B30"))) PPC_WEAK_FUNC(sub_823C9B30);
PPC_FUNC_IMPL(__imp__sub_823C9B30) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,176
	ctx.r3.s64 = ctx.r3.s64 + 176;
	// bl 0x823c9508
	ctx.lr = 0x823C9B4C;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9B5C"))) PPC_WEAK_FUNC(sub_823C9B5C);
PPC_FUNC_IMPL(__imp__sub_823C9B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9B60"))) PPC_WEAK_FUNC(sub_823C9B60);
PPC_FUNC_IMPL(__imp__sub_823C9B60) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,188
	ctx.r3.s64 = ctx.r3.s64 + 188;
	// bl 0x823c9508
	ctx.lr = 0x823C9B7C;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9B8C"))) PPC_WEAK_FUNC(sub_823C9B8C);
PPC_FUNC_IMPL(__imp__sub_823C9B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9B90"))) PPC_WEAK_FUNC(sub_823C9B90);
PPC_FUNC_IMPL(__imp__sub_823C9B90) {
	PPC_FUNC_PROLOGUE();
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,200
	ctx.r3.s64 = ctx.r3.s64 + 200;
	// bl 0x823c9508
	ctx.lr = 0x823C9BAC;
	sub_823C9508(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9BBC"))) PPC_WEAK_FUNC(sub_823C9BBC);
PPC_FUNC_IMPL(__imp__sub_823C9BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9BC0"))) PPC_WEAK_FUNC(sub_823C9BC0);
PPC_FUNC_IMPL(__imp__sub_823C9BC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d0958
	sub_823D0958(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C9BCC"))) PPC_WEAK_FUNC(sub_823C9BCC);
PPC_FUNC_IMPL(__imp__sub_823C9BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9BD0"))) PPC_WEAK_FUNC(sub_823C9BD0);
PPC_FUNC_IMPL(__imp__sub_823C9BD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d09e0
	sub_823D09E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C9BDC"))) PPC_WEAK_FUNC(sub_823C9BDC);
PPC_FUNC_IMPL(__imp__sub_823C9BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9BE0"))) PPC_WEAK_FUNC(sub_823C9BE0);
PPC_FUNC_IMPL(__imp__sub_823C9BE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823c9c2c
	if (!cr6.eq) goto loc_823C9C2C;
	// lhz r9,216(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 216);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823c9c2c
	if (!cr6.gt) goto loc_823C9C2C;
	// lwz r8,212(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_823C9C04:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// bne cr6,0x823c9c1c
	if (!cr6.eq) goto loc_823C9C1C;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r7,r4
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, xer);
	// beq cr6,0x823c9c38
	if (cr6.eq) goto loc_823C9C38;
loc_823C9C1C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823c9c04
	if (cr6.lt) goto loc_823C9C04;
loc_823C9C2C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d0a78
	sub_823D0A78(ctx, base);
	return;
loc_823C9C38:
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stb r5,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823C9C48"))) PPC_WEAK_FUNC(sub_823C9C48);
PPC_FUNC_IMPL(__imp__sub_823C9C48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// b 0x823d0ad8
	sub_823D0AD8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823C9C54"))) PPC_WEAK_FUNC(sub_823C9C54);
PPC_FUNC_IMPL(__imp__sub_823C9C54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9C58"))) PPC_WEAK_FUNC(sub_823C9C58);
PPC_FUNC_IMPL(__imp__sub_823C9C58) {
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
	ctx.lr = 0x823C9C60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r31,216(r10)
	r31.u64 = PPC_LOAD_U16(ctx.r10.u32 + 216);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x823c9c98
	if (!cr6.gt) goto loc_823C9C98;
	// lwz r11,212(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 212);
loc_823C9C7C:
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r30,r4
	cr6.compare<int32_t>(r30.s32, ctx.r4.s32, xer);
	// beq cr6,0x823c9d64
	if (cr6.eq) goto loc_823C9D64;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// cmpw cr6,r3,r31
	cr6.compare<int32_t>(ctx.r3.s32, r31.s32, xer);
	// blt cr6,0x823c9c7c
	if (cr6.lt) goto loc_823C9C7C;
loc_823C9C98:
	// lhz r11,216(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 216);
	// li r30,1
	r30.s64 = 1;
	// lwz r31,212(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 212);
	// li r29,0
	r29.s64 = 0;
	// rotlwi r3,r11,6
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 6);
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// sth r28,216(r10)
	PPC_STORE_U16(ctx.r10.u32 + 216, r28.u16);
	// addi r10,r10,212
	ctx.r10.s64 = ctx.r10.s64 + 212;
	// addi r10,r8,8
	ctx.r10.s64 = ctx.r8.s64 + 8;
	// addi r10,r9,8
	ctx.r10.s64 = ctx.r9.s64 + 8;
	// addi r31,r11,20
	r31.s64 = r11.s64 + 20;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// addi r3,r11,44
	ctx.r3.s64 = r11.s64 + 44;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r6,r31,8
	ctx.r6.s64 = r31.s64 + 8;
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// stb r5,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r5.u8);
	// stw r7,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r7.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// lwz r5,4(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r5,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r5.u32);
	// lwz r4,8(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r4,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r4.u32);
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// stw r7,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r7.u32);
	// lwz r6,20(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// stw r6,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r6.u32);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r5,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r5.u32);
	// lbz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 4);
	// stb r4,48(r11)
	PPC_STORE_U8(r11.u32 + 48, ctx.r4.u8);
	// lbz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 8);
	// stb r10,52(r11)
	PPC_STORE_U8(r11.u32 + 52, ctx.r10.u8);
	// lbz r8,9(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 9);
	// stb r8,53(r11)
	PPC_STORE_U8(r11.u32 + 53, ctx.r8.u8);
	// lbz r7,10(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 10);
	// stb r7,54(r11)
	PPC_STORE_U8(r11.u32 + 54, ctx.r7.u8);
	// lbz r6,11(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 11);
	// stb r6,55(r11)
	PPC_STORE_U8(r11.u32 + 55, ctx.r6.u8);
	// sth r29,60(r11)
	PPC_STORE_U16(r11.u32 + 60, r29.u16);
	// lhz r5,16(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// bl 0x821c9650
	ctx.lr = 0x823C9D5C;
	sub_821C9650(ctx, base);
loc_823C9D5C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823C9D64:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x823c9d90
	if (!cr6.eq) goto loc_823C9D90;
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823c9d5c
	if (cr6.eq) goto loc_823C9D5C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-17992
	ctx.r3.s64 = r11.s64 + -17992;
	// bl 0x82130000
	ctx.lr = 0x823C9D88;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823C9D90:
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x823c9d5c
	if (!cr6.eq) goto loc_823C9D5C;
	// lbz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 48);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823c9d5c
	if (!cr6.eq) goto loc_823C9D5C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823C9DB4"))) PPC_WEAK_FUNC(sub_823C9DB4);
PPC_FUNC_IMPL(__imp__sub_823C9DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9DB8"))) PPC_WEAK_FUNC(sub_823C9DB8);
PPC_FUNC_IMPL(__imp__sub_823C9DB8) {
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
	ctx.lr = 0x823C9DC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-17996
	ctx.r9.s64 = ctx.r10.s64 + -17996;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r5,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r5.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// lhz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x823C9E08;
	sub_821C9650(ctx, base);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823c9e1c
	if (cr6.eq) goto loc_823C9E1C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823c9e24
	goto loc_823C9E24;
loc_823C9E1C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
loc_823C9E24:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821c9790
	ctx.lr = 0x823C9E2C;
	sub_821C9790(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C9E38;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C9E44"))) PPC_WEAK_FUNC(sub_823C9E44);
PPC_FUNC_IMPL(__imp__sub_823C9E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9E48"))) PPC_WEAK_FUNC(sub_823C9E48);
PPC_FUNC_IMPL(__imp__sub_823C9E48) {
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
	ctx.lr = 0x823C9E50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-17996
	ctx.r9.s64 = ctx.r10.s64 + -17996;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// lhz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x823C9E98;
	sub_821C9650(ctx, base);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823c9eac
	if (cr6.eq) goto loc_823C9EAC;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823c9eb4
	goto loc_823C9EB4;
loc_823C9EAC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
loc_823C9EB4:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821c9790
	ctx.lr = 0x823C9EBC;
	sub_821C9790(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C9EC8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C9ED4"))) PPC_WEAK_FUNC(sub_823C9ED4);
PPC_FUNC_IMPL(__imp__sub_823C9ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9ED8"))) PPC_WEAK_FUNC(sub_823C9ED8);
PPC_FUNC_IMPL(__imp__sub_823C9ED8) {
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
	ctx.lr = 0x823C9EE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-17896
	ctx.r9.s64 = ctx.r10.s64 + -17896;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// lhz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x823C9F28;
	sub_821C9650(ctx, base);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823c9f3c
	if (cr6.eq) goto loc_823C9F3C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823c9f44
	goto loc_823C9F44;
loc_823C9F3C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
loc_823C9F44:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821c9790
	ctx.lr = 0x823C9F4C;
	sub_821C9790(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823C9F58;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823C9F64"))) PPC_WEAK_FUNC(sub_823C9F64);
PPC_FUNC_IMPL(__imp__sub_823C9F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823C9F68"))) PPC_WEAK_FUNC(sub_823C9F68);
PPC_FUNC_IMPL(__imp__sub_823C9F68) {
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
	// addi r10,r11,-17896
	ctx.r10.s64 = r11.s64 + -17896;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823C9F98;
	sub_82130588(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c9fb0
	if (cr6.eq) goto loc_823C9FB0;
	// bl 0x82130588
	ctx.lr = 0x823C9FAC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823C9FB0:
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

__attribute__((alias("__imp__sub_823C9FC8"))) PPC_WEAK_FUNC(sub_823C9FC8);
PPC_FUNC_IMPL(__imp__sub_823C9FC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ca014
	if (cr6.eq) goto loc_823CA014;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
loc_823C9FE0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823c9ff8
	if (cr6.eq) goto loc_823C9FF8;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x823c9ffc
	if (cr6.eq) goto loc_823C9FFC;
loc_823C9FF8:
	// li r11,0
	r11.s64 = 0;
loc_823C9FFC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823c9fe0
	if (!cr6.eq) goto loc_823C9FE0;
loc_823CA014:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CA01C"))) PPC_WEAK_FUNC(sub_823CA01C);
PPC_FUNC_IMPL(__imp__sub_823CA01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CA020"))) PPC_WEAK_FUNC(sub_823CA020);
PPC_FUNC_IMPL(__imp__sub_823CA020) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ca074
	if (cr6.eq) goto loc_823CA074;
	// lwz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
loc_823CA03C:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ca054
	if (cr6.eq) goto loc_823CA054;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x823ca058
	if (cr6.eq) goto loc_823CA058;
loc_823CA054:
	// li r11,0
	r11.s64 = 0;
loc_823CA058:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ca07c
	if (!cr6.eq) goto loc_823CA07C;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823ca03c
	if (!cr6.eq) goto loc_823CA03C;
loc_823CA074:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_823CA07C:
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CA084"))) PPC_WEAK_FUNC(sub_823CA084);
PPC_FUNC_IMPL(__imp__sub_823CA084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

