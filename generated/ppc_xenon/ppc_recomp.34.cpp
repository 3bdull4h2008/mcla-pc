#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82261918"))) PPC_WEAK_FUNC(sub_82261918);
PPC_FUNC_IMPL(__imp__sub_82261918) {
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
	ctx.lr = 0x82261920;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,72
	r25.s64 = 72;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82261950
	if (cr6.eq) goto loc_82261950;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82261954
	goto loc_82261954;
loc_82261950:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82261954:
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822619f4
	if (!cr6.gt) goto loc_822619F4;
	// mr r30,r24
	r30.u64 = r24.u64;
	// addi r27,r23,912
	r27.s64 = r23.s64 + 912;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_8226196C:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x82261988
	if (cr6.eq) goto loc_82261988;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x8226198c
	goto loc_8226198C;
loc_82261988:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_8226198C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822619c8
	if (cr6.eq) goto loc_822619C8;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822619c0
	if (cr6.eq) goto loc_822619C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822619B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822619c8
	if (cr6.eq) goto loc_822619C8;
loc_822619C0:
	// li r11,1
	r11.s64 = 1;
	// b 0x822619cc
	goto loc_822619CC;
loc_822619C8:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_822619CC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822619e8
	if (cr6.eq) goto loc_822619E8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r27,r27,112
	r27.s64 = r27.s64 + 112;
	// bl 0x82260da8
	ctx.lr = 0x822619E8;
	sub_82260DA8(ctx, base);
loc_822619E8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8226196c
	if (!cr0.eq) goto loc_8226196C;
loc_822619F4:
	// addi r3,r23,1844
	ctx.r3.s64 = r23.s64 + 1844;
	// bl 0x82260e70
	ctx.lr = 0x822619FC;
	sub_82260E70(ctx, base);
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r9,r23,2056
	ctx.r9.s64 = r23.s64 + 2056;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
loc_82261A08:
	// std r24,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r24.u64);
	// lwz r3,-4964(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4964);
	// lwzx r11,r8,r3
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82261a60
	if (cr6.eq) goto loc_82261A60;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261a60
	if (cr6.eq) goto loc_82261A60;
loc_82261A2C:
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r5,30(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 30);
	// rlwinm r4,r5,0,0,16
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82261a4c
	if (cr6.eq) goto loc_82261A4C;
	// ld r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// or r5,r10,r6
	ctx.r5.u64 = ctx.r10.u64 | ctx.r6.u64;
	// std r5,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r5.u64);
loc_82261A4C:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r10,r10,1,62
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82261a2c
	if (!cr6.eq) goto loc_82261A2C;
	// lwz r3,-4964(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4964);
loc_82261A60:
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmpwi cr6,r8,88
	cr6.compare<int32_t>(ctx.r8.s32, 88, xer);
	// blt cr6,0x82261a08
	if (cr6.lt) goto loc_82261A08;
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r23,2376
	ctx.r4.s64 = r23.s64 + 2376;
	// bl 0x827288d8
	ctx.lr = 0x82261A7C;
	sub_827288D8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82261A84"))) PPC_WEAK_FUNC(sub_82261A84);
PPC_FUNC_IMPL(__imp__sub_82261A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82261A88"))) PPC_WEAK_FUNC(sub_82261A88);
PPC_FUNC_IMPL(__imp__sub_82261A88) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82261A90;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,72
	r25.s64 = 72;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82261ac0
	if (cr6.eq) goto loc_82261AC0;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82261ac4
	goto loc_82261AC4;
loc_82261AC0:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82261AC4:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82261b60
	if (!cr6.gt) goto loc_82261B60;
	// li r30,0
	r30.s64 = 0;
	// addi r27,r24,912
	r27.s64 = r24.s64 + 912;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82261AD8:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x82261af4
	if (cr6.eq) goto loc_82261AF4;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x82261af8
	goto loc_82261AF8;
loc_82261AF4:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_82261AF8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82261b34
	if (cr6.eq) goto loc_82261B34;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82261b2c
	if (cr6.eq) goto loc_82261B2C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261B20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82261b34
	if (cr6.eq) goto loc_82261B34;
loc_82261B2C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82261b38
	goto loc_82261B38;
loc_82261B34:
	// li r11,0
	r11.s64 = 0;
loc_82261B38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261b54
	if (cr6.eq) goto loc_82261B54;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r27,r27,112
	r27.s64 = r27.s64 + 112;
	// bl 0x82261540
	ctx.lr = 0x82261B54;
	sub_82261540(ctx, base);
loc_82261B54:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82261ad8
	if (!cr0.eq) goto loc_82261AD8;
loc_82261B60:
	// addi r3,r24,1844
	ctx.r3.s64 = r24.s64 + 1844;
	// bl 0x82260f20
	ctx.lr = 0x82261B68;
	sub_82260F20(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// li r29,8
	r29.s64 = 8;
	// addi r28,r24,2056
	r28.s64 = r24.s64 + 2056;
	// lwz r3,-4964(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -4964);
loc_82261B78:
	// lwzx r11,r29,r3
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82261bd4
	if (cr6.eq) goto loc_82261BD4;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82261bd4
	if (cr6.eq) goto loc_82261BD4;
loc_82261B94:
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// and r10,r30,r11
	ctx.r10.u64 = r30.u64 & r11.u64;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// bne cr6,0x82261bc0
	if (!cr6.eq) goto loc_82261BC0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lhz r10,30(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 30);
	// rlwinm r9,r10,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82261bc0
	if (cr6.eq) goto loc_82261BC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82728c48
	ctx.lr = 0x82261BC0;
	sub_82728C48(ctx, base);
loc_82261BC0:
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rldicr r30,r30,1,62
	r30.u64 = __builtin_rotateleft64(r30.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82261b94
	if (!cr6.eq) goto loc_82261B94;
	// lwz r3,-4964(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -4964);
loc_82261BD4:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmpwi cr6,r29,88
	cr6.compare<int32_t>(r29.s32, 88, xer);
	// blt cr6,0x82261b78
	if (cr6.lt) goto loc_82261B78;
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r24,2376
	ctx.r4.s64 = r24.s64 + 2376;
	// bl 0x82728960
	ctx.lr = 0x82261BF0;
	sub_82728960(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82261BF8"))) PPC_WEAK_FUNC(sub_82261BF8);
PPC_FUNC_IMPL(__imp__sub_82261BF8) {
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
	ctx.lr = 0x82261C00;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,2620(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82261c28
	if (!cr6.eq) goto loc_82261C28;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261c40
	if (cr6.eq) goto loc_82261C40;
loc_82261C28:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261C40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82261C40:
	// bl 0x822614a0
	ctx.lr = 0x82261C44;
	sub_822614A0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r29,-12348(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 76);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82261c64
	if (cr6.eq) goto loc_82261C64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391628
	ctx.lr = 0x82261C64;
	sub_82391628(ctx, base);
loc_82261C64:
	// lbz r11,76(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 76);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82261c7c
	if (cr6.eq) goto loc_82261C7C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391688
	ctx.lr = 0x82261C7C;
	sub_82391688(ctx, base);
loc_82261C7C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261df4
	if (cr6.eq) goto loc_82261DF4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r10,r11,-5004
	ctx.r10.s64 = r11.s64 + -5004;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261cac
	if (cr6.eq) goto loc_82261CAC;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// li r11,1
	r11.s64 = 1;
	// b 0x82261cb0
	goto loc_82261CB0;
loc_82261CAC:
	// li r11,0
	r11.s64 = 0;
loc_82261CB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261e08
	if (cr6.eq) goto loc_82261E08;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82261e08
	if (cr6.eq) goto loc_82261E08;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-4180
	ctx.r5.s64 = r11.s64 + -4180;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82261CE0;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82261e08
	if (cr6.eq) goto loc_82261E08;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,1888
	ctx.r4.s64 = r30.s64 + 1888;
	// bl 0x821be710
	ctx.lr = 0x82261CF8;
	sub_821BE710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82261D00;
	sub_821BE4F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lbz r10,2620(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// clrlwi r8,r10,25
	ctx.r8.u64 = ctx.r10.u32 & 0x7F;
	// rlwinm r7,r9,2,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x80;
	// xori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 ^ 128;
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// stb r5,2620(r30)
	PPC_STORE_U8(r30.u32 + 2620, ctx.r5.u8);
	// bl 0x821be4f0
	ctx.lr = 0x82261D28;
	sub_821BE4F0(ctx, base);
	// cntlzw r4,r3
	ctx.r4.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lbz r11,2620(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// li r5,2
	ctx.r5.s64 = 2;
	// rlwinm r10,r4,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// addi r4,r30,1880
	ctx.r4.s64 = r30.s64 + 1880;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwimi r11,r9,5,26,26
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x20) | (r11.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r11,2620(r30)
	PPC_STORE_U8(r30.u32 + 2620, r11.u8);
	// bl 0x821be710
	ctx.lr = 0x82261D50;
	sub_821BE710(ctx, base);
	// li r5,896
	ctx.r5.s64 = 896;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x82261D60;
	sub_821BE250(ctx, base);
	// li r5,896
	ctx.r5.s64 = 896;
	// addi r4,r30,912
	ctx.r4.s64 = r30.s64 + 912;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x82261D70;
	sub_821BE250(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r4,r30,1808
	ctx.r4.s64 = r30.s64 + 1808;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x82261D80;
	sub_821BE250(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r4,r30,1844
	ctx.r4.s64 = r30.s64 + 1844;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x82261D90;
	sub_821BE250(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r30,1896
	ctx.r4.s64 = r30.s64 + 1896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DA0;
	sub_821BE710(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r30,2056
	ctx.r4.s64 = r30.s64 + 2056;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DB0;
	sub_821BE710(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r30,2216
	ctx.r4.s64 = r30.s64 + 2216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DC0;
	sub_821BE710(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r30,2376
	ctx.r4.s64 = r30.s64 + 2376;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DD0;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,2616
	ctx.r4.s64 = r30.s64 + 2616;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x82261DE0;
	sub_821BE710(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391568
	ctx.lr = 0x82261DEC;
	sub_82391568(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82261DF4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261E08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82261E08:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82261E10"))) PPC_WEAK_FUNC(sub_82261E10);
PPC_FUNC_IMPL(__imp__sub_82261E10) {
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
	ctx.lr = 0x82261E18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r3,-12348(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// li r4,20
	ctx.r4.s64 = 20;
	// stw r27,1892(r31)
	PPC_STORE_U32(r31.u32 + 1892, r27.u32);
	// beq cr6,0x82261f38
	if (cr6.eq) goto loc_82261F38;
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// li r12,163
	r12.s64 = 163;
	// and r10,r11,r12
	ctx.r10.u64 = r11.u64 & r12.u64;
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,2620(r31)
	PPC_STORE_U8(r31.u32 + 2620, ctx.r9.u8);
	// bl 0x82390eb0
	ctx.lr = 0x82261E58;
	sub_82390EB0(ctx, base);
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,72
	r25.s64 = 72;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lbzx r8,r25,r26
	ctx.r8.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82261e80
	if (cr6.eq) goto loc_82261E80;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82261e84
	goto loc_82261E84;
loc_82261E80:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82261E84:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82261f50
	if (!cr6.gt) goto loc_82261F50;
	// mr r30,r27
	r30.u64 = r27.u64;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82261E94:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x82261eb0
	if (cr6.eq) goto loc_82261EB0;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x82261eb4
	goto loc_82261EB4;
loc_82261EB0:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_82261EB4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82261ef0
	if (cr6.eq) goto loc_82261EF0;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82261ee8
	if (cr6.eq) goto loc_82261EE8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261EDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82261ef0
	if (cr6.eq) goto loc_82261EF0;
loc_82261EE8:
	// li r11,1
	r11.s64 = 1;
	// b 0x82261ef4
	goto loc_82261EF4;
loc_82261EF0:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82261EF4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82261f24
	if (cr6.eq) goto loc_82261F24;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82261f24
	if (cr6.eq) goto loc_82261F24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261F24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82261F24:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82261e94
	if (!cr0.eq) goto loc_82261E94;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82261F38:
	// stw r27,1888(r31)
	PPC_STORE_U32(r31.u32 + 1888, r27.u32);
	// bl 0x82390e08
	ctx.lr = 0x82261F40;
	sub_82390E08(ctx, base);
	// lbz r10,2620(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// li r11,1
	r11.s64 = 1;
	// rlwimi r10,r11,4,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stb r10,2620(r31)
	PPC_STORE_U8(r31.u32 + 2620, ctx.r10.u8);
loc_82261F50:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82261F58"))) PPC_WEAK_FUNC(sub_82261F58);
PPC_FUNC_IMPL(__imp__sub_82261F58) {
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
	ctx.lr = 0x82261F60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x822614a0
	ctx.lr = 0x82261F70;
	sub_822614A0(ctx, base);
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82262040
	if (cr6.eq) goto loc_82262040;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// rlwinm r9,r9,0,29,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stb r9,2620(r31)
	PPC_STORE_U8(r31.u32 + 2620, ctx.r9.u8);
	// lwz r3,-12348(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// lbz r8,76(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 76);
	// rlwinm r7,r8,0,25,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// bl 0x82391688
	ctx.lr = 0x82261FA8;
	sub_82391688(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82262010
	if (cr6.eq) goto loc_82262010;
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82261fd4
	if (!cr6.eq) goto loc_82261FD4;
	// lwz r11,1892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1892);
	// lwz r10,1888(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1888);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82262010
	if (!cr6.lt) goto loc_82262010;
loc_82261FD4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82261FE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,-12640(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12640);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82262004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,1888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1888);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// stw r6,1892(r31)
	PPC_STORE_U32(r31.u32 + 1892, ctx.r6.u32);
loc_82262010:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8226201C;
	sub_822A39C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a5578
	ctx.lr = 0x82262024;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x82262034;
	sub_822A5578(ctx, base);
	// bl 0x822a2370
	ctx.lr = 0x82262038;
	sub_822A2370(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82262040:
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r9,2620(r31)
	PPC_STORE_U8(r31.u32 + 2620, ctx.r9.u8);
	// lwz r29,-12348(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// lbz r8,76(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 76);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391628
	ctx.lr = 0x82262078;
	sub_82391628(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226208C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r8,r9,-4984
	ctx.r8.s64 = ctx.r9.s64 + -4984;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822620b0
	if (cr6.eq) goto loc_822620B0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// li r11,1
	r11.s64 = 1;
	// b 0x822620b4
	goto loc_822620B4;
loc_822620B0:
	// li r11,0
	r11.s64 = 0;
loc_822620B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-4180
	ctx.r5.s64 = r11.s64 + -4180;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca720
	ctx.lr = 0x822620E0;
	sub_821CA720(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822621cc
	if (cr6.eq) goto loc_822621CC;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,1888
	ctx.r4.s64 = r31.s64 + 1888;
	// bl 0x821be7e8
	ctx.lr = 0x822620F8;
	sub_821BE7E8(ctx, base);
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r4,r11,25,7,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// bl 0x821be528
	ctx.lr = 0x82262108;
	sub_821BE528(ctx, base);
	// lbz r10,2620(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r4,r10,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821be528
	ctx.lr = 0x82262118;
	sub_821BE528(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,1880
	ctx.r4.s64 = r31.s64 + 1880;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x82262128;
	sub_821BE7E8(ctx, base);
	// li r5,896
	ctx.r5.s64 = 896;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be3d8
	ctx.lr = 0x82262138;
	sub_821BE3D8(ctx, base);
	// li r5,896
	ctx.r5.s64 = 896;
	// addi r4,r31,912
	ctx.r4.s64 = r31.s64 + 912;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be3d8
	ctx.lr = 0x82262148;
	sub_821BE3D8(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r4,r31,1808
	ctx.r4.s64 = r31.s64 + 1808;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be3d8
	ctx.lr = 0x82262158;
	sub_821BE3D8(ctx, base);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r4,r31,1844
	ctx.r4.s64 = r31.s64 + 1844;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be3d8
	ctx.lr = 0x82262168;
	sub_821BE3D8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r31,1896
	ctx.r4.s64 = r31.s64 + 1896;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x82262178;
	sub_821BE7E8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r31,2056
	ctx.r4.s64 = r31.s64 + 2056;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x82262188;
	sub_821BE7E8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r31,2216
	ctx.r4.s64 = r31.s64 + 2216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x82262198;
	sub_821BE7E8(ctx, base);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r31,2376
	ctx.r4.s64 = r31.s64 + 2376;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x822621A8;
	sub_821BE7E8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,2616
	ctx.r4.s64 = r31.s64 + 2616;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be7e8
	ctx.lr = 0x822621B8;
	sub_821BE7E8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391500
	ctx.lr = 0x822621C4;
	sub_82391500(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x822621CC;
	sub_821BE610(ctx, base);
loc_822621CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822621D4"))) PPC_WEAK_FUNC(sub_822621D4);
PPC_FUNC_IMPL(__imp__sub_822621D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822621D8"))) PPC_WEAK_FUNC(sub_822621D8);
PPC_FUNC_IMPL(__imp__sub_822621D8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822621E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,72
	r26.s64 = 72;
	// li r27,0
	r27.s64 = 0;
	// lbzx r11,r26,r25
	r11.u64 = PPC_LOAD_U8(r26.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,17892
	r29.s64 = r11.s64 + 17892;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// beq cr6,0x82262210
	if (cr6.eq) goto loc_82262210;
	// lwz r11,804(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82262214
	goto loc_82262214;
loc_82262210:
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82262214:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822622e4
	if (!cr6.gt) goto loc_822622E4;
	// li r30,0
	r30.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82262224:
	// lbzx r11,r26,r25
	r11.u64 = PPC_LOAD_U8(r26.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x82262240
	if (cr6.eq) goto loc_82262240;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,404(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x82262244
	goto loc_82262244;
loc_82262240:
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_82262244:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82262280
	if (cr6.eq) goto loc_82262280;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82262278
	if (cr6.eq) goto loc_82262278;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226226C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82262280
	if (cr6.eq) goto loc_82262280;
loc_82262278:
	// li r11,1
	r11.s64 = 1;
	// b 0x82262284
	goto loc_82262284;
loc_82262280:
	// li r11,0
	r11.s64 = 0;
loc_82262284:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822622d8
	if (cr6.eq) goto loc_822622D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82262298;
	sub_822A8108(ctx, base);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x822a8108
	ctx.lr = 0x822622A8;
	sub_822A8108(ctx, base);
	// lfs f13,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x822a8108
	ctx.lr = 0x822622B8;
	sub_822A8108(ctx, base);
	// lfs f12,56(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// xor r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 ^ r11.u64;
	// xor r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// xor r27,r7,r27
	r27.u64 = ctx.r7.u64 ^ r27.u64;
loc_822622D8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82262224
	if (!cr0.eq) goto loc_82262224;
loc_822622E4:
	// clrlwi r3,r27,31
	ctx.r3.u64 = r27.u32 & 0x1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822622F0"))) PPC_WEAK_FUNC(sub_822622F0);
PPC_FUNC_IMPL(__imp__sub_822622F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,-5008(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5008);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// lwz r11,16(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82262320"))) PPC_WEAK_FUNC(sub_82262320);
PPC_FUNC_IMPL(__imp__sub_82262320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lbz r9,2620(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 2620);
	// rlwinm r8,r9,26,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x1;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226233C"))) PPC_WEAK_FUNC(sub_8226233C);
PPC_FUNC_IMPL(__imp__sub_8226233C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82262340"))) PPC_WEAK_FUNC(sub_82262340);
PPC_FUNC_IMPL(__imp__sub_82262340) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lbz r10,2620(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2620);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82262370
	if (!cr6.eq) goto loc_82262370;
	// lwz r10,1888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1888);
	// lwz r11,1892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1892);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82262374
	if (!cr6.lt) goto loc_82262374;
loc_82262370:
	// li r11,0
	r11.s64 = 0;
loc_82262374:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82262384"))) PPC_WEAK_FUNC(sub_82262384);
PPC_FUNC_IMPL(__imp__sub_82262384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82262388"))) PPC_WEAK_FUNC(sub_82262388);
PPC_FUNC_IMPL(__imp__sub_82262388) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82262398:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82262398
	if (cr6.eq) goto loc_82262398;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lwz r3,-5008(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5008);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822623C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822623C4:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822623c4
	if (cr6.eq) goto loc_822623C4;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822623E8"))) PPC_WEAK_FUNC(sub_822623E8);
PPC_FUNC_IMPL(__imp__sub_822623E8) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,-12348(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82390f38
	ctx.lr = 0x82262410;
	sub_82390F38(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82262434
	if (!cr6.eq) goto loc_82262434;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82262434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82262434:
	// lbz r11,76(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226247c
	if (cr6.eq) goto loc_8226247C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822621d8
	ctx.lr = 0x8226244C;
	sub_822621D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82262468
	if (cr6.eq) goto loc_82262468;
	// lbz r11,52(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 52);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stb r10,52(r31)
	PPC_STORE_U8(r31.u32 + 52, ctx.r10.u8);
	// b 0x822624b0
	goto loc_822624B0;
loc_82262468:
	// lbz r11,52(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 52);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stb r10,52(r31)
	PPC_STORE_U8(r31.u32 + 52, ctx.r10.u8);
	// b 0x822624b0
	goto loc_822624B0;
loc_8226247C:
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822624b0
	if (cr6.eq) goto loc_822624B0;
	// lbz r11,52(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 52);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r31,r11,30,31,31
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// bl 0x822621d8
	ctx.lr = 0x82262498;
	sub_822621D8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// beq cr6,0x822624b0
	if (cr6.eq) goto loc_822624B0;
	// lbz r11,2620(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stb r10,2620(r30)
	PPC_STORE_U8(r30.u32 + 2620, ctx.r10.u8);
loc_822624B0:
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

__attribute__((alias("__imp__sub_822624C8"))) PPC_WEAK_FUNC(sub_822624C8);
PPC_FUNC_IMPL(__imp__sub_822624C8) {
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
	// b 0x82262388
	sub_82262388(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822624E4"))) PPC_WEAK_FUNC(sub_822624E4);
PPC_FUNC_IMPL(__imp__sub_822624E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822624E8"))) PPC_WEAK_FUNC(sub_822624E8);
PPC_FUNC_IMPL(__imp__sub_822624E8) {
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
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,9416
	ctx.r4.s64 = r11.s64 + 9416;
	// addi r3,r10,-9672
	ctx.r3.s64 = ctx.r10.s64 + -9672;
	// bl 0x82554798
	ctx.lr = 0x82262508;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,8944
	ctx.r4.s64 = ctx.r9.s64 + 8944;
	// addi r3,r8,-9688
	ctx.r3.s64 = ctx.r8.s64 + -9688;
	// bl 0x82554798
	ctx.lr = 0x8226251C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,4216
	ctx.r4.s64 = ctx.r7.s64 + 4216;
	// addi r3,r6,-9716
	ctx.r3.s64 = ctx.r6.s64 + -9716;
	// bl 0x82554798
	ctx.lr = 0x82262530;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,8992
	ctx.r4.s64 = ctx.r5.s64 + 8992;
	// addi r3,r3,-9744
	ctx.r3.s64 = ctx.r3.s64 + -9744;
	// bl 0x82554798
	ctx.lr = 0x82262544;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,9024
	ctx.r4.s64 = r11.s64 + 9024;
	// addi r3,r10,-9780
	ctx.r3.s64 = ctx.r10.s64 + -9780;
	// bl 0x82554798
	ctx.lr = 0x82262558;
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

__attribute__((alias("__imp__sub_82262568"))) PPC_WEAK_FUNC(sub_82262568);
PPC_FUNC_IMPL(__imp__sub_82262568) {
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
	// bl 0x821c8ed8
	ctx.lr = 0x82262580;
	sub_821C8ED8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lfs f0,12428(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	f0.f64 = double(temp.f32);
	// lfs f13,31296(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31296);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// lfs f12,15004(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 15004);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// lfs f11,-9332(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -9332);
	ctx.f11.f64 = double(temp.f32);
	// stw r6,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r6.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stfs f13,80(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stfs f12,84(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stfs f11,88(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// addi r10,r31,60
	ctx.r10.s64 = r31.s64 + 60;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82262600"))) PPC_WEAK_FUNC(sub_82262600);
PPC_FUNC_IMPL(__imp__sub_82262600) {
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
	ctx.lr = 0x82262608;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x8226261C;
	sub_82180430(ctx, base);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r8,2
	ctx.r8.s64 = 2;
	// stb r11,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r11.u8);
	// stb r10,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// addi r4,r7,-9180
	ctx.r4.s64 = ctx.r7.s64 + -9180;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,128
	ctx.r7.s64 = 128;
	// li r6,128
	ctx.r6.s64 = 128;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226266C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-9192
	ctx.r4.s64 = ctx.r8.s64 + -9192;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r6,128
	ctx.r6.s64 = 128;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// li r7,128
	ctx.r7.s64 = 128;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822626A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// addi r29,r9,30576
	r29.s64 = ctx.r9.s64 + 30576;
	// addi r4,r8,-9216
	ctx.r4.s64 = ctx.r8.s64 + -9216;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
	// bl 0x821ca540
	ctx.lr = 0x822626C8;
	sub_821CA540(ctx, base);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-9244
	ctx.r4.s64 = ctx.r7.s64 + -9244;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822626E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-9272
	ctx.r4.s64 = ctx.r10.s64 + -9272;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8226270C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-9300
	ctx.r4.s64 = ctx.r7.s64 + -9300;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82262730;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-9328
	ctx.r4.s64 = ctx.r10.s64 + -9328;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82262754;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82262760;
	sub_821C9A90(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82262768"))) PPC_WEAK_FUNC(sub_82262768);
PPC_FUNC_IMPL(__imp__sub_82262768) {
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
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x82262780;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262790
	if (cr6.eq) goto loc_82262790;
	// bl 0x82262568
	ctx.lr = 0x8226278C;
	sub_82262568(ctx, base);
	// b 0x82262794
	goto loc_82262794;
loc_82262790:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82262794:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,-4944
	r31.s64 = r11.s64 + -4944;
	// stw r3,-4944(r11)
	PPC_STORE_U32(r11.u32 + -4944, ctx.r3.u32);
	// bl 0x82262600
	ctx.lr = 0x822627A4;
	sub_82262600(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822627BC"))) PPC_WEAK_FUNC(sub_822627BC);
PPC_FUNC_IMPL(__imp__sub_822627BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822627C0"))) PPC_WEAK_FUNC(sub_822627C0);
PPC_FUNC_IMPL(__imp__sub_822627C0) {
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
	ctx.lr = 0x822627C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x822627E4;
	sub_821C8FE0(ctx, base);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mulli r11,r30,368
	r11.s64 = r30.s64 * 368;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82264c90
	ctx.lr = 0x822627FC;
	sub_82264C90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82262804;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226280C"))) PPC_WEAK_FUNC(sub_8226280C);
PPC_FUNC_IMPL(__imp__sub_8226280C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82262810"))) PPC_WEAK_FUNC(sub_82262810);
PPC_FUNC_IMPL(__imp__sub_82262810) {
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
	ctx.lr = 0x82262818;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x82262830;
	sub_821C8FE0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r31,32(r28)
	PPC_STORE_U32(r28.u32 + 32, r31.u32);
	// beq cr6,0x82262888
	if (cr6.eq) goto loc_82262888;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82262888
	if (cr6.eq) goto loc_82262888;
	// li r30,0
	r30.s64 = 0;
loc_82262850:
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82265fe0
	ctx.lr = 0x82262864;
	sub_82265FE0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82264fd0
	ctx.lr = 0x82262870;
	sub_82264FD0(ctx, base);
	// lwz r10,32(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,368
	r30.s64 = r30.s64 + 368;
	// lhz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82262850
	if (cr6.lt) goto loc_82262850;
loc_82262888:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82262890;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82262898"))) PPC_WEAK_FUNC(sub_82262898);
PPC_FUNC_IMPL(__imp__sub_82262898) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822628A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r29,36(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822628f4
	if (cr6.eq) goto loc_822628F4;
loc_822628B4:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822628e8
	if (cr6.eq) goto loc_822628E8;
	// li r31,0
	r31.s64 = 0;
loc_822628C8:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82266dd0
	ctx.lr = 0x822628D4;
	sub_82266DD0(ctx, base);
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,368
	r31.s64 = r31.s64 + 368;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822628c8
	if (cr6.lt) goto loc_822628C8;
loc_822628E8:
	// lwz r29,0(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x822628b4
	if (!cr6.eq) goto loc_822628B4;
loc_822628F4:
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82262948
	if (!cr6.eq) goto loc_82262948;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,-12556(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12556);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,-12572(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -12572);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	f0.f64 = double(temp.f32);
	// fnmsubs f12,f0,f13,f12
	ctx.f12.f64 = double(float(-(f0.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// lfs f13,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsel f11,f12,f12,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f0,f10,f0,f11
	f0.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// stfs f0,-12556(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12556, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82262948:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,-12556(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12556, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226295C"))) PPC_WEAK_FUNC(sub_8226295C);
PPC_FUNC_IMPL(__imp__sub_8226295C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82262960"))) PPC_WEAK_FUNC(sub_82262960);
PPC_FUNC_IMPL(__imp__sub_82262960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f15{};
	PPCRegister f16{};
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v122{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82262968;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9a4
	ctx.lr = 0x82262970;
	// addi r12,r1,-288
	r12.s64 = ctx.r1.s64 + -288;
	// bl 0x823dd524
	ctx.lr = 0x82262978;
	// stwu r1,-1728(r1)
	ea = -1728 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8226298C;
	sub_821C8FE0(ctx, base);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r10,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r10.u32);
	// beq cr6,0x82263108
	if (cr6.eq) goto loc_82263108;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-4920(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4920);
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822629dc
	if (!cr6.eq) goto loc_822629DC;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r11,-4920(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4920, r11.u32);
loc_822629C8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822629c8
	if (cr6.eq) goto loc_822629C8;
	// std r11,-4928(r9)
	PPC_STORE_U64(ctx.r9.u32 + -4928, r11.u64);
loc_822629DC:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822629dc
	if (cr6.eq) goto loc_822629DC;
	// ld r10,-4928(r9)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r9.u32 + -4928);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r24,0
	r24.s64 = 0;
	// subf r7,r10,r11
	ctx.r7.s64 = r11.s64 - ctx.r10.s64;
	// std r7,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r7.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,-9360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -9360);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lhz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// fmuls f15,f12,f0
	f15.f64 = double(float(ctx.f12.f64 * f0.f64));
	// blt cr6,0x82262b50
	if (cr6.lt) goto loc_82262B50;
	// addic. r6,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r6.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// beq 0x82262a70
	if (cr0.eq) goto loc_82262A70;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r10,r11,200
	ctx.r10.s64 = r11.s64 + 200;
loc_82262A38:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82262a50
	if (cr6.eq) goto loc_82262A50;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// mr r11,r24
	r11.u64 = r24.u64;
	// bne cr6,0x82262a54
	if (!cr6.eq) goto loc_82262A54;
loc_82262A50:
	// li r11,1
	r11.s64 = 1;
loc_82262A54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82262a70
	if (!cr6.eq) goto loc_82262A70;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 + 368;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// bne cr6,0x82262a38
	if (!cr6.eq) goto loc_82262A38;
loc_82262A70:
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mulli r11,r7,368
	r11.s64 = ctx.r7.s64 * 368;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r5,112
	ctx.r5.s64 = 112;
	// li r6,64
	ctx.r6.s64 = 64;
	// li r4,144
	ctx.r4.s64 = 144;
	// lbz r9,331(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 331);
	// lvx128 v122,r11,r5
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82262aa0
	if (cr6.eq) goto loc_82262AA0;
	// lvx128 v123,r11,r4
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82262ad0
	goto loc_82262AD0;
loc_82262AA0:
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// twllei r8,0
	// divw r3,r9,r8
	ctx.r3.s32 = ctx.r9.s32 / ctx.r8.s32;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r3,r3,r8
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// subf r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// mulli r11,r9,368
	r11.s64 = ctx.r9.s64 * 368;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// andc r9,r8,r3
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r3.u64;
	// twlgei r9,-1
	// lvx128 v123,r11,r6
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82262AD0:
	// addic. r9,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r9.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge 0x82262adc
	if (!cr0.lt) goto loc_82262ADC;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
loc_82262ADC:
	// mulli r11,r9,368
	r11.s64 = ctx.r9.s64 * 368;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r3,331(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 331);
	// lvx128 v124,r11,r5
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262afc
	if (cr6.eq) goto loc_82262AFC;
	// lvx128 v125,r11,r4
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82262b2c
	goto loc_82262B2C;
loc_82262AFC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// twllei r8,0
	// divw r5,r9,r8
	ctx.r5.s32 = ctx.r9.s32 / ctx.r8.s32;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r4,r5,r8
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// subf r3,r4,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r4.s64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// mulli r11,r3,368
	r11.s64 = ctx.r3.s64 * 368;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// andc r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// twlgei r4,-1
	// lvx128 v125,r5,r6
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82262B2C:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// beq cr6,0x82262b70
	if (cr6.eq) goto loc_82262B70;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// stw r7,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r7.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
	// b 0x82262b70
	goto loc_82262B70;
loc_82262B50:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v122,r0,r11
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v124,r0,r10
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v123,r0,r9
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r0,r8
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82262B70:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// lwz r30,-26876(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// bl 0x82189e20
	ctx.lr = 0x82262B8C;
	sub_82189E20(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82189e20
	ctx.lr = 0x82262B98;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x82262BA4;
	sub_8217F768(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r11,17320(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82262bbc
	if (!cr6.lt) goto loc_82262BBC;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_82262BBC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x82262BC4;
	sub_8217F768(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r11,r30,112
	r11.s64 = r30.s64 + 112;
	// lfs f27,-28964(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28964);
	f27.f64 = double(temp.f32);
	// lfs f28,-9152(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -9152);
	f28.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f29,-9156(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -9156);
	f29.f64 = double(temp.f32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// lfs f21,-12084(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -12084);
	f21.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f22,-15468(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -15468);
	f22.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f16,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f16.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lfs f26,-9160(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9160);
	f26.f64 = double(temp.f32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lfs f17,11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	f17.f64 = double(temp.f32);
	// lfs f18,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	f18.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f30,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f23,-9164(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -9164);
	f23.f64 = double(temp.f32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lfs f19,-9168(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -9168);
	f19.f64 = double(temp.f32);
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// lfs f20,-31376(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -31376);
	f20.f64 = double(temp.f32);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r20,-256
	r20.s64 = -16777216;
	// mr r23,r24
	r23.u64 = r24.u64;
	// li r19,-1
	r19.s64 = -1;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// lis r25,-32124
	r25.s64 = -2105278464;
	// lis r22,-32124
	r22.s64 = -2105278464;
	// addi r18,r11,-31664
	r18.s64 = r11.s64 + -31664;
	// addi r17,r10,-31648
	r17.s64 = ctx.r10.s64 + -31648;
	// addi r16,r9,2240
	r16.s64 = ctx.r9.s64 + 2240;
	// addi r15,r8,2528
	r15.s64 = ctx.r8.s64 + 2528;
	// addi r14,r7,29952
	r14.s64 = ctx.r7.s64 + 29952;
	// addi r21,r6,-31280
	r21.s64 = ctx.r6.s64 + -31280;
loc_82262C94:
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// vor128 v127,v122,v122
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)v122.u8));
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// vor128 v126,v123,v123
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// bne cr6,0x82262cb4
	if (!cr6.eq) goto loc_82262CB4;
	// lwz r5,56(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// vor128 v127,v124,v124
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// vor128 v126,v125,v125
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
loc_82262CB4:
	// lwz r3,-25232(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -25232);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82262CE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82178370
	ctx.lr = 0x82262CFC;
	sub_82178370(ctx, base);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x8217d5e8
	ctx.lr = 0x82262D04;
	sub_8217D5E8(ctx, base);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// lfs f1,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// fmr f4,f17
	ctx.f4.f64 = f17.f64;
	// fmr f3,f18
	ctx.f3.f64 = f18.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8217d460
	ctx.lr = 0x82262D1C;
	sub_8217D460(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x8217c658
	ctx.lr = 0x82262D28;
	sub_8217C658(ctx, base);
	// stfs f30,224(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f31,228(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stfs f31,232(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// stfs f31,240(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f30,244(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f31,248(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f31,256(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lwz r3,-26876(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// stfs f31,260(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f30,264(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f31,272(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f31,276(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f16,280(r1)
	temp.f32 = float(f16.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// bl 0x8217ce80
	ctx.lr = 0x82262D68;
	sub_8217CE80(ctx, base);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// lvx128 v62,r21,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lvx128 v61,r21,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r21,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82256058
	ctx.lr = 0x82262DA8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262df4
	if (cr6.eq) goto loc_82262DF4;
	// bl 0x82256058
	ctx.lr = 0x82262DB4;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82262df4
	if (!cr6.eq) goto loc_82262DF4;
	// lfs f0,24(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r14.u32 + 24);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f20
	ctx.f1.f64 = double(float(f0.f64 * f20.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82262DCC;
	sub_823DBAE8(ctx, base);
	// lfs f0,24(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r14.u32 + 24);
	f0.f64 = double(temp.f32);
	// frsp f25,f1
	f25.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f0,f20
	ctx.f1.f64 = double(float(f0.f64 * f20.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x82262DDC;
	sub_823DBBC8(ctx, base);
	// lvx128 v61,r0,r15
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lvx128 v62,r0,r16
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r17
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r18
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82262e50
	goto loc_82262E50;
loc_82262DF4:
	// vsubfp128 v63,v126,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// lvx128 v61,r0,r15
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r16
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// vor128 v0,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// lvx128 v60,r0,r17
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r18
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// vmsum3fp128 v59,v63,v63
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v58,v59
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vcmpeqfp128 v11,v58,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v60,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v57,v63,v6
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,200(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	f0.f64 = double(temp.f32);
	// lfs f25,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	f25.f64 = double(temp.f32);
loc_82262E50:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// vor128 v0,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v56,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v127.f32)));
	// vmsum3fp128 v55,v63,v63
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v54,v55
	simde_mm_store_ps(v54.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v55.f32))));
	// vor128 v12,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vcmpeqfp128 v11,v54,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v60,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v53,v63,v6
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f25
	ctx.f11.f64 = double(float(ctx.f13.f64 * f25.f64));
	// fmuls f10,f12,f25
	ctx.f10.f64 = double(float(ctx.f12.f64 * f25.f64));
	// fmadds f25,f12,f0,f11
	f25.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f11.f64));
	// fmsubs f1,f13,f0,f10
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64 - ctx.f10.f64));
	// fmr f2,f25
	ctx.f2.f64 = f25.f64;
	// bl 0x823dcdd8
	ctx.lr = 0x82262EBC;
	sub_823DCDD8(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// fsubs f24,f19,f9
	f24.f64 = double(float(f19.f64 - ctx.f9.f64));
	// bl 0x82256058
	ctx.lr = 0x82262EC8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262ee8
	if (cr6.eq) goto loc_82262EE8;
	// bl 0x82256058
	ctx.lr = 0x82262ED4;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82262ee8
	if (!cr6.eq) goto loc_82262EE8;
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x82262eec
	goto loc_82262EEC;
loc_82262EE8:
	// fabs f0,f25
	ctx.fpscr.disableFlushMode();
	f0.u64 = f25.u64 & ~0x8000000000000000;
loc_82262EEC:
	// lfs f13,288(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f30,f0
	ctx.f12.f64 = double(float(f30.f64 - f0.f64));
	// lfs f11,308(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f13,f22
	ctx.f10.f64 = double(float(ctx.f13.f64 * f22.f64));
	// fmuls f9,f11,f21
	ctx.f9.f64 = double(float(ctx.f11.f64 * f21.f64));
	// stfs f10,288(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f9,308(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lfs f8,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fneg f1,f24
	ctx.f1.u64 = f24.u64 ^ 0x8000000000000000;
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmadds f25,f12,f23,f7
	f25.f64 = double(float(ctx.f12.f64 * f23.f64 + ctx.f7.f64));
	// bl 0x82235ee0
	ctx.lr = 0x82262F20;
	sub_82235EE0(ctx, base);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// bl 0x82235e30
	ctx.lr = 0x82262F2C;
	sub_82235E30(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82262F3C;
	sub_8217C088(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82262F40;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82262f60
	if (cr6.eq) goto loc_82262F60;
	// bl 0x82256058
	ctx.lr = 0x82262F4C;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82262f60
	if (!cr6.eq) goto loc_82262F60;
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x82262f98
	goto loc_82262F98;
loc_82262F60:
	// lfs f0,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f0.f64 = double(temp.f32);
	// lis r11,21845
	r11.s64 = 1431633920;
	// fmuls f13,f0,f15
	ctx.f13.f64 = double(float(f0.f64 * f15.f64));
	// ori r10,r11,21846
	ctx.r10.u64 = r11.u64 | 21846;
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,208(r1)
	PPC_STORE_U64(ctx.r1.u32 + 208, ctx.f12.u64);
	// lwz r9,212(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// mulhw r11,r9,r10
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r8,r9
	r11.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_82262F98:
	// addi r11,r11,15
	r11.s64 = r11.s64 + 15;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x8217d9a0
	ctx.lr = 0x82262FA8;
	sub_8217D9A0(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x82262FB4;
	sub_8217BB68(ctx, base);
	// mr r9,r19
	ctx.r9.u64 = r19.u64;
	// stfs f29,-26916(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r26.u32 + -26916, temp.u32);
	// fmr f8,f28
	ctx.f8.f64 = f28.f64;
	// stfs f28,-26924(r27)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// stw r9,-26892(r25)
	PPC_STORE_U32(r25.u32 + -26892, ctx.r9.u32);
	// lfs f0,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	f0.f64 = double(temp.f32);
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f7,f29
	ctx.f7.f64 = f29.f64;
	// lfs f5,-26908(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f4,-26928(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f2,f1
	ctx.f2.f64 = ctx.f1.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82262FEC;
	sub_8217BC28(ctx, base);
	// stfs f27,-26916(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r26.u32 + -26916, temp.u32);
	// stfs f28,-26924(r27)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// lwz r9,-26892(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + -26892);
	// lfs f1,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// fmr f8,f28
	ctx.f8.f64 = f28.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f7,f27
	ctx.f7.f64 = f27.f64;
	// lfs f5,-26908(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f4,-26928(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fneg f2,f1
	ctx.f2.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// bl 0x8217bc28
	ctx.lr = 0x8226301C;
	sub_8217BC28(ctx, base);
	// stfs f29,-26916(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r26.u32 + -26916, temp.u32);
	// stfs f26,-26924(r27)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// lwz r9,-26892(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + -26892);
	// lfs f13,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmr f8,f26
	ctx.f8.f64 = f26.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f7,f29
	ctx.f7.f64 = f29.f64;
	// lfs f5,-26908(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f4,-26928(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f2,f13
	ctx.f2.f64 = ctx.f13.f64;
	// fneg f1,f13
	ctx.f1.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// bl 0x8217bc28
	ctx.lr = 0x82263050;
	sub_8217BC28(ctx, base);
	// stfs f27,-26916(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r26.u32 + -26916, temp.u32);
	// lwz r9,-26892(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + -26892);
	// stfs f26,-26924(r27)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// fmr f8,f26
	ctx.f8.f64 = f26.f64;
	// lfs f1,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// fmr f7,f27
	ctx.f7.f64 = f27.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f5,-26908(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f1
	ctx.f2.f64 = ctx.f1.f64;
	// lfs f4,-26928(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x82263080;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x82263084;
	sub_8217BC98(ctx, base);
	// lwz r3,-25232(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -25232);
	// li r11,1
	r11.s64 = 1;
	// stfs f30,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f30,148(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stw r20,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r20.u32);
	// stw r24,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r24.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r24,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r24.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stb r24,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, r24.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,167(r1)
	PPC_STORE_U8(ctx.r1.u32 + 167, r11.u8);
	// stb r11,168(r1)
	PPC_STORE_U8(ctx.r1.u32 + 168, r11.u8);
	// stb r24,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r24.u8);
	// stb r24,165(r1)
	PPC_STORE_U8(ctx.r1.u32 + 165, r24.u8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822630D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x8217cb48
	ctx.lr = 0x822630D8;
	sub_8217CB48(ctx, base);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// cmpwi cr6,r23,2
	cr6.compare<int32_t>(r23.s32, 2, xer);
	// blt cr6,0x82262c94
	if (cr6.lt) goto loc_82262C94;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e20
	ctx.lr = 0x822630F0;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82189e20
	ctx.lr = 0x822630FC;
	sub_82189E20(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x8217c658
	ctx.lr = 0x82263108;
	sub_8217C658(ctx, base);
loc_82263108:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x821c9030
	ctx.lr = 0x82263110;
	sub_821C9030(ctx, base);
	// addi r1,r1,1728
	ctx.r1.s64 = ctx.r1.s64 + 1728;
	// addi r12,r1,-288
	r12.s64 = ctx.r1.s64 + -288;
	// bl 0x823dd7bc
	ctx.lr = 0x8226311C;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9f0
	ctx.lr = 0x82263124;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82263128"))) PPC_WEAK_FUNC(sub_82263128);
PPC_FUNC_IMPL(__imp__sub_82263128) {
	PPC_FUNC_PROLOGUE();
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82263130;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82263144;
	sub_821C8FE0(ctx, base);
	// lwz r11,32(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822632b4
	if (cr6.eq) goto loc_822632B4;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x82263158;
	sub_82187BE0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217fed0
	ctx.lr = 0x82263160;
	sub_8217FED0(ctx, base);
	// lis r21,-32131
	r21.s64 = -2105737216;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,17320(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 17320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8226317c
	if (!cr6.lt) goto loc_8226317C;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_8226317C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x82263184;
	sub_8217F768(ctx, base);
	// bl 0x82478d80
	ctx.lr = 0x82263188;
	sub_82478D80(ctx, base);
	// lwz r10,32(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// li r29,0
	r29.s64 = 0;
	// lhz r11,8(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263298
	if (cr6.eq) goto loc_82263298;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lis r11,0
	r11.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// ori r22,r11,54609
	r22.u64 = r11.u64 | 54609;
	// lis r25,-1
	r25.s64 = -65536;
	// lwz r11,-26892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_822631C0:
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r3,r10,r28
	ctx.r3.u64 = ctx.r10.u64 + r28.u64;
	// lwz r10,200(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822631e0
	if (cr6.eq) goto loc_822631E0;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// bne cr6,0x822631e4
	if (!cr6.eq) goto loc_822631E4;
loc_822631E0:
	// li r10,1
	ctx.r10.s64 = 1;
loc_822631E4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82263200
	if (cr6.eq) goto loc_82263200;
	// lwz r11,192(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// lwz r10,52(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 52);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r11,-26892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -26892);
loc_82263200:
	// lhz r10,-26892(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + -26892);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// rlwinm r8,r11,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// lwz r7,-6148(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + -6148);
	// rlwimi r9,r10,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwimi r11,r6,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// mr r30,r11
	r30.u64 = r11.u64;
	// beq cr6,0x822632c4
	if (cr6.eq) goto loc_822632C4;
	// lbz r10,-6144(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822632c4
	if (cr6.eq) goto loc_822632C4;
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lbzx r10,r11,r22
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r22.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82263278
	if (!cr6.eq) goto loc_82263278;
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// bne cr6,0x82263260
	if (!cr6.eq) goto loc_82263260;
	// lis r11,-4
	r11.s64 = -262144;
	// ori r11,r11,5649
	r11.u64 = r11.u64 | 5649;
	// b 0x82263268
	goto loc_82263268;
loc_82263260:
	// lis r11,-234
	r11.s64 = -15335424;
	// ori r11,r11,64529
	r11.u64 = r11.u64 | 64529;
loc_82263268:
	// stw r11,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, r11.u32);
loc_8226326C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82263270:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82265bb0
	ctx.lr = 0x82263278;
	sub_82265BB0(ctx, base);
loc_82263278:
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, r11.u32);
	// addi r28,r28,368
	r28.s64 = r28.s64 + 368;
	// lwz r10,32(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// lhz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x822631c0
	if (cr6.lt) goto loc_822631C0;
loc_82263298:
	// lwz r11,17320(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 17320);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// cmpw cr6,r20,r11
	cr6.compare<int32_t>(r20.s32, r11.s32, xer);
	// ble cr6,0x822632ac
	if (!cr6.gt) goto loc_822632AC;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_822632AC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822632B4;
	sub_8217F768(ctx, base);
loc_822632B4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x822632BC;
	sub_821C9030(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_822632C4:
	// lwz r11,-5052(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -5052);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226326c
	if (!cr6.eq) goto loc_8226326C;
	// lwz r11,32(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// bge cr6,0x82263308
	if (!cr6.lt) goto loc_82263308;
	// lwz r11,200(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822632fc
	if (cr6.eq) goto loc_822632FC;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82263300
	if (!cr6.eq) goto loc_82263300;
loc_822632FC:
	// li r11,1
	r11.s64 = 1;
loc_82263300:
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// b 0x82263270
	goto loc_82263270;
loc_82263308:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8226326c
	if (!cr6.eq) goto loc_8226326C;
	// lwz r11,200(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226332c
	if (cr6.eq) goto loc_8226332C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82263330
	if (!cr6.eq) goto loc_82263330;
loc_8226332C:
	// li r11,1
	r11.s64 = 1;
loc_82263330:
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// b 0x82263270
	goto loc_82263270;
}

__attribute__((alias("__imp__sub_82263338"))) PPC_WEAK_FUNC(sub_82263338);
PPC_FUNC_IMPL(__imp__sub_82263338) {
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
	ctx.lr = 0x82263340;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822633d8
	if (cr6.eq) goto loc_822633D8;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822633d8
	if (cr6.eq) goto loc_822633D8;
	// addi r10,r4,50
	ctx.r10.s64 = ctx.r4.s64 + 50;
	// li r31,0
	r31.s64 = 0;
	// rlwinm r29,r10,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_82263378:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r11,r29,r3
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82263398
	if (cr6.eq) goto loc_82263398;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8226339c
	if (!cr6.eq) goto loc_8226339C;
loc_82263398:
	// li r11,1
	r11.s64 = 1;
loc_8226339C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822633c0
	if (cr6.eq) goto loc_822633C0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x822653a8
	ctx.lr = 0x822633B4;
	sub_822653A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822633e4
	if (!cr6.eq) goto loc_822633E4;
loc_822633C0:
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,368
	r31.s64 = r31.s64 + 368;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x82263378
	if (cr6.lt) goto loc_82263378;
loc_822633D8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822633E4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822633F0"))) PPC_WEAK_FUNC(sub_822633F0);
PPC_FUNC_IMPL(__imp__sub_822633F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822633F8;
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82263590
	if (cr6.eq) goto loc_82263590;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82263444
	if (cr6.eq) goto loc_82263444;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82263448
	if (cr6.eq) goto loc_82263448;
loc_82263444:
	// li r11,0
	r11.s64 = 0;
loc_82263448:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82263590
	if (!cr6.eq) goto loc_82263590;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// ble cr6,0x82263590
	if (!cr6.gt) goto loc_82263590;
	// lhz r11,8(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x82263590
	if (!cr6.lt) goto loc_82263590;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a8108
	ctx.lr = 0x82263470;
	sub_822A8108(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,48
	ctx.r10.s64 = 48;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lvx128 v127,r11,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8148
	ctx.lr = 0x82263484;
	sub_822A8148(ctx, base);
	// lvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// vmsum3fp128 v60,v61,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// vor128 v59,v127,v127
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r6,r8,2240
	ctx.r6.s64 = ctx.r8.s64 + 2240;
	// lwz r5,48(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r11,r4,-31648
	r11.s64 = ctx.r4.s64 + -31648;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,-31664
	ctx.r10.s64 = ctx.r3.s64 + -31664;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3732(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v58,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vrsqrtefp128 v56,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v11,v56,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v63,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v55,v61,v6
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp128 v59,v55,v57,v59
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v57.f32)), simde_mm_load_ps(v59.f32)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8226352c
	if (cr6.eq) goto loc_8226352C;
	// li r11,400
	r11.s64 = 400;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v54,r28,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82263534
	goto loc_82263534;
loc_8226352C:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82263534:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mulli r10,r31,368
	ctx.r10.s64 = r31.s64 * 368;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r29,50
	ctx.r9.s64 = r29.s64 + 50;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r3
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82263564
	if (cr6.eq) goto loc_82263564;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82263568
	if (!cr6.eq) goto loc_82263568;
loc_82263564:
	// li r11,1
	r11.s64 = 1;
loc_82263568:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263590
	if (cr6.eq) goto loc_82263590;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x822653a8
	ctx.lr = 0x82263580;
	sub_822653A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82263594
	if (!cr6.eq) goto loc_82263594;
loc_82263590:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82263594:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822635A4"))) PPC_WEAK_FUNC(sub_822635A4);
PPC_FUNC_IMPL(__imp__sub_822635A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822635A8"))) PPC_WEAK_FUNC(sub_822635A8);
PPC_FUNC_IMPL(__imp__sub_822635A8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,-4944(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x822635CC;
	sub_821C8FE0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// bl 0x821c9030
	ctx.lr = 0x822635DC;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_822635F0"))) PPC_WEAK_FUNC(sub_822635F0);
PPC_FUNC_IMPL(__imp__sub_822635F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// b 0x82262810
	sub_82262810(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82263600"))) PPC_WEAK_FUNC(sub_82263600);
PPC_FUNC_IMPL(__imp__sub_82263600) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82263624;
	sub_822A8108(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r5,r3,48
	ctx.r5.s64 = ctx.r3.s64 + 48;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82263648
	if (cr6.eq) goto loc_82263648;
	// li r11,400
	r11.s64 = 400;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82263654
	goto loc_82263654;
loc_82263648:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82263654:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// bl 0x82263338
	ctx.lr = 0x82263668;
	sub_82263338(ctx, base);
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

__attribute__((alias("__imp__sub_82263680"))) PPC_WEAK_FUNC(sub_82263680);
PPC_FUNC_IMPL(__imp__sub_82263680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mulli r10,r3,368
	ctx.r10.s64 = ctx.r3.s64 * 368;
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226369C"))) PPC_WEAK_FUNC(sub_8226369C);
PPC_FUNC_IMPL(__imp__sub_8226369C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822636A0"))) PPC_WEAK_FUNC(sub_822636A0);
PPC_FUNC_IMPL(__imp__sub_822636A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x822a8108
	ctx.lr = 0x822636C4;
	sub_822A8108(ctx, base);
	// li r10,48
	ctx.r10.s64 = 48;
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-9148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9148);
	ctx.f13.f64 = double(temp.f32);
	// ble cr6,0x82263760
	if (!cr6.gt) goto loc_82263760;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r30,32
	ctx.r8.s64 = r30.s64 + 32;
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,72
	r11.s64 = r11.s64 + 72;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_8226370C:
	// lwzx r6,r8,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x82263750
	if (!cr6.eq) goto loc_82263750;
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// lfs f6,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f0,f2
	f0.f64 = double(float(sqrt(ctx.f2.f64)));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82263750
	if (!cr6.gt) goto loc_82263750;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
loc_82263750:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 + 368;
	// addi r11,r11,368
	r11.s64 = r11.s64 + 368;
	// bne 0x8226370c
	if (!cr0.eq) goto loc_8226370C;
loc_82263760:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
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

__attribute__((alias("__imp__sub_8226377C"))) PPC_WEAK_FUNC(sub_8226377C);
PPC_FUNC_IMPL(__imp__sub_8226377C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263780"))) PPC_WEAK_FUNC(sub_82263780);
PPC_FUNC_IMPL(__imp__sub_82263780) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f1,-9148(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -9148);
	ctx.f1.f64 = double(temp.f32);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// addi r11,r10,72
	r11.s64 = ctx.r10.s64 + 72;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_822637A8:
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x822637f4
	if (!cr6.eq) goto loc_822637F4;
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f0,f3
	f0.f64 = double(float(sqrt(ctx.f3.f64)));
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822637f4
	if (!cr6.gt) goto loc_822637F4;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_822637F4:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,368
	r11.s64 = r11.s64 + 368;
	// bne 0x822637a8
	if (!cr0.eq) goto loc_822637A8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82263804"))) PPC_WEAK_FUNC(sub_82263804);
PPC_FUNC_IMPL(__imp__sub_82263804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263808"))) PPC_WEAK_FUNC(sub_82263808);
PPC_FUNC_IMPL(__imp__sub_82263808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82262810
	sub_82262810(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226381C"))) PPC_WEAK_FUNC(sub_8226381C);
PPC_FUNC_IMPL(__imp__sub_8226381C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263820"))) PPC_WEAK_FUNC(sub_82263820);
PPC_FUNC_IMPL(__imp__sub_82263820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r10,-4944(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4944);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mulli r9,r4,92
	ctx.r9.s64 = ctx.r4.s64 * 92;
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r10,32(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// addi r9,r11,50
	ctx.r9.s64 = r11.s64 + 50;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,66
	r31.s64 = r11.s64 + 66;
	// mulli r10,r4,368
	ctx.r10.s64 = ctx.r4.s64 * 368;
	// stwx r3,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r3.u32);
	// lwz r11,-4944(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4944);
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stfsx f0,r3,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + r11.u32, temp.u32);
	// stwx r5,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r5.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82263894"))) PPC_WEAK_FUNC(sub_82263894);
PPC_FUNC_IMPL(__imp__sub_82263894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263898"))) PPC_WEAK_FUNC(sub_82263898);
PPC_FUNC_IMPL(__imp__sub_82263898) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mulli r9,r9,368
	ctx.r9.s64 = ctx.r9.s64 * 368;
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r7,r10,50
	ctx.r7.s64 = ctx.r10.s64 + 50;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmpwi cr6,r6,3
	cr6.compare<int32_t>(ctx.r6.s32, 3, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r10,r10,66
	ctx.r10.s64 = ctx.r10.s64 + 66;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,1
	ctx.r6.s64 = 1;
	// stwx r6,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfsx f0,r7,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822638F0"))) PPC_WEAK_FUNC(sub_822638F0);
PPC_FUNC_IMPL(__imp__sub_822638F0) {
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
	// bl 0x82263600
	ctx.lr = 0x82263914;
	sub_82263600(ctx, base);
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

__attribute__((alias("__imp__sub_82263930"))) PPC_WEAK_FUNC(sub_82263930);
PPC_FUNC_IMPL(__imp__sub_82263930) {
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
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x822633f0
	ctx.lr = 0x82263960;
	sub_822633F0(ctx, base);
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

__attribute__((alias("__imp__sub_82263980"))) PPC_WEAK_FUNC(sub_82263980);
PPC_FUNC_IMPL(__imp__sub_82263980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mulli r10,r8,368
	ctx.r10.s64 = ctx.r8.s64 * 368;
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822639AC"))) PPC_WEAK_FUNC(sub_822639AC);
PPC_FUNC_IMPL(__imp__sub_822639AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822639B0"))) PPC_WEAK_FUNC(sub_822639B0);
PPC_FUNC_IMPL(__imp__sub_822639B0) {
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
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x822636a0
	ctx.lr = 0x822639E0;
	sub_822636A0(ctx, base);
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

__attribute__((alias("__imp__sub_822639FC"))) PPC_WEAK_FUNC(sub_822639FC);
PPC_FUNC_IMPL(__imp__sub_822639FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263A00"))) PPC_WEAK_FUNC(sub_82263A00);
PPC_FUNC_IMPL(__imp__sub_82263A00) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82263A24;
	sub_821C8FE0(ctx, base);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x82263A2C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82263a68
	if (cr6.eq) goto loc_82263A68;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
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
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// b 0x82263a6c
	goto loc_82263A6C;
loc_82263A68:
	// li r31,0
	r31.s64 = 0;
loc_82263A6C:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r31,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82263A80;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_82263A9C"))) PPC_WEAK_FUNC(sub_82263A9C);
PPC_FUNC_IMPL(__imp__sub_82263A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263AA0"))) PPC_WEAK_FUNC(sub_82263AA0);
PPC_FUNC_IMPL(__imp__sub_82263AA0) {
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
	ctx.lr = 0x82263AA8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lhz r11,26(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263ac4
	if (cr6.eq) goto loc_82263AC4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82263AC4;
	sub_82130588(ctx, base);
loc_82263AC4:
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263ad8
	if (cr6.eq) goto loc_82263AD8;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82263AD8;
	sub_82130588(ctx, base);
loc_82263AD8:
	// lhz r31,10(r30)
	r31.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82263b10
	if (cr6.eq) goto loc_82263B10;
	// lwz r29,4(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82263b08
	if (!cr6.gt) goto loc_82263B08;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82263AF4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82265240
	ctx.lr = 0x82263AFC;
	sub_82265240(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,368
	r30.s64 = r30.s64 + 368;
	// bne 0x82263af4
	if (!cr0.eq) goto loc_82263AF4;
loc_82263B08:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82263B10;
	sub_82130588(ctx, base);
loc_82263B10:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82263B18"))) PPC_WEAK_FUNC(sub_82263B18);
PPC_FUNC_IMPL(__imp__sub_82263B18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// b 0x82263a00
	sub_82263A00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82263B24"))) PPC_WEAK_FUNC(sub_82263B24);
PPC_FUNC_IMPL(__imp__sub_82263B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263B28"))) PPC_WEAK_FUNC(sub_82263B28);
PPC_FUNC_IMPL(__imp__sub_82263B28) {
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
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// bl 0x82263a00
	ctx.lr = 0x82263B48;
	sub_82263A00(ctx, base);
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

__attribute__((alias("__imp__sub_82263B64"))) PPC_WEAK_FUNC(sub_82263B64);
PPC_FUNC_IMPL(__imp__sub_82263B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263B68"))) PPC_WEAK_FUNC(sub_82263B68);
PPC_FUNC_IMPL(__imp__sub_82263B68) {
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
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x82263B90;
	sub_821C8FE0(ctx, base);
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x82263bb0
	if (!cr6.eq) goto loc_82263BB0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x82263be4
	goto loc_82263BE4;
loc_82263BB0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82263bf4
	if (cr6.eq) goto loc_82263BF4;
loc_82263BB8:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x82263bd4
	if (cr6.eq) goto loc_82263BD4;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82263bb8
	if (!cr6.eq) goto loc_82263BB8;
	// b 0x82263bf4
	goto loc_82263BF4;
loc_82263BD4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_82263BE4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82263aa0
	ctx.lr = 0x82263BEC;
	sub_82263AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82263BF4;
	sub_82130588(ctx, base);
loc_82263BF4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82263BFC;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_82263C14"))) PPC_WEAK_FUNC(sub_82263C14);
PPC_FUNC_IMPL(__imp__sub_82263C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82263C18"))) PPC_WEAK_FUNC(sub_82263C18);
PPC_FUNC_IMPL(__imp__sub_82263C18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// b 0x82263b68
	sub_82263B68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82263C28"))) PPC_WEAK_FUNC(sub_82263C28);
PPC_FUNC_IMPL(__imp__sub_82263C28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f31{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82263C30;
	// stfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-9136
	ctx.r4.s64 = ctx.r9.s64 + -9136;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// bl 0x823db670
	ctx.lr = 0x82263C70;
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
	ctx.lr = 0x82263C84;
	sub_821FD7C0(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// li r20,0
	r20.s64 = 0;
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// lwz r3,324(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// stb r20,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r20.u8);
	// stw r20,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r20.u32);
	// stw r8,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r8.u32);
	// bl 0x822031a8
	ctx.lr = 0x82263CA8;
	sub_822031A8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82263cc0
	if (cr6.eq) goto loc_82263CC0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82263CC0:
	// rlwinm r11,r19,1,0,30
	r11.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// li r18,1
	r18.s64 = 1;
	// add r11,r19,r11
	r11.u64 = r19.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// lwz r11,32(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82263d48
	if (!cr6.eq) goto loc_82263D48;
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x82263f50
	if (!cr6.gt) goto loc_82263F50;
	// lis r11,32767
	r11.s64 = 2147418112;
	// addi r9,r31,40
	ctx.r9.s64 = r31.s64 + 40;
	// ori r22,r11,65535
	r22.u64 = r11.u64 | 65535;
loc_82263CFC:
	// cmpw cr6,r10,r19
	cr6.compare<int32_t>(ctx.r10.s32, r19.s32, xer);
	// beq cr6,0x82263d28
	if (cr6.eq) goto loc_82263D28;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r11,r22
	cr6.compare<int32_t>(r11.s32, r22.s32, xer);
	// beq cr6,0x82263d28
	if (cr6.eq) goto loc_82263D28;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82263d28
	if (cr6.eq) goto loc_82263D28;
	// lwz r8,40(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bge cr6,0x82263d28
	if (!cr6.lt) goto loc_82263D28;
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
loc_82263D28:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,192
	ctx.r9.s64 = ctx.r9.s64 + 192;
	// cmpw cr6,r10,r21
	cr6.compare<int32_t>(ctx.r10.s32, r21.s32, xer);
	// blt cr6,0x82263cfc
	if (cr6.lt) goto loc_82263CFC;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82263D48:
	// lwz r9,8(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r9,48(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82263d68
	if (!cr6.eq) goto loc_82263D68;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82263D68:
	// lwz r6,28(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mulli r8,r11,368
	ctx.r8.s64 = r11.s64 * 368;
	// lwz r3,36(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// lvx128 v63,r6,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r26,r8,r9
	r26.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r3,r10
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// add r27,r10,r11
	r27.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82264f38
	ctx.lr = 0x82263DA0;
	sub_82264F38(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x82387a18
	ctx.lr = 0x82263DA8;
	sub_82387A18(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r28,r20
	r28.u64 = r20.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x82263eac
	if (!cr6.gt) goto loc_82263EAC;
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r31,r31,36
	r31.s64 = r31.s64 + 36;
	// ori r22,r9,65535
	r22.u64 = ctx.r9.u64 | 65535;
	// addi r25,r11,-12656
	r25.s64 = r11.s64 + -12656;
	// addi r24,r10,-12632
	r24.s64 = ctx.r10.s64 + -12632;
loc_82263DD4:
	// cmpw cr6,r28,r19
	cr6.compare<int32_t>(r28.s32, r19.s32, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
	// lwz r30,-28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82263e44
	if (cr6.eq) goto loc_82263E44;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x82263E18;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82263e44
	if (cr6.eq) goto loc_82263E44;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82263e44
	if (cr6.eq) goto loc_82263E44;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82263E34;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x82263e9c
	if (cr6.eq) goto loc_82263E9C;
loc_82263E44:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// bgt cr6,0x82263e98
	if (cr6.gt) goto loc_82263E98;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpw cr6,r10,r22
	cr6.compare<int32_t>(ctx.r10.s32, r22.s32, xer);
	// beq cr6,0x82263e74
	if (cr6.eq) goto loc_82263E74;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82263e98
	if (!cr6.eq) goto loc_82263E98;
loc_82263E74:
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// bne cr6,0x82263e9c
	if (!cr6.eq) goto loc_82263E9C;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r4,r11,64
	ctx.r4.s64 = r11.s64 + 64;
	// bl 0x82264f38
	ctx.lr = 0x82263E90;
	sub_82264F38(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x82263e9c
	if (!cr6.lt) goto loc_82263E9C;
loc_82263E98:
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
loc_82263E9C:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// cmpw cr6,r28,r21
	cr6.compare<int32_t>(r28.s32, r21.s32, xer);
	// blt cr6,0x82263dd4
	if (cr6.lt) goto loc_82263DD4;
loc_82263EAC:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82263f50
	if (!cr6.eq) goto loc_82263F50;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// bne cr6,0x82263f50
	if (!cr6.eq) goto loc_82263F50;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,-4940(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4940);
	// cmplw cr6,r9,r29
	cr6.compare<uint32_t>(ctx.r9.u32, r29.u32, xer);
	// beq cr6,0x82263ee8
	if (cr6.eq) goto loc_82263EE8;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// stw r29,-4940(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4940, r29.u32);
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x82263f10
	goto loc_82263F10;
loc_82263EE8:
	// lwz r10,-4936(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4936);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82263f0c
	if (!cr6.eq) goto loc_82263F0C;
	// cmpwi cr6,r18,1
	cr6.compare<int32_t>(r18.s32, 1, xer);
	// beq cr6,0x82263f24
	if (cr6.eq) goto loc_82263F24;
	// lwz r10,-4932(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4932);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x82263f28
	goto loc_82263F28;
loc_82263F0C:
	// lwz r6,-4932(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4932);
loc_82263F10:
	// cmpwi cr6,r18,1
	cr6.compare<int32_t>(r18.s32, 1, xer);
	// bne cr6,0x82263f28
	if (!cr6.eq) goto loc_82263F28;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x82263f28
	goto loc_82263F28;
loc_82263F24:
	// lwz r6,-4932(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4932);
loc_82263F28:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r18,-4936(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4936, r18.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r10,-9144
	ctx.r4.s64 = ctx.r10.s64 + -9144;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82263F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82263F50:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82263F60"))) PPC_WEAK_FUNC(sub_82263F60);
PPC_FUNC_IMPL(__imp__sub_82263F60) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82263F68;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-9136
	ctx.r4.s64 = ctx.r9.s64 + -9136;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// bl 0x823db670
	ctx.lr = 0x82263FA8;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x82263FBC;
	sub_821FD7C0(ctx, base);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r21,0
	r21.s64 = 0;
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// lwz r3,308(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// stb r21,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r21.u8);
	// stw r21,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r21.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// bl 0x822031a8
	ctx.lr = 0x82263FE0;
	sub_822031A8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82263ff8
	if (cr6.eq) goto loc_82263FF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82263FF8:
	// rlwinm r11,r24,1,0,30
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 1) & 0xFFFFFFFE;
	// li r20,1
	r20.s64 = 1;
	// add r11,r24,r11
	r11.u64 = r24.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r8,r11,r30
	ctx.r8.u64 = r11.u64 + r30.u64;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lwz r10,32(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x82264080
	if (!cr6.eq) goto loc_82264080;
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x82264254
	if (!cr6.gt) goto loc_82264254;
	// lis r11,32767
	r11.s64 = 2147418112;
	// addi r9,r30,40
	ctx.r9.s64 = r30.s64 + 40;
	// ori r7,r11,65535
	ctx.r7.u64 = r11.u64 | 65535;
loc_82264034:
	// cmpw cr6,r10,r24
	cr6.compare<int32_t>(ctx.r10.s32, r24.s32, xer);
	// beq cr6,0x82264060
	if (cr6.eq) goto loc_82264060;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// beq cr6,0x82264060
	if (cr6.eq) goto loc_82264060;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82264060
	if (cr6.eq) goto loc_82264060;
	// lwz r6,40(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bge cr6,0x82264060
	if (!cr6.lt) goto loc_82264060;
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
loc_82264060:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,192
	ctx.r9.s64 = ctx.r9.s64 + 192;
	// cmpw cr6,r10,r22
	cr6.compare<int32_t>(ctx.r10.s32, r22.s32, xer);
	// blt cr6,0x82264034
	if (cr6.lt) goto loc_82264034;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82264080:
	// lwz r9,8(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r9,48(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822640a0
	if (!cr6.eq) goto loc_822640A0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_822640A0:
	// lwz r8,36(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r9,28(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// addi r5,r9,64
	ctx.r5.s64 = ctx.r9.s64 + 64;
	// add r27,r11,r10
	r27.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82263780
	ctx.lr = 0x822640C0;
	sub_82263780(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x82387a18
	ctx.lr = 0x822640C8;
	sub_82387A18(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r28,r21
	r28.u64 = r21.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x822641b0
	if (!cr6.gt) goto loc_822641B0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r29,r30,36
	r29.s64 = r30.s64 + 36;
	// addi r26,r11,-12656
	r26.s64 = r11.s64 + -12656;
	// addi r25,r10,-12632
	r25.s64 = ctx.r10.s64 + -12632;
loc_822640EC:
	// cmpw cr6,r28,r24
	cr6.compare<int32_t>(r28.s32, r24.s32, xer);
	// beq cr6,0x822641a0
	if (cr6.eq) goto loc_822641A0;
	// lwz r30,-28(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822641b0
	if (cr6.eq) goto loc_822641B0;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822641a0
	if (cr6.eq) goto loc_822641A0;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226415c
	if (cr6.eq) goto loc_8226415C;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x82264130;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226415c
	if (cr6.eq) goto loc_8226415C;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226415c
	if (cr6.eq) goto loc_8226415C;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8226414C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822641a0
	if (cr6.eq) goto loc_822641A0;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x822641a0
	if (cr6.eq) goto loc_822641A0;
loc_8226415C:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,-4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -4);
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// bgt cr6,0x8226419c
	if (cr6.gt) goto loc_8226419C;
	// bne cr6,0x822641a0
	if (!cr6.eq) goto loc_822641A0;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r5,r11,64
	ctx.r5.s64 = r11.s64 + 64;
	// bl 0x82263780
	ctx.lr = 0x82264194;
	sub_82263780(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x822641a0
	if (!cr6.lt) goto loc_822641A0;
loc_8226419C:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
loc_822641A0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r22
	cr6.compare<int32_t>(r28.s32, r22.s32, xer);
	// blt cr6,0x822640ec
	if (cr6.lt) goto loc_822640EC;
loc_822641B0:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82264254
	if (!cr6.eq) goto loc_82264254;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bne cr6,0x82264254
	if (!cr6.eq) goto loc_82264254;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,-4940(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4940);
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// beq cr6,0x822641ec
	if (cr6.eq) goto loc_822641EC;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// stw r31,-4940(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4940, r31.u32);
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x82264214
	goto loc_82264214;
loc_822641EC:
	// lwz r10,-4936(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4936);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82264210
	if (!cr6.eq) goto loc_82264210;
	// cmpwi cr6,r20,1
	cr6.compare<int32_t>(r20.s32, 1, xer);
	// beq cr6,0x82264228
	if (cr6.eq) goto loc_82264228;
	// lwz r10,-4932(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4932);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x8226422c
	goto loc_8226422C;
loc_82264210:
	// lwz r6,-4932(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4932);
loc_82264214:
	// cmpwi cr6,r20,1
	cr6.compare<int32_t>(r20.s32, 1, xer);
	// bne cr6,0x8226422c
	if (!cr6.eq) goto loc_8226422C;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r6,-4932(r11)
	PPC_STORE_U32(r11.u32 + -4932, ctx.r6.u32);
	// b 0x8226422c
	goto loc_8226422C;
loc_82264228:
	// lwz r6,-4932(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4932);
loc_8226422C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r20,-4936(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4936, r20.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r10,-9144
	ctx.r4.s64 = ctx.r10.s64 + -9144;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82264254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82264254:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82264264"))) PPC_WEAK_FUNC(sub_82264264);
PPC_FUNC_IMPL(__imp__sub_82264264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264268"))) PPC_WEAK_FUNC(sub_82264268);
PPC_FUNC_IMPL(__imp__sub_82264268) {
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
	ctx.lr = 0x82264270;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r4,36(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82264298
	if (cr6.eq) goto loc_82264298;
loc_82264284:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82263b68
	ctx.lr = 0x8226428C;
	sub_82263B68(ctx, base);
	// lwz r4,36(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82264284
	if (!cr6.eq) goto loc_82264284;
loc_82264298:
	// lwz r31,44(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822642d4
	if (cr6.eq) goto loc_822642D4;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822642AC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822642d4
	if (!cr6.eq) goto loc_822642D4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822642d4
	if (cr6.eq) goto loc_822642D4;
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
	ctx.lr = 0x822642D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822642D4:
	// lwz r31,48(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82264310
	if (cr6.eq) goto loc_82264310;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822642E8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82264310
	if (!cr6.eq) goto loc_82264310;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82264310
	if (cr6.eq) goto loc_82264310;
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
	ctx.lr = 0x82264310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82264310:
	// addi r30,r28,60
	r30.s64 = r28.s64 + 60;
	// li r29,4
	r29.s64 = 4;
loc_82264318:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82264354
	if (cr6.eq) goto loc_82264354;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8226432C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82264354
	if (!cr6.eq) goto loc_82264354;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82264354
	if (cr6.eq) goto loc_82264354;
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
	ctx.lr = 0x82264354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82264354:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82264318
	if (!cr0.eq) goto loc_82264318;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x82264368;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82264370"))) PPC_WEAK_FUNC(sub_82264370);
PPC_FUNC_IMPL(__imp__sub_82264370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82263b68
	sub_82263B68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82264384"))) PPC_WEAK_FUNC(sub_82264384);
PPC_FUNC_IMPL(__imp__sub_82264384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264388"))) PPC_WEAK_FUNC(sub_82264388);
PPC_FUNC_IMPL(__imp__sub_82264388) {
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
	// bl 0x82263c28
	ctx.lr = 0x822643B4;
	sub_82263C28(ctx, base);
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

__attribute__((alias("__imp__sub_822643D0"))) PPC_WEAK_FUNC(sub_822643D0);
PPC_FUNC_IMPL(__imp__sub_822643D0) {
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
	// bl 0x82263f60
	ctx.lr = 0x822643FC;
	sub_82263F60(ctx, base);
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

__attribute__((alias("__imp__sub_82264418"))) PPC_WEAK_FUNC(sub_82264418);
PPC_FUNC_IMPL(__imp__sub_82264418) {
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
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,15144
	ctx.r4.s64 = r11.s64 + 15144;
	// addi r3,r10,-8680
	ctx.r3.s64 = ctx.r10.s64 + -8680;
	// bl 0x82554798
	ctx.lr = 0x82264438;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,17264
	ctx.r4.s64 = ctx.r9.s64 + 17264;
	// addi r3,r8,-8704
	ctx.r3.s64 = ctx.r8.s64 + -8704;
	// bl 0x82554798
	ctx.lr = 0x8226444C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,14344
	ctx.r4.s64 = ctx.r7.s64 + 14344;
	// addi r3,r6,-8748
	ctx.r3.s64 = ctx.r6.s64 + -8748;
	// bl 0x82554798
	ctx.lr = 0x82264460;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,13736
	ctx.r4.s64 = ctx.r5.s64 + 13736;
	// addi r3,r3,-8792
	ctx.r3.s64 = ctx.r3.s64 + -8792;
	// bl 0x82554798
	ctx.lr = 0x82264474;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,14368
	ctx.r4.s64 = r11.s64 + 14368;
	// addi r3,r10,-8836
	ctx.r3.s64 = ctx.r10.s64 + -8836;
	// bl 0x82554798
	ctx.lr = 0x82264488;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,14488
	ctx.r4.s64 = ctx.r9.s64 + 14488;
	// addi r3,r8,-8884
	ctx.r3.s64 = ctx.r8.s64 + -8884;
	// bl 0x82554798
	ctx.lr = 0x8226449C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,14576
	ctx.r4.s64 = ctx.r7.s64 + 14576;
	// addi r3,r6,-8924
	ctx.r3.s64 = ctx.r6.s64 + -8924;
	// bl 0x82554798
	ctx.lr = 0x822644B0;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,14640
	ctx.r4.s64 = ctx.r5.s64 + 14640;
	// addi r3,r3,-8960
	ctx.r3.s64 = ctx.r3.s64 + -8960;
	// bl 0x82554798
	ctx.lr = 0x822644C4;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,14720
	ctx.r4.s64 = r11.s64 + 14720;
	// addi r3,r10,-8992
	ctx.r3.s64 = ctx.r10.s64 + -8992;
	// bl 0x82554798
	ctx.lr = 0x822644D8;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,14768
	ctx.r4.s64 = ctx.r9.s64 + 14768;
	// addi r3,r8,-9036
	ctx.r3.s64 = ctx.r8.s64 + -9036;
	// bl 0x82554798
	ctx.lr = 0x822644EC;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,17288
	ctx.r4.s64 = ctx.r7.s64 + 17288;
	// addi r3,r6,-9076
	ctx.r3.s64 = ctx.r6.s64 + -9076;
	// bl 0x82554798
	ctx.lr = 0x82264500;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,17360
	ctx.r4.s64 = ctx.r5.s64 + 17360;
	// addi r3,r3,-9120
	ctx.r3.s64 = ctx.r3.s64 + -9120;
	// bl 0x82554798
	ctx.lr = 0x82264514;
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

__attribute__((alias("__imp__sub_82264524"))) PPC_WEAK_FUNC(sub_82264524);
PPC_FUNC_IMPL(__imp__sub_82264524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264528"))) PPC_WEAK_FUNC(sub_82264528);
PPC_FUNC_IMPL(__imp__sub_82264528) {
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
	// lwz r31,-4944(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -4944);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226455c
	if (cr6.eq) goto loc_8226455C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82264268
	ctx.lr = 0x82264554;
	sub_82264268(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8226455C;
	sub_82130588(ctx, base);
loc_8226455C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-4944(r30)
	PPC_STORE_U32(r30.u32 + -4944, r11.u32);
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

__attribute__((alias("__imp__sub_8226457C"))) PPC_WEAK_FUNC(sub_8226457C);
PPC_FUNC_IMPL(__imp__sub_8226457C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264580"))) PPC_WEAK_FUNC(sub_82264580);
PPC_FUNC_IMPL(__imp__sub_82264580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,16
	r11.s64 = 16;
	// stw r11,256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 256, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226458C"))) PPC_WEAK_FUNC(sub_8226458C);
PPC_FUNC_IMPL(__imp__sub_8226458C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264590"))) PPC_WEAK_FUNC(sub_82264590);
PPC_FUNC_IMPL(__imp__sub_82264590) {
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82264598;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r6,2256
	ctx.r4.s64 = ctx.r6.s64 + 2256;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f0,208(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r1,112
	r28.s64 = ctx.r1.s64 + 112;
	// stfs f0,212(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,128
	r27.s64 = ctx.r1.s64 + 128;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r3,-1
	ctx.r3.s64 = -1;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// sth r3,220(r1)
	PPC_STORE_U16(ctx.r1.u32 + 220, ctx.r3.u16);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// sth r11,222(r1)
	PPC_STORE_U16(ctx.r1.u32 + 222, r11.u16);
	// stb r11,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, r11.u8);
	// lis r6,-32114
	ctx.r6.s64 = -2104623104;
	// sth r11,226(r1)
	PPC_STORE_U16(ctx.r1.u32 + 226, r11.u16);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r11.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r8,-1
	ctx.r8.s64 = -1;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,2048
	ctx.r7.s64 = 2048;
	// lvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-23452(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -23452);
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82574418
	ctx.lr = 0x82264684;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82264698
	if (cr6.eq) goto loc_82264698;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82264698:
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f31,12(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822646C8"))) PPC_WEAK_FUNC(sub_822646C8);
PPC_FUNC_IMPL(__imp__sub_822646C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822646E4"))) PPC_WEAK_FUNC(sub_822646E4);
PPC_FUNC_IMPL(__imp__sub_822646E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822646E8"))) PPC_WEAK_FUNC(sub_822646E8);
PPC_FUNC_IMPL(__imp__sub_822646E8) {
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

__attribute__((alias("__imp__sub_82264760"))) PPC_WEAK_FUNC(sub_82264760);
PPC_FUNC_IMPL(__imp__sub_82264760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32218
	r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,17808
	ctx.r3.s64 = r11.s64 + 17808;
	// b 0x822646e8
	sub_822646E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82264770"))) PPC_WEAK_FUNC(sub_82264770);
PPC_FUNC_IMPL(__imp__sub_82264770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32218
	r11.s64 = -2111438848;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,18120
	ctx.r3.s64 = r11.s64 + 18120;
	// b 0x822c9b10
	sub_822C9B10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82264780"))) PPC_WEAK_FUNC(sub_82264780);
PPC_FUNC_IMPL(__imp__sub_82264780) {
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
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,18272
	ctx.r4.s64 = r11.s64 + 18272;
	// addi r3,r10,-8360
	ctx.r3.s64 = ctx.r10.s64 + -8360;
	// bl 0x82554798
	ctx.lr = 0x822647A0;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,18288
	ctx.r4.s64 = ctx.r9.s64 + 18288;
	// addi r3,r8,-8384
	ctx.r3.s64 = ctx.r8.s64 + -8384;
	// bl 0x82554798
	ctx.lr = 0x822647B4;
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

__attribute__((alias("__imp__sub_822647C4"))) PPC_WEAK_FUNC(sub_822647C4);
PPC_FUNC_IMPL(__imp__sub_822647C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822647C8"))) PPC_WEAK_FUNC(sub_822647C8);
PPC_FUNC_IMPL(__imp__sub_822647C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822647D8"))) PPC_WEAK_FUNC(sub_822647D8);
PPC_FUNC_IMPL(__imp__sub_822647D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bne 0x8226481c
	if (!cr0.eq) goto loc_8226481C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82264808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_8226481C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82264830"))) PPC_WEAK_FUNC(sub_82264830);
PPC_FUNC_IMPL(__imp__sub_82264830) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822648c4
	if (!cr6.eq) goto loc_822648C4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-7976
	ctx.r3.s64 = r11.s64 + -7976;
	// bl 0x82478c30
	ctx.lr = 0x8226485C;
	sub_82478C30(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822648c4
	if (cr6.eq) goto loc_822648C4;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// beq cr6,0x822648c4
	if (cr6.eq) goto loc_822648C4;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-7988
	ctx.r4.s64 = ctx.r10.s64 + -7988;
	// bl 0x8218a568
	ctx.lr = 0x82264888;
	sub_8218A568(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-8000
	ctx.r4.s64 = ctx.r8.s64 + -8000;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822648A4;
	sub_8218A568(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-8012
	ctx.r4.s64 = ctx.r6.s64 + -8012;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822648C0;
	sub_8218A568(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
loc_822648C4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822648D8"))) PPC_WEAK_FUNC(sub_822648D8);
PPC_FUNC_IMPL(__imp__sub_822648D8) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82264950
	if (!cr6.eq) goto loc_82264950;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-7940
	ctx.r3.s64 = r11.s64 + -7940;
	// bl 0x82478c30
	ctx.lr = 0x82264904;
	sub_82478C30(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264950
	if (cr6.eq) goto loc_82264950;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// beq cr6,0x82264948
	if (cr6.eq) goto loc_82264948;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-7952
	ctx.r4.s64 = ctx.r10.s64 + -7952;
	// bl 0x8218a568
	ctx.lr = 0x82264930;
	sub_8218A568(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82264948:
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_82264950:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82264964"))) PPC_WEAK_FUNC(sub_82264964);
PPC_FUNC_IMPL(__imp__sub_82264964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82264968"))) PPC_WEAK_FUNC(sub_82264968);
PPC_FUNC_IMPL(__imp__sub_82264968) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82264970;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r29,r1,112
	r29.s64 = ctx.r1.s64 + 112;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v58,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32)));
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-7572(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7572);
	// stvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f5d98
	ctx.lr = 0x822649D4;
	sub_822F5D98(ctx, base);
	// lwz r3,-7572(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7572);
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f1688
	ctx.lr = 0x822649E0;
	sub_822F1688(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822649fc
	if (cr6.eq) goto loc_822649FC;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82264a04
	goto loc_82264A04;
loc_822649FC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82264A04:
	// lfs f12,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f11,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82264A44;
	sub_8218A6E0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82264A5C;
	sub_82189CE0(ctx, base);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82264a8c
	if (cr6.eq) goto loc_82264A8C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r10,80
	ctx.r6.s64 = ctx.r10.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82264A8C;
	sub_8218A6E0(ctx, base);
loc_82264A8C:
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82264abc
	if (cr6.eq) goto loc_82264ABC;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,-12556(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12556);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82264abc
	if (!cr6.lt) goto loc_82264ABC;
	// lfs f13,432(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 432);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,432(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 432, temp.u32);
loc_82264ABC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82264AC8"))) PPC_WEAK_FUNC(sub_82264AC8);
PPC_FUNC_IMPL(__imp__sub_82264AC8) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82264AD0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r29,r1,128
	r29.s64 = ctx.r1.s64 + 128;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v58,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32)));
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-7572(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7572);
	// stvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f5d98
	ctx.lr = 0x82264B34;
	sub_822F5D98(ctx, base);
	// lwz r3,-7572(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7572);
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f1688
	ctx.lr = 0x82264B40;
	sub_822F1688(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,240
	ctx.r6.s64 = 240;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,22080(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22080);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// lwz r10,-8092(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lvx128 v56,r31,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfd f11,-7920(r3)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r3.u32 + -7920);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f10,-11620(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11620);
	ctx.f10.f64 = double(temp.f32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lvx128 v57,r11,r6
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v57,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v55,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f9,f13,f13
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f13,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f7,f12,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fsub f5,f6,f11
	ctx.f5.f64 = ctx.f6.f64 - ctx.f11.f64;
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f10
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f10.f64));
	// fsel f2,f3,f3,f0
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f3.f64 : f0.f64;
	// fsel f1,f3,f3,f0
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f3.f64 : f0.f64;
	// fsubs f0,f2,f31
	f0.f64 = double(float(ctx.f2.f64 - f31.f64));
	// fsel f13,f0,f31,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? f31.f64 : ctx.f1.f64;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// beq cr6,0x82264c04
	if (cr6.eq) goto loc_82264C04;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82264C04;
	sub_8218A6E0(ctx, base);
loc_82264C04:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82264c34
	if (cr6.eq) goto loc_82264C34;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,-12556(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12556);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82264c34
	if (!cr6.lt) goto loc_82264C34;
	// lfs f13,432(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 432);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,432(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 432, temp.u32);
loc_82264C34:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82264C40"))) PPC_WEAK_FUNC(sub_82264C40);
PPC_FUNC_IMPL(__imp__sub_82264C40) {
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
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264c64
	if (cr6.eq) goto loc_82264C64;
	// bl 0x8247a8d0
	ctx.lr = 0x82264C64;
	sub_8247A8D0(ctx, base);
loc_82264C64:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264c74
	if (cr6.eq) goto loc_82264C74;
	// bl 0x8247a8d0
	ctx.lr = 0x82264C74;
	sub_8247A8D0(ctx, base);
loc_82264C74:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82264C90"))) PPC_WEAK_FUNC(sub_82264C90);
PPC_FUNC_IMPL(__imp__sub_82264C90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// li r6,64
	ctx.r6.s64 = 64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,80
	ctx.r7.s64 = 80;
	// li r10,96
	ctx.r10.s64 = 96;
	// li r11,144
	r11.s64 = 144;
	// lvx128 v63,r30,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,112
	ctx.r9.s64 = 112;
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,128
	ctx.r8.s64 = 128;
	// lvx128 v62,r30,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r7,r31,r30
	ctx.r7.s64 = r30.s64 - r31.s64;
	// lvx128 v61,r30,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r30,204
	ctx.r10.s64 = r30.s64 + 204;
	// lvx128 v60,r30,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,200
	r11.s64 = r31.s64 + 200;
	// lvx128 v59,r30,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,2
	ctx.r9.s64 = 2;
	// lvx128 v58,r30,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,160(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 160);
	// stb r8,160(r31)
	PPC_STORE_U8(r31.u32 + 160, ctx.r8.u8);
	// lbz r6,328(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 328);
	// stb r6,328(r31)
	PPC_STORE_U8(r31.u32 + 328, ctx.r6.u8);
	// lbz r5,329(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 329);
	// stb r5,329(r31)
	PPC_STORE_U8(r31.u32 + 329, ctx.r5.u8);
	// lbz r4,330(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 330);
	// stb r4,330(r31)
	PPC_STORE_U8(r31.u32 + 330, ctx.r4.u8);
	// lbz r3,331(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 331);
	// stb r3,331(r31)
	PPC_STORE_U8(r31.u32 + 331, ctx.r3.u8);
	// lfs f0,164(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 164);
	f0.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lfs f13,168(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// lfs f12,176(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,176(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// lfs f11,180(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 180);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,180(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// lfs f10,188(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 188);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,188(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
loc_82264D54:
	// lwzx r8,r11,r7
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lfs f0,60(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// lwz r6,-204(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -204);
	// stw r6,-200(r11)
	PPC_STORE_U32(r11.u32 + -200, ctx.r6.u32);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r5,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r5.u32);
	// lfs f13,64(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,68(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// lwz r4,-200(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -200);
	// stw r4,-196(r11)
	PPC_STORE_U32(r11.u32 + -196, ctx.r4.u32);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r3,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r3.u32);
	// lfs f12,68(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,72(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 72, temp.u32);
	// lwz r8,-196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -196);
	// stw r8,-192(r11)
	PPC_STORE_U32(r11.u32 + -192, ctx.r8.u32);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// lfs f11,72(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,76(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 76, temp.u32);
	// lwz r5,-192(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -192);
	// stw r5,-188(r11)
	PPC_STORE_U32(r11.u32 + -188, ctx.r5.u32);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
	// lfs f10,76(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,80(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 80, temp.u32);
	// lwz r3,-188(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -188);
	// stw r3,-184(r11)
	PPC_STORE_U32(r11.u32 + -184, ctx.r3.u32);
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// lfs f9,80(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,84(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 84, temp.u32);
	// lwz r6,-184(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -184);
	// stw r6,-180(r11)
	PPC_STORE_U32(r11.u32 + -180, ctx.r6.u32);
	// lwz r5,20(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r5.u32);
	// lfs f8,84(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,88(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 88, temp.u32);
	// lwz r4,-180(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -180);
	// stw r4,-176(r11)
	PPC_STORE_U32(r11.u32 + -176, ctx.r4.u32);
	// lwz r3,24(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// stw r3,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r3.u32);
	// lfs f7,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,92(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 92, temp.u32);
	// lwz r8,-176(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -176);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stw r8,-172(r11)
	PPC_STORE_U32(r11.u32 + -172, ctx.r8.u32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x82264d54
	if (!cr0.eq) goto loc_82264D54;
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264e34
	if (cr6.eq) goto loc_82264E34;
	// bl 0x8247a8d0
	ctx.lr = 0x82264E34;
	sub_8247A8D0(ctx, base);
loc_82264E34:
	// lwz r11,336(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 336);
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r11.u32);
	// beq cr6,0x82264e4c
	if (cr6.eq) goto loc_82264E4C;
	// bl 0x8247a8d0
	ctx.lr = 0x82264E4C;
	sub_8247A8D0(ctx, base);
loc_82264E4C:
	// lwz r11,340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 340);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r11.u32);
	// lwz r10,348(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 348);
	// stw r10,348(r31)
	PPC_STORE_U32(r31.u32 + 348, ctx.r10.u32);
	// lfs f0,172(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 172);
	f0.f64 = double(temp.f32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
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

__attribute__((alias("__imp__sub_82264E80"))) PPC_WEAK_FUNC(sub_82264E80);
PPC_FUNC_IMPL(__imp__sub_82264E80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82264E88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-4336
	ctx.r4.s64 = r11.s64 + -4336;
	// bl 0x821c8fe0
	ctx.lr = 0x82264EA4;
	sub_821C8FE0(ctx, base);
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82264ef4
	if (cr6.eq) goto loc_82264EF4;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r8,r10,-12548
	ctx.r8.s64 = ctx.r10.s64 + -12548;
	// addi r7,r9,29952
	ctx.r7.s64 = ctx.r9.s64 + 29952;
	// lfs f12,-12548(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12548);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,464(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 464, temp.u32);
	// lfs f0,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r6,336(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// fmuls f13,f0,f12
	ctx.f13.f64 = double(float(f0.f64 * ctx.f12.f64));
	// stfs f13,468(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 468, temp.u32);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// bl 0x8247a8d0
	ctx.lr = 0x82264EF0;
	sub_8247A8D0(ctx, base);
	// stw r30,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r30.u32);
loc_82264EF4:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82264f08
	if (cr6.eq) goto loc_82264F08;
	// bl 0x8247a8d0
	ctx.lr = 0x82264F04;
	sub_8247A8D0(ctx, base);
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
loc_82264F08:
	// li r11,64
	r11.s64 = 64;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,112
	ctx.r10.s64 = 112;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r9,160(r31)
	PPC_STORE_U8(r31.u32 + 160, ctx.r9.u8);
	// stvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821c9030
	ctx.lr = 0x82264F30;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82264F38"))) PPC_WEAK_FUNC(sub_82264F38);
PPC_FUNC_IMPL(__imp__sub_82264F38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lbz r10,330(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 330);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82264f8c
	if (cr6.eq) goto loc_82264F8C;
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// li r10,80
	ctx.r10.s64 = 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261be90
	ctx.lr = 0x82264F7C;
	sub_8261BE90(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82264F8C:
	// lfs f0,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82264FD0"))) PPC_WEAK_FUNC(sub_82264FD0);
PPC_FUNC_IMPL(__imp__sub_82264FD0) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// li r11,112
	r11.s64 = 112;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r4,348(r31)
	PPC_STORE_U32(r31.u32 + 348, ctx.r4.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x822f1478
	ctx.lr = 0x82265020;
	sub_822F1478(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// lfs f0,11360(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11360);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x822f14c8
	ctx.lr = 0x82265044;
	sub_822F14C8(ctx, base);
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

__attribute__((alias("__imp__sub_8226505C"))) PPC_WEAK_FUNC(sub_8226505C);
PPC_FUNC_IMPL(__imp__sub_8226505C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265060"))) PPC_WEAK_FUNC(sub_82265060);
PPC_FUNC_IMPL(__imp__sub_82265060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r4,5
	ctx.r9.s64 = ctx.r4.s64 + 5;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r4,332(r11)
	PPC_STORE_U32(r11.u32 + 332, ctx.r4.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82265074:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82265074
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82265074;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82265084"))) PPC_WEAK_FUNC(sub_82265084);
PPC_FUNC_IMPL(__imp__sub_82265084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265088"))) PPC_WEAK_FUNC(sub_82265088);
PPC_FUNC_IMPL(__imp__sub_82265088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r4,8
	ctx.r9.s64 = ctx.r4.s64 + 8;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r4,332(r11)
	PPC_STORE_U32(r11.u32 + 332, ctx.r4.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8226509C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8226509c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8226509C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822650AC"))) PPC_WEAK_FUNC(sub_822650AC);
PPC_FUNC_IMPL(__imp__sub_822650AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822650B0"))) PPC_WEAK_FUNC(sub_822650B0);
PPC_FUNC_IMPL(__imp__sub_822650B0) {
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// beq cr6,0x822650e4
	if (cr6.eq) goto loc_822650E4;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822650E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822650E4:
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

__attribute__((alias("__imp__sub_822650FC"))) PPC_WEAK_FUNC(sub_822650FC);
PPC_FUNC_IMPL(__imp__sub_822650FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265100"))) PPC_WEAK_FUNC(sub_82265100);
PPC_FUNC_IMPL(__imp__sub_82265100) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x82265160
	if (cr6.eq) goto loc_82265160;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82265140
	if (cr6.eq) goto loc_82265140;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82265140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82265140:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82265160
	if (cr6.eq) goto loc_82265160;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82265160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82265160:
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

__attribute__((alias("__imp__sub_8226517C"))) PPC_WEAK_FUNC(sub_8226517C);
PPC_FUNC_IMPL(__imp__sub_8226517C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265180"))) PPC_WEAK_FUNC(sub_82265180);
PPC_FUNC_IMPL(__imp__sub_82265180) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-7904
	ctx.r10.s64 = r11.s64 + -7904;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82619418
	ctx.lr = 0x822651AC;
	sub_82619418(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822651c4
	if (cr6.eq) goto loc_822651C4;
	// bl 0x82130588
	ctx.lr = 0x822651C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822651C4:
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

__attribute__((alias("__imp__sub_822651DC"))) PPC_WEAK_FUNC(sub_822651DC);
PPC_FUNC_IMPL(__imp__sub_822651DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822651E0"))) PPC_WEAK_FUNC(sub_822651E0);
PPC_FUNC_IMPL(__imp__sub_822651E0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-8032
	ctx.r10.s64 = r11.s64 + -8032;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82619418
	ctx.lr = 0x8226520C;
	sub_82619418(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82265224
	if (cr6.eq) goto loc_82265224;
	// bl 0x82130588
	ctx.lr = 0x82265220;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82265224:
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

__attribute__((alias("__imp__sub_8226523C"))) PPC_WEAK_FUNC(sub_8226523C);
PPC_FUNC_IMPL(__imp__sub_8226523C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265240"))) PPC_WEAK_FUNC(sub_82265240);
PPC_FUNC_IMPL(__imp__sub_82265240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v63{};
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
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82265264
	if (cr6.eq) goto loc_82265264;
	// bl 0x8247a8d0
	ctx.lr = 0x82265264;
	sub_8247A8D0(ctx, base);
loc_82265264:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82265274
	if (cr6.eq) goto loc_82265274;
	// bl 0x8247a8d0
	ctx.lr = 0x82265274;
	sub_8247A8D0(ctx, base);
loc_82265274:
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8226529c
	if (cr6.lt) goto loc_8226529C;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-7572(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f14c8
	ctx.lr = 0x8226529C;
	sub_822F14C8(ctx, base);
loc_8226529C:
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822652b8
	if (cr6.eq) goto loc_822652B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822652B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822652B8:
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822652d4
	if (cr6.eq) goto loc_822652D4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822652D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822652D4:
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

__attribute__((alias("__imp__sub_822652E8"))) PPC_WEAK_FUNC(sub_822652E8);
PPC_FUNC_IMPL(__imp__sub_822652E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v63{};
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-4336
	ctx.r4.s64 = r11.s64 + -4336;
	// bl 0x821c8fe0
	ctx.lr = 0x82265310;
	sub_821C8FE0(ctx, base);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r30,0
	r30.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r30,329(r31)
	PPC_STORE_U8(r31.u32 + 329, r30.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r10,328(r31)
	PPC_STORE_U8(r31.u32 + 328, ctx.r10.u8);
	// beq cr6,0x82265334
	if (cr6.eq) goto loc_82265334;
	// bl 0x8247a8d0
	ctx.lr = 0x82265330;
	sub_8247A8D0(ctx, base);
	// stw r30,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r30.u32);
loc_82265334:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82265348
	if (cr6.eq) goto loc_82265348;
	// bl 0x8247a8d0
	ctx.lr = 0x82265344;
	sub_8247A8D0(ctx, base);
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
loc_82265348:
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r11.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82265378
	if (cr6.lt) goto loc_82265378;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-7572(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f14c8
	ctx.lr = 0x82265378;
	sub_822F14C8(ctx, base);
loc_82265378:
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x82264830
	ctx.lr = 0x82265380;
	sub_82264830(ctx, base);
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// bl 0x822648d8
	ctx.lr = 0x82265388;
	sub_822648D8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82265390;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_822653A8"))) PPC_WEAK_FUNC(sub_822653A8);
PPC_FUNC_IMPL(__imp__sub_822653A8) {
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
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x822653B0;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d8
	ctx.lr = 0x822653B8;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lbz r11,330(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 330);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822656f4
	if (cr6.eq) goto loc_822656F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r31,80
	r30.s64 = r31.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r29,r31,64
	r29.s64 = r31.s64 + 64;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8261d980
	ctx.lr = 0x822653FC;
	sub_8261D980(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261d980
	ctx.lr = 0x82265410;
	sub_8261D980(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8261d980
	ctx.lr = 0x82265424;
	sub_8261D980(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8261d980
	ctx.lr = 0x82265438;
	sub_8261D980(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x8261b020
	ctx.lr = 0x82265458;
	sub_8261B020(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lfs f28,-9152(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -9152);
	f28.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f29,-9160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -9160);
	f29.f64 = double(temp.f32);
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
	// beq cr6,0x822654a8
	if (cr6.eq) goto loc_822654A8;
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x822654a8
	if (cr6.lt) goto loc_822654A8;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x822654a8
	if (cr6.gt) goto loc_822654A8;
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// blt cr6,0x822654a8
	if (cr6.lt) goto loc_822654A8;
	// fcmpu cr6,f13,f28
	cr6.compare(ctx.f13.f64, f28.f64);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x822654ac
	if (!cr6.gt) goto loc_822654AC;
loc_822654A8:
	// li r11,0
	r11.s64 = 0;
loc_822654AC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r26,96
	r26.s64 = 96;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226558c
	if (!cr6.eq) goto loc_8226558C;
	// lvx128 v63,r31,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v59,v61,v63
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261d980
	ctx.lr = 0x822654F0;
	sub_8261D980(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8261d980
	ctx.lr = 0x82265504;
	sub_8261D980(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261d980
	ctx.lr = 0x82265518;
	sub_8261D980(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8261d980
	ctx.lr = 0x8226552C;
	sub_8261D980(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x8261b020
	ctx.lr = 0x8226554C;
	sub_8261B020(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82265584
	if (cr6.eq) goto loc_82265584;
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x82265584
	if (cr6.lt) goto loc_82265584;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x82265584
	if (cr6.gt) goto loc_82265584;
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// blt cr6,0x82265584
	if (cr6.lt) goto loc_82265584;
	// fcmpu cr6,f13,f28
	cr6.compare(ctx.f13.f64, f28.f64);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x82265588
	if (!cr6.gt) goto loc_82265588;
loc_82265584:
	// li r11,0
	r11.s64 = 0;
loc_82265588:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8226558C:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82265668
	if (!cr6.eq) goto loc_82265668;
	// lvx128 v58,r31,r26
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lvx128 v56,r0,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v57,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// vsubfp128 v54,v56,v58
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v58.f32)));
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261d980
	ctx.lr = 0x822655CC;
	sub_8261D980(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8261d980
	ctx.lr = 0x822655E0;
	sub_8261D980(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261d980
	ctx.lr = 0x822655F4;
	sub_8261D980(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8261d980
	ctx.lr = 0x82265608;
	sub_8261D980(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x8261b020
	ctx.lr = 0x82265628;
	sub_8261B020(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82265660
	if (cr6.eq) goto loc_82265660;
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x82265660
	if (cr6.lt) goto loc_82265660;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x82265660
	if (cr6.gt) goto loc_82265660;
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// blt cr6,0x82265660
	if (cr6.lt) goto loc_82265660;
	// fcmpu cr6,f13,f28
	cr6.compare(ctx.f13.f64, f28.f64);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x82265664
	if (!cr6.gt) goto loc_82265664;
loc_82265660:
	// li r11,0
	r11.s64 = 0;
loc_82265664:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_82265668:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822656e0
	if (cr6.eq) goto loc_822656E0;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f12,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r27
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v53,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f10,184(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	ctx.f10.f64 = double(temp.f32);
	// lvlx128 v52,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v52,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// fmadds f0,f11,f13,f0
	f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + f0.f64));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// fsubs f9,f0,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f9
	cr6.compare(ctx.f13.f64, ctx.f9.f64);
	// ble cr6,0x822656e0
	if (!cr6.gt) goto loc_822656E0;
	// lfs f12,180(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 180);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bge cr6,0x822656e0
	if (!cr6.lt) goto loc_822656E0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x822656DC;
	// b 0x823d9234
	return;
loc_822656E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x822656F0;
	// b 0x823d9234
	return;
loc_822656F4:
	// addi r10,r31,64
	ctx.r10.s64 = r31.s64 + 64;
	// lvx128 v51,r0,r27
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r28
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// vsubfp128 v0,v50,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r9,r11,-23776
	ctx.r9.s64 = r11.s64 + -23776;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v12,v51,v59
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v59.f32)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v49,v0,v12
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32), 0xEF));
	// vsubfp128 v63,v60,v49
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v49.f32)));
	// vcmpgefp128. v48,v62,v63
	simde_mm_store_ps(v48.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v48.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82265740
	if (cr6.eq) goto loc_82265740;
	// li r11,1
	r11.s64 = 1;
	// b 0x82265790
	goto loc_82265790;
loc_82265740:
	// vmsum3fp128 v47,v0,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// vsubfp128 v61,v47,v63
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgefp128. v46,v62,v61
	simde_mm_store_ps(v46.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v46.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r11,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82265768
	if (cr6.eq) goto loc_82265768;
	// vaddfp v12,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)));
	// li r11,2
	r11.s64 = 2;
	// b 0x82265790
	goto loc_82265790;
loc_82265768:
	// vaddfp128 v45,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// vupkd3d128 v44,v60,4
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v44 = vTemp;
	// li r11,0
	r11.s64 = 0;
	// vspltw128 v11,v44,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0x0));
	// vrefp128 v13,v45
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v45.f32)));
	// vor128 v10,v45,v45
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v45.u8));
	// vnmsubfp v8,v13,v10,v11
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v13,v8,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v6,v63,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v12,v0,v6,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
loc_82265790:
	// vaddfp128 v43,v12,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v43.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v59.f32)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stvx128 v43,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x822657b8
	if (!cr6.eq) goto loc_822657B8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,168(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-9152(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9152);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// b 0x822657bc
	goto loc_822657BC;
loc_822657B8:
	// lfs f0,168(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	f0.f64 = double(temp.f32);
loc_822657BC:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f9,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmuls f6,f10,f10
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f5,f7,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f12
	cr6.compare(ctx.f5.f64, ctx.f12.f64);
	// bge cr6,0x82265814
	if (!cr6.lt) goto loc_82265814;
	// lfs f13,184(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x82265814
	if (!cr6.gt) goto loc_82265814;
	// lfs f12,180(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 180);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// blt cr6,0x82265818
	if (cr6.lt) goto loc_82265818;
loc_82265814:
	// li r11,0
	r11.s64 = 0;
loc_82265818:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x82265828;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8226582C"))) PPC_WEAK_FUNC(sub_8226582C);
PPC_FUNC_IMPL(__imp__sub_8226582C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265830"))) PPC_WEAK_FUNC(sub_82265830);
PPC_FUNC_IMPL(__imp__sub_82265830) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82265838;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d4
	ctx.lr = 0x82265840;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r30,r11,-4912
	r30.s64 = r11.s64 + -4912;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,-4896(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4896);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// clrlwi r7,r11,31
	ctx.r7.u64 = r11.u32 & 0x1;
	// lfs f27,17032(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	f27.f64 = double(temp.f32);
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8226589c
	if (!cr6.eq) goto loc_8226589C;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stfs f31,0(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f27,4(r30)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// stfs f31,8(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stw r11,-4896(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4896, r11.u32);
loc_8226589C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r4,-27692(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27692);
	// lfs f1,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82179778
	ctx.lr = 0x822658B0;
	sub_82179778(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// lfs f30,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fdivs f29,f30,f1
	f29.f64 = double(float(f30.f64 / ctx.f1.f64));
	// bl 0x8217f768
	ctx.lr = 0x822658C8;
	sub_8217F768(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r27,-25600(r8)
	r27.u64 = PPC_LOAD_U32(ctx.r8.u32 + -25600);
	// bl 0x8217f768
	ctx.lr = 0x822658DC;
	sub_8217F768(ctx, base);
	// li r7,112
	ctx.r7.s64 = 112;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,128
	ctx.r6.s64 = 128;
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f30,120(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v60,r31,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// vaddfp128 v59,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// lvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v0,v62,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// vpermwi128 v58,v63,99
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v57,v63,135
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,-32124
	r28.s64 = -2105278464;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// vmulfp128 v13,v61,v58
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v58.f32)));
	// vor128 v12,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vor128 v11,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// vnmsubfp v0,v0,v11,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vpermwi128 v56,v0,99
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x9C));
	// stvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v10,v0,135
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x78));
	// vmulfp128 v9,v57,v56
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// vnmsubfp v8,v12,v10,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v8,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c088
	ctx.lr = 0x82265968;
	sub_8217C088(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x82265970;
	sub_8217D9A0(ctx, base);
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r29,66
	ctx.r6.s64 = r29.s64 + 66;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r5,-4288
	ctx.r4.s64 = ctx.r5.s64 + -4288;
	// lwzx r3,r7,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r11,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// lwzx r30,r10,r4
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	// ble cr6,0x822659fc
	if (!cr6.gt) goto loc_822659FC;
	// addi r10,r29,50
	ctx.r10.s64 = r29.s64 + 50;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x822659cc
	if (!cr6.eq) goto loc_822659CC;
	// lvlx128 v55,r11,r31
	temp.u32 = r11.u32 + r31.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v53,r30,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v52,v53,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)));
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822659CC:
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82265a50
	if (!cr6.eq) goto loc_82265A50;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v51,r30,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v50,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmulfp128 v48,v51,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32)));
	// stvx128 v48,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82265a50
	goto loc_82265A50;
loc_822659FC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f13.f64 = double(temp.f32);
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v127,r30,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,12424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12424);
	f0.f64 = double(temp.f32);
	// lvx128 v126,r30,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82265A1C;
	sub_823DBAE8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vsubfp128 v47,v126,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,14884(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fadds f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 + f30.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v46,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v45,v46,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// vmaddfp128 v127,v47,v45,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v45.f32)), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82265A50:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// li r4,33
	ctx.r4.s64 = 33;
	// lfs f9,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lfs f11,104(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 * f29.f64));
	// lfs f29,96(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 96);
	f29.f64 = double(temp.f32);
	// lfs f0,15360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// fmuls f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f28,100(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 100);
	f28.f64 = double(temp.f32);
	// fmuls f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f5,f10,f0
	ctx.f5.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fctiwz f4,f8
	ctx.f4.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f4.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f3,f7
	ctx.f3.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f3.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f2,f6
	ctx.f2.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f2,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f2.u64);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// fctiwz f1,f5
	ctx.f1.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f1,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f1.u64);
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r5,r6,8,16,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// or r11,r5,r7
	r11.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r8,r11,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 | ctx.r10.u64;
	// or r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 | ctx.r10.u64;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r10,r6,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r9,r5,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r31,r10,r11
	r31.u64 = ctx.r10.u64 | r11.u64;
	// or r29,r9,r11
	r29.u64 = ctx.r9.u64 | r11.u64;
	// bl 0x8217bb68
	ctx.lr = 0x82265AF4;
	sub_8217BB68(ctx, base);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// fmr f8,f31
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f31.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82265B1C;
	sub_8217BC28(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r11,-4848
	r30.s64 = r11.s64 + -4848;
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
loc_82265B28:
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// lfs f12,-4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmuls f3,f0,f28
	ctx.f3.f64 = double(float(f0.f64 * f28.f64));
	// fadds f2,f13,f27
	ctx.f2.f64 = double(float(ctx.f13.f64 + f27.f64));
	// fmuls f1,f12,f29
	ctx.f1.f64 = double(float(ctx.f12.f64 * f29.f64));
	// bl 0x8217bc28
	ctx.lr = 0x82265B5C;
	sub_8217BC28(ctx, base);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// addi r11,r30,516
	r11.s64 = r30.s64 + 516;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82265b28
	if (cr6.lt) goto loc_82265B28;
	// bl 0x8217bc98
	ctx.lr = 0x82265B70;
	sub_8217BC98(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// addi r4,r11,-31280
	ctx.r4.s64 = r11.s64 + -31280;
	// bl 0x8217c088
	ctx.lr = 0x82265B80;
	sub_8217C088(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x82265B8C;
	sub_8217F768(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba20
	ctx.lr = 0x82265BA8;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82265BAC"))) PPC_WEAK_FUNC(sub_82265BAC);
PPC_FUNC_IMPL(__imp__sub_82265BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265BB0"))) PPC_WEAK_FUNC(sub_82265BB0);
PPC_FUNC_IMPL(__imp__sub_82265BB0) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82265BB8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x82264830
	ctx.lr = 0x82265BD0;
	sub_82264830(ctx, base);
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// bl 0x822648d8
	ctx.lr = 0x82265BD8;
	sub_822648D8(ctx, base);
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r10,16
	ctx.r10.s64 = 16;
	// rlwinm r26,r28,2,0,29
	r26.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r9,-4288
	ctx.r7.s64 = ctx.r9.s64 + -4288;
	// stvx128 v63,r6,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r8,-4336
	ctx.r4.s64 = ctx.r8.s64 + -4336;
	// stvx128 v62,r5,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r26,r31
	r11.u64 = PPC_LOAD_U32(r26.u32 + r31.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwzx r8,r10,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// stw r8,116(r9)
	PPC_STORE_U32(ctx.r9.u32 + 116, ctx.r8.u32);
	// bl 0x821c8fe0
	ctx.lr = 0x82265C28;
	sub_821C8FE0(ctx, base);
	// lwz r7,336(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r30,400
	r30.s64 = 400;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82265cb8
	if (cr6.eq) goto loc_82265CB8;
	// addi r11,r28,13
	r11.s64 = r28.s64 + 13;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// rotlwi r9,r7,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,48
	ctx.r8.s64 = 48;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfsx f0,r7,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// lis r29,-32256
	r29.s64 = -2113929216;
	// stfs f0,432(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 432, temp.u32);
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r7,116(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	// lvx128 v61,r7,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// stvx128 v61,r4,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,176(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lfs f0,-4208(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -4208);
	f0.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f13,-12260(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12260);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r10,-7884
	ctx.r4.s64 = ctx.r10.s64 + -7884;
	// fdivs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// fsel f8,f9,f9,f0
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f0.f64;
	// fsel f7,f9,f9,f0
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f0.f64;
	// fsubs f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f1,f6,f13,f7
	ctx.f1.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : ctx.f7.f64;
	// bl 0x8247a6a0
	ctx.lr = 0x82265CB8;
	sub_8247A6A0(ctx, base);
loc_82265CB8:
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82265cd8
	if (cr6.eq) goto loc_82265CD8;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r9,64
	ctx.r9.s64 = 64;
	// lwz r8,116(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// lvx128 v60,r8,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82265CD8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82265CE0;
	sub_821C9030(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82265d08
	if (cr6.eq) goto loc_82265D08;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82265d0c
	if (!cr6.eq) goto loc_82265D0C;
loc_82265D08:
	// li r11,0
	r11.s64 = 0;
loc_82265D0C:
	// addi r9,r28,50
	ctx.r9.s64 = r28.s64 + 50;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r29,r9,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r29,r31
	r11.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82265d2c
	if (cr6.eq) goto loc_82265D2C;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82265d30
	if (!cr6.eq) goto loc_82265D30;
loc_82265D2C:
	// li r27,0
	r27.s64 = 0;
loc_82265D30:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// stb r27,48(r11)
	PPC_STORE_U8(r11.u32 + 48, r27.u8);
	// lfs f2,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f2.f64 = double(temp.f32);
	// lwzx r6,r26,r31
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + r31.u32);
	// lfs f1,176(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	ctx.f1.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bl 0x82269648
	ctx.lr = 0x82265D60;
	sub_82269648(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r30,-7572(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lbz r10,14546(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 14546);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82265da4
	if (!cr6.eq) goto loc_82265DA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f10d0
	ctx.lr = 0x82265D7C;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82265d9c
	if (cr6.gt) goto loc_82265D9C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f10d0
	ctx.lr = 0x82265D90;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x82265da4
	if (!cr6.lt) goto loc_82265DA4;
loc_82265D9C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82265da8
	goto loc_82265DA8;
loc_82265DA4:
	// li r11,0
	r11.s64 = 0;
loc_82265DA8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82265dec
	if (!cr6.eq) goto loc_82265DEC;
	// lbz r11,329(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 329);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82265dec
	if (!cr6.eq) goto loc_82265DEC;
	// lwzx r11,r29,r31
	r11.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82265dec
	if (cr6.eq) goto loc_82265DEC;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x82265dec
	if (!cr6.eq) goto loc_82265DEC;
	// lwz r11,348(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82265dec
	if (cr6.lt) goto loc_82265DEC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82265830
	ctx.lr = 0x82265DEC;
	sub_82265830(ctx, base);
loc_82265DEC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82265DF4"))) PPC_WEAK_FUNC(sub_82265DF4);
PPC_FUNC_IMPL(__imp__sub_82265DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265DF8"))) PPC_WEAK_FUNC(sub_82265DF8);
PPC_FUNC_IMPL(__imp__sub_82265DF8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-4336
	ctx.r4.s64 = r11.s64 + -4336;
	// bl 0x821c8fe0
	ctx.lr = 0x82265E24;
	sub_821C8FE0(ctx, base);
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82265e8c
	if (cr6.eq) goto loc_82265E8C;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82265e8c
	if (cr6.eq) goto loc_82265E8C;
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82265e8c
	if (cr6.eq) goto loc_82265E8C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-7876
	ctx.r4.s64 = r11.s64 + -7876;
	// bl 0x8247bc80
	ctx.lr = 0x82265E54;
	sub_8247BC80(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82265e8c
	if (cr6.lt) goto loc_82265E8C;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82265e74
	if (cr6.eq) goto loc_82265E74;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// b 0x82265e7c
	goto loc_82265E7C;
loc_82265E74:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82265E7C:
	// addi r11,r3,109
	r11.s64 = ctx.r3.s64 + 109;
	// lwz r10,336(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82265E8C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82265E94;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_82265EAC"))) PPC_WEAK_FUNC(sub_82265EAC);
PPC_FUNC_IMPL(__imp__sub_82265EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265EB0"))) PPC_WEAK_FUNC(sub_82265EB0);
PPC_FUNC_IMPL(__imp__sub_82265EB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v62{};
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
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r5,-32114
	ctx.r5.s64 = -2104623104;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,-11624(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// lwz r3,-23452(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -23452);
	// lfs f13,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,192(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// li r11,0
	r11.s64 = 0;
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r8,204(r1)
	PPC_STORE_U16(ctx.r1.u32 + 204, ctx.r8.u16);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// sth r11,206(r1)
	PPC_STORE_U16(ctx.r1.u32 + 206, r11.u16);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r11,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r11.u8);
	// sth r11,210(r1)
	PPC_STORE_U16(ctx.r1.u32 + 210, r11.u16);
	// stw r11,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r11.u32);
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82265fc4
	if (cr6.eq) goto loc_82265FC4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,2048
	ctx.r7.s64 = 2048;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82574418
	ctx.lr = 0x82265F84;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82265fc4
	if (cr6.eq) goto loc_82265FC4;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// lfs f8,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfs f2,176(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
loc_82265FC4:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
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

__attribute__((alias("__imp__sub_82265FDC"))) PPC_WEAK_FUNC(sub_82265FDC);
PPC_FUNC_IMPL(__imp__sub_82265FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82265FE0"))) PPC_WEAK_FUNC(sub_82265FE0);
PPC_FUNC_IMPL(__imp__sub_82265FE0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82265FE8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,160(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822661f8
	if (cr6.eq) goto loc_822661F8;
	// addi r28,r31,64
	r28.s64 = r31.s64 + 64;
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// li r27,80
	r27.s64 = 80;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,330(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 330);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266040
	if (cr6.eq) goto loc_82266040;
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lvx128 v62,r31,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,172
	r11.s64 = 172;
	// vsubfp128 v13,v62,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v61,r31,r11
	temp.u32 = r31.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82266040:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f13,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// li r29,0
	r29.s64 = 0;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r5,-32114
	ctx.r5.s64 = -2104623104;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f31,208(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stw r29,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r29.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f31,212(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lfs f0,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lwz r3,-23452(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -23452);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r9,220(r1)
	PPC_STORE_U16(ctx.r1.u32 + 220, ctx.r9.u16);
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r29,222(r1)
	PPC_STORE_U16(ctx.r1.u32 + 222, r29.u16);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r29,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, r29.u8);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// sth r29,226(r1)
	PPC_STORE_U16(ctx.r1.u32 + 226, r29.u16);
	// stw r29,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r29.u32);
	// beq cr6,0x8226611c
	if (cr6.eq) goto loc_8226611C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,2048
	ctx.r7.s64 = 2048;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82574418
	ctx.lr = 0x822660F8;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8226611c
	if (cr6.eq) goto loc_8226611C;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// li r9,128
	ctx.r9.s64 = 128;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8226611C:
	// lbz r11,330(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 330);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822661e0
	if (cr6.eq) goto loc_822661E0;
	// lvx128 v57,r0,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// lvx128 v56,r31,r27
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// vsubfp128 v55,v56,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r6,-31664
	ctx.r4.s64 = ctx.r6.s64 + -31664;
	// addi r3,r5,-31648
	ctx.r3.s64 = ctx.r5.s64 + -31648;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,-8040(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8040);
	f0.f64 = double(temp.f32);
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,104(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f31,100(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v54,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v54,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,96(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f11,104(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v51,v52,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vrsqrtefp128 v50,v51
	simde_mm_store_ps(v50.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v51.f32))));
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v12,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v11,v50,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v63,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v49,v52,v6
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vor128 v48,v49,v49
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v47,v48,v53
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822661ec
	goto loc_822661EC;
loc_822661E0:
	// vspltisw128 v46,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,96
	r11.s64 = 96;
	// stvx128 v46,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822661EC:
	// stb r29,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r29.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82265eb0
	ctx.lr = 0x822661F8;
	sub_82265EB0(ctx, base);
loc_822661F8:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82266204"))) PPC_WEAK_FUNC(sub_82266204);
PPC_FUNC_IMPL(__imp__sub_82266204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266208"))) PPC_WEAK_FUNC(sub_82266208);
PPC_FUNC_IMPL(__imp__sub_82266208) {
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
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82266210;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d0
	ctx.lr = 0x82266218;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r10,64
	ctx.r10.s64 = 64;
	// li r9,80
	ctx.r9.s64 = 80;
	// li r8,96
	ctx.r8.s64 = 96;
	// li r7,112
	ctx.r7.s64 = 112;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r3,144
	ctx.r3.s64 = 144;
	// stw r30,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r30.u32);
	// stw r30,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r30.u32);
	// li r28,-1
	r28.s64 = -1;
	// li r29,1
	r29.s64 = 1;
	// lfs f31,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f28,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f28.f64 = double(temp.f32);
	// addi r11,r31,264
	r11.s64 = r31.s64 + 264;
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,3
	ctx.r9.s64 = 3;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,128(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f28,132(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f31,136(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stb r30,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r30.u8);
	// lfs f0,14192(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r30,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r30.u32);
	// stfs f0,188(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
	// stvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r29,328(r31)
	PPC_STORE_U8(r31.u32 + 328, r29.u8);
	// stb r30,329(r31)
	PPC_STORE_U8(r31.u32 + 329, r30.u8);
	// stb r30,330(r31)
	PPC_STORE_U8(r31.u32 + 330, r30.u8);
	// stb r30,331(r31)
	PPC_STORE_U8(r31.u32 + 331, r30.u8);
	// stw r28,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r28.u32);
loc_822662B4:
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r9,-64(r11)
	PPC_STORE_U32(r11.u32 + -64, ctx.r9.u32);
	// stw r30,-264(r11)
	PPC_STORE_U32(r11.u32 + -264, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x822662b4
	if (!cr0.eq) goto loc_822662B4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,352(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r30,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r30.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// li r3,128
	ctx.r3.s64 = 128;
	// lfs f13,-8040(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8040);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31016(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,27636(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27636);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,30712(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30712);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stfs f12,176(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stfs f11,180(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// stfs f10,184(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x8226631C;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82266340
	if (cr6.eq) goto loc_82266340;
	// bl 0x82619428
	ctx.lr = 0x8226632C;
	sub_82619428(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// addi r10,r11,-7904
	ctx.r10.s64 = r11.s64 + -7904;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82266344
	goto loc_82266344;
loc_82266340:
	// mr r29,r30
	r29.u64 = r30.u64;
loc_82266344:
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplw cr6,r29,r3
	cr6.compare<uint32_t>(r29.u32, ctx.r3.u32, xer);
	// beq cr6,0x82266388
	if (cr6.eq) goto loc_82266388;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266368
	if (cr6.eq) goto loc_82266368;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266368:
	// stw r29,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82266388
	if (cr6.eq) goto loc_82266388;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266388;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266388:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r3,48
	ctx.r3.s64 = 48;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r30,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, r30.u32);
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r30,36(r9)
	PPC_STORE_U32(ctx.r9.u32 + 36, r30.u32);
	// lwz r8,192(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r30,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, r30.u32);
	// lwz r7,192(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r30,120(r7)
	PPC_STORE_U32(ctx.r7.u32 + 120, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822663B8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822663dc
	if (cr6.eq) goto loc_822663DC;
	// bl 0x82619428
	ctx.lr = 0x822663C8;
	sub_82619428(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// addi r10,r11,-8032
	ctx.r10.s64 = r11.s64 + -8032;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x822663e0
	goto loc_822663E0;
loc_822663DC:
	// mr r29,r30
	r29.u64 = r30.u64;
loc_822663E0:
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplw cr6,r29,r3
	cr6.compare<uint32_t>(r29.u32, ctx.r3.u32, xer);
	// beq cr6,0x82266424
	if (cr6.eq) goto loc_82266424;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266404
	if (cr6.eq) goto loc_82266404;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266404;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266404:
	// stw r29,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82266424
	if (cr6.eq) goto loc_82266424;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266424;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266424:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// stw r30,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, r30.u32);
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// stw r30,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, r30.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stw r28,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r28.u32);
	// bl 0x822652e8
	ctx.lr = 0x82266454;
	sub_822652E8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r28,r11,-4848
	r28.s64 = r11.s64 + -4848;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
	// lfs f30,-7864(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7864);
	f30.f64 = double(temp.f32);
	// lfs f29,18204(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	f29.f64 = double(temp.f32);
loc_82266470:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// stfs f28,-8(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r29.u32 + -8, temp.u32);
	// stfs f31,-4(r29)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r29.u32 + -4, temp.u32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// stfs f31,0(r29)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmuls f27,f11,f29
	f27.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbae8
	ctx.lr = 0x822664A0;
	sub_823DBAE8(ctx, base);
	// frsp f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = double(float(ctx.f1.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x822664AC;
	sub_823DBBC8(ctx, base);
	// lfs f10,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// frsp f9,f1
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lfs f8,-8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f26
	ctx.f7.f64 = double(float(ctx.f10.f64 * f26.f64));
	// fmuls f6,f8,f26
	ctx.f6.f64 = double(float(ctx.f8.f64 * f26.f64));
	// addi r10,r28,520
	ctx.r10.s64 = r28.s64 + 520;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// fmadds f5,f8,f9,f7
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f7.f64));
	// stfs f5,-8(r29)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r29.u32 + -8, temp.u32);
	// fmsubs f4,f10,f9,f6
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 - ctx.f6.f64));
	// stfs f4,0(r29)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x82266470
	if (cr6.lt) goto loc_82266470;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba1c
	ctx.lr = 0x822664F4;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822664F8"))) PPC_WEAK_FUNC(sub_822664F8);
PPC_FUNC_IMPL(__imp__sub_822664F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82266500;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9b8
	ctx.lr = 0x82266508;
	// li r12,-288
	r12.s64 = -288;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-272
	r12.s64 = -272;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,-4336
	ctx.r4.s64 = r11.s64 + -4336;
	// bl 0x821c8fe0
	ctx.lr = 0x82266530;
	sub_821C8FE0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f0,-12544(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12544);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f22,12424(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12424);
	f22.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f26,14980(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14980);
	f26.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f28,-7788(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -7788);
	f28.f64 = double(temp.f32);
	// lfs f21,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f21.f64 = double(temp.f32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lfs f23,14348(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14348);
	f23.f64 = double(temp.f32);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// lfs f27,15004(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 15004);
	f27.f64 = double(temp.f32);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lfs f25,12428(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12428);
	f25.f64 = double(temp.f32);
	// lfs f29,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lis r27,-32130
	r27.s64 = -2105671680;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lis r29,23772
	r29.s64 = 1557921792;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// fmr f24,f31
	f24.f64 = f31.f64;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// fdivs f20,f31,f0
	f20.f64 = double(float(f31.f64 / f0.f64));
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lis r28,-32130
	r28.s64 = -2105671680;
	// addi r3,r3,-7812
	ctx.r3.s64 = ctx.r3.s64 + -7812;
	// addi r30,r30,17820
	r30.s64 = r30.s64 + 17820;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// li r17,0
	r17.s64 = 0;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r20,400
	r20.s64 = 400;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// ori r18,r29,64167
	r18.u64 = r29.u64 | 64167;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r21,-32120
	r21.s64 = -2105016320;
	// lis r15,-32115
	r15.s64 = -2104688640;
	// addi r23,r11,-12548
	r23.s64 = r11.s64 + -12548;
	// addi r25,r10,-4288
	r25.s64 = ctx.r10.s64 + -4288;
	// addi r27,r9,29952
	r27.s64 = ctx.r9.s64 + 29952;
	// addi r26,r8,2176
	r26.s64 = ctx.r8.s64 + 2176;
	// addi r16,r7,-7820
	r16.s64 = ctx.r7.s64 + -7820;
	// addi r22,r6,-7836
	r22.s64 = ctx.r6.s64 + -7836;
	// addi r19,r5,-7884
	r19.s64 = ctx.r5.s64 + -7884;
	// addi r14,r4,-7860
	r14.s64 = ctx.r4.s64 + -7860;
loc_82266624:
	// addi r11,r17,50
	r11.s64 = r17.s64 + 50;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r29,r31
	r11.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8226667c
	if (cr6.eq) goto loc_8226667C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82266708
	if (!cr6.eq) goto loc_82266708;
	// addi r11,r17,66
	r11.s64 = r17.s64 + 66;
	// lfs f0,88(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 88);
	f0.f64 = double(temp.f32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r11,r31
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f20,f13
	ctx.f12.f64 = double(float(f0.f64 * f20.f64 + ctx.f13.f64));
	// stfsx f12,r11,r31
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// fsel f11,f12,f12,f29
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f29.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// fsubs f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 - f31.f64));
	// fsel f24,f10,f31,f11
	f24.f64 = ctx.f10.f64 >= 0.0 ? f31.f64 : ctx.f11.f64;
	// blt cr6,0x82266708
	if (cr6.lt) goto loc_82266708;
	// li r10,0
	ctx.r10.s64 = 0;
	// stfsx f29,r11,r31
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// stwx r10,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r10.u32);
	// b 0x82266708
	goto loc_82266708;
loc_8226667C:
	// addi r11,r17,66
	r11.s64 = r17.s64 + 66;
	// lfs f0,88(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f12,r11,r31
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f25,f12
	f0.f64 = double(float(f0.f64 * f25.f64 + ctx.f12.f64));
	// stfsx f0,r11,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x822666b0
	if (cr6.lt) goto loc_822666B0;
	// li r10,3
	ctx.r10.s64 = 3;
	// stfsx f29,r11,r31
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// stwx r10,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r10.u32);
	// b 0x822666b4
	goto loc_822666B4;
loc_822666B0:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_822666B4:
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82266708
	if (cr6.lt) goto loc_82266708;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266708
	if (!cr6.eq) goto loc_82266708;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// fsubs f0,f31,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - ctx.f13.f64));
	// li r9,32
	ctx.r9.s64 = 32;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lwzx r6,r8,r25
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r25.u32);
	// lvx128 v61,r6,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f14c8
	ctx.lr = 0x82266708;
	sub_822F14C8(ctx, base);
loc_82266708:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r9,-6144(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82266730
	if (cr6.eq) goto loc_82266730;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r11,156(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82266734
	if (!cr6.eq) goto loc_82266734;
loc_82266730:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82266734:
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// clrlwi r28,r10,24
	r28.u64 = ctx.r10.u32 & 0xFF;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266790
	if (cr6.eq) goto loc_82266790;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82266788
	if (!cr6.eq) goto loc_82266788;
	// bl 0x82256058
	ctx.lr = 0x82266764;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266790
	if (cr6.eq) goto loc_82266790;
	// bl 0x82256058
	ctx.lr = 0x82266770;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82266790
	if (cr0.eq) goto loc_82266790;
	// bl 0x82256058
	ctx.lr = 0x8226677C;
	sub_82256058(ctx, base);
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82266790
	if (cr6.eq) goto loc_82266790;
loc_82266788:
	// li r11,1
	r11.s64 = 1;
	// b 0x82266794
	goto loc_82266794;
loc_82266790:
	// li r11,0
	r11.s64 = 0;
loc_82266794:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822667ac
	if (cr6.eq) goto loc_822667AC;
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = f29.f64;
	// b 0x822667b0
	goto loc_822667B0;
loc_822667AC:
	// fmr f0,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = f24.f64;
loc_822667B0:
	// addi r11,r17,13
	r11.s64 = r17.s64 + 13;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// lwzx r8,r29,r31
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r8,3
	cr6.compare<int32_t>(ctx.r8.s32, 3, xer);
	// beq cr6,0x822667d4
	if (cr6.eq) goto loc_822667D4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82266800
	if (cr6.eq) goto loc_82266800;
loc_822667D4:
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266800
	if (!cr6.eq) goto loc_82266800;
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82266800
	if (cr6.lt) goto loc_82266800;
	// stfs f29,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f29,148(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// stfs f29,152(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// bl 0x822f14c8
	ctx.lr = 0x82266800;
	sub_822F14C8(ctx, base);
loc_82266800:
	// lwzx r11,r29,r31
	r11.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82266d38
	if (cr6.eq) goto loc_82266D38;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82266d38
	if (cr6.eq) goto loc_82266D38;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82266d38
	if (!cr6.eq) goto loc_82266D38;
	// lbz r11,329(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 329);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266870
	if (cr6.eq) goto loc_82266870;
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266870
	if (cr6.eq) goto loc_82266870;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266870
	if (!cr6.eq) goto loc_82266870;
	// lfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,464(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 464, temp.u32);
	// lfs f13,0(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lfs f0,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f13,468(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// bl 0x8247a8d0
	ctx.lr = 0x82266868;
	sub_8247A8D0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,336(r31)
	PPC_STORE_U32(r31.u32 + 336, ctx.r10.u32);
loc_82266870:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f12,176(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f0,-4208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4208);
	f0.f64 = double(temp.f32);
	// lfs f13,-12260(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12260);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fdivs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fsel f8,f9,f9,f29
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f29.f64;
	// fsubs f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 - f31.f64));
	// fsel f30,f7,f31,f8
	f30.f64 = ctx.f7.f64 >= 0.0 ? f31.f64 : ctx.f8.f64;
	// bne cr6,0x82266d98
	if (!cr6.eq) goto loc_82266D98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82265fe0
	ctx.lr = 0x822668B0;
	sub_82265FE0(ctx, base);
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266be8
	if (!cr6.eq) goto loc_82266BE8;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-12540(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12540);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822668d0
	if (cr6.lt) goto loc_822668D0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_822668D0:
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// addi r30,r31,336
	r30.s64 = r31.s64 + 336;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822669b8
	if (!cr6.eq) goto loc_822669B8;
	// lbz r11,329(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 329);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822669b8
	if (!cr6.eq) goto loc_822669B8;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-4916(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -4916);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82266910
	if (!cr6.eq) goto loc_82266910;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
loc_82266910:
	// bl 0x824804d0
	ctx.lr = 0x82266914;
	sub_824804D0(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822669b8
	if (cr6.eq) goto loc_822669B8;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8247a6a0
	ctx.lr = 0x82266930;
	sub_8247A6A0(ctx, base);
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// lwzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// lvx128 v59,r9,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r8,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8247a020
	ctx.lr = 0x82266954;
	sub_8247A020(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x822650b0
	ctx.lr = 0x82266960;
	sub_822650B0(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,624(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 624);
	// addi r3,r11,672
	ctx.r3.s64 = r11.s64 + 672;
	// lwz r29,112(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82265100
	ctx.lr = 0x82266978;
	sub_82265100(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8247a838
	ctx.lr = 0x82266980;
	sub_8247A838(ctx, base);
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r5,120(r6)
	PPC_STORE_U32(ctx.r6.u32 + 120, ctx.r5.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r3,r11,120
	ctx.r3.s64 = r11.s64 + 120;
	// stw r3,148(r4)
	PPC_STORE_U32(ctx.r4.u32 + 148, ctx.r3.u32);
	// beq cr6,0x822669b8
	if (cr6.eq) goto loc_822669B8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822669B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822669B8:
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82266b64
	if (!cr6.eq) goto loc_82266B64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r9,-6144(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82266b64
	if (!cr6.eq) goto loc_82266B64;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwzx r29,r11,r25
	r29.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// beq cr6,0x82266ad4
	if (cr6.eq) goto loc_82266AD4;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// cmplwi cr6,r11,15
	cr6.compare<uint32_t>(r11.u32, 15, xer);
	// bgt cr6,0x82266ad4
	if (cr6.gt) goto loc_82266AD4;
	// lis r12,-32218
	r12.s64 = -2111438848;
	// addi r12,r12,27144
	r12.s64 = r12.s64 + 27144;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82266A48;
	case 1:
		goto loc_82266AD4;
	case 2:
		goto loc_82266AD4;
	case 3:
		goto loc_82266AA8;
	case 4:
		goto loc_82266A78;
	case 5:
		goto loc_82266A48;
	case 6:
		goto loc_82266A48;
	case 7:
		goto loc_82266A78;
	case 8:
		goto loc_82266A48;
	case 9:
		goto loc_82266AD4;
	case 10:
		goto loc_82266AD4;
	case 11:
		goto loc_82266AD4;
	case 12:
		goto loc_82266AD4;
	case 13:
		goto loc_82266AD4;
	case 14:
		goto loc_82266AD4;
	case 15:
		goto loc_82266A48;
	default:
		__builtin_unreachable();
	}
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27304(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27304);
	// lwz r17,27256(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27256);
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
	// lwz r17,27256(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27256);
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27348);
	// lwz r17,27208(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 27208);
loc_82266A48:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-4916(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -4916);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x824804d0
	ctx.lr = 0x82266A5C;
	sub_824804D0(ctx, base);
	// stw r3,340(r31)
	PPC_STORE_U32(r31.u32 + 340, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266ad4
	if (cr6.eq) goto loc_82266AD4;
	// li r11,64
	r11.s64 = 64;
	// lvx128 v58,r29,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r3,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82266ad4
	goto loc_82266AD4;
loc_82266A78:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-4916(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -4916);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x824804d0
	ctx.lr = 0x82266A8C;
	sub_824804D0(ctx, base);
	// stw r3,340(r31)
	PPC_STORE_U32(r31.u32 + 340, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266ad4
	if (cr6.eq) goto loc_82266AD4;
	// li r11,64
	r11.s64 = 64;
	// lvx128 v57,r29,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82266ad4
	goto loc_82266AD4;
loc_82266AA8:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-4916(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -4916);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x824804d0
	ctx.lr = 0x82266ABC;
	sub_824804D0(ctx, base);
	// stw r3,340(r31)
	PPC_STORE_U32(r31.u32 + 340, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266ad4
	if (cr6.eq) goto loc_82266AD4;
	// li r11,64
	r11.s64 = 64;
	// lvx128 v56,r29,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r3,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82266AD4:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266b64
	if (cr6.eq) goto loc_82266B64;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// bl 0x8247a020
	ctx.lr = 0x82266AE8;
	sub_8247A020(ctx, base);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// lwz r4,196(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// bl 0x822650b0
	ctx.lr = 0x82266AF4;
	sub_822650B0(ctx, base);
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lwz r11,624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 624);
	// lwz r29,116(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r3,r11,672
	ctx.r3.s64 = r11.s64 + 672;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82265100
	ctx.lr = 0x82266B0C;
	sub_82265100(ctx, base);
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// bl 0x8247a838
	ctx.lr = 0x82266B14;
	sub_8247A838(ctx, base);
	// lwz r10,340(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// lwz r9,136(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// lwz r3,256(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 256);
	// bl 0x8247bc80
	ctx.lr = 0x82266B28;
	sub_8247BC80(ctx, base);
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lwz r7,340(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// stw r3,344(r31)
	PPC_STORE_U32(r31.u32 + 344, ctx.r3.u32);
	// stw r7,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r7.u32);
	// lwz r6,340(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r5,r11,36
	ctx.r5.s64 = r11.s64 + 36;
	// stw r5,148(r6)
	PPC_STORE_U32(ctx.r6.u32 + 148, ctx.r5.u32);
	// beq cr6,0x82266b64
	if (cr6.eq) goto loc_82266B64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82266B64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82266B64:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266b78
	if (cr6.eq) goto loc_82266B78;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// bl 0x8247a020
	ctx.lr = 0x82266B78;
	sub_8247A020(ctx, base);
loc_82266B78:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266be8
	if (cr6.eq) goto loc_82266BE8;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// bl 0x8247a020
	ctx.lr = 0x82266B8C;
	sub_8247A020(ctx, base);
	// lwz r11,344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 344);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82266be8
	if (cr6.lt) goto loc_82266BE8;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x82266BA0;
	sub_822F10D0(ctx, base);
	// fcmpu cr6,f1,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f27.f64);
	// bge cr6,0x82266bbc
	if (!cr6.lt) goto loc_82266BBC;
	// fmuls f0,f1,f28
	f0.f64 = double(float(ctx.f1.f64 * f28.f64));
	// fsel f13,f0,f0,f29
	ctx.f13.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fsel f0,f12,f31,f13
	f0.f64 = ctx.f12.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// b 0x82266bd4
	goto loc_82266BD4;
loc_82266BBC:
	// fsubs f0,f1,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f27.f64));
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// fsel f12,f13,f13,f29
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f29.f64;
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// fsel f10,f11,f31,f12
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f31.f64 : ctx.f12.f64;
	// fsubs f0,f31,f10
	f0.f64 = double(float(f31.f64 - ctx.f10.f64));
loc_82266BD4:
	// lwz r11,344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 344);
	// lwz r10,340(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// addi r9,r11,109
	ctx.r9.s64 = r11.s64 + 109;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r8,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, temp.u32);
loc_82266BE8:
	// lwz r11,348(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82266d98
	if (cr6.lt) goto loc_82266D98;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266d98
	if (!cr6.eq) goto loc_82266D98;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	f0.f64 = double(temp.f32);
	// addi r11,r31,264
	r11.s64 = r31.s64 + 264;
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,16
	ctx.r10.s64 = 16;
	// lwzx r30,r9,r25
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + r25.u32);
	// ble cr6,0x82266c4c
	if (!cr6.gt) goto loc_82266C4C;
	// stfs f29,352(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lvx128 v53,r30,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lvlx128 v55,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmulfp128 v52,v53,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// stvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f14c8
	ctx.lr = 0x82266C48;
	sub_822F14C8(ctx, base);
	// b 0x82266d98
	goto loc_82266D98;
loc_82266C4C:
	// li r11,32
	r11.s64 = 32;
	// lfs f0,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	f0.f64 = double(temp.f32);
	// lvx128 v127,r30,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f1,f0,f22
	ctx.f1.f64 = double(float(f0.f64 * f22.f64));
	// lvx128 v126,r30,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823dbae8
	ctx.lr = 0x82266C64;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// vsubfp128 v51,v126,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lwz r11,-12640(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -12640);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// fadds f12,f13,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(ctx.f13.f64 + f31.f64));
	// fmuls f11,f12,f21
	ctx.f11.f64 = double(float(ctx.f12.f64 * f21.f64));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v50,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmaddfp128 v127,v51,v49,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32)), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82266cb0
	if (cr6.eq) goto loc_82266CB0;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82266cb4
	if (cr6.eq) goto loc_82266CB4;
loc_82266CB0:
	// li r11,0
	r11.s64 = 0;
loc_82266CB4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82266d24
	if (!cr6.eq) goto loc_82266D24;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// mulld r11,r11,r18
	r11.s64 = r11.s64 * r18.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r8,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// lfd f12,120(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// stw r11,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r11.u32);
	// lfs f8,208(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 208);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,212(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 212);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lfs f10,352(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// fmadds f6,f7,f23,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * f23.f64 + ctx.f13.f64));
	// fmadds f0,f6,f0,f10
	f0.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f10.f64));
	// stfs f0,352(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// ble cr6,0x82266d24
	if (!cr6.gt) goto loc_82266D24;
	// fsubs f0,f0,f26
	f0.f64 = double(float(f0.f64 - f26.f64));
	// stfs f0,352(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
loc_82266D24:
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// bl 0x822f14c8
	ctx.lr = 0x82266D34;
	sub_822F14C8(ctx, base);
	// b 0x82266d98
	goto loc_82266D98;
loc_82266D38:
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// bne cr6,0x82266d98
	if (!cr6.eq) goto loc_82266D98;
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82266d80
	if (cr6.eq) goto loc_82266D80;
	// lfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,464(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 464, temp.u32);
	// lfs f13,0(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// lfs f0,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f13,468(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// bl 0x8247a8d0
	ctx.lr = 0x82266D78;
	sub_8247A8D0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,336(r31)
	PPC_STORE_U32(r31.u32 + 336, ctx.r10.u32);
loc_82266D80:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82266d98
	if (cr6.eq) goto loc_82266D98;
	// bl 0x8247a8d0
	ctx.lr = 0x82266D90;
	sub_8247A8D0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r11.u32);
loc_82266D98:
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// cmpwi cr6,r17,16
	cr6.compare<int32_t>(r17.s32, 16, xer);
	// blt cr6,0x82266624
	if (cr6.lt) goto loc_82266624;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c9030
	ctx.lr = 0x82266DAC;
	sub_821C9030(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// li r0,-288
	r0.s64 = -288;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-272
	r0.s64 = -272;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba04
	ctx.lr = 0x82266DC8;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82266DCC"))) PPC_WEAK_FUNC(sub_82266DCC);
PPC_FUNC_IMPL(__imp__sub_82266DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266DD0"))) PPC_WEAK_FUNC(sub_82266DD0);
PPC_FUNC_IMPL(__imp__sub_82266DD0) {
	PPC_FUNC_PROLOGUE();
	// b 0x822664f8
	sub_822664F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82266DD4"))) PPC_WEAK_FUNC(sub_82266DD4);
PPC_FUNC_IMPL(__imp__sub_82266DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266DD8"))) PPC_WEAK_FUNC(sub_82266DD8);
PPC_FUNC_IMPL(__imp__sub_82266DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,176(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 176, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266DEC"))) PPC_WEAK_FUNC(sub_82266DEC);
PPC_FUNC_IMPL(__imp__sub_82266DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266DF0"))) PPC_WEAK_FUNC(sub_82266DF0);
PPC_FUNC_IMPL(__imp__sub_82266DF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,180(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 180, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E04"))) PPC_WEAK_FUNC(sub_82266E04);
PPC_FUNC_IMPL(__imp__sub_82266E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266E08"))) PPC_WEAK_FUNC(sub_82266E08);
PPC_FUNC_IMPL(__imp__sub_82266E08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,168(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 168, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E1C"))) PPC_WEAK_FUNC(sub_82266E1C);
PPC_FUNC_IMPL(__imp__sub_82266E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266E20"))) PPC_WEAK_FUNC(sub_82266E20);
PPC_FUNC_IMPL(__imp__sub_82266E20) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82266e50
	if (!cr6.gt) goto loc_82266E50;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f13,-7912(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,188(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 188, temp.u32);
	// blr 
	return;
loc_82266E50:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,188(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 188, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E60"))) PPC_WEAK_FUNC(sub_82266E60);
PPC_FUNC_IMPL(__imp__sub_82266E60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,330(r9)
	PPC_STORE_U8(ctx.r9.u32 + 330, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E80"))) PPC_WEAK_FUNC(sub_82266E80);
PPC_FUNC_IMPL(__imp__sub_82266E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,172(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 172, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266E94"))) PPC_WEAK_FUNC(sub_82266E94);
PPC_FUNC_IMPL(__imp__sub_82266E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266E98"))) PPC_WEAK_FUNC(sub_82266E98);
PPC_FUNC_IMPL(__imp__sub_82266E98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,16
	ctx.r9.s64 = 16;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r8,r10,5
	ctx.r8.s64 = ctx.r10.s64 + 5;
	// stw r10,332(r11)
	PPC_STORE_U32(r11.u32 + 332, ctx.r10.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82266EB4:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82266eb4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82266EB4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266EC4"))) PPC_WEAK_FUNC(sub_82266EC4);
PPC_FUNC_IMPL(__imp__sub_82266EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266EC8"))) PPC_WEAK_FUNC(sub_82266EC8);
PPC_FUNC_IMPL(__imp__sub_82266EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,16
	ctx.r9.s64 = 16;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r8,r10,8
	ctx.r8.s64 = ctx.r10.s64 + 8;
	// stw r10,332(r11)
	PPC_STORE_U32(r11.u32 + 332, ctx.r10.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82266EE4:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82266ee4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82266EE4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266EF4"))) PPC_WEAK_FUNC(sub_82266EF4);
PPC_FUNC_IMPL(__imp__sub_82266EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266EF8"))) PPC_WEAK_FUNC(sub_82266EF8);
PPC_FUNC_IMPL(__imp__sub_82266EF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266F1C"))) PPC_WEAK_FUNC(sub_82266F1C);
PPC_FUNC_IMPL(__imp__sub_82266F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266F20"))) PPC_WEAK_FUNC(sub_82266F20);
PPC_FUNC_IMPL(__imp__sub_82266F20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82266f58
	if (cr6.eq) goto loc_82266F58;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r11,r11,50
	r11.s64 = r11.s64 + 50;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82266F58:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266F6C"))) PPC_WEAK_FUNC(sub_82266F6C);
PPC_FUNC_IMPL(__imp__sub_82266F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266F70"))) PPC_WEAK_FUNC(sub_82266F70);
PPC_FUNC_IMPL(__imp__sub_82266F70) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f12,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-8(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// bne cr6,0x82266fac
	if (!cr6.eq) goto loc_82266FAC;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82266fac
	if (!cr6.eq) goto loc_82266FAC;
	// li r11,0
	r11.s64 = 0;
loc_82266FAC:
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// stb r11,331(r10)
	PPC_STORE_U8(ctx.r10.u32 + 331, r11.u8);
	// li r8,144
	ctx.r8.s64 = 144;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82266FC4"))) PPC_WEAK_FUNC(sub_82266FC4);
PPC_FUNC_IMPL(__imp__sub_82266FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82266FC8"))) PPC_WEAK_FUNC(sub_82266FC8);
PPC_FUNC_IMPL(__imp__sub_82266FC8) {
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
	// li r3,368
	ctx.r3.s64 = 368;
	// bl 0x82130528
	ctx.lr = 0x82266FE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226700c
	if (cr6.eq) goto loc_8226700C;
	// bl 0x82266208
	ctx.lr = 0x82266FF0;
	sub_82266208(ctx, base);
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
loc_8226700C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226702C"))) PPC_WEAK_FUNC(sub_8226702C);
PPC_FUNC_IMPL(__imp__sub_8226702C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267030"))) PPC_WEAK_FUNC(sub_82267030);
PPC_FUNC_IMPL(__imp__sub_82267030) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82267060
	if (cr6.eq) goto loc_82267060;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82265240
	ctx.lr = 0x82267058;
	sub_82265240(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82267060;
	sub_82130588(ctx, base);
loc_82267060:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267074"))) PPC_WEAK_FUNC(sub_82267074);
PPC_FUNC_IMPL(__imp__sub_82267074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267078"))) PPC_WEAK_FUNC(sub_82267078);
PPC_FUNC_IMPL(__imp__sub_82267078) {
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
	// b 0x82264e80
	sub_82264E80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822670DC"))) PPC_WEAK_FUNC(sub_822670DC);
PPC_FUNC_IMPL(__imp__sub_822670DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822670E0"))) PPC_WEAK_FUNC(sub_822670E0);
PPC_FUNC_IMPL(__imp__sub_822670E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r10,80
	ctx.r10.s64 = 80;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r5,r6,r3
	PPC_STORE_U32(ctx.r6.u32 + ctx.r3.u32, ctx.r5.u32);
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r8,160(r4)
	PPC_STORE_U8(ctx.r4.u32 + 160, ctx.r8.u8);
	// stvx128 v63,r4,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267154"))) PPC_WEAK_FUNC(sub_82267154);
PPC_FUNC_IMPL(__imp__sub_82267154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267158"))) PPC_WEAK_FUNC(sub_82267158);
PPC_FUNC_IMPL(__imp__sub_82267158) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r10,112
	ctx.r10.s64 = 112;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// lvx128 v63,r5,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822671C4"))) PPC_WEAK_FUNC(sub_822671C4);
PPC_FUNC_IMPL(__imp__sub_822671C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822671C8"))) PPC_WEAK_FUNC(sub_822671C8);
PPC_FUNC_IMPL(__imp__sub_822671C8) {
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
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,28616
	ctx.r4.s64 = r11.s64 + 28616;
	// addi r3,r10,-7372
	ctx.r3.s64 = ctx.r10.s64 + -7372;
	// bl 0x82554798
	ctx.lr = 0x822671E8;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,28720
	ctx.r4.s64 = ctx.r9.s64 + 28720;
	// addi r3,r8,-7392
	ctx.r3.s64 = ctx.r8.s64 + -7392;
	// bl 0x82554798
	ctx.lr = 0x822671FC;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,28792
	ctx.r4.s64 = ctx.r7.s64 + 28792;
	// addi r3,r6,-7416
	ctx.r3.s64 = ctx.r6.s64 + -7416;
	// bl 0x82554798
	ctx.lr = 0x82267210;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,28896
	ctx.r4.s64 = ctx.r5.s64 + 28896;
	// addi r3,r3,-7448
	ctx.r3.s64 = ctx.r3.s64 + -7448;
	// bl 0x82554798
	ctx.lr = 0x82267224;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,28120
	ctx.r4.s64 = r11.s64 + 28120;
	// addi r3,r10,-7472
	ctx.r3.s64 = ctx.r10.s64 + -7472;
	// bl 0x82554798
	ctx.lr = 0x82267238;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,28144
	ctx.r4.s64 = ctx.r9.s64 + 28144;
	// addi r3,r8,-7504
	ctx.r3.s64 = ctx.r8.s64 + -7504;
	// bl 0x82554798
	ctx.lr = 0x8226724C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,28168
	ctx.r4.s64 = ctx.r7.s64 + 28168;
	// addi r3,r6,-7536
	ctx.r3.s64 = ctx.r6.s64 + -7536;
	// bl 0x82554798
	ctx.lr = 0x82267260;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,28192
	ctx.r4.s64 = ctx.r5.s64 + 28192;
	// addi r3,r3,-7560
	ctx.r3.s64 = ctx.r3.s64 + -7560;
	// bl 0x82554798
	ctx.lr = 0x82267274;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,28256
	ctx.r4.s64 = r11.s64 + 28256;
	// addi r3,r10,-7588
	ctx.r3.s64 = ctx.r10.s64 + -7588;
	// bl 0x82554798
	ctx.lr = 0x82267288;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,28288
	ctx.r4.s64 = ctx.r9.s64 + 28288;
	// addi r3,r8,-7616
	ctx.r3.s64 = ctx.r8.s64 + -7616;
	// bl 0x82554798
	ctx.lr = 0x8226729C;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,29016
	ctx.r4.s64 = ctx.r7.s64 + 29016;
	// addi r3,r6,-7640
	ctx.r3.s64 = ctx.r6.s64 + -7640;
	// bl 0x82554798
	ctx.lr = 0x822672B0;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,28312
	ctx.r4.s64 = ctx.r5.s64 + 28312;
	// addi r3,r3,-7672
	ctx.r3.s64 = ctx.r3.s64 + -7672;
	// bl 0x82554798
	ctx.lr = 0x822672C4;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,28360
	ctx.r4.s64 = r11.s64 + 28360;
	// addi r3,r10,-7704
	ctx.r3.s64 = ctx.r10.s64 + -7704;
	// bl 0x82554798
	ctx.lr = 0x822672D8;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,28408
	ctx.r4.s64 = ctx.r9.s64 + 28408;
	// addi r3,r8,-7724
	ctx.r3.s64 = ctx.r8.s64 + -7724;
	// bl 0x82554798
	ctx.lr = 0x822672EC;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,28448
	ctx.r4.s64 = ctx.r7.s64 + 28448;
	// addi r3,r6,-7748
	ctx.r3.s64 = ctx.r6.s64 + -7748;
	// bl 0x82554798
	ctx.lr = 0x82267300;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,28528
	ctx.r4.s64 = ctx.r5.s64 + 28528;
	// addi r3,r3,-7784
	ctx.r3.s64 = ctx.r3.s64 + -7784;
	// bl 0x82554798
	ctx.lr = 0x82267314;
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

__attribute__((alias("__imp__sub_82267324"))) PPC_WEAK_FUNC(sub_82267324);
PPC_FUNC_IMPL(__imp__sub_82267324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267328"))) PPC_WEAK_FUNC(sub_82267328);
PPC_FUNC_IMPL(__imp__sub_82267328) {
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
	// clrlwi r31,r4,16
	r31.u64 = ctx.r4.u32 & 0xFFFF;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x82267380
	if (!cr6.lt) goto loc_82267380;
loc_82267354:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r11,r31,368
	r11.s64 = r31.s64 * 368;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r4,r3,368
	ctx.r4.s64 = ctx.r3.s64 + 368;
	// bl 0x82264c90
	ctx.lr = 0x82267368;
	sub_82264C90(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// clrlwi r31,r10,16
	r31.u64 = ctx.r10.u32 & 0xFFFF;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82267354
	if (cr6.lt) goto loc_82267354;
loc_82267380:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
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

__attribute__((alias("__imp__sub_822673A8"))) PPC_WEAK_FUNC(sub_822673A8);
PPC_FUNC_IMPL(__imp__sub_822673A8) {
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
	ctx.lr = 0x822673B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mulli r3,r30,368
	ctx.r3.s64 = r30.s64 * 368;
	// bl 0x82130528
	ctx.lr = 0x822673C0;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822673ec
	if (!cr6.gt) goto loc_822673EC;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_822673D0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822673e0
	if (cr6.eq) goto loc_822673E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82266208
	ctx.lr = 0x822673E0;
	sub_82266208(ctx, base);
loc_822673E0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,368
	r31.s64 = r31.s64 + 368;
	// bne 0x822673d0
	if (!cr0.eq) goto loc_822673D0;
loc_822673EC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822673F8"))) PPC_WEAK_FUNC(sub_822673F8);
PPC_FUNC_IMPL(__imp__sub_822673F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r3,r31,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x82267414;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82267468
	if (!cr6.gt) goto loc_82267468;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,255
	ctx.r9.s64 = 255;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82267434:
	// addic. r7,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r7.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq 0x8226745c
	if (cr0.eq) goto loc_8226745C;
	// stfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stw r8,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r8.u32);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
	// stb r10,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r10.u8);
loc_8226745C:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x82267434
	if (!cr0.eq) goto loc_82267434;
loc_82267468:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226747C"))) PPC_WEAK_FUNC(sub_8226747C);
PPC_FUNC_IMPL(__imp__sub_8226747C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267480"))) PPC_WEAK_FUNC(sub_82267480);
PPC_FUNC_IMPL(__imp__sub_82267480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mulli r10,r4,368
	ctx.r10.s64 = ctx.r4.s64 * 368;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267490"))) PPC_WEAK_FUNC(sub_82267490);
PPC_FUNC_IMPL(__imp__sub_82267490) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267498"))) PPC_WEAK_FUNC(sub_82267498);
PPC_FUNC_IMPL(__imp__sub_82267498) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r4,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822674AC"))) PPC_WEAK_FUNC(sub_822674AC);
PPC_FUNC_IMPL(__imp__sub_822674AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822674B0"))) PPC_WEAK_FUNC(sub_822674B0);
PPC_FUNC_IMPL(__imp__sub_822674B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f1,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822674C4"))) PPC_WEAK_FUNC(sub_822674C4);
PPC_FUNC_IMPL(__imp__sub_822674C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822674C8"))) PPC_WEAK_FUNC(sub_822674C8);
PPC_FUNC_IMPL(__imp__sub_822674C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f1,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822674DC"))) PPC_WEAK_FUNC(sub_822674DC);
PPC_FUNC_IMPL(__imp__sub_822674DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822674E0"))) PPC_WEAK_FUNC(sub_822674E0);
PPC_FUNC_IMPL(__imp__sub_822674E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// mulli r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 * 368;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267510"))) PPC_WEAK_FUNC(sub_82267510);
PPC_FUNC_IMPL(__imp__sub_82267510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// b 0x82267328
	sub_82267328(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82267524"))) PPC_WEAK_FUNC(sub_82267524);
PPC_FUNC_IMPL(__imp__sub_82267524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267528"))) PPC_WEAK_FUNC(sub_82267528);
PPC_FUNC_IMPL(__imp__sub_82267528) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267540"))) PPC_WEAK_FUNC(sub_82267540);
PPC_FUNC_IMPL(__imp__sub_82267540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulli r10,r7,368
	ctx.r10.s64 = ctx.r7.s64 * 368;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267564"))) PPC_WEAK_FUNC(sub_82267564);
PPC_FUNC_IMPL(__imp__sub_82267564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267568"))) PPC_WEAK_FUNC(sub_82267568);
PPC_FUNC_IMPL(__imp__sub_82267568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stwx r8,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267588"))) PPC_WEAK_FUNC(sub_82267588);
PPC_FUNC_IMPL(__imp__sub_82267588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stfs f0,4(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822675AC"))) PPC_WEAK_FUNC(sub_822675AC);
PPC_FUNC_IMPL(__imp__sub_822675AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822675B0"))) PPC_WEAK_FUNC(sub_822675B0);
PPC_FUNC_IMPL(__imp__sub_822675B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// sth r7,8(r5)
	PPC_STORE_U16(ctx.r5.u32 + 8, ctx.r7.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822675D4"))) PPC_WEAK_FUNC(sub_822675D4);
PPC_FUNC_IMPL(__imp__sub_822675D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822675D8"))) PPC_WEAK_FUNC(sub_822675D8);
PPC_FUNC_IMPL(__imp__sub_822675D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// stb r7,10(r5)
	PPC_STORE_U8(ctx.r5.u32 + 10, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822675FC"))) PPC_WEAK_FUNC(sub_822675FC);
PPC_FUNC_IMPL(__imp__sub_822675FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267600"))) PPC_WEAK_FUNC(sub_82267600);
PPC_FUNC_IMPL(__imp__sub_82267600) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// stb r7,11(r5)
	PPC_STORE_U8(ctx.r5.u32 + 11, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267624"))) PPC_WEAK_FUNC(sub_82267624);
PPC_FUNC_IMPL(__imp__sub_82267624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267628"))) PPC_WEAK_FUNC(sub_82267628);
PPC_FUNC_IMPL(__imp__sub_82267628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r4,r7
	ctx.r4.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// rlwinm r10,r6,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r8,r3,1
	ctx.r8.u64 = ctx.r3.u64 ^ 1;
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// stb r8,14(r11)
	PPC_STORE_U8(r11.u32 + 14, ctx.r8.u8);
	// stb r7,13(r11)
	PPC_STORE_U8(r11.u32 + 13, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267670"))) PPC_WEAK_FUNC(sub_82267670);
PPC_FUNC_IMPL(__imp__sub_82267670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267688"))) PPC_WEAK_FUNC(sub_82267688);
PPC_FUNC_IMPL(__imp__sub_82267688) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// stb r7,12(r5)
	PPC_STORE_U8(ctx.r5.u32 + 12, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822676AC"))) PPC_WEAK_FUNC(sub_822676AC);
PPC_FUNC_IMPL(__imp__sub_822676AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822676B0"))) PPC_WEAK_FUNC(sub_822676B0);
PPC_FUNC_IMPL(__imp__sub_822676B0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822676f0
	if (!cr6.gt) goto loc_822676F0;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f13,-7912(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// blr 
	return;
loc_822676F0:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226770C"))) PPC_WEAK_FUNC(sub_8226770C);
PPC_FUNC_IMPL(__imp__sub_8226770C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267710"))) PPC_WEAK_FUNC(sub_82267710);
PPC_FUNC_IMPL(__imp__sub_82267710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,20(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,20(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267738"))) PPC_WEAK_FUNC(sub_82267738);
PPC_FUNC_IMPL(__imp__sub_82267738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stfs f0,16(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226775C"))) PPC_WEAK_FUNC(sub_8226775C);
PPC_FUNC_IMPL(__imp__sub_8226775C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267760"))) PPC_WEAK_FUNC(sub_82267760);
PPC_FUNC_IMPL(__imp__sub_82267760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,20(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,16(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267788"))) PPC_WEAK_FUNC(sub_82267788);
PPC_FUNC_IMPL(__imp__sub_82267788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 24);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822677A0"))) PPC_WEAK_FUNC(sub_822677A0);
PPC_FUNC_IMPL(__imp__sub_822677A0) {
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
	// lhz r11,10(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r31,r3,4
	r31.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822677e8
	if (!cr6.eq) goto loc_822677E8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x822677e0
	if (cr6.eq) goto loc_822677E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822673a8
	ctx.lr = 0x822677DC;
	sub_822673A8(ctx, base);
	// b 0x822677e4
	goto loc_822677E4;
loc_822677E0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822677E4:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_822677E8:
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
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

__attribute__((alias("__imp__sub_82267804"))) PPC_WEAK_FUNC(sub_82267804);
PPC_FUNC_IMPL(__imp__sub_82267804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267808"))) PPC_WEAK_FUNC(sub_82267808);
PPC_FUNC_IMPL(__imp__sub_82267808) {
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
	ctx.lr = 0x82267810;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r31,6(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82267840
	if (!cr6.gt) goto loc_82267840;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8226782C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82265240
	ctx.lr = 0x82267834;
	sub_82265240(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,368
	r30.s64 = r30.s64 + 368;
	// bne 0x8226782c
	if (!cr0.eq) goto loc_8226782C;
loc_82267840:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x82267848;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// sth r11,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r11.u16);
	// sth r11,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82267860"))) PPC_WEAK_FUNC(sub_82267860);
PPC_FUNC_IMPL(__imp__sub_82267860) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82267808
	ctx.lr = 0x82267880;
	sub_82267808(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82267888;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// sth r30,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r30.u16);
	// sth r30,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r30.u16);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x822678A0;
	sub_82130588(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// sth r30,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r30.u16);
	// sth r30,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r30.u16);
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

__attribute__((alias("__imp__sub_822678C4"))) PPC_WEAK_FUNC(sub_822678C4);
PPC_FUNC_IMPL(__imp__sub_822678C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822678C8"))) PPC_WEAK_FUNC(sub_822678C8);
PPC_FUNC_IMPL(__imp__sub_822678C8) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// beq cr6,0x82267904
	if (cr6.eq) goto loc_82267904;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822673a8
	ctx.lr = 0x82267900;
	sub_822673A8(ctx, base);
	// b 0x82267908
	goto loc_82267908;
loc_82267904:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82267908:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
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

__attribute__((alias("__imp__sub_82267928"))) PPC_WEAK_FUNC(sub_82267928);
PPC_FUNC_IMPL(__imp__sub_82267928) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r30,4(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lhz r9,10(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 10);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8226797c
	if (!cr6.eq) goto loc_8226797C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x82267974
	if (cr6.eq) goto loc_82267974;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822673a8
	ctx.lr = 0x82267970;
	sub_822673A8(ctx, base);
	// b 0x82267978
	goto loc_82267978;
loc_82267974:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82267978:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8226797C:
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
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

__attribute__((alias("__imp__sub_82267998"))) PPC_WEAK_FUNC(sub_82267998);
PPC_FUNC_IMPL(__imp__sub_82267998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r6,r7,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r5,20(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f12,-8(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r5,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822679D8"))) PPC_WEAK_FUNC(sub_822679D8);
PPC_FUNC_IMPL(__imp__sub_822679D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r4,r6,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// stwx r8,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r8.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r8,20(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// lvx128 v63,r4,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267A4C"))) PPC_WEAK_FUNC(sub_82267A4C);
PPC_FUNC_IMPL(__imp__sub_82267A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267A50"))) PPC_WEAK_FUNC(sub_82267A50);
PPC_FUNC_IMPL(__imp__sub_82267A50) {
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
	ctx.lr = 0x82267A58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82267a98
	if (!cr6.eq) goto loc_82267A98;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// beq cr6,0x82267a90
	if (cr6.eq) goto loc_82267A90;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822673f8
	ctx.lr = 0x82267A8C;
	sub_822673F8(ctx, base);
	// b 0x82267a94
	goto loc_82267A94;
loc_82267A90:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82267A94:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_82267A98:
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// lhz r10,6(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82267ad8
	if (!cr6.eq) goto loc_82267AD8;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// sth r28,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r28.u16);
	// beq cr6,0x82267ad0
	if (cr6.eq) goto loc_82267AD0;
	// rlwinm r3,r28,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x82267AC0;
	sub_82130528(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// sth r28,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r28.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82267AD0:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_82267AD8:
	// sth r28,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r28.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82267AE4"))) PPC_WEAK_FUNC(sub_82267AE4);
PPC_FUNC_IMPL(__imp__sub_82267AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267AE8"))) PPC_WEAK_FUNC(sub_82267AE8);
PPC_FUNC_IMPL(__imp__sub_82267AE8) {
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
	ctx.lr = 0x82267AF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r30,r28,12
	r30.s64 = r28.s64 + 12;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82267b20
	if (cr6.eq) goto loc_82267B20;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822673f8
	ctx.lr = 0x82267B1C;
	sub_822673F8(ctx, base);
	// b 0x82267b24
	goto loc_82267B24;
loc_82267B20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82267B24:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// beq cr6,0x82267b4c
	if (cr6.eq) goto loc_82267B4C;
	// rlwinm r3,r29,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x82267B3C;
	sub_82130528(ctx, base);
	// stw r3,20(r28)
	PPC_STORE_U32(r28.u32 + 20, ctx.r3.u32);
	// sth r29,26(r28)
	PPC_STORE_U16(r28.u32 + 26, r29.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82267B4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r29,26(r28)
	PPC_STORE_U16(r28.u32 + 26, r29.u16);
	// stw r3,20(r28)
	PPC_STORE_U32(r28.u32 + 20, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82267B60"))) PPC_WEAK_FUNC(sub_82267B60);
PPC_FUNC_IMPL(__imp__sub_82267B60) {
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
	// b 0x82267a50
	sub_82267A50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82267B74"))) PPC_WEAK_FUNC(sub_82267B74);
PPC_FUNC_IMPL(__imp__sub_82267B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267B78"))) PPC_WEAK_FUNC(sub_82267B78);
PPC_FUNC_IMPL(__imp__sub_82267B78) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82267808
	ctx.lr = 0x82267B9C;
	sub_82267808(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82267BA4;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// sth r30,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r30.u16);
	// sth r30,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r30.u16);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82267BBC;
	sub_82130588(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// sth r30,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r30.u16);
	// sth r30,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r30.u16);
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

__attribute__((alias("__imp__sub_82267BE0"))) PPC_WEAK_FUNC(sub_82267BE0);
PPC_FUNC_IMPL(__imp__sub_82267BE0) {
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
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30920
	ctx.r4.s64 = r11.s64 + 30920;
	// addi r3,r10,-6236
	ctx.r3.s64 = ctx.r10.s64 + -6236;
	// bl 0x82554798
	ctx.lr = 0x82267C00;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,31016
	ctx.r4.s64 = ctx.r9.s64 + 31016;
	// addi r3,r8,-6264
	ctx.r3.s64 = ctx.r8.s64 + -6264;
	// bl 0x82554798
	ctx.lr = 0x82267C14;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,31464
	ctx.r4.s64 = ctx.r7.s64 + 31464;
	// addi r3,r6,-6296
	ctx.r3.s64 = ctx.r6.s64 + -6296;
	// bl 0x82554798
	ctx.lr = 0x82267C28;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,31584
	ctx.r4.s64 = ctx.r5.s64 + 31584;
	// addi r3,r3,-6328
	ctx.r3.s64 = ctx.r3.s64 + -6328;
	// bl 0x82554798
	ctx.lr = 0x82267C3C;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,31608
	ctx.r4.s64 = r11.s64 + 31608;
	// addi r3,r10,-6352
	ctx.r3.s64 = ctx.r10.s64 + -6352;
	// bl 0x82554798
	ctx.lr = 0x82267C50;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,29920
	ctx.r4.s64 = ctx.r9.s64 + 29920;
	// addi r3,r8,-6384
	ctx.r3.s64 = ctx.r8.s64 + -6384;
	// bl 0x82554798
	ctx.lr = 0x82267C64;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,29968
	ctx.r4.s64 = ctx.r7.s64 + 29968;
	// addi r3,r6,-6416
	ctx.r3.s64 = ctx.r6.s64 + -6416;
	// bl 0x82554798
	ctx.lr = 0x82267C78;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,29992
	ctx.r4.s64 = ctx.r5.s64 + 29992;
	// addi r3,r3,-6444
	ctx.r3.s64 = ctx.r3.s64 + -6444;
	// bl 0x82554798
	ctx.lr = 0x82267C8C;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30016
	ctx.r4.s64 = r11.s64 + 30016;
	// addi r3,r10,-6476
	ctx.r3.s64 = ctx.r10.s64 + -6476;
	// bl 0x82554798
	ctx.lr = 0x82267CA0;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,30056
	ctx.r4.s64 = ctx.r9.s64 + 30056;
	// addi r3,r8,-6520
	ctx.r3.s64 = ctx.r8.s64 + -6520;
	// bl 0x82554798
	ctx.lr = 0x82267CB4;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,30088
	ctx.r4.s64 = ctx.r7.s64 + 30088;
	// addi r3,r6,-6552
	ctx.r3.s64 = ctx.r6.s64 + -6552;
	// bl 0x82554798
	ctx.lr = 0x82267CC8;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,30128
	ctx.r4.s64 = ctx.r5.s64 + 30128;
	// addi r3,r3,-6596
	ctx.r3.s64 = ctx.r3.s64 + -6596;
	// bl 0x82554798
	ctx.lr = 0x82267CDC;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30168
	ctx.r4.s64 = r11.s64 + 30168;
	// addi r3,r10,-6640
	ctx.r3.s64 = ctx.r10.s64 + -6640;
	// bl 0x82554798
	ctx.lr = 0x82267CF0;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,30208
	ctx.r4.s64 = ctx.r9.s64 + 30208;
	// addi r3,r8,-6680
	ctx.r3.s64 = ctx.r8.s64 + -6680;
	// bl 0x82554798
	ctx.lr = 0x82267D04;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,30248
	ctx.r4.s64 = ctx.r7.s64 + 30248;
	// addi r3,r6,-6716
	ctx.r3.s64 = ctx.r6.s64 + -6716;
	// bl 0x82554798
	ctx.lr = 0x82267D18;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,30320
	ctx.r4.s64 = ctx.r5.s64 + 30320;
	// addi r3,r3,-6752
	ctx.r3.s64 = ctx.r3.s64 + -6752;
	// bl 0x82554798
	ctx.lr = 0x82267D2C;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30344
	ctx.r4.s64 = r11.s64 + 30344;
	// addi r3,r10,-6796
	ctx.r3.s64 = ctx.r10.s64 + -6796;
	// bl 0x82554798
	ctx.lr = 0x82267D40;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,31128
	ctx.r4.s64 = ctx.r9.s64 + 31128;
	// addi r3,r8,-6828
	ctx.r3.s64 = ctx.r8.s64 + -6828;
	// bl 0x82554798
	ctx.lr = 0x82267D54;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,31192
	ctx.r4.s64 = ctx.r7.s64 + 31192;
	// addi r3,r6,-6860
	ctx.r3.s64 = ctx.r6.s64 + -6860;
	// bl 0x82554798
	ctx.lr = 0x82267D68;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,30384
	ctx.r4.s64 = ctx.r5.s64 + 30384;
	// addi r3,r3,-6892
	ctx.r3.s64 = ctx.r3.s64 + -6892;
	// bl 0x82554798
	ctx.lr = 0x82267D7C;
	sub_82554798(ctx, base);
	// lis r11,-32218
	r11.s64 = -2111438848;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,30480
	ctx.r4.s64 = r11.s64 + 30480;
	// addi r3,r10,-6924
	ctx.r3.s64 = ctx.r10.s64 + -6924;
	// bl 0x82554798
	ctx.lr = 0x82267D90;
	sub_82554798(ctx, base);
	// lis r9,-32218
	ctx.r9.s64 = -2111438848;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,30520
	ctx.r4.s64 = ctx.r9.s64 + 30520;
	// addi r3,r8,-6964
	ctx.r3.s64 = ctx.r8.s64 + -6964;
	// bl 0x82554798
	ctx.lr = 0x82267DA4;
	sub_82554798(ctx, base);
	// lis r7,-32218
	ctx.r7.s64 = -2111438848;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,30560
	ctx.r4.s64 = ctx.r7.s64 + 30560;
	// addi r3,r6,-7004
	ctx.r3.s64 = ctx.r6.s64 + -7004;
	// bl 0x82554798
	ctx.lr = 0x82267DB8;
	sub_82554798(ctx, base);
	// lis r5,-32218
	ctx.r5.s64 = -2111438848;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,30600
	ctx.r4.s64 = ctx.r5.s64 + 30600;
	// addi r3,r3,-7040
	ctx.r3.s64 = ctx.r3.s64 + -7040;
	// bl 0x82554798
	ctx.lr = 0x82267DCC;
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

__attribute__((alias("__imp__sub_82267DDC"))) PPC_WEAK_FUNC(sub_82267DDC);
PPC_FUNC_IMPL(__imp__sub_82267DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267DE0"))) PPC_WEAK_FUNC(sub_82267DE0);
PPC_FUNC_IMPL(__imp__sub_82267DE0) {
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
	ctx.lr = 0x82267DE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82267e28
	if (cr6.eq) goto loc_82267E28;
	// addic. r30,r11,-1
	xer.ca = r11.u32 > 0;
	r30.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x82267e28
	if (cr0.lt) goto loc_82267E28;
	// addi r11,r30,13684
	r11.s64 = r30.s64 + 13684;
	// li r29,0
	r29.s64 = 0;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r3
	r31.u64 = r11.u64 + ctx.r3.u64;
loc_82267E10:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82238408
	ctx.lr = 0x82267E18;
	sub_82238408(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// bge 0x82267e10
	if (!cr0.lt) goto loc_82267E10;
loc_82267E28:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82267E30"))) PPC_WEAK_FUNC(sub_82267E30);
PPC_FUNC_IMPL(__imp__sub_82267E30) {
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
	ctx.lr = 0x82267E38;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r31,13684
	r11.s64 = r31.s64 + 13684;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82238408
	ctx.lr = 0x82267E58;
	sub_82238408(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r9,160(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// bge cr6,0x82267e8c
	if (!cr6.lt) goto loc_82267E8C;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82267E70:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r9,160(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82267e70
	if (cr6.lt) goto loc_82267E70;
loc_82267E8C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82267E94"))) PPC_WEAK_FUNC(sub_82267E94);
PPC_FUNC_IMPL(__imp__sub_82267E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82267E98"))) PPC_WEAK_FUNC(sub_82267E98);
PPC_FUNC_IMPL(__imp__sub_82267E98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	// cmplwi cr6,r3,6
	cr6.compare<uint32_t>(ctx.r3.u32, 6, xer);
	// beq cr6,0x82267f48
	if (cr6.eq) {
		sub_82267F48(ctx, base);
		return;
	}
	// cmplwi cr6,r3,8
	cr6.compare<uint32_t>(ctx.r3.u32, 8, xer);
	// beq cr6,0x82267f48
	if (cr6.eq) {
		sub_82267F48(ctx, base);
		return;
	}
	// cmplwi cr6,r3,9
	cr6.compare<uint32_t>(ctx.r3.u32, 9, xer);
	// bne cr6,0x82268008
	if (!cr6.eq) {
		sub_82268008(ctx, base);
		return;
	}
	// cmplwi cr6,r4,21
	cr6.compare<uint32_t>(ctx.r4.u32, 21, xer);
	// bgt cr6,0x82268008
	if (cr6.gt) {
		sub_82268008(ctx, base);
		return;
	}
	// lis r12,-32218
	r12.s64 = -2111438848;
	// addi r12,r12,32464
	r12.s64 = r12.s64 + 32464;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		// ERROR: 0x82267F28
		return;
	case 1:
		// ERROR: 0x82267F30
		return;
	case 2:
		// ERROR: 0x82267F28
		return;
	case 3:
		// ERROR: 0x82267F30
		return;
	case 4:
		// ERROR: 0x82267F30
		return;
	case 5:
		// ERROR: 0x82267F30
		return;
	case 6:
		// ERROR: 0x82267F28
		return;
	case 7:
		// ERROR: 0x82267F28
		return;
	case 8:
		// ERROR: 0x82268008
		return;
	case 9:
		// ERROR: 0x82268008
		return;
	case 10:
		// ERROR: 0x82268008
		return;
	case 11:
		// ERROR: 0x82268008
		return;
	case 12:
		// ERROR: 0x82267F30
		return;
	case 13:
		// ERROR: 0x82267F30
		return;
	case 14:
		// ERROR: 0x82267F28
		return;
	case 15:
		// ERROR: 0x82267F28
		return;
	case 16:
		// ERROR: 0x82268008
		return;
	case 17:
		// ERROR: 0x82268008
		return;
	case 18:
		// ERROR: 0x82268008
		return;
	case 19:
		// ERROR: 0x82268008
		return;
	case 20:
		// ERROR: 0x82267F38
		return;
	case 21:
		// ERROR: 0x82267F40
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_82267ED0"))) PPC_WEAK_FUNC(sub_82267ED0);
PPC_FUNC_IMPL(__imp__sub_82267ED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r17{};
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32560(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32560);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,32552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32552);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,32568(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32568);
	// lwz r17,32576(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32576);
	// li r3,13
	ctx.r3.s64 = 13;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267F30"))) PPC_WEAK_FUNC(sub_82267F30);
PPC_FUNC_IMPL(__imp__sub_82267F30) {
	PPC_FUNC_PROLOGUE();
	// li r3,12
	ctx.r3.s64 = 12;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267F38"))) PPC_WEAK_FUNC(sub_82267F38);
PPC_FUNC_IMPL(__imp__sub_82267F38) {
	PPC_FUNC_PROLOGUE();
	// li r3,21
	ctx.r3.s64 = 21;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267F40"))) PPC_WEAK_FUNC(sub_82267F40);
PPC_FUNC_IMPL(__imp__sub_82267F40) {
	PPC_FUNC_PROLOGUE();
	// li r3,20
	ctx.r3.s64 = 20;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267F48"))) PPC_WEAK_FUNC(sub_82267F48);
PPC_FUNC_IMPL(__imp__sub_82267F48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	// cmplwi cr6,r4,15
	cr6.compare<uint32_t>(ctx.r4.u32, 15, xer);
	// bgt cr6,0x82268008
	if (cr6.gt) {
		sub_82268008(ctx, base);
		return;
	}
	// lis r12,-32218
	r12.s64 = -2111438848;
	// addi r12,r12,32616
	r12.s64 = r12.s64 + 32616;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		// ERROR: 0x82267FA8
		return;
	case 1:
		// ERROR: 0x82267FB0
		return;
	case 2:
		// ERROR: 0x82267FB8
		return;
	case 3:
		// ERROR: 0x82267FC0
		return;
	case 4:
		// ERROR: 0x82267FC8
		return;
	case 5:
		// ERROR: 0x82267FD0
		return;
	case 6:
		// ERROR: 0x82268008
		return;
	case 7:
		// ERROR: 0x82267FD8
		return;
	case 8:
		// ERROR: 0x82267FE0
		return;
	case 9:
		// ERROR: 0x82267FE8
		return;
	case 10:
		// ERROR: 0x82267FF0
		return;
	case 11:
		// ERROR: 0x82267FF8
		return;
	case 12:
		// ERROR: 0x82268000
		return;
	case 13:
		// ERROR: 0x82268000
		return;
	case 14:
		// ERROR: 0x82268000
		return;
	case 15:
		// ERROR: 0x82268000
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_82267F68"))) PPC_WEAK_FUNC(sub_82267F68);
PPC_FUNC_IMPL(__imp__sub_82267F68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r17{};
	// lwz r17,32680(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32680);
	// lwz r17,32688(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32688);
	// lwz r17,32696(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32696);
	// lwz r17,32704(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32704);
	// lwz r17,32712(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32712);
	// lwz r17,32720(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32720);
	// lwz r17,-32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32760);
	// lwz r17,32728(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32728);
	// lwz r17,32736(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32736);
	// lwz r17,32744(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32744);
	// lwz r17,32752(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32752);
	// lwz r17,32760(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32760);
	// lwz r17,-32768(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32768);
	// lwz r17,-32768(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32768);
	// lwz r17,-32768(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32768);
	// lwz r17,-32768(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -32768);
	// li r3,7
	ctx.r3.s64 = 7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FB0"))) PPC_WEAK_FUNC(sub_82267FB0);
PPC_FUNC_IMPL(__imp__sub_82267FB0) {
	PPC_FUNC_PROLOGUE();
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FB8"))) PPC_WEAK_FUNC(sub_82267FB8);
PPC_FUNC_IMPL(__imp__sub_82267FB8) {
	PPC_FUNC_PROLOGUE();
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FC0"))) PPC_WEAK_FUNC(sub_82267FC0);
PPC_FUNC_IMPL(__imp__sub_82267FC0) {
	PPC_FUNC_PROLOGUE();
	// li r3,6
	ctx.r3.s64 = 6;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FC8"))) PPC_WEAK_FUNC(sub_82267FC8);
PPC_FUNC_IMPL(__imp__sub_82267FC8) {
	PPC_FUNC_PROLOGUE();
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FD0"))) PPC_WEAK_FUNC(sub_82267FD0);
PPC_FUNC_IMPL(__imp__sub_82267FD0) {
	PPC_FUNC_PROLOGUE();
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FD8"))) PPC_WEAK_FUNC(sub_82267FD8);
PPC_FUNC_IMPL(__imp__sub_82267FD8) {
	PPC_FUNC_PROLOGUE();
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FE0"))) PPC_WEAK_FUNC(sub_82267FE0);
PPC_FUNC_IMPL(__imp__sub_82267FE0) {
	PPC_FUNC_PROLOGUE();
	// li r3,10
	ctx.r3.s64 = 10;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FE8"))) PPC_WEAK_FUNC(sub_82267FE8);
PPC_FUNC_IMPL(__imp__sub_82267FE8) {
	PPC_FUNC_PROLOGUE();
	// li r3,29
	ctx.r3.s64 = 29;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FF0"))) PPC_WEAK_FUNC(sub_82267FF0);
PPC_FUNC_IMPL(__imp__sub_82267FF0) {
	PPC_FUNC_PROLOGUE();
	// li r3,28
	ctx.r3.s64 = 28;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82267FF8"))) PPC_WEAK_FUNC(sub_82267FF8);
PPC_FUNC_IMPL(__imp__sub_82267FF8) {
	PPC_FUNC_PROLOGUE();
	// li r3,9
	ctx.r3.s64 = 9;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82268000"))) PPC_WEAK_FUNC(sub_82268000);
PPC_FUNC_IMPL(__imp__sub_82268000) {
	PPC_FUNC_PROLOGUE();
	// li r3,19
	ctx.r3.s64 = 19;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82268008"))) PPC_WEAK_FUNC(sub_82268008);
PPC_FUNC_IMPL(__imp__sub_82268008) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82268010"))) PPC_WEAK_FUNC(sub_82268010);
PPC_FUNC_IMPL(__imp__sub_82268010) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82268030
	if (!cr6.lt) goto loc_82268030;
	// li r11,0
	r11.s64 = 0;
loc_82268030:
	// addi r11,r11,13684
	r11.s64 = r11.s64 + 13684;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r9,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// b 0x822384c0
	sub_822384C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82268050"))) PPC_WEAK_FUNC(sub_82268050);
PPC_FUNC_IMPL(__imp__sub_82268050) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82268054"))) PPC_WEAK_FUNC(sub_82268054);
PPC_FUNC_IMPL(__imp__sub_82268054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82268058"))) PPC_WEAK_FUNC(sub_82268058);
PPC_FUNC_IMPL(__imp__sub_82268058) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r10,r10,13684
	ctx.r10.s64 = ctx.r10.s64 + 13684;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r6,r10,13684
	ctx.r6.s64 = ctx.r10.s64 + 13684;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// ble cr6,0x822680cc
	if (!cr6.gt) goto loc_822680CC;
	// addi r7,r10,13685
	ctx.r7.s64 = ctx.r10.s64 + 13685;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// stwx r3,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r3.u32);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r10,r10,13685
	ctx.r10.s64 = ctx.r10.s64 + 13685;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r9.u32);
	// lwz r9,-10028(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r6,r10,13685
	ctx.r6.s64 = ctx.r10.s64 + 13685;
	// addi r5,r10,13684
	ctx.r5.s64 = ctx.r10.s64 + 13684;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r9,128
	ctx.r3.s64 = ctx.r9.s64 + 128;
	// lwzx r5,r4,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// b 0x822388a8
	sub_822388A8(ctx, base);
	return;
loc_822680CC:
	// addi r7,r10,13683
	ctx.r7.s64 = ctx.r10.s64 + 13683;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// stwx r3,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r3.u32);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r10,r10,13683
	ctx.r10.s64 = ctx.r10.s64 + 13683;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r9.u32);
	// lwz r10,-10028(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// addi r6,r10,13684
	ctx.r6.s64 = ctx.r10.s64 + 13684;
	// addi r5,r10,13683
	ctx.r5.s64 = ctx.r10.s64 + 13683;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r4,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// b 0x822388a8
	sub_822388A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82268114"))) PPC_WEAK_FUNC(sub_82268114);
PPC_FUNC_IMPL(__imp__sub_82268114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82268118"))) PPC_WEAK_FUNC(sub_82268118);
PPC_FUNC_IMPL(__imp__sub_82268118) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822681c4
	if (!cr6.gt) goto loc_822681C4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8226814C:
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// bne cr6,0x82268160
	if (!cr6.eq) goto loc_82268160;
	// li r10,5
	ctx.r10.s64 = 5;
	// b 0x82268180
	goto loc_82268180;
loc_82268160:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x82268170
	if (!cr6.eq) goto loc_82268170;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82268180
	goto loc_82268180;
loc_82268170:
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r10,r11,3
	ctx.r10.s64 = r11.s64 + 3;
loc_82268180:
	// addi r11,r31,13684
	r11.s64 = r31.s64 + 13684;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822681b4
	if (cr6.eq) goto loc_822681B4;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r10,38(r9)
	PPC_STORE_U8(ctx.r9.u32 + 38, ctx.r10.u8);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r6,r3,80
	ctx.r6.s64 = ctx.r3.s64 + 80;
	// bl 0x822384c0
	ctx.lr = 0x822681B4;
	sub_822384C0(ctx, base);
loc_822681B4:
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8226814c
	if (cr6.lt) goto loc_8226814C;
loc_822681C4:
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

__attribute__((alias("__imp__sub_822681E0"))) PPC_WEAK_FUNC(sub_822681E0);
PPC_FUNC_IMPL(__imp__sub_822681E0) {
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
	ctx.lr = 0x822681E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268268
	if (cr6.eq) goto loc_82268268;
	// addi r29,r11,128
	r29.s64 = r11.s64 + 128;
	// bl 0x822387e8
	ctx.lr = 0x82268210;
	sub_822387E8(ctx, base);
	// addi r11,r31,13684
	r11.s64 = r31.s64 + 13684;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,4
	ctx.r4.s64 = 4;
	// stwx r3,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r3.u32);
	// stb r10,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r10.u8);
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x82237b38
	ctx.lr = 0x82268230;
	sub_82237B38(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r4,r31,r30
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x82238688
	ctx.lr = 0x82268240;
	sub_82238688(ctx, base);
	// lwzx r7,r31,r30
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r9,38(r7)
	PPC_STORE_U8(ctx.r7.u32 + 38, ctx.r9.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822384c0
	ctx.lr = 0x82268268;
	sub_822384C0(ctx, base);
loc_82268268:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82268270"))) PPC_WEAK_FUNC(sub_82268270);
PPC_FUNC_IMPL(__imp__sub_82268270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x82268278;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addis r31,r26,1
	r31.s64 = r26.s64 + 65536;
	// addi r31,r31,-11228
	r31.s64 = r31.s64 + -11228;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226873c
	if (cr6.eq) goto loc_8226873C;
	// bl 0x82178848
	ctx.lr = 0x82268298;
	sub_82178848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r10,-21512
	ctx.r4.s64 = ctx.r10.s64 + -21512;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x822682B8;
	sub_825EE0E0(ctx, base);
	// lbz r5,159(r26)
	ctx.r5.u64 = PPC_LOAD_U8(r26.u32 + 159);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822682f0
	if (cr6.eq) goto loc_822682F0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,-5356
	ctx.r4.s64 = r11.s64 + -5356;
	// bl 0x825ee0e0
	ctx.lr = 0x822682D4;
	sub_825EE0E0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r5,160(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 160);
	// stb r10,159(r26)
	PPC_STORE_U8(r26.u32 + 159, ctx.r10.u8);
	// addi r4,r9,-5376
	ctx.r4.s64 = ctx.r9.s64 + -5376;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x825ee0e0
	ctx.lr = 0x822682F0;
	sub_825EE0E0(ctx, base);
loc_822682F0:
	// lwz r11,160(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 160);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82268324
	if (!cr6.gt) goto loc_82268324;
	// lbz r11,158(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5396
	ctx.r4.s64 = r11.s64 + -5396;
	// beq cr6,0x8226831c
	if (cr6.eq) goto loc_8226831C;
	// lwz r5,168(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 168);
	// b 0x82268330
	goto loc_82268330;
loc_8226831C:
	// li r5,-1
	ctx.r5.s64 = -1;
	// b 0x82268330
	goto loc_82268330;
loc_82268324:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-5396
	ctx.r4.s64 = r11.s64 + -5396;
loc_82268330:
	// bl 0x825ee0e0
	ctx.lr = 0x82268334;
	sub_825EE0E0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5412
	ctx.r4.s64 = r11.s64 + -5412;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82268348;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5420
	ctx.r4.s64 = ctx.r10.s64 + -5420;
	// bl 0x825ee2d8
	ctx.lr = 0x8226835C;
	sub_825EE2D8(ctx, base);
	// lbz r8,156(r26)
	ctx.r8.u64 = PPC_LOAD_U8(r26.u32 + 156);
	// lis r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// ori r29,r9,54609
	r29.u64 = ctx.r9.u64 | 54609;
	// beq cr6,0x822683dc
	if (cr6.eq) goto loc_822683DC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,-5432
	ctx.r4.s64 = r11.s64 + -5432;
	// bl 0x825ee0e0
	ctx.lr = 0x82268384;
	sub_825EE0E0(ctx, base);
	// lbzx r10,r26,r29
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + r29.u32);
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822683b8
	if (cr6.eq) goto loc_822683B8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5448
	ctx.r4.s64 = r11.s64 + -5448;
	// bl 0x82218310
	ctx.lr = 0x822683A0;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5456
	ctx.r4.s64 = ctx.r10.s64 + -5456;
	// bl 0x825ee2d8
	ctx.lr = 0x822683B4;
	sub_825EE2D8(ctx, base);
	// b 0x822684e0
	goto loc_822684E0;
loc_822683B8:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5472
	ctx.r4.s64 = r11.s64 + -5472;
	// bl 0x82218310
	ctx.lr = 0x822683C4;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5456
	ctx.r4.s64 = ctx.r10.s64 + -5456;
	// bl 0x825ee2d8
	ctx.lr = 0x822683D8;
	sub_825EE2D8(ctx, base);
	// b 0x822684e0
	goto loc_822684E0;
loc_822683DC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// addi r4,r11,-5484
	ctx.r4.s64 = r11.s64 + -5484;
	// bl 0x82218310
	ctx.lr = 0x822683EC;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5456
	ctx.r4.s64 = ctx.r10.s64 + -5456;
	// bl 0x825ee2d8
	ctx.lr = 0x82268400;
	sub_825EE2D8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,17292(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17292);
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmplwi cr6,r11,15
	cr6.compare<uint32_t>(r11.u32, 15, xer);
	// bgt cr6,0x822684cc
	if (cr6.gt) goto loc_822684CC;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-31700
	r12.s64 = r12.s64 + -31700;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8226846C;
	case 1:
		goto loc_82268474;
	case 2:
		goto loc_8226847C;
	case 3:
		goto loc_82268484;
	case 4:
		goto loc_8226848C;
	case 5:
		goto loc_82268494;
	case 6:
		goto loc_822684CC;
	case 7:
		goto loc_8226849C;
	case 8:
		goto loc_822684A4;
	case 9:
		goto loc_822684AC;
	case 10:
		goto loc_822684B4;
	case 11:
		goto loc_822684BC;
	case 12:
		goto loc_822684C4;
	case 13:
		goto loc_822684C4;
	case 14:
		goto loc_822684C4;
	case 15:
		goto loc_822684C4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-31636(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31636);
	// lwz r17,-31628(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31628);
	// lwz r17,-31620(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31620);
	// lwz r17,-31612(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31612);
	// lwz r17,-31604(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31604);
	// lwz r17,-31596(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31596);
	// lwz r17,-31540(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31540);
	// lwz r17,-31588(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31588);
	// lwz r17,-31580(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31580);
	// lwz r17,-31572(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31572);
	// lwz r17,-31564(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31564);
	// lwz r17,-31556(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31556);
	// lwz r17,-31548(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31548);
	// lwz r17,-31548(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31548);
	// lwz r17,-31548(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31548);
	// lwz r17,-31548(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31548);
loc_8226846C:
	// li r5,7
	ctx.r5.s64 = 7;
	// b 0x822684d0
	goto loc_822684D0;
loc_82268474:
	// li r5,8
	ctx.r5.s64 = 8;
	// b 0x822684d0
	goto loc_822684D0;
loc_8226847C:
	// li r5,5
	ctx.r5.s64 = 5;
	// b 0x822684d0
	goto loc_822684D0;
loc_82268484:
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x822684d0
	goto loc_822684D0;
loc_8226848C:
	// li r5,4
	ctx.r5.s64 = 4;
	// b 0x822684d0
	goto loc_822684D0;
loc_82268494:
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x822684d0
	goto loc_822684D0;
loc_8226849C:
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684A4:
	// li r5,10
	ctx.r5.s64 = 10;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684AC:
	// li r5,29
	ctx.r5.s64 = 29;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684B4:
	// li r5,28
	ctx.r5.s64 = 28;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684BC:
	// li r5,9
	ctx.r5.s64 = 9;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684C4:
	// li r5,19
	ctx.r5.s64 = 19;
	// b 0x822684d0
	goto loc_822684D0;
loc_822684CC:
	// li r5,1
	ctx.r5.s64 = 1;
loc_822684D0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,-5432
	ctx.r4.s64 = r11.s64 + -5432;
	// bl 0x825ee0e0
	ctx.lr = 0x822684E0;
	sub_825EE0E0(ctx, base);
loc_822684E0:
	// lwz r11,160(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 160);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r28,r10,-5496
	r28.s64 = ctx.r10.s64 + -5496;
	// bne cr6,0x82268500
	if (!cr6.eq) goto loc_82268500;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5516
	ctx.r4.s64 = r11.s64 + -5516;
	// b 0x82268524
	goto loc_82268524;
loc_82268500:
	// ble cr6,0x8226853c
	if (!cr6.gt) goto loc_8226853C;
	// lbz r11,158(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226851c
	if (cr6.eq) goto loc_8226851C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5532
	ctx.r4.s64 = r11.s64 + -5532;
	// b 0x82268524
	goto loc_82268524;
loc_8226851C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5548
	ctx.r4.s64 = r11.s64 + -5548;
loc_82268524:
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8226852C;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8226853C;
	sub_825EE2D8(ctx, base);
loc_8226853C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-5564
	ctx.r4.s64 = r11.s64 + -5564;
	// bl 0x825ee0e0
	ctx.lr = 0x82268550;
	sub_825EE0E0(ctx, base);
	// lbzx r10,r26,r29
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + r29.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// add r27,r26,r29
	r27.u64 = r26.u64 + r29.u64;
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x82251d70
	ctx.lr = 0x82268568;
	sub_82251D70(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// addi r4,r11,-5584
	ctx.r4.s64 = r11.s64 + -5584;
	// li r5,1
	ctx.r5.s64 = 1;
	// bne cr6,0x82268588
	if (!cr6.eq) goto loc_82268588;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82268588:
	// bl 0x825ee0e0
	ctx.lr = 0x8226858C;
	sub_825EE0E0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r5,r11,-5596
	ctx.r5.s64 = r11.s64 + -5596;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822685A0;
	sub_82137A08(ctx, base);
	// cmplwi cr6,r29,8
	cr6.compare<uint32_t>(r29.u32, 8, xer);
	// bgt cr6,0x82268658
	if (cr6.gt) goto loc_82268658;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-31296
	r12.s64 = r12.s64 + -31296;
	// rlwinm r0,r29,2,0,29
	r0.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r29.u64) {
	case 0:
		goto loc_822685E4;
	case 1:
		goto loc_822685F0;
	case 2:
		goto loc_822685FC;
	case 3:
		goto loc_82268608;
	case 4:
		goto loc_82268614;
	case 5:
		goto loc_82268658;
	case 6:
		goto loc_82268620;
	case 7:
		goto loc_8226862C;
	case 8:
		goto loc_82268638;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-31260(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31260);
	// lwz r17,-31248(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31248);
	// lwz r17,-31236(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31236);
	// lwz r17,-31224(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31224);
	// lwz r17,-31212(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31212);
	// lwz r17,-31144(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31144);
	// lwz r17,-31200(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31200);
	// lwz r17,-31188(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31188);
	// lwz r17,-31176(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31176);
loc_822685E4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5612
	ctx.r4.s64 = r11.s64 + -5612;
	// b 0x82268640
	goto loc_82268640;
loc_822685F0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5632
	ctx.r4.s64 = r11.s64 + -5632;
	// b 0x82268640
	goto loc_82268640;
loc_822685FC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r5,r11,-5660
	ctx.r5.s64 = r11.s64 + -5660;
	// b 0x8226864c
	goto loc_8226864C;
loc_82268608:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5676
	ctx.r4.s64 = r11.s64 + -5676;
	// b 0x82268640
	goto loc_82268640;
loc_82268614:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5696
	ctx.r4.s64 = r11.s64 + -5696;
	// b 0x82268640
	goto loc_82268640;
loc_82268620:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5728
	ctx.r4.s64 = r11.s64 + -5728;
	// b 0x82268640
	goto loc_82268640;
loc_8226862C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5756
	ctx.r4.s64 = r11.s64 + -5756;
	// b 0x82268640
	goto loc_82268640;
loc_82268638:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5788
	ctx.r4.s64 = r11.s64 + -5788;
loc_82268640:
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82268648;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_8226864C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x825ee2d8
	ctx.lr = 0x82268658;
	sub_825EE2D8(ctx, base);
loc_82268658:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-5804
	ctx.r4.s64 = r11.s64 + -5804;
	// bl 0x825ee0e0
	ctx.lr = 0x8226866C;
	sub_825EE0E0(ctx, base);
	// lwz r10,168(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 168);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82268690
	if (!cr6.eq) goto loc_82268690;
	// lbz r11,158(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268690
	if (cr6.eq) goto loc_82268690;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5832
	ctx.r4.s64 = r11.s64 + -5832;
	// b 0x822686bc
	goto loc_822686BC;
loc_82268690:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822686d4
	if (cr6.eq) goto loc_822686D4;
	// lbz r11,158(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822686d4
	if (!cr6.eq) goto loc_822686D4;
	// lwz r11,160(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 160);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x822686d4
	if (!cr6.gt) goto loc_822686D4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-5864
	ctx.r4.s64 = r11.s64 + -5864;
loc_822686BC:
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822686C4;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x822686D4;
	sub_825EE2D8(ctx, base);
loc_822686D4:
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,54320
	ctx.r10.u64 = r11.u64 | 54320;
	// lbzx r9,r26,r10
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82268728
	if (cr6.eq) goto loc_82268728;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// addi r4,r11,-5880
	ctx.r4.s64 = r11.s64 + -5880;
	// bl 0x82218310
	ctx.lr = 0x822686F8;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5892
	ctx.r4.s64 = ctx.r10.s64 + -5892;
	// bl 0x825ee2d8
	ctx.lr = 0x8226870C;
	sub_825EE2D8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r9,-5908
	ctx.r4.s64 = ctx.r9.s64 + -5908;
	// bl 0x825ee0e0
	ctx.lr = 0x82268720;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82268728:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-5908
	ctx.r4.s64 = r11.s64 + -5908;
	// bl 0x825ee0e0
	ctx.lr = 0x8226873C;
	sub_825EE0E0(ctx, base);
loc_8226873C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82268744"))) PPC_WEAK_FUNC(sub_82268744);
PPC_FUNC_IMPL(__imp__sub_82268744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82268748"))) PPC_WEAK_FUNC(sub_82268748);
PPC_FUNC_IMPL(__imp__sub_82268748) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x8226875C;
	sub_82387928(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// addi r4,r9,-21652
	ctx.r4.s64 = ctx.r9.s64 + -21652;
	// li r8,10000
	ctx.r8.s64 = 10000;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// li r7,1450
	ctx.r7.s64 = 1450;
	// li r6,1450
	ctx.r6.s64 = 1450;
	// li r9,1
	ctx.r9.s64 = 1;
	// bne cr6,0x82268790
	if (!cr6.eq) goto loc_82268790;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r10,-5308
	ctx.r5.s64 = ctx.r10.s64 + -5308;
	// b 0x82268798
	goto loc_82268798;
loc_82268790:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r10,-5336
	ctx.r5.s64 = ctx.r10.s64 + -5336;
loc_82268798:
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x821fb938
	ctx.lr = 0x822687A0;
	sub_821FB938(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822687B0"))) PPC_WEAK_FUNC(sub_822687B0);
PPC_FUNC_IMPL(__imp__sub_822687B0) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-21652
	ctx.r4.s64 = ctx.r10.s64 + -21652;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f96c8
	ctx.lr = 0x822687D8;
	sub_821F96C8(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,54308
	ctx.r7.u64 = ctx.r9.u64 | 54308;
	// ori r6,r8,54312
	ctx.r6.u64 = ctx.r8.u64 | 54312;
	// li r11,0
	r11.s64 = 0;
	// stwx r11,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r11.u32);
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82268808"))) PPC_WEAK_FUNC(sub_82268808);
PPC_FUNC_IMPL(__imp__sub_82268808) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-13512(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// lfs f13,-4960(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4960);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82268854
	if (!cr6.gt) goto loc_82268854;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,-4964(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4964);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82268854
	if (!cr6.lt) goto loc_82268854;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r9,-12360
	ctx.r8.s64 = ctx.r9.s64 + -12360;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// cmpwi cr6,r6,5
	cr6.compare<int32_t>(ctx.r6.s32, 5, xer);
	// bne cr6,0x82268854
	if (!cr6.eq) goto loc_82268854;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
loc_82268854:
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// lfs f0,356(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 356);
	f0.f64 = double(temp.f32);
	// stfs f0,-13512(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -13512, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226886C"))) PPC_WEAK_FUNC(sub_8226886C);
PPC_FUNC_IMPL(__imp__sub_8226886C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82268870"))) PPC_WEAK_FUNC(sub_82268870);
PPC_FUNC_IMPL(__imp__sub_82268870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-13516(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13516);
	f0.f64 = double(temp.f32);
	// lfs f13,-4952(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4952);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822688bc
	if (!cr6.gt) goto loc_822688BC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,-4956(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4956);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822688bc
	if (!cr6.lt) goto loc_822688BC;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r9,-12360
	ctx.r8.s64 = ctx.r9.s64 + -12360;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// cmpwi cr6,r6,6
	cr6.compare<int32_t>(ctx.r6.s32, 6, xer);
	// bne cr6,0x822688bc
	if (!cr6.eq) goto loc_822688BC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
loc_822688BC:
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// lfs f0,344(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 344);
	f0.f64 = double(temp.f32);
	// stfs f0,-13516(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -13516, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822688D4"))) PPC_WEAK_FUNC(sub_822688D4);
PPC_FUNC_IMPL(__imp__sub_822688D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822688D8"))) PPC_WEAK_FUNC(sub_822688D8);
PPC_FUNC_IMPL(__imp__sub_822688D8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82268910
	if (cr6.eq) goto loc_82268910;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lhz r30,8(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x82268914
	goto loc_82268914;
loc_82268910:
	// li r30,0
	r30.s64 = 0;
loc_82268914:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268924;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82268928;
	sub_822A8108(ctx, base);
	// mulli r11,r30,368
	r11.s64 = r30.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r10,r11,240
	ctx.r10.s64 = r11.s64 + 240;
	// lfs f0,244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 248);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,240(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 240);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// stw r30,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r30.u32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f0,32668(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32668);
	f0.f64 = double(temp.f32);
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// bge cr6,0x82268998
	if (!cr6.lt) goto loc_82268998;
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82268998
	if (!cr6.eq) goto loc_82268998;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268998:
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

__attribute__((alias("__imp__sub_822689B0"))) PPC_WEAK_FUNC(sub_822689B0);
PPC_FUNC_IMPL(__imp__sub_822689B0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822689e8
	if (cr6.eq) goto loc_822689E8;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lhz r30,8(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x822689ec
	goto loc_822689EC;
loc_822689E8:
	// li r30,0
	r30.s64 = 0;
loc_822689EC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822689FC;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82268A00;
	sub_822A8108(ctx, base);
	// mulli r11,r30,368
	r11.s64 = r30.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r10,r11,240
	ctx.r10.s64 = r11.s64 + 240;
	// lfs f0,244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 248);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,240(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 240);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f0,32668(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32668);
	f0.f64 = double(temp.f32);
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// ble cr6,0x82268a6c
	if (!cr6.gt) goto loc_82268A6C;
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82268a6c
	if (!cr6.eq) goto loc_82268A6C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268A6C:
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

__attribute__((alias("__imp__sub_82268A84"))) PPC_WEAK_FUNC(sub_82268A84);
PPC_FUNC_IMPL(__imp__sub_82268A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

