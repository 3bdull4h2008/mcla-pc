#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82695290"))) PPC_WEAK_FUNC(sub_82695290);
PPC_FUNC_IMPL(__imp__sub_82695290) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lhz r11,156(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 156);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r11,152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stw r9,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826952B8"))) PPC_WEAK_FUNC(sub_826952B8);
PPC_FUNC_IMPL(__imp__sub_826952B8) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x826949b0
	ctx.lr = 0x826952DC;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826952ec
	if (cr6.eq) goto loc_826952EC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
loc_826952EC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82695300"))) PPC_WEAK_FUNC(sub_82695300);
PPC_FUNC_IMPL(__imp__sub_82695300) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// bl 0x826949b0
	ctx.lr = 0x82695320;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269533c
	if (cr6.eq) goto loc_8269533C;
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
loc_8269533C:
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

__attribute__((alias("__imp__sub_82695350"))) PPC_WEAK_FUNC(sub_82695350);
PPC_FUNC_IMPL(__imp__sub_82695350) {
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
	ctx.lr = 0x82695358;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r30.u32);
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x826949b0
	ctx.lr = 0x82695378;
	sub_826949B0(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826953e0
	if (!cr6.gt) goto loc_826953E0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r11,r31,20
	r11.s64 = r31.s64 + 20;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,-4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// bl 0x826949b0
	ctx.lr = 0x826953AC;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826953bc
	if (cr6.eq) goto loc_826953BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x826953c0
	goto loc_826953C0;
loc_826953BC:
	// li r11,0
	r11.s64 = 0;
loc_826953C0:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r7,0(r28)
	PPC_STORE_U8(r28.u32 + 0, ctx.r7.u8);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826953E0:
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r11.u8);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826953F4"))) PPC_WEAK_FUNC(sub_826953F4);
PPC_FUNC_IMPL(__imp__sub_826953F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826953F8"))) PPC_WEAK_FUNC(sub_826953F8);
PPC_FUNC_IMPL(__imp__sub_826953F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82695418
	if (!cr6.gt) goto loc_82695418;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r11,r3,20
	r11.s64 = ctx.r3.s64 + 20;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// blr 
	return;
loc_82695418:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,31892
	ctx.r3.s64 = r11.s64 + 31892;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82695424"))) PPC_WEAK_FUNC(sub_82695424);
PPC_FUNC_IMPL(__imp__sub_82695424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82695428"))) PPC_WEAK_FUNC(sub_82695428);
PPC_FUNC_IMPL(__imp__sub_82695428) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82695430;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// stw r22,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r22.u32);
	// addic. r28,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	r28.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// li r29,1
	r29.s64 = 1;
	// mr r30,r22
	r30.u64 = r22.u64;
	// ble 0x8269556c
	if (!cr0.gt) goto loc_8269556C;
	// lis r26,-32130
	r26.s64 = -2105671680;
loc_82695464:
	// lwz r11,548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 548);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82695488
	if (cr6.eq) goto loc_82695488;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// stw r11,548(r31)
	PPC_STORE_U32(r31.u32 + 548, r11.u32);
	// lbz r9,552(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 552);
	// extsb r3,r9
	ctx.r3.s64 = ctx.r9.s8;
	// b 0x826954b8
	goto loc_826954B8;
loc_82695488:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x826954b0
	if (!cr6.lt) goto loc_826954B0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x826954b8
	goto loc_826954B8;
loc_826954B0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x826954B8;
	sub_821BE4F0(ctx, base);
loc_826954B8:
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// bne cr6,0x826954cc
	if (!cr6.eq) goto loc_826954CC;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_826954CC:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r11,-31340(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -31340);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x826954f0
	if (!cr6.eq) goto loc_826954F0;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826954f0
	if (!cr6.eq) goto loc_826954F0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cf9b8
	ctx.lr = 0x826954F0;
	sub_821CF9B8(ctx, base);
loc_826954F0:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82695560
	if (cr6.eq) goto loc_82695560;
	// extsb r10,r25
	ctx.r10.s64 = r25.s8;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8269556c
	if (cr6.eq) goto loc_8269556C;
	// clrlwi r10,r24,24
	ctx.r10.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82695548
	if (cr6.eq) goto loc_82695548;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82695548
	if (cr6.eq) goto loc_82695548;
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x82695554
	if (cr6.eq) goto loc_82695554;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x82695554
	if (cr6.eq) goto loc_82695554;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x82695554
	if (cr6.eq) goto loc_82695554;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x82695554
	if (cr6.eq) goto loc_82695554;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82695554
	if (cr6.eq) goto loc_82695554;
loc_82695548:
	// stbx r11,r30,r27
	PPC_STORE_U8(r30.u32 + r27.u32, r11.u8);
	// mr r29,r22
	r29.u64 = r22.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82695554:
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x82695464
	if (cr6.lt) goto loc_82695464;
	// b 0x8269556c
	goto loc_8269556C;
loc_82695560:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8269556c
	if (!cr6.eq) goto loc_8269556C;
	// li r30,-1
	r30.s64 = -1;
loc_8269556C:
	// addic. r10,r30,-1
	xer.ca = r30.u32 > 0;
	ctx.r10.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x826955b0
	if (cr0.lt) goto loc_826955B0;
loc_82695574:
	// lbzx r11,r10,r27
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r27.u32);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x826955a4
	if (cr6.eq) goto loc_826955A4;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x826955a4
	if (cr6.eq) goto loc_826955A4;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x826955a4
	if (cr6.eq) goto loc_826955A4;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x826955a4
	if (cr6.eq) goto loc_826955A4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826955b0
	if (!cr6.eq) goto loc_826955B0;
loc_826955A4:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// bge 0x82695574
	if (!cr0.lt) goto loc_82695574;
loc_826955B0:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// blt cr6,0x826955c0
	if (cr6.lt) goto loc_826955C0;
	// stbx r22,r30,r27
	PPC_STORE_U8(r30.u32 + r27.u32, r22.u8);
loc_826955C0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_826955C8"))) PPC_WEAK_FUNC(sub_826955C8);
PPC_FUNC_IMPL(__imp__sub_826955C8) {
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
	ctx.lr = 0x826955D0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x821bdcf8
	ctx.lr = 0x826955E0;
	sub_821BDCF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r29,16(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,62
	ctx.r6.s64 = 62;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82695428
	ctx.lr = 0x82695604;
	sub_82695428(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x821be568
	ctx.lr = 0x82695614;
	sub_821BE568(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r29,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r29.u32);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// extsb r11,r10
	r11.s64 = ctx.r10.s8;
	// addi r9,r11,-47
	ctx.r9.s64 = r11.s64 + -47;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8269563C"))) PPC_WEAK_FUNC(sub_8269563C);
PPC_FUNC_IMPL(__imp__sub_8269563C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82695640"))) PPC_WEAK_FUNC(sub_82695640);
PPC_FUNC_IMPL(__imp__sub_82695640) {
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
	ctx.lr = 0x82695648;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,32
	ctx.r3.s64 = 32;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x82130528
	ctx.lr = 0x82695660;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826956bc
	if (cr6.eq) goto loc_826956BC;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// lhz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x82695688;
	sub_821C9650(ctx, base);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82695698:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82695698
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82695698;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826956BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826956C8"))) PPC_WEAK_FUNC(sub_826956C8);
PPC_FUNC_IMPL(__imp__sub_826956C8) {
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
	ctx.lr = 0x826956D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720a08
	ctx.lr = 0x826956EC;
	sub_82720A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823db670
	ctx.lr = 0x826956FC;
	sub_823DB670(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r30,92
	ctx.r3.s64 = r30.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x8269570C;
	sub_823DB670(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82695720"))) PPC_WEAK_FUNC(sub_82695720);
PPC_FUNC_IMPL(__imp__sub_82695720) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r10,r11,32108
	ctx.r10.s64 = r11.s64 + 32108;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82695760
	if (cr6.eq) goto loc_82695760;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82695760;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82695760:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82695780
	if (cr6.eq) goto loc_82695780;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82695780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82695780:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r8,r11,-19708
	ctx.r8.s64 = r11.s64 + -19708;
	// addi r7,r10,-21500
	ctx.r7.s64 = ctx.r10.s64 + -21500;
	// addi r6,r9,-5056
	ctx.r6.s64 = ctx.r9.s64 + -5056;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// stw r7,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r7.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826957B8"))) PPC_WEAK_FUNC(sub_826957B8);
PPC_FUNC_IMPL(__imp__sub_826957B8) {
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
	// bl 0x82695720
	ctx.lr = 0x826957D8;
	sub_82695720(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826957f0
	if (cr6.eq) goto loc_826957F0;
	// bl 0x82130588
	ctx.lr = 0x826957EC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826957F0:
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

__attribute__((alias("__imp__sub_82695808"))) PPC_WEAK_FUNC(sub_82695808);
PPC_FUNC_IMPL(__imp__sub_82695808) {
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
	ctx.lr = 0x82695810;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// addi r10,r23,4
	ctx.r10.s64 = r23.s64 + 4;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// subf r10,r4,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r4.s64;
loc_8269583C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8269583c
	if (!cr6.eq) goto loc_8269583C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// addi r25,r10,-4944
	r25.s64 = ctx.r10.s64 + -4944;
	// addi r24,r11,3998
	r24.s64 = r11.s64 + 3998;
	// bne cr6,0x82695894
	if (!cr6.eq) goto loc_82695894;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82695870;
	sub_82130528(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82695890
	if (cr6.eq) goto loc_82695890;
	// stw r25,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r26,4
	ctx.r3.s64 = r26.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x8269588C;
	sub_82720A50(ctx, base);
	// b 0x82695894
	goto loc_82695894;
loc_82695890:
	// li r26,0
	r26.s64 = 0;
loc_82695894:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x826958c8
	if (!cr6.eq) goto loc_826958C8;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x826958A4;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826958c4
	if (cr6.eq) goto loc_826958C4;
	// stw r25,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r27,4
	ctx.r3.s64 = r27.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x826958C0;
	sub_82720A50(ctx, base);
	// b 0x826958c8
	goto loc_826958C8;
loc_826958C4:
	// li r27,0
	r27.s64 = 0;
loc_826958C8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x826958fc
	if (!cr6.eq) goto loc_826958FC;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x826958D8;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826958f8
	if (cr6.eq) goto loc_826958F8;
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x826958F4;
	sub_82720A50(ctx, base);
	// b 0x826958fc
	goto loc_826958FC;
loc_826958F8:
	// li r28,0
	r28.s64 = 0;
loc_826958FC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82695930
	if (!cr6.eq) goto loc_82695930;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x8269590C;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8269592c
	if (cr6.eq) goto loc_8269592C;
	// stw r25,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82695928;
	sub_82720A50(ctx, base);
	// b 0x82695930
	goto loc_82695930;
loc_8269592C:
	// li r29,0
	r29.s64 = 0;
loc_82695930:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82695964
	if (!cr6.eq) goto loc_82695964;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82695940;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82695960
	if (cr6.eq) goto loc_82695960;
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x8269595C;
	sub_82720A50(ctx, base);
	// b 0x82695964
	goto loc_82695964;
loc_82695960:
	// li r30,0
	r30.s64 = 0;
loc_82695964:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82695998
	if (!cr6.eq) goto loc_82695998;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82695974;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82695994
	if (cr6.eq) goto loc_82695994;
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82695990;
	sub_82720A50(ctx, base);
	// b 0x82695998
	goto loc_82695998;
loc_82695994:
	// li r31,0
	r31.s64 = 0;
loc_82695998:
	// stw r26,68(r23)
	PPC_STORE_U32(r23.u32 + 68, r26.u32);
	// stw r27,72(r23)
	PPC_STORE_U32(r23.u32 + 72, r27.u32);
	// stw r28,76(r23)
	PPC_STORE_U32(r23.u32 + 76, r28.u32);
	// stw r29,80(r23)
	PPC_STORE_U32(r23.u32 + 80, r29.u32);
	// stw r30,84(r23)
	PPC_STORE_U32(r23.u32 + 84, r30.u32);
	// stw r31,88(r23)
	PPC_STORE_U32(r23.u32 + 88, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826959B8"))) PPC_WEAK_FUNC(sub_826959B8);
PPC_FUNC_IMPL(__imp__sub_826959B8) {
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
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// lwz r10,152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r9
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lbz r8,160(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 160);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82695a00
	if (cr6.eq) goto loc_82695A00;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,29360
	ctx.r4.s64 = r11.s64 + 29360;
	// bl 0x82694e50
	ctx.lr = 0x82695A00;
	sub_82694E50(ctx, base);
loc_82695A00:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82695a10
	if (!cr6.eq) goto loc_82695A10;
	// stw r30,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r30.u32);
loc_82695A10:
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,116(r30)
	PPC_STORE_U32(r30.u32 + 116, r11.u32);
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,224(r31)
	PPC_STORE_U32(r31.u32 + 224, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82695A40"))) PPC_WEAK_FUNC(sub_82695A40);
PPC_FUNC_IMPL(__imp__sub_82695A40) {
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
	ctx.lr = 0x82695A48;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,72(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82695aa0
	if (cr6.eq) goto loc_82695AA0;
	// addi r27,r5,100
	r27.s64 = ctx.r5.s64 + 100;
	// li r31,0
	r31.s64 = 0;
loc_82695A68:
	// lwz r11,68(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r29,r11,r31
	r29.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r10,r29,4
	ctx.r10.s64 = r29.s64 + 4;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82694a90
	ctx.lr = 0x82695A84;
	sub_82694A90(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c3048
	ctx.lr = 0x82695A8C;
	sub_821C3048(ctx, base);
	// lhz r9,72(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 72);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x82695a68
	if (cr6.lt) goto loc_82695A68;
loc_82695AA0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82695AA8"))) PPC_WEAK_FUNC(sub_82695AA8);
PPC_FUNC_IMPL(__imp__sub_82695AA8) {
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
	ctx.lr = 0x82695AB0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,20(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82695b08
	if (cr6.eq) goto loc_82695B08;
	// addi r27,r4,100
	r27.s64 = ctx.r4.s64 + 100;
	// li r31,0
	r31.s64 = 0;
loc_82695AD0:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r29,r11,r31
	r29.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r10,r29,4
	ctx.r10.s64 = r29.s64 + 4;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82694a90
	ctx.lr = 0x82695AEC;
	sub_82694A90(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c3048
	ctx.lr = 0x82695AF4;
	sub_821C3048(ctx, base);
	// lhz r9,20(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x82695ad0
	if (cr6.lt) goto loc_82695AD0;
loc_82695B08:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82695B10"))) PPC_WEAK_FUNC(sub_82695B10);
PPC_FUNC_IMPL(__imp__sub_82695B10) {
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
	ctx.lr = 0x82695B18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,28(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82695b70
	if (cr6.eq) goto loc_82695B70;
	// addi r27,r4,100
	r27.s64 = ctx.r4.s64 + 100;
	// li r31,0
	r31.s64 = 0;
loc_82695B38:
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r29,r11,r31
	r29.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r10,r29,4
	ctx.r10.s64 = r29.s64 + 4;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82694a90
	ctx.lr = 0x82695B54;
	sub_82694A90(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c3048
	ctx.lr = 0x82695B5C;
	sub_821C3048(ctx, base);
	// lhz r9,28(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 28);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x82695b38
	if (cr6.lt) goto loc_82695B38;
loc_82695B70:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82695B78"))) PPC_WEAK_FUNC(sub_82695B78);
PPC_FUNC_IMPL(__imp__sub_82695B78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82695B80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x826949b0
	ctx.lr = 0x82695B9C;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82695bc4
	if (cr6.eq) goto loc_82695BC4;
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82695a40
	ctx.lr = 0x82695BB8;
	sub_82695A40(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82695BC4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82695BD0"))) PPC_WEAK_FUNC(sub_82695BD0);
PPC_FUNC_IMPL(__imp__sub_82695BD0) {
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
	ctx.lr = 0x82695BD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82695350
	ctx.lr = 0x82695BE8;
	sub_82695350(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82695BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82695C18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82695C20"))) PPC_WEAK_FUNC(sub_82695C20);
PPC_FUNC_IMPL(__imp__sub_82695C20) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82695350
	ctx.lr = 0x82695C44;
	sub_82695350(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82695C5C;
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

__attribute__((alias("__imp__sub_82695C74"))) PPC_WEAK_FUNC(sub_82695C74);
PPC_FUNC_IMPL(__imp__sub_82695C74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82695C78"))) PPC_WEAK_FUNC(sub_82695C78);
PPC_FUNC_IMPL(__imp__sub_82695C78) {
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82695350
	ctx.lr = 0x82695C8C;
	sub_82695350(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82695C9C"))) PPC_WEAK_FUNC(sub_82695C9C);
PPC_FUNC_IMPL(__imp__sub_82695C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82695CA0"))) PPC_WEAK_FUNC(sub_82695CA0);
PPC_FUNC_IMPL(__imp__sub_82695CA0) {
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82695350
	ctx.lr = 0x82695CBC;
	sub_82695350(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r10,r31,20
	ctx.r10.s64 = r31.s64 + 20;
	// lbz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r7,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r7.u32);
	// stwx r3,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r3.u32);
	// bne cr6,0x82695ce8
	if (!cr6.eq) goto loc_82695CE8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82695aa8
	ctx.lr = 0x82695CE8;
	sub_82695AA8(ctx, base);
loc_82695CE8:
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

__attribute__((alias("__imp__sub_82695CFC"))) PPC_WEAK_FUNC(sub_82695CFC);
PPC_FUNC_IMPL(__imp__sub_82695CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82695D00"))) PPC_WEAK_FUNC(sub_82695D00);
PPC_FUNC_IMPL(__imp__sub_82695D00) {
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
	ctx.lr = 0x82695D08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r11,0
	r11.s64 = 0;
	// lwz r9,84(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82695de8
	if (!cr6.gt) goto loc_82695DE8;
	// addi r31,r30,20
	r31.s64 = r30.s64 + 20;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_82695D2C:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r4,r7
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, xer);
	// bne cr6,0x82695d3c
	if (!cr6.eq) goto loc_82695D3C;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_82695D3C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x82695d2c
	if (cr6.lt) goto loc_82695D2C;
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x82695de8
	if (cr6.eq) goto loc_82695DE8;
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x82695de8
	if (!cr6.lt) goto loc_82695DE8;
	// subf r29,r11,r9
	r29.s64 = ctx.r9.s64 - r11.s64;
loc_82695D64:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// lwz r3,-4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// bl 0x82695b10
	ctx.lr = 0x82695D7C;
	sub_82695B10(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r31
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// addi r7,r11,160
	ctx.r7.s64 = r11.s64 + 160;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// add r6,r10,r31
	ctx.r6.u64 = ctx.r10.u64 + r31.u64;
	// lwz r11,-4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -4);
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// bl 0x826949b0
	ctx.lr = 0x82695DB4;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82695dc8
	if (cr6.eq) goto loc_82695DC8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82695de0
	if (!cr6.eq) goto loc_82695DE0;
loc_82695DC8:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// lwz r3,-4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// bl 0x82695aa8
	ctx.lr = 0x82695DE0;
	sub_82695AA8(ctx, base);
loc_82695DE0:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x82695d64
	if (!cr0.eq) goto loc_82695D64;
loc_82695DE8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82695DF0"))) PPC_WEAK_FUNC(sub_82695DF0);
PPC_FUNC_IMPL(__imp__sub_82695DF0) {
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
	ctx.lr = 0x82695DF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82695e20
	if (!cr6.eq) goto loc_82695E20;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x82695E20;
	sub_82608A98(ctx, base);
loc_82695E20:
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lhz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82695e50
	if (!cr6.eq) goto loc_82695E50;
	// bl 0x821c9438
	ctx.lr = 0x82695E44;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a50
	ctx.lr = 0x82695E50;
	sub_82137A50(ctx, base);
loc_82695E50:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821c9550
	ctx.lr = 0x82695E58;
	sub_821C9550(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r29,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r29.u16);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r29.u16);
	// twllei r11,0
	// subf r31,r9,r3
	r31.s64 = ctx.r3.s64 - ctx.r9.s64;
	// beq cr6,0x82695eb0
	if (cr6.eq) goto loc_82695EB0;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_82695E8C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82695e8c
	if (!cr6.eq) goto loc_82695E8C;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x82695EB0;
	sub_821C9650(ctx, base);
loc_82695EB0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r27,r31,2,0,29
	r27.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,16
	ctx.r3.s64 = 16;
	// lwzx r28,r27,r11
	r28.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// bl 0x82130528
	ctx.lr = 0x82695EC4;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82695ef8
	if (cr6.eq) goto loc_82695EF8;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lhz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// bl 0x821c9650
	ctx.lr = 0x82695EE8;
	sub_821C9650(ctx, base);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r29,r31
	r29.u64 = r31.u64;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_82695EF8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r29,r27,r11
	PPC_STORE_U32(r27.u32 + r11.u32, r29.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x82695F08;
	sub_82130588(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r27,r10
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82695F18"))) PPC_WEAK_FUNC(sub_82695F18);
PPC_FUNC_IMPL(__imp__sub_82695F18) {
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
	ctx.lr = 0x82695F20;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82695f48
	if (!cr6.eq) goto loc_82695F48;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x82695F48;
	sub_82608A98(ctx, base);
loc_82695F48:
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lhz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82695f78
	if (!cr6.eq) goto loc_82695F78;
	// bl 0x821c9438
	ctx.lr = 0x82695F6C;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a50
	ctx.lr = 0x82695F78;
	sub_82137A50(ctx, base);
loc_82695F78:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9550
	ctx.lr = 0x82695F80;
	sub_821C9550(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// twllei r11,0
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// sth r29,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r29.u16);
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r29.u16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// subf r28,r9,r3
	r28.s64 = ctx.r3.s64 - ctx.r9.s64;
	// beq cr6,0x82695fd8
	if (cr6.eq) goto loc_82695FD8;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82695FB0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82695fb0
	if (!cr6.eq) goto loc_82695FB0;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x82695FD8;
	sub_821C9650(ctx, base);
loc_82695FD8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r27,r28,2,0,29
	r27.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,16
	ctx.r3.s64 = 16;
	// lwzx r28,r27,r11
	r28.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// bl 0x82130528
	ctx.lr = 0x82695FEC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82696020
	if (cr6.eq) goto loc_82696020;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lhz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// bl 0x821c9650
	ctx.lr = 0x82696010;
	sub_821C9650(ctx, base);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r29,r31
	r29.u64 = r31.u64;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_82696020:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r29,r27,r11
	PPC_STORE_U32(r27.u32 + r11.u32, r29.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x82696030;
	sub_82130588(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r27,r10
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82696040"))) PPC_WEAK_FUNC(sub_82696040);
PPC_FUNC_IMPL(__imp__sub_82696040) {
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
	ctx.lr = 0x82696048;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82696110
	if (cr6.eq) goto loc_82696110;
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r27,r11,3998
	r27.s64 = r11.s64 + 3998;
	// beq cr6,0x8269607c
	if (cr6.eq) goto loc_8269607C;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x82696080
	goto loc_82696080;
loc_8269607C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82696080:
	// bl 0x821c9550
	ctx.lr = 0x82696084;
	sub_821C9550(ctx, base);
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// divwu r9,r3,r11
	ctx.r9.u32 = ctx.r3.u32 / r11.u32;
	// twllei r11,0
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r6,r11,r10
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82696110
	if (cr6.eq) goto loc_82696110;
loc_826960B0:
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826960c8
	if (cr6.eq) goto loc_826960C8;
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x826960cc
	goto loc_826960CC;
loc_826960C8:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_826960CC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821372b8
	ctx.lr = 0x826960D4;
	sub_821372B8(ctx, base);
loc_826960D4:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x826960f8
	if (cr6.eq) goto loc_826960F8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826960d4
	if (cr6.eq) goto loc_826960D4;
loc_826960F8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8269611c
	if (cr6.eq) goto loc_8269611C;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r30,r29,12
	r30.s64 = r29.s64 + 12;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826960b0
	if (!cr6.eq) goto loc_826960B0;
loc_82696110:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269611C:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// beq cr6,0x82696140
	if (cr6.eq) goto loc_82696140;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82696138;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82696140;
	sub_82130588(ctx, base);
loc_82696140:
	// lhz r11,6(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,6(r26)
	PPC_STORE_U16(r26.u32 + 6, ctx.r10.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8269615C"))) PPC_WEAK_FUNC(sub_8269615C);
PPC_FUNC_IMPL(__imp__sub_8269615C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82696160"))) PPC_WEAK_FUNC(sub_82696160);
PPC_FUNC_IMPL(__imp__sub_82696160) {
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
	ctx.lr = 0x82696168;
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82696190
	if (!cr6.eq) goto loc_82696190;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x82696190;
	sub_82608A98(ctx, base);
loc_82696190:
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
	// bne cr6,0x826961c0
	if (!cr6.eq) goto loc_826961C0;
	// bl 0x821c9438
	ctx.lr = 0x826961B4;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82694b70
	ctx.lr = 0x826961C0;
	sub_82694B70(ctx, base);
loc_826961C0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9550
	ctx.lr = 0x826961C8;
	sub_821C9550(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// divwu r9,r3,r10
	ctx.r9.u32 = ctx.r3.u32 / ctx.r10.u32;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r11,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r11.u16);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r11.u16);
	// twllei r10,0
	// subf r30,r8,r3
	r30.s64 = ctx.r3.s64 - ctx.r8.s64;
	// beq cr6,0x82696220
	if (cr6.eq) goto loc_82696220;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_826961FC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826961fc
	if (!cr6.eq) goto loc_826961FC;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x82696220;
	sub_821C9650(ctx, base);
loc_82696220:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r30,r30,2,0,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,10
	ctx.r3.s64 = r31.s64 + 10;
	// lwzx r6,r30,r11
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82695640
	ctx.lr = 0x8269623C;
	sub_82695640(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r3,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, ctx.r3.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x8269624C;
	sub_82130588(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r9
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8269625C"))) PPC_WEAK_FUNC(sub_8269625C);
PPC_FUNC_IMPL(__imp__sub_8269625C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82696260"))) PPC_WEAK_FUNC(sub_82696260);
PPC_FUNC_IMPL(__imp__sub_82696260) {
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
	ctx.lr = 0x82696268;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// li r3,164
	ctx.r3.s64 = 164;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// bl 0x82130528
	ctx.lr = 0x82696294;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r30,r11,-4944
	r30.s64 = r11.s64 + -4944;
	// beq cr6,0x826962bc
	if (cr6.eq) goto loc_826962BC;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x826962B8;
	sub_82720A50(ctx, base);
	// b 0x826962c0
	goto loc_826962C0;
loc_826962BC:
	// li r31,0
	r31.s64 = 0;
loc_826962C0:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x826962C8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826962ec
	if (cr6.eq) goto loc_826962EC;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x826962E4;
	sub_82720A50(ctx, base);
	// mr r23,r29
	r23.u64 = r29.u64;
	// b 0x826962f0
	goto loc_826962F0;
loc_826962EC:
	// li r23,0
	r23.s64 = 0;
loc_826962F0:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x826962F8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8269631c
	if (cr6.eq) goto loc_8269631C;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82696314;
	sub_82720A50(ctx, base);
	// mr r25,r29
	r25.u64 = r29.u64;
	// b 0x82696320
	goto loc_82696320;
loc_8269631C:
	// li r25,0
	r25.s64 = 0;
loc_82696320:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82696328;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8269634c
	if (cr6.eq) goto loc_8269634C;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82696344;
	sub_82720A50(ctx, base);
	// mr r27,r29
	r27.u64 = r29.u64;
	// b 0x82696350
	goto loc_82696350;
loc_8269634C:
	// li r27,0
	r27.s64 = 0;
loc_82696350:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82696358;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8269637c
	if (cr6.eq) goto loc_8269637C;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82696374;
	sub_82720A50(ctx, base);
	// mr r28,r29
	r28.u64 = r29.u64;
	// b 0x82696380
	goto loc_82696380;
loc_8269637C:
	// li r28,0
	r28.s64 = 0;
loc_82696380:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82696388;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826963ac
	if (cr6.eq) goto loc_826963AC;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x826963A4;
	sub_82720A50(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// b 0x826963b0
	goto loc_826963B0;
loc_826963AC:
	// li r5,0
	ctx.r5.s64 = 0;
loc_826963B0:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82695808
	ctx.lr = 0x826963D0;
	sub_82695808(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_826963D8"))) PPC_WEAK_FUNC(sub_826963D8);
PPC_FUNC_IMPL(__imp__sub_826963D8) {
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
	ctx.lr = 0x826963E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826963FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r3,92
	ctx.r4.s64 = ctx.r3.s64 + 92;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// bl 0x82695350
	ctx.lr = 0x82696410;
	sub_82695350(ctx, base);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8269642C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r3,92
	r30.s64 = ctx.r3.s64 + 92;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r10,r10,32116
	ctx.r10.s64 = ctx.r10.s64 + 32116;
loc_8269643C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82696460
	if (cr6.eq) goto loc_82696460;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8269643c
	if (cr6.eq) goto loc_8269643C;
loc_82696460:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826964a8
	if (!cr6.eq) goto loc_826964A8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269647C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r11,160
	ctx.r4.s64 = r11.s64 + 160;
	// bl 0x823db670
	ctx.lr = 0x82696494;
	sub_823DB670(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826964A8:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r10,r10,-2176
	ctx.r10.s64 = ctx.r10.s64 + -2176;
loc_826964B4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826964d8
	if (cr6.eq) goto loc_826964D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826964b4
	if (cr6.eq) goto loc_826964B4;
loc_826964D8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82696510
	if (!cr6.eq) goto loc_82696510;
	// lwz r5,116(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 116);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// stw r5,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r5.u32);
	// bl 0x823dc018
	ctx.lr = 0x826964FC;
	sub_823DC018(ctx, base);
	// li r10,3
	ctx.r10.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82696510:
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r29,128
	ctx.r3.s64 = r29.s64 + 128;
	// bl 0x826949b0
	ctx.lr = 0x82696520;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269655c
	if (cr6.eq) goto loc_8269655C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269655c
	if (cr6.eq) goto loc_8269655C;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r11,160
	ctx.r4.s64 = r11.s64 + 160;
	// bl 0x823db670
	ctx.lr = 0x82696548;
	sub_823DB670(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8269655C:
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82695038
	ctx.lr = 0x8269656C;
	sub_82695038(ctx, base);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82696578"))) PPC_WEAK_FUNC(sub_82696578);
PPC_FUNC_IMPL(__imp__sub_82696578) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82696580;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,40
	ctx.r3.s64 = 40;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x82130528
	ctx.lr = 0x8269659C;
	sub_82130528(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lhz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// ori r23,r9,65535
	r23.u64 = ctx.r9.u64 | 65535;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82696794
	if (!cr6.lt) goto loc_82696794;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r21,r11,32108
	r21.s64 = r11.s64 + 32108;
	// addi r22,r10,-4944
	r22.s64 = ctx.r10.s64 + -4944;
	// addi r20,r9,3998
	r20.s64 = ctx.r9.s64 + 3998;
	// addi r19,r8,10116
	r19.s64 = ctx.r8.s64 + 10116;
loc_826965D8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826965fc
	if (cr6.eq) goto loc_826965FC;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82696600
	goto loc_82696600;
loc_826965FC:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_82696600:
	// mr r10,r19
	ctx.r10.u64 = r19.u64;
loc_82696604:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82696628
	if (cr6.eq) goto loc_82696628;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82696604
	if (cr6.eq) goto loc_82696604;
loc_82696628:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r3,164
	ctx.r3.s64 = 164;
	// bne cr6,0x82696704
	if (!cr6.eq) goto loc_82696704;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// add r10,r11,r23
	ctx.r10.u64 = r11.u64 + r23.u64;
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r28,r11,2,14,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FFFC;
	// mr r26,r11
	r26.u64 = r11.u64;
	// lwzx r27,r28,r25
	r27.u64 = PPC_LOAD_U32(r28.u32 + r25.u32);
	// bl 0x82130528
	ctx.lr = 0x82696650;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826966b0
	if (cr6.eq) goto loc_826966B0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82696698
	if (cr6.eq) goto loc_82696698;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r22,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r22.u32);
	// bl 0x82720a50
	ctx.lr = 0x82696690;
	sub_82720A50(ctx, base);
	// mr r30,r31
	r30.u64 = r31.u64;
	// b 0x826966b4
	goto loc_826966B4;
loc_82696698:
	// stw r22,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r22.u32);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x826966A8;
	sub_82720A50(ctx, base);
	// mr r30,r31
	r30.u64 = r31.u64;
	// b 0x826966b4
	goto loc_826966B4;
loc_826966B0:
	// li r30,0
	r30.s64 = 0;
loc_826966B4:
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82130528
	ctx.lr = 0x826966BC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826966e4
	if (cr6.eq) goto loc_826966E4;
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r18,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r18.u32);
	// stw r21,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r21.u32);
	// bl 0x82720a08
	ctx.lr = 0x826966E0;
	sub_82720A08(ctx, base);
	// b 0x826966e8
	goto loc_826966E8;
loc_826966E4:
	// li r31,0
	r31.s64 = 0;
loc_826966E8:
	// stwx r31,r28,r25
	PPC_STORE_U32(r28.u32 + r25.u32, r31.u32);
	// addi r10,r26,1
	ctx.r10.s64 = r26.s64 + 1;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// clrlwi r30,r10,16
	r30.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// b 0x82696784
	goto loc_82696784;
loc_82696704:
	// bl 0x82130528
	ctx.lr = 0x82696708;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82696760
	if (cr6.eq) goto loc_82696760;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82696748
	if (cr6.eq) goto loc_82696748;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r22,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r22.u32);
	// bl 0x82720a50
	ctx.lr = 0x82696740;
	sub_82720A50(ctx, base);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// b 0x82696764
	goto loc_82696764;
loc_82696748:
	// stw r22,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r22.u32);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82696758;
	sub_82720A50(ctx, base);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// b 0x82696764
	goto loc_82696764;
loc_82696760:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82696764:
	// rlwinm r10,r30,2,14,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r9,r10,r25
	PPC_STORE_U32(ctx.r10.u32 + r25.u32, ctx.r9.u32);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_82696784:
	// lhz r11,4(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x826965d8
	if (cr6.lt) goto loc_826965D8;
loc_82696794:
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// add r10,r11,r23
	ctx.r10.u64 = r11.u64 + r23.u64;
	// rlwinm r8,r10,2,14,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3FFFC;
	// lwzx r31,r8,r25
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + r25.u32);
	// bl 0x82130588
	ctx.lr = 0x826967AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_826967B8"))) PPC_WEAK_FUNC(sub_826967B8);
PPC_FUNC_IMPL(__imp__sub_826967B8) {
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
	ctx.lr = 0x826967C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r10,r11,32136
	ctx.r10.s64 = r11.s64 + 32136;
	// lhz r30,72(r29)
	r30.u64 = PPC_LOAD_U16(r29.u32 + 72);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82696814
	if (!cr6.gt) goto loc_82696814;
	// li r31,0
	r31.s64 = 0;
loc_826967E4:
	// lwz r11,68(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82696808
	if (cr6.eq) goto loc_82696808;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82696808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82696808:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826967e4
	if (!cr0.eq) goto loc_826967E4;
loc_82696814:
	// lhz r11,74(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82696828
	if (cr6.eq) goto loc_82696828;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x82130588
	ctx.lr = 0x82696828;
	sub_82130588(ctx, base);
loc_82696828:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82696830"))) PPC_WEAK_FUNC(sub_82696830);
PPC_FUNC_IMPL(__imp__sub_82696830) {
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
	ctx.lr = 0x82696838;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// stw r28,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r28.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r30,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r30.u32);
	// lhz r11,156(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 156);
	// lwz r10,152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stw r27,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r27.u32);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r11,r31,152
	r11.s64 = r31.s64 + 152;
	// sth r8,156(r31)
	PPC_STORE_U16(r31.u32 + 156, ctx.r8.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// bl 0x826959b8
	ctx.lr = 0x8269687C;
	sub_826959B8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r4,r1,180
	ctx.r4.s64 = ctx.r1.s64 + 180;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x82695df0
	ctx.lr = 0x82696894;
	sub_82695DF0(ctx, base);
	// addi r10,r29,160
	ctx.r10.s64 = r29.s64 + 160;
	// mr r11,r30
	r11.u64 = r30.u64;
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - r30.s64;
loc_826968A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x826968a0
	if (!cr6.eq) goto loc_826968A0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826968f8
	if (cr6.eq) goto loc_826968F8;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826968d8
	if (cr6.eq) goto loc_826968D8;
	// addi r5,r1,172
	ctx.r5.s64 = ctx.r1.s64 + 172;
	// addi r4,r1,188
	ctx.r4.s64 = ctx.r1.s64 + 188;
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// bl 0x82695df0
	ctx.lr = 0x826968D8;
	sub_82695DF0(ctx, base);
loc_826968D8:
	// addi r10,r28,52
	ctx.r10.s64 = r28.s64 + 52;
	// mr r11,r27
	r11.u64 = r27.u64;
	// subf r10,r27,r10
	ctx.r10.s64 = ctx.r10.s64 - r27.s64;
loc_826968E4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x826968e4
	if (!cr6.eq) goto loc_826968E4;
loc_826968F8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82696900"))) PPC_WEAK_FUNC(sub_82696900);
PPC_FUNC_IMPL(__imp__sub_82696900) {
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
	ctx.lr = 0x82696908;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r29,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82696a38
	if (cr6.eq) goto loc_82696A38;
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// bl 0x826949b0
	ctx.lr = 0x82696930;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82696964
	if (cr6.eq) goto loc_82696964;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82696958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82696964:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826969fc
	if (cr6.eq) goto loc_826969FC;
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x826949b0
	ctx.lr = 0x8269697C;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826969a0
	if (cr6.eq) goto loc_826969A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826969a0
	if (cr6.eq) goto loc_826969A0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82695d00
	ctx.lr = 0x826969A0;
	sub_82695D00(ctx, base);
loc_826969A0:
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826969BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826969fc
	if (cr6.eq) goto loc_826969FC;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826969f0
	if (cr6.eq) goto loc_826969F0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826969F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826969F0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826969FC:
	// addi r4,r31,160
	ctx.r4.s64 = r31.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82695300
	ctx.lr = 0x82696A08;
	sub_82695300(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82696a38
	if (cr6.eq) goto loc_82696A38;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82696A2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x82696a3c
	if (!cr6.eq) goto loc_82696A3C;
loc_82696A38:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82696A3C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82696A44"))) PPC_WEAK_FUNC(sub_82696A44);
PPC_FUNC_IMPL(__imp__sub_82696A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82696A48"))) PPC_WEAK_FUNC(sub_82696A48);
PPC_FUNC_IMPL(__imp__sub_82696A48) {
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
	ctx.lr = 0x82696A50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r11,124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x82696a7c
	if (!cr6.eq) goto loc_82696A7C;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82696a88
	if (cr6.eq) goto loc_82696A88;
loc_82696A7C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82695d00
	ctx.lr = 0x82696A88;
	sub_82695D00(ctx, base);
loc_82696A88:
	// lwz r29,124(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bne cr6,0x82696aa0
	if (!cr6.eq) goto loc_82696AA0;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82696ab4
	if (cr6.eq) goto loc_82696AB4;
loc_82696AA0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82696ab4
	if (cr6.eq) goto loc_82696AB4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82695b10
	ctx.lr = 0x82696AB4;
	sub_82695B10(ctx, base);
loc_82696AB4:
	// stw r31,124(r30)
	PPC_STORE_U32(r30.u32 + 124, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82696ae0
	if (cr6.eq) goto loc_82696AE0;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bne cr6,0x82696ad4
	if (!cr6.eq) goto loc_82696AD4;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82696ae0
	if (cr6.eq) goto loc_82696AE0;
loc_82696AD4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82695aa8
	ctx.lr = 0x82696AE0;
	sub_82695AA8(ctx, base);
loc_82696AE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82696AE8"))) PPC_WEAK_FUNC(sub_82696AE8);
PPC_FUNC_IMPL(__imp__sub_82696AE8) {
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
	ctx.lr = 0x82696AF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r29,128
	r31.s64 = r29.s64 + 128;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x82237920
	ctx.lr = 0x82696B14;
	sub_82237920(ctx, base);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82696b70
	if (cr6.eq) goto loc_82696B70;
loc_82696B20:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82696040
	ctx.lr = 0x82696B28;
	sub_82696040(ctx, base);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82696b5c
	if (!cr6.gt) goto loc_82696B5C;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_82696B40:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82696b5c
	if (!cr6.eq) goto loc_82696B5C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x82696b40
	if (cr6.lt) goto loc_82696B40;
loc_82696B5C:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82696b20
	if (!cr6.eq) goto loc_82696B20;
loc_82696B70:
	// lhz r11,156(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 156);
	// stw r30,124(r29)
	PPC_STORE_U32(r29.u32 + 124, r30.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r30,224(r29)
	PPC_STORE_U32(r29.u32 + 224, r30.u32);
	// ble cr6,0x82696bbc
	if (!cr6.gt) goto loc_82696BBC;
	// mr r31,r30
	r31.u64 = r30.u64;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_82696B8C:
	// lwz r11,152(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 152);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82696bb0
	if (cr6.eq) goto loc_82696BB0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82696BB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82696BB0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82696b8c
	if (!cr0.eq) goto loc_82696B8C;
loc_82696BBC:
	// lhz r11,156(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 156);
	// addi r7,r29,152
	ctx.r7.s64 = r29.s64 + 152;
	// lwz r9,152(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 152);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82696bf4
	if (cr6.eq) goto loc_82696BF4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82696BE0:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82696be0
	if (!cr6.eq) goto loc_82696BE0;
loc_82696BF4:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r7)
	PPC_STORE_U16(ctx.r7.u32 + 4, ctx.r8.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82696C10"))) PPC_WEAK_FUNC(sub_82696C10);
PPC_FUNC_IMPL(__imp__sub_82696C10) {
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
	ctx.lr = 0x82696C18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,32140
	ctx.r4.s64 = r11.s64 + 32140;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82695350
	ctx.lr = 0x82696C30;
	sub_82695350(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r10,r31,20
	ctx.r10.s64 = r31.s64 + 20;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r8.u32);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,32(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82696C5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82696C78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,116(r31)
	PPC_STORE_U8(r31.u32 + 116, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82696C88"))) PPC_WEAK_FUNC(sub_82696C88);
PPC_FUNC_IMPL(__imp__sub_82696C88) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82696C90;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// lwz r11,84(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82696d10
	if (!cr6.gt) goto loc_82696D10;
	// addic. r30,r11,-1
	xer.ca = r11.u32 > 0;
	r30.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x82696db4
	if (cr0.lt) goto loc_82696DB4;
	// addi r11,r30,5
	r11.s64 = r30.s64 + 5;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r28
	r31.u64 = r11.u64 + r28.u64;
loc_82696CC4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82696CE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82696d04
	if (!cr6.eq) goto loc_82696D04;
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// bge 0x82696cc4
	if (!cr0.lt) goto loc_82696CC4;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_82696D04:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_82696D10:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// bl 0x82237920
	ctx.lr = 0x82696D2C;
	sub_82237920(ctx, base);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82696db4
	if (cr6.eq) goto loc_82696DB4;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82696D40:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82696D5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82696d6c
	if (cr6.eq) goto loc_82696D6C;
	// li r26,1
	r26.s64 = 1;
loc_82696D6C:
	// lwz r30,12(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82696d40
	if (!cr6.eq) goto loc_82696D40;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_82696D84:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82696dac
	if (!cr6.lt) goto loc_82696DAC;
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
	// beq cr6,0x82696d84
	if (cr6.eq) goto loc_82696D84;
	// b 0x82696d40
	goto loc_82696D40;
loc_82696DAC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82696d40
	if (!cr6.eq) goto loc_82696D40;
loc_82696DB4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82696DC0"))) PPC_WEAK_FUNC(sub_82696DC0);
PPC_FUNC_IMPL(__imp__sub_82696DC0) {
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
	// std r5,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r5.u64);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// std r6,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r6.u64);
	// addi r3,r3,100
	ctx.r3.s64 = ctx.r3.s64 + 100;
	// std r7,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r7.u64);
	// bl 0x82696160
	ctx.lr = 0x82696DEC;
	sub_82696160(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82696DFC"))) PPC_WEAK_FUNC(sub_82696DFC);
PPC_FUNC_IMPL(__imp__sub_82696DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82696E00"))) PPC_WEAK_FUNC(sub_82696E00);
PPC_FUNC_IMPL(__imp__sub_82696E00) {
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
	ctx.lr = 0x82696E08;
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
	// beq cr6,0x82696e6c
	if (cr6.eq) goto loc_82696E6C;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_82696E28:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82696e58
	if (cr6.eq) goto loc_82696E58;
loc_82696E38:
	// mr r26,r31
	r26.u64 = r31.u64;
	// lwz r31,28(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82696E48;
	sub_82130588(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x82696E50;
	sub_82130588(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82696e38
	if (!cr6.eq) goto loc_82696E38;
loc_82696E58:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x82696e28
	if (cr6.lt) goto loc_82696E28;
loc_82696E6C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82696E74;
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

__attribute__((alias("__imp__sub_82696E88"))) PPC_WEAK_FUNC(sub_82696E88);
PPC_FUNC_IMPL(__imp__sub_82696E88) {
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
	ctx.lr = 0x82696E90;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r30,r28
	r30.u64 = r28.u64;
	// lhz r29,4(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r26,r29
	r26.u64 = r29.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82696ec0
	if (cr6.eq) goto loc_82696EC0;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82696EB8;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x82696ec4
	goto loc_82696EC4;
loc_82696EC0:
	// mr r27,r28
	r27.u64 = r28.u64;
loc_82696EC4:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82696efc
	if (!cr6.gt) goto loc_82696EFC;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82696ED4:
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r30,2,14,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r8,r30,16
	ctx.r8.u64 = r30.u32 & 0xFFFF;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r6,r8,1
	ctx.r6.s64 = ctx.r8.s64 + 1;
	// lwzx r5,r10,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// clrlwi r30,r6,16
	r30.u64 = ctx.r6.u32 & 0xFFFF;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stwx r5,r9,r27
	PPC_STORE_U32(ctx.r9.u32 + r27.u32, ctx.r5.u32);
	// bne 0x82696ed4
	if (!cr0.eq) goto loc_82696ED4;
loc_82696EFC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82696F04;
	sub_82130588(ctx, base);
	// sth r26,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r26.u16);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// sth r28,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r28.u16);
	// beq cr6,0x82696f24
	if (cr6.eq) goto loc_82696F24;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82696F20;
	sub_82130528(ctx, base);
	// b 0x82696f28
	goto loc_82696F28;
loc_82696F24:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82696F28:
	// rlwinm r11,r26,2,14,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0x3FFFC;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r26,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r26.u16);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82696f5c
	if (cr6.eq) goto loc_82696F5C;
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - r11.s64;
loc_82696F48:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82696f48
	if (!cr6.eq) goto loc_82696F48;
loc_82696F5C:
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// ble cr6,0x82696fac
	if (!cr6.gt) goto loc_82696FAC;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82696F80:
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// bne 0x82696f80
	if (!cr0.eq) goto loc_82696F80;
loc_82696FAC:
	// clrlwi r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82696fc0
	if (cr6.eq) goto loc_82696FC0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x82696FC0;
	sub_82130588(ctx, base);
loc_82696FC0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82696FC8"))) PPC_WEAK_FUNC(sub_82696FC8);
PPC_FUNC_IMPL(__imp__sub_82696FC8) {
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
	// bl 0x826967b8
	ctx.lr = 0x82696FE8;
	sub_826967B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82697000
	if (cr6.eq) goto loc_82697000;
	// bl 0x82130588
	ctx.lr = 0x82696FFC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82697000:
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

__attribute__((alias("__imp__sub_82697018"))) PPC_WEAK_FUNC(sub_82697018);
PPC_FUNC_IMPL(__imp__sub_82697018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82697020;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// addi r10,r11,32152
	ctx.r10.s64 = r11.s64 + 32152;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r24,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r24.u32);
	// li r9,30
	ctx.r9.s64 = 30;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// li r31,0
	r31.s64 = 0;
	// li r4,30
	ctx.r4.s64 = 30;
	// sth r9,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, ctx.r9.u16);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r30,r31
	r30.u64 = r31.u64;
	// bl 0x821b5998
	ctx.lr = 0x8269705C;
	sub_821B5998(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// mr r27,r31
	r27.u64 = r31.u64;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82697070:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82697070
	if (!cr6.eq) goto loc_82697070;
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r23,r11,0
	r23.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x826971e8
	if (!cr6.gt) goto loc_826971E8;
	// lis r25,-32255
	r25.s64 = -2113863680;
loc_82697098:
	// lbzx r8,r27,r28
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// extsb r11,r8
	r11.s64 = ctx.r8.s8;
	// addi r11,r11,-39
	r11.s64 = r11.s64 + -39;
	// stbx r8,r10,r9
	PPC_STORE_U8(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u8);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x826971d8
	if (cr6.gt) goto loc_826971D8;
	// lis r12,-32151
	r12.s64 = -2107047936;
	// addi r12,r12,28876
	r12.s64 = r12.s64 + 28876;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826970EC;
	case 1:
		goto loc_826970EC;
	case 2:
		goto loc_826970EC;
	case 3:
		goto loc_826971D8;
	case 4:
		goto loc_826971D8;
	case 5:
		goto loc_826970EC;
	case 6:
		goto loc_826971D8;
	case 7:
		goto loc_826970EC;
	default:
		__builtin_unreachable();
	}
	// lwz r19,28908(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28908);
	// lwz r19,28908(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28908);
	// lwz r19,28908(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28908);
	// lwz r19,29144(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 29144);
	// lwz r19,29144(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 29144);
	// lwz r19,28908(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28908);
	// lwz r19,29144(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 29144);
	// lwz r19,28908(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28908);
loc_826970EC:
	// lhz r8,10116(r25)
	ctx.r8.u64 = PPC_LOAD_U16(r25.u32 + 10116);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lbzx r7,r27,r28
	ctx.r7.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// stbx r31,r10,r9
	PPC_STORE_U8(ctx.r10.u32 + ctx.r9.u32, r31.u8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// sth r31,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, r31.u16);
	// sth r8,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r8.u16);
	// stb r7,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r7.u8);
	// sth r31,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, r31.u16);
loc_82697114:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82697114
	if (!cr6.eq) goto loc_82697114;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x8269713C;
	sub_821C9650(ctx, base);
	// rlwinm r11,r30,3,13,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0x7FFF8;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// sth r31,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r31.u16);
	// clrlwi r30,r10,16
	r30.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lhz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 108);
	// bl 0x821c9650
	ctx.lr = 0x82697160;
	sub_821C9650(ctx, base);
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x82130588
	ctx.lr = 0x82697168;
	sub_82130588(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// sth r31,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r31.u16);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// sth r31,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r31.u16);
loc_8269717C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8269717c
	if (!cr6.eq) goto loc_8269717C;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x826971A4;
	sub_821C9650(ctx, base);
	// rlwinm r11,r30,3,13,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0x7FFF8;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// sth r31,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r31.u16);
	// clrlwi r30,r10,16
	r30.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lhz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 92);
	// bl 0x821c9650
	ctx.lr = 0x826971C8;
	sub_821C9650(ctx, base);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x82130588
	ctx.lr = 0x826971D0;
	sub_82130588(ctx, base);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// b 0x826971dc
	goto loc_826971DC;
loc_826971D8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_826971DC:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpw cr6,r27,r23
	cr6.compare<int32_t>(r27.s32, r23.s32, xer);
	// blt cr6,0x82697098
	if (cr6.lt) goto loc_82697098;
loc_826971E8:
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// sth r31,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r31.u16);
	// sth r31,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, r31.u16);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// stbx r31,r10,r8
	PPC_STORE_U8(ctx.r10.u32 + ctx.r8.u32, r31.u8);
loc_82697204:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82697204
	if (!cr6.eq) goto loc_82697204;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x8269722C;
	sub_821C9650(ctx, base);
	// rlwinm r11,r30,3,13,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0x7FFF8;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// sth r31,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r31.u16);
	// lhz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// sth r10,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r10.u16);
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x821c9650
	ctx.lr = 0x82697250;
	sub_821C9650(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82130588
	ctx.lr = 0x82697258;
	sub_82130588(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82696578
	ctx.lr = 0x82697270;
	sub_82696578(ctx, base);
	// stw r3,8(r26)
	PPC_STORE_U32(r26.u32 + 8, ctx.r3.u32);
	// mr r30,r29
	r30.u64 = r29.u64;
	// li r31,30
	r31.s64 = 30;
loc_8269727C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82697284;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x8269727c
	if (!cr0.eq) goto loc_8269727C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82697298;
	sub_82130588(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826972A4"))) PPC_WEAK_FUNC(sub_826972A4);
PPC_FUNC_IMPL(__imp__sub_826972A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826972A8"))) PPC_WEAK_FUNC(sub_826972A8);
PPC_FUNC_IMPL(__imp__sub_826972A8) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,32152
	ctx.r10.s64 = r11.s64 + 32152;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826972f0
	if (cr6.eq) goto loc_826972F0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826972F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826972F0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// addi r9,r11,-5056
	ctx.r9.s64 = r11.s64 + -5056;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82697314
	if (cr6.eq) goto loc_82697314;
	// bl 0x82130588
	ctx.lr = 0x82697310;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82697314:
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

__attribute__((alias("__imp__sub_8269732C"))) PPC_WEAK_FUNC(sub_8269732C);
PPC_FUNC_IMPL(__imp__sub_8269732C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82697330"))) PPC_WEAK_FUNC(sub_82697330);
PPC_FUNC_IMPL(__imp__sub_82697330) {
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
	ctx.lr = 0x82697338;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82697504
	if (cr6.eq) goto loc_82697504;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r29,r10,-13576
	r29.s64 = ctx.r10.s64 + -13576;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82697364:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82697388
	if (cr6.eq) goto loc_82697388;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697364
	if (cr6.eq) goto loc_82697364;
loc_82697388:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826973c8
	if (!cr6.eq) goto loc_826973C8;
loc_82697390:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697398;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82697540
	if (cr6.eq) goto loc_82697540;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x826973BC;
	sub_82720A50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_826973C8:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r29,r10,-13568
	r29.s64 = ctx.r10.s64 + -13568;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_826973D8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826973fc
	if (cr6.eq) goto loc_826973FC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826973d8
	if (cr6.eq) goto loc_826973D8;
loc_826973FC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697390
	if (cr6.eq) goto loc_82697390;
	// cmpwi cr6,r8,39
	cr6.compare<int32_t>(ctx.r8.s32, 39, xer);
	// bne cr6,0x82697494
	if (!cr6.eq) goto loc_82697494;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r30
	r11.u64 = r30.u64;
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - r30.s64;
loc_82697418:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82697418
	if (!cr6.eq) goto loc_82697418;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_82697434:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82697434
	if (!cr6.eq) goto loc_82697434;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// li r3,164
	ctx.r3.s64 = 164;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stb r9,-1(r8)
	PPC_STORE_U8(ctx.r8.u32 + -1, ctx.r9.u8);
	// bl 0x82130528
	ctx.lr = 0x82697464;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82697540
	if (cr6.eq) goto loc_82697540;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,81
	ctx.r4.s64 = ctx.r1.s64 + 81;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x82697488;
	sub_82720A50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_82697494:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82694710
	ctx.lr = 0x8269749C;
	sub_82694710(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826974e0
	if (cr6.eq) goto loc_826974E0;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x826974B0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82697540
	if (cr6.eq) goto loc_82697540;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x826974D4;
	sub_82720A50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_826974E0:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x826974E8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82697540
	if (cr6.eq) goto loc_82697540;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82697018
	ctx.lr = 0x826974FC;
	sub_82697018(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_82697504:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x8269750C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82697540
	if (cr6.eq) goto loc_82697540;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-4944
	ctx.r9.s64 = r11.s64 + -4944;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82697534;
	sub_82720A50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_82697540:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8269754C"))) PPC_WEAK_FUNC(sub_8269754C);
PPC_FUNC_IMPL(__imp__sub_8269754C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82697550"))) PPC_WEAK_FUNC(sub_82697550);
PPC_FUNC_IMPL(__imp__sub_82697550) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82697558;
	// stwu r1,-2384(r1)
	ea = -2384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r10,r11,-5044
	ctx.r10.s64 = r11.s64 + -5044;
	// li r26,0
	r26.s64 = 0;
	// li r5,127
	ctx.r5.s64 = 127;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, r26.u8);
	// addi r3,r1,225
	ctx.r3.s64 = ctx.r1.s64 + 225;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// bl 0x823d9890
	ctx.lr = 0x82697590;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// stb r26,1376(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1376, r26.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1377
	ctx.r3.s64 = ctx.r1.s64 + 1377;
	// bl 0x823d9890
	ctx.lr = 0x826975A4;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,608(r1)
	PPC_STORE_U8(ctx.r1.u32 + 608, r26.u8);
	// addi r3,r1,609
	ctx.r3.s64 = ctx.r1.s64 + 609;
	// bl 0x823d9890
	ctx.lr = 0x826975B8;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,736(r1)
	PPC_STORE_U8(ctx.r1.u32 + 736, r26.u8);
	// addi r3,r1,737
	ctx.r3.s64 = ctx.r1.s64 + 737;
	// bl 0x823d9890
	ctx.lr = 0x826975CC;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,992(r1)
	PPC_STORE_U8(ctx.r1.u32 + 992, r26.u8);
	// addi r3,r1,993
	ctx.r3.s64 = ctx.r1.s64 + 993;
	// bl 0x823d9890
	ctx.lr = 0x826975E0;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,352(r1)
	PPC_STORE_U8(ctx.r1.u32 + 352, r26.u8);
	// addi r3,r1,353
	ctx.r3.s64 = ctx.r1.s64 + 353;
	// bl 0x823d9890
	ctx.lr = 0x826975F4;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,480(r1)
	PPC_STORE_U8(ctx.r1.u32 + 480, r26.u8);
	// addi r3,r1,481
	ctx.r3.s64 = ctx.r1.s64 + 481;
	// bl 0x823d9890
	ctx.lr = 0x82697608;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,1504(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1504, r26.u8);
	// addi r3,r1,1505
	ctx.r3.s64 = ctx.r1.s64 + 1505;
	// bl 0x823d9890
	ctx.lr = 0x8269761C;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,1120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1120, r26.u8);
	// addi r3,r1,1121
	ctx.r3.s64 = ctx.r1.s64 + 1121;
	// bl 0x823d9890
	ctx.lr = 0x82697630;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,1248(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1248, r26.u8);
	// addi r3,r1,1249
	ctx.r3.s64 = ctx.r1.s64 + 1249;
	// bl 0x823d9890
	ctx.lr = 0x82697644;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,1632(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1632, r26.u8);
	// addi r3,r1,1633
	ctx.r3.s64 = ctx.r1.s64 + 1633;
	// bl 0x823d9890
	ctx.lr = 0x82697658;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,2016(r1)
	PPC_STORE_U8(ctx.r1.u32 + 2016, r26.u8);
	// addi r3,r1,2017
	ctx.r3.s64 = ctx.r1.s64 + 2017;
	// bl 0x823d9890
	ctx.lr = 0x8269766C;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,1888(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1888, r26.u8);
	// addi r3,r1,1889
	ctx.r3.s64 = ctx.r1.s64 + 1889;
	// bl 0x823d9890
	ctx.lr = 0x82697680;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,1760(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1760, r26.u8);
	// addi r3,r1,1761
	ctx.r3.s64 = ctx.r1.s64 + 1761;
	// bl 0x823d9890
	ctx.lr = 0x82697694;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,864(r1)
	PPC_STORE_U8(ctx.r1.u32 + 864, r26.u8);
	// addi r3,r1,865
	ctx.r3.s64 = ctx.r1.s64 + 865;
	// bl 0x823d9890
	ctx.lr = 0x826976A8;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r26,2144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 2144, r26.u8);
	// addi r3,r1,2145
	ctx.r3.s64 = ctx.r1.s64 + 2145;
	// bl 0x823d9890
	ctx.lr = 0x826976BC;
	sub_823D9890(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r9,r9,-13284
	ctx.r9.s64 = ctx.r9.s64 + -13284;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stw r9,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// lis r31,-32256
	r31.s64 = -2113929216;
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r8,r8,31184
	ctx.r8.s64 = ctx.r8.s64 + 31184;
	// addi r7,r7,29344
	ctx.r7.s64 = ctx.r7.s64 + 29344;
	// addi r6,r6,-12176
	ctx.r6.s64 = ctx.r6.s64 + -12176;
	// stw r8,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r8.u32);
	// addi r5,r5,32176
	ctx.r5.s64 = ctx.r5.s64 + 32176;
	// stw r7,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r7.u32);
	// addi r4,r4,-2176
	ctx.r4.s64 = ctx.r4.s64 + -2176;
	// stw r6,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r6.u32);
	// addi r3,r3,7744
	ctx.r3.s64 = ctx.r3.s64 + 7744;
	// stw r5,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r5.u32);
	// addi r10,r10,-13268
	ctx.r10.s64 = ctx.r10.s64 + -13268;
	// stw r4,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r4.u32);
	// addi r9,r31,7760
	ctx.r9.s64 = r31.s64 + 7760;
	// stw r3,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r3.u32);
	// lis r28,-32256
	r28.s64 = -2113929216;
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// lis r24,-32256
	r24.s64 = -2113929216;
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// lis r23,-32255
	r23.s64 = -2113863680;
	// lis r22,-32247
	r22.s64 = -2113339392;
	// lis r21,-32248
	r21.s64 = -2113404928;
	// lis r20,-32255
	r20.s64 = -2113863680;
	// lis r19,-32245
	r19.s64 = -2113208320;
	// addi r8,r28,7756
	ctx.r8.s64 = r28.s64 + 7756;
	// addi r7,r24,7752
	ctx.r7.s64 = r24.s64 + 7752;
	// addi r6,r23,-13560
	ctx.r6.s64 = r23.s64 + -13560;
	// stw r8,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r8.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r7,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r7.u32);
	// addi r5,r22,-15984
	ctx.r5.s64 = r22.s64 + -15984;
	// stw r6,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r6.u32);
	// addi r4,r21,30504
	ctx.r4.s64 = r21.s64 + 30504;
	// addi r3,r20,-13276
	ctx.r3.s64 = r20.s64 + -13276;
	// stw r5,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r5.u32);
	// addi r10,r19,29328
	ctx.r10.s64 = r19.s64 + 29328;
	// stw r4,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r4.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stw r3,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r3.u32);
	// addi r31,r11,3998
	r31.s64 = r11.s64 + 3998;
	// stw r10,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r10.u32);
	// addi r8,r1,480
	ctx.r8.s64 = ctx.r1.s64 + 480;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r7,r1,1376
	ctx.r7.s64 = ctx.r1.s64 + 1376;
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r31.u32);
	// addi r6,r1,608
	ctx.r6.s64 = ctx.r1.s64 + 608;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r5,r1,736
	ctx.r5.s64 = ctx.r1.s64 + 736;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// addi r4,r1,992
	ctx.r4.s64 = ctx.r1.s64 + 992;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// addi r11,r1,1504
	r11.s64 = ctx.r1.s64 + 1504;
	// stw r4,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// addi r10,r1,1120
	ctx.r10.s64 = ctx.r1.s64 + 1120;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// addi r9,r1,1248
	ctx.r9.s64 = ctx.r1.s64 + 1248;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// addi r8,r1,1632
	ctx.r8.s64 = ctx.r1.s64 + 1632;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// addi r7,r1,2016
	ctx.r7.s64 = ctx.r1.s64 + 2016;
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// addi r6,r1,1888
	ctx.r6.s64 = ctx.r1.s64 + 1888;
	// addi r5,r1,1760
	ctx.r5.s64 = ctx.r1.s64 + 1760;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// addi r4,r1,864
	ctx.r4.s64 = ctx.r1.s64 + 864;
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// addi r3,r1,2144
	ctx.r3.s64 = ctx.r1.s64 + 2144;
	// stw r6,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// stw r5,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r5.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r4,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r4.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r3,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r3.u32);
	// addi r4,r11,636
	ctx.r4.s64 = r11.s64 + 636;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,128
	ctx.r6.s64 = 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82760bf0
	ctx.lr = 0x82697828;
	sub_82760BF0(ctx, base);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82694800
	ctx.lr = 0x82697834;
	sub_82694800(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826982a8
	if (!cr6.eq) goto loc_826982A8;
	// lbz r11,480(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 480);
	// lbz r5,352(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 352);
	// extsb r6,r11
	ctx.r6.s64 = r11.s8;
	// lbz r11,864(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 864);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x826978d4
	if (cr6.eq) goto loc_826978D4;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826978d4
	if (cr6.eq) goto loc_826978D4;
	// extsb r10,r5
	ctx.r10.s64 = ctx.r5.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826978d4
	if (cr6.eq) goto loc_826978D4;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x8269787C;
	sub_82697330(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,864
	ctx.r4.s64 = ctx.r1.s64 + 864;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697890;
	sub_82697330(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x826978A4;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x826978C8;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_826978D4:
	// lbz r10,608(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 608);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697978
	if (cr6.eq) goto loc_82697978;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82697978
	if (cr6.eq) goto loc_82697978;
	// lbz r10,1760(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1760);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82697978
	if (cr6.eq) goto loc_82697978;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x8269790C;
	sub_82697330(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,1760
	ctx.r4.s64 = ctx.r1.s64 + 1760;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697920;
	sub_82697330(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,864
	ctx.r4.s64 = ctx.r1.s64 + 864;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697934;
	sub_82697330(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697948;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x8269796C;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82697978:
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826979d8
	if (cr6.eq) goto loc_826979D8;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,2144
	ctx.r4.s64 = ctx.r1.s64 + 2144;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697994;
	sub_82697330(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,864
	ctx.r4.s64 = ctx.r1.s64 + 864;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x826979A8;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x826979CC;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_826979D8:
	// lbz r8,992(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 992);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697bd0
	if (cr6.eq) goto loc_82697BD0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x82697ad4
	if (cr6.eq) goto loc_82697AD4;
	// extsb r11,r8
	r11.s64 = ctx.r8.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82697ad4
	if (cr6.eq) goto loc_82697AD4;
	// extsb r11,r5
	r11.s64 = ctx.r5.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82697ad4
	if (cr6.eq) goto loc_82697AD4;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697A0C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r29,r11,-4944
	r29.s64 = r11.s64 + -4944;
	// beq cr6,0x82697a34
	if (cr6.eq) goto loc_82697A34;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82697A30;
	sub_82720A50(ctx, base);
	// b 0x82697a38
	goto loc_82697A38;
loc_82697A34:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_82697A38:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697A40;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82697a64
	if (cr6.eq) goto loc_82697A64;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r4,r1,992
	ctx.r4.s64 = ctx.r1.s64 + 992;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82697A5C;
	sub_82720A50(ctx, base);
	// mr r28,r30
	r28.u64 = r30.u64;
	// b 0x82697a68
	goto loc_82697A68;
loc_82697A64:
	// mr r28,r26
	r28.u64 = r26.u64;
loc_82697A68:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697A70;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82697a90
	if (cr6.eq) goto loc_82697A90;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82697A8C;
	sub_82720A50(ctx, base);
	// b 0x82697a94
	goto loc_82697A94;
loc_82697A90:
	// mr r30,r26
	r30.u64 = r26.u64;
loc_82697A94:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697AA4;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82697AC8;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82697AD4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697bd0
	if (cr6.eq) goto loc_82697BD0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x82697b90
	if (cr6.eq) goto loc_82697B90;
	// lbz r11,1504(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1504);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82697b90
	if (cr6.eq) goto loc_82697B90;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697AF8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r29,r11,-4944
	r29.s64 = r11.s64 + -4944;
	// beq cr6,0x82697b20
	if (cr6.eq) goto loc_82697B20;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addi r4,r1,1504
	ctx.r4.s64 = ctx.r1.s64 + 1504;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82697B1C;
	sub_82720A50(ctx, base);
	// b 0x82697b24
	goto loc_82697B24;
loc_82697B20:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_82697B24:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697B2C;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82697b4c
	if (cr6.eq) goto loc_82697B4C;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82697B48;
	sub_82720A50(ctx, base);
	// b 0x82697b50
	goto loc_82697B50;
loc_82697B4C:
	// mr r30,r26
	r30.u64 = r26.u64;
loc_82697B50:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697B60;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82697B84;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82697B90:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697bd0
	if (cr6.eq) goto loc_82697BD0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x82697bd0
	if (cr6.eq) goto loc_82697BD0;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697BA8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82697efc
	if (cr6.eq) goto loc_82697EFC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x82697BCC;
	sub_82720A50(ctx, base);
	// b 0x82697f00
	goto loc_82697F00;
loc_82697BD0:
	// lbz r11,1120(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1120);
	// lbz r10,1248(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1248);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82697c84
	if (cr6.eq) goto loc_82697C84;
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x82697c84
	if (cr6.eq) goto loc_82697C84;
	// lbz r7,1632(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1632);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82697c84
	if (cr6.eq) goto loc_82697C84;
	// lbz r7,2016(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 2016);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82697c84
	if (cr6.eq) goto loc_82697C84;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,2016
	ctx.r4.s64 = ctx.r1.s64 + 2016;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697C18;
	sub_82697330(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,1632
	ctx.r4.s64 = ctx.r1.s64 + 1632;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697C2C;
	sub_82697330(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,1248
	ctx.r4.s64 = ctx.r1.s64 + 1248;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697C40;
	sub_82697330(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,1120
	ctx.r4.s64 = ctx.r1.s64 + 1120;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697C54;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82697C78;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82697C84:
	// lbz r7,736(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 736);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697f40
	if (cr6.eq) goto loc_82697F40;
	// extsb r4,r7
	ctx.r4.s64 = ctx.r7.s8;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82697d44
	if (cr6.eq) goto loc_82697D44;
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82697d44
	if (cr6.eq) goto loc_82697D44;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697CB0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82697cd8
	if (cr6.eq) goto loc_82697CD8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,736
	ctx.r4.s64 = ctx.r1.s64 + 736;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x82697CD4;
	sub_82720A50(ctx, base);
	// b 0x82697cdc
	goto loc_82697CDC;
loc_82697CD8:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_82697CDC:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697CEC;
	sub_82697330(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,992
	ctx.r4.s64 = ctx.r1.s64 + 992;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697D00;
	sub_82697330(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697D14;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82697D38;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82697D44:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697f40
	if (cr6.eq) goto loc_82697F40;
	// extsb r8,r7
	ctx.r8.s64 = ctx.r7.s8;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82697e1c
	if (cr6.eq) goto loc_82697E1C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82697e1c
	if (cr6.eq) goto loc_82697E1C;
	// extsb r11,r10
	r11.s64 = ctx.r10.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82697e1c
	if (cr6.eq) goto loc_82697E1C;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697D74;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82697d9c
	if (cr6.eq) goto loc_82697D9C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,736
	ctx.r4.s64 = ctx.r1.s64 + 736;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x82697D98;
	sub_82720A50(ctx, base);
	// b 0x82697da0
	goto loc_82697DA0;
loc_82697D9C:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_82697DA0:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697DB0;
	sub_82697330(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,1248
	ctx.r4.s64 = ctx.r1.s64 + 1248;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697DC4;
	sub_82697330(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,1120
	ctx.r4.s64 = ctx.r1.s64 + 1120;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697DD8;
	sub_82697330(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697DEC;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82697E10;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82697E1C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697f40
	if (cr6.eq) goto loc_82697F40;
	// extsb r11,r7
	r11.s64 = ctx.r7.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82697eb8
	if (cr6.eq) goto loc_82697EB8;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697E38;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82697e60
	if (cr6.eq) goto loc_82697E60;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,736
	ctx.r4.s64 = ctx.r1.s64 + 736;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x82697E5C;
	sub_82720A50(ctx, base);
	// b 0x82697e64
	goto loc_82697E64;
loc_82697E60:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_82697E64:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697E74;
	sub_82697330(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697E88;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82697EAC;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82697EB8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697f40
	if (cr6.eq) goto loc_82697F40;
	// extsb r11,r5
	r11.s64 = ctx.r5.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82697f40
	if (cr6.eq) goto loc_82697F40;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82697ED4;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82697efc
	if (cr6.eq) goto loc_82697EFC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x82697EF8;
	sub_82720A50(ctx, base);
	// b 0x82697f00
	goto loc_82697F00;
loc_82697EFC:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_82697F00:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697F10;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82697F34;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82697F40:
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// addi r10,r10,32160
	ctx.r10.s64 = ctx.r10.s64 + 32160;
loc_82697F4C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82697f70
	if (cr6.eq) goto loc_82697F70;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82697f4c
	if (cr6.eq) goto loc_82697F4C;
loc_82697F70:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82697fe0
	if (!cr6.eq) goto loc_82697FE0;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697F88;
	sub_82697330(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,1888
	ctx.r4.s64 = ctx.r1.s64 + 1888;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697F9C;
	sub_82697330(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82697FB0;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82697FD4;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82697FE0:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x826981b8
	if (cr6.eq) goto loc_826981B8;
	// extsb r11,r7
	r11.s64 = ctx.r7.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82698010
	if (cr6.eq) goto loc_82698010;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// addi r6,r1,736
	ctx.r6.s64 = ctx.r1.s64 + 736;
	// addi r5,r1,480
	ctx.r5.s64 = ctx.r1.s64 + 480;
	// b 0x8269829c
	goto loc_8269829C;
loc_82698010:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x826981b8
	if (cr6.eq) goto loc_826981B8;
	// lbz r11,1376(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1376);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698098
	if (cr6.eq) goto loc_82698098;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x8269802C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82698054
	if (cr6.eq) goto loc_82698054;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,1376
	ctx.r4.s64 = ctx.r1.s64 + 1376;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x82698050;
	sub_82720A50(ctx, base);
	// b 0x82698058
	goto loc_82698058;
loc_82698054:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_82698058:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82698068;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x8269808C;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82698098:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x826981b8
	if (cr6.eq) goto loc_826981B8;
	// extsb r11,r5
	r11.s64 = ctx.r5.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82698120
	if (cr6.eq) goto loc_82698120;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x826980B4;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826980dc
	if (cr6.eq) goto loc_826980DC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,1376
	ctx.r4.s64 = ctx.r1.s64 + 1376;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x826980D8;
	sub_82720A50(ctx, base);
	// b 0x826980e0
	goto loc_826980E0;
loc_826980DC:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_826980E0:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x826980F0;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82698114;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82698120:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x826981b8
	if (cr6.eq) goto loc_826981B8;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82698130;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r29,r11,-4944
	r29.s64 = r11.s64 + -4944;
	// beq cr6,0x82698158
	if (cr6.eq) goto loc_82698158;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addi r4,r1,1888
	ctx.r4.s64 = ctx.r1.s64 + 1888;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82698154;
	sub_82720A50(ctx, base);
	// b 0x8269815c
	goto loc_8269815C;
loc_82698158:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_8269815C:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82698164;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82698188
	if (cr6.eq) goto loc_82698188;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82698180;
	sub_82720A50(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// b 0x8269818c
	goto loc_8269818C;
loc_82698188:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
loc_8269818C:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82695808
	ctx.lr = 0x826981AC;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_826981B8:
	// extsb r11,r7
	r11.s64 = ctx.r7.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82698238
	if (cr6.eq) goto loc_82698238;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x826981CC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826981f4
	if (cr6.eq) goto loc_826981F4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,736
	ctx.r4.s64 = ctx.r1.s64 + 736;
	// addi r10,r11,-4944
	ctx.r10.s64 = r11.s64 + -4944;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82720a50
	ctx.lr = 0x826981F0;
	sub_82720A50(ctx, base);
	// b 0x826981f8
	goto loc_826981F8;
loc_826981F4:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_826981F8:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82698208;
	sub_82697330(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x8269822C;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82698238:
	// extsb r11,r5
	r11.s64 = ctx.r5.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82698284
	if (cr6.eq) goto loc_82698284;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82697330
	ctx.lr = 0x82698254;
	sub_82697330(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82695808
	ctx.lr = 0x82698278;
	sub_82695808(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
loc_82698284:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
loc_8269829C:
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82696260
	ctx.lr = 0x826982A8;
	sub_82696260(ctx, base);
loc_826982A8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,2384
	ctx.r1.s64 = ctx.r1.s64 + 2384;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_826982B4"))) PPC_WEAK_FUNC(sub_826982B4);
PPC_FUNC_IMPL(__imp__sub_826982B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826982B8"))) PPC_WEAK_FUNC(sub_826982B8);
PPC_FUNC_IMPL(__imp__sub_826982B8) {
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
	ctx.lr = 0x826982C0;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r9,64
	ctx.r9.s64 = 64;
	// addi r10,r11,32136
	ctx.r10.s64 = r11.s64 + 32136;
	// li r24,0
	r24.s64 = 0;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// li r3,256
	ctx.r3.s64 = 256;
	// sth r24,72(r28)
	PPC_STORE_U16(r28.u32 + 72, r24.u16);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// sth r9,74(r28)
	PPC_STORE_U16(r28.u32 + 74, ctx.r9.u16);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// addi r30,r28,68
	r30.s64 = r28.s64 + 68;
	// bl 0x82130528
	ctx.lr = 0x82698304;
	sub_82130528(ctx, base);
	// stw r3,68(r28)
	PPC_STORE_U32(r28.u32 + 68, ctx.r3.u32);
	// li r5,127
	ctx.r5.s64 = 127;
	// stb r24,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r24.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,113
	ctx.r3.s64 = ctx.r1.s64 + 113;
	// bl 0x823d9890
	ctx.lr = 0x8269831C;
	sub_823D9890(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r4,r7,25080
	ctx.r4.s64 = ctx.r7.s64 + 25080;
	// addi r3,r6,3998
	ctx.r3.s64 = ctx.r6.s64 + 3998;
	// addi r5,r8,29344
	ctx.r5.s64 = ctx.r8.s64 + 29344;
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r11,30868
	r29.s64 = r11.s64 + 30868;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82760940
	ctx.lr = 0x82698360;
	sub_82760940(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826955c8
	ctx.lr = 0x82698368;
	sub_826955C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,128
	ctx.r6.s64 = 128;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x826983c8
	if (cr6.eq) goto loc_826983C8;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x82760bf0
	ctx.lr = 0x82698390;
	sub_82760BF0(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// subf r10,r10,r28
	ctx.r10.s64 = r28.s64 - ctx.r10.s64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_826983A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x826983a0
	if (!cr6.eq) goto loc_826983A0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82696e88
	ctx.lr = 0x826983BC;
	sub_82696E88(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9238
	return;
loc_826983C8:
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x82760bf0
	ctx.lr = 0x826983D0;
	sub_82760BF0(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// subf r10,r10,r28
	ctx.r10.s64 = r28.s64 - ctx.r10.s64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_826983E0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x826983e0
	if (!cr6.eq) goto loc_826983E0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760b38
	ctx.lr = 0x82698404;
	sub_82760B38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82698474
	if (!cr6.eq) goto loc_82698474;
loc_82698410:
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x82698418;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269843c
	if (cr6.eq) goto loc_8269843C;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82697550
	ctx.lr = 0x82698434;
	sub_82697550(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x82698440
	goto loc_82698440;
loc_8269843C:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_82698440:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r7,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r7.u16);
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// bl 0x82760b38
	ctx.lr = 0x82698468;
	sub_82760B38(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82698410
	if (cr6.eq) goto loc_82698410;
loc_82698474:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82696e88
	ctx.lr = 0x8269847C;
	sub_82696E88(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82698488"))) PPC_WEAK_FUNC(sub_82698488);
PPC_FUNC_IMPL(__imp__sub_82698488) {
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
	ctx.lr = 0x82698490;
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r7,932(r1)
	PPC_STORE_U32(ctx.r1.u32 + 932, ctx.r7.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// stw r3,900(r1)
	PPC_STORE_U32(ctx.r1.u32 + 900, ctx.r3.u32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,32188
	ctx.r4.s64 = r11.s64 + 32188;
	// stw r30,924(r1)
	PPC_STORE_U32(ctx.r1.u32 + 924, r30.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// bl 0x823dc018
	ctx.lr = 0x826984C4;
	sub_823DC018(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760b38
	ctx.lr = 0x826984D4;
	sub_82760B38(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82698978
	if (!cr6.eq) goto loc_82698978;
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// lis r27,-32125
	r27.s64 = -2105344000;
	// lis r26,-32245
	r26.s64 = -2113208320;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lis r30,-32245
	r30.s64 = -2113208320;
	// lis r3,-32245
	ctx.r3.s64 = -2113208320;
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r4,r4,30868
	ctx.r4.s64 = ctx.r4.s64 + 30868;
	// addi r9,r9,29360
	ctx.r9.s64 = ctx.r9.s64 + 29360;
	// addi r18,r28,-29288
	r18.s64 = r28.s64 + -29288;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r17,r27,-29292
	r17.s64 = r27.s64 + -29292;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r21,r26,31332
	r21.s64 = r26.s64 + 31332;
	// li r24,0
	r24.s64 = 0;
	// addi r19,r29,-29496
	r19.s64 = r29.s64 + -29496;
	// addi r28,r30,31236
	r28.s64 = r30.s64 + 31236;
	// addi r27,r3,32180
	r27.s64 = ctx.r3.s64 + 32180;
	// addi r16,r5,29328
	r16.s64 = ctx.r5.s64 + 29328;
	// addi r15,r6,-13276
	r15.s64 = ctx.r6.s64 + -13276;
	// addi r20,r7,31340
	r20.s64 = ctx.r7.s64 + 31340;
	// addi r14,r8,29344
	r14.s64 = ctx.r8.s64 + 29344;
	// addi r22,r10,3998
	r22.s64 = ctx.r10.s64 + 3998;
	// addi r26,r11,31184
	r26.s64 = r11.s64 + 31184;
loc_8269855C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760940
	ctx.lr = 0x82698568;
	sub_82760940(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698638
	if (cr6.eq) goto loc_82698638;
	// li r5,127
	ctx.r5.s64 = 127;
	// stb r24,336(r1)
	PPC_STORE_U8(ctx.r1.u32 + 336, r24.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,337
	ctx.r3.s64 = ctx.r1.s64 + 337;
	// bl 0x823d9890
	ctx.lr = 0x82698588;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r24,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r24.u8);
	// addi r3,r1,209
	ctx.r3.s64 = ctx.r1.s64 + 209;
	// bl 0x823d9890
	ctx.lr = 0x8269859C;
	sub_823D9890(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// stw r14,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r14.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// stw r22,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r22.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r6,128
	ctx.r6.s64 = 128;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760bf0
	ctx.lr = 0x826985D8;
	sub_82760BF0(ctx, base);
	// li r3,232
	ctx.r3.s64 = 232;
	// bl 0x82130528
	ctx.lr = 0x826985E0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269860c
	if (cr6.eq) goto loc_8269860C;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// lwz r4,900(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 900);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// bl 0x82698b98
	ctx.lr = 0x82698604;
	sub_82698B98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82698610
	goto loc_82698610;
loc_8269860C:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
loc_82698610:
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lwz r3,932(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 932);
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// bl 0x82696830
	ctx.lr = 0x82698624;
	sub_82696830(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// addi r3,r25,8
	ctx.r3.s64 = r25.s64 + 8;
	// bl 0x82695f18
	ctx.lr = 0x82698634;
	sub_82695F18(ctx, base);
	// b 0x8269895c
	goto loc_8269895C;
loc_82698638:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760940
	ctx.lr = 0x82698644;
	sub_82760940(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698738
	if (cr6.eq) goto loc_82698738;
	// li r5,127
	ctx.r5.s64 = 127;
	// stb r24,464(r1)
	PPC_STORE_U8(ctx.r1.u32 + 464, r24.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,465
	ctx.r3.s64 = ctx.r1.s64 + 465;
	// bl 0x823d9890
	ctx.lr = 0x82698664;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r24,592(r1)
	PPC_STORE_U8(ctx.r1.u32 + 592, r24.u8);
	// addi r3,r1,593
	ctx.r3.s64 = ctx.r1.s64 + 593;
	// bl 0x823d9890
	ctx.lr = 0x82698678;
	sub_823D9890(ctx, base);
	// addi r11,r1,464
	r11.s64 = ctx.r1.s64 + 464;
	// addi r10,r1,592
	ctx.r10.s64 = ctx.r1.s64 + 592;
	// stw r15,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r15.u32);
	// stw r16,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r16.u32);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// stw r22,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r22.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// li r6,128
	ctx.r6.s64 = 128;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760bf0
	ctx.lr = 0x826986B0;
	sub_82760BF0(ctx, base);
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x826986B8;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826986f8
	if (cr6.eq) goto loc_826986F8;
	// addi r29,r30,32
	r29.s64 = r30.s64 + 32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82720a08
	ctx.lr = 0x826986D0;
	sub_82720A08(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823db670
	ctx.lr = 0x826986E0;
	sub_823DB670(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,592
	ctx.r4.s64 = ctx.r1.s64 + 592;
	// addi r3,r29,92
	ctx.r3.s64 = r29.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x826986F0;
	sub_823DB670(ctx, base);
	// stw r24,188(r30)
	PPC_STORE_U32(r30.u32 + 188, r24.u32);
	// b 0x826986fc
	goto loc_826986FC;
loc_826986F8:
	// mr r30,r24
	r30.u64 = r24.u64;
loc_826986FC:
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,932(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 932);
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// bl 0x82695f18
	ctx.lr = 0x82698714;
	sub_82695F18(ctx, base);
	// lwz r11,932(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 932);
	// addi r9,r11,44
	ctx.r9.s64 = r11.s64 + 44;
	// lhz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 48);
	// lwz r8,44(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,48(r11)
	PPC_STORE_U16(r11.u32 + 48, ctx.r7.u16);
	// stwx r30,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r30.u32);
	// b 0x8269895c
	goto loc_8269895C;
loc_82698738:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82760940
	ctx.lr = 0x82698744;
	sub_82760940(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826987b0
	if (cr6.eq) goto loc_826987B0;
	// li r5,127
	ctx.r5.s64 = 127;
	// stb r24,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r24.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,209
	ctx.r3.s64 = ctx.r1.s64 + 209;
	// bl 0x823d9890
	ctx.lr = 0x82698764;
	sub_823D9890(ctx, base);
	// li r3,76
	ctx.r3.s64 = 76;
	// bl 0x82130528
	ctx.lr = 0x8269876C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82698794
	if (cr6.eq) goto loc_82698794;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x826982b8
	ctx.lr = 0x8269878C;
	sub_826982B8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// b 0x82698798
	goto loc_82698798;
loc_82698794:
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
loc_82698798:
	// lwz r11,932(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 932);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82695f18
	ctx.lr = 0x826987AC;
	sub_82695F18(ctx, base);
	// b 0x8269895c
	goto loc_8269895C;
loc_826987B0:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760940
	ctx.lr = 0x826987BC;
	sub_82760940(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698864
	if (cr6.eq) goto loc_82698864;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x827608b0
	ctx.lr = 0x826987D8;
	sub_827608B0(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760b38
	ctx.lr = 0x826987E8;
	sub_82760B38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269895c
	if (!cr6.eq) goto loc_8269895C;
loc_826987F4:
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x826987FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82698820
	if (cr6.eq) goto loc_82698820;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82697550
	ctx.lr = 0x82698818;
	sub_82697550(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// b 0x82698824
	goto loc_82698824;
loc_82698820:
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
loc_82698824:
	// lwz r11,932(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 932);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,20(r11)
	PPC_STORE_U16(r11.u32 + 20, ctx.r6.u16);
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// bl 0x82760b38
	ctx.lr = 0x82698854;
	sub_82760B38(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826987f4
	if (cr6.eq) goto loc_826987F4;
	// b 0x8269895c
	goto loc_8269895C;
loc_82698864:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82760940
	ctx.lr = 0x8269886C;
	sub_82760940(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698914
	if (cr6.eq) goto loc_82698914;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x827608b0
	ctx.lr = 0x82698888;
	sub_827608B0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760b38
	ctx.lr = 0x82698898;
	sub_82760B38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269895c
	if (!cr6.eq) goto loc_8269895C;
loc_826988A4:
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82130528
	ctx.lr = 0x826988AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826988d0
	if (cr6.eq) goto loc_826988D0;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82697550
	ctx.lr = 0x826988C8;
	sub_82697550(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// b 0x826988d4
	goto loc_826988D4;
loc_826988D0:
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
loc_826988D4:
	// lwz r11,932(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 932);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r9,r11,24
	ctx.r9.s64 = r11.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 28);
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,28(r11)
	PPC_STORE_U16(r11.u32 + 28, ctx.r6.u16);
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// bl 0x82760b38
	ctx.lr = 0x82698904;
	sub_82760B38(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826988a4
	if (cr6.eq) goto loc_826988A4;
	// b 0x8269895c
	goto loc_8269895C;
loc_82698914:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x82760940
	ctx.lr = 0x8269891C;
	sub_82760940(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269895c
	if (cr6.eq) goto loc_8269895C;
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r6,128
	ctx.r6.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760bf0
	ctx.lr = 0x82698944;
	sub_82760BF0(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// lwz r3,900(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 900);
	// addi r6,r1,932
	ctx.r6.s64 = ctx.r1.s64 + 932;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x82698d90
	ctx.lr = 0x8269895C;
	sub_82698D90(ctx, base);
loc_8269895C:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,924(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 924);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760b38
	ctx.lr = 0x8269896C;
	sub_82760B38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269855c
	if (cr6.eq) goto loc_8269855C;
loc_82698978:
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82698980"))) PPC_WEAK_FUNC(sub_82698980);
PPC_FUNC_IMPL(__imp__sub_82698980) {
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
	ctx.lr = 0x82698988;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r9,r10,32196
	ctx.r9.s64 = ctx.r10.s64 + 32196;
	// lhz r11,28(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 28);
	// stw r9,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826989e0
	if (!cr6.gt) goto loc_826989E0;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_826989B0:
	// lwz r11,24(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826989d4
	if (cr6.eq) goto loc_826989D4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826989D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826989D4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826989b0
	if (!cr0.eq) goto loc_826989B0;
loc_826989E0:
	// lhz r30,20(r27)
	r30.u64 = PPC_LOAD_U16(r27.u32 + 20);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82698a20
	if (!cr6.gt) goto loc_82698A20;
	// li r31,0
	r31.s64 = 0;
loc_826989F0:
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82698a14
	if (cr6.eq) goto loc_82698A14;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82698A14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82698A14:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826989f0
	if (!cr0.eq) goto loc_826989F0;
loc_82698A20:
	// lhz r11,48(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82698a6c
	if (!cr6.gt) goto loc_82698A6C;
	// mr r30,r11
	r30.u64 = r11.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// addi r28,r10,-19708
	r28.s64 = ctx.r10.s64 + -19708;
loc_82698A44:
	// lwz r11,44(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82698a60
	if (cr6.eq) goto loc_82698A60;
	// stw r28,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r28.u32);
	// stw r29,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r29.u32);
	// bl 0x82130588
	ctx.lr = 0x82698A60;
	sub_82130588(ctx, base);
loc_82698A60:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82698a44
	if (!cr0.eq) goto loc_82698A44;
loc_82698A6C:
	// lhz r10,8(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 8);
	// addi r29,r27,4
	r29.s64 = r27.s64 + 4;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82698b0c
	if (!cr6.gt) goto loc_82698B0C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_82698A84:
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82698aa4
	if (!cr6.eq) goto loc_82698AA4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x82698a84
	if (cr6.lt) goto loc_82698A84;
	// b 0x82698b0c
	goto loc_82698B0C;
loc_82698AA4:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82698ac4
	if (cr6.eq) goto loc_82698AC4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82698AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82698AC4:
	// lwz r30,12(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82698aa4
	if (!cr6.eq) goto loc_82698AA4;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_82698ADC:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82698b04
	if (!cr6.lt) goto loc_82698B04;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r30,r11,r8
	r30.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82698adc
	if (cr6.eq) goto loc_82698ADC;
	// b 0x82698aa4
	goto loc_82698AA4;
loc_82698B04:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82698aa4
	if (!cr6.eq) goto loc_82698AA4;
loc_82698B0C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82696ae8
	ctx.lr = 0x82698B14;
	sub_82696AE8(ctx, base);
	// lhz r11,158(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698b28
	if (cr6.eq) goto loc_82698B28;
	// lwz r3,152(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 152);
	// bl 0x82130588
	ctx.lr = 0x82698B28;
	sub_82130588(ctx, base);
loc_82698B28:
	// addi r3,r27,140
	ctx.r3.s64 = r27.s64 + 140;
	// bl 0x82138a18
	ctx.lr = 0x82698B30;
	sub_82138A18(ctx, base);
	// addi r3,r27,128
	ctx.r3.s64 = r27.s64 + 128;
	// bl 0x82138a18
	ctx.lr = 0x82698B38;
	sub_82138A18(ctx, base);
	// lhz r11,50(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 50);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698b4c
	if (cr6.eq) goto loc_82698B4C;
	// lwz r3,44(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// bl 0x82130588
	ctx.lr = 0x82698B4C;
	sub_82130588(ctx, base);
loc_82698B4C:
	// addi r3,r27,32
	ctx.r3.s64 = r27.s64 + 32;
	// bl 0x82138a18
	ctx.lr = 0x82698B54;
	sub_82138A18(ctx, base);
	// lhz r11,30(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698b68
	if (cr6.eq) goto loc_82698B68;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x82698B68;
	sub_82130588(ctx, base);
loc_82698B68:
	// lhz r11,22(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698b7c
	if (cr6.eq) goto loc_82698B7C;
	// lwz r3,16(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x82698B7C;
	sub_82130588(ctx, base);
loc_82698B7C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82138a18
	ctx.lr = 0x82698B84;
	sub_82138A18(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82698B8C"))) PPC_WEAK_FUNC(sub_82698B8C);
PPC_FUNC_IMPL(__imp__sub_82698B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82698B90"))) PPC_WEAK_FUNC(sub_82698B90);
PPC_FUNC_IMPL(__imp__sub_82698B90) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,124(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82698B98"))) PPC_WEAK_FUNC(sub_82698B98);
PPC_FUNC_IMPL(__imp__sub_82698B98) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82698BA0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r31,0
	r31.s64 = 0;
	// addi r10,r11,32196
	ctx.r10.s64 = r11.s64 + 32196;
	// li r25,64
	r25.s64 = 64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// li r3,256
	ctx.r3.s64 = 256;
	// sth r31,10(r30)
	PPC_STORE_U16(r30.u32 + 10, r31.u16);
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// sth r31,8(r30)
	PPC_STORE_U16(r30.u32 + 8, r31.u16);
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// stb r31,15(r30)
	PPC_STORE_U8(r30.u32 + 15, r31.u8);
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// sth r31,20(r30)
	PPC_STORE_U16(r30.u32 + 20, r31.u16);
	// mr r20,r8
	r20.u64 = ctx.r8.u64;
	// sth r25,22(r30)
	PPC_STORE_U16(r30.u32 + 22, r25.u16);
	// mr r19,r9
	r19.u64 = ctx.r9.u64;
	// addi r27,r30,16
	r27.s64 = r30.s64 + 16;
	// bl 0x82130528
	ctx.lr = 0x82698BF8;
	sub_82130528(ctx, base);
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// sth r31,28(r30)
	PPC_STORE_U16(r30.u32 + 28, r31.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// sth r25,30(r30)
	PPC_STORE_U16(r30.u32 + 30, r25.u16);
	// addi r26,r30,24
	r26.s64 = r30.s64 + 24;
	// bl 0x82130528
	ctx.lr = 0x82698C10;
	sub_82130528(ctx, base);
	// stw r3,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r3.u32);
	// sth r31,38(r30)
	PPC_STORE_U16(r30.u32 + 38, r31.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// sth r31,36(r30)
	PPC_STORE_U16(r30.u32 + 36, r31.u16);
	// addi r28,r30,32
	r28.s64 = r30.s64 + 32;
	// stw r31,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r31.u32);
	// addi r29,r30,44
	r29.s64 = r30.s64 + 44;
	// stb r31,43(r30)
	PPC_STORE_U8(r30.u32 + 43, r31.u8);
	// sth r31,48(r30)
	PPC_STORE_U16(r30.u32 + 48, r31.u16);
	// sth r25,50(r30)
	PPC_STORE_U16(r30.u32 + 50, r25.u16);
	// bl 0x82130528
	ctx.lr = 0x82698C3C;
	sub_82130528(ctx, base);
	// stw r3,44(r30)
	PPC_STORE_U32(r30.u32 + 44, ctx.r3.u32);
	// stw r31,120(r30)
	PPC_STORE_U32(r30.u32 + 120, r31.u32);
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r31,124(r30)
	PPC_STORE_U32(r30.u32 + 124, r31.u32);
	// li r3,512
	ctx.r3.s64 = 512;
	// sth r31,134(r30)
	PPC_STORE_U16(r30.u32 + 134, r31.u16);
	// addi r25,r30,152
	r25.s64 = r30.s64 + 152;
	// sth r31,132(r30)
	PPC_STORE_U16(r30.u32 + 132, r31.u16);
	// stw r31,128(r30)
	PPC_STORE_U32(r30.u32 + 128, r31.u32);
	// stb r31,139(r30)
	PPC_STORE_U8(r30.u32 + 139, r31.u8);
	// sth r31,146(r30)
	PPC_STORE_U16(r30.u32 + 146, r31.u16);
	// sth r31,144(r30)
	PPC_STORE_U16(r30.u32 + 144, r31.u16);
	// stw r31,140(r30)
	PPC_STORE_U32(r30.u32 + 140, r31.u32);
	// stb r31,151(r30)
	PPC_STORE_U8(r30.u32 + 151, r31.u8);
	// sth r31,156(r30)
	PPC_STORE_U16(r30.u32 + 156, r31.u16);
	// sth r9,158(r30)
	PPC_STORE_U16(r30.u32 + 158, ctx.r9.u16);
	// bl 0x82130528
	ctx.lr = 0x82698C80;
	sub_82130528(ctx, base);
	// stw r3,152(r30)
	PPC_STORE_U32(r30.u32 + 152, ctx.r3.u32);
	// stw r31,224(r30)
	PPC_STORE_U32(r30.u32 + 224, r31.u32);
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// stb r31,160(r30)
	PPC_STORE_U8(r30.u32 + 160, r31.u8);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82698488
	ctx.lr = 0x82698CA8;
	sub_82698488(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r24,r11,29360
	r24.s64 = r11.s64 + 29360;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x826948d8
	ctx.lr = 0x82698CBC;
	sub_826948D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82698d10
	if (!cr6.eq) goto loc_82698D10;
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x82698CCC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82698ce4
	if (cr6.eq) goto loc_82698CE4;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x826956c8
	ctx.lr = 0x82698CE0;
	sub_826956C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82698CE4:
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82695f18
	ctx.lr = 0x82698CF8;
	sub_82695F18(ctx, base);
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r8.u16);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
loc_82698D10:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82696e88
	ctx.lr = 0x82698D18;
	sub_82696E88(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82696e88
	ctx.lr = 0x82698D20;
	sub_82696E88(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82696e88
	ctx.lr = 0x82698D28;
	sub_82696E88(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82696e88
	ctx.lr = 0x82698D30;
	sub_82696E88(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82698D3C"))) PPC_WEAK_FUNC(sub_82698D3C);
PPC_FUNC_IMPL(__imp__sub_82698D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82698D40"))) PPC_WEAK_FUNC(sub_82698D40);
PPC_FUNC_IMPL(__imp__sub_82698D40) {
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
	// bl 0x82698980
	ctx.lr = 0x82698D60;
	sub_82698980(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82698d78
	if (cr6.eq) goto loc_82698D78;
	// bl 0x82130588
	ctx.lr = 0x82698D74;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82698D78:
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

__attribute__((alias("__imp__sub_82698D90"))) PPC_WEAK_FUNC(sub_82698D90);
PPC_FUNC_IMPL(__imp__sub_82698D90) {
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
	ctx.lr = 0x82698D98;
	// stwu r1,-1456(r1)
	ea = -1456 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r5,r11,5276
	ctx.r5.s64 = r11.s64 + 5276;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82698DC8;
	sub_821CA6A8(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// li r31,0
	r31.s64 = 0;
	// addi r8,r9,31940
	ctx.r8.s64 = ctx.r9.s64 + 31940;
	// stw r31,1248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1248, r31.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// stw r8,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, ctx.r8.u32);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// stw r31,1252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1252, r31.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r7,32240
	ctx.r4.s64 = ctx.r7.s64 + 32240;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// bl 0x82760048
	ctx.lr = 0x82698DFC;
	sub_82760048(ctx, base);
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// bl 0x82760d58
	ctx.lr = 0x82698E04;
	sub_82760D58(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, r31.u8);
	// addi r3,r1,193
	ctx.r3.s64 = ctx.r1.s64 + 193;
	// bl 0x823d9890
	ctx.lr = 0x82698E18;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,576(r1)
	PPC_STORE_U8(ctx.r1.u32 + 576, r31.u8);
	// addi r3,r1,577
	ctx.r3.s64 = ctx.r1.s64 + 577;
	// bl 0x823d9890
	ctx.lr = 0x82698E2C;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,320(r1)
	PPC_STORE_U8(ctx.r1.u32 + 320, r31.u8);
	// addi r3,r1,321
	ctx.r3.s64 = ctx.r1.s64 + 321;
	// bl 0x823d9890
	ctx.lr = 0x82698E40;
	sub_823D9890(ctx, base);
	// li r5,127
	ctx.r5.s64 = 127;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,448(r1)
	PPC_STORE_U8(ctx.r1.u32 + 448, r31.u8);
	// addi r3,r1,449
	ctx.r3.s64 = ctx.r1.s64 + 449;
	// bl 0x823d9890
	ctx.lr = 0x82698E54;
	sub_823D9890(ctx, base);
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// lis r3,-32245
	ctx.r3.s64 = -2113208320;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r6,29360
	ctx.r10.s64 = ctx.r6.s64 + 29360;
	// addi r8,r4,31360
	ctx.r8.s64 = ctx.r4.s64 + 31360;
	// addi r7,r3,31372
	ctx.r7.s64 = ctx.r3.s64 + 31372;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r9,r5,29344
	ctx.r9.s64 = ctx.r5.s64 + 29344;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// addi r6,r11,3998
	ctx.r6.s64 = r11.s64 + 3998;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// addi r4,r1,576
	ctx.r4.s64 = ctx.r1.s64 + 576;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r11,r1,448
	r11.s64 = ctx.r1.s64 + 448;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,128
	ctx.r6.s64 = 128;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// lwz r4,-29428(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -29428);
	// bl 0x82760bf0
	ctx.lr = 0x82698ED0;
	sub_82760BF0(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r10,32188
	ctx.r4.s64 = ctx.r10.s64 + 32188;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823dc018
	ctx.lr = 0x82698EE4;
	sub_823DC018(ctx, base);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82698f0c
	if (cr6.eq) goto loc_82698F0C;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,-29428(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -29428);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,704
	ctx.r4.s64 = ctx.r1.s64 + 704;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82698488
	ctx.lr = 0x82698F08;
	sub_82698488(ctx, base);
	// b 0x82698f44
	goto loc_82698F44;
loc_82698F0C:
	// li r3,232
	ctx.r3.s64 = 232;
	// bl 0x82130528
	ctx.lr = 0x82698F14;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82698f3c
	if (cr6.eq) goto loc_82698F3C;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// lwz r8,-29428(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + -29428);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r6,r1,704
	ctx.r6.s64 = ctx.r1.s64 + 704;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// bl 0x82698b98
	ctx.lr = 0x82698F38;
	sub_82698B98(ctx, base);
	// b 0x82698f40
	goto loc_82698F40;
loc_82698F3C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82698F40:
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
loc_82698F44:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, ctx.r10.u32);
	// bl 0x821be610
	ctx.lr = 0x82698F58;
	sub_821BE610(ctx, base);
	// addi r1,r1,1456
	ctx.r1.s64 = ctx.r1.s64 + 1456;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82698F60"))) PPC_WEAK_FUNC(sub_82698F60);
PPC_FUNC_IMPL(__imp__sub_82698F60) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,32236
	ctx.r9.s64 = ctx.r10.s64 + 32236;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r5,r31,88
	ctx.r5.s64 = r31.s64 + 88;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r6,r31,4
	ctx.r6.s64 = r31.s64 + 4;
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// addi r3,r8,3998
	ctx.r3.s64 = ctx.r8.s64 + 3998;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stb r11,19(r31)
	PPC_STORE_U8(r31.u32 + 19, r11.u8);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// sth r11,94(r31)
	PPC_STORE_U16(r31.u32 + 94, r11.u16);
	// sth r11,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r11.u16);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// stb r11,99(r31)
	PPC_STORE_U8(r31.u32 + 99, r11.u8);
	// sth r11,106(r31)
	PPC_STORE_U16(r31.u32 + 106, r11.u16);
	// sth r11,104(r31)
	PPC_STORE_U16(r31.u32 + 104, r11.u16);
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stb r11,111(r31)
	PPC_STORE_U8(r31.u32 + 111, r11.u8);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// stb r11,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r11.u8);
	// bl 0x82698d90
	ctx.lr = 0x82698FDC;
	sub_82698D90(ctx, base);
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

__attribute__((alias("__imp__sub_82698FF4"))) PPC_WEAK_FUNC(sub_82698FF4);
PPC_FUNC_IMPL(__imp__sub_82698FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82698FF8"))) PPC_WEAK_FUNC(sub_82698FF8);
PPC_FUNC_IMPL(__imp__sub_82698FF8) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,32236
	ctx.r10.s64 = r11.s64 + 32236;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82699040
	if (cr6.eq) goto loc_82699040;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82699040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82699040:
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x82696e00
	ctx.lr = 0x82699048;
	sub_82696E00(ctx, base);
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x82696e00
	ctx.lr = 0x82699050;
	sub_82696E00(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82138a18
	ctx.lr = 0x82699058;
	sub_82138A18(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82699070
	if (cr6.eq) goto loc_82699070;
	// bl 0x82130588
	ctx.lr = 0x8269906C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82699070:
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

__attribute__((alias("__imp__sub_82699088"))) PPC_WEAK_FUNC(sub_82699088);
PPC_FUNC_IMPL(__imp__sub_82699088) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lwz r3,-29340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -29340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826990bc
	if (cr6.eq) goto loc_826990BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826990BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826990BC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-29340(r31)
	PPC_STORE_U32(r31.u32 + -29340, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826990D8"))) PPC_WEAK_FUNC(sub_826990D8);
PPC_FUNC_IMPL(__imp__sub_826990D8) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826990F8;
	sub_822A3998(ctx, base);
	// bl 0x822a7cc8
	ctx.lr = 0x826990FC;
	sub_822A7CC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82699144
	if (cr6.eq) goto loc_82699144;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699114;
	sub_822A3998(ctx, base);
	// lbz r11,17(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82699130
	if (!cr6.eq) goto loc_82699130;
	// lbz r11,16(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82699134
	if (cr6.eq) goto loc_82699134;
loc_82699130:
	// li r11,1
	r11.s64 = 1;
loc_82699134:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82699148
	if (cr6.eq) goto loc_82699148;
loc_82699144:
	// li r11,0
	r11.s64 = 0;
loc_82699148:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82699160"))) PPC_WEAK_FUNC(sub_82699160);
PPC_FUNC_IMPL(__imp__sub_82699160) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699184;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826991e0
	if (cr6.eq) goto loc_826991E0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269919C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826991e0
	if (cr6.eq) goto loc_826991E0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826991B8;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r30,1
	r30.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r30,2154(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2154, r30.u8);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826991D4;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// stb r30,2156(r8)
	PPC_STORE_U8(ctx.r8.u32 + 2156, r30.u8);
loc_826991E0:
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

__attribute__((alias("__imp__sub_826991F8"))) PPC_WEAK_FUNC(sub_826991F8);
PPC_FUNC_IMPL(__imp__sub_826991F8) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269921C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82699278
	if (cr6.eq) goto loc_82699278;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699234;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82699278
	if (cr6.eq) goto loc_82699278;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699250;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r30,1
	r30.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r30,2153(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2153, r30.u8);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269926C;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// stb r30,2155(r8)
	PPC_STORE_U8(ctx.r8.u32 + 2155, r30.u8);
loc_82699278:
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

__attribute__((alias("__imp__sub_82699290"))) PPC_WEAK_FUNC(sub_82699290);
PPC_FUNC_IMPL(__imp__sub_82699290) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826992B0;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826992f4
	if (cr6.eq) goto loc_826992F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826992C8;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826992f4
	if (cr6.eq) goto loc_826992F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826992E4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r10,2160(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2160, ctx.r10.u8);
loc_826992F4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82699308"))) PPC_WEAK_FUNC(sub_82699308);
PPC_FUNC_IMPL(__imp__sub_82699308) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699328;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8269936c
	if (cr6.eq) goto loc_8269936C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699340;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8269936c
	if (cr6.eq) goto loc_8269936C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269935C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r10,2159(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2159, ctx.r10.u8);
loc_8269936C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82699380"))) PPC_WEAK_FUNC(sub_82699380);
PPC_FUNC_IMPL(__imp__sub_82699380) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826993A4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82699400
	if (cr6.eq) goto loc_82699400;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826993BC;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82699400
	if (cr6.eq) goto loc_82699400;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826993D8;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r30,1
	r30.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r30,2149(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2149, r30.u8);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826993F4;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// stb r30,2151(r8)
	PPC_STORE_U8(ctx.r8.u32 + 2151, r30.u8);
loc_82699400:
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

__attribute__((alias("__imp__sub_82699418"))) PPC_WEAK_FUNC(sub_82699418);
PPC_FUNC_IMPL(__imp__sub_82699418) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269943C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82699498
	if (cr6.eq) goto loc_82699498;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699454;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82699498
	if (cr6.eq) goto loc_82699498;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699470;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r30,1
	r30.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r30,2150(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2150, r30.u8);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269948C;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// stb r30,2152(r8)
	PPC_STORE_U8(ctx.r8.u32 + 2152, r30.u8);
loc_82699498:
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

__attribute__((alias("__imp__sub_826994B0"))) PPC_WEAK_FUNC(sub_826994B0);
PPC_FUNC_IMPL(__imp__sub_826994B0) {
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
	ctx.lr = 0x826994B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826994D0;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r29,r31,21628
	r29.s64 = r31.s64 + 21628;
	// lbz r9,21660(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 21660);
	// li r30,0
	r30.s64 = 0;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r31,r11,64
	r31.s64 = r11.s64 + 64;
	// lwz r8,2128(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 2128);
	// stb r9,2127(r11)
	PPC_STORE_U8(r11.u32 + 2127, ctx.r9.u8);
	// ori r7,r8,32768
	ctx.r7.u64 = ctx.r8.u64 | 32768;
	// stw r7,2128(r11)
	PPC_STORE_U32(r11.u32 + 2128, ctx.r7.u32);
loc_826994F8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823924b0
	ctx.lr = 0x82699508;
	sub_823924B0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,7
	cr6.compare<int32_t>(r30.s32, 7, xer);
	// blt cr6,0x826994f8
	if (cr6.lt) goto loc_826994F8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82699520"))) PPC_WEAK_FUNC(sub_82699520);
PPC_FUNC_IMPL(__imp__sub_82699520) {
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
	ctx.lr = 0x82699528;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699540;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r31,0
	r31.s64 = 0;
	// addi r30,r28,21628
	r30.s64 = r28.s64 + 21628;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r29,r11,64
	r29.s64 = r11.s64 + 64;
	// lbz r9,2127(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 2127);
	// stb r9,21660(r28)
	PPC_STORE_U8(r28.u32 + 21660, ctx.r9.u8);
loc_8269955C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82392460
	ctx.lr = 0x82699568;
	sub_82392460(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,7
	cr6.compare<int32_t>(r31.s32, 7, xer);
	// blt cr6,0x8269955c
	if (cr6.lt) goto loc_8269955C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82699584"))) PPC_WEAK_FUNC(sub_82699584);
PPC_FUNC_IMPL(__imp__sub_82699584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82699588"))) PPC_WEAK_FUNC(sub_82699588);
PPC_FUNC_IMPL(__imp__sub_82699588) {
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
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,1
	r11.s64 = 1;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,-29341(r10)
	PPC_STORE_U8(ctx.r10.u32 + -29341, r11.u8);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,17268(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826995C0;
	sub_822A3998(ctx, base);
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,132(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// lwz r11,1664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1664);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x826995d8
	if (!cr6.lt) goto loc_826995D8;
	// li r11,1
	r11.s64 = 1;
loc_826995D8:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lwz r10,1668(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1668);
	// stw r10,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82699600"))) PPC_WEAK_FUNC(sub_82699600);
PPC_FUNC_IMPL(__imp__sub_82699600) {
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
	ctx.lr = 0x82699608;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699624;
	sub_822A3998(ctx, base);
	// srawi r10,r30,16
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = r30.s32 >> 16;
	// srawi r9,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r9.s64 = r30.s32 >> 8;
	// clrlwi r6,r30,24
	ctx.r6.u64 = r30.u32 & 0xFF;
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,15364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15364);
	f0.f64 = double(temp.f32);
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// addi r29,r11,64
	r29.s64 = r11.s64 + 64;
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fmuls f5,f8,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f5,96(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f4,f7,f0
	ctx.f4.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f4,104(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmuls f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f3,100(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x8261e440
	ctx.lr = 0x826996A0;
	sub_8261E440(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x826996b8
	if (cr6.eq) goto loc_826996B8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261e4f8
	ctx.lr = 0x826996B8;
	sub_8261E4F8(ctx, base);
loc_826996B8:
	// lis r11,0
	r11.s64 = 0;
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// ori r10,r11,39356
	ctx.r10.u64 = r11.u64 | 39356;
	// addi r30,r30,-26276
	r30.s64 = r30.s64 + -26276;
	// addi r28,r28,-26280
	r28.s64 = r28.s64 + -26280;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r5,r31,r10
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// bl 0x82391ff8
	ctx.lr = 0x826996E8;
	sub_82391FF8(ctx, base);
	// lbz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82699704
	if (!cr6.eq) goto loc_82699704;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391fb8
	ctx.lr = 0x82699704;
	sub_82391FB8(ctx, base);
loc_82699704:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269970C"))) PPC_WEAK_FUNC(sub_8269970C);
PPC_FUNC_IMPL(__imp__sub_8269970C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82699710"))) PPC_WEAK_FUNC(sub_82699710);
PPC_FUNC_IMPL(__imp__sub_82699710) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82699740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r9,r9,57668
	ctx.r9.u64 = ctx.r9.u64 | 57668;
	// ori r8,r8,57664
	ctx.r8.u64 = ctx.r8.u64 | 57664;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-28660
	ctx.r4.s64 = ctx.r7.s64 + -28660;
	// stwx r3,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r30,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r30.u32);
	// bl 0x8268da78
	ctx.lr = 0x8269976C;
	sub_8268DA78(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// bl 0x82699600
	ctx.lr = 0x8269977C;
	sub_82699600(ctx, base);
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

__attribute__((alias("__imp__sub_82699794"))) PPC_WEAK_FUNC(sub_82699794);
PPC_FUNC_IMPL(__imp__sub_82699794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82699798"))) PPC_WEAK_FUNC(sub_82699798);
PPC_FUNC_IMPL(__imp__sub_82699798) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826997BC;
	sub_822A3998(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r8,1
	ctx.r8.s64 = 1;
	// ori r7,r10,57712
	ctx.r7.u64 = ctx.r10.u64 | 57712;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// ori r5,r6,57696
	ctx.r5.u64 = ctx.r6.u64 | 57696;
	// stwx r8,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r8.u32);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r4,r31,r5
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	// bl 0x82392538
	ctx.lr = 0x826997E8;
	sub_82392538(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826997FC"))) PPC_WEAK_FUNC(sub_826997FC);
PPC_FUNC_IMPL(__imp__sub_826997FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82699800"))) PPC_WEAK_FUNC(sub_82699800);
PPC_FUNC_IMPL(__imp__sub_82699800) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699824;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,57692
	ctx.r7.u64 = ctx.r9.u64 | 57692;
	// ori r6,r8,57696
	ctx.r6.u64 = ctx.r8.u64 | 57696;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r5,r31,r7
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lwzx r4,r31,r6
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// bl 0x82393118
	ctx.lr = 0x8269984C;
	sub_82393118(ctx, base);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r11,-7864
	r11.s64 = r11.s64 + -7864;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82699860:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82699860
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82699860;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82699888"))) PPC_WEAK_FUNC(sub_82699888);
PPC_FUNC_IMPL(__imp__sub_82699888) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826998AC;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r31,0
	r31.s64 = 0;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r30,r11,64
	r30.s64 = r11.s64 + 64;
loc_826998BC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823931c0
	ctx.lr = 0x826998C8;
	sub_823931C0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x826998f8
	if (cr6.gt) goto loc_826998F8;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,5
	cr6.compare<int32_t>(r31.s32, 5, xer);
	// blt cr6,0x826998bc
	if (cr6.lt) goto loc_826998BC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_826998E0:
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
loc_826998F8:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x826998e0
	goto loc_826998E0;
}

__attribute__((alias("__imp__sub_82699900"))) PPC_WEAK_FUNC(sub_82699900);
PPC_FUNC_IMPL(__imp__sub_82699900) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269992C;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// blt cr6,0x82699958
	if (cr6.lt) goto loc_82699958;
	// beq cr6,0x82699950
	if (cr6.eq) goto loc_82699950;
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// bge cr6,0x8269995c
	if (!cr6.lt) goto loc_8269995C;
	// stw r30,384(r11)
	PPC_STORE_U32(r11.u32 + 384, r30.u32);
	// b 0x8269995c
	goto loc_8269995C;
loc_82699950:
	// stw r30,380(r11)
	PPC_STORE_U32(r11.u32 + 380, r30.u32);
	// b 0x8269995c
	goto loc_8269995C;
loc_82699958:
	// stw r30,376(r11)
	PPC_STORE_U32(r11.u32 + 376, r30.u32);
loc_8269995C:
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

__attribute__((alias("__imp__sub_82699974"))) PPC_WEAK_FUNC(sub_82699974);
PPC_FUNC_IMPL(__imp__sub_82699974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82699978"))) PPC_WEAK_FUNC(sub_82699978);
PPC_FUNC_IMPL(__imp__sub_82699978) {
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
	ctx.lr = 0x82699980;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269999C;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r30,r11,64
	r30.s64 = r11.s64 + 64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82392558
	ctx.lr = 0x826999B4;
	sub_82392558(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82699a04
	if (cr6.eq) goto loc_82699A04;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826999d8
	if (cr6.eq) goto loc_826999D8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,-28568
	ctx.r4.s64 = r11.s64 + -28568;
	// b 0x826999e0
	goto loc_826999E0;
loc_826999D8:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,2656
	ctx.r4.s64 = r11.s64 + 2656;
loc_826999E0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-28588
	ctx.r3.s64 = r11.s64 + -28588;
	// bl 0x82130000
	ctx.lr = 0x826999EC;
	sub_82130000(ctx, base);
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82699a50
	if (!cr6.eq) goto loc_82699A50;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-28608
	ctx.r3.s64 = r11.s64 + -28608;
	// b 0x82699a40
	goto loc_82699A40;
loc_82699A04:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82699a18
	if (cr6.eq) goto loc_82699A18;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,-28568
	ctx.r4.s64 = r11.s64 + -28568;
	// b 0x82699a20
	goto loc_82699A20;
loc_82699A18:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,2656
	ctx.r4.s64 = r11.s64 + 2656;
loc_82699A20:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-28628
	ctx.r3.s64 = r11.s64 + -28628;
	// bl 0x82130000
	ctx.lr = 0x82699A2C;
	sub_82130000(ctx, base);
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82699a50
	if (cr6.eq) goto loc_82699A50;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-28648
	ctx.r3.s64 = r11.s64 + -28648;
loc_82699A40:
	// bl 0x82130000
	ctx.lr = 0x82699A44;
	sub_82130000(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82392590
	ctx.lr = 0x82699A50;
	sub_82392590(ctx, base);
loc_82699A50:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82699A58"))) PPC_WEAK_FUNC(sub_82699A58);
PPC_FUNC_IMPL(__imp__sub_82699A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f29.u64);
	// stfd f30,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28660
	ctx.r4.s64 = r11.s64 + -28660;
	// bl 0x8268da78
	ctx.lr = 0x82699A8C;
	sub_8268DA78(ctx, base);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// srawi r8,r10,16
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 16;
	// srawi r7,r10,8
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 8;
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lwz r3,17268(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17268);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// li r4,0
	ctx.r4.s64 = 0;
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// lfs f0,15364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15364);
	f0.f64 = double(temp.f32);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fmuls f31,f8,f0
	f31.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmuls f29,f7,f0
	f29.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fmuls f30,f6,f0
	f30.f64 = double(float(ctx.f6.f64 * f0.f64));
	// bl 0x822a3998
	ctx.lr = 0x82699AF8;
	sub_822A3998(ctx, base);
	// lwz r7,48(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r10,r31,-2
	ctx.r10.s64 = r31.s64 + -2;
	// cmplwi cr6,r10,19
	cr6.compare<uint32_t>(ctx.r10.u32, 19, xer);
	// lwz r11,132(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 132);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bgt cr6,0x82699c4c
	if (cr6.gt) goto loc_82699C4C;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-25816
	r12.s64 = r12.s64 + -25816;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_82699B98;
	case 1:
		goto loc_82699BA8;
	case 2:
		goto loc_82699BB8;
	case 3:
		goto loc_82699C4C;
	case 4:
		goto loc_82699C4C;
	case 5:
		goto loc_82699BC8;
	case 6:
		goto loc_82699BD8;
	case 7:
		goto loc_82699BE8;
	case 8:
		goto loc_82699BF8;
	case 9:
		goto loc_82699C08;
	case 10:
		goto loc_82699C18;
	case 11:
		goto loc_82699C28;
	case 12:
		goto loc_82699C38;
	case 13:
		goto loc_82699C4C;
	case 14:
		goto loc_82699C4C;
	case 15:
		goto loc_82699C4C;
	case 16:
		goto loc_82699C4C;
	case 17:
		goto loc_82699C4C;
	case 18:
		goto loc_82699B78;
	case 19:
		goto loc_82699B88;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-25704(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25704);
	// lwz r19,-25688(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25688);
	// lwz r19,-25672(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25672);
	// lwz r19,-25524(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25524);
	// lwz r19,-25524(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25524);
	// lwz r19,-25656(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25656);
	// lwz r19,-25640(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25640);
	// lwz r19,-25624(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25624);
	// lwz r19,-25608(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25608);
	// lwz r19,-25592(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25592);
	// lwz r19,-25576(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25576);
	// lwz r19,-25560(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25560);
	// lwz r19,-25544(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25544);
	// lwz r19,-25524(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25524);
	// lwz r19,-25524(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25524);
	// lwz r19,-25524(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25524);
	// lwz r19,-25524(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25524);
	// lwz r19,-25524(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25524);
	// lwz r19,-25736(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25736);
	// lwz r19,-25720(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25720);
loc_82699B78:
	// stfs f31,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stfs f30,20(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stfs f29,24(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699B88:
	// stfs f31,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// stfs f30,36(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// stfs f29,40(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699B98:
	// stfs f31,80(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 80, temp.u32);
	// stfs f30,84(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 84, temp.u32);
	// stfs f29,88(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 88, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699BA8:
	// stfs f31,96(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 96, temp.u32);
	// stfs f30,100(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 100, temp.u32);
	// stfs f29,104(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 104, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699BB8:
	// stfs f31,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f30,116(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f29,120(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699BC8:
	// stfs f31,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 48, temp.u32);
	// stfs f30,52(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
	// stfs f29,56(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699BD8:
	// stfs f31,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// stfs f30,68(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// stfs f29,72(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 72, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699BE8:
	// stfs f31,1408(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 1408, temp.u32);
	// stfs f30,1412(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 1412, temp.u32);
	// stfs f29,1416(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 1416, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699BF8:
	// stfs f31,1424(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 1424, temp.u32);
	// stfs f30,1428(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 1428, temp.u32);
	// stfs f29,1432(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 1432, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699C08:
	// stfs f31,1440(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 1440, temp.u32);
	// stfs f30,1444(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 1444, temp.u32);
	// stfs f29,1448(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 1448, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699C18:
	// stfs f31,1456(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 1456, temp.u32);
	// stfs f30,1460(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 1460, temp.u32);
	// stfs f29,1464(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 1464, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699C28:
	// stfs f31,1472(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 1472, temp.u32);
	// stfs f30,1476(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 1476, temp.u32);
	// stfs f29,1480(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 1480, temp.u32);
	// b 0x82699c4c
	goto loc_82699C4C;
loc_82699C38:
	// lfs f0,300(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 300);
	f0.f64 = double(temp.f32);
	// stfs f31,288(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 288, temp.u32);
	// stfs f30,292(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 292, temp.u32);
	// stfs f29,296(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 296, temp.u32);
	// stfs f0,300(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 300, temp.u32);
loc_82699C4C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f30,-32(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82699C6C"))) PPC_WEAK_FUNC(sub_82699C6C);
PPC_FUNC_IMPL(__imp__sub_82699C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82699C70"))) PPC_WEAK_FUNC(sub_82699C70);
PPC_FUNC_IMPL(__imp__sub_82699C70) {
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
	ctx.lr = 0x82699C78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r3,21696
	r30.s64 = ctx.r3.s64 + 21696;
	// li r27,1
	r27.s64 = 1;
	// addi r29,r11,-28660
	r29.s64 = r11.s64 + -28660;
loc_82699C94:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x82699CA0;
	sub_8268DCB0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268da78
	ctx.lr = 0x82699CAC;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82699cc0
	if (cr6.eq) goto loc_82699CC0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_82699CC0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,40
	cr6.compare<int32_t>(r31.s32, 40, xer);
	// blt cr6,0x82699c94
	if (cr6.lt) goto loc_82699C94;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82699CD8"))) PPC_WEAK_FUNC(sub_82699CD8);
PPC_FUNC_IMPL(__imp__sub_82699CD8) {
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
	ctx.lr = 0x82699CE0;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82699D00;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,57692
	ctx.r7.u64 = ctx.r9.u64 | 57692;
	// ori r6,r8,57696
	ctx.r6.u64 = ctx.r8.u64 | 57696;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r5,r31,r7
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lwzx r4,r31,r6
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// bl 0x82393118
	ctx.lr = 0x82699D28;
	sub_82393118(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x821d2578
	ctx.lr = 0x82699D38;
	sub_821D2578(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f8,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f8.f64 = double(temp.f32);
	// addi r29,r31,21696
	r29.s64 = r31.s64 + 21696;
	// lfs f0,15360(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 15360);
	f0.f64 = double(temp.f32);
	// mr r27,r30
	r27.u64 = r30.u64;
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f31,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f31.f64 = double(temp.f32);
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f7,120(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f6,124(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stw r30,21664(r31)
	PPC_STORE_U32(r31.u32 + 21664, r30.u32);
	// li r24,1
	r24.s64 = 1;
	// addi r25,r11,-28660
	r25.s64 = r11.s64 + -28660;
loc_82699D94:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x82699DA0;
	sub_8268DCB0(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x8268da78
	ctx.lr = 0x82699DB0;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82699dc8
	if (cr6.eq) goto loc_82699DC8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r24,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r24.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r27,0(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_82699DC8:
	// srawi r11,r27,16
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0xFFFF) != 0);
	r11.s64 = r27.s32 >> 16;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f31
	cr6.compare(ctx.f9.f64, f31.f64);
	// bge cr6,0x82699e4c
	if (!cr6.lt) goto loc_82699E4C;
	// srawi r11,r27,8
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0xFF) != 0);
	r11.s64 = r27.s32 >> 8;
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f31
	cr6.compare(ctx.f9.f64, f31.f64);
	// bge cr6,0x82699e4c
	if (!cr6.lt) goto loc_82699E4C;
	// clrlwi r10,r27,24
	ctx.r10.u64 = r27.u32 & 0xFF;
	// lfs f0,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f31
	cr6.compare(ctx.f9.f64, f31.f64);
	// bge cr6,0x82699e4c
	if (!cr6.lt) goto loc_82699E4C;
	// stw r28,21664(r31)
	PPC_STORE_U32(r31.u32 + 21664, r28.u32);
loc_82699E4C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,40
	cr6.compare<int32_t>(r30.s32, 40, xer);
	// blt cr6,0x82699d94
	if (cr6.lt) goto loc_82699D94;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82699E68"))) PPC_WEAK_FUNC(sub_82699E68);
PPC_FUNC_IMPL(__imp__sub_82699E68) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-28532
	ctx.r4.s64 = r11.s64 + -28532;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268da78
	ctx.lr = 0x82699E98;
	sub_8268DA78(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,336(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 336);
	// lwz r30,4(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82699EB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// mulli r6,r30,1000
	ctx.r6.s64 = r30.s64 * 1000;
	// lwz r11,17268(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17268);
	// add r30,r3,r6
	r30.u64 = ctx.r3.u64 + ctx.r6.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822a3998
	ctx.lr = 0x82699ED0;
	sub_822A3998(ctx, base);
	// lwz r5,48(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r10,r4,57692
	ctx.r10.u64 = ctx.r4.u64 | 57692;
	// ori r9,r3,57696
	ctx.r9.u64 = ctx.r3.u64 | 57696;
	// lwz r11,132(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r5,r31,r10
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// lwzx r4,r31,r9
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// bl 0x82393118
	ctx.lr = 0x82699EF8;
	sub_82393118(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r5,-28556
	ctx.r3.s64 = ctx.r5.s64 + -28556;
	// stb r6,19(r8)
	PPC_STORE_U8(ctx.r8.u32 + 19, ctx.r6.u8);
	// sth r30,16(r8)
	PPC_STORE_U16(ctx.r8.u32 + 16, r30.u16);
	// bl 0x82130000
	ctx.lr = 0x82699F18;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_82699F34"))) PPC_WEAK_FUNC(sub_82699F34);
PPC_FUNC_IMPL(__imp__sub_82699F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82699F38"))) PPC_WEAK_FUNC(sub_82699F38);
PPC_FUNC_IMPL(__imp__sub_82699F38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,-28392
	r11.s64 = r11.s64 + -28392;
loc_82699F48:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x82699f6c
	if (cr6.eq) goto loc_82699F6C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699f48
	if (cr6.eq) goto loc_82699F48;
loc_82699F6C:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x82699f7c
	if (!cr6.eq) goto loc_82699F7C;
loc_82699F74:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82699F7C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,-28412
	r11.s64 = r11.s64 + -28412;
loc_82699F88:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x82699fac
	if (cr6.eq) goto loc_82699FAC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699f88
	if (cr6.eq) goto loc_82699F88;
loc_82699FAC:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699f74
	if (cr6.eq) goto loc_82699F74;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,-28432
	r11.s64 = r11.s64 + -28432;
loc_82699FC0:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x82699fe4
	if (cr6.eq) goto loc_82699FE4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699fc0
	if (cr6.eq) goto loc_82699FC0;
loc_82699FE4:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699f74
	if (cr6.eq) goto loc_82699F74;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,24484
	r11.s64 = r11.s64 + 24484;
loc_82699FF8:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x8269a01c
	if (cr6.eq) goto loc_8269A01C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699ff8
	if (cr6.eq) goto loc_82699FF8;
loc_8269A01C:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699f74
	if (cr6.eq) goto loc_82699F74;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,-28448
	r11.s64 = r11.s64 + -28448;
loc_8269A030:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x8269a054
	if (cr6.eq) goto loc_8269A054;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8269a030
	if (cr6.eq) goto loc_8269A030;
loc_8269A054:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699f74
	if (cr6.eq) goto loc_82699F74;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,-28464
	r11.s64 = r11.s64 + -28464;
loc_8269A068:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x8269a08c
	if (cr6.eq) goto loc_8269A08C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8269a068
	if (cr6.eq) goto loc_8269A068;
loc_8269A08C:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699f74
	if (cr6.eq) goto loc_82699F74;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,-28488
	r11.s64 = r11.s64 + -28488;
loc_8269A0A0:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x8269a0c4
	if (cr6.eq) goto loc_8269A0C4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8269a0a0
	if (cr6.eq) goto loc_8269A0A0;
loc_8269A0C4:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699f74
	if (cr6.eq) goto loc_82699F74;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,-28504
	r11.s64 = r11.s64 + -28504;
loc_8269A0D8:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x8269a0fc
	if (cr6.eq) goto loc_8269A0FC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8269a0d8
	if (cr6.eq) goto loc_8269A0D8;
loc_8269A0FC:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82699f74
	if (cr6.eq) goto loc_82699F74;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r11,r11,-28524
	r11.s64 = r11.s64 + -28524;
loc_8269A10C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8269a130
	if (cr6.eq) goto loc_8269A130;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8269a10c
	if (cr6.eq) goto loc_8269A10C;
loc_8269A130:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269A13C"))) PPC_WEAK_FUNC(sub_8269A13C);
PPC_FUNC_IMPL(__imp__sub_8269A13C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269A140"))) PPC_WEAK_FUNC(sub_8269A140);
PPC_FUNC_IMPL(__imp__sub_8269A140) {
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
	ctx.lr = 0x8269A148;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82387b90
	ctx.lr = 0x8269A154;
	sub_82387B90(ctx, base);
	// lwz r11,1340(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8269a194
	if (!cr6.gt) goto loc_8269A194;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_8269A16C:
	// bl 0x82387b90
	ctx.lr = 0x8269A170;
	sub_82387B90(ctx, base);
	// add r11,r31,r3
	r11.u64 = r31.u64 + ctx.r3.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238f1e8
	ctx.lr = 0x8269A17C;
	sub_8238F1E8(ctx, base);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// bne cr6,0x8269a188
	if (!cr6.eq) goto loc_8269A188;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_8269A188:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8176
	r31.s64 = r31.s64 + 8176;
	// bne 0x8269a16c
	if (!cr0.eq) goto loc_8269A16C;
loc_8269A194:
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269A1A8"))) PPC_WEAK_FUNC(sub_8269A1A8);
PPC_FUNC_IMPL(__imp__sub_8269A1A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,21680(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 21680);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269A1B0"))) PPC_WEAK_FUNC(sub_8269A1B0);
PPC_FUNC_IMPL(__imp__sub_8269A1B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-29340(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// lwz r11,21680(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21680);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8269a1d4
	if (cr6.eq) goto loc_8269A1D4;
	// lbz r11,16(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8269a1d8
	if (!cr6.eq) goto loc_8269A1D8;
loc_8269A1D4:
	// li r11,0
	r11.s64 = 0;
loc_8269A1D8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269A1E0"))) PPC_WEAK_FUNC(sub_8269A1E0);
PPC_FUNC_IMPL(__imp__sub_8269A1E0) {
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
	ctx.lr = 0x8269A1E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269A204;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,52(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8269a230
	if (cr6.eq) goto loc_8269A230;
	// bl 0x8238f1e8
	ctx.lr = 0x8269A218;
	sub_8238F1E8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238f1e8
	ctx.lr = 0x8269A224;
	sub_8238F1E8(ctx, base);
	// cmpw cr6,r28,r3
	cr6.compare<int32_t>(r28.s32, ctx.r3.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8269a234
	if (cr6.eq) goto loc_8269A234;
loc_8269A230:
	// li r11,0
	r11.s64 = 0;
loc_8269A234:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269a244
	if (cr6.eq) goto loc_8269A244;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
loc_8269A244:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822aae48
	ctx.lr = 0x8269A250;
	sub_822AAE48(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269a278
	if (!cr6.eq) goto loc_8269A278;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-29340(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// lwz r10,21680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 21680);
	// lbz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8269a284
	if (cr6.eq) goto loc_8269A284;
loc_8269A278:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,1
	r11.s64 = 1;
	// stw r11,-29336(r10)
	PPC_STORE_U32(ctx.r10.u32 + -29336, r11.u32);
loc_8269A284:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269A28C"))) PPC_WEAK_FUNC(sub_8269A28C);
PPC_FUNC_IMPL(__imp__sub_8269A28C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269A290"))) PPC_WEAK_FUNC(sub_8269A290);
PPC_FUNC_IMPL(__imp__sub_8269A290) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8269A298;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r21,8
	r21.s64 = 8;
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// bne cr6,0x8269a2b4
	if (!cr6.eq) goto loc_8269A2B4;
	// li r21,7
	r21.s64 = 7;
	// b 0x8269a2c0
	goto loc_8269A2C0;
loc_8269A2B4:
	// cmpwi cr6,r5,2
	cr6.compare<int32_t>(ctx.r5.s32, 2, xer);
	// bne cr6,0x8269a2c0
	if (!cr6.eq) goto loc_8269A2C0;
	// li r21,9
	r21.s64 = 9;
loc_8269A2C0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269A2D0;
	sub_822A3998(ctx, base);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238f1e8
	ctx.lr = 0x8269A2D8;
	sub_8238F1E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8269A2E0;
	sub_82387B90(ctx, base);
	// mulli r9,r31,84
	ctx.r9.s64 = r31.s64 * 84;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,324(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
	// add r7,r3,r9
	ctx.r7.u64 = ctx.r3.u64 + ctx.r9.u64;
	// li r20,0
	r20.s64 = 0;
	// addis r23,r7,4
	r23.s64 = ctx.r7.s64 + 262144;
	// mr r27,r20
	r27.u64 = r20.u64;
	// addi r23,r23,-15504
	r23.s64 = r23.s64 + -15504;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8269A30C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269a3f8
	if (cr6.eq) goto loc_8269A3F8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r24,1
	r24.s64 = 1;
	// lis r22,-32111
	r22.s64 = -2104426496;
	// addi r25,r11,-28368
	r25.s64 = r11.s64 + -28368;
	// addi r29,r10,-19624
	r29.s64 = ctx.r10.s64 + -19624;
	// addi r26,r9,-2176
	r26.s64 = ctx.r9.s64 + -2176;
loc_8269A334:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x8269A340;
	sub_8268DCB0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8268da78
	ctx.lr = 0x8269A350;
	sub_8268DA78(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823901c0
	ctx.lr = 0x8269A364;
	sub_823901C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269a3b8
	if (!cr6.eq) goto loc_8269A3B8;
	// lbz r11,-29346(r22)
	r11.u64 = PPC_LOAD_U8(r22.u32 + -29346);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269a3b8
	if (!cr6.eq) goto loc_8269A3B8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8269A38C;
	sub_8268DA78(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8269A3A0;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8269a3d8
	if (cr6.eq) goto loc_8269A3D8;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r24,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r24.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// b 0x8269a3d8
	goto loc_8269A3D8;
loc_8269A3B8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8269A3C8;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269a3d8
	if (cr6.eq) goto loc_8269A3D8;
	// stw r20,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r20.u32);
	// stw r24,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r24.u32);
loc_8269A3D8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,324(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 324);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269A3F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r27,r3
	cr6.compare<uint32_t>(r27.u32, ctx.r3.u32, xer);
	// blt cr6,0x8269a334
	if (cr6.lt) goto loc_8269A334;
loc_8269A3F8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8269A400"))) PPC_WEAK_FUNC(sub_8269A400);
PPC_FUNC_IMPL(__imp__sub_8269A400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r19{};
	// cmplwi cr6,r4,48
	cr6.compare<uint32_t>(ctx.r4.u32, 48, xer);
	// bgt cr6,0x8269a5e4
	if (cr6.gt) goto loc_8269A5E4;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-23520
	r12.s64 = r12.s64 + -23520;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8269A4E4;
	case 1:
		goto loc_8269A4EC;
	case 2:
		goto loc_8269A4F4;
	case 3:
		goto loc_8269A4FC;
	case 4:
		goto loc_8269A504;
	case 5:
		goto loc_8269A50C;
	case 6:
		goto loc_8269A514;
	case 7:
		goto loc_8269A51C;
	case 8:
		goto loc_8269A524;
	case 9:
		goto loc_8269A52C;
	case 10:
		goto loc_8269A534;
	case 11:
		goto loc_8269A53C;
	case 12:
		goto loc_8269A544;
	case 13:
		goto loc_8269A54C;
	case 14:
		goto loc_8269A554;
	case 15:
		goto loc_8269A55C;
	case 16:
		goto loc_8269A564;
	case 17:
		goto loc_8269A56C;
	case 18:
		goto loc_8269A574;
	case 19:
		goto loc_8269A57C;
	case 20:
		goto loc_8269A584;
	case 21:
		goto loc_8269A58C;
	case 22:
		goto loc_8269A594;
	case 23:
		goto loc_8269A59C;
	case 24:
		goto loc_8269A5A4;
	case 25:
		goto loc_8269A5AC;
	case 26:
		goto loc_8269A5B4;
	case 27:
		goto loc_8269A5BC;
	case 28:
		goto loc_8269A5C4;
	case 29:
		goto loc_8269A5CC;
	case 30:
		goto loc_8269A5E4;
	case 31:
		goto loc_8269A5E4;
	case 32:
		goto loc_8269A5E4;
	case 33:
		goto loc_8269A5E4;
	case 34:
		goto loc_8269A5D4;
	case 35:
		goto loc_8269A5E4;
	case 36:
		goto loc_8269A5E4;
	case 37:
		goto loc_8269A5E4;
	case 38:
		goto loc_8269A5E4;
	case 39:
		goto loc_8269A5E4;
	case 40:
		goto loc_8269A5E4;
	case 41:
		goto loc_8269A5E4;
	case 42:
		goto loc_8269A5E4;
	case 43:
		goto loc_8269A5E4;
	case 44:
		goto loc_8269A5E4;
	case 45:
		goto loc_8269A5E4;
	case 46:
		goto loc_8269A5E4;
	case 47:
		goto loc_8269A5DC;
	case 48:
		goto loc_8269A5E4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-23324(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23324);
	// lwz r19,-23316(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23316);
	// lwz r19,-23308(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23308);
	// lwz r19,-23300(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23300);
	// lwz r19,-23292(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23292);
	// lwz r19,-23284(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23284);
	// lwz r19,-23276(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23276);
	// lwz r19,-23268(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23268);
	// lwz r19,-23260(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23260);
	// lwz r19,-23252(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23252);
	// lwz r19,-23244(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23244);
	// lwz r19,-23236(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23236);
	// lwz r19,-23228(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23228);
	// lwz r19,-23220(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23220);
	// lwz r19,-23212(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23212);
	// lwz r19,-23204(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23204);
	// lwz r19,-23196(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23196);
	// lwz r19,-23188(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23188);
	// lwz r19,-23180(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23180);
	// lwz r19,-23172(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23172);
	// lwz r19,-23164(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23164);
	// lwz r19,-23156(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23156);
	// lwz r19,-23148(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23148);
	// lwz r19,-23140(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23140);
	// lwz r19,-23132(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23132);
	// lwz r19,-23124(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23124);
	// lwz r19,-23116(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23116);
	// lwz r19,-23108(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23108);
	// lwz r19,-23100(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23100);
	// lwz r19,-23092(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23092);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23084(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23084);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
	// lwz r19,-23076(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23076);
	// lwz r19,-23068(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23068);
loc_8269A4E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8269A4EC:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8269A4F4:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8269A4FC:
	// li r3,6
	ctx.r3.s64 = 6;
	// blr 
	return;
loc_8269A504:
	// li r3,7
	ctx.r3.s64 = 7;
	// blr 
	return;
loc_8269A50C:
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_8269A514:
	// li r3,9
	ctx.r3.s64 = 9;
	// blr 
	return;
loc_8269A51C:
	// li r3,11
	ctx.r3.s64 = 11;
	// blr 
	return;
loc_8269A524:
	// li r3,12
	ctx.r3.s64 = 12;
	// blr 
	return;
loc_8269A52C:
	// li r3,14
	ctx.r3.s64 = 14;
	// blr 
	return;
loc_8269A534:
	// li r3,15
	ctx.r3.s64 = 15;
	// blr 
	return;
loc_8269A53C:
	// li r3,16
	ctx.r3.s64 = 16;
	// blr 
	return;
loc_8269A544:
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_8269A54C:
	// li r3,17
	ctx.r3.s64 = 17;
	// blr 
	return;
loc_8269A554:
	// li r3,18
	ctx.r3.s64 = 18;
	// blr 
	return;
loc_8269A55C:
	// li r3,19
	ctx.r3.s64 = 19;
	// blr 
	return;
loc_8269A564:
	// li r3,20
	ctx.r3.s64 = 20;
	// blr 
	return;
loc_8269A56C:
	// li r3,21
	ctx.r3.s64 = 21;
	// blr 
	return;
loc_8269A574:
	// li r3,38
	ctx.r3.s64 = 38;
	// blr 
	return;
loc_8269A57C:
	// li r3,39
	ctx.r3.s64 = 39;
	// blr 
	return;
loc_8269A584:
	// li r3,40
	ctx.r3.s64 = 40;
	// blr 
	return;
loc_8269A58C:
	// li r3,41
	ctx.r3.s64 = 41;
	// blr 
	return;
loc_8269A594:
	// li r3,42
	ctx.r3.s64 = 42;
	// blr 
	return;
loc_8269A59C:
	// li r3,44
	ctx.r3.s64 = 44;
	// blr 
	return;
loc_8269A5A4:
	// li r3,45
	ctx.r3.s64 = 45;
	// blr 
	return;
loc_8269A5AC:
	// li r3,49
	ctx.r3.s64 = 49;
	// blr 
	return;
loc_8269A5B4:
	// li r3,50
	ctx.r3.s64 = 50;
	// blr 
	return;
loc_8269A5BC:
	// li r3,51
	ctx.r3.s64 = 51;
	// blr 
	return;
loc_8269A5C4:
	// li r3,52
	ctx.r3.s64 = 52;
	// blr 
	return;
loc_8269A5CC:
	// li r3,53
	ctx.r3.s64 = 53;
	// blr 
	return;
loc_8269A5D4:
	// li r3,23
	ctx.r3.s64 = 23;
	// blr 
	return;
loc_8269A5DC:
	// li r3,24
	ctx.r3.s64 = 24;
	// blr 
	return;
loc_8269A5E4:
	// li r3,-1
	ctx.r3.s64 = -1;
}

__attribute__((alias("__imp__sub_8269A5EC"))) PPC_WEAK_FUNC(sub_8269A5EC);
PPC_FUNC_IMPL(__imp__sub_8269A5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269A5F0"))) PPC_WEAK_FUNC(sub_8269A5F0);
PPC_FUNC_IMPL(__imp__sub_8269A5F0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269A614;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r11,r11,-18992
	r11.s64 = r11.s64 + -18992;
	// lwz r10,132(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r3,r10,64
	ctx.r3.s64 = ctx.r10.s64 + 64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lbz r10,2116(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2116);
	// bne cr6,0x8269a640
	if (!cr6.eq) goto loc_8269A640;
	// lwz r11,148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// b 0x8269a644
	goto loc_8269A644;
loc_8269A640:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8269A644:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8269a654
	if (cr6.eq) goto loc_8269A654;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x82391e18
	ctx.lr = 0x8269A654;
	sub_82391E18(ctx, base);
loc_8269A654:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269A668"))) PPC_WEAK_FUNC(sub_8269A668);
PPC_FUNC_IMPL(__imp__sub_8269A668) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269A68C;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r11,r11,-18840
	r11.s64 = r11.s64 + -18840;
	// lwz r10,132(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r3,r10,64
	ctx.r3.s64 = ctx.r10.s64 + 64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lbz r10,2117(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2117);
	// bne cr6,0x8269a6b8
	if (!cr6.eq) goto loc_8269A6B8;
	// lwz r11,148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// b 0x8269a6bc
	goto loc_8269A6BC;
loc_8269A6B8:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8269A6BC:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8269a6cc
	if (cr6.eq) goto loc_8269A6CC;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x82391de8
	ctx.lr = 0x8269A6CC;
	sub_82391DE8(ctx, base);
loc_8269A6CC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269A6E0"))) PPC_WEAK_FUNC(sub_8269A6E0);
PPC_FUNC_IMPL(__imp__sub_8269A6E0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269A704;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r11,r11,-18688
	r11.s64 = r11.s64 + -18688;
	// lwz r10,132(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r3,r10,64
	ctx.r3.s64 = ctx.r10.s64 + 64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lbz r10,2118(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2118);
	// bne cr6,0x8269a730
	if (!cr6.eq) goto loc_8269A730;
	// lwz r11,148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// b 0x8269a734
	goto loc_8269A734;
loc_8269A730:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8269A734:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8269a744
	if (cr6.eq) goto loc_8269A744;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x82391e00
	ctx.lr = 0x8269A744;
	sub_82391E00(ctx, base);
loc_8269A744:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269A758"))) PPC_WEAK_FUNC(sub_8269A758);
PPC_FUNC_IMPL(__imp__sub_8269A758) {
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
	ctx.lr = 0x8269A760;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addis r26,r31,1
	r26.s64 = r31.s64 + 65536;
	// addi r26,r26,-26012
	r26.s64 = r26.s64 + -26012;
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x8269a400
	ctx.lr = 0x8269A778;
	sub_8269A400(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269A78C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// addi r25,r11,64
	r25.s64 = r11.s64 + 64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82391f48
	ctx.lr = 0x8269A7A4;
	sub_82391F48(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r22,1
	r22.s64 = 1;
	// cmpwi cr6,r23,49
	cr6.compare<int32_t>(r23.s32, 49, xer);
	// bne cr6,0x8269a7d0
	if (!cr6.eq) goto loc_8269A7D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269A7C0;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r22,2158(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2158, r22.u8);
	// b 0x8269a7f0
	goto loc_8269A7F0;
loc_8269A7D0:
	// cmpwi cr6,r23,11
	cr6.compare<int32_t>(r23.s32, 11, xer);
	// bne cr6,0x8269a7f0
	if (!cr6.eq) goto loc_8269A7F0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269A7E4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r22,2162(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2162, r22.u8);
loc_8269A7F0:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// mulli r11,r10,152
	r11.s64 = ctx.r10.s64 * 152;
	// ori r7,r9,41984
	ctx.r7.u64 = ctx.r9.u64 | 41984;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lis r6,0
	ctx.r6.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// ori r27,r8,42128
	r27.u64 = ctx.r8.u64 | 42128;
	// ori r28,r6,42132
	r28.u64 = ctx.r6.u64 | 42132;
	// lbzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8269a8fc
	if (!cr6.eq) goto loc_8269A8FC;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8269a888
	if (!cr6.eq) goto loc_8269A888;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,43656
	ctx.r9.u64 = ctx.r10.u64 | 43656;
	// lbzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bne cr6,0x8269a860
	if (!cr6.eq) goto loc_8269A860;
	// lis r11,0
	r11.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// ori r10,r11,43664
	ctx.r10.u64 = r11.u64 | 43664;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r30,5
	r30.s64 = 5;
	// lwzx r5,r31,r10
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// bl 0x82391ee0
	ctx.lr = 0x8269A85C;
	sub_82391EE0(ctx, base);
	// b 0x8269a91c
	goto loc_8269A91C;
loc_8269A860:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,43804
	ctx.r9.u64 = ctx.r10.u64 | 43804;
	// lwzx r5,r31,r9
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8269a8ec
	if (!cr6.gt) goto loc_8269A8EC;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r30,5
	r30.s64 = 5;
	// bl 0x82391ee0
	ctx.lr = 0x8269A884;
	sub_82391EE0(ctx, base);
	// b 0x8269a91c
	goto loc_8269A91C;
loc_8269A888:
	// cmpwi cr6,r10,11
	cr6.compare<int32_t>(ctx.r10.s32, 11, xer);
	// bne cr6,0x8269a8f4
	if (!cr6.eq) goto loc_8269A8F4;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,42136
	ctx.r9.u64 = ctx.r10.u64 | 42136;
	// lbzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bne cr6,0x8269a8c4
	if (!cr6.eq) goto loc_8269A8C4;
	// lis r11,0
	r11.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// ori r10,r11,42144
	ctx.r10.u64 = r11.u64 | 42144;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r30,r24
	r30.u64 = r24.u64;
	// lwzx r5,r31,r10
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// bl 0x82391ee0
	ctx.lr = 0x8269A8C0;
	sub_82391EE0(ctx, base);
	// b 0x8269a91c
	goto loc_8269A91C;
loc_8269A8C4:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,42284
	ctx.r9.u64 = ctx.r10.u64 | 42284;
	// lwzx r5,r31,r9
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// cmpwi cr6,r5,5
	cr6.compare<int32_t>(ctx.r5.s32, 5, xer);
	// beq cr6,0x8269a8ec
	if (cr6.eq) goto loc_8269A8EC;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r30,r24
	r30.u64 = r24.u64;
	// bl 0x82391ee0
	ctx.lr = 0x8269A8E8;
	sub_82391EE0(ctx, base);
	// b 0x8269a91c
	goto loc_8269A91C;
loc_8269A8EC:
	// lwzx r30,r11,r28
	r30.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// b 0x8269a91c
	goto loc_8269A91C;
loc_8269A8F4:
	// lwzx r30,r11,r28
	r30.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// b 0x8269a908
	goto loc_8269A908;
loc_8269A8FC:
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r8,r9,41992
	ctx.r8.u64 = ctx.r9.u64 | 41992;
	// lwzx r30,r11,r8
	r30.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
loc_8269A908:
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// bne cr6,0x8269a91c
	if (!cr6.eq) goto loc_8269A91C;
	// lwzx r11,r11,r27
	r11.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8269aa38
	if (cr6.eq) goto loc_8269AA38;
loc_8269A91C:
	// cmpwi cr6,r23,38
	cr6.compare<int32_t>(r23.s32, 38, xer);
	// bne cr6,0x8269a954
	if (!cr6.eq) goto loc_8269A954;
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r8,r11,57984
	ctx.r8.u64 = r11.u64 | 57984;
	// ori r7,r10,57856
	ctx.r7.u64 = ctx.r10.u64 | 57856;
	// ori r6,r9,57780
	ctx.r6.u64 = ctx.r9.u64 | 57780;
	// li r5,11
	ctx.r5.s64 = 11;
	// stbx r24,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r24.u8);
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// stwx r5,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r5.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_8269A954:
	// cmpwi cr6,r23,5
	cr6.compare<int32_t>(r23.s32, 5, xer);
	// bne cr6,0x8269a98c
	if (!cr6.eq) goto loc_8269A98C;
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r8,r11,57984
	ctx.r8.u64 = r11.u64 | 57984;
	// ori r7,r10,57832
	ctx.r7.u64 = ctx.r10.u64 | 57832;
	// ori r6,r9,57780
	ctx.r6.u64 = ctx.r9.u64 | 57780;
	// li r5,11
	ctx.r5.s64 = 11;
	// stbx r24,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r24.u8);
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// stwx r5,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r5.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_8269A98C:
	// cmpwi cr6,r23,24
	cr6.compare<int32_t>(r23.s32, 24, xer);
	// beq cr6,0x8269a9d8
	if (cr6.eq) goto loc_8269A9D8;
	// cmpwi cr6,r23,23
	cr6.compare<int32_t>(r23.s32, 23, xer);
	// beq cr6,0x8269a9d8
	if (cr6.eq) goto loc_8269A9D8;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// beq cr6,0x8269aa38
	if (cr6.eq) goto loc_8269AA38;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,14446
	ctx.r9.s64 = r11.s64 + 14446;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r10,57984
	ctx.r7.u64 = ctx.r10.u64 | 57984;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r5,r8,57780
	ctx.r5.u64 = ctx.r8.u64 | 57780;
	// li r4,11
	ctx.r4.s64 = 11;
	// stbx r24,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r24.u8);
	// stwx r30,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, r30.u32);
	// stwx r4,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r4.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_8269A9D8:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mulli r11,r11,152
	r11.s64 = r11.s64 * 152;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// lwzx r4,r10,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// bl 0x8269a400
	ctx.lr = 0x8269A9F0;
	sub_8269A400(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lwzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// cmpwi cr6,r3,24
	cr6.compare<int32_t>(ctx.r3.s32, 24, xer);
	// ori r6,r9,57984
	ctx.r6.u64 = ctx.r9.u64 | 57984;
	// lis r7,0
	ctx.r7.s64 = 0;
	// li r4,11
	ctx.r4.s64 = 11;
	// ori r5,r7,57780
	ctx.r5.u64 = ctx.r7.u64 | 57780;
	// stbx r24,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, r24.u8);
	// lwzx r11,r10,r27
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// addi r3,r11,14446
	ctx.r3.s64 = r11.s64 + 14446;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r8.u32);
	// stwx r4,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r4.u32);
	// bne cr6,0x8269aa34
	if (!cr6.eq) goto loc_8269AA34;
	// stb r22,2140(r25)
	PPC_STORE_U8(r25.u32 + 2140, r22.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_8269AA34:
	// stb r24,2140(r25)
	PPC_STORE_U8(r25.u32 + 2140, r24.u8);
loc_8269AA38:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8269AA40"))) PPC_WEAK_FUNC(sub_8269AA40);
PPC_FUNC_IMPL(__imp__sub_8269AA40) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,39524
	ctx.r9.u64 = ctx.r10.u64 | 39524;
	// lwz r11,-29340(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// cmpwi cr6,r8,16
	cr6.compare<int32_t>(ctx.r8.s32, 16, xer);
	// bne cr6,0x8269aadc
	if (!cr6.eq) goto loc_8269AADC;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269AA80;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8269aadc
	if (cr6.eq) goto loc_8269AADC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269AA98;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8269aadc
	if (cr6.eq) goto loc_8269AADC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269AAB4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r30,1
	r30.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r30,2150(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2150, r30.u8);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269AAD0;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// stb r30,2152(r8)
	PPC_STORE_U8(ctx.r8.u32 + 2152, r30.u8);
loc_8269AADC:
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

__attribute__((alias("__imp__sub_8269AAF4"))) PPC_WEAK_FUNC(sub_8269AAF4);
PPC_FUNC_IMPL(__imp__sub_8269AAF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269AAF8"))) PPC_WEAK_FUNC(sub_8269AAF8);
PPC_FUNC_IMPL(__imp__sub_8269AAF8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269AB20;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r30,r11,64
	r30.s64 = r11.s64 + 64;
	// beq cr6,0x8269ab40
	if (cr6.eq) goto loc_8269AB40;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-28340
	ctx.r3.s64 = r11.s64 + -28340;
	// b 0x8269ab48
	goto loc_8269AB48;
loc_8269AB40:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-28360
	ctx.r3.s64 = r11.s64 + -28360;
loc_8269AB48:
	// bl 0x821e6800
	ctx.lr = 0x8269AB4C;
	sub_821E6800(ctx, base);
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r4,r10,1
	ctx.r4.u64 = ctx.r10.u64 ^ 1;
	// bl 0x82391e60
	ctx.lr = 0x8269AB60;
	sub_82391E60(ctx, base);
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

__attribute__((alias("__imp__sub_8269AB78"))) PPC_WEAK_FUNC(sub_8269AB78);
PPC_FUNC_IMPL(__imp__sub_8269AB78) {
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
	ctx.lr = 0x8269AB80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269AB9C;
	sub_822A3998(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r4,144(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// addi r10,r11,64
	ctx.r10.s64 = r11.s64 + 64;
	// bl 0x8269a400
	ctx.lr = 0x8269ABB8;
	sub_8269A400(ctx, base);
	// cmpwi cr6,r3,38
	cr6.compare<int32_t>(ctx.r3.s32, 38, xer);
	// lis r11,0
	r11.s64 = 0;
	// bne cr6,0x8269abf8
	if (!cr6.eq) goto loc_8269ABF8;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r8,r11,57984
	ctx.r8.u64 = r11.u64 | 57984;
	// ori r7,r10,57856
	ctx.r7.u64 = ctx.r10.u64 | 57856;
	// ori r6,r9,57780
	ctx.r6.u64 = ctx.r9.u64 | 57780;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,11
	ctx.r4.s64 = 11;
	// stbx r5,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, ctx.r5.u8);
	// lwz r3,148(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// stwx r4,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8269ABF8:
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r9,r11,57984
	ctx.r9.u64 = r11.u64 | 57984;
	// bne cr6,0x8269ac34
	if (!cr6.eq) goto loc_8269AC34;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r6,r8,57832
	ctx.r6.u64 = ctx.r8.u64 | 57832;
	// ori r5,r7,57780
	ctx.r5.u64 = ctx.r7.u64 | 57780;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r4,11
	ctx.r4.s64 = 11;
	// stbx r10,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r3,148(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// stwx r4,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r4.u32);
	// stwx r3,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8269AC34:
	// li r29,0
	r29.s64 = 0;
	// ori r6,r8,57780
	ctx.r6.u64 = ctx.r8.u64 | 57780;
	// stbx r29,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r29.u8);
	// li r7,11
	ctx.r7.s64 = 11;
	// lwz r5,148(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// cmpwi cr6,r3,24
	cr6.compare<int32_t>(ctx.r3.s32, 24, xer);
	// lwz r11,144(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// addi r4,r11,14446
	ctx.r4.s64 = r11.s64 + 14446;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r5,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r5.u32);
	// stwx r7,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r7.u32);
	// bne cr6,0x8269ac74
	if (!cr6.eq) goto loc_8269AC74;
	// li r11,1
	r11.s64 = 1;
	// stb r11,2140(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2140, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8269AC74:
	// cmpwi cr6,r3,23
	cr6.compare<int32_t>(ctx.r3.s32, 23, xer);
	// bne cr6,0x8269ac88
	if (!cr6.eq) goto loc_8269AC88;
	// stb r29,2140(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2140, r29.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8269AC88:
	// cmpwi cr6,r3,16
	cr6.compare<int32_t>(ctx.r3.s32, 16, xer);
	// bne cr6,0x8269aca0
	if (!cr6.eq) goto loc_8269ACA0;
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r31,r31,-23400
	r31.s64 = r31.s64 + -23400;
	// b 0x8269acb4
	goto loc_8269ACB4;
loc_8269ACA0:
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x8269acc4
	if (!cr6.eq) goto loc_8269ACC4;
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r31,r31,-21880
	r31.s64 = r31.s64 + -21880;
loc_8269ACB4:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// bl 0x82391ee0
	ctx.lr = 0x8269ACC0;
	sub_82391EE0(ctx, base);
	// stb r29,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r29.u8);
loc_8269ACC4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8269ACCC"))) PPC_WEAK_FUNC(sub_8269ACCC);
PPC_FUNC_IMPL(__imp__sub_8269ACCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269ACD0"))) PPC_WEAK_FUNC(sub_8269ACD0);
PPC_FUNC_IMPL(__imp__sub_8269ACD0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269ACFC;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r31,30
	cr6.compare<int32_t>(r31.s32, 30, xer);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// bne cr6,0x8269ad20
	if (!cr6.eq) goto loc_8269AD20;
	// lwz r11,148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x82391e18
	ctx.lr = 0x8269AD1C;
	sub_82391E18(ctx, base);
	// b 0x8269ad4c
	goto loc_8269AD4C;
loc_8269AD20:
	// cmpwi cr6,r31,31
	cr6.compare<int32_t>(r31.s32, 31, xer);
	// bne cr6,0x8269ad38
	if (!cr6.eq) goto loc_8269AD38;
	// lwz r11,148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x82391de8
	ctx.lr = 0x8269AD34;
	sub_82391DE8(ctx, base);
	// b 0x8269ad4c
	goto loc_8269AD4C;
loc_8269AD38:
	// cmpwi cr6,r31,32
	cr6.compare<int32_t>(r31.s32, 32, xer);
	// bne cr6,0x8269ad4c
	if (!cr6.eq) goto loc_8269AD4C;
	// lwz r11,148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x82391e00
	ctx.lr = 0x8269AD4C;
	sub_82391E00(ctx, base);
loc_8269AD4C:
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

__attribute__((alias("__imp__sub_8269AD64"))) PPC_WEAK_FUNC(sub_8269AD64);
PPC_FUNC_IMPL(__imp__sub_8269AD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269AD68"))) PPC_WEAK_FUNC(sub_8269AD68);
PPC_FUNC_IMPL(__imp__sub_8269AD68) {
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
	ctx.lr = 0x8269AD70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// addi r30,r30,-26012
	r30.s64 = r30.s64 + -26012;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r4,48
	cr6.compare<int32_t>(ctx.r4.s32, 48, xer);
	// beq cr6,0x8269b024
	if (cr6.eq) goto loc_8269B024;
	// bl 0x8269a400
	ctx.lr = 0x8269AD90;
	sub_8269A400(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269ADA4;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r29,r11,64
	r29.s64 = r11.s64 + 64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391f48
	ctx.lr = 0x8269ADBC;
	sub_82391F48(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,34
	cr6.compare<int32_t>(r11.s32, 34, xer);
	// beq cr6,0x8269afb4
	if (cr6.eq) goto loc_8269AFB4;
	// cmpwi cr6,r11,47
	cr6.compare<int32_t>(r11.s32, 47, xer);
	// beq cr6,0x8269afb4
	if (cr6.eq) goto loc_8269AFB4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8269ae8c
	if (!cr6.eq) goto loc_8269AE8C;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,43656
	ctx.r10.u64 = r11.u64 | 43656;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8269b024
	if (!cr6.eq) goto loc_8269B024;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,42136
	ctx.r10.u64 = r11.u64 | 42136;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8269b024
	if (!cr6.eq) goto loc_8269B024;
	// lis r11,0
	r11.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// ori r10,r11,42276
	ctx.r10.u64 = r11.u64 | 42276;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,42128
	ctx.r7.u64 = ctx.r9.u64 | 42128;
	// ori r6,r8,42132
	ctx.r6.u64 = ctx.r8.u64 | 42132;
	// stwx r28,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r28.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r11,r5,152
	r11.s64 = ctx.r5.s64 * 152;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r10,-28312
	ctx.r3.s64 = ctx.r10.s64 + -28312;
	// stwx r5,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, ctx.r5.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r11,r9,152
	r11.s64 = ctx.r9.s64 * 152;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stwx r4,r8,r6
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x8269AE50;
	sub_82130000(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391f48
	ctx.lr = 0x8269AE5C;
	sub_82391F48(ctx, base);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// ori r4,r7,43796
	ctx.r4.u64 = ctx.r7.u64 | 43796;
	// ori r11,r6,43800
	r11.u64 = ctx.r6.u64 | 43800;
	// ori r10,r5,43804
	ctx.r10.u64 = ctx.r5.u64 | 43804;
	// li r9,11
	ctx.r9.s64 = 11;
	// stwx r28,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r28.u32);
	// stwx r9,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r9.u32);
	// stwx r3,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8269AE8C:
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// bne cr6,0x8269af44
	if (!cr6.eq) goto loc_8269AF44;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,43656
	ctx.r10.u64 = r11.u64 | 43656;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8269b024
	if (!cr6.eq) goto loc_8269B024;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,42136
	ctx.r10.u64 = r11.u64 | 42136;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8269b024
	if (!cr6.eq) goto loc_8269B024;
	// lis r11,0
	r11.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// ori r10,r11,43796
	ctx.r10.u64 = r11.u64 | 43796;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,42128
	ctx.r7.u64 = ctx.r9.u64 | 42128;
	// ori r6,r8,42132
	ctx.r6.u64 = ctx.r8.u64 | 42132;
	// stwx r28,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r28.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r3,r10,-28312
	ctx.r3.s64 = ctx.r10.s64 + -28312;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r11,r5,152
	r11.s64 = ctx.r5.s64 * 152;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stwx r5,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, ctx.r5.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r11,r9,152
	r11.s64 = ctx.r9.s64 * 152;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stwx r4,r8,r6
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x8269AF08;
	sub_82130000(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82391f48
	ctx.lr = 0x8269AF14;
	sub_82391F48(ctx, base);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// ori r4,r7,42276
	ctx.r4.u64 = ctx.r7.u64 | 42276;
	// ori r11,r6,42280
	r11.u64 = ctx.r6.u64 | 42280;
	// ori r10,r5,42284
	ctx.r10.u64 = ctx.r5.u64 | 42284;
	// li r9,1
	ctx.r9.s64 = 1;
	// stwx r28,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r28.u32);
	// stwx r9,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r9.u32);
	// stwx r3,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8269AF44:
	// mulli r11,r11,152
	r11.s64 = r11.s64 * 152;
	// lis r10,0
	ctx.r10.s64 = 0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// ori r9,r10,41984
	ctx.r9.u64 = ctx.r10.u64 | 41984;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8269b024
	if (!cr6.eq) goto loc_8269B024;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r8,r10,42124
	ctx.r8.u64 = ctx.r10.u64 | 42124;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r5,r7,42128
	ctx.r5.u64 = ctx.r7.u64 | 42128;
	// ori r10,r6,42132
	ctx.r10.u64 = ctx.r6.u64 | 42132;
	// stwx r9,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r9.u32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r11,r8,152
	r11.s64 = ctx.r8.s64 * 152;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// addi r3,r9,-28312
	ctx.r3.s64 = ctx.r9.s64 + -28312;
	// stwx r8,r7,r5
	PPC_STORE_U32(ctx.r7.u32 + ctx.r5.u32, ctx.r8.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r11,r6,152
	r11.s64 = ctx.r6.s64 * 152;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// stwx r4,r5,r10
	PPC_STORE_U32(ctx.r5.u32 + ctx.r10.u32, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x8269AFAC;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8269AFB4:
	// lbz r10,2140(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 2140);
	// mulli r11,r11,152
	r11.s64 = r11.s64 * 152;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// ori r8,r10,42128
	ctx.r8.u64 = ctx.r10.u64 | 42128;
	// beq cr6,0x8269afe0
	if (cr6.eq) goto loc_8269AFE0;
	// li r7,47
	ctx.r7.s64 = 47;
	// li r4,24
	ctx.r4.s64 = 24;
	// b 0x8269afe8
	goto loc_8269AFE8;
loc_8269AFE0:
	// li r7,34
	ctx.r7.s64 = 34;
	// li r4,23
	ctx.r4.s64 = 23;
loc_8269AFE8:
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// bl 0x82391f48
	ctx.lr = 0x8269AFF0;
	sub_82391F48(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,0
	ctx.r10.s64 = 0;
	// mulli r11,r11,152
	r11.s64 = r11.s64 * 152;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// ori r7,r10,42124
	ctx.r7.u64 = ctx.r10.u64 | 42124;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r5,r6,42132
	ctx.r5.u64 = ctx.r6.u64 | 42132;
	// stwx r9,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r9.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r11,r4,152
	r11.s64 = ctx.r4.s64 * 152;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stwx r3,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.r3.u32);
loc_8269B024:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269B02C"))) PPC_WEAK_FUNC(sub_8269B02C);
PPC_FUNC_IMPL(__imp__sub_8269B02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269B030"))) PPC_WEAK_FUNC(sub_8269B030);
PPC_FUNC_IMPL(__imp__sub_8269B030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B054;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,12
	cr6.compare<uint32_t>(r31.u32, 12, xer);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// bgt cr6,0x8269b1d8
	if (cr6.gt) goto loc_8269B1D8;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-20352
	r12.s64 = r12.s64 + -20352;
	// rlwinm r0,r31,2,0,29
	r0.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r31.u64) {
	case 0:
		goto loc_8269B0B4;
	case 1:
		goto loc_8269B0CC;
	case 2:
		goto loc_8269B0E4;
	case 3:
		goto loc_8269B0FC;
	case 4:
		goto loc_8269B114;
	case 5:
		goto loc_8269B12C;
	case 6:
		goto loc_8269B144;
	case 7:
		goto loc_8269B15C;
	case 8:
		goto loc_8269B174;
	case 9:
		goto loc_8269B18C;
	case 10:
		goto loc_8269B1A4;
	case 11:
		goto loc_8269B1BC;
	case 12:
		goto loc_8269B1D4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-20300(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20300);
	// lwz r19,-20276(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20276);
	// lwz r19,-20252(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20252);
	// lwz r19,-20228(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20228);
	// lwz r19,-20204(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20204);
	// lwz r19,-20180(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20180);
	// lwz r19,-20156(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20156);
	// lwz r19,-20132(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20132);
	// lwz r19,-20108(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20108);
	// lwz r19,-20084(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20084);
	// lwz r19,-20060(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20060);
	// lwz r19,-20036(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20036);
	// lwz r19,-20012(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20012);
loc_8269B0B4:
	// lbz r3,43(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 43);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B0CC:
	// lbz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 44);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B0E4:
	// lbz r3,45(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 45);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B0FC:
	// lbz r3,46(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 46);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B114:
	// lbz r3,47(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 47);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B12C:
	// lbz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 48);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B144:
	// lbz r3,49(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B15C:
	// lbz r3,50(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 50);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B174:
	// lbz r3,51(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 51);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B18C:
	// lbz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 52);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B1A4:
	// lbz r3,53(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 53);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B1BC:
	// lbz r3,54(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 54);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269B1D4:
	// lbz r3,55(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 55);
loc_8269B1D8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269B1EC"))) PPC_WEAK_FUNC(sub_8269B1EC);
PPC_FUNC_IMPL(__imp__sub_8269B1EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269B1F0"))) PPC_WEAK_FUNC(sub_8269B1F0);
PPC_FUNC_IMPL(__imp__sub_8269B1F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x8269B1F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x822a3998
	ctx.lr = 0x8269B21C;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r10,-28264
	ctx.r3.s64 = ctx.r10.s64 + -28264;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r24,132(r9)
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// bl 0x82130000
	ctx.lr = 0x8269B238;
	sub_82130000(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8269b030
	ctx.lr = 0x8269B244;
	sub_8269B030(ctx, base);
	// addi r8,r27,14429
	ctx.r8.s64 = r27.s64 + 14429;
	// li r26,0
	r26.s64 = 0;
	// rlwinm r30,r8,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r29,r26
	r29.u64 = r26.u64;
	// cmplwi cr6,r27,12
	cr6.compare<uint32_t>(r27.u32, 12, xer);
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// bgt cr6,0x8269b61c
	if (cr6.gt) goto loc_8269B61C;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-19848
	r12.s64 = r12.s64 + -19848;
	// rlwinm r0,r27,2,0,29
	r0.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r27.u64) {
	case 0:
		goto loc_8269B2AC;
	case 1:
		goto loc_8269B314;
	case 2:
		goto loc_8269B33C;
	case 3:
		goto loc_8269B364;
	case 4:
		goto loc_8269B3CC;
	case 5:
		goto loc_8269B410;
	case 6:
		goto loc_8269B478;
	case 7:
		goto loc_8269B4DC;
	case 8:
		goto loc_8269B504;
	case 9:
		goto loc_8269B548;
	case 10:
		goto loc_8269B570;
	case 11:
		goto loc_8269B598;
	case 12:
		goto loc_8269B5C0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-19796(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19796);
	// lwz r19,-19692(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19692);
	// lwz r19,-19652(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19652);
	// lwz r19,-19612(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19612);
	// lwz r19,-19508(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19508);
	// lwz r19,-19440(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19440);
	// lwz r19,-19336(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19336);
	// lwz r19,-19236(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19236);
	// lwz r19,-19196(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19196);
	// lwz r19,-19128(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19128);
	// lwz r19,-19088(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19088);
	// lwz r19,-19048(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19048);
	// lwz r19,-19008(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19008);
loc_8269B2AC:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B2B8;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269B2C0;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269b2e4
	if (cr6.eq) goto loc_8269B2E4;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stwx r26,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r26.u32);
	// mr r11,r26
	r11.u64 = r26.u64;
	// lbz r29,-28051(r10)
	r29.u64 = PPC_LOAD_U8(ctx.r10.u32 + -28051);
	// stb r11,43(r24)
	PPC_STORE_U8(r24.u32 + 43, r11.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B2E4:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B2F8;
	sub_82250268(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r10,r11,-28064
	ctx.r10.s64 = r11.s64 + -28064;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lbzx r29,r3,r10
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// stb r11,43(r24)
	PPC_STORE_U8(r24.u32 + 43, r11.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B314:
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B324;
	sub_82250268(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r10,r11,-28048
	ctx.r10.s64 = r11.s64 + -28048;
	// lbzx r29,r3,r10
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// stb r3,44(r24)
	PPC_STORE_U8(r24.u32 + 44, ctx.r3.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B33C:
	// li r5,9
	ctx.r5.s64 = 9;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B34C;
	sub_82250268(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r10,r11,-28836
	ctx.r10.s64 = r11.s64 + -28836;
	// lbzx r29,r3,r10
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// stb r3,45(r24)
	PPC_STORE_U8(r24.u32 + 45, ctx.r3.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B364:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B370;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269B378;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269b39c
	if (cr6.eq) goto loc_8269B39C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stwx r26,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r26.u32);
	// mr r11,r26
	r11.u64 = r26.u64;
	// lbz r29,-28049(r10)
	r29.u64 = PPC_LOAD_U8(ctx.r10.u32 + -28049);
	// stb r11,46(r24)
	PPC_STORE_U8(r24.u32 + 46, r11.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B39C:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B3B0;
	sub_82250268(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r10,r11,-28040
	ctx.r10.s64 = r11.s64 + -28040;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lbzx r29,r3,r10
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// stb r11,46(r24)
	PPC_STORE_U8(r24.u32 + 46, r11.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B3CC:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B3D8;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269B3E0;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// stwx r26,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269b400
	if (cr6.eq) goto loc_8269B400;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r29,-28050(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + -28050);
	// stb r26,47(r24)
	PPC_STORE_U8(r24.u32 + 47, r26.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B400:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r29,-28826(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + -28826);
	// stb r26,47(r24)
	PPC_STORE_U8(r24.u32 + 47, r26.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B410:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B41C;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269B424;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269b448
	if (cr6.eq) goto loc_8269B448;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stwx r26,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r26.u32);
	// mr r11,r26
	r11.u64 = r26.u64;
	// lbz r29,-28049(r10)
	r29.u64 = PPC_LOAD_U8(ctx.r10.u32 + -28049);
	// stb r11,48(r24)
	PPC_STORE_U8(r24.u32 + 48, r11.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B448:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B45C;
	sub_82250268(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r9,r10,-28032
	ctx.r9.s64 = ctx.r10.s64 + -28032;
	// lbzx r29,r3,r9
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// stb r11,48(r24)
	PPC_STORE_U8(r24.u32 + 48, r11.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B478:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B484;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269B48C;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269b4ac
	if (cr6.eq) goto loc_8269B4AC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stwx r26,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r26.u32);
	// lbz r29,-28043(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + -28043);
	// stb r26,49(r24)
	PPC_STORE_U8(r24.u32 + 49, r26.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B4AC:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B4C0;
	sub_82250268(ctx, base);
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r10,r11,-28028
	ctx.r10.s64 = r11.s64 + -28028;
	// lbzx r29,r3,r10
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// stb r26,49(r24)
	PPC_STORE_U8(r24.u32 + 49, r26.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B4DC:
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B4EC;
	sub_82250268(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r9,r11,-28024
	ctx.r9.s64 = r11.s64 + -28024;
	// lbzx r29,r3,r9
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// stb r3,50(r24)
	PPC_STORE_U8(r24.u32 + 50, ctx.r3.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B504:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B510;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269B518;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// stwx r26,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269b538
	if (cr6.eq) goto loc_8269B538;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r29,-28042(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + -28042);
	// stb r26,51(r24)
	PPC_STORE_U8(r24.u32 + 51, r26.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B538:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r29,-28825(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + -28825);
	// stb r26,51(r24)
	PPC_STORE_U8(r24.u32 + 51, r26.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B548:
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B558;
	sub_82250268(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r9,r11,-28016
	ctx.r9.s64 = r11.s64 + -28016;
	// lbzx r29,r3,r9
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// stb r3,52(r24)
	PPC_STORE_U8(r24.u32 + 52, ctx.r3.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B570:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B580;
	sub_82250268(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r9,r11,-28012
	ctx.r9.s64 = r11.s64 + -28012;
	// lbzx r29,r3,r9
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// stb r3,53(r24)
	PPC_STORE_U8(r24.u32 + 53, ctx.r3.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B598:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B5A8;
	sub_82250268(ctx, base);
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r9,r11,-28008
	ctx.r9.s64 = r11.s64 + -28008;
	// lbzx r29,r3,r9
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// stb r3,54(r24)
	PPC_STORE_U8(r24.u32 + 54, ctx.r3.u8);
	// b 0x8269b61c
	goto loc_8269B61C;
loc_8269B5C0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B5CC;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269B5D4;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269b5f0
	if (cr6.eq) goto loc_8269B5F0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stwx r26,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r26.u32);
	// lbz r29,-28041(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + -28041);
	// b 0x8269b618
	goto loc_8269B618;
loc_8269B5F0:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82250268
	ctx.lr = 0x8269B604;
	sub_82250268(ctx, base);
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r10,r11,-28004
	ctx.r10.s64 = r11.s64 + -28004;
	// lbzx r29,r3,r10
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
loc_8269B618:
	// stb r26,55(r24)
	PPC_STORE_U8(r24.u32 + 55, r26.u8);
loc_8269B61C:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8269b64c
	if (cr6.eq) goto loc_8269B64C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28272
	ctx.r4.s64 = r11.s64 + -28272;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8268da78
	ctx.lr = 0x8269B638;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269b64c
	if (cr6.eq) goto loc_8269B64C;
	// li r11,1
	r11.s64 = 1;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_8269B64C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8269B654"))) PPC_WEAK_FUNC(sub_8269B654);
PPC_FUNC_IMPL(__imp__sub_8269B654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269B658"))) PPC_WEAK_FUNC(sub_8269B658);
PPC_FUNC_IMPL(__imp__sub_8269B658) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B680;
	sub_822A3998(ctx, base);
	// lwz r30,48(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addis r4,r31,1
	ctx.r4.s64 = r31.s64 + 65536;
	// addi r4,r4,-15944
	ctx.r4.s64 = ctx.r4.s64 + -15944;
	// lwz r31,132(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82397f00
	ctx.lr = 0x8269B698;
	sub_82397F00(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// bl 0x82361988
	ctx.lr = 0x8269B6B4;
	sub_82361988(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// bl 0x82363210
	ctx.lr = 0x8269B6C0;
	sub_82363210(ctx, base);
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

__attribute__((alias("__imp__sub_8269B6D8"))) PPC_WEAK_FUNC(sub_8269B6D8);
PPC_FUNC_IMPL(__imp__sub_8269B6D8) {
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
	ctx.lr = 0x8269B6E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B6FC;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,132(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// bl 0x8238f1e8
	ctx.lr = 0x8269B708;
	sub_8238F1E8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8269B710;
	sub_82387B90(ctx, base);
	// mulli r9,r29,84
	ctx.r9.s64 = r29.s64 * 84;
	// add r8,r3,r9
	ctx.r8.u64 = ctx.r3.u64 + ctx.r9.u64;
	// li r11,0
	r11.s64 = 0;
	// addis r29,r8,4
	r29.s64 = ctx.r8.s64 + 262144;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// addi r29,r29,-15504
	r29.s64 = r29.s64 + -15504;
	// bne cr6,0x8269b734
	if (!cr6.eq) goto loc_8269B734;
	// li r11,21
	r11.s64 = 21;
	// b 0x8269b760
	goto loc_8269B760;
loc_8269B734:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269b744
	if (!cr6.eq) goto loc_8269B744;
	// li r11,27
	r11.s64 = 27;
	// b 0x8269b760
	goto loc_8269B760;
loc_8269B744:
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// bne cr6,0x8269b754
	if (!cr6.eq) goto loc_8269B754;
	// li r11,33
	r11.s64 = 33;
	// b 0x8269b760
	goto loc_8269B760;
loc_8269B754:
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// bne cr6,0x8269b760
	if (!cr6.eq) goto loc_8269B760;
	// li r11,36
	r11.s64 = 36;
loc_8269B760:
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// li r4,35
	ctx.r4.s64 = 35;
	// add r10,r30,r10
	ctx.r10.u64 = r30.u64 + ctx.r10.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// addi r5,r31,2
	ctx.r5.s64 = r31.s64 + 2;
	// bl 0x823901c0
	ctx.lr = 0x8269B77C;
	sub_823901C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269b794
	if (cr6.eq) goto loc_8269B794;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8269B794:
	// addi r5,r31,1
	ctx.r5.s64 = r31.s64 + 1;
	// li r4,35
	ctx.r4.s64 = 35;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823901c0
	ctx.lr = 0x8269B7A4;
	sub_823901C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8269B7BC"))) PPC_WEAK_FUNC(sub_8269B7BC);
PPC_FUNC_IMPL(__imp__sub_8269B7BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269B7C0"))) PPC_WEAK_FUNC(sub_8269B7C0);
PPC_FUNC_IMPL(__imp__sub_8269B7C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x8269B7C8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B7E0;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lwz r3,132(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r25,r3,20
	r25.s64 = ctx.r3.s64 + 20;
	// bl 0x8238f1e8
	ctx.lr = 0x8269B7F8;
	sub_8238F1E8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8269B800;
	sub_82387B90(ctx, base);
	// mulli r9,r29,84
	ctx.r9.s64 = r29.s64 * 84;
	// add r8,r3,r9
	ctx.r8.u64 = ctx.r3.u64 + ctx.r9.u64;
	// li r24,0
	r24.s64 = 0;
	// addis r26,r8,4
	r26.s64 = ctx.r8.s64 + 262144;
	// addi r26,r26,-15504
	r26.s64 = r26.s64 + -15504;
loc_8269B814:
	// cmplwi cr6,r24,12
	cr6.compare<uint32_t>(r24.u32, 12, xer);
	// bgt cr6,0x8269b8f0
	if (cr6.gt) goto loc_8269B8F0;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-18380
	r12.s64 = r12.s64 + -18380;
	// rlwinm r0,r24,2,0,29
	r0.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r24.u64) {
	case 0:
		goto loc_8269B868;
	case 1:
		goto loc_8269B870;
	case 2:
		goto loc_8269B87C;
	case 3:
		goto loc_8269B888;
	case 4:
		goto loc_8269B894;
	case 5:
		goto loc_8269B8A0;
	case 6:
		goto loc_8269B8AC;
	case 7:
		goto loc_8269B8B8;
	case 8:
		goto loc_8269B8C0;
	case 9:
		goto loc_8269B8CC;
	case 10:
		goto loc_8269B8D4;
	case 11:
		goto loc_8269B8E0;
	case 12:
		goto loc_8269B8E8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-18328(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18328);
	// lwz r19,-18320(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18320);
	// lwz r19,-18308(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18308);
	// lwz r19,-18296(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18296);
	// lwz r19,-18284(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18284);
	// lwz r19,-18272(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18272);
	// lwz r19,-18260(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18260);
	// lwz r19,-18248(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18248);
	// lwz r19,-18240(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18240);
	// lwz r19,-18228(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18228);
	// lwz r19,-18220(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18220);
	// lwz r19,-18208(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18208);
	// lwz r19,-18200(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18200);
loc_8269B868:
	// li r30,0
	r30.s64 = 0;
	// b 0x8269b8ec
	goto loc_8269B8EC;
loc_8269B870:
	// li r30,0
	r30.s64 = 0;
	// li r31,1
	r31.s64 = 1;
	// b 0x8269b8f0
	goto loc_8269B8F0;
loc_8269B87C:
	// li r30,0
	r30.s64 = 0;
	// li r31,2
	r31.s64 = 2;
	// b 0x8269b8f0
	goto loc_8269B8F0;
loc_8269B888:
	// li r30,0
	r30.s64 = 0;
	// li r31,3
	r31.s64 = 3;
	// b 0x8269b8f0
	goto loc_8269B8F0;
loc_8269B894:
	// li r30,0
	r30.s64 = 0;
	// li r31,4
	r31.s64 = 4;
	// b 0x8269b8f0
	goto loc_8269B8F0;
loc_8269B8A0:
	// li r30,0
	r30.s64 = 0;
	// li r31,5
	r31.s64 = 5;
	// b 0x8269b8f0
	goto loc_8269B8F0;
loc_8269B8AC:
	// li r30,0
	r30.s64 = 0;
	// li r31,6
	r31.s64 = 6;
	// b 0x8269b8f0
	goto loc_8269B8F0;
loc_8269B8B8:
	// li r30,1
	r30.s64 = 1;
	// b 0x8269b8ec
	goto loc_8269B8EC;
loc_8269B8C0:
	// li r30,1
	r30.s64 = 1;
	// li r31,1
	r31.s64 = 1;
	// b 0x8269b8f0
	goto loc_8269B8F0;
loc_8269B8CC:
	// li r30,2
	r30.s64 = 2;
	// b 0x8269b8ec
	goto loc_8269B8EC;
loc_8269B8D4:
	// li r30,2
	r30.s64 = 2;
	// li r31,1
	r31.s64 = 1;
	// b 0x8269b8f0
	goto loc_8269B8F0;
loc_8269B8E0:
	// li r30,3
	r30.s64 = 3;
	// b 0x8269b8ec
	goto loc_8269B8EC;
loc_8269B8E8:
	// li r30,4
	r30.s64 = 4;
loc_8269B8EC:
	// li r31,0
	r31.s64 = 0;
loc_8269B8F0:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bne cr6,0x8269b904
	if (!cr6.eq) goto loc_8269B904;
	// li r10,21
	ctx.r10.s64 = 21;
	// b 0x8269b930
	goto loc_8269B930;
loc_8269B904:
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x8269b914
	if (!cr6.eq) goto loc_8269B914;
	// li r10,27
	ctx.r10.s64 = 27;
	// b 0x8269b930
	goto loc_8269B930;
loc_8269B914:
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// bne cr6,0x8269b924
	if (!cr6.eq) goto loc_8269B924;
	// li r10,33
	ctx.r10.s64 = 33;
	// b 0x8269b930
	goto loc_8269B930;
loc_8269B924:
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x8269b930
	if (!cr6.eq) goto loc_8269B930;
	// li r10,36
	ctx.r10.s64 = 36;
loc_8269B930:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82398018
	ctx.lr = 0x8269B94C;
	sub_82398018(ctx, base);
	// clrlwi r28,r3,24
	r28.u64 = ctx.r3.u32 & 0xFF;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// add r5,r29,r28
	ctx.r5.u64 = r29.u64 + r28.u64;
	// li r4,35
	ctx.r4.s64 = 35;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823900e0
	ctx.lr = 0x8269B964;
	sub_823900E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269b974
	if (cr6.eq) goto loc_8269B974;
	// li r27,0
	r27.s64 = 0;
loc_8269B974:
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// bne cr6,0x8269b990
	if (!cr6.eq) goto loc_8269B990;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r29,1
	ctx.r5.s64 = r29.s64 + 1;
	// li r4,35
	ctx.r4.s64 = 35;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823900e0
	ctx.lr = 0x8269B990;
	sub_823900E0(ctx, base);
loc_8269B990:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// cmpwi cr6,r24,13
	cr6.compare<int32_t>(r24.s32, 13, xer);
	// blt cr6,0x8269b814
	if (cr6.lt) goto loc_8269B814;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8269B9A4"))) PPC_WEAK_FUNC(sub_8269B9A4);
PPC_FUNC_IMPL(__imp__sub_8269B9A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269B9A8"))) PPC_WEAK_FUNC(sub_8269B9A8);
PPC_FUNC_IMPL(__imp__sub_8269B9A8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8269B9B0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269B9D0;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lfs f31,36(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	f31.f64 = double(temp.f32);
	// bl 0x822a3998
	ctx.lr = 0x8269B9EC;
	sub_822A3998(ctx, base);
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,20(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// lfs f0,32680(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 32680);
	f0.f64 = double(temp.f32);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lfs f13,24(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f31,f13
	ctx.f12.f64 = double(float(f31.f64 / ctx.f13.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x8269ba18
	if (cr6.gt) goto loc_8269BA18;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8269BA18:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8269BA24"))) PPC_WEAK_FUNC(sub_8269BA24);
PPC_FUNC_IMPL(__imp__sub_8269BA24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269BA28"))) PPC_WEAK_FUNC(sub_8269BA28);
PPC_FUNC_IMPL(__imp__sub_8269BA28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,46
	cr6.compare<uint32_t>(r11.u32, 46, xer);
	// bgt cr6,0x8269bbd0
	if (cr6.gt) goto loc_8269BBD0;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-17844
	r12.s64 = r12.s64 + -17844;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8269BB08;
	case 1:
		goto loc_8269BB10;
	case 2:
		goto loc_8269BB18;
	case 3:
		goto loc_8269BBD0;
	case 4:
		goto loc_8269BB28;
	case 5:
		goto loc_8269BB20;
	case 6:
		goto loc_8269BB38;
	case 7:
		goto loc_8269BB40;
	case 8:
		goto loc_8269BB48;
	case 9:
		goto loc_8269BBD0;
	case 10:
		goto loc_8269BB50;
	case 11:
		goto loc_8269BB58;
	case 12:
		goto loc_8269BB60;
	case 13:
		goto loc_8269BB68;
	case 14:
		goto loc_8269BB70;
	case 15:
		goto loc_8269BB30;
	case 16:
		goto loc_8269BBD0;
	case 17:
		goto loc_8269BB78;
	case 18:
		goto loc_8269BBD0;
	case 19:
		goto loc_8269BBD0;
	case 20:
		goto loc_8269BBD0;
	case 21:
		goto loc_8269BBD0;
	case 22:
		goto loc_8269BBD0;
	case 23:
		goto loc_8269BB80;
	case 24:
		goto loc_8269BB88;
	case 25:
		goto loc_8269BBD0;
	case 26:
		goto loc_8269BBD0;
	case 27:
		goto loc_8269BB90;
	case 28:
		goto loc_8269BB98;
	case 29:
		goto loc_8269BBB8;
	case 30:
		goto loc_8269BBB0;
	case 31:
		goto loc_8269BBC0;
	case 32:
		goto loc_8269BBD0;
	case 33:
		goto loc_8269BBA0;
	case 34:
		goto loc_8269BBC8;
	case 35:
		goto loc_8269BBC8;
	case 36:
		goto loc_8269BBC8;
	case 37:
		goto loc_8269BBC8;
	case 38:
		goto loc_8269BBC8;
	case 39:
		goto loc_8269BBC8;
	case 40:
		goto loc_8269BBC8;
	case 41:
		goto loc_8269BBC8;
	case 42:
		goto loc_8269BBC8;
	case 43:
		goto loc_8269BBC8;
	case 44:
		goto loc_8269BBC8;
	case 45:
		goto loc_8269BBC8;
	case 46:
		goto loc_8269BBA8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-17656(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17656);
	// lwz r19,-17648(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17648);
	// lwz r19,-17640(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17640);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17624(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17624);
	// lwz r19,-17632(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17632);
	// lwz r19,-17608(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17608);
	// lwz r19,-17600(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17600);
	// lwz r19,-17592(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17592);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17584(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17584);
	// lwz r19,-17576(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17576);
	// lwz r19,-17568(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17568);
	// lwz r19,-17560(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17560);
	// lwz r19,-17552(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17552);
	// lwz r19,-17616(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17616);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17544(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17544);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17536(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17536);
	// lwz r19,-17528(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17528);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17520(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17520);
	// lwz r19,-17512(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17512);
	// lwz r19,-17480(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17480);
	// lwz r19,-17488(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17488);
	// lwz r19,-17472(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17472);
	// lwz r19,-17456(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17456);
	// lwz r19,-17504(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17504);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17464(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17464);
	// lwz r19,-17496(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17496);
loc_8269BB08:
	// li r3,14
	ctx.r3.s64 = 14;
	// blr 
	return;
loc_8269BB10:
	// li r3,12
	ctx.r3.s64 = 12;
	// blr 
	return;
loc_8269BB18:
	// li r3,11
	ctx.r3.s64 = 11;
	// blr 
	return;
loc_8269BB20:
	// li r3,13
	ctx.r3.s64 = 13;
	// blr 
	return;
loc_8269BB28:
	// li r3,17
	ctx.r3.s64 = 17;
	// blr 
	return;
loc_8269BB30:
	// li r3,53
	ctx.r3.s64 = 53;
	// blr 
	return;
loc_8269BB38:
	// li r3,18
	ctx.r3.s64 = 18;
	// blr 
	return;
loc_8269BB40:
	// li r3,19
	ctx.r3.s64 = 19;
	// blr 
	return;
loc_8269BB48:
	// li r3,30
	ctx.r3.s64 = 30;
	// blr 
	return;
loc_8269BB50:
	// li r3,16
	ctx.r3.s64 = 16;
	// blr 
	return;
loc_8269BB58:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8269BB60:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8269BB68:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8269BB70:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_8269BB78:
	// li r3,21
	ctx.r3.s64 = 21;
	// blr 
	return;
loc_8269BB80:
	// li r3,43
	ctx.r3.s64 = 43;
	// blr 
	return;
loc_8269BB88:
	// li r3,44
	ctx.r3.s64 = 44;
	// blr 
	return;
loc_8269BB90:
	// li r3,45
	ctx.r3.s64 = 45;
	// blr 
	return;
loc_8269BB98:
	// li r3,46
	ctx.r3.s64 = 46;
	// blr 
	return;
loc_8269BBA0:
	// li r3,10
	ctx.r3.s64 = 10;
	// blr 
	return;
loc_8269BBA8:
	// li r3,52
	ctx.r3.s64 = 52;
	// blr 
	return;
loc_8269BBB0:
	// li r3,7
	ctx.r3.s64 = 7;
	// blr 
	return;
loc_8269BBB8:
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_8269BBC0:
	// li r3,9
	ctx.r3.s64 = 9;
	// blr 
	return;
loc_8269BBC8:
	// li r3,35
	ctx.r3.s64 = 35;
	// blr 
	return;
loc_8269BBD0:
	// li r3,-1
	ctx.r3.s64 = -1;
}

__attribute__((alias("__imp__sub_8269BBD8"))) PPC_WEAK_FUNC(sub_8269BBD8);
PPC_FUNC_IMPL(__imp__sub_8269BBD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r19{};
	// cmplwi cr6,r4,53
	cr6.compare<uint32_t>(ctx.r4.u32, 53, xer);
	// bgt cr6,0x8269bdf8
	if (cr6.gt) goto loc_8269BDF8;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-17416
	r12.s64 = r12.s64 + -17416;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8269BCD0;
	case 1:
		goto loc_8269BDF8;
	case 2:
		goto loc_8269BCD8;
	case 3:
		goto loc_8269BCE0;
	case 4:
		goto loc_8269BCE8;
	case 5:
		goto loc_8269BD48;
	case 6:
		goto loc_8269BCF0;
	case 7:
		goto loc_8269BCF8;
	case 8:
		goto loc_8269BD00;
	case 9:
		goto loc_8269BD08;
	case 10:
		goto loc_8269BD10;
	case 11:
		goto loc_8269BD18;
	case 12:
		goto loc_8269BD20;
	case 13:
		goto loc_8269BD28;
	case 14:
		goto loc_8269BD30;
	case 15:
		goto loc_8269BD38;
	case 16:
		goto loc_8269BD40;
	case 17:
		goto loc_8269BD58;
	case 18:
		goto loc_8269BD60;
	case 19:
		goto loc_8269BD50;
	case 20:
		goto loc_8269BD68;
	case 21:
		goto loc_8269BD70;
	case 22:
		goto loc_8269BDF8;
	case 23:
		goto loc_8269BD78;
	case 24:
		goto loc_8269BD78;
	case 25:
		goto loc_8269BDF8;
	case 26:
		goto loc_8269BDF8;
	case 27:
		goto loc_8269BDF8;
	case 28:
		goto loc_8269BDF8;
	case 29:
		goto loc_8269BDF8;
	case 30:
		goto loc_8269BDF8;
	case 31:
		goto loc_8269BDF8;
	case 32:
		goto loc_8269BDF8;
	case 33:
		goto loc_8269BDF8;
	case 34:
		goto loc_8269BDF8;
	case 35:
		goto loc_8269BDF8;
	case 36:
		goto loc_8269BDF8;
	case 37:
		goto loc_8269BDF8;
	case 38:
		goto loc_8269BD80;
	case 39:
		goto loc_8269BD88;
	case 40:
		goto loc_8269BD90;
	case 41:
		goto loc_8269BD98;
	case 42:
		goto loc_8269BDA0;
	case 43:
		goto loc_8269BDA8;
	case 44:
		goto loc_8269BDB0;
	case 45:
		goto loc_8269BDB8;
	case 46:
		goto loc_8269BDF8;
	case 47:
		goto loc_8269BDC0;
	case 48:
		goto loc_8269BDC8;
	case 49:
		goto loc_8269BDD0;
	case 50:
		goto loc_8269BDD8;
	case 51:
		goto loc_8269BDE0;
	case 52:
		goto loc_8269BDE8;
	case 53:
		goto loc_8269BDF0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-17200(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17200);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-17192(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17192);
	// lwz r19,-17184(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17184);
	// lwz r19,-17176(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17176);
	// lwz r19,-17080(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17080);
	// lwz r19,-17168(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17168);
	// lwz r19,-17160(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17160);
	// lwz r19,-17152(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17152);
	// lwz r19,-17144(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17144);
	// lwz r19,-17136(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17136);
	// lwz r19,-17128(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17128);
	// lwz r19,-17120(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17120);
	// lwz r19,-17112(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17112);
	// lwz r19,-17104(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17104);
	// lwz r19,-17096(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17096);
	// lwz r19,-17088(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17088);
	// lwz r19,-17064(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17064);
	// lwz r19,-17056(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17056);
	// lwz r19,-17072(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17072);
	// lwz r19,-17048(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17048);
	// lwz r19,-17040(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17040);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-17032(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17032);
	// lwz r19,-17032(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17032);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-17024(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17024);
	// lwz r19,-17016(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17016);
	// lwz r19,-17008(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17008);
	// lwz r19,-17000(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17000);
	// lwz r19,-16992(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16992);
	// lwz r19,-16984(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16984);
	// lwz r19,-16976(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16976);
	// lwz r19,-16968(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16968);
	// lwz r19,-16904(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16904);
	// lwz r19,-16960(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16960);
	// lwz r19,-16952(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16952);
	// lwz r19,-16944(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16944);
	// lwz r19,-16936(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16936);
	// lwz r19,-16928(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16928);
	// lwz r19,-16920(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16920);
	// lwz r19,-16912(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16912);
loc_8269BCD0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8269BCD8:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8269BCE0:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8269BCE8:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8269BCF0:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_8269BCF8:
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_8269BD00:
	// li r3,6
	ctx.r3.s64 = 6;
	// blr 
	return;
loc_8269BD08:
	// li r3,7
	ctx.r3.s64 = 7;
	// blr 
	return;
loc_8269BD10:
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_8269BD18:
	// li r3,9
	ctx.r3.s64 = 9;
	// blr 
	return;
loc_8269BD20:
	// li r3,10
	ctx.r3.s64 = 10;
	// blr 
	return;
loc_8269BD28:
	// li r3,11
	ctx.r3.s64 = 11;
	// blr 
	return;
loc_8269BD30:
	// li r3,12
	ctx.r3.s64 = 12;
	// blr 
	return;
loc_8269BD38:
	// li r3,13
	ctx.r3.s64 = 13;
	// blr 
	return;
loc_8269BD40:
	// li r3,14
	ctx.r3.s64 = 14;
	// blr 
	return;
loc_8269BD48:
	// li r3,15
	ctx.r3.s64 = 15;
	// blr 
	return;
loc_8269BD50:
	// li r3,18
	ctx.r3.s64 = 18;
	// blr 
	return;
loc_8269BD58:
	// li r3,16
	ctx.r3.s64 = 16;
	// blr 
	return;
loc_8269BD60:
	// li r3,17
	ctx.r3.s64 = 17;
	// blr 
	return;
loc_8269BD68:
	// li r3,19
	ctx.r3.s64 = 19;
	// blr 
	return;
loc_8269BD70:
	// li r3,20
	ctx.r3.s64 = 20;
	// blr 
	return;
loc_8269BD78:
	// li r3,21
	ctx.r3.s64 = 21;
	// blr 
	return;
loc_8269BD80:
	// li r3,23
	ctx.r3.s64 = 23;
	// blr 
	return;
loc_8269BD88:
	// li r3,24
	ctx.r3.s64 = 24;
	// blr 
	return;
loc_8269BD90:
	// li r3,25
	ctx.r3.s64 = 25;
	// blr 
	return;
loc_8269BD98:
	// li r3,26
	ctx.r3.s64 = 26;
	// blr 
	return;
loc_8269BDA0:
	// li r3,27
	ctx.r3.s64 = 27;
	// blr 
	return;
loc_8269BDA8:
	// li r3,28
	ctx.r3.s64 = 28;
	// blr 
	return;
loc_8269BDB0:
	// li r3,29
	ctx.r3.s64 = 29;
	// blr 
	return;
loc_8269BDB8:
	// li r3,30
	ctx.r3.s64 = 30;
	// blr 
	return;
loc_8269BDC0:
	// li r3,31
	ctx.r3.s64 = 31;
	// blr 
	return;
loc_8269BDC8:
	// li r3,32
	ctx.r3.s64 = 32;
	// blr 
	return;
loc_8269BDD0:
	// li r3,33
	ctx.r3.s64 = 33;
	// blr 
	return;
loc_8269BDD8:
	// li r3,34
	ctx.r3.s64 = 34;
	// blr 
	return;
loc_8269BDE0:
	// li r3,35
	ctx.r3.s64 = 35;
	// blr 
	return;
loc_8269BDE8:
	// li r3,36
	ctx.r3.s64 = 36;
	// blr 
	return;
loc_8269BDF0:
	// li r3,37
	ctx.r3.s64 = 37;
	// blr 
	return;
loc_8269BDF8:
	// li r3,-1
	ctx.r3.s64 = -1;
}

__attribute__((alias("__imp__sub_8269BE00"))) PPC_WEAK_FUNC(sub_8269BE00);
PPC_FUNC_IMPL(__imp__sub_8269BE00) {
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
	ctx.lr = 0x8269BE08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	r11.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// ori r9,r11,39524
	ctx.r9.u64 = r11.u64 | 39524;
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// ori r8,r10,41984
	ctx.r8.u64 = ctx.r10.u64 | 41984;
	// lwzx r4,r3,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// mulli r11,r4,152
	r11.s64 = ctx.r4.s64 * 152;
	// add r7,r11,r3
	ctx.r7.u64 = r11.u64 + ctx.r3.u64;
	// lbzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8269be84
	if (!cr6.eq) goto loc_8269BE84;
	// bl 0x8269ba28
	ctx.lr = 0x8269BE40;
	sub_8269BA28(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269BE54;
	sub_822A3998(ctx, base);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238f1e8
	ctx.lr = 0x8269BE5C;
	sub_8238F1E8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8269BE64;
	sub_82387B90(ctx, base);
	// mulli r11,r28,84
	r11.s64 = r28.s64 * 84;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addis r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 262144;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r3,-15504
	ctx.r3.s64 = ctx.r3.s64 + -15504;
	// bl 0x823900e0
	ctx.lr = 0x8269BE84;
	sub_823900E0(ctx, base);
loc_8269BE84:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269BE8C"))) PPC_WEAK_FUNC(sub_8269BE8C);
PPC_FUNC_IMPL(__imp__sub_8269BE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269BE90"))) PPC_WEAK_FUNC(sub_8269BE90);
PPC_FUNC_IMPL(__imp__sub_8269BE90) {
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
	ctx.lr = 0x8269BE98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x8269a400
	ctx.lr = 0x8269BEA8;
	sub_8269A400(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269BEBC;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// addi r27,r11,64
	r27.s64 = r11.s64 + 64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82391ee0
	ctx.lr = 0x8269BED8;
	sub_82391EE0(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,57984
	ctx.r9.u64 = ctx.r10.u64 | 57984;
	// lbzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8269bfb0
	if (cr6.eq) goto loc_8269BFB0;
	// cmpwi cr6,r30,49
	cr6.compare<int32_t>(r30.s32, 49, xer);
	// bne cr6,0x8269bf18
	if (!cr6.eq) goto loc_8269BF18;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269BF00;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r10,2157(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2157, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269BF18:
	// cmpwi cr6,r30,11
	cr6.compare<int32_t>(r30.s32, 11, xer);
	// bne cr6,0x8269bf44
	if (!cr6.eq) goto loc_8269BF44;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269BF2C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r10,2161(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2161, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269BF44:
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x8269bf64
	if (!cr6.eq) goto loc_8269BF64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82391ee0
	ctx.lr = 0x8269BF5C;
	sub_82391EE0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269BF64:
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// bne cr6,0x8269bfb0
	if (!cr6.eq) goto loc_8269BFB0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x8269bfa0
	if (!cr6.eq) goto loc_8269BFA0;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,42284
	ctx.r10.u64 = r11.u64 | 42284;
	// lwzx r5,r31,r10
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmpwi cr6,r5,5
	cr6.compare<int32_t>(ctx.r5.s32, 5, xer);
	// bne cr6,0x8269bfa4
	if (!cr6.eq) goto loc_8269BFA4;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82391ee0
	ctx.lr = 0x8269BF98;
	sub_82391EE0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269BFA0:
	// li r5,5
	ctx.r5.s64 = 5;
loc_8269BFA4:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82391ee0
	ctx.lr = 0x8269BFB0;
	sub_82391EE0(ctx, base);
loc_8269BFB0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8269BFB8"))) PPC_WEAK_FUNC(sub_8269BFB8);
PPC_FUNC_IMPL(__imp__sub_8269BFB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269BFE4;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// lwz r10,1664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1664);
	// lwz r11,1668(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1668);
	// bne cr6,0x8269c068
	if (!cr6.eq) goto loc_8269C068;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8269c014
	if (!cr6.eq) goto loc_8269C014;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x8269c014
	if (cr6.eq) goto loc_8269C014;
loc_8269C00C:
	// li r4,23
	ctx.r4.s64 = 23;
	// b 0x8269c09c
	goto loc_8269C09C;
loc_8269C014:
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,39260
	ctx.r10.u64 = r11.u64 | 39260;
	// lwzx r11,r30,r10
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x8269c0a8
	if (cr6.gt) goto loc_8269C0A8;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-16320
	r12.s64 = r12.s64 + -16320;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8269C058;
	case 1:
		goto loc_8269C00C;
	case 2:
		goto loc_8269C058;
	case 3:
		goto loc_8269C060;
	case 4:
		goto loc_8269C080;
	case 5:
		goto loc_8269C00C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-16296(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16296);
	// lwz r19,-16372(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16372);
	// lwz r19,-16296(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16296);
	// lwz r19,-16288(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16288);
	// lwz r19,-16256(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16256);
	// lwz r19,-16372(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -16372);
loc_8269C058:
	// li r4,21
	ctx.r4.s64 = 21;
	// b 0x8269c09c
	goto loc_8269C09C;
loc_8269C060:
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x8269c09c
	goto loc_8269C09C;
loc_8269C068:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269c0a8
	if (!cr6.eq) goto loc_8269C0A8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8269c088
	if (!cr6.eq) goto loc_8269C088;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x8269c0a8
	if (cr6.eq) goto loc_8269C0A8;
loc_8269C080:
	// li r4,22
	ctx.r4.s64 = 22;
	// b 0x8269c09c
	goto loc_8269C09C;
loc_8269C088:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8269c0a8
	if (!cr6.eq) goto loc_8269C0A8;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x8269c0a8
	if (cr6.eq) goto loc_8269C0A8;
	// li r4,8
	ctx.r4.s64 = 8;
loc_8269C09C:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b34f8
	ctx.lr = 0x8269C0A8;
	sub_826B34F8(ctx, base);
loc_8269C0A8:
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

__attribute__((alias("__imp__sub_8269C0C0"))) PPC_WEAK_FUNC(sub_8269C0C0);
PPC_FUNC_IMPL(__imp__sub_8269C0C0) {
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
	ctx.lr = 0x8269C0C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x822a3998
	ctx.lr = 0x8269C0EC;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r28,r8,39260
	r28.u64 = ctx.r8.u64 | 39260;
	// lwz r9,132(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// lbz r7,-29341(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + -29341);
	// addi r31,r9,64
	r31.s64 = ctx.r9.s64 + 64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8269c198
	if (cr6.eq) goto loc_8269C198;
	// li r10,0
	ctx.r10.s64 = 0;
	// add r30,r29,r28
	r30.u64 = r29.u64 + r28.u64;
	// stb r10,-29341(r11)
	PPC_STORE_U8(r11.u32 + -29341, ctx.r10.u8);
	// lwzx r11,r29,r28
	r11.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// lwz r4,1600(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1600);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x8269c140
	if (!cr6.gt) goto loc_8269C140;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
loc_8269C140:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x8269C148;
	sub_8268DCB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269c160
	if (cr6.eq) goto loc_8269C160;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269C160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8269C160:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// lwz r4,1604(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1604);
	// bl 0x8268dcb0
	ctx.lr = 0x8269C180;
	sub_8268DCB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269c198
	if (cr6.eq) goto loc_8269C198;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269C198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8269C198:
	// lis r11,0
	r11.s64 = 0;
	// lwzx r5,r29,r28
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// ori r10,r11,39256
	ctx.r10.u64 = r11.u64 | 39256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbzx r4,r29,r10
	ctx.r4.u64 = PPC_LOAD_U8(r29.u32 + ctx.r10.u32);
	// bl 0x82391f78
	ctx.lr = 0x8269C1B4;
	sub_82391F78(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8269C1BC"))) PPC_WEAK_FUNC(sub_8269C1BC);
PPC_FUNC_IMPL(__imp__sub_8269C1BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269C1C0"))) PPC_WEAK_FUNC(sub_8269C1C0);
PPC_FUNC_IMPL(__imp__sub_8269C1C0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269C1EC;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,39260
	ctx.r7.u64 = ctx.r9.u64 | 39260;
	// ori r4,r8,39256
	ctx.r4.u64 = ctx.r8.u64 | 39256;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r5,r31,r7
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lbzx r4,r31,r4
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// bl 0x82391fb8
	ctx.lr = 0x8269C218;
	sub_82391FB8(ctx, base);
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

__attribute__((alias("__imp__sub_8269C230"))) PPC_WEAK_FUNC(sub_8269C230);
PPC_FUNC_IMPL(__imp__sub_8269C230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-28248
	ctx.r3.s64 = r11.s64 + -28248;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269C23C"))) PPC_WEAK_FUNC(sub_8269C23C);
PPC_FUNC_IMPL(__imp__sub_8269C23C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269C240"))) PPC_WEAK_FUNC(sub_8269C240);
PPC_FUNC_IMPL(__imp__sub_8269C240) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29342(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29342);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// bne cr6,0x8269c280
	if (!cr6.eq) goto loc_8269C280;
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r5,-6745(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + -6745);
	// stb r10,-29345(r7)
	PPC_STORE_U8(ctx.r7.u32 + -29345, ctx.r10.u8);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// stb r9,-29347(r6)
	PPC_STORE_U8(ctx.r6.u32 + -29347, ctx.r9.u8);
	// rlwinm r11,r4,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stb r11,-6745(r8)
	PPC_STORE_U8(ctx.r8.u32 + -6745, r11.u8);
	// blr 
	return;
loc_8269C280:
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-29345(r9)
	PPC_STORE_U8(ctx.r9.u32 + -29345, r11.u8);
	// stb r10,-29347(r8)
	PPC_STORE_U8(ctx.r8.u32 + -29347, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269C298"))) PPC_WEAK_FUNC(sub_8269C298);
PPC_FUNC_IMPL(__imp__sub_8269C298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9d4
	ctx.lr = 0x8269C2B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// fmr f28,f4
	f28.f64 = ctx.f4.f64;
	// fmr f27,f5
	f27.f64 = ctx.f5.f64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269C2D8;
	sub_822A3998(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b1490
	ctx.lr = 0x8269C2E4;
	sub_822B1490(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,17268(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x8269C2F4;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,880(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 880);
	// lwz r31,124(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 124);
	// bl 0x822a3998
	ctx.lr = 0x8269C30C;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x8269C310;
	sub_822A8108(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269C320;
	sub_822A3998(ctx, base);
	// lwz r9,880(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r7,124(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 124);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,216(r7)
	PPC_STORE_U32(ctx.r7.u32 + 216, ctx.r8.u32);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269C33C;
	sub_822A3998(ctx, base);
	// lwz r6,880(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r5,124(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 124);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f31,192(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r5.u32 + 192, temp.u32);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269C354;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r11,124(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f30,196(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 196, temp.u32);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269C36C;
	sub_822A3998(ctx, base);
	// lwz r10,880(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,124(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 124);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f31,27644(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27644);
	f31.f64 = double(temp.f32);
	// fmuls f0,f29,f31
	f0.f64 = double(float(f29.f64 * f31.f64));
	// stfs f0,200(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 200, temp.u32);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269C390;
	sub_822A3998(ctx, base);
	// lwz r7,880(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r6,124(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 124);
	// fmuls f13,f28,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f28.f64 * f31.f64));
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f13,204(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 204, temp.u32);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269C3AC;
	sub_822A3998(ctx, base);
	// lwz r5,880(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r4,124(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 124);
	// stfs f27,168(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r4.u32 + 168, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba20
	ctx.lr = 0x8269C3C4;
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

__attribute__((alias("__imp__sub_8269C3D8"))) PPC_WEAK_FUNC(sub_8269C3D8);
PPC_FUNC_IMPL(__imp__sub_8269C3D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r3,-29345(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + -29345);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269C3E4"))) PPC_WEAK_FUNC(sub_8269C3E4);
PPC_FUNC_IMPL(__imp__sub_8269C3E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269C3E8"))) PPC_WEAK_FUNC(sub_8269C3E8);
PPC_FUNC_IMPL(__imp__sub_8269C3E8) {
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
	ctx.lr = 0x8269C3F0;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// stw r30,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r30.u32);
	// addis r6,r30,1
	ctx.r6.s64 = r30.s64 + 65536;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r11,-27720
	ctx.r5.s64 = r11.s64 + -27720;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26288
	ctx.r6.s64 = ctx.r6.s64 + -26288;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8269C424;
	sub_824DF200(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r31,r10,-29312
	r31.s64 = ctx.r10.s64 + -29312;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r9,-27736
	ctx.r5.s64 = ctx.r9.s64 + -27736;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8269C44C;
	sub_824DF200(ctx, base);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// addi r28,r8,-29200
	r28.s64 = ctx.r8.s64 + -29200;
	// addi r5,r7,-27756
	ctx.r5.s64 = ctx.r7.s64 + -27756;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8269C474;
	sub_824DF200(ctx, base);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r6,-27772
	ctx.r5.s64 = ctx.r6.s64 + -27772;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8269C494;
	sub_824DF200(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r5,-27792
	ctx.r5.s64 = ctx.r5.s64 + -27792;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r28,16
	ctx.r6.s64 = r28.s64 + 16;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C4B4;
	sub_824DF200(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addis r30,r30,1
	r30.s64 = r30.s64 + 65536;
	// addi r31,r11,-28000
	r31.s64 = r11.s64 + -28000;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r20,-32244
	r20.s64 = -2113142784;
	// lis r19,-32244
	r19.s64 = -2113142784;
	// lis r18,-32244
	r18.s64 = -2113142784;
	// lis r17,-32244
	r17.s64 = -2113142784;
	// lis r16,-32244
	r16.s64 = -2113142784;
	// addi r30,r30,-25952
	r30.s64 = r30.s64 + -25952;
	// lis r15,-32244
	r15.s64 = -2113142784;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r28,r10,-27808
	r28.s64 = ctx.r10.s64 + -27808;
	// addi r27,r9,-27824
	r27.s64 = ctx.r9.s64 + -27824;
	// addi r26,r8,-27840
	r26.s64 = ctx.r8.s64 + -27840;
	// addi r25,r7,-27856
	r25.s64 = ctx.r7.s64 + -27856;
	// addi r24,r6,-27872
	r24.s64 = ctx.r6.s64 + -27872;
	// addi r23,r5,-27888
	r23.s64 = ctx.r5.s64 + -27888;
	// addi r22,r4,-27908
	r22.s64 = ctx.r4.s64 + -27908;
	// addi r21,r3,-27928
	r21.s64 = ctx.r3.s64 + -27928;
	// addi r20,r20,-27948
	r20.s64 = r20.s64 + -27948;
	// addi r19,r19,-27956
	r19.s64 = r19.s64 + -27956;
	// addi r18,r18,-27964
	r18.s64 = r18.s64 + -27964;
	// addi r17,r17,-27976
	r17.s64 = r17.s64 + -27976;
	// addi r16,r16,-27988
	r16.s64 = r16.s64 + -27988;
	// addi r15,r15,-27996
	r15.s64 = r15.s64 + -27996;
	// addi r14,r11,-28008
	r14.s64 = r11.s64 + -28008;
loc_8269C540:
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x8269C550;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,12
	ctx.r6.s64 = r30.s64 + 12;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C56C;
	sub_824DF200(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C57C;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C598;
	sub_824DF200(ctx, base);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C5A8;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,4
	ctx.r6.s64 = r30.s64 + 4;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C5C4;
	sub_824DF200(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C5D4;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,8
	ctx.r6.s64 = r30.s64 + 8;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C5F0;
	sub_824DF200(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C600;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,16
	ctx.r6.s64 = r30.s64 + 16;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C61C;
	sub_824DF200(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C62C;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,20
	ctx.r6.s64 = r30.s64 + 20;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C648;
	sub_824DF200(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C658;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,32
	ctx.r6.s64 = r30.s64 + 32;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C674;
	sub_824DF200(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C684;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,36
	ctx.r6.s64 = r30.s64 + 36;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C6A0;
	sub_824DF200(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C6B0;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,40
	ctx.r6.s64 = r30.s64 + 40;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C6CC;
	sub_824DF200(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C6DC;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,1200
	ctx.r6.s64 = r30.s64 + 1200;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C6F8;
	sub_824DF200(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C708;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,1216
	ctx.r6.s64 = r30.s64 + 1216;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C724;
	sub_824DF200(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C734;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,1220
	ctx.r6.s64 = r30.s64 + 1220;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C750;
	sub_824DF200(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C760;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,1224
	ctx.r6.s64 = r30.s64 + 1224;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C77C;
	sub_824DF200(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C78C;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,1232
	ctx.r6.s64 = r30.s64 + 1232;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C7A8;
	sub_824DF200(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x8269C7B8;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,1236
	ctx.r6.s64 = r30.s64 + 1236;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C7D4;
	sub_824DF200(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r10,r11,100
	ctx.r10.s64 = r11.s64 + 100;
	// addi r30,r30,48
	r30.s64 = r30.s64 + 48;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x8269c540
	if (cr6.lt) goto loc_8269C540;
	// lwz r31,356(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r8,0
	ctx.r8.s64 = 0;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// addi r5,r11,-28028
	ctx.r5.s64 = r11.s64 + -28028;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26388
	ctx.r6.s64 = ctx.r6.s64 + -26388;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C814;
	sub_824DF200(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-28052
	ctx.r5.s64 = ctx.r10.s64 + -28052;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26348
	ctx.r6.s64 = ctx.r6.s64 + -26348;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C838;
	sub_824DF200(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r9,-28072
	ctx.r5.s64 = ctx.r9.s64 + -28072;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26380
	ctx.r6.s64 = ctx.r6.s64 + -26380;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C85C;
	sub_824DF200(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// addi r5,r7,-28096
	ctx.r5.s64 = ctx.r7.s64 + -28096;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26340
	ctx.r6.s64 = ctx.r6.s64 + -26340;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C880;
	sub_824DF200(ctx, base);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r6,-28120
	ctx.r5.s64 = ctx.r6.s64 + -28120;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26372
	ctx.r6.s64 = ctx.r6.s64 + -26372;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C8A4;
	sub_824DF200(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r5,-28144
	ctx.r5.s64 = ctx.r5.s64 + -28144;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26332
	ctx.r6.s64 = ctx.r6.s64 + -26332;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C8C8;
	sub_824DF200(ctx, base);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// addi r5,r4,-28168
	ctx.r5.s64 = ctx.r4.s64 + -28168;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26364
	ctx.r6.s64 = ctx.r6.s64 + -26364;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C8EC;
	sub_824DF200(ctx, base);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// addi r5,r3,-28192
	ctx.r5.s64 = ctx.r3.s64 + -28192;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26324
	ctx.r6.s64 = ctx.r6.s64 + -26324;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C910;
	sub_824DF200(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,-28212
	ctx.r5.s64 = r11.s64 + -28212;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26356
	ctx.r6.s64 = ctx.r6.s64 + -26356;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C934;
	sub_824DF200(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-28236
	ctx.r5.s64 = ctx.r10.s64 + -28236;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r6,-26316
	ctx.r6.s64 = ctx.r6.s64 + -26316;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8269C958;
	sub_824DF200(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8269C960"))) PPC_WEAK_FUNC(sub_8269C960);
PPC_FUNC_IMPL(__imp__sub_8269C960) {
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
	ctx.lr = 0x8269C968;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269C980;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r30,0
	r30.s64 = 0;
	// addi r26,r11,4272
	r26.s64 = r11.s64 + 4272;
	// mr r29,r26
	r29.u64 = r26.u64;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r27,r11,64
	r27.s64 = r11.s64 + 64;
loc_8269C99C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8269c9fc
	if (!cr6.gt) goto loc_8269C9FC;
loc_8269C9AC:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82393118
	ctx.lr = 0x8269C9BC;
	sub_82393118(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82392520
	ctx.lr = 0x8269C9CC;
	sub_82392520(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bl 0x82391d38
	ctx.lr = 0x8269C9EC;
	sub_82391D38(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x8269c9ac
	if (cr6.lt) goto loc_8269C9AC;
loc_8269C9FC:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r11,r26,20
	r11.s64 = r26.s64 + 20;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8269c99c
	if (cr6.lt) goto loc_8269C99C;
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8269CA20"))) PPC_WEAK_FUNC(sub_8269CA20);
PPC_FUNC_IMPL(__imp__sub_8269CA20) {
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
	ctx.lr = 0x8269CA28;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269CA40;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r30,0
	r30.s64 = 0;
	// addi r26,r11,4272
	r26.s64 = r11.s64 + 4272;
	// mr r29,r26
	r29.u64 = r26.u64;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r28,r11,64
	r28.s64 = r11.s64 + 64;
loc_8269CA5C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82392538
	ctx.lr = 0x8269CA68;
	sub_82392538(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8269cac4
	if (!cr6.gt) goto loc_8269CAC4;
loc_8269CA78:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82393118
	ctx.lr = 0x8269CA88;
	sub_82393118(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82392520
	ctx.lr = 0x8269CA98;
	sub_82392520(ctx, base);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82391d38
	ctx.lr = 0x8269CAB4;
	sub_82391D38(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x8269ca78
	if (cr6.lt) goto loc_8269CA78;
loc_8269CAC4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82392548
	ctx.lr = 0x8269CACC;
	sub_82392548(ctx, base);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r11,r26,20
	r11.s64 = r26.s64 + 20;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8269ca5c
	if (cr6.lt) goto loc_8269CA5C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269CAEC;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8269cb04
	if (!cr6.eq) goto loc_8269CB04;
	// li r11,0
	r11.s64 = 0;
loc_8269CB04:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// lwz r31,1016(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 1016);
	// bl 0x822a3998
	ctx.lr = 0x8269CB14;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// bl 0x82360f90
	ctx.lr = 0x8269CB20;
	sub_82360F90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,20(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x822a3998
	ctx.lr = 0x8269CB34;
	sub_822A3998(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,48(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// lwz r3,-8256(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8256);
	// bl 0x8236d850
	ctx.lr = 0x8269CB50;
	sub_8236D850(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8269CB58"))) PPC_WEAK_FUNC(sub_8269CB58);
PPC_FUNC_IMPL(__imp__sub_8269CB58) {
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
	ctx.lr = 0x8269CB60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,-27684
	ctx.r9.s64 = r11.s64 + -27684;
	// addi r8,r10,-27696
	ctx.r8.s64 = ctx.r10.s64 + -27696;
	// lwz r3,21680(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 21680);
	// addi r28,r29,12
	r28.s64 = r29.s64 + 12;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r8,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r8.u32);
	// beq cr6,0x8269cba4
	if (cr6.eq) goto loc_8269CBA4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269CBA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8269CBA4:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213650
	ctx.lr = 0x8269CBB8;
	sub_82213650(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213650
	ctx.lr = 0x8269CBC8;
	sub_82213650(ctx, base);
	// li r31,9
	r31.s64 = 9;
loc_8269CBCC:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213650
	ctx.lr = 0x8269CBDC;
	sub_82213650(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,14
	cr6.compare<int32_t>(r31.s32, 14, xer);
	// ble cr6,0x8269cbcc
	if (!cr6.gt) goto loc_8269CBCC;
	// li r31,0
	r31.s64 = 0;
loc_8269CBEC:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// addi r4,r31,18
	ctx.r4.s64 = r31.s64 + 18;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213650
	ctx.lr = 0x8269CBFC;
	sub_82213650(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,26
	cr6.compare<int32_t>(r31.s32, 26, xer);
	// blt cr6,0x8269cbec
	if (cr6.lt) goto loc_8269CBEC;
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// addi r3,r3,-15888
	ctx.r3.s64 = ctx.r3.s64 + -15888;
	// bl 0x82392950
	ctx.lr = 0x8269CC14;
	sub_82392950(ctx, base);
	// addis r31,r29,1
	r31.s64 = r29.s64 + 65536;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r31,r31,-15944
	r31.s64 = r31.s64 + -15944;
	// addi r10,r11,-3140
	ctx.r10.s64 = r11.s64 + -3140;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x8269CC30;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8269CC38;
	sub_821D2028(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r8,r9,-21856
	ctx.r8.s64 = ctx.r9.s64 + -21856;
	// stw r8,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r8.u32);
	// bl 0x824e0430
	ctx.lr = 0x8269CC4C;
	sub_824E0430(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269CC54"))) PPC_WEAK_FUNC(sub_8269CC54);
PPC_FUNC_IMPL(__imp__sub_8269CC54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269CC58"))) PPC_WEAK_FUNC(sub_8269CC58);
PPC_FUNC_IMPL(__imp__sub_8269CC58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-2016
	ctx.r3.s64 = r11.s64 + -2016;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269CC64"))) PPC_WEAK_FUNC(sub_8269CC64);
PPC_FUNC_IMPL(__imp__sub_8269CC64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269CC68"))) PPC_WEAK_FUNC(sub_8269CC68);
PPC_FUNC_IMPL(__imp__sub_8269CC68) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x826a0810
	sub_826A0810(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8269CC70"))) PPC_WEAK_FUNC(sub_8269CC70);
PPC_FUNC_IMPL(__imp__sub_8269CC70) {
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
	ctx.lr = 0x8269CC78;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r21,0
	r21.s64 = 0;
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r21
	r27.u64 = r21.u64;
	// ori r26,r11,57856
	r26.u64 = r11.u64 | 57856;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// ori r25,r10,57832
	r25.u64 = ctx.r10.u64 | 57832;
	// ori r23,r9,57848
	r23.u64 = ctx.r9.u64 | 57848;
	// ori r24,r8,57984
	r24.u64 = ctx.r8.u64 | 57984;
	// li r22,-1
	r22.s64 = -1;
loc_8269CCB0:
	// addi r11,r27,14446
	r11.s64 = r27.s64 + 14446;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r28,r31
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x8269cda0
	if (cr6.lt) goto loc_8269CDA0;
	// cmpwi cr6,r27,18
	cr6.compare<int32_t>(r27.s32, 18, xer);
	// bne cr6,0x8269cd14
	if (!cr6.eq) goto loc_8269CD14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82699418
	ctx.lr = 0x8269CCD4;
	sub_82699418(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// lwzx r20,r31,r26
	r20.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// bl 0x822a3998
	ctx.lr = 0x8269CCE4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cntlzw r10,r20
	ctx.r10.u64 = r20.u32 == 0 ? 32 : __builtin_clz(r20.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// addi r30,r11,64
	r30.s64 = r11.s64 + 64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82391ea8
	ctx.lr = 0x8269CD04;
	sub_82391EA8(ctx, base);
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// beq cr6,0x8269cd9c
	if (cr6.eq) goto loc_8269CD9C;
	// stb r21,2140(r30)
	PPC_STORE_U8(r30.u32 + 2140, r21.u8);
	// b 0x8269cd9c
	goto loc_8269CD9C;
loc_8269CD14:
	// cmpwi cr6,r27,12
	cr6.compare<int32_t>(r27.s32, 12, xer);
	// bne cr6,0x8269cd4c
	if (!cr6.eq) goto loc_8269CD4C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// lwzx r30,r31,r25
	r30.u64 = PPC_LOAD_U32(r31.u32 + r25.u32);
	// bl 0x822a3998
	ctx.lr = 0x8269CD2C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cntlzw r10,r30
	ctx.r10.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// bl 0x82391e78
	ctx.lr = 0x8269CD48;
	sub_82391E78(ctx, base);
	// b 0x8269cd9c
	goto loc_8269CD9C;
loc_8269CD4C:
	// cmpwi cr6,r27,16
	cr6.compare<int32_t>(r27.s32, 16, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x8269cd88
	if (!cr6.eq) goto loc_8269CD88;
	// lwzx r4,r31,r23
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r23.u32);
	// bl 0x8269aaf8
	ctx.lr = 0x8269CD60;
	sub_8269AAF8(ctx, base);
	// lbzx r11,r31,r24
	r11.u64 = PPC_LOAD_U8(r31.u32 + r24.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269cd9c
	if (cr6.eq) goto loc_8269CD9C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269CD78;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,84(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// bl 0x8233b4d8
	ctx.lr = 0x8269CD84;
	sub_8233B4D8(ctx, base);
	// b 0x8269cd9c
	goto loc_8269CD9C;
loc_8269CD88:
	// bl 0x82699418
	ctx.lr = 0x8269CD8C;
	sub_82699418(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r5,r28,r31
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// bl 0x8269be90
	ctx.lr = 0x8269CD9C;
	sub_8269BE90(ctx, base);
loc_8269CD9C:
	// stwx r22,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, r22.u32);
loc_8269CDA0:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpwi cr6,r27,49
	cr6.compare<int32_t>(r27.s32, 49, xer);
	// blt cr6,0x8269ccb0
	if (cr6.lt) goto loc_8269CCB0;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,57780
	ctx.r10.u64 = r11.u64 | 57780;
	// stwx r22,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r22.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8269CDC0"))) PPC_WEAK_FUNC(sub_8269CDC0);
PPC_FUNC_IMPL(__imp__sub_8269CDC0) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269CDE8;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8269ce90
	if (cr6.eq) goto loc_8269CE90;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x822a3998
	ctx.lr = 0x8269CE04;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,10
	ctx.r5.s64 = 10;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r31,r11,8109
	r31.s64 = r11.s64 + 8109;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823dd800
	ctx.lr = 0x8269CE24;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8269ce90
	if (cr6.eq) goto loc_8269CE90;
	// bl 0x82178848
	ctx.lr = 0x8269CE30;
	sub_82178848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ce58
	if (cr6.eq) goto loc_8269CE58;
	// bl 0x82178880
	ctx.lr = 0x8269CE40;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ce58
	if (cr6.eq) goto loc_8269CE58;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// b 0x8269ce60
	goto loc_8269CE60;
loc_8269CE58:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,-27652
	ctx.r5.s64 = r11.s64 + -27652;
loc_8269CE60:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8269CE70;
	sub_82137A08(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e06e0
	ctx.lr = 0x8269CE7C;
	sub_824E06E0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269CE90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8269CE90:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

__attribute__((alias("__imp__sub_8269CEA8"))) PPC_WEAK_FUNC(sub_8269CEA8);
PPC_FUNC_IMPL(__imp__sub_8269CEA8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-12040(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12040);
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// lhz r30,492(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 492);
	// bl 0x822a3998
	ctx.lr = 0x8269CEDC;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addic. r10,r30,-1
	xer.ca = r30.u32 > 0;
	ctx.r10.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// addi r8,r11,64
	ctx.r8.s64 = r11.s64 + 64;
	// lbz r11,2127(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2127);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// bne 0x8269cf00
	if (!cr0.eq) goto loc_8269CF00;
	// li r11,0
	r11.s64 = 0;
	// b 0x8269cf40
	goto loc_8269CF40;
loc_8269CF00:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x8269cf40
	if (cr6.lt) goto loc_8269CF40;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// blt cr6,0x8269cf18
	if (cr6.lt) goto loc_8269CF18;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8269CF18:
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r6,r11,r7
	ctx.r6.s32 = r11.s32 / ctx.r7.s32;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// mullw r4,r6,r7
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// andc r3,r7,r5
	ctx.r3.u64 = ctx.r7.u64 & ~ctx.r5.u64;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// twllei r7,0
	// twlgei r3,-1
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_8269CF40:
	// lwz r10,2064(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2064);
	// stb r11,2063(r8)
	PPC_STORE_U8(ctx.r8.u32 + 2063, r11.u8);
	// ori r7,r10,32768
	ctx.r7.u64 = ctx.r10.u64 | 32768;
	// stw r7,2064(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2064, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_8269CF68"))) PPC_WEAK_FUNC(sub_8269CF68);
PPC_FUNC_IMPL(__imp__sub_8269CF68) {
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
	ctx.lr = 0x8269CF70;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r3,32(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269CF8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// ble cr6,0x8269cf9c
	if (!cr6.gt) goto loc_8269CF9C;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_8269CF9C:
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// rlwinm r10,r28,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r11,-12040(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -12040);
	// lwz r8,320(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 320);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lhz r30,100(r7)
	r30.u64 = PPC_LOAD_U16(ctx.r7.u32 + 100);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8269CFC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r24,0
	r24.s64 = 0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r31,r24
	r31.u64 = r24.u64;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// addi r27,r11,9572
	r27.s64 = r11.s64 + 9572;
loc_8269CFDC:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// addi r11,r11,-6
	r11.s64 = r11.s64 + -6;
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// blt cr6,0x8269cff8
	if (cr6.lt) goto loc_8269CFF8;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// b 0x8269d004
	goto loc_8269D004;
loc_8269CFF8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8269d00c
	if (!cr6.lt) goto loc_8269D00C;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
loc_8269D004:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8269d068
	if (cr6.lt) goto loc_8269D068;
loc_8269D00C:
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// bge cr6,0x8269d068
	if (!cr6.lt) goto loc_8269D068;
	// addi r9,r28,12
	ctx.r9.s64 = r28.s64 + 12;
	// lwz r10,-12040(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -12040);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lwzx r6,r6,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// bl 0x82137a08
	ctx.lr = 0x8269D03C;
	sub_82137A08(ctx, base);
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db6d0
	ctx.lr = 0x8269D048;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269d054
	if (cr6.eq) goto loc_8269D054;
	// stb r24,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r24.u8);
loc_8269D054:
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r31,18
	ctx.r4.s64 = r31.s64 + 18;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x8269D068;
	sub_82213B80(ctx, base);
loc_8269D068:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,26
	cr6.compare<int32_t>(r31.s32, 26, xer);
	// blt cr6,0x8269cfdc
	if (cr6.lt) goto loc_8269CFDC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// addi r4,r11,-21664
	ctx.r4.s64 = r11.s64 + -21664;
	// bl 0x821f9fb8
	ctx.lr = 0x8269D084;
	sub_821F9FB8(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r31,r10,2612
	r31.s64 = ctx.r10.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,56(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8269D0A0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x8269D0B0;
	sub_825ED480(ctx, base);
	// lwz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r7,336(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 336);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8269D0C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// subf r4,r6,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r6.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r4,r5,620
	ctx.r4.s64 = ctx.r5.s64 + 620;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// bl 0x82722678
	ctx.lr = 0x8269D0E8;
	sub_82722678(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r3,28728
	ctx.r4.s64 = ctx.r3.s64 + 28728;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x8269D0FC;
	sub_82722678(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8269D104"))) PPC_WEAK_FUNC(sub_8269D104);
PPC_FUNC_IMPL(__imp__sub_8269D104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269D108"))) PPC_WEAK_FUNC(sub_8269D108);
PPC_FUNC_IMPL(__imp__sub_8269D108) {
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
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8269d188
	if (cr6.lt) goto loc_8269D188;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blt cr6,0x8269d188
	if (cr6.lt) goto loc_8269D188;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r4,12
	ctx.r10.s64 = ctx.r4.s64 + 12;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r11,-12040(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12040);
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r7,9572
	ctx.r5.s64 = ctx.r7.s64 + 9572;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r6,r8,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// lwzx r6,r6,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// bl 0x82137a08
	ctx.lr = 0x8269D154;
	sub_82137A08(ctx, base);
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db6d0
	ctx.lr = 0x8269D160;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269d170
	if (cr6.eq) goto loc_8269D170;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
loc_8269D170:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,34
	ctx.r4.s64 = 34;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x8269D188;
	sub_82213B80(ctx, base);
loc_8269D188:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269D198"))) PPC_WEAK_FUNC(sub_8269D198);
PPC_FUNC_IMPL(__imp__sub_8269D198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x8269D1A0;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r31,-32119
	r31.s64 = -2104950784;
	// addis r30,r27,1
	r30.s64 = r27.s64 + 65536;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r30,r30,-7840
	r30.s64 = r30.s64 + -7840;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,-8256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8256);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8236da50
	ctx.lr = 0x8269D1D0;
	sub_8236DA50(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ori r29,r11,57692
	r29.u64 = r11.u64 | 57692;
	// ble cr6,0x8269d200
	if (!cr6.gt) goto loc_8269D200;
	// lwz r3,-8256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8256);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r5,r27,r29
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// bl 0x8236daa0
	ctx.lr = 0x8269D1F0;
	sub_8236DAA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269d200
	if (cr6.eq) goto loc_8269D200;
	// li r28,1
	r28.s64 = 1;
loc_8269D200:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269D210;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// clrlwi r28,r28,24
	r28.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// bne cr6,0x8269d23c
	if (!cr6.eq) goto loc_8269D23C;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r5,r27,r29
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// bl 0x82393118
	ctx.lr = 0x8269D234;
	sub_82393118(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8269d254
	goto loc_8269D254;
loc_8269D23C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r31,r11,2144
	r31.s64 = r11.s64 + 2144;
loc_8269D254:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// ori r9,r10,57708
	ctx.r9.u64 = ctx.r10.u64 | 57708;
	// clrlwi r8,r26,24
	ctx.r8.u64 = r26.u32 & 0xFF;
	// lfs f9,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f9.f64 = double(temp.f32);
	// beq cr6,0x8269d290
	if (cr6.eq) goto loc_8269D290;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8269d2bc
	if (cr6.eq) goto loc_8269D2BC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8269d2bc
	if (cr6.eq) goto loc_8269D2BC;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8269d2bc
	if (cr6.eq) goto loc_8269D2BC;
	// b 0x8269d2b8
	goto loc_8269D2B8;
loc_8269D290:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8269d2bc
	if (!cr6.eq) goto loc_8269D2BC;
	// lwzx r11,r27,r9
	r11.u64 = PPC_LOAD_U32(r27.u32 + ctx.r9.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x8269d2bc
	if (cr6.eq) goto loc_8269D2BC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8269d2b8
	if (cr6.eq) goto loc_8269D2B8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x8269d2bc
	if (!cr6.eq) goto loc_8269D2BC;
loc_8269D2B8:
	// fmuls f31,f31,f9
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f31.f64 * ctx.f9.f64));
loc_8269D2BC:
	// fabs f8,f31
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = f31.u64 & ~0x8000000000000000;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f10,-21460(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21460);
	ctx.f10.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f11,11328(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11328);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1760(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -1760);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fnmsubs f7,f8,f11,f10
	ctx.f7.f64 = double(float(-(ctx.f8.f64 * ctx.f11.f64 - ctx.f10.f64)));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fsel f5,f6,f7,f13
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f7.f64 : ctx.f13.f64;
	// fsubs f4,f5,f12
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f12.f64));
	// fsel f3,f4,f12,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f12.f64 : ctx.f5.f64;
	// fdivs f13,f31,f3
	ctx.f13.f64 = double(float(f31.f64 / ctx.f3.f64));
	// bgt cr6,0x8269d310
	if (cr6.gt) goto loc_8269D310;
	// li r10,-1
	ctx.r10.s64 = -1;
loc_8269D310:
	// lwzx r11,r27,r9
	r11.u64 = PPC_LOAD_U32(r27.u32 + ctx.r9.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x8269d650
	if (cr6.gt) goto loc_8269D650;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-11464
	r12.s64 = r12.s64 + -11464;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8269D354;
	case 1:
		goto loc_8269D454;
	case 2:
		goto loc_8269D53C;
	case 3:
		goto loc_8269D650;
	case 4:
		goto loc_8269D650;
	case 5:
		goto loc_8269D5C4;
	case 6:
		goto loc_8269D630;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-11436(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11436);
	// lwz r19,-11180(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11180);
	// lwz r19,-10948(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10948);
	// lwz r19,-10672(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10672);
	// lwz r19,-10672(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10672);
	// lwz r19,-10812(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10812);
	// lwz r19,-10704(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10704);
loc_8269D354:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8269d368
	if (cr6.eq) goto loc_8269D368;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x8269d370
	if (!cr6.eq) goto loc_8269D370;
loc_8269D368:
	// cntlzw r11,r8
	r11.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r26,r11,27,31,31
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_8269D370:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269d3e8
	if (cr6.eq) goto loc_8269D3E8;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269d3b4
	if (cr6.eq) goto loc_8269D3B4;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8269D3B4:
	// fadds f12,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,14880(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14880);
	f0.f64 = double(temp.f32);
	// lfs f13,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f10,f11,f12,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f1,f9,f13,f10
	ctx.f1.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// bl 0x8213e850
	ctx.lr = 0x8269D3DC;
	sub_8213E850(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8269D3E8:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// addi r3,r31,6
	ctx.r3.s64 = r31.s64 + 6;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269d420
	if (cr6.eq) goto loc_8269D420;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8269D420:
	// fadds f12,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,14880(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14880);
	f0.f64 = double(temp.f32);
	// lfs f13,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f10,f11,f12,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f1,f9,f13,f10
	ctx.f1.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// bl 0x8213e850
	ctx.lr = 0x8269D448;
	sub_8213E850(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8269D454:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8269d4d0
	if (!cr6.eq) goto loc_8269D4D0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8269d4d0
	if (!cr6.eq) goto loc_8269D4D0;
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// addi r3,r31,2
	ctx.r3.s64 = r31.s64 + 2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269d49c
	if (cr6.eq) goto loc_8269D49C;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8269D49C:
	// fadds f12,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-28424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28424);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f10,f11,f12,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f1,f9,f13,f10
	ctx.f1.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// bl 0x8213e850
	ctx.lr = 0x8269D4C4;
	sub_8213E850(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8269D4D0:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269d504
	if (cr6.eq) goto loc_8269D504;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8269D504:
	// fadds f12,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-28424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28424);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f10,f11,f12,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f1,f9,f13,f10
	ctx.f1.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// bl 0x8213e850
	ctx.lr = 0x8269D530;
	sub_8213E850(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8269D53C:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8269d650
	if (cr6.eq) goto loc_8269D650;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,32680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32680);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f31,f13
	cr6.compare(f31.f64, ctx.f13.f64);
	// ble cr6,0x8269d560
	if (!cr6.gt) goto loc_8269D560;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f31,f13
	f31.f64 = double(float(f31.f64 * ctx.f13.f64));
loc_8269D560:
	// addi r31,r31,14
	r31.s64 = r31.s64 + 14;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269d598
	if (cr6.eq) goto loc_8269D598;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8269D598:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f1,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f0.f64 + f31.f64));
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lfs f3,30284(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30284);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-27644(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -27644);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82151fe0
	ctx.lr = 0x8269D5B0;
	sub_82151FE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213e850
	ctx.lr = 0x8269D5B8;
	sub_8213E850(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8269D5C4:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8269d650
	if (cr6.eq) goto loc_8269D650;
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269d604
	if (cr6.eq) goto loc_8269D604;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8269D604:
	// fadds f13,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f9
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fsel f11,f12,f13,f9
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : ctx.f9.f64;
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f1,f10,f0,f11
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// bl 0x8213e850
	ctx.lr = 0x8269D624;
	sub_8213E850(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8269D630:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8269d650
	if (cr6.eq) goto loc_8269D650;
	// lbz r11,18(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82250268
	ctx.lr = 0x8269D64C;
	sub_82250268(ctx, base);
	// stb r3,18(r31)
	PPC_STORE_U8(r31.u32 + 18, ctx.r3.u8);
loc_8269D650:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8269D65C"))) PPC_WEAK_FUNC(sub_8269D65C);
PPC_FUNC_IMPL(__imp__sub_8269D65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269D660"))) PPC_WEAK_FUNC(sub_8269D660);
PPC_FUNC_IMPL(__imp__sub_8269D660) {
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
	ctx.lr = 0x8269D668;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x8269d774
	if (cr6.lt) goto loc_8269D774;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269D690;
	sub_822A3998(ctx, base);
	// lwz r26,48(r3)
	r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// lwz r11,132(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 132);
	// addi r30,r11,64
	r30.s64 = r11.s64 + 64;
	// blt cr6,0x8269d6e4
	if (cr6.lt) goto loc_8269D6E4;
	// lis r11,0
	r11.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r10,r11,57696
	ctx.r10.u64 = r11.u64 | 57696;
	// lwzx r3,r28,r10
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	// bl 0x823924d0
	ctx.lr = 0x8269D6B8;
	sub_823924D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823924e0
	ctx.lr = 0x8269D6C4;
	sub_823924E0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82393118
	ctx.lr = 0x8269D6D4;
	sub_82393118(ctx, base);
	// bl 0x8236e2e8
	ctx.lr = 0x8269D6D8;
	sub_8236E2E8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82392510
	ctx.lr = 0x8269D6E0;
	sub_82392510(ctx, base);
	// b 0x8269d738
	goto loc_8269D738;
loc_8269D6E4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82392538
	ctx.lr = 0x8269D6F0;
	sub_82392538(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r11,4272
	r28.s64 = r11.s64 + 4272;
	// li r31,0
	r31.s64 = 0;
	// lwzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8269d730
	if (!cr6.gt) goto loc_8269D730;
loc_8269D70C:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82393118
	ctx.lr = 0x8269D71C;
	sub_82393118(ctx, base);
	// bl 0x8236e2e8
	ctx.lr = 0x8269D720;
	sub_8236E2E8(ctx, base);
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8269d70c
	if (cr6.lt) goto loc_8269D70C;
loc_8269D730:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82392548
	ctx.lr = 0x8269D738;
	sub_82392548(ctx, base);
loc_8269D738:
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8269d74c
	if (!cr6.eq) goto loc_8269D74C;
	// li r11,0
	r11.s64 = 0;
loc_8269D74C:
	// lwz r3,80(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 80);
	// lwz r31,1016(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 1016);
	// bl 0x82360f90
	ctx.lr = 0x8269D758;
	sub_82360F90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r5,20(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r3,-8256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8256);
	// bl 0x8236d850
	ctx.lr = 0x8269D774;
	sub_8236D850(ctx, base);
loc_8269D774:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8269D77C"))) PPC_WEAK_FUNC(sub_8269D77C);
PPC_FUNC_IMPL(__imp__sub_8269D77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269D780"))) PPC_WEAK_FUNC(sub_8269D780);
PPC_FUNC_IMPL(__imp__sub_8269D780) {
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
	ctx.lr = 0x8269D788;
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r10,-27620
	ctx.r4.s64 = ctx.r10.s64 + -27620;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821ca540
	ctx.lr = 0x8269D7B0;
	sub_821CA540(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269D7C0;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269D7C8;
	sub_82332098(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8269d7e8
	if (cr6.eq) goto loc_8269D7E8;
loc_8269D7D8:
	// bl 0x821c9a90
	ctx.lr = 0x8269D7DC;
	sub_821C9A90(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x823d9240
	return;
loc_8269D7E8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r5,r11,-27624
	ctx.r5.s64 = r11.s64 + -27624;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x8269D800;
	sub_821CA6A8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8269d7d8
	if (cr6.eq) goto loc_8269D7D8;
	// bl 0x821c9a90
	ctx.lr = 0x8269D814;
	sub_821C9A90(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-29924
	ctx.r9.s64 = r11.s64 + -29924;
	// stw r10,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r10.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,4416(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4416);
	// bl 0x821cf7b8
	ctx.lr = 0x8269D83C;
	sub_821CF7B8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0490
	ctx.lr = 0x8269D848;
	sub_821D0490(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// add r29,r27,r31
	r29.u64 = r27.u64 + r31.u64;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// bge cr6,0x8269d8ac
	if (!cr6.lt) goto loc_8269D8AC;
	// mulli r11,r31,168
	r11.s64 = r31.s64 * 168;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r30,r11,28
	r30.s64 = r11.s64 + 28;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r28,r11,-27640
	r28.s64 = r11.s64 + -27640;
loc_8269D86C:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,80
	ctx.r5.s64 = 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cffe8
	ctx.lr = 0x8269D884;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8269d86c
	if (cr6.eq) goto loc_8269D86C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x8269D89C;
	sub_82130000(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,168
	r30.s64 = r30.s64 + 168;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x8269d86c
	if (cr6.lt) goto loc_8269D86C;
loc_8269D8AC:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be610
	ctx.lr = 0x8269D8B4;
	sub_821BE610(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8269D8C0"))) PPC_WEAK_FUNC(sub_8269D8C0);
PPC_FUNC_IMPL(__imp__sub_8269D8C0) {
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
	ctx.lr = 0x8269D8C8;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-27620
	ctx.r4.s64 = ctx.r10.s64 + -27620;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x8269D8E8;
	sub_821CA540(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269D8F8;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269D900;
	sub_82332098(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r4,25
	ctx.r4.s64 = 25;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x8269d920
	if (cr6.eq) goto loc_8269D920;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,-27536
	ctx.r5.s64 = r11.s64 + -27536;
	// b 0x8269d928
	goto loc_8269D928;
loc_8269D920:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,-27556
	ctx.r5.s64 = r11.s64 + -27556;
loc_8269D928:
	// bl 0x82137a08
	ctx.lr = 0x8269D92C;
	sub_82137A08(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,-27624
	ctx.r5.s64 = r11.s64 + -27624;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca6a8
	ctx.lr = 0x8269D948;
	sub_821CA6A8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x8269d968
	if (!cr6.eq) goto loc_8269D968;
	// bl 0x821c9a90
	ctx.lr = 0x8269D95C;
	sub_821C9A90(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d9240
	return;
loc_8269D968:
	// bl 0x821c9a90
	ctx.lr = 0x8269D96C;
	sub_821C9A90(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-29924
	ctx.r9.s64 = r11.s64 + -29924;
	// stw r10,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r10.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,4416(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4416);
	// bl 0x821cf7b8
	ctx.lr = 0x8269D994;
	sub_821CF7B8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269D9A0;
	sub_822A3998(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// lwz r31,132(r6)
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + 132);
	// bl 0x821d0490
	ctx.lr = 0x8269D9B8;
	sub_821D0490(ctx, base);
	// addi r5,r31,8109
	ctx.r5.s64 = r31.s64 + 8109;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x82699f38
	ctx.lr = 0x8269D9D0;
	sub_82699F38(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8269d9f0
	if (cr6.eq) goto loc_8269D9F0;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r28,28
	ctx.r3.s64 = r28.s64 + 28;
	// bl 0x82137a08
	ctx.lr = 0x8269D9E8;
	sub_82137A08(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_8269D9F0:
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x8269da4c
	if (!cr6.lt) goto loc_8269DA4C;
	// mulli r11,r31,168
	r11.s64 = r31.s64 * 168;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r29,r11,28
	r29.s64 = r11.s64 + 28;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r27,r11,-27640
	r27.s64 = r11.s64 + -27640;
loc_8269DA0C:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,80
	ctx.r5.s64 = 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821cffe8
	ctx.lr = 0x8269DA24;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8269da0c
	if (cr6.eq) goto loc_8269DA0C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x8269DA3C;
	sub_82130000(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,168
	r29.s64 = r29.s64 + 168;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x8269da0c
	if (cr6.lt) goto loc_8269DA0C;
loc_8269DA4C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r31,r30
	r31.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x8269DA58;
	sub_821BE610(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r10,r11,-28304
	ctx.r10.s64 = r11.s64 + -28304;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8269da7c
	if (!cr6.eq) goto loc_8269DA7C;
	// lbz r11,21670(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 21670);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269da98
	if (cr6.eq) goto loc_8269DA98;
loc_8269DA7C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,-27580
	ctx.r5.s64 = r11.s64 + -27580;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269d780
	ctx.lr = 0x8269DA90;
	sub_8269D780(ctx, base);
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_8269DA98:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,-27604
	ctx.r5.s64 = r11.s64 + -27604;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269d780
	ctx.lr = 0x8269DAAC;
	sub_8269D780(ctx, base);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8269DAB8"))) PPC_WEAK_FUNC(sub_8269DAB8);
PPC_FUNC_IMPL(__imp__sub_8269DAB8) {
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
	ctx.lr = 0x8269DAC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238f1f0
	ctx.lr = 0x8269DAD4;
	sub_8238F1F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238f6b0
	ctx.lr = 0x8269DADC;
	sub_8238F6B0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238f1e8
	ctx.lr = 0x8269DAE8;
	sub_8238F1E8(ctx, base);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mulli r31,r3,104
	r31.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// add r3,r31,r11
	ctx.r3.u64 = r31.u64 + r11.u64;
	// bl 0x82396110
	ctx.lr = 0x8269DAFC;
	sub_82396110(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269db64
	if (cr6.eq) goto loc_8269DB64;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-27376
	ctx.r4.s64 = ctx.r10.s64 + -27376;
loc_8269DB10:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r28,3
	cr6.compare<int32_t>(r28.s32, 3, xer);
	// lwz r31,-10244(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x8269db34
	if (!cr6.eq) goto loc_8269DB34;
	// bl 0x82218310
	ctx.lr = 0x8269DB28;
	sub_82218310(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r4,r9,-27396
	ctx.r4.s64 = ctx.r9.s64 + -27396;
	// b 0x8269dbc4
	goto loc_8269DBC4;
loc_8269DB34:
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// bne cr6,0x8269db4c
	if (!cr6.eq) goto loc_8269DB4C;
	// bl 0x82218310
	ctx.lr = 0x8269DB40;
	sub_82218310(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r4,r9,-27416
	ctx.r4.s64 = ctx.r9.s64 + -27416;
	// b 0x8269dbc4
	goto loc_8269DBC4;
loc_8269DB4C:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bne cr6,0x8269dbb8
	if (!cr6.eq) goto loc_8269DBB8;
	// bl 0x82218310
	ctx.lr = 0x8269DB58;
	sub_82218310(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r4,r9,-27436
	ctx.r4.s64 = ctx.r9.s64 + -27436;
	// b 0x8269dbc4
	goto loc_8269DBC4;
loc_8269DB64:
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// add r3,r31,r11
	ctx.r3.u64 = r31.u64 + r11.u64;
	// bl 0x82396130
	ctx.lr = 0x8269DB70;
	sub_82396130(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269db88
	if (cr6.eq) goto loc_8269DB88;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-27452
	ctx.r4.s64 = ctx.r10.s64 + -27452;
	// b 0x8269db10
	goto loc_8269DB10;
loc_8269DB88:
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// add r3,r31,r11
	ctx.r3.u64 = r31.u64 + r11.u64;
	// bl 0x82396158
	ctx.lr = 0x8269DB94;
	sub_82396158(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269dbac
	if (cr6.eq) goto loc_8269DBAC;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-27468
	ctx.r4.s64 = ctx.r10.s64 + -27468;
	// b 0x8269db10
	goto loc_8269DB10;
loc_8269DBAC:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-27484
	ctx.r4.s64 = ctx.r10.s64 + -27484;
	// b 0x8269db10
	goto loc_8269DB10;
loc_8269DBB8:
	// bl 0x82218310
	ctx.lr = 0x8269DBBC;
	sub_82218310(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r4,r9,-27504
	ctx.r4.s64 = ctx.r9.s64 + -27504;
loc_8269DBC4:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x8269DBD0;
	sub_82218310(ctx, base);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r5,r8,-27512
	ctx.r5.s64 = ctx.r8.s64 + -27512;
	// li r4,80
	ctx.r4.s64 = 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x8269DBEC;
	sub_82137A08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269DBF4"))) PPC_WEAK_FUNC(sub_8269DBF4);
PPC_FUNC_IMPL(__imp__sub_8269DBF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269DBF8"))) PPC_WEAK_FUNC(sub_8269DBF8);
PPC_FUNC_IMPL(__imp__sub_8269DBF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x8269DC00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2176
	ctx.r6.s64 = ctx.r8.s64 + 2176;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r9,2176(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2176);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r9,r5
	ctx.r10.s64 = ctx.r9.s64 * ctx.r5.s64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// li r30,-1
	r30.s64 = -1;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2176, r11.u32);
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// srawi r7,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r31,r5,r8
	r31.s64 = ctx.r8.s64 - ctx.r5.s64;
	// bl 0x822a3998
	ctx.lr = 0x8269DC5C;
	sub_822A3998(ctx, base);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238f1e8
	ctx.lr = 0x8269DC64;
	sub_8238F1E8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8269DC6C;
	sub_82387B90(ctx, base);
	// mulli r4,r27,84
	ctx.r4.s64 = r27.s64 * 84;
	// lwz r11,17268(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addis r27,r10,4
	r27.s64 = ctx.r10.s64 + 262144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r27,r27,-15504
	r27.s64 = r27.s64 + -15504;
	// bl 0x822a3998
	ctx.lr = 0x8269DC8C;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269DC94;
	sub_82332098(ctx, base);
	// lwz r11,17268(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822a3998
	ctx.lr = 0x8269DCA8;
	sub_822A3998(ctx, base);
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r3,r11,8109
	ctx.r3.s64 = r11.s64 + 8109;
	// addi r4,r9,-29820
	ctx.r4.s64 = ctx.r9.s64 + -29820;
	// bl 0x823d90b0
	ctx.lr = 0x8269DCBC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269dcd0
	if (cr6.eq) goto loc_8269DCD0;
loc_8269DCC4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269DCD0:
	// cmplwi cr6,r28,4
	cr6.compare<uint32_t>(r28.u32, 4, xer);
	// bgt cr6,0x8269de24
	if (cr6.gt) goto loc_8269DE24;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-8976
	r12.s64 = r12.s64 + -8976;
	// rlwinm r0,r28,2,0,29
	r0.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r28.u64) {
	case 0:
		goto loc_8269DD04;
	case 1:
		goto loc_8269DD58;
	case 2:
		goto loc_8269DDA4;
	case 3:
		goto loc_8269DDE8;
	case 4:
		goto loc_8269DE14;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-8956(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8956);
	// lwz r19,-8872(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8872);
	// lwz r19,-8796(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8796);
	// lwz r19,-8728(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8728);
	// lwz r19,-8684(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8684);
loc_8269DD04:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269dd18
	if (cr6.eq) goto loc_8269DD18;
	// li r30,2
	r30.s64 = 2;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DD18:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x8269dd28
	if (!cr6.eq) goto loc_8269DD28;
	// li r30,11
	r30.s64 = 11;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DD28:
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// bne cr6,0x8269dd38
	if (!cr6.eq) goto loc_8269DD38;
	// li r30,12
	r30.s64 = 12;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DD38:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269dd48
	if (!cr6.eq) goto loc_8269DD48;
	// li r30,13
	r30.s64 = 13;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DD48:
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// bne cr6,0x8269de24
	if (!cr6.eq) goto loc_8269DE24;
	// li r30,17
	r30.s64 = 17;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DD58:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269dd6c
	if (cr6.eq) goto loc_8269DD6C;
	// li r30,4
	r30.s64 = 4;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DD6C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8269dd9c
	if (cr6.eq) goto loc_8269DD9C;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// beq cr6,0x8269dd9c
	if (cr6.eq) goto loc_8269DD9C;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269dd8c
	if (!cr6.eq) goto loc_8269DD8C;
	// li r30,46
	r30.s64 = 46;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DD8C:
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// bne cr6,0x8269de24
	if (!cr6.eq) goto loc_8269DE24;
	// li r30,43
	r30.s64 = 43;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DD9C:
	// li r30,45
	r30.s64 = 45;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DDA4:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ddb8
	if (cr6.eq) goto loc_8269DDB8;
	// li r30,3
	r30.s64 = 3;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DDB8:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8269dde0
	if (cr6.eq) goto loc_8269DDE0;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// beq cr6,0x8269dde0
	if (cr6.eq) goto loc_8269DDE0;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269ddd8
	if (cr6.eq) goto loc_8269DDD8;
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// bne cr6,0x8269de24
	if (!cr6.eq) goto loc_8269DE24;
loc_8269DDD8:
	// li r30,19
	r30.s64 = 19;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DDE0:
	// li r30,18
	r30.s64 = 18;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DDE8:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269dcc4
	if (!cr6.eq) goto loc_8269DCC4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8269de0c
	if (cr6.eq) goto loc_8269DE0C;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// beq cr6,0x8269de0c
	if (cr6.eq) goto loc_8269DE0C;
	// li r30,14
	r30.s64 = 14;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DE0C:
	// li r30,10
	r30.s64 = 10;
	// b 0x8269de24
	goto loc_8269DE24;
loc_8269DE14:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269dcc4
	if (!cr6.eq) goto loc_8269DCC4;
	// li r30,21
	r30.s64 = 21;
loc_8269DE24:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823901c0
	ctx.lr = 0x8269DE34;
	sub_823901C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269dcc4
	if (!cr6.eq) goto loc_8269DCC4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823900e0
	ctx.lr = 0x8269DE54;
	sub_823900E0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8269DE60"))) PPC_WEAK_FUNC(sub_8269DE60);
PPC_FUNC_IMPL(__imp__sub_8269DE60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8269DE68;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8268daf8
	ctx.lr = 0x8269DE7C;
	sub_8268DAF8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r24,0
	r24.s64 = 0;
	// addi r27,r11,-12120
	r27.s64 = r11.s64 + -12120;
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269df84
	if (cr6.eq) goto loc_8269DF84;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r28,0
	r28.s64 = 0;
	// addi r29,r31,28
	r29.s64 = r31.s64 + 28;
	// li r23,5
	r23.s64 = 5;
	// addi r22,r9,-28272
	r22.s64 = ctx.r9.s64 + -28272;
	// addi r26,r10,-27360
	r26.s64 = ctx.r10.s64 + -27360;
	// addi r25,r11,9572
	r25.s64 = r11.s64 + 9572;
loc_8269DEB8:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// addic. r30,r10,8109
	xer.ca = ctx.r10.u32 > 4294959186;
	r30.s64 = ctx.r10.s64 + 8109;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x8269df84
	if (cr0.eq) goto loc_8269DF84;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8268db80
	ctx.lr = 0x8269DED4;
	sub_8268DB80(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8269df84
	if (cr6.eq) goto loc_8269DF84;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269DEF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,80
	ctx.r4.s64 = 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x8269DF08;
	sub_82137A08(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// add r3,r28,r11
	ctx.r3.u64 = r28.u64 + r11.u64;
	// bl 0x82396488
	ctx.lr = 0x8269DF14;
	sub_82396488(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r29,80
	ctx.r3.s64 = r29.s64 + 80;
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82137a08
	ctx.lr = 0x8269DF28;
	sub_82137A08(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8269DF38;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269df48
	if (cr6.eq) goto loc_8269DF48;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stw r23,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r23.u32);
loc_8269DF48:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8269DF58;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269df6c
	if (cr6.eq) goto loc_8269DF6C;
	// addi r11,r29,3
	r11.s64 = r29.s64 + 3;
	// stw r23,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r23.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_8269DF6C:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r28,r28,104
	r28.s64 = r28.s64 + 104;
	// addi r29,r29,168
	r29.s64 = r29.s64 + 168;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x8269deb8
	if (cr6.lt) goto loc_8269DEB8;
loc_8269DF84:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8269DF8C"))) PPC_WEAK_FUNC(sub_8269DF8C);
PPC_FUNC_IMPL(__imp__sub_8269DF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269DF90"))) PPC_WEAK_FUNC(sub_8269DF90);
PPC_FUNC_IMPL(__imp__sub_8269DF90) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269DFB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12120);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,100(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 100);
	// bl 0x8269a1e0
	ctx.lr = 0x8269DFCC;
	sub_8269A1E0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269DFDC"))) PPC_WEAK_FUNC(sub_8269DFDC);
PPC_FUNC_IMPL(__imp__sub_8269DFDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269DFE0"))) PPC_WEAK_FUNC(sub_8269DFE0);
PPC_FUNC_IMPL(__imp__sub_8269DFE0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E008;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// bl 0x82387b90
	ctx.lr = 0x8269E014;
	sub_82387B90(ctx, base);
	// mulli r11,r30,8176
	r11.s64 = r30.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8269a1e0
	ctx.lr = 0x8269E028;
	sub_8269A1E0(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8269E02C;
	sub_82387B90(ctx, base);
	// lis r10,3
	ctx.r10.s64 = 196608;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// stw r30,1344(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1344, r30.u32);
	// ori r9,r10,57424
	ctx.r9.u64 = ctx.r10.u64 | 57424;
	// li r7,1
	ctx.r7.s64 = 1;
	// stbx r7,r3,r9
	PPC_STORE_U8(ctx.r3.u32 + ctx.r9.u32, ctx.r7.u8);
	// lwz r11,-29336(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -29336);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8269e064
	if (!cr6.eq) goto loc_8269E064;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269E064;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8269E064:
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

__attribute__((alias("__imp__sub_8269E07C"))) PPC_WEAK_FUNC(sub_8269E07C);
PPC_FUNC_IMPL(__imp__sub_8269E07C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269E080"))) PPC_WEAK_FUNC(sub_8269E080);
PPC_FUNC_IMPL(__imp__sub_8269E080) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E0A4;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,132(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// bl 0x82390558
	ctx.lr = 0x8269E0B0;
	sub_82390558(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r6,r9,39524
	ctx.r6.u64 = ctx.r9.u64 | 39524;
	// ori r5,r8,49436
	ctx.r5.u64 = ctx.r8.u64 | 49436;
	// ori r4,r7,49440
	ctx.r4.u64 = ctx.r7.u64 | 49440;
	// li r11,32
	r11.s64 = 32;
	// li r10,0
	ctx.r10.s64 = 0;
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// stwx r10,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r10.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stwx r3,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// addi r7,r9,-29032
	ctx.r7.s64 = ctx.r9.s64 + -29032;
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r5,r8,9572
	ctx.r5.s64 = ctx.r8.s64 + 9572;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r3,-16092
	ctx.r3.s64 = ctx.r3.s64 + -16092;
	// lwz r6,128(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 128);
	// bl 0x82137a08
	ctx.lr = 0x8269E100;
	sub_82137A08(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269E114"))) PPC_WEAK_FUNC(sub_8269E114);
PPC_FUNC_IMPL(__imp__sub_8269E114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269E118"))) PPC_WEAK_FUNC(sub_8269E118);
PPC_FUNC_IMPL(__imp__sub_8269E118) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E13C;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,132(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// bl 0x8238f9d0
	ctx.lr = 0x8269E148;
	sub_8238F9D0(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r6,r9,39524
	ctx.r6.u64 = ctx.r9.u64 | 39524;
	// ori r5,r8,49436
	ctx.r5.u64 = ctx.r8.u64 | 49436;
	// ori r4,r7,49440
	ctx.r4.u64 = ctx.r7.u64 | 49440;
	// li r11,30
	r11.s64 = 30;
	// li r10,0
	ctx.r10.s64 = 0;
	// stwx r11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r11.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// stwx r10,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, ctx.r10.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stwx r3,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// addi r7,r9,-29032
	ctx.r7.s64 = ctx.r9.s64 + -29032;
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r5,r8,9572
	ctx.r5.s64 = ctx.r8.s64 + 9572;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r3,-16092
	ctx.r3.s64 = ctx.r3.s64 + -16092;
	// lwz r6,120(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 120);
	// bl 0x82137a08
	ctx.lr = 0x8269E198;
	sub_82137A08(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269E1AC"))) PPC_WEAK_FUNC(sub_8269E1AC);
PPC_FUNC_IMPL(__imp__sub_8269E1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269E1B0"))) PPC_WEAK_FUNC(sub_8269E1B0);
PPC_FUNC_IMPL(__imp__sub_8269E1B0) {
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
	ctx.lr = 0x8269E1B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-2176
	ctx.r4.s64 = r11.s64 + -2176;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268da78
	ctx.lr = 0x8269E1D8;
	sub_8268DA78(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,4(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E1F0;
	sub_822A3998(ctx, base);
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// clrlwi r4,r29,24
	ctx.r4.u64 = r29.u32 & 0xFF;
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// bl 0x82391e00
	ctx.lr = 0x8269E204;
	sub_82391E00(ctx, base);
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r28,r28,-26012
	r28.s64 = r28.s64 + -26012;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-19624
	ctx.r4.s64 = ctx.r6.s64 + -19624;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r7,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r7.u32);
	// bl 0x8268da78
	ctx.lr = 0x8269E228;
	sub_8268DA78(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// ori r11,r5,49436
	r11.u64 = ctx.r5.u64 | 49436;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// ori r9,r4,49440
	ctx.r9.u64 = ctx.r4.u64 | 49440;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r8,-29032
	ctx.r6.s64 = ctx.r8.s64 + -29032;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stwx r29,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r29.u32);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r5,9572
	ctx.r5.s64 = ctx.r5.s64 + 9572;
	// addi r3,r3,-16092
	ctx.r3.s64 = ctx.r3.s64 + -16092;
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// bl 0x82137a08
	ctx.lr = 0x8269E270;
	sub_82137A08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269E278"))) PPC_WEAK_FUNC(sub_8269E278);
PPC_FUNC_IMPL(__imp__sub_8269E278) {
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
	ctx.lr = 0x8269E280;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-2176
	ctx.r4.s64 = r11.s64 + -2176;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268da78
	ctx.lr = 0x8269E2A0;
	sub_8268DA78(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,4(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E2B8;
	sub_822A3998(ctx, base);
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// clrlwi r4,r29,24
	ctx.r4.u64 = r29.u32 & 0xFF;
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// bl 0x82391de8
	ctx.lr = 0x8269E2CC;
	sub_82391DE8(ctx, base);
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// li r7,31
	ctx.r7.s64 = 31;
	// addi r28,r28,-26012
	r28.s64 = r28.s64 + -26012;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-19624
	ctx.r4.s64 = ctx.r6.s64 + -19624;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r7,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r7.u32);
	// bl 0x8268da78
	ctx.lr = 0x8269E2F0;
	sub_8268DA78(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// ori r11,r5,49436
	r11.u64 = ctx.r5.u64 | 49436;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// ori r9,r4,49440
	ctx.r9.u64 = ctx.r4.u64 | 49440;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r8,-29032
	ctx.r6.s64 = ctx.r8.s64 + -29032;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stwx r29,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r29.u32);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r5,9572
	ctx.r5.s64 = ctx.r5.s64 + 9572;
	// addi r3,r3,-16092
	ctx.r3.s64 = ctx.r3.s64 + -16092;
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// bl 0x82137a08
	ctx.lr = 0x8269E338;
	sub_82137A08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269E340"))) PPC_WEAK_FUNC(sub_8269E340);
PPC_FUNC_IMPL(__imp__sub_8269E340) {
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
	ctx.lr = 0x8269E348;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-2176
	ctx.r4.s64 = r11.s64 + -2176;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268da78
	ctx.lr = 0x8269E368;
	sub_8268DA78(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,4(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E380;
	sub_822A3998(ctx, base);
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// clrlwi r4,r29,24
	ctx.r4.u64 = r29.u32 & 0xFF;
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// bl 0x82391e18
	ctx.lr = 0x8269E394;
	sub_82391E18(ctx, base);
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// li r7,30
	ctx.r7.s64 = 30;
	// addi r28,r28,-26012
	r28.s64 = r28.s64 + -26012;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-19624
	ctx.r4.s64 = ctx.r6.s64 + -19624;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r7,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r7.u32);
	// bl 0x8268da78
	ctx.lr = 0x8269E3B8;
	sub_8268DA78(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// ori r11,r5,49436
	r11.u64 = ctx.r5.u64 | 49436;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// ori r9,r4,49440
	ctx.r9.u64 = ctx.r4.u64 | 49440;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r8,-29032
	ctx.r6.s64 = ctx.r8.s64 + -29032;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stwx r29,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r29.u32);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r5,9572
	ctx.r5.s64 = ctx.r5.s64 + 9572;
	// addi r3,r3,-16092
	ctx.r3.s64 = ctx.r3.s64 + -16092;
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// bl 0x82137a08
	ctx.lr = 0x8269E400;
	sub_82137A08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269E408"))) PPC_WEAK_FUNC(sub_8269E408);
PPC_FUNC_IMPL(__imp__sub_8269E408) {
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
	ctx.lr = 0x8269E410;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// addis r31,r28,1
	r31.s64 = r28.s64 + 65536;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// addi r31,r31,-23552
	r31.s64 = r31.s64 + -23552;
	// mr r26,r23
	r26.u64 = r23.u64;
	// mr r30,r23
	r30.u64 = r23.u64;
	// ori r29,r10,50032
	r29.u64 = ctx.r10.u64 | 50032;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r25,r11,-27348
	r25.s64 = r11.s64 + -27348;
loc_8269E444:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269e4c4
	if (cr6.eq) goto loc_8269E4C4;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E45C;
	sub_822A3998(ctx, base);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238f1e8
	ctx.lr = 0x8269E464;
	sub_8238F1E8(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8269E46C;
	sub_82387B90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269ba28
	ctx.lr = 0x8269E480;
	sub_8269BA28(ctx, base);
	// mulli r11,r22,84
	r11.s64 = r22.s64 * 84;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x823901c0
	ctx.lr = 0x8269E494;
	sub_823901C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269e4ac
	if (!cr6.eq) goto loc_8269E4AC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r26,r11,r26
	r26.u64 = r11.u64 + r26.u64;
	// b 0x8269e4b4
	goto loc_8269E4B4;
loc_8269E4AC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130000
	ctx.lr = 0x8269E4B4;
	sub_82130000(ctx, base);
loc_8269E4B4:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e4c4
	if (!cr6.eq) goto loc_8269E4C4;
	// stb r23,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r23.u8);
loc_8269E4C4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,152
	r31.s64 = r31.s64 + 152;
	// cmpwi cr6,r30,49
	cr6.compare<int32_t>(r30.s32, 49, xer);
	// blt cr6,0x8269e444
	if (cr6.lt) goto loc_8269E444;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8269E4E0"))) PPC_WEAK_FUNC(sub_8269E4E0);
PPC_FUNC_IMPL(__imp__sub_8269E4E0) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8269E4E8;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d8
	ctx.lr = 0x8269E4F0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r4,8109
	ctx.r3.s64 = ctx.r4.s64 + 8109;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// addi r31,r4,20
	r31.s64 = ctx.r4.s64 + 20;
	// bl 0x82396408
	ctx.lr = 0x8269E508;
	sub_82396408(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E51C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8269e878
	if (cr6.eq) goto loc_8269E878;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E534;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x8269e794
	if (cr6.eq) goto loc_8269E794;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// beq cr6,0x8269e69c
	if (cr6.eq) goto loc_8269E69C;
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// bne cr6,0x8269e878
	if (!cr6.eq) goto loc_8269E878;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82398018
	ctx.lr = 0x8269E560;
	sub_82398018(ctx, base);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82398018
	ctx.lr = 0x8269E574;
	sub_82398018(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// bl 0x82398018
	ctx.lr = 0x8269E58C;
	sub_82398018(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// bl 0x82398018
	ctx.lr = 0x8269E5A4;
	sub_82398018(ctx, base);
	// lwz r11,17268(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// add r31,r10,r31
	r31.u64 = ctx.r10.u64 + r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x8269E5BC;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x8269E5C4;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mulli r10,r31,50
	ctx.r10.s64 = r31.s64 * 50;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e5d8
	if (!cr6.eq) goto loc_8269E5D8;
	// mulli r10,r31,13
	ctx.r10.s64 = r31.s64 * 13;
loc_8269E5D8:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x8269e5e8
	if (!cr6.lt) goto loc_8269E5E8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8269e5f4
	goto loc_8269E5F4;
loc_8269E5E8:
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// ble cr6,0x8269e5f4
	if (!cr6.gt) goto loc_8269E5F4;
	// li r10,100
	ctx.r10.s64 = 100;
loc_8269E5F4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mulli r9,r27,104
	ctx.r9.s64 = r27.s64 * 104;
	// lwz r11,-12120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12120);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f12,84(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,31016(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f10,80(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f0,11360(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fctiwz f8,f11
	ctx.f8.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f7,f9
	ctx.f7.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// subf r3,r6,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r6.s64;
	// lfd f5,80(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f3,80(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f6
	ctx.f1.f64 = double(float(ctx.f6.f64));
	// frsp f13,f4
	ctx.f13.f64 = double(float(ctx.f4.f64));
	// frsp f12,f2
	ctx.f12.f64 = double(float(ctx.f2.f64));
	// fmuls f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fnmsubs f10,f12,f11,f13
	ctx.f10.f64 = double(float(-(ctx.f12.f64 * ctx.f11.f64 - ctx.f13.f64)));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f9,0,r28
	PPC_STORE_U32(r28.u32, ctx.f9.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x8269E698;
	// b 0x823d9244
	return;
loc_8269E69C:
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r8,108(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// lwz r7,104(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// lwz r6,128(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// lwz r3,16(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r5,144(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	// lfs f0,112(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 112);
	f0.f64 = double(temp.f32);
	// lwz r4,144(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 144);
	// lfs f31,112(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 112);
	f31.f64 = double(temp.f32);
	// lfs f30,192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 192);
	f30.f64 = double(temp.f32);
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f29,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f29.f64 = double(temp.f32);
	// fdivs f28,f13,f0
	f28.f64 = double(float(ctx.f13.f64 / f0.f64));
	// bl 0x82558590
	ctx.lr = 0x8269E6D8;
	sub_82558590(ctx, base);
	// lis r3,-32115
	ctx.r3.s64 = -2104688640;
	// mulli r10,r27,104
	ctx.r10.s64 = r27.s64 * 104;
	// fdivs f12,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64 / f30.f64));
	// fdivs f11,f29,f31
	ctx.f11.f64 = double(float(f29.f64 / f31.f64));
	// lwz r11,-12120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -12120);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// fsubs f10,f28,f12
	ctx.f10.f64 = double(float(f28.f64 - ctx.f12.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f9,f28,f11
	ctx.f9.f64 = double(float(f28.f64 - ctx.f11.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f8,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,-8080(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8080);
	f0.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// lfs f6,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64));
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f4,f10,f9
	ctx.f4.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// fctiwz f3,f7
	ctx.f3.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f2,f5
	ctx.f2.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// fsel f1,f4,f4,f0
	ctx.f1.f64 = ctx.f4.f64 >= 0.0 ? ctx.f4.f64 : f0.f64;
	// subf r4,r7,r6
	ctx.r4.s64 = ctx.r6.s64 - ctx.r7.s64;
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fsel f11,f4,f4,f0
	ctx.f11.f64 = ctx.f4.f64 >= 0.0 ? ctx.f4.f64 : f0.f64;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// fsubs f7,f1,f13
	ctx.f7.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// frsp f6,f10
	ctx.f6.f64 = double(float(ctx.f10.f64));
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// fsel f4,f7,f13,f11
	ctx.f4.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// fnmsubs f3,f4,f5,f6
	ctx.f3.f64 = double(float(-(ctx.f4.f64 * ctx.f5.f64 - ctx.f6.f64)));
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfiwx f2,0,r28
	PPC_STORE_U32(r28.u32, ctx.f2.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x8269E790;
	// b 0x823d9244
	return;
loc_8269E794:
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lwz r8,76(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mulli r10,r27,104
	ctx.r10.s64 = r27.s64 * 104;
	// lwz r11,-12120(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12120);
	// lwz r6,108(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	// lwz r5,20(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// lwz r4,104(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 104);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r9,148(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 148);
	// lwz r8,4(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r6,148(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 148);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,76(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,31016(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lfs f10,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f13,-27304(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -27304);
	ctx.f13.f64 = double(temp.f32);
	// lfs f8,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,12(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f8,f7
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fsubs f4,f8,f6
	ctx.f4.f64 = double(float(ctx.f8.f64 - ctx.f6.f64));
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f12,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f3,f11,f13
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f2,f9,f13
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fdivs f1,f5,f4
	ctx.f1.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fctiwz f13,f3
	ctx.f13.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f11,f2
	ctx.f11.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r10,r4,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r4.s64;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// fsubs f10,f0,f1
	ctx.f10.f64 = double(float(f0.f64 - ctx.f1.f64));
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f6,88(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f4,f6
	ctx.f4.f64 = double(ctx.f6.s64);
	// fsel f7,f10,f10,f12
	ctx.f7.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : ctx.f12.f64;
	// fsel f5,f10,f10,f12
	ctx.f5.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : ctx.f12.f64;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f4
	ctx.f1.f64 = double(float(ctx.f4.f64));
	// fsubs f2,f7,f0
	ctx.f2.f64 = double(float(ctx.f7.f64 - f0.f64));
	// frsp f3,f8
	ctx.f3.f64 = double(float(ctx.f8.f64));
	// fsel f0,f2,f0,f5
	f0.f64 = ctx.f2.f64 >= 0.0 ? f0.f64 : ctx.f5.f64;
	// fnmsubs f13,f0,f3,f1
	ctx.f13.f64 = double(float(-(f0.f64 * ctx.f3.f64 - ctx.f1.f64)));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f12,0,r28
	PPC_STORE_U32(r28.u32, ctx.f12.u32);
loc_8269E878:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x8269E884;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8269E888"))) PPC_WEAK_FUNC(sub_8269E888);
PPC_FUNC_IMPL(__imp__sub_8269E888) {
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
	ctx.lr = 0x8269E890;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269E8A8;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r31,r11,8109
	r31.s64 = r11.s64 + 8109;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396408
	ctx.lr = 0x8269E8BC;
	sub_82396408(ctx, base);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82396110
	ctx.lr = 0x8269E8D0;
	sub_82396110(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8269e934
	if (cr6.eq) goto loc_8269E934;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r3,-10020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// bl 0x826bcd90
	ctx.lr = 0x8269E8EC;
	sub_826BCD90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e928
	if (!cr6.eq) goto loc_8269E928;
	// lbz r11,21670(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 21670);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e928
	if (!cr6.eq) goto loc_8269E928;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r3,-10020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// bl 0x826bcd90
	ctx.lr = 0x8269E910;
	sub_826BCD90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ea7c
	if (cr6.eq) goto loc_8269EA7C;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8269E928:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8269E934:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396408
	ctx.lr = 0x8269E93C;
	sub_82396408(ctx, base);
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82396130
	ctx.lr = 0x8269E94C;
	sub_82396130(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269e9a4
	if (cr6.eq) goto loc_8269E9A4;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r3,-10020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// bl 0x826bcd90
	ctx.lr = 0x8269E968;
	sub_826BCD90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e928
	if (!cr6.eq) goto loc_8269E928;
	// lbz r11,21670(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 21670);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e928
	if (!cr6.eq) goto loc_8269E928;
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,-10020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// bl 0x826bcd90
	ctx.lr = 0x8269E98C;
	sub_826BCD90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ea7c
	if (cr6.eq) goto loc_8269EA7C;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8269E9A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396408
	ctx.lr = 0x8269E9AC;
	sub_82396408(ctx, base);
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82396158
	ctx.lr = 0x8269E9BC;
	sub_82396158(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ea14
	if (cr6.eq) goto loc_8269EA14;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,-10020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// bl 0x826bcd90
	ctx.lr = 0x8269E9D8;
	sub_826BCD90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e928
	if (!cr6.eq) goto loc_8269E928;
	// lbz r11,21670(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 21670);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e928
	if (!cr6.eq) goto loc_8269E928;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,-10020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// bl 0x826bcd90
	ctx.lr = 0x8269E9FC;
	sub_826BCD90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ea7c
	if (cr6.eq) goto loc_8269EA7C;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8269EA14:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396408
	ctx.lr = 0x8269EA1C;
	sub_82396408(ctx, base);
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82396180
	ctx.lr = 0x8269EA2C;
	sub_82396180(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ea7c
	if (cr6.eq) goto loc_8269EA7C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-10020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// bl 0x826bcd90
	ctx.lr = 0x8269EA48;
	sub_826BCD90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e928
	if (!cr6.eq) goto loc_8269E928;
	// lbz r11,21670(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 21670);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269e928
	if (!cr6.eq) goto loc_8269E928;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// bl 0x826bcd90
	ctx.lr = 0x8269EA6C;
	sub_826BCD90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269ea80
	if (!cr6.eq) goto loc_8269EA80;
loc_8269EA7C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8269EA80:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8269EA88"))) PPC_WEAK_FUNC(sub_8269EA88);
PPC_FUNC_IMPL(__imp__sub_8269EA88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269EAA8;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8269eacc
	if (!cr6.eq) goto loc_8269EACC;
loc_8269EAB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8269EACC:
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// bne cr6,0x8269eae0
	if (!cr6.eq) goto loc_8269EAE0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8269EAE0:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,4120(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8269eafc
	if (!cr6.gt) goto loc_8269EAFC;
	// fmr f9,f0
	ctx.f9.f64 = f0.f64;
	// b 0x8269eb00
	goto loc_8269EB00;
loc_8269EAFC:
	// fmr f9,f13
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f13.f64;
loc_8269EB00:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// bne cr6,0x8269eb10
	if (!cr6.eq) goto loc_8269EB10;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8269EB10:
	// lfs f13,4116(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4116);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8269eb24
	if (!cr6.gt) goto loc_8269EB24;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
	// b 0x8269eb28
	goto loc_8269EB28;
loc_8269EB24:
	// fmr f10,f13
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f13.f64;
loc_8269EB28:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// bne cr6,0x8269eb38
	if (!cr6.eq) goto loc_8269EB38;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8269EB38:
	// lfs f13,4124(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4124);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8269eb4c
	if (!cr6.gt) goto loc_8269EB4C;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// b 0x8269eb50
	goto loc_8269EB50;
loc_8269EB4C:
	// fmr f11,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f13.f64;
loc_8269EB50:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8269eb60
	if (!cr6.eq) goto loc_8269EB60;
	// li r11,0
	r11.s64 = 0;
loc_8269EB60:
	// lfs f13,4112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8269eb74
	if (!cr6.gt) goto loc_8269EB74;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// b 0x8269eb78
	goto loc_8269EB78;
loc_8269EB74:
	// fmr f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64;
loc_8269EB78:
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,14992(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	f0.f64 = double(temp.f32);
	// lfs f13,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// lfs f8,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f13,f13,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f8.f64));
	// bgt cr6,0x8269ebc4
	if (cr6.gt) goto loc_8269EBC4;
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// bgt cr6,0x8269ebc4
	if (cr6.gt) goto loc_8269EBC4;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x8269ebc4
	if (cr6.gt) goto loc_8269EBC4;
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x8269ebc4
	if (cr6.gt) goto loc_8269EBC4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8269eab4
	if (!cr6.gt) goto loc_8269EAB4;
loc_8269EBC4:
	// fadds f12,f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fadds f11,f12,f10
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f10.f64));
	// fadds f10,f11,f9
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f9.f64));
	// fmuls f31,f10,f0
	f31.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x8269ebe8
	if (!cr6.gt) goto loc_8269EBE8;
	// fmr f31,f13
	f31.f64 = ctx.f13.f64;
loc_8269EBE8:
	// lwz r3,132(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// bl 0x8238f1e8
	ctx.lr = 0x8269EBF0;
	sub_8238F1E8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12120);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// li r9,20
	ctx.r9.s64 = 20;
	// lwz r8,44(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// divw r7,r8,r9
	ctx.r7.s32 = ctx.r8.s32 / ctx.r9.s32;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r3,125
	cr6.compare<int32_t>(ctx.r3.s32, 125, xer);
	// bge cr6,0x8269ec3c
	if (!cr6.lt) goto loc_8269EC3C;
	// li r3,125
	ctx.r3.s64 = 125;
loc_8269EC3C:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6730(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6730);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8269ec50
	if (cr6.eq) goto loc_8269EC50;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8269EC50:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269EC64"))) PPC_WEAK_FUNC(sub_8269EC64);
PPC_FUNC_IMPL(__imp__sub_8269EC64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269EC68"))) PPC_WEAK_FUNC(sub_8269EC68);
PPC_FUNC_IMPL(__imp__sub_8269EC68) {
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
	// bl 0x8269ea88
	ctx.lr = 0x8269EC80;
	sub_8269EA88(ctx, base);
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// li r6,44
	ctx.r6.s64 = 44;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8262fb78
	ctx.lr = 0x8269EC94;
	sub_8262FB78(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,25048
	ctx.r4.s64 = ctx.r10.s64 + 25048;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8269ECAC;
	sub_822183B0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269ECC0"))) PPC_WEAK_FUNC(sub_8269ECC0);
PPC_FUNC_IMPL(__imp__sub_8269ECC0) {
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
	ctx.lr = 0x8269ECC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269ECE8;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r11,-16
	r28.s64 = r11.s64 + -16;
	// bne cr6,0x8269ed00
	if (!cr6.eq) goto loc_8269ED00;
	// li r28,0
	r28.s64 = 0;
loc_8269ED00:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269ed0c
	if (!cr6.eq) goto loc_8269ED0C;
	// li r31,0
	r31.s64 = 0;
loc_8269ED0C:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// add r30,r31,r29
	r30.u64 = r31.u64 + r29.u64;
	// ble cr6,0x8269ed78
	if (!cr6.gt) goto loc_8269ED78;
loc_8269ED18:
	// lbz r11,14(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 14);
	// cmplwi cr6,r11,28
	cr6.compare<uint32_t>(r11.u32, 28, xer);
	// bge cr6,0x8269ed6c
	if (!cr6.lt) goto loc_8269ED6C;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// bge cr6,0x8269ed38
	if (!cr6.lt) goto loc_8269ED38;
	// li r11,12
	r11.s64 = 12;
	// b 0x8269ed44
	goto loc_8269ED44;
loc_8269ED38:
	// cmpwi cr6,r11,28
	cr6.compare<int32_t>(r11.s32, 28, xer);
	// ble cr6,0x8269ed44
	if (!cr6.gt) goto loc_8269ED44;
	// li r11,28
	r11.s64 = 28;
loc_8269ED44:
	// stb r11,14(r30)
	PPC_STORE_U8(r30.u32 + 14, r11.u8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269ED58;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8269ed18
	if (!cr6.eq) goto loc_8269ED18;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269ED6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269ED78:
	// lbz r11,14(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 14);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// ble cr6,0x8269ed6c
	if (!cr6.gt) goto loc_8269ED6C;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// bge cr6,0x8269ed98
	if (!cr6.lt) goto loc_8269ED98;
	// li r11,12
	r11.s64 = 12;
	// b 0x8269eda4
	goto loc_8269EDA4;
loc_8269ED98:
	// cmpwi cr6,r11,28
	cr6.compare<int32_t>(r11.s32, 28, xer);
	// ble cr6,0x8269eda4
	if (!cr6.gt) goto loc_8269EDA4;
	// li r11,28
	r11.s64 = 28;
loc_8269EDA4:
	// stb r11,14(r30)
	PPC_STORE_U8(r30.u32 + 14, r11.u8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269EDB8;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8269ed78
	if (!cr6.eq) goto loc_8269ED78;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8269EDCC"))) PPC_WEAK_FUNC(sub_8269EDCC);
PPC_FUNC_IMPL(__imp__sub_8269EDCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269EDD0"))) PPC_WEAK_FUNC(sub_8269EDD0);
PPC_FUNC_IMPL(__imp__sub_8269EDD0) {
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
	ctx.lr = 0x8269EDD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269EDF8;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r11,-16
	r28.s64 = r11.s64 + -16;
	// bne cr6,0x8269ee10
	if (!cr6.eq) goto loc_8269EE10;
	// li r28,0
	r28.s64 = 0;
loc_8269EE10:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269ee1c
	if (!cr6.eq) goto loc_8269EE1C;
	// li r31,0
	r31.s64 = 0;
loc_8269EE1C:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// add r30,r31,r29
	r30.u64 = r31.u64 + r29.u64;
	// ble cr6,0x8269ee84
	if (!cr6.gt) goto loc_8269EE84;
loc_8269EE28:
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,13
	cr6.compare<uint32_t>(r11.u32, 13, xer);
	// bge cr6,0x8269ee78
	if (!cr6.lt) goto loc_8269EE78;
	// add. r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x8269ee44
	if (!cr0.lt) goto loc_8269EE44;
	// li r11,0
	r11.s64 = 0;
	// b 0x8269ee50
	goto loc_8269EE50;
loc_8269EE44:
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// ble cr6,0x8269ee50
	if (!cr6.gt) goto loc_8269EE50;
	// li r11,13
	r11.s64 = 13;
loc_8269EE50:
	// stb r11,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r11.u8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269EE64;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8269ee28
	if (!cr6.eq) goto loc_8269EE28;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269EE78:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269EE84:
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ee78
	if (cr6.eq) goto loc_8269EE78;
	// add. r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x8269eea0
	if (!cr0.lt) goto loc_8269EEA0;
	// li r11,0
	r11.s64 = 0;
	// b 0x8269eeac
	goto loc_8269EEAC;
loc_8269EEA0:
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// ble cr6,0x8269eeac
	if (!cr6.gt) goto loc_8269EEAC;
	// li r11,13
	r11.s64 = 13;
loc_8269EEAC:
	// stb r11,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r11.u8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269EEC0;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8269ee84
	if (!cr6.eq) goto loc_8269EE84;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8269EED4"))) PPC_WEAK_FUNC(sub_8269EED4);
PPC_FUNC_IMPL(__imp__sub_8269EED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269EED8"))) PPC_WEAK_FUNC(sub_8269EED8);
PPC_FUNC_IMPL(__imp__sub_8269EED8) {
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
	ctx.lr = 0x8269EEE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269EF00;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r11,-16
	r28.s64 = r11.s64 + -16;
	// bne cr6,0x8269ef18
	if (!cr6.eq) goto loc_8269EF18;
	// li r28,0
	r28.s64 = 0;
loc_8269EF18:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269ef24
	if (!cr6.eq) goto loc_8269EF24;
	// li r31,0
	r31.s64 = 0;
loc_8269EF24:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// add r30,r31,r29
	r30.u64 = r31.u64 + r29.u64;
	// ble cr6,0x8269ef8c
	if (!cr6.gt) goto loc_8269EF8C;
loc_8269EF30:
	// lbz r11,10(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// cmplwi cr6,r11,11
	cr6.compare<uint32_t>(r11.u32, 11, xer);
	// bge cr6,0x8269ef80
	if (!cr6.lt) goto loc_8269EF80;
	// add. r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x8269ef4c
	if (!cr0.lt) goto loc_8269EF4C;
	// li r11,0
	r11.s64 = 0;
	// b 0x8269ef58
	goto loc_8269EF58;
loc_8269EF4C:
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// ble cr6,0x8269ef58
	if (!cr6.gt) goto loc_8269EF58;
	// li r11,11
	r11.s64 = 11;
loc_8269EF58:
	// stb r11,10(r30)
	PPC_STORE_U8(r30.u32 + 10, r11.u8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269EF6C;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8269ef30
	if (!cr6.eq) goto loc_8269EF30;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269EF80:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8269EF8C:
	// lbz r11,10(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ef80
	if (cr6.eq) goto loc_8269EF80;
	// add. r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x8269efa8
	if (!cr0.lt) goto loc_8269EFA8;
	// li r11,0
	r11.s64 = 0;
	// b 0x8269efb4
	goto loc_8269EFB4;
loc_8269EFA8:
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// ble cr6,0x8269efb4
	if (!cr6.gt) goto loc_8269EFB4;
	// li r11,11
	r11.s64 = 11;
loc_8269EFB4:
	// stb r11,10(r30)
	PPC_STORE_U8(r30.u32 + 10, r11.u8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269EFC8;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8269ef8c
	if (!cr6.eq) goto loc_8269EF8C;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8269EFDC"))) PPC_WEAK_FUNC(sub_8269EFDC);
PPC_FUNC_IMPL(__imp__sub_8269EFDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269EFE0"))) PPC_WEAK_FUNC(sub_8269EFE0);
PPC_FUNC_IMPL(__imp__sub_8269EFE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x8269EFE8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x822a3998
	ctx.lr = 0x8269F00C;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x8269f024
	if (!cr6.eq) goto loc_8269F024;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8269F024:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8269f034
	if (cr6.eq) goto loc_8269F034;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F034:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// lbz r27,16(r11)
	r27.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8269f04c
	if (cr6.eq) goto loc_8269F04C;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F04C:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// lbz r26,10(r11)
	r26.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8269f064
	if (cr6.eq) goto loc_8269F064;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F064:
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// addi r11,r29,-1
	r11.s64 = r29.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// lbz r29,14(r10)
	r29.u64 = PPC_LOAD_U8(ctx.r10.u32 + 14);
	// bgt cr6,0x8269f6a8
	if (cr6.gt) goto loc_8269F6A8;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,-3952
	r12.s64 = r12.s64 + -3952;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8269F0A0;
	case 1:
		goto loc_8269F1F8;
	case 2:
		goto loc_8269F350;
	case 3:
		goto loc_8269F584;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-3936(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3936);
	// lwz r19,-3592(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3592);
	// lwz r19,-3248(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3248);
	// lwz r19,-2684(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + -2684);
loc_8269F0A0:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// beq cr6,0x8269f0b0
	if (cr6.eq) goto loc_8269F0B0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
loc_8269F0B0:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269F0B8;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8269f184
	if (cr6.eq) goto loc_8269F184;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x8269f110
	if (cr6.eq) goto loc_8269F110;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269edd0
	ctx.lr = 0x8269F0E4;
	sub_8269EDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f0fc
	if (!cr6.eq) goto loc_8269F0FC;
	// li r31,0
	r31.s64 = 0;
loc_8269F0FC:
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F110:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269edd0
	ctx.lr = 0x8269F124;
	sub_8269EDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269f13c
	if (cr6.eq) goto loc_8269F13C;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F13C:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// bl 0x8269eed8
	ctx.lr = 0x8269F158;
	sub_8269EED8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f1e4
	if (!cr6.eq) goto loc_8269F1E4;
	// li r31,0
	r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// stb r26,10(r11)
	PPC_STORE_U8(r11.u32 + 10, r26.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F184:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269edd0
	ctx.lr = 0x8269F198;
	sub_8269EDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269f1b0
	if (cr6.eq) goto loc_8269F1B0;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F1B0:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// bl 0x8269eed8
	ctx.lr = 0x8269F1CC;
	sub_8269EED8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f1e4
	if (!cr6.eq) goto loc_8269F1E4;
	// li r31,0
	r31.s64 = 0;
loc_8269F1E4:
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r26,10(r11)
	PPC_STORE_U8(r11.u32 + 10, r26.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F1F8:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// beq cr6,0x8269f208
	if (cr6.eq) goto loc_8269F208;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
loc_8269F208:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269F210;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8269f2dc
	if (cr6.eq) goto loc_8269F2DC;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x8269f268
	if (cr6.eq) goto loc_8269F268;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269ecc0
	ctx.lr = 0x8269F23C;
	sub_8269ECC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f33c
	if (!cr6.eq) goto loc_8269F33C;
	// li r31,0
	r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// stb r29,14(r11)
	PPC_STORE_U8(r11.u32 + 14, r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F268:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269eed8
	ctx.lr = 0x8269F27C;
	sub_8269EED8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269f294
	if (cr6.eq) goto loc_8269F294;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F294:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r26,10(r11)
	PPC_STORE_U8(r11.u32 + 10, r26.u8);
	// bl 0x8269ecc0
	ctx.lr = 0x8269F2B0;
	sub_8269ECC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f33c
	if (!cr6.eq) goto loc_8269F33C;
	// li r31,0
	r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// stb r29,14(r11)
	PPC_STORE_U8(r11.u32 + 14, r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F2DC:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269eed8
	ctx.lr = 0x8269F2F0;
	sub_8269EED8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269f308
	if (cr6.eq) goto loc_8269F308;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F308:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r26,10(r11)
	PPC_STORE_U8(r11.u32 + 10, r26.u8);
	// bl 0x8269ecc0
	ctx.lr = 0x8269F324;
	sub_8269ECC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f33c
	if (!cr6.eq) goto loc_8269F33C;
	// li r31,0
	r31.s64 = 0;
loc_8269F33C:
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r29,14(r11)
	PPC_STORE_U8(r11.u32 + 14, r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F350:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// beq cr6,0x8269f360
	if (cr6.eq) goto loc_8269F360;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
loc_8269F360:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269F368;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8269f4d8
	if (cr6.eq) goto loc_8269F4D8;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x8269f42c
	if (cr6.eq) goto loc_8269F42C;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269edd0
	ctx.lr = 0x8269F394;
	sub_8269EDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269f3ac
	if (cr6.eq) goto loc_8269F3AC;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F3AC:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// bl 0x8269ecc0
	ctx.lr = 0x8269F3C8;
	sub_8269ECC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8269f3e4
	if (cr6.eq) goto loc_8269F3E4;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F3E4:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r29,14(r11)
	PPC_STORE_U8(r11.u32 + 14, r29.u8);
	// bl 0x8269edd0
	ctx.lr = 0x8269F400;
	sub_8269EDD0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f0fc
	if (!cr6.eq) goto loc_8269F0FC;
	// li r31,0
	r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F42C:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269edd0
	ctx.lr = 0x8269F440;
	sub_8269EDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269f458
	if (cr6.eq) goto loc_8269F458;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F458:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// bl 0x8269eed8
	ctx.lr = 0x8269F474;
	sub_8269EED8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8269f490
	if (cr6.eq) goto loc_8269F490;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F490:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r26,10(r11)
	PPC_STORE_U8(r11.u32 + 10, r26.u8);
	// bl 0x8269ecc0
	ctx.lr = 0x8269F4AC;
	sub_8269ECC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f33c
	if (!cr6.eq) goto loc_8269F33C;
	// li r31,0
	r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// stb r29,14(r11)
	PPC_STORE_U8(r11.u32 + 14, r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F4D8:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269edd0
	ctx.lr = 0x8269F4EC;
	sub_8269EDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269f504
	if (cr6.eq) goto loc_8269F504;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F504:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// bl 0x8269eed8
	ctx.lr = 0x8269F520;
	sub_8269EED8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8269f53c
	if (cr6.eq) goto loc_8269F53C;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F53C:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r26,10(r11)
	PPC_STORE_U8(r11.u32 + 10, r26.u8);
	// bl 0x8269ecc0
	ctx.lr = 0x8269F558;
	sub_8269ECC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f33c
	if (!cr6.eq) goto loc_8269F33C;
	// li r31,0
	r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// stb r29,14(r11)
	PPC_STORE_U8(r11.u32 + 14, r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F584:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// beq cr6,0x8269f594
	if (cr6.eq) goto loc_8269F594;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
loc_8269F594:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8235af08
	ctx.lr = 0x8269F59C;
	sub_8235AF08(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8269f634
	if (cr6.eq) goto loc_8269F634;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x8269f5c0
	if (cr6.eq) goto loc_8269F5C0;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F5C0:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269edd0
	ctx.lr = 0x8269F5D4;
	sub_8269EDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269f5ec
	if (cr6.eq) goto loc_8269F5EC;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F5EC:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// bl 0x8269ecc0
	ctx.lr = 0x8269F608;
	sub_8269ECC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f33c
	if (!cr6.eq) goto loc_8269F33C;
	// li r31,0
	r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// stb r29,14(r11)
	PPC_STORE_U8(r11.u32 + 14, r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F634:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269edd0
	ctx.lr = 0x8269F648;
	sub_8269EDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x8269f660
	if (cr6.eq) goto loc_8269F660;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8269F660:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// bl 0x8269ecc0
	ctx.lr = 0x8269F67C;
	sub_8269ECC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269f6a8
	if (!cr6.eq) goto loc_8269F6A8;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x8269f33c
	if (!cr6.eq) goto loc_8269F33C;
	// li r31,0
	r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r31,r30
	r11.u64 = r31.u64 + r30.u64;
	// stb r29,14(r11)
	PPC_STORE_U8(r11.u32 + 14, r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8269F6A8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8269F6B4"))) PPC_WEAK_FUNC(sub_8269F6B4);
PPC_FUNC_IMPL(__imp__sub_8269F6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269F6B8"))) PPC_WEAK_FUNC(sub_8269F6B8);
PPC_FUNC_IMPL(__imp__sub_8269F6B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269F6D4;
	sub_822A3998(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r9,-27300
	ctx.r5.s64 = ctx.r9.s64 + -27300;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// addi r6,r11,8109
	ctx.r6.s64 = r11.s64 + 8109;
	// bl 0x82137a08
	ctx.lr = 0x8269F6F8;
	sub_82137A08(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ori r5,r6,3600
	ctx.r5.u64 = ctx.r6.u64 | 3600;
	// lwz r11,-10028(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10028);
	// lwzx r3,r11,r5
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	// bl 0x82695ca0
	ctx.lr = 0x8269F714;
	sub_82695CA0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269F724"))) PPC_WEAK_FUNC(sub_8269F724);
PPC_FUNC_IMPL(__imp__sub_8269F724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269F728"))) PPC_WEAK_FUNC(sub_8269F728);
PPC_FUNC_IMPL(__imp__sub_8269F728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269F744;
	sub_822A3998(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r9,-27280
	ctx.r5.s64 = ctx.r9.s64 + -27280;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// addi r6,r11,8109
	ctx.r6.s64 = r11.s64 + 8109;
	// bl 0x82137a08
	ctx.lr = 0x8269F768;
	sub_82137A08(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ori r5,r6,3600
	ctx.r5.u64 = ctx.r6.u64 | 3600;
	// lwz r11,-10028(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10028);
	// lwzx r3,r11,r5
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	// bl 0x82695ca0
	ctx.lr = 0x8269F784;
	sub_82695CA0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269F794"))) PPC_WEAK_FUNC(sub_8269F794);
PPC_FUNC_IMPL(__imp__sub_8269F794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269F798"))) PPC_WEAK_FUNC(sub_8269F798);
PPC_FUNC_IMPL(__imp__sub_8269F798) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269F7B4;
	sub_822A3998(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r9,-27264
	ctx.r5.s64 = ctx.r9.s64 + -27264;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// addi r6,r11,8109
	ctx.r6.s64 = r11.s64 + 8109;
	// bl 0x82137a08
	ctx.lr = 0x8269F7D8;
	sub_82137A08(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ori r5,r6,3600
	ctx.r5.u64 = ctx.r6.u64 | 3600;
	// lwz r11,-10028(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10028);
	// lwzx r3,r11,r5
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	// bl 0x82695ca0
	ctx.lr = 0x8269F7F4;
	sub_82695CA0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8269F804"))) PPC_WEAK_FUNC(sub_8269F804);
PPC_FUNC_IMPL(__imp__sub_8269F804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269F808"))) PPC_WEAK_FUNC(sub_8269F808);
PPC_FUNC_IMPL(__imp__sub_8269F808) {
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
	ctx.lr = 0x8269F810;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,328(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 328);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8269F82C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-27236
	ctx.r4.s64 = ctx.r9.s64 + -27236;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8268da78
	ctx.lr = 0x8269F840;
	sub_8268DA78(ctx, base);
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r7,0
	ctx.r7.s64 = 0;
	// addi r30,r11,-27248
	r30.s64 = r11.s64 + -27248;
	// ori r6,r7,39524
	ctx.r6.u64 = ctx.r7.u64 | 39524;
	// lwz r11,-29340(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -29340);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stwx r8,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, ctx.r8.u32);
	// bl 0x8268da78
	ctx.lr = 0x8269F870;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8269f8ac
	if (cr6.eq) goto loc_8269F8AC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8269F888;
	sub_8268DA78(ctx, base);
	// lwz r11,-29340(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -29340);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// li r4,50
	ctx.r4.s64 = 50;
	// addi r5,r9,9572
	ctx.r5.s64 = ctx.r9.s64 + 9572;
	// addi r3,r3,-26008
	ctx.r3.s64 = ctx.r3.s64 + -26008;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82137a08
	ctx.lr = 0x8269F8AC;
	sub_82137A08(ctx, base);
loc_8269F8AC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8269ad68
	ctx.lr = 0x8269F8B4;
	sub_8269AD68(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269F8BC"))) PPC_WEAK_FUNC(sub_8269F8BC);
PPC_FUNC_IMPL(__imp__sub_8269F8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269F8C0"))) PPC_WEAK_FUNC(sub_8269F8C0);
PPC_FUNC_IMPL(__imp__sub_8269F8C0) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8269F8C8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269F8DC;
	sub_822A3998(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8269f900
	if (cr6.eq) goto loc_8269F900;
	// addi r11,r11,208
	r11.s64 = r11.s64 + 208;
	// b 0x8269f904
	goto loc_8269F904;
loc_8269F900:
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
loc_8269F904:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r29,r10,-29280
	r29.s64 = ctx.r10.s64 + -29280;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,48
	ctx.r5.s64 = 48;
	// stvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,48
	ctx.r3.s64 = 48;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// stvx128 v63,r29,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r29,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r29,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,880(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 880);
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// stw r29,144(r10)
	PPC_STORE_U32(ctx.r10.u32 + 144, r29.u32);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269F95C;
	sub_822A3998(ctx, base);
	// lwz r9,880(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,124(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 124);
	// stw r29,144(r8)
	PPC_STORE_U32(ctx.r8.u32 + 144, r29.u32);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269F974;
	sub_822A3998(ctx, base);
	// lwz r7,880(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,124(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 124);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,14184(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14184);
	f0.f64 = double(temp.f32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stfs f0,168(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// li r8,48
	ctx.r8.s64 = 48;
	// lfs f0,48(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 48);
	f0.f64 = double(temp.f32);
	// addi r7,r9,-29216
	ctx.r7.s64 = ctx.r9.s64 + -29216;
	// lfs f12,52(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,56(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,31968(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31968);
	ctx.f13.f64 = double(temp.f32);
	// lbz r6,-29342(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + -29342);
	// lfs f11,31224(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31224);
	ctx.f11.f64 = double(temp.f32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lfs f9,31296(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31296);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsubs f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// stfs f0,48(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 48, temp.u32);
	// fadds f12,f10,f9
	ctx.f12.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// stfs f13,52(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 52, temp.u32);
	// stfs f12,56(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 56, temp.u32);
	// lvx128 v63,r29,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8269f9fc
	if (!cr6.eq) goto loc_8269F9FC;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lbz r9,-6745(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6745);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r11,-6745(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6745, r11.u8);
loc_8269F9FC:
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r11,21
	r11.s64 = 21;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stw r11,-29212(r9)
	PPC_STORE_U32(ctx.r9.u32 + -29212, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r10,-29347(r8)
	PPC_STORE_U8(ctx.r8.u32 + -29347, ctx.r10.u8);
	// lwz r3,-12288(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12288);
	// bl 0x821ebcf0
	ctx.lr = 0x8269FA24;
	sub_821EBCF0(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,-12216(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12216);
	// bl 0x821f0c10
	ctx.lr = 0x8269FA30;
	sub_821F0C10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82304648
	ctx.lr = 0x8269FA38;
	sub_82304648(ctx, base);
	// lis r3,-32119
	ctx.r3.s64 = -2104950784;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10432(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10432);
	// lwz r9,2016(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2016);
	// stb r10,33(r9)
	PPC_STORE_U8(ctx.r9.u32 + 33, ctx.r10.u8);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3d80
	ctx.lr = 0x8269FA5C;
	sub_822A3D80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,880(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 880);
	// bl 0x822b1490
	ctx.lr = 0x8269FA68;
	sub_822B1490(ctx, base);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// li r11,21
	r11.s64 = 21;
	// stb r11,-29348(r8)
	PPC_STORE_U8(ctx.r8.u32 + -29348, r11.u8);
	// lwz r11,-18004(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -18004);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269fa9c
	if (cr6.eq) goto loc_8269FA9C;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r10,-29343(r9)
	PPC_STORE_U8(ctx.r9.u32 + -29343, ctx.r10.u8);
	// stb r8,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r8.u8);
loc_8269FA9C:
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stb r11,-29345(r9)
	PPC_STORE_U8(ctx.r9.u32 + -29345, r11.u8);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// stb r10,-29344(r8)
	PPC_STORE_U8(ctx.r8.u32 + -29344, ctx.r10.u8);
	// addi r3,r7,-27224
	ctx.r3.s64 = ctx.r7.s64 + -27224;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821fa230
	ctx.lr = 0x8269FAD4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,32(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8269FAE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// addi r4,r5,-21664
	ctx.r4.s64 = ctx.r5.s64 + -21664;
	// addi r31,r11,-12592
	r31.s64 = r11.s64 + -12592;
	// bl 0x821f9fb8
	ctx.lr = 0x8269FB00;
	sub_821F9FB8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x827205a8
	ctx.lr = 0x8269FB0C;
	sub_827205A8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8269FB14"))) PPC_WEAK_FUNC(sub_8269FB14);
PPC_FUNC_IMPL(__imp__sub_8269FB14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8269FB18"))) PPC_WEAK_FUNC(sub_8269FB18);
PPC_FUNC_IMPL(__imp__sub_8269FB18) {
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
	ctx.lr = 0x8269FB20;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269FB34;
	sub_822A3998(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r11,-29347(r10)
	PPC_STORE_U8(ctx.r10.u32 + -29347, r11.u8);
	// lwz r3,-12288(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12288);
	// bl 0x821ebc70
	ctx.lr = 0x8269FB54;
	sub_821EBC70(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,-12216(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12216);
	// bl 0x821f0800
	ctx.lr = 0x8269FB60;
	sub_821F0800(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82304648
	ctx.lr = 0x8269FB68;
	sub_82304648(ctx, base);
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// lis r28,-32111
	r28.s64 = -2104426496;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,-10432(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10432);
	// lwz r5,2016(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 2016);
	// stb r6,33(r5)
	PPC_STORE_U8(ctx.r5.u32 + 33, ctx.r6.u8);
	// lbz r4,-29345(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + -29345);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8269fb98
	if (!cr6.eq) goto loc_8269FB98;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827057e0
	ctx.lr = 0x8269FB98;
	sub_827057E0(ctx, base);
loc_8269FB98:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822a3d80
	ctx.lr = 0x8269FBA8;
	sub_822A3D80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// bl 0x822b1490
	ctx.lr = 0x8269FBB4;
	sub_822B1490(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29343(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29343);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8269fbd8
	if (cr6.eq) goto loc_8269FBD8;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stb r10,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, ctx.r10.u8);
loc_8269FBD8:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x8269FBE0;
	sub_8238EFE8(ctx, base);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-27208
	ctx.r4.s64 = ctx.r10.s64 + -27208;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x8269FBFC;
	sub_8268B770(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213338
	ctx.lr = 0x8269FC10;
	sub_82213338(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213338
	ctx.lr = 0x8269FC20;
	sub_82213338(ctx, base);
	// li r30,0
	r30.s64 = 0;
loc_8269FC24:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r4,r30,18
	ctx.r4.s64 = r30.s64 + 18;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213338
	ctx.lr = 0x8269FC34;
	sub_82213338(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,26
	cr6.compare<int32_t>(r30.s32, 26, xer);
	// blt cr6,0x8269fc24
	if (cr6.lt) goto loc_8269FC24;
	// li r30,9
	r30.s64 = 9;
loc_8269FC44:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213338
	ctx.lr = 0x8269FC54;
	sub_82213338(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,14
	cr6.compare<int32_t>(r30.s32, 14, xer);
	// ble cr6,0x8269fc44
	if (!cr6.gt) goto loc_8269FC44;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lwz r11,-29340(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// lwz r10,21680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 21680);
	// lbz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8269fcb0
	if (!cr6.eq) goto loc_8269FCB0;
	// lbz r11,-29344(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -29344);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269fcb0
	if (!cr6.eq) goto loc_8269FCB0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269FC94;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x8269fcac
	if (!cr6.eq) goto loc_8269FCAC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8269FCAC:
	// bl 0x82353650
	ctx.lr = 0x8269FCB0;
	sub_82353650(ctx, base);
loc_8269FCB0:
	// lbz r11,-29345(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + -29345);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8269fcc0
	if (!cr6.eq) goto loc_8269FCC0;
	// stb r11,-29344(r31)
	PPC_STORE_U8(r31.u32 + -29344, r11.u8);
loc_8269FCC0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8269FCC8"))) PPC_WEAK_FUNC(sub_8269FCC8);
PPC_FUNC_IMPL(__imp__sub_8269FCC8) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8269FCD0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269FCE4;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822a8858
	ctx.lr = 0x8269FCEC;
	sub_822A8858(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269FCF8;
	sub_822A3998(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b1490
	ctx.lr = 0x8269FD04;
	sub_822B1490(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269FD10;
	sub_822A3998(ctx, base);
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8269fd30
	if (cr6.eq) goto loc_8269FD30;
	// addi r11,r11,208
	r11.s64 = r11.s64 + 208;
	// b 0x8269fd34
	goto loc_8269FD34;
loc_8269FD30:
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
loc_8269FD34:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// addi r26,r10,-29280
	r26.s64 = ctx.r10.s64 + -29280;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,48
	ctx.r5.s64 = 48;
	// stvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// stvx128 v63,r26,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r26,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r26,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a3998
	ctx.lr = 0x8269FD80;
	sub_822A3998(ctx, base);
	// lwz r9,880(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,124(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 124);
	// stw r26,144(r8)
	PPC_STORE_U32(ctx.r8.u32 + 144, r26.u32);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269FD98;
	sub_822A3998(ctx, base);
	// lwz r7,880(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,124(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 124);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r28,-32111
	r28.s64 = -2104426496;
	// lfs f0,14184(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14184);
	f0.f64 = double(temp.f32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stfs f0,168(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// lfs f12,52(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lfs f10,56(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// addi r8,r10,-29216
	ctx.r8.s64 = ctx.r10.s64 + -29216;
	// lfs f13,31968(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31968);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-29340(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -29340);
	// lfs f0,48(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 48);
	f0.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,31224(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31224);
	ctx.f11.f64 = double(temp.f32);
	// ori r6,r7,57992
	ctx.r6.u64 = ctx.r7.u64 | 57992;
	// lfs f9,31296(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31296);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fadds f12,f10,f9
	ctx.f12.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// stfs f0,48(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 48, temp.u32);
	// stfs f13,52(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 52, temp.u32);
	// li r27,0
	r27.s64 = 0;
	// stfs f12,56(r26)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r26.u32 + 56, temp.u32);
	// li r10,20
	ctx.r10.s64 = 20;
	// lvx128 v63,r26,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,1
	ctx.r9.s64 = 1;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwx r27,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, r27.u32);
	// stw r10,-29212(r5)
	PPC_STORE_U32(ctx.r5.u32 + -29212, ctx.r10.u32);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// stb r9,-29347(r29)
	PPC_STORE_U8(r29.u32 + -29347, ctx.r9.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12288(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -12288);
	// bl 0x821ebcf0
	ctx.lr = 0x8269FE3C;
	sub_821EBCF0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// bl 0x821f0c10
	ctx.lr = 0x8269FE48;
	sub_821F0C10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82304648
	ctx.lr = 0x8269FE50;
	sub_82304648(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x827057e0
	ctx.lr = 0x8269FE5C;
	sub_827057E0(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10432(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10432);
	// lwz r8,2016(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 2016);
	// stb r9,33(r8)
	PPC_STORE_U8(ctx.r8.u32 + 33, ctx.r9.u8);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3d80
	ctx.lr = 0x8269FE80;
	sub_822A3D80(ctx, base);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269fec0
	if (cr6.eq) goto loc_8269FEC0;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,192
	ctx.r9.s64 = 192;
	// lfs f0,204(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 204);
	f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f11,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8269FEC0:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// li r11,20
	r11.s64 = 20;
	// stb r11,-29348(r10)
	PPC_STORE_U8(ctx.r10.u32 + -29348, r11.u8);
	// lwz r10,-18004(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18004);
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269fef0
	if (cr6.eq) goto loc_8269FEF0;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// stb r10,-29343(r9)
	PPC_STORE_U8(ctx.r9.u32 + -29343, ctx.r10.u8);
	// stb r27,4(r11)
	PPC_STORE_U8(r11.u32 + 4, r27.u8);
loc_8269FEF0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-27168
	ctx.r4.s64 = ctx.r10.s64 + -27168;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8269FF14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8269ff28
	if (cr6.eq) goto loc_8269FF28;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-29346(r10)
	PPC_STORE_U8(ctx.r10.u32 + -29346, r11.u8);
loc_8269FF28:
	// lbz r11,-29347(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + -29347);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8269ff70
	if (cr6.eq) goto loc_8269FF70;
	// lwz r11,-29340(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -29340);
	// lwz r11,21680(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21680);
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8269ff70
	if (!cr6.eq) goto loc_8269FF70;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8269FF54;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x8269ff6c
	if (!cr6.eq) goto loc_8269FF6C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8269FF6C:
	// bl 0x823535e8
	ctx.lr = 0x8269FF70;
	sub_823535E8(ctx, base);
loc_8269FF70:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-27188
	ctx.r4.s64 = ctx.r10.s64 + -27188;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x8269FF88;
	sub_8268B770(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8269FF90"))) PPC_WEAK_FUNC(sub_8269FF90);
PPC_FUNC_IMPL(__imp__sub_8269FF90) {
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
	ctx.lr = 0x8269FF98;
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// addi r31,r11,-21664
	r31.s64 = r11.s64 + -21664;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,-10236(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x8269FFC0;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a00c0
	if (cr6.eq) goto loc_826A00C0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10236(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8269FFD4;
	sub_821F9FB8(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stb r31,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, r31.u8);
	// bge cr6,0x826a0004
	if (!cr6.lt) goto loc_826A0004;
	// li r6,256
	ctx.r6.s64 = 256;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x825ee318
	ctx.lr = 0x8269FFF8;
	sub_825EE318(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826a00c0
	if (cr6.eq) goto loc_826A00C0;
loc_826A0004:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r3,r11,-27160
	ctx.r3.s64 = r11.s64 + -27160;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x826A0018;
	sub_82130000(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c9ab0
	ctx.lr = 0x826A0020;
	sub_821C9AB0(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r8,63
	ctx.r8.s64 = 63;
loc_826A0028:
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826a0080
	if (cr6.eq) goto loc_826A0080;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826a0074
	if (cr6.eq) goto loc_826A0074;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826a007c
	if (cr6.eq) goto loc_826A007C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x826a0028
	if (cr0.gt) goto loc_826A0028;
	// b 0x826a0080
	goto loc_826A0080;
loc_826A0074:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x826a0080
	goto loc_826A0080;
loc_826A007C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_826A0080:
	// stb r31,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r31.u8);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821ca980
	ctx.lr = 0x826A0094;
	sub_821CA980(ctx, base);
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db6d0
	ctx.lr = 0x826A00A0;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a00ac
	if (cr6.eq) goto loc_826A00AC;
	// stb r31,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r31.u8);
loc_826A00AC:
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x826A00C0;
	sub_82213B80(ctx, base);
loc_826A00C0:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826A00C8"))) PPC_WEAK_FUNC(sub_826A00C8);
PPC_FUNC_IMPL(__imp__sub_826A00C8) {
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
	ctx.lr = 0x826A00D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r27,r11,4272
	r27.s64 = r11.s64 + 4272;
	// li r29,0
	r29.s64 = 0;
	// stb r10,0(r28)
	PPC_STORE_U8(r28.u32 + 0, ctx.r10.u8);
	// mr r30,r27
	r30.u64 = r27.u64;
loc_826A00F0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826a0134
	if (!cr6.gt) goto loc_826A0134;
loc_826A0100:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82392520
	ctx.lr = 0x826A010C;
	sub_82392520(ctx, base);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x8236e2e8
	ctx.lr = 0x826A0124;
	sub_8236E2E8(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x826a0100
	if (cr6.lt) goto loc_826A0100;
loc_826A0134:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r11,r27,20
	r11.s64 = r27.s64 + 20;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826a00f0
	if (cr6.lt) goto loc_826A00F0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826A0154"))) PPC_WEAK_FUNC(sub_826A0154);
PPC_FUNC_IMPL(__imp__sub_826A0154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A0158"))) PPC_WEAK_FUNC(sub_826A0158);
PPC_FUNC_IMPL(__imp__sub_826A0158) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x826A0160;
	// stfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x826A0170;
	sub_824E0648(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r25,r11,-25696
	r25.s64 = r11.s64 + -25696;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r10,-21856
	ctx.r4.s64 = ctx.r10.s64 + -21856;
	// stw r25,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r25.u32);
	// addi r3,r9,-28824
	ctx.r3.s64 = ctx.r9.s64 + -28824;
	// addi r11,r8,-29204
	r11.s64 = ctx.r8.s64 + -29204;
	// stw r4,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r4.u32);
	// addi r10,r7,-27684
	ctx.r10.s64 = ctx.r7.s64 + -27684;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// addi r9,r6,-27696
	ctx.r9.s64 = ctx.r6.s64 + -27696;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// addi r27,r31,21696
	r27.s64 = r31.s64 + 21696;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// addi r8,r5,-29192
	ctx.r8.s64 = ctx.r5.s64 + -29192;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// stw r30,21680(r31)
	PPC_STORE_U32(r31.u32 + 21680, r30.u32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// subf r9,r27,r8
	ctx.r9.s64 = ctx.r8.s64 - r27.s64;
	// li r10,40
	ctx.r10.s64 = 40;
loc_826A01DC:
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x826a01dc
	if (!cr0.eq) goto loc_826A01DC;
	// addi r26,r31,21856
	r26.s64 = r31.s64 + 21856;
	// li r29,2
	r29.s64 = 2;
	// mr r28,r26
	r28.u64 = r26.u64;
loc_826A01FC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826a00c8
	ctx.lr = 0x826A0204;
	sub_826A00C8(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,5764
	r28.s64 = r28.s64 + 5764;
	// bge 0x826a01fc
	if (!cr0.lt) goto loc_826A01FC;
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// li r10,49
	ctx.r10.s64 = 49;
	// addi r11,r11,-23552
	r11.s64 = r11.s64 + -23552;
	// li r9,200
	ctx.r9.s64 = 200;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// li r29,-1
	r29.s64 = -1;
loc_826A0228:
	// stw r9,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// stb r30,-8(r11)
	PPC_STORE_U8(r11.u32 + -8, r30.u8);
	// stw r29,132(r11)
	PPC_STORE_U32(r11.u32 + 132, r29.u32);
	// stw r29,136(r11)
	PPC_STORE_U32(r11.u32 + 136, r29.u32);
	// stw r29,140(r11)
	PPC_STORE_U32(r11.u32 + 140, r29.u32);
	// addi r11,r11,152
	r11.s64 = r11.s64 + 152;
	// bne 0x826a0228
	if (!cr0.eq) goto loc_826A0228;
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,-15944
	ctx.r3.s64 = ctx.r3.s64 + -15944;
	// bl 0x82398118
	ctx.lr = 0x826A0258;
	sub_82398118(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,-15888
	ctx.r3.s64 = ctx.r3.s64 + -15888;
	// bl 0x82395138
	ctx.lr = 0x826A0264;
	sub_82395138(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// ori r8,r11,57996
	ctx.r8.u64 = r11.u64 | 57996;
	// ori r7,r10,39520
	ctx.r7.u64 = ctx.r10.u64 | 39520;
	// addi r6,r9,-29168
	ctx.r6.s64 = ctx.r9.s64 + -29168;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r3,17296
	ctx.r3.s64 = 17296;
	// stwx r5,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r5.u32);
	// stbx r30,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r30.u8);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cntlzw r4,r11
	ctx.r4.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r4,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r10,r11,1
	ctx.r10.u64 = r11.u64 ^ 1;
	// stb r10,21670(r31)
	PPC_STORE_U8(r31.u32 + 21670, ctx.r10.u8);
	// bl 0x82130528
	ctx.lr = 0x826A02A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a02b4
	if (cr6.eq) goto loc_826A02B4;
	// bl 0x826b1f88
	ctx.lr = 0x826A02B0;
	sub_826B1F88(ctx, base);
	// b 0x826a02b8
	goto loc_826A02B8;
loc_826A02B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826A02B8:
	// lis r6,0
	ctx.r6.s64 = 0;
	// stw r3,21680(r31)
	PPC_STORE_U32(r31.u32 + 21680, ctx.r3.u32);
	// lis r11,0
	r11.s64 = 0;
	// stw r30,21672(r31)
	PPC_STORE_U32(r31.u32 + 21672, r30.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r30,21676(r31)
	PPC_STORE_U32(r31.u32 + 21676, r30.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stw r30,21664(r31)
	PPC_STORE_U32(r31.u32 + 21664, r30.u32);
	// ori r6,r6,57768
	ctx.r6.u64 = ctx.r6.u64 | 57768;
	// stb r30,21684(r31)
	PPC_STORE_U8(r31.u32 + 21684, r30.u8);
	// ori r11,r11,57776
	r11.u64 = r11.u64 | 57776;
	// stb r30,21668(r31)
	PPC_STORE_U8(r31.u32 + 21668, r30.u8);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r10,r10,57992
	ctx.r10.u64 = ctx.r10.u64 | 57992;
	// ori r9,r9,57984
	ctx.r9.u64 = ctx.r9.u64 | 57984;
	// stwx r29,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, r29.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stbx r30,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r30.u8);
	// ori r8,r8,57780
	ctx.r8.u64 = ctx.r8.u64 | 57780;
	// ori r7,r7,57980
	ctx.r7.u64 = ctx.r7.u64 | 57980;
	// lis r20,0
	r20.s64 = 0;
	// stwx r30,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r30.u32);
	// ori r5,r5,39260
	ctx.r5.u64 = ctx.r5.u64 | 39260;
	// stbx r30,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r30.u8);
	// lis r28,0
	r28.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// stwx r29,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r29.u32);
	// lis r24,0
	r24.s64 = 0;
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// lis r23,0
	r23.s64 = 0;
	// ori r6,r20,39244
	ctx.r6.u64 = r20.u64 | 39244;
	// stwx r30,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r30.u32);
	// ori r11,r28,57712
	r11.u64 = r28.u64 | 57712;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r22,0
	r22.s64 = 0;
	// lis r21,0
	r21.s64 = 0;
	// ori r3,r3,39356
	ctx.r3.u64 = ctx.r3.u64 | 39356;
	// stbx r30,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, r30.u8);
	// ori r10,r24,57772
	ctx.r10.u64 = r24.u64 | 57772;
	// stwx r30,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r30.u32);
	// ori r9,r23,57704
	ctx.r9.u64 = r23.u64 | 57704;
	// lis r19,-32256
	r19.s64 = -2113929216;
	// lis r18,-32256
	r18.s64 = -2113929216;
	// ori r4,r4,39256
	ctx.r4.u64 = ctx.r4.u64 | 39256;
	// stwx r30,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r30.u32);
	// ori r8,r22,57700
	ctx.r8.u64 = r22.u64 | 57700;
	// stwx r30,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r30.u32);
	// ori r7,r21,39228
	ctx.r7.u64 = r21.u64 | 39228;
	// stwx r29,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r29.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lfs f0,17032(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r19.u32 + 17032);
	f0.f64 = double(temp.f32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f13,7444(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r11,20
	r11.s64 = 20;
	// stfs f0,21688(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 21688, temp.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stbx r6,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, ctx.r6.u8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stwx r29,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r29.u32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// stbx r30,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r30.u8);
	// stfs f13,21692(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 21692, temp.u32);
	// stw r11,-29212(r5)
	PPC_STORE_U32(ctx.r5.u32 + -29212, r11.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// ori r6,r10,39248
	ctx.r6.u64 = ctx.r10.u64 | 39248;
	// ori r5,r9,39524
	ctx.r5.u64 = ctx.r9.u64 | 39524;
	// ori r3,r3,39232
	ctx.r3.u64 = ctx.r3.u64 | 39232;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// lfs f12,-31384(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31384);
	ctx.f12.f64 = double(temp.f32);
	// li r11,6
	r11.s64 = 6;
	// stfsx f12,r31,r6
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, temp.u32);
	// addi r10,r10,-25952
	ctx.r10.s64 = ctx.r10.s64 + -25952;
	// stwx r29,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r29.u32);
	// stfsx f31,r31,r3
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, temp.u32);
	// li r9,25
	ctx.r9.s64 = 25;
	// stw r11,-29208(r4)
	PPC_STORE_U32(ctx.r4.u32 + -29208, r11.u32);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lfs f4,-26972(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -26972);
	ctx.f4.f64 = double(temp.f32);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lfs f5,-26976(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -26976);
	ctx.f5.f64 = double(temp.f32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lfs f6,-26980(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -26980);
	ctx.f6.f64 = double(temp.f32);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lfs f7,-26984(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -26984);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,-11624(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -11624);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,-26988(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -26988);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,-26992(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -26992);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,-26996(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -26996);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-27000(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -27000);
	ctx.f12.f64 = double(temp.f32);
loc_826A0444:
	// stfs f12,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f9,8(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f31,16(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stfs f8,20(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stfs f31,32(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// stfs f31,36(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// stfs f31,40(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// stfs f7,1200(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 1200, temp.u32);
	// stfs f6,1216(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 1216, temp.u32);
	// stfs f5,1220(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 1220, temp.u32);
	// stfs f4,1224(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 1224, temp.u32);
	// stfs f13,1232(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 1232, temp.u32);
	// stfs f13,1236(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 1236, temp.u32);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// bne 0x826a0444
	if (!cr0.eq) goto loc_826A0444;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// ori r9,r9,39588
	ctx.r9.u64 = ctx.r9.u64 | 39588;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r11,0
	r11.s64 = 0;
	// ori r8,r8,39592
	ctx.r8.u64 = ctx.r8.u64 | 39592;
	// ori r7,r7,39600
	ctx.r7.u64 = ctx.r7.u64 | 39600;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lfsx f11,r31,r9
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	ctx.f11.f64 = double(temp.f32);
	// ori r11,r11,39596
	r11.u64 = r11.u64 | 39596;
	// ori r9,r6,39292
	ctx.r9.u64 = ctx.r6.u64 | 39292;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lfsx f10,r31,r8
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	ctx.f10.f64 = double(temp.f32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lfsx f9,r31,r7
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	ctx.f9.f64 = double(temp.f32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfsx f12,r31,r11
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// lis r28,0
	r28.s64 = 0;
	// stfsx f12,r31,r9
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, temp.u32);
	// lis r24,0
	r24.s64 = 0;
	// ori r8,r5,39268
	ctx.r8.u64 = ctx.r5.u64 | 39268;
	// ori r7,r4,39296
	ctx.r7.u64 = ctx.r4.u64 | 39296;
	// lis r23,0
	r23.s64 = 0;
	// ori r6,r3,39272
	ctx.r6.u64 = ctx.r3.u64 | 39272;
	// ori r5,r10,39300
	ctx.r5.u64 = ctx.r10.u64 | 39300;
	// lis r29,0
	r29.s64 = 0;
	// stfsx f12,r31,r8
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, temp.u32);
	// ori r3,r28,39304
	ctx.r3.u64 = r28.u64 | 39304;
	// stfsx f13,r31,r7
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, temp.u32);
	// ori r10,r24,39280
	ctx.r10.u64 = r24.u64 | 39280;
	// ori r9,r23,39308
	ctx.r9.u64 = r23.u64 | 39308;
	// stfsx f13,r31,r6
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, temp.u32);
	// ori r4,r29,39276
	ctx.r4.u64 = r29.u64 | 39276;
	// stfsx f11,r31,r5
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, temp.u32);
	// lis r22,0
	r22.s64 = 0;
	// lis r21,0
	r21.s64 = 0;
	// stfsx f10,r31,r3
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, temp.u32);
	// lis r20,-32111
	r20.s64 = -2104426496;
	// stfsx f10,r31,r10
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, temp.u32);
	// lis r18,0
	r18.s64 = 0;
	// stfsx f9,r31,r9
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, temp.u32);
	// lis r11,0
	r11.s64 = 0;
	// stfsx f11,r31,r4
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, temp.u32);
	// ori r8,r22,39284
	ctx.r8.u64 = r22.u64 | 39284;
	// ori r7,r21,39328
	ctx.r7.u64 = r21.u64 | 39328;
	// addi r6,r20,-29216
	ctx.r6.s64 = r20.s64 + -29216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r19,0
	r19.s64 = 0;
	// ori r11,r11,39344
	r11.u64 = r11.u64 | 39344;
	// stfsx f9,r31,r8
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, temp.u32);
	// ori r3,r18,39264
	ctx.r3.u64 = r18.u64 | 39264;
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r9,r31,1
	ctx.r9.s64 = r31.s64 + 65536;
	// lfs f13,14988(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// ori r4,r19,39240
	ctx.r4.u64 = r19.u64 | 39240;
	// addi r10,r10,-26388
	ctx.r10.s64 = ctx.r10.s64 + -26388;
	// stfsx f13,r31,r11
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// addi r9,r9,-26348
	ctx.r9.s64 = ctx.r9.s64 + -26348;
	// stwx r30,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r30.u32);
	// addis r8,r31,1
	ctx.r8.s64 = r31.s64 + 65536;
	// addis r7,r31,1
	ctx.r7.s64 = r31.s64 + 65536;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// addis r5,r31,1
	ctx.r5.s64 = r31.s64 + 65536;
	// stfs f31,0(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// stfs f31,4(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addi r8,r8,-26380
	ctx.r8.s64 = ctx.r8.s64 + -26380;
	// addi r7,r7,-26340
	ctx.r7.s64 = ctx.r7.s64 + -26340;
	// addi r6,r6,-26372
	ctx.r6.s64 = ctx.r6.s64 + -26372;
	// addi r5,r5,-26332
	ctx.r5.s64 = ctx.r5.s64 + -26332;
	// addi r3,r3,-26364
	ctx.r3.s64 = ctx.r3.s64 + -26364;
	// addi r11,r11,-26324
	r11.s64 = r11.s64 + -26324;
	// stfs f31,0(r8)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// stfs f31,4(r8)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// addis r9,r31,1
	ctx.r9.s64 = r31.s64 + 65536;
	// stfs f0,0(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r10,r10,-26356
	ctx.r10.s64 = ctx.r10.s64 + -26356;
	// stfs f0,4(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// addi r9,r9,-26316
	ctx.r9.s64 = ctx.r9.s64 + -26316;
	// stfs f31,0(r6)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// stfs f31,4(r6)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stfs f0,4(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// stfs f31,0(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f31,4(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f31,0(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f31,4(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// bl 0x824e06e0
	ctx.lr = 0x826A062C;
	sub_824E06E0(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r3,r8,49588
	ctx.r3.u64 = ctx.r8.u64 | 49588;
	// lis r5,-32111
	ctx.r5.s64 = -2104426496;
	// lis r4,-32111
	ctx.r4.s64 = -2104426496;
	// lfs f12,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// ori r7,r7,49584
	ctx.r7.u64 = ctx.r7.u64 | 49584;
	// ori r6,r6,39229
	ctx.r6.u64 = ctx.r6.u64 | 39229;
	// stwx r30,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r30.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r29,-32244
	r29.s64 = -2113142784;
	// addi r28,r5,-29312
	r28.s64 = ctx.r5.s64 + -29312;
	// addi r25,r4,-29200
	r25.s64 = ctx.r4.s64 + -29200;
	// mr r11,r30
	r11.u64 = r30.u64;
	// lfs f0,-11300(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11300);
	f0.f64 = double(temp.f32);
	// lfs f13,4764(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4764);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// stw r11,-29336(r10)
	PPC_STORE_U32(ctx.r10.u32 + -29336, r11.u32);
	// lfs f11,-27004(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -27004);
	ctx.f11.f64 = double(temp.f32);
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stbx r30,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, r30.u8);
	// stfs f0,-29312(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + -29312, temp.u32);
	// stfs f12,-29200(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + -29200, temp.u32);
	// lis r29,-32125
	r29.s64 = -2105344000;
	// stfs f13,4(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r28.u32 + 4, temp.u32);
	// addi r30,r3,-14596
	r30.s64 = ctx.r3.s64 + -14596;
	// stfs f31,8(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 8, temp.u32);
	// addi r24,r11,-14960
	r24.s64 = r11.s64 + -14960;
	// stfs f11,4(r25)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r25.u32 + 4, temp.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stfs f31,8(r25)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r25.u32 + 8, temp.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stfs f0,16(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 16, temp.u32);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// stfs f13,20(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r28.u32 + 20, temp.u32);
	// addi r5,r10,-27016
	ctx.r5.s64 = ctx.r10.s64 + -27016;
	// stfs f31,24(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 24, temp.u32);
	// li r7,160
	ctx.r7.s64 = 160;
	// stfs f12,16(r25)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r25.u32 + 16, temp.u32);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// stfs f11,20(r25)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r25.u32 + 20, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stfs f31,24(r25)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r25.u32 + 24, temp.u32);
	// lwz r3,2832(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 2832);
	// bl 0x82202b98
	ctx.lr = 0x826A06F4;
	sub_82202B98(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// addi r5,r7,-27032
	ctx.r5.s64 = ctx.r7.s64 + -27032;
	// lwz r3,2832(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 2832);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// li r7,17292
	ctx.r7.s64 = 17292;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82202b98
	ctx.lr = 0x826A0718;
	sub_82202B98(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r5,r6,-27048
	ctx.r5.s64 = ctx.r6.s64 + -27048;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213058
	ctx.lr = 0x826A0738;
	sub_82213058(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r5,-27064
	ctx.r5.s64 = ctx.r5.s64 + -27064;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213058
	ctx.lr = 0x826A0754;
	sub_82213058(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r30,9
	r30.s64 = 9;
	// addi r28,r11,-27084
	r28.s64 = r11.s64 + -27084;
loc_826A0760:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r6,r30,-9
	ctx.r6.s64 = r30.s64 + -9;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826A0774;
	sub_82137A08(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213058
	ctx.lr = 0x826A078C;
	sub_82213058(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,14
	cr6.compare<int32_t>(r30.s32, 14, xer);
	// ble cr6,0x826a0760
	if (!cr6.gt) goto loc_826A0760;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r26,r11,30576
	r26.s64 = r11.s64 + 30576;
	// addi r4,r10,-27108
	ctx.r4.s64 = ctx.r10.s64 + -27108;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821ca540
	ctx.lr = 0x826A07B0;
	sub_821CA540(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r30,18
	r30.s64 = 18;
	// li r28,26
	r28.s64 = 26;
	// addi r27,r11,-27124
	r27.s64 = r11.s64 + -27124;
loc_826A07C0:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r6,r30,-24
	ctx.r6.s64 = r30.s64 + -24;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826A07D4;
	sub_82137A08(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213058
	ctx.lr = 0x826A07EC;
	sub_82213058(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne 0x826a07c0
	if (!cr0.eq) goto loc_826A07C0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826A0800;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_826A0810"))) PPC_WEAK_FUNC(sub_826A0810);
PPC_FUNC_IMPL(__imp__sub_826A0810) {
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
	// bl 0x8269cb58
	ctx.lr = 0x826A0830;
	sub_8269CB58(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826a0848
	if (cr6.eq) goto loc_826A0848;
	// bl 0x82130588
	ctx.lr = 0x826A0844;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826A0848:
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

__attribute__((alias("__imp__sub_826A0860"))) PPC_WEAK_FUNC(sub_826A0860);
PPC_FUNC_IMPL(__imp__sub_826A0860) {
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
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,58000
	ctx.r3.u64 = ctx.r3.u64 | 58000;
	// bl 0x82130528
	ctx.lr = 0x826A0878;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a0888
	if (cr6.eq) goto loc_826A0888;
	// bl 0x826a0158
	ctx.lr = 0x826A0884;
	sub_826A0158(ctx, base);
	// b 0x826a088c
	goto loc_826A088C;
loc_826A0888:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826A088C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-29340(r11)
	PPC_STORE_U32(r11.u32 + -29340, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826A08A4"))) PPC_WEAK_FUNC(sub_826A08A4);
PPC_FUNC_IMPL(__imp__sub_826A08A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A08A8"))) PPC_WEAK_FUNC(sub_826A08A8);
PPC_FUNC_IMPL(__imp__sub_826A08A8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x826A08B0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A08C4;
	sub_822A3998(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r3,r9,-26948
	ctx.r3.s64 = ctx.r9.s64 + -26948;
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// addi r22,r11,64
	r22.s64 = r11.s64 + 64;
	// bl 0x821fa230
	ctx.lr = 0x826A08E0;
	sub_821FA230(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// li r24,3
	r24.s64 = 3;
	// li r19,1
	r19.s64 = 1;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// addi r21,r11,-14196
	r21.s64 = r11.s64 + -14196;
	// addi r23,r10,-26956
	r23.s64 = ctx.r10.s64 + -26956;
	// addi r29,r9,-26968
	r29.s64 = ctx.r9.s64 + -26968;
	// addi r26,r8,-21664
	r26.s64 = ctx.r8.s64 + -21664;
loc_826A0914:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82392460
	ctx.lr = 0x826A0920;
	sub_82392460(ctx, base);
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x826A0934;
	sub_821F9FB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,56(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r24,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r24.u32);
	// bl 0x821c9790
	ctx.lr = 0x826A0950;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x826A0960;
	sub_825ED480(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826a0978
	if (!cr6.eq) goto loc_826A0978;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821bd618
	ctx.lr = 0x826A0978;
	sub_821BD618(ctx, base);
loc_826A0978:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ed4a0
	ctx.lr = 0x826A098C;
	sub_825ED4A0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x826A0998;
	sub_8268DCB0(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268da78
	ctx.lr = 0x826A09A4;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a09b4
	if (cr6.eq) goto loc_826A09B4;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
	// stw r19,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r19.u32);
loc_826A09B4:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,7
	cr6.compare<int32_t>(r28.s32, 7, xer);
	// blt cr6,0x826a0914
	if (cr6.lt) goto loc_826A0914;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_826A09C8"))) PPC_WEAK_FUNC(sub_826A09C8);
PPC_FUNC_IMPL(__imp__sub_826A09C8) {
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
	ctx.lr = 0x826A09D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A09F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x826A0A00;
	sub_8268DCB0(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-26956
	ctx.r4.s64 = ctx.r9.s64 + -26956;
	// bl 0x8268da78
	ctx.lr = 0x826A0A10;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a0a1c
	if (cr6.eq) goto loc_826A0A1C;
	// lwz r31,4(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_826A0A1C:
	// add. r11,r31,r29
	r11.u64 = r31.u64 + r29.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r9,43
	ctx.r9.s64 = 43;
	// blt 0x826a0a2c
	if (cr0.lt) goto loc_826A0A2C;
	// li r9,0
	ctx.r9.s64 = 0;
loc_826A0A2C:
	// lis r10,12192
	ctx.r10.s64 = 799014912;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// ori r7,r10,48771
	ctx.r7.u64 = ctx.r10.u64 | 48771;
	// mulhw r6,r8,r7
	ctx.r6.s64 = (int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32)) >> 32;
	// srawi r11,r6,3
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	r11.s64 = ctx.r6.s32 >> 3;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mulli r4,r5,43
	ctx.r4.s64 = ctx.r5.s64 * 43;
	// subf r11,r4,r8
	r11.s64 = ctx.r8.s64 - ctx.r4.s64;
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// cmpwi cr6,r31,15
	cr6.compare<int32_t>(r31.s32, 15, xer);
	// beq cr6,0x826a0a64
	if (cr6.eq) goto loc_826A0A64;
	// cmpwi cr6,r31,16
	cr6.compare<int32_t>(r31.s32, 16, xer);
	// bne cr6,0x826a0a74
	if (!cr6.eq) goto loc_826A0A74;
loc_826A0A64:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// li r31,17
	r31.s64 = 17;
	// bgt cr6,0x826a0a74
	if (cr6.gt) goto loc_826A0A74;
	// li r31,14
	r31.s64 = 14;
loc_826A0A74:
	// li r11,1
	r11.s64 = 1;
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A0A90;
	sub_822A3998(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r7,48(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,132(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 132);
	// lwz r6,336(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 336);
	// addi r29,r11,64
	r29.s64 = r11.s64 + 64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826A0AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823924b0
	ctx.lr = 0x826A0AC4;
	sub_823924B0(ctx, base);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r28,r5,-21664
	r28.s64 = ctx.r5.s64 + -21664;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A0ADC;
	sub_821F9FB8(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,336(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 336);
	// lwz r30,56(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A0AF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,-26968
	ctx.r4.s64 = ctx.r8.s64 + -26968;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203058
	ctx.lr = 0x826A0B1C;
	sub_82203058(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A0B28;
	sub_821F9FB8(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r7,1072
	ctx.r4.s64 = ctx.r7.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x826A0B3C;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826A0B44"))) PPC_WEAK_FUNC(sub_826A0B44);
PPC_FUNC_IMPL(__imp__sub_826A0B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A0B48"))) PPC_WEAK_FUNC(sub_826A0B48);
PPC_FUNC_IMPL(__imp__sub_826A0B48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A0B74;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,57692
	ctx.r7.u64 = ctx.r9.u64 | 57692;
	// ori r6,r8,57696
	ctx.r6.u64 = ctx.r8.u64 | 57696;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r5,r31,r7
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lwzx r4,r31,r6
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// bl 0x82393118
	ctx.lr = 0x826A0B9C;
	sub_82393118(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f31,7444(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f31.f64 = double(temp.f32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// rlwinm r6,r10,24,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// rlwinm r4,r10,16,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFF;
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// lfs f0,15364(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15364);
	f0.f64 = double(temp.f32);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// fmuls f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f3,100(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f2,104(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmuls f4,f7,f0
	ctx.f4.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f4,96(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x8261e1a0
	ctx.lr = 0x826A0C1C;
	sub_8261E1A0(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lfs f0,31016(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r8,-21664
	r30.s64 = ctx.r8.s64 + -21664;
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821f9fb8
	ctx.lr = 0x826A0C60;
	sub_821F9FB8(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// fctiwz f0,f1
	f0.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// addi r4,r7,-26880
	ctx.r4.s64 = ctx.r7.s64 + -26880;
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825ee0e0
	ctx.lr = 0x826A0C80;
	sub_825EE0E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A0C8C;
	sub_821F9FB8(ctx, base);
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r4,r6,-26896
	ctx.r4.s64 = ctx.r6.s64 + -26896;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x826A0CAC;
	sub_825EE0E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A0CB8;
	sub_821F9FB8(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lfs f11,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// addi r4,r5,-26912
	ctx.r4.s64 = ctx.r5.s64 + -26912;
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825ee0e0
	ctx.lr = 0x826A0CD8;
	sub_825EE0E0(ctx, base);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f9,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,11360(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f8,112(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8261e2b8
	ctx.lr = 0x826A0CFC;
	sub_8261E2B8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lis r7,-1
	ctx.r7.s64 = -65536;
	// lfs f0,15360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v59,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v56,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// fctidz f3,f7
	ctx.f3.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// fctidz f2,f6
	ctx.f2.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lbz r11,87(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// rlwimi r7,r11,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r31,r9,r5
	r31.u64 = ctx.r9.u64 | ctx.r5.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x826A0D78;
	sub_821F9FB8(ctx, base);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,-26932
	ctx.r4.s64 = ctx.r8.s64 + -26932;
	// bl 0x825ee0e0
	ctx.lr = 0x826A0D8C;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

__attribute__((alias("__imp__sub_826A0DA8"))) PPC_WEAK_FUNC(sub_826A0DA8);
PPC_FUNC_IMPL(__imp__sub_826A0DA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A0DD4;
	sub_822A3998(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ori r7,r10,39356
	ctx.r7.u64 = ctx.r10.u64 | 39356;
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// lfs f31,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwzx r10,r31,r7
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r10,-2
	ctx.r9.s64 = ctx.r10.s64 + -2;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// cmplwi cr6,r9,19
	cr6.compare<uint32_t>(ctx.r9.u32, 19, xer);
	// bgt cr6,0x826a0f7c
	if (cr6.gt) goto loc_826A0F7C;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,3624
	r12.s64 = r12.s64 + 3624;
	// rlwinm r0,r9,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r9.u64) {
	case 0:
		goto loc_826A0E9C;
	case 1:
		goto loc_826A0EB0;
	case 2:
		goto loc_826A0EC4;
	case 3:
		goto loc_826A0F7C;
	case 4:
		goto loc_826A0F7C;
	case 5:
		goto loc_826A0ED8;
	case 6:
		goto loc_826A0EEC;
	case 7:
		goto loc_826A0F00;
	case 8:
		goto loc_826A0F14;
	case 9:
		goto loc_826A0F28;
	case 10:
		goto loc_826A0F3C;
	case 11:
		goto loc_826A0F50;
	case 12:
		goto loc_826A0F64;
	case 13:
		goto loc_826A0F7C;
	case 14:
		goto loc_826A0F7C;
	case 15:
		goto loc_826A0F7C;
	case 16:
		goto loc_826A0F7C;
	case 17:
		goto loc_826A0F7C;
	case 18:
		goto loc_826A0E78;
	case 19:
		goto loc_826A0E88;
	default:
		__builtin_unreachable();
	}
	// lwz r19,3740(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3740);
	// lwz r19,3760(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3760);
	// lwz r19,3780(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3780);
	// lwz r19,3964(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3964);
	// lwz r19,3964(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3964);
	// lwz r19,3800(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3800);
	// lwz r19,3820(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3820);
	// lwz r19,3840(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3840);
	// lwz r19,3860(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3860);
	// lwz r19,3880(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3880);
	// lwz r19,3900(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3900);
	// lwz r19,3920(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3920);
	// lwz r19,3940(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3940);
	// lwz r19,3964(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3964);
	// lwz r19,3964(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3964);
	// lwz r19,3964(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3964);
	// lwz r19,3964(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3964);
	// lwz r19,3964(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3964);
	// lwz r19,3704(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3704);
	// lwz r19,3720(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3720);
loc_826A0E78:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0E88:
	// li r11,16
	r11.s64 = 16;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r10,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0E9C:
	// li r11,64
	r11.s64 = 64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r10,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0EB0:
	// li r11,80
	r11.s64 = 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r10,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0EC4:
	// li r11,96
	r11.s64 = 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r10,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0ED8:
	// li r11,32
	r11.s64 = 32;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r10,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0EEC:
	// li r11,48
	r11.s64 = 48;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v57,r10,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0F00:
	// li r10,1408
	ctx.r10.s64 = 1408;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v56,r11,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0F14:
	// li r10,1424
	ctx.r10.s64 = 1424;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v55,r11,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0F28:
	// li r10,1440
	ctx.r10.s64 = 1440;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v54,r11,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0F3C:
	// li r10,1456
	ctx.r10.s64 = 1456;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v53,r11,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0F50:
	// li r10,1472
	ctx.r10.s64 = 1472;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v52,r11,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a0f7c
	goto loc_826A0F7C;
loc_826A0F64:
	// lfs f0,280(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 280);
	f0.f64 = double(temp.f32);
	// lfs f13,276(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,272(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_826A0F7C:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261e1a0
	ctx.lr = 0x826A0F84;
	sub_8261E1A0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r7,-21664
	r30.s64 = ctx.r7.s64 + -21664;
	// lvlx128 v51,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// lvx128 v49,r0,r9
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// vmulfp128 v48,v49,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// stvx128 v48,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821f9fb8
	ctx.lr = 0x826A0FC8;
	sub_821F9FB8(ctx, base);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// addi r4,r6,-26880
	ctx.r4.s64 = ctx.r6.s64 + -26880;
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825ee0e0
	ctx.lr = 0x826A0FE8;
	sub_825EE0E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A0FF4;
	sub_821F9FB8(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lfs f12,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// addi r4,r5,-26896
	ctx.r4.s64 = ctx.r5.s64 + -26896;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825ee0e0
	ctx.lr = 0x826A1014;
	sub_825EE0E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1020;
	sub_821F9FB8(ctx, base);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lfs f10,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// addi r4,r4,-26912
	ctx.r4.s64 = ctx.r4.s64 + -26912;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825ee0e0
	ctx.lr = 0x826A1040;
	sub_825EE0E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f8,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f7,112(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x8261e2b8
	ctx.lr = 0x826A1064;
	sub_8261E2B8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lis r6,-1
	ctx.r6.s64 = -65536;
	// lfs f0,15360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15360);
	f0.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v47,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v46,v47,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// lvx128 v45,r0,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v44,v45,v46
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32)));
	// stvx128 v44,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// lfs f6,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f3,f6
	ctx.f3.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f4.u64);
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// lfs f2,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f2.f64 = double(temp.f32);
	// lbz r11,95(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f1.u64);
	// lbz r10,95(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// rlwimi r6,r10,8,16,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF00FF);
	// or r9,r6,r11
	ctx.r9.u64 = ctx.r6.u64 | r11.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r31,r8,r5
	r31.u64 = ctx.r8.u64 | ctx.r5.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x826A10E0;
	sub_821F9FB8(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r7,-26932
	ctx.r4.s64 = ctx.r7.s64 + -26932;
	// bl 0x825ee0e0
	ctx.lr = 0x826A10F4;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

__attribute__((alias("__imp__sub_826A1110"))) PPC_WEAK_FUNC(sub_826A1110);
PPC_FUNC_IMPL(__imp__sub_826A1110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A113C;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ori r7,r10,39356
	ctx.r7.u64 = ctx.r10.u64 | 39356;
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// lfs f31,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r10,r11,64
	ctx.r10.s64 = r11.s64 + 64;
	// lwzx r6,r31,r7
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lis r11,0
	r11.s64 = 0;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ori r7,r11,39260
	ctx.r7.u64 = r11.u64 | 39260;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwzx r11,r31,r7
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// bne cr6,0x826a11a0
	if (!cr6.eq) goto loc_826A11A0;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r8,1568
	ctx.r8.s64 = 1568;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v63,r4,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a11bc
	goto loc_826A11BC;
loc_826A11A0:
	// addi r11,r11,33
	r11.s64 = r11.s64 + 33;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r5,r6,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v62,r5,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826A11BC:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261e1a0
	ctx.lr = 0x826A11C4;
	sub_8261E1A0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r7,-21664
	r30.s64 = ctx.r7.s64 + -21664;
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// vmulfp128 v58,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821f9fb8
	ctx.lr = 0x826A1208;
	sub_821F9FB8(ctx, base);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// addi r4,r6,-26880
	ctx.r4.s64 = ctx.r6.s64 + -26880;
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825ee0e0
	ctx.lr = 0x826A1228;
	sub_825EE0E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1234;
	sub_821F9FB8(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lfs f12,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// addi r4,r5,-26896
	ctx.r4.s64 = ctx.r5.s64 + -26896;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825ee0e0
	ctx.lr = 0x826A1254;
	sub_825EE0E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1260;
	sub_821F9FB8(ctx, base);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lfs f10,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// addi r4,r4,-26912
	ctx.r4.s64 = ctx.r4.s64 + -26912;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825ee0e0
	ctx.lr = 0x826A1280;
	sub_825EE0E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f8,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f7,112(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x8261e2b8
	ctx.lr = 0x826A12A4;
	sub_8261E2B8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lis r6,-1
	ctx.r6.s64 = -65536;
	// lfs f0,15360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15360);
	f0.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v57,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v54,v55,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// lfs f6,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f3,f6
	ctx.f3.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f4.u64);
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// lfs f2,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f2.f64 = double(temp.f32);
	// lbz r11,95(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f1.u64);
	// lbz r10,95(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// rlwimi r6,r10,8,16,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF00FF);
	// or r9,r6,r11
	ctx.r9.u64 = ctx.r6.u64 | r11.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r31,r8,r5
	r31.u64 = ctx.r8.u64 | ctx.r5.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x826A1320;
	sub_821F9FB8(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r7,-26932
	ctx.r4.s64 = ctx.r7.s64 + -26932;
	// bl 0x825ee0e0
	ctx.lr = 0x826A1334;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

__attribute__((alias("__imp__sub_826A1350"))) PPC_WEAK_FUNC(sub_826A1350);
PPC_FUNC_IMPL(__imp__sub_826A1350) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// addis r11,r3,1
	r11.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-7548
	r11.s64 = r11.s64 + -7548;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bne 0x826a13b4
	if (!cr0.eq) goto loc_826A13B4;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r3,r9,-26864
	ctx.r3.s64 = ctx.r9.s64 + -26864;
	// bl 0x821fa230
	ctx.lr = 0x826A1388;
	sub_821FA230(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x826a13a4
	if (!cr6.eq) goto loc_826A13A4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_826A13A4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,348(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 348);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A13B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826A13B4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826A13C4"))) PPC_WEAK_FUNC(sub_826A13C4);
PPC_FUNC_IMPL(__imp__sub_826A13C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A13C8"))) PPC_WEAK_FUNC(sub_826A13C8);
PPC_FUNC_IMPL(__imp__sub_826A13C8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A13F0;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,57692
	ctx.r7.u64 = ctx.r9.u64 | 57692;
	// ori r6,r8,57696
	ctx.r6.u64 = ctx.r8.u64 | 57696;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r5,r31,r7
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lwzx r4,r31,r6
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// bl 0x82393118
	ctx.lr = 0x826A1418;
	sub_82393118(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r4,-21664
	ctx.r4.s64 = ctx.r4.s64 + -21664;
	// lwz r3,-10236(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1430;
	sub_821F9FB8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-26844
	ctx.r4.s64 = r11.s64 + -26844;
	// bl 0x825ee120
	ctx.lr = 0x826A1444;
	sub_825EE120(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r9,5
	ctx.r9.s64 = 5;
	// ori r8,r10,57988
	ctx.r8.u64 = ctx.r10.u64 | 57988;
	// sth r7,16(r30)
	PPC_STORE_U16(r30.u32 + 16, ctx.r7.u16);
	// stwx r9,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_826A1474"))) PPC_WEAK_FUNC(sub_826A1474);
PPC_FUNC_IMPL(__imp__sub_826A1474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A1478"))) PPC_WEAK_FUNC(sub_826A1478);
PPC_FUNC_IMPL(__imp__sub_826A1478) {
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
	ctx.lr = 0x826A1480;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A1498;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// addi r31,r31,-7840
	r31.s64 = r31.s64 + -7840;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823931c0
	ctx.lr = 0x826A14B4;
	sub_823931C0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x826a14d0
	if (cr6.eq) goto loc_826A14D0;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r28,64
	r28.s64 = 64;
	// bne cr6,0x826a14d4
	if (!cr6.eq) goto loc_826A14D4;
loc_826A14D0:
	// li r28,16
	r28.s64 = 16;
loc_826A14D4:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26864
	ctx.r3.s64 = r11.s64 + -26864;
	// bl 0x821fa230
	ctx.lr = 0x826A14E0;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
loc_826A14E8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x826A14F4;
	sub_8268DCB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a1528
	if (cr6.eq) goto loc_826A1528;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// bgt cr6,0x826a1518
	if (cr6.gt) goto loc_826A1518;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// bge cr6,0x826a1518
	if (!cr6.lt) goto loc_826A1518;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// b 0x826a1520
	goto loc_826A1520;
loc_826A1518:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
loc_826A1520:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A1528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826A1528:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,64
	cr6.compare<int32_t>(r31.s32, 64, xer);
	// blt cr6,0x826a14e8
	if (cr6.lt) goto loc_826A14E8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A1548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpw cr6,r4,r29
	cr6.compare<int32_t>(ctx.r4.s32, r29.s32, xer);
	// bgt cr6,0x826a155c
	if (cr6.gt) goto loc_826A155C;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x826a1560
	if (!cr6.lt) goto loc_826A1560;
loc_826A155C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_826A1560:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x826A1568;
	sub_8268DCB0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826A1570"))) PPC_WEAK_FUNC(sub_826A1570);
PPC_FUNC_IMPL(__imp__sub_826A1570) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x826A1578;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// li r27,0
	r27.s64 = 0;
	// addi r30,r30,-7840
	r30.s64 = r30.s64 + -7840;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x826a15a0
	if (!cr6.lt) goto loc_826A15A0;
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
loc_826A15A0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-21664
	ctx.r4.s64 = ctx.r10.s64 + -21664;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A15B4;
	sub_821F9FB8(ctx, base);
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x826a15f8
	if (!cr6.eq) goto loc_826A15F8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-26708
	ctx.r4.s64 = r11.s64 + -26708;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826A15D4;
	sub_825EE0E0(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r10,-26844
	ctx.r4.s64 = ctx.r10.s64 + -26844;
	// bl 0x825ee0e0
	ctx.lr = 0x826A15E8;
	sub_825EE0E0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826a1478
	ctx.lr = 0x826A15F0;
	sub_826A1478(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826A15F8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A1608;
	sub_822A3998(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// ori r8,r10,57692
	ctx.r8.u64 = ctx.r10.u64 | 57692;
	// lwz r10,132(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// lwzx r11,r29,r8
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r8.u32);
	// addi r3,r10,64
	ctx.r3.s64 = ctx.r10.s64 + 64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x826a162c
	if (!cr6.lt) goto loc_826A162C;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_826A162C:
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82393118
	ctx.lr = 0x826A1638;
	sub_82393118(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-26708
	ctx.r4.s64 = r11.s64 + -26708;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826A1650;
	sub_825EE0E0(ctx, base);
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r10,-26844
	ctx.r4.s64 = ctx.r10.s64 + -26844;
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// bl 0x825ee0e0
	ctx.lr = 0x826A1668;
	sub_825EE0E0(ctx, base);
	// lhz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// cmplwi cr6,r8,65535
	cr6.compare<uint32_t>(ctx.r8.u32, 65535, xer);
	// bne cr6,0x826a178c
	if (!cr6.eq) goto loc_826A178C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r9,r10,39188
	ctx.r9.u64 = ctx.r10.u64 | 39188;
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// lfsx f1,r8,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x826A1694;
	sub_8213E850(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r31,2
	ctx.r3.s64 = r31.s64 + 2;
	// addi r7,r11,4899
	ctx.r7.s64 = r11.s64 + 4899;
	// rlwinm r6,r7,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lfsx f1,r6,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r29.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x826A16AC;
	sub_8213E850(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r5,0
	ctx.r5.s64 = 0;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r4,r5,39148
	ctx.r4.u64 = ctx.r5.u64 | 39148;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// lfsx f1,r10,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x826A16CC;
	sub_8213E850(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r31,6
	ctx.r3.s64 = r31.s64 + 6;
	// addi r9,r11,4894
	ctx.r9.s64 = r11.s64 + 4894;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lfsx f1,r8,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x826A16E4;
	sub_8213E850(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stb r27,18(r31)
	PPC_STORE_U8(r31.u32 + 18, r27.u8);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// lfs f1,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x826A16F8;
	sub_8213E850(ctx, base);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// oris r5,r6,65280
	ctx.r5.u64 = ctx.r6.u64 | 4278190080;
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r5.u32);
	// oris r3,r4,255
	ctx.r3.u64 = ctx.r4.u64 | 16711680;
	// rotlwi r11,r3,0
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// ori r10,r11,65280
	ctx.r10.u64 = r11.u64 | 65280;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// ori r8,r9,255
	ctx.r8.u64 = ctx.r9.u64 | 255;
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x826a178c
	if (cr6.gt) goto loc_826A178C;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,5968
	r12.s64 = r12.s64 + 5968;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826A1764;
	case 1:
		goto loc_826A1770;
	case 2:
		goto loc_826A177C;
	case 3:
		goto loc_826A177C;
	case 4:
		goto loc_826A177C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,5988(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5988);
	// lwz r19,6000(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6000);
	// lwz r19,6012(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6012);
	// lwz r19,6012(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6012);
	// lwz r19,6012(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6012);
loc_826A1764:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f1,-29924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29924);
	ctx.f1.f64 = double(temp.f32);
	// b 0x826a1784
	goto loc_826A1784;
loc_826A1770:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f1,-13300(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13300);
	ctx.f1.f64 = double(temp.f32);
	// b 0x826a1784
	goto loc_826A1784;
loc_826A177C:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lfs f1,-29484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29484);
	ctx.f1.f64 = double(temp.f32);
loc_826A1784:
	// addi r3,r31,14
	ctx.r3.s64 = r31.s64 + 14;
	// bl 0x8213e850
	ctx.lr = 0x826A178C;
	sub_8213E850(ctx, base);
loc_826A178C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x826a182c
	if (cr6.gt) goto loc_826A182C;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,6064
	r12.s64 = r12.s64 + 6064;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826A17C8;
	case 1:
		goto loc_826A17D4;
	case 2:
		goto loc_826A17E0;
	case 3:
		goto loc_826A17EC;
	case 4:
		goto loc_826A17F8;
	case 5:
		goto loc_826A1804;
	default:
		__builtin_unreachable();
	}
	// lwz r19,6088(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6088);
	// lwz r19,6100(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6100);
	// lwz r19,6112(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6112);
	// lwz r19,6124(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6124);
	// lwz r19,6136(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6136);
	// lwz r19,6148(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6148);
loc_826A17C8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-26724
	ctx.r4.s64 = ctx.r10.s64 + -26724;
	// b 0x826a180c
	goto loc_826A180C;
loc_826A17D4:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-26740
	ctx.r4.s64 = ctx.r10.s64 + -26740;
	// b 0x826a180c
	goto loc_826A180C;
loc_826A17E0:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-26756
	ctx.r4.s64 = ctx.r10.s64 + -26756;
	// b 0x826a180c
	goto loc_826A180C;
loc_826A17EC:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-26772
	ctx.r4.s64 = ctx.r10.s64 + -26772;
	// b 0x826a180c
	goto loc_826A180C;
loc_826A17F8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-26788
	ctx.r4.s64 = ctx.r10.s64 + -26788;
	// b 0x826a180c
	goto loc_826A180C;
loc_826A1804:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-26808
	ctx.r4.s64 = ctx.r10.s64 + -26808;
loc_826A180C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826A1818;
	sub_82218310(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-26828
	ctx.r4.s64 = ctx.r9.s64 + -26828;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x826A182C;
	sub_825EE2D8(ctx, base);
loc_826A182C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826A1838"))) PPC_WEAK_FUNC(sub_826A1838);
PPC_FUNC_IMPL(__imp__sub_826A1838) {
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
	ctx.lr = 0x826A1840;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r30,r11,-21664
	r30.s64 = r11.s64 + -21664;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1860;
	sub_821F9FB8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x826A1874;
	sub_825EE0E0(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r3,-8256(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8256);
	// lwz r9,1660(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1660);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x826a18c0
	if (!cr6.gt) goto loc_826A18C0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1894;
	sub_821F9FB8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r11,-26676
	ctx.r4.s64 = r11.s64 + -26676;
	// bl 0x825ee0e0
	ctx.lr = 0x826A18A8;
	sub_825EE0E0(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,34
	ctx.r4.s64 = 34;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213338
	ctx.lr = 0x826A18B8;
	sub_82213338(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826A18C0:
	// bl 0x8236dab8
	ctx.lr = 0x826A18C4;
	sub_8236DAB8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x826a1928
	if (cr6.lt) goto loc_826A1928;
	// lis r11,4194
	r11.s64 = 274857984;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// ori r8,r11,19923
	ctx.r8.u64 = r11.u64 | 19923;
	// li r7,1000
	ctx.r7.s64 = 1000;
	// mulhw r6,r9,r8
	ctx.r6.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32)) >> 32;
	// srawi r11,r6,6
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	r11.s64 = ctx.r6.s32 >> 6;
	// divw r4,r3,r7
	ctx.r4.s32 = ctx.r3.s32 / ctx.r7.s32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mulli r11,r5,1000
	r11.s64 = ctx.r5.s64 * 1000;
	// subf r5,r11,r9
	ctx.r5.s64 = ctx.r9.s64 - r11.s64;
	// bl 0x8269d108
	ctx.lr = 0x826A1900;
	sub_8269D108(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A190C;
	sub_821F9FB8(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r10,-26676
	ctx.r4.s64 = ctx.r10.s64 + -26676;
	// bl 0x825ee0e0
	ctx.lr = 0x826A1920;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826A1928:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,34
	ctx.r4.s64 = 34;
	// addi r5,r10,-26688
	ctx.r5.s64 = ctx.r10.s64 + -26688;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x826A1940;
	sub_82213B80(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A194C;
	sub_821F9FB8(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r9,-26676
	ctx.r4.s64 = ctx.r9.s64 + -26676;
	// bl 0x825ee0e0
	ctx.lr = 0x826A1960;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826A1968"))) PPC_WEAK_FUNC(sub_826A1968);
PPC_FUNC_IMPL(__imp__sub_826A1968) {
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
	ctx.lr = 0x826A1970;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-26864
	ctx.r3.s64 = r11.s64 + -26864;
	// bl 0x821fa230
	ctx.lr = 0x826A1984;
	sub_821FA230(ctx, base);
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// lis r28,-32119
	r28.s64 = -2104950784;
	// addi r29,r29,-7840
	r29.s64 = r29.s64 + -7840;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-8256(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -8256);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8236da50
	ctx.lr = 0x826A19A0;
	sub_8236DA50(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r10,-26608
	ctx.r4.s64 = ctx.r10.s64 + -26608;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268da78
	ctx.lr = 0x826A19B8;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a1b1c
	if (cr6.eq) goto loc_826A1B1C;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,101
	cr6.compare<int32_t>(r11.s32, 101, xer);
	// bne cr6,0x826a1b1c
	if (!cr6.eq) goto loc_826A1B1C;
	// lis r11,0
	r11.s64 = 0;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// ori r30,r11,57692
	r30.u64 = r11.u64 | 57692;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// ble cr6,0x826a1a10
	if (!cr6.gt) goto loc_826A1A10;
	// lwz r3,-8256(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -8256);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r5,r31,r30
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x8236daa0
	ctx.lr = 0x826A19F0;
	sub_8236DAA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826a1a10
	if (cr6.eq) goto loc_826A1A10;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26624
	ctx.r3.s64 = r11.s64 + -26624;
	// bl 0x821fa230
	ctx.lr = 0x826A1A08;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x826a1ae8
	goto loc_826A1AE8;
loc_826A1A10:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A1A20;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r5,r31,r30
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// bl 0x82393118
	ctx.lr = 0x826A1A38;
	sub_82393118(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r10,-7864
	ctx.r10.s64 = ctx.r10.s64 + -7864;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826A1A4C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826a1a4c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826A1A4C;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,57688
	ctx.r10.u64 = r11.u64 | 57688;
	// lhzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + ctx.r10.u32);
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x826a1ac0
	if (cr6.lt) goto loc_826A1AC0;
	// lis r11,4194
	r11.s64 = 274857984;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// ori r8,r11,19923
	ctx.r8.u64 = r11.u64 | 19923;
	// li r7,1000
	ctx.r7.s64 = 1000;
	// mulhw r6,r9,r8
	ctx.r6.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32)) >> 32;
	// srawi r11,r6,6
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	r11.s64 = ctx.r6.s32 >> 6;
	// divw r4,r10,r7
	ctx.r4.s32 = ctx.r10.s32 / ctx.r7.s32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mulli r11,r5,1000
	r11.s64 = ctx.r5.s64 * 1000;
	// subf r5,r11,r9
	ctx.r5.s64 = ctx.r9.s64 - r11.s64;
	// bl 0x8269d108
	ctx.lr = 0x826A1AAC;
	sub_8269D108(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r3,r10,-26640
	ctx.r3.s64 = ctx.r10.s64 + -26640;
	// bl 0x821fa230
	ctx.lr = 0x826A1AB8;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x826a1ae8
	goto loc_826A1AE8;
loc_826A1AC0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26660
	ctx.r3.s64 = r11.s64 + -26660;
	// bl 0x821fa230
	ctx.lr = 0x826A1ACC;
	sub_821FA230(ctx, base);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,34
	ctx.r4.s64 = 34;
	// addi r5,r10,-26688
	ctx.r5.s64 = ctx.r10.s64 + -26688;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x826A1AE8;
	sub_82213B80(ctx, base);
loc_826A1AE8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826a1b1c
	if (cr6.eq) goto loc_826A1B1C;
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A1B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826a1b20
	if (cr6.eq) goto loc_826A1B20;
loc_826A1B1C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826A1B20:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826A1B28"))) PPC_WEAK_FUNC(sub_826A1B28);
PPC_FUNC_IMPL(__imp__sub_826A1B28) {
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
	ctx.lr = 0x826A1B30;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A1B4C;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addis r30,r25,1
	r30.s64 = r25.s64 + 65536;
	// addi r30,r30,-7840
	r30.s64 = r30.s64 + -7840;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823931c0
	ctx.lr = 0x826A1B68;
	sub_823931C0(ctx, base);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r26,0
	r26.s64 = 0;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r7,-21664
	ctx.r4.s64 = ctx.r7.s64 + -21664;
	// lwz r3,-10236(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1B90;
	sub_821F9FB8(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r31,r6,2612
	r31.s64 = ctx.r6.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,56(r5)
	r29.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x826A1BAC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x826A1BBC;
	sub_825ED480(ctx, base);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r4,-12116
	ctx.r3.s64 = ctx.r4.s64 + -12116;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x826A1BD4;
	sub_821C9790(ctx, base);
	// li r27,1
	r27.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x826A1BE8;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A1C00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r26
	r31.u64 = r26.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x826a1c88
	if (!cr6.gt) goto loc_826A1C88;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// addi r24,r11,-26596
	r24.s64 = r11.s64 + -26596;
loc_826A1C18:
	// lwz r3,-8256(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -8256);
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// beq cr6,0x826a1c38
	if (cr6.eq) goto loc_826A1C38;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x826a1c40
	goto loc_826A1C40;
loc_826A1C38:
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// li r6,0
	ctx.r6.s64 = 0;
loc_826A1C40:
	// bl 0x8236da38
	ctx.lr = 0x826A1C44;
	sub_8236DA38(ctx, base);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x826A1C4C;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A1C60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x826A1C64;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826A1C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x826a1c18
	if (cr6.lt) goto loc_826A1C18;
loc_826A1C88:
	// lis r11,0
	r11.s64 = 0;
	// li r10,10
	ctx.r10.s64 = 10;
	// ori r9,r11,57768
	ctx.r9.u64 = r11.u64 | 57768;
	// stwx r10,r25,r9
	PPC_STORE_U32(r25.u32 + ctx.r9.u32, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826A1CA0"))) PPC_WEAK_FUNC(sub_826A1CA0);
PPC_FUNC_IMPL(__imp__sub_826A1CA0) {
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
	ctx.lr = 0x826A1CA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// lis r29,-32119
	r29.s64 = -2104950784;
	// addis r30,r26,1
	r30.s64 = r26.s64 + 65536;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r30,-7840
	r30.s64 = r30.s64 + -7840;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-8256(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -8256);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8236daa0
	ctx.lr = 0x826A1CD8;
	sub_8236DAA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,-8256(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -8256);
	// li r27,1
	r27.s64 = 1;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// beq cr6,0x826a1d00
	if (cr6.eq) goto loc_826A1D00;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x826a1d08
	goto loc_826A1D08;
loc_826A1D00:
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// li r6,1
	ctx.r6.s64 = 1;
loc_826A1D08:
	// bl 0x8236da38
	ctx.lr = 0x826A1D0C;
	sub_8236DA38(ctx, base);
	// li r11,7
	r11.s64 = 7;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-21664
	ctx.r4.s64 = ctx.r9.s64 + -21664;
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1D2C;
	sub_821F9FB8(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r30,r8,2612
	r30.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,56(r7)
	r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x826A1D48;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x826A1D58;
	sub_825ED480(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r6,-12116
	ctx.r3.s64 = ctx.r6.s64 + -12116;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x826A1D70;
	sub_821C9790(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x826A1D80;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A1D98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x826A1DA0;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826A1DB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x826A1DB8;
	sub_825EF9F0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-26596
	ctx.r4.s64 = ctx.r7.s64 + -26596;
	// lwz r11,44(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826A1DD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,57768
	ctx.r9.u64 = ctx.r10.u64 | 57768;
	// stwx r27,r26,r9
	PPC_STORE_U32(r26.u32 + ctx.r9.u32, r27.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826A1DE8"))) PPC_WEAK_FUNC(sub_826A1DE8);
PPC_FUNC_IMPL(__imp__sub_826A1DE8) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-8256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8256);
	// lbz r10,248(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 248);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826a1f30
	if (!cr6.eq) goto loc_826A1F30;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A1E2C;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,57692
	ctx.r7.u64 = ctx.r9.u64 | 57692;
	// ori r6,r8,57696
	ctx.r6.u64 = ctx.r8.u64 | 57696;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r5,r31,r7
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lwzx r4,r31,r6
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// bl 0x82393118
	ctx.lr = 0x826A1E54;
	sub_82393118(ctx, base);
	// lbz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// extsw r5,r30
	ctx.r5.s64 = r30.s32;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// lfs f0,15364(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 15364);
	f0.f64 = double(temp.f32);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// lfs f12,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f12.f64 = double(temp.f32);
	// frsp f9,f13
	ctx.f9.f64 = double(float(ctx.f13.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// lfs f11,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f13,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,15360(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 15360);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r9,-21664
	ctx.r4.s64 = ctx.r9.s64 + -21664;
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fmadds f4,f9,f12,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f5.f64));
	// fsel f3,f4,f4,f11
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f4.f64 : ctx.f11.f64;
	// fsubs f2,f3,f13
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f13.f64));
	// fsel f1,f2,f13,f3
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f13.f64 : ctx.f3.f64;
	// fmuls f13,f1,f10
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// rlwimi r8,r6,24,0,7
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r6.u32, 24) & 0xFF000000) | (ctx.r8.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f31,f9,f0
	f31.f64 = double(float(ctx.f9.f64 * f0.f64));
	// bl 0x821f9fb8
	ctx.lr = 0x826A1F08;
	sub_821F9FB8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r4,r9,-26588
	ctx.r4.s64 = ctx.r9.s64 + -26588;
	// lfs f0,31016(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fmuls f8,f31,f0
	ctx.f8.f64 = double(float(f31.f64 * f0.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825ee0e0
	ctx.lr = 0x826A1F30;
	sub_825EE0E0(ctx, base);
loc_826A1F30:
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

__attribute__((alias("__imp__sub_826A1F4C"))) PPC_WEAK_FUNC(sub_826A1F4C);
PPC_FUNC_IMPL(__imp__sub_826A1F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A1F50"))) PPC_WEAK_FUNC(sub_826A1F50);
PPC_FUNC_IMPL(__imp__sub_826A1F50) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91fc
	ctx.lr = 0x826A1F58;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r29,r11,-21664
	r29.s64 = r11.s64 + -21664;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1F78;
	sub_821F9FB8(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r10,-26880
	ctx.r4.s64 = ctx.r10.s64 + -26880;
	// bl 0x825ee120
	ctx.lr = 0x826A1F8C;
	sub_825EE120(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1F98;
	sub_821F9FB8(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r9,-26896
	ctx.r4.s64 = ctx.r9.s64 + -26896;
	// bl 0x825ee120
	ctx.lr = 0x826A1FAC;
	sub_825EE120(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A1FB8;
	sub_821F9FB8(ctx, base);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r8,-26912
	ctx.r4.s64 = ctx.r8.s64 + -26912;
	// bl 0x825ee120
	ctx.lr = 0x826A1FCC;
	sub_825EE120(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// extsw r11,r5
	r11.s64 = ctx.r5.s32;
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// extsw r9,r4
	ctx.r9.s64 = ctx.r4.s32;
	// lfs f0,11360(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	f0.f64 = double(temp.f32);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v63,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f0
	ctx.f9.f64 = double(f0.s64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// stfs f6,0(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// stfs f8,8(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// stfs f7,4(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261e2b8
	ctx.lr = 0x826A204C;
	sub_8261E2B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261e440
	ctx.lr = 0x826A2054;
	sub_8261E440(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x826a206c
	if (cr6.eq) goto loc_826A206C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261e4f8
	ctx.lr = 0x826A206C;
	sub_8261E4F8(ctx, base);
loc_826A206C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826A2074"))) PPC_WEAK_FUNC(sub_826A2074);
PPC_FUNC_IMPL(__imp__sub_826A2074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A2078"))) PPC_WEAK_FUNC(sub_826A2078);
PPC_FUNC_IMPL(__imp__sub_826A2078) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
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
	// bl 0x826a1f50
	ctx.lr = 0x826A20A8;
	sub_826A1F50(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A20B8;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r6,r8,57692
	ctx.r6.u64 = ctx.r8.u64 | 57692;
	// ori r4,r7,57696
	ctx.r4.u64 = ctx.r7.u64 | 57696;
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r5,r31,r6
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// lwzx r4,r31,r4
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r4.u32);
	// bl 0x82393118
	ctx.lr = 0x826A20E0;
	sub_82393118(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,15360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f6,f10
	ctx.f6.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fmuls f3,f11,f0
	ctx.f3.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f4,f9
	ctx.f4.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fmuls f2,f5,f13
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fctiwz f1,f3
	ctx.f1.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fmuls f0,f2,f0
	f0.f64 = double(float(ctx.f2.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwimi r5,r4,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// rlwimi r7,r11,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r6,r7,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_826A217C"))) PPC_WEAK_FUNC(sub_826A217C);
PPC_FUNC_IMPL(__imp__sub_826A217C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A2180"))) PPC_WEAK_FUNC(sub_826A2180);
PPC_FUNC_IMPL(__imp__sub_826A2180) {
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
	ctx.lr = 0x826A2188;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,-8256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8256);
	// lbz r10,248(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 248);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826a2260
	if (!cr6.eq) goto loc_826A2260;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A21BC;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r9,57692
	ctx.r7.u64 = ctx.r9.u64 | 57692;
	// ori r6,r8,57696
	ctx.r6.u64 = ctx.r8.u64 | 57696;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r11,64
	ctx.r3.s64 = r11.s64 + 64;
	// lwzx r5,r30,r7
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + ctx.r7.u32);
	// lwzx r4,r30,r6
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + ctx.r6.u32);
	// bl 0x82393118
	ctx.lr = 0x826A21E4;
	sub_82393118(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r11,r5,57668
	r11.u64 = ctx.r5.u64 | 57668;
	// ori r10,r4,57664
	ctx.r10.u64 = ctx.r4.u64 | 57664;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r9,-28660
	ctx.r4.s64 = ctx.r9.s64 + -28660;
	// stwx r28,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stwx r29,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, r29.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x826A2214;
	sub_8268DA78(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// srawi r5,r6,16
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 16;
	// srawi r11,r6,8
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	r11.s64 = ctx.r6.s32 >> 8;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwimi r7,r10,16,8,15
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// rotlwi r8,r7,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// rlwimi r8,r9,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// rlwimi r7,r6,0,24,31
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0xFF) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// bl 0x826a1de8
	ctx.lr = 0x826A2260;
	sub_826A1DE8(ctx, base);
loc_826A2260:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826A2268"))) PPC_WEAK_FUNC(sub_826A2268);
PPC_FUNC_IMPL(__imp__sub_826A2268) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x826A2270;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-26864
	ctx.r3.s64 = r11.s64 + -26864;
	// bl 0x821fa230
	ctx.lr = 0x826A2284;
	sub_821FA230(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// addi r21,r11,-21664
	r21.s64 = r11.s64 + -21664;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// lwz r3,-10236(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A22A0;
	sub_821F9FB8(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r24,56(r3)
	r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r20,0
	r20.s64 = 0;
	// ori r9,r10,57696
	ctx.r9.u64 = ctx.r10.u64 | 57696;
	// li r8,7
	ctx.r8.s64 = 7;
	// stw r20,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r20.u32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// lwzx r11,r31,r9
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x826a247c
	if (cr6.lt) goto loc_826A247C;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bge cr6,0x826a247c
	if (!cr6.lt) goto loc_826A247C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826a2420
	if (cr6.eq) goto loc_826A2420;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A22EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r4,r9,-26560
	ctx.r4.s64 = ctx.r9.s64 + -26560;
	// bl 0x82203008
	ctx.lr = 0x826A22FC;
	sub_82203008(ctx, base);
	// bl 0x825ef808
	ctx.lr = 0x826A2300;
	sub_825EF808(ctx, base);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r11,r11,-7764
	r11.s64 = r11.s64 + -7764;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r10,r3,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r3.s64;
	// cmpwi cr6,r8,10
	cr6.compare<int32_t>(ctx.r8.s32, 10, xer);
	// bge cr6,0x826a2320
	if (!cr6.lt) goto loc_826A2320;
	// rotlwi r23,r8,0
	r23.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// b 0x826a2324
	goto loc_826A2324;
loc_826A2320:
	// li r23,10
	r23.s64 = 10;
loc_826A2324:
	// cmpwi cr6,r10,10
	cr6.compare<int32_t>(ctx.r10.s32, 10, xer);
	// bge cr6,0x826a2350
	if (!cr6.lt) goto loc_826A2350;
	// lwz r11,-10236(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10236);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r4,r10,24
	ctx.r4.s64 = ctx.r10.s64 + 24;
	// addi r5,r9,-26688
	ctx.r5.s64 = ctx.r9.s64 + -26688;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x826A2344;
	sub_82213B80(ctx, base);
	// cmpwi cr6,r23,10
	cr6.compare<int32_t>(r23.s32, 10, xer);
	// bne cr6,0x826a2350
	if (!cr6.eq) goto loc_826A2350;
	// li r23,9
	r23.s64 = 9;
loc_826A2350:
	// mr r30,r20
	r30.u64 = r20.u64;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x826a2420
	if (!cr6.gt) goto loc_826A2420;
	// lis r9,4194
	ctx.r9.s64 = 274857984;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r26,-32115
	r26.s64 = -2104688640;
	// li r25,1000
	r25.s64 = 1000;
	// ori r29,r9,19923
	r29.u64 = ctx.r9.u64 | 19923;
	// addi r28,r11,9572
	r28.s64 = r11.s64 + 9572;
	// addi r27,r10,-26572
	r27.s64 = ctx.r10.s64 + -26572;
loc_826A237C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x825ede80
	ctx.lr = 0x826A2390;
	sub_825EDE80(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r31,-12040(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + -12040);
	// bl 0x825ef808
	ctx.lr = 0x826A239C;
	sub_825EF808(ctx, base);
	// divw r11,r3,r25
	r11.s32 = ctx.r3.s32 / r25.s32;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r31,r10,r31
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x825ef808
	ctx.lr = 0x826A23B4;
	sub_825EF808(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mulhw r8,r9,r29
	ctx.r8.s64 = (int64_t(ctx.r9.s32) * int64_t(r29.s32)) >> 32;
	// srawi r11,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	r11.s64 = ctx.r8.s32 >> 6;
	// li r4,128
	ctx.r4.s64 = 128;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mulli r6,r7,1000
	ctx.r6.s64 = ctx.r7.s64 * 1000;
	// subf r11,r6,r9
	r11.s64 = ctx.r9.s64 - ctx.r6.s64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r11,r31
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82137a08
	ctx.lr = 0x826A23E8;
	sub_82137A08(ctx, base);
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823db6d0
	ctx.lr = 0x826A23F4;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a2400
	if (cr6.eq) goto loc_826A2400;
	// stb r20,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r20.u8);
loc_826A2400:
	// lwz r11,-10236(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10236);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r30,24
	ctx.r4.s64 = r30.s64 + 24;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x826A2414;
	sub_82213B80(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r23
	cr6.compare<int32_t>(r30.s32, r23.s32, xer);
	// blt cr6,0x826a237c
	if (cr6.lt) goto loc_826A237C;
loc_826A2420:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r31,r11,2612
	r31.s64 = r11.s64 + 2612;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x826A2434;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x826A2444;
	sub_825ED480(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-10964
	ctx.r4.s64 = ctx.r9.s64 + -10964;
	// bl 0x82722678
	ctx.lr = 0x826A245C;
	sub_82722678(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// lwz r3,-10236(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A2468;
	sub_821F9FB8(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r8,1072
	ctx.r4.s64 = ctx.r8.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x826A247C;
	sub_825EE0E0(ctx, base);
loc_826A247C:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_826A2484"))) PPC_WEAK_FUNC(sub_826A2484);
PPC_FUNC_IMPL(__imp__sub_826A2484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A2488"))) PPC_WEAK_FUNC(sub_826A2488);
PPC_FUNC_IMPL(__imp__sub_826A2488) {
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
	ctx.lr = 0x826A2490;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// addis r31,r28,1
	r31.s64 = r28.s64 + 65536;
	// addi r31,r31,-7840
	r31.s64 = r31.s64 + -7840;
	// lwz r3,-8256(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8256);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8236da50
	ctx.lr = 0x826A24B0;
	sub_8236DA50(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ori r29,r11,57692
	r29.u64 = r11.u64 | 57692;
	// ble cr6,0x826a24fc
	if (!cr6.gt) goto loc_826A24FC;
	// lwz r3,-8256(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8256);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r5,r28,r29
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// bl 0x8236daa0
	ctx.lr = 0x826A24D0;
	sub_8236DAA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826a24fc
	if (cr6.eq) goto loc_826A24FC;
	// lwz r3,-8256(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8256);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8236efd8
	ctx.lr = 0x826A24E8;
	sub_8236EFD8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826a1838
	ctx.lr = 0x826A24F0;
	sub_826A1838(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826A24FC:
	// lwz r3,-8256(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8256);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r5,r28,r29
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// bl 0x8236f098
	ctx.lr = 0x826A250C;
	sub_8236F098(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826a1838
	ctx.lr = 0x826A2514;
	sub_826A1838(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826A2520"))) PPC_WEAK_FUNC(sub_826A2520);
PPC_FUNC_IMPL(__imp__sub_826A2520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x826A2528;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d8
	ctx.lr = 0x826A2530;
	// stwu r1,-992(r1)
	ea = -992 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A2548;
	sub_822A3998(ctx, base);
	// addis r29,r18,1
	r29.s64 = r18.s64 + 65536;
	// lwz r30,48(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r29,r29,-26188
	r29.s64 = r29.s64 + -26188;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// lwz r11,132(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r25,r11,64
	r25.s64 = r11.s64 + 64;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x826a2610
	if (!cr6.eq) goto loc_826A2610;
	// li r31,0
	r31.s64 = 0;
loc_826A2574:
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8269d660
	ctx.lr = 0x826A2584;
	sub_8269D660(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,5
	cr6.compare<int32_t>(r31.s32, 5, xer);
	// blt cr6,0x826a2574
	if (cr6.lt) goto loc_826A2574;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x826a25a4
	if (!cr6.eq) goto loc_826A25A4;
	// li r11,0
	r11.s64 = 0;
loc_826A25A4:
	// lwz r3,80(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lwz r31,1016(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 1016);
	// bl 0x82360f90
	ctx.lr = 0x826A25B0;
	sub_82360F90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,20(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r3,-8256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8256);
	// bl 0x8236d850
	ctx.lr = 0x826A25CC;
	sub_8236D850(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r3,r9,-26468
	ctx.r3.s64 = ctx.r9.s64 + -26468;
	// bl 0x821fa230
	ctx.lr = 0x826A25D8;
	sub_821FA230(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// addi r3,r7,-26492
	ctx.r3.s64 = ctx.r7.s64 + -26492;
	// lwz r6,16(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// ori r5,r6,16
	ctx.r5.u64 = ctx.r6.u64 | 16;
	// stw r5,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r5.u32);
	// bl 0x821fa230
	ctx.lr = 0x826A25F4;
	sub_821FA230(ctx, base);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r11,r4,16
	r11.u64 = ctx.r4.u64 | 16;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// addi r1,r1,992
	ctx.r1.s64 = ctx.r1.s64 + 992;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba24
	ctx.lr = 0x826A260C;
	// b 0x823d9210
	return;
loc_826A2610:
	// lis r11,0
	r11.s64 = 0;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// ori r9,r11,39352
	ctx.r9.u64 = r11.u64 | 39352;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-26504
	ctx.r4.s64 = ctx.r10.s64 + -26504;
	// lwzx r3,r18,r9
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + ctx.r9.u32);
	// bl 0x8268da78
	ctx.lr = 0x826A262C;
	sub_8268DA78(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x826a2668
	if (cr6.lt) goto loc_826A2668;
	// mulli r11,r11,5764
	r11.s64 = r11.s64 * 5764;
	// add r11,r11,r18
	r11.u64 = r11.u64 + r18.u64;
	// addi r3,r11,21856
	ctx.r3.s64 = r11.s64 + 21856;
	// bl 0x8269ca20
	ctx.lr = 0x826A2648;
	sub_8269CA20(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// ori r9,r11,57712
	ctx.r9.u64 = r11.u64 | 57712;
	// stwx r10,r18,r9
	PPC_STORE_U32(r18.u32 + ctx.r9.u32, ctx.r10.u32);
	// addi r1,r1,992
	ctx.r1.s64 = ctx.r1.s64 + 992;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba24
	ctx.lr = 0x826A2664;
	// b 0x823d9210
	return;
loc_826A2668:
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r30,-32244
	r30.s64 = -2113142784;
	// addi r26,r11,4272
	r26.s64 = r11.s64 + 4272;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f31,15360(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 15360);
	f31.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r26,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r26.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r31,-32244
	r31.s64 = -2113142784;
	// addi r30,r30,-26512
	r30.s64 = r30.s64 + -26512;
	// li r27,0
	r27.s64 = 0;
	// lis r23,-32255
	r23.s64 = -2113863680;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// addi r19,r11,-30140
	r19.s64 = r11.s64 + -30140;
	// addi r24,r10,-29924
	r24.s64 = ctx.r10.s64 + -29924;
	// addi r22,r9,-27624
	r22.s64 = ctx.r9.s64 + -27624;
	// addi r21,r8,10372
	r21.s64 = ctx.r8.s64 + 10372;
	// addi r20,r7,-27620
	r20.s64 = ctx.r7.s64 + -27620;
	// addi r28,r6,30576
	r28.s64 = ctx.r6.s64 + 30576;
	// addi r17,r5,-26520
	r17.s64 = ctx.r5.s64 + -26520;
	// addi r16,r4,-26528
	r16.s64 = ctx.r4.s64 + -26528;
	// addi r15,r3,-26536
	r15.s64 = ctx.r3.s64 + -26536;
	// addi r14,r31,-26544
	r14.s64 = r31.s64 + -26544;
	// b 0x826a26e8
	goto loc_826A26E8;
loc_826A26E4:
	// lwz r29,104(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_826A26E8:
	// addi r11,r27,-1
	r11.s64 = r27.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x826a2740
	if (cr6.gt) goto loc_826A2740;
	// addi r11,r27,-1
	r11.s64 = r27.s64 + -1;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,10000
	r12.s64 = r12.s64 + 10000;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826A2720;
	case 1:
		goto loc_826A2728;
	case 2:
		goto loc_826A2730;
	case 3:
		goto loc_826A2738;
	default:
		__builtin_unreachable();
	}
	// lwz r19,10016(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10016);
	// lwz r19,10024(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10024);
	// lwz r19,10032(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10032);
	// lwz r19,10040(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10040);
loc_826A2720:
	// lwz r5,112(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// b 0x826a2744
	goto loc_826A2744;
loc_826A2728:
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// b 0x826a2744
	goto loc_826A2744;
loc_826A2730:
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// b 0x826a2744
	goto loc_826A2744;
loc_826A2738:
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// b 0x826a2744
	goto loc_826A2744;
loc_826A2740:
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
loc_826A2744:
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82137a08
	ctx.lr = 0x826A2750;
	sub_82137A08(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x826A275C;
	sub_821CA540(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mulli r11,r11,168
	r11.s64 = r11.s64 * 168;
	// add r11,r11,r18
	r11.u64 = r11.u64 + r18.u64;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// addi r6,r11,28
	ctx.r6.s64 = r11.s64 + 28;
	// bl 0x82137a08
	ctx.lr = 0x826A2780;
	sub_82137A08(ctx, base);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,768
	ctx.r4.s64 = ctx.r1.s64 + 768;
	// bl 0x821ca6a8
	ctx.lr = 0x826A2798;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826a27b0
	if (!cr6.eq) goto loc_826A27B0;
	// bl 0x821c9a90
	ctx.lr = 0x826A27AC;
	sub_821C9A90(ctx, base);
	// b 0x826a2a1c
	goto loc_826A2A1C;
loc_826A27B0:
	// bl 0x821c9a90
	ctx.lr = 0x826A27B4;
	sub_821C9A90(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r24,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r24.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r30,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, r30.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwz r4,4416(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 4416);
	// bl 0x821cf7b8
	ctx.lr = 0x826A27D0;
	sub_821CF7B8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82392538
	ctx.lr = 0x826A27DC;
	sub_82392538(ctx, base);
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826A27EC;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0490
	ctx.lr = 0x826A27F8;
	sub_821D0490(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826a2a08
	if (!cr6.gt) goto loc_826A2A08;
loc_826A2804:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82393118
	ctx.lr = 0x826A2814;
	sub_82393118(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826A2828;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0490
	ctx.lr = 0x826A2834;
	sub_821D0490(ctx, base);
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826A2844;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0490
	ctx.lr = 0x826A2850;
	sub_821D0490(ctx, base);
	// sth r3,16(r31)
	PPC_STORE_U16(r31.u32 + 16, ctx.r3.u16);
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826A2864;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0490
	ctx.lr = 0x826A2870;
	sub_821D0490(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stb r8,19(r31)
	PPC_STORE_U8(r31.u32 + 19, ctx.r8.u8);
	// bl 0x821cfaa8
	ctx.lr = 0x826A2890;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0528
	ctx.lr = 0x826A289C;
	sub_821D0528(ctx, base);
	// addi r3,r31,14
	ctx.r3.s64 = r31.s64 + 14;
	// bl 0x8213e850
	ctx.lr = 0x826A28A4;
	sub_8213E850(ctx, base);
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826A28B4;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0528
	ctx.lr = 0x826A28C0;
	sub_821D0528(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213e850
	ctx.lr = 0x826A28C8;
	sub_8213E850(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0528
	ctx.lr = 0x826A28D4;
	sub_821D0528(ctx, base);
	// addi r3,r31,2
	ctx.r3.s64 = r31.s64 + 2;
	// bl 0x8213e850
	ctx.lr = 0x826A28DC;
	sub_8213E850(ctx, base);
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826A28EC;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0528
	ctx.lr = 0x826A28F8;
	sub_821D0528(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x8213e850
	ctx.lr = 0x826A2900;
	sub_8213E850(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0528
	ctx.lr = 0x826A290C;
	sub_821D0528(ctx, base);
	// addi r3,r31,6
	ctx.r3.s64 = r31.s64 + 6;
	// bl 0x8213e850
	ctx.lr = 0x826A2914;
	sub_8213E850(ctx, base);
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826A2924;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0528
	ctx.lr = 0x826A2930;
	sub_821D0528(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// bl 0x821d0528
	ctx.lr = 0x826A2940;
	sub_821D0528(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// bl 0x821d0528
	ctx.lr = 0x826A2950;
	sub_821D0528(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0528
	ctx.lr = 0x826A2960;
	sub_821D0528(ctx, base);
	// fmuls f0,f29,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 * f31.f64));
	// fmuls f13,f28,f31
	ctx.f13.f64 = double(float(f28.f64 * f31.f64));
	// li r5,80
	ctx.r5.s64 = 80;
	// fmuls f12,f1,f31
	ctx.f12.f64 = double(float(ctx.f1.f64 * f31.f64));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// fmuls f11,f30,f31
	ctx.f11.f64 = double(float(f30.f64 * f31.f64));
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// fctiwz f10,f0
	ctx.f10.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f9,f13
	ctx.f9.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f8,f12
	ctx.f8.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// fctiwz f7,f11
	ctx.f7.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f7,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.f7.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwimi r7,r9,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r6,r7,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
	// bl 0x821cfaa8
	ctx.lr = 0x826A29C4;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0490
	ctx.lr = 0x826A29D0;
	sub_821D0490(ctx, base);
	// stb r3,18(r31)
	PPC_STORE_U8(r31.u32 + 18, ctx.r3.u8);
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826A29E4;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0528
	ctx.lr = 0x826A29F0;
	sub_821D0528(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x8213e850
	ctx.lr = 0x826A29F8;
	sub_8213E850(ctx, base);
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r7
	cr6.compare<int32_t>(r30.s32, ctx.r7.s32, xer);
	// blt cr6,0x826a2804
	if (cr6.lt) goto loc_826A2804;
loc_826A2A08:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82392548
	ctx.lr = 0x826A2A10;
	sub_82392548(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x826A2A18;
	sub_821BE610(ctx, base);
	// stw r19,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r19.u32);
loc_826A2A1C:
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r10,r11,20
	ctx.r10.s64 = r11.s64 + 20;
	// cmpw cr6,r26,r10
	cr6.compare<int32_t>(r26.s32, ctx.r10.s32, xer);
	// blt cr6,0x826a26e4
	if (cr6.lt) goto loc_826A26E4;
	// lwz r31,100(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x826a2a4c
	if (!cr6.eq) goto loc_826A2A4C;
	// li r11,0
	r11.s64 = 0;
loc_826A2A4C:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r30,1016(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 1016);
	// bl 0x82360f90
	ctx.lr = 0x826A2A58;
	sub_82360F90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,20(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r3,-8256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8256);
	// bl 0x8236d850
	ctx.lr = 0x826A2A74;
	sub_8236D850(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r8,2
	ctx.r8.s64 = 2;
	// ori r7,r9,57712
	ctx.r7.u64 = ctx.r9.u64 | 57712;
	// stwx r8,r18,r7
	PPC_STORE_U32(r18.u32 + ctx.r7.u32, ctx.r8.u32);
	// addi r1,r1,992
	ctx.r1.s64 = ctx.r1.s64 + 992;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba24
	ctx.lr = 0x826A2A90;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_826A2A94"))) PPC_WEAK_FUNC(sub_826A2A94);
PPC_FUNC_IMPL(__imp__sub_826A2A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A2A98"))) PPC_WEAK_FUNC(sub_826A2A98);
PPC_FUNC_IMPL(__imp__sub_826A2A98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// bl 0x823d91f0
	ctx.lr = 0x826A2AA0;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A2AC0;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addis r31,r29,1
	r31.s64 = r29.s64 + 65536;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// addi r31,r31,-7840
	r31.s64 = r31.s64 + -7840;
	// li r26,0
	r26.s64 = 0;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// lwz r3,-8256(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8256);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r27,r11,64
	r27.s64 = r11.s64 + 64;
	// bl 0x8236da50
	ctx.lr = 0x826A2AE8;
	sub_8236DA50(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ori r28,r9,57692
	r28.u64 = ctx.r9.u64 | 57692;
	// ble cr6,0x826a2b18
	if (!cr6.gt) goto loc_826A2B18;
	// lwz r3,-8256(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8256);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r5,r29,r28
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x8236daa0
	ctx.lr = 0x826A2B08;
	sub_8236DAA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826a2b18
	if (cr6.eq) goto loc_826A2B18;
	// li r26,1
	r26.s64 = 1;
loc_826A2B18:
	// clrlwi r26,r26,24
	r26.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x826a2b3c
	if (!cr6.eq) goto loc_826A2B3C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r5,r29,r28
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x82393118
	ctx.lr = 0x826A2B34;
	sub_82393118(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x826a2b54
	goto loc_826A2B54;
loc_826A2B3C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r31,r11,2144
	r31.s64 = r11.s64 + 2144;
loc_826A2B54:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-21664
	ctx.r4.s64 = ctx.r10.s64 + -21664;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A2B68;
	sub_821F9FB8(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// ori r8,r9,57708
	ctx.r8.u64 = ctx.r9.u64 | 57708;
	// lwzx r11,r29,r8
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x826a2f54
	if (cr6.gt) goto loc_826A2F54;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,11160
	r12.s64 = r12.s64 + 11160;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826A2BB8;
	case 1:
		goto loc_826A2BCC;
	case 2:
		goto loc_826A2CB0;
	case 3:
		goto loc_826A2E08;
	case 4:
		goto loc_826A2F54;
	case 5:
		goto loc_826A2F54;
	case 6:
		goto loc_826A2E98;
	case 7:
		goto loc_826A2F18;
	default:
		__builtin_unreachable();
	}
	// lwz r19,11192(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11192);
	// lwz r19,11212(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11212);
	// lwz r19,11440(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// lwz r19,11784(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11784);
	// lwz r19,12116(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12116);
	// lwz r19,12116(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12116);
	// lwz r19,11928(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11928);
	// lwz r19,12056(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12056);
loc_826A2BB8:
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-26428
	ctx.r4.s64 = ctx.r10.s64 + -26428;
	// extsh r5,r11
	ctx.r5.s64 = r11.s16;
	// b 0x826a2f4c
	goto loc_826A2F4C;
loc_826A2BCC:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f30,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// bne cr6,0x826a2be8
	if (!cr6.eq) goto loc_826A2BE8;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x826a2c10
	goto loc_826A2C10;
loc_826A2BE8:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_826A2C10:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// li r29,4
	r29.s64 = 4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r30,r11,-26448
	r30.s64 = r11.s64 + -26448;
	// lfs f31,11364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	f31.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmuls f0,f0,f31
	f0.f64 = double(float(f0.f64 * f31.f64));
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82203058
	ctx.lr = 0x826A2C44;
	sub_82203058(ctx, base);
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826a2c58
	if (!cr6.eq) goto loc_826A2C58;
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x826a2c80
	goto loc_826A2C80;
loc_826A2C58:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_826A2C80:
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// fmuls f0,f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f31.f64));
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82203058
	ctx.lr = 0x826A2CA0;
	sub_82203058(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_826A2CB0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// bne cr6,0x826a2ccc
	if (!cr6.eq) goto loc_826A2CCC;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x826a2cf4
	goto loc_826A2CF4;
loc_826A2CCC:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_826A2CF4:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// li r29,4
	r29.s64 = 4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r29.u32);
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// addi r30,r11,-26448
	r30.s64 = r11.s64 + -26448;
	// lfs f30,31016(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	f30.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmuls f0,f0,f30
	f0.f64 = double(float(f0.f64 * f30.f64));
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82203058
	ctx.lr = 0x826A2D28;
	sub_82203058(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x826a2d9c
	if (cr6.eq) goto loc_826A2D9C;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826a2d44
	if (!cr6.eq) goto loc_826A2D44;
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// b 0x826a2d6c
	goto loc_826A2D6C;
loc_826A2D44:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_826A2D6C:
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// fmuls f0,f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f30.f64));
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stw r29,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r29.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r6,r1,136
	ctx.r6.s64 = ctx.r1.s64 + 136;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82203058
	ctx.lr = 0x826A2D8C;
	sub_82203058(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_826A2D9C:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826a2db0
	if (!cr6.eq) goto loc_826A2DB0;
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// b 0x826a2dd8
	goto loc_826A2DD8;
loc_826A2DB0:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_826A2DD8:
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// fmuls f0,f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f30.f64));
	// stfs f0,152(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r6,r1,152
	ctx.r6.s64 = ctx.r1.s64 + 152;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82203058
	ctx.lr = 0x826A2DF8;
	sub_82203058(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_826A2E08:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826a2e20
	if (!cr6.eq) goto loc_826A2E20;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// b 0x826a2e48
	goto loc_826A2E48;
loc_826A2E20:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_826A2E48:
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// li r5,359
	ctx.r5.s64 = 359;
	// li r4,0
	ctx.r4.s64 = 0;
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r31,56(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82250268
	ctx.lr = 0x826A2E64;
	sub_82250268(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// stw r3,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r3.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r11.u32);
	// addi r6,r1,168
	ctx.r6.s64 = ctx.r1.s64 + 168;
	// addi r4,r10,-26448
	ctx.r4.s64 = ctx.r10.s64 + -26448;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203058
	ctx.lr = 0x826A2E88;
	sub_82203058(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_826A2E98:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826a2eb0
	if (!cr6.eq) goto loc_826A2EB0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// b 0x826a2ed8
	goto loc_826A2ED8;
loc_826A2EB0:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_826A2ED8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// li r10,4
	ctx.r10.s64 = 4;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r10,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r10.u32);
	// addi r6,r1,184
	ctx.r6.s64 = ctx.r1.s64 + 184;
	// addi r4,r9,-26448
	ctx.r4.s64 = ctx.r9.s64 + -26448;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,184(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x826A2F08;
	sub_82203058(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_826A2F18:
	// lbz r11,18(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r10,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r10.u32);
	// addi r6,r1,200
	ctx.r6.s64 = ctx.r1.s64 + 200;
	// addi r4,r9,-26448
	ctx.r4.s64 = ctx.r9.s64 + -26448;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r11.u32);
	// bl 0x82203058
	ctx.lr = 0x826A2F40;
	sub_82203058(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,1072
	ctx.r4.s64 = ctx.r8.s64 + 1072;
loc_826A2F4C:
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x826A2F54;
	sub_825EE0E0(ctx, base);
loc_826A2F54:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826A2F64"))) PPC_WEAK_FUNC(sub_826A2F64);
PPC_FUNC_IMPL(__imp__sub_826A2F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A2F68"))) PPC_WEAK_FUNC(sub_826A2F68);
PPC_FUNC_IMPL(__imp__sub_826A2F68) {
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
	ctx.lr = 0x826A2F70;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addis r26,r31,1
	r26.s64 = r31.s64 + 65536;
	// addi r26,r26,-7840
	r26.s64 = r26.s64 + -7840;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x826a30c4
	if (cr6.lt) goto loc_826A30C4;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bge cr6,0x826a30c4
	if (!cr6.lt) goto loc_826A30C4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A2FA4;
	sub_822A3998(ctx, base);
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r30,0
	r30.s64 = 0;
	// addi r29,r29,-7764
	r29.s64 = r29.s64 + -7764;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r3,r9,-26864
	ctx.r3.s64 = ctx.r9.s64 + -26864;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// addi r27,r11,64
	r27.s64 = r11.s64 + 64;
	// bl 0x821fa230
	ctx.lr = 0x826A2FCC;
	sub_821FA230(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x823931c0
	ctx.lr = 0x826A2FDC;
	sub_823931C0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x826a306c
	if (!cr6.gt) goto loc_826A306C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r24,1
	r24.s64 = 1;
	// addi r22,r11,-28272
	r22.s64 = r11.s64 + -28272;
loc_826A2FF4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x826A3000;
	sub_8268DCB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826a3060
	if (cr6.eq) goto loc_826A3060;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82393118
	ctx.lr = 0x826A301C;
	sub_82393118(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// cmplwi cr6,r11,32768
	cr6.compare<uint32_t>(r11.u32, 32768, xer);
	// bge cr6,0x826a306c
	if (!cr6.lt) goto loc_826A306C;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8268da78
	ctx.lr = 0x826A303C;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a3060
	if (cr6.eq) goto loc_826A3060;
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// stw r24,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r24.u32);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
loc_826A3060:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r25
	cr6.compare<int32_t>(r30.s32, r25.s32, xer);
	// blt cr6,0x826a2ff4
	if (cr6.lt) goto loc_826A2FF4;
loc_826A306C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-21664
	ctx.r4.s64 = ctx.r10.s64 + -21664;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826A3080;
	sub_821F9FB8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r31,r9,2612
	r31.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,56(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x826A309C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x826A30AC;
	sub_825ED480(ctx, base);
	// li r7,10
	ctx.r7.s64 = 10;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-10964
	ctx.r4.s64 = ctx.r6.s64 + -10964;
	// bl 0x82722678
	ctx.lr = 0x826A30C4;
	sub_82722678(ctx, base);
loc_826A30C4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_826A30CC"))) PPC_WEAK_FUNC(sub_826A30CC);
PPC_FUNC_IMPL(__imp__sub_826A30CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A30D0"))) PPC_WEAK_FUNC(sub_826A30D0);
PPC_FUNC_IMPL(__imp__sub_826A30D0) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826A30D8;
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f29.u64);
	// stfd f30,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r3,r9,-26412
	ctx.r3.s64 = ctx.r9.s64 + -26412;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// addi r8,r11,45
	ctx.r8.s64 = r11.s64 + 45;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lwz r5,688(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 688);
	// lfs f0,648(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 648);
	f0.f64 = double(temp.f32);
	// lwz r4,692(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 692);
	// lfs f13,652(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 652);
	ctx.f13.f64 = double(temp.f32);
	// extsw r11,r5
	r11.s64 = ctx.r5.s32;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f4,f6,f13
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fctiwz f5,f7
	ctx.f5.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fctiwz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x826A3170;
	sub_82130000(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// bl 0x82178848
	ctx.lr = 0x826A3178;
	sub_82178848(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826a3188
	if (!cr6.eq) goto loc_826A3188;
	// li r29,1
	r29.s64 = 1;
loc_826A3188:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// extsw r10,r31
	ctx.r10.s64 = r31.s32;
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
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r10,r9,-29312
	ctx.r10.s64 = ctx.r9.s64 + -29312;
	// frsp f29,f11
	f29.f64 = double(float(ctx.f11.f64));
	// rlwinm r30,r29,4,0,27
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfsx f10,r30,r10
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfsx f9,r30,r8
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	ctx.f9.f64 = double(temp.f32);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmuls f7,f9,f29
	ctx.f7.f64 = double(float(ctx.f9.f64 * f29.f64));
	// stfs f7,100(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// frsp f30,f12
	f30.f64 = double(float(ctx.f12.f64));
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r11,4416
	ctx.r3.s64 = r11.s64 + 4416;
	// fmuls f8,f10,f30
	ctx.f8.f64 = double(float(ctx.f10.f64 * f30.f64));
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r6,4416(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4416);
	// lwz r5,604(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 604);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826A3204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,4640
	ctx.r3.s64 = r11.s64 + 4640;
	// lwz r11,4640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4640);
	// lwz r10,604(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 604);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826A3220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r11,r9,-29200
	r11.s64 = ctx.r9.s64 + -29200;
	// li r7,4496
	ctx.r7.s64 = 4496;
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// li r5,4720
	ctx.r5.s64 = 4720;
	// lfsx f6,r30,r11
	temp.u32 = PPC_LOAD_U32(r30.u32 + r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f4,f6,f30
	ctx.f4.f64 = double(float(ctx.f6.f64 * f30.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfsx f5,r30,r6
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r6.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f3,f5,f29
	ctx.f3.f64 = double(float(ctx.f5.f64 * f29.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// stvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// stvx128 v63,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-56(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826A327C"))) PPC_WEAK_FUNC(sub_826A327C);
PPC_FUNC_IMPL(__imp__sub_826A327C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A3280"))) PPC_WEAK_FUNC(sub_826A3280);
PPC_FUNC_IMPL(__imp__sub_826A3280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r9,r10,57664
	ctx.r9.u64 = ctx.r10.u64 | 57664;
	// addi r11,r5,-2
	r11.s64 = ctx.r5.s64 + -2;
	// cmplwi cr6,r11,19
	cr6.compare<uint32_t>(r11.u32, 19, xer);
	// stwx r4,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r4.u32);
	// bgt cr6,0x826a33cc
	if (cr6.gt) goto loc_826A33CC;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,12996
	r12.s64 = r12.s64 + 12996;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826A332C;
	case 1:
		goto loc_826A3338;
	case 2:
		goto loc_826A3344;
	case 3:
		goto loc_826A33CC;
	case 4:
		goto loc_826A33CC;
	case 5:
		goto loc_826A3350;
	case 6:
		goto loc_826A335C;
	case 7:
		goto loc_826A3368;
	case 8:
		goto loc_826A3374;
	case 9:
		goto loc_826A3380;
	case 10:
		goto loc_826A338C;
	case 11:
		goto loc_826A3398;
	case 12:
		goto loc_826A33A4;
	case 13:
		goto loc_826A33CC;
	case 14:
		goto loc_826A33CC;
	case 15:
		goto loc_826A33CC;
	case 16:
		goto loc_826A33CC;
	case 17:
		goto loc_826A33CC;
	case 18:
		goto loc_826A3314;
	case 19:
		goto loc_826A3320;
	default:
		__builtin_unreachable();
	}
	// lwz r19,13100(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13100);
	// lwz r19,13112(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13112);
	// lwz r19,13124(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13124);
	// lwz r19,13260(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13260);
	// lwz r19,13260(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13260);
	// lwz r19,13136(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13136);
	// lwz r19,13148(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13148);
	// lwz r19,13160(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13160);
	// lwz r19,13172(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13172);
	// lwz r19,13184(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13184);
	// lwz r19,13196(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13196);
	// lwz r19,13208(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13208);
	// lwz r19,13220(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13220);
	// lwz r19,13260(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13260);
	// lwz r19,13260(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13260);
	// lwz r19,13260(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13260);
	// lwz r19,13260(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13260);
	// lwz r19,13260(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13260);
	// lwz r19,13076(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13076);
	// lwz r19,13088(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13088);
loc_826A3314:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26200
	ctx.r3.s64 = r11.s64 + -26200;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A3320:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26216
	ctx.r3.s64 = r11.s64 + -26216;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A332C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26228
	ctx.r3.s64 = r11.s64 + -26228;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A3338:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26240
	ctx.r3.s64 = r11.s64 + -26240;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A3344:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26252
	ctx.r3.s64 = r11.s64 + -26252;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A3350:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26264
	ctx.r3.s64 = r11.s64 + -26264;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A335C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26280
	ctx.r3.s64 = r11.s64 + -26280;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A3368:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26296
	ctx.r3.s64 = r11.s64 + -26296;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A3374:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26312
	ctx.r3.s64 = r11.s64 + -26312;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A3380:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26328
	ctx.r3.s64 = r11.s64 + -26328;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A338C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26344
	ctx.r3.s64 = r11.s64 + -26344;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A3398:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26360
	ctx.r3.s64 = r11.s64 + -26360;
	// b 0x826a33ac
	goto loc_826A33AC;
loc_826A33A4:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-26372
	ctx.r3.s64 = r11.s64 + -26372;
loc_826A33AC:
	// bl 0x821fa230
	ctx.lr = 0x826A33B0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,336(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 336);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826A33C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r7,r8,57668
	ctx.r7.u64 = ctx.r8.u64 | 57668;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
loc_826A33CC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826A33E0"))) PPC_WEAK_FUNC(sub_826A33E0);
PPC_FUNC_IMPL(__imp__sub_826A33E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// bl 0x823d91f8
	ctx.lr = 0x826A33E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A3400;
	sub_822A3998(ctx, base);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r10,r31,-2
	ctx.r10.s64 = r31.s64 + -2;
	// li r31,0
	r31.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r10,19
	cr6.compare<uint32_t>(ctx.r10.u32, 19, xer);
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bgt cr6,0x826a36d0
	if (cr6.gt) goto loc_826A36D0;
	// lis r12,-32150
	r12.s64 = -2106982400;
	// addi r12,r12,13368
	r12.s64 = r12.s64 + 13368;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_826A34E0;
	case 1:
		goto loc_826A350C;
	case 2:
		goto loc_826A3538;
	case 3:
		goto loc_826A36D0;
	case 4:
		goto loc_826A36D0;
	case 5:
		goto loc_826A3564;
	case 6:
		goto loc_826A3590;
	case 7:
		goto loc_826A35BC;
	case 8:
		goto loc_826A35E8;
	case 9:
		goto loc_826A3614;
	case 10:
		goto loc_826A3640;
	case 11:
		goto loc_826A366C;
	case 12:
		goto loc_826A3698;
	case 13:
		goto loc_826A36D0;
	case 14:
		goto loc_826A36D0;
	case 15:
		goto loc_826A36D0;
	case 16:
		goto loc_826A36D0;
	case 17:
		goto loc_826A36D0;
	case 18:
		goto loc_826A3488;
	case 19:
		goto loc_826A34B4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,13536(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13536);
	// lwz r19,13580(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13580);
	// lwz r19,13624(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13624);
	// lwz r19,14032(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14032);
	// lwz r19,14032(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14032);
	// lwz r19,13668(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13668);
	// lwz r19,13712(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13712);
	// lwz r19,13756(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13756);
	// lwz r19,13800(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13800);
	// lwz r19,13844(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13844);
	// lwz r19,13888(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13888);
	// lwz r19,13932(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13932);
	// lwz r19,13976(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13976);
	// lwz r19,14032(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14032);
	// lwz r19,14032(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14032);
	// lwz r19,14032(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14032);
	// lwz r19,14032(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14032);
	// lwz r19,14032(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14032);
	// lwz r19,13448(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13448);
	// lwz r19,13492(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13492);
loc_826A3488:
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-25988
	ctx.r3.s64 = ctx.r8.s64 + -25988;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A34A4;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26200
	ctx.r3.s64 = ctx.r7.s64 + -26200;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A34B4:
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26004
	ctx.r3.s64 = ctx.r8.s64 + -26004;
	// lvx128 v62,r11,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A34D0;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26216
	ctx.r3.s64 = ctx.r7.s64 + -26216;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A34E0:
	// li r10,80
	ctx.r10.s64 = 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26016
	ctx.r3.s64 = ctx.r8.s64 + -26016;
	// lvx128 v61,r11,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A34FC;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26228
	ctx.r3.s64 = ctx.r7.s64 + -26228;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A350C:
	// li r10,96
	ctx.r10.s64 = 96;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26028
	ctx.r3.s64 = ctx.r8.s64 + -26028;
	// lvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A3528;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26240
	ctx.r3.s64 = ctx.r7.s64 + -26240;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A3538:
	// li r10,112
	ctx.r10.s64 = 112;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26040
	ctx.r3.s64 = ctx.r8.s64 + -26040;
	// lvx128 v59,r11,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A3554;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26252
	ctx.r3.s64 = ctx.r7.s64 + -26252;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A3564:
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26056
	ctx.r3.s64 = ctx.r8.s64 + -26056;
	// lvx128 v58,r11,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A3580;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26264
	ctx.r3.s64 = ctx.r7.s64 + -26264;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A3590:
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26072
	ctx.r3.s64 = ctx.r8.s64 + -26072;
	// lvx128 v57,r11,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A35AC;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26280
	ctx.r3.s64 = ctx.r7.s64 + -26280;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A35BC:
	// li r10,1408
	ctx.r10.s64 = 1408;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26092
	ctx.r3.s64 = ctx.r8.s64 + -26092;
	// lvx128 v56,r11,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A35D8;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26296
	ctx.r3.s64 = ctx.r7.s64 + -26296;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A35E8:
	// li r10,1424
	ctx.r10.s64 = 1424;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26112
	ctx.r3.s64 = ctx.r8.s64 + -26112;
	// lvx128 v55,r11,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A3604;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26312
	ctx.r3.s64 = ctx.r7.s64 + -26312;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A3614:
	// li r10,1440
	ctx.r10.s64 = 1440;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26132
	ctx.r3.s64 = ctx.r8.s64 + -26132;
	// lvx128 v54,r11,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A3630;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26328
	ctx.r3.s64 = ctx.r7.s64 + -26328;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A3640:
	// li r10,1456
	ctx.r10.s64 = 1456;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26152
	ctx.r3.s64 = ctx.r8.s64 + -26152;
	// lvx128 v53,r11,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A365C;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26344
	ctx.r3.s64 = ctx.r7.s64 + -26344;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A366C:
	// li r10,1472
	ctx.r10.s64 = 1472;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r3,r8,-26172
	ctx.r3.s64 = ctx.r8.s64 + -26172;
	// lvx128 v52,r11,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821fa230
	ctx.lr = 0x826A3688;
	sub_821FA230(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r7,-26360
	ctx.r3.s64 = ctx.r7.s64 + -26360;
	// b 0x826a36c8
	goto loc_826A36C8;
loc_826A3698:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lfs f0,288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 288);
	f0.f64 = double(temp.f32);
	// lfs f13,292(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r10,-26184
	ctx.r3.s64 = ctx.r10.s64 + -26184;
	// lfs f12,296(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 296);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x821fa230
	ctx.lr = 0x826A36BC;
	sub_821FA230(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r9,-26372
	ctx.r3.s64 = ctx.r9.s64 + -26372;
loc_826A36C8:
	// bl 0x821fa230
	ctx.lr = 0x826A36CC;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_826A36D0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-1
	ctx.r9.s64 = -65536;
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r11,-28660
	r29.s64 = r11.s64 + -28660;
	// lfs f0,15360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15360);
	f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f7,f10
	ctx.f7.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f6,f9
	ctx.f6.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f5,f8
	ctx.f5.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwimi r9,r6,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// or r11,r9,r8
	r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r31,r10,r7
	r31.u64 = ctx.r10.u64 | ctx.r7.u64;
	// bl 0x8268da78
	ctx.lr = 0x826A3740;
	sub_8268DA78(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a3754
	if (cr6.eq) goto loc_826A3754;
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
loc_826A3754:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268da78
	ctx.lr = 0x826A3764;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a3774
	if (cr6.eq) goto loc_826A3774;
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
loc_826A3774:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826A377C"))) PPC_WEAK_FUNC(sub_826A377C);
PPC_FUNC_IMPL(__imp__sub_826A377C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826A3780"))) PPC_WEAK_FUNC(sub_826A3780);
PPC_FUNC_IMPL(__imp__sub_826A3780) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826A3788;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826A37A4;
	sub_822A3998(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// addi r10,r11,64
	ctx.r10.s64 = r11.s64 + 64;
	// lis r11,0
	r11.s64 = 0;
	// ori r7,r11,39260
	ctx.r7.u64 = r11.u64 | 39260;
	// lwzx r11,r31,r7
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// bne cr6,0x826a37e8
	if (!cr6.eq) goto loc_826A37E8;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r8,1568
	ctx.r8.s64 = 1568;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v63,r4,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a3804
	goto loc_826A3804;
loc_826A37E8:
	// addi r11,r11,33
	r11.s64 = r11.s64 + 33;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r5,r6,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v62,r5,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826A3804:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lfs f0,15360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f7,f10
	ctx.f7.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f6,f9
	ctx.f6.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f5,f8
	ctx.f5.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwimi r10,r7,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r29,r5,r8
	r29.u64 = ctx.r5.u64 | ctx.r8.u64;
	// bne cr6,0x826a3870
	if (!cr6.eq) goto loc_826A3870;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-25928
	ctx.r3.s64 = r11.s64 + -25928;
	// b 0x826a3878
	goto loc_826A3878;
loc_826A3870:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-25940
	ctx.r3.s64 = r11.s64 + -25940;
loc_826A3878:
	// bl 0x821fa230
	ctx.lr = 0x826A387C;
	sub_821FA230(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-28660
	r31.s64 = r11.s64 + -28660;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x826A3890;
	sub_8268DA78(ctx, base);
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a38a4
	if (cr6.eq) goto loc_826A38A4;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
loc_826A38A4:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x826a38b8
	if (!cr6.eq) goto loc_826A38B8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-25956
	ctx.r3.s64 = r11.s64 + -25956;
	// b 0x826a38c0
	goto loc_826A38C0;
loc_826A38B8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-25972
	ctx.r3.s64 = r11.s64 + -25972;
loc_826A38C0:
	// bl 0x821fa230
	ctx.lr = 0x826A38C4;
	sub_821FA230(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268da78
	ctx.lr = 0x826A38D0;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826a38e0
	if (cr6.eq) goto loc_826A38E0;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
loc_826A38E0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826A38E8"))) PPC_WEAK_FUNC(sub_826A38E8);
PPC_FUNC_IMPL(__imp__sub_826A38E8) {
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
	// bne cr6,0x826a3910
	if (!cr6.eq) goto loc_826A3910;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-25928
	ctx.r3.s64 = r11.s64 + -25928;
	// b 0x826a3918
	goto loc_826A3918;
loc_826A3910:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-25940
	ctx.r3.s64 = r11.s64 + -25940;
loc_826A3918:
	// bl 0x821fa230
	ctx.lr = 0x826A391C;
	sub_821FA230(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28660
	ctx.r4.s64 = r11.s64 + -28660;
	// bl 0x8268da78
	ctx.lr = 0x826A392C;
	sub_8268DA78(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826a3944
	if (cr6.eq) goto loc_826A3944;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82699600
	ctx.lr = 0x826A3944;
	sub_82699600(ctx, base);
loc_826A3944:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

