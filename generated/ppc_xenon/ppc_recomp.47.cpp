#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822CDC1C"))) PPC_WEAK_FUNC(sub_822CDC1C);
PPC_FUNC_IMPL(__imp__sub_822CDC1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CDC20"))) PPC_WEAK_FUNC(sub_822CDC20);
PPC_FUNC_IMPL(__imp__sub_822CDC20) {
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
	// lis r11,4095
	r11.s64 = 268369920;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// ble cr6,0x822cdc50
	if (!cr6.gt) goto loc_822CDC50;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-15120
	ctx.r3.s64 = r11.s64 + -15120;
	// bl 0x823dd898
	ctx.lr = 0x822CDC48;
	sub_823DD898(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823db0a0
	ctx.lr = 0x822CDC50;
	sub_823DB0A0(ctx, base);
loc_822CDC50:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822cdc70
	if (cr6.eq) goto loc_822CDC70;
	// rlwinm r3,r4,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x822CDC60;
	sub_82130528(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822CDC70:
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

__attribute__((alias("__imp__sub_822CDC84"))) PPC_WEAK_FUNC(sub_822CDC84);
PPC_FUNC_IMPL(__imp__sub_822CDC84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CDC88"))) PPC_WEAK_FUNC(sub_822CDC88);
PPC_FUNC_IMPL(__imp__sub_822CDC88) {
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
	ctx.lr = 0x822CDC90;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r26,r28,52
	r26.s64 = r28.s64 + 52;
	// lwz r30,52(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// lwz r11,56(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x822cddb4
	if (cr6.eq) goto loc_822CDDB4;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_822CDCB0:
	// lbz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// addi r29,r30,8
	r29.s64 = r30.s64 + 8;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// rlwinm r8,r9,0,27,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1C;
	// cmplwi cr6,r8,20
	cr6.compare<uint32_t>(ctx.r8.u32, 20, xer);
	// beq cr6,0x822cdda4
	if (cr6.eq) goto loc_822CDDA4;
	// rlwinm r9,r10,8,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// cmpwi cr6,r8,97
	cr6.compare<int32_t>(ctx.r8.s32, 97, xer);
	// bne cr6,0x822cdce0
	if (!cr6.eq) goto loc_822CDCE0;
	// li r11,1
	r11.s64 = 1;
loc_822CDCE0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cdd90
	if (cr6.eq) goto loc_822CDD90;
	// lhz r11,1628(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 1628);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cdd90
	if (cr6.eq) goto loc_822CDD90;
	// divwu r9,r10,r11
	ctx.r9.u32 = ctx.r10.u32 / r11.u32;
	// lwz r8,1624(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 1624);
	// twllei r11,0
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r5,r8
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cdd90
	if (cr6.eq) goto loc_822CDD90;
loc_822CDD1C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x822cdd38
	if (cr6.eq) goto loc_822CDD38;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cdd1c
	if (!cr6.eq) goto loc_822CDD1C;
	// b 0x822cdd90
	goto loc_822CDD90;
loc_822CDD38:
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822cdd90
	if (cr6.eq) goto loc_822CDD90;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822cdd74
	if (cr6.lt) goto loc_822CDD74;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822CDD58;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r25,0(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822CDD6C;
	sub_82270170(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82274430
	ctx.lr = 0x822CDD74;
	sub_82274430(ctx, base);
loc_822CDD74:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822cdd90
	if (cr6.lt) goto loc_822CDD90;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82457940
	ctx.lr = 0x822CDD90;
	sub_82457940(ctx, base);
loc_822CDD90:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,30,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFE3;
	// ori r9,r10,20
	ctx.r9.u64 = ctx.r10.u64 | 20;
	// stb r9,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r9.u8);
loc_822CDDA4:
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x822cdcb0
	if (!cr6.eq) goto loc_822CDCB0;
loc_822CDDB4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822CDDBC"))) PPC_WEAK_FUNC(sub_822CDDBC);
PPC_FUNC_IMPL(__imp__sub_822CDDBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CDDC0"))) PPC_WEAK_FUNC(sub_822CDDC0);
PPC_FUNC_IMPL(__imp__sub_822CDDC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822cde14
	if (cr6.eq) goto loc_822CDE14;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// srawi. r10,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x822cde14
	if (!cr0.gt) goto loc_822CDE14;
loc_822CDDE4:
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r5,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r5.u32);
	// lwz r3,28(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// stw r3,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r3.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// bgt 0x822cdde4
	if (cr0.gt) goto loc_822CDDE4;
loc_822CDE14:
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822CDE28"))) PPC_WEAK_FUNC(sub_822CDE28);
PPC_FUNC_IMPL(__imp__sub_822CDE28) {
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
	ctx.lr = 0x822CDE30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822cde58
	if (!cr6.eq) goto loc_822CDE58;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x822CDE58;
	sub_82608A98(ctx, base);
loc_822CDE58:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x822cde88
	if (!cr6.eq) goto loc_822CDE88;
	// bl 0x821c9438
	ctx.lr = 0x822CDE7C;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822cd600
	ctx.lr = 0x822CDE88;
	sub_822CD600(ctx, base);
loc_822CDE88:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r3,16
	ctx.r3.s64 = 16;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// twllei r11,0
	// divwu r8,r10,r11
	ctx.r8.u32 = ctx.r10.u32 / r11.u32;
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r30,r6,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r30,r9
	r29.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x822CDEB4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cdee0
	if (cr6.eq) goto loc_822CDEE0;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// stw r29,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r29.u32);
	// b 0x822cdee4
	goto loc_822CDEE4;
loc_822CDEE0:
	// li r11,0
	r11.s64 = 0;
loc_822CDEE4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r11,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, r11.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r9
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822CDEFC"))) PPC_WEAK_FUNC(sub_822CDEFC);
PPC_FUNC_IMPL(__imp__sub_822CDEFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CDF00"))) PPC_WEAK_FUNC(sub_822CDF00);
PPC_FUNC_IMPL(__imp__sub_822CDF00) {
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
	ctx.lr = 0x822CDF08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// subf r11,r28,r4
	r11.s64 = ctx.r4.s64 - r28.s64;
	// srawi. r31,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	r31.s64 = r11.s32 >> 4;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// ble 0x822cdf60
	if (!cr0.gt) goto loc_822CDF60;
loc_822CDF20:
	// srawi r30,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	r30.s64 = r31.s32 >> 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r29,r11,r28
	r29.u64 = r11.u64 + r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238d550
	ctx.lr = 0x822CDF38;
	sub_8238D550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cdf54
	if (cr6.eq) goto loc_822CDF54;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// addi r28,r29,16
	r28.s64 = r29.s64 + 16;
	// addi r31,r11,-1
	r31.s64 = r11.s64 + -1;
	// b 0x822cdf58
	goto loc_822CDF58;
loc_822CDF54:
	// mr r31,r30
	r31.u64 = r30.u64;
loc_822CDF58:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bgt cr6,0x822cdf20
	if (cr6.gt) goto loc_822CDF20;
loc_822CDF60:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822CDF6C"))) PPC_WEAK_FUNC(sub_822CDF6C);
PPC_FUNC_IMPL(__imp__sub_822CDF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CDF70"))) PPC_WEAK_FUNC(sub_822CDF70);
PPC_FUNC_IMPL(__imp__sub_822CDF70) {
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
	ctx.lr = 0x822CDF78;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplw cr6,r6,r10
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r10.u32, xer);
	// blt cr6,0x822cdf9c
	if (cr6.lt) goto loc_822CDF9C;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r6,r10
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r10.u32, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// blt cr6,0x822cdfa0
	if (cr6.lt) goto loc_822CDFA0;
loc_822CDF9C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822CDFA0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cdff4
	if (cr6.eq) goto loc_822CDFF4;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r8,4(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// lwz r30,8(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// li r29,0
	r29.s64 = 0;
	// lwz r28,12(r6)
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r30,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r30.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r29.u8);
	// stw r28,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r28.u32);
	// bl 0x822cdf70
	ctx.lr = 0x822CDFEC;
	sub_822CDF70(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_822CDFF4:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// srawi r7,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 4;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplw cr6,r7,r5
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r5.u32, xer);
	// ble cr6,0x822ce0e4
	if (!cr6.gt) goto loc_822CE0E4;
	// rlwinm r5,r5,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r7,r5,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r5.s64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// beq cr6,0x822ce058
	if (cr6.eq) goto loc_822CE058;
loc_822CE020:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ce048
	if (cr6.eq) goto loc_822CE048;
	// lwz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r4,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r4.u32);
	// lwz r4,8(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r4,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r4.u32);
	// lwz r4,12(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// stw r4,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r4.u32);
loc_822CE048:
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bne cr6,0x822ce020
	if (!cr6.eq) goto loc_822CE020;
loc_822CE058:
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r8,r11,r7
	ctx.r8.s64 = ctx.r7.s64 - r11.s64;
	// add r4,r9,r5
	ctx.r4.u64 = ctx.r9.u64 + ctx.r5.u64;
	// srawi. r8,r8,4
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 4;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// ble 0x822ce0a4
	if (!cr0.gt) goto loc_822CE0A4;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_822CE074:
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r3,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r3.u32);
	// lwz r7,12(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// bgt 0x822ce074
	if (cr0.gt) goto loc_822CE074;
loc_822CE0A4:
	// add r10,r5,r11
	ctx.r10.u64 = ctx.r5.u64 + r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822ce1ac
	if (cr6.eq) goto loc_822CE1AC;
loc_822CE0B0:
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r7,8(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// lwz r5,12(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stw r5,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r5.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822ce0b0
	if (!cr6.eq) goto loc_822CE0B0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_822CE0E4:
	// subf. r8,r7,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x822ce120
	if (cr0.eq) goto loc_822CE120;
loc_822CE0EC:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ce114
	if (cr6.eq) goto loc_822CE114;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r4,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r4.u32);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r5,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r5.u32);
	// lwz r4,12(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stw r4,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r4.u32);
loc_822CE114:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x822ce0ec
	if (!cr0.eq) goto loc_822CE0EC;
loc_822CE120:
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822ce168
	if (cr6.eq) goto loc_822CE168;
loc_822CE130:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ce158
	if (cr6.eq) goto loc_822CE158;
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r4,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r4.u32);
	// lwz r5,8(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r5,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r5.u32);
	// lwz r4,12(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// stw r4,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r4.u32);
loc_822CE158:
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bne cr6,0x822ce130
	if (!cr6.eq) goto loc_822CE130;
loc_822CE168:
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// beq cr6,0x822ce1ac
	if (cr6.eq) goto loc_822CE1AC;
loc_822CE180:
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r7,8(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// lwz r5,12(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stw r5,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r5.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822ce180
	if (!cr6.eq) goto loc_822CE180;
loc_822CE1AC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822CE1B4"))) PPC_WEAK_FUNC(sub_822CE1B4);
PPC_FUNC_IMPL(__imp__sub_822CE1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CE1B8"))) PPC_WEAK_FUNC(sub_822CE1B8);
PPC_FUNC_IMPL(__imp__sub_822CE1B8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822CE1C0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x8238e5c0
	ctx.lr = 0x822CE1CC;
	sub_8238E5C0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// addi r27,r29,64
	r27.s64 = r29.s64 + 64;
	// stw r10,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r10.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r9,-28552
	ctx.r4.s64 = ctx.r9.s64 + -28552;
	// addi r3,r27,4
	ctx.r3.s64 = r27.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x822CE1F0;
	sub_823DB670(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// li r28,0
	r28.s64 = 0;
	// addi r4,r8,-18492
	ctx.r4.s64 = ctx.r8.s64 + -18492;
	// addi r3,r7,-18508
	ctx.r3.s64 = ctx.r7.s64 + -18508;
	// stw r28,100(r29)
	PPC_STORE_U32(r29.u32 + 100, r28.u32);
	// addi r11,r6,19212
	r11.s64 = ctx.r6.s64 + 19212;
	// stw r4,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r4.u32);
	// addi r10,r5,19036
	ctx.r10.s64 = ctx.r5.s64 + 19036;
	// stw r3,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r3.u32);
	// lis r8,8192
	ctx.r8.s64 = 536870912;
	// stw r28,104(r29)
	PPC_STORE_U32(r29.u32 + 104, r28.u32);
	// stw r28,108(r29)
	PPC_STORE_U32(r29.u32 + 108, r28.u32);
	// lis r7,8192
	ctx.r7.s64 = 536870912;
	// stw r28,112(r29)
	PPC_STORE_U32(r29.u32 + 112, r28.u32);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// stw r28,116(r29)
	PPC_STORE_U32(r29.u32 + 116, r28.u32);
	// ori r3,r8,30
	ctx.r3.u64 = ctx.r8.u64 | 30;
	// stw r11,120(r29)
	PPC_STORE_U32(r29.u32 + 120, r11.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// stw r10,124(r29)
	PPC_STORE_U32(r29.u32 + 124, ctx.r10.u32);
	// ori r10,r7,31
	ctx.r10.u64 = ctx.r7.u64 | 31;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// stw r3,148(r29)
	PPC_STORE_U32(r29.u32 + 148, ctx.r3.u32);
	// ori r4,r9,27
	ctx.r4.u64 = ctx.r9.u64 | 27;
	// std r28,132(r29)
	PPC_STORE_U64(r29.u32 + 132, r28.u64);
	// li r26,3
	r26.s64 = 3;
	// stw r10,160(r29)
	PPC_STORE_U32(r29.u32 + 160, ctx.r10.u32);
	// addi r9,r6,19232
	ctx.r9.s64 = ctx.r6.s64 + 19232;
	// stw r4,140(r29)
	PPC_STORE_U32(r29.u32 + 140, ctx.r4.u32);
	// addi r6,r5,19116
	ctx.r6.s64 = ctx.r5.s64 + 19116;
	// stw r26,128(r29)
	PPC_STORE_U32(r29.u32 + 128, r26.u32);
	// lbz r8,640(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 640);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// addi r11,r29,120
	r11.s64 = r29.s64 + 120;
	// stb r7,640(r29)
	PPC_STORE_U8(r29.u32 + 640, ctx.r7.u8);
	// addi r3,r29,708
	ctx.r3.s64 = r29.s64 + 708;
	// stw r9,120(r29)
	PPC_STORE_U32(r29.u32 + 120, ctx.r9.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stw r6,648(r29)
	PPC_STORE_U32(r29.u32 + 648, ctx.r6.u32);
	// bl 0x822cd490
	ctx.lr = 0x822CE29C;
	sub_822CD490(ctx, base);
	// lis r5,24910
	ctx.r5.s64 = 1632501760;
	// li r3,61
	ctx.r3.s64 = 61;
	// sth r28,1630(r29)
	PPC_STORE_U16(r29.u32 + 1630, r28.u16);
	// ori r4,r5,21079
	ctx.r4.u64 = ctx.r5.u64 | 21079;
	// sth r28,1628(r29)
	PPC_STORE_U16(r29.u32 + 1628, r28.u16);
	// li r30,-1
	r30.s64 = -1;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r31,r29,1624
	r31.s64 = r29.s64 + 1624;
	// stw r28,1624(r29)
	PPC_STORE_U32(r29.u32 + 1624, r28.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stb r28,1635(r29)
	PPC_STORE_U8(r29.u32 + 1635, r28.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE2DC;
	sub_822CDE28(ctx, base);
	// lis r11,24898
	r11.s64 = 1631715328;
	// li r10,65
	ctx.r10.s64 = 65;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r9,r11,17219
	ctx.r9.u64 = r11.u64 | 17219;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE304;
	sub_822CDE28(ctx, base);
	// lis r8,24899
	ctx.r8.s64 = 1631780864;
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r6,r8,20300
	ctx.r6.u64 = ctx.r8.u64 | 20300;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE32C;
	sub_822CDE28(ctx, base);
	// lis r5,24899
	ctx.r5.s64 = 1631780864;
	// li r4,62
	ctx.r4.s64 = 62;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r5,20296
	r11.u64 = ctx.r5.u64 | 20296;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE354;
	sub_822CDE28(ctx, base);
	// lis r10,24919
	ctx.r10.s64 = 1633091584;
	// li r9,47
	ctx.r9.s64 = 47;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,12600
	ctx.r8.u64 = ctx.r10.u64 | 12600;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE37C;
	sub_822CDE28(ctx, base);
	// lis r7,24951
	ctx.r7.s64 = 1635188736;
	// li r6,38
	ctx.r6.s64 = 38;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,13635
	ctx.r5.u64 = ctx.r7.u64 | 13635;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE3A4;
	sub_822CDE28(ctx, base);
	// lis r4,24909
	ctx.r4.s64 = 1632436224;
	// li r3,48
	ctx.r3.s64 = 48;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,18764
	r11.u64 = ctx.r4.u64 | 18764;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE3CC;
	sub_822CDE28(ctx, base);
	// lis r10,24917
	ctx.r10.s64 = 1632960512;
	// li r9,35
	ctx.r9.s64 = 35;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,17752
	ctx.r8.u64 = ctx.r10.u64 | 17752;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE3F4;
	sub_822CDE28(ctx, base);
	// lis r7,24917
	ctx.r7.s64 = 1632960512;
	// li r6,34
	ctx.r6.s64 = 34;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,19791
	ctx.r5.u64 = ctx.r7.u64 | 19791;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE41C;
	sub_822CDE28(ctx, base);
	// lis r4,24898
	ctx.r4.s64 = 1631715328;
	// li r3,43
	ctx.r3.s64 = 43;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,12628
	r11.u64 = ctx.r4.u64 | 12628;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE444;
	sub_822CDE28(ctx, base);
	// lis r10,24882
	ctx.r10.s64 = 1630666752;
	// ori r9,r10,12336
	ctx.r9.u64 = ctx.r10.u64 | 12336;
	// li r8,46
	ctx.r8.s64 = 46;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE46C;
	sub_822CDE28(ctx, base);
	// lis r7,24917
	ctx.r7.s64 = 1632960512;
	// li r6,31
	ctx.r6.s64 = 31;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,21589
	ctx.r5.u64 = ctx.r7.u64 | 21589;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE494;
	sub_822CDE28(ctx, base);
	// lis r4,24917
	ctx.r4.s64 = 1632960512;
	// li r3,30
	ctx.r3.s64 = 30;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,19541
	r11.u64 = ctx.r4.u64 | 19541;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE4BC;
	sub_822CDE28(ctx, base);
	// lis r10,24898
	ctx.r10.s64 = 1631715328;
	// li r9,44
	ctx.r9.s64 = 44;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,16724
	ctx.r8.u64 = ctx.r10.u64 | 16724;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE4E4;
	sub_822CDE28(ctx, base);
	// lis r7,24898
	ctx.r7.s64 = 1631715328;
	// li r6,45
	ctx.r6.s64 = 45;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,21583
	ctx.r5.u64 = ctx.r7.u64 | 21583;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE50C;
	sub_822CDE28(ctx, base);
	// lis r4,24899
	ctx.r4.s64 = 1631780864;
	// li r3,42
	ctx.r3.s64 = 42;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,13636
	r11.u64 = ctx.r4.u64 | 13636;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE534;
	sub_822CDE28(ctx, base);
	// lis r10,24900
	ctx.r10.s64 = 1631846400;
	// li r9,41
	ctx.r9.s64 = 41;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,12592
	ctx.r8.u64 = ctx.r10.u64 | 12592;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE55C;
	sub_822CDE28(ctx, base);
	// lis r7,24914
	ctx.r7.s64 = 1632763904;
	// li r6,40
	ctx.r6.s64 = 40;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,21074
	ctx.r5.u64 = ctx.r7.u64 | 21074;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE584;
	sub_822CDE28(ctx, base);
	// lis r4,24922
	ctx.r4.s64 = 1633288192;
	// li r11,29
	r11.s64 = 29;
	// ori r3,r4,20302
	ctx.r3.u64 = ctx.r4.u64 | 20302;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE5AC;
	sub_822CDE28(ctx, base);
	// lis r10,24897
	ctx.r10.s64 = 1631649792;
	// li r9,27
	ctx.r9.s64 = 27;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,18258
	ctx.r8.u64 = ctx.r10.u64 | 18258;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE5D4;
	sub_822CDE28(ctx, base);
	// lis r7,24914
	ctx.r7.s64 = 1632763904;
	// li r6,24
	ctx.r6.s64 = 24;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,20306
	ctx.r5.u64 = ctx.r7.u64 | 20306;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE5FC;
	sub_822CDE28(ctx, base);
	// lis r4,24912
	ctx.r4.s64 = 1632632832;
	// li r3,28
	ctx.r3.s64 = 28;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,21836
	r11.u64 = ctx.r4.u64 | 21836;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE624;
	sub_822CDE28(ctx, base);
	// lis r10,24898
	ctx.r10.s64 = 1631715328;
	// li r9,39
	ctx.r9.s64 = 39;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,18763
	ctx.r8.u64 = ctx.r10.u64 | 18763;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE64C;
	sub_822CDE28(ctx, base);
	// lis r7,24882
	ctx.r7.s64 = 1630666752;
	// li r6,23
	ctx.r6.s64 = 23;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,22340
	ctx.r5.u64 = ctx.r7.u64 | 22340;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE674;
	sub_822CDE28(ctx, base);
	// lis r4,24919
	ctx.r4.s64 = 1633091584;
	// li r3,22
	ctx.r3.s64 = 22;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,18508
	r11.u64 = ctx.r4.u64 | 18508;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE69C;
	sub_822CDE28(ctx, base);
	// lis r10,24917
	ctx.r10.s64 = 1632960512;
	// li r9,33
	ctx.r9.s64 = 33;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,19797
	ctx.r8.u64 = ctx.r10.u64 | 19797;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE6C4;
	sub_822CDE28(ctx, base);
	// lis r7,24901
	ctx.r7.s64 = 1631911936;
	// li r6,19
	ctx.r6.s64 = 19;
	// ori r5,r7,22081
	ctx.r5.u64 = ctx.r7.u64 | 22081;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE6EC;
	sub_822CDE28(ctx, base);
	// lis r4,24914
	ctx.r4.s64 = 1632763904;
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,21838
	r11.u64 = ctx.r4.u64 | 21838;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE714;
	sub_822CDE28(ctx, base);
	// lis r10,24915
	ctx.r10.s64 = 1632829440;
	// li r9,52
	ctx.r9.s64 = 52;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,21061
	ctx.r8.u64 = ctx.r10.u64 | 21061;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE73C;
	sub_822CDE28(ctx, base);
	// lis r7,24902
	ctx.r7.s64 = 1631977472;
	// li r6,37
	ctx.r6.s64 = 37;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,22359
	ctx.r5.u64 = ctx.r7.u64 | 22359;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE764;
	sub_822CDE28(ctx, base);
	// lis r4,24900
	ctx.r4.s64 = 1631846400;
	// li r3,49
	ctx.r3.s64 = 49;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,21332
	r11.u64 = ctx.r4.u64 | 21332;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE78C;
	sub_822CDE28(ctx, base);
	// lis r10,24906
	ctx.r10.s64 = 1632239616;
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,17491
	ctx.r8.u64 = ctx.r10.u64 | 17491;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE7B4;
	sub_822CDE28(ctx, base);
	// lis r7,24906
	ctx.r7.s64 = 1632239616;
	// li r6,21
	ctx.r6.s64 = 21;
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r26.u32);
	// ori r5,r7,21581
	ctx.r5.u64 = ctx.r7.u64 | 21581;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE7DC;
	sub_822CDE28(ctx, base);
	// lis r4,24902
	ctx.r4.s64 = 1631977472;
	// li r3,53
	ctx.r3.s64 = 53;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,16706
	r11.u64 = ctx.r4.u64 | 16706;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE804;
	sub_822CDE28(ctx, base);
	// lis r10,24910
	ctx.r10.s64 = 1632501760;
	// li r9,60
	ctx.r9.s64 = 60;
	// ori r8,r10,17996
	ctx.r8.u64 = ctx.r10.u64 | 17996;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE82C;
	sub_822CDE28(ctx, base);
	// lis r7,24910
	ctx.r7.s64 = 1632501760;
	// li r6,59
	ctx.r6.s64 = 59;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,21332
	ctx.r5.u64 = ctx.r7.u64 | 21332;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE854;
	sub_822CDE28(ctx, base);
	// lis r4,24910
	ctx.r4.s64 = 1632501760;
	// li r3,58
	ctx.r3.s64 = 58;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,21059
	r11.u64 = ctx.r4.u64 | 21059;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE87C;
	sub_822CDE28(ctx, base);
	// lis r10,24910
	ctx.r10.s64 = 1632501760;
	// li r9,57
	ctx.r9.s64 = 57;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,21074
	ctx.r8.u64 = ctx.r10.u64 | 21074;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE8A4;
	sub_822CDE28(ctx, base);
	// lis r7,24910
	ctx.r7.s64 = 1632501760;
	// li r6,56
	ctx.r6.s64 = 56;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,21075
	ctx.r5.u64 = ctx.r7.u64 | 21075;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE8CC;
	sub_822CDE28(ctx, base);
	// lis r4,24910
	ctx.r4.s64 = 1632501760;
	// li r3,50
	ctx.r3.s64 = 50;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,19026
	r11.u64 = ctx.r4.u64 | 19026;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE8F4;
	sub_822CDE28(ctx, base);
	// lis r10,24910
	ctx.r10.s64 = 1632501760;
	// li r9,51
	ctx.r9.s64 = 51;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,21061
	ctx.r8.u64 = ctx.r10.u64 | 21061;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE91C;
	sub_822CDE28(ctx, base);
	// lis r7,24897
	ctx.r7.s64 = 1631649792;
	// li r6,66
	ctx.r6.s64 = 66;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,20306
	ctx.r5.u64 = ctx.r7.u64 | 20306;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE944;
	sub_822CDE28(ctx, base);
	// lis r4,24897
	ctx.r4.s64 = 1631649792;
	// li r3,67
	ctx.r3.s64 = 67;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,16722
	r11.u64 = ctx.r4.u64 | 16722;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE96C;
	sub_822CDE28(ctx, base);
	// lis r10,24899
	ctx.r10.s64 = 1631780864;
	// li r9,36
	ctx.r9.s64 = 36;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,20556
	ctx.r8.u64 = ctx.r10.u64 | 20556;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE994;
	sub_822CDE28(ctx, base);
	// lis r7,24916
	ctx.r7.s64 = 1632894976;
	// li r6,55
	ctx.r6.s64 = 55;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,19782
	ctx.r5.u64 = ctx.r7.u64 | 19782;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE9BC;
	sub_822CDE28(ctx, base);
	// lis r4,24897
	ctx.r4.s64 = 1631649792;
	// li r3,78
	ctx.r3.s64 = 78;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,21059
	r11.u64 = ctx.r4.u64 | 21059;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CE9E4;
	sub_822CDE28(ctx, base);
	// lis r10,24898
	ctx.r10.s64 = 1631715328;
	// li r9,77
	ctx.r9.s64 = 77;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,21315
	ctx.r8.u64 = ctx.r10.u64 | 21315;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CEA0C;
	sub_822CDE28(ctx, base);
	// lis r7,24908
	ctx.r7.s64 = 1632370688;
	// li r6,76
	ctx.r6.s64 = 76;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,21315
	ctx.r5.u64 = ctx.r7.u64 | 21315;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CEA34;
	sub_822CDE28(ctx, base);
	// lis r4,24900
	ctx.r4.s64 = 1631846400;
	// li r3,73
	ctx.r3.s64 = 73;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,21315
	r11.u64 = ctx.r4.u64 | 21315;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CEA5C;
	sub_822CDE28(ctx, base);
	// lis r10,24909
	ctx.r10.s64 = 1632436224;
	// li r9,69
	ctx.r9.s64 = 69;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,21315
	ctx.r8.u64 = ctx.r10.u64 | 21315;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CEA84;
	sub_822CDE28(ctx, base);
	// lis r7,24916
	ctx.r7.s64 = 1632894976;
	// li r6,74
	ctx.r6.s64 = 74;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,21315
	ctx.r5.u64 = ctx.r7.u64 | 21315;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CEAAC;
	sub_822CDE28(ctx, base);
	// lis r4,24919
	ctx.r4.s64 = 1633091584;
	// li r3,75
	ctx.r3.s64 = 75;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,21315
	r11.u64 = ctx.r4.u64 | 21315;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CEAD4;
	sub_822CDE28(ctx, base);
	// lis r10,24916
	ctx.r10.s64 = 1632894976;
	// li r9,70
	ctx.r9.s64 = 70;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r8,r10,17494
	ctx.r8.u64 = ctx.r10.u64 | 17494;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CEAFC;
	sub_822CDE28(ctx, base);
	// lis r7,24915
	ctx.r7.s64 = 1632829440;
	// li r6,71
	ctx.r6.s64 = 71;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r5,r7,21846
	ctx.r5.u64 = ctx.r7.u64 | 21846;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822cde28
	ctx.lr = 0x822CEB24;
	sub_822CDE28(ctx, base);
	// lis r4,24908
	ctx.r4.s64 = 1632370688;
	// li r3,72
	ctx.r3.s64 = 72;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// ori r11,r4,20311
	r11.u64 = ctx.r4.u64 | 20311;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822cde28
	ctx.lr = 0x822CEB4C;
	sub_822CDE28(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r28,656(r29)
	PPC_STORE_U32(r29.u32 + 656, r28.u32);
	// li r3,152
	ctx.r3.s64 = 152;
	// stw r28,660(r29)
	PPC_STORE_U32(r29.u32 + 660, r28.u32);
	// stw r28,668(r29)
	PPC_STORE_U32(r29.u32 + 668, r28.u32);
	// lfs f0,14988(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// stfs f0,664(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 664, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x822CEB6C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ceb7c
	if (cr6.eq) goto loc_822CEB7C;
	// bl 0x824f5c00
	ctx.lr = 0x822CEB78;
	sub_824F5C00(ctx, base);
	// b 0x822ceb80
	goto loc_822CEB80;
loc_822CEB7C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822CEB80:
	// stw r3,672(r29)
	PPC_STORE_U32(r29.u32 + 672, ctx.r3.u32);
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x82130528
	ctx.lr = 0x822CEB8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ceb9c
	if (cr6.eq) goto loc_822CEB9C;
	// bl 0x824f5c00
	ctx.lr = 0x822CEB98;
	sub_824F5C00(ctx, base);
	// b 0x822ceba0
	goto loc_822CEBA0;
loc_822CEB9C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822CEBA0:
	// stw r3,676(r29)
	PPC_STORE_U32(r29.u32 + 676, ctx.r3.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x822CEBAC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cebc4
	if (cr6.eq) goto loc_822CEBC4;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
	// b 0x822cebc8
	goto loc_822CEBC8;
loc_822CEBC4:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_822CEBC8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,680(r29)
	PPC_STORE_U32(r29.u32 + 680, r11.u32);
	// stw r28,688(r29)
	PPC_STORE_U32(r29.u32 + 688, r28.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// stw r28,692(r29)
	PPC_STORE_U32(r29.u32 + 692, r28.u32);
	// stw r28,696(r29)
	PPC_STORE_U32(r29.u32 + 696, r28.u32);
	// stw r28,1616(r29)
	PPC_STORE_U32(r29.u32 + 1616, r28.u32);
	// lfs f0,-1760(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1760);
	f0.f64 = double(temp.f32);
	// stb r28,701(r29)
	PPC_STORE_U8(r29.u32 + 701, r28.u8);
	// stfs f0,704(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 704, temp.u32);
	// stb r28,700(r29)
	PPC_STORE_U8(r29.u32 + 700, r28.u8);
	// bl 0x82130528
	ctx.lr = 0x822CEBF8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cec08
	if (cr6.eq) goto loc_822CEC08;
	// bl 0x822d4cd8
	ctx.lr = 0x822CEC04;
	sub_822D4CD8(ctx, base);
	// b 0x822cec0c
	goto loc_822CEC0C;
loc_822CEC08:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822CEC0C:
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stw r3,1620(r29)
	PPC_STORE_U32(r29.u32 + 1620, ctx.r3.u32);
	// addi r10,r29,12
	ctx.r10.s64 = r29.s64 + 12;
	// addi r8,r9,-18520
	ctx.r8.s64 = ctx.r9.s64 + -18520;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwz r7,-18520(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18520);
	// stw r7,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r7.u32);
	// lhz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// sth r6,16(r29)
	PPC_STORE_U16(r29.u32 + 16, ctx.r6.u16);
loc_822CEC30:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822cec30
	if (!cr6.eq) goto loc_822CEC30;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// li r10,16004
	ctx.r10.s64 = 16004;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// stw r9,44(r29)
	PPC_STORE_U32(r29.u32 + 44, ctx.r9.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stb r8,48(r29)
	PPC_STORE_U8(r29.u32 + 48, ctx.r8.u8);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r6,r3,-14596
	ctx.r6.s64 = ctx.r3.s64 + -14596;
	// addi r5,r11,-14960
	ctx.r5.s64 = r11.s64 + -14960;
	// lwz r3,2832(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2832);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82202c00
	ctx.lr = 0x822CEC7C;
	sub_82202C00(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r3,-10224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r10,-18544
	ctx.r5.s64 = ctx.r10.s64 + -18544;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8268b960
	ctx.lr = 0x822CEC98;
	sub_8268B960(ctx, base);
	// stw r3,100(r29)
	PPC_STORE_U32(r29.u32 + 100, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r3,-10224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r9,-18556
	ctx.r5.s64 = ctx.r9.s64 + -18556;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8268b960
	ctx.lr = 0x822CECB4;
	sub_8268B960(ctx, base);
	// stw r3,104(r29)
	PPC_STORE_U32(r29.u32 + 104, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r3,-10224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r8,-18584
	ctx.r5.s64 = ctx.r8.s64 + -18584;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8268b960
	ctx.lr = 0x822CECD0;
	sub_8268B960(ctx, base);
	// stw r3,108(r29)
	PPC_STORE_U32(r29.u32 + 108, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r3,-10224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r7,-18608
	ctx.r5.s64 = ctx.r7.s64 + -18608;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8268b960
	ctx.lr = 0x822CECEC;
	sub_8268B960(ctx, base);
	// stw r3,112(r29)
	PPC_STORE_U32(r29.u32 + 112, ctx.r3.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r3,-10224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r5,-18628
	ctx.r5.s64 = ctx.r5.s64 + -18628;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8268b960
	ctx.lr = 0x822CED08;
	sub_8268B960(ctx, base);
	// stw r3,116(r29)
	PPC_STORE_U32(r29.u32 + 116, ctx.r3.u32);
	// li r3,3168
	ctx.r3.s64 = 3168;
	// bl 0x82130528
	ctx.lr = 0x822CED14;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ced38
	if (cr6.eq) goto loc_822CED38;
	// bl 0x827407d8
	ctx.lr = 0x822CED20;
	sub_827407D8(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,-27628(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27628, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_822CED38:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,-27628(r11)
	PPC_STORE_U32(r11.u32 + -27628, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822CED4C"))) PPC_WEAK_FUNC(sub_822CED4C);
PPC_FUNC_IMPL(__imp__sub_822CED4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CED50"))) PPC_WEAK_FUNC(sub_822CED50);
PPC_FUNC_IMPL(__imp__sub_822CED50) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238da28
	ctx.lr = 0x822CED78;
	sub_8238DA28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CED8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822CEDA4"))) PPC_WEAK_FUNC(sub_822CEDA4);
PPC_FUNC_IMPL(__imp__sub_822CEDA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CEDA8"))) PPC_WEAK_FUNC(sub_822CEDA8);
PPC_FUNC_IMPL(__imp__sub_822CEDA8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238da80
	ctx.lr = 0x822CEDD0;
	sub_8238DA80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CEDE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822CEDFC"))) PPC_WEAK_FUNC(sub_822CEDFC);
PPC_FUNC_IMPL(__imp__sub_822CEDFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CEE00"))) PPC_WEAK_FUNC(sub_822CEE00);
PPC_FUNC_IMPL(__imp__sub_822CEE00) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238dae8
	ctx.lr = 0x822CEE28;
	sub_8238DAE8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CEE3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822CEE54"))) PPC_WEAK_FUNC(sub_822CEE54);
PPC_FUNC_IMPL(__imp__sub_822CEE54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CEE58"))) PPC_WEAK_FUNC(sub_822CEE58);
PPC_FUNC_IMPL(__imp__sub_822CEE58) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238db50
	ctx.lr = 0x822CEE7C;
	sub_8238DB50(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CEE90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822CEEA8"))) PPC_WEAK_FUNC(sub_822CEEA8);
PPC_FUNC_IMPL(__imp__sub_822CEEA8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822CEECC;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CEEE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822CEEF8"))) PPC_WEAK_FUNC(sub_822CEEF8);
PPC_FUNC_IMPL(__imp__sub_822CEEF8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238dc20
	ctx.lr = 0x822CEF1C;
	sub_8238DC20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CEF30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822CEF48"))) PPC_WEAK_FUNC(sub_822CEF48);
PPC_FUNC_IMPL(__imp__sub_822CEF48) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-64
	ctx.r3.s64 = ctx.r3.s64 + -64;
	// b 0x822d00a0
	sub_822D00A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CEF50"))) PPC_WEAK_FUNC(sub_822CEF50);
PPC_FUNC_IMPL(__imp__sub_822CEF50) {
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
	ctx.lr = 0x822CEF58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-18492
	ctx.r9.s64 = r11.s64 + -18492;
	// addi r8,r10,-18508
	ctx.r8.s64 = ctx.r10.s64 + -18508;
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// addi r30,r31,64
	r30.s64 = r31.s64 + 64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r8,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r8.u32);
	// beq cr6,0x822cef8c
	if (cr6.eq) goto loc_822CEF8C;
	// bl 0x82130588
	ctx.lr = 0x822CEF8C;
	sub_82130588(ctx, base);
loc_822CEF8C:
	// lwz r3,676(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 676);
	// bl 0x82130588
	ctx.lr = 0x822CEF94;
	sub_82130588(ctx, base);
	// lwz r3,672(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// bl 0x82130588
	ctx.lr = 0x822CEF9C;
	sub_82130588(ctx, base);
	// lwz r29,668(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 668);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822cefb8
	if (cr6.eq) goto loc_822CEFB8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f6d10
	ctx.lr = 0x822CEFB0;
	sub_824F6D10(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x822CEFB8;
	sub_82130588(ctx, base);
loc_822CEFB8:
	// lwz r3,1620(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1620);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cefd8
	if (cr6.eq) goto loc_822CEFD8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CEFD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CEFD8:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r5,100(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x822CEFEC;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,104(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8268b6d0
	ctx.lr = 0x822CEFFC;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x8268b6d0
	ctx.lr = 0x822CF00C;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,112(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x8268b6d0
	ctx.lr = 0x822CF01C;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,116(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x8268b6d0
	ctx.lr = 0x822CF02C;
	sub_8268B6D0(ctx, base);
	// addi r3,r31,1624
	ctx.r3.s64 = r31.s64 + 1624;
	// bl 0x822cdba0
	ctx.lr = 0x822CF034;
	sub_822CDBA0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r8,r11,-28
	ctx.r8.s64 = r11.s64 + -28;
	// addi r7,r10,68
	ctx.r7.s64 = ctx.r10.s64 + 68;
	// addi r6,r9,-21868
	ctx.r6.s64 = ctx.r9.s64 + -21868;
	// stw r8,648(r31)
	PPC_STORE_U32(r31.u32 + 648, ctx.r8.u32);
	// stw r8,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r7.u32);
	// stw r6,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r6.u32);
	// bl 0x8238e618
	ctx.lr = 0x822CF064;
	sub_8238E618(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822CF06C"))) PPC_WEAK_FUNC(sub_822CF06C);
PPC_FUNC_IMPL(__imp__sub_822CF06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CF070"))) PPC_WEAK_FUNC(sub_822CF070);
PPC_FUNC_IMPL(__imp__sub_822CF070) {
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
	ctx.lr = 0x822CF078;
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r11,19036
	ctx.r9.s64 = r11.s64 + 19036;
	// addi r8,r10,-18644
	ctx.r8.s64 = ctx.r10.s64 + -18644;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// bl 0x824f9438
	ctx.lr = 0x822CF0B0;
	sub_824F9438(ctx, base);
	// lis r5,8192
	ctx.r5.s64 = 536870912;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// std r30,180(r1)
	PPC_STORE_U64(ctx.r1.u32 + 180, r30.u64);
	// lis r4,8192
	ctx.r4.s64 = 536870912;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// ori r9,r5,30
	ctx.r9.u64 = ctx.r5.u64 | 30;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// lis r6,4096
	ctx.r6.s64 = 268435456;
	// addi r11,r7,19116
	r11.s64 = ctx.r7.s64 + 19116;
	// stw r9,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r9.u32);
	// ori r8,r4,31
	ctx.r8.u64 = ctx.r4.u64 | 31;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// ori r10,r6,27
	ctx.r10.u64 = ctx.r6.u64 | 27;
	// stw r8,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r8.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stw r3,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// stw r10,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r10.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r7,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r7.u32);
	// cmplwi cr6,r31,351
	cr6.compare<uint32_t>(r31.u32, 351, xer);
	// lbz r5,688(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 688);
	// ori r4,r5,128
	ctx.r4.u64 = ctx.r5.u64 | 128;
	// stb r4,688(r1)
	PPC_STORE_U8(ctx.r1.u32 + 688, ctx.r4.u8);
	// blt cr6,0x822cf118
	if (cr6.lt) goto loc_822CF118;
	// addi r11,r31,31
	r11.s64 = r31.s64 + 31;
loc_822CF118:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// bl 0x82388580
	ctx.lr = 0x822CF13C;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822CF14C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x822CF154;
	sub_824E7110(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822CF160;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822CF178;
	sub_82270170(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82272df8
	ctx.lr = 0x822CF18C;
	sub_82272DF8(ctx, base);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// bne cr6,0x822cf1cc
	if (!cr6.eq) goto loc_822CF1CC;
loc_822CF198:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822CF1A0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822CF1B0;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x822CF1B4;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x822CF1B8;
	sub_82130000(ctx, base);
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x821c91b8
	ctx.lr = 0x822CF1C0;
	sub_821C91B8(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x822cf198
	if (cr6.eq) goto loc_822CF198;
loc_822CF1CC:
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cf1dc
	if (cr6.eq) goto loc_822CF1DC;
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_822CF1DC:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822cf1f8
	if (!cr6.gt) goto loc_822CF1F8;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// ld r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U64(r11.u32 + 24);
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d9244
	return;
loc_822CF1F8:
	// lis r3,32767
	ctx.r3.s64 = 2147418112;
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822CF208"))) PPC_WEAK_FUNC(sub_822CF208);
PPC_FUNC_IMPL(__imp__sub_822CF208) {
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
	ctx.lr = 0x822CF210;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x82388580
	ctx.lr = 0x822CF228;
	sub_82388580(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822CF238;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x822CF240;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cf3cc
	if (cr6.eq) goto loc_822CF3CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822CF254;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822CF264;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x822CF26C;
	sub_824E70F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cf3cc
	if (cr6.eq) goto loc_822CF3CC;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x822CF284;
	sub_8238EC00(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cf3cc
	if (cr6.eq) goto loc_822CF3CC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r9,44(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lhz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// extsh r30,r7
	r30.s64 = ctx.r7.s16;
	// addi r3,r11,24
	ctx.r3.s64 = r11.s64 + 24;
	// bl 0x824e6a18
	ctx.lr = 0x822CF2C4;
	sub_824E6A18(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x822cf308
	if (!cr6.eq) goto loc_822CF308;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r10,-10240(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lis r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-18404
	ctx.r4.s64 = ctx.r9.s64 + -18404;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// addi r3,r11,24
	ctx.r3.s64 = r11.s64 + 24;
	// lwz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CF308;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CF308:
	// rlwinm r11,r27,1,0,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r3,52(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// bl 0x8238f6b0
	ctx.lr = 0x822CF324;
	sub_8238F6B0(ctx, base);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,800(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 800);
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// beq cr6,0x822cf368
	if (cr6.eq) goto loc_822CF368;
	// stw r30,800(r10)
	PPC_STORE_U32(ctx.r10.u32 + 800, r30.u32);
	// addi r10,r30,10
	ctx.r10.s64 = r30.s64 + 10;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r10,r28
	ctx.r3.u64 = ctx.r10.u64 + r28.u64;
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r27,8(r9)
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x822cf070
	ctx.lr = 0x822CF360;
	sub_822CF070(ctx, base);
	// stw r3,804(r27)
	PPC_STORE_U32(r27.u32 + 804, ctx.r3.u32);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
loc_822CF368:
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,804(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 804);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x822cf3cc
	if (!cr6.lt) goto loc_822CF3CC;
	// stw r11,804(r10)
	PPC_STORE_U32(ctx.r10.u32 + 804, r11.u32);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r3,r11,24
	ctx.r3.s64 = r11.s64 + 24;
	// bl 0x824e6a38
	ctx.lr = 0x822CF398;
	sub_824E6A38(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822cf3cc
	if (!cr6.eq) goto loc_822CF3CC;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// addi r10,r30,10
	ctx.r10.s64 = r30.s64 + 10;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r5,40(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r28
	ctx.r6.u64 = ctx.r10.u64 + r28.u64;
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r3,r11,24
	ctx.r3.s64 = r11.s64 + 24;
	// bl 0x8229d2e0
	ctx.lr = 0x822CF3CC;
	sub_8229D2E0(ctx, base);
loc_822CF3CC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822CF3D4"))) PPC_WEAK_FUNC(sub_822CF3D4);
PPC_FUNC_IMPL(__imp__sub_822CF3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CF3D8"))) PPC_WEAK_FUNC(sub_822CF3D8);
PPC_FUNC_IMPL(__imp__sub_822CF3D8) {
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
	ctx.lr = 0x822CF3E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x82388580
	ctx.lr = 0x822CF3FC;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822CF40C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x822CF414;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cf53c
	if (cr6.eq) goto loc_822CF53C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822CF428;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822CF438;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x822CF440;
	sub_824E70F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cf53c
	if (cr6.eq) goto loc_822CF53C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r3,r11,24
	ctx.r3.s64 = r11.s64 + 24;
	// bl 0x824e6a18
	ctx.lr = 0x822CF464;
	sub_824E6A18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822cf4a8
	if (!cr6.eq) goto loc_822CF4A8;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r10,-10240(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lis r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-18404
	ctx.r4.s64 = ctx.r9.s64 + -18404;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// addi r3,r11,24
	ctx.r3.s64 = r11.s64 + 24;
	// lwz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CF4A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822CF4A8:
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r30,8(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,800(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 800);
	// cmpw cr6,r9,r28
	cr6.compare<int32_t>(ctx.r9.s32, r28.s32, xer);
	// beq cr6,0x822cf4d0
	if (cr6.eq) goto loc_822CF4D0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822cf070
	ctx.lr = 0x822CF4C8;
	sub_822CF070(ctx, base);
	// stw r3,804(r30)
	PPC_STORE_U32(r30.u32 + 804, ctx.r3.u32);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
loc_822CF4D0:
	// rlwinm r10,r29,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// add r8,r29,r10
	ctx.r8.u64 = r29.u64 + ctx.r10.u64;
	// rlwinm r11,r8,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r30,r11,r27
	r30.u64 = r11.u64 + r27.u64;
	// lwz r7,804(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 804);
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// bge cr6,0x822cf53c
	if (!cr6.lt) goto loc_822CF53C;
	// stw r11,804(r10)
	PPC_STORE_U32(ctx.r10.u32 + 804, r11.u32);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r3,r11,24
	ctx.r3.s64 = r11.s64 + 24;
	// bl 0x824e6a38
	ctx.lr = 0x822CF510;
	sub_824E6A38(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822cf53c
	if (!cr6.eq) goto loc_822CF53C;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r5,40(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r3,r11,24
	ctx.r3.s64 = r11.s64 + 24;
	// bl 0x8229d2e0
	ctx.lr = 0x822CF53C;
	sub_8229D2E0(ctx, base);
loc_822CF53C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822CF544"))) PPC_WEAK_FUNC(sub_822CF544);
PPC_FUNC_IMPL(__imp__sub_822CF544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CF548"))) PPC_WEAK_FUNC(sub_822CF548);
PPC_FUNC_IMPL(__imp__sub_822CF548) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CF580;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822CF59C"))) PPC_WEAK_FUNC(sub_822CF59C);
PPC_FUNC_IMPL(__imp__sub_822CF59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CF5A0"))) PPC_WEAK_FUNC(sub_822CF5A0);
PPC_FUNC_IMPL(__imp__sub_822CF5A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CF5D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822CF5F4"))) PPC_WEAK_FUNC(sub_822CF5F4);
PPC_FUNC_IMPL(__imp__sub_822CF5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CF5F8"))) PPC_WEAK_FUNC(sub_822CF5F8);
PPC_FUNC_IMPL(__imp__sub_822CF5F8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8238d970
	ctx.lr = 0x822CF620;
	sub_8238D970(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-12440(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CF63C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_822CF65C"))) PPC_WEAK_FUNC(sub_822CF65C);
PPC_FUNC_IMPL(__imp__sub_822CF65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CF660"))) PPC_WEAK_FUNC(sub_822CF660);
PPC_FUNC_IMPL(__imp__sub_822CF660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822cdb08
	sub_822CDB08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CF678"))) PPC_WEAK_FUNC(sub_822CF678);
PPC_FUNC_IMPL(__imp__sub_822CF678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lfs f1,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// clrlwi r5,r9,16
	ctx.r5.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822CF6BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-18724
	ctx.r4.s64 = ctx.r4.s64 + -18724;
	// lwz r3,-10224(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x822CF6D4;
	sub_8268B770(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822CF6E8"))) PPC_WEAK_FUNC(sub_822CF6E8);
PPC_FUNC_IMPL(__imp__sub_822CF6E8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x822CF6F0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r28,r11,-18192
	r28.s64 = r11.s64 + -18192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CF720;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r27,r11,-18200
	r27.s64 = r11.s64 + -18200;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822CF748;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// addi r26,r11,-18208
	r26.s64 = r11.s64 + -18208;
	// ble cr6,0x822cf7b8
	if (!cr6.gt) goto loc_822CF7B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CF778;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r29
	ctx.r9.s64 = r29.s32;
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// lfs f0,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	f0.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fdivs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// stfs f6,8(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// b 0x822cf7c4
	goto loc_822CF7C4;
loc_822CF7B8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
loc_822CF7C4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18216
	ctx.r4.s64 = ctx.r10.s64 + -18216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CF7E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r24,0
	r24.s64 = 0;
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// stw r24,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r24.u32);
	// bl 0x82387b90
	ctx.lr = 0x822CF7F4;
	sub_82387B90(ctx, base);
	// lwz r8,1340(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x822cf848
	if (!cr6.gt) goto loc_822CF848;
	// bl 0x82387b90
	ctx.lr = 0x822CF804;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822cf848
	if (cr6.lt) goto loc_822CF848;
	// bl 0x82387b90
	ctx.lr = 0x822CF814;
	sub_82387B90(ctx, base);
	// lwz r29,1344(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// bl 0x82387b90
	ctx.lr = 0x822CF81C;
	sub_82387B90(ctx, base);
	// lwz r11,1340(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x822cf848
	if (!cr6.lt) goto loc_822CF848;
	// bl 0x82387b90
	ctx.lr = 0x822CF82C;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// mulli r11,r11,8176
	r11.s64 = r11.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238f998
	ctx.lr = 0x822CF840;
	sub_8238F998(ctx, base);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r10.u32);
loc_822CF848:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,22968
	ctx.r4.s64 = ctx.r10.s64 + 22968;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CF868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 20, temp.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,23008
	ctx.r4.s64 = ctx.r7.s64 + 23008;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,80(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822CF88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 24, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18224
	ctx.r4.s64 = ctx.r10.s64 + -18224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CF8B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-18232
	ctx.r4.s64 = ctx.r7.s64 + -18232;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,76(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822CF8D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r3.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18240
	ctx.r4.s64 = ctx.r10.s64 + -18240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CF8F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,36(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 36, temp.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r7,-18936
	r29.s64 = ctx.r7.s64 + -18936;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,80(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822CF920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,40(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 40, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r25,r10,-18248
	r25.s64 = ctx.r10.s64 + -18248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CF948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,44(r30)
	PPC_STORE_U32(r30.u32 + 44, ctx.r3.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822CF968;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,176(r30)
	PPC_STORE_U32(r30.u32 + 176, ctx.r3.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,-18256
	ctx.r4.s64 = ctx.r4.s64 + -18256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,76(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CF98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,264(r30)
	PPC_STORE_U32(r30.u32 + 264, ctx.r3.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,22976
	ctx.r4.s64 = ctx.r10.s64 + 22976;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CF9B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,184(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 184, temp.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,22992
	ctx.r4.s64 = ctx.r6.s64 + 22992;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,80(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CF9D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,188(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 188, temp.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-18264
	ctx.r4.s64 = ctx.r9.s64 + -18264;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,76(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CF9F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,192(r30)
	PPC_STORE_U32(r30.u32 + 192, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-18272
	ctx.r4.s64 = ctx.r6.s64 + -18272;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,76(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CFA1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,196(r30)
	PPC_STORE_U32(r30.u32 + 196, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-18280
	ctx.r4.s64 = ctx.r9.s64 + -18280;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,76(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CFA40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,200(r30)
	PPC_STORE_U32(r30.u32 + 200, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-18288
	ctx.r4.s64 = ctx.r6.s64 + -18288;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,76(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CFA64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,204(r30)
	PPC_STORE_U32(r30.u32 + 204, ctx.r3.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18296
	ctx.r4.s64 = ctx.r10.s64 + -18296;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CFA88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,208(r30)
	PPC_STORE_U32(r30.u32 + 208, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-18304
	ctx.r4.s64 = ctx.r6.s64 + -18304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,76(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CFAAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,212(r30)
	PPC_STORE_U32(r30.u32 + 212, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-18788
	ctx.r4.s64 = ctx.r9.s64 + -18788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,80(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CFAD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,216(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 216, temp.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-18892
	ctx.r4.s64 = ctx.r6.s64 + -18892;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,80(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CFAF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,220(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 220, temp.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CFB14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,224(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 224, temp.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-18956
	ctx.r4.s64 = ctx.r7.s64 + -18956;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,80(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822CFB38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,228(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 228, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18312
	ctx.r4.s64 = ctx.r10.s64 + -18312;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CFB5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,232(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 232, temp.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-18320
	ctx.r4.s64 = ctx.r7.s64 + -18320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,76(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822CFB80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,236(r30)
	PPC_STORE_U32(r30.u32 + 236, ctx.r3.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CFBA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,240(r30)
	PPC_STORE_U32(r30.u32 + 240, ctx.r3.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-18804
	ctx.r4.s64 = ctx.r8.s64 + -18804;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,76(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822CFBC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,244(r30)
	PPC_STORE_U32(r30.u32 + 244, ctx.r3.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,76(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CFBE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,248(r30)
	PPC_STORE_U32(r30.u32 + 248, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18328
	ctx.r4.s64 = ctx.r10.s64 + -18328;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CFC08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,252(r30)
	PPC_STORE_U32(r30.u32 + 252, ctx.r3.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r11,76(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// addi r4,r6,-18860
	ctx.r4.s64 = ctx.r6.s64 + -18860;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CFC2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,256(r30)
	PPC_STORE_U32(r30.u32 + 256, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-18336
	ctx.r4.s64 = ctx.r9.s64 + -18336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,76(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822CFC50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,260(r30)
	PPC_STORE_U32(r30.u32 + 260, ctx.r3.u32);
	// stw r24,180(r30)
	PPC_STORE_U32(r30.u32 + 180, r24.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-18344
	ctx.r4.s64 = ctx.r7.s64 + -18344;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,76(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822CFC78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,268(r30)
	PPC_STORE_U32(r30.u32 + 268, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CFC98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,272(r30)
	PPC_STORE_U32(r30.u32 + 272, ctx.r3.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-9144
	ctx.r4.s64 = ctx.r7.s64 + -9144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,76(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822CFCBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r3,276(r30)
	PPC_STORE_U32(r30.u32 + 276, ctx.r3.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// sth r24,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r24.u16);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// sth r5,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, ctx.r5.u16);
	// bl 0x822cd5b0
	ctx.lr = 0x822CFCD8;
	sub_822CD5B0(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r11,r4,-19140
	r11.s64 = ctx.r4.s64 + -19140;
	// addi r4,r3,-18352
	ctx.r4.s64 = ctx.r3.s64 + -18352;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,108
	ctx.r3.s64 = ctx.r1.s64 + 108;
	// bl 0x8238d970
	ctx.lr = 0x822CFCFC;
	sub_8238D970(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238e470
	ctx.lr = 0x822CFD0C;
	sub_8238E470(ctx, base);
	// lhz r11,100(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// stw r24,280(r30)
	PPC_STORE_U32(r30.u32 + 280, r24.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822cfd40
	if (!cr6.gt) goto loc_822CFD40;
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
loc_822CFD24:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r8,280(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r9,280(r30)
	PPC_STORE_U32(r30.u32 + 280, ctx.r9.u32);
	// bne 0x822cfd24
	if (!cr0.eq) goto loc_822CFD24;
loc_822CFD40:
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
	ctx.lr = 0x822CFD60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,284(r30)
	PPC_STORE_U32(r30.u32 + 284, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-18876
	ctx.r4.s64 = ctx.r7.s64 + -18876;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,76(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822CFD84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,288(r30)
	PPC_STORE_U32(r30.u32 + 288, ctx.r3.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18360
	ctx.r4.s64 = ctx.r10.s64 + -18360;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CFDA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,292(r30)
	PPC_STORE_U32(r30.u32 + 292, ctx.r3.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-18368
	ctx.r4.s64 = ctx.r7.s64 + -18368;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,76(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822CFDCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,296(r30)
	PPC_STORE_U32(r30.u32 + 296, ctx.r3.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-18376
	ctx.r4.s64 = ctx.r10.s64 + -18376;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822CFDF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,300(r30)
	PPC_STORE_U32(r30.u32 + 300, ctx.r3.u32);
	// mr r29,r24
	r29.u64 = r24.u64;
	// addi r26,r11,-12120
	r26.s64 = r11.s64 + -12120;
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cfe60
	if (cr6.eq) goto loc_822CFE60;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r28,r30,304
	r28.s64 = r30.s64 + 304;
	// addi r27,r10,23016
	r27.s64 = ctx.r10.s64 + 23016;
loc_822CFE18:
	// cmpwi cr6,r29,100
	cr6.compare<int32_t>(r29.s32, 100, xer);
	// bge cr6,0x822cfe90
	if (!cr6.lt) goto loc_822CFE90;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CFE3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x822cfe18
	if (cr6.lt) goto loc_822CFE18;
	// cmpwi cr6,r29,100
	cr6.compare<int32_t>(r29.s32, 100, xer);
	// bge cr6,0x822cfe90
	if (!cr6.lt) goto loc_822CFE90;
loc_822CFE60:
	// addi r10,r29,76
	ctx.r10.s64 = r29.s64 + 76;
	// subfic r9,r29,100
	xer.ca = r29.u32 <= 100;
	ctx.r9.s64 = 100 - r29.s64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822cfe90
	if (cr6.eq) goto loc_822CFE90;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822CFE80:
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822cfe80
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822CFE80;
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
loc_822CFE90:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// mr r29,r24
	r29.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822cff14
	if (cr6.eq) goto loc_822CFF14;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r28,r30,704
	r28.s64 = r30.s64 + 704;
	// ori r27,r10,65535
	r27.u64 = ctx.r10.u64 | 65535;
	// addi r25,r11,-18384
	r25.s64 = r11.s64 + -18384;
loc_822CFEB4:
	// cmpwi cr6,r29,100
	cr6.compare<int32_t>(r29.s32, 100, xer);
	// bge cr6,0x822cff40
	if (!cr6.lt) goto loc_822CFF40;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CFED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x822cfee8
	if (!cr6.lt) goto loc_822CFEE8;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// b 0x822cfef4
	goto loc_822CFEF4;
loc_822CFEE8:
	// cmpw cr6,r3,r27
	cr6.compare<int32_t>(ctx.r3.s32, r27.s32, xer);
	// ble cr6,0x822cfef4
	if (!cr6.gt) goto loc_822CFEF4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_822CFEF4:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// sth r3,0(r28)
	PPC_STORE_U16(r28.u32 + 0, ctx.r3.u16);
	// lhz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x822cfeb4
	if (cr6.lt) goto loc_822CFEB4;
	// cmpwi cr6,r29,100
	cr6.compare<int32_t>(r29.s32, 100, xer);
	// bge cr6,0x822cff40
	if (!cr6.lt) goto loc_822CFF40;
loc_822CFF14:
	// addi r11,r29,352
	r11.s64 = r29.s64 + 352;
	// subfic r10,r29,100
	xer.ca = r29.u32 <= 100;
	ctx.r10.s64 = 100 - r29.s64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822cff40
	if (cr6.eq) goto loc_822CFF40;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822CFF34:
	// sth r9,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r9.u16);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bdnz 0x822cff34
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822CFF34;
loc_822CFF40:
	// addi r30,r30,48
	r30.s64 = r30.s64 + 48;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x822CFF54;
	sub_823D9890(ctx, base);
	// lis r31,3
	r31.s64 = 196608;
	// lis r11,3
	r11.s64 = 196608;
	// ori r31,r31,57288
	r31.u64 = r31.u64 | 57288;
	// li r29,-1
	r29.s64 = -1;
	// ori r27,r11,57416
	r27.u64 = r11.u64 | 57416;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_822CFF6C:
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// bl 0x82387b90
	ctx.lr = 0x822CFF78;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lwz r3,-12216(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12216);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwzx r4,r31,r11
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x821ef020
	ctx.lr = 0x822CFF90;
	sub_821EF020(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x822cffb8
	if (cr6.eq) goto loc_822CFFB8;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822cffb8
	if (cr6.eq) goto loc_822CFFB8;
	// bl 0x82387b90
	ctx.lr = 0x822CFFAC;
	sub_82387B90(ctx, base);
	// lwzx r11,r31,r3
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
loc_822CFFB8:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// blt cr6,0x822cff6c
	if (cr6.lt) goto loc_822CFF6C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lhz r8,102(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// addi r9,r10,-19152
	ctx.r9.s64 = ctx.r10.s64 + -19152;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// beq cr6,0x822cffe4
	if (cr6.eq) goto loc_822CFFE4;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82130588
	ctx.lr = 0x822CFFE4;
	sub_82130588(ctx, base);
loc_822CFFE4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822CFFEC"))) PPC_WEAK_FUNC(sub_822CFFEC);
PPC_FUNC_IMPL(__imp__sub_822CFFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CFFF0"))) PPC_WEAK_FUNC(sub_822CFFF0);
PPC_FUNC_IMPL(__imp__sub_822CFFF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// subf r9,r5,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r5.s64;
	// srawi. r10,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x822d0038
	if (!cr0.gt) goto loc_822D0038;
	// subf r9,r4,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r4.s64;
loc_822D0008:
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stw r5,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r5.u32);
	// lwz r8,12(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bgt 0x822d0008
	if (cr0.gt) goto loc_822D0008;
loc_822D0038:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D0044"))) PPC_WEAK_FUNC(sub_822D0044);
PPC_FUNC_IMPL(__imp__sub_822D0044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D0048"))) PPC_WEAK_FUNC(sub_822D0048);
PPC_FUNC_IMPL(__imp__sub_822D0048) {
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
	// li r3,1636
	ctx.r3.s64 = 1636;
	// bl 0x82130528
	ctx.lr = 0x822D005C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d0080
	if (cr6.eq) goto loc_822D0080;
	// bl 0x822ce1b8
	ctx.lr = 0x822D0068;
	sub_822CE1B8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,-12440(r11)
	PPC_STORE_U32(r11.u32 + -12440, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822D0080:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12440(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12440, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D009C"))) PPC_WEAK_FUNC(sub_822D009C);
PPC_FUNC_IMPL(__imp__sub_822D009C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D00A0"))) PPC_WEAK_FUNC(sub_822D00A0);
PPC_FUNC_IMPL(__imp__sub_822D00A0) {
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
	// bl 0x822cef50
	ctx.lr = 0x822D00C0;
	sub_822CEF50(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d00d8
	if (cr6.eq) goto loc_822D00D8;
	// bl 0x82130588
	ctx.lr = 0x822D00D4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D00D8:
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

__attribute__((alias("__imp__sub_822D00F0"))) PPC_WEAK_FUNC(sub_822D00F0);
PPC_FUNC_IMPL(__imp__sub_822D00F0) {
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
	ctx.lr = 0x822D00F8;
	// stwu r1,-1072(r1)
	ea = -1072 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82387b90
	ctx.lr = 0x822D010C;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r10,-18128
	ctx.r4.s64 = ctx.r10.s64 + -18128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,1192(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 1192);
	// bl 0x8238dbb0
	ctx.lr = 0x822D012C;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,40(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D0140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387b90
	ctx.lr = 0x822D0144;
	sub_82387B90(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r7,-18136
	ctx.r4.s64 = ctx.r7.s64 + -18136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,1208(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 1208);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0164;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,40(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822D0178;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387b90
	ctx.lr = 0x822D017C;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r10,-18144
	ctx.r4.s64 = ctx.r10.s64 + -18144;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,1320(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 1320);
	// bl 0x8238dbb0
	ctx.lr = 0x822D019C;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,40(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D01B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r27,-32129
	r27.s64 = -2105606144;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r7,r27,-28304
	ctx.r7.s64 = r27.s64 + -28304;
	// addi r4,r8,-18152
	ctx.r4.s64 = ctx.r8.s64 + -18152;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dc20
	ctx.lr = 0x822D01D4;
	sub_8238DC20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,40(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822D01E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r6,-28304(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -28304);
	// addi r4,r4,-18160
	ctx.r4.s64 = ctx.r4.s64 + -18160;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dc20
	ctx.lr = 0x822D0204;
	sub_8238DC20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D0218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-18168
	ctx.r4.s64 = ctx.r10.s64 + -18168;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0234;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,40(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D0248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x822D0250;
	sub_822A4AE0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d026c
	if (cr6.eq) goto loc_822D026C;
	// bl 0x82387b90
	ctx.lr = 0x822D0260;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// b 0x822d0278
	goto loc_822D0278;
loc_822D026C:
	// bl 0x82387b90
	ctx.lr = 0x822D0270;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
loc_822D0278:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r10,-18176
	ctx.r4.s64 = ctx.r10.s64 + -18176;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238dbb0
	ctx.lr = 0x822D0294;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D02A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82457a30
	ctx.lr = 0x822D02B0;
	sub_82457A30(ctx, base);
	// lhz r11,98(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 98);
	// lhz r7,102(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// rotlwi r8,r11,8
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 8);
	// lhz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 96);
	// lhz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// or r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 | ctx.r7.u64;
	// addic. r11,r5,-2000
	xer.ca = ctx.r5.u32 > 1999;
	r11.s64 = ctx.r5.s64 + -2000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 | ctx.r3.u64;
	// bge 0x822d02dc
	if (!cr0.lt) goto loc_822D02DC;
	// li r11,0
	r11.s64 = 0;
loc_822D02DC:
	// rlwinm r11,r11,24,1,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0x7F000000;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// or r6,r11,r10
	ctx.r6.u64 = r11.u64 | ctx.r10.u64;
	// addi r4,r9,-18184
	ctx.r4.s64 = ctx.r9.s64 + -18184;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238dbb0
	ctx.lr = 0x822D02FC;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D0310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822cd490
	ctx.lr = 0x822D0318;
	sub_822CD490(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822cf6e8
	ctx.lr = 0x822D0324;
	sub_822CF6E8(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,904
	ctx.r5.s64 = 904;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x822D0334;
	sub_823DA950(ctx, base);
	// lwz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r11,r30,904
	r11.s64 = r30.s64 + 904;
	// addi r10,r31,52
	ctx.r10.s64 = r31.s64 + 52;
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// addi r28,r28,-908
	r28.s64 = r28.s64 + -908;
	// srawi r4,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 4;
	// li r27,908
	r27.s64 = 908;
	// stw r4,904(r30)
	PPC_STORE_U32(r30.u32 + 904, ctx.r4.u32);
	// addi r29,r11,4
	r29.s64 = r11.s64 + 4;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r30,52(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// beq cr6,0x822d0398
	if (cr6.eq) goto loc_822D0398;
loc_822D036C:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238d6a0
	ctx.lr = 0x822D037C;
	sub_8238D6A0(ctx, base);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
	// subf r28,r3,r28
	r28.s64 = r28.s64 - ctx.r3.s64;
	// add r27,r3,r27
	r27.u64 = ctx.r3.u64 + r27.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x822d036c
	if (!cr6.eq) goto loc_822D036C;
loc_822D0398:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,1072
	ctx.r1.s64 = ctx.r1.s64 + 1072;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D03A4"))) PPC_WEAK_FUNC(sub_822D03A4);
PPC_FUNC_IMPL(__imp__sub_822D03A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D03A8"))) PPC_WEAK_FUNC(sub_822D03A8);
PPC_FUNC_IMPL(__imp__sub_822D03A8) {
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
	// bl 0x822d00f0
	ctx.lr = 0x822D03C8;
	sub_822D00F0(ctx, base);
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,56(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// add r3,r30,r31
	ctx.r3.u64 = r30.u64 + r31.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x822d03fc
	if (cr6.eq) goto loc_822D03FC;
loc_822D03E4:
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x822d03e4
	if (!cr6.eq) goto loc_822D03E4;
	// cmpwi cr6,r10,1000
	cr6.compare<int32_t>(ctx.r10.s32, 1000, xer);
	// bge cr6,0x822d0418
	if (!cr6.lt) goto loc_822D0418;
loc_822D03FC:
	// subfic r31,r10,1000
	xer.ca = ctx.r10.u32 <= 1000;
	r31.s64 = 1000 - ctx.r10.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r5,r31,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x823d9890
	ctx.lr = 0x822D040C;
	sub_823D9890(ctx, base);
	// rlwinm r11,r31,4,0,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// b 0x822d041c
	goto loc_822D041C;
loc_822D0418:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822D041C:
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

__attribute__((alias("__imp__sub_822D0434"))) PPC_WEAK_FUNC(sub_822D0434);
PPC_FUNC_IMPL(__imp__sub_822D0434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D0438"))) PPC_WEAK_FUNC(sub_822D0438);
PPC_FUNC_IMPL(__imp__sub_822D0438) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x822D0440;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r11,0
	r11.s64 = 0;
	// lwz r10,40(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// lwz r9,36(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// subf r8,r10,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r10.s64;
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r10,r7,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// beq cr6,0x822d0490
	if (cr6.eq) goto loc_822D0490;
	// lwz r9,44(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x822d0490
	if (cr6.eq) goto loc_822D0490;
	// lwz r9,48(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x822d0490
	if (cr6.eq) goto loc_822D0490;
	// lwz r9,52(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// bne cr6,0x822d0494
	if (!cr6.eq) goto loc_822D0494;
loc_822D0490:
	// li r11,1
	r11.s64 = 1;
loc_822D0494:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r18,0
	r18.s64 = 0;
	// li r17,0
	r17.s64 = 0;
	// li r19,0
	r19.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d0ff0
	if (cr6.eq) goto loc_822D0FF0;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x822d1060
	if (cr6.eq) goto loc_822D1060;
	// bl 0x82256058
	ctx.lr = 0x822D04B8;
	sub_82256058(ctx, base);
	// lwz r11,3140(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 3140);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d1060
	if (!cr6.eq) goto loc_822D1060;
	// lbz r11,3774(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3774);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d1060
	if (!cr6.eq) goto loc_822D1060;
	// lwz r9,3080(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 3080);
	// li r22,-1
	r22.s64 = -1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822d0504
	if (!cr6.gt) goto loc_822D0504;
	// addi r10,r24,16
	ctx.r10.s64 = r24.s64 + 16;
loc_822D04E4:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x822d04f4
	if (!cr6.eq) goto loc_822D04F4;
	// mr r22,r11
	r22.u64 = r11.u64;
loc_822D04F4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,192
	ctx.r10.s64 = ctx.r10.s64 + 192;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822d04e4
	if (cr6.lt) goto loc_822D04E4;
loc_822D0504:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x822D0510;
	sub_8238EC00(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x822d1060
	if (cr6.eq) goto loc_822D1060;
	// lis r28,-32115
	r28.s64 = -2104688640;
	// lwz r30,0(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-18200
	ctx.r4.s64 = r11.s64 + -18200;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D0548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r27,r8,-18876
	r27.s64 = ctx.r8.s64 + -18876;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,48(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D0570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-19036
	ctx.r4.s64 = ctx.r10.s64 + -19036;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D0594;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-18032
	ctx.r4.s64 = ctx.r7.s64 + -18032;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,76(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D05B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-12440(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D05D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d063c
	if (cr6.eq) goto loc_822D063C;
	// divw r9,r31,r11
	ctx.r9.s32 = r31.s32 / r11.s32;
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// rotlwi r10,r31,1
	ctx.r10.u64 = __builtin_rotateleft32(r31.u32, 1);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// twllei r11,0
	// lfs f0,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	f0.f64 = double(temp.f32);
	// andc r11,r11,r5
	r11.u64 = r11.u64 & ~ctx.r5.u64;
	// lwz r10,52(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// twlgei r11,-1
	// addi r4,r4,-18240
	ctx.r4.s64 = ctx.r4.s64 + -18240;
	// li r5,2
	ctx.r5.s64 = 2;
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D063C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D063C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r31,r29,-64
	r31.s64 = r29.s64 + -64;
	// addi r29,r11,-18040
	r29.s64 = r11.s64 + -18040;
	// clrlwi r27,r30,16
	r27.u64 = r30.u32 & 0xFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r26,0(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238d970
	ctx.lr = 0x822D0660;
	sub_8238D970(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,84(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D0674;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r11,r22,1,0,30
	r11.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// add r10,r22,r11
	ctx.r10.u64 = r22.u64 + r11.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r25,r11,r24
	r25.u64 = r11.u64 + r24.u64;
	// lwz r9,8(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// lwz r23,76(r8)
	r23.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// blt cr6,0x822d0738
	if (cr6.lt) goto loc_822D0738;
	// lwz r11,40(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822d0738
	if (cr6.eq) goto loc_822D0738;
	// lwz r3,3160(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 3160);
	// bl 0x82397458
	ctx.lr = 0x822D06B0;
	sub_82397458(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d0738
	if (!cr6.eq) goto loc_822D0738;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r7,40(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238da80
	ctx.lr = 0x822D06D8;
	sub_8238DA80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D06EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d0738
	if (cr6.eq) goto loc_822D0738;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d0738
	if (cr6.eq) goto loc_822D0738;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r6,r7,-18056
	ctx.r6.s64 = ctx.r7.s64 + -18056;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
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
	ctx.lr = 0x822D0738;
	sub_82234A10(ctx, base);
loc_822D0738:
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// lwz r21,48(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x822d0758
	if (cr6.eq) goto loc_822D0758;
	// lwz r3,132(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 132);
	// bl 0x8238f998
	ctx.lr = 0x822D0750;
	sub_8238F998(ctx, base);
	// lwz r29,24(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// b 0x822d075c
	goto loc_822D075C;
loc_822D0758:
	// li r29,-1
	r29.s64 = -1;
loc_822D075C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// addi r26,r11,-18328
	r26.s64 = r11.s64 + -18328;
	// beq cr6,0x822d0970
	if (cr6.eq) goto loc_822D0970;
	// lwz r11,172(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 172);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822d0970
	if (!cr6.eq) goto loc_822D0970;
	// lwz r11,3096(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 3096);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x822d0970
	if (cr6.eq) goto loc_822D0970;
	// cmplwi cr6,r29,7
	cr6.compare<uint32_t>(r29.u32, 7, xer);
	// bgt cr6,0x822d0970
	if (cr6.gt) goto loc_822D0970;
	// lis r12,-32211
	r12.s64 = -2110980096;
	// addi r12,r12,1956
	r12.s64 = r12.s64 + 1956;
	// rlwinm r0,r29,2,0,29
	r0.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r29.u64) {
	case 0:
		goto loc_822D07C4;
	case 1:
		goto loc_822D07E0;
	case 2:
		goto loc_822D07FC;
	case 3:
		goto loc_822D0818;
	case 4:
		goto loc_822D0848;
	case 5:
		goto loc_822D0970;
	case 6:
		goto loc_822D08D8;
	case 7:
		goto loc_822D0864;
	default:
		__builtin_unreachable();
	}
	// lwz r17,1988(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 1988);
	// lwz r17,2016(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 2016);
	// lwz r17,2044(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 2044);
	// lwz r17,2072(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 2072);
	// lwz r17,2120(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 2120);
	// lwz r17,2416(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 2416);
	// lwz r17,2264(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 2264);
	// lwz r17,2148(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 2148);
loc_822D07C4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r11,-18064
	ctx.r3.s64 = r11.s64 + -18064;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822cdb08
	ctx.lr = 0x822D07DC;
	sub_822CDB08(ctx, base);
	// b 0x822d0970
	goto loc_822D0970;
loc_822D07E0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r11,-18072
	ctx.r3.s64 = r11.s64 + -18072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822cdb08
	ctx.lr = 0x822D07F8;
	sub_822CDB08(ctx, base);
	// b 0x822d0970
	goto loc_822D0970;
loc_822D07FC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r11,-18080
	ctx.r3.s64 = r11.s64 + -18080;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822cdb08
	ctx.lr = 0x822D0814;
	sub_822CDB08(ctx, base);
	// b 0x822d0970
	goto loc_822D0970;
loc_822D0818:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r11,-18972
	ctx.r3.s64 = r11.s64 + -18972;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822cdb08
	ctx.lr = 0x822D0830;
	sub_822CDB08(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822cdb08
	ctx.lr = 0x822D0844;
	sub_822CDB08(ctx, base);
	// b 0x822d0970
	goto loc_822D0970;
loc_822D0848:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r11,-18088
	ctx.r3.s64 = r11.s64 + -18088;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822cdb08
	ctx.lr = 0x822D0860;
	sub_822CDB08(ctx, base);
	// b 0x822d0970
	goto loc_822D0970;
loc_822D0864:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r30,r11,-19124
	r30.s64 = r11.s64 + -19124;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822cdb08
	ctx.lr = 0x822D0880;
	sub_822CDB08(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D089C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// blt cr6,0x822d0970
	if (cr6.lt) goto loc_822D0970;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,-19132
	r30.s64 = r11.s64 + -19132;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D08C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822d0970
	if (cr6.eq) goto loc_822D0970;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// b 0x822d0948
	goto loc_822D0948;
loc_822D08D8:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r30,r11,-19108
	r30.s64 = r11.s64 + -19108;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822cdb08
	ctx.lr = 0x822D08F4;
	sub_822CDB08(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D0910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// blt cr6,0x822d0970
	if (cr6.lt) goto loc_822D0970;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,-19116
	r30.s64 = r11.s64 + -19116;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D093C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822d0970
	if (cr6.eq) goto loc_822D0970;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
loc_822D0948:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8238dbb0
	ctx.lr = 0x822D095C;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D0970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D0970:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r9,796(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 796);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d0c1c
	if (cr6.eq) goto loc_822D0C1C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,27786
	ctx.r9.u64 = ctx.r10.u64 | 27786;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822d09ec
	if (!cr6.eq) goto loc_822D09EC;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r9,44(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 44);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lhz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 16);
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// beq cr6,0x822d09ec
	if (cr6.eq) goto loc_822D09EC;
	// lwz r3,132(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 132);
	// bl 0x8238f998
	ctx.lr = 0x822D09D4;
	sub_8238F998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822cf208
	ctx.lr = 0x822D09EC;
	sub_822CF208(ctx, base);
loc_822D09EC:
	// lwz r11,172(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 172);
	// li r5,3
	ctx.r5.s64 = 3;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822d0b5c
	if (!cr6.eq) goto loc_822D0B5C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-18096
	ctx.r4.s64 = r11.s64 + -18096;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r19,1
	r19.s64 = 1;
	// bl 0x8238dbb0
	ctx.lr = 0x822D0A18;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D0A2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-18860
	ctx.r4.s64 = ctx.r9.s64 + -18860;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0A48;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D0A5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r7,-18208
	ctx.r4.s64 = ctx.r7.s64 + -18208;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0A78;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822D0A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r5,-18384
	ctx.r4.s64 = ctx.r5.s64 + -18384;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238da80
	ctx.lr = 0x822D0AAC;
	sub_8238DA80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D0AC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r30,r10,-18908
	r30.s64 = ctx.r10.s64 + -18908;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D0AE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r7,-18104
	ctx.r4.s64 = ctx.r7.s64 + -18104;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D0B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D0B2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r7,-18256
	ctx.r4.s64 = ctx.r7.s64 + -18256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238dbb0
	ctx.lr = 0x822D0B44;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822D0B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822d0ba0
	goto loc_822D0BA0;
loc_822D0B5C:
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-18908
	ctx.r4.s64 = r11.s64 + -18908;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D0B7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r8,-18104
	ctx.r4.s64 = ctx.r8.s64 + -18104;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D0BA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D0BA0:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r9,44(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 44);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,40(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// lwz r5,136(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 136);
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// bge cr6,0x822d0bcc
	if (!cr6.lt) goto loc_822D0BCC;
	// li r17,1
	r17.s64 = 1;
loc_822D0BCC:
	// lwz r11,20(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 20);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f13,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-13148(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	f0.f64 = double(temp.f32);
	// lfs f12,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fcmpu cr6,f11,f10
	cr6.compare(ctx.f11.f64, ctx.f10.f64);
	// ble cr6,0x822d0bf8
	if (!cr6.gt) goto loc_822D0BF8;
	// li r18,1
	r18.s64 = 1;
loc_822D0BF8:
	// mr r7,r18
	ctx.r7.u64 = r18.u64;
	// mr r6,r17
	ctx.r6.u64 = r17.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822cd720
	ctx.lr = 0x822D0C10;
	sub_822CD720(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d921c
	return;
loc_822D0C1C:
	// lbz r11,797(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 797);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d0cc8
	if (cr6.eq) goto loc_822D0CC8;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r4,0(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// bl 0x82388c48
	ctx.lr = 0x822D0C34;
	sub_82388C48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d1060
	if (cr6.eq) goto loc_822D1060;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r30,r10,5
	r30.s64 = ctx.r10.s64 + 327680;
	// addi r30,r30,-5328
	r30.s64 = r30.s64 + -5328;
	// lwz r11,4168(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4168);
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// blt cr6,0x822d0c64
	if (cr6.lt) goto loc_822D0C64;
	// cmpwi cr6,r11,40
	cr6.compare<int32_t>(r11.s32, 40, xer);
	// blt cr6,0x822d0c74
	if (cr6.lt) goto loc_822D0C74;
loc_822D0C64:
	// cmpwi cr6,r11,351
	cr6.compare<int32_t>(r11.s32, 351, xer);
	// blt cr6,0x822d1060
	if (cr6.lt) goto loc_822D1060;
	// cmpwi cr6,r11,382
	cr6.compare<int32_t>(r11.s32, 382, xer);
	// bge cr6,0x822d1060
	if (!cr6.lt) goto loc_822D1060;
loc_822D0C74:
	// lwz r11,148(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// lwz r10,1060(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1060);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822d1060
	if (!cr6.eq) goto loc_822D1060;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82640738
	ctx.lr = 0x822D0C8C;
	sub_82640738(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x822d1060
	if (!cr6.eq) goto loc_822D1060;
	// lwz r3,132(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 132);
	// lwz r30,4168(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4168);
	// bl 0x8238f998
	ctx.lr = 0x822D0CA0;
	sub_8238F998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822cf3d8
	ctx.lr = 0x822D0CBC;
	sub_822CF3D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d921c
	return;
loc_822D0CC8:
	// lwz r11,172(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 172);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822d0e88
	if (!cr6.eq) goto loc_822D0E88;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-18096
	ctx.r4.s64 = r11.s64 + -18096;
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x8238dbb0
	ctx.lr = 0x822D0CF0;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D0D04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-18208
	ctx.r4.s64 = ctx.r9.s64 + -18208;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0D20;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D0D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r7,-18860
	ctx.r4.s64 = ctx.r7.s64 + -18860;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0D50;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822D0D64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r5,-18384
	ctx.r4.s64 = ctx.r5.s64 + -18384;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238da80
	ctx.lr = 0x822D0D84;
	sub_8238DA80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D0D98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r30,r10,-18908
	r30.s64 = ctx.r10.s64 + -18908;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0DB8;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,40(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D0DCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,-18104
	ctx.r4.s64 = ctx.r8.s64 + -18104;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0DE8;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r7,40(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822D0DFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,76(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D0E1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r4,r10,-18256
	ctx.r4.s64 = ctx.r10.s64 + -18256;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238dbb0
	ctx.lr = 0x822D0E34;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,40(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D0E48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// bne cr6,0x822d1060
	if (!cr6.eq) goto loc_822D1060;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238dbb0
	ctx.lr = 0x822D0E68;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D0E7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d921c
	return;
loc_822D0E88:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822d0f24
	if (!cr6.eq) goto loc_822D0F24;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-18112
	ctx.r4.s64 = r11.s64 + -18112;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8238dbb0
	ctx.lr = 0x822D0EA4;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D0EB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r9,-18908
	ctx.r4.s64 = ctx.r9.s64 + -18908;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0ED4;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D0EE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r7,-18104
	ctx.r4.s64 = ctx.r7.s64 + -18104;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0F04;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822D0F18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d921c
	return;
loc_822D0F24:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d0fc0
	if (!cr6.eq) goto loc_822D0FC0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-18120
	ctx.r4.s64 = r11.s64 + -18120;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8238dbb0
	ctx.lr = 0x822D0F40;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D0F54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r9,-18908
	ctx.r4.s64 = ctx.r9.s64 + -18908;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0F70;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D0F84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r7,-18104
	ctx.r4.s64 = ctx.r7.s64 + -18104;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dbb0
	ctx.lr = 0x822D0FA0;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822D0FB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d921c
	return;
loc_822D0FC0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-18908
	ctx.r4.s64 = r11.s64 + -18908;
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x8238dbb0
	ctx.lr = 0x822D0FD4;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D0FE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x822d1034
	goto loc_822D1034;
loc_822D0FF0:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1060
	if (cr6.eq) goto loc_822D1060;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r30,-64(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -64);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-18908
	ctx.r4.s64 = r11.s64 + -18908;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r31,r29,-64
	r31.s64 = r29.s64 + -64;
	// bl 0x8238dbb0
	ctx.lr = 0x822D101C;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D1030;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,-64(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -64);
loc_822D1034:
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r9,-18104
	ctx.r4.s64 = ctx.r9.s64 + -18104;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238dbb0
	ctx.lr = 0x822D104C;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D1060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D1060:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_822D106C"))) PPC_WEAK_FUNC(sub_822D106C);
PPC_FUNC_IMPL(__imp__sub_822D106C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D1070"))) PPC_WEAK_FUNC(sub_822D1070);
PPC_FUNC_IMPL(__imp__sub_822D1070) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r31,r3,52
	r31.s64 = ctx.r3.s64 + 52;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// rlwinm r8,r9,0,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822d10f8
	if (cr6.eq) goto loc_822D10F8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238d4f0
	ctx.lr = 0x822D10AC;
	sub_8238D4F0(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lbz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x822cdf00
	ctx.lr = 0x822D10D0;
	sub_822CDF00(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// beq cr6,0x822d10f8
	if (cr6.eq) goto loc_822D10F8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8238d520
	ctx.lr = 0x822D10E8;
	sub_8238D520(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d10fc
	if (!cr6.eq) goto loc_822D10FC;
loc_822D10F8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822D10FC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_822D1114"))) PPC_WEAK_FUNC(sub_822D1114);
PPC_FUNC_IMPL(__imp__sub_822D1114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D1118"))) PPC_WEAK_FUNC(sub_822D1118);
PPC_FUNC_IMPL(__imp__sub_822D1118) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822d1070
	ctx.lr = 0x822D1130;
	sub_822D1070(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d1154
	if (cr6.eq) goto loc_822D1154;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// bl 0x822cddc0
	ctx.lr = 0x822D1154;
	sub_822CDDC0(ctx, base);
loc_822D1154:
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

__attribute__((alias("__imp__sub_822D1168"))) PPC_WEAK_FUNC(sub_822D1168);
PPC_FUNC_IMPL(__imp__sub_822D1168) {
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
	// bl 0x822d1070
	ctx.lr = 0x822D1178;
	sub_822D1070(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D1194"))) PPC_WEAK_FUNC(sub_822D1194);
PPC_FUNC_IMPL(__imp__sub_822D1194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D1198"))) PPC_WEAK_FUNC(sub_822D1198);
PPC_FUNC_IMPL(__imp__sub_822D1198) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238d970
	ctx.lr = 0x822D11B4;
	sub_8238D970(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d1070
	ctx.lr = 0x822D11C0;
	sub_822D1070(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d11e0
	if (cr6.eq) goto loc_822D11E0;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
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
loc_822D11E0:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_822D11F8"))) PPC_WEAK_FUNC(sub_822D11F8);
PPC_FUNC_IMPL(__imp__sub_822D11F8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238d970
	ctx.lr = 0x822D1214;
	sub_8238D970(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d1070
	ctx.lr = 0x822D1220;
	sub_822D1070(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d1240
	if (cr6.eq) goto loc_822D1240;
	// lfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
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
loc_822D1240:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
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

__attribute__((alias("__imp__sub_822D125C"))) PPC_WEAK_FUNC(sub_822D125C);
PPC_FUNC_IMPL(__imp__sub_822D125C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D1260"))) PPC_WEAK_FUNC(sub_822D1260);
PPC_FUNC_IMPL(__imp__sub_822D1260) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x822D1268;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ce68
	ctx.lr = 0x822D127C;
	sub_8226CE68(ctx, base);
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// li r29,0
	r29.s64 = 0;
	// stw r3,668(r31)
	PPC_STORE_U32(r31.u32 + 668, ctx.r3.u32);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x822d1588
	if (cr6.gt) goto loc_822D1588;
	// lis r12,-32211
	r12.s64 = -2110980096;
	// addi r12,r12,4776
	r12.s64 = r12.s64 + 4776;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822D12C0;
	case 1:
		goto loc_822D1378;
	case 2:
		goto loc_822D1440;
	case 3:
		goto loc_822D1554;
	case 4:
		goto loc_822D1554;
	case 5:
		goto loc_822D1570;
	default:
		__builtin_unreachable();
	}
	// lwz r17,4800(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 4800);
	// lwz r17,4984(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 4984);
	// lwz r17,5184(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 5184);
	// lwz r17,5460(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 5460);
	// lwz r17,5460(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 5460);
	// lwz r17,5488(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 5488);
loc_822D12C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D12C8;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822D12D8;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x822D12E0;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1588
	if (cr6.eq) goto loc_822D1588;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// srawi. r8,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 4;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x822d1588
	if (cr0.eq) goto loc_822D1588;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,664(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 664);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,668(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 668);
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,88(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	f0.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f0,664(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 664, temp.u32);
	// beq cr6,0x822d1588
	if (cr6.eq) goto loc_822D1588;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822d1588
	if (!cr6.lt) goto loc_822D1588;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D133C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822D134C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x822D1354;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d1588
	if (cr6.eq) goto loc_822D1588;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,660(r31)
	PPC_STORE_U32(r31.u32 + 660, ctx.r10.u32);
	// lfs f0,-17980(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17980);
	f0.f64 = double(temp.f32);
	// stfs f0,664(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 664, temp.u32);
	// b 0x822d1588
	goto loc_822D1588;
loc_822D1378:
	// lbz r11,701(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 701);
	// addi r28,r31,688
	r28.s64 = r31.s64 + 688;
	// stw r29,688(r31)
	PPC_STORE_U32(r31.u32 + 688, r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d13c0
	if (cr6.eq) goto loc_822D13C0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-18000
	ctx.r10.s64 = r11.s64 + -18000;
	// stw r10,1616(r31)
	PPC_STORE_U32(r31.u32 + 1616, ctx.r10.u32);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stw r9,696(r31)
	PPC_STORE_U32(r31.u32 + 696, ctx.r9.u32);
	// lwz r8,56(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// srawi r5,r6,4
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 4;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stw r4,692(r31)
	PPC_STORE_U32(r31.u32 + 692, ctx.r4.u32);
	// b 0x822d13e8
	goto loc_822D13E8;
loc_822D13C0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r30,r31,708
	r30.s64 = r31.s64 + 708;
	// addi r10,r11,-18016
	ctx.r10.s64 = r11.s64 + -18016;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r10,1616(r31)
	PPC_STORE_U32(r31.u32 + 1616, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cf6e8
	ctx.lr = 0x822D13DC;
	sub_822CF6E8(ctx, base);
	// li r9,905
	ctx.r9.s64 = 905;
	// stw r30,696(r31)
	PPC_STORE_U32(r31.u32 + 696, r30.u32);
	// stw r9,692(r31)
	PPC_STORE_U32(r31.u32 + 692, ctx.r9.u32);
loc_822D13E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D13F0;
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
	ctx.lr = 0x822D1404;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lwz r30,680(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lwz r27,676(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 676);
	// bl 0x824e7110
	ctx.lr = 0x822D1414;
	sub_824E7110(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r4,1616(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1616);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r3,668(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 668);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// bl 0x824f6ea0
	ctx.lr = 0x822D1434;
	sub_824F6EA0(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,660(r31)
	PPC_STORE_U32(r31.u32 + 660, ctx.r9.u32);
	// b 0x822d1588
	goto loc_822D1588;
loc_822D1440:
	// lwz r11,680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x822d1588
	if (cr6.eq) goto loc_822D1588;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x822d1564
	if (!cr6.eq) goto loc_822D1564;
	// lwz r10,688(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 688);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d1510
	if (!cr6.eq) goto loc_822D1510;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D146C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822D1480;
	sub_82270170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D148C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822D149C;
	sub_82270170(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r27,680(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// lwz r30,672(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r26,r31,684
	r26.s64 = r31.s64 + 684;
	// addi r25,r31,692
	r25.s64 = r31.s64 + 692;
	// addi r24,r31,696
	r24.s64 = r31.s64 + 696;
	// bl 0x824e7118
	ctx.lr = 0x822D14BC;
	sub_824E7118(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x822D14C8;
	sub_824E7110(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,1616(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1616);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// lwz r3,668(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 668);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// stb r29,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r29.u8);
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// stw r26,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r26.u32);
	// stw r27,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r27.u32);
	// bl 0x824f7308
	ctx.lr = 0x822D1504;
	sub_824F7308(ctx, base);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,660(r31)
	PPC_STORE_U32(r31.u32 + 660, ctx.r9.u32);
	// b 0x822d1588
	goto loc_822D1588;
loc_822D1510:
	// lwz r30,672(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r6,r31,684
	ctx.r6.s64 = r31.s64 + 684;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,676(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 676);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r31,692
	ctx.r8.s64 = r31.s64 + 692;
	// lwz r4,1616(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1616);
	// addi r7,r31,696
	ctx.r7.s64 = r31.s64 + 696;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// stb r29,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r29.u8);
	// bl 0x824f7468
	ctx.lr = 0x822D1548;
	sub_824F7468(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r5,660(r31)
	PPC_STORE_U32(r31.u32 + 660, ctx.r5.u32);
	// b 0x822d1588
	goto loc_822D1588;
loc_822D1554:
	// lwz r11,680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x822d1588
	if (cr6.eq) goto loc_822D1588;
loc_822D1564:
	// li r11,5
	r11.s64 = 5;
	// stw r11,660(r31)
	PPC_STORE_U32(r31.u32 + 660, r11.u32);
	// b 0x822d1588
	goto loc_822D1588;
loc_822D1570:
	// lfs f0,704(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 704);
	f0.f64 = double(temp.f32);
	// stb r29,701(r31)
	PPC_STORE_U8(r31.u32 + 701, r29.u8);
	// stfs f0,664(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 664, temp.u32);
	// stw r29,660(r31)
	PPC_STORE_U32(r31.u32 + 660, r29.u32);
	// lwz r3,1620(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1620);
	// bl 0x822d4cc0
	ctx.lr = 0x822D1588;
	sub_822D4CC0(ctx, base);
loc_822D1588:
	// lwz r3,1620(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1620);
	// bl 0x82740720
	ctx.lr = 0x822D1590;
	sub_82740720(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d1640
	if (!cr6.eq) goto loc_822D1640;
	// lwz r3,1620(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1620);
	// bl 0x823b2078
	ctx.lr = 0x822D15A4;
	sub_823B2078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1624
	if (cr6.eq) goto loc_822D1624;
	// lwz r11,1620(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1620);
	// lis r27,-32115
	r27.s64 = -2104688640;
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// lwz r11,1620(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1620);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// addi r26,r11,4
	r26.s64 = r11.s64 + 4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r28,r11,-18024
	r28.s64 = r11.s64 + -18024;
loc_822D15D0:
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822d160c
	if (cr6.eq) goto loc_822D160C;
	// lwz r31,-12440(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + -12440);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238dae8
	ctx.lr = 0x822D15F8;
	sub_8238DAE8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D160C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D160C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// blt cr6,0x822d15d0
	if (cr6.lt) goto loc_822D15D0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
loc_822D1624:
	// lwz r3,1620(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1620);
	// bl 0x823b2090
	ctx.lr = 0x822D162C;
	sub_823B2090(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1640
	if (cr6.eq) goto loc_822D1640;
	// lwz r11,1620(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1620);
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
loc_822D1640:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822D1648"))) PPC_WEAK_FUNC(sub_822D1648);
PPC_FUNC_IMPL(__imp__sub_822D1648) {
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
	// addi r4,r11,-2744
	ctx.r4.s64 = r11.s64 + -2744;
	// addi r3,r10,-17828
	ctx.r3.s64 = ctx.r10.s64 + -17828;
	// bl 0x82554798
	ctx.lr = 0x822D1668;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-2656
	ctx.r4.s64 = ctx.r9.s64 + -2656;
	// addi r3,r8,-17856
	ctx.r3.s64 = ctx.r8.s64 + -17856;
	// bl 0x82554798
	ctx.lr = 0x822D167C;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-2568
	ctx.r4.s64 = ctx.r7.s64 + -2568;
	// addi r3,r6,-17884
	ctx.r3.s64 = ctx.r6.s64 + -17884;
	// bl 0x82554798
	ctx.lr = 0x822D1690;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-2464
	ctx.r4.s64 = ctx.r5.s64 + -2464;
	// addi r3,r3,-17912
	ctx.r3.s64 = ctx.r3.s64 + -17912;
	// bl 0x82554798
	ctx.lr = 0x822D16A4;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-2440
	ctx.r4.s64 = r11.s64 + -2440;
	// addi r3,r10,-17944
	ctx.r3.s64 = ctx.r10.s64 + -17944;
	// bl 0x82554798
	ctx.lr = 0x822D16B8;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-9528
	ctx.r4.s64 = ctx.r9.s64 + -9528;
	// addi r3,r8,-17976
	ctx.r3.s64 = ctx.r8.s64 + -17976;
	// bl 0x82554798
	ctx.lr = 0x822D16CC;
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

__attribute__((alias("__imp__sub_822D16DC"))) PPC_WEAK_FUNC(sub_822D16DC);
PPC_FUNC_IMPL(__imp__sub_822D16DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D16E0"))) PPC_WEAK_FUNC(sub_822D16E0);
PPC_FUNC_IMPL(__imp__sub_822D16E0) {
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
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,30
	cr6.compare<int32_t>(r11.s32, 30, xer);
	// bne cr6,0x822d1708
	if (!cr6.eq) goto loc_822D1708;
	// bl 0x822cccd0
	ctx.lr = 0x822D1704;
	sub_822CCCD0(ctx, base);
	// b 0x822d1720
	goto loc_822D1720;
loc_822D1708:
	// cmpwi cr6,r11,60
	cr6.compare<int32_t>(r11.s32, 60, xer);
	// bne cr6,0x822d1720
	if (!cr6.eq) goto loc_822D1720;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822cdc88
	ctx.lr = 0x822D1718;
	sub_822CDC88(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,656(r31)
	PPC_STORE_U32(r31.u32 + 656, r11.u32);
loc_822D1720:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// addi r9,r10,-27612
	ctx.r9.s64 = ctx.r10.s64 + -27612;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,656(r31)
	PPC_STORE_U32(r31.u32 + 656, ctx.r8.u32);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d1748
	if (!cr6.eq) goto loc_822D1748;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d1260
	ctx.lr = 0x822D1748;
	sub_822D1260(ctx, base);
loc_822D1748:
	// lwz r3,1620(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1620);
	// bl 0x822d4e00
	ctx.lr = 0x822D1750;
	sub_822D4E00(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27628(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27628);
	// bl 0x82740958
	ctx.lr = 0x822D175C;
	sub_82740958(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D1770"))) PPC_WEAK_FUNC(sub_822D1770);
PPC_FUNC_IMPL(__imp__sub_822D1770) {
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
	ctx.lr = 0x822D1778;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r31,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, r31.u32);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// addi r10,r1,212
	ctx.r10.s64 = ctx.r1.s64 + 212;
	// srawi r11,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	r11.s64 = ctx.r9.s32 >> 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x822d17b8
	if (cr6.lt) goto loc_822D17B8;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
loc_822D17B8:
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lis r9,4095
	ctx.r9.s64 = 268369920;
	// ori r8,r9,65535
	ctx.r8.u64 = ctx.r9.u64 | 65535;
	// add r25,r10,r11
	r25.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r25,r8
	cr6.compare<uint32_t>(r25.u32, ctx.r8.u32, xer);
	// ble cr6,0x822d17e4
	if (!cr6.gt) goto loc_822D17E4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-15120
	ctx.r3.s64 = r11.s64 + -15120;
	// bl 0x823dd898
	ctx.lr = 0x822D17DC;
	sub_823DD898(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823db0a0
	ctx.lr = 0x822D17E4;
	sub_823DB0A0(ctx, base);
loc_822D17E4:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822d17fc
	if (cr6.eq) goto loc_822D17FC;
	// rlwinm r3,r25,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x822D17F4;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x822d1800
	goto loc_822D1800;
loc_822D17FC:
	// li r27,0
	r27.s64 = 0;
loc_822D1800:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r27
	r11.u64 = r27.u64;
	// cmplw cr6,r10,r29
	cr6.compare<uint32_t>(ctx.r10.u32, r29.u32, xer);
	// beq cr6,0x822d1848
	if (cr6.eq) goto loc_822D1848;
loc_822D1810:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1838
	if (cr6.eq) goto loc_822D1838;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
loc_822D1838:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmplw cr6,r10,r29
	cr6.compare<uint32_t>(ctx.r10.u32, r29.u32, xer);
	// bne cr6,0x822d1810
	if (!cr6.eq) goto loc_822D1810;
loc_822D1848:
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// bne cr6,0x822d1880
	if (!cr6.eq) goto loc_822D1880;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1878
	if (cr6.eq) goto loc_822D1878;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r7,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r7.u32);
loc_822D1878:
	// addi r31,r11,16
	r31.s64 = r11.s64 + 16;
	// b 0x822d18c4
	goto loc_822D18C4;
loc_822D1880:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d18c0
	if (cr6.eq) goto loc_822D18C0;
loc_822D188C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d18b4
	if (cr6.eq) goto loc_822D18B4;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// lwz r6,12(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
loc_822D18B4:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x822d188c
	if (!cr0.eq) goto loc_822D188C;
loc_822D18C0:
	// mr r31,r11
	r31.u64 = r11.u64;
loc_822D18C4:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d1924
	if (!cr6.eq) goto loc_822D1924;
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmplw cr6,r29,r9
	cr6.compare<uint32_t>(r29.u32, ctx.r9.u32, xer);
	// beq cr6,0x822d1920
	if (cr6.eq) goto loc_822D1920;
	// subf r10,r31,r29
	ctx.r10.s64 = r29.s64 - r31.s64;
loc_822D18E4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1910
	if (cr6.eq) goto loc_822D1910;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stw r5,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r5.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
loc_822D1910:
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bne cr6,0x822d18e4
	if (!cr6.eq) goto loc_822D18E4;
loc_822D1920:
	// mr r31,r11
	r31.u64 = r11.u64;
loc_822D1924:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d1934
	if (cr6.eq) goto loc_822D1934;
	// bl 0x82130588
	ctx.lr = 0x822D1934;
	sub_82130588(ctx, base);
loc_822D1934:
	// rlwinm r11,r25,4,0,27
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r27,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r27.u32);
	// stw r31,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r31.u32);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// stw r11,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822D1950"))) PPC_WEAK_FUNC(sub_822D1950);
PPC_FUNC_IMPL(__imp__sub_822D1950) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822d19b4
	if (cr6.eq) goto loc_822D19B4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1998
	if (cr6.eq) goto loc_822D1998;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r7,12(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// stw r7,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r7.u32);
loc_822D1998:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822D19B4:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// bl 0x822d1770
	ctx.lr = 0x822D19D4;
	sub_822D1770(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D19E4"))) PPC_WEAK_FUNC(sub_822D19E4);
PPC_FUNC_IMPL(__imp__sub_822D19E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D19E8"))) PPC_WEAK_FUNC(sub_822D19E8);
PPC_FUNC_IMPL(__imp__sub_822D19E8) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// subf r8,r11,r4
	ctx.r8.s64 = ctx.r4.s64 - r11.s64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r30,r8,4
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	r30.s64 = ctx.r8.s32 >> 4;
	// srawi r6,r7,4
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 4;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// blt cr6,0x822d1a44
	if (cr6.lt) goto loc_822D1A44;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x822cdf70
	ctx.lr = 0x822D1A40;
	sub_822CDF70(ctx, base);
	// b 0x822d1a54
	goto loc_822D1A54;
loc_822D1A44:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// bl 0x822d1770
	ctx.lr = 0x822D1A54;
	sub_822D1770(ctx, base);
loc_822D1A54:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
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

__attribute__((alias("__imp__sub_822D1A78"))) PPC_WEAK_FUNC(sub_822D1A78);
PPC_FUNC_IMPL(__imp__sub_822D1A78) {
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
	ctx.lr = 0x822D1A80;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r31,r23,52
	r31.s64 = r23.s64 + 52;
	// li r24,0
	r24.s64 = 0;
	// lwz r5,56(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// lwz r4,52(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 52);
	// cmplw cr6,r4,r5
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, xer);
	// beq cr6,0x822d1abc
	if (cr6.eq) goto loc_822D1ABC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r24,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r24.u8);
	// bl 0x822cfff0
	ctx.lr = 0x822D1ABC;
	sub_822CFFF0(ctx, base);
loc_822D1ABC:
	// lwz r25,904(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 904);
	// addi r11,r30,904
	r11.s64 = r30.s64 + 904;
	// addi r28,r29,-908
	r28.s64 = r29.s64 + -908;
	// li r26,908
	r26.s64 = 908;
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822d1b78
	if (cr6.eq) goto loc_822D1B78;
	// mr r27,r25
	r27.u64 = r25.u64;
loc_822D1ADC:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238d4c8
	ctx.lr = 0x822D1AE4;
	sub_8238D4C8(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238d750
	ctx.lr = 0x822D1AF4;
	sub_8238D750(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x822d1b44
	if (cr6.eq) goto loc_822D1B44;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d1b34
	if (cr6.eq) goto loc_822D1B34;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r8,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r7,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r7.u32);
loc_822D1B34:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// b 0x822d1b64
	goto loc_822D1B64;
loc_822D1B44:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r24,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r24.u8);
	// bl 0x822d1770
	ctx.lr = 0x822D1B64;
	sub_822D1770(ctx, base);
loc_822D1B64:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// add r30,r29,r30
	r30.u64 = r29.u64 + r30.u64;
	// subf r28,r29,r28
	r28.s64 = r28.s64 - r29.s64;
	// add r26,r29,r26
	r26.u64 = r29.u64 + r26.u64;
	// bne 0x822d1adc
	if (!cr0.eq) goto loc_822D1ADC;
loc_822D1B78:
	// subfic r11,r25,1000
	xer.ca = r25.u32 <= 1000;
	r11.s64 = 1000 - r25.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r29,r11,4,0,27
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823d9890
	ctx.lr = 0x822D1B90;
	sub_823D9890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r30,r29,r26
	r30.u64 = r29.u64 + r26.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822d1be4
	if (cr6.eq) goto loc_822D1BE4;
loc_822D1BA4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,97
	cr6.compare<uint32_t>(ctx.r10.u32, 97, xer);
	// bne cr6,0x822d1bd4
	if (!cr6.eq) goto loc_822D1BD4;
	// lbz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// rlwinm r8,r9,0,27,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1C;
	// cmplwi cr6,r8,20
	cr6.compare<uint32_t>(ctx.r8.u32, 20, xer);
	// beq cr6,0x822d1bd4
	if (cr6.eq) goto loc_822D1BD4;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r9,r9,0,30,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFE3;
	// ori r8,r9,20
	ctx.r8.u64 = ctx.r9.u64 | 20;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
loc_822D1BD4:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822d1ba4
	if (!cr6.eq) goto loc_822D1BA4;
loc_822D1BE4:
	// bl 0x821789d8
	ctx.lr = 0x822D1BE8;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1c00
	if (cr6.eq) goto loc_822D1C00;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r6,17008(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x822d1c08
	goto loc_822D1C08;
loc_822D1C00:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r6,17016(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_822D1C08:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r31,0(r23)
	r31.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,-17792
	ctx.r4.s64 = r11.s64 + -17792;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8238dbb0
	ctx.lr = 0x822D1C20;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D1C34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,0(r23)
	r31.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// bl 0x82178848
	ctx.lr = 0x822D1C3C;
	sub_82178848(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r8,-17800
	ctx.r4.s64 = ctx.r8.s64 + -17800;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// li r5,3
	ctx.r5.s64 = 3;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8238dbb0
	ctx.lr = 0x822D1C60;
	sub_8238DBB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822D1C74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r4,700(r23)
	ctx.r4.u64 = PPC_LOAD_U8(r23.u32 + 700);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822d1c9c
	if (!cr6.eq) goto loc_822D1C9C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,1
	r11.s64 = 1;
	// stb r11,701(r23)
	PPC_STORE_U8(r23.u32 + 701, r11.u8);
	// stb r11,700(r23)
	PPC_STORE_U8(r23.u32 + 700, r11.u8);
	// lfs f0,27632(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27632);
	f0.f64 = double(temp.f32);
	// stfs f0,664(r23)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r23.u32 + 664, temp.u32);
loc_822D1C9C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822D1CA4"))) PPC_WEAK_FUNC(sub_822D1CA4);
PPC_FUNC_IMPL(__imp__sub_822D1CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D1CA8"))) PPC_WEAK_FUNC(sub_822D1CA8);
PPC_FUNC_IMPL(__imp__sub_822D1CA8) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r31,r11,52
	r31.s64 = r11.s64 + 52;
	// bl 0x8238d4f0
	ctx.lr = 0x822D1CD0;
	sub_8238D4F0(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lbz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x822cdf00
	ctx.lr = 0x822D1CF4;
	sub_822CDF00(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// srawi r8,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 4;
	// cmplwi cr6,r8,1000
	cr6.compare<uint32_t>(ctx.r8.u32, 1000, xer);
	// blt cr6,0x822d1d18
	if (cr6.lt) goto loc_822D1D18;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x822d1d70
	goto loc_822D1D70;
loc_822D1D18:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// bne cr6,0x822d1d58
	if (!cr6.eq) goto loc_822D1D58;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x822d1950
	ctx.lr = 0x822D1D50;
	sub_822D1950(ctx, base);
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x822d1d64
	goto loc_822D1D64;
loc_822D1D58:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// bl 0x822d19e8
	ctx.lr = 0x822D1D60;
	sub_822D19E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_822D1D64:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d670
	ctx.lr = 0x822D1D6C;
	sub_8238D670(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D1D70:
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

__attribute__((alias("__imp__sub_822D1D88"))) PPC_WEAK_FUNC(sub_822D1D88);
PPC_FUNC_IMPL(__imp__sub_822D1D88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x822D1D90;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// bl 0x82256058
	ctx.lr = 0x822D1DA0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d1db4
	if (cr6.eq) goto loc_822D1DB4;
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d1ee0
	if (!cr6.eq) goto loc_822D1EE0;
loc_822D1DB4:
	// bl 0x82387a18
	ctx.lr = 0x822D1DB8;
	sub_82387A18(ctx, base);
	// lbz r11,0(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 0);
	// li r26,1
	r26.s64 = 1;
	// extsb r11,r11
	r11.s64 = r11.s8;
	// addi r11,r11,-97
	r11.s64 = r11.s64 + -97;
	// cmplwi cr6,r11,19
	cr6.compare<uint32_t>(r11.u32, 19, xer);
	// bgt cr6,0x822d1f20
	if (cr6.gt) goto loc_822D1F20;
	// lis r12,-32211
	r12.s64 = -2110980096;
	// addi r12,r12,7656
	r12.s64 = r12.s64 + 7656;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822D1F1C;
	case 1:
		goto loc_822D1F20;
	case 2:
		goto loc_822D1F20;
	case 3:
		goto loc_822D1F20;
	case 4:
		goto loc_822D1F20;
	case 5:
		goto loc_822D1F20;
	case 6:
		goto loc_822D1F20;
	case 7:
		goto loc_822D1F20;
	case 8:
		goto loc_822D1F20;
	case 9:
		goto loc_822D1F20;
	case 10:
		goto loc_822D1F04;
	case 11:
		goto loc_822D1F20;
	case 12:
		goto loc_822D1F20;
	case 13:
		goto loc_822D1E38;
	case 14:
		goto loc_822D1EEC;
	case 15:
		goto loc_822D1F20;
	case 16:
		goto loc_822D1F20;
	case 17:
		goto loc_822D1F20;
	case 18:
		goto loc_822D1F20;
	case 19:
		goto loc_822D1F1C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,7964(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7964);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7940(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7940);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7736(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7736);
	// lwz r17,7916(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7916);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7968(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7968);
	// lwz r17,7964(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 7964);
loc_822D1E38:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1ee0
	if (cr6.eq) goto loc_822D1EE0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// li r28,0
	r28.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// lbzx r27,r9,r10
	r27.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// addi r29,r30,400
	r29.s64 = r30.s64 + 400;
loc_822D1E64:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822d1e74
	if (cr6.eq) goto loc_822D1E74;
	// lwz r11,260(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// b 0x822d1e78
	goto loc_822D1E78;
loc_822D1E74:
	// lwz r11,132(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 132);
loc_822D1E78:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822d1ed8
	if (!cr6.lt) goto loc_822D1ED8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822D1E8C;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d1ec8
	if (!cr6.eq) goto loc_822D1EC8;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822d1eb8
	if (cr6.lt) goto loc_822D1EB8;
	// cmpwi cr6,r31,31
	cr6.compare<int32_t>(r31.s32, 31, xer);
	// bge cr6,0x822d1eb8
	if (!cr6.lt) goto loc_822D1EB8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d1ebc
	if (!cr6.eq) goto loc_822D1EBC;
loc_822D1EB8:
	// li r11,0
	r11.s64 = 0;
loc_822D1EBC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1ecc
	if (cr6.eq) goto loc_822D1ECC;
loc_822D1EC8:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_822D1ECC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// b 0x822d1e64
	goto loc_822D1E64;
loc_822D1ED8:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bgt cr6,0x822d1f20
	if (cr6.gt) goto loc_822D1F20;
loc_822D1EE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_822D1EEC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d1f20
	if (!cr6.eq) goto loc_822D1F20;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_822D1F04:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1f20
	if (cr6.eq) goto loc_822D1F20;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_822D1F1C:
	// li r26,0
	r26.s64 = 0;
loc_822D1F20:
	// bl 0x8269c3d8
	ctx.lr = 0x822D1F24;
	sub_8269C3D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d1f90
	if (!cr6.eq) goto loc_822D1F90;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1f90
	if (cr6.eq) goto loc_822D1F90;
	// bl 0x82387a98
	ctx.lr = 0x822D1F40;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1f90
	if (cr6.eq) goto loc_822D1F90;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r31,r11,-18804
	r31.s64 = r11.s64 + -18804;
	// bl 0x8238d9b8
	ctx.lr = 0x822D1F64;
	sub_8238D9B8(ctx, base);
loc_822D1F64:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x822d1f88
	if (cr6.eq) goto loc_822D1F88;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d1f64
	if (cr6.eq) goto loc_822D1F64;
loc_822D1F88:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d1ee0
	if (!cr6.eq) goto loc_822D1EE0;
loc_822D1F90:
	// lbz r11,8(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 8);
	// rlwinm r30,r11,30,29,31
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x7;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x822d1fb4
	if (!cr6.eq) goto loc_822D1FB4;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822d1070
	ctx.lr = 0x822D1FAC;
	sub_822D1070(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d1ee0
	if (!cr6.eq) goto loc_822D1EE0;
loc_822D1FB4:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// beq cr6,0x822d1fc8
	if (cr6.eq) goto loc_822D1FC8;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x822d1fe0
	if (!cr6.eq) goto loc_822D1FE0;
loc_822D1FC8:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822d1070
	ctx.lr = 0x822D1FD4;
	sub_822D1070(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d1fe0
	if (!cr6.eq) goto loc_822D1FE0;
	// li r29,1
	r29.s64 = 1;
loc_822D1FE0:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822d1070
	ctx.lr = 0x822D1FEC;
	sub_822D1070(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822d2010
	if (!cr6.eq) goto loc_822D2010;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822d1ca8
	ctx.lr = 0x822D2004;
	sub_822D1CA8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d1ee0
	if (cr6.eq) goto loc_822D1EE0;
loc_822D2010:
	// cmplwi cr6,r30,4
	cr6.compare<uint32_t>(r30.u32, 4, xer);
	// bgt cr6,0x822d1ee0
	if (cr6.gt) goto loc_822D1EE0;
	// lis r12,-32211
	r12.s64 = -2110980096;
	// addi r12,r12,8240
	r12.s64 = r12.s64 + 8240;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r30.u64) {
	case 0:
		goto loc_822D2044;
	case 1:
		goto loc_822D205C;
	case 2:
		goto loc_822D2098;
	case 3:
		goto loc_822D2080;
	case 4:
		goto loc_822D2080;
	default:
		__builtin_unreachable();
	}
	// lwz r17,8260(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 8260);
	// lwz r17,8284(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 8284);
	// lwz r17,8344(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 8344);
	// lwz r17,8320(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 8320);
	// lwz r17,8320(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 8320);
loc_822D2044:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d620
	ctx.lr = 0x822D2050;
	sub_8238D620(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_822D205C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d2080
	if (!cr6.eq) goto loc_822D2080;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d590
	ctx.lr = 0x822D2074;
	sub_8238D590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1ee0
	if (cr6.eq) goto loc_822D1EE0;
loc_822D2080:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d5f0
	ctx.lr = 0x822D208C;
	sub_8238D5F0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_822D2098:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d20bc
	if (!cr6.eq) goto loc_822D20BC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8238d590
	ctx.lr = 0x822D20B0;
	sub_8238D590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d1ee0
	if (cr6.eq) goto loc_822D1EE0;
loc_822D20BC:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d5f0
	ctx.lr = 0x822D20C8;
	sub_8238D5F0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822D20D4"))) PPC_WEAK_FUNC(sub_822D20D4);
PPC_FUNC_IMPL(__imp__sub_822D20D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D20D8"))) PPC_WEAK_FUNC(sub_822D20D8);
PPC_FUNC_IMPL(__imp__sub_822D20D8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822D20E0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82387b90
	ctx.lr = 0x822D20F8;
	sub_82387B90(ctx, base);
	// bl 0x8238b3f8
	ctx.lr = 0x822D20FC;
	sub_8238B3F8(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x822D2108;
	sub_822F10D0(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x82387b90
	ctx.lr = 0x822D2110;
	sub_82387B90(ctx, base);
	// stfs f31,1332(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1332, temp.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d240
	ctx.lr = 0x822D2124;
	sub_8238D240(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822D2130"))) PPC_WEAK_FUNC(sub_822D2130);
PPC_FUNC_IMPL(__imp__sub_822D2130) {
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
	// bl 0x8238d410
	ctx.lr = 0x822D2148;
	sub_8238D410(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r7,r9,-17420
	ctx.r7.s64 = ctx.r9.s64 + -17420;
	// addi r6,r8,-17460
	ctx.r6.s64 = ctx.r8.s64 + -17460;
	// addi r10,r31,12
	ctx.r10.s64 = r31.s64 + 12;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r5,-17420(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17420);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r4,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r4.u32);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lbz r9,12(r7)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + 12);
	// stb r9,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r9.u8);
loc_822D2184:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d2184
	if (!cr6.eq) goto loc_822D2184;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stb r10,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r10.u8);
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
	// bl 0x82387b90
	ctx.lr = 0x822D21AC;
	sub_82387B90(ctx, base);
	// lis r7,3
	ctx.r7.s64 = 196608;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// ori r4,r7,57424
	ctx.r4.u64 = ctx.r7.u64 | 57424;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// stw r4,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r4.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r6,r3,-14596
	ctx.r6.s64 = ctx.r3.s64 + -14596;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,2832(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2832);
	// addi r5,r11,-14960
	ctx.r5.s64 = r11.s64 + -14960;
	// bl 0x82202c00
	ctx.lr = 0x822D21DC;
	sub_82202C00(ctx, base);
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

__attribute__((alias("__imp__sub_822D21F4"))) PPC_WEAK_FUNC(sub_822D21F4);
PPC_FUNC_IMPL(__imp__sub_822D21F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D21F8"))) PPC_WEAK_FUNC(sub_822D21F8);
PPC_FUNC_IMPL(__imp__sub_822D21F8) {
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
	// addi r10,r11,-17460
	ctx.r10.s64 = r11.s64 + -17460;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8238d010
	ctx.lr = 0x822D2224;
	sub_8238D010(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d223c
	if (cr6.eq) goto loc_822D223C;
	// bl 0x82130588
	ctx.lr = 0x822D2238;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D223C:
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

__attribute__((alias("__imp__sub_822D2254"))) PPC_WEAK_FUNC(sub_822D2254);
PPC_FUNC_IMPL(__imp__sub_822D2254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2258"))) PPC_WEAK_FUNC(sub_822D2258);
PPC_FUNC_IMPL(__imp__sub_822D2258) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822D2260;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x8238d390
	ctx.lr = 0x822D2268;
	sub_8238D390(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82388540
	ctx.lr = 0x822D2270;
	sub_82388540(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x822D2274;
	sub_82387B90(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f1,1332(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 1332);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lfs f2,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822f1518
	ctx.lr = 0x822D2290;
	sub_822F1518(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x822D229C;
	sub_822A39C0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d22cc
	if (cr6.eq) goto loc_822D22CC;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822D22B0;
	sub_822A39C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a5578
	ctx.lr = 0x822D22B8;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d22cc
	if (cr6.eq) goto loc_822D22CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x822D22C8;
	sub_822A5578(ctx, base);
	// bl 0x822a0028
	ctx.lr = 0x822D22CC;
	sub_822A0028(ctx, base);
loc_822D22CC:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// subfic r29,r11,1240
	xer.ca = r11.u32 <= 1240;
	r29.s64 = 1240 - r11.s64;
	// li r30,5
	r30.s64 = 5;
loc_822D22DC:
	// bl 0x82387b90
	ctx.lr = 0x822D22E0;
	sub_82387B90(ctx, base);
	// add r11,r29,r31
	r11.u64 = r29.u64 + r31.u64;
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lfsx f0,r11,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822d22dc
	if (!cr0.eq) goto loc_822D22DC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e6980
	ctx.lr = 0x822D2300;
	sub_821E6980(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D230C"))) PPC_WEAK_FUNC(sub_822D230C);
PPC_FUNC_IMPL(__imp__sub_822D230C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2310"))) PPC_WEAK_FUNC(sub_822D2310);
PPC_FUNC_IMPL(__imp__sub_822D2310) {
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
	// bl 0x822e7028
	ctx.lr = 0x822D2328;
	sub_822E7028(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-17092
	ctx.r10.s64 = r11.s64 + -17092;
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

__attribute__((alias("__imp__sub_822D234C"))) PPC_WEAK_FUNC(sub_822D234C);
PPC_FUNC_IMPL(__imp__sub_822D234C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2350"))) PPC_WEAK_FUNC(sub_822D2350);
PPC_FUNC_IMPL(__imp__sub_822D2350) {
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
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lwz r11,-18004(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -18004);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822d237c
	if (cr6.eq) goto loc_822D237C;
	// bl 0x823110f0
	ctx.lr = 0x822D237C;
	sub_823110F0(ctx, base);
loc_822D237C:
	// bl 0x8217fff8
	ctx.lr = 0x822D2380;
	sub_8217FFF8(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x822D2384;
	sub_82130000(ctx, base);
	// bl 0x822ed180
	ctx.lr = 0x822D2388;
	sub_822ED180(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-7740
	r31.s64 = r11.s64 + -7740;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d23a4
	if (!cr6.eq) goto loc_822D23A4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822ecd88
	ctx.lr = 0x822D23A4;
	sub_822ECD88(ctx, base);
loc_822D23A4:
	// lwz r11,-18004(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -18004);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822d23bc
	if (cr6.eq) goto loc_822D23BC;
	// li r4,8192
	ctx.r4.s64 = 8192;
	// bl 0x822ee700
	ctx.lr = 0x822D23BC;
	sub_822EE700(ctx, base);
loc_822D23BC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// bl 0x822e5218
	ctx.lr = 0x822D23C8;
	sub_822E5218(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d23dc
	if (!cr6.eq) goto loc_822D23DC;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x822ecd88
	ctx.lr = 0x822D23DC;
	sub_822ECD88(ctx, base);
loc_822D23DC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7896(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7896);
	// bl 0x822e8780
	ctx.lr = 0x822D23E8;
	sub_822E8780(ctx, base);
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

__attribute__((alias("__imp__sub_822D2400"))) PPC_WEAK_FUNC(sub_822D2400);
PPC_FUNC_IMPL(__imp__sub_822D2400) {
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
	// addi r10,r11,-17092
	ctx.r10.s64 = r11.s64 + -17092;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822e7018
	ctx.lr = 0x822D242C;
	sub_822E7018(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d2444
	if (cr6.eq) goto loc_822D2444;
	// bl 0x82130588
	ctx.lr = 0x822D2440;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D2444:
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

__attribute__((alias("__imp__sub_822D245C"))) PPC_WEAK_FUNC(sub_822D245C);
PPC_FUNC_IMPL(__imp__sub_822D245C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2460"))) PPC_WEAK_FUNC(sub_822D2460);
PPC_FUNC_IMPL(__imp__sub_822D2460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, r11.u8);
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D2478"))) PPC_WEAK_FUNC(sub_822D2478);
PPC_FUNC_IMPL(__imp__sub_822D2478) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f0,84(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 84);
	f0.f64 = double(temp.f32);
	// lwz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lfs f13,80(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r31,r11,29952
	r31.s64 = r11.s64 + 29952;
	// fdivs f2,f0,f13
	ctx.f2.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f2,76(r30)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r30.u32 + 76, temp.u32);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x822d24d0
	if (!cr6.eq) goto loc_822D24D0;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x821bd9b8
	ctx.lr = 0x822D24CC;
	sub_821BD9B8(ctx, base);
	// b 0x822d24dc
	goto loc_822D24DC;
loc_822D24D0:
	// lwz r5,92(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// fmr f1,f2
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x821bd9f8
	ctx.lr = 0x822D24DC;
	sub_821BD9F8(ctx, base);
loc_822D24DC:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822d2514
	if (!cr6.eq) goto loc_822D2514;
	// lfs f13,88(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x822d2514
	if (!cr6.gt) goto loc_822D2514;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lfs f13,18612(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18612);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// b 0x822d252c
	goto loc_822D252C;
loc_822D2514:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,18612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	f0.f64 = double(temp.f32);
	// lfs f13,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
loc_822D252C:
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

__attribute__((alias("__imp__sub_822D2548"))) PPC_WEAK_FUNC(sub_822D2548);
PPC_FUNC_IMPL(__imp__sub_822D2548) {
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
	ctx.lr = 0x822D2550;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,2512
	r30.s64 = r11.s64 + 2512;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r29,1
	r29.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lfs f0,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stw r29,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r29.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stw r28,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r28.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stb r29,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r29.u8);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r3,r10,-27572
	ctx.r3.s64 = ctx.r10.s64 + -27572;
	// bl 0x821c07c0
	ctx.lr = 0x822D25B0;
	sub_821C07C0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822d25fc
	if (cr6.eq) goto loc_822D25FC;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stw r28,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r28.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stw r29,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r29.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// lfs f12,-16776(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16776);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fdivs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 / f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// li r12,96
	r12.s64 = 96;
	// stfiwx f11,r31,r12
	PPC_STORE_U32(r31.u32 + r12.u32, ctx.f11.u32);
	// b 0x822d2638
	goto loc_822D2638;
loc_822D25FC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,-27592
	ctx.r3.s64 = r11.s64 + -27592;
	// bl 0x821c07c0
	ctx.lr = 0x822D260C;
	sub_821C07C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d2638
	if (cr6.eq) goto loc_822D2638;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stw r29,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r29.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x822d2630
	if (cr6.gt) goto loc_822D2630;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
loc_822D2630:
	// stfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stw r29,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r29.u32);
loc_822D2638:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r11,-27512
	ctx.r3.s64 = r11.s64 + -27512;
	// bl 0x821c0750
	ctx.lr = 0x822D2648;
	sub_821C0750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d265c
	if (cr6.eq) goto loc_822D265C;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
loc_822D265C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-27492
	ctx.r10.s64 = r11.s64 + -27492;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d2678
	if (cr6.eq) goto loc_822D2678;
	// stb r29,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r29.u8);
	// b 0x822d2690
	goto loc_822D2690;
loc_822D2678:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-27552
	ctx.r10.s64 = r11.s64 + -27552;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d2690
	if (cr6.eq) goto loc_822D2690;
	// stb r28,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r28.u8);
loc_822D2690:
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r11,-27532
	ctx.r3.s64 = r11.s64 + -27532;
	// bl 0x821c0750
	ctx.lr = 0x822D26A4;
	sub_821C0750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d26b8
	if (cr6.eq) goto loc_822D26B8;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_822D26B8:
	// stfs f31,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d2478
	ctx.lr = 0x822D26C4;
	sub_822D2478(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D26D0"))) PPC_WEAK_FUNC(sub_822D26D0);
PPC_FUNC_IMPL(__imp__sub_822D26D0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-28248
	ctx.r9.s64 = r11.s64 + -28248;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r8,-16728
	ctx.r4.s64 = ctx.r8.s64 + -16728;
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwzx r5,r10,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x822D270C;
	sub_82130000(ctx, base);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r11,r31,20
	r11.s64 = r31.s64 + 20;
	// cmpwi cr6,r7,10
	cr6.compare<int32_t>(ctx.r7.s32, 10, xer);
	// beq cr6,0x822d2750
	if (cr6.eq) goto loc_822D2750;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// cmpwi cr6,r10,10
	cr6.compare<int32_t>(ctx.r10.s32, 10, xer);
	// bne cr6,0x822d2738
	if (!cr6.eq) goto loc_822D2738;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
loc_822D2738:
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r8.u32);
loc_822D2750:
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

__attribute__((alias("__imp__sub_822D2768"))) PPC_WEAK_FUNC(sub_822D2768);
PPC_FUNC_IMPL(__imp__sub_822D2768) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r5,68(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x822d27cc
	if (!cr6.gt) goto loc_822D27CC;
	// lis r11,26214
	r11.s64 = 1717960704;
	// lwz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// addi r7,r3,20
	ctx.r7.s64 = ctx.r3.s64 + 20;
	// ori r9,r11,26215
	ctx.r9.u64 = r11.u64 | 26215;
loc_822D2788:
	// add r11,r6,r8
	r11.u64 = ctx.r6.u64 + ctx.r8.u64;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// mulhw r11,r3,r9
	r11.s64 = (int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32)) >> 32;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r3,r7
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x822d27d4
	if (cr6.eq) goto loc_822D27D4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// blt cr6,0x822d2788
	if (cr6.lt) goto loc_822D2788;
loc_822D27CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822D27D4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D27DC"))) PPC_WEAK_FUNC(sub_822D27DC);
PPC_FUNC_IMPL(__imp__sub_822D27DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D27E0"))) PPC_WEAK_FUNC(sub_822D27E0);
PPC_FUNC_IMPL(__imp__sub_822D27E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d27fc
	if (cr6.eq) goto loc_822D27FC;
	// lbz r11,10(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822d2800
	if (cr6.eq) goto loc_822D2800;
loc_822D27FC:
	// li r11,0
	r11.s64 = 0;
loc_822D2800:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D2814"))) PPC_WEAK_FUNC(sub_822D2814);
PPC_FUNC_IMPL(__imp__sub_822D2814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2818"))) PPC_WEAK_FUNC(sub_822D2818);
PPC_FUNC_IMPL(__imp__sub_822D2818) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8238a988
	ctx.lr = 0x822D2834;
	sub_8238A988(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-16768
	ctx.r10.s64 = r11.s64 + -16768;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// bl 0x827bcd84
	ctx.lr = 0x822D2858;
	__imp__XGetVideoMode(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,2516
	r11.s64 = r11.s64 + 2516;
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f0,-16704(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -16704);
	f0.f64 = double(temp.f32);
	// stfs f13,-4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d2888
	if (!cr6.lt) goto loc_822D2888;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// b 0x822d288c
	goto loc_822D288C;
loc_822D2888:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_822D288C:
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r7,r9,-7924
	ctx.r7.s64 = ctx.r9.s64 + -7924;
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d28b0
	if (cr6.eq) goto loc_822D28B0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,27632(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27632);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// b 0x822d28b4
	goto loc_822D28B4;
loc_822D28B0:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
loc_822D28B4:
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r9,-17932(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17932);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x822d28e8
	if (!cr6.eq) goto loc_822D28E8;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// li r10,2
	ctx.r10.s64 = 2;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f0,f13,f11
	f0.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_822D28E8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f0,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r8,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r8.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r8.u32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// lfs f13,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stb r8,100(r31)
	PPC_STORE_U8(r31.u32 + 100, ctx.r8.u8);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// stfs f13,88(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

__attribute__((alias("__imp__sub_822D2940"))) PPC_WEAK_FUNC(sub_822D2940);
PPC_FUNC_IMPL(__imp__sub_822D2940) {
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
	// addi r10,r11,-16768
	ctx.r10.s64 = r11.s64 + -16768;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8238a948
	ctx.lr = 0x822D296C;
	sub_8238A948(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d2984
	if (cr6.eq) goto loc_822D2984;
	// bl 0x82130588
	ctx.lr = 0x822D2980;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D2984:
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

__attribute__((alias("__imp__sub_822D299C"))) PPC_WEAK_FUNC(sub_822D299C);
PPC_FUNC_IMPL(__imp__sub_822D299C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D29A0"))) PPC_WEAK_FUNC(sub_822D29A0);
PPC_FUNC_IMPL(__imp__sub_822D29A0) {
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
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82130528
	ctx.lr = 0x822D29B4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d29c4
	if (cr6.eq) goto loc_822D29C4;
	// bl 0x822d2818
	ctx.lr = 0x822D29C0;
	sub_822D2818(ctx, base);
	// b 0x822d29c8
	goto loc_822D29C8;
loc_822D29C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822D29C8:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,-12640(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12640, ctx.r3.u32);
	// stw r3,-12636(r11)
	PPC_STORE_U32(r11.u32 + -12636, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D29E8"))) PPC_WEAK_FUNC(sub_822D29E8);
PPC_FUNC_IMPL(__imp__sub_822D29E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x822D29F0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r29,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r29.u8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d2b98
	if (cr6.eq) goto loc_822D2B98;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r28,r31,20
	r28.s64 = r31.s64 + 20;
	// li r27,1
	r27.s64 = 1;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// addi r23,r8,-24980
	r23.s64 = ctx.r8.s64 + -24980;
	// addi r22,r9,-25012
	r22.s64 = ctx.r9.s64 + -25012;
	// addi r25,r10,-25036
	r25.s64 = ctx.r10.s64 + -25036;
	// addi r24,r11,-28248
	r24.s64 = r11.s64 + -28248;
loc_822D2A38:
	// lwz r10,48(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,48(r28)
	PPC_STORE_U32(r28.u32 + 48, ctx.r10.u32);
	// stw r11,44(r28)
	PPC_STORE_U32(r28.u32 + 44, r11.u32);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x822d2a5c
	if (!cr6.eq) goto loc_822D2A5C;
	// stw r29,44(r28)
	PPC_STORE_U32(r28.u32 + 44, r29.u32);
loc_822D2A5C:
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r28
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r9,r24
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + r24.u32);
	// bl 0x82130000
	ctx.lr = 0x822D2A7C;
	sub_82130000(ctx, base);
	// cmplwi cr6,r30,8
	cr6.compare<uint32_t>(r30.u32, 8, xer);
	// bgt cr6,0x822d2b84
	if (cr6.gt) goto loc_822D2B84;
	// lis r12,-32211
	r12.s64 = -2110980096;
	// addi r12,r12,10908
	r12.s64 = r12.s64 + 10908;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r30.u64) {
	case 0:
		goto loc_822D2AC0;
	case 1:
		goto loc_822D2AC8;
	case 2:
		goto loc_822D2AEC;
	case 3:
		goto loc_822D2B10;
	case 4:
		goto loc_822D2B30;
	case 5:
		goto loc_822D2B48;
	case 6:
		goto loc_822D2B50;
	case 7:
		goto loc_822D2ADC;
	case 8:
		goto loc_822D2B00;
	default:
		__builtin_unreachable();
	}
	// lwz r17,10944(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 10944);
	// lwz r17,10952(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 10952);
	// lwz r17,10988(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 10988);
	// lwz r17,11024(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 11024);
	// lwz r17,11056(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 11056);
	// lwz r17,11080(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 11080);
	// lwz r17,11088(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 11088);
	// lwz r17,10972(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 10972);
	// lwz r17,11008(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 11008);
loc_822D2AC0:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// b 0x822d2b88
	goto loc_822D2B88;
loc_822D2AC8:
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d2adc
	if (cr6.eq) goto loc_822D2ADC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3c18
	ctx.lr = 0x822D2ADC;
	sub_822A3C18(ctx, base);
loc_822D2ADC:
	// stb r29,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r29.u8);
	// stb r27,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r27.u8);
	// stb r29,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r29.u8);
	// b 0x822d2b8c
	goto loc_822D2B8C;
loc_822D2AEC:
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d2b00
	if (cr6.eq) goto loc_822D2B00;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3ff8
	ctx.lr = 0x822D2B00;
	sub_822A3FF8(ctx, base);
loc_822D2B00:
	// stb r29,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r29.u8);
	// stb r29,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r29.u8);
	// stb r29,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r29.u8);
	// b 0x822d2b8c
	goto loc_822D2B8C;
loc_822D2B10:
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d2b24
	if (cr6.eq) goto loc_822D2B24;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822a3c18
	ctx.lr = 0x822D2B24;
	sub_822A3C18(ctx, base);
loc_822D2B24:
	// stb r29,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r29.u8);
	// stb r27,6(r31)
	PPC_STORE_U8(r31.u32 + 6, r27.u8);
	// b 0x822d2b8c
	goto loc_822D2B8C;
loc_822D2B30:
	// stb r29,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r29.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r29,6(r31)
	PPC_STORE_U8(r31.u32 + 6, r29.u8);
	// lwz r3,17268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// bl 0x822a3ff8
	ctx.lr = 0x822D2B44;
	sub_822A3FF8(ctx, base);
	// b 0x822d2b8c
	goto loc_822D2B8C;
loc_822D2B48:
	// stb r27,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r27.u8);
	// b 0x822d2b8c
	goto loc_822D2B8C;
loc_822D2B50:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d2b6c
	if (cr6.eq) goto loc_822D2B6C;
	// lbz r11,10(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x822d2b70
	if (cr6.eq) goto loc_822D2B70;
loc_822D2B6C:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822D2B70:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d2b8c
	if (cr6.eq) goto loc_822D2B8C;
	// stb r27,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r27.u8);
	// b 0x822d2b8c
	goto loc_822D2B8C;
loc_822D2B84:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_822D2B88:
	// bl 0x821bd618
	ctx.lr = 0x822D2B8C;
	sub_821BD618(ctx, base);
loc_822D2B8C:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d2a38
	if (!cr6.eq) goto loc_822D2A38;
loc_822D2B98:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2BAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_822D2BB4"))) PPC_WEAK_FUNC(sub_822D2BB4);
PPC_FUNC_IMPL(__imp__sub_822D2BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2BB8"))) PPC_WEAK_FUNC(sub_822D2BB8);
PPC_FUNC_IMPL(__imp__sub_822D2BB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-16604
	ctx.r10.s64 = r11.s64 + -16604;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D2BC8"))) PPC_WEAK_FUNC(sub_822D2BC8);
PPC_FUNC_IMPL(__imp__sub_822D2BC8) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,2604(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2604);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822d2c24
	if (!cr6.gt) goto loc_822D2C24;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D2C08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r7,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r7.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D2C24:
	// li r11,1
	r11.s64 = 1;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D2C40"))) PPC_WEAK_FUNC(sub_822D2C40);
PPC_FUNC_IMPL(__imp__sub_822D2C40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2C5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-16556
	ctx.r3.s64 = ctx.r9.s64 + -16556;
	// bl 0x821bd618
	ctx.lr = 0x822D2C6C;
	sub_821BD618(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D2C7C"))) PPC_WEAK_FUNC(sub_822D2C7C);
PPC_FUNC_IMPL(__imp__sub_822D2C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2C80"))) PPC_WEAK_FUNC(sub_822D2C80);
PPC_FUNC_IMPL(__imp__sub_822D2C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2C9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-16500
	ctx.r3.s64 = ctx.r9.s64 + -16500;
	// bl 0x821bd618
	ctx.lr = 0x822D2CAC;
	sub_821BD618(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D2CBC"))) PPC_WEAK_FUNC(sub_822D2CBC);
PPC_FUNC_IMPL(__imp__sub_822D2CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2CC0"))) PPC_WEAK_FUNC(sub_822D2CC0);
PPC_FUNC_IMPL(__imp__sub_822D2CC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2CDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-16444
	ctx.r3.s64 = ctx.r9.s64 + -16444;
	// bl 0x821bd618
	ctx.lr = 0x822D2CEC;
	sub_821BD618(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D2CFC"))) PPC_WEAK_FUNC(sub_822D2CFC);
PPC_FUNC_IMPL(__imp__sub_822D2CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2D00"))) PPC_WEAK_FUNC(sub_822D2D00);
PPC_FUNC_IMPL(__imp__sub_822D2D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-16604
	ctx.r9.s64 = r11.s64 + -16604;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D2D18"))) PPC_WEAK_FUNC(sub_822D2D18);
PPC_FUNC_IMPL(__imp__sub_822D2D18) {
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
	// addi r10,r11,-16604
	ctx.r10.s64 = r11.s64 + -16604;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x822D2D44;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d2d5c
	if (cr6.eq) goto loc_822D2D5C;
	// bl 0x82130588
	ctx.lr = 0x822D2D58;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D2D5C:
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

__attribute__((alias("__imp__sub_822D2D74"))) PPC_WEAK_FUNC(sub_822D2D74);
PPC_FUNC_IMPL(__imp__sub_822D2D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2D78"))) PPC_WEAK_FUNC(sub_822D2D78);
PPC_FUNC_IMPL(__imp__sub_822D2D78) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r11,-27436(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -27436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d2de0
	if (!cr6.eq) goto loc_822D2DE0;
	// li r3,104
	ctx.r3.s64 = 104;
	// bl 0x82130528
	ctx.lr = 0x822D2DA0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d2dc4
	if (cr6.eq) goto loc_822D2DC4;
	// bl 0x823d4368
	ctx.lr = 0x822D2DAC;
	sub_823D4368(ctx, base);
	// stw r3,-27436(r31)
	PPC_STORE_U32(r31.u32 + -27436, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D2DC4:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,-27436(r31)
	PPC_STORE_U32(r31.u32 + -27436, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D2DE0:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r3,-27436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -27436);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D2E04"))) PPC_WEAK_FUNC(sub_822D2E04);
PPC_FUNC_IMPL(__imp__sub_822D2E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2E08"))) PPC_WEAK_FUNC(sub_822D2E08);
PPC_FUNC_IMPL(__imp__sub_822D2E08) {
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
	// addi r9,r11,-16064
	ctx.r9.s64 = r11.s64 + -16064;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822d2e3c
	if (cr6.eq) goto loc_822D2E3C;
	// bl 0x82130588
	ctx.lr = 0x822D2E38;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D2E3C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D2E50"))) PPC_WEAK_FUNC(sub_822D2E50);
PPC_FUNC_IMPL(__imp__sub_822D2E50) {
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
	ctx.lr = 0x822D2E58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-10000(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// bl 0x823c61d0
	ctx.lr = 0x822D2E68;
	sub_823C61D0(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r3,-27432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -27432);
	// bl 0x823d6550
	ctx.lr = 0x822D2E74;
	sub_823D6550(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-4960(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4960);
	// bl 0x823cba60
	ctx.lr = 0x822D2E80;
	sub_823CBA60(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,-10008(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10008);
	// bl 0x823ce8f0
	ctx.lr = 0x822D2E8C;
	sub_823CE8F0(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r11,-27436(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27436);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r3,-27436(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27436);
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x822d2ec4
	if (!cr6.eq) goto loc_822D2EC4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2EC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D2EC4:
	// lwz r3,-27432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -27432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d2ee4
	if (cr6.eq) goto loc_822D2EE4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2EE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D2EE4:
	// lwz r3,-4960(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4960);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-27432(r30)
	PPC_STORE_U32(r30.u32 + -27432, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d2f0c
	if (cr6.eq) goto loc_822D2F0C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D2F0C:
	// lwz r3,-10008(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10008);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-4960(r31)
	PPC_STORE_U32(r31.u32 + -4960, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d2f34
	if (cr6.eq) goto loc_822D2F34;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2F34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D2F34:
	// lwz r3,-10000(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10008(r29)
	PPC_STORE_U32(r29.u32 + -10008, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d2f5c
	if (cr6.eq) goto loc_822D2F5C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2F5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D2F5C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10000(r28)
	PPC_STORE_U32(r28.u32 + -10000, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D2F6C"))) PPC_WEAK_FUNC(sub_822D2F6C);
PPC_FUNC_IMPL(__imp__sub_822D2F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2F70"))) PPC_WEAK_FUNC(sub_822D2F70);
PPC_FUNC_IMPL(__imp__sub_822D2F70) {
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
	// li r31,0
	r31.s64 = 0;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r11,r31
	r11.u64 = r31.u64;
	// stb r31,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r31.u8);
	// stb r31,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r31.u8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stb r11,-27440(r10)
	PPC_STORE_U8(ctx.r10.u32 + -27440, r11.u8);
	// lwz r3,-10000(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// bl 0x823c3620
	ctx.lr = 0x822D2FA8;
	sub_823C3620(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lwz r3,-27432(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27432);
	// bl 0x82130000
	ctx.lr = 0x822D2FB4;
	sub_82130000(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-10008(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10008);
	// bl 0x823ce958
	ctx.lr = 0x822D2FC0;
	sub_823CE958(ctx, base);
	// lwz r11,-10008(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10008);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
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

__attribute__((alias("__imp__sub_822D2FE0"))) PPC_WEAK_FUNC(sub_822D2FE0);
PPC_FUNC_IMPL(__imp__sub_822D2FE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// b 0x823bd200
	sub_823BD200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D2FEC"))) PPC_WEAK_FUNC(sub_822D2FEC);
PPC_FUNC_IMPL(__imp__sub_822D2FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D2FF0"))) PPC_WEAK_FUNC(sub_822D2FF0);
PPC_FUNC_IMPL(__imp__sub_822D2FF0) {
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
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// bl 0x823d3278
	ctx.lr = 0x822D3008;
	sub_823D3278(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r3,-27436(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27436);
	// bl 0x823d41e8
	ctx.lr = 0x822D3014;
	sub_823D41E8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r3,-10000(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// bl 0x823c6538
	ctx.lr = 0x822D3020;
	sub_823C6538(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D3030"))) PPC_WEAK_FUNC(sub_822D3030);
PPC_FUNC_IMPL(__imp__sub_822D3030) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822D3038;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bge cr6,0x822d3068
	if (!cr6.lt) goto loc_822D3068;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x822d3090
	goto loc_822D3090;
loc_822D3068:
	// lwz r3,-10000(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// bl 0x823bb408
	ctx.lr = 0x822D3070;
	sub_823BB408(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d308c
	if (cr6.eq) goto loc_822D308C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,100(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	f0.f64 = double(temp.f32);
	// b 0x822d3090
	goto loc_822D3090;
loc_822D308C:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_822D3090:
	// fneg f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// li r10,1
	ctx.r10.s64 = 1;
	// fsel f31,f13,f30,f0
	f31.f64 = ctx.f13.f64 >= 0.0 ? f30.f64 : f0.f64;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bgt cr6,0x822d30a8
	if (cr6.gt) goto loc_822D30A8;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822D30A8:
	// lbz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// addi r11,r31,20
	r11.s64 = r31.s64 + 20;
	// stb r10,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r10.u8);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r9,21(r31)
	PPC_STORE_U8(r31.u32 + 21, ctx.r9.u8);
	// beq cr6,0x822d30d4
	if (cr6.eq) goto loc_822D30D4;
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822d30d8
	if (cr6.eq) goto loc_822D30D8;
loc_822D30D4:
	// li r11,0
	r11.s64 = 0;
loc_822D30D8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d30f4
	if (!cr6.eq) goto loc_822D30F4;
	// lbz r11,-27440(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -27440);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d3144
	if (cr6.eq) goto loc_822D3144;
loc_822D30F4:
	// li r11,0
	r11.s64 = 0;
	// li r31,76
	r31.s64 = 76;
	// stb r11,-27440(r30)
	PPC_STORE_U8(r30.u32 + -27440, r11.u8);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r11,-13240
	r29.s64 = r11.s64 + -13240;
loc_822D3108:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x822D3110;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 312);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D3120;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d313c
	if (!cr6.eq) goto loc_822D313C;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,105
	cr6.compare<int32_t>(r31.s32, 105, xer);
	// blt cr6,0x822d3108
	if (cr6.lt) goto loc_822D3108;
	// b 0x822d3144
	goto loc_822D3144;
loc_822D313C:
	// li r11,1
	r11.s64 = 1;
	// stb r11,-27440(r30)
	PPC_STORE_U8(r30.u32 + -27440, r11.u8);
loc_822D3144:
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r11,-12640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d3168
	if (cr6.eq) goto loc_822D3168;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822d316c
	if (cr6.eq) goto loc_822D316C;
loc_822D3168:
	// li r11,0
	r11.s64 = 0;
loc_822D316C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d31b4
	if (cr6.eq) goto loc_822D31B4;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// li r9,1
	ctx.r9.s64 = 1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// stb r9,320(r11)
	PPC_STORE_U8(r11.u32 + 320, ctx.r9.u8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823c9848
	ctx.lr = 0x822D31A4;
	sub_823C9848(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_822D31B4:
	// lwz r3,-10000(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// bl 0x823beeb0
	ctx.lr = 0x822D31BC;
	sub_823BEEB0(ctx, base);
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// addi r11,r11,308
	r11.s64 = r11.s64 + 308;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// ble cr6,0x822d31fc
	if (!cr6.gt) goto loc_822D31FC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x822d31f0
	if (cr6.eq) goto loc_822D31F0;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// b 0x822d31fc
	goto loc_822D31FC;
loc_822D31F0:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x822d31fc
	if (!cr6.gt) goto loc_822D31FC;
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
loc_822D31FC:
	// lwz r3,-10000(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823bbaf8
	ctx.lr = 0x822D3208;
	sub_823BBAF8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cebd8
	ctx.lr = 0x822D3218;
	sub_823CEBD8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-4960(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4960);
	// bl 0x823c9848
	ctx.lr = 0x822D3224;
	sub_823C9848(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r3,-27432(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27432);
	// bl 0x823d6100
	ctx.lr = 0x822D3234;
	sub_823D6100(ctx, base);
	// lwz r3,-10000(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// bl 0x823bb4d8
	ctx.lr = 0x822D323C;
	sub_823BB4D8(ctx, base);
	// lwz r11,-12640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d325c
	if (cr6.eq) goto loc_822D325C;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822d3260
	if (cr6.eq) goto loc_822D3260;
loc_822D325C:
	// li r11,0
	r11.s64 = 0;
loc_822D3260:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d3278
	if (!cr6.eq) goto loc_822D3278;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,320(r11)
	PPC_STORE_U8(r11.u32 + 320, ctx.r10.u8);
loc_822D3278:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D3288"))) PPC_WEAK_FUNC(sub_822D3288);
PPC_FUNC_IMPL(__imp__sub_822D3288) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822D32A0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d32d8
	if (cr6.eq) goto loc_822D32D8;
	// bl 0x823cc178
	ctx.lr = 0x822D32B0;
	sub_823CC178(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-16056
	ctx.r9.s64 = r11.s64 + -16056;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-10008(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10008, r31.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D32D8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10008(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10008, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D32F8"))) PPC_WEAK_FUNC(sub_822D32F8);
PPC_FUNC_IMPL(__imp__sub_822D32F8) {
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
	ctx.lr = 0x822D3300;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r31,6(r3)
	r31.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d333c
	if (cr6.eq) goto loc_822D333C;
	// lwz r29,0(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822d3334
	if (!cr6.gt) goto loc_822D3334;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_822D3320:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D3328;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x822d3320
	if (!cr0.eq) goto loc_822D3320;
loc_822D3334:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x822D333C;
	sub_82130588(ctx, base);
loc_822D333C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822D3344"))) PPC_WEAK_FUNC(sub_822D3344);
PPC_FUNC_IMPL(__imp__sub_822D3344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3348"))) PPC_WEAK_FUNC(sub_822D3348);
PPC_FUNC_IMPL(__imp__sub_822D3348) {
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
	// addi r10,r11,-16048
	ctx.r10.s64 = r11.s64 + -16048;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,10(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d3384
	if (cr6.eq) goto loc_822D3384;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x822D3384;
	sub_82130588(ctx, base);
loc_822D3384:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d339c
	if (cr6.eq) goto loc_822D339C;
	// bl 0x82130588
	ctx.lr = 0x822D3398;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D339C:
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

__attribute__((alias("__imp__sub_822D33B4"))) PPC_WEAK_FUNC(sub_822D33B4);
PPC_FUNC_IMPL(__imp__sub_822D33B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D33B8"))) PPC_WEAK_FUNC(sub_822D33B8);
PPC_FUNC_IMPL(__imp__sub_822D33B8) {
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
	ctx.lr = 0x822D33C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// beq cr6,0x822d342c
	if (cr6.eq) goto loc_822D342C;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_822D33E0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d3418
	if (cr6.eq) goto loc_822D3418;
loc_822D33F0:
	// mr r26,r31
	r26.u64 = r31.u64;
	// lwz r31,16(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,8(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x822D3400;
	sub_82130588(ctx, base);
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D3408;
	sub_82130588(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x822D3410;
	sub_82130588(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822d33f0
	if (!cr6.eq) goto loc_822D33F0;
loc_822D3418:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x822d33e0
	if (cr6.lt) goto loc_822D33E0;
loc_822D342C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D3434;
	sub_82130588(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822D3448"))) PPC_WEAK_FUNC(sub_822D3448);
PPC_FUNC_IMPL(__imp__sub_822D3448) {
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
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x822D3460;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d3498
	if (cr6.eq) goto loc_822D3498;
	// bl 0x823d5710
	ctx.lr = 0x822D3470;
	sub_823D5710(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-16040
	ctx.r9.s64 = r11.s64 + -16040;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-27432(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27432, r31.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D3498:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-27432(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27432, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D34B8"))) PPC_WEAK_FUNC(sub_822D34B8);
PPC_FUNC_IMPL(__imp__sub_822D34B8) {
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
	ctx.lr = 0x822D34C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-16032
	ctx.r10.s64 = r11.s64 + -16032;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r30,218(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 218);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d350c
	if (cr6.eq) goto loc_822D350C;
	// lwz r28,212(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822d3504
	if (!cr6.gt) goto loc_822D3504;
	// addi r29,r28,56
	r29.s64 = r28.s64 + 56;
loc_822D34F0:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D34F8;
	sub_82130588(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,64
	r29.s64 = r29.s64 + 64;
	// bne 0x822d34f0
	if (!cr0.eq) goto loc_822D34F0;
loc_822D3504:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x822D350C;
	sub_82130588(ctx, base);
loc_822D350C:
	// addi r3,r31,200
	ctx.r3.s64 = r31.s64 + 200;
	// bl 0x822d33b8
	ctx.lr = 0x822D3514;
	sub_822D33B8(ctx, base);
	// addi r3,r31,188
	ctx.r3.s64 = r31.s64 + 188;
	// bl 0x822d33b8
	ctx.lr = 0x822D351C;
	sub_822D33B8(ctx, base);
	// addi r3,r31,176
	ctx.r3.s64 = r31.s64 + 176;
	// bl 0x822d33b8
	ctx.lr = 0x822D3524;
	sub_822D33B8(ctx, base);
	// addi r3,r31,164
	ctx.r3.s64 = r31.s64 + 164;
	// bl 0x822d33b8
	ctx.lr = 0x822D352C;
	sub_822D33B8(ctx, base);
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// bl 0x822d33b8
	ctx.lr = 0x822D3534;
	sub_822D33B8(ctx, base);
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// bl 0x822d33b8
	ctx.lr = 0x822D353C;
	sub_822D33B8(ctx, base);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x822d33b8
	ctx.lr = 0x822D3544;
	sub_822D33B8(ctx, base);
	// addi r3,r31,116
	ctx.r3.s64 = r31.s64 + 116;
	// bl 0x822d33b8
	ctx.lr = 0x822D354C;
	sub_822D33B8(ctx, base);
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// bl 0x822d33b8
	ctx.lr = 0x822D3554;
	sub_822D33B8(ctx, base);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x822d33b8
	ctx.lr = 0x822D355C;
	sub_822D33B8(ctx, base);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x822d33b8
	ctx.lr = 0x822D3564;
	sub_822D33B8(ctx, base);
	// addi r3,r31,68
	ctx.r3.s64 = r31.s64 + 68;
	// bl 0x822d33b8
	ctx.lr = 0x822D356C;
	sub_822D33B8(ctx, base);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// bl 0x82138a18
	ctx.lr = 0x822D3574;
	sub_82138A18(ctx, base);
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x82138a18
	ctx.lr = 0x822D357C;
	sub_82138A18(ctx, base);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82138a18
	ctx.lr = 0x822D3584;
	sub_82138A18(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82138a18
	ctx.lr = 0x822D358C;
	sub_82138A18(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82138a18
	ctx.lr = 0x822D3594;
	sub_82138A18(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D359C"))) PPC_WEAK_FUNC(sub_822D359C);
PPC_FUNC_IMPL(__imp__sub_822D359C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D35A0"))) PPC_WEAK_FUNC(sub_822D35A0);
PPC_FUNC_IMPL(__imp__sub_822D35A0) {
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
	// bl 0x822d34b8
	ctx.lr = 0x822D35C0;
	sub_822D34B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d35d8
	if (cr6.eq) goto loc_822D35D8;
	// bl 0x82130588
	ctx.lr = 0x822D35D4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D35D8:
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

__attribute__((alias("__imp__sub_822D35F0"))) PPC_WEAK_FUNC(sub_822D35F0);
PPC_FUNC_IMPL(__imp__sub_822D35F0) {
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
	// addi r10,r11,-16024
	ctx.r10.s64 = r11.s64 + -16024;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822d34b8
	ctx.lr = 0x822D361C;
	sub_822D34B8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d3634
	if (cr6.eq) goto loc_822D3634;
	// bl 0x82130588
	ctx.lr = 0x822D3630;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D3634:
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

__attribute__((alias("__imp__sub_822D364C"))) PPC_WEAK_FUNC(sub_822D364C);
PPC_FUNC_IMPL(__imp__sub_822D364C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3650"))) PPC_WEAK_FUNC(sub_822D3650);
PPC_FUNC_IMPL(__imp__sub_822D3650) {
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
	ctx.lr = 0x822D3658;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x822d36c8
	if (!cr6.gt) goto loc_822D36C8;
	// addi r29,r26,6
	r29.s64 = r26.s64 + 6;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
loc_822D3670:
	// lhz r11,12(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d3684
	if (cr6.eq) goto loc_822D3684;
	// lwz r3,6(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 6);
	// bl 0x82130588
	ctx.lr = 0x822D3684;
	sub_82130588(ctx, base);
loc_822D3684:
	// lhz r31,0(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d36bc
	if (cr6.eq) goto loc_822D36BC;
	// lwz r28,-6(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + -6);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822d36b4
	if (!cr6.gt) goto loc_822D36B4;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_822D36A0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D36A8;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x822d36a0
	if (!cr0.eq) goto loc_822D36A0;
loc_822D36B4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x822D36BC;
	sub_82130588(ctx, base);
loc_822D36BC:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,20
	r29.s64 = r29.s64 + 20;
	// bne 0x822d3670
	if (!cr0.eq) goto loc_822D3670;
loc_822D36C8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x822D36D0;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822D36D8"))) PPC_WEAK_FUNC(sub_822D36D8);
PPC_FUNC_IMPL(__imp__sub_822D36D8) {
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
	// li r3,252
	ctx.r3.s64 = 252;
	// bl 0x82130528
	ctx.lr = 0x822D36F0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d3728
	if (cr6.eq) goto loc_822D3728;
	// bl 0x823cb7e0
	ctx.lr = 0x822D3700;
	sub_823CB7E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-16024
	ctx.r9.s64 = r11.s64 + -16024;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-4960(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4960, r31.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D3728:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-4960(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4960, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D3748"))) PPC_WEAK_FUNC(sub_822D3748);
PPC_FUNC_IMPL(__imp__sub_822D3748) {
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
	ctx.lr = 0x822D3750;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r29,20
	ctx.r3.s64 = r29.s64 + 20;
	// addi r10,r11,-16016
	ctx.r10.s64 = r11.s64 + -16016;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lhz r5,26(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 26);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822d377c
	if (cr6.eq) goto loc_822D377C;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x822d3650
	ctx.lr = 0x822D377C;
	sub_822D3650(ctx, base);
loc_822D377C:
	// lhz r31,18(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 18);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d37b4
	if (cr6.eq) goto loc_822D37B4;
	// lwz r28,12(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822d37ac
	if (!cr6.gt) goto loc_822D37AC;
	// addi r30,r28,4
	r30.s64 = r28.s64 + 4;
loc_822D3798:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D37A0;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// bne 0x822d3798
	if (!cr0.eq) goto loc_822D3798;
loc_822D37AC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x822D37B4;
	sub_82130588(ctx, base);
loc_822D37B4:
	// lhz r11,10(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d37c8
	if (cr6.eq) goto loc_822D37C8;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x822D37C8;
	sub_82130588(ctx, base);
loc_822D37C8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D37D0"))) PPC_WEAK_FUNC(sub_822D37D0);
PPC_FUNC_IMPL(__imp__sub_822D37D0) {
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
	// bl 0x822d3748
	ctx.lr = 0x822D37F0;
	sub_822D3748(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d3808
	if (cr6.eq) goto loc_822D3808;
	// bl 0x82130588
	ctx.lr = 0x822D3804;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D3808:
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

__attribute__((alias("__imp__sub_822D3820"))) PPC_WEAK_FUNC(sub_822D3820);
PPC_FUNC_IMPL(__imp__sub_822D3820) {
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
	// addi r3,r31,3952
	ctx.r3.s64 = r31.s64 + 3952;
	// addi r10,r11,-16008
	ctx.r10.s64 = r11.s64 + -16008;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823bfdb0
	ctx.lr = 0x822D3850;
	sub_823BFDB0(ctx, base);
	// addi r3,r31,3908
	ctx.r3.s64 = r31.s64 + 3908;
	// bl 0x822d3748
	ctx.lr = 0x822D3858;
	sub_822D3748(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,-21868
	ctx.r7.s64 = ctx.r9.s64 + -21868;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x822d387c
	if (cr6.eq) goto loc_822D387C;
	// bl 0x82130588
	ctx.lr = 0x822D3878;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D387C:
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

__attribute__((alias("__imp__sub_822D3894"))) PPC_WEAK_FUNC(sub_822D3894);
PPC_FUNC_IMPL(__imp__sub_822D3894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3898"))) PPC_WEAK_FUNC(sub_822D3898);
PPC_FUNC_IMPL(__imp__sub_822D3898) {
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
	// li r3,4048
	ctx.r3.s64 = 4048;
	// bl 0x82130528
	ctx.lr = 0x822D38B0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d38e8
	if (cr6.eq) goto loc_822D38E8;
	// bl 0x823c7b18
	ctx.lr = 0x822D38C0;
	sub_823C7B18(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-15996
	ctx.r9.s64 = r11.s64 + -15996;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-10000(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10000, r31.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D38E8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10000(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10000, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D3908"))) PPC_WEAK_FUNC(sub_822D3908);
PPC_FUNC_IMPL(__imp__sub_822D3908) {
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
	// bl 0x822d3898
	ctx.lr = 0x822D3918;
	sub_822D3898(ctx, base);
	// bl 0x822d3288
	ctx.lr = 0x822D391C;
	sub_822D3288(ctx, base);
	// bl 0x822d36d8
	ctx.lr = 0x822D3920;
	sub_822D36D8(ctx, base);
	// bl 0x822d3448
	ctx.lr = 0x822D3924;
	sub_822D3448(ctx, base);
	// bl 0x822d2d78
	ctx.lr = 0x822D3928;
	sub_822D2D78(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823ce810
	ctx.lr = 0x822D3934;
	sub_823CE810(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-4960(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4960);
	// bl 0x823cc070
	ctx.lr = 0x822D3940;
	sub_823CC070(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r3,-27432(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27432);
	// bl 0x823d68f0
	ctx.lr = 0x822D394C;
	sub_823D68F0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,-10000(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10000);
	// bl 0x823c8218
	ctx.lr = 0x822D3958;
	sub_823C8218(ctx, base);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lwz r3,-27436(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27436);
	// bl 0x823d4058
	ctx.lr = 0x822D3964;
	sub_823D4058(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D3974"))) PPC_WEAK_FUNC(sub_822D3974);
PPC_FUNC_IMPL(__imp__sub_822D3974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3978"))) PPC_WEAK_FUNC(sub_822D3978);
PPC_FUNC_IMPL(__imp__sub_822D3978) {
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
	// bl 0x822d2d00
	ctx.lr = 0x822D3990;
	sub_822D2D00(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-15680
	ctx.r9.s64 = r11.s64 + -15680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D39BC"))) PPC_WEAK_FUNC(sub_822D39BC);
PPC_FUNC_IMPL(__imp__sub_822D39BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D39C0"))) PPC_WEAK_FUNC(sub_822D39C0);
PPC_FUNC_IMPL(__imp__sub_822D39C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-15632
	ctx.r3.s64 = r11.s64 + -15632;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D39CC"))) PPC_WEAK_FUNC(sub_822D39CC);
PPC_FUNC_IMPL(__imp__sub_822D39CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D39D0"))) PPC_WEAK_FUNC(sub_822D39D0);
PPC_FUNC_IMPL(__imp__sub_822D39D0) {
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
	// addi r10,r11,-13092
	ctx.r10.s64 = r11.s64 + -13092;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d3a24
	if (!cr6.eq) goto loc_822D3A24;
	// bl 0x822c4eb8
	ctx.lr = 0x822D3A00;
	sub_822C4EB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822c4ec8
	ctx.lr = 0x822D3A0C;
	sub_822C4EC8(ctx, base);
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821d2a58
	ctx.lr = 0x822D3A18;
	sub_821D2A58(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822c54d8
	ctx.lr = 0x822D3A24;
	sub_822C54D8(ctx, base);
loc_822D3A24:
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

__attribute__((alias("__imp__sub_822D3A3C"))) PPC_WEAK_FUNC(sub_822D3A3C);
PPC_FUNC_IMPL(__imp__sub_822D3A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3A40"))) PPC_WEAK_FUNC(sub_822D3A40);
PPC_FUNC_IMPL(__imp__sub_822D3A40) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-13092
	ctx.r10.s64 = r11.s64 + -13092;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d3abc
	if (!cr6.eq) goto loc_822D3ABC;
	// bl 0x822c4eb8
	ctx.lr = 0x822D3A6C;
	sub_822C4EB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822c4ec8
	ctx.lr = 0x822D3A78;
	sub_822C4EC8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822c4ed8
	ctx.lr = 0x822D3A88;
	sub_822C4ED8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822c4ec8
	ctx.lr = 0x822D3A94;
	sub_822C4EC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D3AA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822c4f20
	ctx.lr = 0x822D3AB0;
	sub_822C4F20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x821d2a58
	ctx.lr = 0x822D3ABC;
	sub_821D2A58(ctx, base);
loc_822D3ABC:
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

__attribute__((alias("__imp__sub_822D3AD4"))) PPC_WEAK_FUNC(sub_822D3AD4);
PPC_FUNC_IMPL(__imp__sub_822D3AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3AD8"))) PPC_WEAK_FUNC(sub_822D3AD8);
PPC_FUNC_IMPL(__imp__sub_822D3AD8) {
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
	// addi r10,r11,-15616
	ctx.r10.s64 = r11.s64 + -15616;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826d92e8
	ctx.lr = 0x822D3B04;
	sub_826D92E8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d3b1c
	if (cr6.eq) goto loc_822D3B1C;
	// bl 0x82130588
	ctx.lr = 0x822D3B18;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D3B1C:
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

__attribute__((alias("__imp__sub_822D3B34"))) PPC_WEAK_FUNC(sub_822D3B34);
PPC_FUNC_IMPL(__imp__sub_822D3B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3B38"))) PPC_WEAK_FUNC(sub_822D3B38);
PPC_FUNC_IMPL(__imp__sub_822D3B38) {
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
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// addi r10,r11,-15680
	ctx.r10.s64 = r11.s64 + -15680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x822D3B68;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d2bb8
	ctx.lr = 0x822D3B70;
	sub_822D2BB8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d3b88
	if (cr6.eq) goto loc_822D3B88;
	// bl 0x82130588
	ctx.lr = 0x822D3B84;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D3B88:
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

__attribute__((alias("__imp__sub_822D3BA0"))) PPC_WEAK_FUNC(sub_822D3BA0);
PPC_FUNC_IMPL(__imp__sub_822D3BA0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-10012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d3bfc
	if (cr6.eq) goto loc_822D3BFC;
	// bl 0x826d8b48
	ctx.lr = 0x822D3BC4;
	sub_826D8B48(ctx, base);
	// lwz r3,-10012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// bl 0x826d8868
	ctx.lr = 0x822D3BCC;
	sub_826D8868(ctx, base);
	// lwz r3,-10012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// bl 0x826d4ba0
	ctx.lr = 0x822D3BD4;
	sub_826D4BA0(ctx, base);
	// lwz r3,-10012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d3bf4
	if (cr6.eq) goto loc_822D3BF4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D3BF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D3BF4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10012(r31)
	PPC_STORE_U32(r31.u32 + -10012, r11.u32);
loc_822D3BFC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D3C10"))) PPC_WEAK_FUNC(sub_822D3C10);
PPC_FUNC_IMPL(__imp__sub_822D3C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// b 0x826d8b48
	sub_826D8B48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D3C1C"))) PPC_WEAK_FUNC(sub_822D3C1C);
PPC_FUNC_IMPL(__imp__sub_822D3C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3C20"))) PPC_WEAK_FUNC(sub_822D3C20);
PPC_FUNC_IMPL(__imp__sub_822D3C20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d3cc0
	if (cr6.eq) goto loc_822D3CC0;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d3c68
	if (cr6.eq) goto loc_822D3C68;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822d3c84
	if (!cr6.gt) goto loc_822D3C84;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x822d3c78
	goto loc_822D3C78;
loc_822D3C68:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822d3c84
	if (!cr6.gt) goto loc_822D3C84;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_822D3C78:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d3c88
	if (!cr6.eq) goto loc_822D3C88;
loc_822D3C84:
	// li r11,0
	r11.s64 = 0;
loc_822D3C88:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d3cc0
	if (cr6.eq) goto loc_822D3CC0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x822D3C9C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d3cc0
	if (cr6.eq) goto loc_822D3CC0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822D3CB4;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822D3CC0;
	sub_822A3998(ctx, base);
loc_822D3CC0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r9,2256
	ctx.r7.s64 = ctx.r9.s64 + 2256;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// addi r6,r8,-31600
	ctx.r6.s64 = ctx.r8.s64 + -31600;
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// addi r5,r11,45
	ctx.r5.s64 = r11.s64 + 45;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r4,r4,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x822d3d14
	if (cr6.eq) goto loc_822D3D14;
	// li r11,96
	r11.s64 = 96;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r10,112
	ctx.r10.s64 = 112;
	// lvx128 v62,r4,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r4,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v2,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
loc_822D3D14:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// bl 0x826d75d8
	ctx.lr = 0x822D3D20;
	sub_826D75D8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D3D34"))) PPC_WEAK_FUNC(sub_822D3D34);
PPC_FUNC_IMPL(__imp__sub_822D3D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3D38"))) PPC_WEAK_FUNC(sub_822D3D38);
PPC_FUNC_IMPL(__imp__sub_822D3D38) {
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
	// lis r3,6
	ctx.r3.s64 = 393216;
	// ori r3,r3,17616
	ctx.r3.u64 = ctx.r3.u64 | 17616;
	// bl 0x82130528
	ctx.lr = 0x822D3D54;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d3d8c
	if (cr6.eq) goto loc_822D3D8C;
	// bl 0x826d8e70
	ctx.lr = 0x822D3D64;
	sub_826D8E70(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-15616
	ctx.r9.s64 = r11.s64 + -15616;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-10012(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10012, r31.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D3D8C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10012(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10012, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D3DAC"))) PPC_WEAK_FUNC(sub_822D3DAC);
PPC_FUNC_IMPL(__imp__sub_822D3DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3DB0"))) PPC_WEAK_FUNC(sub_822D3DB0);
PPC_FUNC_IMPL(__imp__sub_822D3DB0) {
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
	// bl 0x822d3d38
	ctx.lr = 0x822D3DCC;
	sub_822D3D38(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10012(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10012);
	// bl 0x826d89f0
	ctx.lr = 0x822D3DE4;
	sub_826D89F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,-10012(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10012);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x826d81b0
	ctx.lr = 0x822D3DF4;
	sub_826D81B0(ctx, base);
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

__attribute__((alias("__imp__sub_822D3E0C"))) PPC_WEAK_FUNC(sub_822D3E0C);
PPC_FUNC_IMPL(__imp__sub_822D3E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3E10"))) PPC_WEAK_FUNC(sub_822D3E10);
PPC_FUNC_IMPL(__imp__sub_822D3E10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20376(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20376);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D3E1C"))) PPC_WEAK_FUNC(sub_822D3E1C);
PPC_FUNC_IMPL(__imp__sub_822D3E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3E20"))) PPC_WEAK_FUNC(sub_822D3E20);
PPC_FUNC_IMPL(__imp__sub_822D3E20) {
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
	// bl 0x822d2d00
	ctx.lr = 0x822D3E38;
	sub_822D2D00(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-15244
	ctx.r9.s64 = r11.s64 + -15244;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D3E64"))) PPC_WEAK_FUNC(sub_822D3E64);
PPC_FUNC_IMPL(__imp__sub_822D3E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3E68"))) PPC_WEAK_FUNC(sub_822D3E68);
PPC_FUNC_IMPL(__imp__sub_822D3E68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-15196
	ctx.r3.s64 = r11.s64 + -15196;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D3E74"))) PPC_WEAK_FUNC(sub_822D3E74);
PPC_FUNC_IMPL(__imp__sub_822D3E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3E78"))) PPC_WEAK_FUNC(sub_822D3E78);
PPC_FUNC_IMPL(__imp__sub_822D3E78) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// b 0x827277a0
	sub_827277A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D3E80"))) PPC_WEAK_FUNC(sub_822D3E80);
PPC_FUNC_IMPL(__imp__sub_822D3E80) {
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
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x822D3E98;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d3ed4
	if (cr6.eq) goto loc_822D3ED4;
	// bl 0x824905e0
	ctx.lr = 0x822D3EA8;
	sub_824905E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r11,-15264
	ctx.r9.s64 = r11.s64 + -15264;
	// stb r10,22(r31)
	PPC_STORE_U8(r31.u32 + 22, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D3ED4:
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

__attribute__((alias("__imp__sub_822D3EEC"))) PPC_WEAK_FUNC(sub_822D3EEC);
PPC_FUNC_IMPL(__imp__sub_822D3EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3EF0"))) PPC_WEAK_FUNC(sub_822D3EF0);
PPC_FUNC_IMPL(__imp__sub_822D3EF0) {
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
	// beq cr6,0x822d3f1c
	if (cr6.eq) goto loc_822D3F1C;
	// bl 0x824905e0
	ctx.lr = 0x822D3F10;
	sub_824905E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-15264
	ctx.r10.s64 = r11.s64 + -15264;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_822D3F1C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D3F30"))) PPC_WEAK_FUNC(sub_822D3F30);
PPC_FUNC_IMPL(__imp__sub_822D3F30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822D3F3C"))) PPC_WEAK_FUNC(sub_822D3F3C);
PPC_FUNC_IMPL(__imp__sub_822D3F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D3F40"))) PPC_WEAK_FUNC(sub_822D3F40);
PPC_FUNC_IMPL(__imp__sub_822D3F40) {
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
	// bl 0x824905e0
	ctx.lr = 0x822D3F58;
	sub_824905E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-15184
	ctx.r9.s64 = r11.s64 + -15184;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// addi r11,r31,56
	r11.s64 = r31.s64 + 56;
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stb r8,22(r31)
	PPC_STORE_U8(r31.u32 + 22, ctx.r8.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D3FB0"))) PPC_WEAK_FUNC(sub_822D3FB0);
PPC_FUNC_IMPL(__imp__sub_822D3FB0) {
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
	// bl 0x824905e0
	ctx.lr = 0x822D3FC8;
	sub_824905E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-15184
	ctx.r8.s64 = r11.s64 + -15184;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r11,r31,56
	r11.s64 = r31.s64 + 56;
	// stw r10,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r10,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r10.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D4018"))) PPC_WEAK_FUNC(sub_822D4018);
PPC_FUNC_IMPL(__imp__sub_822D4018) {
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
	// bl 0x824905e0
	ctx.lr = 0x822D4030;
	sub_824905E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-15164
	ctx.r9.s64 = r11.s64 + -15164;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stb r8,22(r31)
	PPC_STORE_U8(r31.u32 + 22, ctx.r8.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D4088"))) PPC_WEAK_FUNC(sub_822D4088);
PPC_FUNC_IMPL(__imp__sub_822D4088) {
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
	// bl 0x824905e0
	ctx.lr = 0x822D40A0;
	sub_824905E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-15164
	ctx.r8.s64 = r11.s64 + -15164;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D40F0"))) PPC_WEAK_FUNC(sub_822D40F0);
PPC_FUNC_IMPL(__imp__sub_822D40F0) {
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
	// bl 0x824905e0
	ctx.lr = 0x822D4108;
	sub_824905E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-15144
	ctx.r8.s64 = r11.s64 + -15144;
	// li r11,0
	r11.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r10,r31,40
	ctx.r10.s64 = r31.s64 + 40;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stb r11,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r11.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D415C"))) PPC_WEAK_FUNC(sub_822D415C);
PPC_FUNC_IMPL(__imp__sub_822D415C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4160"))) PPC_WEAK_FUNC(sub_822D4160);
PPC_FUNC_IMPL(__imp__sub_822D4160) {
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
	// bl 0x824905e0
	ctx.lr = 0x822D4178;
	sub_824905E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-15144
	ctx.r8.s64 = r11.s64 + -15144;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r10,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r10.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D41C8"))) PPC_WEAK_FUNC(sub_822D41C8);
PPC_FUNC_IMPL(__imp__sub_822D41C8) {
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
	// addi r10,r11,-15244
	ctx.r10.s64 = r11.s64 + -15244;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822d2bb8
	ctx.lr = 0x822D41F4;
	sub_822D2BB8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d420c
	if (cr6.eq) goto loc_822D420C;
	// bl 0x82130588
	ctx.lr = 0x822D4208;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D420C:
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

__attribute__((alias("__imp__sub_822D4224"))) PPC_WEAK_FUNC(sub_822D4224);
PPC_FUNC_IMPL(__imp__sub_822D4224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4228"))) PPC_WEAK_FUNC(sub_822D4228);
PPC_FUNC_IMPL(__imp__sub_822D4228) {
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
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x822D423C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4258
	if (cr6.eq) goto loc_822D4258;
	// bl 0x822d3f40
	ctx.lr = 0x822D4248;
	sub_822D3F40(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822D4258:
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

__attribute__((alias("__imp__sub_822D426C"))) PPC_WEAK_FUNC(sub_822D426C);
PPC_FUNC_IMPL(__imp__sub_822D426C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4270"))) PPC_WEAK_FUNC(sub_822D4270);
PPC_FUNC_IMPL(__imp__sub_822D4270) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822d3fb0
	sub_822D3FB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D427C"))) PPC_WEAK_FUNC(sub_822D427C);
PPC_FUNC_IMPL(__imp__sub_822D427C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D4280"))) PPC_WEAK_FUNC(sub_822D4280);
PPC_FUNC_IMPL(__imp__sub_822D4280) {
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
	// li r3,76
	ctx.r3.s64 = 76;
	// bl 0x82130528
	ctx.lr = 0x822D4294;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d42b0
	if (cr6.eq) goto loc_822D42B0;
	// bl 0x822d4018
	ctx.lr = 0x822D42A0;
	sub_822D4018(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822D42B0:
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

__attribute__((alias("__imp__sub_822D42C4"))) PPC_WEAK_FUNC(sub_822D42C4);
PPC_FUNC_IMPL(__imp__sub_822D42C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D42C8"))) PPC_WEAK_FUNC(sub_822D42C8);
PPC_FUNC_IMPL(__imp__sub_822D42C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822d4088
	sub_822D4088(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D42D4"))) PPC_WEAK_FUNC(sub_822D42D4);
PPC_FUNC_IMPL(__imp__sub_822D42D4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D42D8"))) PPC_WEAK_FUNC(sub_822D42D8);
PPC_FUNC_IMPL(__imp__sub_822D42D8) {
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
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x822D42EC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4308
	if (cr6.eq) goto loc_822D4308;
	// bl 0x822d40f0
	ctx.lr = 0x822D42F8;
	sub_822D40F0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822D4308:
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

__attribute__((alias("__imp__sub_822D431C"))) PPC_WEAK_FUNC(sub_822D431C);
PPC_FUNC_IMPL(__imp__sub_822D431C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4320"))) PPC_WEAK_FUNC(sub_822D4320);
PPC_FUNC_IMPL(__imp__sub_822D4320) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822d4160
	sub_822D4160(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D432C"))) PPC_WEAK_FUNC(sub_822D432C);
PPC_FUNC_IMPL(__imp__sub_822D432C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D4330"))) PPC_WEAK_FUNC(sub_822D4330);
PPC_FUNC_IMPL(__imp__sub_822D4330) {
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
	ctx.lr = 0x822D4338;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4364
	if (cr6.eq) goto loc_822D4364;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D4364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D4364:
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r30,-7784(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -7784);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d4384
	if (cr6.eq) goto loc_822D4384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822ebd20
	ctx.lr = 0x822D437C;
	sub_822EBD20(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822D4384;
	sub_82130588(ctx, base);
loc_822D4384:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7784(r31)
	PPC_STORE_U32(r31.u32 + -7784, r11.u32);
	// bl 0x826c2578
	ctx.lr = 0x822D4390;
	sub_826C2578(ctx, base);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r3,-24400(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24400);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d43b4
	if (cr6.eq) goto loc_822D43B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D43B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D43B4:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-24400(r30)
	PPC_STORE_U32(r30.u32 + -24400, r11.u32);
	// lwz r3,-12012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d43e0
	if (cr6.eq) goto loc_822D43E0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D43E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D43E0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12012(r31)
	PPC_STORE_U32(r31.u32 + -12012, r11.u32);
	// bl 0x8272d2d8
	ctx.lr = 0x822D43EC;
	sub_8272D2D8(ctx, base);
	// bl 0x82365218
	ctx.lr = 0x822D43F0;
	sub_82365218(ctx, base);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r3,-10432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4414
	if (cr6.eq) goto loc_822D4414;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D4414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D4414:
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10432(r31)
	PPC_STORE_U32(r31.u32 + -10432, r11.u32);
	// lwz r31,-8256(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -8256);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d443c
	if (cr6.eq) goto loc_822D443C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8236e6a0
	ctx.lr = 0x822D4434;
	sub_8236E6A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822D443C;
	sub_82130588(ctx, base);
loc_822D443C:
	// lis r31,-32119
	r31.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-8256(r30)
	PPC_STORE_U32(r30.u32 + -8256, r11.u32);
	// lwz r30,-8252(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -8252);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d4464
	if (cr6.eq) goto loc_822D4464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82371200
	ctx.lr = 0x822D445C;
	sub_82371200(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822D4464;
	sub_82130588(ctx, base);
loc_822D4464:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-8252(r31)
	PPC_STORE_U32(r31.u32 + -8252, r11.u32);
	// bl 0x8239d968
	ctx.lr = 0x822D4470;
	sub_8239D968(ctx, base);
	// bl 0x821d3278
	ctx.lr = 0x822D4474;
	sub_821D3278(ctx, base);
	// bl 0x821bd520
	ctx.lr = 0x822D4478;
	sub_821BD520(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r30,-9996(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -9996);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d4498
	if (cr6.eq) goto loc_822D4498;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827285d8
	ctx.lr = 0x822D4490;
	sub_827285D8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822D4498;
	sub_82130588(ctx, base);
loc_822D4498:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-9996(r31)
	PPC_STORE_U32(r31.u32 + -9996, r11.u32);
	// lwz r31,20(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d44bc
	if (cr6.eq) goto loc_822D44BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827275c8
	ctx.lr = 0x822D44B4;
	sub_827275C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822D44BC;
	sub_82130588(ctx, base);
loc_822D44BC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// bl 0x8246a7b8
	ctx.lr = 0x822D44C8;
	sub_8246A7B8(ctx, base);
	// bl 0x82469ad8
	ctx.lr = 0x822D44CC;
	sub_82469AD8(ctx, base);
	// bl 0x82507860
	ctx.lr = 0x822D44D0;
	sub_82507860(ctx, base);
	// bl 0x82195a00
	ctx.lr = 0x822D44D4;
	sub_82195A00(ctx, base);
	// bl 0x825032f8
	ctx.lr = 0x822D44D8;
	sub_825032F8(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r31,-27428(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d44f8
	if (cr6.eq) goto loc_822D44F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82490a88
	ctx.lr = 0x822D44F0;
	sub_82490A88(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822D44F8;
	sub_82130588(ctx, base);
loc_822D44F8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-27428(r30)
	PPC_STORE_U32(r30.u32 + -27428, r11.u32);
	// bl 0x8239c920
	ctx.lr = 0x822D4504;
	sub_8239C920(ctx, base);
	// bl 0x821e6a68
	ctx.lr = 0x822D4508;
	sub_821E6A68(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x822D450C;
	sub_82130000(ctx, base);
	// bl 0x82465550
	ctx.lr = 0x822D4510;
	sub_82465550(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822D4518"))) PPC_WEAK_FUNC(sub_822D4518);
PPC_FUNC_IMPL(__imp__sub_822D4518) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,16000
	ctx.r5.s64 = r11.s64 + 16000;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D4548;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,16112
	ctx.r5.s64 = ctx.r5.s64 + 16112;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x822D4598;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D45DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D45F0"))) PPC_WEAK_FUNC(sub_822D45F0);
PPC_FUNC_IMPL(__imp__sub_822D45F0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,16936
	ctx.r5.s64 = r11.s64 + 16936;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D4620;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,17008
	ctx.r5.s64 = ctx.r5.s64 + 17008;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x822D4670;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D46B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D46C8"))) PPC_WEAK_FUNC(sub_822D46C8);
PPC_FUNC_IMPL(__imp__sub_822D46C8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,17024
	ctx.r5.s64 = r11.s64 + 17024;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D46F8;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,17096
	ctx.r5.s64 = ctx.r5.s64 + 17096;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x822D4748;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D478C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D47A0"))) PPC_WEAK_FUNC(sub_822D47A0);
PPC_FUNC_IMPL(__imp__sub_822D47A0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,17112
	ctx.r5.s64 = r11.s64 + 17112;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D47D0;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,17184
	ctx.r5.s64 = ctx.r5.s64 + 17184;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x822D4820;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D4864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D4878"))) PPC_WEAK_FUNC(sub_822D4878);
PPC_FUNC_IMPL(__imp__sub_822D4878) {
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
	ctx.lr = 0x822D4880;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_822D4888:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d4888
	if (cr6.eq) goto loc_822D4888;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// extsw r4,r11
	ctx.r4.s64 = r11.s32;
	// addi r3,r10,2192
	ctx.r3.s64 = ctx.r10.s64 + 2192;
	// bl 0x821ce210
	ctx.lr = 0x822D48A8;
	sub_821CE210(ctx, base);
loc_822D48A8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d48a8
	if (cr6.eq) goto loc_822D48A8;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// extsw r4,r11
	ctx.r4.s64 = r11.s32;
	// addi r3,r10,2176
	ctx.r3.s64 = ctx.r10.s64 + 2176;
	// bl 0x821ce210
	ctx.lr = 0x822D48C8;
	sub_821CE210(ctx, base);
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82465138
	ctx.lr = 0x822D48D0;
	sub_82465138(ctx, base);
	// bl 0x82465128
	ctx.lr = 0x822D48D4;
	sub_82465128(ctx, base);
	// bl 0x82465140
	ctx.lr = 0x822D48D8;
	sub_82465140(ctx, base);
	// bl 0x82388340
	ctx.lr = 0x822D48DC;
	sub_82388340(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D48E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823971d0
	ctx.lr = 0x822D48EC;
	sub_823971D0(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// blt cr6,0x822d48e4
	if (cr6.lt) goto loc_822D48E4;
	// bl 0x8239c6f0
	ctx.lr = 0x822D48FC;
	sub_8239C6F0(ctx, base);
	// bl 0x8238a878
	ctx.lr = 0x822D4900;
	sub_8238A878(ctx, base);
	// bl 0x82397d60
	ctx.lr = 0x822D4904;
	sub_82397D60(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x822D4908;
	sub_82387B90(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8238ce30
	ctx.lr = 0x822D4910;
	sub_8238CE30(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x822D4914;
	sub_82387B90(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8238ba38
	ctx.lr = 0x822D491C;
	sub_8238BA38(ctx, base);
	// bl 0x82388540
	ctx.lr = 0x822D4920;
	sub_82388540(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x822D4928;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822d493c
	if (cr6.eq) goto loc_822D493C;
	// bl 0x82490990
	ctx.lr = 0x822D4938;
	sub_82490990(ctx, base);
	// b 0x822d4940
	goto loc_822D4940;
loc_822D493C:
	// mr r29,r27
	r29.u64 = r27.u64;
loc_822D4940:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r3,100
	ctx.r3.s64 = 100;
	// addi r30,r11,-27428
	r30.s64 = r11.s64 + -27428;
	// stw r29,-27428(r11)
	PPC_STORE_U32(r11.u32 + -27428, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x822D4954;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4980
	if (cr6.eq) goto loc_822D4980;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r27,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r27.u32);
	// stw r27,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r27.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-15124
	ctx.r10.s64 = r11.s64 + -15124;
	// stw r27,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r27.u32);
	// stw r27,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r27.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x822d4984
	goto loc_822D4984;
loc_822D4980:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D4984:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d4518
	ctx.lr = 0x822D498C;
	sub_822D4518(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r28,r11,-14964
	r28.s64 = r11.s64 + -14964;
	// addi r5,r10,-14976
	ctx.r5.s64 = ctx.r10.s64 + -14976;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82490a08
	ctx.lr = 0x822D49AC;
	sub_82490A08(ctx, base);
	// li r3,100
	ctx.r3.s64 = 100;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130528
	ctx.lr = 0x822D49B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d49e4
	if (cr6.eq) goto loc_822D49E4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r27,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r27.u32);
	// stw r27,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r27.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-15096
	ctx.r10.s64 = r11.s64 + -15096;
	// stw r27,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r27.u32);
	// stw r27,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r27.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x822d49e8
	goto loc_822D49E8;
loc_822D49E4:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D49E8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d45f0
	ctx.lr = 0x822D49F0;
	sub_822D45F0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r11,-14992
	ctx.r5.s64 = r11.s64 + -14992;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82490a08
	ctx.lr = 0x822D4A08;
	sub_82490A08(ctx, base);
	// li r3,100
	ctx.r3.s64 = 100;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130528
	ctx.lr = 0x822D4A14;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4a40
	if (cr6.eq) goto loc_822D4A40;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r27,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r27.u32);
	// stw r27,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r27.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-15068
	ctx.r10.s64 = r11.s64 + -15068;
	// stw r27,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r27.u32);
	// stw r27,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r27.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x822d4a44
	goto loc_822D4A44;
loc_822D4A40:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D4A44:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d46c8
	ctx.lr = 0x822D4A4C;
	sub_822D46C8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r11,-15004
	ctx.r5.s64 = r11.s64 + -15004;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82490a08
	ctx.lr = 0x822D4A64;
	sub_82490A08(ctx, base);
	// li r3,100
	ctx.r3.s64 = 100;
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130528
	ctx.lr = 0x822D4A70;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4a9c
	if (cr6.eq) goto loc_822D4A9C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r27,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r27.u32);
	// stw r27,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r27.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-15040
	ctx.r10.s64 = r11.s64 + -15040;
	// stw r27,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r27.u32);
	// stw r27,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r27.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x822d4aa0
	goto loc_822D4AA0;
loc_822D4A9C:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D4AA0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d47a0
	ctx.lr = 0x822D4AA8;
	sub_822D47A0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r11,-15016
	ctx.r5.s64 = r11.s64 + -15016;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82490a08
	ctx.lr = 0x822D4AC0;
	sub_82490A08(ctx, base);
	// bl 0x825032b8
	ctx.lr = 0x822D4AC4;
	sub_825032B8(ctx, base);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82195800
	ctx.lr = 0x822D4ACC;
	sub_82195800(ctx, base);
	// bl 0x82507820
	ctx.lr = 0x822D4AD0;
	sub_82507820(ctx, base);
	// bl 0x82469a98
	ctx.lr = 0x822D4AD4;
	sub_82469A98(ctx, base);
	// bl 0x8239edc0
	ctx.lr = 0x822D4AD8;
	sub_8239EDC0(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x822D4AE0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4af0
	if (cr6.eq) goto loc_822D4AF0;
	// bl 0x827279a0
	ctx.lr = 0x822D4AEC;
	sub_827279A0(ctx, base);
	// b 0x822d4af4
	goto loc_822D4AF4;
loc_822D4AF0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_822D4AF4:
	// stw r3,20(r26)
	PPC_STORE_U32(r26.u32 + 20, ctx.r3.u32);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822D4B00;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d4b1c
	if (cr6.eq) goto loc_822D4B1C;
	// bl 0x82728608
	ctx.lr = 0x822D4B10;
	sub_82728608(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r31,-9996(r11)
	PPC_STORE_U32(r11.u32 + -9996, r31.u32);
	// b 0x822d4b28
	goto loc_822D4B28;
loc_822D4B1C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r11,-9996(r10)
	PPC_STORE_U32(ctx.r10.u32 + -9996, r11.u32);
loc_822D4B28:
	// bl 0x822ca238
	ctx.lr = 0x822D4B2C;
	sub_822CA238(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stb r27,-23664(r11)
	PPC_STORE_U8(r11.u32 + -23664, r27.u8);
	// bl 0x821d4090
	ctx.lr = 0x822D4B38;
	sub_821D4090(ctx, base);
	// bl 0x8239de80
	ctx.lr = 0x822D4B3C;
	sub_8239DE80(ctx, base);
	// bl 0x8236e388
	ctx.lr = 0x822D4B40;
	sub_8236E388(ctx, base);
	// bl 0x82371310
	ctx.lr = 0x822D4B44;
	sub_82371310(ctx, base);
	// lis r3,344
	ctx.r3.s64 = 22544384;
	// bl 0x821e7770
	ctx.lr = 0x822D4B4C;
	sub_821E7770(ctx, base);
	// bl 0x82328648
	ctx.lr = 0x822D4B50;
	sub_82328648(ctx, base);
	// bl 0x82365108
	ctx.lr = 0x822D4B54;
	sub_82365108(ctx, base);
	// bl 0x8272da30
	ctx.lr = 0x822D4B58;
	sub_8272DA30(ctx, base);
	// bl 0x821f2b08
	ctx.lr = 0x822D4B5C;
	sub_821F2B08(ctx, base);
	// bl 0x826ff8c0
	ctx.lr = 0x822D4B60;
	sub_826FF8C0(ctx, base);
	// bl 0x826c2d88
	ctx.lr = 0x822D4B64;
	sub_826C2D88(ctx, base);
	// bl 0x822ec338
	ctx.lr = 0x822D4B68;
	sub_822EC338(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8226f530
	ctx.lr = 0x822D4B70;
	sub_8226F530(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822D4B78"))) PPC_WEAK_FUNC(sub_822D4B78);
PPC_FUNC_IMPL(__imp__sub_822D4B78) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// bl 0x82588078
	ctx.lr = 0x822D4BB4;
	sub_82588078(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// beq cr6,0x822d4bf0
	if (cr6.eq) goto loc_822D4BF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D4BD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// blt cr6,0x822d4bf0
	if (cr6.lt) goto loc_822D4BF0;
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bgt cr6,0x822d4bf0
	if (cr6.gt) goto loc_822D4BF0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272f540
	ctx.lr = 0x822D4BF0;
	sub_8272F540(ctx, base);
loc_822D4BF0:
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

__attribute__((alias("__imp__sub_822D4C04"))) PPC_WEAK_FUNC(sub_822D4C04);
PPC_FUNC_IMPL(__imp__sub_822D4C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4C08"))) PPC_WEAK_FUNC(sub_822D4C08);
PPC_FUNC_IMPL(__imp__sub_822D4C08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r7,12(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822D4C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D4C58"))) PPC_WEAK_FUNC(sub_822D4C58);
PPC_FUNC_IMPL(__imp__sub_822D4C58) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8229e680
	ctx.lr = 0x822D4C70;
	sub_8229E680(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,19320
	ctx.r5.s64 = r11.s64 + 19320;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822D4C8C;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r9,r10,19464
	ctx.r9.s64 = ctx.r10.s64 + 19464;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82587fe0
	ctx.lr = 0x822D4CA8;
	sub_82587FE0(ctx, base);
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

__attribute__((alias("__imp__sub_822D4CBC"))) PPC_WEAK_FUNC(sub_822D4CBC);
PPC_FUNC_IMPL(__imp__sub_822D4CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4CC0"))) PPC_WEAK_FUNC(sub_822D4CC0);
PPC_FUNC_IMPL(__imp__sub_822D4CC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r11,7
	r11.s64 = 7;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D4CD8"))) PPC_WEAK_FUNC(sub_822D4CD8);
PPC_FUNC_IMPL(__imp__sub_822D4CD8) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r30,0
	r30.s64 = 0;
	// addi r8,r9,-14352
	ctx.r8.s64 = ctx.r9.s64 + -14352;
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// li r10,8
	ctx.r10.s64 = 8;
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
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822D4D40:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x822d4d40
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822D4D40;
	// addi r11,r31,88
	r11.s64 = r31.s64 + 88;
	// stb r30,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r30.u8);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822D4D68:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x822d4d68
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822D4D68;
	// stb r30,124(r31)
	PPC_STORE_U8(r31.u32 + 124, r30.u8);
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x82130528
	ctx.lr = 0x822D4D80;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4d90
	if (cr6.eq) goto loc_822D4D90;
	// bl 0x824f5c00
	ctx.lr = 0x822D4D8C;
	sub_824F5C00(ctx, base);
	// b 0x822d4d94
	goto loc_822D4D94;
loc_822D4D90:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822D4D94:
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x82130528
	ctx.lr = 0x822D4DA0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d4db0
	if (cr6.eq) goto loc_822D4DB0;
	// bl 0x824f5c00
	ctx.lr = 0x822D4DAC;
	sub_824F5C00(ctx, base);
	// b 0x822d4db4
	goto loc_822D4DB4;
loc_822D4DB0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822D4DB4:
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x822D4DC0;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d4de0
	if (cr6.eq) goto loc_822D4DE0;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x822d4de4
	goto loc_822D4DE4;
loc_822D4DE0:
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
loc_822D4DE4:
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

__attribute__((alias("__imp__sub_822D4DFC"))) PPC_WEAK_FUNC(sub_822D4DFC);
PPC_FUNC_IMPL(__imp__sub_822D4DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D4E00"))) PPC_WEAK_FUNC(sub_822D4E00);
PPC_FUNC_IMPL(__imp__sub_822D4E00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x822D4E08;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ce68
	ctx.lr = 0x822D4E1C;
	sub_8226CE68(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x822d51d0
	if (cr6.gt) goto loc_822D51D0;
	// lis r12,-32211
	r12.s64 = -2110980096;
	// addi r12,r12,20040
	r12.s64 = r12.s64 + 20040;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822D4E6C;
	case 1:
		goto loc_822D4ED0;
	case 2:
		goto loc_822D5020;
	case 3:
		goto loc_822D5050;
	case 4:
		goto loc_822D5070;
	case 5:
		goto loc_822D5070;
	case 6:
		goto loc_822D5080;
	case 7:
		goto loc_822D5108;
	case 8:
		goto loc_822D5178;
	default:
		__builtin_unreachable();
	}
	// lwz r17,20076(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20076);
	// lwz r17,20176(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20176);
	// lwz r17,20512(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20512);
	// lwz r17,20560(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20560);
	// lwz r17,20592(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20592);
	// lwz r17,20592(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20592);
	// lwz r17,20608(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20608);
	// lwz r17,20744(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20744);
	// lwz r17,20856(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + 20856);
loc_822D4E6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D4E74;
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
	ctx.lr = 0x822D4E88;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r29,r31,24
	r29.s64 = r31.s64 + 24;
	// bl 0x824e7110
	ctx.lr = 0x822D4E9C;
	sub_824E7110(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-14348
	ctx.r4.s64 = ctx.r9.s64 + -14348;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// bl 0x824f6ea0
	ctx.lr = 0x822D4EC0;
	sub_824F6EA0(ctx, base);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D4ED0:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x822d5010
	if (!cr6.eq) goto loc_822D5010;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,36
	ctx.r9.s64 = 36;
	// addi r8,r31,88
	ctx.r8.s64 = r31.s64 + 88;
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
	// addi r29,r31,32
	r29.s64 = r31.s64 + 32;
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d4fbc
	if (!cr6.eq) goto loc_822D4FBC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D4F14;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822D4F28;
	sub_82270170(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D4F34;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822D4F44;
	sub_82270170(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r25,16(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// lwz r28,8(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r24,r31,20
	r24.s64 = r31.s64 + 20;
	// bl 0x824e7118
	ctx.lr = 0x822D4F5C;
	sub_824E7118(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x822D4F68;
	sub_824E7110(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// stw r28,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r28.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// stw r24,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r24.u32);
	// addi r4,r9,-14348
	ctx.r4.s64 = ctx.r9.s64 + -14348;
	// stw r25,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r25.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// stb r11,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r11.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// bl 0x824f7308
	ctx.lr = 0x822D4FAC;
	sub_824F7308(ctx, base);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D4FBC:
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// addi r4,r7,-14348
	ctx.r4.s64 = ctx.r7.s64 + -14348;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// stb r3,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r3.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824f7468
	ctx.lr = 0x822D5000;
	sub_824F7468(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5010:
	// li r11,6
	r11.s64 = 6;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5020:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x822d5040
	if (cr6.eq) goto loc_822D5040;
	// li r11,6
	r11.s64 = 6;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_822D5040:
	// li r11,5
	r11.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5050:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// li r11,5
	r11.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5070:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5080:
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822D5098:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822d5098
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822D5098;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822D50AC;
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
	ctx.lr = 0x822D50C0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r29,r31,24
	r29.s64 = r31.s64 + 24;
	// bl 0x824e7110
	ctx.lr = 0x822D50D4;
	sub_824E7110(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-14348
	ctx.r4.s64 = ctx.r9.s64 + -14348;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// bl 0x824f6ea0
	ctx.lr = 0x822D50F8;
	sub_824F6EA0(ctx, base);
	// li r8,8
	ctx.r8.s64 = 8;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5108:
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x822d51c8
	if (!cr6.eq) goto loc_822D51C8;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,38
	ctx.r10.s64 = 38;
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// ble cr6,0x822d51c8
	if (!cr6.gt) goto loc_822D51C8;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r8,r31,20
	ctx.r8.s64 = r31.s64 + 20;
	// addi r7,r31,44
	ctx.r7.s64 = r31.s64 + 44;
	// li r6,38
	ctx.r6.s64 = 38;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,40(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// bl 0x824f7578
	ctx.lr = 0x822D5158;
	sub_824F7578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r8,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r7,r11,11
	ctx.r7.s64 = r11.s64 + 11;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D5178:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d51d0
	if (cr6.eq) goto loc_822D51D0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x822d51c8
	if (!cr6.eq) goto loc_822D51C8;
	// lis r11,12336
	r11.s64 = 808452096;
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
	// ori r8,r11,12544
	ctx.r8.u64 = r11.u64 | 12544;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// beq cr6,0x822d51d8
	if (cr6.eq) goto loc_822D51D8;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822D51BC:
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x822d51bc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822D51BC;
loc_822D51C8:
	// li r11,11
	r11.s64 = 11;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_822D51D0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_822D51D8:
	// li r11,10
	r11.s64 = 10;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822D51E8"))) PPC_WEAK_FUNC(sub_822D51E8);
PPC_FUNC_IMPL(__imp__sub_822D51E8) {
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
	// addi r10,r11,-14352
	ctx.r10.s64 = r11.s64 + -14352;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d5220
	if (cr6.eq) goto loc_822D5220;
	// bl 0x82130588
	ctx.lr = 0x822D5220;
	sub_82130588(ctx, base);
loc_822D5220:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x822D5228;
	sub_82130588(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x822D5230;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822D5238;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d5250
	if (cr6.eq) goto loc_822D5250;
	// bl 0x82130588
	ctx.lr = 0x822D524C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D5250:
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

__attribute__((alias("__imp__sub_822D5268"))) PPC_WEAK_FUNC(sub_822D5268);
PPC_FUNC_IMPL(__imp__sub_822D5268) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r3,-27384(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + -27384);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D5274"))) PPC_WEAK_FUNC(sub_822D5274);
PPC_FUNC_IMPL(__imp__sub_822D5274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5278"))) PPC_WEAK_FUNC(sub_822D5278);
PPC_FUNC_IMPL(__imp__sub_822D5278) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r8,r9,-14368
	ctx.r8.s64 = ctx.r9.s64 + -14368;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,29,29,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x4;
	// xori r4,r5,4
	ctx.r4.u64 = ctx.r5.u64 ^ 4;
	// lwzx r3,r4,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D52A0"))) PPC_WEAK_FUNC(sub_822D52A0);
PPC_FUNC_IMPL(__imp__sub_822D52A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x822d6408
	ctx.lr = 0x822D52BC;
	sub_822D6408(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d52d4
	if (cr6.eq) goto loc_822D52D4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r31,r11,-13576
	r31.s64 = r11.s64 + -13576;
	// b 0x822d52dc
	goto loc_822D52DC;
loc_822D52D4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r31,r11,-13568
	r31.s64 = r11.s64 + -13568;
loc_822D52DC:
	// bl 0x822d63f8
	ctx.lr = 0x822D52E0;
	sub_822D63F8(ctx, base);
	// stfd f1,32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-14036
	ctx.r3.s64 = r11.s64 + -14036;
	// bl 0x82130000
	ctx.lr = 0x822D52F8;
	sub_82130000(ctx, base);
	// bl 0x822d63f8
	ctx.lr = 0x822D52FC;
	sub_822D63F8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bgt cr6,0x822d5318
	if (cr6.gt) goto loc_822D5318;
	// bl 0x822d6408
	ctx.lr = 0x822D5308;
	sub_822D6408(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x822d531c
	if (cr6.eq) goto loc_822D531C;
loc_822D5318:
	// li r11,1
	r11.s64 = 1;
loc_822D531C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_822D5338"))) PPC_WEAK_FUNC(sub_822D5338);
PPC_FUNC_IMPL(__imp__sub_822D5338) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d63f8
	sub_822D63F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D533C"))) PPC_WEAK_FUNC(sub_822D533C);
PPC_FUNC_IMPL(__imp__sub_822D533C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5340"))) PPC_WEAK_FUNC(sub_822D5340);
PPC_FUNC_IMPL(__imp__sub_822D5340) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d6310
	sub_822D6310(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D5344"))) PPC_WEAK_FUNC(sub_822D5344);
PPC_FUNC_IMPL(__imp__sub_822D5344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5348"))) PPC_WEAK_FUNC(sub_822D5348);
PPC_FUNC_IMPL(__imp__sub_822D5348) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r11,-14472(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -14472);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d53b0
	if (!cr6.eq) goto loc_822D53B0;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822D5370;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d5394
	if (cr6.eq) goto loc_822D5394;
	// bl 0x822dadf0
	ctx.lr = 0x822D537C;
	sub_822DADF0(ctx, base);
	// stw r3,-14472(r31)
	PPC_STORE_U32(r31.u32 + -14472, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D5394:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,-14472(r31)
	PPC_STORE_U32(r31.u32 + -14472, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D53B0:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r3,-14472(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -14472);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D53D4"))) PPC_WEAK_FUNC(sub_822D53D4);
PPC_FUNC_IMPL(__imp__sub_822D53D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D53D8"))) PPC_WEAK_FUNC(sub_822D53D8);
PPC_FUNC_IMPL(__imp__sub_822D53D8) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r11,-14468(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -14468);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d5440
	if (!cr6.eq) goto loc_822D5440;
	// li r3,4352
	ctx.r3.s64 = 4352;
	// bl 0x82130528
	ctx.lr = 0x822D5400;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d5424
	if (cr6.eq) goto loc_822D5424;
	// bl 0x822df540
	ctx.lr = 0x822D540C;
	sub_822DF540(ctx, base);
	// stw r3,-14468(r31)
	PPC_STORE_U32(r31.u32 + -14468, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D5424:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,-14468(r31)
	PPC_STORE_U32(r31.u32 + -14468, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822D5440:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r3,-14468(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -14468);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822D5464"))) PPC_WEAK_FUNC(sub_822D5464);
PPC_FUNC_IMPL(__imp__sub_822D5464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5468"))) PPC_WEAK_FUNC(sub_822D5468);
PPC_FUNC_IMPL(__imp__sub_822D5468) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r30,512
	cr6.compare<int32_t>(r30.s32, 512, xer);
	// beq cr6,0x822d54d0
	if (cr6.eq) goto loc_822D54D0;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// cmpwi cr6,r30,1024
	cr6.compare<int32_t>(r30.s32, 1024, xer);
	// bne cr6,0x822d54a8
	if (!cr6.eq) goto loc_822D54A8;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x822D549C;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d54d0
	if (!cr6.eq) goto loc_822D54D0;
loc_822D54A8:
	// rlwinm r11,r30,0,19,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FE0;
	// rlwinm r11,r11,0,23,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF1FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d54c8
	if (cr6.eq) goto loc_822D54C8;
	// lwz r11,-7572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// lbz r11,14546(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 14546);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d54d0
	if (!cr6.eq) goto loc_822D54D0;
loc_822D54C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d9078
	ctx.lr = 0x822D54D0;
	sub_822D9078(ctx, base);
loc_822D54D0:
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

__attribute__((alias("__imp__sub_822D54E8"))) PPC_WEAK_FUNC(sub_822D54E8);
PPC_FUNC_IMPL(__imp__sub_822D54E8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822D54F0;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r25,0
	r25.s64 = 0;
	// addi r28,r11,-27312
	r28.s64 = r11.s64 + -27312;
	// addi r11,r28,384
	r11.s64 = r28.s64 + 384;
loc_822D5508:
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
	// addi r10,r28,13184
	ctx.r10.s64 = r28.s64 + 13184;
	// addi r11,r11,400
	r11.s64 = r11.s64 + 400;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d5508
	if (cr6.lt) goto loc_822D5508;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ori r8,r9,57792
	ctx.r8.u64 = ctx.r9.u64 | 57792;
	// lwz r11,-17628(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17628);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,22080(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22080);
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82176058
	ctx.lr = 0x822D554C;
	sub_82176058(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r31,r11,3528
	r31.s64 = r11.s64 + 3528;
	// mr r30,r25
	r30.u64 = r25.u64;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lhz r7,26(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822d55d0
	if (cr6.eq) goto loc_822D55D0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r29,r25
	r29.u64 = r25.u64;
	// lis r26,-32120
	r26.s64 = -2105016320;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_822D557C:
	// lbz r10,-27383(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + -27383);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5590
	if (cr6.eq) goto loc_822D5590;
	// lfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// b 0x822d5594
	goto loc_822D5594;
loc_822D5590:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_822D5594:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lfs f5,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// lfs f4,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822d7d00
	ctx.lr = 0x822D55B8;
	sub_822D7D00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,304
	r29.s64 = r29.s64 + 304;
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d557c
	if (cr6.lt) goto loc_822D557C;
loc_822D55D0:
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5608
	if (cr6.eq) goto loc_822D5608;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_822D55E4:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x822d9de0
	ctx.lr = 0x822D55F0;
	sub_822D9DE0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d55e4
	if (cr6.lt) goto loc_822D55E4;
loc_822D5608:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822D5614"))) PPC_WEAK_FUNC(sub_822D5614);
PPC_FUNC_IMPL(__imp__sub_822D5614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5618"))) PPC_WEAK_FUNC(sub_822D5618);
PPC_FUNC_IMPL(__imp__sub_822D5618) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822D5620;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-7520(r1)
	ea = -7520 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x822d67d0
	ctx.lr = 0x822D562C;
	sub_822D67D0(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r11,-27312
	r28.s64 = r11.s64 + -27312;
	// addi r11,r28,384
	r11.s64 = r28.s64 + 384;
loc_822D563C:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r10,r28,13184
	ctx.r10.s64 = r28.s64 + 13184;
	// addi r11,r11,400
	r11.s64 = r11.s64 + 400;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d563c
	if (cr6.lt) goto loc_822D563C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ori r8,r9,57792
	ctx.r8.u64 = ctx.r9.u64 | 57792;
	// lwz r11,-17628(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17628);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,22080(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22080);
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82176058
	ctx.lr = 0x822D5680;
	sub_82176058(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x822d9490
	ctx.lr = 0x822D5688;
	sub_822D9490(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8217d5e8
	ctx.lr = 0x822D5690;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// bl 0x8217d5e8
	ctx.lr = 0x822D5698;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56A0;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,3280
	ctx.r3.s64 = ctx.r1.s64 + 3280;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56A8;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,4272
	ctx.r3.s64 = ctx.r1.s64 + 4272;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56B0;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,5264
	ctx.r3.s64 = ctx.r1.s64 + 5264;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56B8;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,6256
	ctx.r3.s64 = ctx.r1.s64 + 6256;
	// bl 0x8217d5e8
	ctx.lr = 0x822D56C0;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822e0230
	ctx.lr = 0x822D56C8;
	sub_822E0230(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r31,r11,3528
	r31.s64 = r11.s64 + 3528;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lhz r7,26(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822d5720
	if (cr6.eq) goto loc_822D5720;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_822D56E4:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x822d7120
	ctx.lr = 0x822D5708;
	sub_822D7120(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,304
	r29.s64 = r29.s64 + 304;
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d56e4
	if (cr6.lt) goto loc_822D56E4;
loc_822D5720:
	// addi r3,r1,6256
	ctx.r3.s64 = ctx.r1.s64 + 6256;
	// bl 0x8217cb48
	ctx.lr = 0x822D5728;
	sub_8217CB48(ctx, base);
	// addi r3,r1,5264
	ctx.r3.s64 = ctx.r1.s64 + 5264;
	// bl 0x8217cb48
	ctx.lr = 0x822D5730;
	sub_8217CB48(ctx, base);
	// addi r3,r1,4272
	ctx.r3.s64 = ctx.r1.s64 + 4272;
	// bl 0x8217cb48
	ctx.lr = 0x822D5738;
	sub_8217CB48(ctx, base);
	// addi r3,r1,3280
	ctx.r3.s64 = ctx.r1.s64 + 3280;
	// bl 0x8217cb48
	ctx.lr = 0x822D5740;
	sub_8217CB48(ctx, base);
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// bl 0x8217cb48
	ctx.lr = 0x822D5748;
	sub_8217CB48(ctx, base);
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// bl 0x8217cb48
	ctx.lr = 0x822D5750;
	sub_8217CB48(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8217cb48
	ctx.lr = 0x822D5758;
	sub_8217CB48(ctx, base);
	// addi r1,r1,7520
	ctx.r1.s64 = ctx.r1.s64 + 7520;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D5760"))) PPC_WEAK_FUNC(sub_822D5760);
PPC_FUNC_IMPL(__imp__sub_822D5760) {
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
	ctx.lr = 0x822D5768;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r31,r11,3528
	r31.s64 = r11.s64 + 3528;
	// li r27,-1
	r27.s64 = -1;
	// li r28,-1
	r28.s64 = -1;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// li r29,0
	r29.s64 = 0;
	// lfs f0,-13972(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13972);
	f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f30,f0
	f30.f64 = f0.f64;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// fmr f31,f0
	f31.f64 = f0.f64;
	// rlwinm r26,r9,31,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x1;
	// lhz r8,26(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// rlwinm r25,r9,30,31,31
	r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d5884
	if (cr6.eq) goto loc_822D5884;
	// li r30,0
	r30.s64 = 0;
loc_822D57C0:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d5860
	if (cr6.eq) goto loc_822D5860;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// beq cr6,0x822d5860
	if (cr6.eq) goto loc_822D5860;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// beq cr6,0x822d5860
	if (cr6.eq) goto loc_822D5860;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x822d5820
	if (!cr6.eq) goto loc_822D5820;
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d5814
	if (!cr6.eq) goto loc_822D5814;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5820
	if (cr6.eq) goto loc_822D5820;
	// lhz r10,292(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 292);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d5820
	if (!cr6.eq) goto loc_822D5820;
loc_822D5814:
	// bl 0x822d9d30
	ctx.lr = 0x822D5818;
	sub_822D9D30(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x822d5860
	goto loc_822D5860;
loc_822D5820:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// lhz r9,292(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 292);
	// lfs f0,260(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 260);
	f0.f64 = double(temp.f32);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d5850
	if (cr6.eq) goto loc_822D5850;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x822d5860
	if (!cr6.gt) goto loc_822D5860;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// mr r27,r29
	r27.u64 = r29.u64;
	// b 0x822d5860
	goto loc_822D5860;
loc_822D5850:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822d5860
	if (!cr6.gt) goto loc_822D5860;
	// fmr f31,f0
	f31.f64 = f0.f64;
	// mr r28,r29
	r28.u64 = r29.u64;
loc_822D5860:
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d57c0
	if (cr6.lt) goto loc_822D57C0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x822d5884
	if (cr6.lt) goto loc_822D5884;
	// mulli r10,r28,304
	ctx.r10.s64 = r28.s64 * 304;
	// b 0x822d589c
	goto loc_822D589C;
loc_822D5884:
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d58a8
	if (!cr6.eq) goto loc_822D58A8;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x822d58a8
	if (cr6.lt) goto loc_822D58A8;
	// mulli r10,r27,304
	ctx.r10.s64 = r27.s64 * 304;
loc_822D589C:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x822d9d30
	ctx.lr = 0x822D58A8;
	sub_822D9D30(ctx, base);
loc_822D58A8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822D58B8"))) PPC_WEAK_FUNC(sub_822D58B8);
PPC_FUNC_IMPL(__imp__sub_822D58B8) {
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
	ctx.lr = 0x822D58C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d58ec
	if (cr6.eq) goto loc_822D58EC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D58E0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_822D58EC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d5924
	if (cr6.eq) goto loc_822D5924;
	// li r30,0
	r30.s64 = 0;
loc_822D5900:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x822d8f78
	ctx.lr = 0x822D5910;
	sub_822D8F78(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822d5900
	if (cr6.lt) goto loc_822D5900;
loc_822D5924:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D5930"))) PPC_WEAK_FUNC(sub_822D5930);
PPC_FUNC_IMPL(__imp__sub_822D5930) {
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
	ctx.lr = 0x822D5938;
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
	// beq cr6,0x822d599c
	if (cr6.eq) goto loc_822D599C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822d599c
	if (cr6.eq) goto loc_822D599C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D596C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d599c
	if (cr6.eq) goto loc_822D599C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D5980;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x822df820
	ctx.lr = 0x822D5994;
	sub_822DF820(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822D599C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D59AC"))) PPC_WEAK_FUNC(sub_822D59AC);
PPC_FUNC_IMPL(__imp__sub_822D59AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D59B0"))) PPC_WEAK_FUNC(sub_822D59B0);
PPC_FUNC_IMPL(__imp__sub_822D59B0) {
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
	ctx.lr = 0x822D59B8;
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
	// beq cr6,0x822d5a1c
	if (cr6.eq) goto loc_822D5A1C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822d5a1c
	if (cr6.eq) goto loc_822D5A1C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D59EC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d5a1c
	if (cr6.eq) goto loc_822D5A1C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D5A00;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x822db6f0
	ctx.lr = 0x822D5A14;
	sub_822DB6F0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822D5A1C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822D5A2C"))) PPC_WEAK_FUNC(sub_822D5A2C);
PPC_FUNC_IMPL(__imp__sub_822D5A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D5A30"))) PPC_WEAK_FUNC(sub_822D5A30);
PPC_FUNC_IMPL(__imp__sub_822D5A30) {
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
	ctx.lr = 0x822D5A38;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r31,r11,3528
	r31.s64 = r11.s64 + 3528;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d5dc0
	if (cr6.eq) goto loc_822D5DC0;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-27381(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -27381);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5a74
	if (cr6.eq) goto loc_822D5A74;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f0,3576(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3576);
	f0.f64 = double(temp.f32);
	// b 0x822d5a7c
	goto loc_822D5A7C;
loc_822D5A74:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f0,3580(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3580);
	f0.f64 = double(temp.f32);
loc_822D5A7C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lbz r9,-27382(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -27382);
	// lfs f30,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d5b08
	if (cr6.eq) goto loc_822D5B08;
loc_822D5A98:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5a98
	if (cr6.eq) goto loc_822D5A98;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ld r7,-27360(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + -27360);
	// lfs f0,-14064(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -14064);
	f0.f64 = double(temp.f32);
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// lfs f13,12428(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822d5af4
	if (!cr6.gt) goto loc_822D5AF4;
loc_822D5AE0:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d5ae0
	if (cr6.eq) goto loc_822D5AE0;
	// std r11,-27360(r10)
	PPC_STORE_U64(ctx.r10.u32 + -27360, r11.u64);
loc_822D5AF4:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// li r11,0
	r11.s64 = 0;
	// bgt cr6,0x822d5b04
	if (cr6.gt) goto loc_822D5B04;
	// li r11,1
	r11.s64 = 1;
loc_822D5B04:
	// stb r11,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r11.u8);
loc_822D5B08:
	// bl 0x822bf228
	ctx.lr = 0x822D5B0C;
	sub_822BF228(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,-11624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11624);
	f31.f64 = double(temp.f32);
	// bne cr6,0x822d5bb8
	if (!cr6.eq) goto loc_822D5BB8;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// lwz r30,-8092(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r11,45
	ctx.r4.s64 = r11.s64 + 45;
	// lfs f12,-26236(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -26236);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r6,29952
	r11.s64 = ctx.r6.s64 + 29952;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// lfs f2,3572(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3572);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lwzx r9,r10,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lfs f9,696(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 696);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 - f31.f64));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fsel f6,f7,f7,f11
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : ctx.f11.f64;
	// fsubs f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsel f4,f5,f0,f6
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? f0.f64 : ctx.f6.f64;
	// fmadds f1,f4,f10,f13
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f10.f64 + ctx.f13.f64));
	// bl 0x821ce490
	ctx.lr = 0x822D5B94;
	sub_821CE490(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e5b30
	ctx.lr = 0x822D5B9C;
	sub_822E5B30(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d5bb8
	if (cr6.eq) goto loc_822D5BB8;
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f30
	f0.f64 = double(float(f0.f64 * f30.f64));
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// b 0x822d5bbc
	goto loc_822D5BBC;
loc_822D5BB8:
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
loc_822D5BBC:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f13,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f0,3664(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 3664, temp.u32);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x822dcaf0
	ctx.lr = 0x822D5BD8;
	sub_822DCAF0(ctx, base);
	// bl 0x822d79e0
	ctx.lr = 0x822D5BDC;
	sub_822D79E0(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// li r29,0
	r29.s64 = 0;
	// addi r8,r9,-27380
	ctx.r8.s64 = ctx.r9.s64 + -27380;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-14389(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -14389);
	// bne cr6,0x822d5d5c
	if (!cr6.eq) goto loc_822D5D5C;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5d4c
	if (cr6.eq) goto loc_822D5D4C;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-14356(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14356);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d5d4c
	if (!cr6.eq) goto loc_822D5D4C;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,-14464(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14464);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-14464(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14464, r11.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// ble cr6,0x822d5d80
	if (!cr6.gt) goto loc_822D5D80;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lwz r11,-14432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14432);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5c90
	if (cr6.lt) goto loc_822D5C90;
	// lwz r11,-14448(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -14448);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822d5cc4
	if (!cr6.lt) goto loc_822D5CC4;
	// lwz r10,-14424(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -14424);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x822d5ce0
	if (cr6.lt) goto loc_822D5CE0;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lfs f0,-14404(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -14404);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// lfs f0,-14396(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -14396);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d5ce0
	if (!cr6.lt) goto loc_822D5CE0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,-14424(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -14424);
	// mulli r10,r10,304
	ctx.r10.s64 = ctx.r10.s64 * 304;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x822d5cd4
	goto loc_822D5CD4;
loc_822D5C90:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-14436(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14436);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5cdc
	if (cr6.lt) goto loc_822D5CDC;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lfs f0,-14400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14400);
	f0.f64 = double(temp.f32);
	// lfs f13,-14440(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -14440);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822d5cdc
	if (!cr6.lt) goto loc_822D5CDC;
	// lwz r11,-14448(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -14448);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5ce0
	if (cr6.lt) goto loc_822D5CE0;
loc_822D5CC4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r9,r11,304
	ctx.r9.s64 = r11.s64 * 304;
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + r11.u64;
loc_822D5CD4:
	// bl 0x822d9d30
	ctx.lr = 0x822D5CD8;
	sub_822D9D30(ctx, base);
	// li r29,1
	r29.s64 = 1;
loc_822D5CDC:
	// lwz r11,-14448(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -14448);
loc_822D5CE0:
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d5d80
	if (!cr6.eq) goto loc_822D5D80;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3652(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3652);
	f0.f64 = double(temp.f32);
	// lfs f13,11364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822d5d80
	if (!cr6.lt) goto loc_822D5D80;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5d24
	if (cr6.lt) goto loc_822D5D24;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r9,r11,304
	ctx.r9.s64 = r11.s64 * 304;
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + r11.u64;
	// bl 0x822d9d30
	ctx.lr = 0x822D5D20;
	sub_822D9D30(ctx, base);
	// b 0x822d5d80
	goto loc_822D5D80;
loc_822D5D24:
	// lwz r11,-14424(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -14424);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822d5d80
	if (cr6.lt) goto loc_822D5D80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,-14424(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -14424);
	// mulli r10,r10,304
	ctx.r10.s64 = ctx.r10.s64 * 304;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x822d9d30
	ctx.lr = 0x822D5D48;
	sub_822D9D30(ctx, base);
	// b 0x822d5d80
	goto loc_822D5D80;
loc_822D5D4C:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-14464(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14464, r11.u32);
	// b 0x822d5d80
	goto loc_822D5D80;
loc_822D5D5C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d5d80
	if (cr6.eq) goto loc_822D5D80;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,11724(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 11724);
	// clrlwi r10,r11,30
	ctx.r10.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d5d80
	if (!cr6.eq) goto loc_822D5D80;
	// li r11,5
	r11.s64 = 5;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_822D5D80:
	// bl 0x822d6428
	ctx.lr = 0x822D5D84;
	sub_822D6428(ctx, base);
	// bl 0x822da940
	ctx.lr = 0x822D5D88;
	sub_822DA940(ctx, base);
	// bl 0x822d54e8
	ctx.lr = 0x822D5D8C;
	sub_822D54E8(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-27384(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -27384);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d5da0
	if (!cr6.eq) goto loc_822D5DA0;
	// bl 0x822d5618
	ctx.lr = 0x822D5DA0;
	sub_822D5618(ctx, base);
loc_822D5DA0:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d5dc0
	if (!cr6.eq) goto loc_822D5DC0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d5dc0
	if (cr6.eq) goto loc_822D5DC0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822d5760
	ctx.lr = 0x822D5DC0;
	sub_822D5760(ctx, base);
loc_822D5DC0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D5DD0"))) PPC_WEAK_FUNC(sub_822D5DD0);
PPC_FUNC_IMPL(__imp__sub_822D5DD0) {
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
	ctx.lr = 0x822D5DD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r8,r11,-13964
	ctx.r8.s64 = r11.s64 + -13964;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// lwz r11,-14472(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14472);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// stw r7,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r7.u32);
	// lwz r3,-14472(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14472);
	// lwz r6,12(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x822d5e24
	if (!cr6.eq) goto loc_822D5E24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D5E24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D5E24:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d5e44
	if (cr6.eq) goto loc_822D5E44;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D5E44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D5E44:
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x822D5E4C;
	sub_82130588(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r11,0
	r11.s64 = 0;
	// stw r11,3528(r10)
	PPC_STORE_U32(ctx.r10.u32 + 3528, r11.u32);
	// lhz r31,26(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 26);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d5e90
	if (cr6.eq) goto loc_822D5E90;
	// lwz r28,20(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822d5e88
	if (!cr6.gt) goto loc_822D5E88;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_822D5E74:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d9080
	ctx.lr = 0x822D5E7C;
	sub_822D9080(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// bne 0x822d5e74
	if (!cr0.eq) goto loc_822D5E74;
loc_822D5E88:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x822D5E90;
	sub_82130588(ctx, base);
loc_822D5E90:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2810
	ctx.lr = 0x822D5E98;
	sub_821D2810(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D5EA0"))) PPC_WEAK_FUNC(sub_822D5EA0);
PPC_FUNC_IMPL(__imp__sub_822D5EA0) {
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
	ctx.lr = 0x822D5EC0;
	sub_821D2970(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-13964
	ctx.r10.s64 = r11.s64 + -13964;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b48f0
	ctx.lr = 0x822D5ED4;
	sub_821B48F0(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x822d5930
	ctx.lr = 0x822D5EDC;
	sub_822D5930(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x822d59b0
	ctx.lr = 0x822D5EE4;
	sub_822D59B0(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822d58b8
	ctx.lr = 0x822D5EF4;
	sub_822D58B8(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r11,r9,3528
	r11.s64 = ctx.r9.s64 + 3528;
	// addi r3,r8,-27352
	ctx.r3.s64 = ctx.r8.s64 + -27352;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bl 0x821c07c0
	ctx.lr = 0x822D5F0C;
	sub_821C07C0(ctx, base);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r5,r7,-14512
	ctx.r5.s64 = ctx.r7.s64 + -14512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cntlzw r4,r11
	ctx.r4.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r4,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stb r11,-27382(r6)
	PPC_STORE_U8(ctx.r6.u32 + -27382, r11.u8);
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

__attribute__((alias("__imp__sub_822D5F48"))) PPC_WEAK_FUNC(sub_822D5F48);
PPC_FUNC_IMPL(__imp__sub_822D5F48) {
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
	// bl 0x822d5dd0
	ctx.lr = 0x822D5F68;
	sub_822D5DD0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d5f80
	if (cr6.eq) goto loc_822D5F80;
	// bl 0x82130588
	ctx.lr = 0x822D5F7C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D5F80:
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

__attribute__((alias("__imp__sub_822D5F98"))) PPC_WEAK_FUNC(sub_822D5F98);
PPC_FUNC_IMPL(__imp__sub_822D5F98) {
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
	ctx.lr = 0x822D5FA0;
	// stwu r1,-1712(r1)
	ea = -1712 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// sth r28,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, r28.u16);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// sth r28,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, r28.u16);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821e5fd0
	ctx.lr = 0x822D5FD4;
	sub_821E5FD0(ctx, base);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// li r29,60
	r29.s64 = 60;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// stb r28,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r28.u8);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// stwx r9,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822d6040
	if (cr6.eq) goto loc_822D6040;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822d5ea0
	ctx.lr = 0x822D6024;
	sub_822D5EA0(ctx, base);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
loc_822D6040:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r10,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822D6054"))) PPC_WEAK_FUNC(sub_822D6054);
PPC_FUNC_IMPL(__imp__sub_822D6054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D6058"))) PPC_WEAK_FUNC(sub_822D6058);
PPC_FUNC_IMPL(__imp__sub_822D6058) {
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
	ctx.lr = 0x822D6060;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x822b9708
	ctx.lr = 0x822D606C;
	sub_822B9708(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// addi r4,r10,19848
	ctx.r4.s64 = ctx.r10.s64 + 19848;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x822D6084;
	sub_821CA540(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r9,19612
	r30.s64 = ctx.r9.s64 + 19612;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x822D6098;
	sub_821CA540(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x822D60A4;
	sub_821CA540(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r29,r11,3528
	r29.s64 = r11.s64 + 3528;
	// addi r5,r8,-13924
	ctx.r5.s64 = ctx.r8.s64 + -13924;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x822d5f98
	ctx.lr = 0x822D60C8;
	sub_822D5F98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822D60D0;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822D60D8;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822D60E0;
	sub_821C9A90(ctx, base);
	// bl 0x822d5348
	ctx.lr = 0x822D60E4;
	sub_822D5348(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822d6110
	if (!cr6.eq) goto loc_822D6110;
	// mr r31,r11
	r31.u64 = r11.u64;
	// bl 0x822d53d8
	ctx.lr = 0x822D60FC;
	sub_822D53D8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x822dd450
	ctx.lr = 0x822D610C;
	sub_822DD450(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_822D6110:
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x822dac38
	ctx.lr = 0x822D6118;
	sub_822DAC38(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822d94a0
	ctx.lr = 0x822D6120;
	sub_822D94A0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822d9560
	ctx.lr = 0x822D6128;
	sub_822D9560(ctx, base);
	// bl 0x822d8d70
	ctx.lr = 0x822D612C;
	sub_822D8D70(ctx, base);
loc_822D612C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d612c
	if (cr6.eq) goto loc_822D612C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// addi r3,r10,-13952
	ctx.r3.s64 = ctx.r10.s64 + -13952;
	// bl 0x82130000
	ctx.lr = 0x822D614C;
	sub_82130000(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// lhz r9,26(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d618c
	if (cr6.eq) goto loc_822D618C;
	// li r30,0
	r30.s64 = 0;
loc_822D6164:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x822d6a78
	ctx.lr = 0x822D6174;
	sub_822D6A78(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,304
	r30.s64 = r30.s64 + 304;
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x822d6164
	if (cr6.lt) goto loc_822D6164;
loc_822D618C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d618c
	if (cr6.eq) goto loc_822D618C;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822D61A8"))) PPC_WEAK_FUNC(sub_822D61A8);
PPC_FUNC_IMPL(__imp__sub_822D61A8) {
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
	// li r11,16
	r11.s64 = 16;
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r8,r10,-31568
	ctx.r8.s64 = ctx.r10.s64 + -31568;
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// lvx128 v59,r3,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// vsubfp128 v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r3,r6,2240
	ctx.r3.s64 = ctx.r6.s64 + 2240;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r5,-31648
	ctx.r10.s64 = ctx.r5.s64 + -31648;
	// addi r9,r11,-31664
	ctx.r9.s64 = r11.s64 + -31664;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r8,-12736
	ctx.r7.s64 = ctx.r8.s64 + -12736;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v58,v62
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v57,v57
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vaddfp128 v11,v57,v60
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vrsqrtefp128 v55,v56
	simde_mm_store_ps(v55.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// vor128 v10,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vcmpeqfp128 v9,v55,v61
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v8,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v63,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v10,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v3,v56,v4
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vsel v2,v11,v3,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// stvx128 v2,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6240"))) PPC_WEAK_FUNC(sub_822D6240);
PPC_FUNC_IMPL(__imp__sub_822D6240) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-11856
	r11.s64 = r11.s64 + -11856;
	// lwz r10,-11840(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11840);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822d6280
	if (!cr6.eq) goto loc_822D6280;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,-11840(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11840, ctx.r10.u32);
	// lfs f0,14884(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
loc_822D6280:
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// addi r6,r8,2240
	ctx.r6.s64 = ctx.r8.s64 + 2240;
	// lvx128 v59,r3,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// vsubfp128 v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r11,r5,-31648
	r11.s64 = ctx.r5.s64 + -31648;
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,-31664
	ctx.r10.s64 = ctx.r3.s64 + -31664;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r8,r9,-12736
	ctx.r8.s64 = ctx.r9.s64 + -12736;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v58,v62
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// vmsum3fp128 v56,v57,v57
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vaddfp128 v11,v57,v60
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vrsqrtefp128 v55,v56
	simde_mm_store_ps(v55.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// vor128 v10,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vcmpeqfp128 v9,v55,v61
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v8,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v63,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v10,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v3,v56,v4
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vsel v2,v11,v3,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// stvx128 v2,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6310"))) PPC_WEAK_FUNC(sub_822D6310);
PPC_FUNC_IMPL(__imp__sub_822D6310) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v63{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d6334
	if (!cr6.eq) goto loc_822D6334;
	// lbz r10,-14375(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + -14375);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d63ec
	if (!cr6.eq) goto loc_822D63EC;
loc_822D6334:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d637c
	if (!cr6.eq) goto loc_822D637C;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r10,-14348(r7)
	PPC_STORE_U8(ctx.r7.u32 + -14348, ctx.r10.u8);
	// stb r9,-14352(r6)
	PPC_STORE_U8(ctx.r6.u32 + -14352, ctx.r9.u8);
	// beq cr6,0x822d6364
	if (cr6.eq) goto loc_822D6364;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-14375(r8)
	PPC_STORE_U8(ctx.r8.u32 + -14375, r11.u8);
loc_822D6364:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-14444(r10)
	PPC_STORE_U8(ctx.r10.u32 + -14444, r11.u8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_822D637C:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r31,r10,-11984
	r31.s64 = ctx.r10.s64 + -11984;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r10,-14444(r7)
	PPC_STORE_U8(ctx.r7.u32 + -14444, ctx.r10.u8);
	// li r30,16
	r30.s64 = 16;
	// stb r9,-14348(r6)
	PPC_STORE_U8(ctx.r6.u32 + -14348, ctx.r9.u8);
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// stb r4,-14352(r5)
	PPC_STORE_U8(ctx.r5.u32 + -14352, ctx.r4.u8);
	// li r7,32
	ctx.r7.s64 = 32;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,48
	ctx.r6.s64 = 48;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// lvx128 v63,r3,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822d63ec
	if (cr6.eq) goto loc_822D63EC;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-14375(r8)
	PPC_STORE_U8(ctx.r8.u32 + -14375, r11.u8);
loc_822D63EC:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D63F8"))) PPC_WEAK_FUNC(sub_822D63F8);
PPC_FUNC_IMPL(__imp__sub_822D63F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f1,3672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3672);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6404"))) PPC_WEAK_FUNC(sub_822D6404);
PPC_FUNC_IMPL(__imp__sub_822D6404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D6408"))) PPC_WEAK_FUNC(sub_822D6408);
PPC_FUNC_IMPL(__imp__sub_822D6408) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-14360(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14360);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x822d6420
	if (cr6.gt) goto loc_822D6420;
	// li r11,0
	r11.s64 = 0;
loc_822D6420:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6428"))) PPC_WEAK_FUNC(sub_822D6428);
PPC_FUNC_IMPL(__imp__sub_822D6428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lfs f0,-6432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6432);
	f0.f64 = double(temp.f32);
	// li r11,-1
	r11.s64 = -1;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lfs f13,-13544(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13544);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// stfs f0,-14400(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -14400, temp.u32);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// stw r11,-14436(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14436, r11.u32);
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// stfs f0,-14404(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + -14404, temp.u32);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f13,-14440(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + -14440, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r10,-14432(r6)
	PPC_STORE_U32(ctx.r6.u32 + -14432, ctx.r10.u32);
	// stfs f13,-14396(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + -14396, temp.u32);
	// stw r9,-14448(r4)
	PPC_STORE_U32(ctx.r4.u32 + -14448, ctx.r9.u32);
	// stw r8,-14424(r31)
	PPC_STORE_U32(r31.u32 + -14424, ctx.r8.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D6494"))) PPC_WEAK_FUNC(sub_822D6494);
PPC_FUNC_IMPL(__imp__sub_822D6494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D6498"))) PPC_WEAK_FUNC(sub_822D6498);
PPC_FUNC_IMPL(__imp__sub_822D6498) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,292(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 292);
	// rlwinm r10,r11,0,21,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7FE;
	// rlwinm r10,r10,0,28,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC0F;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,3623(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3623);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6520
	if (cr6.eq) goto loc_822D6520;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-14428
	ctx.r9.s64 = r11.s64 + -14428;
	// lwz r11,-14428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14428);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d64f8
	if (cr6.eq) goto loc_822D64F8;
	// lfs f0,268(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	f0.f64 = double(temp.f32);
loc_822D64D8:
	// lfs f13,268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822d650c
	if (cr6.lt) goto loc_822D650C;
	// addi r9,r11,276
	ctx.r9.s64 = r11.s64 + 276;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,276(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d64d8
	if (!cr6.eq) goto loc_822D64D8;
loc_822D64F8:
	// li r11,0
	r11.s64 = 0;
	// stw r10,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, ctx.r10.u32);
	// stw r11,276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 276, r11.u32);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// blr 
	return;
loc_822D650C:
	// stw r11,276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 276, r11.u32);
	// stw r10,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, ctx.r10.u32);
	// stw r3,280(r11)
	PPC_STORE_U32(r11.u32 + 280, ctx.r3.u32);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// blr 
	return;
loc_822D6520:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,-14428(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14428);
	// stw r9,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, ctx.r9.u32);
	// stw r11,276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 276, r11.u32);
	// stw r3,-14428(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14428, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D653C"))) PPC_WEAK_FUNC(sub_822D653C);
PPC_FUNC_IMPL(__imp__sub_822D653C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D6540"))) PPC_WEAK_FUNC(sub_822D6540);
PPC_FUNC_IMPL(__imp__sub_822D6540) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r7,252(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lbz r11,295(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 295);
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// extsb r9,r11
	ctx.r9.s64 = r11.s8;
	// bne cr6,0x822d657c
	if (!cr6.eq) goto loc_822D657C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,3676(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3676);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d657c
	if (cr6.eq) goto loc_822D657C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,268(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3664(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3664);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822d6580
	if (cr6.lt) goto loc_822D6580;
loc_822D657C:
	// li r11,0
	r11.s64 = 0;
loc_822D6580:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d65a4
	if (!cr6.eq) goto loc_822D65A4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-14380(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d65a8
	if (!cr6.eq) goto loc_822D65A8;
loc_822D65A4:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822D65A8:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r11,3612
	ctx.r10.s64 = r11.s64 + 3612;
	// lbz r11,10(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d6698
	if (cr6.eq) goto loc_822D6698;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r5,r11,-14444
	ctx.r5.s64 = r11.s64 + -14444;
	// lbz r4,1(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822d6698
	if (!cr6.eq) goto loc_822D6698;
	// lhz r11,292(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 292);
	// rlwinm r5,r11,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822d669c
	if (cr6.eq) goto loc_822D669C;
	// lbz r11,296(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 296);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d6698
	if (cr6.eq) goto loc_822D6698;
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// bne cr6,0x822d6698
	if (!cr6.eq) goto loc_822D6698;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822d662c
	if (cr6.eq) goto loc_822D662C;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x822d6668
	if (!cr6.eq) goto loc_822D6668;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d6660
	if (!cr6.eq) goto loc_822D6660;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,2
	ctx.r9.s64 = 2;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,288(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// b 0x822d6668
	goto loc_822D6668;
loc_822D662C:
	// clrlwi r5,r8,24
	ctx.r5.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822d6698
	if (cr6.eq) goto loc_822D6698;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x822d6668
	if (!cr6.eq) goto loc_822D6668;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d6660
	if (cr6.eq) goto loc_822D6660;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,4
	ctx.r9.s64 = 4;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,288(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// b 0x822d6668
	goto loc_822D6668;
loc_822D6660:
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x822d669c
	if (cr6.eq) goto loc_822D669C;
loc_822D6668:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,288(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r11,29952
	ctx.r5.s64 = r11.s64 + 29952;
	// lfs f0,88(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f13,f12
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f11,288(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ble cr6,0x822d669c
	if (!cr6.gt) goto loc_822D669C;
	// stfs f0,288(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
loc_822D6698:
	// li r9,1
	ctx.r9.s64 = 1;
loc_822D669C:
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// stb r11,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, r11.u8);
	// bne cr6,0x822d66b4
	if (!cr6.eq) goto loc_822D66B4;
	// li r11,4
	r11.s64 = 4;
	// stb r11,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, r11.u8);
loc_822D66B4:
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d66cc
	if (cr6.eq) goto loc_822D66CC;
	// lbz r10,296(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 296);
	// ori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 | 1;
	// stb r8,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, ctx.r8.u8);
loc_822D66CC:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stb r9,295(r3)
	PPC_STORE_U8(ctx.r3.u32 + 295, ctx.r9.u8);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,296(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 296);
	// ori r8,r11,2
	ctx.r8.u64 = r11.u64 | 2;
	// stb r8,296(r3)
	PPC_STORE_U8(ctx.r3.u32 + 296, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D66E8"))) PPC_WEAK_FUNC(sub_822D66E8);
PPC_FUNC_IMPL(__imp__sub_822D66E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6700
	if (cr6.eq) goto loc_822D6700;
	// li r3,4
	ctx.r3.s64 = 4;
loc_822D6700:
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6714
	if (cr6.eq) goto loc_822D6714;
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_822D6714:
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6728
	if (cr6.eq) goto loc_822D6728;
	// li r3,16
	ctx.r3.s64 = 16;
	// blr 
	return;
loc_822D6728:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d673c
	if (cr6.eq) goto loc_822D673C;
	// li r3,32
	ctx.r3.s64 = 32;
	// blr 
	return;
loc_822D673C:
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6750
	if (cr6.eq) goto loc_822D6750;
	// li r3,64
	ctx.r3.s64 = 64;
	// blr 
	return;
loc_822D6750:
	// rlwinm r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6764
	if (cr6.eq) goto loc_822D6764;
	// li r3,128
	ctx.r3.s64 = 128;
	// blr 
	return;
loc_822D6764:
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d6778
	if (cr6.eq) goto loc_822D6778;
	// li r3,512
	ctx.r3.s64 = 512;
	// blr 
	return;
loc_822D6778:
	// rlwinm r10,r11,0,7,7
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d678c
	if (cr6.eq) goto loc_822D678C;
	// li r3,1024
	ctx.r3.s64 = 1024;
	// blr 
	return;
loc_822D678C:
	// rlwinm r10,r11,0,11,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1FFFFE;
	// rlwinm r10,r10,0,30,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFE0003;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d67a4
	if (cr6.eq) goto loc_822D67A4;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_822D67A4:
	// rlwinm r10,r11,0,17,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7C00;
	// rlwinm r10,r10,0,21,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d67bc
	if (cr6.eq) goto loc_822D67BC;
	// li r3,256
	ctx.r3.s64 = 256;
	// blr 
	return;
loc_822D67BC:
	// rlwinm r11,r11,0,20,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x800;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r3,2048
	ctx.r3.s64 = 2048;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D67D0"))) PPC_WEAK_FUNC(sub_822D67D0);
PPC_FUNC_IMPL(__imp__sub_822D67D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822D67DC"))) PPC_WEAK_FUNC(sub_822D67DC);
PPC_FUNC_IMPL(__imp__sub_822D67DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D67E0"))) PPC_WEAK_FUNC(sub_822D67E0);
PPC_FUNC_IMPL(__imp__sub_822D67E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stb r3,3622(r11)
	PPC_STORE_U8(r11.u32 + 3622, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822D67EC"))) PPC_WEAK_FUNC(sub_822D67EC);
PPC_FUNC_IMPL(__imp__sub_822D67EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822D67F0"))) PPC_WEAK_FUNC(sub_822D67F0);
PPC_FUNC_IMPL(__imp__sub_822D67F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-14374(r10)
	PPC_STORE_U8(ctx.r10.u32 + -14374, r11.u8);
	// blr 
	return;
}

