#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8274EBC0"))) PPC_WEAK_FUNC(sub_8274EBC0);
PPC_FUNC_IMPL(__imp__sub_8274EBC0) {
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
	ctx.lr = 0x8274EBC8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r29,r11,-21400
	r29.s64 = r11.s64 + -21400;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x8274eaa0
	ctx.lr = 0x8274EBE8;
	sub_8274EAA0(ctx, base);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// li r3,2240
	ctx.r3.s64 = 2240;
	// ori r4,r4,32780
	ctx.r4.u64 = ctx.r4.u64 | 32780;
	// bl 0x82130b50
	ctx.lr = 0x8274EBF8;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274ec0c
	if (!cr0.eq) goto loc_8274EC0C;
	// lis r29,-32761
	r29.s64 = -2147024896;
	// ori r29,r29,14
	r29.u64 = r29.u64 | 14;
	// b 0x8274edb0
	goto loc_8274EDB0;
loc_8274EC0C:
	// li r25,1
	r25.s64 = 1;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r25,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r25.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x8274EC28;
	sub_823DA950(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274d490
	ctx.lr = 0x8274EC34;
	sub_8274D490(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8274eda4
	if (cr0.lt) goto loc_8274EDA4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274ec80
	if (!cr6.gt) goto loc_8274EC80;
	// addi r28,r31,1096
	r28.s64 = r31.s64 + 1096;
loc_8274EC50:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x82751928
	ctx.lr = 0x8274EC64;
	sub_82751928(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8274eda4
	if (cr0.lt) goto loc_8274EDA4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8274ec50
	if (cr6.lt) goto loc_8274EC50;
loc_8274EC80:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274eccc
	if (!cr6.gt) goto loc_8274ECCC;
	// addi r28,r31,1128
	r28.s64 = r31.s64 + 1128;
loc_8274EC94:
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r7,40(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,36(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x82752c70
	ctx.lr = 0x8274ECB0;
	sub_82752C70(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8274eda4
	if (cr0.lt) goto loc_8274EDA4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8274ec94
	if (cr6.lt) goto loc_8274EC94;
loc_8274ECCC:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x8274ECE0;
	sub_8244EE40(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,1304(r31)
	PPC_STORE_U32(r31.u32 + 1304, ctx.r3.u32);
	// bne 0x8274ecf8
	if (!cr0.eq) goto loc_8274ECF8;
loc_8274ECEC:
	// lis r29,-32768
	r29.s64 = -2147483648;
	// ori r29,r29,16389
	r29.u64 = r29.u64 | 16389;
	// b 0x8274eda4
	goto loc_8274EDA4;
loc_8274ECF8:
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x827bd3f4
	ctx.lr = 0x8274ED04;
	__imp__XamNotifyCreateListener(ctx, base);
	// stw r3,1312(r31)
	PPC_STORE_U32(r31.u32 + 1312, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8274ecec
	if (cr0.eq) goto loc_8274ECEC;
	// stw r25,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r25.u32);
	// addi r3,r31,1272
	ctx.r3.s64 = r31.s64 + 1272;
	// bl 0x827bcff4
	ctx.lr = 0x8274ED1C;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274ed9c
	if (!cr6.eq) goto loc_8274ED9C;
	// lis r11,-32139
	r11.s64 = -2106261504;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,-5648
	ctx.r5.s64 = r11.s64 + -5648;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82460300
	ctx.lr = 0x8274ED4C;
	sub_82460300(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,1264(r31)
	PPC_STORE_U32(r31.u32 + 1264, ctx.r3.u32);
	// beq 0x8274ecec
	if (cr0.eq) goto loc_8274ECEC;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,1304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1304);
	// bl 0x82135db8
	ctx.lr = 0x8274ED64;
	sub_82135DB8(ctx, base);
	// lwz r6,4(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8274ed9c
	if (cr6.eq) goto loc_8274ED9C;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,1264(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8275cf78
	ctx.lr = 0x8274ED8C;
	sub_8275CF78(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8274ed9c
	if (!cr0.eq) goto loc_8274ED9C;
	// lis r29,-32768
	r29.s64 = -2147483648;
	// ori r29,r29,16389
	r29.u64 = r29.u64 | 16389;
loc_8274ED9C:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bge cr6,0x8274edb0
	if (!cr6.lt) goto loc_8274EDB0;
loc_8274EDA4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274e2f0
	ctx.lr = 0x8274EDAC;
	sub_8274E2F0(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274EDB0:
	// stw r31,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r31.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8274EDC0"))) PPC_WEAK_FUNC(sub_8274EDC0);
PPC_FUNC_IMPL(__imp__sub_8274EDC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274EDE8"))) PPC_WEAK_FUNC(sub_8274EDE8);
PPC_FUNC_IMPL(__imp__sub_8274EDE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274EE10"))) PPC_WEAK_FUNC(sub_8274EE10);
PPC_FUNC_IMPL(__imp__sub_8274EE10) {
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
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274ee8c
	if (!cr6.eq) goto loc_8274EE8C;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274ee8c
	if (cr6.eq) goto loc_8274EE8C;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r9,16
	r11.s64 = ctx.r9.s64 + 16;
loc_8274EE3C:
	// lwz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274ee54
	if (cr6.eq) goto loc_8274EE54;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// beq cr6,0x8274ee7c
	if (cr6.eq) goto loc_8274EE7C;
loc_8274EE54:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// blt cr6,0x8274ee3c
	if (cr6.lt) goto loc_8274EE3C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8274EE68:
	// addi r11,r3,0
	r11.s64 = ctx.r3.s64 + 0;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = r11.u64 ^ 1;
	// b 0x8274ee90
	goto loc_8274EE90;
loc_8274EE7C:
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x8274f988
	ctx.lr = 0x8274EE88;
	sub_8274F988(ctx, base);
	// b 0x8274ee68
	goto loc_8274EE68;
loc_8274EE8C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8274EE90:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274EEA0"))) PPC_WEAK_FUNC(sub_8274EEA0);
PPC_FUNC_IMPL(__imp__sub_8274EEA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// mullw r3,r3,r11
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(r11.s32);
	// ori r4,r4,24
	ctx.r4.u64 = ctx.r4.u64 | 24;
	// b 0x82130b50
	sub_82130B50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8274EEB4"))) PPC_WEAK_FUNC(sub_8274EEB4);
PPC_FUNC_IMPL(__imp__sub_8274EEB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274EEB8"))) PPC_WEAK_FUNC(sub_8274EEB8);
PPC_FUNC_IMPL(__imp__sub_8274EEB8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x8274EED0;
	sub_8244D150(ctx, base);
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

__attribute__((alias("__imp__sub_8274EEE8"))) PPC_WEAK_FUNC(sub_8274EEE8);
PPC_FUNC_IMPL(__imp__sub_8274EEE8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823da950
	ctx.lr = 0x8274EF00;
	sub_823DA950(ctx, base);
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

__attribute__((alias("__imp__sub_8274EF18"))) PPC_WEAK_FUNC(sub_8274EF18);
PPC_FUNC_IMPL(__imp__sub_8274EF18) {
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
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// bl 0x82753160
	ctx.lr = 0x8274EF2C;
	sub_82753160(ctx, base);
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

__attribute__((alias("__imp__sub_8274EF40"))) PPC_WEAK_FUNC(sub_8274EF40);
PPC_FUNC_IMPL(__imp__sub_8274EF40) {
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
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// bl 0x82753570
	ctx.lr = 0x8274EF54;
	sub_82753570(ctx, base);
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

__attribute__((alias("__imp__sub_8274EF68"))) PPC_WEAK_FUNC(sub_8274EF68);
PPC_FUNC_IMPL(__imp__sub_8274EF68) {
	PPC_FUNC_PROLOGUE();
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// ori r4,r4,24
	ctx.r4.u64 = ctx.r4.u64 | 24;
	// b 0x821310f8
	sub_821310F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8274EF74"))) PPC_WEAK_FUNC(sub_8274EF74);
PPC_FUNC_IMPL(__imp__sub_8274EF74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274EF78"))) PPC_WEAK_FUNC(sub_8274EF78);
PPC_FUNC_IMPL(__imp__sub_8274EF78) {
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
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-4448
	ctx.r3.s64 = r11.s64 + -4448;
	// bl 0x827536c8
	ctx.lr = 0x8274EF90;
	sub_827536C8(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-4248
	ctx.r3.s64 = r11.s64 + -4248;
	// bl 0x827536e0
	ctx.lr = 0x8274EF9C;
	sub_827536E0(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-4424
	ctx.r3.s64 = r11.s64 + -4424;
	// bl 0x827536f8
	ctx.lr = 0x8274EFA8;
	sub_827536F8(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-4376
	ctx.r3.s64 = r11.s64 + -4376;
	// bl 0x82753710
	ctx.lr = 0x8274EFB4;
	sub_82753710(ctx, base);
	// lis r11,-32194
	r11.s64 = -2109865984;
	// addi r3,r11,-17464
	ctx.r3.s64 = r11.s64 + -17464;
	// bl 0x82753728
	ctx.lr = 0x8274EFC0;
	sub_82753728(ctx, base);
	// lis r11,-32194
	r11.s64 = -2109865984;
	// addi r3,r11,-17688
	ctx.r3.s64 = r11.s64 + -17688;
	// bl 0x82753740
	ctx.lr = 0x8274EFCC;
	sub_82753740(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274EFDC"))) PPC_WEAK_FUNC(sub_8274EFDC);
PPC_FUNC_IMPL(__imp__sub_8274EFDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274EFE0"))) PPC_WEAK_FUNC(sub_8274EFE0);
PPC_FUNC_IMPL(__imp__sub_8274EFE0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8274ef78
	ctx.lr = 0x8274EFFC;
	sub_8274EF78(ctx, base);
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82753280
	ctx.lr = 0x8274F008;
	sub_82753280(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274f024
	if (cr0.eq) goto loc_8274F024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82753160
	ctx.lr = 0x8274F018;
	sub_82753160(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8274f048
	goto loc_8274F048;
loc_8274F024:
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// li r10,160
	ctx.r10.s64 = 160;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// addi r9,r31,384
	ctx.r9.s64 = r31.s64 + 384;
	// li r11,9
	r11.s64 = 9;
	// sth r10,32(r31)
	PPC_STORE_U16(r31.u32 + 32, ctx.r10.u16);
	// stw r9,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r11,40(r31)
	PPC_STORE_U16(r31.u32 + 40, r11.u16);
loc_8274F048:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274F060"))) PPC_WEAK_FUNC(sub_8274F060);
PPC_FUNC_IMPL(__imp__sub_8274F060) {
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
	ctx.lr = 0x8274F068;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// addi r9,r31,28
	ctx.r9.s64 = r31.s64 + 28;
	// addi r23,r31,8
	r23.s64 = r31.s64 + 8;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r20,r24
	r20.u64 = r24.u64;
	// li r22,1
	r22.s64 = 1;
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// lwz r25,8(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
loc_8274F0A4:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274f0e0
	if (cr6.eq) goto loc_8274F0E0;
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// bne cr6,0x8274f0c8
	if (!cr6.eq) goto loc_8274F0C8;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x8274f0cc
	goto loc_8274F0CC;
loc_8274F0C8:
	// stw r24,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r24.u32);
loc_8274F0CC:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274f0e4
	if (cr6.eq) goto loc_8274F0E4;
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// b 0x8274f0e4
	goto loc_8274F0E4;
loc_8274F0E0:
	// stw r24,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r24.u32);
loc_8274F0E4:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8274f0a4
	if (!cr0.eq) goto loc_8274F0A4;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8274f254
	if (cr6.eq) goto loc_8274F254;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8274f254
	if (cr6.eq) goto loc_8274F254;
	// mr r22,r24
	r22.u64 = r24.u64;
	// b 0x8274f24c
	goto loc_8274F24C;
loc_8274F10C:
	// addi r21,r21,-1
	r21.s64 = r21.s64 + -1;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8274f254
	if (cr6.eq) goto loc_8274F254;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8274f254
	if (cr6.eq) goto loc_8274F254;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// addi r3,r31,400
	ctx.r3.s64 = r31.s64 + 400;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r6,r9,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x82751ca8
	ctx.lr = 0x8274F14C;
	sub_82751CA8(ctx, base);
	// stb r24,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r24.u8);
	// sth r24,46(r31)
	PPC_STORE_U16(r31.u32 + 46, r24.u16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// bl 0x82752ff8
	ctx.lr = 0x8274F164;
	sub_82752FF8(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274f254
	if (!cr0.eq) goto loc_8274F254;
	// lhz r29,46(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// mr r22,r24
	r22.u64 = r24.u64;
	// addi r28,r1,88
	r28.s64 = ctx.r1.s64 + 88;
	// mr r27,r23
	r27.u64 = r23.u64;
	// li r26,2
	r26.s64 = 2;
loc_8274F180:
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274f1f4
	if (cr6.eq) goto loc_8274F1F4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r31,384
	ctx.r4.s64 = r31.s64 + 384;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x8274F1A8;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274f1c4
	if (!cr6.lt) goto loc_8274F1C4;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274F1C4:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8274f1f4
	if (!cr6.eq) goto loc_8274F1F4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F1E4;
	sub_8274F9A8(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274f1f4
	if (!cr0.eq) goto loc_8274F1F4;
	// addi r20,r20,-1
	r20.s64 = r20.s64 + -1;
loc_8274F1F4:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x8274f180
	if (!cr0.eq) goto loc_8274F180;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274f228
	if (!cr6.lt) goto loc_8274F228;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274F228:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8274f24c
	if (!cr6.eq) goto loc_8274F24C;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F248;
	sub_8274F9A8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
loc_8274F24C:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x8274f10c
	if (!cr6.eq) goto loc_8274F10C;
loc_8274F254:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8274F260"))) PPC_WEAK_FUNC(sub_8274F260);
PPC_FUNC_IMPL(__imp__sub_8274F260) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8274ef78
	ctx.lr = 0x8274F27C;
	sub_8274EF78(ctx, base);
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827536c0
	ctx.lr = 0x8274F288;
	sub_827536C0(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274f2a4
	if (cr0.eq) goto loc_8274F2A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82753570
	ctx.lr = 0x8274F298;
	sub_82753570(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8274f2c0
	goto loc_8274F2C0;
loc_8274F2A4:
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// addi r10,r31,704
	ctx.r10.s64 = r31.s64 + 704;
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r9,40(r31)
	PPC_STORE_U16(r31.u32 + 40, ctx.r9.u16);
loc_8274F2C0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274F2D8"))) PPC_WEAK_FUNC(sub_8274F2D8);
PPC_FUNC_IMPL(__imp__sub_8274F2D8) {
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
	ctx.lr = 0x8274F2E0;
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// addi r21,r31,28
	r21.s64 = r31.s64 + 28;
	// addi r20,r31,8
	r20.s64 = r31.s64 + 8;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r18,r23
	r18.u64 = r23.u64;
	// li r17,1
	r17.s64 = 1;
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r22,8(r11)
	r22.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r21.u32);
	// stw r23,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r23.u32);
loc_8274F31C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274f358
	if (cr6.eq) goto loc_8274F358;
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// bne cr6,0x8274f340
	if (!cr6.eq) goto loc_8274F340;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x8274f344
	goto loc_8274F344;
loc_8274F340:
	// stw r23,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r23.u32);
loc_8274F344:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274f35c
	if (cr6.eq) goto loc_8274F35C;
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// b 0x8274f35c
	goto loc_8274F35C;
loc_8274F358:
	// stw r23,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r23.u32);
loc_8274F35C:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8274f31c
	if (!cr0.eq) goto loc_8274F31C;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8274f56c
	if (cr6.eq) goto loc_8274F56C;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8274f56c
	if (cr6.eq) goto loc_8274F56C;
	// mr r17,r23
	r17.u64 = r23.u64;
	// b 0x8274f564
	goto loc_8274F564;
loc_8274F384:
	// addi r19,r19,-1
	r19.s64 = r19.s64 + -1;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8274f56c
	if (cr6.eq) goto loc_8274F56C;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8274f56c
	if (cr6.eq) goto loc_8274F56C;
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r3,r31,704
	ctx.r3.s64 = r31.s64 + 704;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,24(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x8274F3B8;
	sub_823DA950(ctx, base);
	// addi r28,r31,64
	r28.s64 = r31.s64 + 64;
	// sth r23,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r23.u16);
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// stw r28,0(r21)
	PPC_STORE_U32(r21.u32 + 0, r28.u32);
	// sth r23,42(r31)
	PPC_STORE_U16(r31.u32 + 42, r23.u16);
	// stb r23,44(r31)
	PPC_STORE_U8(r31.u32 + 44, r23.u8);
loc_8274F3D0:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82753408
	ctx.lr = 0x8274F3E0;
	sub_82753408(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi. r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274f41c
	if (!cr0.eq) goto loc_8274F41C;
	// lhz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// sth r23,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r23.u16);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r21)
	PPC_STORE_U32(r21.u32 + 0, r11.u32);
	// bl 0x827534a0
	ctx.lr = 0x8274F410;
	sub_827534A0(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x8274f3d0
	if (cr0.eq) goto loc_8274F3D0;
loc_8274F41C:
	// clrlwi. r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274f56c
	if (!cr0.eq) goto loc_8274F56C;
	// li r11,160
	r11.s64 = 160;
	// lhz r24,42(r31)
	r24.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// li r5,320
	ctx.r5.s64 = 320;
	// sth r11,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r11.u16);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823da950
	ctx.lr = 0x8274F440;
	sub_823DA950(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,160
	ctx.r6.s64 = 160;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,720
	ctx.r3.s64 = r31.s64 + 720;
	// bl 0x82751ca8
	ctx.lr = 0x8274F458;
	sub_82751CA8(ctx, base);
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// mr r26,r20
	r26.u64 = r20.u64;
	// li r25,2
	r25.s64 = 2;
loc_8274F464:
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274f514
	if (cr6.eq) goto loc_8274F514;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,8000
	ctx.r10.s64 = 8000;
	// lhz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// mulli r9,r9,16000
	ctx.r9.s64 = ctx.r9.s64 * 16000;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// divw r10,r9,r10
	ctx.r10.s32 = ctx.r9.s32 / ctx.r10.s32;
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// rlwinm r29,r10,1,0,30
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274f4ac
	if (cr6.lt) goto loc_8274F4AC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r29,r11,r10
	r29.s64 = ctx.r10.s64 - r11.s64;
loc_8274F4AC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x8274F4C8;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274f4e4
	if (!cr6.lt) goto loc_8274F4E4;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274F4E4:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8274f514
	if (!cr6.eq) goto loc_8274F514;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F504;
	sub_8274F9A8(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274f514
	if (!cr0.eq) goto loc_8274F514;
	// addi r18,r18,-1
	r18.s64 = r18.s64 + -1;
loc_8274F514:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x8274f464
	if (!cr0.eq) goto loc_8274F464;
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r24,r9
	ctx.r9.u64 = r24.u64 + ctx.r9.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274f540
	if (!cr6.lt) goto loc_8274F540;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274F540:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8274f564
	if (!cr6.eq) goto loc_8274F564;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F560;
	sub_8274F9A8(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
loc_8274F564:
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x8274f384
	if (!cr6.eq) goto loc_8274F384;
loc_8274F56C:
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8274F578"))) PPC_WEAK_FUNC(sub_8274F578);
PPC_FUNC_IMPL(__imp__sub_8274F578) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8274f58c
	if (!cr6.eq) goto loc_8274F58C;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x8274f598
	goto loc_8274F598;
loc_8274F58C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r3
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
loc_8274F598:
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x8274fa28
	sub_8274FA28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8274F5A0"))) PPC_WEAK_FUNC(sub_8274F5A0);
PPC_FUNC_IMPL(__imp__sub_8274F5A0) {
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
	ctx.lr = 0x8274F5A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_8274F5C0:
	// lwz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274f5d8
	if (cr6.eq) goto loc_8274F5D8;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x8274f604
	if (cr6.eq) goto loc_8274F604;
loc_8274F5D8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// blt cr6,0x8274f5c0
	if (cr6.lt) goto loc_8274F5C0;
	// mr r28,r27
	r28.u64 = r27.u64;
loc_8274F5EC:
	// subf r30,r29,r4
	r30.s64 = ctx.r4.s64 - r29.s64;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x8274f640
	if (cr6.eq) goto loc_8274F640;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8274f638
	goto loc_8274F638;
loc_8274F604:
	// li r28,1
	r28.s64 = 1;
	// b 0x8274f5ec
	goto loc_8274F5EC;
loc_8274F60C:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f640
	if (cr6.eq) goto loc_8274F640;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F634;
	sub_8274F9A8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8274F638:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274f60c
	if (!cr6.eq) goto loc_8274F60C;
loc_8274F640:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bne cr6,0x8274f678
	if (!cr6.eq) goto loc_8274F678;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f670
	if (cr6.eq) goto loc_8274F670;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274F668;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8274f6b8
	goto loc_8274F6B8;
loc_8274F670:
	// li r27,1
	r27.s64 = 1;
	// b 0x8274f6b8
	goto loc_8274F6B8;
loc_8274F678:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8274f6b0
	goto loc_8274F6B0;
loc_8274F684:
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f6b8
	if (cr6.eq) goto loc_8274F6B8;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F6AC;
	sub_8274F9A8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8274F6B0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8274f684
	if (!cr6.eq) goto loc_8274F684;
loc_8274F6B8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274F6C4"))) PPC_WEAK_FUNC(sub_8274F6C4);
PPC_FUNC_IMPL(__imp__sub_8274F6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274F6C8"))) PPC_WEAK_FUNC(sub_8274F6C8);
PPC_FUNC_IMPL(__imp__sub_8274F6C8) {
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
	ctx.lr = 0x8274F6D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f6f4
	if (cr6.eq) goto loc_8274F6F4;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_8274F6F4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274f700
	if (cr6.eq) goto loc_8274F700;
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
loc_8274F700:
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// ori r31,r9,1
	r31.u64 = ctx.r9.u64 | 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274f764
	if (cr6.eq) goto loc_8274F764;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f744
	if (cr6.eq) goto loc_8274F744;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f764
	if (cr6.eq) goto loc_8274F764;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F740;
	sub_8274F9A8(ctx, base);
	// b 0x8274f764
	goto loc_8274F764;
loc_8274F744:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f764
	if (cr6.eq) goto loc_8274F764;
loc_8274F74C:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F75C;
	sub_8274F9A8(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne 0x8274f74c
	if (!cr0.eq) goto loc_8274F74C;
loc_8274F764:
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
loc_8274F768:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f7b0
	if (cr6.eq) goto loc_8274F7B0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274f784
	if (cr6.eq) goto loc_8274F784;
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// bne cr6,0x8274f7b0
	if (!cr6.eq) goto loc_8274F7B0;
loc_8274F784:
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8274f7c4
	if (!cr6.eq) goto loc_8274F7C4;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f7b0
	if (cr6.eq) goto loc_8274F7B0;
loc_8274F798:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F7A8;
	sub_8274F9A8(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne 0x8274f798
	if (!cr0.eq) goto loc_8274F798;
loc_8274F7B0:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// blt cr6,0x8274f768
	if (cr6.lt) goto loc_8274F768;
	// b 0x8274f7ec
	goto loc_8274F7EC;
loc_8274F7C4:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274f7ec
	if (cr6.eq) goto loc_8274F7EC;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r10,r30,2
	ctx.r10.s64 = r30.s64 + 2;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// lwzx r3,r10,r28
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// bl 0x8274f9a8
	ctx.lr = 0x8274F7EC;
	sub_8274F9A8(ctx, base);
loc_8274F7EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274F7F8"))) PPC_WEAK_FUNC(sub_8274F7F8);
PPC_FUNC_IMPL(__imp__sub_8274F7F8) {
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
	ctx.lr = 0x8274F800;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274f898
	if (cr6.eq) goto loc_8274F898;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8274f6c8
	ctx.lr = 0x8274F820;
	sub_8274F6C8(ctx, base);
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f84c
	if (cr6.eq) goto loc_8274F84C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f848
	if (cr6.eq) goto loc_8274F848;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274F848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274F848:
	// stw r28,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r28.u32);
loc_8274F84C:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274f860
	if (cr6.eq) goto loc_8274F860;
	// bl 0x8274fac8
	ctx.lr = 0x8274F85C;
	sub_8274FAC8(ctx, base);
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
loc_8274F860:
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
	// li r29,2
	r29.s64 = 2;
loc_8274F868:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274f87c
	if (cr6.eq) goto loc_8274F87C;
	// bl 0x8274fac8
	ctx.lr = 0x8274F878;
	sub_8274FAC8(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_8274F87C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8274f868
	if (!cr0.eq) goto loc_8274F868;
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// bl 0x821310f8
	ctx.lr = 0x8274F898;
	sub_821310F8(ctx, base);
loc_8274F898:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274F8A0"))) PPC_WEAK_FUNC(sub_8274F8A0);
PPC_FUNC_IMPL(__imp__sub_8274F8A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8274F8A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,16(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// bl 0x82130b50
	ctx.lr = 0x8274F8D0;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274f8e4
	if (!cr0.eq) goto loc_8274F8E4;
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x8274f968
	goto loc_8274F968;
loc_8274F8E4:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8274fbb0
	ctx.lr = 0x8274F8F4;
	sub_8274FBB0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8274f968
	if (cr0.lt) goto loc_8274F968;
	// li r27,0
	r27.s64 = 0;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
loc_8274F904:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274f920
	if (cr6.eq) goto loc_8274F920;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8274fbb0
	ctx.lr = 0x8274F918;
	sub_8274FBB0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8274f968
	if (cr0.lt) goto loc_8274F968;
loc_8274F920:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplwi cr6,r27,2
	cr6.compare<uint32_t>(r27.u32, 2, xer);
	// blt cr6,0x8274f904
	if (cr6.lt) goto loc_8274F904;
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274f95c
	if (cr6.eq) goto loc_8274F95C;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274F954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8274f960
	goto loc_8274F960;
loc_8274F95C:
	// li r30,1
	r30.s64 = 1;
loc_8274F960:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x8274f974
	if (!cr6.lt) goto loc_8274F974;
loc_8274F968:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274f7f8
	ctx.lr = 0x8274F970;
	sub_8274F7F8(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274F974:
	// stw r31,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8274F984"))) PPC_WEAK_FUNC(sub_8274F984);
PPC_FUNC_IMPL(__imp__sub_8274F984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274F988"))) PPC_WEAK_FUNC(sub_8274F988);
PPC_FUNC_IMPL(__imp__sub_8274F988) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8274f99c
	goto loc_8274F99C;
loc_8274F994:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8274F99C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274f994
	if (!cr6.eq) goto loc_8274F994;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274F9A8"))) PPC_WEAK_FUNC(sub_8274F9A8);
PPC_FUNC_IMPL(__imp__sub_8274F9A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,259
	cr6.compare<int32_t>(ctx.r9.s32, 259, xer);
	// bne cr6,0x8274f9c4
	if (!cr6.eq) goto loc_8274F9C4;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_8274F9C4:
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// addi r11,r8,8
	r11.s64 = ctx.r8.s64 + 8;
	// lwz r9,8(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274fa00
	if (!cr6.eq) goto loc_8274FA00;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274fa00
	if (cr6.eq) goto loc_8274FA00;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// bne cr6,0x8274f9f4
	if (!cr6.eq) goto loc_8274F9F4;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8274F9F4:
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
loc_8274FA00:
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274fa18
	if (cr6.eq) goto loc_8274FA18;
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// b 0x8274fa1c
	goto loc_8274FA1C;
loc_8274FA18:
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
loc_8274FA1C:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r4,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274FA28"))) PPC_WEAK_FUNC(sub_8274FA28);
PPC_FUNC_IMPL(__imp__sub_8274FA28) {
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
	ctx.lr = 0x8274FA30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274faa4
	if (cr6.eq) goto loc_8274FAA4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8274fa5c
	if (!cr6.eq) goto loc_8274FA5C;
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
loc_8274FA5C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// bl 0x8244d150
	ctx.lr = 0x8274FA78;
	sub_8244D150(ctx, base);
	// li r10,259
	ctx.r10.s64 = 259;
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
	// addi r11,r30,8
	r11.s64 = r30.s64 + 8;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274fab0
	if (cr6.eq) goto loc_8274FAB0;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x8274fab4
	goto loc_8274FAB4;
loc_8274FAA4:
	// lis r28,-32761
	r28.s64 = -2147024896;
	// ori r28,r28,122
	r28.u64 = r28.u64 | 122;
	// b 0x8274fab8
	goto loc_8274FAB8;
loc_8274FAB0:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8274FAB4:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
loc_8274FAB8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274FAC4"))) PPC_WEAK_FUNC(sub_8274FAC4);
PPC_FUNC_IMPL(__imp__sub_8274FAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274FAC8"))) PPC_WEAK_FUNC(sub_8274FAC8);
PPC_FUNC_IMPL(__imp__sub_8274FAC8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274fb14
	if (cr6.eq) goto loc_8274FB14;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274fb04
	if (cr6.eq) goto loc_8274FB04;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x8274FAFC;
	sub_821310F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_8274FB04:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32773
	ctx.r4.u64 = ctx.r4.u64 | 32773;
	// bl 0x821310f8
	ctx.lr = 0x8274FB14;
	sub_821310F8(ctx, base);
loc_8274FB14:
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

__attribute__((alias("__imp__sub_8274FB28"))) PPC_WEAK_FUNC(sub_8274FB28);
PPC_FUNC_IMPL(__imp__sub_8274FB28) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274fb94
	if (cr6.eq) goto loc_8274FB94;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274fb68
	if (cr6.eq) goto loc_8274FB68;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x8274FB64;
	sub_821310F8(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_8274FB68:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274fb84
	if (cr6.eq) goto loc_8274FB84;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x821310f8
	ctx.lr = 0x8274FB80;
	sub_821310F8(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_8274FB84:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32774
	ctx.r4.u64 = ctx.r4.u64 | 32774;
	// bl 0x821310f8
	ctx.lr = 0x8274FB94;
	sub_821310F8(ctx, base);
loc_8274FB94:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274FBAC"))) PPC_WEAK_FUNC(sub_8274FBAC);
PPC_FUNC_IMPL(__imp__sub_8274FBAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274FBB0"))) PPC_WEAK_FUNC(sub_8274FBB0);
PPC_FUNC_IMPL(__imp__sub_8274FBB0) {
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
	ctx.lr = 0x8274FBB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// ori r4,r4,32773
	ctx.r4.u64 = ctx.r4.u64 | 32773;
	// li r28,0
	r28.s64 = 0;
	// bl 0x82130b50
	ctx.lr = 0x8274FBD8;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274fc04
	if (!cr0.eq) goto loc_8274FC04;
loc_8274FBE0:
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r28,r28,14
	r28.u64 = r28.u64 | 14;
	// bl 0x8274fac8
	ctx.lr = 0x8274FBF0;
	sub_8274FAC8(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274FBF4:
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8274FC04:
	// rlwinm r29,r30,3,0,28
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x82130b50
	ctx.lr = 0x8274FC18;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// beq 0x8274fbe0
	if (cr0.eq) goto loc_8274FBE0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274fbf4
	if (cr6.eq) goto loc_8274FBF4;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8274FC30:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274fc5c
	if (cr6.eq) goto loc_8274FC5C;
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// b 0x8274fc60
	goto loc_8274FC60;
loc_8274FC5C:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8274FC60:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274fc30
	if (!cr6.eq) goto loc_8274FC30;
	// b 0x8274fbf4
	goto loc_8274FBF4;
}

__attribute__((alias("__imp__sub_8274FC70"))) PPC_WEAK_FUNC(sub_8274FC70);
PPC_FUNC_IMPL(__imp__sub_8274FC70) {
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
	ctx.lr = 0x8274FC78;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,12
	ctx.r3.s64 = 12;
	// ori r4,r4,32774
	ctx.r4.u64 = ctx.r4.u64 | 32774;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// li r25,0
	r25.s64 = 0;
	// bl 0x82130b50
	ctx.lr = 0x8274FCA4;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8274fd34
	if (cr0.eq) goto loc_8274FD34;
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// mullw r26,r29,r30
	r26.s64 = int64_t(r29.s32) * int64_t(r30.s32);
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x82130b50
	ctx.lr = 0x8274FCC4;
	sub_82130B50(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mullw r3,r28,r30
	ctx.r3.s64 = int64_t(r28.s32) * int64_t(r30.s32);
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x82130b50
	ctx.lr = 0x8274FCD8;
	sub_82130B50(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274fd34
	if (cr6.eq) goto loc_8274FD34;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274fd34
	if (cr6.eq) goto loc_8274FD34;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274fd48
	if (cr6.eq) goto loc_8274FD48;
	// subf r8,r27,r29
	ctx.r8.s64 = r29.s64 - r27.s64;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8274FD00:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r8.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + r27.u64;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// bne 0x8274fd00
	if (!cr0.eq) goto loc_8274FD00;
	// b 0x8274fd48
	goto loc_8274FD48;
loc_8274FD34:
	// lis r25,-32761
	r25.s64 = -2147024896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r25,r25,14
	r25.u64 = r25.u64 | 14;
	// bl 0x8274fb28
	ctx.lr = 0x8274FD44;
	sub_8274FB28(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274FD48:
	// stw r31,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r31.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8274FD58"))) PPC_WEAK_FUNC(sub_8274FD58);
PPC_FUNC_IMPL(__imp__sub_8274FD58) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82458098
	ctx.lr = 0x8274FD74;
	sub_82458098(ctx, base);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r10,328(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 328);
	// mulli r9,r11,1000
	ctx.r9.s64 = r11.s64 * 1000;
	// rotldi r11,r9,1
	r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 1);
	// divd r3,r9,r10
	ctx.r3.s64 = ctx.r9.s64 / ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// tdllei r10,0
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// tdlgei r11,-1
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

__attribute__((alias("__imp__sub_8274FDAC"))) PPC_WEAK_FUNC(sub_8274FDAC);
PPC_FUNC_IMPL(__imp__sub_8274FDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274FDB0"))) PPC_WEAK_FUNC(sub_8274FDB0);
PPC_FUNC_IMPL(__imp__sub_8274FDB0) {
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
	// li r30,0
	r30.s64 = 0;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8274fe00
	if (cr6.eq) goto loc_8274FE00;
	// bl 0x8274fd58
	ctx.lr = 0x8274FDDC;
	sub_8274FD58(ctx, base);
	// ld r11,24(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// ld r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - r11.s64;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// blt cr6,0x8274fe00
	if (cr6.lt) goto loc_8274FE00;
	// li r30,1
	r30.s64 = 1;
	// std r11,56(r31)
	PPC_STORE_U64(r31.u32 + 56, r11.u64);
loc_8274FE00:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274FE1C"))) PPC_WEAK_FUNC(sub_8274FE1C);
PPC_FUNC_IMPL(__imp__sub_8274FE1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274FE20"))) PPC_WEAK_FUNC(sub_8274FE20);
PPC_FUNC_IMPL(__imp__sub_8274FE20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r6,0
	ctx.r6.s64 = 0;
	// ld r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r8.u32 + 16);
	// lhz r11,32(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 32);
	// divdu r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 / ctx.r9.u64;
	// lhz r9,66(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 66);
	// std r6,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, ctx.r6.u64);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// srawi r10,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	ctx.r10.s64 = r11.s32 >> 12;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r10,r11,4096
	ctx.r10.s64 = r11.s64 + 4096;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srawi r10,r7,12
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFF) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 12;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r3,r9,12
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFF) != 0);
	ctx.r3.s64 = ctx.r9.s32 >> 12;
	// rlwinm r10,r10,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// addze r3,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r3.s64 = temp.s64;
	// subf r10,r10,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r10.s64;
	// rlwinm r7,r3,12,0,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 12) & 0xFFFFF000;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// bge cr6,0x8274fecc
	if (!cr6.lt) goto loc_8274FECC;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// blt cr6,0x8274feb8
	if (cr6.lt) goto loc_8274FEB8;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x8274ff08
	if (!cr6.gt) goto loc_8274FF08;
loc_8274FEB8:
	// lwz r11,356(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 356);
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,356(r8)
	PPC_STORE_U32(ctx.r8.u32 + 356, r11.u32);
	// blr 
	return;
loc_8274FECC:
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bge cr6,0x8274fedc
	if (!cr6.lt) goto loc_8274FEDC;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8274feb8
	if (cr6.gt) goto loc_8274FEB8;
loc_8274FEDC:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x8274ff00
	if (!cr6.lt) goto loc_8274FF00;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8274fef4
	if (cr6.gt) goto loc_8274FEF4;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x8274ff10
	if (!cr6.gt) goto loc_8274FF10;
loc_8274FEF4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8274FEF8:
	// stw r6,356(r8)
	PPC_STORE_U32(ctx.r8.u32 + 356, ctx.r6.u32);
	// blr 
	return;
loc_8274FF00:
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8274ff10
	if (cr6.gt) goto loc_8274FF10;
loc_8274FF08:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8274fef4
	if (cr6.lt) goto loc_8274FEF4;
loc_8274FF10:
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// ld r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r8.u32 + 16);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r11,r11,4096
	r11.s64 = r11.s64 + 4096;
	// srawi r9,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	ctx.r9.s64 = r11.s32 >> 12;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r9,r9,12,0,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFFFF000;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// mulli r11,r11,20
	r11.s64 = r11.s64 * 20;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// std r11,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, r11.u64);
	// b 0x8274fef8
	goto loc_8274FEF8;
}

__attribute__((alias("__imp__sub_8274FF48"))) PPC_WEAK_FUNC(sub_8274FF48);
PPC_FUNC_IMPL(__imp__sub_8274FF48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r10,r3,372
	ctx.r10.s64 = ctx.r3.s64 + 372;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274ffa8
	if (cr6.eq) goto loc_8274FFA8;
	// ld r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
loc_8274FF68:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ld r6,24(r8)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
	// cmpld cr6,r7,r6
	cr6.compare<uint64_t>(ctx.r7.u64, ctx.r6.u64, xer);
	// blt cr6,0x8274ff88
	if (cr6.lt) goto loc_8274FF88;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274ff68
	if (!cr6.eq) goto loc_8274FF68;
loc_8274FF88:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274ffcc
	if (!cr6.eq) goto loc_8274FFCC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274ffa8
	if (cr6.eq) goto loc_8274FFA8;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// ld r11,24(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 24);
	// cmpld cr6,r11,r7
	cr6.compare<uint64_t>(r11.u64, ctx.r7.u64, xer);
	// beq cr6,0x8275000c
	if (cr6.eq) goto loc_8275000C;
loc_8274FFA8:
	// stw r3,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r3.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274ffc0
	if (cr6.eq) goto loc_8274FFC0;
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// b 0x8274ffc4
	goto loc_8274FFC4;
loc_8274FFC0:
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
loc_8274FFC4:
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// blr 
	return;
loc_8274FFCC:
	// ld r11,24(r8)
	r11.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
	// cmpld cr6,r11,r7
	cr6.compare<uint64_t>(r11.u64, ctx.r7.u64, xer);
	// beq cr6,0x8275000c
	if (cr6.eq) goto loc_8275000C;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8274fffc
	if (!cr6.eq) goto loc_8274FFFC;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// bnelr cr6
	if (!cr6.eq) return;
	// b 0x8274ffc4
	goto loc_8274FFC4;
loc_8274FFFC:
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r4,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r4.u32);
	// blr 
	return;
loc_8275000C:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82750018"))) PPC_WEAK_FUNC(sub_82750018);
PPC_FUNC_IMPL(__imp__sub_82750018) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 64);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// ld r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// std r9,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r9.u64);
	// addi r10,r3,372
	ctx.r10.s64 = ctx.r3.s64 + 372;
	// addi r7,r7,4096
	ctx.r7.s64 = ctx.r7.s64 + 4096;
	// stw r9,312(r3)
	PPC_STORE_U32(ctx.r3.u32 + 312, ctx.r9.u32);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stw r9,304(r3)
	PPC_STORE_U32(ctx.r3.u32 + 304, ctx.r9.u32);
	// srawi r8,r7,12
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 12;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,12,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFFFF000;
	// subf r11,r11,r7
	r11.s64 = ctx.r7.s64 - r11.s64;
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// lwz r11,372(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x8275007c
	if (!cr6.eq) goto loc_8275007C;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_8275007C:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r7,r3,364
	ctx.r7.s64 = ctx.r3.s64 + 364;
loc_82750094:
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r8,4(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827500ac
	if (cr6.eq) goto loc_827500AC;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// b 0x827500b0
	goto loc_827500B0;
loc_827500AC:
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_827500B0:
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x827500d0
	if (!cr6.eq) goto loc_827500D0;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_827500D0:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// bne cr6,0x82750094
	if (!cr6.eq) goto loc_82750094;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827500E8"))) PPC_WEAK_FUNC(sub_827500E8);
PPC_FUNC_IMPL(__imp__sub_827500E8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x827500F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// lwz r9,312(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// lhz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 68);
	// lhz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfd f13,21560(r10)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + 21560);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// subf r10,r8,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r8.s64;
	// fdiv f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 / f0.f64;
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bge cr6,0x82750140
	if (!cr6.lt) goto loc_82750140;
	// fdiv f12,f12,f0
	ctx.f12.f64 = ctx.f12.f64 / f0.f64;
	// b 0x82750144
	goto loc_82750144;
loc_82750140:
	// fmr f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64;
loc_82750144:
	// lfd f11,288(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 288);
	// fmul f0,f11,f0
	f0.f64 = ctx.f11.f64 * f0.f64;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82750158
	if (cr6.lt) goto loc_82750158;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82750158:
	// fsub f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f13.f64 - f0.f64;
	// addi r11,r10,10
	r11.s64 = ctx.r10.s64 + 10;
	// fmul f12,f0,f12
	ctx.f12.f64 = f0.f64 * ctx.f12.f64;
	// stfd f0,296(r31)
	PPC_STORE_U64(r31.u32 + 296, f0.u64);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r26,0
	r26.s64 = 0;
	// lfdx f0,r11,r31
	f0.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// fmadd f0,f13,f0,f12
	f0.f64 = ctx.f13.f64 * f0.f64 + ctx.f12.f64;
	// stfdx f0,r11,r31
	PPC_STORE_U64(r11.u32 + r31.u32, f0.u64);
	// lfd f0,280(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 280);
	// stw r26,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r26.u32);
	// stw r26,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r26.u32);
	// lfdx f13,r11,r31
	ctx.f13.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x827502b8
	if (!cr6.lt) goto loc_827502B8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82750314
	if (cr6.eq) goto loc_82750314;
	// addi r11,r10,9
	r11.s64 = ctx.r10.s64 + 9;
	// fsub f13,f13,f0
	ctx.f13.f64 = ctx.f13.f64 - f0.f64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lfdx f12,r11,r31
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// fsub f0,f12,f0
	f0.f64 = ctx.f12.f64 - f0.f64;
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fabs f0,f0
	f0.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82750314
	if (!cr6.lt) goto loc_82750314;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r28,372(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// addi r30,r31,372
	r30.s64 = r31.s64 + 372;
	// addi r11,r11,-20
	r11.s64 = r11.s64 + -20;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// divdu r10,r11,r10
	ctx.r10.u64 = r11.u64 / ctx.r10.u64;
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
	// sth r10,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r10.u16);
	// beq cr6,0x82750314
	if (cr6.eq) goto loc_82750314;
	// lwz r27,0(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// ld r29,24(r27)
	r29.u64 = PPC_LOAD_U64(r27.u32 + 24);
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// bl 0x8274f988
	ctx.lr = 0x82750204;
	sub_8274F988(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82750314
	if (cr0.eq) goto loc_82750314;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// cmpld cr6,r11,r29
	cr6.compare<uint64_t>(r11.u64, r29.u64, xer);
	// ble cr6,0x82750314
	if (!cr6.gt) goto loc_82750314;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r29,20
	ctx.r10.s64 = r29.s64 + 20;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827502a8
	if (cr6.eq) goto loc_827502A8;
loc_8275022C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ld r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// cmpld cr6,r9,r10
	cr6.compare<uint64_t>(ctx.r9.u64, ctx.r10.u64, xer);
	// bgt cr6,0x82750250
	if (cr6.gt) goto loc_82750250;
	// bne cr6,0x82750244
	if (!cr6.eq) goto loc_82750244;
	// li r8,1
	ctx.r8.s64 = 1;
loc_82750244:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275022c
	if (!cr6.eq) goto loc_8275022C;
loc_82750250:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x827502a8
	if (cr6.eq) goto loc_827502A8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82750280
	if (cr6.eq) goto loc_82750280;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82750274
	if (!cr6.eq) goto loc_82750274;
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
loc_82750274:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
loc_82750280:
	// stw r26,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r26.u32);
	// addi r11,r31,364
	r11.s64 = r31.s64 + 364;
	// lwz r10,368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275029c
	if (cr6.eq) goto loc_8275029C;
	// stw r28,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r28.u32);
	// b 0x827502a0
	goto loc_827502A0;
loc_8275029C:
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
loc_827502A0:
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// b 0x82750314
	goto loc_82750314;
loc_827502A8:
	// ld r11,24(r27)
	r11.u64 = PPC_LOAD_U64(r27.u32 + 24);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// std r11,24(r27)
	PPC_STORE_U64(r27.u32 + 24, r11.u64);
	// b 0x82750314
	goto loc_82750314;
loc_827502B8:
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,25
	cr6.compare<uint32_t>(r11.u32, 25, xer);
	// bge cr6,0x82750314
	if (!cr6.lt) goto loc_82750314;
	// addi r11,r10,11
	r11.s64 = ctx.r10.s64 + 11;
	// fsub f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f13.f64 - f0.f64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lfdx f12,r11,r31
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// fsub f0,f12,f0
	f0.f64 = ctx.f12.f64 - f0.f64;
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fabs f0,f0
	f0.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82750314
	if (!cr6.lt) goto loc_82750314;
	// ld r11,16(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x82750314
	if (cr6.eq) goto loc_82750314;
	// addi r10,r11,-20
	ctx.r10.s64 = r11.s64 + -20;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// li r9,20
	ctx.r9.s64 = 20;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// std r10,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r10.u64);
	// divdu r10,r11,r9
	ctx.r10.u64 = r11.u64 / ctx.r9.u64;
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
	// sth r10,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r10.u16);
loc_82750314:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8275031C"))) PPC_WEAK_FUNC(sub_8275031C);
PPC_FUNC_IMPL(__imp__sub_8275031C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82750320"))) PPC_WEAK_FUNC(sub_82750320);
PPC_FUNC_IMPL(__imp__sub_82750320) {
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
	ctx.lr = 0x82750328;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lwz r3,392(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// bl 0x8274f578
	ctx.lr = 0x82750360;
	sub_8274F578(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82750384
	if (!cr0.lt) goto loc_82750384;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x827503ac
	goto loc_827503AC;
loc_82750384:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r29,380
	r11.s64 = r29.s64 + 380;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// lwz r10,384(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 384);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827503a4
	if (cr6.eq) goto loc_827503A4;
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
	// b 0x827503a8
	goto loc_827503A8;
loc_827503A4:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_827503A8:
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
loc_827503AC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827503B4"))) PPC_WEAK_FUNC(sub_827503B4);
PPC_FUNC_IMPL(__imp__sub_827503B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827503B8"))) PPC_WEAK_FUNC(sub_827503B8);
PPC_FUNC_IMPL(__imp__sub_827503B8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82750414
	if (cr6.eq) goto loc_82750414;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827503f8
	if (cr6.eq) goto loc_827503F8;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x827503F4;
	sub_821310F8(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_827503F8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8274fb28
	ctx.lr = 0x82750400;
	sub_8274FB28(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32787
	ctx.r4.u64 = ctx.r4.u64 | 32787;
	// bl 0x821310f8
	ctx.lr = 0x82750414;
	sub_821310F8(ctx, base);
loc_82750414:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275042C"))) PPC_WEAK_FUNC(sub_8275042C);
PPC_FUNC_IMPL(__imp__sub_8275042C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82750430"))) PPC_WEAK_FUNC(sub_82750430);
PPC_FUNC_IMPL(__imp__sub_82750430) {
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
	ctx.lr = 0x82750438;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32768
	r28.s64 = -2147483648;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r28,r28,16389
	r28.u64 = r28.u64 | 16389;
	// bl 0x8274fdb0
	ctx.lr = 0x8275044C;
	sub_8274FDB0(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x827505a4
	if (cr0.eq) goto loc_827505A4;
	// lwz r29,372(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 372);
	// addi r31,r30,372
	r31.s64 = r30.s64 + 372;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827505a0
	if (cr6.eq) goto loc_827505A0;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// ld r11,16(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 16);
	// ld r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 24);
	// cmpld cr6,r9,r11
	cr6.compare<uint64_t>(ctx.r9.u64, r11.u64, xer);
	// beq cr6,0x8275051c
	if (cr6.eq) goto loc_8275051C;
	// lwz r11,316(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 316);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,316(r30)
	PPC_STORE_U32(r30.u32 + 316, r11.u32);
	// lwz r11,352(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 352);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82750598
	if (cr6.eq) goto loc_82750598;
	// lwz r31,364(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 364);
	// addi r29,r30,364
	r29.s64 = r30.s64 + 364;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827505d8
	if (cr6.eq) goto loc_827505D8;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x827504b4
	if (!cr6.eq) goto loc_827504B4;
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_827504B4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r30,340
	ctx.r4.s64 = r30.s64 + 340;
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x823da950
	ctx.lr = 0x827504D4;
	sub_823DA950(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,10
	r11.s64 = 10;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82750320
	ctx.lr = 0x827504EC;
	sub_82750320(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x82750590
	if (!cr0.lt) goto loc_82750590;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// bne cr6,0x827505b8
	if (!cr6.eq) goto loc_827505B8;
	// stw r31,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r31.u32);
	// b 0x827505b8
	goto loc_827505B8;
loc_8275051C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82750544
	if (cr6.eq) goto loc_82750544;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82750538
	if (!cr6.eq) goto loc_82750538;
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
loc_82750538:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
loc_82750544:
	// addi r3,r30,340
	ctx.r3.s64 = r30.s64 + 340;
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x823da950
	ctx.lr = 0x82750554;
	sub_823DA950(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r11,352(r30)
	PPC_STORE_U32(r30.u32 + 352, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82750320
	ctx.lr = 0x82750568;
	sub_82750320(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x827505ac
	if (!cr0.lt) goto loc_827505AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827505b8
	if (!cr6.eq) goto loc_827505B8;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// b 0x827505b8
	goto loc_827505B8;
loc_82750590:
	// stw r27,352(r30)
	PPC_STORE_U32(r30.u32 + 352, r27.u32);
	// b 0x827505b8
	goto loc_827505B8;
loc_82750598:
	// mr r28,r27
	r28.u64 = r27.u64;
	// b 0x827505b8
	goto loc_827505B8;
loc_827505A0:
	// stw r27,72(r30)
	PPC_STORE_U32(r30.u32 + 72, r27.u32);
loc_827505A4:
	// std r27,56(r30)
	PPC_STORE_U64(r30.u32 + 56, r27.u64);
	// b 0x827505b8
	goto loc_827505B8;
loc_827505AC:
	// ld r11,56(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 56);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// std r11,56(r30)
	PPC_STORE_U64(r30.u32 + 56, r11.u64);
loc_827505B8:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x827505d8
	if (cr6.lt) goto loc_827505D8;
	// ld r11,16(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 16);
	// lwz r10,320(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 320);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// std r11,16(r30)
	PPC_STORE_U64(r30.u32 + 16, r11.u64);
	// stw r10,320(r30)
	PPC_STORE_U32(r30.u32 + 320, ctx.r10.u32);
loc_827505D8:
	// ld r11,56(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 56);
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// ble cr6,0x827505ec
	if (!cr6.gt) goto loc_827505EC;
	// addi r11,r11,-20
	r11.s64 = r11.s64 + -20;
	// std r11,56(r30)
	PPC_STORE_U64(r30.u32 + 56, r11.u64);
loc_827505EC:
	// lwz r31,380(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 380);
	// addi r29,r30,380
	r29.s64 = r30.s64 + 380;
	// b 0x82750694
	goto loc_82750694;
loc_827505F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8275069c
	if (cr6.eq) goto loc_8275069C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82750630
	if (cr6.eq) goto loc_82750630;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82750624
	if (!cr6.eq) goto loc_82750624;
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_82750624:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
loc_82750630:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8244d150
	ctx.lr = 0x8275066C;
	sub_8244D150(ctx, base);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// addi r11,r30,364
	r11.s64 = r30.s64 + 364;
	// lwz r10,368(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 368);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82750688
	if (cr6.eq) goto loc_82750688;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x8275068c
	goto loc_8275068C;
loc_82750688:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8275068C:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_82750694:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827505f8
	if (!cr6.eq) goto loc_827505F8;
loc_8275069C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827506A8"))) PPC_WEAK_FUNC(sub_827506A8);
PPC_FUNC_IMPL(__imp__sub_827506A8) {
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
	ctx.lr = 0x827506B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r28,r25
	r28.u64 = r25.u64;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lhz r11,0(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r27,r11,31,21,31
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FF;
	// rlwinm r30,r11,20,12,31
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xFFFFF;
	// bne cr6,0x8275073c
	if (!cr6.eq) goto loc_8275073C;
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8275071c
	if (cr6.eq) goto loc_8275071C;
	// bl 0x8244fee8
	ctx.lr = 0x827506F0;
	sub_8244FEE8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// clrldi r10,r3,32
	ctx.r10.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// addi r11,r11,-21312
	r11.s64 = r11.s64 + -21312;
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpldi cr6,r9,0
	cr6.compare<uint64_t>(ctx.r9.u64, 0, xer);
	// bne cr6,0x82750714
	if (!cr6.eq) goto loc_82750714;
	// li r9,20
	ctx.r9.s64 = 20;
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// std r9,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r9.u64);
loc_82750714:
	// std r10,24(r31)
	PPC_STORE_U64(r31.u32 + 24, ctx.r10.u64);
	// b 0x82750728
	goto loc_82750728;
loc_8275071C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274fd58
	ctx.lr = 0x82750724;
	sub_8274FD58(ctx, base);
	// std r3,24(r31)
	PPC_STORE_U64(r31.u32 + 24, ctx.r3.u64);
loc_82750728:
	// li r11,1
	r11.s64 = 1;
	// stb r30,308(r31)
	PPC_STORE_U8(r31.u32 + 308, r30.u8);
	// sth r27,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r27.u16);
	// std r25,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r25.u64);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
loc_8275073C:
	// lbz r11,308(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 308);
	// clrlwi r29,r30,24
	r29.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// beq cr6,0x82750758
	if (cr6.eq) goto loc_82750758;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827500e8
	ctx.lr = 0x82750754;
	sub_827500E8(ctx, base);
	// stb r30,308(r31)
	PPC_STORE_U8(r31.u32 + 308, r30.u8);
loc_82750758:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274fe20
	ctx.lr = 0x82750768;
	sub_8274FE20(ctx, base);
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r11.u32);
	// blt cr6,0x827507a8
	if (cr6.lt) goto loc_827507A8;
	// beq cr6,0x82750828
	if (cr6.eq) goto loc_82750828;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bge cr6,0x82750860
	if (!cr6.lt) goto loc_82750860;
	// lwz r11,360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// lwz r10,356(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8275085c
	if (!cr6.lt) goto loc_8275085C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82750018
	ctx.lr = 0x827507A0;
	sub_82750018(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8274fe20
	ctx.lr = 0x827507A8;
	sub_8274FE20(ctx, base);
loc_827507A8:
	// lwz r30,364(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// addi r29,r31,364
	r29.s64 = r31.s64 + 364;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8275085c
	if (cr6.eq) goto loc_8275085C;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x827507c8
	if (!cr6.eq) goto loc_827507C8;
	// stw r25,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r25.u32);
loc_827507C8:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r25,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r25.u32);
	// std r10,24(r11)
	PPC_STORE_U64(r11.u32 + 24, ctx.r10.u64);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x823da950
	ctx.lr = 0x827507F4;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r24,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r24.u32);
	// bl 0x8274ff48
	ctx.lr = 0x82750808;
	sub_8274FF48(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x82750860
	if (!cr0.lt) goto loc_82750860;
	// stw r25,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r25.u32);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82750848
	if (cr6.eq) goto loc_82750848;
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// b 0x8275084c
	goto loc_8275084C;
loc_82750828:
	// lbz r11,308(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 308);
	// li r28,1
	r28.s64 = 1;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x82750860
	if (!cr6.eq) goto loc_82750860;
	// lwz r11,312(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r11.u32);
	// b 0x82750860
	goto loc_82750860;
loc_82750848:
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_8275084C:
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r11.u32);
loc_8275085C:
	// li r28,1
	r28.s64 = 1;
loc_82750860:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8275086C"))) PPC_WEAK_FUNC(sub_8275086C);
PPC_FUNC_IMPL(__imp__sub_8275086C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82750870"))) PPC_WEAK_FUNC(sub_82750870);
PPC_FUNC_IMPL(__imp__sub_82750870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// ld r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 40);
	// li r8,20
	ctx.r8.s64 = 20;
	// li r11,0
	r11.s64 = 0;
	// lwz r10,372(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// divdu r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 / ctx.r8.u64;
	// addi r8,r3,372
	ctx.r8.s64 = ctx.r3.s64 + 372;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// sth r9,64(r3)
	PPC_STORE_U16(ctx.r3.u32 + 64, ctx.r9.u16);
	// std r11,296(r3)
	PPC_STORE_U64(ctx.r3.u32 + 296, r11.u64);
	// stw r11,304(r3)
	PPC_STORE_U32(ctx.r3.u32 + 304, r11.u32);
	// stb r11,308(r3)
	PPC_STORE_U8(ctx.r3.u32 + 308, r11.u8);
	// stw r11,312(r3)
	PPC_STORE_U32(ctx.r3.u32 + 312, r11.u32);
	// beq cr6,0x82750908
	if (cr6.eq) goto loc_82750908;
	// addi r7,r3,364
	ctx.r7.s64 = ctx.r3.s64 + 364;
loc_827508B4:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827508dc
	if (cr6.eq) goto loc_827508DC;
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplw cr6,r9,r6
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, xer);
	// bne cr6,0x827508d0
	if (!cr6.eq) goto loc_827508D0;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
loc_827508D0:
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
loc_827508DC:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827508f4
	if (cr6.eq) goto loc_827508F4;
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// b 0x827508f8
	goto loc_827508F8;
loc_827508F4:
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
loc_827508F8:
	// stw r10,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r10.u32);
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827508b4
	if (!cr6.eq) goto loc_827508B4;
loc_82750908:
	// addi r10,r3,80
	ctx.r10.s64 = ctx.r3.s64 + 80;
	// li r11,25
	r11.s64 = 25;
loc_82750910:
	// ld r9,280(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 280);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bne 0x82750910
	if (!cr0.eq) goto loc_82750910;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82750928"))) PPC_WEAK_FUNC(sub_82750928);
PPC_FUNC_IMPL(__imp__sub_82750928) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82750930;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,400
	ctx.r3.s64 = 400;
	// ori r4,r4,32787
	ctx.r4.u64 = ctx.r4.u64 | 32787;
	// bl 0x82130b50
	ctx.lr = 0x8275094C;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x82750960
	if (!cr0.eq) goto loc_82750960;
loc_82750954:
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x82750ac4
	goto loc_82750AC4;
loc_82750960:
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// stw r30,392(r31)
	PPC_STORE_U32(r31.u32 + 392, r30.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// li r10,28
	ctx.r10.s64 = 28;
	// li r11,240
	r11.s64 = 240;
	// li r7,12
	ctx.r7.s64 = 12;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lfd f0,-1824(r9)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + -1824);
	// li r6,4
	ctx.r6.s64 = 4;
	// lfd f13,-1832(r8)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r8.u32 + -1832);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,1
	ctx.r8.s64 = 1;
	// stfd f0,288(r31)
	PPC_STORE_U64(r31.u32 + 288, f0.u64);
	// stfd f13,280(r31)
	PPC_STORE_U64(r31.u32 + 280, ctx.f13.u64);
	// std r11,48(r31)
	PPC_STORE_U64(r31.u32 + 48, r11.u64);
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
	// addi r3,r31,328
	ctx.r3.s64 = r31.s64 + 328;
	// sth r7,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r7.u16);
	// sth r6,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r6.u16);
	// sth r10,66(r31)
	PPC_STORE_U16(r31.u32 + 66, ctx.r10.u16);
	// stw r9,360(r31)
	PPC_STORE_U32(r31.u32 + 360, ctx.r9.u32);
	// stw r8,336(r31)
	PPC_STORE_U32(r31.u32 + 336, ctx.r8.u32);
	// bl 0x82458060
	ctx.lr = 0x827509BC;
	sub_82458060(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x827509e4
	if (!cr0.eq) goto loc_827509E4;
	// bl 0x82135db0
	ctx.lr = 0x827509C8;
	sub_82135DB0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt 0x827509d8
	if (cr0.gt) goto loc_827509D8;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82750abc
	goto loc_82750ABC;
loc_827509D8:
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r30,r11,32775
	r30.u64 = r11.u64 | 2147942400;
	// b 0x82750abc
	goto loc_82750ABC;
loc_827509E4:
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
	// li r11,25
	r11.s64 = 25;
loc_827509EC:
	// lfd f0,280(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 280);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfd f0,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, f0.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bne 0x827509ec
	if (!cr0.eq) goto loc_827509EC;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r3,r11,2
	ctx.r3.s64 = r11.s64 + 2;
	// bl 0x8274fc70
	ctx.lr = 0x82750A20;
	sub_8274FC70(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x82750ac4
	if (cr0.lt) goto loc_82750AC4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130b50
	ctx.lr = 0x82750A3C;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// beq 0x82750954
	if (cr0.eq) goto loc_82750954;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82750abc
	if (!cr6.gt) goto loc_82750ABC;
	// addi r7,r31,364
	ctx.r7.s64 = r31.s64 + 364;
	// li r11,0
	r11.s64 = 0;
loc_82750A60:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwx r10,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.r10.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82750aa0
	if (cr6.eq) goto loc_82750AA0;
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// b 0x82750aa4
	goto loc_82750AA4;
loc_82750AA0:
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
loc_82750AA4:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r10,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r10.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// blt cr6,0x82750a60
	if (cr6.lt) goto loc_82750A60;
loc_82750ABC:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x82750ad0
	if (!cr6.lt) goto loc_82750AD0;
loc_82750AC4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827503b8
	ctx.lr = 0x82750ACC;
	sub_827503B8(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_82750AD0:
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82750AE0"))) PPC_WEAK_FUNC(sub_82750AE0);
PPC_FUNC_IMPL(__imp__sub_82750AE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,192(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82750AE8"))) PPC_WEAK_FUNC(sub_82750AE8);
PPC_FUNC_IMPL(__imp__sub_82750AE8) {
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
	ctx.lr = 0x82750AF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82750b40
	if (!cr6.gt) goto loc_82750B40;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
loc_82750B10:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82750B24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r28,r3
	cr6.compare<uint32_t>(r28.u32, ctx.r3.u32, xer);
	// beq cr6,0x82750b4c
	if (cr6.eq) goto loc_82750B4C;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82750b10
	if (cr6.lt) goto loc_82750B10;
loc_82750B40:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82750B44:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82750B4C:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// b 0x82750b44
	goto loc_82750B44;
}

__attribute__((alias("__imp__sub_82750B5C"))) PPC_WEAK_FUNC(sub_82750B5C);
PPC_FUNC_IMPL(__imp__sub_82750B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82750B60"))) PPC_WEAK_FUNC(sub_82750B60);
PPC_FUNC_IMPL(__imp__sub_82750B60) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82750B68;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r28,r26
	r28.u64 = r26.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x827bdc04
	ctx.lr = 0x82750B84;
	__imp__XamVoiceHeadsetPresent(ctx, base);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82750ba0
	if (cr6.eq) goto loc_82750BA0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82750ba8
	if (cr6.eq) goto loc_82750BA8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82750bb0
	if (!cr6.eq) goto loc_82750BB0;
loc_82750BA0:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82750bb0
	if (cr6.eq) goto loc_82750BB0;
loc_82750BA8:
	// li r28,1
	r28.s64 = 1;
	// li r27,1
	r27.s64 = 1;
loc_82750BB0:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// lwz r11,1316(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1316);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82750bd0
	if (!cr6.eq) goto loc_82750BD0;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82750d50
	if (cr6.eq) goto loc_82750D50;
loc_82750BD0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x827bd314
	ctx.lr = 0x82750BD8;
	__imp__XamUserGetSigninState(ctx, base);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82750dd0
	if (cr6.eq) goto loc_82750DD0;
	// addi r30,r31,148
	r30.s64 = r31.s64 + 148;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821326a8
	ctx.lr = 0x82750BFC;
	sub_821326A8(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82750d24
	if (cr6.eq) goto loc_82750D24;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82750d24
	if (!cr6.eq) goto loc_82750D24;
	// stw r26,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r26.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82750d50
	if (!cr6.gt) goto loc_82750D50;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
loc_82750C28:
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addis r10,r10,-4100
	ctx.r10.s64 = ctx.r10.s64 + -268697600;
	// addic. r10,r10,-12
	xer.ca = ctx.r10.u32 > 11;
	ctx.r10.s64 = ctx.r10.s64 + -12;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82750ce8
	if (cr0.eq) goto loc_82750CE8;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82750ca4
	if (cr6.eq) goto loc_82750CA4;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x82750d08
	if (!cr6.eq) goto loc_82750D08;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// ble cr6,0x82750c68
	if (!cr6.gt) goto loc_82750C68;
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
loc_82750C68:
	// lwa r10,32(r11)
	ctx.r10.s64 = int32_t(PPC_LOAD_U32(r11.u32 + 32));
	// lfs f0,184(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	f0.f64 = double(temp.f32);
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x82750d08
	if (cr6.eq) goto loc_82750D08;
	// stb r26,198(r31)
	PPC_STORE_U8(r31.u32 + 198, r26.u8);
	// li r28,1
	r28.s64 = 1;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// b 0x82750d04
	goto loc_82750D04;
loc_82750CA4:
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// beq cr6,0x82750cbc
	if (cr6.eq) goto loc_82750CBC;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// b 0x82750cc0
	goto loc_82750CC0;
loc_82750CBC:
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
loc_82750CC0:
	// stw r10,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r10.u32);
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// beq cr6,0x82750cdc
	if (cr6.eq) goto loc_82750CDC;
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// b 0x82750ce0
	goto loc_82750CE0;
loc_82750CDC:
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
loc_82750CE0:
	// li r27,1
	r27.s64 = 1;
	// b 0x82750d04
	goto loc_82750D04;
loc_82750CE8:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// beq cr6,0x82750d00
	if (cr6.eq) goto loc_82750D00;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// b 0x82750d04
	goto loc_82750D04;
loc_82750D00:
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_82750D04:
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
loc_82750D08:
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,40
	ctx.r9.s64 = ctx.r9.s64 + 40;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// blt cr6,0x82750c28
	if (cr6.lt) goto loc_82750C28;
	// b 0x82750d50
	goto loc_82750D50;
loc_82750D24:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,997
	cr6.compare<uint32_t>(r11.u32, 997, xer);
	// beq cr6,0x82750d50
	if (cr6.eq) goto loc_82750D50;
	// stw r26,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r26.u32);
loc_82750D34:
	// lis r11,2
	r11.s64 = 131072;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// ori r11,r11,25604
	r11.u64 = r11.u64 | 25604;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82750d50
	if (cr6.eq) goto loc_82750D50;
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// li r28,1
	r28.s64 = 1;
loc_82750D50:
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// bne cr6,0x82750d90
	if (!cr6.eq) goto loc_82750D90;
loc_82750D58:
	// li r30,1128
	r30.s64 = 1128;
loc_82750D5C:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82750d80
	if (cr6.eq) goto loc_82750D80;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x82750d80
	if (cr6.eq) goto loc_82750D80;
	// bl 0x82752450
	ctx.lr = 0x82750D80;
	sub_82752450(ctx, base);
loc_82750D80:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplwi cr6,r30,1264
	cr6.compare<uint32_t>(r30.u32, 1264, xer);
	// blt cr6,0x82750d5c
	if (cr6.lt) goto loc_82750D5C;
	// li r28,1
	r28.s64 = 1;
loc_82750D90:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bne cr6,0x82750dc8
	if (!cr6.eq) goto loc_82750DC8;
	// lbz r11,198(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,184(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// bl 0x8274e020
	ctx.lr = 0x82750DC8;
	sub_8274E020(ctx, base);
loc_82750DC8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82750DD0:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82750d34
	if (cr6.eq) goto loc_82750D34;
	// addi r7,r31,148
	ctx.r7.s64 = r31.s64 + 148;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lis r3,-2
	ctx.r3.s64 = -131072;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r8,r11,-4896
	ctx.r8.s64 = r11.s64 + -4896;
	// addi r9,r31,180
	ctx.r9.s64 = r31.s64 + 180;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r3,r3,2001
	ctx.r3.u64 = ctx.r3.u64 | 2001;
	// bl 0x827bd324
	ctx.lr = 0x82750E0C;
	__imp__XamUserReadProfileSettings(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82750e38
	if (cr0.eq) goto loc_82750E38;
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// beq cr6,0x82750e38
	if (cr6.eq) goto loc_82750E38;
	// lis r11,2
	r11.s64 = 131072;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// ori r11,r11,25604
	r11.u64 = r11.u64 | 25604;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82750e40
	if (cr6.eq) goto loc_82750E40;
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// b 0x82750e40
	goto loc_82750E40;
loc_82750E38:
	// li r11,1
	r11.s64 = 1;
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
loc_82750E40:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,252
	ctx.r4.s64 = 252;
	// bl 0x827bd424
	ctx.lr = 0x82750E50;
	__imp__XamUserCheckPrivilege(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x82750e94
	if (!cr0.eq) goto loc_82750E94;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82750e94
	if (cr6.eq) goto loc_82750E94;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,251
	ctx.r4.s64 = 251;
	// bl 0x827bd424
	ctx.lr = 0x82750E74;
	__imp__XamUserCheckPrivilege(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rldimi r11,r3,32,0
	r11.u64 = (__builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFF00000000) | (r11.u64 & 0xFFFFFFFF);
	// cmpldi cr6,r11,1
	cr6.compare<uint64_t>(r11.u64, 1, xer);
	// bne cr6,0x82750e8c
	if (!cr6.eq) goto loc_82750E8C;
	// lis r11,1
	r11.s64 = 65536;
	// b 0x82750e98
	goto loc_82750E98;
loc_82750E8C:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82750e98
	goto loc_82750E98;
loc_82750E94:
	// lis r11,2
	r11.s64 = 131072;
loc_82750E98:
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r10,36(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82750eac
	if (cr6.eq) goto loc_82750EAC;
	// lis r11,2
	r11.s64 = 131072;
loc_82750EAC:
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// rlwinm r10,r10,0,16,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// b 0x82750d58
	goto loc_82750D58;
}

__attribute__((alias("__imp__sub_82750EC0"))) PPC_WEAK_FUNC(sub_82750EC0);
PPC_FUNC_IMPL(__imp__sub_82750EC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
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
	ctx.lr = 0x82750EC8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r20,1
	r20.s64 = 1;
	// li r21,2
	r21.s64 = 2;
	// mr r29,r22
	r29.u64 = r22.u64;
	// addi r23,r27,72
	r23.s64 = r27.s64 + 72;
loc_82750EEC:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r23
	reserved.u32 = *(uint32_t*)(base + r23.u32);
	r11.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r11,r20
	cr6.compare<int32_t>(r11.s32, r20.s32, xer);
	// bne cr6,0x82750f10
	if (!cr6.eq) goto loc_82750F10;
	// stwcx. r21,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r21.s32));
	cr0.so = xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82750eec
	if (!cr0.eq) goto loc_82750EEC;
	// b 0x82750f18
	goto loc_82750F18;
loc_82750F10:
	// stwcx. r11,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r11.s32));
	cr0.so = xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_82750F18:
	// mr r11,r11
	r11.u64 = r11.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8275109c
	if (!cr6.eq) goto loc_8275109C;
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82751098
	if (cr6.eq) goto loc_82751098;
	// lwz r11,196(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// rlwinm. r11,r11,0,12,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82751098
	if (cr0.eq) goto loc_82751098;
	// addi r26,r27,68
	r26.s64 = r27.s64 + 68;
	// mr r29,r22
	r29.u64 = r22.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r31,r22
	r31.u64 = r22.u64;
	// bl 0x827bd684
	ctx.lr = 0x82750F50;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,52(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 52);
	// addi r28,r27,52
	r28.s64 = r27.s64 + 52;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82750f80
	goto loc_82750F80;
loc_82750F60:
	// cmplw cr6,r31,r25
	cr6.compare<uint32_t>(r31.u32, r25.u32, xer);
	// bge cr6,0x82750f88
	if (!cr6.lt) goto loc_82750F88;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// add r31,r10,r31
	r31.u64 = ctx.r10.u64 + r31.u64;
loc_82750F80:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82750f60
	if (!cr6.eq) goto loc_82750F60;
loc_82750F88:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd674
	ctx.lr = 0x82750F90;
	__imp__KfReleaseSpinLock(ctx, base);
	// cmplw cr6,r31,r25
	cr6.compare<uint32_t>(r31.u32, r25.u32, xer);
	// blt cr6,0x8275109c
	if (cr6.lt) goto loc_8275109C;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x8275108c
	goto loc_8275108C;
loc_82750FA0:
	// cmplw cr6,r29,r25
	cr6.compare<uint32_t>(r29.u32, r25.u32, xer);
	// bge cr6,0x8275109c
	if (!cr6.lt) goto loc_8275109C;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8275109c
	if (cr6.eq) goto loc_8275109C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r29,r25
	ctx.r9.s64 = r25.s64 - r29.s64;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x82750fd8
	if (cr6.lt) goto loc_82750FD8;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
loc_82750FD8:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// add r4,r29,r24
	ctx.r4.u64 = r29.u64 + r24.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823da950
	ctx.lr = 0x82750FEC;
	sub_823DA950(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + r30.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x82751008
	if (!cr6.lt) goto loc_82751008;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82751008:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82751088
	if (!cr6.eq) goto loc_82751088;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd684
	ctx.lr = 0x82751024;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82751050
	if (cr6.eq) goto loc_82751050;
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82751044
	if (!cr6.eq) goto loc_82751044;
	// stw r22,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r22.u32);
loc_82751044:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r22.u32);
loc_82751050:
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8275107c
	if (!cr6.eq) goto loc_8275107C;
	// stw r22,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r22.u32);
	// addi r11,r27,60
	r11.s64 = r27.s64 + 60;
	// lwz r10,64(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82751074
	if (cr6.eq) goto loc_82751074;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x82751078
	goto loc_82751078;
loc_82751074:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_82751078:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
loc_8275107C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd674
	ctx.lr = 0x82751084;
	__imp__KfReleaseSpinLock(ctx, base);
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_82751088:
	// add r29,r30,r29
	r29.u64 = r30.u64 + r29.u64;
loc_8275108C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82750fa0
	if (!cr6.eq) goto loc_82750FA0;
	// b 0x8275109c
	goto loc_8275109C;
loc_82751098:
	// mr r29,r25
	r29.u64 = r25.u64;
loc_8275109C:
	// li r10,3
	ctx.r10.s64 = 3;
loc_827510A0:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r23
	reserved.u32 = *(uint32_t*)(base + r23.u32);
	r11.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82751130
	if (!cr6.eq) goto loc_82751130;
	// stwcx. r22,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r22.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x827510a0
	if (!cr0.eq) goto loc_827510A0;
	// b 0x82751138
	goto loc_82751138;
loc_827510C4:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r23
	reserved.u32 = *(uint32_t*)(base + r23.u32);
	r11.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r11,r21
	cr6.compare<int32_t>(r11.s32, r21.s32, xer);
	// bne cr6,0x827510e8
	if (!cr6.eq) goto loc_827510E8;
	// stwcx. r20,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r20.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x827510c4
	if (!cr0.eq) goto loc_827510C4;
	// b 0x827510f0
	goto loc_827510F0;
loc_827510E8:
	// stwcx. r11,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r11.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_827510F0:
	// mr r11,r11
	r11.u64 = r11.u64;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82751144
	if (cr6.eq) goto loc_82751144;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82751144
	if (cr6.eq) goto loc_82751144;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82751144
	if (cr6.eq) goto loc_82751144;
loc_8275110C:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r23
	reserved.u32 = *(uint32_t*)(base + r23.u32);
	r11.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82751130
	if (!cr6.eq) goto loc_82751130;
	// stwcx. r22,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r22.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8275110c
	if (!cr0.eq) goto loc_8275110C;
	// b 0x82751138
	goto loc_82751138;
loc_82751130:
	// stwcx. r11,0,r23
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r23.u32), reserved.s32, __builtin_bswap32(r11.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_82751138:
	// mr r11,r11
	r11.u64 = r11.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x827510c4
	if (!cr6.eq) goto loc_827510C4;
loc_82751144:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82751150"))) PPC_WEAK_FUNC(sub_82751150);
PPC_FUNC_IMPL(__imp__sub_82751150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCRegister reserved{};
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
	ctx.lr = 0x82751158;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,148
	ctx.r3.s64 = r31.s64 + 148;
	// addi r30,r31,72
	r30.s64 = r31.s64 + 72;
	// bl 0x827bdc24
	ctx.lr = 0x82751170;
	__imp__XMsgCancelIORequest(ctx, base);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// b 0x827511f0
	goto loc_827511F0;
loc_8275117C:
	// li r11,2
	r11.s64 = 2;
	// li r8,3
	ctx.r8.s64 = 3;
loc_82751184:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r30
	reserved.u32 = *(uint32_t*)(base + r30.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x827511a8
	if (!cr6.eq) goto loc_827511A8;
	// stwcx. r8,0,r30
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r30.u32), reserved.s32, __builtin_bswap32(ctx.r8.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82751184
	if (!cr0.eq) goto loc_82751184;
	// b 0x827511b0
	goto loc_827511B0;
loc_827511A8:
	// stwcx. r10,0,r30
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r30.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_827511B0:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x827511fc
	if (cr6.eq) goto loc_827511FC;
	// li r11,1
	r11.s64 = 1;
loc_827511C0:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r30
	reserved.u32 = *(uint32_t*)(base + r30.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x827511e4
	if (!cr6.eq) goto loc_827511E4;
	// stwcx. r29,0,r30
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r30.u32), reserved.s32, __builtin_bswap32(r29.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x827511c0
	if (!cr0.eq) goto loc_827511C0;
	// b 0x827511ec
	goto loc_827511EC;
loc_827511E4:
	// stwcx. r10,0,r30
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r30.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_827511EC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_827511F0:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8275117c
	if (!cr6.eq) goto loc_8275117C;
	// b 0x82751208
	goto loc_82751208;
loc_827511FC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827511fc
	if (!cr6.eq) goto loc_827511FC;
loc_82751208:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275121c
	if (cr6.eq) goto loc_8275121C;
	// bl 0x827bdc14
	ctx.lr = 0x82751218;
	__imp__XamVoiceClose(ctx, base);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
loc_8275121C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82754dd8
	ctx.lr = 0x82751224;
	sub_82754DD8(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82751264
	if (!cr6.gt) goto loc_82751264;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_8275123C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751250;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8275123c
	if (cr6.lt) goto loc_8275123C;
loc_82751264:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275126C"))) PPC_WEAK_FUNC(sub_8275126C);
PPC_FUNC_IMPL(__imp__sub_8275126C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82751270"))) PPC_WEAK_FUNC(sub_82751270);
PPC_FUNC_IMPL(__imp__sub_82751270) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82751278;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// ori r28,r28,87
	r28.u64 = r28.u64 | 87;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827512d8
	if (cr6.eq) goto loc_827512D8;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_8275129C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82750ae8
	ctx.lr = 0x827512A8;
	sub_82750AE8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x827512d8
	if (cr0.eq) goto loc_827512D8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827512C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x827512d8
	if (cr0.lt) goto loc_827512D8;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x8275129c
	if (cr6.lt) goto loc_8275129C;
loc_827512D8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827512E4"))) PPC_WEAK_FUNC(sub_827512E4);
PPC_FUNC_IMPL(__imp__sub_827512E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827512E8"))) PPC_WEAK_FUNC(sub_827512E8);
PPC_FUNC_IMPL(__imp__sub_827512E8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827512F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// ori r28,r28,87
	r28.u64 = r28.u64 | 87;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82751350
	if (cr6.eq) goto loc_82751350;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_82751314:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82750ae8
	ctx.lr = 0x82751320;
	sub_82750AE8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82751350
	if (cr0.eq) goto loc_82751350;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751338;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x82751350
	if (cr0.lt) goto loc_82751350;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x82751314
	if (cr6.lt) goto loc_82751314;
loc_82751350:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8275135C"))) PPC_WEAK_FUNC(sub_8275135C);
PPC_FUNC_IMPL(__imp__sub_8275135C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82751360"))) PPC_WEAK_FUNC(sub_82751360);
PPC_FUNC_IMPL(__imp__sub_82751360) {
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
	ctx.lr = 0x82751368;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// bl 0x82750b60
	ctx.lr = 0x82751374;
	sub_82750B60(ctx, base);
	// addi r24,r25,76
	r24.s64 = r25.s64 + 76;
	// li r26,0
	r26.s64 = 0;
	// lwz r31,76(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 76);
	// b 0x82751428
	goto loc_82751428;
loc_82751384:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x82751430
	if (cr6.eq) goto loc_82751430;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827513bc
	if (cr6.eq) goto loc_827513BC;
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x827513b0
	if (!cr6.eq) goto loc_827513B0;
	// stw r26,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r26.u32);
loc_827513B0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r10.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
loc_827513BC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x827513e0
	if (!cr6.eq) goto loc_827513E0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
loc_827513E0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r25,68
	r30.s64 = r25.s64 + 68;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
	// bl 0x827bd684
	ctx.lr = 0x827513F4;
	__imp__KfAcquireSpinLock(ctx, base);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// lwz r10,56(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// addi r11,r25,52
	r11.s64 = r25.s64 + 52;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82751414
	if (cr6.eq) goto loc_82751414;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x82751418
	goto loc_82751418;
loc_82751414:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_82751418:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd674
	ctx.lr = 0x82751424;
	__imp__KfReleaseSpinLock(ctx, base);
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
loc_82751428:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82751384
	if (!cr6.eq) goto loc_82751384;
loc_82751430:
	// lwz r27,60(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 60);
	// addi r23,r25,60
	r23.s64 = r25.s64 + 60;
	// b 0x827515f0
	goto loc_827515F0;
loc_8275143C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf. r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82751614
	if (!cr0.eq) goto loc_82751614;
	// addi r31,r25,68
	r31.s64 = r25.s64 + 68;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd684
	ctx.lr = 0x8275145C;
	__imp__KfAcquireSpinLock(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8274f988
	ctx.lr = 0x82751468;
	sub_8274F988(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x82751480
	if (!cr0.eq) goto loc_82751480;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8274f988
	ctx.lr = 0x82751478;
	sub_8274F988(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// ble cr6,0x827515fc
	if (!cr6.gt) goto loc_827515FC;
loc_82751480:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827514a8
	if (cr6.eq) goto loc_827514A8;
	// lwz r10,4(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8275149c
	if (!cr6.eq) goto loc_8275149C;
	// stw r26,4(r23)
	PPC_STORE_U32(r23.u32 + 4, r26.u32);
loc_8275149C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r10.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
loc_827514A8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd674
	ctx.lr = 0x827514B4;
	__imp__KfReleaseSpinLock(ctx, base);
	// stw r26,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r26.u32);
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827514cc
	if (cr6.eq) goto loc_827514CC;
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// b 0x827514d0
	goto loc_827514D0;
loc_827514CC:
	// stw r27,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r27.u32);
loc_827514D0:
	// stw r27,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r27.u32);
	// addi r28,r25,84
	r28.s64 = r25.s64 + 84;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r30,r31
	r30.u64 = r31.u64;
	// rlwinm. r11,r10,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x827515b8
	if (!cr0.gt) goto loc_827515B8;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
loc_827514FC:
	// lha r10,0(r31)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 0));
	// li r12,-7880
	r12.s64 = -7880;
	// addi r11,r10,-7880
	r11.s64 = ctx.r10.s64 + -7880;
	// sth r26,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, r26.u16);
	// sth r26,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r26.u16);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// addi r5,r1,82
	ctx.r5.s64 = ctx.r1.s64 + 82;
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// andi. r10,r9,7880
	ctx.r10.u64 = ctx.r9.u64 & 7880;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | r11.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r10,7880
	r11.s64 = ctx.r10.s64 + 7880;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// and r9,r11,r12
	ctx.r9.u64 = r11.u64 & r12.u64;
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
	// bl 0x82753758
	ctx.lr = 0x8275154C;
	sub_82753758(ctx, base);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// li r12,-7880
	r12.s64 = -7880;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// lha r10,0(r31)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 0));
	// addi r11,r10,-7880
	r11.s64 = ctx.r10.s64 + -7880;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// andi. r10,r9,7880
	ctx.r10.u64 = ctx.r9.u64 & 7880;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// or r10,r11,r10
	ctx.r10.u64 = r11.u64 | ctx.r10.u64;
	// addi r11,r10,7880
	r11.s64 = ctx.r10.s64 + 7880;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// and r9,r11,r12
	ctx.r9.u64 = r11.u64 & r12.u64;
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
	// bl 0x82753758
	ctx.lr = 0x82751598;
	sub_82753758(ctx, base);
	// lha r11,80(r1)
	r11.s64 = int16_t(PPC_LOAD_U16(ctx.r1.u32 + 80));
	// lhz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// rlwimi r10,r11,4,0,27
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xFFFFFFF0) | (ctx.r10.u64 & 0xFFFFFFFF0000000F);
	// stb r10,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r10.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne 0x827514fc
	if (!cr0.eq) goto loc_827514FC;
loc_827515B8:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r3,8(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// bl 0x827bdc34
	ctx.lr = 0x827515E4;
	__imp__XamVoiceSubmitPacket(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8275160c
	if (cr0.lt) goto loc_8275160C;
	// lwz r27,0(r23)
	r27.u64 = PPC_LOAD_U32(r23.u32 + 0);
loc_827515F0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8275143c
	if (!cr6.eq) goto loc_8275143C;
	// b 0x82751614
	goto loc_82751614;
loc_827515FC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r25,68
	ctx.r3.s64 = r25.s64 + 68;
	// bl 0x827bd674
	ctx.lr = 0x82751608;
	__imp__KfReleaseSpinLock(ctx, base);
	// b 0x82751614
	goto loc_82751614;
loc_8275160C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
loc_82751614:
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// bl 0x82754e98
	ctx.lr = 0x8275161C;
	sub_82754E98(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x82751660
	if (cr0.lt) goto loc_82751660;
	// lwz r11,32(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// mr r30,r26
	r30.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82751660
	if (!cr6.gt) goto loc_82751660;
	// addi r31,r25,12
	r31.s64 = r25.s64 + 12;
loc_82751638:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275164C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,32(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82751638
	if (cr6.lt) goto loc_82751638;
loc_82751660:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8275166C"))) PPC_WEAK_FUNC(sub_8275166C);
PPC_FUNC_IMPL(__imp__sub_8275166C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82751670"))) PPC_WEAK_FUNC(sub_82751670);
PPC_FUNC_IMPL(__imp__sub_82751670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82751678;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// bl 0x82750ae8
	ctx.lr = 0x82751694;
	sub_82750AE8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x827516bc
	if (cr0.eq) goto loc_827516BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827516B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_827516BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827516C8"))) PPC_WEAK_FUNC(sub_827516C8);
PPC_FUNC_IMPL(__imp__sub_827516C8) {
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
	ctx.lr = 0x827516D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244d150
	ctx.lr = 0x827516EC;
	sub_8244D150(ctx, base);
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8275175c
	if (!cr6.gt) goto loc_8275175C;
	// addi r31,r28,36
	r31.s64 = r28.s64 + 36;
loc_82751700:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r29,12(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
loc_82751714:
	// lwz r8,-8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275172c
	if (cr6.eq) goto loc_8275172C;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// beq cr6,0x82751764
	if (cr6.eq) goto loc_82751764;
loc_8275172C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// blt cr6,0x82751714
	if (cr6.lt) goto loc_82751714;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82751740:
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r3,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, ctx.r3.u32);
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82751700
	if (cr6.lt) goto loc_82751700;
loc_8275175C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82751764:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x8274f988
	ctx.lr = 0x82751770;
	sub_8274F988(ctx, base);
	// b 0x82751740
	goto loc_82751740;
}

__attribute__((alias("__imp__sub_82751774"))) PPC_WEAK_FUNC(sub_82751774);
PPC_FUNC_IMPL(__imp__sub_82751774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82751778"))) PPC_WEAK_FUNC(sub_82751778);
PPC_FUNC_IMPL(__imp__sub_82751778) {
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
	ctx.lr = 0x82751780;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82751868
	if (cr6.eq) goto loc_82751868;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827517a8
	if (cr6.eq) goto loc_827517A8;
	// bl 0x827bdc14
	ctx.lr = 0x827517A4;
	__imp__XamVoiceClose(ctx, base);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
loc_827517A8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x827553d0
	ctx.lr = 0x827517B0;
	sub_827553D0(ctx, base);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// mr r29,r28
	r29.u64 = r28.u64;
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827517e8
	if (!cr6.gt) goto loc_827517E8;
	// addi r30,r31,36
	r30.s64 = r31.s64 + 36;
loc_827517C8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8274f7f8
	ctx.lr = 0x827517D0;
	sub_8274F7F8(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x827517c8
	if (cr6.lt) goto loc_827517C8;
loc_827517E8:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82751828
	if (!cr6.gt) goto loc_82751828;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_827517FC:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x827517fc
	if (cr6.lt) goto loc_827517FC;
loc_82751828:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x8274fb28
	ctx.lr = 0x82751830;
	sub_8274FB28(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,148
	ctx.r3.s64 = r31.s64 + 148;
	// bl 0x827bdc24
	ctx.lr = 0x8275183C;
	__imp__XMsgCancelIORequest(ctx, base);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82751858
	if (cr6.eq) goto loc_82751858;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x82751854;
	sub_821310F8(ctx, base);
	// stw r28,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r28.u32);
loc_82751858:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32779
	ctx.r4.u64 = ctx.r4.u64 | 32779;
	// bl 0x821310f8
	ctx.lr = 0x82751868;
	sub_821310F8(ctx, base);
loc_82751868:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82751870"))) PPC_WEAK_FUNC(sub_82751870);
PPC_FUNC_IMPL(__imp__sub_82751870) {
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
	ctx.lr = 0x82751878;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82751150
	ctx.lr = 0x82751888;
	sub_82751150(ctx, base);
	// addi r28,r31,8
	r28.s64 = r31.s64 + 8;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bdc44
	ctx.lr = 0x8275189C;
	__imp__XamVoiceCreate(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x82751900
	if (cr0.lt) goto loc_82751900;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x827554d0
	ctx.lr = 0x827518B0;
	sub_827554D0(ctx, base);
	// lis r11,2
	r11.s64 = 131072;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// ori r11,r11,25604
	r11.u64 = r11.u64 | 25604;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
loc_827518CC:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// stwcx. r8,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r8.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x827518cc
	if (!cr0.eq) goto loc_827518CC;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// addi r4,r11,-1808
	ctx.r4.s64 = r11.s64 + -1808;
	// li r5,54
	ctx.r5.s64 = 54;
	// bl 0x823da950
	ctx.lr = 0x827518F8;
	sub_823DA950(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bge cr6,0x82751918
	if (!cr6.lt) goto loc_82751918;
loc_82751900:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82751918
	if (cr6.eq) goto loc_82751918;
	// bl 0x827bdc14
	ctx.lr = 0x82751910;
	__imp__XamVoiceClose(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82751918:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82751924"))) PPC_WEAK_FUNC(sub_82751924);
PPC_FUNC_IMPL(__imp__sub_82751924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82751928"))) PPC_WEAK_FUNC(sub_82751928);
PPC_FUNC_IMPL(__imp__sub_82751928) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82751930;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// li r3,464
	ctx.r3.s64 = 464;
	// ori r4,r4,32779
	ctx.r4.u64 = ctx.r4.u64 | 32779;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// bl 0x82130b50
	ctx.lr = 0x82751954;
	sub_82130B50(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// li r20,0
	r20.s64 = 0;
	// bne 0x8275196c
	if (!cr0.eq) goto loc_8275196C;
loc_82751960:
	// lis r22,-32761
	r22.s64 = -2147024896;
	// ori r22,r22,14
	r22.u64 = r22.u64 | 14;
	// b 0x82751c88
	goto loc_82751C88;
loc_8275196C:
	// lis r11,2
	r11.s64 = 131072;
	// stw r19,144(r28)
	PPC_STORE_U32(r28.u32 + 144, r19.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r20,68(r28)
	PPC_STORE_U32(r28.u32 + 68, r20.u32);
	// ori r11,r11,25604
	r11.u64 = r11.u64 | 25604;
	// stw r20,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r20.u32);
	// addi r31,r28,180
	r31.s64 = r28.s64 + 180;
	// stw r11,196(r28)
	PPC_STORE_U32(r28.u32 + 196, r11.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r9,198(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 198);
	// lis r3,-2
	ctx.r3.s64 = -131072;
	// std r9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// addi r8,r11,-4896
	ctx.r8.s64 = r11.s64 + -4896;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,255
	ctx.r4.s64 = 255;
	// ori r3,r3,2001
	ctx.r3.u64 = ctx.r3.u64 | 2001;
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// lfs f0,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,184(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 184, temp.u32);
	// bl 0x827bd324
	ctx.lr = 0x827519D8;
	__imp__XamUserReadProfileSettings(ctx, base);
	// cmplwi cr6,r3,122
	cr6.compare<uint32_t>(ctx.r3.u32, 122, xer);
	// beq cr6,0x827519ec
	if (cr6.eq) goto loc_827519EC;
	// lis r22,-32768
	r22.s64 = -2147483648;
	// ori r22,r22,16389
	r22.u64 = r22.u64 | 16389;
	// b 0x82751c88
	goto loc_82751C88;
loc_827519EC:
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x82130b50
	ctx.lr = 0x827519FC;
	sub_82130B50(ctx, base);
	// stw r3,176(r28)
	PPC_STORE_U32(r28.u32 + 176, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82751960
	if (cr0.eq) goto loc_82751960;
	// addi r31,r28,48
	r31.s64 = r28.s64 + 48;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x8274fc70
	ctx.lr = 0x82751A24;
	sub_8274FC70(ctx, base);
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// blt 0x82751c88
	if (cr0.lt) goto loc_82751C88;
	// addi r8,r28,52
	ctx.r8.s64 = r28.s64 + 52;
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
loc_82751A34:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r10,24
	r11.s64 = ctx.r10.s64 + 24;
	// stw r10,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r10.u32);
	// stw r20,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, r20.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82751a68
	if (cr6.eq) goto loc_82751A68;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x82751a6c
	goto loc_82751A6C;
loc_82751A68:
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
loc_82751A6C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// cmplwi cr6,r9,5
	cr6.compare<uint32_t>(ctx.r9.u32, 5, xer);
	// blt cr6,0x82751a34
	if (cr6.lt) goto loc_82751A34;
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8244d150
	ctx.lr = 0x82751A8C;
	sub_8244D150(ctx, base);
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8244d150
	ctx.lr = 0x82751A9C;
	sub_8244D150(ctx, base);
	// mr r30,r20
	r30.u64 = r20.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82751b30
	if (cr6.eq) goto loc_82751B30;
	// addi r31,r28,12
	r31.s64 = r28.s64 + 12;
loc_82751AAC:
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// bge cr6,0x82751b30
	if (!cr6.lt) goto loc_82751B30;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751AD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// blt 0x82751b30
	if (cr0.lt) goto loc_82751B30;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751AF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// stwx r11,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r11,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r11.u32);
	// blt cr6,0x82751aac
	if (cr6.lt) goto loc_82751AAC;
loc_82751B30:
	// addi r11,r28,32
	r11.s64 = r28.s64 + 32;
	// stw r30,32(r28)
	PPC_STORE_U32(r28.u32 + 32, r30.u32);
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// blt cr6,0x82751c88
	if (cr6.lt) goto loc_82751C88;
	// mr r25,r20
	r25.u64 = r20.u64;
	// mr r21,r20
	r21.u64 = r20.u64;
	// addi r31,r1,128
	r31.s64 = ctx.r1.s64 + 128;
	// addi r23,r1,112
	r23.s64 = ctx.r1.s64 + 112;
	// mr r26,r11
	r26.u64 = r11.u64;
loc_82751B54:
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// mr r29,r20
	r29.u64 = r20.u64;
	// bl 0x8244d150
	ctx.lr = 0x82751B68;
	sub_8244D150(ctx, base);
	// addi r30,r1,104
	r30.s64 = ctx.r1.s64 + 104;
	// mr r24,r31
	r24.u64 = r31.u64;
	// li r27,2
	r27.s64 = 2;
loc_82751B74:
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82751ba4
	if (cr6.eq) goto loc_82751BA4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
loc_82751BA4:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// bne 0x82751b74
	if (!cr0.eq) goto loc_82751B74;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82751c34
	if (cr6.eq) goto loc_82751C34;
	// addi r7,r26,4
	ctx.r7.s64 = r26.s64 + 4;
	// lwz r4,0(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x8274f8a0
	ctx.lr = 0x82751BD0;
	sub_8274F8A0(ctx, base);
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// blt 0x82751c48
	if (cr0.lt) goto loc_82751C48;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// mr r30,r20
	r30.u64 = r20.u64;
	// mr r29,r20
	r29.u64 = r20.u64;
loc_82751BE8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82751c1c
	if (cr6.eq) goto loc_82751C1C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,0(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82751C10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// blt 0x82751c48
	if (cr0.lt) goto loc_82751C48;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82751C1C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r29,2
	cr6.compare<uint32_t>(r29.u32, 2, xer);
	// blt cr6,0x82751be8
	if (cr6.lt) goto loc_82751BE8;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// blt cr6,0x82751c48
	if (cr6.lt) goto loc_82751C48;
loc_82751C34:
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// mr r31,r24
	r31.u64 = r24.u64;
	// cmplwi cr6,r21,3
	cr6.compare<uint32_t>(r21.u32, 3, xer);
	// blt cr6,0x82751b54
	if (cr6.lt) goto loc_82751B54;
loc_82751C48:
	// stw r25,44(r28)
	PPC_STORE_U32(r28.u32 + 44, r25.u32);
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// blt cr6,0x82751c88
	if (cr6.lt) goto loc_82751C88;
	// addi r8,r28,4
	ctx.r8.s64 = r28.s64 + 4;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// addi r6,r28,36
	ctx.r6.s64 = r28.s64 + 36;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82755560
	ctx.lr = 0x82751C70;
	sub_82755560(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// stw r10,140(r28)
	PPC_STORE_U32(r28.u32 + 140, ctx.r10.u32);
	// bge 0x82751c94
	if (!cr0.lt) goto loc_82751C94;
loc_82751C88:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82751778
	ctx.lr = 0x82751C90;
	sub_82751778(ctx, base);
	// mr r28,r20
	r28.u64 = r20.u64;
loc_82751C94:
	// stw r28,0(r18)
	PPC_STORE_U32(r18.u32 + 0, r28.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82751CA4"))) PPC_WEAK_FUNC(sub_82751CA4);
PPC_FUNC_IMPL(__imp__sub_82751CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82751CA8"))) PPC_WEAK_FUNC(sub_82751CA8);
PPC_FUNC_IMPL(__imp__sub_82751CA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// li r31,1
	r31.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// blt cr6,0x82751d24
	if (cr6.lt) goto loc_82751D24;
	// beq cr6,0x82751ce8
	if (cr6.eq) goto loc_82751CE8;
	// cmplwi cr6,r7,3
	cr6.compare<uint32_t>(ctx.r7.u32, 3, xer);
	// blt cr6,0x82751cd8
	if (cr6.lt) goto loc_82751CD8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82751e1c
	goto loc_82751E1C;
loc_82751CD8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r31,6
	r31.s64 = 6;
	// addi r5,r11,-4624
	ctx.r5.s64 = r11.s64 + -4624;
	// b 0x82751d30
	goto loc_82751D30;
loc_82751CE8:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82751d18
	if (cr6.eq) goto loc_82751D18;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_82751CF8:
	// lhz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// sth r7,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r7.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// sth r8,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bne 0x82751cf8
	if (!cr0.eq) goto loc_82751CF8;
loc_82751D18:
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// b 0x82751d28
	goto loc_82751D28;
loc_82751D24:
	// li r31,2
	r31.s64 = 2;
loc_82751D28:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r5,r11,-4880
	ctx.r5.s64 = r11.s64 + -4880;
loc_82751D30:
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82751e14
	if (cr6.eq) goto loc_82751E14;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfd f12,-1816(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + -1816);
	// lfd f13,-17600(r10)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + -17600);
loc_82751D4C:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82751d9c
	if (cr6.eq) goto loc_82751D9C;
	// mr r11,r31
	r11.u64 = r31.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + r31.u64;
loc_82751D60:
	// lha r10,0(r7)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r7.u32 + 0));
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// std r10,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r10.u64);
	// lfd f11,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lwz r9,256(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// fmul f11,f11,f12
	ctx.f11.f64 = ctx.f11.f64 * ctx.f12.f64;
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// stfdx f11,r9,r3
	PPC_STORE_U64(ctx.r9.u32 + ctx.r3.u32, ctx.f11.u64);
	// lwz r10,256(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// stw r10,256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 256, ctx.r10.u32);
	// bne 0x82751d60
	if (!cr0.eq) goto loc_82751D60;
loc_82751D9C:
	// lwz r10,256(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// li r11,32
	r11.s64 = 32;
loc_82751DA8:
	// rlwinm r30,r10,3,24,28
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xF8;
	// lfd f11,0(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lfdx f10,r30,r3
	ctx.f10.u64 = PPC_LOAD_U64(r30.u32 + ctx.r3.u32);
	// fmadd f0,f10,f11,f0
	f0.f64 = ctx.f10.f64 * ctx.f11.f64 + f0.f64;
	// bne 0x82751da8
	if (!cr0.eq) goto loc_82751DA8;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f0.u64);
	// lwz r10,-20(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -20);
	// addi r11,r10,-32767
	r11.s64 = ctx.r10.s64 + -32767;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// clrlwi r10,r9,17
	ctx.r10.u64 = ctx.r9.u32 & 0x7FFF;
	// or r10,r11,r10
	ctx.r10.u64 = r11.u64 | ctx.r10.u64;
	// addis r11,r10,1
	r11.s64 = ctx.r10.s64 + 65536;
	// addi r11,r11,-32768
	r11.s64 = r11.s64 + -32768;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// rlwinm r9,r11,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// sth r11,0(r4)
	PPC_STORE_U16(ctx.r4.u32 + 0, r11.u16);
	// addi r4,r4,2
	ctx.r4.s64 = ctx.r4.s64 + 2;
	// blt cr6,0x82751d4c
	if (cr6.lt) goto loc_82751D4C;
loc_82751E14:
	// divwu r3,r8,r31
	ctx.r3.u32 = ctx.r8.u32 / r31.u32;
	// twllei r31,0
loc_82751E1C:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82751E28"))) PPC_WEAK_FUNC(sub_82751E28);
PPC_FUNC_IMPL(__imp__sub_82751E28) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82751E30;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r24,r25,8
	r24.s64 = r25.s64 + 8;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// li r21,1
	r21.s64 = 1;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r27,8(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_82751E60:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82751e9c
	if (cr6.eq) goto loc_82751E9C;
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// bne cr6,0x82751e84
	if (!cr6.eq) goto loc_82751E84;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x82751e88
	goto loc_82751E88;
loc_82751E84:
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
loc_82751E88:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82751ea0
	if (cr6.eq) goto loc_82751EA0;
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// b 0x82751ea0
	goto loc_82751EA0;
loc_82751E9C:
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
loc_82751EA0:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82751e60
	if (!cr0.eq) goto loc_82751E60;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82752018
	if (cr6.eq) goto loc_82752018;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82752018
	if (cr6.eq) goto loc_82752018;
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// b 0x82752010
	goto loc_82752010;
loc_82751EC8:
	// addi r23,r23,-1
	r23.s64 = r23.s64 + -1;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82752018
	if (cr6.eq) goto loc_82752018;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82752018
	if (cr6.eq) goto loc_82752018;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r30,r11,r8
	r30.s64 = ctx.r8.s64 - r11.s64;
loc_82751EF4:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82751f28
	if (cr6.eq) goto loc_82751F28;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r8,4(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// blt cr6,0x82751f28
	if (cr6.lt) goto loc_82751F28;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r30,r11,r8
	r30.s64 = ctx.r8.s64 - r11.s64;
loc_82751F28:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82751ef4
	if (!cr0.eq) goto loc_82751EF4;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// mr r28,r24
	r28.u64 = r24.u64;
	// li r26,2
	r26.s64 = 2;
loc_82751F40:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82751fc0
	if (cr6.eq) goto loc_82751FC0;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bl 0x823da950
	ctx.lr = 0x82751F74;
	sub_823DA950(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + r30.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x82751f90
	if (!cr6.lt) goto loc_82751F90;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82751F90:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82751fc0
	if (!cr6.eq) goto loc_82751FC0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x8274f9a8
	ctx.lr = 0x82751FB0;
	sub_8274F9A8(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x82751fc0
	if (!cr0.eq) goto loc_82751FC0;
	// addi r22,r22,-1
	r22.s64 = r22.s64 + -1;
loc_82751FC0:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82751f40
	if (!cr0.eq) goto loc_82751F40;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + r30.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x82751fec
	if (!cr6.lt) goto loc_82751FEC;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82751FEC:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82752010
	if (!cr6.eq) goto loc_82752010;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// bl 0x8274f9a8
	ctx.lr = 0x8275200C;
	sub_8274F9A8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_82752010:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x82751ec8
	if (!cr6.eq) goto loc_82751EC8;
loc_82752018:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82752024"))) PPC_WEAK_FUNC(sub_82752024);
PPC_FUNC_IMPL(__imp__sub_82752024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82752028"))) PPC_WEAK_FUNC(sub_82752028);
PPC_FUNC_IMPL(__imp__sub_82752028) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82752030;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,1
	r29.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplw cr6,r30,r7
	cr6.compare<uint32_t>(r30.u32, ctx.r7.u32, xer);
	// beq cr6,0x82752124
	if (cr6.eq) goto loc_82752124;
	// li r11,4
	r11.s64 = 4;
	// stb r29,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r29.u8);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f31,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f31.f64 = double(temp.f32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// addi r9,r31,36
	ctx.r9.s64 = r31.s64 + 36;
loc_8275209C:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stb r8,-4(r11)
	PPC_STORE_U8(r11.u32 + -4, ctx.r8.u8);
	// cmplwi cr6,r6,65535
	cr6.compare<uint32_t>(ctx.r6.u32, 65535, xer);
	// stb r10,-3(r11)
	PPC_STORE_U8(r11.u32 + -3, ctx.r10.u8);
	// bgt cr6,0x827520c8
	if (cr6.gt) goto loc_827520C8;
	// lbz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// slw r5,r29,r10
	ctx.r5.u64 = ctx.r10.u8 & 0x20 ? 0 : (r29.u32 << (ctx.r10.u8 & 0x3F));
	// and. r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 & ctx.r5.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne 0x827520c8
	if (!cr0.eq) goto loc_827520C8;
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// b 0x827520cc
	goto loc_827520CC;
loc_827520C8:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_827520CC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x8275209c
	if (cr6.lt) goto loc_8275209C;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x827520f0
	if (cr6.eq) goto loc_827520F0;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x823ea140
	ctx.lr = 0x827520F0;
	sub_823EA140(ctx, base);
loc_827520F0:
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82752104
	if (!cr6.eq) goto loc_82752104;
	// lwz r30,80(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// b 0x82752114
	goto loc_82752114;
loc_82752104:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ea0d8
	ctx.lr = 0x8275210C;
	sub_823EA0D8(ctx, base);
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r29,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r29.u8);
loc_82752114:
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x823ea218
	ctx.lr = 0x82752124;
	sub_823EA218(ctx, base);
loc_82752124:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82752130"))) PPC_WEAK_FUNC(sub_82752130);
PPC_FUNC_IMPL(__imp__sub_82752130) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8275214c
	if (cr6.eq) goto loc_8275214C;
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// b 0x82752150
	goto loc_82752150;
loc_8275214C:
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
loc_82752150:
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x823ea1a8
	sub_823EA1A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8275215C"))) PPC_WEAK_FUNC(sub_8275215C);
PPC_FUNC_IMPL(__imp__sub_8275215C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82752160"))) PPC_WEAK_FUNC(sub_82752160);
PPC_FUNC_IMPL(__imp__sub_82752160) {
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
	ctx.lr = 0x82752168;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827521b8
	if (!cr6.gt) goto loc_827521B8;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
loc_82752188:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275219C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r28,r3
	cr6.compare<uint32_t>(r28.u32, ctx.r3.u32, xer);
	// beq cr6,0x827521c4
	if (cr6.eq) goto loc_827521C4;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82752188
	if (cr6.lt) goto loc_82752188;
loc_827521B8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827521BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_827521C4:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// b 0x827521bc
	goto loc_827521BC;
}

__attribute__((alias("__imp__sub_827521D4"))) PPC_WEAK_FUNC(sub_827521D4);
PPC_FUNC_IMPL(__imp__sub_827521D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827521D8"))) PPC_WEAK_FUNC(sub_827521D8);
PPC_FUNC_IMPL(__imp__sub_827521D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x827521E0;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r5,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r5.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// li r11,4
	r11.s64 = 4;
	// li r29,0
	r29.s64 = 0;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r30,1
	r30.s64 = 1;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// ori r10,r10,48000
	ctx.r10.u64 = ctx.r10.u64 | 48000;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// stb r29,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r29.u8);
	// addi r26,r31,72
	r26.s64 = r31.s64 + 72;
	// stb r11,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, r11.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stb r30,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r30.u8);
	// stb r11,121(r1)
	PPC_STORE_U8(ctx.r1.u32 + 121, r11.u8);
	// stb r30,122(r1)
	PPC_STORE_U8(ctx.r1.u32 + 122, r30.u8);
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r29.u32);
	// beq cr6,0x82752270
	if (cr6.eq) goto loc_82752270;
	// bl 0x823ea140
	ctx.lr = 0x8275226C;
	sub_823EA140(ctx, base);
	// stw r29,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r29.u32);
loc_82752270:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r24,r31,80
	r24.s64 = r31.s64 + 80;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752288
	if (cr6.eq) goto loc_82752288;
	// bl 0x823ea140
	ctx.lr = 0x82752284;
	sub_823EA140(ctx, base);
	// stw r29,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r29.u32);
loc_82752288:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275229c
	if (cr6.eq) goto loc_8275229C;
	// bl 0x823ea140
	ctx.lr = 0x82752298;
	sub_823EA140(ctx, base);
	// stw r29,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r29.u32);
loc_8275229C:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lwz r9,56(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_827522B8:
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,145
	ctx.r7.s64 = ctx.r1.s64 + 145;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r6,r1,148
	ctx.r6.s64 = ctx.r1.s64 + 148;
	// stbx r11,r9,r8
	PPC_STORE_U8(ctx.r9.u32 + ctx.r8.u32, r11.u8);
	// stbx r11,r9,r7
	PPC_STORE_U8(ctx.r9.u32 + ctx.r7.u32, r11.u8);
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// stfsx f31,r9,r6
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r6.u32, temp.u32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// blt cr6,0x827522b8
	if (cr6.lt) goto loc_827522B8;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823eaaf0
	ctx.lr = 0x827522F4;
	sub_823EAAF0(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x82752418
	if (cr0.lt) goto loc_82752418;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r27,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r27.u32);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// stb r30,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, r30.u8);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stb r29,122(r1)
	PPC_STORE_U8(ctx.r1.u32 + 122, r29.u8);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82752318:
	// addi r8,r11,9
	ctx.r8.s64 = r11.s64 + 9;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,145
	ctx.r6.s64 = ctx.r1.s64 + 145;
	// lwzx r8,r8,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// stbx r29,r9,r7
	PPC_STORE_U8(ctx.r9.u32 + ctx.r7.u32, r29.u8);
	// stbx r10,r9,r6
	PPC_STORE_U8(ctx.r9.u32 + ctx.r6.u32, ctx.r10.u8);
	// cmplwi cr6,r8,65535
	cr6.compare<uint32_t>(ctx.r8.u32, 65535, xer);
	// bgt cr6,0x8275235c
	if (cr6.gt) goto loc_8275235C;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// slw r8,r30,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 << (r11.u8 & 0x3F));
	// and. r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8275235c
	if (!cr0.eq) goto loc_8275235C;
	// addi r10,r1,148
	ctx.r10.s64 = ctx.r1.s64 + 148;
	// stfsx f31,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// b 0x82752364
	goto loc_82752364;
loc_8275235C:
	// addi r10,r1,148
	ctx.r10.s64 = ctx.r1.s64 + 148;
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82752364:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x82752318
	if (cr6.lt) goto loc_82752318;
	// stw r25,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r25.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8275238c
	if (!cr6.eq) goto loc_8275238C;
	// lwz r25,0(r24)
	r25.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// b 0x8275239c
	goto loc_8275239C;
loc_8275238C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823ea0d8
	ctx.lr = 0x82752394;
	sub_823EA0D8(ctx, base);
	// stfs f31,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stb r30,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r30.u8);
loc_8275239C:
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823eaaf0
	ctx.lr = 0x827523AC;
	sub_823EAAF0(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x82752418
	if (cr0.lt) goto loc_82752418;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752410
	if (!cr6.gt) goto loc_82752410;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_827523C4:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827523E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x827523fc
	if (!cr0.lt) goto loc_827523FC;
	// lis r11,-32768
	r11.s64 = -2147483648;
	// ori r11,r11,16385
	r11.u64 = r11.u64 | 16385;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bne cr6,0x82752410
	if (!cr6.eq) goto loc_82752410;
loc_827523FC:
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x827523c4
	if (cr6.lt) goto loc_827523C4;
loc_82752410:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bge cr6,0x82752440
	if (!cr6.lt) goto loc_82752440;
loc_82752418:
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275242c
	if (cr6.eq) goto loc_8275242C;
	// bl 0x823ea140
	ctx.lr = 0x82752428;
	sub_823EA140(ctx, base);
	// stw r29,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r29.u32);
loc_8275242C:
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752440
	if (cr6.eq) goto loc_82752440;
	// bl 0x823ea140
	ctx.lr = 0x8275243C;
	sub_823EA140(ctx, base);
	// stw r29,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r29.u32);
loc_82752440:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82752450"))) PPC_WEAK_FUNC(sub_82752450);
PPC_FUNC_IMPL(__imp__sub_82752450) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82752458;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// li r22,1
	r22.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r23,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r23.u8);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r8,3
	ctx.r8.s64 = 3;
	// lwz r10,76(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stb r22,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, r22.u8);
	// stb r9,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, ctx.r9.u8);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stb r8,152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 152, ctx.r8.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r7,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r7.u8);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stb r23,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r23.u8);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// stb r22,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r22.u8);
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// bne cr6,0x827526a0
	if (!cr6.eq) goto loc_827526A0;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lwz r30,68(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// stw r22,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r22.u32);
	// li r31,1112
	r31.s64 = 1112;
	// stw r22,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r22.u32);
	// addi r21,r11,-1112
	r21.s64 = r11.s64 + -1112;
	// stw r22,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r22.u32);
	// stw r22,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r22.u32);
loc_827524F4:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8275252c
	if (cr6.eq) goto loc_8275252C;
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lwz r9,196(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// rlwinm r9,r9,0,12,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF0000;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// beq cr6,0x82752530
	if (cr6.eq) goto loc_82752530;
loc_8275252C:
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
loc_82752530:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82752588
	if (cr6.eq) goto loc_82752588;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r10,196(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// rlwinm. r10,r10,0,12,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xF0000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82752584
	if (cr0.eq) goto loc_82752584;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82752558
	if (!cr6.eq) goto loc_82752558;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82752588
	if (cr6.eq) goto loc_82752588;
loc_82752558:
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x827bd414
	ctx.lr = 0x82752578;
	__imp__XamUserAreUsersFriends(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82752588
	if (!cr6.eq) goto loc_82752588;
loc_82752584:
	// stwx r23,r21,r31
	PPC_STORE_U32(r21.u32 + r31.u32, r23.u32);
loc_82752588:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r31,1128
	cr6.compare<uint32_t>(r31.u32, 1128, xer);
	// blt cr6,0x827524f4
	if (cr6.lt) goto loc_827524F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r26,r23
	r26.u64 = r23.u64;
	// addi r25,r1,132
	r25.s64 = ctx.r1.s64 + 132;
	// li r31,1112
	r31.s64 = 1112;
	// addi r24,r28,-1076
	r24.s64 = r28.s64 + -1076;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_827525AC:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827525d0
	if (cr6.eq) goto loc_827525D0;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r27,r22
	r27.u64 = r22.u64;
	// lwz r9,192(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x827525d4
	if (!cr6.eq) goto loc_827525D4;
loc_827525D0:
	// mr r27,r23
	r27.u64 = r23.u64;
loc_827525D4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82752664
	if (cr6.eq) goto loc_82752664;
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x827525f4
	if (!cr0.eq) goto loc_827525F4;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x82752664
	if (!cr6.eq) goto loc_82752664;
loc_827525F4:
	// mr r30,r23
	r30.u64 = r23.u64;
	// addi r29,r1,112
	r29.s64 = ctx.r1.s64 + 112;
loc_827525FC:
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// beq cr6,0x82752654
	if (cr6.eq) goto loc_82752654;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82752654
	if (!cr6.eq) goto loc_82752654;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82752650
	if (cr0.eq) goto loc_82752650;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82752650
	if (cr6.eq) goto loc_82752650;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r10,196(r11)
	PPC_STORE_U32(r11.u32 + 196, ctx.r10.u32);
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r4,r31,r3
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	// bl 0x8274e020
	ctx.lr = 0x8275264C;
	sub_8274E020(ctx, base);
	// b 0x82752654
	goto loc_82752654;
loc_82752650:
	// stwx r23,r31,r21
	PPC_STORE_U32(r31.u32 + r21.u32, r23.u32);
loc_82752654:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplwi cr6,r30,4
	cr6.compare<uint32_t>(r30.u32, 4, xer);
	// blt cr6,0x827525fc
	if (cr6.lt) goto loc_827525FC;
loc_82752664:
	// lwzx r11,r31,r21
	r11.u64 = PPC_LOAD_U32(r31.u32 + r21.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82752680
	if (cr6.eq) goto loc_82752680;
	// lwzx r11,r24,r31
	r11.u64 = PPC_LOAD_U32(r24.u32 + r31.u32);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bgt cr6,0x82752680
	if (cr6.gt) goto loc_82752680;
	// stfs f31,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
loc_82752680:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// cmplwi cr6,r31,1128
	cr6.compare<uint32_t>(r31.u32, 1128, xer);
	// blt cr6,0x827525ac
	if (cr6.lt) goto loc_827525AC;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r3,72(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// bl 0x823ea270
	ctx.lr = 0x827526A0;
	sub_823EA270(ctx, base);
loc_827526A0:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_827526AC"))) PPC_WEAK_FUNC(sub_827526AC);
PPC_FUNC_IMPL(__imp__sub_827526AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827526B0"))) PPC_WEAK_FUNC(sub_827526B0);
PPC_FUNC_IMPL(__imp__sub_827526B0) {
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
	ctx.lr = 0x827526B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8275278c
	if (cr6.eq) goto loc_8275278C;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752700
	if (!cr6.gt) goto loc_82752700;
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
loc_827526E0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8274f7f8
	ctx.lr = 0x827526E8;
	sub_8274F7F8(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x827526e0
	if (cr6.lt) goto loc_827526E0;
loc_82752700:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752740
	if (!cr6.gt) goto loc_82752740;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_82752714:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x82752714
	if (cr6.lt) goto loc_82752714;
loc_82752740:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752754
	if (cr6.eq) goto loc_82752754;
	// bl 0x823ea140
	ctx.lr = 0x82752750;
	sub_823EA140(ctx, base);
	// stw r28,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r28.u32);
loc_82752754:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752768
	if (cr6.eq) goto loc_82752768;
	// bl 0x823ea140
	ctx.lr = 0x82752764;
	sub_823EA140(ctx, base);
	// stw r28,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r28.u32);
loc_82752768:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275277c
	if (cr6.eq) goto loc_8275277C;
	// bl 0x823ea140
	ctx.lr = 0x82752778;
	sub_823EA140(ctx, base);
	// stw r28,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r28.u32);
loc_8275277C:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32784
	ctx.r4.u64 = ctx.r4.u64 | 32784;
	// bl 0x821310f8
	ctx.lr = 0x8275278C;
	sub_821310F8(ctx, base);
loc_8275278C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82752794"))) PPC_WEAK_FUNC(sub_82752794);
PPC_FUNC_IMPL(__imp__sub_82752794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82752798"))) PPC_WEAK_FUNC(sub_82752798);
PPC_FUNC_IMPL(__imp__sub_82752798) {
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
	ctx.lr = 0x827527A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827527fc
	if (!cr6.gt) goto loc_827527FC;
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
loc_827527BC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x8274e118
	ctx.lr = 0x827527D8;
	sub_8274E118(ctx, base);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8274f5a0
	ctx.lr = 0x827527E8;
	sub_8274F5A0(ctx, base);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x827527bc
	if (cr6.lt) goto loc_827527BC;
loc_827527FC:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752838
	if (!cr6.gt) goto loc_82752838;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_82752810:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x82752810
	if (cr6.lt) goto loc_82752810;
loc_82752838:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82752844"))) PPC_WEAK_FUNC(sub_82752844);
PPC_FUNC_IMPL(__imp__sub_82752844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82752848"))) PPC_WEAK_FUNC(sub_82752848);
PPC_FUNC_IMPL(__imp__sub_82752848) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82752850;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// ori r28,r28,87
	r28.u64 = r28.u64 | 87;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827528b0
	if (cr6.eq) goto loc_827528B0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_82752874:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82752160
	ctx.lr = 0x82752880;
	sub_82752160(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x827528b0
	if (cr0.eq) goto loc_827528B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x827528b0
	if (cr0.lt) goto loc_827528B0;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x82752874
	if (cr6.lt) goto loc_82752874;
loc_827528B0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827528BC"))) PPC_WEAK_FUNC(sub_827528BC);
PPC_FUNC_IMPL(__imp__sub_827528BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827528C0"))) PPC_WEAK_FUNC(sub_827528C0);
PPC_FUNC_IMPL(__imp__sub_827528C0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827528C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r28,-32761
	r28.s64 = -2147024896;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// ori r28,r28,87
	r28.u64 = r28.u64 | 87;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82752928
	if (cr6.eq) goto loc_82752928;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_827528EC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82752160
	ctx.lr = 0x827528F8;
	sub_82752160(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82752928
	if (cr0.eq) goto loc_82752928;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x82752928
	if (cr0.lt) goto loc_82752928;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x827528ec
	if (cr6.lt) goto loc_827528EC;
loc_82752928:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82752934"))) PPC_WEAK_FUNC(sub_82752934);
PPC_FUNC_IMPL(__imp__sub_82752934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82752938"))) PPC_WEAK_FUNC(sub_82752938);
PPC_FUNC_IMPL(__imp__sub_82752938) {
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
	ctx.lr = 0x82752940;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// bl 0x8244d150
	ctx.lr = 0x8275296C;
	sub_8244D150(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stb r26,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r26.u8);
	// bne cr6,0x827529a0
	if (!cr6.eq) goto loc_827529A0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827529a0
	if (!cr6.eq) goto loc_827529A0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82752028
	ctx.lr = 0x8275298C;
	sub_82752028(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x827529bc
	if (!cr6.eq) goto loc_827529BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82752450
	ctx.lr = 0x8275299C;
	sub_82752450(ctx, base);
	// b 0x827529bc
	goto loc_827529BC;
loc_827529A0:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827521d8
	ctx.lr = 0x827529B4;
	sub_827521D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x827529cc
	if (cr0.lt) goto loc_827529CC;
loc_827529BC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// std r27,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r27.u64);
	// stw r10,1308(r11)
	PPC_STORE_U32(r11.u32 + 1308, ctx.r10.u32);
loc_827529CC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827529D4"))) PPC_WEAK_FUNC(sub_827529D4);
PPC_FUNC_IMPL(__imp__sub_827529D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827529D8"))) PPC_WEAK_FUNC(sub_827529D8);
PPC_FUNC_IMPL(__imp__sub_827529D8) {
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
	ctx.lr = 0x827529E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x827529F4;
	sub_8244D150(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752a30
	if (!cr6.gt) goto loc_82752A30;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_82752A08:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x82752a08
	if (cr6.lt) goto loc_82752A08;
loc_82752A30:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752a48
	if (cr6.eq) goto loc_82752A48;
	// bl 0x823ea140
	ctx.lr = 0x82752A40;
	sub_823EA140(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
loc_82752A48:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,1308(r11)
	PPC_STORE_U32(r11.u32 + 1308, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82752A60"))) PPC_WEAK_FUNC(sub_82752A60);
PPC_FUNC_IMPL(__imp__sub_82752A60) {
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
	ctx.lr = 0x82752A68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r30,-32768
	r30.s64 = -2147483648;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r4,-1840(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -1840);
	// ori r30,r30,16389
	r30.u64 = r30.u64 | 16389;
	// bl 0x82752160
	ctx.lr = 0x82752A8C;
	sub_82752160(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// beq 0x82752ac8
	if (cr0.eq) goto loc_82752AC8;
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82752ab4
	if (cr6.eq) goto loc_82752AB4;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82752450
	ctx.lr = 0x82752AB4;
	sub_82752450(ctx, base);
loc_82752AB4:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8274cfd0
	ctx.lr = 0x82752AC4;
	sub_8274CFD0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82752AC8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82752AD4"))) PPC_WEAK_FUNC(sub_82752AD4);
PPC_FUNC_IMPL(__imp__sub_82752AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82752AD8"))) PPC_WEAK_FUNC(sub_82752AD8);
PPC_FUNC_IMPL(__imp__sub_82752AD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,9
	r11.s64 = ctx.r4.s64 + 9;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplw cr6,r5,r10
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, xer);
	// beq cr6,0x82752afc
	if (cr6.eq) goto loc_82752AFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stwx r5,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r5.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,1308(r11)
	PPC_STORE_U32(r11.u32 + 1308, ctx.r10.u32);
loc_82752AFC:
	// b 0x82752450
	sub_82752450(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82752B00"))) PPC_WEAK_FUNC(sub_82752B00);
PPC_FUNC_IMPL(__imp__sub_82752B00) {
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
	ctx.lr = 0x82752B08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752b60
	if (!cr6.gt) goto loc_82752B60;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
loc_82752B2C:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752B40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82752b4c
	if (!cr6.eq) goto loc_82752B4C;
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
loc_82752B4C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82752b2c
	if (cr6.lt) goto loc_82752B2C;
loc_82752B60:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82752b78
	if (cr6.eq) goto loc_82752B78;
	// li r11,200
	r11.s64 = 200;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// b 0x82752bac
	goto loc_82752BAC;
loc_82752B78:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82752bac
	if (!cr6.gt) goto loc_82752BAC;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82752ba8
	if (cr6.eq) goto loc_82752BA8;
	// bl 0x8244fee8
	ctx.lr = 0x82752B94;
	sub_8244FEE8(ctx, base);
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// subf r10,r3,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r3.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
loc_82752BA8:
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
loc_82752BAC:
	// bl 0x8244fee8
	ctx.lr = 0x82752BB0;
	sub_8244FEE8(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82752BC0"))) PPC_WEAK_FUNC(sub_82752BC0);
PPC_FUNC_IMPL(__imp__sub_82752BC0) {
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
	ctx.lr = 0x82752BC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244d150
	ctx.lr = 0x82752BE4;
	sub_8244D150(ctx, base);
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82752c54
	if (!cr6.gt) goto loc_82752C54;
	// addi r31,r28,24
	r31.s64 = r28.s64 + 24;
loc_82752BF8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r29,12(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
loc_82752C0C:
	// lwz r8,-8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82752c24
	if (cr6.eq) goto loc_82752C24;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// beq cr6,0x82752c5c
	if (cr6.eq) goto loc_82752C5C;
loc_82752C24:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// blt cr6,0x82752c0c
	if (cr6.lt) goto loc_82752C0C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82752C38:
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r3,r11,r27
	PPC_STORE_U32(r11.u32 + r27.u32, ctx.r3.u32);
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82752bf8
	if (cr6.lt) goto loc_82752BF8;
loc_82752C54:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82752C5C:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x8274f988
	ctx.lr = 0x82752C68;
	sub_8274F988(ctx, base);
	// b 0x82752c38
	goto loc_82752C38;
}

__attribute__((alias("__imp__sub_82752C6C"))) PPC_WEAK_FUNC(sub_82752C6C);
PPC_FUNC_IMPL(__imp__sub_82752C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82752C70"))) PPC_WEAK_FUNC(sub_82752C70);
PPC_FUNC_IMPL(__imp__sub_82752C70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82752C78;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r3,88
	ctx.r3.s64 = 88;
	// ori r4,r4,32784
	ctx.r4.u64 = ctx.r4.u64 | 32784;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// mr r18,r7
	r18.u64 = ctx.r7.u64;
	// mr r17,r8
	r17.u64 = ctx.r8.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x82130b50
	ctx.lr = 0x82752CA8;
	sub_82130B50(ctx, base);
	// mr. r25,r3
	r25.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// bne 0x82752cbc
	if (!cr0.eq) goto loc_82752CBC;
	// lis r26,-32761
	r26.s64 = -2147024896;
	// ori r26,r26,14
	r26.u64 = r26.u64 | 14;
	// b 0x82752ebc
	goto loc_82752EBC;
loc_82752CBC:
	// li r11,0
	r11.s64 = 0;
	// stw r20,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r20.u32);
	// li r5,24
	ctx.r5.s64 = 24;
	// stw r11,68(r25)
	PPC_STORE_U32(r25.u32 + 68, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8244d150
	ctx.lr = 0x82752CD8;
	sub_8244D150(ctx, base);
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x82752CE8;
	sub_8244D150(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82752d7c
	if (cr6.eq) goto loc_82752D7C;
	// addi r31,r25,12
	r31.s64 = r25.s64 + 12;
loc_82752CF8:
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// bge cr6,0x82752d7c
	if (!cr6.lt) goto loc_82752D7C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752D1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r26,r3
	r26.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x82752d7c
	if (cr0.lt) goto loc_82752D7C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752D3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// stwx r11,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r11,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r11.u32);
	// blt cr6,0x82752cf8
	if (cr6.lt) goto loc_82752CF8;
loc_82752D7C:
	// addi r11,r25,20
	r11.s64 = r25.s64 + 20;
	// stw r30,20(r25)
	PPC_STORE_U32(r25.u32 + 20, r30.u32);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x82752ebc
	if (cr6.lt) goto loc_82752EBC;
	// li r24,0
	r24.s64 = 0;
	// li r21,0
	r21.s64 = 0;
	// addi r31,r1,112
	r31.s64 = ctx.r1.s64 + 112;
	// addi r22,r1,96
	r22.s64 = ctx.r1.s64 + 96;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_82752DA0:
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// li r29,0
	r29.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x82752DB4;
	sub_8244D150(ctx, base);
	// addi r30,r1,88
	r30.s64 = ctx.r1.s64 + 88;
	// mr r23,r31
	r23.u64 = r31.u64;
	// li r28,2
	r28.s64 = 2;
loc_82752DC0:
	// lwz r3,0(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752df0
	if (cr6.eq) goto loc_82752DF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
loc_82752DF0:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// bne 0x82752dc0
	if (!cr0.eq) goto loc_82752DC0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82752e80
	if (cr6.eq) goto loc_82752E80;
	// addi r7,r27,4
	ctx.r7.s64 = r27.s64 + 4;
	// lwz r4,0(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8274f8a0
	ctx.lr = 0x82752E1C;
	sub_8274F8A0(ctx, base);
	// mr. r26,r3
	r26.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x82752e94
	if (cr0.lt) goto loc_82752E94;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// li r30,0
	r30.s64 = 0;
	// li r29,0
	r29.s64 = 0;
loc_82752E34:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82752e68
	if (cr6.eq) goto loc_82752E68;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82752E5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r26,r3
	r26.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x82752e94
	if (cr0.lt) goto loc_82752E94;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82752E68:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r29,2
	cr6.compare<uint32_t>(r29.u32, 2, xer);
	// blt cr6,0x82752e34
	if (cr6.lt) goto loc_82752E34;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x82752e94
	if (cr6.lt) goto loc_82752E94;
loc_82752E80:
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
	// mr r31,r23
	r31.u64 = r23.u64;
	// cmplwi cr6,r21,3
	cr6.compare<uint32_t>(r21.u32, 3, xer);
	// blt cr6,0x82752da0
	if (cr6.lt) goto loc_82752DA0;
loc_82752E94:
	// stw r24,32(r25)
	PPC_STORE_U32(r25.u32 + 32, r24.u32);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x82752ebc
	if (cr6.lt) goto loc_82752EBC;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x827521d8
	ctx.lr = 0x82752EB4;
	sub_827521D8(ctx, base);
	// mr. r26,r3
	r26.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// bge 0x82752ec8
	if (!cr0.lt) goto loc_82752EC8;
loc_82752EBC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x827526b0
	ctx.lr = 0x82752EC4;
	sub_827526B0(ctx, base);
	// li r25,0
	r25.s64 = 0;
loc_82752EC8:
	// stw r25,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r25.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_82752ED8"))) PPC_WEAK_FUNC(sub_82752ED8);
PPC_FUNC_IMPL(__imp__sub_82752ED8) {
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
	ctx.lr = 0x82752EE0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82752efc
	if (!cr6.eq) goto loc_82752EFC;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752EFC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82752f10
	if (!cr6.eq) goto loc_82752F10;
	// li r3,6130
	ctx.r3.s64 = 6130;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F10:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82752f24
	if (!cr6.eq) goto loc_82752F24;
	// li r3,6125
	ctx.r3.s64 = 6125;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F24:
	// lhz r10,14(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82752f3c
	if (cr6.lt) goto loc_82752F3C;
	// li r3,6145
	ctx.r3.s64 = 6145;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F3C:
	// lhz r10,18(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// addi r29,r31,18
	r29.s64 = r31.s64 + 18;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82752f54
	if (cr6.lt) goto loc_82752F54;
	// li r3,6150
	ctx.r3.s64 = 6150;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F54:
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// ble cr6,0x82752f68
	if (!cr6.gt) goto loc_82752F68;
	// li r3,6135
	ctx.r3.s64 = 6135;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F68:
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// ble cr6,0x82752f80
	if (!cr6.gt) goto loc_82752F80;
	// li r3,6140
	ctx.r3.s64 = 6140;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752F80:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82752fe8
	if (cr6.eq) goto loc_82752FE8;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,64206
	cr6.compare<uint32_t>(r11.u32, 64206, xer);
	// bne cr6,0x82752fe8
	if (!cr6.eq) goto loc_82752FE8;
	// lbz r11,12(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 12);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x82752fa8
	if (cr6.eq) goto loc_82752FA8;
	// li r3,6110
	ctx.r3.s64 = 6110;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752FA8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x82755e70
	ctx.lr = 0x82752FB4;
	sub_82755E70(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x827556f8
	ctx.lr = 0x82752FC4;
	sub_827556F8(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lhz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82755688
	ctx.lr = 0x82752FE0;
	sub_82755688(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82752fec
	goto loc_82752FEC;
loc_82752FE8:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_82752FEC:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82752FF4"))) PPC_WEAK_FUNC(sub_82752FF4);
PPC_FUNC_IMPL(__imp__sub_82752FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82752FF8"))) PPC_WEAK_FUNC(sub_82752FF8);
PPC_FUNC_IMPL(__imp__sub_82752FF8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82458098
	ctx.lr = 0x8275301C;
	sub_82458098(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82752ed8
	ctx.lr = 0x82753028;
	sub_82752ED8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82458098
	ctx.lr = 0x82753034;
	sub_82458098(ctx, base);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r11,r11,-22784
	r11.s64 = r11.s64 + -22784;
	// ld r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// subf r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpd cr6,r10,r9
	cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, xer);
	// bge cr6,0x82753058
	if (!cr6.lt) goto loc_82753058;
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
loc_82753058:
	// ld r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 16);
	// cmpd cr6,r10,r9
	cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, xer);
	// ble cr6,0x82753068
	if (!cr6.gt) goto loc_82753068;
	// std r10,16(r11)
	PPC_STORE_U64(r11.u32 + 16, ctx.r10.u64);
loc_82753068:
	// ld r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// std r10,24(r11)
	PPC_STORE_U64(r11.u32 + 24, ctx.r10.u64);
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8275309C"))) PPC_WEAK_FUNC(sub_8275309C);
PPC_FUNC_IMPL(__imp__sub_8275309C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827530A0"))) PPC_WEAK_FUNC(sub_827530A0);
PPC_FUNC_IMPL(__imp__sub_827530A0) {
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
	ctx.lr = 0x827530A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827530c0
	if (!cr6.eq) goto loc_827530C0;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x82753158
	goto loc_82753158;
loc_827530C0:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82753154
	if (cr6.eq) goto loc_82753154;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,64206
	cr6.compare<uint32_t>(r11.u32, 64206, xer);
	// bne cr6,0x82753154
	if (!cr6.eq) goto loc_82753154;
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x827530ec
	if (cr6.eq) goto loc_827530EC;
	// li r3,6115
	ctx.r3.s64 = 6115;
	// b 0x82753158
	goto loc_82753158;
loc_827530EC:
	// li r29,0
	r29.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// bl 0x827558c0
	ctx.lr = 0x827530FC;
	sub_827558C0(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275311c
	if (cr6.eq) goto loc_8275311C;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753118;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
loc_8275311C:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82753138
	if (cr6.eq) goto loc_82753138;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
loc_82753138:
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r29,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r29.u32);
	// b 0x82753158
	goto loc_82753158;
loc_82753154:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_82753158:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82753160"))) PPC_WEAK_FUNC(sub_82753160);
PPC_FUNC_IMPL(__imp__sub_82753160) {
	PPC_FUNC_PROLOGUE();
	// b 0x827530a0
	sub_827530A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82753164"))) PPC_WEAK_FUNC(sub_82753164);
PPC_FUNC_IMPL(__imp__sub_82753164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82753168"))) PPC_WEAK_FUNC(sub_82753168);
PPC_FUNC_IMPL(__imp__sub_82753168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8275318c
	if (!cr6.eq) goto loc_8275318C;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x8275326c
	goto loc_8275326C;
loc_8275318C:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r11,-21256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21252(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21248(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21244(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21240);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753268
	if (cr6.eq) goto loc_82753268;
	// lwz r11,-21256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21256);
	// li r4,44
	ctx.r4.s64 = 44;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82753218
	if (!cr0.eq) goto loc_82753218;
loc_82753210:
	// li r3,6000
	ctx.r3.s64 = 6000;
	// b 0x8275326c
	goto loc_8275326C;
loc_82753218:
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stb r9,12(r11)
	PPC_STORE_U8(r11.u32 + 12, ctx.r9.u8);
	// li r8,100
	ctx.r8.s64 = 100;
	// ori r10,r10,64206
	ctx.r10.u64 = ctx.r10.u64 | 64206;
	// li r9,3000
	ctx.r9.s64 = 3000;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r4,24(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x82755790
	ctx.lr = 0x8275324C;
	sub_82755790(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82753260
	if (cr0.eq) goto loc_82753260;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827530a0
	ctx.lr = 0x8275325C;
	sub_827530A0(ctx, base);
	// b 0x82753210
	goto loc_82753210;
loc_82753260:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8275326c
	goto loc_8275326C;
loc_82753268:
	// li r3,6001
	ctx.r3.s64 = 6001;
loc_8275326C:
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

__attribute__((alias("__imp__sub_82753280"))) PPC_WEAK_FUNC(sub_82753280);
PPC_FUNC_IMPL(__imp__sub_82753280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32107
	ctx.r9.s64 = -2104164352;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,-22784
	ctx.r8.s64 = ctx.r9.s64 + -22784;
	// lis r10,15258
	ctx.r10.s64 = 999948288;
	// ori r10,r10,51712
	ctx.r10.u64 = ctx.r10.u64 | 51712;
	// std r11,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, r11.u64);
	// std r11,8(r8)
	PPC_STORE_U64(ctx.r8.u32 + 8, r11.u64);
	// std r11,16(r8)
	PPC_STORE_U64(ctx.r8.u32 + 16, r11.u64);
	// std r11,24(r8)
	PPC_STORE_U64(ctx.r8.u32 + 24, r11.u64);
	// std r11,32(r8)
	PPC_STORE_U64(ctx.r8.u32 + 32, r11.u64);
	// std r10,-22784(r9)
	PPC_STORE_U64(ctx.r9.u32 + -22784, ctx.r10.u64);
	// b 0x82753168
	sub_82753168(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827532B0"))) PPC_WEAK_FUNC(sub_827532B0);
PPC_FUNC_IMPL(__imp__sub_827532B0) {
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
	ctx.lr = 0x827532B8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827533f8
	if (cr6.eq) goto loc_827533F8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,64206
	cr6.compare<uint32_t>(ctx.r10.u32, 64206, xer);
	// bne cr6,0x827533f8
	if (!cr6.eq) goto loc_827533F8;
	// lbz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// cmplwi cr6,r10,11
	cr6.compare<uint32_t>(ctx.r10.u32, 11, xer);
	// beq cr6,0x827532ec
	if (cr6.eq) goto loc_827532EC;
	// li r3,6115
	ctx.r3.s64 = 6115;
	// b 0x827533fc
	goto loc_827533FC;
loc_827532EC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827532fc
	if (!cr6.eq) goto loc_827532FC;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x827533fc
	goto loc_827533FC;
loc_827532FC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82753310
	if (!cr6.eq) goto loc_82753310;
	// li r3,6130
	ctx.r3.s64 = 6130;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753310:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82753324
	if (!cr6.eq) goto loc_82753324;
	// li r3,6125
	ctx.r3.s64 = 6125;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753324:
	// lhz r9,14(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// addi r8,r11,14
	ctx.r8.s64 = r11.s64 + 14;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x82753340
	if (cr6.lt) goto loc_82753340;
	// li r3,6145
	ctx.r3.s64 = 6145;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753340:
	// lhz r9,18(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x82753354
	if (cr6.lt) goto loc_82753354;
	// li r3,6150
	ctx.r3.s64 = 6150;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753354:
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// ble cr6,0x8275336c
	if (!cr6.gt) goto loc_8275336C;
	// li r3,6135
	ctx.r3.s64 = 6135;
	// b 0x827533fc
	goto loc_827533FC;
loc_8275336C:
	// lbz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// ble cr6,0x82753380
	if (!cr6.gt) goto loc_82753380;
	// li r3,6140
	ctx.r3.s64 = 6140;
	// b 0x827533fc
	goto loc_827533FC;
loc_82753380:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// lhz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// addi r29,r1,160
	r29.s64 = ctx.r1.s64 + 160;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r5,r11,4
	ctx.r5.s64 = r11.s64 + 4;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// bl 0x82756270
	ctx.lr = 0x827533B0;
	sub_82756270(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827533f0
	if (cr6.eq) goto loc_827533F0;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// addi r10,r31,52
	ctx.r10.s64 = r31.s64 + 52;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// li r11,0
	r11.s64 = 0;
loc_827533C8:
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfsx f0,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	f0.f64 = double(temp.f32);
	// lfsx f13,r11,r8
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stfs f0,-48(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -48, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,48
	cr6.compare<int32_t>(r11.s32, 48, xer);
	// blt cr6,0x827533c8
	if (cr6.lt) goto loc_827533C8;
loc_827533F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827533fc
	goto loc_827533FC;
loc_827533F8:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_827533FC:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82753404"))) PPC_WEAK_FUNC(sub_82753404);
PPC_FUNC_IMPL(__imp__sub_82753404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82753408"))) PPC_WEAK_FUNC(sub_82753408);
PPC_FUNC_IMPL(__imp__sub_82753408) {
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
	ctx.lr = 0x82753410;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82458098
	ctx.lr = 0x82753428;
	sub_82458098(ctx, base);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x827532b0
	ctx.lr = 0x82753438;
	sub_827532B0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82458098
	ctx.lr = 0x82753444;
	sub_82458098(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r11,r11,-21296
	r11.s64 = r11.s64 + -21296;
	// ld r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// subf r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpd cr6,r10,r9
	cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, xer);
	// bge cr6,0x82753468
	if (!cr6.lt) goto loc_82753468;
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
loc_82753468:
	// ld r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 16);
	// cmpd cr6,r10,r9
	cr6.compare<int64_t>(ctx.r10.s64, ctx.r9.s64, xer);
	// ble cr6,0x82753478
	if (!cr6.gt) goto loc_82753478;
	// std r10,16(r11)
	PPC_STORE_U64(r11.u32 + 16, ctx.r10.u64);
loc_82753478:
	// ld r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// std r10,24(r11)
	PPC_STORE_U64(r11.u32 + 24, ctx.r10.u64);
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275349C"))) PPC_WEAK_FUNC(sub_8275349C);
PPC_FUNC_IMPL(__imp__sub_8275349C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827534A0"))) PPC_WEAK_FUNC(sub_827534A0);
PPC_FUNC_IMPL(__imp__sub_827534A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r11,92(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 92);
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827534B4"))) PPC_WEAK_FUNC(sub_827534B4);
PPC_FUNC_IMPL(__imp__sub_827534B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827534B8"))) PPC_WEAK_FUNC(sub_827534B8);
PPC_FUNC_IMPL(__imp__sub_827534B8) {
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
	ctx.lr = 0x827534C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827534d4
	if (!cr6.eq) goto loc_827534D4;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x82753568
	goto loc_82753568;
loc_827534D4:
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82753564
	if (cr6.eq) goto loc_82753564;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,64206
	cr6.compare<uint32_t>(r11.u32, 64206, xer);
	// bne cr6,0x82753564
	if (!cr6.eq) goto loc_82753564;
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,11
	cr6.compare<uint32_t>(r11.u32, 11, xer);
	// beq cr6,0x82753500
	if (cr6.eq) goto loc_82753500;
	// li r3,6115
	ctx.r3.s64 = 6115;
	// b 0x82753568
	goto loc_82753568;
loc_82753500:
	// li r29,0
	r29.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// bl 0x82756638
	ctx.lr = 0x82753510;
	sub_82756638(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82753530
	if (cr6.eq) goto loc_82753530;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275352C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
loc_82753530:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275354c
	if (cr6.eq) goto loc_8275354C;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82753548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
loc_8275354C:
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275355C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82753568
	goto loc_82753568;
loc_82753564:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_82753568:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82753570"))) PPC_WEAK_FUNC(sub_82753570);
PPC_FUNC_IMPL(__imp__sub_82753570) {
	PPC_FUNC_PROLOGUE();
	// b 0x827534b8
	sub_827534B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82753574"))) PPC_WEAK_FUNC(sub_82753574);
PPC_FUNC_IMPL(__imp__sub_82753574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82753578"))) PPC_WEAK_FUNC(sub_82753578);
PPC_FUNC_IMPL(__imp__sub_82753578) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x827535a0
	if (!cr6.eq) goto loc_827535A0;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x827536a8
	goto loc_827536A8;
loc_827535A0:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r31,0
	r31.s64 = 0;
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// lwz r11,-21256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21252(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21248(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21244(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21240);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827536a4
	if (cr6.eq) goto loc_827536A4;
	// lwz r11,-21256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21256);
	// li r4,44
	ctx.r4.s64 = 44;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275361C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8275362c
	if (!cr0.eq) goto loc_8275362C;
loc_82753624:
	// li r3,6000
	ctx.r3.s64 = 6000;
	// b 0x827536a8
	goto loc_827536A8;
loc_8275362C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// li r9,11
	ctx.r9.s64 = 11;
	// ori r10,r10,64206
	ctx.r10.u64 = ctx.r10.u64 | 64206;
	// stb r9,12(r11)
	PPC_STORE_U8(r11.u32 + 12, ctx.r9.u8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82756468
	ctx.lr = 0x8275364C;
	sub_82756468(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82753660
	if (cr0.eq) goto loc_82753660;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827534b8
	ctx.lr = 0x8275365C;
	sub_827534B8(ctx, base);
	// b 0x82753624
	goto loc_82753624;
loc_82753660:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r11,15258
	r11.s64 = 999948288;
	// addi r30,r10,-21296
	r30.s64 = ctx.r10.s64 + -21296;
	// ori r11,r11,51712
	r11.u64 = r11.u64 | 51712;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r31,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r31.u64);
	// std r31,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, r31.u64);
	// std r31,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, r31.u64);
	// std r31,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, r31.u64);
	// std r31,32(r9)
	PPC_STORE_U64(ctx.r9.u32 + 32, r31.u64);
	// std r11,-21296(r10)
	PPC_STORE_U64(ctx.r10.u32 + -21296, r11.u64);
	// bl 0x82458060
	ctx.lr = 0x82753694;
	sub_82458060(ctx, base);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r11.u32);
	// b 0x827536a8
	goto loc_827536A8;
loc_827536A4:
	// li r3,6001
	ctx.r3.s64 = 6001;
loc_827536A8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827536C0"))) PPC_WEAK_FUNC(sub_827536C0);
PPC_FUNC_IMPL(__imp__sub_827536C0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82753578
	sub_82753578(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827536C4"))) PPC_WEAK_FUNC(sub_827536C4);
PPC_FUNC_IMPL(__imp__sub_827536C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827536C8"))) PPC_WEAK_FUNC(sub_827536C8);
PPC_FUNC_IMPL(__imp__sub_827536C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21256(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21256, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827536DC"))) PPC_WEAK_FUNC(sub_827536DC);
PPC_FUNC_IMPL(__imp__sub_827536DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827536E0"))) PPC_WEAK_FUNC(sub_827536E0);
PPC_FUNC_IMPL(__imp__sub_827536E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21252(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21252, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827536F4"))) PPC_WEAK_FUNC(sub_827536F4);
PPC_FUNC_IMPL(__imp__sub_827536F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827536F8"))) PPC_WEAK_FUNC(sub_827536F8);
PPC_FUNC_IMPL(__imp__sub_827536F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21248(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21248, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275370C"))) PPC_WEAK_FUNC(sub_8275370C);
PPC_FUNC_IMPL(__imp__sub_8275370C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82753710"))) PPC_WEAK_FUNC(sub_82753710);
PPC_FUNC_IMPL(__imp__sub_82753710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21244(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21244, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82753724"))) PPC_WEAK_FUNC(sub_82753724);
PPC_FUNC_IMPL(__imp__sub_82753724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82753728"))) PPC_WEAK_FUNC(sub_82753728);
PPC_FUNC_IMPL(__imp__sub_82753728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21240(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21240, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275373C"))) PPC_WEAK_FUNC(sub_8275373C);
PPC_FUNC_IMPL(__imp__sub_8275373C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82753740"))) PPC_WEAK_FUNC(sub_82753740);
PPC_FUNC_IMPL(__imp__sub_82753740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-21236(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21236, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82753754"))) PPC_WEAK_FUNC(sub_82753754);
PPC_FUNC_IMPL(__imp__sub_82753754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82753758"))) PPC_WEAK_FUNC(sub_82753758);
PPC_FUNC_IMPL(__imp__sub_82753758) {
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82753760;
	// lhz r11,8(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 8);
	// addi r21,r6,8
	r21.s64 = ctx.r6.s64 + 8;
	// lhz r9,26(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 26);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// srawi r8,r10,15
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 15;
	// srawi r10,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// clrlwi r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82753790
	if (cr6.eq) goto loc_82753790;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_82753790:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x827537a8
	if (!cr6.eq) goto loc_827537A8;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x827537b0
	goto loc_827537B0;
loc_827537A8:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_827537B0:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x827537ec
	if (cr6.gt) goto loc_827537EC;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x827537f8
	goto loc_827537F8;
loc_827537EC:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_827537F8:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,10(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 10);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r31,28(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 28);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r27,r11
	r27.s64 = r11.s16;
	// extsh r11,r31
	r11.s64 = r31.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x82753840
	if (cr6.eq) goto loc_82753840;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_82753840:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x82753858
	if (!cr6.eq) goto loc_82753858;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753860
	goto loc_82753860;
loc_82753858:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753860:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x8275389c
	if (cr6.gt) goto loc_8275389C;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x827538a8
	goto loc_827538A8;
loc_8275389C:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_827538A8:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,12(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 12);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r31,30(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 30);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r28,r11
	r28.s64 = r11.s16;
	// extsh r11,r31
	r11.s64 = r31.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x827538f0
	if (cr6.eq) goto loc_827538F0;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_827538F0:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x82753908
	if (!cr6.eq) goto loc_82753908;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753910
	goto loc_82753910;
loc_82753908:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753910:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x8275394c
	if (cr6.gt) goto loc_8275394C;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753958
	goto loc_82753958;
loc_8275394C:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753958:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,14(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 14);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r31,32(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r29,r11
	r29.s64 = r11.s16;
	// extsh r11,r31
	r11.s64 = r31.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x827539a0
	if (cr6.eq) goto loc_827539A0;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_827539A0:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x827539b8
	if (!cr6.eq) goto loc_827539B8;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x827539c0
	goto loc_827539C0;
loc_827539B8:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_827539C0:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x827539fc
	if (cr6.gt) goto loc_827539FC;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753a08
	goto loc_82753A08;
loc_827539FC:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753A08:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,16(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 16);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r31,34(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 34);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r30,r11
	r30.s64 = r11.s16;
	// extsh r11,r31
	r11.s64 = r31.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x82753a50
	if (cr6.eq) goto loc_82753A50;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_82753A50:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r9,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x82753a68
	if (!cr6.eq) goto loc_82753A68;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753a70
	goto loc_82753A70;
loc_82753A68:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753A70:
	// srawi r7,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r7.s64 = r11.s32 >> 10;
	// clrlwi r31,r11,26
	r31.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r31,r10
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r7,r7,31
	ctx.r7.u64 = ctx.r7.u32 & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x82753aac
	if (cr6.gt) goto loc_82753AAC;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753ab8
	goto loc_82753AB8;
loc_82753AAC:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753AB8:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,18(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 18);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// lhz r26,36(r6)
	r26.u64 = PPC_LOAD_U16(ctx.r6.u32 + 36);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// and r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 & r11.u64;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// or r11,r10,r8
	r11.u64 = ctx.r10.u64 | ctx.r8.u64;
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// extsh r31,r11
	r31.s64 = r11.s16;
	// extsh r11,r26
	r11.s64 = r26.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// srawi r10,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// beq cr6,0x82753b00
	if (cr6.eq) goto loc_82753B00;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r10,r9,19
	ctx.r10.u64 = ctx.r9.u32 & 0x1FFF;
loc_82753B00:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r7,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r7.s64 = 32 - ctx.r9.s64;
	// bne cr6,0x82753b18
	if (!cr6.eq) goto loc_82753B18;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753b20
	goto loc_82753B20;
loc_82753B18:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r7
	temp.u32 = ctx.r7.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753B20:
	// srawi r26,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	r26.s64 = r11.s32 >> 10;
	// clrlwi r9,r11,26
	ctx.r9.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r26,r26,31
	r26.u64 = r26.u32 & 0x1;
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// xor r11,r26,r8
	r11.u64 = r26.u64 ^ ctx.r8.u64;
	// rlwinm r9,r9,3,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r10,26
	cr6.compare<int32_t>(ctx.r10.s32, 26, xer);
	// bgt cr6,0x82753b5c
	if (cr6.gt) goto loc_82753B5C;
	// subfic r10,r10,26
	xer.ca = ctx.r10.u32 <= 26;
	ctx.r10.s64 = 26 - ctx.r10.s64;
	// sraw r10,r9,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r9.s32 < 0) & (((ctx.r9.s32 >> temp.u32) << temp.u32) != ctx.r9.s32);
	ctx.r10.s64 = ctx.r9.s32 >> temp.u32;
	// b 0x82753b68
	goto loc_82753B68;
loc_82753B5C:
	// addi r10,r10,-26
	ctx.r10.s64 = ctx.r10.s64 + -26;
	// slw r9,r9,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// clrlwi r10,r9,17
	ctx.r10.u64 = ctx.r9.u32 & 0x7FFF;
loc_82753B68:
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// lhz r26,0(r6)
	r26.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = -ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r31
	ctx.r9.s64 = r31.s16;
	// andc r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 & ~r11.u64;
	// and r11,r8,r11
	r11.u64 = ctx.r8.u64 & r11.u64;
	// extsh r8,r30
	ctx.r8.s64 = r30.s16;
	// or r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 | r11.u64;
	// extsh r7,r29
	ctx.r7.s64 = r29.s16;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r31,r28
	r31.s64 = r28.s16;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// extsh r11,r26
	r11.s64 = r26.s16;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
	// lhz r27,42(r6)
	r27.u64 = PPC_LOAD_U16(ctx.r6.u32 + 42);
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// srawi r9,r11,15
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFF) != 0);
	ctx.r9.s64 = r11.s32 >> 15;
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// clrlwi r29,r9,31
	r29.u64 = ctx.r9.u32 & 0x1;
	// extsh r28,r27
	r28.s64 = r27.s16;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// extsh r31,r8
	r31.s64 = ctx.r8.s16;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// beq cr6,0x82753bd8
	if (cr6.eq) goto loc_82753BD8;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// clrlwi r11,r10,19
	r11.u64 = ctx.r10.u32 & 0x1FFF;
loc_82753BD8:
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subfic r9,r10,32
	xer.ca = ctx.r10.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r10.s64;
	// bne cr6,0x82753bf0
	if (!cr6.eq) goto loc_82753BF0;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753bf8
	goto loc_82753BF8;
loc_82753BF0:
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r11,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r11.s32 < 0) & (((r11.s32 >> temp.u32) << temp.u32) != r11.s32);
	ctx.r10.s64 = r11.s32 >> temp.u32;
loc_82753BF8:
	// srawi r8,r28,10
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x3FF) != 0);
	ctx.r8.s64 = r28.s32 >> 10;
	// srawi r7,r28,6
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x3F) != 0);
	ctx.r7.s64 = r28.s32 >> 6;
	// clrlwi r30,r28,26
	r30.u64 = r28.u32 & 0x3F;
	// clrlwi r11,r7,28
	r11.u64 = ctx.r7.u32 & 0xF;
	// mullw r10,r30,r10
	ctx.r10.s64 = int64_t(r30.s32) * int64_t(ctx.r10.s32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// xor r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 ^ r29.u64;
	// rlwinm r10,r8,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x82753c34
	if (cr6.gt) goto loc_82753C34;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753c40
	goto loc_82753C40;
loc_82753C34:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753C40:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r9,2(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 2);
	// neg r8,r10
	ctx.r8.s64 = -ctx.r10.s64;
	// lhz r30,44(r6)
	r30.u64 = PPC_LOAD_U16(ctx.r6.u32 + 44);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// andc r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 & ~r11.u64;
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// and r11,r8,r11
	r11.u64 = ctx.r8.u64 & r11.u64;
	// srawi r9,r10,15
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 15;
	// or r8,r11,r7
	ctx.r8.u64 = r11.u64 | ctx.r7.u64;
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// extsh r11,r30
	r11.s64 = r30.s16;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// srawi r10,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// beq cr6,0x82753c88
	if (cr6.eq) goto loc_82753C88;
	// neg r8,r10
	ctx.r8.s64 = -ctx.r10.s64;
	// clrlwi r10,r8,19
	ctx.r10.u64 = ctx.r8.u32 & 0x1FFF;
loc_82753C88:
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subfic r8,r8,32
	xer.ca = ctx.r8.u32 <= 32;
	ctx.r8.s64 = 32 - ctx.r8.s64;
	// bne cr6,0x82753ca0
	if (!cr6.eq) goto loc_82753CA0;
	// li r10,32
	ctx.r10.s64 = 32;
	// b 0x82753ca8
	goto loc_82753CA8;
loc_82753CA0:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// sraw r10,r10,r8
	temp.u32 = ctx.r8.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
loc_82753CA8:
	// srawi r30,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	r30.s64 = r11.s32 >> 10;
	// clrlwi r29,r11,26
	r29.u64 = r11.u32 & 0x3F;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// mullw r10,r29,r10
	ctx.r10.s64 = int64_t(r29.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// clrlwi r30,r30,31
	r30.u64 = r30.u32 & 0x1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// xor r9,r30,r9
	ctx.r9.u64 = r30.u64 ^ ctx.r9.u64;
	// rlwinm r10,r10,3,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFF80;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// bgt cr6,0x82753ce4
	if (cr6.gt) goto loc_82753CE4;
	// subfic r11,r11,26
	xer.ca = r11.u32 <= 26;
	r11.s64 = 26 - r11.s64;
	// sraw r10,r10,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753cf0
	goto loc_82753CF0;
loc_82753CE4:
	// addi r11,r11,-26
	r11.s64 = r11.s64 + -26;
	// slw r10,r10,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
loc_82753CF0:
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// lhz r8,4(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// neg r30,r10
	r30.s64 = -ctx.r10.s64;
	// sth r27,44(r6)
	PPC_STORE_U16(ctx.r6.u32 + 44, r27.u16);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// andc r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 & ~r11.u64;
	// and r11,r30,r11
	r11.u64 = r30.u64 & r11.u64;
	// or r11,r7,r11
	r11.u64 = ctx.r7.u64 | r11.u64;
	// extsh r7,r31
	ctx.r7.s64 = r31.s16;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// srawi r24,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r24.s64 = ctx.r7.s32 >> 1;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r9,256
	cr6.compare<int32_t>(ctx.r9.s32, 256, xer);
	// srawi r25,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	r25.s64 = ctx.r10.s32 >> 1;
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x82753d40
	if (cr6.lt) goto loc_82753D40;
	// li r11,0
	r11.s64 = 0;
loc_82753D40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82753d58
	if (cr6.eq) goto loc_82753D58;
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// b 0x82753d5c
	goto loc_82753D5C;
loc_82753D58:
	// li r9,64
	ctx.r9.s64 = 64;
loc_82753D5C:
	// lhz r27,50(r6)
	r27.u64 = PPC_LOAD_U16(ctx.r6.u32 + 50);
	// lhz r8,52(r6)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r6.u32 + 52);
	// subf r7,r27,r8
	ctx.r7.s64 = ctx.r8.s64 - r27.s64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82753d80
	if (!cr6.lt) goto loc_82753D80;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
loc_82753D80:
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// srawi r11,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	r11.s64 = ctx.r8.s32 >> 6;
	// bge cr6,0x82753da4
	if (!cr6.lt) goto loc_82753DA4;
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// extsh r30,r9
	r30.s64 = ctx.r9.s16;
	// b 0x82753dac
	goto loc_82753DAC;
loc_82753DA4:
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// extsh r30,r11
	r30.s64 = r11.s16;
loc_82753DAC:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82753dbc
	if (cr6.eq) goto loc_82753DBC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// b 0x8275403c
	goto loc_8275403C;
loc_82753DBC:
	// subf r9,r25,r4
	ctx.r9.s64 = ctx.r4.s64 - r25.s64;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x82753ddc
	if (!cr6.lt) goto loc_82753DDC;
	// neg r11,r4
	r11.s64 = -ctx.r4.s64;
	// extsh r7,r11
	ctx.r7.s64 = r11.s16;
	// b 0x82753de0
	goto loc_82753DE0;
loc_82753DDC:
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_82753DE0:
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// ori r11,r8,1
	r11.u64 = ctx.r8.u64 | 1;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// rlwinm r11,r10,17,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0x1;
	// rlwinm r9,r10,18,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 18) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e08
	if (cr6.eq) goto loc_82753E08;
	// li r11,15
	r11.s64 = 15;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E08:
	// rlwinm r9,r10,19,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e20
	if (cr6.eq) goto loc_82753E20;
	// li r11,14
	r11.s64 = 14;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E20:
	// rlwinm r9,r10,20,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e38
	if (cr6.eq) goto loc_82753E38;
	// li r11,13
	r11.s64 = 13;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E38:
	// rlwinm r9,r10,21,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e50
	if (cr6.eq) goto loc_82753E50;
	// li r11,12
	r11.s64 = 12;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E50:
	// rlwinm r9,r10,22,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e68
	if (cr6.eq) goto loc_82753E68;
	// li r11,11
	r11.s64 = 11;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E68:
	// rlwinm r9,r10,23,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e80
	if (cr6.eq) goto loc_82753E80;
	// li r11,10
	r11.s64 = 10;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E80:
	// rlwinm r9,r10,24,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753e98
	if (cr6.eq) goto loc_82753E98;
	// li r11,9
	r11.s64 = 9;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753E98:
	// rlwinm r9,r10,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753eb0
	if (cr6.eq) goto loc_82753EB0;
	// li r11,8
	r11.s64 = 8;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753EB0:
	// rlwinm r9,r10,26,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753ec8
	if (cr6.eq) goto loc_82753EC8;
	// li r11,7
	r11.s64 = 7;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753EC8:
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753ee0
	if (cr6.eq) goto loc_82753EE0;
	// li r11,6
	r11.s64 = 6;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753EE0:
	// rlwinm r9,r10,28,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753ef8
	if (cr6.eq) goto loc_82753EF8;
	// li r11,5
	r11.s64 = 5;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753EF8:
	// rlwinm r9,r10,29,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753f10
	if (cr6.eq) goto loc_82753F10;
	// li r11,4
	r11.s64 = 4;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753F10:
	// rlwinm r9,r10,30,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753f28
	if (cr6.eq) goto loc_82753F28;
	// li r11,3
	r11.s64 = 3;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753F28:
	// rlwinm r9,r10,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	// xor r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82753f40
	if (cr6.eq) goto loc_82753F40;
	// li r11,2
	r11.s64 = 2;
	// b 0x82753f54
	goto loc_82753F54;
loc_82753F40:
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r10,1
	r11.u64 = ctx.r10.u64 ^ 1;
loc_82753F54:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// subfic r11,r9,7
	xer.ca = ctx.r9.u32 <= 7;
	r11.s64 = 7 - ctx.r9.s64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82753f80
	if (!cr6.lt) goto loc_82753F80;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// sraw r11,r10,r8
	temp.u32 = ctx.r8.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	r11.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82753f88
	goto loc_82753F88;
loc_82753F80:
	// slw r11,r8,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (r11.u8 & 0x3F));
	// extsh r11,r11
	r11.s64 = r11.s16;
loc_82753F88:
	// rlwinm r10,r9,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// extsh r9,r30
	ctx.r9.s64 = r30.s16;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// srawi r7,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// subf r11,r7,r8
	r11.s64 = ctx.r8.s64 - ctx.r7.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-124
	cr6.compare<int32_t>(r11.s32, -124, xer);
	// bge cr6,0x82753fb8
	if (!cr6.lt) goto loc_82753FB8;
	// li r11,15
	r11.s64 = 15;
	// b 0x82754020
	goto loc_82754020;
loc_82753FB8:
	// cmpwi cr6,r11,80
	cr6.compare<int32_t>(r11.s32, 80, xer);
	// blt cr6,0x8275401c
	if (cr6.lt) goto loc_8275401C;
	// cmpwi cr6,r11,178
	cr6.compare<int32_t>(r11.s32, 178, xer);
	// bge cr6,0x82753fd0
	if (!cr6.lt) goto loc_82753FD0;
	// li r11,2
	r11.s64 = 2;
	// b 0x82754020
	goto loc_82754020;
loc_82753FD0:
	// cmpwi cr6,r11,246
	cr6.compare<int32_t>(r11.s32, 246, xer);
	// bge cr6,0x82753fe0
	if (!cr6.lt) goto loc_82753FE0;
	// li r11,3
	r11.s64 = 3;
	// b 0x82754020
	goto loc_82754020;
loc_82753FE0:
	// cmpwi cr6,r11,300
	cr6.compare<int32_t>(r11.s32, 300, xer);
	// bge cr6,0x82753ff0
	if (!cr6.lt) goto loc_82753FF0;
	// li r11,4
	r11.s64 = 4;
	// b 0x82754020
	goto loc_82754020;
loc_82753FF0:
	// cmpwi cr6,r11,349
	cr6.compare<int32_t>(r11.s32, 349, xer);
	// bge cr6,0x82754000
	if (!cr6.lt) goto loc_82754000;
	// li r11,5
	r11.s64 = 5;
	// b 0x82754020
	goto loc_82754020;
loc_82754000:
	// cmpwi cr6,r11,400
	cr6.compare<int32_t>(r11.s32, 400, xer);
	// bge cr6,0x82754010
	if (!cr6.lt) goto loc_82754010;
	// li r11,6
	r11.s64 = 6;
	// b 0x82754020
	goto loc_82754020;
loc_82754010:
	// cmpwi cr6,r11,2048
	cr6.compare<int32_t>(r11.s32, 2048, xer);
	// li r11,7
	r11.s64 = 7;
	// blt cr6,0x82754020
	if (cr6.lt) goto loc_82754020;
loc_8275401C:
	// li r11,1
	r11.s64 = 1;
loc_82754020:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x8275403c
	if (!cr6.lt) goto loc_8275403C;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,15
	cr6.compare<int32_t>(ctx.r10.s32, 15, xer);
	// beq cr6,0x8275403c
	if (cr6.eq) goto loc_8275403C;
	// not r11,r10
	r11.u64 = ~ctx.r10.u64;
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
loc_8275403C:
	// extsh r28,r11
	r28.s64 = r11.s16;
	// srawi. r31,r28,3
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7) != 0);
	r31.s64 = r28.s32 >> 3;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82754050
	if (cr0.eq) goto loc_82754050;
	// xori r11,r28,15
	r11.u64 = r28.u64 ^ 15;
	// extsh r11,r11
	r11.s64 = r11.s16;
loc_82754050:
	// extsh r11,r11
	r11.s64 = r11.s16;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r23,r11,1,0,30
	r23.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r10,-4320
	ctx.r9.s64 = ctx.r10.s64 + -4320;
	// extsh r8,r30
	ctx.r8.s64 = r30.s16;
	// srawi r10,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 2;
	// lhzx r11,r23,r9
	r11.u64 = PPC_LOAD_U16(r23.u32 + ctx.r9.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r4,r11,0,21,24
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x780;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// srawi r11,r4,7
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7F) != 0);
	r11.s64 = ctx.r4.s32 >> 7;
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// addi r11,r11,-7
	r11.s64 = r11.s64 + -7;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827540ac
	if (!cr6.lt) goto loc_827540AC;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// sraw r11,r10,r8
	temp.u32 = ctx.r8.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	r11.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x827540b8
	goto loc_827540B8;
loc_827540AC:
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// slw r8,r10,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
loc_827540B8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// blt cr6,0x827540c8
	if (cr6.lt) goto loc_827540C8;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_827540C8:
	// extsh r11,r27
	r11.s64 = r27.s16;
	// rlwinm r9,r27,0,23,27
	ctx.r9.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x1F0;
	// srawi r11,r11,9
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FF) != 0);
	r11.s64 = r11.s32 >> 9;
	// srawi r10,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 4;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827540fc
	if (!cr6.lt) goto loc_827540FC;
	// neg r9,r11
	ctx.r9.s64 = -r11.s64;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// sraw r10,r8,r7
	temp.u32 = ctx.r7.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r10.s64 = ctx.r8.s32 >> temp.u32;
	// b 0x82754108
	goto loc_82754108;
loc_827540FC:
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// slw r9,r10,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
loc_82754108:
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// li r11,15872
	r11.s64 = 15872;
	// bgt cr6,0x82754118
	if (cr6.gt) goto loc_82754118;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82754118:
	// extsh r11,r11
	r11.s64 = r11.s16;
	// extsh r29,r4
	r29.s64 = ctx.r4.s16;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// ble cr6,0x82754148
	if (!cr6.gt) goto loc_82754148;
	// lhz r11,46(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 46);
	// li r26,-1
	r26.s64 = -1;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8275414c
	if (cr6.eq) goto loc_8275414C;
loc_82754148:
	// li r26,0
	r26.s64 = 0;
loc_8275414C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// extsh r22,r30
	r22.s64 = r30.s16;
	// addi r10,r11,-4272
	ctx.r10.s64 = r11.s64 + -4272;
	// lhzx r9,r23,r10
	ctx.r9.u64 = PPC_LOAD_U16(r23.u32 + ctx.r10.u32);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// rlwinm r7,r8,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r22,r7
	r11.s64 = ctx.r7.s64 - r22.s64;
	// srawi r11,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	r11.s64 = r11.s32 >> 5;
	// add r10,r11,r22
	ctx.r10.u64 = r11.u64 + r22.u64;
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmpwi cr6,r10,544
	cr6.compare<int32_t>(ctx.r10.s32, 544, xer);
	// bge cr6,0x82754188
	if (!cr6.lt) goto loc_82754188;
	// li r11,544
	r11.s64 = 544;
	// b 0x82754194
	goto loc_82754194;
loc_82754188:
	// cmpwi cr6,r10,5120
	cr6.compare<int32_t>(ctx.r10.s32, 5120, xer);
	// blt cr6,0x82754194
	if (cr6.lt) goto loc_82754194;
	// li r11,5120
	r11.s64 = 5120;
loc_82754194:
	// lhz r10,48(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 48);
	// extsh r9,r27
	ctx.r9.s64 = r27.s16;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// sth r11,52(r6)
	PPC_STORE_U16(ctx.r6.u32 + 52, r11.u16);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r11,r4,17,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 17) & 0x1;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r30,r29,18,31,31
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 18) & 0x1;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
	// xor r30,r30,r11
	r30.u64 = r30.u64 ^ r11.u64;
	// srawi r8,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 6;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srawi r7,r10,6
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3F) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 6;
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// sth r7,50(r6)
	PPC_STORE_U16(ctx.r6.u32 + 50, ctx.r7.u16);
	// sth r10,48(r6)
	PPC_STORE_U16(ctx.r6.u32 + 48, ctx.r10.u16);
	// beq cr6,0x827541f4
	if (cr6.eq) goto loc_827541F4;
	// li r11,15
	r11.s64 = 15;
	// b 0x82754340
	goto loc_82754340;
loc_827541F4:
	// rlwinm r10,r29,19,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 19) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275420c
	if (cr6.eq) goto loc_8275420C;
	// li r11,14
	r11.s64 = 14;
	// b 0x82754340
	goto loc_82754340;
loc_8275420C:
	// rlwinm r10,r29,20,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 20) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82754224
	if (cr6.eq) goto loc_82754224;
	// li r11,13
	r11.s64 = 13;
	// b 0x82754340
	goto loc_82754340;
loc_82754224:
	// rlwinm r10,r29,21,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 21) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275423c
	if (cr6.eq) goto loc_8275423C;
	// li r11,12
	r11.s64 = 12;
	// b 0x82754340
	goto loc_82754340;
loc_8275423C:
	// rlwinm r10,r29,22,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 22) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82754254
	if (cr6.eq) goto loc_82754254;
	// li r11,11
	r11.s64 = 11;
	// b 0x82754340
	goto loc_82754340;
loc_82754254:
	// rlwinm r10,r29,23,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 23) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275426c
	if (cr6.eq) goto loc_8275426C;
	// li r11,10
	r11.s64 = 10;
	// b 0x82754340
	goto loc_82754340;
loc_8275426C:
	// rlwinm r10,r29,24,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82754284
	if (cr6.eq) goto loc_82754284;
	// li r11,9
	r11.s64 = 9;
	// b 0x82754340
	goto loc_82754340;
loc_82754284:
	// rlwinm r10,r29,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 25) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275429c
	if (cr6.eq) goto loc_8275429C;
	// li r11,8
	r11.s64 = 8;
	// b 0x82754340
	goto loc_82754340;
loc_8275429C:
	// rlwinm r10,r29,26,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 26) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827542b4
	if (cr6.eq) goto loc_827542B4;
	// li r11,7
	r11.s64 = 7;
	// b 0x82754340
	goto loc_82754340;
loc_827542B4:
	// rlwinm r10,r29,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 27) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827542cc
	if (cr6.eq) goto loc_827542CC;
	// li r11,6
	r11.s64 = 6;
	// b 0x82754340
	goto loc_82754340;
loc_827542CC:
	// rlwinm r10,r29,28,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 28) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827542e4
	if (cr6.eq) goto loc_827542E4;
	// li r11,5
	r11.s64 = 5;
	// b 0x82754340
	goto loc_82754340;
loc_827542E4:
	// rlwinm r10,r29,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 29) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827542fc
	if (cr6.eq) goto loc_827542FC;
	// li r11,4
	r11.s64 = 4;
	// b 0x82754340
	goto loc_82754340;
loc_827542FC:
	// rlwinm r10,r29,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 30) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82754314
	if (cr6.eq) goto loc_82754314;
	// li r11,3
	r11.s64 = 3;
	// b 0x82754340
	goto loc_82754340;
loc_82754314:
	// rlwinm r10,r29,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 31) & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275432c
	if (cr6.eq) goto loc_8275432C;
	// li r11,2
	r11.s64 = 2;
	// b 0x82754340
	goto loc_82754340;
loc_8275432C:
	// clrlwi r10,r29,31
	ctx.r10.u64 = r29.u32 & 0x1;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
loc_82754340:
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// subfic r11,r8,6
	xer.ca = ctx.r8.u32 <= 6;
	r11.s64 = 6 - ctx.r8.s64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82754368
	if (!cr6.lt) goto loc_82754368;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// sraw r11,r10,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	r11.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x82754370
	goto loc_82754370;
loc_82754368:
	// slw r11,r29,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r29.u32 << (r11.u8 & 0x3F));
	// extsh r11,r11
	r11.s64 = r11.s16;
loc_82754370:
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// beq cr6,0x82754398
	if (cr6.eq) goto loc_82754398;
	// subf r7,r29,r24
	ctx.r7.s64 = r24.s64 - r29.s64;
	// subf r4,r29,r25
	ctx.r4.s64 = r25.s64 - r29.s64;
	// li r31,-1024
	r31.s64 = -1024;
	// extsh r27,r7
	r27.s64 = ctx.r7.s16;
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// b 0x827543ac
	goto loc_827543AC;
loc_82754398:
	// add r10,r24,r29
	ctx.r10.u64 = r24.u64 + r29.u64;
	// add r7,r25,r29
	ctx.r7.u64 = r25.u64 + r29.u64;
	// li r31,0
	r31.s64 = 0;
	// extsh r27,r10
	r27.s64 = ctx.r10.s16;
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
loc_827543AC:
	// extsh r30,r4
	r30.s64 = ctx.r4.s16;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// addi r11,r30,-8191
	r11.s64 = r30.s64 + -8191;
	// xori r10,r3,1
	ctx.r10.u64 = ctx.r3.u64 ^ 1;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// rlwinm r8,r8,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// and r3,r11,r30
	ctx.r3.u64 = r11.u64 & r30.u64;
	// clrlwi r11,r9,19
	r11.u64 = ctx.r9.u32 & 0x1FFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// or r9,r11,r3
	ctx.r9.u64 = r11.u64 | ctx.r3.u64;
	// extsh r31,r31
	r31.s64 = r31.s16;
	// addi r3,r9,8192
	ctx.r3.s64 = ctx.r9.s64 + 8192;
	// andc r25,r28,r10
	r25.u64 = r28.u64 & ~ctx.r10.u64;
	// srawi r11,r3,16
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	r11.s64 = ctx.r3.s32 >> 16;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// rlwinm r3,r11,0,0,18
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFE000;
	// andc r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 & ~r11.u64;
	// add r11,r8,r7
	r11.u64 = ctx.r8.u64 + ctx.r7.u64;
	// or r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 | ctx.r3.u64;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// and r3,r8,r10
	ctx.r3.u64 = ctx.r8.u64 & ctx.r10.u64;
	// extsh r28,r7
	r28.s64 = ctx.r7.s16;
	// or r11,r3,r25
	r11.u64 = ctx.r3.u64 | r25.u64;
	// sth r11,0(r5)
	PPC_STORE_U16(ctx.r5.u32 + 0, r11.u16);
	// bge cr6,0x8275441c
	if (!cr6.lt) goto loc_8275441C;
	// neg r11,r30
	r11.s64 = -r30.s64;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
loc_8275441C:
	// rlwinm r11,r4,17,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 17) & 0x1;
	// rlwinm r9,r4,18,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 18) & 0x1;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275443c
	if (cr6.eq) goto loc_8275443C;
	// li r11,15
	r11.s64 = 15;
	// b 0x82754588
	goto loc_82754588;
loc_8275443C:
	// rlwinm r9,r10,19,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754454
	if (cr6.eq) goto loc_82754454;
	// li r11,14
	r11.s64 = 14;
	// b 0x82754588
	goto loc_82754588;
loc_82754454:
	// rlwinm r9,r10,20,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275446c
	if (cr6.eq) goto loc_8275446C;
	// li r11,13
	r11.s64 = 13;
	// b 0x82754588
	goto loc_82754588;
loc_8275446C:
	// rlwinm r9,r10,21,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754484
	if (cr6.eq) goto loc_82754484;
	// li r11,12
	r11.s64 = 12;
	// b 0x82754588
	goto loc_82754588;
loc_82754484:
	// rlwinm r9,r10,22,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275449c
	if (cr6.eq) goto loc_8275449C;
	// li r11,11
	r11.s64 = 11;
	// b 0x82754588
	goto loc_82754588;
loc_8275449C:
	// rlwinm r9,r10,23,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827544b4
	if (cr6.eq) goto loc_827544B4;
	// li r11,10
	r11.s64 = 10;
	// b 0x82754588
	goto loc_82754588;
loc_827544B4:
	// rlwinm r9,r10,24,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827544cc
	if (cr6.eq) goto loc_827544CC;
	// li r11,9
	r11.s64 = 9;
	// b 0x82754588
	goto loc_82754588;
loc_827544CC:
	// rlwinm r9,r10,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827544e4
	if (cr6.eq) goto loc_827544E4;
	// li r11,8
	r11.s64 = 8;
	// b 0x82754588
	goto loc_82754588;
loc_827544E4:
	// rlwinm r9,r10,26,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827544fc
	if (cr6.eq) goto loc_827544FC;
	// li r11,7
	r11.s64 = 7;
	// b 0x82754588
	goto loc_82754588;
loc_827544FC:
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754514
	if (cr6.eq) goto loc_82754514;
	// li r11,6
	r11.s64 = 6;
	// b 0x82754588
	goto loc_82754588;
loc_82754514:
	// rlwinm r9,r10,28,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275452c
	if (cr6.eq) goto loc_8275452C;
	// li r11,5
	r11.s64 = 5;
	// b 0x82754588
	goto loc_82754588;
loc_8275452C:
	// rlwinm r9,r10,29,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754544
	if (cr6.eq) goto loc_82754544;
	// li r11,4
	r11.s64 = 4;
	// b 0x82754588
	goto loc_82754588;
loc_82754544:
	// rlwinm r9,r10,30,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8275455c
	if (cr6.eq) goto loc_8275455C;
	// li r11,3
	r11.s64 = 3;
	// b 0x82754588
	goto loc_82754588;
loc_8275455C:
	// rlwinm r9,r10,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754574
	if (cr6.eq) goto loc_82754574;
	// li r11,2
	r11.s64 = 2;
	// b 0x82754588
	goto loc_82754588;
loc_82754574:
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// xor r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 ^ r11.u64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
loc_82754588:
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// subfic r11,r9,6
	xer.ca = ctx.r9.u32 <= 6;
	r11.s64 = 6 - ctx.r9.s64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827545b0
	if (!cr6.lt) goto loc_827545B0;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// sraw r11,r10,r8
	temp.u32 = ctx.r8.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	r11.s64 = ctx.r10.s32 >> temp.u32;
	// b 0x827545b8
	goto loc_827545B8;
loc_827545B0:
	// slw r11,r10,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// extsh r11,r11
	r11.s64 = r11.s16;
loc_827545B8:
	// cntlzw r10,r30
	ctx.r10.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// ori r5,r11,32
	ctx.r5.u64 = r11.u64 | 32;
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// subfic r3,r4,0
	xer.ca = ctx.r4.u32 <= 0;
	ctx.r3.s64 = 0 - ctx.r4.s64;
	// extsh r5,r26
	ctx.r5.s64 = r26.s16;
	// subfe r8,r3,r3
	temp.u8 = (~ctx.r3.u32 + ctx.r3.u32 < ~ctx.r3.u32) | (~ctx.r3.u32 + ctx.r3.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r3.u64 + ctx.r3.u64 + xer.ca;
	xer.ca = temp.u8;
	// not r3,r5
	ctx.r3.u64 = ~ctx.r5.u64;
	// rlwinm r11,r8,0,0,21
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFC00;
	// subfic r7,r29,0
	xer.ca = r29.u32 <= 0;
	ctx.r7.s64 = 0 - r29.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// subfe r4,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsh r30,r3
	r30.s64 = ctx.r3.s16;
	// sth r11,42(r6)
	PPC_STORE_U16(ctx.r6.u32 + 42, r11.u16);
	// rlwinm r8,r4,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r11,r21
	r11.u64 = r21.u64;
	// li r10,6
	ctx.r10.s64 = 6;
loc_82754610:
	// lhz r9,18(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// lhz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// xor r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 ^ r31.u64;
	// srawi r9,r4,8
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 8;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bge cr6,0x8275463c
	if (!cr6.lt) goto loc_8275463C;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// b 0x82754644
	goto loc_82754644;
loc_8275463C:
	// subf r5,r8,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r8.s64;
	// extsh r9,r5
	ctx.r9.s64 = ctx.r5.s16;
loc_82754644:
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subf r5,r9,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r9.s64;
	// and r4,r5,r3
	ctx.r4.u64 = ctx.r5.u64 & ctx.r3.u64;
	// sth r4,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r4.u16);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bne 0x82754610
	if (!cr0.eq) goto loc_82754610;
	// lhz r4,28(r6)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + 28);
	// extsh r8,r27
	ctx.r8.s64 = r27.s16;
	// lhz r5,40(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 40);
	// lhz r10,32(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 32);
	// lhz r7,38(r6)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r6.u32 + 38);
	// xor r5,r5,r27
	ctx.r5.u64 = ctx.r5.u64 ^ r27.u64;
	// lhz r11,30(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 30);
	// lhz r31,34(r6)
	r31.u64 = PPC_LOAD_U16(ctx.r6.u32 + 34);
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// lhz r29,26(r6)
	r29.u64 = PPC_LOAD_U16(ctx.r6.u32 + 26);
	// sth r4,30(r6)
	PPC_STORE_U16(ctx.r6.u32 + 30, ctx.r4.u16);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r10,34(r6)
	PPC_STORE_U16(ctx.r6.u32 + 34, ctx.r10.u16);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// sth r11,32(r6)
	PPC_STORE_U16(ctx.r6.u32 + 32, r11.u16);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// sth r31,36(r6)
	PPC_STORE_U16(ctx.r6.u32 + 36, r31.u16);
	// li r10,-4096
	ctx.r10.s64 = -4096;
	// sth r29,28(r6)
	PPC_STORE_U16(ctx.r6.u32 + 28, r29.u16);
	// sth r28,26(r6)
	PPC_STORE_U16(ctx.r6.u32 + 26, r28.u16);
	// sth r27,38(r6)
	PPC_STORE_U16(ctx.r6.u32 + 38, r27.u16);
	// sth r7,40(r6)
	PPC_STORE_U16(ctx.r6.u32 + 40, ctx.r7.u16);
	// blt cr6,0x827546c4
	if (cr6.lt) goto loc_827546C4;
	// li r10,4096
	ctx.r10.s64 = 4096;
loc_827546C4:
	// lhz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// cmpwi cr6,r11,-8191
	cr6.compare<int32_t>(r11.s32, -8191, xer);
	// li r11,-8191
	r11.s64 = -8191;
	// blt cr6,0x827546dc
	if (cr6.lt) goto loc_827546DC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_827546DC:
	// extsh r7,r11
	ctx.r7.s64 = r11.s16;
	// cmpwi cr6,r7,8191
	cr6.compare<int32_t>(ctx.r7.s32, 8191, xer);
	// blt cr6,0x827546ec
	if (cr6.lt) goto loc_827546EC;
	// li r11,8191
	r11.s64 = 8191;
loc_827546EC:
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bge cr6,0x82754704
	if (!cr6.lt) goto loc_82754704;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// b 0x8275470c
	goto loc_8275470C;
loc_82754704:
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
loc_8275470C:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x82754720
	if (!cr6.eq) goto loc_82754720;
	// li r11,0
	r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8275472c
	goto loc_8275472C;
loc_82754720:
	// extsh r11,r11
	r11.s64 = r11.s16;
	// li r9,192
	ctx.r9.s64 = 192;
	// srawi r11,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	r11.s64 = r11.s32 >> 5;
loc_8275472C:
	// lhz r10,2(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 2);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// srawi r7,r8,7
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 7;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,-12288
	cr6.compare<int32_t>(ctx.r10.s32, -12288, xer);
	// bge cr6,0x82754750
	if (!cr6.lt) goto loc_82754750;
	// li r11,-12288
	r11.s64 = -12288;
loc_82754750:
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpwi cr6,r10,12288
	cr6.compare<int32_t>(ctx.r10.s32, 12288, xer);
	// blt cr6,0x82754760
	if (cr6.lt) goto loc_82754760;
	// li r11,12288
	r11.s64 = 12288;
loc_82754760:
	// extsh r7,r11
	ctx.r7.s64 = r11.s16;
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// and r10,r7,r3
	ctx.r10.u64 = ctx.r7.u64 & ctx.r3.u64;
	// srawi r11,r11,8
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFF) != 0);
	r11.s64 = r11.s32 >> 8;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// sth r10,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, ctx.r10.u16);
	// bge cr6,0x82754788
	if (!cr6.lt) goto loc_82754788;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// b 0x82754790
	goto loc_82754790;
loc_82754788:
	// subf r9,r9,r11
	ctx.r9.s64 = r11.s64 - ctx.r9.s64;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
loc_82754790:
	// subfic r10,r7,15360
	xer.ca = ctx.r7.u32 <= 15360;
	ctx.r10.s64 = 15360 - ctx.r7.s64;
	// subf r11,r11,r4
	r11.s64 = ctx.r4.s64 - r11.s64;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// neg r10,r9
	ctx.r10.s64 = -ctx.r9.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// cmpw cr6,r5,r4
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, xer);
	// bge cr6,0x827547c0
	if (!cr6.lt) goto loc_827547C0;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_827547C0:
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827547d0
	if (!cr6.lt) goto loc_827547D0;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_827547D0:
	// and r10,r8,r3
	ctx.r10.u64 = ctx.r8.u64 & ctx.r3.u64;
	// cmpwi cr6,r7,-11776
	cr6.compare<int32_t>(ctx.r7.s32, -11776, xer);
	// sth r10,0(r6)
	PPC_STORE_U16(ctx.r6.u32 + 0, ctx.r10.u16);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x827547e8
	if (cr6.lt) goto loc_827547E8;
	// li r11,0
	r11.s64 = 0;
loc_827547E8:
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lhz r10,20(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 20);
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// lhz r11,22(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 22);
	// addi r5,r9,-4288
	ctx.r5.s64 = ctx.r9.s64 + -4288;
	// and r7,r8,r3
	ctx.r7.u64 = ctx.r8.u64 & ctx.r3.u64;
	// sth r7,46(r6)
	PPC_STORE_U16(ctx.r6.u32 + 46, ctx.r7.u16);
	// lhzx r5,r23,r5
	ctx.r5.u64 = PPC_LOAD_U16(r23.u32 + ctx.r5.u32);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// subf r9,r11,r4
	ctx.r9.s64 = ctx.r4.s64 - r11.s64;
	// rlwinm r5,r4,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// extsh r4,r9
	ctx.r4.s64 = ctx.r9.s16;
	// subf r7,r10,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r10.s64;
	// srawi r9,r4,5
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 5;
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// srawi r9,r5,7
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 7;
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
	// sth r11,22(r6)
	PPC_STORE_U16(ctx.r6.u32 + 22, r11.u16);
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r11,20(r6)
	PPC_STORE_U16(ctx.r6.u32 + 20, r11.u16);
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - r11.s64;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x8275485c
	if (!cr6.lt) goto loc_8275485C;
	// neg r10,r9
	ctx.r10.s64 = -ctx.r9.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
loc_8275485C:
	// rlwinm r9,r11,29,19,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFF;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82754874
	if (!cr6.lt) goto loc_82754874;
	// cmpwi cr6,r22,1536
	cr6.compare<int32_t>(r22.s32, 1536, xer);
	// bge cr6,0x8275487c
	if (!cr6.lt) goto loc_8275487C;
loc_82754874:
	// li r10,512
	ctx.r10.s64 = 512;
	// b 0x82754888
	goto loc_82754888;
loc_8275487C:
	// subfic r11,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	r11.s64 = 0 - ctx.r8.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r10,r10,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x200;
loc_82754888:
	// lhz r11,4(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// not r9,r3
	ctx.r9.u64 = ~ctx.r3.u64;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - r11.s64;
	// rlwinm r7,r9,0,23,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x100;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// srawi r10,r4,4
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 4;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// and r11,r3,r30
	r11.u64 = ctx.r3.u64 & r30.u64;
	// or r10,r11,r7
	ctx.r10.u64 = r11.u64 | ctx.r7.u64;
	// sth r10,4(r6)
	PPC_STORE_U16(ctx.r6.u32 + 4, ctx.r10.u16);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_827548B4"))) PPC_WEAK_FUNC(sub_827548B4);
PPC_FUNC_IMPL(__imp__sub_827548B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827548B8"))) PPC_WEAK_FUNC(sub_827548B8);
PPC_FUNC_IMPL(__imp__sub_827548B8) {
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
	ctx.lr = 0x827548C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r26,r29
	r26.u64 = r29.u64;
	// mr r25,r29
	r25.u64 = r29.u64;
	// lwz r8,136(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754950
	if (cr6.eq) goto loc_82754950;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
loc_827548EC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// lwz r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// bgt cr6,0x82754904
	if (cr6.gt) goto loc_82754904;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
loc_82754904:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827548ec
	if (!cr0.eq) goto loc_827548EC;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82754950
	if (cr6.eq) goto loc_82754950;
	// lwz r9,136(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
loc_82754920:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// divwu r8,r26,r11
	ctx.r8.u32 = r26.u32 / r11.u32;
	// twllei r11,0
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf. r8,r8,r26
	ctx.r8.s64 = r26.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82754944
	if (cr0.eq) goto loc_82754944;
	// mullw r26,r11,r26
	r26.s64 = int64_t(r11.s32) * int64_t(r26.s32);
loc_82754944:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82754920
	if (!cr0.eq) goto loc_82754920;
loc_82754950:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mullw r27,r26,r30
	r27.s64 = int64_t(r26.s32) * int64_t(r30.s32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82754a24
	if (!cr6.eq) goto loc_82754A24;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x82130b50
	ctx.lr = 0x82754970;
	sub_82130B50(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mulli r3,r30,28
	ctx.r3.s64 = r30.s64 * 28;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x82130b50
	ctx.lr = 0x82754984;
	sub_82130B50(ctx, base);
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// rlwinm r3,r30,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x82130b50
	ctx.lr = 0x82754998;
	sub_82130B50(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827549bc
	if (cr6.eq) goto loc_827549BC;
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827549bc
	if (cr6.eq) goto loc_827549BC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82754a24
	if (!cr6.eq) goto loc_82754A24;
loc_827549BC:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r25,-32761
	r25.s64 = -2147024896;
	// ori r25,r25,14
	r25.u64 = r25.u64 | 14;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827549e0
	if (cr6.eq) goto loc_827549E0;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x827549DC;
	sub_821310F8(ctx, base);
	// stw r29,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r29.u32);
loc_827549E0:
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827549fc
	if (cr6.eq) goto loc_827549FC;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x821310f8
	ctx.lr = 0x827549F8;
	sub_821310F8(ctx, base);
	// stw r29,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r29.u32);
loc_827549FC:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82754a18
	if (cr6.eq) goto loc_82754A18;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x82754A14;
	sub_821310F8(ctx, base);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
loc_82754A18:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82754A24:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8244d150
	ctx.lr = 0x82754A34;
	sub_8244D150(ctx, base);
	// mulli r28,r30,28
	r28.s64 = r30.s64 * 28;
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x82754A48;
	sub_8244D150(ctx, base);
	// rlwinm r29,r30,3,0,28
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8244d150
	ctx.lr = 0x82754A5C;
	sub_8244D150(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + r27.u64;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// beq cr6,0x82754a18
	if (cr6.eq) goto loc_82754A18;
loc_82754A7C:
	// addi r11,r11,-28
	r11.s64 = r11.s64 + -28;
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// subf r9,r26,r9
	ctx.r9.s64 = ctx.r9.s64 - r26.s64;
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// stw r26,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r26.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// bne 0x82754a7c
	if (!cr0.eq) goto loc_82754A7C;
	// b 0x82754a18
	goto loc_82754A18;
}

__attribute__((alias("__imp__sub_82754AA0"))) PPC_WEAK_FUNC(sub_82754AA0);
PPC_FUNC_IMPL(__imp__sub_82754AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82754AA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r22,0
	r22.s64 = 0;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// mr r28,r22
	r28.u64 = r22.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r27,8(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r23,144(r31)
	r23.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r26,r11,31,1,31
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r25,148(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r10,40(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82754b2c
	if (cr6.eq) goto loc_82754B2C;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,196(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82754b04
	if (cr0.eq) goto loc_82754B04;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244d150
	ctx.lr = 0x82754B04;
	sub_8244D150(ctx, base);
loc_82754B04:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82754B28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
loc_82754B2C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r24,16000
	r24.s64 = 16000;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82754c1c
	if (!cr6.eq) goto loc_82754C1C;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lis r10,16384
	ctx.r10.s64 = 1073741824;
	// rlwinm r9,r11,0,0,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000000;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82754b64
	if (!cr6.eq) goto loc_82754B64;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// blt cr6,0x82754b64
	if (cr6.lt) goto loc_82754B64;
	// addi r25,r25,200
	r25.s64 = r25.s64 + 200;
loc_82754B64:
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// beq cr6,0x82754bc8
	if (cr6.eq) goto loc_82754BC8;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82754bc8
	if (!cr0.eq) goto loc_82754BC8;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82754bac
	if (cr6.eq) goto loc_82754BAC;
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_82754B8C:
	// lha r9,0(r11)
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(r11.u32 + 0));
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// srawi r8,r9,31
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 31;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// xor r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r28,r9,r28
	r28.u64 = ctx.r9.u64 + r28.u64;
	// bne 0x82754b8c
	if (!cr0.eq) goto loc_82754B8C;
loc_82754BAC:
	// divwu r11,r28,r26
	r11.u32 = r28.u32 / r26.u32;
	// twllei r26,0
	// subfc r11,r11,r25
	xer.ca = r25.u32 >= r11.u32;
	r11.s64 = r25.s64 - r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x82754bcc
	goto loc_82754BCC;
loc_82754BC8:
	// stw r22,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r22.u32);
loc_82754BCC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82754bec
	if (!cr6.eq) goto loc_82754BEC;
	// li r11,500
	r11.s64 = 500;
	// li r10,300
	ctx.r10.s64 = 300;
	// stw r11,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r11.u32);
	// stw r10,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r10.u32);
	// b 0x82754c1c
	goto loc_82754C1C;
loc_82754BEC:
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82754c14
	if (!cr6.gt) goto loc_82754C14;
	// mulli r10,r26,1000
	ctx.r10.s64 = r26.s64 * 1000;
	// divwu r10,r10,r24
	ctx.r10.u32 = ctx.r10.u32 / r24.u32;
	// li r9,1
	ctx.r9.s64 = 1;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// stw r11,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r11.u32);
	// b 0x82754c1c
	goto loc_82754C1C;
loc_82754C14:
	// li r11,600
	r11.s64 = 600;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
loc_82754C1C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82754c30
	if (!cr6.eq) goto loc_82754C30;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// beq cr6,0x82754c3c
	if (cr6.eq) goto loc_82754C3C;
loc_82754C30:
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r11,30000
	cr6.compare<uint32_t>(r11.u32, 30000, xer);
	// ble cr6,0x82754c60
	if (!cr6.gt) goto loc_82754C60;
loc_82754C3C:
	// lbz r11,140(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 140);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// stw r22,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r22.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r4,r10,-1808
	ctx.r4.s64 = ctx.r10.s64 + -1808;
	// stb r11,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r11.u8);
	// li r5,54
	ctx.r5.s64 = 54;
	// bl 0x823da950
	ctx.lr = 0x82754C60;
	sub_823DA950(ctx, base);
loc_82754C60:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82754c80
	if (!cr6.eq) goto loc_82754C80;
	// mulli r11,r26,1000
	r11.s64 = r26.s64 * 1000;
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// divwu r11,r11,r24
	r11.u32 = r11.u32 / r24.u32;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
loc_82754C80:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82754C88"))) PPC_WEAK_FUNC(sub_82754C88);
PPC_FUNC_IMPL(__imp__sub_82754C88) {
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
	ctx.lr = 0x82754C90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82754cc0
	if (!cr6.eq) goto loc_82754CC0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_82754CC0:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,140(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82754cfc
	if (cr6.eq) goto loc_82754CFC;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// rlwinm. r10,r10,0,12,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xF0000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82754cfc
	if (cr0.eq) goto loc_82754CFC;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bdc34
	ctx.lr = 0x82754CFC;
	__imp__XamVoiceSubmitPacket(ctx, base);
loc_82754CFC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82754d14
	if (cr6.eq) goto loc_82754D14;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82754d28
	if (!cr6.lt) goto loc_82754D28;
loc_82754D14:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_82754D28:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r30,116
	r11.s64 = r30.s64 + 116;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// lwz r10,120(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 120);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82754d48
	if (cr6.eq) goto loc_82754D48;
	// stw r29,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r29.u32);
	// b 0x82754d4c
	goto loc_82754D4C;
loc_82754D48:
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
loc_82754D4C:
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82754D58"))) PPC_WEAK_FUNC(sub_82754D58);
PPC_FUNC_IMPL(__imp__sub_82754D58) {
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
	ctx.lr = 0x82754D60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addi r11,r29,20
	r11.s64 = r29.s64 + 20;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x8274f578
	ctx.lr = 0x82754D8C;
	sub_8274F578(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82754da4
	if (!cr0.lt) goto loc_82754DA4;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// stw r11,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r11.u32);
loc_82754DA4:
	// rlwinm r11,r29,3,0,28
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,100
	r11.s64 = r11.s64 + 100;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82754dc8
	if (cr6.eq) goto loc_82754DC8;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x82754dcc
	goto loc_82754DCC;
loc_82754DC8:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_82754DCC:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82754DD8"))) PPC_WEAK_FUNC(sub_82754DD8);
PPC_FUNC_IMPL(__imp__sub_82754DD8) {
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
	ctx.lr = 0x82754DE0;
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
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82754e5c
	if (!cr6.gt) goto loc_82754E5C;
	// addi r31,r30,100
	r31.s64 = r30.s64 + 100;
	// addi r29,r30,80
	r29.s64 = r30.s64 + 80;
loc_82754E04:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8274f6c8
	ctx.lr = 0x82754E18;
	sub_8274F6C8(ctx, base);
loc_82754E18:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82754e44
	if (cr6.eq) goto loc_82754E44;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82754e34
	if (!cr6.eq) goto loc_82754E34;
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
loc_82754E34:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// b 0x82754e18
	goto loc_82754E18;
loc_82754E44:
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x82754e04
	if (cr6.lt) goto loc_82754E04;
loc_82754E5C:
	// addi r11,r30,116
	r11.s64 = r30.s64 + 116;
loc_82754E60:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82754e8c
	if (cr6.eq) goto loc_82754E8C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82754e7c
	if (!cr6.eq) goto loc_82754E7C;
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
loc_82754E7C:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r27,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r27.u32);
	// b 0x82754e60
	goto loc_82754E60;
loc_82754E8C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82754E94"))) PPC_WEAK_FUNC(sub_82754E94);
PPC_FUNC_IMPL(__imp__sub_82754E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82754E98"))) PPC_WEAK_FUNC(sub_82754E98);
PPC_FUNC_IMPL(__imp__sub_82754E98) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82754EA0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r15,0
	r15.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r15,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r15.u32);
	// mr r17,r15
	r17.u64 = r15.u64;
	// mr r16,r15
	r16.u64 = r15.u64;
	// bl 0x8244fee8
	ctx.lr = 0x82754EBC;
	sub_8244FEE8(ctx, base);
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// li r14,28
	r14.s64 = 28;
	// cmplw cr6,r19,r11
	cr6.compare<uint32_t>(r19.u32, r11.u32, xer);
	// lwz r20,116(r28)
	r20.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// subf r11,r11,r19
	r11.s64 = r19.s64 - r11.s64;
	// addi r21,r28,116
	r21.s64 = r28.s64 + 116;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// beq cr6,0x82755224
	if (cr6.eq) goto loc_82755224;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r18,r11,-4256
	r18.s64 = r11.s64 + -4256;
loc_82754EF4:
	// lwz r29,0(r20)
	r29.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x82755224
	if (cr6.eq) goto loc_82755224;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82755224
	if (!cr6.eq) goto loc_82755224;
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplw cr6,r17,r10
	cr6.compare<uint32_t>(r17.u32, ctx.r10.u32, xer);
	// bge cr6,0x82755224
	if (!cr6.lt) goto loc_82755224;
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// cmpwi cr6,r10,20
	cr6.compare<int32_t>(ctx.r10.s32, 20, xer);
	// blt cr6,0x82755224
	if (cr6.lt) goto loc_82755224;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// beq cr6,0x82754f74
	if (cr6.eq) goto loc_82754F74;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82754f44
	if (cr6.eq) goto loc_82754F44;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82754f54
	if (!cr6.eq) goto loc_82754F54;
loc_82754F44:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r15,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r15.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
loc_82754F54:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x8244d150
	ctx.lr = 0x82754F64;
	sub_8244D150(ctx, base);
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r16,1
	r16.s64 = 1;
	// stw r15,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r15.u32);
	// b 0x82755114
	goto loc_82755114;
loc_82754F74:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x827550b8
	if (!cr6.eq) goto loc_827550B8;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r23,r28,24
	r23.s64 = r28.s64 + 24;
	// lwz r30,8(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// addze r31,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r31.s64 = temp.s64;
	// mulli r11,r31,3
	r11.s64 = r31.s64 * 3;
	// add r27,r11,r30
	r27.u64 = r11.u64 + r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823da950
	ctx.lr = 0x82754FAC;
	sub_823DA950(ctx, base);
	// mulli r11,r31,7
	r11.s64 = r31.s64 * 7;
	// add r24,r11,r30
	r24.u64 = r11.u64 + r30.u64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823da950
	ctx.lr = 0x82754FC4;
	sub_823DA950(ctx, base);
	// rlwinm. r25,r31,1,0,30
	r25.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// mr r26,r30
	r26.u64 = r30.u64;
	// ble 0x82755038
	if (!cr0.gt) goto loc_82755038;
	// addi r11,r25,-1
	r11.s64 = r25.s64 + -1;
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r22,r11,1
	r22.s64 = r11.s64 + 1;
loc_82754FDC:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// clrlwi r4,r11,28
	ctx.r4.u64 = r11.u32 & 0xF;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82753758
	ctx.lr = 0x82754FF4;
	sub_82753758(ctx, base);
	// lha r11,0(r26)
	r11.s64 = int16_t(PPC_LOAD_U16(r26.u32 + 0));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// sth r11,0(r26)
	PPC_STORE_U16(r26.u32 + 0, r11.u16);
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// rlwinm r4,r11,28,4,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFFFFFF;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x82753758
	ctx.lr = 0x8275501C;
	sub_82753758(ctx, base);
	// lha r11,0(r26)
	r11.s64 = int16_t(PPC_LOAD_U16(r26.u32 + 0));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// sth r11,0(r26)
	PPC_STORE_U16(r26.u32 + 0, r11.u16);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// bne 0x82754fdc
	if (!cr0.eq) goto loc_82754FDC;
loc_82755038:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r24
	r27.u64 = r24.u64;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82755104
	if (!cr6.gt) goto loc_82755104;
	// addi r11,r25,-1
	r11.s64 = r25.s64 + -1;
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
loc_82755058:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// clrlwi r4,r11,28
	ctx.r4.u64 = r11.u32 & 0xF;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82753758
	ctx.lr = 0x82755070;
	sub_82753758(ctx, base);
	// lha r11,0(r31)
	r11.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 0));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// rlwinm r4,r11,28,4,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFFFFFF;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82753758
	ctx.lr = 0x82755098;
	sub_82753758(ctx, base);
	// lha r11,0(r31)
	r11.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 0));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// bne 0x82755058
	if (!cr0.eq) goto loc_82755058;
	// b 0x82755104
	goto loc_82755104;
loc_827550B8:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82755118
	if (!cr6.eq) goto loc_82755118;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + r11.u64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82755104
	if (cr6.eq) goto loc_82755104;
loc_827550DC:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r8,r8,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lhzx r8,r8,r18
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + r18.u32);
	// sth r8,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
	// sth r8,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// bne 0x827550dc
	if (!cr0.eq) goto loc_827550DC;
loc_82755104:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r15,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r15.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r11.u32);
loc_82755114:
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
loc_82755118:
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82754aa0
	ctx.lr = 0x82755128;
	sub_82754AA0(ctx, base);
	// lwz r11,144(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 144);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x827551c8
	if (!cr6.eq) goto loc_827551C8;
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// mr r30,r15
	r30.u64 = r15.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827551c8
	if (!cr6.gt) goto loc_827551C8;
	// addi r27,r28,88
	r27.s64 = r28.s64 + 88;
loc_82755148:
	// lwz r11,132(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 132);
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// subf r11,r11,r29
	r11.s64 = r29.s64 - r11.s64;
	// divw r11,r11,r14
	r11.s32 = r11.s32 / r14.s32;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82755168
	if (cr6.lt) goto loc_82755168;
	// mr r31,r15
	r31.u64 = r15.u64;
	// b 0x82755174
	goto loc_82755174;
loc_82755168:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
loc_82755174:
	// lwz r26,0(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8244d150
	ctx.lr = 0x82755188;
	sub_8244D150(ctx, base);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r11,8(r26)
	PPC_STORE_U32(r26.u32 + 8, r11.u32);
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r11,12(r26)
	PPC_STORE_U32(r26.u32 + 12, r11.u32);
	// bl 0x82754d58
	ctx.lr = 0x827551A8;
	sub_82754D58(ctx, base);
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// stw r11,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r11.u32);
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82755148
	if (cr6.lt) goto loc_82755148;
loc_827551C8:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827551f0
	if (cr6.eq) goto loc_827551F0;
	// lwz r10,4(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x827551e4
	if (!cr6.eq) goto loc_827551E4;
	// stw r15,4(r21)
	PPC_STORE_U32(r21.u32 + 4, r15.u32);
loc_827551E4:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r21)
	PPC_STORE_U32(r21.u32 + 0, ctx.r10.u32);
	// stw r15,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r15.u32);
loc_827551F0:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82755208
	if (!cr6.eq) goto loc_82755208;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82754c88
	ctx.lr = 0x82755208;
	sub_82754C88(ctx, base);
loc_82755208:
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// lwz r20,0(r21)
	r20.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// addi r11,r11,-20
	r11.s64 = r11.s64 + -20;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// bne cr6,0x82754ef4
	if (!cr6.eq) goto loc_82754EF4;
loc_82755224:
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// mr r30,r15
	r30.u64 = r15.u64;
	// stw r19,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r19.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827552d0
	if (!cr6.gt) goto loc_827552D0;
	// addi r31,r28,80
	r31.s64 = r28.s64 + 80;
loc_8275523C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulli r11,r11,3
	r11.s64 = r11.s64 * 3;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,344
	ctx.r10.s64 = r11.s64 + 344;
	// addi r11,r11,332
	r11.s64 = r11.s64 + 332;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwzx r5,r11,r9
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// bl 0x8274f5a0
	ctx.lr = 0x82755278;
	sub_8274F5A0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82755288:
	// lwz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827552a0
	if (cr6.eq) goto loc_827552A0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x827552b4
	if (cr6.eq) goto loc_827552B4;
loc_827552A0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// blt cr6,0x82755288
	if (cr6.lt) goto loc_82755288;
	// stw r15,144(r28)
	PPC_STORE_U32(r28.u32 + 144, r15.u32);
loc_827552B4:
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8275523c
	if (cr6.lt) goto loc_8275523C;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x827553c0
	if (cr6.lt) goto loc_827553C0;
loc_827552D0:
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// mr r31,r15
	r31.u64 = r15.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827553c0
	if (!cr6.gt) goto loc_827553C0;
	// li r29,24
	r29.s64 = 24;
loc_827552E4:
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r30,r11,100
	r30.s64 = r11.s64 + 100;
	// lwz r11,100(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 100);
loc_827552F4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827553b0
	if (cr6.eq) goto loc_827553B0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,2
	cr6.compare<uint32_t>(r31.u32, 2, xer);
	// bne cr6,0x82755318
	if (!cr6.eq) goto loc_82755318;
	// lwz r11,132(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 132);
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// divw r11,r11,r14
	r11.s32 = r11.s32 / r14.s32;
	// b 0x8275532c
	goto loc_8275532C;
loc_82755318:
	// addi r11,r31,31
	r11.s64 = r31.s64 + 31;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r28
	r11.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// divw r11,r11,r29
	r11.s32 = r11.s32 / r29.s32;
loc_8275532C:
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82755340
	if (cr6.lt) goto loc_82755340;
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// b 0x8275534c
	goto loc_8275534C;
loc_82755340:
	// lwz r10,96(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 96);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
loc_8275534C:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x827553b0
	if (cr6.eq) goto loc_827553B0;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827553b0
	if (cr6.eq) goto loc_827553B0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82755390
	if (cr6.eq) goto loc_82755390;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82755384
	if (!cr6.eq) goto loc_82755384;
	// stw r15,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r15.u32);
loc_82755384:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// stw r15,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r15.u32);
loc_82755390:
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r11.u32);
	// bne 0x827553a8
	if (!cr0.eq) goto loc_827553A8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82754c88
	ctx.lr = 0x827553A8;
	sub_82754C88(ctx, base);
loc_827553A8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x827552f4
	goto loc_827552F4;
loc_827553B0:
	// lwz r11,136(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x827552e4
	if (cr6.lt) goto loc_827552E4;
loc_827553C0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_827553CC"))) PPC_WEAK_FUNC(sub_827553CC);
PPC_FUNC_IMPL(__imp__sub_827553CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827553D0"))) PPC_WEAK_FUNC(sub_827553D0);
PPC_FUNC_IMPL(__imp__sub_827553D0) {
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
	ctx.lr = 0x827553D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827554c4
	if (cr6.eq) goto loc_827554C4;
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// li r29,0
	r29.s64 = 0;
	// mr r28,r29
	r28.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82755460
	if (!cr6.gt) goto loc_82755460;
	// addi r31,r30,124
	r31.s64 = r30.s64 + 124;
loc_82755400:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -44);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8274f6c8
	ctx.lr = 0x82755414;
	sub_8274F6C8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82755430
	if (cr6.eq) goto loc_82755430;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x821310f8
	ctx.lr = 0x8275542C;
	sub_821310F8(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_82755430:
	// lwz r3,-36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275544c
	if (cr6.eq) goto loc_8275544C;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x82755448;
	sub_821310F8(ctx, base);
	// stw r29,-36(r31)
	PPC_STORE_U32(r31.u32 + -36, r29.u32);
loc_8275544C:
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x82755400
	if (cr6.lt) goto loc_82755400;
loc_82755460:
	// lwz r3,96(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275547c
	if (cr6.eq) goto loc_8275547C;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x82755478;
	sub_821310F8(ctx, base);
	// stw r29,96(r30)
	PPC_STORE_U32(r30.u32 + 96, r29.u32);
loc_8275547C:
	// lwz r3,132(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82755498
	if (cr6.eq) goto loc_82755498;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// bl 0x821310f8
	ctx.lr = 0x82755494;
	sub_821310F8(ctx, base);
	// stw r29,132(r30)
	PPC_STORE_U32(r30.u32 + 132, r29.u32);
loc_82755498:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827554b4
	if (cr6.eq) goto loc_827554B4;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x827554B0;
	sub_821310F8(ctx, base);
	// stw r29,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r29.u32);
loc_827554B4:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r4,r4,32781
	ctx.r4.u64 = ctx.r4.u64 | 32781;
	// bl 0x821310f8
	ctx.lr = 0x827554C4;
	sub_821310F8(ctx, base);
loc_827554C4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827554CC"))) PPC_WEAK_FUNC(sub_827554CC);
PPC_FUNC_IMPL(__imp__sub_827554CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827554D0"))) PPC_WEAK_FUNC(sub_827554D0);
PPC_FUNC_IMPL(__imp__sub_827554D0) {
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
	ctx.lr = 0x827554D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82754dd8
	ctx.lr = 0x827554E8;
	sub_82754DD8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827548b8
	ctx.lr = 0x827554F0;
	sub_827548B8(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// b 0x8275552c
	goto loc_8275552C;
loc_827554F8:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// subf r11,r30,r10
	r11.s64 = ctx.r10.s64 - r30.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82755518
	if (cr6.lt) goto loc_82755518;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// b 0x82755524
	goto loc_82755524;
loc_82755518:
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
loc_82755524:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82754c88
	ctx.lr = 0x8275552C;
	sub_82754C88(ctx, base);
loc_8275552C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x827554f8
	if (!cr6.eq) goto loc_827554F8;
	// li r11,600
	r11.s64 = 600;
	// stb r29,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r29.u8);
	// stw r29,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r29.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// stw r29,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r29.u32);
	// stw r29,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r29.u32);
	// bl 0x8244fee8
	ctx.lr = 0x82755550;
	sub_8244FEE8(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82755560"))) PPC_WEAK_FUNC(sub_82755560);
PPC_FUNC_IMPL(__imp__sub_82755560) {
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
	ctx.lr = 0x82755568;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,160
	ctx.r3.s64 = 160;
	// ori r4,r4,32781
	ctx.r4.u64 = ctx.r4.u64 | 32781;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// bl 0x82130b50
	ctx.lr = 0x82755594;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8275567c
	if (cr0.eq) goto loc_8275567C;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// bl 0x823da950
	ctx.lr = 0x827555BC;
	sub_823DA950(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82755650
	if (cr6.eq) goto loc_82755650;
	// addi r11,r30,22
	r11.s64 = r30.s64 + 22;
	// mulli r27,r28,24
	r27.s64 = r28.s64 * 24;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r31
	r29.u64 = r11.u64 + r31.u64;
loc_827555D4:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// addi r29,r29,-4
	r29.s64 = r29.s64 + -4;
	// bl 0x82130b50
	ctx.lr = 0x827555EC;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,36(r29)
	PPC_STORE_U32(r29.u32 + 36, ctx.r3.u32);
	// beq 0x8275567c
	if (cr0.eq) goto loc_8275567C;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// rlwinm r3,r28,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x82130b50
	ctx.lr = 0x82755608;
	sub_82130B50(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8275567c
	if (cr0.eq) goto loc_8275567C;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82755648
	if (cr6.eq) goto loc_82755648;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82755628:
	// lwz r8,36(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// stwx r8,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r8.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// bne 0x82755628
	if (!cr0.eq) goto loc_82755628;
loc_82755648:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x827555d4
	if (!cr6.eq) goto loc_827555D4;
loc_82755650:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827548b8
	ctx.lr = 0x82755658;
	sub_827548B8(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8275566c
	if (!cr0.lt) goto loc_8275566C;
loc_82755660:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827553d0
	ctx.lr = 0x82755668;
	sub_827553D0(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8275566C:
	// stw r31,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8275567C:
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x82755660
	goto loc_82755660;
}

__attribute__((alias("__imp__sub_82755688"))) PPC_WEAK_FUNC(sub_82755688);
PPC_FUNC_IMPL(__imp__sub_82755688) {
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
	ctx.lr = 0x82755690;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// clrlwi r9,r8,16
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFF;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r29,r11,-1752
	r29.s64 = r11.s64 + -1752;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// stw r9,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r9.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r29
	r31.u64 = r29.u64;
	// sth r7,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, ctx.r7.u16);
loc_827556C4:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lha r5,0(r31)
	ctx.r5.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 0));
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x82756a70
	ctx.lr = 0x827556D8;
	sub_82756A70(ctx, base);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// addi r11,r29,34
	r11.s64 = r29.s64 + 34;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x827556c4
	if (cr6.lt) goto loc_827556C4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827556F4"))) PPC_WEAK_FUNC(sub_827556F4);
PPC_FUNC_IMPL(__imp__sub_827556F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827556F8"))) PPC_WEAK_FUNC(sub_827556F8);
PPC_FUNC_IMPL(__imp__sub_827556F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f4
	ctx.lr = 0x82755700;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// lfs f3,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// addi r28,r11,4
	r28.s64 = r11.s64 + 4;
	// lfs f2,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,56(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 56);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82757260
	ctx.lr = 0x8275572C;
	sub_82757260(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lfs f1,56(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 56);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827572e0
	ctx.lr = 0x82755740;
	sub_827572E0(ctx, base);
	// lfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82757170
	ctx.lr = 0x82755748;
	sub_82757170(ctx, base);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// bl 0x82757210
	ctx.lr = 0x82755750;
	sub_82757210(ctx, base);
	// stfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lfs f1,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82757118
	ctx.lr = 0x8275575C;
	sub_82757118(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// lfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r30,12
	ctx.r4.s64 = r30.s64 + 12;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82756e80
	ctx.lr = 0x82755774;
	sub_82756E80(ctx, base);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f0,56(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 56, temp.u32);
	// lfs f0,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,60(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 60, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8275578C"))) PPC_WEAK_FUNC(sub_8275578C);
PPC_FUNC_IMPL(__imp__sub_8275578C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82755790"))) PPC_WEAK_FUNC(sub_82755790);
PPC_FUNC_IMPL(__imp__sub_82755790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82755798;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x827557b8
	if (!cr6.eq) goto loc_827557B8;
loc_827557B0:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827558b0
	goto loc_827558B0;
loc_827557B8:
	// lis r29,-32111
	r29.s64 = -2104426496;
	// li r26,0
	r26.s64 = 0;
	// li r4,88
	ctx.r4.s64 = 88;
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-21256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21256);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827557D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x827557b0
	if (cr0.eq) goto loc_827557B0;
	// li r28,1
	r28.s64 = 1;
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// stw r27,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r27.u32);
	// li r4,40
	ctx.r4.s64 = 40;
	// stw r28,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-21256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21256);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82755804;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// beq 0x827557b0
	if (cr0.eq) goto loc_827557B0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// sth r26,28(r11)
	PPC_STORE_U16(r11.u32 + 28, r26.u16);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// sth r26,36(r11)
	PPC_STORE_U16(r11.u32 + 36, r26.u16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r3,371
	ctx.r3.s64 = 371;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f0,12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f0,16(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stfs f31,24(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// stfs f0,32(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// bl 0x82757f78
	ctx.lr = 0x82755848;
	sub_82757F78(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x827557b0
	if (!cr0.eq) goto loc_827557B0;
	// stfs f31,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82757f00
	ctx.lr = 0x8275585C;
	sub_82757F00(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x827557b0
	if (!cr0.eq) goto loc_827557B0;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82757640
	ctx.lr = 0x8275586C;
	sub_82757640(ctx, base);
	// clrlwi. r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x827557b0
	if (!cr0.eq) goto loc_827557B0;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82757540
	ctx.lr = 0x8275587C;
	sub_82757540(ctx, base);
	// extsh. r11,r3
	r11.s64 = ctx.r3.s16;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x827557b0
	if (!cr0.eq) goto loc_827557B0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f31,48(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stw r28,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r28.u32);
	// stfs f31,56(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r26,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r26.u32);
	// lfs f0,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
loc_827558B0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827558BC"))) PPC_WEAK_FUNC(sub_827558BC);
PPC_FUNC_IMPL(__imp__sub_827558BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827558C0"))) PPC_WEAK_FUNC(sub_827558C0);
PPC_FUNC_IMPL(__imp__sub_827558C0) {
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
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82755934
	if (cr6.eq) goto loc_82755934;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8275a6a0
	ctx.lr = 0x827558E8;
	sub_8275A6A0(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x827575f0
	ctx.lr = 0x827558F0;
	sub_827575F0(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x827576e8
	ctx.lr = 0x827558F8;
	sub_827576E8(ctx, base);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x827575f0
	ctx.lr = 0x82755900;
	sub_827575F0(ctx, base);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82755924
	if (cr6.eq) goto loc_82755924;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275591C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
loc_82755924:
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82755934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82755934:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82755950"))) PPC_WEAK_FUNC(sub_82755950);
PPC_FUNC_IMPL(__imp__sub_82755950) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-3344(r1)
	ea = -3344 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,291
	ctx.r5.s64 = 291;
	// li r4,145
	ctx.r4.s64 = 145;
	// bl 0x82758108
	ctx.lr = 0x8275597C;
	sub_82758108(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,-1712
	ctx.r9.s64 = r11.s64 + -1712;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r7,145
	ctx.r7.s64 = 145;
	// addi r8,r1,1240
	ctx.r8.s64 = ctx.r1.s64 + 1240;
loc_82755994:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lfs f13,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f0,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,0(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// bgt 0x82755994
	if (cr0.gt) goto loc_82755994;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r5,291
	ctx.r5.s64 = 291;
	// lfs f13,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827583c0
	ctx.lr = 0x827559E8;
	sub_827583C0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r7,r1,2288
	ctx.r7.s64 = ctx.r1.s64 + 2288;
	// addi r6,r1,1248
	ctx.r6.s64 = ctx.r1.s64 + 1248;
	// li r5,9
	ctx.r5.s64 = 9;
	// li r4,291
	ctx.r4.s64 = 291;
	// lfs f0,-1128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1128);
	f0.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// bl 0x82758268
	ctx.lr = 0x82755A10;
	sub_82758268(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,2288
	ctx.r4.s64 = ctx.r1.s64 + 2288;
	// addi r3,r1,1248
	ctx.r3.s64 = ctx.r1.s64 + 1248;
	// bl 0x82757cd0
	ctx.lr = 0x82755A20;
	sub_82757CD0(ctx, base);
	// addi r1,r1,3344
	ctx.r1.s64 = ctx.r1.s64 + 3344;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82755A38"))) PPC_WEAK_FUNC(sub_82755A38);
PPC_FUNC_IMPL(__imp__sub_82755A38) {
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
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82755A40;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823db9d8
	ctx.lr = 0x82755A48;
	// stwu r1,-1536(r1)
	ea = -1536 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// addi r11,r23,-1
	r11.s64 = r23.s64 + -1;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// frsp f28,f0
	f28.f64 = double(float(f0.f64));
	// fdivs f0,f28,f29
	f0.f64 = double(float(f28.f64 / f29.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// cmpwi cr6,r29,80
	cr6.compare<int32_t>(r29.s32, 80, xer);
	// ble cr6,0x82755a90
	if (!cr6.gt) goto loc_82755A90;
	// li r29,80
	r29.s64 = 80;
loc_82755A90:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// rlwinm r9,r29,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// add r31,r27,r11
	r31.u64 = r27.u64 + r11.u64;
	// add r30,r9,r10
	r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82755b0c
	if (!cr6.gt) goto loc_82755B0C;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r28,r30
	r28.u64 = r30.u64;
	// subf r25,r30,r11
	r25.s64 = r11.s64 - r30.s64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// subf r24,r30,r31
	r24.s64 = r31.s64 - r30.s64;
	// mr r26,r29
	r26.u64 = r29.u64;
	// lfs f30,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f30.f64 = double(temp.f32);
loc_82755AD4:
	// fadds f0,f31,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 + f30.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r21,84(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r11,r21,2,0,29
	r11.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r11,r22
	temp.u32 = PPC_LOAD_U32(r11.u32 + r22.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82758910
	ctx.lr = 0x82755AF0;
	sub_82758910(ctx, base);
	// stfsx f1,r25,r28
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r25.u32 + r28.u32, temp.u32);
	// stw r21,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r21.u32);
	// stfsx f31,r24,r28
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r24.u32 + r28.u32, temp.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// fadds f31,f31,f29
	f31.f64 = double(float(f31.f64 + f29.f64));
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x82755ad4
	if (!cr0.eq) goto loc_82755AD4;
loc_82755B0C:
	// rlwinm r11,r23,2,0,29
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// lfs f1,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82758910
	ctx.lr = 0x82755B1C;
	sub_82758910(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// stfsx f1,r27,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r27.u32 + r11.u32, temp.u32);
	// stwx r23,r27,r30
	PPC_STORE_U32(r27.u32 + r30.u32, r23.u32);
	// stfsx f28,r27,r31
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + r31.u32, temp.u32);
	// ble cr6,0x82755bdc
	if (!cr6.gt) goto loc_82755BDC;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r8,r30,4
	ctx.r8.s64 = r30.s64 + 4;
	// mr r11,r31
	r11.u64 = r31.u64;
	// lfs f10,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// subf r30,r31,r30
	r30.s64 = r30.s64 - r31.s64;
	// subf r4,r31,r9
	ctx.r4.s64 = ctx.r9.s64 - r31.s64;
	// subf r3,r31,r7
	ctx.r3.s64 = ctx.r7.s64 - r31.s64;
loc_82755B60:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// fdivs f11,f10,f0
	ctx.f11.f64 = double(float(ctx.f10.f64 / f0.f64));
	// bge cr6,0x82755bcc
	if (!cr6.lt) goto loc_82755BCC;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// lfsx f12,r3,r11
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r9,r22
	r11.u64 = ctx.r9.u64 + r22.u64;
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
loc_82755B98:
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// fsubs f9,f9,f13
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fmuls f9,f9,f12
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fmadds f9,f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + f0.f64));
	// stfs f9,0(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// blt cr6,0x82755b98
	if (cr6.lt) goto loc_82755B98;
loc_82755BCC:
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x82755b60
	if (!cr0.eq) goto loc_82755B60;
loc_82755BDC:
	// addi r1,r1,1536
	ctx.r1.s64 = ctx.r1.s64 + 1536;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dba24
	ctx.lr = 0x82755BE8;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82755BEC"))) PPC_WEAK_FUNC(sub_82755BEC);
PPC_FUNC_IMPL(__imp__sub_82755BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82755BF0"))) PPC_WEAK_FUNC(sub_82755BF0);
PPC_FUNC_IMPL(__imp__sub_82755BF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82755BF8;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-3184(r1)
	ea = -3184 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// lwz r31,72(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// li r9,100
	ctx.r9.s64 = 100;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,1536
	ctx.r6.s64 = ctx.r1.s64 + 1536;
	// addi r5,r1,512
	ctx.r5.s64 = ctx.r1.s64 + 512;
	// addi r30,r27,8
	r30.s64 = r27.s64 + 8;
	// bl 0x827597a0
	ctx.lr = 0x82755C3C;
	sub_827597A0(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lfs f13,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r9,100
	ctx.r9.s64 = 100;
	// addi r7,r1,512
	ctx.r7.s64 = ctx.r1.s64 + 512;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,1536
	ctx.r4.s64 = ctx.r1.s64 + 1536;
	// lfs f0,-23584(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -23584);
	f0.f64 = double(temp.f32);
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// fdivs f31,f0,f13
	f31.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82759548
	ctx.lr = 0x82755C6C;
	sub_82759548(ctx, base);
	// addi r26,r30,4
	r26.s64 = r30.s64 + 4;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,100
	ctx.r10.s64 = 100;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,1536
	ctx.r7.s64 = ctx.r1.s64 + 1536;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,512
	ctx.r4.s64 = ctx.r1.s64 + 512;
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// bl 0x82758b28
	ctx.lr = 0x82755C94;
	sub_82758B28(ctx, base);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,512
	ctx.r4.s64 = ctx.r1.s64 + 512;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82755a38
	ctx.lr = 0x82755CA4;
	sub_82755A38(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lhz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bne cr6,0x82755ccc
	if (!cr6.eq) goto loc_82755CCC;
	// extsh. r11,r6
	r11.s64 = ctx.r6.s16;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82755dcc
	if (cr0.eq) goto loc_82755DCC;
loc_82755CCC:
	// lha r7,36(r31)
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 36));
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82755CE0:
	// extsw r11,r8
	r11.s64 = ctx.r8.s32;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fctiwz f11,f11
	ctx.f11.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lhz r11,102(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// blt cr6,0x82755d48
	if (cr6.lt) goto loc_82755D48;
	// extsh. r11,r11
	r11.s64 = r11.s16;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// blt 0x82755d3c
	if (cr0.lt) goto loc_82755D3C;
	// bge cr6,0x82755d40
	if (!cr6.lt) goto loc_82755D40;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,512
	ctx.r4.s64 = ctx.r1.s64 + 512;
	// addi r9,r1,1936
	ctx.r9.s64 = ctx.r1.s64 + 1936;
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lfsx f11,r5,r4
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfsx f11,r10,r9
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// b 0x82755d5c
	goto loc_82755D5C;
loc_82755D3C:
	// blt cr6,0x82755d48
	if (cr6.lt) goto loc_82755D48;
loc_82755D40:
	// lfs f11,1532(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 1532);
	ctx.f11.f64 = double(temp.f32);
	// b 0x82755d50
	goto loc_82755D50;
loc_82755D48:
	// addi r9,r1,512
	ctx.r9.s64 = ctx.r1.s64 + 512;
	// lfsx f11,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f11.f64 = double(temp.f32);
loc_82755D50:
	// addi r11,r1,1936
	r11.s64 = ctx.r1.s64 + 1936;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_82755D5C:
	// addi r9,r1,512
	ctx.r9.s64 = ctx.r1.s64 + 512;
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 + f0.f64));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lfsx f11,r10,r9
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// cmpwi cr6,r10,1024
	cr6.compare<int32_t>(ctx.r10.s32, 1024, xer);
	// blt cr6,0x82755ce0
	if (cr6.lt) goto loc_82755CE0;
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r11,r1,1936
	r11.s64 = ctx.r1.s64 + 1936;
	// li r10,256
	ctx.r10.s64 = 256;
	// lfs f0,-32720(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -32720);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82755D98:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82755d98
	if (!cr0.eq) goto loc_82755D98;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,1936
	ctx.r4.s64 = ctx.r1.s64 + 1936;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// lwz r11,-21244(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21244);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82755DCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82755DCC:
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,1536
	ctx.r6.s64 = ctx.r1.s64 + 1536;
	// addi r5,r27,16
	ctx.r5.s64 = r27.s64 + 16;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// bl 0x827590e0
	ctx.lr = 0x82755DE4;
	sub_827590E0(ctx, base);
	// addi r5,r27,20
	ctx.r5.s64 = r27.s64 + 20;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82759098
	ctx.lr = 0x82755DF4;
	sub_82759098(ctx, base);
	// addi r6,r1,1936
	ctx.r6.s64 = ctx.r1.s64 + 1936;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r24,145
	ctx.r4.s64 = r24.s64 + 145;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82758108
	ctx.lr = 0x82755E08;
	sub_82758108(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r6,r1,1936
	ctx.r6.s64 = ctx.r1.s64 + 1936;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,1936
	ctx.r3.s64 = ctx.r1.s64 + 1936;
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82758428
	ctx.lr = 0x82755E20;
	sub_82758428(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,1936
	ctx.r3.s64 = ctx.r1.s64 + 1936;
	// bl 0x82758658
	ctx.lr = 0x82755E2C;
	sub_82758658(ctx, base);
	// lwz r31,3268(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3268);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// addi r3,r1,1936
	ctx.r3.s64 = ctx.r1.s64 + 1936;
	// bl 0x82758ec0
	ctx.lr = 0x82755E48;
	sub_82758EC0(ctx, base);
	// lfs f5,52(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 52);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,48(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 48);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82758a58
	ctx.lr = 0x82755E60;
	sub_82758A58(ctx, base);
	// stfs f1,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// addi r1,r1,3184
	ctx.r1.s64 = ctx.r1.s64 + 3184;
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82755E70"))) PPC_WEAK_FUNC(sub_82755E70);
PPC_FUNC_IMPL(__imp__sub_82755E70) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82755E78;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-4352(r1)
	ea = -4352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r25,72(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// and. r11,r11,r9
	r11.u64 = r11.u64 & ctx.r9.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82755eb4
	if (!cr0.eq) goto loc_82755EB4;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82756078
	goto loc_82756078;
loc_82755EB4:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r11,160
	r11.s64 = 160;
loc_82755EBC:
	// lha r9,0(r3)
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r3.u32 + 0));
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// std r9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// frsp f0,f0
	f0.f64 = double(float(f0.f64));
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bgt 0x82755ebc
	if (cr0.gt) goto loc_82755EBC;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// li r5,160
	ctx.r5.s64 = 160;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82757fe8
	ctx.lr = 0x82755EF8;
	sub_82757FE8(ctx, base);
	// addi r26,r31,44
	r26.s64 = r31.s64 + 44;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x82755950
	ctx.lr = 0x82755F0C;
	sub_82755950(ctx, base);
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lwz r27,24(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82758868
	ctx.lr = 0x82755F18;
	sub_82758868(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,145
	ctx.r5.s64 = 145;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82757338
	ctx.lr = 0x82755F34;
	sub_82757338(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r4,r27,145
	ctx.r4.s64 = r27.s64 + 145;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82758108
	ctx.lr = 0x82755F4C;
	sub_82758108(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82758428
	ctx.lr = 0x82755F64;
	sub_82758428(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82758658
	ctx.lr = 0x82755F70;
	sub_82758658(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r7,r1,1168
	ctx.r7.s64 = ctx.r1.s64 + 1168;
	// addi r6,r1,2208
	ctx.r6.s64 = ctx.r1.s64 + 2208;
	// li r5,9
	ctx.r5.s64 = 9;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82758268
	ctx.lr = 0x82755F88;
	sub_82758268(ctx, base);
	// addi r11,r1,104
	r11.s64 = ctx.r1.s64 + 104;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r1,1168
	ctx.r5.s64 = ctx.r1.s64 + 1168;
	// addi r4,r1,2208
	ctx.r4.s64 = ctx.r1.s64 + 2208;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82755bf0
	ctx.lr = 0x82755FB4;
	sub_82755BF0(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f1,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// li r5,225
	ctx.r5.s64 = 225;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// extsh r6,r11
	ctx.r6.s64 = r11.s16;
	// bl 0x82759c10
	ctx.lr = 0x82755FD4;
	sub_82759C10(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f0,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// beq cr6,0x82756004
	if (cr6.eq) goto loc_82756004;
	// lfs f2,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82759ab0
	ctx.lr = 0x82756004;
	sub_82759AB0(ctx, base);
loc_82756004:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82756074
	if (cr6.eq) goto loc_82756074;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f10,20(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f9,16(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,24(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// lfs f11,12(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11360);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 / f0.f64));
	// lfs f7,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f13,27636(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27636);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f11,f7
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f7.f64));
	// fmuls f0,f0,f10
	f0.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fmadds f0,f0,f9,f8
	f0.f64 = double(float(f0.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82756054
	if (!cr6.lt) goto loc_82756054;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82756054:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,11364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82756068
	if (!cr6.gt) goto loc_82756068;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82756068:
	// fdivs f0,f12,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 / f0.f64));
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// stfs f11,4(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 4, temp.u32);
loc_82756074:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82756078:
	// addi r1,r1,4352
	ctx.r1.s64 = ctx.r1.s64 + 4352;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82756080"))) PPC_WEAK_FUNC(sub_82756080);
PPC_FUNC_IMPL(__imp__sub_82756080) {
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
	// bl 0x823d91f4
	ctx.lr = 0x82756088;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d0
	ctx.lr = 0x82756090;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lfs f27,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	f27.f64 = double(temp.f32);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lfs f28,108(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	f28.f64 = double(temp.f32);
	// lfs f31,44(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	f31.f64 = double(temp.f32);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lfs f30,60(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	f30.f64 = double(temp.f32);
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
	// lfs f29,48(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	f29.f64 = double(temp.f32);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lfs f26,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	f26.f64 = double(temp.f32);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x827560d4
	if (cr6.lt) goto loc_827560D4;
	// li r11,0
	r11.s64 = 0;
loc_827560D4:
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r9,-1120
	r28.s64 = ctx.r9.s64 + -1120;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfsx f0,r11,r28
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + r28.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// bne cr6,0x827560f8
	if (!cr6.eq) goto loc_827560F8;
	// stfs f27,4(r30)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// b 0x827560fc
	goto loc_827560FC;
loc_827560F8:
	// stfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
loc_827560FC:
	// lwa r11,8(r29)
	r11.s64 = int32_t(PPC_LOAD_U32(r29.u32 + 8));
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,-760(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -760);
	f0.f64 = double(temp.f32);
	// lfs f13,-764(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -764);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f1,f12,f0,f13
	ctx.f1.f64 = double(float(-(ctx.f12.f64 * f0.f64 - ctx.f13.f64)));
	// bl 0x823dcb38
	ctx.lr = 0x82756128;
	sub_823DCB38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f0,-11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11360);
	f0.f64 = double(temp.f32);
	// lfs f13,-17876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -17876);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 / ctx.f12.f64));
	// fmuls f12,f12,f30
	ctx.f12.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmadds f12,f12,f31,f29
	ctx.f12.f64 = double(float(ctx.f12.f64 * f31.f64 + f29.f64));
	// fdivs f0,f0,f12
	f0.f64 = double(float(f0.f64 / ctx.f12.f64));
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8275615c
	if (!cr6.lt) goto loc_8275615C;
	// stfs f13,0(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
loc_8275615C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,26200(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26200);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82756174
	if (!cr6.gt) goto loc_82756174;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
loc_82756174:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-28872(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28872);
	f0.f64 = double(temp.f32);
	// fmuls f0,f28,f0
	f0.f64 = double(float(f28.f64 * f0.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x827561b8
	if (cr6.gt) goto loc_827561B8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-32032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32032);
	f0.f64 = double(temp.f32);
	// fmuls f0,f28,f0
	f0.f64 = double(float(f28.f64 * f0.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x827561b8
	if (cr6.lt) goto loc_827561B8;
	// fadds f13,f13,f28
	ctx.f13.f64 = double(float(ctx.f13.f64 + f28.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// b 0x82756214
	goto loc_82756214;
loc_827561B8:
	// fcmpu cr6,f27,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, ctx.f12.f64);
	// ble cr6,0x827561cc
	if (!cr6.gt) goto loc_827561CC;
	// fmr f0,f28
	f0.f64 = f28.f64;
	// fmr f12,f27
	ctx.f12.f64 = f27.f64;
	// b 0x827561d0
	goto loc_827561D0;
loc_827561CC:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
loc_827561D0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f11,27632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27632);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x82756214
	if (!cr6.lt) goto loc_82756214;
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f10,f12
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x82756214
	if (!cr6.lt) goto loc_82756214;
	// fcmpu cr6,f13,f28
	cr6.compare(ctx.f13.f64, f28.f64);
	// ble cr6,0x82756210
	if (!cr6.gt) goto loc_82756210;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x82756214
	goto loc_82756214;
loc_82756210:
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = f28.f64;
loc_82756214:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// blt cr6,0x82756228
	if (cr6.lt) goto loc_82756228;
	// li r11,0
	r11.s64 = 0;
loc_82756228:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r28,32
	ctx.r10.s64 = r28.s64 + 32;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r4,r30,20
	ctx.r4.s64 = r30.s64 + 20;
	// addi r3,r29,12
	ctx.r3.s64 = r29.s64 + 12;
	// lfsx f0,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// lfs f1,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82759d98
	ctx.lr = 0x82756250;
	sub_82759D98(ctx, base);
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f26
	f0.f64 = double(float(f0.f64 * f26.f64));
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba1c
	ctx.lr = 0x82756268;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8275626C"))) PPC_WEAK_FUNC(sub_8275626C);
PPC_FUNC_IMPL(__imp__sub_8275626C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82756270"))) PPC_WEAK_FUNC(sub_82756270);
PPC_FUNC_IMPL(__imp__sub_82756270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82756278;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// sth r7,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r7.u16);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// li r27,0
	r27.s64 = 0;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r29.u32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lhz r24,0(r30)
	r24.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// lbz r23,0(r29)
	r23.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lwz r20,4(r31)
	r20.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// mr r28,r27
	r28.u64 = r27.u64;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// addi r22,r11,-832
	r22.s64 = r11.s64 + -832;
loc_827562C4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwzx r5,r28,r22
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + r22.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8275a530
	ctx.lr = 0x827562D4;
	sub_8275A530(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// stwx r10,r28,r11
	PPC_STORE_U32(r28.u32 + r11.u32, ctx.r10.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r28,68
	cr6.compare<int32_t>(r28.s32, 68, xer);
	// blt cr6,0x827562c4
	if (cr6.lt) goto loc_827562C4;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82756080
	ctx.lr = 0x82756300;
	sub_82756080(ctx, base);
	// lhz r11,92(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 92);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82756330
	if (!cr6.eq) goto loc_82756330;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// lwz r10,484(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 484);
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// lhz r8,58(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// lhz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// lfs f2,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f1,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8275a0c0
	ctx.lr = 0x82756330;
	sub_8275A0C0(ctx, base);
loc_82756330:
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8275a018
	ctx.lr = 0x82756344;
	sub_8275A018(ctx, base);
	// lwz r11,492(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 492);
	// li r10,80
	ctx.r10.s64 = 80;
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f0.f64 = double(temp.f32);
	// lis r28,-32111
	r28.s64 = -2104426496;
	// sth r10,0(r26)
	PPC_STORE_U16(r26.u32 + 0, ctx.r10.u16);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lhz r11,92(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275638c
	if (!cr6.eq) goto loc_8275638C;
	// li r11,1
	r11.s64 = 1;
	// li r5,8
	ctx.r5.s64 = 8;
	// sth r11,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r11.u16);
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// lwz r11,-21244(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -21244);
	// addi r3,r31,108
	ctx.r3.s64 = r31.s64 + 108;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756388;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82756430
	goto loc_82756430;
loc_8275638C:
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// sth r27,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r27.u16);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// sth r24,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r24.u16);
	// stb r23,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r23.u8);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lhz r8,94(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 94);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// bne cr6,0x82756430
	if (!cr6.eq) goto loc_82756430;
	// mr r11,r27
	r11.u64 = r27.u64;
	// sth r27,94(r31)
	PPC_STORE_U16(r31.u32 + 94, r27.u16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82756430
	if (!cr6.gt) goto loc_82756430;
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
loc_827563E0:
	// lha r8,0(r10)
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r10.u32 + 0));
	// extsw r7,r11
	ctx.r7.s64 = r11.s32;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// lhz r8,110(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 110);
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// blt cr6,0x827563e0
	if (cr6.lt) goto loc_827563E0;
loc_82756430:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,260
	ctx.r5.s64 = 260;
	// lwz r11,-21244(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -21244);
	// addi r4,r20,2056
	ctx.r4.s64 = r20.s64 + 2056;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r5,260
	ctx.r5.s64 = 260;
	// lwz r11,-21244(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -21244);
	// addi r4,r20,2316
	ctx.r4.s64 = r20.s64 + 2316;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82756468"))) PPC_WEAK_FUNC(sub_82756468);
PPC_FUNC_IMPL(__imp__sub_82756468) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82756470;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82756488
	if (!cr6.eq) goto loc_82756488;
loc_82756480:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82756630
	goto loc_82756630;
loc_82756488:
	// lis r29,-32111
	r29.s64 = -2104426496;
	// li r30,0
	r30.s64 = 0;
	// li r4,116
	ctx.r4.s64 = 116;
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-21256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21256);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827564A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82756480
	if (cr0.eq) goto loc_82756480;
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f12,12892(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12892);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// li r10,100
	ctx.r10.s64 = 100;
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// sth r11,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r11.u16);
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// lfs f12,21588(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 21588);
	ctx.f12.f64 = double(temp.f32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lfs f11,31016(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31016);
	ctx.f11.f64 = double(temp.f32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// sth r30,56(r31)
	PPC_STORE_U16(r31.u32 + 56, r30.u16);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// sth r30,58(r31)
	PPC_STORE_U16(r31.u32 + 58, r30.u16);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stfs f13,48(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// sth r30,94(r31)
	PPC_STORE_U16(r31.u32 + 94, r30.u16);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// sth r10,96(r31)
	PPC_STORE_U16(r31.u32 + 96, ctx.r10.u16);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// li r3,644
	ctx.r3.s64 = 644;
	// stfs f12,76(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f13,80(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f11,108(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// lwz r11,-21256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21256);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82756480
	if (cr0.eq) goto loc_82756480;
	// lwz r11,-21256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21256);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,80
	ctx.r3.s64 = 80;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756590;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82756480
	if (cr0.eq) goto loc_82756480;
	// lwz r11,-21256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21256);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,65
	ctx.r3.s64 = 65;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827565B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82756480
	if (cr0.eq) goto loc_82756480;
	// lwz r11,-21256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21256);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,65
	ctx.r3.s64 = 65;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827565D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82756480
	if (cr0.eq) goto loc_82756480;
	// lwz r11,-21256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21256);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,102
	ctx.r3.s64 = 102;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827565F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82756480
	if (cr0.eq) goto loc_82756480;
	// lwz r11,-21256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -21256);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,104
	ctx.r3.s64 = 104;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82756480
	if (cr0.eq) goto loc_82756480;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8275a620
	ctx.lr = 0x82756624;
	sub_8275A620(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = r11.u64 ^ 1;
loc_82756630:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82756638"))) PPC_WEAK_FUNC(sub_82756638);
PPC_FUNC_IMPL(__imp__sub_82756638) {
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
	ctx.lr = 0x82756640;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82756718
	if (cr6.eq) goto loc_82756718;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82756674
	if (cr6.eq) goto loc_82756674;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756670;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
loc_82756674:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8275a6a0
	ctx.lr = 0x8275667C;
	sub_8275A6A0(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82756698
	if (cr6.eq) goto loc_82756698;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756694;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
loc_82756698:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827566b4
	if (cr6.eq) goto loc_827566B4;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827566B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
loc_827566B4:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827566d0
	if (cr6.eq) goto loc_827566D0;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827566CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
loc_827566D0:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827566ec
	if (cr6.eq) goto loc_827566EC;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827566E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
loc_827566EC:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82756708
	if (cr6.eq) goto loc_82756708;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
loc_82756708:
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756718;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82756718:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82756724"))) PPC_WEAK_FUNC(sub_82756724);
PPC_FUNC_IMPL(__imp__sub_82756724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82756728"))) PPC_WEAK_FUNC(sub_82756728);
PPC_FUNC_IMPL(__imp__sub_82756728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
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
	// bl 0x823d91ec
	ctx.lr = 0x82756730;
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-2576(r1)
	ea = -2576 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// lis r25,-32111
	r25.s64 = -2104426496;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// srawi r28,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	r28.s64 = ctx.r5.s32 >> 1;
	// stfs f2,2660(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 2660, temp.u32);
	// stfs f29,2668(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 2668, temp.u32);
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// lwz r11,-21248(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -21248);
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// li r5,1028
	ctx.r5.s64 = 1028;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82756788;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-21248(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -21248);
	// li r5,1028
	ctx.r5.s64 = 1028;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1456
	ctx.r3.s64 = ctx.r1.s64 + 1456;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827567A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82756838
	if (!cr6.gt) goto loc_82756838;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// mr r11,r30
	r11.u64 = r30.u64;
	// lfs f0,14884(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// subf r9,r30,r29
	ctx.r9.s64 = r29.s64 - r30.s64;
	// lwz r7,-3628(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + -3628);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// lwz r8,-3624(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + -3624);
	// lfs f13,12872(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12872);
	ctx.f13.f64 = double(temp.f32);
loc_827567D4:
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f12,f31,f0
	ctx.f12.f64 = double(float(f31.f64 + f0.f64));
	// fmadds f11,f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + f0.f64));
	// lfsx f10,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 * f0.f64));
	// addi r6,r1,416
	ctx.r6.s64 = ctx.r1.s64 + 416;
	// addi r5,r1,1456
	ctx.r5.s64 = ctx.r1.s64 + 1456;
	// fadds f31,f31,f30
	f31.f64 = double(float(f31.f64 + f30.f64));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// fctiwz f12,f12
	ctx.f12.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f12,f11
	ctx.f12.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r4,r4,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r3,2,22,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// lfsx f12,r3,r8
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f12,f10
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// stfsx f12,r4,r6
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r6.u32, temp.u32);
	// lfsx f12,r3,r7
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f12,f10
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// stfsx f12,r4,r5
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, temp.u32);
	// bne 0x827567d4
	if (!cr0.eq) goto loc_827567D4;
loc_82756838:
	// li r5,512
	ctx.r5.s64 = 512;
	// addi r4,r1,1456
	ctx.r4.s64 = ctx.r1.s64 + 1456;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x82758228
	ctx.lr = 0x82756848;
	sub_82758228(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// ble cr6,0x8275687c
	if (!cr6.gt) goto loc_8275687C;
	// extsw r11,r28
	r11.s64 = r28.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fdivs f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// b 0x82756880
	goto loc_82756880;
loc_8275687C:
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = f0.f64;
loc_82756880:
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// addi r10,r1,1280
	ctx.r10.s64 = ctx.r1.s64 + 1280;
	// addi r9,r1,2320
	ctx.r9.s64 = ctx.r1.s64 + 2320;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r11,40
	r11.s64 = 40;
loc_82756894:
	// fadds f11,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f0.f64 + ctx.f12.f64));
	// lfs f10,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f0,f0,f10
	f0.f64 = double(float(f0.f64 * ctx.f10.f64));
	// lfs f10,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f8,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lfs f7,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// fmuls f10,f10,f11
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fmadds f0,f8,f13,f0
	f0.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + f0.f64));
	// stfs f0,0(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// fadds f0,f11,f12
	f0.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// fsubs f13,f9,f12
	ctx.f13.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// fmadds f11,f7,f9,f10
	ctx.f11.f64 = double(float(ctx.f7.f64 * ctx.f9.f64 + ctx.f10.f64));
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x82756894
	if (!cr0.eq) goto loc_82756894;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,12892(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12892);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f29,f0
	cr6.compare(f29.f64, f0.f64);
	// beq cr6,0x827569e4
	if (cr6.eq) goto loc_827569E4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,2660
	ctx.r8.s64 = ctx.r1.s64 + 2660;
	// addi r7,r1,2660
	ctx.r7.s64 = ctx.r1.s64 + 2660;
	// lfs f0,-124(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -124);
	f0.f64 = double(temp.f32);
	// addi r11,r1,2668
	r11.s64 = ctx.r1.s64 + 2668;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,2668
	ctx.r6.s64 = ctx.r1.s64 + 2668;
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvlx128 v60,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvlx128 v63,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r5,r1,2660
	ctx.r5.s64 = ctx.r1.s64 + 2660;
	// addi r8,r1,2660
	ctx.r8.s64 = ctx.r1.s64 + 2660;
	// lvlx128 v59,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v62,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r1,2668
	r11.s64 = ctx.r1.s64 + 2668;
	// lvlx128 v57,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r7,r1,2668
	ctx.r7.s64 = ctx.r1.s64 + 2668;
	// lvlx128 v56,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v62,v63,4,3
	simde_mm_store_ps(v62.f32, simde_mm_blend_ps(simde_mm_load_ps(v62.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 57), 4));
	// lvlx128 v58,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v60,v61,4,3
	simde_mm_store_ps(v60.f32, simde_mm_blend_ps(simde_mm_load_ps(v60.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 57), 4));
	// vrlimi128 v58,v59,4,3
	simde_mm_store_ps(v58.f32, simde_mm_blend_ps(simde_mm_load_ps(v58.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 57), 4));
	// lvlx128 v59,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v55,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v63,v62,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r10,20
	ctx.r10.s64 = 20;
	// vrlimi128 v56,v57,4,3
	simde_mm_store_ps(v56.f32, simde_mm_blend_ps(simde_mm_load_ps(v56.f32), simde_mm_permute_ps(simde_mm_load_ps(v57.f32), 57), 4));
	// lvlx128 v57,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v57,v59,4,3
	simde_mm_store_ps(v57.f32, simde_mm_blend_ps(simde_mm_load_ps(v57.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 57), 4));
	// lvlx128 v59,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v62,v58,v58
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// mr r11,r27
	r11.u64 = r27.u64;
	// vrlimi128 v59,v55,4,3
	simde_mm_store_ps(v59.f32, simde_mm_blend_ps(simde_mm_load_ps(v59.f32), simde_mm_permute_ps(simde_mm_load_ps(v55.f32), 57), 4));
	// vor128 v61,v56,v56
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vrlimi128 v63,v57,3,2
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v57.f32), 78), 3));
	// vrlimi128 v62,v59,3,2
	simde_mm_store_ps(v62.f32, simde_mm_blend_ps(simde_mm_load_ps(v62.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 78), 3));
	// vrlimi128 v61,v60,3,2
	simde_mm_store_ps(v61.f32, simde_mm_blend_ps(simde_mm_load_ps(v61.f32), simde_mm_permute_ps(simde_mm_load_ps(v60.f32), 78), 3));
loc_827569A4:
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,4
	ctx.r8.s64 = 4;
	// vmulfp128 v60,v60,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// vmulfp128 v60,v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vmulfp128 v60,v60,v62
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vcfpsxws128 v60,v60,0
	simde_mm_store_si128((simde__m128i*)v60.s32, simde_mm_vctsxs(simde_mm_load_ps(v60.f32)));
	// vpkswss128 v60,v60,v60
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v60,v60,1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// stvewx128 v59,r0,r11
	ea = (r11.u32) & ~0x3;
	PPC_STORE_U32(ea, v59.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v60,r11,r8
	ea = (r11.u32 + ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, v60.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x827569a4
	if (!cr0.eq) goto loc_827569A4;
	// b 0x82756a20
	goto loc_82756A20;
loc_827569E4:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r10,20
	ctx.r10.s64 = 20;
loc_827569F0:
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,4
	ctx.r8.s64 = 4;
	// vcfpsxws128 v63,v63,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_si128((simde__m128i*)v63.s32, simde_mm_vctsxs(simde_mm_load_ps(v63.f32)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// vpkswss128 v63,v63,v63
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v63,v63,1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// stvewx128 v62,r0,r11
	ea = (r11.u32) & ~0x3;
	PPC_STORE_U32(ea, v62.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v63,r11,r8
	ea = (r11.u32 + ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, v63.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x827569f0
	if (!cr0.eq) goto loc_827569F0;
loc_82756A20:
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// addi r9,r1,1456
	ctx.r9.s64 = ctx.r1.s64 + 1456;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r11,40
	r11.s64 = 40;
loc_82756A30:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfs f0,0(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f0,0(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x82756a30
	if (!cr0.eq) goto loc_82756A30;
	// addi r1,r1,2576
	ctx.r1.s64 = ctx.r1.s64 + 2576;
	// lfd f29,-88(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82756A6C"))) PPC_WEAK_FUNC(sub_82756A6C);
PPC_FUNC_IMPL(__imp__sub_82756A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82756A70"))) PPC_WEAK_FUNC(sub_82756A70);
PPC_FUNC_IMPL(__imp__sub_82756A70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// extsh r6,r4
	ctx.r6.s64 = ctx.r4.s16;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi r4,0
	cr0.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne 0x82756aa4
	if (!cr0.eq) goto loc_82756AA4;
	// stb r6,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r6.u8);
	// b 0x82756abc
	goto loc_82756ABC;
loc_82756AA4:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// lbz r31,0(r9)
	r31.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// slw r8,r4,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r8.u8 & 0x3F));
	// or r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 | r31.u64;
	// stb r8,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
loc_82756ABC:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r8,8
	cr6.compare<uint32_t>(ctx.r8.u32, 8, xer);
	// ble cr6,0x82756b2c
	if (!cr6.gt) goto loc_82756B2C;
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// clrlwi r7,r7,16
	ctx.r7.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// blt cr6,0x82756b00
	if (cr6.lt) goto loc_82756B00;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_82756B00:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsh r8,r6
	ctx.r8.s64 = ctx.r6.s16;
	// subf r10,r10,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r10.s64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// sraw r10,r8,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r10.s64 = ctx.r8.s32 >> temp.u32;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,248
	ctx.r10.s64 = ctx.r10.s64 + 248;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// b 0x82756b60
	goto loc_82756B60;
loc_82756B2C:
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r9,8
	cr6.compare<uint32_t>(ctx.r9.u32, 8, xer);
	// bne cr6,0x82756b60
	if (!cr6.eq) goto loc_82756B60;
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r8,r7,16
	ctx.r8.u64 = ctx.r7.u32 & 0xFFFF;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lhz r11,0(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x82756b60
	if (cr6.lt) goto loc_82756B60;
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
loc_82756B60:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82756B68"))) PPC_WEAK_FUNC(sub_82756B68);
PPC_FUNC_IMPL(__imp__sub_82756B68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// cmpw cr6,r5,r4
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, xer);
	// blt cr6,0x82756b74
	if (cr6.lt) goto loc_82756B74;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82756B74:
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r11,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82756B80"))) PPC_WEAK_FUNC(sub_82756B80);
PPC_FUNC_IMPL(__imp__sub_82756B80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lfs f0,4792(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4792);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// blelr cr6
	if (!cr6.gt) return;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r9,-16(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
loc_82756BAC:
	// lfs f12,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f11,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// fmuls f12,f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f12,f11,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r11,-16(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x82756be4
	if (!cr6.lt) goto loc_82756BE4;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_82756BE4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x82756bac
	if (cr6.lt) goto loc_82756BAC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82756BF4"))) PPC_WEAK_FUNC(sub_82756BF4);
PPC_FUNC_IMPL(__imp__sub_82756BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82756BF8"))) PPC_WEAK_FUNC(sub_82756BF8);
PPC_FUNC_IMPL(__imp__sub_82756BF8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82756C00;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// lfs f5,4796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4796);
	ctx.f5.f64 = double(temp.f32);
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82756c74
	if (!cr6.gt) goto loc_82756C74;
	// lis r3,32639
	ctx.r3.s64 = 2139029504;
	// clrlwi. r10,r11,2
	ctx.r10.u64 = r11.u32 & 0x3FFFFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// ori r3,r3,65518
	ctx.r3.u64 = ctx.r3.u64 | 65518;
	// beq 0x82756c54
	if (cr0.eq) goto loc_82756C54;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82756C48:
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x82756c48
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82756C48;
loc_82756C54:
	// rlwinm. r10,r4,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// li r4,0
	ctx.r4.s64 = 0;
	// beq 0x82756c74
	if (cr0.eq) goto loc_82756C74;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82756C68:
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x82756c68
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82756C68;
loc_82756C74:
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x82756d20
	if (!cr6.gt) goto loc_82756D20;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f11,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_82756C94:
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f10,-4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// fmuls f0,f0,f0
	f0.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f0,f13,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + f0.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x82756d14
	if (!cr6.lt) goto loc_82756D14;
	// addic. r10,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r10.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x82756d00
	if (!cr0.gt) goto loc_82756D00;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
loc_82756CCC:
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// lfsx f13,r9,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82756d00
	if (cr6.gt) goto loc_82756D00;
	// addi r30,r1,88
	r30.s64 = ctx.r1.s64 + 88;
	// addi r29,r1,84
	r29.s64 = ctx.r1.s64 + 84;
	// addi r28,r1,92
	r28.s64 = ctx.r1.s64 + 92;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwzx r30,r9,r30
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + r30.u32);
	// stfsx f13,r9,r29
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + r29.u32, temp.u32);
	// stwx r30,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, r30.u32);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// bgt 0x82756ccc
	if (cr0.gt) goto loc_82756CCC;
loc_82756D00:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r30,r1,88
	r30.s64 = ctx.r1.s64 + 88;
	// stfsx f0,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// stwx r4,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r4.u32);
loc_82756D14:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r4,r6
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r6.s32, xer);
	// blt cr6,0x82756c94
	if (cr6.lt) goto loc_82756C94;
loc_82756D20:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82756e60
	if (!cr6.gt) goto loc_82756E60;
	// mr r25,r11
	r25.u64 = r11.u64;
	// lwz r28,284(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r26,r1,88
	r26.s64 = ctx.r1.s64 + 88;
	// lfs f6,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f6.f64 = double(temp.f32);
loc_82756D3C:
	// lwz r29,0(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmplw cr6,r29,r6
	cr6.compare<uint32_t>(r29.u32, ctx.r6.u32, xer);
	// blt cr6,0x82756d50
	if (cr6.lt) goto loc_82756D50;
	// li r11,0
	r11.s64 = 0;
loc_82756D50:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f10,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r10,r29,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// add r31,r10,r8
	r31.u64 = ctx.r10.u64 + ctx.r8.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f0,f10,f8
	f0.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// fsubs f13,f9,f7
	ctx.f13.f64 = double(float(ctx.f9.f64 - ctx.f7.f64));
	// lfs f12,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f4,f12,f0
	ctx.f4.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmsubs f13,f11,f13,f4
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 - ctx.f4.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f0,f11,f0,f12
	f0.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ble cr6,0x82756dc4
	if (!cr6.gt) goto loc_82756DC4;
	// lwz r11,292(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
loc_82756DA8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// beq cr6,0x82756e78
	if (cr6.eq) goto loc_82756E78;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r28
	cr6.compare<int32_t>(ctx.r10.s32, r28.s32, xer);
	// blt cr6,0x82756da8
	if (cr6.lt) goto loc_82756DA8;
loc_82756DC4:
	// mr r30,r23
	r30.u64 = r23.u64;
loc_82756DC8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82756b80
	ctx.lr = 0x82756DD4;
	sub_82756B80(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r5
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, xer);
	// blt cr6,0x82756de4
	if (cr6.lt) goto loc_82756DE4;
	// li r11,0
	r11.s64 = 0;
loc_82756DE4:
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f4,f0,f11
	ctx.f4.f64 = double(float(f0.f64 * ctx.f11.f64));
	// lfs f3,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f11,f12,f11
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmadds f13,f12,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmsubs f12,f12,f3,f4
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f3.f64 - ctx.f4.f64));
	// fmadds f0,f0,f3,f11
	f0.f64 = double(float(f0.f64 * ctx.f3.f64 + ctx.f11.f64));
	// fdivs f13,f6,f13
	ctx.f13.f64 = double(float(ctx.f6.f64 / ctx.f13.f64));
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fadds f0,f12,f8
	f0.f64 = double(float(ctx.f12.f64 + ctx.f8.f64));
	// fadds f13,f13,f7
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f7.f64));
	// fsubs f12,f10,f0
	ctx.f12.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f11,f9,f13
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fmuls f12,f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f12,f11,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fcmpu cr6,f12,f5
	cr6.compare(ctx.f12.f64, ctx.f5.f64);
	// bge cr6,0x82756e54
	if (!cr6.lt) goto loc_82756E54;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f5,f12
	ctx.f5.f64 = ctx.f12.f64;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r29,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r29.u32);
	// stw r3,4(r24)
	PPC_STORE_U32(r24.u32 + 4, ctx.r3.u32);
loc_82756E54:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x82756d3c
	if (!cr0.eq) goto loc_82756D3C;
loc_82756E60:
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// stfs f13,4(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 4, temp.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9234
	return;
loc_82756E78:
	// lwz r30,276(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// b 0x82756dc8
	goto loc_82756DC8;
}

__attribute__((alias("__imp__sub_82756E80"))) PPC_WEAK_FUNC(sub_82756E80);
PPC_FUNC_IMPL(__imp__sub_82756E80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x82756E88;
	// stfd f31,-144(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -144, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// addi r23,r10,-3744
	r23.s64 = ctx.r10.s64 + -3744;
	// lfs f0,-32032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32032);
	f0.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// addi r11,r11,-752
	r11.s64 = r11.s64 + -752;
	// ble cr6,0x82756ec8
	if (!cr6.gt) goto loc_82756EC8;
	// addi r10,r11,1644
	ctx.r10.s64 = r11.s64 + 1644;
	// mr r21,r11
	r21.u64 = r11.u64;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// b 0x82756ed4
	goto loc_82756ED4;
loc_82756EC8:
	// addi r10,r11,2744
	ctx.r10.s64 = r11.s64 + 2744;
	// addi r21,r11,48
	r21.s64 = r11.s64 + 48;
	// addi r9,r23,24
	ctx.r9.s64 = r23.s64 + 24;
loc_82756ED4:
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// addi r10,r11,3600
	ctx.r10.s64 = r11.s64 + 3600;
	// addi r8,r11,4324
	ctx.r8.s64 = r11.s64 + 4324;
	// addi r11,r11,4984
	r11.s64 = r11.s64 + 4984;
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// ble cr6,0x82756f28
	if (!cr6.gt) goto loc_82756F28;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// mr r11,r21
	r11.u64 = r21.u64;
	// subf r7,r21,r10
	ctx.r7.s64 = ctx.r10.s64 - r21.s64;
	// subf r8,r21,r19
	ctx.r8.s64 = r19.s64 - r21.s64;
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
loc_82756F0C:
	// lfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfsx f0,r7,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82756f0c
	if (!cr0.eq) goto loc_82756F0C;
loc_82756F28:
	// addi r11,r23,48
	r11.s64 = r23.s64 + 48;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r30,r11,-16
	r30.s64 = r11.s64 + -16;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r25,0
	r25.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// addi r31,r1,144
	r31.s64 = ctx.r1.s64 + 144;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// addi r26,r1,148
	r26.s64 = ctx.r1.s64 + 148;
	// subf r22,r10,r9
	r22.s64 = ctx.r9.s64 - ctx.r10.s64;
loc_82756F5C:
	// lwzx r11,r22,r28
	r11.u64 = PPC_LOAD_U32(r22.u32 + r28.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// li r8,2
	ctx.r8.s64 = 2;
loc_82756F70:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82756f9c
	if (!cr6.gt) goto loc_82756F9C;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
loc_82756F84:
	// lfsx f13,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// fmadds f0,f13,f12,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + f0.f64));
	// bne 0x82756f84
	if (!cr0.eq) goto loc_82756F84;
loc_82756F9C:
	// stfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r10,r27,r10
	ctx.r10.u64 = r27.u64 + ctx.r10.u64;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x82756f70
	if (!cr0.eq) goto loc_82756F70;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r24,4
	cr6.compare<int32_t>(r24.s32, 4, xer);
	// lfs f13,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f2,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f0,f2
	f0.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsubs f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f13,0(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// bge cr6,0x8275701c
	if (!cr6.lt) goto loc_8275701C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r18,28(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r17,24(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r16,20(r11)
	r16.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r18,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r18.u32);
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r17.u32);
	// stw r16,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r16.u32);
	// bl 0x82756bf8
	ctx.lr = 0x82757018;
	sub_82756BF8(ctx, base);
	// b 0x82757070
	goto loc_82757070;
loc_8275701C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82756b80
	ctx.lr = 0x82757030;
	sub_82756B80(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// rotlwi r11,r3,0
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// blt cr6,0x82757058
	if (cr6.lt) goto loc_82757058;
	// li r11,0
	r11.s64 = 0;
loc_82757058:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
loc_82757070:
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r6,r23,48
	ctx.r6.s64 = r23.s64 + 48;
	// fadds f0,f2,f0
	f0.f64 = double(float(ctx.f2.f64 + f0.f64));
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lfs f0,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// addi r10,r25,1
	ctx.r10.s64 = r25.s64 + 1;
	// fadds f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 + f0.f64));
	// addi r9,r27,4
	ctx.r9.s64 = r27.s64 + 4;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// addi r8,r26,4
	ctx.r8.s64 = r26.s64 + 4;
	// addi r7,r29,4
	ctx.r7.s64 = r29.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// addi r25,r10,1
	r25.s64 = ctx.r10.s64 + 1;
	// addi r27,r9,4
	r27.s64 = ctx.r9.s64 + 4;
	// addi r26,r8,4
	r26.s64 = ctx.r8.s64 + 4;
	// addi r29,r7,4
	r29.s64 = ctx.r7.s64 + 4;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r30,r6
	cr6.compare<int32_t>(r30.s32, ctx.r6.s32, xer);
	// blt cr6,0x82756f5c
	if (cr6.lt) goto loc_82756F5C;
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// ble cr6,0x82757108
	if (!cr6.gt) goto loc_82757108;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// subf r9,r10,r21
	ctx.r9.s64 = r21.s64 - ctx.r10.s64;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// subf r8,r8,r19
	ctx.r8.s64 = r19.s64 - ctx.r8.s64;
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
loc_827570EC:
	// lfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfsx f0,r8,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827570ec
	if (!cr0.eq) goto loc_827570EC;
loc_82757108:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-144(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82757114"))) PPC_WEAK_FUNC(sub_82757114);
PPC_FUNC_IMPL(__imp__sub_82757114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82757118"))) PPC_WEAK_FUNC(sub_82757118);
PPC_FUNC_IMPL(__imp__sub_82757118) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,4800
	r11.s64 = r11.s64 + 4800;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fmuls f0,f0,f0
	f0.f64 = double(float(f0.f64 * f0.f64));
loc_82757138:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f1,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82757154
	if (!cr6.lt) goto loc_82757154;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
loc_82757154:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r8,r11,256
	ctx.r8.s64 = r11.s64 + 256;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x82757138
	if (cr6.lt) goto loc_82757138;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275716C"))) PPC_WEAK_FUNC(sub_8275716C);
PPC_FUNC_IMPL(__imp__sub_8275716C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82757170"))) PPC_WEAK_FUNC(sub_82757170);
PPC_FUNC_IMPL(__imp__sub_82757170) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-17876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17876);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82757190
	if (cr6.gt) goto loc_82757190;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_82757190:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f0,26200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26200);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x827571a4
	if (!cr6.gt) goto loc_827571A4;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_827571A4:
	// bl 0x823db788
	ctx.lr = 0x827571A8;
	sub_823DB788(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfd f0,5064(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 5064);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsub f12,f0,f1
	ctx.f12.f64 = f0.f64 - ctx.f1.f64;
	// lfs f0,5056(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5056);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// ble cr6,0x827571f0
	if (!cr6.gt) goto loc_827571F0;
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x82757200
	goto loc_82757200;
loc_827571F0:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_82757200:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82757210"))) PPC_WEAK_FUNC(sub_82757210);
PPC_FUNC_IMPL(__imp__sub_82757210) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// frsp f12,f0
	ctx.f12.f64 = double(float(f0.f64));
	// lfs f0,-760(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -760);
	f0.f64 = double(temp.f32);
	// lfs f13,-764(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -764);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f1,f12,f0,f13
	ctx.f1.f64 = double(float(-(ctx.f12.f64 * f0.f64 - ctx.f13.f64)));
	// bl 0x823dcb38
	ctx.lr = 0x82757248;
	sub_823DCB38(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275725C"))) PPC_WEAK_FUNC(sub_8275725C);
PPC_FUNC_IMPL(__imp__sub_8275725C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82757260"))) PPC_WEAK_FUNC(sub_82757260);
PPC_FUNC_IMPL(__imp__sub_82757260) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// fmuls f0,f3,f3
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f3.f64 * ctx.f3.f64));
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r11,r11,5072
	r11.s64 = r11.s64 + 5072;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
loc_8275727C:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f3,f13
	ctx.f13.f64 = double(float(ctx.f3.f64 - ctx.f13.f64));
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82757298
	if (!cr6.lt) goto loc_82757298;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_82757298:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x8275727c
	if (cr6.lt) goto loc_8275727C;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f0,f1,f2
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// lfsx f13,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f2
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f2.f64));
	// fmuls f0,f0,f0
	f0.f64 = double(float(f0.f64 * f0.f64));
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x827572d0
	if (!cr6.lt) goto loc_827572D0;
	// li r7,1
	ctx.r7.s64 = 1;
loc_827572D0:
	// rlwinm r11,r7,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827572DC"))) PPC_WEAK_FUNC(sub_827572DC);
PPC_FUNC_IMPL(__imp__sub_827572DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827572E0"))) PPC_WEAK_FUNC(sub_827572E0);
PPC_FUNC_IMPL(__imp__sub_827572E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827572E8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r29,r3,0,28,28
	r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// subf r5,r29,r3
	ctx.r5.s64 = ctx.r3.s64 - r29.s64;
	// addi r3,r11,5072
	ctx.r3.s64 = r11.s64 + 5072;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x82756b68
	ctx.lr = 0x82757314;
	sub_82756B68(ctx, base);
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x82757328
	if (!cr6.eq) goto loc_82757328;
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// b 0x8275732c
	goto loc_8275732C;
loc_82757328:
	// stfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
loc_8275732C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82757338"))) PPC_WEAK_FUNC(sub_82757338);
PPC_FUNC_IMPL(__imp__sub_82757338) {
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
	ctx.lr = 0x82757340;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d0
	ctx.lr = 0x82757348;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lwz r30,40(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f29,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	f29.f64 = double(temp.f32);
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// lfs f28,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f28.f64 = double(temp.f32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lfs f27,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f27.f64 = double(temp.f32);
	// li r5,161
	ctx.r5.s64 = 161;
	// lfs f26,16828(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16828);
	f26.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lfsx f31,r8,r31
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	f31.f64 = double(temp.f32);
	// li r27,0
	r27.s64 = 0;
	// lfsx f30,r8,r28
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	f30.f64 = double(temp.f32);
	// addi r25,r11,-150
	r25.s64 = r11.s64 + -150;
	// bl 0x82758108
	ctx.lr = 0x827573A8;
	sub_82758108(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// lfs f12,5108(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,5104(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 5104);
	ctx.f11.f64 = double(temp.f32);
loc_827573BC:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f13,f31,f12
	ctx.f13.f64 = double(float(f31.f64 * ctx.f12.f64));
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// lfs f9,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f30,f12
	ctx.f8.f64 = double(float(f30.f64 * ctx.f12.f64));
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// srawi r9,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r30,r9,r10
	r30.s64 = ctx.r10.s64 - ctx.r9.s64;
	// fmadds f31,f0,f10,f13
	f31.f64 = double(float(f0.f64 * ctx.f10.f64 + ctx.f13.f64));
	// fmadds f30,f9,f10,f8
	f30.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f8.f64));
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r10,r31
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f10,r10,r28
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	ctx.f10.f64 = double(temp.f32);
	// stfsx f31,r10,r31
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// stfsx f30,r10,r28
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, temp.u32);
	// fmuls f9,f28,f31
	ctx.f9.f64 = double(float(f28.f64 * f31.f64));
	// fadds f8,f29,f31
	ctx.f8.f64 = double(float(f29.f64 + f31.f64));
	// fadds f7,f28,f30
	ctx.f7.f64 = double(float(f28.f64 + f30.f64));
	// fmuls f0,f29,f31
	f0.f64 = double(float(f29.f64 * f31.f64));
	// fmsubs f9,f29,f30,f9
	ctx.f9.f64 = double(float(f29.f64 * f30.f64 - ctx.f9.f64));
	// fsubs f29,f8,f13
	f29.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsubs f28,f7,f10
	f28.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fabs f13,f9
	ctx.f13.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// blt cr6,0x82757454
	if (cr6.lt) goto loc_82757454;
	// fmuls f10,f13,f27
	ctx.f10.f64 = double(float(ctx.f13.f64 * f27.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f10,f0,f26
	ctx.f10.f64 = double(float(f0.f64 * f26.f64));
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// ble cr6,0x82757454
	if (!cr6.gt) goto loc_82757454;
	// fmr f27,f0
	f27.f64 = f0.f64;
	// mr r27,r11
	r27.u64 = r11.u64;
	// fmr f26,f13
	f26.f64 = ctx.f13.f64;
loc_82757454:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// cmpwi cr6,r11,160
	cr6.compare<int32_t>(r11.s32, 160, xer);
	// blt cr6,0x827573bc
	if (cr6.lt) goto loc_827573BC;
	// srawi r11,r24,1
	xer.ca = (r24.s32 < 0) & ((r24.u32 & 0x1) != 0);
	r11.s64 = r24.s32 >> 1;
	// stfs f29,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f28,36(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// cmpwi cr6,r27,80
	cr6.compare<int32_t>(r27.s32, 80, xer);
	// subf r11,r11,r26
	r11.s64 = r26.s64 - r11.s64;
	// ble cr6,0x827574e4
	if (!cr6.gt) goto loc_827574E4;
	// subfic r10,r27,160
	xer.ca = r27.u32 <= 160;
	ctx.r10.s64 = 160 - r27.s64;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// frsp f11,f0
	ctx.f11.f64 = double(float(f0.f64));
	// lfs f0,-15264(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15264);
	f0.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmadds f0,f12,f0,f13
	f0.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r3,40
	cr6.compare<int32_t>(ctx.r3.s32, 40, xer);
	// ble cr6,0x8275752c
	if (!cr6.gt) goto loc_8275752C;
	// li r3,40
	ctx.r3.s64 = 40;
	// b 0x8275752c
	goto loc_8275752C;
loc_827574E4:
	// mullw r11,r11,r27
	r11.s64 = int64_t(r11.s32) * int64_t(r27.s32);
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f12,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lfs f0,-15264(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -15264);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	f0.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// neg r3,r11
	ctx.r3.s64 = -r11.s64;
	// cmpwi cr6,r3,-40
	cr6.compare<int32_t>(ctx.r3.s32, -40, xer);
	// bge cr6,0x8275752c
	if (!cr6.lt) goto loc_8275752C;
	// li r3,-40
	ctx.r3.s64 = -40;
loc_8275752C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba1c
	ctx.lr = 0x82757538;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8275753C"))) PPC_WEAK_FUNC(sub_8275753C);
PPC_FUNC_IMPL(__imp__sub_8275753C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82757540"))) PPC_WEAK_FUNC(sub_82757540);
PPC_FUNC_IMPL(__imp__sub_82757540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,48
	ctx.r4.s64 = 48;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-21256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21256);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82757570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// bne 0x82757584
	if (!cr0.eq) goto loc_82757584;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827575d8
	goto loc_827575D8;
loc_82757584:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lwz r11,-21248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21248);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827575BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-21248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21248);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827575D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_827575D8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827575F0"))) PPC_WEAK_FUNC(sub_827575F0);
PPC_FUNC_IMPL(__imp__sub_827575F0) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82757628
	if (cr6.eq) goto loc_82757628;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21252(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82757620;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82757628:
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
}

__attribute__((alias("__imp__sub_82757640"))) PPC_WEAK_FUNC(sub_82757640);
PPC_FUNC_IMPL(__imp__sub_82757640) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82757648;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82757660
	if (!cr6.eq) goto loc_82757660;
loc_82757658:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827576e0
	goto loc_827576E0;
loc_82757660:
	// lis r30,-32111
	r30.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// li r4,12
	ctx.r4.s64 = 12;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-21256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21256);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82757680;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82757658
	if (cr0.eq) goto loc_82757658;
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r11,-21256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21256);
	// li r3,13
	ctx.r3.s64 = 13;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827576A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82757658
	if (cr0.eq) goto loc_82757658;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// li r5,52
	ctx.r5.s64 = 52;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,11364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lwz r11,-21248(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21248);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827576DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_827576E0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827576E8"))) PPC_WEAK_FUNC(sub_827576E8);
PPC_FUNC_IMPL(__imp__sub_827576E8) {
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
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8275773c
	if (cr6.eq) goto loc_8275773C;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275772c
	if (cr6.eq) goto loc_8275772C;
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82757724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_8275772C:
	// lwz r11,-21252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275773C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8275773C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82757758"))) PPC_WEAK_FUNC(sub_82757758);
PPC_FUNC_IMPL(__imp__sub_82757758) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addic. r11,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	r11.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// blt 0x8275778c
	if (cr0.lt) goto loc_8275778C;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
loc_82757778:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fadds f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x82757778
	if (!cr0.lt) goto loc_82757778;
loc_8275778C:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f13,14992(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14992);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// blt cr6,0x827577c8
	if (cr6.lt) goto loc_827577C8;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
loc_827577AC:
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x827577c8
	if (!cr6.lt) goto loc_827577C8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x827577ac
	if (!cr0.lt) goto loc_827577AC;
loc_827577C8:
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// cmpwi cr6,r3,76
	cr6.compare<int32_t>(ctx.r3.s32, 76, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r3,76
	ctx.r3.s64 = 76;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827577DC"))) PPC_WEAK_FUNC(sub_827577DC);
PPC_FUNC_IMPL(__imp__sub_827577DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827577E0"))) PPC_WEAK_FUNC(sub_827577E0);
PPC_FUNC_IMPL(__imp__sub_827577E0) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827577E8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// addi r6,r4,1
	ctx.r6.s64 = ctx.r4.s64 + 1;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// srawi. r10,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r31,r1,368
	r31.s64 = ctx.r1.s64 + 368;
	// li r9,0
	ctx.r9.s64 = 0;
	// ble 0x82757840
	if (!cr0.gt) goto loc_82757840;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8275781C:
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stfs f13,0(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8275781c
	if (!cr0.eq) goto loc_8275781C;
loc_82757840:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82757870
	if (cr6.eq) goto loc_82757870;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lfsx f0,r10,r3
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_82757870:
	// subfic r10,r9,65
	xer.ca = ctx.r9.u32 <= 65;
	ctx.r10.s64 = 65 - ctx.r9.s64;
	// lis r28,-32111
	r28.s64 = -2104426496;
	// rlwinm r27,r10,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r11,-21248(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -21248);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82757894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-21248(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -21248);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827578AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827581e8
	ctx.lr = 0x827578BC;
	sub_827581E8(ctx, base);
	// extsw r11,r30
	r11.s64 = r30.s32;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// frsp f12,f0
	ctx.f12.f64 = double(float(f0.f64));
	// lfs f0,16680(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16680);
	f0.f64 = double(temp.f32);
	// lfs f13,6332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6332);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fdivs f0,f0,f12
	f0.f64 = double(float(f0.f64 / ctx.f12.f64));
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8275790c
	if (!cr6.gt) goto loc_8275790C;
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8275791c
	goto loc_8275791C;
loc_8275790C:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8275791C:
	// addic. r11,r30,-1
	xer.ca = r30.u32 > 0;
	r11.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r8,0
	ctx.r8.s64 = 0;
	// ble 0x82757968
	if (!cr0.gt) goto loc_82757968;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// li r10,16384
	ctx.r10.s64 = 16384;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_82757934:
	// srawi r7,r10,15
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 15;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lfsx f0,r7,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f0
	f0.f64 = double(float(f0.f64 * f0.f64));
	// lfsx f13,r7,r4
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + f0.f64));
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x82757934
	if (!cr0.eq) goto loc_82757934;
loc_82757968:
	// mullw r11,r6,r8
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// addi r11,r11,16384
	r11.s64 = r11.s64 + 16384;
	// srawi r11,r11,15
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFF) != 0);
	r11.s64 = r11.s32 >> 15;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// blt cr6,0x82757990
	if (cr6.lt) goto loc_82757990;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// b 0x827579b4
	goto loc_827579B4;
loc_82757990:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f0
	f0.f64 = double(float(f0.f64 * f0.f64));
	// lfsx f13,r11,r9
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + f0.f64));
	// stfsx f0,r8,r29
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + r29.u32, temp.u32);
loc_827579B4:
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827579C0"))) PPC_WEAK_FUNC(sub_827579C0);
PPC_FUNC_IMPL(__imp__sub_827579C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// extsw r11,r4
	r11.s64 = ctx.r4.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// frsp f11,f0
	ctx.f11.f64 = double(float(f0.f64));
	// lfs f0,-28916(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28916);
	f0.f64 = double(temp.f32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f12,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lfs f13,6332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6332);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x82757a34
	if (!cr6.gt) goto loc_82757A34;
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x82757a44
	goto loc_82757A44;
loc_82757A34:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_82757A44:
	// stfs f12,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// addi r9,r8,16384
	ctx.r9.s64 = ctx.r8.s64 + 16384;
	// li r10,63
	ctx.r10.s64 = 63;
loc_82757A54:
	// srawi r7,r9,15
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 15;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lfsx f0,r7,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82757a54
	if (!cr0.eq) goto loc_82757A54;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// li r5,260
	ctx.r5.s64 = 260;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// lwz r11,-21248(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21248);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82757A94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82758228
	ctx.lr = 0x82757AA4;
	sub_82758228(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r6,r30,1
	ctx.r6.s64 = r30.s64 + 1;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// srawi. r7,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// lfs f0,12432(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12432);
	f0.f64 = double(temp.f32);
	// ble 0x82757af4
	if (!cr0.gt) goto loc_82757AF4;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_82757AC4:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r31,4
	ctx.r8.s64 = r31.s64 + 4;
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,0(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fmuls f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r31,r8,4
	r31.s64 = ctx.r8.s64 + 4;
	// bne 0x82757ac4
	if (!cr0.eq) goto loc_82757AC4;
loc_82757AF4:
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// beq cr6,0x82757b0c
	if (cr6.eq) goto loc_82757B0C;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
loc_82757B0C:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82757B24"))) PPC_WEAK_FUNC(sub_82757B24);
PPC_FUNC_IMPL(__imp__sub_82757B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82757B28"))) PPC_WEAK_FUNC(sub_82757B28);
PPC_FUNC_IMPL(__imp__sub_82757B28) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82757B30;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,43
	ctx.r6.s64 = 43;
	// li r5,87
	ctx.r5.s64 = 87;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x827596e0
	ctx.lr = 0x82757B64;
	sub_827596E0(ctx, base);
	// extsw r11,r30
	r11.s64 = r30.s32;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// lfs f0,5672(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5672);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dbaa8
	ctx.lr = 0x82757B88;
	sub_823DBAA8(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	f0.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r31,92(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r31,7
	cr6.compare<int32_t>(r31.s32, 7, xer);
	// ble cr6,0x82757ba0
	if (!cr6.gt) goto loc_82757BA0;
	// li r31,7
	r31.s64 = 7;
loc_82757BA0:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827579c0
	ctx.lr = 0x82757BB4;
	sub_827579C0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f0,5668(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5668);
	f0.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// bl 0x82759280
	ctx.lr = 0x82757BE0;
	sub_82759280(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f1,17324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17324);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827598f0
	ctx.lr = 0x82757BF8;
	sub_827598F0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827577e0
	ctx.lr = 0x82757C0C;
	sub_827577E0(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f0,5664(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5664);
	f0.f64 = double(temp.f32);
	// lfs f13,31308(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82757c94
	if (!cr6.gt) goto loc_82757C94;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
loc_82757C44:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// bge cr6,0x82757c80
	if (!cr6.lt) goto loc_82757C80;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// lfsx f12,r6,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r27.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r6,r5
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// blt cr6,0x82757c80
	if (cr6.lt) goto loc_82757C80;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x82757c80
	if (!cr6.gt) goto loc_82757C80;
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
loc_82757C80:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// blt cr6,0x82757c44
	if (cr6.lt) goto loc_82757C44;
loc_82757C94:
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,3
	ctx.r8.s64 = r11.s64 + 3;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,32767
	ctx.r10.s64 = 32767;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stwx r10,r7,r29
	PPC_STORE_U32(ctx.r7.u32 + r29.u32, ctx.r10.u32);
	// stwx r10,r8,r29
	PPC_STORE_U32(ctx.r8.u32 + r29.u32, ctx.r10.u32);
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82757CD0"))) PPC_WEAK_FUNC(sub_82757CD0);
PPC_FUNC_IMPL(__imp__sub_82757CD0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82757CD8;
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// li r5,92
	ctx.r5.s64 = 92;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x827583f0
	ctx.lr = 0x82757CF4;
	sub_827583F0(ctx, base);
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,92
	ctx.r4.s64 = 92;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82758450
	ctx.lr = 0x82757D08;
	sub_82758450(ctx, base);
	// li r4,86
	ctx.r4.s64 = 86;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82757758
	ctx.lr = 0x82757D14;
	sub_82757758(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// lfs f1,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// addi r5,r1,528
	ctx.r5.s64 = ctx.r1.s64 + 528;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82757b28
	ctx.lr = 0x82757D30;
	sub_82757B28(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82757d54
	if (!cr6.gt) goto loc_82757D54;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_82757D54:
	// addic. r11,r30,-1
	xer.ca = r30.u32 > 0;
	r11.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// blt 0x82757d94
	if (cr0.lt) goto loc_82757D94;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_82757D6C:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fsqrts f13,f13
	ctx.f13.f64 = double(float(sqrt(ctx.f13.f64)));
	// fsqrts f13,f13
	ctx.f13.f64 = double(float(sqrt(ctx.f13.f64)));
	// fsqrts f13,f13
	ctx.f13.f64 = double(float(sqrt(ctx.f13.f64)));
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x82757d6c
	if (!cr0.lt) goto loc_82757D6C;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
loc_82757D94:
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// lfs f1,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lwz r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f2,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// addi r5,r1,528
	ctx.r5.s64 = ctx.r1.s64 + 528;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8275b048
	ctx.lr = 0x82757DC0;
	sub_8275B048(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f1,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8275ada0
	ctx.lr = 0x82757DDC;
	sub_8275ADA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
	// b 0x82757e1c
	goto loc_82757E1C;
loc_82757DEC:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfsx f1,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8275abb8
	ctx.lr = 0x82757E08;
	sub_8275ABB8(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfsx f1,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82757E1C:
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// bge 0x82757dec
	if (!cr0.lt) goto loc_82757DEC;
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// bge cr6,0x82757e94
	if (!cr6.lt) goto loc_82757E94;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,5508
	ctx.r10.s64 = ctx.r10.s64 + 5508;
	// beq cr6,0x82757e64
	if (cr6.eq) goto loc_82757E64;
	// lfs f13,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfsx f13,r8,r7
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82757ec0
	if (cr6.lt) goto loc_82757EC0;
loc_82757E64:
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// rlwinm r8,r31,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// lfsx f13,r9,r10
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfsx f13,r8,r7
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82757ebc
	if (!cr6.lt) goto loc_82757EBC;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// b 0x82757ec0
	goto loc_82757EC0;
loc_82757E94:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,5508
	r11.s64 = r11.s64 + 5508;
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfsx f13,r10,r8
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82757ec0
	if (cr6.lt) goto loc_82757EC0;
loc_82757EBC:
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
loc_82757EC0:
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfsx f1,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	ctx.f1.f64 = double(temp.f32);
	// lfsx f0,r11,r9
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	f0.f64 = double(temp.f32);
	// stfs f1,0(r27)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// stfs f0,4(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 4, temp.u32);
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82757EE4"))) PPC_WEAK_FUNC(sub_82757EE4);
PPC_FUNC_IMPL(__imp__sub_82757EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82757EE8"))) PPC_WEAK_FUNC(sub_82757EE8);
PPC_FUNC_IMPL(__imp__sub_82757EE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,74
	ctx.r10.s64 = 74;
	// addi r11,r11,5160
	r11.s64 = r11.s64 + 5160;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82757F00"))) PPC_WEAK_FUNC(sub_82757F00);
PPC_FUNC_IMPL(__imp__sub_82757F00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-21256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21256);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82757F2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bne 0x82757f40
	if (!cr0.eq) goto loc_82757F40;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82757f60
	goto loc_82757F60;
loc_82757F40:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f0,31016(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
loc_82757F60:
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

__attribute__((alias("__imp__sub_82757F74"))) PPC_WEAK_FUNC(sub_82757F74);
PPC_FUNC_IMPL(__imp__sub_82757F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82757F78"))) PPC_WEAK_FUNC(sub_82757F78);
PPC_FUNC_IMPL(__imp__sub_82757F78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,1492
	ctx.r4.s64 = 1492;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-21256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21256);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82757FAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82757fbc
	if (!cr0.eq) goto loc_82757FBC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82757fd0
	goto loc_82757FD0;
loc_82757FBC:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_82757FD0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82757FE8"))) PPC_WEAK_FUNC(sub_82757FE8);
PPC_FUNC_IMPL(__imp__sub_82757FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82757FF0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// rotlwi r11,r4,1
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r26,r29,8
	r26.s64 = r29.s64 + 8;
	// lwz r24,4(r29)
	r24.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// divw r10,r4,r31
	ctx.r10.s32 = ctx.r4.s32 / r31.s32;
	// twllei r31,0
	// mullw r11,r10,r31
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r31.s32);
	// subf r11,r11,r4
	r11.s64 = ctx.r4.s64 - r11.s64;
	// andc r10,r31,r9
	ctx.r10.u64 = r31.u64 & ~ctx.r9.u64;
	// add r11,r11,r24
	r11.u64 = r11.u64 + r24.u64;
	// twlgei r10,-1
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// twllei r31,0
	// divw r9,r10,r31
	ctx.r9.s32 = ctx.r10.s32 / r31.s32;
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// mullw r9,r9,r31
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r31.s32);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// andc r10,r31,r8
	ctx.r10.u64 = r31.u64 & ~ctx.r8.u64;
	// subf r28,r11,r31
	r28.s64 = r31.s64 - r11.s64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// twlgei r10,-1
	// cmpw cr6,r28,r30
	cr6.compare<int32_t>(r28.s32, r30.s32, xer);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// add r3,r11,r26
	ctx.r3.u64 = r11.u64 + r26.u64;
	// blt cr6,0x8275807c
	if (cr6.lt) goto loc_8275807C;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-21244(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21244);
	// b 0x827580a8
	goto loc_827580A8;
loc_8275807C:
	// lis r23,-32111
	r23.s64 = -2104426496;
	// rlwinm r25,r28,2,0,29
	r25.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwz r10,-21244(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + -21244);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82758094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// subf r11,r28,r30
	r11.s64 = r30.s64 - r28.s64;
	// add r4,r25,r27
	ctx.r4.u64 = r25.u64 + r27.u64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r11,-21244(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -21244);
loc_827580A8:
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827580B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// divw r11,r30,r31
	r11.s32 = r30.s32 / r31.s32;
	// rotlwi r10,r30,1
	ctx.r10.u64 = __builtin_rotateleft32(r30.u32, 1);
	// mullw r11,r11,r31
	r11.s64 = int64_t(r11.s32) * int64_t(r31.s32);
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// add r11,r11,r24
	r11.u64 = r11.u64 + r24.u64;
	// andc r10,r31,r10
	ctx.r10.u64 = r31.u64 & ~ctx.r10.u64;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// twlgei r10,-1
	// divw r10,r9,r31
	ctx.r10.s32 = ctx.r9.s32 / r31.s32;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r10,r10,r31
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r31.s32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// andc r11,r31,r11
	r11.u64 = r31.u64 & ~r11.u64;
	// twllei r31,0
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// twllei r31,0
	// twlgei r11,-1
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82758104"))) PPC_WEAK_FUNC(sub_82758104);
PPC_FUNC_IMPL(__imp__sub_82758104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82758108"))) PPC_WEAK_FUNC(sub_82758108);
PPC_FUNC_IMPL(__imp__sub_82758108) {
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
	ctx.lr = 0x82758110;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r28,r3,8
	r28.s64 = ctx.r3.s64 + 8;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// twllei r11,0
	// neg r8,r10
	ctx.r8.s64 = -ctx.r10.s64;
	// twllei r11,0
	// divw r7,r8,r11
	ctx.r7.s32 = ctx.r8.s32 / r11.s32;
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// mullw r7,r7,r11
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// andc r9,r11,r7
	ctx.r9.u64 = r11.u64 & ~ctx.r7.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// twlgei r9,-1
	// divw r9,r8,r11
	ctx.r9.s32 = ctx.r8.s32 / r11.s32;
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// subf r10,r9,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r9.s64;
	// andc r9,r11,r7
	ctx.r9.u64 = r11.u64 & ~ctx.r7.u64;
	// subf r30,r10,r11
	r30.s64 = r11.s64 - ctx.r10.s64;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// twlgei r9,-1
	// cmpw cr6,r30,r31
	cr6.compare<int32_t>(r30.s32, r31.s32, xer);
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// blt cr6,0x827581a8
	if (cr6.lt) goto loc_827581A8;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// rlwinm r5,r31,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-21244(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21244);
	// b 0x827581d4
	goto loc_827581D4;
loc_827581A8:
	// lis r26,-32111
	r26.s64 = -2104426496;
	// rlwinm r27,r30,2,0,29
	r27.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r11,-21244(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21244);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827581C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r27,r29
	ctx.r3.u64 = r27.u64 + r29.u64;
	// lwz r11,-21244(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -21244);
loc_827581D4:
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827581DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827581E4"))) PPC_WEAK_FUNC(sub_827581E4);
PPC_FUNC_IMPL(__imp__sub_827581E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827581E8"))) PPC_WEAK_FUNC(sub_827581E8);
PPC_FUNC_IMPL(__imp__sub_827581E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827581F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// srawi r11,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	r11.s64 = ctx.r5.s32 >> 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addze r31,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r31.s64 = temp.s64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x8275b660
	ctx.lr = 0x8275820C;
	sub_8275B660(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8275b418
	ctx.lr = 0x8275821C;
	sub_8275B418(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82758224"))) PPC_WEAK_FUNC(sub_82758224);
PPC_FUNC_IMPL(__imp__sub_82758224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82758228"))) PPC_WEAK_FUNC(sub_82758228);
PPC_FUNC_IMPL(__imp__sub_82758228) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82758230;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// srawi r11,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	r11.s64 = ctx.r5.s32 >> 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addze r31,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r31.s64 = temp.s64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x8275b538
	ctx.lr = 0x8275824C;
	sub_8275B538(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8275b660
	ctx.lr = 0x8275825C;
	sub_8275B660(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82758264"))) PPC_WEAK_FUNC(sub_82758264);
PPC_FUNC_IMPL(__imp__sub_82758264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82758268"))) PPC_WEAK_FUNC(sub_82758268);
PPC_FUNC_IMPL(__imp__sub_82758268) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82758270;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// srawi r3,r4,1
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 1;
	// srawi. r11,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	r11.s64 = ctx.r4.s32 >> 2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// subfic r6,r11,256
	xer.ca = r11.u32 <= 256;
	ctx.r6.s64 = 256 - r11.s64;
	// li r8,1
	ctx.r8.s64 = 1;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// slw r5,r8,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r5.u8 & 0x3F));
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// ble 0x827582d0
	if (!cr0.gt) goto loc_827582D0;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_827582A8:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f0,0(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x827582a8
	if (!cr0.eq) goto loc_827582A8;
loc_827582D0:
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// subf r8,r11,r4
	ctx.r8.s64 = ctx.r4.s64 - r11.s64;
	// mr r11,r29
	r11.u64 = r29.u64;
	// srawi. r8,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// li r7,0
	ctx.r7.s64 = 0;
	// ble 0x82758318
	if (!cr0.gt) goto loc_82758318;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
loc_827582F0:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827582f0
	if (!cr0.eq) goto loc_827582F0;
loc_82758318:
	// rlwinm r8,r3,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r4,r8
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r8.s32, xer);
	// beq cr6,0x82758344
	if (cr6.eq) goto loc_82758344;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_82758344:
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// bge cr6,0x8275838c
	if (!cr6.lt) goto loc_8275838C;
	// subf r9,r7,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r7.s64;
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm. r8,r9,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82758370
	if (cr0.eq) goto loc_82758370;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82758364:
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82758364
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82758364;
loc_82758370:
	// rlwinm. r11,r9,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq 0x8275838c
	if (cr0.eq) goto loc_8275838C;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_82758380:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82758380
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82758380;
loc_8275838C:
	// srawi r11,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	r11.s64 = ctx.r5.s32 >> 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addze r31,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r31.s64 = temp.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x8275b660
	ctx.lr = 0x827583A4;
	sub_8275B660(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8275b418
	ctx.lr = 0x827583B4;
	sub_8275B418(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827583BC"))) PPC_WEAK_FUNC(sub_827583BC);
PPC_FUNC_IMPL(__imp__sub_827583BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827583C0"))) PPC_WEAK_FUNC(sub_827583C0);
PPC_FUNC_IMPL(__imp__sub_827583C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blelr cr6
	if (!cr6.gt) return;
loc_827583D0:
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// fmadds f1,f0,f13,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f1.f64));
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bgt 0x827583d0
	if (cr0.gt) goto loc_827583D0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827583F0"))) PPC_WEAK_FUNC(sub_827583F0);
PPC_FUNC_IMPL(__imp__sub_827583F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
loc_827583F8:
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// fmuls f0,f0,f0
	f0.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// fmadds f0,f13,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + f0.f64));
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bgt 0x827583f8
	if (cr0.gt) goto loc_827583F8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82758424"))) PPC_WEAK_FUNC(sub_82758424);
PPC_FUNC_IMPL(__imp__sub_82758424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82758428"))) PPC_WEAK_FUNC(sub_82758428);
PPC_FUNC_IMPL(__imp__sub_82758428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
loc_82758430:
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// fmuls f0,f0,f1
	f0.f64 = double(float(f0.f64 * ctx.f1.f64));
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bgt 0x82758430
	if (cr0.gt) goto loc_82758430;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82758450"))) PPC_WEAK_FUNC(sub_82758450);
PPC_FUNC_IMPL(__imp__sub_82758450) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82758458;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r11
	r30.u64 = r11.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82758578
	if (!cr6.lt) goto loc_82758578;
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r7,r3,12
	ctx.r7.s64 = ctx.r3.s64 + 12;
loc_8275847C:
	// addi r9,r8,3
	ctx.r9.s64 = ctx.r8.s64 + 3;
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// bgt cr6,0x8275852c
	if (cr6.gt) goto loc_8275852C;
	// lwz r9,-8(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x8275849c
	if (!cr6.gt) goto loc_8275849C;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
loc_8275849C:
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// bge cr6,0x827584ac
	if (!cr6.lt) goto loc_827584AC;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
loc_827584AC:
	// lwz r9,-4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x827584c0
	if (!cr6.gt) goto loc_827584C0;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
loc_827584C0:
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// bge cr6,0x827584d0
	if (!cr6.lt) goto loc_827584D0;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
loc_827584D0:
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x827584e4
	if (!cr6.gt) goto loc_827584E4;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r31,r8,1
	r31.s64 = ctx.r8.s64 + 1;
loc_827584E4:
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// bge cr6,0x827584f4
	if (!cr6.lt) goto loc_827584F4;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// addi r29,r8,1
	r29.s64 = ctx.r8.s64 + 1;
loc_827584F4:
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x82758508
	if (!cr6.gt) goto loc_82758508;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r31,r8,2
	r31.s64 = ctx.r8.s64 + 2;
loc_82758508:
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// bge cr6,0x82758518
	if (!cr6.lt) goto loc_82758518;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// addi r29,r8,2
	r29.s64 = ctx.r8.s64 + 2;
loc_82758518:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8275847c
	if (cr6.lt) goto loc_8275847C;
loc_8275852C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82758578
	if (!cr6.lt) goto loc_82758578;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 + ctx.r3.u64;
loc_8275853C:
	// cmpw cr6,r10,r4
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, xer);
	// bge cr6,0x82758578
	if (!cr6.lt) goto loc_82758578;
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x82758558
	if (!cr6.gt) goto loc_82758558;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
loc_82758558:
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// bge cr6,0x82758568
	if (!cr6.lt) goto loc_82758568;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
loc_82758568:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8275853c
	if (cr6.lt) goto loc_8275853C;
loc_82758578:
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r7,r4
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, xer);
	// bgt cr6,0x827585f4
	if (cr6.gt) goto loc_827585F4;
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 + ctx.r3.u64;
loc_82758590:
	// lwz r9,-8(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x827585a4
	if (!cr6.gt) goto loc_827585A4;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
loc_827585A4:
	// lwz r9,-4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x827585b8
	if (!cr6.gt) goto loc_827585B8;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r31,r10,1
	r31.s64 = ctx.r10.s64 + 1;
loc_827585B8:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x827585cc
	if (!cr6.gt) goto loc_827585CC;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r31,r10,2
	r31.s64 = ctx.r10.s64 + 2;
loc_827585CC:
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x827585e0
	if (!cr6.gt) goto loc_827585E0;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r31,r10,3
	r31.s64 = ctx.r10.s64 + 3;
loc_827585E0:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// cmpw cr6,r7,r4
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, xer);
	// ble cr6,0x82758590
	if (!cr6.gt) goto loc_82758590;
loc_827585F4:
	// cmpw cr6,r10,r4
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, xer);
	// bge cr6,0x82758628
	if (!cr6.lt) goto loc_82758628;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 + ctx.r3.u64;
loc_82758604:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x82758618
	if (!cr6.gt) goto loc_82758618;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
loc_82758618:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r10,r4
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, xer);
	// blt cr6,0x82758604
	if (cr6.lt) goto loc_82758604;
loc_82758628:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,-48(r1)
	PPC_STORE_U32(ctx.r1.u32 + -48, r11.u32);
	// bge cr6,0x8275863c
	if (!cr6.lt) goto loc_8275863C;
	// stw r30,-48(r1)
	PPC_STORE_U32(ctx.r1.u32 + -48, r30.u32);
	// blt cr6,0x82758644
	if (cr6.lt) goto loc_82758644;
loc_8275863C:
	// mr r11,r31
	r11.u64 = r31.u64;
	// b 0x82758648
	goto loc_82758648;
loc_82758644:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82758648:
	// lfs f0,-48(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	f0.f64 = double(temp.f32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82758658"))) PPC_WEAK_FUNC(sub_82758658);
PPC_FUNC_IMPL(__imp__sub_82758658) {
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
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82758660;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d8
	ctx.lr = 0x82758668;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r11,r29,-1
	r11.s64 = r29.s64 + -1;
	// extsw r10,r29
	ctx.r10.s64 = r29.s32;
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// frsp f0,f0
	f0.f64 = double(float(f0.f64));
	// lfs f29,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f29.f64 = double(temp.f32);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r28,r29,1
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x1) != 0);
	r28.s64 = r29.s32 >> 1;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r30,r11,-4
	r30.s64 = r11.s64 + -4;
	// fdivs f11,f29,f0
	ctx.f11.f64 = double(float(f29.f64 / f0.f64));
	// lfs f0,-11712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11712);
	f0.f64 = double(temp.f32);
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,-11708(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11708);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f12,18204(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18204);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,-21240(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21240);
	// fmuls f28,f11,f0
	f28.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f31,f11,f13
	f31.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fdivs f1,f12,f10
	ctx.f1.f64 = double(float(ctx.f12.f64 / ctx.f10.f64));
	// fmr f30,f28
	f30.f64 = f28.f64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827586F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fsubs f12,f31,f28
	ctx.f12.f64 = double(float(f31.f64 - f28.f64));
	// lfs f11,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// addi r10,r30,-4
	ctx.r10.s64 = r30.s64 + -4;
	// li r9,2
	ctx.r9.s64 = 2;
	// cmpwi cr6,r28,4
	cr6.compare<int32_t>(r28.s32, 4, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// fmuls f0,f13,f28
	f0.f64 = double(float(ctx.f13.f64 * f28.f64));
	// fmuls f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f11,0(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lfs f11,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fsubs f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 - f0.f64));
	// stfs f12,0(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f12,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f29
	ctx.f13.f64 = double(float(ctx.f13.f64 * f29.f64));
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f12,4(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lfs f12,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f12,-4(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + -4, temp.u32);
	// ble cr6,0x827587e0
	if (!cr6.gt) goto loc_827587E0;
	// li r8,4
	ctx.r8.s64 = 4;
loc_82758758:
	// fmsubs f12,f0,f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64 - f30.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// cmpw cr6,r8,r28
	cr6.compare<int32_t>(ctx.r8.s32, r28.s32, xer);
	// fmsubs f30,f12,f13,f0
	f30.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 - f0.f64));
	// fsubs f0,f31,f12
	f0.f64 = double(float(f31.f64 - ctx.f12.f64));
	// fsubs f10,f31,f30
	ctx.f10.f64 = double(float(f31.f64 - f30.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f10
	f0.f64 = double(float(f0.f64 * ctx.f10.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmsubs f0,f13,f30,f12
	f0.f64 = double(float(ctx.f13.f64 * f30.f64 - ctx.f12.f64));
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f12,f10
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// fsubs f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 - f0.f64));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// blt cr6,0x82758758
	if (cr6.lt) goto loc_82758758;
loc_827587E0:
	// cmpw cr6,r9,r28
	cr6.compare<int32_t>(ctx.r9.s32, r28.s32, xer);
	// bge cr6,0x8275883c
	if (!cr6.lt) goto loc_8275883C;
	// fmsubs f12,f0,f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64 - f30.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r9,r28
	cr6.compare<int32_t>(ctx.r9.s32, r28.s32, xer);
	// fsubs f10,f31,f12
	ctx.f10.f64 = double(float(f31.f64 - ctx.f12.f64));
	// fmuls f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bge cr6,0x8275883c
	if (!cr6.lt) goto loc_8275883C;
	// fmsubs f0,f12,f13,f0
	f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 - f0.f64));
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f31,f0
	f0.f64 = double(float(f31.f64 - f0.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lfs f13,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,-4(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -4, temp.u32);
loc_8275883C:
	// clrlwi. r10,r29,31
	ctx.r10.u64 = r29.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82758854
	if (cr0.eq) goto loc_82758854;
	// fadds f0,f31,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 + f28.f64));
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_82758854:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba24
	ctx.lr = 0x82758860;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82758864"))) PPC_WEAK_FUNC(sub_82758864);
PPC_FUNC_IMPL(__imp__sub_82758864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82758868"))) PPC_WEAK_FUNC(sub_82758868);
PPC_FUNC_IMPL(__imp__sub_82758868) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,17372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17372);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82758880
	if (!cr6.gt) goto loc_82758880;
	// li r3,261
	ctx.r3.s64 = 261;
	// blr 
	return;
loc_82758880:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f0,5684(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5684);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82758898
	if (!cr6.gt) goto loc_82758898;
	// li r3,241
	ctx.r3.s64 = 241;
	// blr 
	return;
loc_82758898:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,21588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 21588);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x827588b0
	if (!cr6.gt) goto loc_827588B0;
	// li r3,221
	ctx.r3.s64 = 221;
	// blr 
	return;
loc_827588B0:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f0,5680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5680);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x827588c8
	if (!cr6.gt) goto loc_827588C8;
	// li r3,201
	ctx.r3.s64 = 201;
	// blr 
	return;
loc_827588C8:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f0,16680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16680);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x827588e0
	if (!cr6.gt) goto loc_827588E0;
	// li r3,181
	ctx.r3.s64 = 181;
	// blr 
	return;
loc_827588E0:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f0,5676(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5676);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82758908
	if (cr6.gt) goto loc_82758908;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f0,24608(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24608);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82758908
	if (cr6.gt) goto loc_82758908;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31304(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31304);
	f0.f64 = double(temp.f32);
loc_82758908:
	// li r3,161
	ctx.r3.s64 = 161;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82758910"))) PPC_WEAK_FUNC(sub_82758910);
PPC_FUNC_IMPL(__imp__sub_82758910) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stfs f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r11,-16(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// srawi r8,r11,23
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFFFF) != 0);
	ctx.r8.s64 = r11.s32 >> 23;
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r11,-127
	r11.s64 = r11.s64 + -127;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// oris r8,r7,16256
	ctx.r8.u64 = ctx.r7.u64 | 1065353216;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stw r8,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r8.u32);
	// lfs f12,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// fmsubs f13,f12,f0,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * f0.f64 - ctx.f13.f64));
	// lfd f0,-16(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// frsp f12,f0
	ctx.f12.f64 = double(float(f0.f64));
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmadds f1,f13,f0,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82758970"))) PPC_WEAK_FUNC(sub_82758970);
PPC_FUNC_IMPL(__imp__sub_82758970) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fmuls f11,f0,f1
	ctx.f11.f64 = double(float(f0.f64 * ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f5,3740(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3740);
	ctx.f5.f64 = double(temp.f32);
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// lfs f6,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f6.f64 = double(temp.f32);
	// lfs f12,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// fmr f13,f6
	ctx.f13.f64 = ctx.f6.f64;
	// lfs f3,5704(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 5704);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,14988(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14988);
	ctx.f4.f64 = double(temp.f32);
	// fadds f0,f11,f5
	f0.f64 = double(float(ctx.f11.f64 + ctx.f5.f64));
	// b 0x827589b8
	goto loc_827589B8;
loc_827589B0:
	// fmuls f0,f0,f4
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f4.f64));
	// fmuls f13,f13,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
loc_827589B8:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x827589b0
	if (cr6.lt) goto loc_827589B0;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// addic. r11,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	r11.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r6,4
	ctx.r10.s64 = ctx.r6.s64 + 4;
	// lfs f9,5700(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 5700);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,5696(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 5696);
	ctx.f8.f64 = double(temp.f32);
	// fnmsubs f10,f0,f9,f8
	ctx.f10.f64 = double(float(-(f0.f64 * ctx.f9.f64 - ctx.f8.f64)));
	// lfs f7,5692(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 5692);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f0,f10,f0,f7
	f0.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f7.f64));
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blelr 
	if (!cr0.gt) return;
loc_827589F4:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// fmuls f10,f0,f1
	ctx.f10.f64 = double(float(f0.f64 * ctx.f1.f64));
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fcmpu cr6,f10,f11
	cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// beq cr6,0x82758a38
	if (cr6.eq) goto loc_82758A38;
	// fadds f0,f10,f5
	f0.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// fmr f13,f6
	ctx.f13.f64 = ctx.f6.f64;
	// b 0x82758a20
	goto loc_82758A20;
loc_82758A18:
	// fmuls f0,f0,f4
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f4.f64));
	// fmuls f13,f13,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
loc_82758A20:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x82758a18
	if (cr6.lt) goto loc_82758A18;
	// fnmsubs f11,f0,f9,f8
	ctx.f11.f64 = double(float(-(f0.f64 * ctx.f9.f64 - ctx.f8.f64)));
	// fmadds f0,f11,f0,f7
	f0.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f7.f64));
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// b 0x82758a3c
	goto loc_82758A3C;
loc_82758A38:
	// lfs f0,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	f0.f64 = double(temp.f32);
loc_82758A3C:
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fmr f11,f10
	ctx.f11.f64 = ctx.f10.f64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x827589f4
	if (cr6.gt) goto loc_827589F4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82758A54"))) PPC_WEAK_FUNC(sub_82758A54);
PPC_FUNC_IMPL(__imp__sub_82758A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82758A58"))) PPC_WEAK_FUNC(sub_82758A58);
PPC_FUNC_IMPL(__imp__sub_82758A58) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82758a74
	if (cr6.gt) goto loc_82758A74;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f2,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
loc_82758A74:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lfs f13,-3164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5708(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5708);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82758ac0
	if (cr6.lt) goto loc_82758AC0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f4,f13
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bge cr6,0x82758ab4
	if (!cr6.lt) goto loc_82758AB4;
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
loc_82758AB4:
	// fcmpu cr6,f0,f2
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f2.f64);
	// ble cr6,0x82758ac0
	if (!cr6.gt) goto loc_82758AC0;
	// fmr f2,f0
	ctx.f2.f64 = f0.f64;
loc_82758AC0:
	// fcmpu cr6,f3,f2
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f3.f64, ctx.f2.f64);
	// ble cr6,0x82758b1c
	if (!cr6.gt) goto loc_82758B1C;
	// fcmpu cr6,f3,f12
	cr6.compare(ctx.f3.f64, ctx.f12.f64);
	// blt cr6,0x82758b1c
	if (cr6.lt) goto loc_82758B1C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-28872(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28872);
	f0.f64 = double(temp.f32);
	// fmuls f0,f5,f0
	f0.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fcmpu cr6,f4,f0
	cr6.compare(ctx.f4.f64, f0.f64);
	// bge cr6,0x82758b10
	if (!cr6.lt) goto loc_82758B10;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-32032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32032);
	f0.f64 = double(temp.f32);
	// fmuls f0,f5,f0
	f0.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fcmpu cr6,f4,f0
	cr6.compare(ctx.f4.f64, f0.f64);
	// ble cr6,0x82758b10
	if (!cr6.gt) goto loc_82758B10;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	f0.f64 = double(temp.f32);
	// fmuls f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 * f0.f64));
	// lfs f0,-17424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -17424);
	f0.f64 = double(temp.f32);
	// fmadds f2,f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f2.f64 * f0.f64 + ctx.f13.f64));
loc_82758B10:
	// fcmpu cr6,f2,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f2.f64, ctx.f12.f64);
	// bge cr6,0x82758b1c
	if (!cr6.lt) goto loc_82758B1C;
	// fadds f2,f2,f12
	ctx.f2.f64 = double(float(ctx.f2.f64 + ctx.f12.f64));
loc_82758B1C:
	// fmr f1,f2
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f2.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82758B24"))) PPC_WEAK_FUNC(sub_82758B24);
PPC_FUNC_IMPL(__imp__sub_82758B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82758B28"))) PPC_WEAK_FUNC(sub_82758B28);
PPC_FUNC_IMPL(__imp__sub_82758B28) {
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
	ctx.lr = 0x82758B30;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d8
	ctx.lr = 0x82758B38;
	// stwu r1,-2064(r1)
	ea = -2064 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lfs f0,5716(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5716);
	f0.f64 = double(temp.f32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lfs f31,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f31.f64 = double(temp.f32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// fmuls f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 * f0.f64));
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lfs f28,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f28.f64 = double(temp.f32);
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// lfs f0,-23584(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -23584);
	f0.f64 = double(temp.f32);
	// fdivs f0,f0,f31
	f0.f64 = double(float(f0.f64 / f31.f64));
	// fsubs f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 - f28.f64));
	// fsel f13,f13,f13,f12
	ctx.f13.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bge cr6,0x82758b9c
	if (!cr6.lt) goto loc_82758B9C;
	// li r11,5
	r11.s64 = 5;
loc_82758B9C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f12,12424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12424);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,5688(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5688);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82758bd4
	if (!cr6.gt) goto loc_82758BD4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82758BD4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lfs f29,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f29.f64 = double(temp.f32);
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 + f29.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// ble cr6,0x82758c20
	if (!cr6.gt) goto loc_82758C20;
loc_82758C00:
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r11,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + r27.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82758c20
	if (cr6.gt) goto loc_82758C20;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// cmpw cr6,r4,r9
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r9.s32, xer);
	// blt cr6,0x82758c00
	if (cr6.lt) goto loc_82758C00;
loc_82758C20:
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x82758d60
	if (!cr6.gt) goto loc_82758D60;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82758450
	ctx.lr = 0x82758C3C;
	sub_82758450(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82758450
	ctx.lr = 0x82758C50;
	sub_82758450(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82758c68
	if (cr6.gt) goto loc_82758C68;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
loc_82758C68:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r11,r11,3796
	r11.s64 = r11.s64 + 3796;
	// lfs f30,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x82758c84
	if (!cr6.eq) goto loc_82758C84;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// b 0x82758c88
	goto loc_82758C88;
loc_82758C84:
	// fdivs f1,f28,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f28.f64 / f0.f64));
loc_82758C88:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82758970
	ctx.lr = 0x82758C98;
	sub_82758970(ctx, base);
	// addi r6,r1,928
	ctx.r6.s64 = ctx.r1.s64 + 928;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82758970
	ctx.lr = 0x82758CA8;
	sub_82758970(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82758d10
	if (!cr6.gt) goto loc_82758D10;
	// mr r11,r31
	r11.u64 = r31.u64;
	// subf r9,r31,r27
	ctx.r9.s64 = r27.s64 - r31.s64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_82758CBC:
	// lfsx f13,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,928
	ctx.r8.s64 = ctx.r1.s64 + 928;
	// fadds f12,f13,f29
	ctx.f12.f64 = double(float(ctx.f13.f64 + f29.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r7,116(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r7,r8
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82758d04
	if (!cr6.lt) goto loc_82758D04;
	// fdivs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_82758D04:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82758cbc
	if (!cr0.eq) goto loc_82758CBC;
loc_82758D10:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// addi r9,r1,108
	ctx.r9.s64 = ctx.r1.s64 + 108;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,528
	ctx.r7.s64 = ctx.r1.s64 + 528;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f1,5712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5712);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82759928
	ctx.lr = 0x82758D38;
	sub_82759928(ctx, base);
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// addi r8,r1,100
	ctx.r8.s64 = ctx.r1.s64 + 100;
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// bl 0x8275b950
	ctx.lr = 0x82758D58;
	sub_8275B950(ctx, base);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// b 0x82758d78
	goto loc_82758D78;
loc_82758D60:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r11,r11,3796
	r11.s64 = r11.s64 + 3796;
	// lfs f30,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f30.f64 = double(temp.f32);
	// fmr f0,f30
	f0.f64 = f30.f64;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_82758D78:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f12,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// lfs f13,6088(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6088);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f31,f12,f29,f13
	f31.f64 = double(float(-(ctx.f12.f64 * f29.f64 - ctx.f13.f64)));
	// bgt cr6,0x82758d98
	if (cr6.gt) goto loc_82758D98;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	f0.f64 = double(temp.f32);
loc_82758D98:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// blt cr6,0x82758da8
	if (cr6.lt) goto loc_82758DA8;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,-29796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29796);
	f0.f64 = double(temp.f32);
loc_82758DA8:
	// fsubs f1,f28,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f28.f64 - f0.f64));
	// bl 0x823db918
	ctx.lr = 0x82758DB0;
	sub_823DB918(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32308);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82758dd0
	if (!cr6.lt) goto loc_82758DD0;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x82758df4
	goto loc_82758DF4;
loc_82758DD0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,-3168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3168);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82758de8
	if (!cr6.gt) goto loc_82758DE8;
	// fmr f0,f28
	f0.f64 = f28.f64;
	// b 0x82758df4
	goto loc_82758DF4;
loc_82758DE8:
	// fsubs f0,f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 - f31.f64));
	// fsubs f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
loc_82758DF4:
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r24)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r24.u32 + 0, temp.u32);
	// stfs f13,0(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// stfs f0,0(r23)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
	// addi r1,r1,2064
	ctx.r1.s64 = ctx.r1.s64 + 2064;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x82758E10;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82758E14"))) PPC_WEAK_FUNC(sub_82758E14);
PPC_FUNC_IMPL(__imp__sub_82758E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82758E18"))) PPC_WEAK_FUNC(sub_82758E18);
PPC_FUNC_IMPL(__imp__sub_82758E18) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmr f13,f4
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f4.f64;
	// lfs f0,-28872(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28872);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// bgt cr6,0x82758e58
	if (cr6.gt) goto loc_82758E58;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-32032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32032);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// blt cr6,0x82758e58
	if (cr6.lt) goto loc_82758E58;
	// fadds f13,f1,f2
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// b 0x82758eb4
	goto loc_82758EB4;
loc_82758E58:
	// fcmpu cr6,f3,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f3.f64, ctx.f13.f64);
	// ble cr6,0x82758e6c
	if (!cr6.gt) goto loc_82758E6C;
	// fmr f0,f1
	f0.f64 = ctx.f1.f64;
	// fmr f13,f3
	ctx.f13.f64 = ctx.f3.f64;
	// b 0x82758e70
	goto loc_82758E70;
loc_82758E6C:
	// fmr f0,f2
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f2.f64;
loc_82758E70:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,27632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27632);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x82758eb4
	if (!cr6.lt) goto loc_82758EB4;
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x82758eb4
	if (!cr6.lt) goto loc_82758EB4;
	// fcmpu cr6,f2,f1
	cr6.compare(ctx.f2.f64, ctx.f1.f64);
	// ble cr6,0x82758eb0
	if (!cr6.gt) goto loc_82758EB0;
	// fmr f0,f2
	f0.f64 = ctx.f2.f64;
	// b 0x82758eb4
	goto loc_82758EB4;
loc_82758EB0:
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f1.f64;
loc_82758EB4:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82758EBC"))) PPC_WEAK_FUNC(sub_82758EBC);
PPC_FUNC_IMPL(__imp__sub_82758EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82758EC0"))) PPC_WEAK_FUNC(sub_82758EC0);
PPC_FUNC_IMPL(__imp__sub_82758EC0) {
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
	ctx.lr = 0x82758EC8;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d8
	ctx.lr = 0x82758ED0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmadds f13,f1,f2,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f2.f64 + f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// ble cr6,0x82758f04
	if (!cr6.gt) goto loc_82758F04;
	// li r11,4
	r11.s64 = 4;
loc_82758F04:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fsubs f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fadds f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f1.f64));
	// fadds f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fctiwz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r25,84(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// bge cr6,0x82758f4c
	if (!cr6.lt) goto loc_82758F4C;
	// li r31,8
	r31.s64 = 8;
loc_82758F4C:
	// cmpwi cr6,r25,160
	cr6.compare<int32_t>(r25.s32, 160, xer);
	// ble cr6,0x82758f58
	if (!cr6.gt) goto loc_82758F58;
	// li r25,160
	r25.s64 = 160;
loc_82758F58:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r26,0
	r26.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// add r28,r11,r27
	r28.u64 = r11.u64 + r27.u64;
	// lfs f31,-31068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31068);
	f31.f64 = double(temp.f32);
	// fmr f28,f0
	f28.f64 = f0.f64;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// subf r29,r31,r24
	r29.s64 = r24.s64 - r31.s64;
	// fmr f29,f0
	f29.f64 = f0.f64;
loc_82758F88:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827583c0
	ctx.lr = 0x82758F98;
	sub_827583C0(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x82758fb0
	if (!cr6.gt) goto loc_82758FB0;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// fmr f29,f30
	f29.f64 = f30.f64;
	// b 0x82758fc0
	goto loc_82758FC0;
loc_82758FB0:
	// addi r11,r30,-1
	r11.s64 = r30.s64 + -1;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// bne cr6,0x82758fc0
	if (!cr6.eq) goto loc_82758FC0;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
loc_82758FC0:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// ble cr6,0x82758f88
	if (!cr6.gt) goto loc_82758F88;
	// add r30,r26,r31
	r30.u64 = r26.u64 + r31.u64;
	// cmpw cr6,r30,r31
	cr6.compare<int32_t>(r30.s32, r31.s32, xer);
	// ble cr6,0x82759020
	if (!cr6.gt) goto loc_82759020;
	// cmpw cr6,r30,r25
	cr6.compare<int32_t>(r30.s32, r25.s32, xer);
	// bge cr6,0x82759020
	if (!cr6.lt) goto loc_82759020;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x82759750
	ctx.lr = 0x82759004;
	sub_82759750(ctx, base);
	// extsw r11,r30
	r11.s64 = r30.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// frsp f0,f0
	f0.f64 = double(float(f0.f64));
	// fadds f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 + f0.f64));
	// b 0x82759038
	goto loc_82759038;
loc_82759020:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// stfs f31,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// frsp f31,f0
	f31.f64 = double(float(f0.f64));
loc_82759038:
	// subf r31,r30,r24
	r31.s64 = r24.s64 - r30.s64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827583c0
	ctx.lr = 0x8275904C;
	sub_827583C0(ctx, base);
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// add r4,r11,r27
	ctx.r4.u64 = r11.u64 + r27.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x827583c0
	ctx.lr = 0x82759064;
	sub_827583C0(ctx, base);
	// fmr f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,0(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f0,14196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	f0.f64 = double(temp.f32);
	// fmadds f0,f13,f30,f0
	f0.f64 = double(float(ctx.f13.f64 * f30.f64 + f0.f64));
	// fsqrts f0,f0
	f0.f64 = double(float(sqrt(f0.f64)));
	// fdivs f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 / f0.f64));
	// stfs f0,0(r23)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x82759094;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82759098"))) PPC_WEAK_FUNC(sub_82759098);
PPC_FUNC_IMPL(__imp__sub_82759098) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x827590A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x827590d8
	if (cr6.eq) goto loc_827590D8;
loc_827590B8:
	// lfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dca68
	ctx.lr = 0x827590C0;
	sub_823DCA68(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x827590b8
	if (!cr0.eq) goto loc_827590B8;
loc_827590D8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827590E0"))) PPC_WEAK_FUNC(sub_827590E0);
PPC_FUNC_IMPL(__imp__sub_827590E0) {
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
	PPCRegister f0{};
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
	// bl 0x823d91f4
	ctx.lr = 0x827590E8;
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x8275bba8
	ctx.lr = 0x82759108;
	sub_8275BBA8(ctx, base);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// li r9,8
	ctx.r9.s64 = 8;
	// li r8,-16
	ctx.r8.s64 = -16;
loc_82759118:
	// li r7,-32
	ctx.r7.s64 = -32;
	// lvlx128 v63,r11,r8
	temp.u32 = r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r6,48
	ctx.r6.s64 = 48;
	// lvlx128 v62,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,64
	ctx.r4.s64 = 64;
	// li r3,16
	ctx.r3.s64 = 16;
	// lvlx128 v61,r11,r7
	temp.u32 = r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r7,80
	ctx.r7.s64 = 80;
	// vrlimi128 v61,v63,4,3
	simde_mm_store_ps(v61.f32, simde_mm_blend_ps(simde_mm_load_ps(v61.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 57), 4));
	// lvlx128 v60,r11,r6
	temp.u32 = r11.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v63,r11,r5
	temp.u32 = r11.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// vrlimi128 v63,v60,4,3
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v60.f32), 57), 4));
	// lvlx128 v60,r11,r4
	temp.u32 = r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v59,r11,r3
	temp.u32 = r11.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v61,v62,2,2
	simde_mm_store_ps(v61.f32, simde_mm_blend_ps(simde_mm_load_ps(v61.f32), simde_mm_permute_ps(simde_mm_load_ps(v62.f32), 78), 2));
	// lvlx128 v58,r11,r7
	temp.u32 = r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// vrlimi128 v63,v60,2,2
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v60.f32), 78), 2));
	// vrlimi128 v61,v59,1,1
	simde_mm_store_ps(v61.f32, simde_mm_blend_ps(simde_mm_load_ps(v61.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 147), 1));
	// vrlimi128 v63,v58,1,1
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v58.f32), 147), 1));
	// vexptefp128 v62,v61
	ctx.fpscr.enableFlushMode();
	v62.f32[0] = exp2f(v61.f32[0]);
	v62.f32[1] = exp2f(v61.f32[1]);
	v62.f32[2] = exp2f(v61.f32[2]);
	v62.f32[3] = exp2f(v61.f32[3]);
	// vexptefp128 v63,v63
	v63.f32[0] = exp2f(v63.f32[0]);
	v63.f32[1] = exp2f(v63.f32[1]);
	v63.f32[2] = exp2f(v63.f32[2]);
	v63.f32[3] = exp2f(v63.f32[3]);
	// stvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bne 0x82759118
	if (!cr0.eq) goto loc_82759118;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r5,260
	ctx.r5.s64 = 260;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// lwz r11,-21248(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21248);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827591A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,432
	ctx.r4.s64 = ctx.r1.s64 + 432;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82758228
	ctx.lr = 0x827591B4;
	sub_82758228(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lfs f12,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// srawi r10,r30,1
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1) != 0);
	ctx.r10.s64 = r30.s32 >> 1;
	// lfs f11,432(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 432);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r1,164
	r11.s64 = ctx.r1.s64 + 164;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// lfs f13,12432(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12432);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// lfs f0,5720(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 5720);
	f0.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f12,f11,f0
	ctx.f12.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r10,r1,436
	ctx.r10.s64 = ctx.r1.s64 + 436;
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// blt cr6,0x8275922c
	if (cr6.lt) goto loc_8275922C;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
loc_827591FC:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x827591fc
	if (!cr0.eq) goto loc_827591FC;
loc_8275922C:
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// beq cr6,0x82759244
	if (cr6.eq) goto loc_82759244;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
loc_82759244:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82759280
	ctx.lr = 0x8275925C;
	sub_82759280(ctx, base);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82758910
	ctx.lr = 0x82759264;
	sub_82758910(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8275927C"))) PPC_WEAK_FUNC(sub_8275927C);
PPC_FUNC_IMPL(__imp__sub_8275927C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82759280"))) PPC_WEAK_FUNC(sub_82759280);
PPC_FUNC_IMPL(__imp__sub_82759280) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82759288;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f13,f9
	cr6.compare(ctx.f13.f64, ctx.f9.f64);
	// bne cr6,0x827592a4
	if (!cr6.eq) goto loc_827592A4;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,5728(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5728);
	ctx.f13.f64 = double(temp.f32);
loc_827592A4:
	// clrlwi. r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x827592b8
	if (cr0.eq) goto loc_827592B8;
	// addi r11,r1,-112
	r11.s64 = ctx.r1.s64 + -112;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// b 0x827592c0
	goto loc_827592C0;
loc_827592B8:
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r29,r1,-112
	r29.s64 = ctx.r1.s64 + -112;
loc_827592C0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lfs f10,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,0(r29)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// stfs f10,0(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// ble cr6,0x827593b8
	if (!cr6.gt) goto loc_827593B8;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r3,4
	r30.s64 = ctx.r3.s64 + 4;
	// lfs f11,5724(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5724);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,25092(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 25092);
	ctx.f12.f64 = double(temp.f32);
loc_827592F4:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f9.f64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x82759328
	if (cr6.lt) goto loc_82759328;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
loc_8275930C:
	// lfs f8,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f7,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// fmadds f0,f8,f7,f0
	f0.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + f0.f64));
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// bne 0x8275930c
	if (!cr0.eq) goto loc_8275930C;
loc_82759328:
	// fdivs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x82759338
	if (!cr6.gt) goto loc_82759338;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_82759338:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x82759344
	if (!cr6.lt) goto loc_82759344;
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
loc_82759344:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// stfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// fneg f8,f0
	ctx.f8.u64 = f0.u64 ^ 0x8000000000000000;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// add r8,r31,r11
	ctx.r8.u64 = r31.u64 + r11.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// stfs f8,4(r8)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// blt cr6,0x8275939c
	if (cr6.lt) goto loc_8275939C;
	// add r5,r31,r10
	ctx.r5.u64 = r31.u64 + ctx.r10.u64;
	// subf r3,r11,r10
	ctx.r3.s64 = ctx.r10.s64 - r11.s64;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8275937C:
	// lfs f8,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfsx f7,r3,r8
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	ctx.f7.f64 = double(temp.f32);
	// addi r5,r5,-4
	ctx.r5.s64 = ctx.r5.s64 + -4;
	// fnmsubs f8,f8,f0,f7
	ctx.f8.f64 = double(float(-(ctx.f8.f64 * f0.f64 - ctx.f7.f64)));
	// stfs f8,0(r8)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8275937c
	if (!cr0.eq) goto loc_8275937C;
loc_8275939C:
	// fnmsubs f0,f0,f0,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(-(f0.f64 * f0.f64 - ctx.f10.f64)));
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// blt cr6,0x827592f4
	if (cr6.lt) goto loc_827592F4;
loc_827593B8:
	// stfs f13,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827593C0"))) PPC_WEAK_FUNC(sub_827593C0);
PPC_FUNC_IMPL(__imp__sub_827593C0) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827593C8;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// lfs f8,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f0,f1,f8
	f0.f64 = double(float(ctx.f1.f64 * ctx.f8.f64));
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
	// fadds f11,f0,f1
	ctx.f11.f64 = double(float(f0.f64 + ctx.f1.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82759414
	if (!cr6.lt) goto loc_82759414;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
loc_827593F8:
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bge cr6,0x82759414
	if (!cr6.lt) goto loc_82759414;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfs f13,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x827593f8
	if (cr6.lt) goto loc_827593F8;
loc_82759414:
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lfs f9,-740(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -740);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f5,f9,f0
	ctx.f5.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fcmpu cr6,f0,f5
	cr6.compare(f0.f64, ctx.f5.f64);
	// bge cr6,0x82759540
	if (!cr6.lt) goto loc_82759540;
	// subf r30,r9,r8
	r30.s64 = ctx.r8.s64 - ctx.r9.s64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f6,14196(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14196);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
loc_82759440:
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// bge cr6,0x82759540
	if (!cr6.lt) goto loc_82759540;
	// fmr f13,f7
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f7.f64;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bge cr6,0x827594b8
	if (!cr6.lt) goto loc_827594B8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// lfsx f12,r9,r5
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x827594b8
	if (!cr6.lt) goto loc_827594B8;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// subf r31,r4,r5
	r31.s64 = ctx.r5.s64 - ctx.r4.s64;
loc_82759470:
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// bge cr6,0x827594a0
	if (!cr6.lt) goto loc_827594A0;
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x8275948c
	if (!cr6.lt) goto loc_8275948C;
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_8275948C:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lfsx f12,r31,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// blt cr6,0x82759470
	if (cr6.lt) goto loc_82759470;
loc_827594A0:
	// fcmpu cr6,f13,f7
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f7.f64);
	// ble cr6,0x827594b8
	if (!cr6.gt) goto loc_827594B8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f13,r30,r7
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + ctx.r7.u32, temp.u32);
	// lfsx f13,r9,r5
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	ctx.f13.f64 = double(temp.f32);
	// b 0x827594f0
	goto loc_827594F0;
loc_827594B8:
	// fadds f13,f11,f10
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f10.f64));
	// fmadds f13,f13,f8,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f8.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f13.u64);
	// lwz r9,-44(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -44);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r8.u64);
	// lfd f13,-40(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f12,r9,r29
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	ctx.f12.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fadds f12,f12,f6
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f6.f64));
	// stfsx f12,r30,r7
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + ctx.r7.u32, temp.u32);
loc_827594F0:
	// fadds f10,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f13,0(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fadds f11,f10,f1
	ctx.f11.f64 = double(float(ctx.f10.f64 + ctx.f1.f64));
	// fcmpu cr6,f11,f9
	cr6.compare(ctx.f11.f64, ctx.f9.f64);
	// ble cr6,0x82759508
	if (!cr6.gt) goto loc_82759508;
	// fmr f11,f9
	ctx.f11.f64 = ctx.f9.f64;
loc_82759508:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// b 0x8275952c
	goto loc_8275952C;
loc_8275951C:
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bge cr6,0x82759538
	if (!cr6.lt) goto loc_82759538;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_8275952C:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f10
	cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// blt cr6,0x8275951c
	if (cr6.lt) goto loc_8275951C;
loc_82759538:
	// fcmpu cr6,f10,f5
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f10.f64, ctx.f5.f64);
	// blt cr6,0x82759440
	if (cr6.lt) goto loc_82759440;
loc_82759540:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82759544"))) PPC_WEAK_FUNC(sub_82759544);
PPC_FUNC_IMPL(__imp__sub_82759544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82759548"))) PPC_WEAK_FUNC(sub_82759548);
PPC_FUNC_IMPL(__imp__sub_82759548) {
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82759550;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-1600(r1)
	ea = -1600 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r11,r11,-32240
	r11.s64 = r11.s64 + -32240;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r31,r10,5744
	r31.s64 = ctx.r10.s64 + 5744;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// addi r9,r1,496
	ctx.r9.s64 = ctx.r1.s64 + 496;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x827593c0
	ctx.lr = 0x82759598;
	sub_827593C0(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// lvlx128 v61,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// vrlimi128 v63,v61,8,0
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 228), 8));
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// vlogefp128 v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	v63.f32[0] = log2f(v63.f32[0]);
	v63.f32[1] = log2f(v63.f32[1]);
	v63.f32[2] = log2f(v63.f32[2]);
	v63.f32[3] = log2f(v63.f32[3]);
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// vexptefp128 v63,v63
	v63.f32[0] = exp2f(v63.f32[0]);
	v63.f32[1] = exp2f(v63.f32[1]);
	v63.f32[2] = exp2f(v63.f32[2]);
	v63.f32[3] = exp2f(v63.f32[3]);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// ble 0x8275964c
	if (!cr0.gt) goto loc_8275964C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r27,0
	r27.s64 = 0;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lfs f30,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f30.f64 = double(temp.f32);
loc_827595E4:
	// addi r11,r1,496
	r11.s64 = ctx.r1.s64 + 496;
	// mr r31,r29
	r31.u64 = r29.u64;
	// lfsx f31,r27,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + r11.u32);
	f31.f64 = double(temp.f32);
	// fadds f0,f31,f0
	f0.f64 = double(float(f31.f64 + f0.f64));
	// fmadds f0,f0,f30,f30
	f0.f64 = double(float(f0.f64 * f30.f64 + f30.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// bge cr6,0x82759634
	if (!cr6.lt) goto loc_82759634;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r30,r31,r29
	r30.s64 = r29.s64 - r31.s64;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r4,4
	ctx.r3.s64 = ctx.r4.s64 + 4;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stfs f13,0(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// rlwinm r5,r11,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// bl 0x823dadd8
	ctx.lr = 0x82759630;
	sub_823DADD8(ctx, base);
	// add r31,r30,r31
	r31.u64 = r30.u64 + r31.u64;
loc_82759634:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// lfsx f13,r27,r11
	temp.u32 = PPC_LOAD_U32(r27.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x827595e4
	if (!cr0.eq) goto loc_827595E4;
loc_8275964C:
	// fctiwz f0,f29
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f29.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f29.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// cmpwi cr6,r30,256
	cr6.compare<int32_t>(r30.s32, 256, xer);
	// ble cr6,0x82759668
	if (!cr6.gt) goto loc_82759668;
	// li r30,256
	r30.s64 = 256;
loc_82759668:
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x82759694
	if (!cr6.lt) goto loc_82759694;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r31,r30
	ctx.r10.s64 = r30.s64 - r31.s64;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r4,4
	ctx.r3.s64 = ctx.r4.s64 + 4;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// rlwinm r5,r11,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// bl 0x823dadd8
	ctx.lr = 0x82759694;
	sub_823DADD8(ctx, base);
loc_82759694:
	// cmpwi cr6,r30,256
	cr6.compare<int32_t>(r30.s32, 256, xer);
	// bge cr6,0x827596c8
	if (!cr6.lt) goto loc_827596C8;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// subfic r10,r30,256
	xer.ca = r30.u32 <= 256;
	ctx.r10.s64 = 256 - r30.s64;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lfs f0,32664(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32664);
	f0.f64 = double(temp.f32);
loc_827596B0:
	// lfs f13,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827596b0
	if (!cr0.eq) goto loc_827596B0;
loc_827596C8:
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
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

__attribute__((alias("__imp__sub_827596DC"))) PPC_WEAK_FUNC(sub_827596DC);
PPC_FUNC_IMPL(__imp__sub_827596DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827596E0"))) PPC_WEAK_FUNC(sub_827596E0);
PPC_FUNC_IMPL(__imp__sub_827596E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// bge cr6,0x82759744
	if (!cr6.lt) goto loc_82759744;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
loc_827596FC:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82759734
	if (cr6.lt) goto loc_82759734;
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82759734
	if (!cr6.gt) goto loc_82759734;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// beq cr6,0x82759744
	if (cr6.eq) goto loc_82759744;
loc_82759734:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// blt cr6,0x827596fc
	if (cr6.lt) goto loc_827596FC;
loc_82759744:
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275974C"))) PPC_WEAK_FUNC(sub_8275974C);
PPC_FUNC_IMPL(__imp__sub_8275974C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82759750"))) PPC_WEAK_FUNC(sub_82759750);
PPC_FUNC_IMPL(__imp__sub_82759750) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// fadds f0,f1,f3
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + ctx.f3.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f12,f3,f1
	ctx.f12.f64 = double(float(ctx.f3.f64 - ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lfs f1,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// fmsubs f0,f0,f13,f2
	f0.f64 = double(float(f0.f64 * ctx.f13.f64 - ctx.f2.f64));
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// beq cr6,0x8275978c
	if (cr6.eq) goto loc_8275978C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f12,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fdivs f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// fneg f1,f12
	ctx.f1.u64 = ctx.f12.u64 ^ 0x8000000000000000;
loc_8275978C:
	// fmadds f0,f1,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f0,f0,f1,f2
	f0.f64 = double(float(f0.f64 * ctx.f1.f64 + ctx.f2.f64));
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275979C"))) PPC_WEAK_FUNC(sub_8275979C);
PPC_FUNC_IMPL(__imp__sub_8275979C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827597A0"))) PPC_WEAK_FUNC(sub_827597A0);
PPC_FUNC_IMPL(__imp__sub_827597A0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827597A8;
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// bl 0x827583f0
	ctx.lr = 0x827597CC;
	sub_827583F0(ctx, base);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827596e0
	ctx.lr = 0x827597E8;
	sub_827596E0(ctx, base);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82759898
	if (!cr6.gt) goto loc_82759898;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// subf r7,r31,r10
	ctx.r7.s64 = ctx.r10.s64 - r31.s64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// rotlwi r8,r5,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// lfs f9,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f9.f64 = double(temp.f32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// subf r6,r31,r29
	ctx.r6.s64 = r29.s64 - r31.s64;
	// lfs f8,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f8.f64 = double(temp.f32);
	// lfs f10,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	ctx.f10.f64 = double(temp.f32);
loc_82759820:
	// lwzx r9,r7,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// lfs f13,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmsubs f13,f12,f10,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 - ctx.f11.f64));
	// fmuls f12,f0,f10
	ctx.f12.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fcmpu cr6,f13,f9
	cr6.compare(ctx.f13.f64, ctx.f9.f64);
	// beq cr6,0x82759860
	if (cr6.eq) goto loc_82759860;
	// fmuls f0,f13,f8
	f0.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// fdivs f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 / f0.f64));
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// b 0x82759864
	goto loc_82759864;
loc_82759860:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f9.f64;
loc_82759864:
	// extsw r10,r9
	ctx.r10.s64 = ctx.r9.s32;
	// fmadds f13,f0,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f13,f13,f0,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f11.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fadds f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfsx f0,r6,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82759820
	if (!cr0.eq) goto loc_82759820;
loc_82759898:
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// bgt cr6,0x827598e4
	if (cr6.gt) goto loc_827598E4;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r11,r31
	r11.u64 = r31.u64;
	// addi r9,r30,28
	ctx.r9.s64 = r30.s64 + 28;
	// subf r8,r31,r29
	ctx.r8.s64 = r29.s64 - r31.s64;
	// li r10,36
	ctx.r10.s64 = 36;
	// lfs f13,-12736(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -12736);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_827598BC:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfsx f0,r11,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r9,r9,28
	ctx.r9.s64 = ctx.r9.s64 + 28;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827598bc
	if (!cr0.eq) goto loc_827598BC;
	// li r11,36
	r11.s64 = 36;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_827598E4:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827598EC"))) PPC_WEAK_FUNC(sub_827598EC);
PPC_FUNC_IMPL(__imp__sub_827598EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827598F0"))) PPC_WEAK_FUNC(sub_827598F0);
PPC_FUNC_IMPL(__imp__sub_827598F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// bltlr cr6
	if (cr6.lt) return;
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
loc_82759904:
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,0(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// fmuls f0,f0,f1
	f0.f64 = double(float(f0.f64 * ctx.f1.f64));
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne 0x82759904
	if (!cr0.eq) goto loc_82759904;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82759928"))) PPC_WEAK_FUNC(sub_82759928);
PPC_FUNC_IMPL(__imp__sub_82759928) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82759930;
	// li r11,0
	r11.s64 = 0;
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// bgt cr6,0x82759944
	if (cr6.gt) goto loc_82759944;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
loc_82759944:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8275997c
	if (!cr6.gt) goto loc_8275997C;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// subf r30,r7,r3
	r30.s64 = ctx.r3.s64 - ctx.r7.s64;
	// subf r29,r7,r4
	r29.s64 = ctx.r4.s64 - ctx.r7.s64;
	// subf r28,r7,r8
	r28.s64 = ctx.r8.s64 - ctx.r7.s64;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82759960:
	// lfsx f0,r30,r6
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r6.u32);
	f0.f64 = double(temp.f32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// lfsx f0,r29,r6
	temp.u32 = PPC_LOAD_U32(r29.u32 + ctx.r6.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r28,r6
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + ctx.r6.u32, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bne 0x82759960
	if (!cr0.eq) goto loc_82759960;
loc_8275997C:
	// subf r6,r11,r10
	ctx.r6.s64 = ctx.r10.s64 - r11.s64;
	// addi r30,r5,-1
	r30.s64 = ctx.r5.s64 + -1;
	// cmpw cr6,r30,r6
	cr6.compare<int32_t>(r30.s32, ctx.r6.s32, xer);
	// ble cr6,0x82759990
	if (!cr6.gt) goto loc_82759990;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
loc_82759990:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x827599e8
	if (!cr6.gt) goto loc_827599E8;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// add r31,r6,r8
	r31.u64 = ctx.r6.u64 + ctx.r8.u64;
	// addi r6,r4,4
	ctx.r6.s64 = ctx.r4.s64 + 4;
	// subf r28,r4,r3
	r28.s64 = ctx.r3.s64 - ctx.r4.s64;
	// subf r27,r8,r7
	r27.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
loc_827599B4:
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lfsx f0,r28,r6
	temp.u32 = PPC_LOAD_U32(r28.u32 + ctx.r6.u32);
	f0.f64 = double(temp.f32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfsx f0,r27,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + r31.u32, temp.u32);
	// lfs f0,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bne 0x827599b4
	if (!cr0.eq) goto loc_827599B4;
loc_827599E8:
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// addi r5,r5,-2
	ctx.r5.s64 = ctx.r5.s64 + -2;
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// ble cr6,0x827599fc
	if (!cr6.gt) goto loc_827599FC;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
loc_827599FC:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82759a50
	if (!cr6.gt) goto loc_82759A50;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r31,r8,r7
	r31.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// subf r4,r4,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r4.s64;
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
loc_82759A1C:
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lfsx f0,r10,r4
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfsx f0,r6,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, temp.u32);
	// lfs f0,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bne 0x82759a1c
	if (!cr0.eq) goto loc_82759A1C;
loc_82759A50:
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x82759aac
	if (cr6.lt) goto loc_82759AAC;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82759aa8
	if (!cr6.gt) goto loc_82759AA8;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// lfs f13,14992(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14992);
	ctx.f13.f64 = double(temp.f32);
loc_82759A7C:
	// lfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82759a9c
	if (!cr6.gt) goto loc_82759A9C;
	// stfsx f0,r10,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, temp.u32);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// lfsx f0,r7,r6
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_82759A9C:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x82759a7c
	if (!cr0.eq) goto loc_82759A7C;
loc_82759AA8:
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
loc_82759AAC:
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82759AB0"))) PPC_WEAK_FUNC(sub_82759AB0);
PPC_FUNC_IMPL(__imp__sub_82759AB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9d8
	ctx.lr = 0x82759AC8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// fmr f29,f2
	f29.f64 = ctx.f2.f64;
	// stfs f31,12(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stfs f29,16(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// bl 0x8275be68
	ctx.lr = 0x82759AE8;
	sub_8275BE68(ctx, base);
	// lha r11,22(r31)
	r11.s64 = int16_t(PPC_LOAD_U16(r31.u32 + 22));
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lhz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r30,r11,1
	r30.u64 = r11.u64 ^ 1;
	// bne 0x82759b14
	if (!cr0.eq) goto loc_82759B14;
	// li r11,1
	r11.s64 = 1;
	// sth r11,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r11.u16);
loc_82759B14:
	// lhz r11,26(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x82759b28
	if (!cr0.eq) goto loc_82759B28;
	// li r11,90
	r11.s64 = 90;
	// sth r11,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r11.u16);
loc_82759B28:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 + f0.f64));
	// bl 0x823db918
	ctx.lr = 0x82759B38;
	sub_823DB918(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f0,5760(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5760);
	f0.f64 = double(temp.f32);
	// fmuls f30,f13,f0
	f30.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x8275bec8
	ctx.lr = 0x82759B54;
	sub_8275BEC8(ctx, base);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lhz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// bl 0x8275bf38
	ctx.lr = 0x82759B68;
	sub_8275BF38(ctx, base);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8275bfc0
	ctx.lr = 0x82759B74;
	sub_8275BFC0(ctx, base);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lhz r5,26(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// lhz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// bl 0x8275c180
	ctx.lr = 0x82759B88;
	sub_8275C180(ctx, base);
	// sth r3,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r3.u16);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x8275c250
	ctx.lr = 0x82759B9C;
	sub_8275C250(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82759be4
	if (cr0.eq) goto loc_82759BE4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fadds f0,f30,f0
	f0.f64 = double(float(f30.f64 + f0.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lbz r3,87(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// bl 0x8275bd58
	ctx.lr = 0x82759BC4;
	sub_8275BD58(ctx, base);
	// lbz r11,30(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 30);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82759bec
	if (cr0.eq) goto loc_82759BEC;
	// lhz r4,22(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8275bc18
	ctx.lr = 0x82759BDC;
	sub_8275BC18(ctx, base);
	// sth r3,20(r31)
	PPC_STORE_U16(r31.u32 + 20, ctx.r3.u16);
	// b 0x82759bec
	goto loc_82759BEC;
loc_82759BE4:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8275be70
	ctx.lr = 0x82759BEC;
	sub_8275BE70(ctx, base);
loc_82759BEC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x82759BFC;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82759C10"))) PPC_WEAK_FUNC(sub_82759C10);
PPC_FUNC_IMPL(__imp__sub_82759C10) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82759C18;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-1232(r1)
	ea = -1232 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// addi r27,r30,8
	r27.s64 = r30.s64 + 8;
	// lfs f2,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x82758e18
	ctx.lr = 0x82759C50;
	sub_82758E18(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bne cr6,0x82759c68
	if (!cr6.eq) goto loc_82759C68;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f31,f31,f0
	f31.f64 = double(float(f31.f64 * f0.f64));
loc_82759C68:
	// lwz r26,0(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82758868
	ctx.lr = 0x82759C74;
	sub_82758868(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82758108
	ctx.lr = 0x82759C8C;
	sub_82758108(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82758658
	ctx.lr = 0x82759C98;
	sub_82758658(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f31,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// bl 0x82758ec0
	ctx.lr = 0x82759CB8;
	sub_82758EC0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// lfs f11,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f11.f64 = double(temp.f32);
	// bne cr6,0x82759cd4
	if (!cr6.eq) goto loc_82759CD4;
	// fmuls f0,f1,f11
	f0.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
loc_82759CD4:
	// lfs f13,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fmr f10,f30
	ctx.f10.f64 = f30.f64;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// lfs f0,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// bge cr6,0x82759cf0
	if (!cr6.lt) goto loc_82759CF0;
	// stfs f31,28(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
loc_82759CF0:
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f31.f64);
	// bge cr6,0x82759cfc
	if (!cr6.lt) goto loc_82759CFC;
	// fmr f10,f31
	ctx.f10.f64 = f31.f64;
loc_82759CFC:
	// fsubs f9,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f12,-6172(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6172);
	ctx.f12.f64 = double(temp.f32);
	// fabs f9,f9
	ctx.f9.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f12
	cr6.compare(ctx.f9.f64, ctx.f12.f64);
	// bge cr6,0x82759d20
	if (!cr6.lt) goto loc_82759D20;
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fmuls f0,f0,f11
	f0.f64 = double(float(f0.f64 * ctx.f11.f64));
	// b 0x82759d58
	goto loc_82759D58;
loc_82759D20:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-11316(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11316);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x82759d44
	if (!cr6.lt) goto loc_82759D44;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82759d4c
	if (cr6.gt) goto loc_82759D4C;
loc_82759D3C:
	// fdivs f0,f0,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 / ctx.f10.f64));
	// b 0x82759d54
	goto loc_82759D54;
loc_82759D44:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82759d3c
	if (cr6.gt) goto loc_82759D3C;
loc_82759D4C:
	// lfs f0,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	f0.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
loc_82759D54:
	// fmuls f0,f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
loc_82759D58:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82759d6c
	if (!cr6.lt) goto loc_82759D6C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82759D6C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82759d80
	if (!cr6.gt) goto loc_82759D80;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_82759D80:
	// stfs f10,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f0,4(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// lfd f30,-80(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82759D98"))) PPC_WEAK_FUNC(sub_82759D98);
PPC_FUNC_IMPL(__imp__sub_82759D98) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82759DA0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r25,r7,320
	r25.s64 = ctx.r7.s64 + 320;
	// addi r24,r7,368
	r24.s64 = ctx.r7.s64 + 368;
	// lfs f0,-32032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32032);
	f0.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// addi r28,r10,-3688
	r28.s64 = ctx.r10.s64 + -3688;
	// addi r11,r11,5768
	r11.s64 = r11.s64 + 5768;
	// ble cr6,0x82759ddc
	if (!cr6.gt) goto loc_82759DDC;
	// addi r10,r11,1644
	ctx.r10.s64 = r11.s64 + 1644;
	// mr r22,r11
	r22.u64 = r11.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// b 0x82759de8
	goto loc_82759DE8;
loc_82759DDC:
	// addi r10,r11,2744
	ctx.r10.s64 = r11.s64 + 2744;
	// addi r22,r11,48
	r22.s64 = r11.s64 + 48;
	// addi r8,r28,24
	ctx.r8.s64 = r28.s64 + 24;
loc_82759DE8:
	// stw r10,-112(r1)
	PPC_STORE_U32(ctx.r1.u32 + -112, ctx.r10.u32);
	// addi r10,r11,3600
	ctx.r10.s64 = r11.s64 + 3600;
	// addi r7,r11,4324
	ctx.r7.s64 = r11.s64 + 4324;
	// stw r10,-108(r1)
	PPC_STORE_U32(ctx.r1.u32 + -108, ctx.r10.u32);
	// addi r10,r28,48
	ctx.r10.s64 = r28.s64 + 48;
	// stw r7,-104(r1)
	PPC_STORE_U32(ctx.r1.u32 + -104, ctx.r7.u32);
	// addi r7,r1,-112
	ctx.r7.s64 = ctx.r1.s64 + -112;
	// addi r31,r10,-16
	r31.s64 = ctx.r10.s64 + -16;
	// subf r23,r7,r8
	r23.s64 = ctx.r8.s64 - ctx.r7.s64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r11,r11,4984
	r11.s64 = r11.s64 + 4984;
	// li r27,0
	r27.s64 = 0;
	// stw r11,-100(r1)
	PPC_STORE_U32(ctx.r1.u32 + -100, r11.u32);
	// li r26,0
	r26.s64 = 0;
	// lfs f13,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// li r29,0
	r29.s64 = 0;
	// lfs f12,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// mr r11,r25
	r11.u64 = r25.u64;
	// addi r6,r1,-112
	ctx.r6.s64 = ctx.r1.s64 + -112;
loc_82759E38:
	// cmpwi cr6,r26,4
	cr6.compare<int32_t>(r26.s32, 4, xer);
	// bge cr6,0x82759f0c
	if (!cr6.lt) goto loc_82759F0C;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r8,r8,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f0,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82759e98
	if (!cr6.gt) goto loc_82759E98;
	// lwz r30,0(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,28(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
loc_82759E7C:
	// lwz r21,0(r7)
	r21.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmpw cr6,r21,r30
	cr6.compare<int32_t>(r21.s32, r30.s32, xer);
	// beq cr6,0x82759f04
	if (cr6.eq) goto loc_82759F04;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// blt cr6,0x82759e7c
	if (cr6.lt) goto loc_82759E7C;
loc_82759E98:
	// lwz r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
loc_82759E9C:
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r8,r3,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lfs f10,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f10
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// lfs f8,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f10,f10,f7
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f7.f64));
	// lfs f6,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f9,f8,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f9.f64));
	// fmsubs f10,f8,f6,f10
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f6.f64 - ctx.f10.f64));
	// fdivs f9,f12,f9
	ctx.f9.f64 = double(float(ctx.f12.f64 / ctx.f9.f64));
	// fmadds f0,f10,f9,f0
	f0.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f10,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f10,f10,f6
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f6.f64));
	// fmadds f0,f0,f7,f10
	f0.f64 = double(float(f0.f64 * ctx.f7.f64 + ctx.f10.f64));
	// fmadds f0,f0,f9,f11
	f0.f64 = double(float(f0.f64 * ctx.f9.f64 + ctx.f11.f64));
	// b 0x82759f2c
	goto loc_82759F2C;
loc_82759F04:
	// lwz r7,20(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// b 0x82759e9c
	goto loc_82759E9C;
loc_82759F0C:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,4(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
loc_82759F2C:
	// lwzx r10,r23,r6
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + ctx.r6.u32);
	// stfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// mr r30,r24
	r30.u64 = r24.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// subf r8,r25,r10
	ctx.r8.s64 = ctx.r10.s64 - r25.s64;
loc_82759F40:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82759f6c
	if (!cr6.gt) goto loc_82759F6C;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
loc_82759F54:
	// lfsx f11,r8,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lfs f10,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fmadds f0,f11,f10,f0
	f0.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + f0.f64));
	// bne 0x82759f54
	if (!cr0.eq) goto loc_82759F54;
loc_82759F6C:
	// stfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// add r8,r29,r8
	ctx.r8.u64 = r29.u64 + ctx.r8.u64;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82759f40
	if (!cr0.eq) goto loc_82759F40;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r7,r28,48
	ctx.r7.s64 = r28.s64 + 48;
	// lfs f11,0(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r27,1
	ctx.r10.s64 = r27.s64 + 1;
	// fadds f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 + f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lfs f0,4(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 4);
	f0.f64 = double(temp.f32);
	// addi r8,r29,4
	ctx.r8.s64 = r29.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 + f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r27,r10,1
	r27.s64 = ctx.r10.s64 + 1;
	// addi r29,r8,4
	r29.s64 = ctx.r8.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmpw cr6,r31,r7
	cr6.compare<int32_t>(r31.s32, ctx.r7.s32, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// blt cr6,0x82759e38
	if (cr6.lt) goto loc_82759E38;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8275a010
	if (!cr6.gt) goto loc_8275A010;
	// mr r11,r25
	r11.u64 = r25.u64;
	// subf r9,r25,r22
	ctx.r9.s64 = r22.s64 - r25.s64;
	// subf r8,r25,r4
	ctx.r8.s64 = ctx.r4.s64 - r25.s64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
loc_82759FF4:
	// lfsx f0,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfsx f0,r11,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82759ff4
	if (!cr0.eq) goto loc_82759FF4;
loc_8275A010:
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8275A014"))) PPC_WEAK_FUNC(sub_8275A014);
PPC_FUNC_IMPL(__imp__sub_8275A014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275A018"))) PPC_WEAK_FUNC(sub_8275A018);
PPC_FUNC_IMPL(__imp__sub_8275A018) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,92(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 92);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x8275a04c
	if (!cr6.eq) goto loc_8275A04C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f5,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f5.f64 = double(temp.f32);
	// b 0x8275a058
	goto loc_8275A058;
loc_8275A04C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// lfs f5,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f5.f64 = double(temp.f32);
loc_8275A058:
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r7,r3,104
	ctx.r7.s64 = ctx.r3.s64 + 104;
	// lwz r30,20(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lfs f4,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f4.f64 = double(temp.f32);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f3,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f3.f64 = double(temp.f32);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f2,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f1,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x8275a798
	ctx.lr = 0x8275A09C;
	sub_8275A798(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275A0C0"))) PPC_WEAK_FUNC(sub_8275A0C0);
PPC_FUNC_IMPL(__imp__sub_8275A0C0) {
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
	ctx.lr = 0x8275A0C8;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d8
	ctx.lr = 0x8275A0D0;
	// stwu r1,-816(r1)
	ea = -816 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32111
	r27.s64 = -2104426496;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// fmr f28,f2
	f28.f64 = ctx.f2.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// lwz r11,-21248(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -21248);
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// addi r25,r30,2316
	r25.s64 = r30.s64 + 2316;
	// addi r26,r30,2056
	r26.s64 = r30.s64 + 2056;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,2316
	ctx.r5.s64 = 2316;
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275A118;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r11,12
	r11.s64 = 12;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lfs f13,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
loc_8275A130:
	// lfs f12,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lwz r9,-3632(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -3632);
	// lfs f0,12872(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12872);
	f0.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fmadds f0,f0,f12,f13
	f0.f64 = double(float(f0.f64 * ctx.f12.f64 + ctx.f13.f64));
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r6,r6,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lfsx f0,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8275a130
	if (!cr0.eq) goto loc_8275A130;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r30,224
	ctx.r5.s64 = r30.s64 + 224;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f30,224(r30)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 224, temp.u32);
loc_8275A188:
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lfsx f0,r10,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	f0.f64 = double(temp.f32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// stfs f13,4(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// blt cr6,0x8275a1dc
	if (cr6.lt) goto loc_8275A1DC;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r4,r11,r9
	ctx.r4.s64 = ctx.r9.s64 - r11.s64;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_8275A1BC:
	// lfs f13,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfsx f12,r4,r8
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r6,-4
	ctx.r6.s64 = ctx.r6.s64 + -4;
	// fnmsubs f13,f13,f0,f12
	ctx.f13.f64 = double(float(-(ctx.f13.f64 * f0.f64 - ctx.f12.f64)));
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8275a1bc
	if (!cr0.eq) goto loc_8275A1BC;
loc_8275A1DC:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpwi cr6,r10,48
	cr6.compare<int32_t>(ctx.r10.s32, 48, xer);
	// blt cr6,0x8275a188
	if (cr6.lt) goto loc_8275A188;
	// mr r11,r29
	r11.u64 = r29.u64;
	// subf r9,r29,r5
	ctx.r9.s64 = ctx.r5.s64 - r29.s64;
	// subf r8,r29,r30
	ctx.r8.s64 = r30.s64 - r29.s64;
	// subf r7,r29,r28
	ctx.r7.s64 = r28.s64 - r29.s64;
	// li r10,12
	ctx.r10.s64 = 12;
loc_8275A200:
	// lfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfsx f0,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r7,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8275a200
	if (!cr0.eq) goto loc_8275A200;
	// addi r31,r30,48
	r31.s64 = r30.s64 + 48;
	// stfs f29,48(r30)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r30.u32 + 48, temp.u32);
	// li r11,1
	r11.s64 = 1;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// subf r6,r31,r5
	ctx.r6.s64 = ctx.r5.s64 - r31.s64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8275A234:
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// lfsx f0,r10,r6
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// ble cr6,0x8275a284
	if (!cr6.gt) goto loc_8275A284;
	// addi r7,r5,4
	ctx.r7.s64 = ctx.r5.s64 + 4;
	// addi r8,r10,-4
	ctx.r8.s64 = ctx.r10.s64 + -4;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_8275A268:
	// lfs f13,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// fnmsubs f0,f13,f12,f0
	f0.f64 = double(float(-(ctx.f13.f64 * ctx.f12.f64 - f0.f64)));
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x8275a268
	if (!cr0.eq) goto loc_8275A268;
loc_8275A284:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// ble cr6,0x8275a234
	if (!cr6.gt) goto loc_8275A234;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmpwi cr6,r11,43
	cr6.compare<int32_t>(r11.s32, 43, xer);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// bgt cr6,0x8275a2f4
	if (cr6.gt) goto loc_8275A2F4;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r5,4
	ctx.r7.s64 = ctx.r5.s64 + 4;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// subfic r6,r11,44
	xer.ca = r11.u32 <= 44;
	ctx.r6.s64 = 44 - r11.s64;
loc_8275A2B8:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r9,r10,-4
	ctx.r9.s64 = ctx.r10.s64 + -4;
	// li r11,12
	r11.s64 = 12;
loc_8275A2C8:
	// lfs f13,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// fnmsubs f0,f13,f12,f0
	f0.f64 = double(float(-(ctx.f13.f64 * ctx.f12.f64 - f0.f64)));
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8275a2c8
	if (!cr0.eq) goto loc_8275A2C8;
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8275a2b8
	if (!cr0.eq) goto loc_8275A2B8;
loc_8275A2F4:
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r10,43
	ctx.r10.s64 = 43;
	// lwz r9,-3620(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3620);
	// subf r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - r31.s64;
loc_8275A308:
	// lfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8275a308
	if (!cr0.eq) goto loc_8275A308;
	// lwz r11,-21248(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -21248);
	// li r5,260
	ctx.r5.s64 = 260;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275A33C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-21248(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -21248);
	// li r5,260
	ctx.r5.s64 = 260;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275A354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,432
	r11.s64 = ctx.r1.s64 + 432;
	// addi r6,r1,348
	ctx.r6.s64 = ctx.r1.s64 + 348;
	// addi r10,r1,684
	ctx.r10.s64 = ctx.r1.s64 + 684;
	// lfs f13,11320(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11320);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// lfs f0,11316(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11316);
	f0.f64 = double(temp.f32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// li r8,21
	ctx.r8.s64 = 21;
loc_8275A384:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,0(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f12,0(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r6,r6,-4
	ctx.r6.s64 = ctx.r6.s64 + -4;
	// bne 0x8275a384
	if (!cr0.eq) goto loc_8275A384;
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// li r5,128
	ctx.r5.s64 = 128;
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmuls f0,f12,f13
	f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r4,r1,432
	ctx.r4.s64 = ctx.r1.s64 + 432;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827581e8
	ctx.lr = 0x8275A3F0;
	sub_827581E8(ctx, base);
	// subf r11,r30,r25
	r11.s64 = r25.s64 - r30.s64;
	// li r10,65
	ctx.r10.s64 = 65;
	// addi r11,r11,-2316
	r11.s64 = r11.s64 + -2316;
	// subf r9,r25,r26
	ctx.r9.s64 = r26.s64 - r25.s64;
loc_8275A400:
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,432
	ctx.r7.s64 = ctx.r1.s64 + 432;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfsx f0,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// lfsx f13,r11,r7
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stfsx f0,r9,r25
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + r25.u32, temp.u32);
	// stfs f13,0(r25)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bgt 0x8275a400
	if (cr0.gt) goto loc_8275A400;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8275c290
	ctx.lr = 0x8275A438;
	sub_8275C290(ctx, base);
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// fcmpu cr6,f28,f30
	cr6.compare(f28.f64, f30.f64);
	// bne cr6,0x8275a458
	if (!cr6.eq) goto loc_8275A458;
	// extsh. r11,r23
	r11.s64 = r23.s16;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8275a458
	if (!cr0.eq) goto loc_8275A458;
	// extsh. r11,r24
	r11.s64 = r24.s16;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8275a51c
	if (cr0.eq) goto loc_8275A51C;
loc_8275A458:
	// li r9,0
	ctx.r9.s64 = 0;
	// extsh r6,r24
	ctx.r6.s64 = r24.s16;
	// mr r11,r30
	r11.u64 = r30.u64;
	// subf r7,r30,r26
	ctx.r7.s64 = r26.s64 - r30.s64;
loc_8275A468:
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// blt cr6,0x8275a4c0
	if (cr6.lt) goto loc_8275A4C0;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// extsh r10,r23
	ctx.r10.s64 = r23.s16;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f12,f12,f28
	ctx.f12.f64 = double(float(ctx.f12.f64 * f28.f64));
	// fctiwz f12,f12
	ctx.f12.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f12,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f12.u64);
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// lfsx f12,r8,r26
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r26.u32);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// bgt cr6,0x8275a4b8
	if (cr6.gt) goto loc_8275A4B8;
	// lfsx f12,r8,r26
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r26.u32);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8275a4c4
	goto loc_8275A4C4;
loc_8275A4B8:
	// lfs f12,256(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 256);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8275a4c4
	goto loc_8275A4C4;
loc_8275A4C0:
	// lfsx f12,r7,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
loc_8275A4C4:
	// stfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lfsx f12,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 + f0.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// fadds f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f11.f64));
	// cmpwi cr6,r9,65
	cr6.compare<int32_t>(ctx.r9.s32, 65, xer);
	// blt cr6,0x8275a468
	if (cr6.lt) goto loc_8275A468;
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// mr r11,r26
	r11.u64 = r26.u64;
	// subf r9,r26,r30
	ctx.r9.s64 = r30.s64 - r26.s64;
	// li r10,65
	ctx.r10.s64 = 65;
	// lfs f0,11312(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11312);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_8275A504:
	// lfsx f13,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8275a504
	if (!cr0.eq) goto loc_8275A504;
loc_8275A51C:
	// addi r1,r1,816
	ctx.r1.s64 = ctx.r1.s64 + 816;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x8275A528;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8275A52C"))) PPC_WEAK_FUNC(sub_8275A52C);
PPC_FUNC_IMPL(__imp__sub_8275A52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275A530"))) PPC_WEAK_FUNC(sub_8275A530);
PPC_FUNC_IMPL(__imp__sub_8275A530) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8275A538;
	// lwz r30,12(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// slw r9,r10,r5
	ctx.r9.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r5.u8 & 0x3F));
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r31,r9,-1
	r31.s64 = ctx.r9.s64 + -1;
	// lhz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lhz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 + ctx.r5.u64;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm. r5,r7,0,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF8;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq 0x8275a5d4
	if (cr0.eq) goto loc_8275A5D4;
	// lbz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// clrlwi r29,r6,16
	r29.u64 = ctx.r6.u32 & 0xFFFF;
	// subfic r6,r9,8
	xer.ca = ctx.r9.u32 <= 8;
	ctx.r6.s64 = 8 - ctx.r9.s64;
	// srw r10,r5,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r10.u8 & 0x3F));
	// stb r10,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r10.u8);
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// cmplw cr6,r10,r29
	cr6.compare<uint32_t>(ctx.r10.u32, r29.u32, xer);
	// blt cr6,0x8275a5b0
	if (cr6.lt) goto loc_8275A5B0;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8275A5B0:
	// lbz r11,0(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// sraw r10,r31,r6
	temp.u32 = ctx.r6.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r31.s32 < 0) & (((r31.s32 >> temp.u32) << temp.u32) != r31.s32);
	ctx.r10.s64 = r31.s32 >> temp.u32;
	// and r11,r10,r11
	r11.u64 = ctx.r10.u64 & r11.u64;
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r7,r7,-8
	ctx.r7.s64 = ctx.r7.s64 + -8;
	// slw r11,r11,r6
	r11.u64 = ctx.r6.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r6.u8 & 0x3F));
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// b 0x8275a614
	goto loc_8275A614;
loc_8275A5D4:
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// clrlwi r8,r31,24
	ctx.r8.u64 = r31.u32 & 0xFF;
	// cmpwi cr6,r7,8
	cr6.compare<int32_t>(ctx.r7.s32, 8, xer);
	// srw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r10.u8 & 0x3F));
	// and r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	// stb r10,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r10.u8);
	// bne cr6,0x8275a614
	if (!cr6.eq) goto loc_8275A614;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// clrlwi r9,r6,16
	ctx.r9.u64 = ctx.r6.u32 & 0xFFFF;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8275a614
	if (cr6.lt) goto loc_8275A614;
	// sth r7,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r7.u16);
loc_8275A614:
	// stb r7,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r7.u8);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275A61C"))) PPC_WEAK_FUNC(sub_8275A61C);
PPC_FUNC_IMPL(__imp__sub_8275A61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275A620"))) PPC_WEAK_FUNC(sub_8275A620);
PPC_FUNC_IMPL(__imp__sub_8275A620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x8275a684
	if (cr6.eq) goto loc_8275A684;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r11,-21256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21256);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275A660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8275a670
	if (!cr0.eq) goto loc_8275A670;
	// li r30,1
	r30.s64 = 1;
	// b 0x8275a680
	goto loc_8275A680;
loc_8275A670:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lfs f0,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
loc_8275A680:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8275A684:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

