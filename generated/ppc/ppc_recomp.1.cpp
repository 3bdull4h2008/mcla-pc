#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_821377DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821377DC) {
	__imp__sub_821377DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821377E0) {
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
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x821377FC;
	sub_821C90C0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82137810
	if (cr6.eq) goto loc_82137810;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_82137810:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82137818;
	sub_821C9108(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821377E0) {
	__imp__sub_821377E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213782C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213782C) {
	__imp__sub_8213782C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137830) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// li r3,-1
	ctx.r3.s64 = -1;
	// beqlr cr6
	if (cr6.eq) return;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
loc_8213784C:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r10,r5
	ctx.r7.u64 = ctx.r10.u64 + ctx.r5.u64;
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// ble cr6,0x82137874
	if (!cr6.gt) goto loc_82137874;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// b 0x8213787c
	goto loc_8213787C;
loc_82137874:
	// bge cr6,0x82137888
	if (!cr6.lt) goto loc_82137888;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_8213787C:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x8213784c
	if (!cr6.gt) goto loc_8213784C;
	// blr 
	return;
loc_82137888:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82137830) {
	__imp__sub_82137830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137890) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,66(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 66);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821378b0
	if (cr6.eq) goto loc_821378B0;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// addi r11,r10,19856
	r11.s64 = ctx.r10.s64 + 19856;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// b 0x821436c0
	sub_821436C0(ctx, base);
	return;
loc_821378B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82137890) {
	__imp__sub_82137890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821378B8) {
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
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82137910
	if (cr6.eq) goto loc_82137910;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_821378DC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821378dc
	if (!cr6.eq) goto loc_821378DC;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x82137904;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82137910;
	sub_823DA950(ctx, base);
loc_82137910:
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

PPC_WEAK_FUNC(sub_821378B8) {
	__imp__sub_821378B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137928) {
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
	ctx.lr = 0x82137930;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821379ec
	if (cr6.eq) goto loc_821379EC;
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r28,r11,3998
	r28.s64 = r11.s64 + 3998;
	// beq cr6,0x82137964
	if (cr6.eq) goto loc_82137964;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x82137968
	goto loc_82137968;
loc_82137964:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82137968:
	// bl 0x821c9550
	ctx.lr = 0x8213796C;
	sub_821C9550(ctx, base);
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
	// lwzx r30,r6,r10
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821379ec
	if (cr6.eq) goto loc_821379EC;
loc_82137994:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821379a8
	if (cr6.eq) goto loc_821379A8;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x821379ac
	goto loc_821379AC;
loc_821379A8:
	// mr r31,r28
	r31.u64 = r28.u64;
loc_821379AC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821372b8
	ctx.lr = 0x821379B4;
	sub_821372B8(ctx, base);
loc_821379B4:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x821379d8
	if (cr6.eq) goto loc_821379D8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821379b4
	if (cr6.eq) goto loc_821379B4;
loc_821379D8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821379f8
	if (cr6.eq) goto loc_821379F8;
	// lwz r30,12(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82137994
	if (!cr6.eq) goto loc_82137994;
loc_821379EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821379F8:
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82137928) {
	__imp__sub_82137928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82137A04) {
	__imp__sub_82137A04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137A08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,136
	ctx.r10.s64 = ctx.r1.s64 + 136;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821c9748
	ctx.lr = 0x82137A3C;
	sub_821C9748(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82137A08) {
	__imp__sub_82137A08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82137A4C) {
	__imp__sub_82137A4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137A50) {
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
	ctx.lr = 0x82137A58;
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
	// beq cr6,0x82137b40
	if (cr6.eq) goto loc_82137B40;
	// rlwinm r3,r22,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r28,r22,16
	r28.u64 = r22.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x82137A7C;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82137aa0
	if (cr6.eq) goto loc_82137AA0;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r28
	ctr.u64 = r28.u64;
loc_82137A94:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82137a94
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82137A94;
loc_82137AA0:
	// lhz r11,4(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82137b30
	if (cr6.eq) goto loc_82137B30;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r26,0
	r26.s64 = 0;
	// addi r23,r11,3998
	r23.s64 = r11.s64 + 3998;
loc_82137ABC:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwzx r31,r26,r11
	r31.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82137b1c
	if (cr6.eq) goto loc_82137B1C;
loc_82137ACC:
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
	// beq cr6,0x82137aec
	if (cr6.eq) goto loc_82137AEC;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x82137af0
	goto loc_82137AF0;
loc_82137AEC:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_82137AF0:
	// bl 0x821c9550
	ctx.lr = 0x82137AF4;
	sub_821C9550(ctx, base);
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
	// bne cr6,0x82137acc
	if (!cr6.eq) goto loc_82137ACC;
loc_82137B1C:
	// lhz r11,4(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// blt cr6,0x82137abc
	if (cr6.lt) goto loc_82137ABC;
loc_82137B30:
	// sth r22,4(r24)
	PPC_STORE_U16(r24.u32 + 4, r22.u16);
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82137B3C;
	sub_82130588(ctx, base);
	// stw r27,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r27.u32);
loc_82137B40:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82137A50) {
	__imp__sub_82137A50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137B48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r11,-1
	r11.s64 = -1;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,5836(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 5836);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82137bc8
	if (cr6.eq) goto loc_82137BC8;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
loc_82137B74:
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x82137bbc
	if (cr6.eq) goto loc_82137BBC;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5824(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 5824);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82137bbc
	if (cr6.eq) goto loc_82137BBC;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// ble cr6,0x82137bbc
	if (!cr6.gt) goto loc_82137BBC;
	// lwz r31,0(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bge cr6,0x82137bbc
	if (!cr6.lt) goto loc_82137BBC;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r8,5836(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 5836);
loc_82137BBC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x82137b74
	if (cr6.lt) goto loc_82137B74;
loc_82137BC8:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82137B48) {
	__imp__sub_82137B48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137BD0) {
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
	ctx.lr = 0x82137BD8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82137f5c
	if (!cr6.eq) goto loc_82137F5C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lhz r9,66(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// clrlwi r22,r4,24
	r22.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// lwz r11,5840(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5840);
	// sth r9,66(r11)
	PPC_STORE_U16(r11.u32 + 66, ctx.r9.u16);
	// lwz r11,5840(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5840);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r8.u32);
	// bne cr6,0x82137c18
	if (!cr6.eq) goto loc_82137C18;
	// bl 0x82137380
	ctx.lr = 0x82137C18;
	sub_82137380(ctx, base);
loc_82137C18:
	// lwz r30,60(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,16(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82137830
	ctx.lr = 0x82137C30;
	sub_82137830(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82137ec0
	if (cr6.lt) goto loc_82137EC0;
	// rotlwi r11,r5,0
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,28
	ctx.r5.s64 = 28;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r25,r10,r11
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x823da950
	ctx.lr = 0x82137C5C;
	sub_823DA950(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// lwz r9,28(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 28);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82137c94
	if (cr6.eq) goto loc_82137C94;
	// li r26,56
	r26.s64 = 56;
	// b 0x82137ca0
	goto loc_82137CA0;
loc_82137C94:
	// lwz r11,52(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 52);
	// addi r11,r11,14
	r11.s64 = r11.s64 + 14;
	// rlwinm r26,r11,2,0,29
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_82137CA0:
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x82137CAC;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x82137CC4;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// lwz r10,28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82137cec
	if (!cr6.eq) goto loc_82137CEC;
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// subf r11,r25,r11
	r11.s64 = r11.s64 - r25.s64;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// stw r10,32(r29)
	PPC_STORE_U32(r29.u32 + 32, ctx.r10.u32);
loc_82137CEC:
	// li r24,1
	r24.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r24,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r24.u32);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82137830
	ctx.lr = 0x82137D0C;
	sub_82137830(ctx, base);
	// li r23,0
	r23.s64 = 0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// add r28,r29,r26
	r28.u64 = r29.u64 + r26.u64;
	// blt cr6,0x82137d60
	if (cr6.lt) goto loc_82137D60;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r4,r11,r5
	ctx.r4.u64 = r11.u64 + ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x823da950
	ctx.lr = 0x82137D30;
	sub_823DA950(ctx, base);
	// stw r28,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r28.u32);
	// addi r27,r28,16
	r27.s64 = r28.s64 + 16;
	// lwzx r4,r29,r26
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r26.u32);
	// lwz r5,12(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823da950
	ctx.lr = 0x82137D48;
	sub_823DA950(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// stw r24,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r24.u32);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// add r28,r11,r27
	r28.u64 = r11.u64 + r27.u64;
	// b 0x82137d64
	goto loc_82137D64;
loc_82137D60:
	// stw r23,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r23.u32);
loc_82137D64:
	// clrlwi r11,r28,21
	r11.u64 = r28.u32 & 0x7FF;
	// subfic r11,r11,2048
	xer.ca = r11.u32 <= 2048;
	r11.s64 = 2048 - r11.s64;
	// cmplwi cr6,r11,2048
	cr6.compare<uint32_t>(r11.u32, 2048, xer);
	// bge cr6,0x82137d78
	if (!cr6.lt) goto loc_82137D78;
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
loc_82137D78:
	// subf r11,r30,r28
	r11.s64 = r28.s64 - r30.s64;
	// lwz r8,0(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r7,60(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// addi r27,r10,19856
	r27.s64 = ctx.r10.s64 + 19856;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// subf r26,r7,r8
	r26.s64 = ctx.r8.s64 - ctx.r7.s64;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r25,r9,9040
	r25.s64 = ctx.r9.s64 + 9040;
	// cmplw cr6,r5,r6
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, xer);
	// ble cr6,0x82137df8
	if (!cr6.gt) goto loc_82137DF8;
	// addi r3,r27,608
	ctx.r3.s64 = r27.s64 + 608;
	// lhz r4,66(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821436c0
	ctx.lr = 0x82137DC4;
	sub_821436C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82137de0
	if (cr6.eq) goto loc_82137DE0;
	// addi r3,r27,608
	ctx.r3.s64 = r27.s64 + 608;
	// lhz r4,66(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821436c0
	ctx.lr = 0x82137DD8;
	sub_821436C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82137de4
	goto loc_82137DE4;
loc_82137DE0:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
loc_82137DE4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,8960
	ctx.r3.s64 = r11.s64 + 8960;
	// bl 0x82130000
	ctx.lr = 0x82137DF8;
	sub_82130000(ctx, base);
loc_82137DF8:
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// cntlzw r11,r22
	r11.u64 = r22.u32 == 0 ? 32 : __builtin_clz(r22.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r8,r11,28,30,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x2;
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// bl 0x821bd600
	ctx.lr = 0x82137E2C;
	sub_821BD600(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82137f64
	if (!cr6.eq) goto loc_82137F64;
	// addi r3,r27,608
	ctx.r3.s64 = r27.s64 + 608;
	// lhz r4,66(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821436c0
	ctx.lr = 0x82137E40;
	sub_821436C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82137e5c
	if (cr6.eq) goto loc_82137E5C;
	// addi r3,r27,608
	ctx.r3.s64 = r27.s64 + 608;
	// lhz r4,66(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821436c0
	ctx.lr = 0x82137E54;
	sub_821436C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82137e60
	goto loc_82137E60;
loc_82137E5C:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
loc_82137E60:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r3,r11,8924
	ctx.r3.s64 = r11.s64 + 8924;
	// bl 0x82130000
	ctx.lr = 0x82137E70;
	sub_82130000(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8244d150
	ctx.lr = 0x82137E80;
	sub_8244D150(ctx, base);
	// lhz r9,66(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// ori r11,r10,65535
	r11.u64 = ctx.r10.u64 | 65535;
	// stw r23,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r23.u32);
	// stw r23,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r23.u32);
	// stb r23,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r23.u8);
	// stb r23,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r23.u8);
	// sth r11,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r11.u16);
	// sth r11,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r11.u16);
	// stw r23,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r23.u32);
	// sth r9,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r9.u16);
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// bl 0x821bcac8
	ctx.lr = 0x82137EB8;
	sub_821BCAC8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_82137EC0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lhz r4,66(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// addi r30,r11,19856
	r30.s64 = r11.s64 + 19856;
	// addi r3,r30,608
	ctx.r3.s64 = r30.s64 + 608;
	// bl 0x821436c0
	ctx.lr = 0x82137ED4;
	sub_821436C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82137ef0
	if (cr6.eq) goto loc_82137EF0;
	// addi r3,r30,608
	ctx.r3.s64 = r30.s64 + 608;
	// lhz r4,66(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821436c0
	ctx.lr = 0x82137EE8;
	sub_821436C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82137ef8
	goto loc_82137EF8;
loc_82137EF0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r11,9040
	ctx.r5.s64 = r11.s64 + 9040;
loc_82137EF8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r3,r11,8888
	ctx.r3.s64 = r11.s64 + 8888;
	// bl 0x82130000
	ctx.lr = 0x82137F08;
	sub_82130000(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8244d150
	ctx.lr = 0x82137F18;
	sub_8244D150(ctx, base);
	// lhz r9,66(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r23,0
	r23.s64 = 0;
	// ori r11,r10,65535
	r11.u64 = ctx.r10.u64 | 65535;
	// stw r23,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r23.u32);
	// sth r11,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r11.u16);
	// stw r23,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r23.u32);
	// stb r23,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r23.u8);
	// stb r23,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r23.u8);
	// sth r11,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r11.u16);
	// stw r23,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r23.u32);
	// sth r9,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r9.u16);
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// bl 0x821bcac8
	ctx.lr = 0x82137F54;
	sub_821BCAC8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_82137F5C:
	// li r11,0
	r11.s64 = 0;
	// stb r11,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r11.u8);
loc_82137F64:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82137BD0) {
	__imp__sub_82137BD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82137F6C) {
	__imp__sub_82137F6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82137F70) {
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
	ctx.lr = 0x82137F78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x82137F90;
	sub_821C90C0(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r30,r11,19856
	r30.s64 = r11.s64 + 19856;
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82137fdc
	if (cr6.eq) goto loc_82137FDC;
	// addi r3,r30,608
	ctx.r3.s64 = r30.s64 + 608;
	// lhz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// bl 0x821436c0
	ctx.lr = 0x82137FB0;
	sub_821436C0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r30,608
	ctx.r3.s64 = r30.s64 + 608;
	// lhz r4,66(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821436c0
	ctx.lr = 0x82137FC0;
	sub_821436C0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r9,9272
	ctx.r3.s64 = ctx.r9.s64 + 9272;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x82137FDC;
	sub_82130000(ctx, base);
loc_82137FDC:
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82138020
	if (cr6.eq) goto loc_82138020;
	// addi r3,r30,608
	ctx.r3.s64 = r30.s64 + 608;
	// lhz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// bl 0x821436c0
	ctx.lr = 0x82137FF4;
	sub_821436C0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r30,608
	ctx.r3.s64 = r30.s64 + 608;
	// lhz r4,66(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821436c0
	ctx.lr = 0x82138004;
	sub_821436C0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r9,9168
	ctx.r3.s64 = ctx.r9.s64 + 9168;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x82138020;
	sub_82130000(ctx, base);
loc_82138020:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82138064
	if (!cr6.eq) goto loc_82138064;
	// addi r3,r30,608
	ctx.r3.s64 = r30.s64 + 608;
	// lhz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// bl 0x821436c0
	ctx.lr = 0x82138038;
	sub_821436C0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r30,608
	ctx.r3.s64 = r30.s64 + 608;
	// lhz r4,66(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// bl 0x821436c0
	ctx.lr = 0x82138048;
	sub_821436C0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r9,9048
	ctx.r3.s64 = ctx.r9.s64 + 9048;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x82138064;
	sub_82130000(ctx, base);
loc_82138064:
	// lwz r30,60(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821380b4
	if (cr6.eq) goto loc_821380B4;
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821380b4
	if (!cr6.eq) goto loc_821380B4;
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821380b4
	if (!cr6.eq) goto loc_821380B4;
	// rotlwi r11,r30,0
	r11.u64 = __builtin_rotateleft32(r30.u32, 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82137830
	ctx.lr = 0x821380A0;
	sub_82137830(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x821380b4
	if (cr6.lt) goto loc_821380B4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r28,r10,r11
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_821380B4:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x821380BC;
	sub_821C9108(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82137F70) {
	__imp__sub_82137F70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821380C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x821380d8
	if (cr6.eq) goto loc_821380D8;
	// b 0x82137f70
	sub_82137F70(ctx, base);
	return;
loc_821380D8:
	// b 0x82146700
	sub_82146700(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_821380C8) {
	__imp__sub_821380C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821380DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821380DC) {
	__imp__sub_821380DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821380E0) {
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
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r11,5880
	ctx.r3.s64 = r11.s64 + 5880;
	// bl 0x826949b0
	ctx.lr = 0x82138100;
	sub_826949B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213811c
	if (cr6.eq) goto loc_8213811C;
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
loc_8213811C:
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

PPC_WEAK_FUNC(sub_821380E0) {
	__imp__sub_821380E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82138130) {
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
	ctx.lr = 0x82138138;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,0
	r11.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r5,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r5.u32);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// stw r6,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r6.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stb r31,70(r30)
	PPC_STORE_U8(r30.u32 + 70, r31.u8);
	// stb r31,71(r30)
	PPC_STORE_U8(r30.u32 + 71, r31.u8);
	// stw r10,44(r30)
	PPC_STORE_U32(r30.u32 + 44, ctx.r10.u32);
	// stw r31,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r31.u32);
	// sth r11,66(r30)
	PPC_STORE_U16(r30.u32 + 66, r11.u16);
	// stw r31,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r31.u32);
	// sth r11,68(r30)
	PPC_STORE_U16(r30.u32 + 68, r11.u16);
	// stw r31,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r31.u32);
	// stb r31,73(r30)
	PPC_STORE_U8(r30.u32 + 73, r31.u8);
	// stb r31,74(r30)
	PPC_STORE_U8(r30.u32 + 74, r31.u8);
	// bl 0x821378b8
	ctx.lr = 0x8213818C;
	sub_821378B8(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r31,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r31.u32);
	// bl 0x821c9060
	ctx.lr = 0x821381A0;
	sub_821C9060(ctx, base);
	// stw r3,52(r30)
	PPC_STORE_U32(r30.u32 + 52, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c9060
	ctx.lr = 0x821381AC;
	sub_821C9060(ctx, base);
	// stw r3,56(r30)
	PPC_STORE_U32(r30.u32 + 56, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x8244d150
	ctx.lr = 0x821381C0;
	sub_8244D150(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r31,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r31,72(r30)
	PPC_STORE_U8(r30.u32 + 72, r31.u8);
	// stw r9,40(r30)
	PPC_STORE_U32(r30.u32 + 40, ctx.r9.u32);
	// stw r31,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82138130) {
	__imp__sub_82138130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821381E0) {
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
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82138228
	if (cr6.lt) goto loc_82138228;
	// beq cr6,0x82138210
	if (cr6.eq) goto loc_82138210;
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
loc_82138210:
	// bl 0x821374e0
	ctx.lr = 0x82138214;
	sub_821374E0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82138228:
	// bl 0x82137560
	ctx.lr = 0x8213822C;
	sub_82137560(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821381E0) {
	__imp__sub_821381E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82138240) {
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
	ctx.lr = 0x82138248;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x82138260;
	sub_821C9790(ctx, base);
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821382c4
	if (cr6.eq) goto loc_821382C4;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x82138278;
	sub_821C90C0(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821382a0
	if (cr6.eq) goto loc_821382A0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,9384
	ctx.r3.s64 = r11.s64 + 9384;
	// bl 0x82130000
	ctx.lr = 0x82138290;
	sub_82130000(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82138298;
	sub_821C9108(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821382A0:
	// li r11,1
	r11.s64 = 1;
	// sth r30,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r30.u16);
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// stb r11,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r11.u8);
	// stb r11,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r11.u8);
	// bl 0x82144fc8
	ctx.lr = 0x821382B8;
	sub_82144FC8(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x821382C4;
	sub_821C9108(ctx, base);
loc_821382C4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82138240) {
	__imp__sub_82138240(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821382CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821382CC) {
	__imp__sub_821382CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821382D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821382e0
	if (cr6.eq) goto loc_821382E0;
	// b 0x821375c8
	sub_821375C8(ctx, base);
	return;
loc_821382E0:
	// b 0x82137690
	sub_82137690(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_821382D0) {
	__imp__sub_821382D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821382E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821382E4) {
	__imp__sub_821382E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821382E8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x82138310;
	sub_821C9790(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137690
	ctx.lr = 0x82138320;
	sub_82137690(ctx, base);
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

PPC_WEAK_FUNC(sub_821382E8) {
	__imp__sub_821382E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82138338) {
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
	ctx.lr = 0x82138340;
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
	// beq cr6,0x82138408
	if (cr6.eq) goto loc_82138408;
	// rlwinm r3,r28,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r31,r28,16
	r31.u64 = r28.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x82138364;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82138388
	if (cr6.eq) goto loc_82138388;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r31
	ctr.u64 = r31.u64;
loc_8213837C:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8213837c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8213837C;
loc_82138388:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821383f8
	if (cr6.eq) goto loc_821383F8;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8213839C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r11,r8,r11
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821383e4
	if (cr6.eq) goto loc_821383E4;
loc_821383AC:
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// twllei r31,0
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lhz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
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
	// bne cr6,0x821383ac
	if (!cr6.eq) goto loc_821383AC;
loc_821383E4:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blt cr6,0x8213839c
	if (cr6.lt) goto loc_8213839C;
loc_821383F8:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82138404;
	sub_82130588(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_82138408:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82138338) {
	__imp__sub_82138338(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82138410) {
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
	ctx.lr = 0x82138418;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,5608
	ctx.r9.s64 = r11.s64 + 5608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r5,r10,9572
	ctx.r5.s64 = ctx.r10.s64 + 9572;
	// li r4,255
	ctx.r4.s64 = 255;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// lwz r6,28(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mr r27,r30
	r27.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x82138448;
	sub_82137A08(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// addi r7,r8,3998
	ctx.r7.s64 = ctx.r8.s64 + 3998;
	// addi r3,r6,30576
	ctx.r3.s64 = ctx.r6.s64 + 30576;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r6,r1,368
	ctx.r6.s64 = ctx.r1.s64 + 368;
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x821ca2f8
	ctx.lr = 0x8213846C;
	sub_821CA2F8(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x82138474;
	sub_821C90C0(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r28,r5,65535
	r28.u64 = ctx.r5.u64 | 65535;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r28,68(r31)
	PPC_STORE_U16(r31.u32 + 68, r28.u16);
	// bgt cr6,0x82138688
	if (cr6.gt) goto loc_82138688;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lhz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// bl 0x821436c0
	ctx.lr = 0x821384A4;
	sub_821436C0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821384cc
	if (!cr6.eq) goto loc_821384CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lhz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// addi r3,r11,9520
	ctx.r3.s64 = r11.s64 + 9520;
	// bl 0x82130000
	ctx.lr = 0x821384C0;
	sub_82130000(ctx, base);
	// lhz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// sth r10,66(r31)
	PPC_STORE_U16(r31.u32 + 66, ctx.r10.u16);
	// b 0x82138680
	goto loc_82138680;
loc_821384CC:
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_821384D0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821384d0
	if (!cr6.eq) goto loc_821384D0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_821384E4:
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
	// bne cr6,0x821384e4
	if (!cr6.eq) goto loc_821384E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r29,64(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8244d150
	ctx.lr = 0x82138510;
	sub_8244D150(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r11,-1
	r11.s64 = -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r29,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r29.u16);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// sth r28,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r28.u16);
	// stb r30,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r30.u8);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stb r10,71(r31)
	PPC_STORE_U8(r31.u32 + 71, ctx.r10.u8);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82138544;
	sub_821C9108(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821bce68
	ctx.lr = 0x82138554;
	sub_821BCE68(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// beq cr6,0x82138638
	if (cr6.eq) goto loc_82138638;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821385ec
	if (!cr6.gt) goto loc_821385EC;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r30,1
	r30.s64 = 1;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// lwz r10,5840(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5840);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bge cr6,0x82138590
	if (!cr6.lt) goto loc_82138590;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_82138590:
	// lhz r9,66(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 66);
	// clrlwi r7,r29,16
	ctx.r7.u64 = r29.u32 & 0xFFFF;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// bne cr6,0x821385c4
	if (!cr6.eq) goto loc_821385C4;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x821385A8;
	sub_821C90C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137bd0
	ctx.lr = 0x821385B4;
	sub_82137BD0(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x821385BC;
	sub_821C9108(ctx, base);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9244
	return;
loc_821385C4:
	// clrlwi r9,r11,21
	ctx.r9.u64 = r11.u32 & 0x7FF;
	// sth r28,66(r10)
	PPC_STORE_U16(ctx.r10.u32 + 66, r28.u16);
	// subfic r9,r9,2048
	xer.ca = ctx.r9.u32 <= 2048;
	ctx.r9.s64 = 2048 - ctx.r9.s64;
	// cmplwi cr6,r9,2048
	cr6.compare<uint32_t>(ctx.r9.u32, 2048, xer);
	// bge cr6,0x821385dc
	if (!cr6.lt) goto loc_821385DC;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_821385DC:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x821385f4
	if (cr6.lt) goto loc_821385F4;
	// b 0x821385f0
	goto loc_821385F0;
loc_821385EC:
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_821385F0:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_821385F4:
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// li r5,1
	ctx.r5.s64 = 1;
	// xori r8,r4,1
	ctx.r8.u64 = ctx.r4.u64 ^ 1;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x821bd600
	ctx.lr = 0x82138628;
	sub_821BD600(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8213863c
	if (!cr6.eq) goto loc_8213863C;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821bd220
	ctx.lr = 0x82138638;
	sub_821BD220(ctx, base);
loc_82138638:
	// li r27,1
	r27.s64 = 1;
loc_8213863C:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82138690
	if (cr6.eq) goto loc_82138690;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x82138650;
	sub_821C90C0(ctx, base);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82138670
	if (cr6.eq) goto loc_82138670;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r11,9484
	ctx.r3.s64 = r11.s64 + 9484;
	// bl 0x82130000
	ctx.lr = 0x8213866C;
	sub_82130000(ctx, base);
	// b 0x82138680
	goto loc_82138680;
loc_82138670:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r11,9456
	ctx.r3.s64 = r11.s64 + 9456;
	// bl 0x82130000
	ctx.lr = 0x82138680;
	sub_82130000(ctx, base);
loc_82138680:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137308
	ctx.lr = 0x82138688;
	sub_82137308(ctx, base);
loc_82138688:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82138690;
	sub_821C9108(ctx, base);
loc_82138690:
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82138410) {
	__imp__sub_82138410(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82138698) {
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
	// lis r11,-32122
	r11.s64 = -2105147392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r10,1852(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1852);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821386dc
	if (cr6.eq) goto loc_821386DC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,9576
	ctx.r3.s64 = r11.s64 + 9576;
	// bl 0x82130000
	ctx.lr = 0x821386C8;
	sub_82130000(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821386DC:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x821386E4;
	sub_821C90C0(ctx, base);
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// beq cr6,0x8213872c
	if (cr6.eq) goto loc_8213872C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82138700
	if (!cr6.gt) goto loc_82138700;
	// bl 0x821bcac8
	ctx.lr = 0x82138700;
	sub_821BCAC8(ctx, base);
loc_82138700:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8244d150
	ctx.lr = 0x82138710;
	sub_8244D150(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// sth r10,66(r31)
	PPC_STORE_U16(r31.u32 + 66, ctx.r10.u16);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stb r11,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r11.u8);
	// b 0x82138758
	goto loc_82138758;
loc_8213872C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ble cr6,0x82138744
	if (!cr6.gt) goto loc_82138744;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82137bd0
	ctx.lr = 0x82138740;
	sub_82137BD0(ctx, base);
	// b 0x82138758
	goto loc_82138758;
loc_82138744:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// bl 0x82137380
	ctx.lr = 0x82138750;
	sub_82137380(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,71(r31)
	PPC_STORE_U8(r31.u32 + 71, ctx.r10.u8);
loc_82138758:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82138760;
	sub_821C9108(ctx, base);
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82138774
	if (!cr6.eq) goto loc_82138774;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821bd220
	ctx.lr = 0x82138774;
	sub_821BD220(ctx, base);
loc_82138774:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82138698) {
	__imp__sub_82138698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82138788) {
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
	// sth r3,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, ctx.r3.u16);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r4,r1,118
	ctx.r4.s64 = ctx.r1.s64 + 118;
	// addi r3,r11,5976
	ctx.r3.s64 = r11.s64 + 5976;
	// bl 0x82613f68
	ctx.lr = 0x821387A8;
	sub_82613F68(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821387c4
	if (cr6.eq) goto loc_821387C4;
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
loc_821387C4:
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

PPC_WEAK_FUNC(sub_82138788) {
	__imp__sub_82138788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821387D8) {
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
	ctx.lr = 0x821387E0;
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
	// bne cr6,0x82138808
	if (!cr6.eq) goto loc_82138808;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x82138808;
	sub_82608A98(ctx, base);
loc_82138808:
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
	// bne cr6,0x82138838
	if (!cr6.eq) goto loc_82138838;
	// bl 0x821c9438
	ctx.lr = 0x8213882C;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82138338
	ctx.lr = 0x82138838;
	sub_82138338(ctx, base);
loc_82138838:
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r3,12
	ctx.r3.s64 = 12;
	// lhz r11,0(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// twllei r10,0
	// divwu r8,r11,r10
	ctx.r8.u32 = r11.u32 / ctx.r10.u32;
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// rlwinm r30,r6,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r30,r9
	r29.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x82138864;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82138888
	if (cr6.eq) goto loc_82138888;
	// lhz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// sth r10,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r10.u16);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// b 0x8213888c
	goto loc_8213888C;
loc_82138888:
	// li r11,0
	r11.s64 = 0;
loc_8213888C:
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

PPC_WEAK_FUNC(sub_821387D8) {
	__imp__sub_821387D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821388A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821388A4) {
	__imp__sub_821388A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821388A8) {
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
	ctx.lr = 0x821388B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821388d8
	if (!cr6.eq) goto loc_821388D8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x821388D8;
	sub_82608A98(ctx, base);
loc_821388D8:
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
	// bne cr6,0x82138908
	if (!cr6.eq) goto loc_82138908;
	// bl 0x821c9438
	ctx.lr = 0x821388FC;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a50
	ctx.lr = 0x82138908;
	sub_82137A50(ctx, base);
loc_82138908:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213891c
	if (cr6.eq) goto loc_8213891C;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// b 0x82138924
	goto loc_82138924;
loc_8213891C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
loc_82138924:
	// bl 0x821c9550
	ctx.lr = 0x82138928;
	sub_821C9550(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r3,16
	ctx.r3.s64 = 16;
	// divwu r8,r10,r11
	ctx.r8.u32 = ctx.r10.u32 / r11.u32;
	// twllei r11,0
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r28,r6,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r28,r9
	r29.u64 = PPC_LOAD_U32(r28.u32 + ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x82138954;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8213898c
	if (cr6.eq) goto loc_8213898C;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// lhz r5,4(r27)
	ctx.r5.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lwz r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x8213897C;
	sub_821C9650(ctx, base);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_8213898C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r11,r28,r10
	PPC_STORE_U32(r28.u32 + ctx.r10.u32, r11.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r28,r9
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_821388A8) {
	__imp__sub_821388A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821389A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821389A4) {
	__imp__sub_821389A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821389A8) {
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
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821389e4
	if (cr6.eq) goto loc_821389E4;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x821c9078
	ctx.lr = 0x821389D0;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821389e4
	if (cr6.eq) goto loc_821389E4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82138698
	ctx.lr = 0x821389E4;
	sub_82138698(ctx, base);
loc_821389E4:
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82138a04
	if (!cr6.eq) goto loc_82138A04;
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82138a04
	if (cr6.eq) goto loc_82138A04;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82138410
	ctx.lr = 0x82138A04;
	sub_82138410(ctx, base);
loc_82138A04:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821389A8) {
	__imp__sub_821389A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82138A18) {
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
	ctx.lr = 0x82138A20;
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
	// beq cr6,0x82138a84
	if (cr6.eq) goto loc_82138A84;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_82138A40:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82138a70
	if (cr6.eq) goto loc_82138A70;
loc_82138A50:
	// mr r26,r31
	r26.u64 = r31.u64;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82138A60;
	sub_82130588(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x82138A68;
	sub_82130588(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82138a50
	if (!cr6.eq) goto loc_82138A50;
loc_82138A70:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x82138a40
	if (cr6.lt) goto loc_82138A40;
loc_82138A84:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82138A8C;
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

PPC_WEAK_FUNC(sub_82138A18) {
	__imp__sub_82138A18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82138AA0) {
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
	ctx.lr = 0x82138AA8;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// addi r10,r11,5956
	ctx.r10.s64 = r11.s64 + 5956;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,5828(r6)
	PPC_STORE_U32(ctx.r6.u32 + 5828, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,5824(r5)
	PPC_STORE_U32(ctx.r5.u32 + 5824, ctx.r10.u32);
	// cntlzw r4,r11
	ctx.r4.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r5,r8,5860
	ctx.r5.s64 = ctx.r8.s64 + 5860;
	// li r11,0
	r11.s64 = 0;
	// stw r9,5844(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5844, ctx.r9.u32);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// stw r11,5840(r7)
	PPC_STORE_U32(ctx.r7.u32 + 5840, r11.u32);
	// lis r27,-32125
	r27.s64 = -2105344000;
	// stw r11,5848(r6)
	PPC_STORE_U32(ctx.r6.u32 + 5848, r11.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lwz r8,4(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// rlwinm r5,r4,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stw r11,5836(r30)
	PPC_STORE_U32(r30.u32 + 5836, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,5832(r27)
	PPC_STORE_U32(r27.u32 + 5832, ctx.r10.u32);
	// stb r10,5852(r7)
	PPC_STORE_U8(ctx.r7.u32 + 5852, ctx.r10.u8);
	// li r29,0
	r29.s64 = 0;
	// stb r9,5853(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5853, ctx.r9.u8);
	// xori r25,r5,1
	r25.u64 = ctx.r5.u64 ^ 1;
	// stw r11,5856(r6)
	PPC_STORE_U32(ctx.r6.u32 + 5856, r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// bne cr6,0x8213930c
	if (!cr6.eq) goto loc_8213930C;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// lwz r11,2828(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 2828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82138b7c
	if (!cr6.eq) goto loc_82138B7C;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x82138B5C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82138b74
	if (cr6.eq) goto loc_82138B74;
	// bl 0x821c0580
	ctx.lr = 0x82138B6C;
	sub_821C0580(ctx, base);
	// stw r31,2828(r28)
	PPC_STORE_U32(r28.u32 + 2828, r31.u32);
	// b 0x82138b7c
	goto loc_82138B7C;
loc_82138B74:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r28)
	PPC_STORE_U32(r28.u32 + 2828, r11.u32);
loc_82138B7C:
	// bl 0x821c4210
	ctx.lr = 0x82138B80;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,2828(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 2828);
	// addi r10,r11,30500
	ctx.r10.s64 = r11.s64 + 30500;
	// lwz r11,30500(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30500);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// bl 0x821c05e8
	ctx.lr = 0x82138BA4;
	sub_821C05E8(ctx, base);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,2828(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 2828);
	// addi r7,r9,5608
	ctx.r7.s64 = ctx.r9.s64 + 5608;
	// addi r5,r8,3998
	ctx.r5.s64 = ctx.r8.s64 + 3998;
	// lwz r4,24(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// bl 0x821c0210
	ctx.lr = 0x82138BC0;
	sub_821C0210(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// stw r24,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r24.u32);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x82138c10
	if (!cr6.eq) goto loc_82138C10;
	// lwz r3,2828(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 2828);
	// bl 0x821bfc50
	ctx.lr = 0x82138BD8;
	sub_821BFC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213930c
	if (cr6.eq) goto loc_8213930C;
	// lwz r31,2828(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 2828);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82138c00
	if (cr6.eq) goto loc_82138C00;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c0688
	ctx.lr = 0x82138BF8;
	sub_821C0688(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82138C00;
	sub_82130588(ctx, base);
loc_82138C00:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r28)
	PPC_STORE_U32(r28.u32 + 2828, r11.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
loc_82138C10:
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r21,r11,9864
	r21.s64 = r11.s64 + 9864;
	// addi r23,r10,9856
	r23.s64 = ctx.r10.s64 + 9856;
	// lwz r28,28(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// addi r22,r9,9848
	r22.s64 = ctx.r9.s64 + 9848;
	// stw r21,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r21.u32);
	// stw r23,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r23.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r22.u32);
	// beq cr6,0x82138ce8
	if (cr6.eq) goto loc_82138CE8;
	// clrlwi r26,r25,24
	r26.u64 = r25.u32 & 0xFF;
loc_82138C48:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82138C58;
	sub_821C82A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82138C6C;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82138cbc
	if (!cr6.eq) goto loc_82138CBC;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82138c88
	if (cr6.eq) goto loc_82138C88;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// b 0x82138c8c
	goto loc_82138C8C;
loc_82138C88:
	// li r11,0
	r11.s64 = 0;
loc_82138C8C:
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
loc_82138C90:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82138cb4
	if (cr6.eq) goto loc_82138CB4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82138c90
	if (cr6.eq) goto loc_82138C90;
loc_82138CB4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82138cdc
	if (cr6.eq) goto loc_82138CDC;
loc_82138CBC:
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x821c6090
	ctx.lr = 0x82138CC4;
	sub_821C6090(ctx, base);
	// lwz r11,5836(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5836);
	// addi r10,r3,127
	ctx.r10.s64 = ctx.r3.s64 + 127;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// stw r11,5836(r30)
	PPC_STORE_U32(r30.u32 + 5836, r11.u32);
	// add r29,r10,r29
	r29.u64 = ctx.r10.u64 + r29.u64;
loc_82138CDC:
	// lwz r28,24(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82138c48
	if (!cr6.eq) goto loc_82138C48;
loc_82138CE8:
	// li r4,2048
	ctx.r4.s64 = 2048;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82135fe8
	ctx.lr = 0x82138CF4;
	sub_82135FE8(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r29,5832(r27)
	PPC_STORE_U32(r27.u32 + 5832, r29.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r11,5836(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5836);
	// stw r3,5828(r10)
	PPC_STORE_U32(ctx.r10.u32 + 5828, ctx.r3.u32);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82135fd0
	ctx.lr = 0x82138D18;
	sub_82135FD0(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r21,0
	r21.s64 = 0;
	// addi r9,r11,5880
	ctx.r9.s64 = r11.s64 + 5880;
	// stw r3,5824(r10)
	PPC_STORE_U32(ctx.r10.u32 + 5824, ctx.r3.u32);
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// lwz r26,28(r8)
	r26.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82139280
	if (cr6.eq) goto loc_82139280;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r31,-32256
	r31.s64 = -2113929216;
	// lis r30,-32256
	r30.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r8,9824
	ctx.r8.s64 = ctx.r8.s64 + 9824;
	// addi r7,r7,9784
	ctx.r7.s64 = ctx.r7.s64 + 9784;
	// li r20,1
	r20.s64 = 1;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// addi r19,r9,9712
	r19.s64 = ctx.r9.s64 + 9712;
	// stw r7,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// addi r14,r6,5976
	r14.s64 = ctx.r6.s64 + 5976;
	// addi r18,r5,19856
	r18.s64 = ctx.r5.s64 + 19856;
	// addi r17,r4,9700
	r17.s64 = ctx.r4.s64 + 9700;
	// addi r16,r3,9692
	r16.s64 = ctx.r3.s64 + 9692;
	// addi r15,r31,9684
	r15.s64 = r31.s64 + 9684;
	// addi r24,r30,9668
	r24.s64 = r30.s64 + 9668;
	// addi r23,r10,9656
	r23.s64 = ctx.r10.s64 + 9656;
	// addi r22,r11,9644
	r22.s64 = r11.s64 + 9644;
loc_82138DAC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82138DBC;
	sub_821C82A8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82138DD0;
	sub_821C82A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82138DE4;
	sub_821C82A8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82138DF8;
	sub_821C82A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82138E0C;
	sub_821C82A8(ctx, base);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82138e64
	if (!cr6.eq) goto loc_82138E64;
	// lwz r11,36(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82138e30
	if (cr6.eq) goto loc_82138E30;
	// lwz r11,32(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// b 0x82138e34
	goto loc_82138E34;
loc_82138E30:
	// li r11,0
	r11.s64 = 0;
loc_82138E34:
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
loc_82138E38:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82138e5c
	if (cr6.eq) goto loc_82138E5C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82138e38
	if (cr6.eq) goto loc_82138E38;
loc_82138E5C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82139274
	if (cr6.eq) goto loc_82139274;
loc_82138E64:
	// cmpwi cr6,r21,-1
	cr6.compare<int32_t>(r21.s32, -1, xer);
	// beq cr6,0x82138e88
	if (cr6.eq) goto loc_82138E88;
	// rlwinm r10,r21,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// add r10,r21,r10
	ctx.r10.u64 = r21.u64 + ctx.r10.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,5824(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5824);
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82138e8c
	goto loc_82138E8C;
loc_82138E88:
	// li r29,0
	r29.s64 = 0;
loc_82138E8C:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// bl 0x821c6090
	ctx.lr = 0x82138E98;
	sub_821C6090(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821c6090
	ctx.lr = 0x82138EA8;
	sub_821C6090(ctx, base);
	// addi r10,r31,127
	ctx.r10.s64 = r31.s64 + 127;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// rlwinm r30,r10,0,0,24
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82138f5c
	if (cr6.eq) goto loc_82138F5C;
	// lwz r11,36(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82138ed0
	if (cr6.eq) goto loc_82138ED0;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// b 0x82138ed4
	goto loc_82138ED4;
loc_82138ED0:
	// li r11,0
	r11.s64 = 0;
loc_82138ED4:
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
loc_82138ED8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82138efc
	if (cr6.eq) goto loc_82138EFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82138ed8
	if (cr6.eq) goto loc_82138ED8;
loc_82138EFC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82138f5c
	if (!cr6.eq) goto loc_82138F5C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82138fc4
	if (cr6.eq) goto loc_82138FC4;
	// lwz r11,36(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82138f20
	if (cr6.eq) goto loc_82138F20;
	// lwz r7,32(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// b 0x82138f24
	goto loc_82138F24;
loc_82138F20:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82138F24:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,5828(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5828);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821450e0
	ctx.lr = 0x82138F40;
	sub_821450E0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82139058
	if (cr6.eq) goto loc_82139058;
	// li r11,2
	r11.s64 = 2;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// b 0x82139058
	goto loc_82139058;
loc_82138F5C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82138fc4
	if (cr6.eq) goto loc_82138FC4;
	// lwz r11,36(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82138f78
	if (cr6.eq) goto loc_82138F78;
	// lwz r7,32(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// b 0x82138f7c
	goto loc_82138F7C;
loc_82138F78:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82138F7C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,5828(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 5828);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82138130
	ctx.lr = 0x82138F98;
	sub_82138130(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82139058
	if (cr6.eq) goto loc_82139058;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82139058
	if (cr6.eq) goto loc_82139058;
	// lwz r8,36(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82138fd0
	if (cr6.eq) goto loc_82138FD0;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// b 0x82138fd4
	goto loc_82138FD4;
loc_82138FC4:
	// li r31,0
	r31.s64 = 0;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// b 0x82139058
	goto loc_82139058;
loc_82138FD0:
	// li r11,0
	r11.s64 = 0;
loc_82138FD4:
	// mr r10,r16
	ctx.r10.u64 = r16.u64;
loc_82138FD8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82138ffc
	if (cr6.eq) goto loc_82138FFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82138fd8
	if (cr6.eq) goto loc_82138FD8;
loc_82138FFC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82139010
	if (!cr6.eq) goto loc_82139010;
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// b 0x82139058
	goto loc_82139058;
loc_82139010:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82139020
	if (cr6.eq) goto loc_82139020;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// b 0x82139024
	goto loc_82139024;
loc_82139020:
	// li r11,0
	r11.s64 = 0;
loc_82139024:
	// mr r10,r17
	ctx.r10.u64 = r17.u64;
loc_82139028:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8213904c
	if (cr6.eq) goto loc_8213904C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82139028
	if (cr6.eq) goto loc_82139028;
loc_8213904C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82139058
	if (!cr6.eq) goto loc_82139058;
	// stw r20,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r20.u32);
loc_82139058:
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// add r10,r30,r11
	ctx.r10.u64 = r30.u64 + r11.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// beq cr6,0x821391c0
	if (cr6.eq) goto loc_821391C0;
	// lbz r11,818(r18)
	r11.u64 = PPC_LOAD_U8(r18.u32 + 818);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821391c0
	if (cr6.eq) goto loc_821391C0;
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8213908c
	if (cr6.eq) goto loc_8213908C;
	// lwz r4,32(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// b 0x82139090
	goto loc_82139090;
loc_8213908C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82139090:
	// addi r3,r18,608
	ctx.r3.s64 = r18.s64 + 608;
	// bl 0x82144768
	ctx.lr = 0x82139098;
	sub_82144768(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// sth r29,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r29.u16);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821391a0
	if (cr6.eq) goto loc_821391A0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821374e0
	ctx.lr = 0x821390B8;
	sub_821374E0(ctx, base);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821387d8
	ctx.lr = 0x821390C8;
	sub_821387D8(ctx, base);
	// li r28,0
	r28.s64 = 0;
loc_821390CC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x821390D4;
	sub_821C91B8(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8213912c
	if (cr6.eq) goto loc_8213912C;
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82139108
	if (cr6.eq) goto loc_82139108;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x821c9078
	ctx.lr = 0x821390F4;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82139108
	if (cr6.eq) goto loc_82139108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82138698
	ctx.lr = 0x82139108;
	sub_82138698(ctx, base);
loc_82139108:
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82139134
	if (!cr6.eq) goto loc_82139134;
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82139134
	if (cr6.eq) goto loc_82139134;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82138410
	ctx.lr = 0x82139128;
	sub_82138410(ctx, base);
	// b 0x82139134
	goto loc_82139134;
loc_8213912C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82146890
	ctx.lr = 0x82139134;
	sub_82146890(ctx, base);
loc_82139134:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821375c8
	ctx.lr = 0x82139140;
	sub_821375C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// beq cr6,0x82139154
	if (cr6.eq) goto loc_82139154;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// bne cr6,0x82139194
	if (!cr6.eq) goto loc_82139194;
loc_82139154:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c90c0
	ctx.lr = 0x8213915C;
	sub_821C90C0(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82139174
	if (cr6.eq) goto loc_82139174;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82130000
	ctx.lr = 0x82139170;
	sub_82130000(ctx, base);
	// b 0x8213918c
	goto loc_8213918C;
loc_82139174:
	// sth r29,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r29.u16);
	// stb r20,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r20.u8);
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
	// stb r20,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r20.u8);
	// bl 0x82144fc8
	ctx.lr = 0x82139188;
	sub_82144FC8(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
loc_8213918C:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9108
	ctx.lr = 0x82139194;
	sub_821C9108(ctx, base);
loc_82139194:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x821390cc
	if (!cr6.eq) goto loc_821390CC;
	// b 0x821391c0
	goto loc_821391C0;
loc_821391A0:
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821391b4
	if (cr6.eq) goto loc_821391B4;
	// lwz r4,32(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// b 0x821391b8
	goto loc_821391B8;
loc_821391B4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821391B8:
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x82130000
	ctx.lr = 0x821391C0;
	sub_82130000(ctx, base);
loc_821391C0:
	// lwz r11,36(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 36);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821391d8
	if (cr6.eq) goto loc_821391D8;
	// lwz r4,32(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// b 0x821391dc
	goto loc_821391DC;
loc_821391D8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
loc_821391DC:
	// stw r30,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r30.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r30,140(r1)
	PPC_STORE_U16(ctx.r1.u32 + 140, r30.u16);
	// sth r30,142(r1)
	PPC_STORE_U16(ctx.r1.u32 + 142, r30.u16);
	// beq cr6,0x82139218
	if (cr6.eq) goto loc_82139218;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_821391F4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821391f4
	if (!cr6.eq) goto loc_821391F4;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x82139218;
	sub_821C9650(ctx, base);
loc_82139218:
	// lwz r31,92(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137928
	ctx.lr = 0x82139228;
	sub_82137928(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213925c
	if (cr6.eq) goto loc_8213925C;
	// lwz r11,36(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8213924c
	if (cr6.eq) goto loc_8213924C;
	// lwz r4,32(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// bl 0x821bd618
	ctx.lr = 0x82139248;
	sub_821BD618(ctx, base);
	// b 0x8213926c
	goto loc_8213926C;
loc_8213924C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// bl 0x821bd618
	ctx.lr = 0x82139258;
	sub_821BD618(ctx, base);
	// b 0x8213926c
	goto loc_8213926C;
loc_8213925C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// bl 0x821388a8
	ctx.lr = 0x8213926C;
	sub_821388A8(ctx, base);
loc_8213926C:
	// lwz r3,136(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x82130588
	ctx.lr = 0x82139274;
	sub_82130588(ctx, base);
loc_82139274:
	// lwz r26,24(r26)
	r26.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82138dac
	if (!cr6.eq) goto loc_82138DAC;
loc_82139280:
	// lwz r31,128(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c5c70
	ctx.lr = 0x8213928C;
	sub_821C5C70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82139294;
	sub_82130588(ctx, base);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r3,2828(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2828);
	// bl 0x821bfc50
	ctx.lr = 0x821392A0;
	sub_821BFC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821392d0
	if (cr6.eq) goto loc_821392D0;
	// lwz r31,2828(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 2828);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821392c8
	if (cr6.eq) goto loc_821392C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c0688
	ctx.lr = 0x821392C0;
	sub_821C0688(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821392C8;
	sub_82130588(ctx, base);
loc_821392C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r30)
	PPC_STORE_U32(r30.u32 + 2828, r11.u32);
loc_821392D0:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,6108(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 6108);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// bl 0x826949b0
	ctx.lr = 0x821392E8;
	sub_826949B0(ctx, base);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82139304
	if (cr6.eq) goto loc_82139304;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,5840(r10)
	PPC_STORE_U32(ctx.r10.u32 + 5840, r11.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
loc_82139304:
	// li r11,0
	r11.s64 = 0;
	// stw r11,5840(r10)
	PPC_STORE_U32(ctx.r10.u32 + 5840, r11.u32);
loc_8213930C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_82138AA0) {
	__imp__sub_82138AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82139314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82139314) {
	__imp__sub_82139314(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82139318) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5880
	ctx.r3.s64 = r11.s64 + 5880;
	// bl 0x82138a18
	ctx.lr = 0x82139330;
	sub_82138A18(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,5976
	ctx.r3.s64 = ctx.r10.s64 + 5976;
	// bl 0x82608de8
	ctx.lr = 0x8213933C;
	sub_82608DE8(ctx, base);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lwz r3,5828(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 5828);
	// bl 0x82135ff0
	ctx.lr = 0x82139348;
	sub_82135FF0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,5824(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 5824);
	// bl 0x82135fd8
	ctx.lr = 0x82139354;
	sub_82135FD8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82139318) {
	__imp__sub_82139318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82139364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82139364) {
	__imp__sub_82139364(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82139368) {
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
	ctx.lr = 0x82139370;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,5924
	ctx.r4.s64 = r11.s64 + 5924;
	// bl 0x821c8fe0
	ctx.lr = 0x82139384;
	sub_821C8FE0(ctx, base);
	// lis r28,-32125
	r28.s64 = -2105344000;
	// lbz r10,5852(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 5852);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82139700
	if (cr6.eq) goto loc_82139700;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r27,0
	r27.s64 = 0;
	// addi r31,r11,5760
	r31.s64 = r11.s64 + 5760;
	// lis r29,-32125
	r29.s64 = -2105344000;
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r10,r31
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821393d4
	if (cr6.eq) goto loc_821393D4;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,5824(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x821393d8
	goto loc_821393D8;
loc_821393D4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_821393D8:
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// addi r9,r31,2
	ctx.r9.s64 = r31.s64 + 2;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lhzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82137690
	ctx.lr = 0x821393EC;
	sub_82137690(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82139420
	if (!cr6.eq) goto loc_82139420;
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r11,r31
	r11.u64 = PPC_LOAD_U16(r11.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821396e4
	if (cr6.eq) goto loc_821396E4;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5824(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821396e8
	goto loc_821396E8;
loc_82139420:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8213955c
	if (!cr6.eq) goto loc_8213955C;
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r11,r31
	r11.u64 = PPC_LOAD_U16(r11.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82139454
	if (cr6.eq) goto loc_82139454;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5824(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82139458
	goto loc_82139458;
loc_82139454:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82139458:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stb r27,74(r11)
	PPC_STORE_U8(r11.u32 + 74, r27.u8);
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r10,5848(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5848);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r11,5856(r30)
	PPC_STORE_U32(r30.u32 + 5856, r11.u32);
	// bne cr6,0x82139494
	if (!cr6.eq) goto loc_82139494;
	// bl 0x821bcac8
	ctx.lr = 0x8213947C;
	sub_821BCAC8(ctx, base);
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r11,5852(r28)
	PPC_STORE_U8(r28.u32 + 5852, r11.u8);
	// bl 0x821c9030
	ctx.lr = 0x8213948C;
	sub_821C9030(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82139494:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r11,r31
	r11.u64 = PPC_LOAD_U16(r11.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821394bc
	if (cr6.eq) goto loc_821394BC;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5824(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821394c0
	goto loc_821394C0;
loc_821394BC:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821394C0:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,74(r11)
	PPC_STORE_U8(r11.u32 + 74, ctx.r10.u8);
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r10,r31
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821394f4
	if (cr6.eq) goto loc_821394F4;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,5824(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x821394f8
	goto loc_821394F8;
loc_821394F4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_821394F8:
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// addi r9,r31,2
	ctx.r9.s64 = r31.s64 + 2;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lhzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82137560
	ctx.lr = 0x8213950C;
	sub_82137560(ctx, base);
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r8,r31
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82139538
	if (cr6.eq) goto loc_82139538;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5824(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213953c
	goto loc_8213953C;
loc_82139538:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8213953C:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82139590
	if (cr6.eq) goto loc_82139590;
	// bl 0x821389a8
	ctx.lr = 0x8213954C;
	sub_821389A8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82139554;
	sub_821C9030(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8213955C:
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x821395a4
	if (!cr6.eq) goto loc_821395A4;
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r11,r31
	r11.u64 = PPC_LOAD_U16(r11.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82139538
	if (cr6.eq) goto loc_82139538;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5824(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213953c
	goto loc_8213953C;
loc_82139590:
	// bl 0x82146890
	ctx.lr = 0x82139594;
	sub_82146890(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8213959C;
	sub_821C9030(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_821395A4:
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82139700
	if (!cr6.eq) goto loc_82139700;
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r11,r31
	r11.u64 = PPC_LOAD_U16(r11.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821395d8
	if (cr6.eq) goto loc_821395D8;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5824(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821395dc
	goto loc_821395DC;
loc_821395D8:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821395DC:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,74(r11)
	PPC_STORE_U8(r11.u32 + 74, ctx.r10.u8);
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r10,r31
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82139610
	if (cr6.eq) goto loc_82139610;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,5824(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82139614
	goto loc_82139614;
loc_82139610:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82139614:
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// addi r9,r31,2
	ctx.r9.s64 = r31.s64 + 2;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lhzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82137560
	ctx.lr = 0x82139628;
	sub_82137560(ctx, base);
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// lwz r10,5824(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r8,r31
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82139654
	if (cr6.eq) goto loc_82139654;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x82139658
	goto loc_82139658;
loc_82139654:
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
loc_82139658:
	// lwz r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82139700
	if (cr6.eq) goto loc_82139700;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82139680
	if (cr6.eq) goto loc_82139680;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x82139684
	goto loc_82139684;
loc_82139680:
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
loc_82139684:
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821396a4
	if (cr6.eq) goto loc_821396A4;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821396a8
	goto loc_821396A8;
loc_821396A4:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821396A8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r10,9872
	ctx.r3.s64 = ctx.r10.s64 + 9872;
	// bl 0x82130000
	ctx.lr = 0x821396B8;
	sub_82130000(ctx, base);
	// lwz r11,5856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5856);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r11,r9,r31
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + r31.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821396e4
	if (cr6.eq) goto loc_821396E4;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5824(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821396e8
	goto loc_821396E8;
loc_821396E4:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821396E8:
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stb r27,74(r11)
	PPC_STORE_U8(r11.u32 + 74, r27.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// stb r10,5852(r28)
	PPC_STORE_U8(r28.u32 + 5852, ctx.r10.u8);
	// stb r9,5853(r8)
	PPC_STORE_U8(ctx.r8.u32 + 5853, ctx.r9.u8);
loc_82139700:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82139708;
	sub_821C9030(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82139368) {
	__imp__sub_82139368(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82139710) {
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
	ctx.lr = 0x82139718;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r4,r11,5892
	ctx.r4.s64 = r11.s64 + 5892;
	// bl 0x821c8fe0
	ctx.lr = 0x8213972C;
	sub_821C8FE0(ctx, base);
	// lis r28,-32125
	r28.s64 = -2105344000;
	// li r27,0
	r27.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,5836(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 5836);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821397c8
	if (cr6.eq) goto loc_821397C8;
	// lis r29,-32125
	r29.s64 = -2105344000;
loc_82139748:
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x821397b8
	if (cr6.eq) goto loc_821397B8;
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5824(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 5824);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821397b8
	if (cr6.eq) goto loc_821397B8;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82139780
	if (!cr6.eq) goto loc_82139780;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82145ed0
	ctx.lr = 0x82139780;
	sub_82145ED0(ctx, base);
loc_82139780:
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821397b8
	if (cr6.eq) goto loc_821397B8;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x821397a4
	if (cr6.eq) goto loc_821397A4;
	// bl 0x821389a8
	ctx.lr = 0x821397A0;
	sub_821389A8(ctx, base);
	// b 0x821397a8
	goto loc_821397A8;
loc_821397A4:
	// bl 0x82146890
	ctx.lr = 0x821397A8;
	sub_82146890(ctx, base);
loc_821397A8:
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821397b8
	if (cr6.eq) goto loc_821397B8;
	// li r27,1
	r27.s64 = 1;
loc_821397B8:
	// lwz r11,5836(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 5836);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82139748
	if (cr6.lt) goto loc_82139748;
loc_821397C8:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821397ec
	if (!cr6.eq) goto loc_821397EC;
	// bl 0x82139368
	ctx.lr = 0x821397D8;
	sub_82139368(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,5852(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5852);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821397ec
	if (cr6.eq) goto loc_821397EC;
	// li r27,1
	r27.s64 = 1;
loc_821397EC:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82139898
	if (!cr6.eq) goto loc_82139898;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82137b48
	ctx.lr = 0x82139808;
	sub_82137B48(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82139898
	if (cr6.eq) goto loc_82139898;
loc_82139814:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8213986c
	if (cr6.eq) goto loc_8213986C;
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82139848
	if (cr6.eq) goto loc_82139848;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x821c9078
	ctx.lr = 0x82139834;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82139848
	if (cr6.eq) goto loc_82139848;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82138698
	ctx.lr = 0x82139848;
	sub_82138698(ctx, base);
loc_82139848:
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82139874
	if (!cr6.eq) goto loc_82139874;
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82139874
	if (cr6.eq) goto loc_82139874;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82138410
	ctx.lr = 0x82139868;
	sub_82138410(ctx, base);
	// b 0x82139874
	goto loc_82139874;
loc_8213986C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82146890
	ctx.lr = 0x82139874;
	sub_82146890(ctx, base);
loc_82139874:
	// lbz r11,71(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 71);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82139898
	if (!cr6.eq) goto loc_82139898;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82137b48
	ctx.lr = 0x8213988C;
	sub_82137B48(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82139814
	if (!cr6.eq) goto loc_82139814;
loc_82139898:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x821398A0;
	sub_821C9030(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82139710) {
	__imp__sub_82139710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821398A8) {
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
	ctx.lr = 0x821398B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,6036
	r30.s64 = r11.s64 + 6036;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82139930
	if (cr6.eq) goto loc_82139930;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// addi r28,r11,10264
	r28.s64 = r11.s64 + 10264;
loc_821398D8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213991c
	if (cr6.eq) goto loc_8213991C;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// bl 0x821cbc88
	ctx.lr = 0x821398F0;
	sub_821CBC88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213990c
	if (!cr6.eq) goto loc_8213990C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r4,r31,r11
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82130000
	ctx.lr = 0x8213990C;
	sub_82130000(ctx, base);
loc_8213990C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82130588
	ctx.lr = 0x82139918;
	sub_82130588(ctx, base);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
loc_8213991C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x821398d8
	if (cr6.lt) goto loc_821398D8;
loc_82139930:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r28,0
	r28.s64 = 0;
	// addi r31,r11,5988
	r31.s64 = r11.s64 + 5988;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82139994
	if (cr6.eq) goto loc_82139994;
	// li r29,0
	r29.s64 = 0;
loc_8213994C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r9,r29,r11
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82139980
	if (cr6.eq) goto loc_82139980;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82139980
	if (cr6.eq) goto loc_82139980;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213997C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
loc_82139980:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8213994c
	if (cr6.lt) goto loc_8213994C;
loc_82139994:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8213999C;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// bl 0x82130588
	ctx.lr = 0x821399BC;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_821398A8) {
	__imp__sub_821398A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821399DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821399DC) {
	__imp__sub_821399DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821399E0) {
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
	ctx.lr = 0x821399E8;
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x82137a08
	ctx.lr = 0x82139A04;
	sub_82137A08(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r30,r11,5608
	r30.s64 = r11.s64 + 5608;
	// addi r5,r10,10372
	ctx.r5.s64 = ctx.r10.s64 + 10372;
	// addi r7,r1,336
	ctx.r7.s64 = ctx.r1.s64 + 336;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// bl 0x82137a08
	ctx.lr = 0x82139A28;
	sub_82137A08(ctx, base);
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x823db6d0
	ctx.lr = 0x82139A34;
	sub_823DB6D0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82139bd8
	if (cr6.eq) goto loc_82139BD8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,10364
	ctx.r4.s64 = r11.s64 + 10364;
	// bl 0x823db730
	ctx.lr = 0x82139A4C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82139a6c
	if (cr6.eq) goto loc_82139A6C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,10356
	ctx.r4.s64 = r11.s64 + 10356;
	// bl 0x823db730
	ctx.lr = 0x82139A64;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82139bd8
	if (!cr6.eq) goto loc_82139BD8;
loc_82139A6C:
	// li r3,1144
	ctx.r3.s64 = 1144;
	// bl 0x82130528
	ctx.lr = 0x82139A74;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82139a88
	if (cr6.eq) goto loc_82139A88;
	// bl 0x821cd750
	ctx.lr = 0x82139A80;
	sub_821CD750(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x82139a8c
	goto loc_82139A8C;
loc_82139A88:
	// li r29,0
	r29.s64 = 0;
loc_82139A8C:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cd7a0
	ctx.lr = 0x82139AA4;
	sub_821CD7A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82139bb8
	if (cr6.eq) goto loc_82139BB8;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r7,r10,3998
	ctx.r7.s64 = ctx.r10.s64 + 3998;
	// lwz r6,28(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca2f8
	ctx.lr = 0x82139ADC;
	sub_821CA2F8(ctx, base);
	// addi r11,r1,336
	r11.s64 = ctx.r1.s64 + 336;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
loc_82139AE4:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82139ae4
	if (!cr6.eq) goto loc_82139AE4;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_82139AF8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x82139af8
	if (!cr6.eq) goto loc_82139AF8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r10,10352
	ctx.r10.s64 = ctx.r10.s64 + 10352;
loc_82139B1C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82139b1c
	if (!cr6.eq) goto loc_82139B1C;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82139B30:
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
	// bne cr6,0x82139b30
	if (!cr6.eq) goto loc_82139B30;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cb9d8
	ctx.lr = 0x82139B58;
	sub_821CB9D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82139b78
	if (!cr6.eq) goto loc_82139B78;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// addi r3,r11,10304
	ctx.r3.s64 = r11.s64 + 10304;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82130000
	ctx.lr = 0x82139B78;
	sub_82130000(ctx, base);
loc_82139B78:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821378b8
	ctx.lr = 0x82139B80;
	sub_821378B8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,6036
	ctx.r3.s64 = r11.s64 + 6036;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8262e420
	ctx.lr = 0x82139B94;
	sub_8262E420(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r9,5988
	ctx.r3.s64 = ctx.r9.s64 + 5988;
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
	// bl 0x8262e420
	ctx.lr = 0x82139BAC;
	sub_8262E420(ctx, base);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// b 0x823d924c
	return;
loc_82139BB8:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82139bd8
	if (cr6.eq) goto loc_82139BD8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82139BD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82139BD8:
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_821399E0) {
	__imp__sub_821399E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82139BE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82139BE8;
	// stwu r1,-576(r1)
	ea = -576 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,6016
	ctx.r10.s64 = r11.s64 + 6016;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213a008
	if (!cr6.eq) goto loc_8213A008;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r21,r11,6036
	r21.s64 = r11.s64 + 6036;
	// lwz r3,6036(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6036);
	// bl 0x82130588
	ctx.lr = 0x82139C10;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r21)
	PPC_STORE_U32(r21.u32 + 0, r11.u32);
	// sth r10,4(r21)
	PPC_STORE_U16(r21.u32 + 4, ctx.r10.u16);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// sth r9,6(r21)
	PPC_STORE_U16(r21.u32 + 6, ctx.r9.u16);
	// addi r20,r11,5988
	r20.s64 = r11.s64 + 5988;
	// lwz r3,5988(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 5988);
	// bl 0x82130588
	ctx.lr = 0x82139C38;
	sub_82130588(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,5996
	ctx.r9.s64 = ctx.r10.s64 + 5996;
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,6(r20)
	PPC_STORE_U16(r20.u32 + 6, r11.u16);
	// sth r10,4(r20)
	PPC_STORE_U16(r20.u32 + 4, ctx.r10.u16);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82139c6c
	if (cr6.eq) goto loc_82139C6C;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x82139c70
	goto loc_82139C70;
loc_82139C6C:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82139C70:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r18,r11,5608
	r18.s64 = r11.s64 + 5608;
	// lwz r11,40(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82139fdc
	if (!cr6.eq) goto loc_82139FDC;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82139fdc
	if (!cr6.eq) goto loc_82139FDC;
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// clrlwi r30,r9,24
	r30.u64 = ctx.r9.u32 & 0xFF;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82139cec
	if (!cr6.eq) goto loc_82139CEC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82139cc0
	if (!cr6.eq) goto loc_82139CC0;
	// bl 0x821311a0
	ctx.lr = 0x82139CC0;
	sub_821311A0(ctx, base);
loc_82139CC0:
	// bl 0x821c4210
	ctx.lr = 0x82139CC4;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// addi r10,r11,30500
	ctx.r10.s64 = r11.s64 + 30500;
	// lwz r11,30500(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30500);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// bl 0x821c05e8
	ctx.lr = 0x82139CE8;
	sub_821C05E8(ctx, base);
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
loc_82139CEC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,36(r18)
	ctx.r4.u64 = PPC_LOAD_U32(r18.u32 + 36);
	// addi r17,r11,3998
	r17.s64 = r11.s64 + 3998;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// bl 0x821c0210
	ctx.lr = 0x82139D00;
	sub_821C0210(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// bne cr6,0x82139d34
	if (!cr6.eq) goto loc_82139D34;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8213a008
	if (!cr6.eq) goto loc_8213A008;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfc50
	ctx.lr = 0x82139D1C;
	sub_821BFC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213a008
	if (cr6.eq) goto loc_8213A008;
	// bl 0x82131720
	ctx.lr = 0x82139D2C;
	sub_82131720(ctx, base);
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// b 0x823d9210
	return;
loc_82139D34:
	// lwz r11,0(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// lwz r25,28(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82139f80
	if (cr6.eq) goto loc_82139F80;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r16,r6,10404
	r16.s64 = ctx.r6.s64 + 10404;
	// addi r15,r5,10304
	r15.s64 = ctx.r5.s64 + 10304;
	// addi r28,r4,10352
	r28.s64 = ctx.r4.s64 + 10352;
	// addi r27,r3,10372
	r27.s64 = ctx.r3.s64 + 10372;
	// addi r19,r7,10396
	r19.s64 = ctx.r7.s64 + 10396;
	// addi r24,r8,10388
	r24.s64 = ctx.r8.s64 + 10388;
	// addi r23,r9,10380
	r23.s64 = ctx.r9.s64 + 10380;
	// addi r22,r10,9848
	r22.s64 = ctx.r10.s64 + 9848;
	// addi r26,r11,30576
	r26.s64 = r11.s64 + 30576;
loc_82139D8C:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82139D9C;
	sub_821C82A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82139DB0;
	sub_821C82A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82139DC4;
	sub_821C82A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82139f68
	if (cr6.eq) goto loc_82139F68;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82139f68
	if (cr6.eq) goto loc_82139F68;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82139f68
	if (cr6.eq) goto loc_82139F68;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82139df4
	if (cr6.eq) goto loc_82139DF4;
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// b 0x82139df8
	goto loc_82139DF8;
loc_82139DF4:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82139DF8:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82139e0c
	if (cr6.eq) goto loc_82139E0C;
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// b 0x82139e10
	goto loc_82139E10;
loc_82139E0C:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82139E10:
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// lwz r6,28(r18)
	ctx.r6.u64 = PPC_LOAD_U32(r18.u32 + 28);
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82139E24;
	sub_82137A08(ctx, base);
	// li r3,1144
	ctx.r3.s64 = 1144;
	// bl 0x82130528
	ctx.lr = 0x82139E2C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82139e40
	if (cr6.eq) goto loc_82139E40;
	// bl 0x821cd750
	ctx.lr = 0x82139E38;
	sub_821CD750(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82139e44
	goto loc_82139E44;
loc_82139E40:
	// li r31,0
	r31.s64 = 0;
loc_82139E44:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cd7a0
	ctx.lr = 0x82139E5C;
	sub_821CD7A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82139f44
	if (cr6.eq) goto loc_82139F44;
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82139e7c
	if (cr6.eq) goto loc_82139E7C;
	// lwz r7,32(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// b 0x82139e80
	goto loc_82139E80;
loc_82139E7C:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82139E80:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r6,28(r18)
	ctx.r6.u64 = PPC_LOAD_U32(r18.u32 + 28);
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82139E94;
	sub_82137A08(ctx, base);
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x821ca2f8
	ctx.lr = 0x82139EB0;
	sub_821CA2F8(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
loc_82139EB8:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82139eb8
	if (!cr6.eq) goto loc_82139EB8;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_82139ECC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x82139ecc
	if (!cr6.eq) goto loc_82139ECC;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821cb9d8
	ctx.lr = 0x82139EF4;
	sub_821CB9D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82139f10
	if (!cr6.eq) goto loc_82139F10;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82130000
	ctx.lr = 0x82139F10;
	sub_82130000(ctx, base);
loc_82139F10:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821378b8
	ctx.lr = 0x82139F18;
	sub_821378B8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8262e420
	ctx.lr = 0x82139F28;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// bl 0x8262e420
	ctx.lr = 0x82139F3C;
	sub_8262E420(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// b 0x82139f70
	goto loc_82139F70;
loc_82139F44:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82139f70
	if (cr6.eq) goto loc_82139F70;
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
	ctx.lr = 0x82139F64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82139f70
	goto loc_82139F70;
loc_82139F68:
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x82130000
	ctx.lr = 0x82139F70;
	sub_82130000(ctx, base);
loc_82139F70:
	// lwz r25,24(r25)
	r25.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x82139d8c
	if (!cr6.eq) goto loc_82139D8C;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82139F80:
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x821c5c70
	ctx.lr = 0x82139F88;
	sub_821C5C70(ctx, base);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x82130588
	ctx.lr = 0x82139F90;
	sub_82130588(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8213a008
	if (!cr6.eq) goto loc_8213A008;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r3,2828(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2828);
	// bl 0x821bfc50
	ctx.lr = 0x82139FA4;
	sub_821BFC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213a008
	if (cr6.eq) goto loc_8213A008;
	// lwz r31,2828(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 2828);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82139fcc
	if (cr6.eq) goto loc_82139FCC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c0688
	ctx.lr = 0x82139FC4;
	sub_821C0688(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82139FCC;
	sub_82130588(ctx, base);
loc_82139FCC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r30)
	PPC_STORE_U32(r30.u32 + 2828, r11.u32);
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// b 0x823d9210
	return;
loc_82139FDC:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82139fec
	if (cr6.eq) goto loc_82139FEC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82139FEC:
	// lis r10,-32236
	ctx.r10.s64 = -2112618496;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// addi r5,r10,-26144
	ctx.r5.s64 = ctx.r10.s64 + -26144;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// bl 0x821ca7a8
	ctx.lr = 0x8213A008;
	sub_821CA7A8(ctx, base);
loc_8213A008:
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_82139BE0) {
	__imp__sub_82139BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A010) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,6052(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6052);
	// bl 0x823ea908
	ctx.lr = 0x8213A02C;
	sub_823EA908(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,6056(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6056);
	// bl 0x823ea908
	ctx.lr = 0x8213A038;
	sub_823EA908(ctx, base);
	// bl 0x823ea808
	ctx.lr = 0x8213A03C;
	sub_823EA808(ctx, base);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lwz r3,6244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 6244);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213a060
	if (cr6.eq) goto loc_8213A060;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213A060:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r4,6232(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 6232);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213a088
	if (cr6.eq) goto loc_8213A088;
	// lwz r3,6240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6240);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A088;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213A088:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,6252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6252);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213a0ac
	if (cr6.eq) goto loc_8213A0AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A0AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213A0AC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,6236(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 6236);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213a0d0
	if (cr6.eq) goto loc_8213A0D0;
	// lwz r3,6240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6240);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A0D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213A0D0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213A010) {
	__imp__sub_8213A010(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A0E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,6049(r11)
	PPC_STORE_U8(r11.u32 + 6049, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213A0E8) {
	__imp__sub_8213A0E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A0F8) {
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
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x823ea988
	ctx.lr = 0x8213A13C;
	sub_823EA988(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x8213a150
	if (!cr6.lt) goto loc_8213A150;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// b 0x8213a15c
	goto loc_8213A15C;
loc_8213A150:
	// lbz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_8213A15C:
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

PPC_WEAK_FUNC(sub_8213A0F8) {
	__imp__sub_8213A0F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213A174) {
	__imp__sub_8213A174(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8213A180;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8213a1a0
	if (!cr6.eq) goto loc_8213A1A0;
loc_8213A194:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9228
	return;
loc_8213A1A0:
	// lwz r24,40(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// mr r20,r30
	r20.u64 = r30.u64;
	// cmplwi cr6,r24,8
	cr6.compare<uint32_t>(r24.u32, 8, xer);
	// bgt cr6,0x8213a194
	if (cr6.gt) goto loc_8213A194;
	// lbz r9,0(r21)
	ctx.r9.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// subfic r8,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// addi r22,r11,6060
	r22.s64 = r11.s64 + 6060;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// li r25,0
	r25.s64 = 0;
	// clrlwi r11,r7,29
	r11.u64 = ctx.r7.u32 & 0x7;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// rlwinm r11,r11,0,31,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// addi r23,r10,6096
	r23.s64 = ctx.r10.s64 + 6096;
	// addi r26,r11,1
	r26.s64 = r11.s64 + 1;
	// beq cr6,0x8213a234
	if (cr6.eq) goto loc_8213A234;
	// mr r28,r22
	r28.u64 = r22.u64;
	// addi r31,r23,8
	r31.s64 = r23.s64 + 8;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_8213A1F0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r27,r31,-8
	r27.s64 = r31.s64 + -8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r26,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r26.u8);
	// stb r3,-8(r31)
	PPC_STORE_U8(r31.u32 + -8, ctx.r3.u8);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stw r25,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r25.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// stw r27,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r27.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bne 0x8213a1f0
	if (!cr0.eq) goto loc_8213A1F0;
loc_8213A234:
	// li r5,27
	ctx.r5.s64 = 27;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,225
	ctx.r3.s64 = ctx.r1.s64 + 225;
	// bl 0x823d9890
	ctx.lr = 0x8213A244;
	sub_823D9890(ctx, base);
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lbz r8,0(r23)
	ctx.r8.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// li r31,5
	r31.s64 = 5;
	// stb r26,225(r1)
	PPC_STORE_U8(ctx.r1.u32 + 225, r26.u8);
	// ori r7,r9,48000
	ctx.r7.u64 = ctx.r9.u64 | 48000;
	// stb r25,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, r25.u8);
	// stb r31,232(r1)
	PPC_STORE_U8(ctx.r1.u32 + 232, r31.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r7.u32);
	// stb r10,234(r1)
	PPC_STORE_U8(ctx.r1.u32 + 234, ctx.r10.u8);
	// beq cr6,0x8213a288
	if (cr6.eq) goto loc_8213A288;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r9,r10,6224
	ctx.r9.s64 = ctx.r10.s64 + 6224;
	// stw r9,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r9.u32);
	// stb r24,6224(r10)
	PPC_STORE_U8(ctx.r10.u32 + 6224, r24.u8);
	// stw r22,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r22.u32);
loc_8213A288:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x823eaaf0
	ctx.lr = 0x8213A294;
	sub_823EAAF0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8213a194
	if (cr6.lt) goto loc_8213A194;
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8213a2c0
	if (cr6.eq) goto loc_8213A2C0;
	// mr r11,r24
	r11.u64 = r24.u64;
loc_8213A2AC:
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r9,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r9.u32);
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bne 0x8213a2ac
	if (!cr0.eq) goto loc_8213A2AC;
loc_8213A2C0:
	// lbz r7,0(r21)
	ctx.r7.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// cmplwi cr6,r7,5
	cr6.compare<uint32_t>(ctx.r7.u32, 5, xer);
	// bne cr6,0x8213a3e0
	if (!cr6.eq) goto loc_8213A3E0;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stb r25,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r25.u8);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stb r25,129(r1)
	PPC_STORE_U8(ctx.r1.u32 + 129, r25.u8);
	// li r11,2
	r11.s64 = 2;
	// stb r31,168(r1)
	PPC_STORE_U8(ctx.r1.u32 + 168, r31.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r31,169(r1)
	PPC_STORE_U8(ctx.r1.u32 + 169, r31.u8);
	// li r8,3
	ctx.r8.s64 = 3;
	// stb r11,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, r11.u8);
	// lfs f0,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r9,4
	ctx.r9.s64 = 4;
	// lfs f13,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r7,r1,184
	ctx.r7.s64 = ctx.r1.s64 + 184;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stw r3,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r3.u32);
	// li r30,6
	r30.s64 = 6;
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r29,r1,128
	r29.s64 = ctx.r1.s64 + 128;
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r28,r1,96
	r28.s64 = ctx.r1.s64 + 96;
	// stfs f0,164(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r27,r1,112
	r27.s64 = ctx.r1.s64 + 112;
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stb r10,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, ctx.r10.u8);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stb r10,137(r1)
	PPC_STORE_U8(ctx.r1.u32 + 137, ctx.r10.u8);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r11,145(r1)
	PPC_STORE_U8(ctx.r1.u32 + 145, r11.u8);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stb r8,152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 152, ctx.r8.u8);
	// stb r8,153(r1)
	PPC_STORE_U8(ctx.r1.u32 + 153, ctx.r8.u8);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// stb r9,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, ctx.r9.u8);
	// stb r9,161(r1)
	PPC_STORE_U8(ctx.r1.u32 + 161, ctx.r9.u8);
	// stb r9,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r9.u8);
	// stb r25,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, r25.u8);
	// stb r31,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r31.u8);
	// stb r10,105(r1)
	PPC_STORE_U8(ctx.r1.u32 + 105, ctx.r10.u8);
	// stb r11,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r11.u8);
	// stb r25,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, r25.u8);
	// stb r11,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r11.u8);
	// stb r10,121(r1)
	PPC_STORE_U8(ctx.r1.u32 + 121, ctx.r10.u8);
	// stb r8,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, ctx.r8.u8);
	// stw r5,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r5.u32);
	// stw r25,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, r25.u32);
	// stw r7,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r7.u32);
	// stw r25,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r25.u32);
	// stw r6,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r6.u32);
	// stw r25,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r25.u32);
	// stb r30,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r30.u8);
	// stw r29,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r29.u32);
	// stb r11,184(r1)
	PPC_STORE_U8(ctx.r1.u32 + 184, r11.u8);
	// stw r28,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r28.u32);
	// stb r11,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, r11.u8);
	// stw r27,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r27.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x823ea218
	ctx.lr = 0x8213A3C8;
	sub_823EA218(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,6256(r5)
	PPC_STORE_U32(ctx.r5.u32 + 6256, r11.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9228
	return;
loc_8213A3E0:
	// lbz r8,1(r21)
	ctx.r8.u64 = PPC_LOAD_U8(r21.u32 + 1);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// mr r11,r25
	r11.u64 = r25.u64;
	// stw r10,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r10.u32);
	// addi r10,r1,129
	ctx.r10.s64 = ctx.r1.s64 + 129;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stb r8,200(r1)
	PPC_STORE_U8(ctx.r1.u32 + 200, ctx.r8.u8);
loc_8213A400:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// beq cr6,0x8213a410
	if (cr6.eq) goto loc_8213A410;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
loc_8213A410:
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// stfs f0,3(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 3, temp.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,-1(r10)
	PPC_STORE_U8(ctx.r10.u32 + -1, ctx.r9.u8);
	// stb r6,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r6.u8);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// blt cr6,0x8213a400
	if (cr6.lt) goto loc_8213A400;
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// li r11,6
	r11.s64 = 6;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stb r11,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r11.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// beq cr6,0x8213a498
	if (cr6.eq) goto loc_8213A498;
	// lwz r8,8(r21)
	ctx.r8.u64 = PPC_LOAD_U32(r21.u32 + 8);
	// addi r11,r1,256
	r11.s64 = ctx.r1.s64 + 256;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_8213A458:
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// beq cr6,0x8213a484
	if (cr6.eq) goto loc_8213A484;
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8213a484
	if (cr6.eq) goto loc_8213A484;
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r6,32(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// b 0x8213a488
	goto loc_8213A488;
loc_8213A484:
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
loc_8213A488:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8213a458
	if (!cr0.eq) goto loc_8213A458;
loc_8213A498:
	// addi r4,r1,200
	ctx.r4.s64 = ctx.r1.s64 + 200;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x823ea218
	ctx.lr = 0x8213A4A4;
	sub_823EA218(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_8213A178) {
	__imp__sub_8213A178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A4B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823ea140
	sub_823EA140(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213A4B0) {
	__imp__sub_8213A4B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A4C0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213A4C0) {
	__imp__sub_8213A4C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213A4C4) {
	__imp__sub_8213A4C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A4C8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8213A4D0;
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r10,6256(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6256);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x8213a5f8
	if (cr6.eq) goto loc_8213A5F8;
	// lbz r11,112(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r26,0
	r26.s64 = 0;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// beq cr6,0x8213a5f0
	if (cr6.eq) goto loc_8213A5F0;
	// mr r11,r26
	r11.u64 = r26.u64;
	// li r27,6
	r27.s64 = 6;
	// li r28,1
	r28.s64 = 1;
	// li r29,2
	r29.s64 = 2;
	// li r30,3
	r30.s64 = 3;
	// li r31,4
	r31.s64 = 4;
	// li r5,5
	ctx.r5.s64 = 5;
loc_8213A52C:
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r24,r1,96
	r24.s64 = ctx.r1.s64 + 96;
	// add r25,r11,r8
	r25.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,384
	ctx.r8.s64 = ctx.r1.s64 + 384;
	// rlwinm r23,r11,2,0,29
	r23.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stbx r9,r10,r24
	PPC_STORE_U8(ctx.r10.u32 + r24.u32, ctx.r9.u8);
	// addi r9,r1,100
	ctx.r9.s64 = ctx.r1.s64 + 100;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r24,r1,144
	r24.s64 = ctx.r1.s64 + 144;
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// lfsx f0,r23,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// stb r27,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r27.u8);
	// addi r23,r1,148
	r23.s64 = ctx.r1.s64 + 148;
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
	// rlwinm r21,r7,4,0,27
	r21.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r20,r1,152
	r20.s64 = ctx.r1.s64 + 152;
	// addi r8,r1,156
	ctx.r8.s64 = ctx.r1.s64 + 156;
	// addi r19,r1,164
	r19.s64 = ctx.r1.s64 + 164;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r22,r11,1
	r22.s64 = r11.s64 + 1;
	// stfsx f0,r21,r23
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + r23.u32, temp.u32);
	// rlwinm r11,r25,4,0,27
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 4) & 0xFFFFFFF0;
	// stbx r26,r21,r24
	PPC_STORE_U8(r21.u32 + r24.u32, r26.u8);
	// stfsx f0,r21,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + ctx.r8.u32, temp.u32);
	// stbx r28,r21,r20
	PPC_STORE_U8(r21.u32 + r20.u32, r28.u8);
	// stfsx f0,r21,r19
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + r19.u32, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r25,r1,388
	r25.s64 = ctx.r1.s64 + 388;
	// stbx r29,r21,r9
	PPC_STORE_U8(r21.u32 + ctx.r9.u32, r29.u8);
	// addi r24,r1,168
	r24.s64 = ctx.r1.s64 + 168;
	// addi r23,r1,172
	r23.s64 = ctx.r1.s64 + 172;
	// addi r20,r1,176
	r20.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,180
	ctx.r8.s64 = ctx.r1.s64 + 180;
	// addi r18,r1,184
	r18.s64 = ctx.r1.s64 + 184;
	// addi r19,r1,188
	r19.s64 = ctx.r1.s64 + 188;
	// stbx r30,r21,r24
	PPC_STORE_U8(r21.u32 + r24.u32, r30.u8);
	// clrlwi r9,r22,24
	ctx.r9.u64 = r22.u32 & 0xFF;
	// stfsx f0,r21,r23
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + r23.u32, temp.u32);
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// stbx r31,r21,r20
	PPC_STORE_U8(r21.u32 + r20.u32, r31.u8);
	// stfsx f0,r21,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + ctx.r8.u32, temp.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stwx r7,r10,r25
	PPC_STORE_U32(ctx.r10.u32 + r25.u32, ctx.r7.u32);
	// cmplw cr6,r9,r6
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, xer);
	// stfsx f0,r21,r19
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + r19.u32, temp.u32);
	// stbx r5,r21,r18
	PPC_STORE_U8(r21.u32 + r18.u32, ctx.r5.u8);
	// blt cr6,0x8213a52c
	if (cr6.lt) goto loc_8213A52C;
loc_8213A5F0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823ea270
	ctx.lr = 0x8213A5F8;
	sub_823EA270(ctx, base);
loc_8213A5F8:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_8213A4C8) {
	__imp__sub_8213A4C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A600) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,6256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6256);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213a79c
	if (cr6.eq) goto loc_8213A79C;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// li r6,3
	ctx.r6.s64 = 3;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stb r6,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r6.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// lwz r8,5592(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5592);
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stw r4,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r4.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r10.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r6,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r6.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r9,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, ctx.r9.u8);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// stb r11,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r11.u8);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stb r7,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, ctx.r7.u8);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stb r5,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r5.u8);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// stb r9,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r9.u8);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stb r9,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r9.u8);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// bne cr6,0x8213a728
	if (!cr6.eq) goto loc_8213A728;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lbz r8,6156(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6156);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8213a728
	if (cr6.eq) goto loc_8213A728;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r11,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r11.u8);
	// stb r7,184(r1)
	PPC_STORE_U8(ctx.r1.u32 + 184, ctx.r7.u8);
	// addi r8,r1,196
	ctx.r8.s64 = ctx.r1.s64 + 196;
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8213A6C8:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r10,-4(r8)
	PPC_STORE_U8(ctx.r8.u32 + -4, ctx.r10.u8);
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// cmplwi cr6,r9,6
	cr6.compare<uint32_t>(ctx.r9.u32, 6, xer);
	// blt cr6,0x8213a6c8
	if (cr6.lt) goto loc_8213A6C8;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lfs f0,10788(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 10788);
	f0.f64 = double(temp.f32);
loc_8213A6F0:
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// addi r9,r1,164
	ctx.r9.s64 = ctx.r1.s64 + 164;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// stbx r6,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r6.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stfsx f0,r11,r7
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, temp.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stb r6,-4(r9)
	PPC_STORE_U8(ctx.r9.u32 + -4, ctx.r6.u8);
	// blt cr6,0x8213a6f0
	if (cr6.lt) goto loc_8213A6F0;
	// b 0x8213a794
	goto loc_8213A794;
loc_8213A728:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// addi r8,r1,180
	ctx.r8.s64 = ctx.r1.s64 + 180;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_8213A738:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r10,-4(r8)
	PPC_STORE_U8(ctx.r8.u32 + -4, ctx.r10.u8);
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// cmplwi cr6,r9,6
	cr6.compare<uint32_t>(ctx.r9.u32, 6, xer);
	// blt cr6,0x8213a738
	if (cr6.lt) goto loc_8213A738;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8213A760:
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// addi r9,r1,164
	ctx.r9.s64 = ctx.r1.s64 + 164;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// stbx r6,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r6.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stfsx f0,r11,r7
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, temp.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stb r6,-4(r9)
	PPC_STORE_U8(ctx.r9.u32 + -4, ctx.r6.u8);
	// blt cr6,0x8213a760
	if (cr6.lt) goto loc_8213A760;
loc_8213A794:
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// bl 0x823ea270
	ctx.lr = 0x8213A79C;
	sub_823EA270(ctx, base);
loc_8213A79C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213A600) {
	__imp__sub_8213A600(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213A7AC) {
	__imp__sub_8213A7AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A7B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x823eaa10
	sub_823EAA10(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213A7B0) {
	__imp__sub_8213A7B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A7B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213A7B4) {
	__imp__sub_8213A7B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A7B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,6248(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 6248);
	// addi r11,r11,10780
	r11.s64 = r11.s64 + 10780;
loc_8213A7D4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// beq cr6,0x8213a808
	if (cr6.eq) goto loc_8213A808;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// blt cr6,0x8213a7d4
	if (cr6.lt) goto loc_8213A7D4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8213A808:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1488
	ctx.r4.s64 = 1488;
	// lwz r3,6252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6252);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8213A7B8) {
	__imp__sub_8213A7B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A828) {
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
	// lis r30,-32125
	r30.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,6252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6252);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A85C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213a874
	if (cr6.eq) goto loc_8213A874;
	// lwz r3,6252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6252);
	// b 0x8213a8a0
	goto loc_8213A8A0;
loc_8213A874:
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r3,6248(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6248);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213a8b0
	if (cr6.eq) goto loc_8213A8B0;
	// lwz r3,6248(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6248);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
loc_8213A8A0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A8B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213A8B0:
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

PPC_WEAK_FUNC(sub_8213A828) {
	__imp__sub_8213A828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A8C8) {
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
	// lis r30,-32125
	r30.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,6252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6252);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A8FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213a924
	if (cr6.eq) goto loc_8213A924;
	// lwz r3,6252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6252);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8213a968
	goto loc_8213A968;
loc_8213A924:
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r3,6248(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6248);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A93C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213a964
	if (cr6.eq) goto loc_8213A964;
	// lwz r3,6248(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6248);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213A960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8213a968
	goto loc_8213A968;
loc_8213A964:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213A968:
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

PPC_WEAK_FUNC(sub_8213A8C8) {
	__imp__sub_8213A8C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,6240(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 6240);
	// addi r11,r11,10776
	r11.s64 = r11.s64 + 10776;
loc_8213A99C:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// beq cr6,0x8213a9d0
	if (cr6.eq) goto loc_8213A9D0;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x8213a99c
	if (cr6.lt) goto loc_8213A99C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8213A9D0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,8320
	ctx.r4.s64 = 8320;
	// lwz r3,6244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 6244);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8213A980) {
	__imp__sub_8213A980(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213A9F0) {
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
	// lis r30,-32125
	r30.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,6244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6244);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213AA24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213aa3c
	if (cr6.eq) goto loc_8213AA3C;
	// lwz r3,6244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6244);
	// b 0x8213aa68
	goto loc_8213AA68;
loc_8213AA3C:
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r3,6240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6240);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213AA54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213aa78
	if (cr6.eq) goto loc_8213AA78;
	// lwz r3,6240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6240);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
loc_8213AA68:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213AA78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213AA78:
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

PPC_WEAK_FUNC(sub_8213A9F0) {
	__imp__sub_8213A9F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213AA90) {
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
	// lis r30,-32125
	r30.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,6244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6244);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213AAC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213aaec
	if (cr6.eq) goto loc_8213AAEC;
	// lwz r3,6244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6244);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213AAE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8213ab30
	goto loc_8213AB30;
loc_8213AAEC:
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r3,6240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6240);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213AB04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213ab2c
	if (cr6.eq) goto loc_8213AB2C;
	// lwz r3,6240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6240);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213AB28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8213ab30
	goto loc_8213AB30;
loc_8213AB2C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213AB30:
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

PPC_WEAK_FUNC(sub_8213AA90) {
	__imp__sub_8213AA90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213AB48) {
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
	// bl 0x8213a600
	ctx.lr = 0x8213AB58;
	sub_8213A600(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,6049(r11)
	PPC_STORE_U8(r11.u32 + 6049, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213AB48) {
	__imp__sub_8213AB48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213AB74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213AB74) {
	__imp__sub_8213AB74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213AB78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x8213AB80;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32125
	r29.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r31,r11,5608
	r31.s64 = r11.s64 + 5608;
	// stw r3,6240(r29)
	PPC_STORE_U32(r29.u32 + 6240, ctx.r3.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stw r4,6248(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6248, ctx.r4.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulli r4,r11,8320
	ctx.r4.s64 = r11.s64 * 8320;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213ABBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,6232(r30)
	PPC_STORE_U32(r30.u32 + 6232, ctx.r3.u32);
	// bne cr6,0x8213abd8
	if (!cr6.eq) goto loc_8213ABD8;
loc_8213ABCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_8213ABD8:
	// li r3,2136
	ctx.r3.s64 = 2136;
	// bl 0x82130528
	ctx.lr = 0x8213ABE0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213ad84
	if (cr6.eq) goto loc_8213AD84;
	// li r5,8320
	ctx.r5.s64 = 8320;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,6232(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 6232);
	// bl 0x821cde08
	ctx.lr = 0x8213ABF8;
	sub_821CDE08(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,6244(r11)
	PPC_STORE_U32(r11.u32 + 6244, ctx.r3.u32);
	// beq cr6,0x8213abcc
	if (cr6.eq) goto loc_8213ABCC;
	// lwz r3,6240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 6240);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,16
	ctx.r5.s64 = 16;
	// mulli r4,r11,1488
	ctx.r4.s64 = r11.s64 * 1488;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213AC2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,6236(r30)
	PPC_STORE_U32(r30.u32 + 6236, ctx.r3.u32);
	// beq cr6,0x8213abcc
	if (cr6.eq) goto loc_8213ABCC;
	// li r3,2136
	ctx.r3.s64 = 2136;
	// bl 0x82130528
	ctx.lr = 0x8213AC44;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213ad9c
	if (cr6.eq) goto loc_8213AD9C;
	// li r5,1488
	ctx.r5.s64 = 1488;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,6236(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 6236);
	// bl 0x821cde08
	ctx.lr = 0x8213AC5C;
	sub_821CDE08(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,6252(r11)
	PPC_STORE_U32(r11.u32 + 6252, ctx.r3.u32);
	// beq cr6,0x8213abcc
	if (cr6.eq) goto loc_8213ABCC;
	// li r31,0
	r31.s64 = 0;
	// li r5,11
	ctx.r5.s64 = 11;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r31.u8);
	// addi r3,r1,89
	ctx.r3.s64 = ctx.r1.s64 + 89;
	// bl 0x823d9890
	ctx.lr = 0x8213AC84;
	sub_823D9890(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,6260
	ctx.r9.s64 = r11.s64 + 6260;
	// addi r8,r10,-4552
	ctx.r8.s64 = ctx.r10.s64 + -4552;
	// li r7,6
	ctx.r7.s64 = 6;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stb r7,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, ctx.r7.u8);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// subfic r6,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r6.s64 = 0 - r11.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r5,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stb r4,90(r1)
	PPC_STORE_U8(ctx.r1.u32 + 90, ctx.r4.u8);
	// bl 0x823eaa88
	ctx.lr = 0x8213ACC0;
	sub_823EAA88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8213abcc
	if (cr6.lt) goto loc_8213ABCC;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r11,r31
	r11.u64 = r31.u64;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32236
	ctx.r8.s64 = -2112618496;
	// lis r7,-32236
	ctx.r7.s64 = -2112618496;
	// stw r11,6256(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6256, r11.u32);
	// addi r5,r9,6092
	ctx.r5.s64 = ctx.r9.s64 + 6092;
	// addi r4,r8,27280
	ctx.r4.s64 = ctx.r8.s64 + 27280;
	// addi r3,r7,30216
	ctx.r3.s64 = ctx.r7.s64 + 30216;
	// bl 0x8213a0f8
	ctx.lr = 0x8213ACF0;
	sub_8213A0F8(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lis r11,-32236
	r11.s64 = -2112618496;
	// addi r6,r3,6052
	ctx.r6.s64 = ctx.r3.s64 + 6052;
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,6049(r4)
	PPC_STORE_U8(ctx.r4.u32 + 6049, r31.u8);
	// addi r4,r11,-21688
	ctx.r4.s64 = r11.s64 + -21688;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823ea888
	ctx.lr = 0x8213AD14;
	sub_823EA888(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32236
	ctx.r9.s64 = -2112618496;
	// addi r6,r10,6056
	ctx.r6.s64 = ctx.r10.s64 + 6056;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-24344
	ctx.r4.s64 = ctx.r9.s64 + -24344;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823ea888
	ctx.lr = 0x8213AD30;
	sub_823EA888(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd494
	ctx.lr = 0x8213AD38;
	__imp__XAudioGetSpeakerConfig(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// rlwinm r7,r8,17,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 17) & 0x2;
	// ori r11,r7,1
	r11.u64 = ctx.r7.u64 | 1;
	// lwz r10,5588(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 5588);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8213ad5c
	if (cr6.eq) goto loc_8213AD5C;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// stw r10,5588(r9)
	PPC_STORE_U32(ctx.r9.u32 + 5588, ctx.r10.u32);
loc_8213AD5C:
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwz r8,5592(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 5592);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// beq cr6,0x8213adb8
	if (cr6.eq) goto loc_8213ADB8;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x8213adb4
	if (!cr6.lt) goto loc_8213ADB4;
	// stw r10,5592(r9)
	PPC_STORE_U32(ctx.r9.u32 + 5592, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_8213AD84:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,6244(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6244, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_8213AD9C:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,6252(r10)
	PPC_STORE_U32(ctx.r10.u32 + 6252, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_8213ADB4:
	// stw r11,5592(r9)
	PPC_STORE_U32(ctx.r9.u32 + 5592, r11.u32);
loc_8213ADB8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8213AB78) {
	__imp__sub_8213AB78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213ADC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213ADC4) {
	__imp__sub_8213ADC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213ADC8) {
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
	ctx.lr = 0x8213ADD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r31,44
	r30.s64 = r31.s64 + 44;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82136358
	ctx.lr = 0x8213ADE4;
	sub_82136358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213adfc
	if (!cr6.eq) goto loc_8213ADFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8213ADFC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r31,56
	r29.s64 = r31.s64 + 56;
	// addi r4,r11,10984
	ctx.r4.s64 = r11.s64 + 10984;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821362a8
	ctx.lr = 0x8213AE14;
	sub_821362A8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213ae24
	if (cr6.eq) goto loc_8213AE24;
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
loc_8213AE24:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r31,120
	r29.s64 = r31.s64 + 120;
	// addi r4,r11,10972
	ctx.r4.s64 = r11.s64 + 10972;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821362a8
	ctx.lr = 0x8213AE3C;
	sub_821362A8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213ae4c
	if (cr6.eq) goto loc_8213AE4C;
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
loc_8213AE4C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r31,184
	r29.s64 = r31.s64 + 184;
	// addi r4,r11,10956
	ctx.r4.s64 = r11.s64 + 10956;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821362a8
	ctx.lr = 0x8213AE64;
	sub_821362A8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213ae74
	if (cr6.eq) goto loc_8213AE74;
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
loc_8213AE74:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r31,248
	r29.s64 = r31.s64 + 248;
	// addi r4,r11,10940
	ctx.r4.s64 = r11.s64 + 10940;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821362a8
	ctx.lr = 0x8213AE8C;
	sub_821362A8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213ae9c
	if (cr6.eq) goto loc_8213AE9C;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
loc_8213AE9C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r31,312
	r29.s64 = r31.s64 + 312;
	// addi r4,r11,10924
	ctx.r4.s64 = r11.s64 + 10924;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821362a8
	ctx.lr = 0x8213AEB4;
	sub_821362A8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213aec4
	if (cr6.eq) goto loc_8213AEC4;
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
loc_8213AEC4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,10904
	ctx.r4.s64 = r11.s64 + 10904;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821361b0
	ctx.lr = 0x8213AED8;
	sub_821361B0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r31,4
	ctx.r5.s64 = r31.s64 + 4;
	// addi r4,r10,10884
	ctx.r4.s64 = ctx.r10.s64 + 10884;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821361b0
	ctx.lr = 0x8213AEEC;
	sub_821361B0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r5,r31,8
	ctx.r5.s64 = r31.s64 + 8;
	// addi r4,r9,10852
	ctx.r4.s64 = ctx.r9.s64 + 10852;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821361b0
	ctx.lr = 0x8213AF00;
	sub_821361B0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r5,r31,20
	ctx.r5.s64 = r31.s64 + 20;
	// addi r4,r8,10832
	ctx.r4.s64 = ctx.r8.s64 + 10832;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821361b0
	ctx.lr = 0x8213AF14;
	sub_821361B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821362c0
	ctx.lr = 0x8213AF1C;
	sub_821362C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8213ADC8) {
	__imp__sub_8213ADC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213AF28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r7,-21846
	ctx.r7.s64 = -1431699456;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r8,-1
	ctx.r8.s64 = -1;
	// sth r11,15(r3)
	PPC_STORE_U16(ctx.r3.u32 + 15, r11.u16);
	// li r9,100
	ctx.r9.s64 = 100;
	// stw r10,1(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1, ctx.r10.u32);
	// li r6,255
	ctx.r6.s64 = 255;
	// stw r10,11(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11, ctx.r10.u32);
	// ori r5,r7,43690
	ctx.r5.u64 = ctx.r7.u64 | 43690;
	// sth r11,17(r3)
	PPC_STORE_U16(ctx.r3.u32 + 17, r11.u16);
	// stb r6,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r6.u8);
	// stw r5,5(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5, ctx.r5.u32);
	// sth r11,19(r3)
	PPC_STORE_U16(ctx.r3.u32 + 19, r11.u16);
	// sth r11,21(r3)
	PPC_STORE_U16(ctx.r3.u32 + 21, r11.u16);
	// sth r8,23(r3)
	PPC_STORE_U16(ctx.r3.u32 + 23, ctx.r8.u16);
	// sth r11,25(r3)
	PPC_STORE_U16(ctx.r3.u32 + 25, r11.u16);
	// sth r11,27(r3)
	PPC_STORE_U16(ctx.r3.u32 + 27, r11.u16);
	// sth r11,29(r3)
	PPC_STORE_U16(ctx.r3.u32 + 29, r11.u16);
	// stw r11,31(r3)
	PPC_STORE_U32(ctx.r3.u32 + 31, r11.u32);
	// stw r11,35(r3)
	PPC_STORE_U32(ctx.r3.u32 + 35, r11.u32);
	// sth r11,39(r3)
	PPC_STORE_U16(ctx.r3.u32 + 39, r11.u16);
	// sth r8,41(r3)
	PPC_STORE_U16(ctx.r3.u32 + 41, ctx.r8.u16);
	// sth r9,43(r3)
	PPC_STORE_U16(ctx.r3.u32 + 43, ctx.r9.u16);
	// stw r11,45(r3)
	PPC_STORE_U32(ctx.r3.u32 + 45, r11.u32);
	// stw r11,49(r3)
	PPC_STORE_U32(ctx.r3.u32 + 49, r11.u32);
	// sth r9,53(r3)
	PPC_STORE_U16(ctx.r3.u32 + 53, ctx.r9.u16);
	// stb r11,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, r11.u8);
	// stw r11,57(r3)
	PPC_STORE_U32(ctx.r3.u32 + 57, r11.u32);
	// stw r11,61(r3)
	PPC_STORE_U32(ctx.r3.u32 + 61, r11.u32);
	// stw r11,65(r3)
	PPC_STORE_U32(ctx.r3.u32 + 65, r11.u32);
	// stw r11,69(r3)
	PPC_STORE_U32(ctx.r3.u32 + 69, r11.u32);
	// stw r11,73(r3)
	PPC_STORE_U32(ctx.r3.u32 + 73, r11.u32);
	// stw r11,77(r3)
	PPC_STORE_U32(ctx.r3.u32 + 77, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213AF28) {
	__imp__sub_8213AF28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213AFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213AFB4) {
	__imp__sub_8213AFB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213AFB8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,11340
	ctx.r9.s64 = r11.s64 + 11340;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8213afec
	if (cr6.eq) goto loc_8213AFEC;
	// bl 0x82130588
	ctx.lr = 0x8213AFE8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8213AFEC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213AFB8) {
	__imp__sub_8213AFB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B000) {
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
	ctx.lr = 0x8213B008;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// li r4,208
	ctx.r4.s64 = 208;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213eb00
	ctx.lr = 0x8213B028;
	sub_8213EB00(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8213b060
	if (cr6.eq) goto loc_8213B060;
	// bl 0x82148940
	ctx.lr = 0x8213B038;
	sub_82148940(ctx, base);
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r10,200(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r7,11444(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11444);
	// subf r6,r7,r29
	ctx.r6.s64 = r29.s64 - ctx.r7.s64;
	// divwu r5,r6,r10
	ctx.r5.u32 = ctx.r6.u32 / ctx.r10.u32;
	// stb r5,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r5.u8);
loc_8213B060:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8213B000) {
	__imp__sub_8213B000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B068) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r9.u32);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// lwz r7,16(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r7,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r7.u32);
	// lbz r6,25(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 25);
	// rlwimi r10,r6,3,28,28
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 3) & 0x8) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFF7);
	// stb r10,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r10.u8);
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r4,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r4.u32);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213b0cc
	if (cr6.eq) goto loc_8213B0CC;
	// bl 0x82148ff0
	ctx.lr = 0x8213B0CC;
	sub_82148FF0(ctx, base);
loc_8213B0CC:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r11,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r11.u32);
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

PPC_WEAK_FUNC(sub_8213B068) {
	__imp__sub_8213B068(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213B0EC) {
	__imp__sub_8213B0EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B0F0) {
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
	ctx.lr = 0x8213B0F8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lbz r11,5(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213b124
	if (cr6.eq) goto loc_8213B124;
	// lwz r11,45(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 45);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213b12c
	if (cr6.eq) goto loc_8213B12C;
loc_8213B124:
	// lwz r11,45(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 45);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8213B12C:
	// lbz r11,5(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213b180
	if (cr6.eq) goto loc_8213B180;
	// lbz r11,8(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 8);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213b180
	if (!cr6.eq) goto loc_8213B180;
	// lhz r10,43(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 43);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// addi r11,r11,11360
	r11.s64 = r11.s64 + 11360;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// stfs f9,12(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x8213b1ac
	goto loc_8213B1AC;
loc_8213B180:
	// lhz r10,43(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 43);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// addi r11,r11,11360
	r11.s64 = r11.s64 + 11360;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
loc_8213B1AC:
	// lbz r11,5(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r11,49(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 49);
	// bne cr6,0x8213b20c
	if (!cr6.eq) goto loc_8213B20C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213b214
	if (!cr6.eq) goto loc_8213B214;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r11,7480(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 7480);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8213b200
	if (!cr6.eq) goto loc_8213B200;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r11,7480(r10)
	PPC_STORE_U32(ctx.r10.u32 + 7480, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,11344
	ctx.r3.s64 = ctx.r9.s64 + 11344;
	// bl 0x821c9790
	ctx.lr = 0x8213B1F4;
	sub_821C9790(ctx, base);
	// stw r3,7476(r30)
	PPC_STORE_U32(r30.u32 + 7476, ctx.r3.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// b 0x8213b218
	goto loc_8213B218;
loc_8213B200:
	// lwz r3,7476(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 7476);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// b 0x8213b218
	goto loc_8213B218;
loc_8213B20C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213b218
	if (cr6.eq) goto loc_8213B218;
loc_8213B214:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_8213B218:
	// lbz r11,5(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213b260
	if (cr6.eq) goto loc_8213B260;
	// lbz r11,9(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 9);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213b260
	if (!cr6.eq) goto loc_8213B260;
	// lhz r11,53(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 53);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// stfs f9,8(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// b 0x8213b280
	goto loc_8213B280;
loc_8213B260:
	// lhz r11,53(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 53);
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
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stfs f11,8(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_8213B280:
	// lbz r11,5(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213b2b0
	if (cr6.eq) goto loc_8213B2B0;
	// lbz r11,9(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 9);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213b2b0
	if (!cr6.eq) goto loc_8213B2B0;
	// lbz r11,55(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 55);
	// lbz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// or r9,r11,r10
	ctx.r9.u64 = r11.u64 | ctx.r10.u64;
	// stb r9,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r9.u8);
	// b 0x8213b2b8
	goto loc_8213B2B8;
loc_8213B2B0:
	// lbz r11,55(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 55);
	// stb r11,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r11.u8);
loc_8213B2B8:
	// lbz r11,21(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 21);
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213b2d4
	if (!cr6.eq) goto loc_8213B2D4;
	// lbz r10,56(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 56);
	// rlwimi r11,r10,2,0,29
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 2) & 0xFFFFFFFC) | (r11.u64 & 0xFFFFFFFF00000003);
	// stb r11,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r11.u8);
loc_8213B2D4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8213B0F0) {
	__imp__sub_8213B0F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B2E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// addi r11,r3,15
	r11.s64 = ctx.r3.s64 + 15;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b300
	if (cr6.eq) goto loc_8213B300;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,15(r4)
	PPC_STORE_U16(ctx.r4.u32 + 15, ctx.r10.u16);
loc_8213B300:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b31c
	if (cr6.eq) goto loc_8213B31C;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,17(r4)
	PPC_STORE_U16(ctx.r4.u32 + 17, ctx.r10.u16);
loc_8213B31C:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b338
	if (cr6.eq) goto loc_8213B338;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,19(r4)
	PPC_STORE_U16(ctx.r4.u32 + 19, ctx.r10.u16);
loc_8213B338:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b354
	if (cr6.eq) goto loc_8213B354;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,21(r4)
	PPC_STORE_U16(ctx.r4.u32 + 21, ctx.r10.u16);
loc_8213B354:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b370
	if (cr6.eq) goto loc_8213B370;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,23(r4)
	PPC_STORE_U16(ctx.r4.u32 + 23, ctx.r10.u16);
loc_8213B370:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b38c
	if (cr6.eq) goto loc_8213B38C;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,25(r4)
	PPC_STORE_U16(ctx.r4.u32 + 25, ctx.r10.u16);
loc_8213B38C:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b3a8
	if (cr6.eq) goto loc_8213B3A8;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,27(r4)
	PPC_STORE_U16(ctx.r4.u32 + 27, ctx.r10.u16);
loc_8213B3A8:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b3c4
	if (cr6.eq) goto loc_8213B3C4;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,29(r4)
	PPC_STORE_U16(ctx.r4.u32 + 29, ctx.r10.u16);
loc_8213B3C4:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,23,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b3e0
	if (cr6.eq) goto loc_8213B3E0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,31(r4)
	PPC_STORE_U32(ctx.r4.u32 + 31, ctx.r10.u32);
loc_8213B3E0:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,22,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b3fc
	if (cr6.eq) goto loc_8213B3FC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,35(r4)
	PPC_STORE_U32(ctx.r4.u32 + 35, ctx.r10.u32);
loc_8213B3FC:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,21,21
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b418
	if (cr6.eq) goto loc_8213B418;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,39(r4)
	PPC_STORE_U16(ctx.r4.u32 + 39, ctx.r10.u16);
loc_8213B418:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b434
	if (cr6.eq) goto loc_8213B434;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,41(r4)
	PPC_STORE_U16(ctx.r4.u32 + 41, ctx.r10.u16);
loc_8213B434:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b450
	if (cr6.eq) goto loc_8213B450;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,43(r4)
	PPC_STORE_U16(ctx.r4.u32 + 43, ctx.r10.u16);
loc_8213B450:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,18,18
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b46c
	if (cr6.eq) goto loc_8213B46C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,45(r4)
	PPC_STORE_U32(ctx.r4.u32 + 45, ctx.r10.u32);
loc_8213B46C:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,17,17
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b488
	if (cr6.eq) goto loc_8213B488;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,49(r4)
	PPC_STORE_U32(ctx.r4.u32 + 49, ctx.r10.u32);
loc_8213B488:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b4a4
	if (cr6.eq) goto loc_8213B4A4;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r10,53(r4)
	PPC_STORE_U16(ctx.r4.u32 + 53, ctx.r10.u16);
loc_8213B4A4:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,15,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b4c0
	if (cr6.eq) goto loc_8213B4C0;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,55(r4)
	PPC_STORE_U8(ctx.r4.u32 + 55, ctx.r10.u8);
loc_8213B4C0:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,14,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b4dc
	if (cr6.eq) goto loc_8213B4DC;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,56(r4)
	PPC_STORE_U8(ctx.r4.u32 + 56, ctx.r10.u8);
loc_8213B4DC:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,13,13
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b4f8
	if (cr6.eq) goto loc_8213B4F8;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,57(r4)
	PPC_STORE_U32(ctx.r4.u32 + 57, ctx.r10.u32);
loc_8213B4F8:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,12,12
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b514
	if (cr6.eq) goto loc_8213B514;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,61(r4)
	PPC_STORE_U32(ctx.r4.u32 + 61, ctx.r10.u32);
loc_8213B514:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,11,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b530
	if (cr6.eq) goto loc_8213B530;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,65(r4)
	PPC_STORE_U32(ctx.r4.u32 + 65, ctx.r10.u32);
loc_8213B530:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,10,10
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x200000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b54c
	if (cr6.eq) goto loc_8213B54C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,69(r4)
	PPC_STORE_U32(ctx.r4.u32 + 69, ctx.r10.u32);
loc_8213B54C:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,9,9
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b568
	if (cr6.eq) goto loc_8213B568;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,73(r4)
	PPC_STORE_U32(ctx.r4.u32 + 73, ctx.r10.u32);
loc_8213B568:
	// lwz r10,11(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11);
	// rlwinm r9,r10,0,8,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213b588
	if (cr6.eq) goto loc_8213B588;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r10,77(r4)
	PPC_STORE_U32(ctx.r4.u32 + 77, ctx.r10.u32);
	// blr 
	return;
loc_8213B588:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B2E0) {
	__imp__sub_8213B2E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// b 0x8213e8e0
	sub_8213E8E0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213B590) {
	__imp__sub_8213B590(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213B59C) {
	__imp__sub_8213B59C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B5A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,57(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 57);
	// lbz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 56);
	// ori r9,r11,32
	ctx.r9.u64 = r11.u64 | 32;
	// ori r8,r10,8
	ctx.r8.u64 = ctx.r10.u64 | 8;
	// stb r9,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r9.u8);
	// stb r8,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r8.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B5A0) {
	__imp__sub_8213B5A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213B5BC) {
	__imp__sub_8213B5BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B5C0) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x8213b618
	if (cr6.eq) goto loc_8213B618;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213b610
	if (!cr6.eq) goto loc_8213B610;
	// lbz r11,59(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r10,r10,6488
	ctx.r10.s64 = ctx.r10.s64 + 6488;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213B610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213B610:
	// li r11,3
	r11.s64 = 3;
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
loc_8213B618:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B5C0) {
	__imp__sub_8213B5C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B62C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213B62C) {
	__imp__sub_8213B62C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B630) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,6(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8213b654
	if (cr6.lt) goto loc_8213B654;
	// beq cr6,0x8213b650
	if (cr6.eq) goto loc_8213B650;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8213b654
	if (!cr6.lt) goto loc_8213B654;
	// b 0x8213b5c0
	sub_8213B5C0(ctx, base);
	return;
loc_8213B650:
	// b 0x8213b5c0
	sub_8213B5C0(ctx, base);
	return;
loc_8213B654:
	// li r11,3
	r11.s64 = 3;
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B630) {
	__imp__sub_8213B630(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B660) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9790
	ctx.lr = 0x8213B688;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8213B69C;
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

PPC_WEAK_FUNC(sub_8213B660) {
	__imp__sub_8213B660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213B6B4) {
	__imp__sub_8213B6B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B6B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9790
	ctx.lr = 0x8213B6E8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8213B700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_8213B6B8) {
	__imp__sub_8213B6B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213B71C) {
	__imp__sub_8213B71C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213B744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213b750
	if (cr6.eq) goto loc_8213B750;
	// stfs f31,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
loc_8213B750:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
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

PPC_WEAK_FUNC(sub_8213B720) {
	__imp__sub_8213B720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213B764) {
	__imp__sub_8213B764(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B768) {
	__imp__sub_8213B768(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B770) {
	PPC_FUNC_PROLOGUE();
	// sth r4,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, ctx.r4.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B770) {
	__imp__sub_8213B770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B778) {
	PPC_FUNC_PROLOGUE();
	// sth r4,124(r3)
	PPC_STORE_U16(ctx.r3.u32 + 124, ctx.r4.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B778) {
	__imp__sub_8213B778(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B780) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,92(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,11364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B780) {
	__imp__sub_8213B780(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B7B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,57(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 57);
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// stw r4,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r4.u32);
	// rlwimi r11,r10,3,28,28
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 3) & 0x8) | (r11.u64 & 0xFFFFFFFFFFFFFFF7);
	// stb r11,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B7B0) {
	__imp__sub_8213B7B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B7C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,108(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B7C8) {
	__imp__sub_8213B7C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B7D0) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8213b800
	if (cr6.eq) goto loc_8213B800;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + r11.u64;
	// li r7,255
	ctx.r7.s64 = 255;
	// stb r7,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, ctx.r7.u8);
loc_8213B800:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r7,58(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 58);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// lbz r5,64(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r3,r10,7216
	ctx.r3.s64 = ctx.r10.s64 + 7216;
	// ori r4,r7,4
	ctx.r4.u64 = ctx.r7.u64 | 4;
	// mulli r7,r5,11488
	ctx.r7.s64 = ctx.r5.s64 * 11488;
	// stb r4,58(r11)
	PPC_STORE_U8(r11.u32 + 58, ctx.r4.u8);
	// lwz r31,196(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// lwz r10,232(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r7,11440(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// subf r4,r7,r11
	ctx.r4.s64 = r11.s64 - ctx.r7.s64;
	// divwu r10,r4,r31
	ctx.r10.u32 = ctx.r4.u32 / r31.u32;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r7,r11,60
	ctx.r7.s64 = r11.s64 + 60;
	// clrlwi r5,r10,24
	ctx.r5.u64 = ctx.r10.u32 & 0xFF;
	// twllei r31,0
	// bl 0x8213f4b8
	ctx.lr = 0x8213B84C;
	sub_8213F4B8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B7D0) {
	__imp__sub_8213B7D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B860) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r11,32640
	r11.s64 = 2139095040;
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,0,1,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7F800000;
	// subf r8,r9,r11
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213b900
	if (cr6.eq) goto loc_8213B900;
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213b8f8
	if (cr6.eq) goto loc_8213B8F8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82148c88
	ctx.lr = 0x8213B8E8;
	sub_82148C88(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8213B8F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82148c88
	ctx.lr = 0x8213B900;
	sub_82148C88(ctx, base);
loc_8213B900:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B860) {
	__imp__sub_8213B860(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B910) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8213b954
	if (cr6.eq) goto loc_8213B954;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r8,r11,7216
	ctx.r8.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r11,232(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// lwz r10,196(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r6,11440(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// divwu r11,r5,r10
	r11.u32 = ctx.r5.u32 / ctx.r10.u32;
	// add r10,r4,r3
	ctx.r10.u64 = ctx.r4.u64 + ctx.r3.u64;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r11,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, r11.u8);
	// blr 
	return;
loc_8213B954:
	// add r10,r4,r3
	ctx.r10.u64 = ctx.r4.u64 + ctx.r3.u64;
	// li r11,255
	r11.s64 = 255;
	// stb r11,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B910) {
	__imp__sub_8213B910(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213B964) {
	__imp__sub_8213B964(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213B968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,11376
	ctx.r9.s64 = r11.s64 + 11376;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,255
	ctx.r7.s64 = 255;
	// lbz r6,58(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 58);
	// rlwimi r6,r10,4,0,29
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r10.u32, 4) & 0xFFFFFFFC) | (ctx.r6.u64 & 0xFFFFFFFF00000003);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r11,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, r11.u8);
	// li r5,253
	ctx.r5.s64 = 253;
	// stb r11,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, r11.u8);
	// addi r8,r3,56
	ctx.r8.s64 = ctx.r3.s64 + 56;
	// stb r6,58(r3)
	PPC_STORE_U8(ctx.r3.u32 + 58, ctx.r6.u8);
	// addi r8,r3,60
	ctx.r8.s64 = ctx.r3.s64 + 60;
	// stb r7,64(r3)
	PPC_STORE_U8(ctx.r3.u32 + 64, ctx.r7.u8);
	// addi r9,r3,72
	ctx.r9.s64 = ctx.r3.s64 + 72;
	// sth r10,60(r3)
	PPC_STORE_U16(ctx.r3.u32 + 60, ctx.r10.u16);
	// sth r10,62(r3)
	PPC_STORE_U16(ctx.r3.u32 + 62, ctx.r10.u16);
	// li r8,8
	ctx.r8.s64 = 8;
	// stb r5,65(r3)
	PPC_STORE_U8(ctx.r3.u32 + 65, ctx.r5.u8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8213B9C0:
	// stb r7,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x8213b9c0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8213B9C0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// stw r10,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, ctx.r10.u32);
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// sth r11,126(r3)
	PPC_STORE_U16(ctx.r3.u32 + 126, r11.u16);
	// sth r11,66(r3)
	PPC_STORE_U16(ctx.r3.u32 + 66, r11.u16);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, r11.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, r11.u32);
	// stw r11,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, r11.u32);
	// stb r7,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r7.u8);
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r11.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, r11.u32);
	// stw r11,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, r11.u32);
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r11.u32);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// sth r10,124(r3)
	PPC_STORE_U16(ctx.r3.u32 + 124, ctx.r10.u16);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213B968) {
	__imp__sub_8213B968(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213BA48) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r10,11376
	ctx.r9.s64 = ctx.r10.s64 + 11376;
	// lbz r11,58(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 58);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// rlwinm r8,r11,0,28,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8213baac
	if (!cr6.eq) goto loc_8213BAAC;
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// addi r11,r9,7112
	r11.s64 = ctx.r9.s64 + 7112;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// ori r7,r8,8
	ctx.r7.u64 = ctx.r8.u64 | 8;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// stb r7,58(r31)
	PPC_STORE_U8(r31.u32 + 58, ctx.r7.u8);
	// lwz r5,-4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + -4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8213BAA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8213bb00
	goto loc_8213BB00;
loc_8213BAAC:
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213bb00
	if (cr6.eq) goto loc_8213BB00;
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213bb00
	if (cr6.eq) goto loc_8213BB00;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82130000
	ctx.lr = 0x8213BAF0;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213ec58
	ctx.lr = 0x8213BB00;
	sub_8213EC58(ctx, base);
loc_8213BB00:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,11340
	ctx.r10.s64 = r11.s64 + 11340;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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

PPC_WEAK_FUNC(sub_8213BA48) {
	__imp__sub_8213BA48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213BB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213BB24) {
	__imp__sub_8213BB24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213BB28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213bb60
	if (cr6.eq) goto loc_8213BB60;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213bb64
	goto loc_8213BB64;
loc_8213BB60:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213BB64:
	// b 0x82148a10
	sub_82148A10(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213BB28) {
	__imp__sub_8213BB28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213BB68) {
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
	ctx.lr = 0x8213BB70;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r3,7008
	r29.s64 = ctx.r3.s64 + 7008;
	// addi r28,r4,6696
	r28.s64 = ctx.r4.s64 + 6696;
	// addi r27,r5,7112
	r27.s64 = ctx.r5.s64 + 7112;
	// addi r26,r6,6904
	r26.s64 = ctx.r6.s64 + 6904;
	// addi r25,r7,6280
	r25.s64 = ctx.r7.s64 + 6280;
	// addi r24,r8,6488
	r24.s64 = ctx.r8.s64 + 6488;
	// addi r23,r9,6384
	r23.s64 = ctx.r9.s64 + 6384;
	// addi r22,r10,6592
	r22.s64 = ctx.r10.s64 + 6592;
	// addi r21,r11,6800
	r21.s64 = r11.s64 + 6800;
loc_8213BBC4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// clrlwi r20,r30,24
	r20.u64 = r30.u32 & 0xFF;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82143708
	ctx.lr = 0x8213BBD4;
	sub_82143708(ctx, base);
	// stwx r3,r31,r21
	PPC_STORE_U32(r31.u32 + r21.u32, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x821438c8
	ctx.lr = 0x8213BBE0;
	sub_821438C8(ctx, base);
	// stwx r3,r31,r22
	PPC_STORE_U32(r31.u32 + r22.u32, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82143c48
	ctx.lr = 0x8213BBEC;
	sub_82143C48(ctx, base);
	// stwx r3,r31,r23
	PPC_STORE_U32(r31.u32 + r23.u32, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82143a88
	ctx.lr = 0x8213BBF8;
	sub_82143A88(ctx, base);
	// stwx r3,r31,r24
	PPC_STORE_U32(r31.u32 + r24.u32, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82143e08
	ctx.lr = 0x8213BC04;
	sub_82143E08(ctx, base);
	// stwx r3,r31,r25
	PPC_STORE_U32(r31.u32 + r25.u32, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82143fc8
	ctx.lr = 0x8213BC10;
	sub_82143FC8(ctx, base);
	// stwx r3,r31,r26
	PPC_STORE_U32(r31.u32 + r26.u32, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82144188
	ctx.lr = 0x8213BC1C;
	sub_82144188(ctx, base);
	// stwx r3,r31,r27
	PPC_STORE_U32(r31.u32 + r27.u32, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82144348
	ctx.lr = 0x8213BC28;
	sub_82144348(ctx, base);
	// stwx r3,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82144508
	ctx.lr = 0x8213BC34;
	sub_82144508(ctx, base);
	// stwx r3,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r3.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r31,100
	cr6.compare<uint32_t>(r31.u32, 100, xer);
	// blt cr6,0x8213bbc4
	if (cr6.lt) goto loc_8213BBC4;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_8213BB68) {
	__imp__sub_8213BB68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213BC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213BC4C) {
	__imp__sub_8213BC4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213BC50) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8213BC58;
	// lbz r7,5(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r7,255
	cr6.compare<uint32_t>(ctx.r7.u32, 255, xer);
	// addi r10,r11,7216
	ctx.r10.s64 = r11.s64 + 7216;
	// bne cr6,0x8213bc8c
	if (!cr6.eq) goto loc_8213BC8C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,-1
	ctx.r4.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// li r29,23900
	r29.s64 = 23900;
	// li r28,0
	r28.s64 = 0;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// b 0x8213bccc
	goto loc_8213BCCC;
loc_8213BC8C:
	// lbz r11,64(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,196(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r11,r7
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r7.s32);
	// lwz r9,11440(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lhz r8,52(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 52);
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lhz r7,54(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 54);
	// lfs f12,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lhz r29,48(r11)
	r29.u64 = PPC_LOAD_U16(r11.u32 + 48);
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// lhz r28,50(r11)
	r28.u64 = PPC_LOAD_U16(r11.u32 + 50);
	// extsh r30,r7
	r30.s64 = ctx.r7.s16;
loc_8213BCCC:
	// lbz r31,8(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// rlwinm r11,r31,0,0,24
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213bce4
	if (!cr6.eq) goto loc_8213BCE4;
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
loc_8213BCE4:
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213bcf8
	if (cr6.eq) goto loc_8213BCF8;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
loc_8213BCF8:
	// lfs f13,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lbz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f11,40(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
	// addi r5,r11,26644
	ctx.r5.s64 = r11.s64 + 26644;
	// cmplwi cr6,r6,255
	cr6.compare<uint32_t>(ctx.r6.u32, 255, xer);
	// beq cr6,0x8213bd5c
	if (cr6.eq) goto loc_8213BD5C;
	// lbz r11,64(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r5,4
	ctx.r7.s64 = ctx.r5.s64 + 4;
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r9,r11,r6
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r6.s32);
	// lwz r11,11444(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11444);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lbz r9,199(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// rlwinm r8,r9,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r7,r8,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// rlwinm r9,r7,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lfs f0,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
loc_8213BD5C:
	// stfs f0,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// cmplwi cr6,r6,255
	cr6.compare<uint32_t>(ctx.r6.u32, 255, xer);
	// beq cr6,0x8213bdac
	if (cr6.eq) goto loc_8213BDAC;
	// lbz r11,64(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r5,4
	ctx.r7.s64 = ctx.r5.s64 + 4;
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r9,r11,r6
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r6.s32);
	// lwz r11,11444(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11444);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lbz r9,199(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// rlwinm r8,r9,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r7,r8,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// rlwinm r9,r7,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lhz r9,82(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// b 0x8213bdb0
	goto loc_8213BDB0;
loc_8213BDAC:
	// li r8,-1
	ctx.r8.s64 = -1;
loc_8213BDB0:
	// lhz r9,124(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 124);
	// rlwinm r27,r31,0,26,26
	r27.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x20;
	// li r11,-1
	r11.s64 = -1;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8213bdcc
	if (!cr6.eq) goto loc_8213BDCC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_8213BDCC:
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213be04
	if (cr6.eq) goto loc_8213BE04;
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f13.u64);
	// lwz r9,-60(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// beq cr6,0x8213be00
	if (cr6.eq) goto loc_8213BE00;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x8213be04
	if (cr6.eq) goto loc_8213BE04;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// b 0x8213be04
	goto loc_8213BE04;
loc_8213BE00:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8213BE04:
	// lhz r9,10(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// beq cr6,0x8213be24
	if (cr6.eq) goto loc_8213BE24;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x8213be28
	if (cr6.eq) goto loc_8213BE28;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// b 0x8213be28
	goto loc_8213BE28;
loc_8213BE24:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8213BE28:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8213be40
	if (cr6.eq) goto loc_8213BE40;
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x8213be44
	if (cr6.eq) goto loc_8213BE44;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x8213be44
	goto loc_8213BE44;
loc_8213BE40:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_8213BE44:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8213be5c
	if (cr6.eq) goto loc_8213BE5C;
	// cmpwi cr6,r7,-1
	cr6.compare<int32_t>(ctx.r7.s32, -1, xer);
	// beq cr6,0x8213be60
	if (cr6.eq) goto loc_8213BE60;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// b 0x8213be60
	goto loc_8213BE60;
loc_8213BE5C:
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_8213BE60:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8213be90
	if (cr6.eq) goto loc_8213BE90;
	// lis r7,-18933
	ctx.r7.s64 = -1240793088;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// ori r4,r7,24759
	ctx.r4.u64 = ctx.r7.u64 | 24759;
	// mulhw r9,r11,r4
	ctx.r9.s64 = (int64_t(r11.s32) * int64_t(ctx.r4.s32)) >> 32;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// srawi r11,r11,8
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFF) != 0);
	r11.s64 = r11.s32 >> 8;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// mulli r7,r9,360
	ctx.r7.s64 = ctx.r9.s64 * 360;
	// subf r11,r7,r8
	r11.s64 = ctx.r8.s64 - ctx.r7.s64;
loc_8213BE90:
	// lhz r9,34(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 34);
	// rlwinm r7,r31,0,25,25
	ctx.r7.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x40;
	// sth r11,52(r3)
	PPC_STORE_U16(ctx.r3.u32 + 52, r11.u16);
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8213beac
	if (!cr6.eq) goto loc_8213BEAC;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
loc_8213BEAC:
	// cmplwi cr6,r6,255
	cr6.compare<uint32_t>(ctx.r6.u32, 255, xer);
	// beq cr6,0x8213bef8
	if (cr6.eq) goto loc_8213BEF8;
	// lbz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r4,r5,4
	ctx.r4.s64 = ctx.r5.s64 + 4;
	// lwz r8,232(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mulli r7,r9,11488
	ctx.r7.s64 = ctx.r9.s64 * 11488;
	// lwz r9,200(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// mullw r8,r9,r6
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// lwz r9,11444(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11444);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,199(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 199);
	// rlwinm r7,r8,30,2,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r4,r7,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// rlwinm r8,r4,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lhz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 80);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_8213BEF8:
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213bf24
	if (cr6.eq) goto loc_8213BF24;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,11012(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11012);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f11.u64);
	// lwz r7,-60(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
loc_8213BF24:
	// lhz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// li r9,23900
	ctx.r9.s64 = 23900;
	// cmplwi cr6,r6,255
	cr6.compare<uint32_t>(ctx.r6.u32, 255, xer);
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + r11.u64;
	// sth r7,54(r3)
	PPC_STORE_U16(ctx.r3.u32 + 54, ctx.r7.u16);
	// beq cr6,0x8213bf88
	if (cr6.eq) goto loc_8213BF88;
	// lbz r11,64(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r5,4
	ctx.r7.s64 = ctx.r5.s64 + 4;
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r9,r11,r6
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r6.s32);
	// lwz r11,11444(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 11444);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lbz r9,199(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// rlwinm r8,r9,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r7,r8,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// rlwinm r9,r7,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// lhz r11,88(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 88);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// blt cr6,0x8213bf88
	if (cr6.lt) goto loc_8213BF88;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
loc_8213BF88:
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213bfb0
	if (cr6.eq) goto loc_8213BFB0;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f13.u64);
	// lwz r11,-60(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// blt cr6,0x8213bfb0
	if (cr6.lt) goto loc_8213BFB0;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_8213BFB0:
	// cmplw cr6,r9,r29
	cr6.compare<uint32_t>(ctx.r9.u32, r29.u32, xer);
	// blt cr6,0x8213bfbc
	if (cr6.lt) goto loc_8213BFBC;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
loc_8213BFBC:
	// sth r9,48(r3)
	PPC_STORE_U16(ctx.r3.u32 + 48, ctx.r9.u16);
	// lbz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r7,255
	cr6.compare<uint32_t>(ctx.r7.u32, 255, xer);
	// beq cr6,0x8213c018
	if (cr6.eq) goto loc_8213C018;
	// lbz r11,64(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r6,r5,4
	ctx.r6.s64 = ctx.r5.s64 + 4;
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r11,r7
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r7.s32);
	// lwz r11,11444(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r4,199(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// rlwinm r10,r4,30,2,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFF8;
	// lwzx r9,r10,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lhz r11,90(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 90);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// ble cr6,0x8213c018
	if (!cr6.gt) goto loc_8213C018;
	// sth r11,50(r3)
	PPC_STORE_U16(ctx.r3.u32 + 50, r11.u16);
	// b 0x823d9244
	return;
loc_8213C018:
	// sth r28,50(r3)
	PPC_STORE_U16(ctx.r3.u32 + 50, r28.u16);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8213BC50) {
	__imp__sub_8213BC50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C020) {
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
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213c068
	if (cr6.eq) goto loc_8213C068;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213c06c
	goto loc_8213C06C;
loc_8213C068:
	// li r31,0
	r31.s64 = 0;
loc_8213C06C:
	// lwz r11,116(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213c09c
	if (cr6.eq) goto loc_8213C09C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213C090;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82148c88
	ctx.lr = 0x8213C09C;
	sub_82148C88(ctx, base);
loc_8213C09C:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82148d78
	ctx.lr = 0x8213C0A8;
	sub_82148D78(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213C020) {
	__imp__sub_8213C020(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C0BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213C0BC) {
	__imp__sub_8213C0BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C0C0) {
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
	ctx.lr = 0x8213C0C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213c0f0
	if (!cr6.eq) goto loc_8213C0F0;
	// bl 0x8213c020
	ctx.lr = 0x8213C0F0;
	sub_8213C020(ctx, base);
loc_8213C0F0:
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213c18c
	if (!cr6.eq) goto loc_8213C18C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137488
	ctx.lr = 0x8213C108;
	sub_82137488(ctx, base);
	// extsh r29,r3
	r29.s64 = ctx.r3.s16;
	// li r7,-1
	ctx.r7.s64 = -1;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x8213c128
	if (cr6.eq) goto loc_8213C128;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a18
	ctx.lr = 0x8213C124;
	sub_82144A18(ctx, base);
	// add r7,r3,r30
	ctx.r7.u64 = ctx.r3.u64 + r30.u64;
loc_8213C128:
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213c160
	if (cr6.eq) goto loc_8213C160;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r6,r11,7216
	ctx.r6.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 232);
	// lwz r11,200(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 200);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213c164
	goto loc_8213C164;
loc_8213C160:
	// li r11,0
	r11.s64 = 0;
loc_8213C164:
	// lbz r10,200(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// sth r29,196(r11)
	PPC_STORE_U16(r11.u32 + 196, r29.u16);
	// rlwimi r10,r9,5,26,26
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x20) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFDF);
	// stw r7,188(r11)
	PPC_STORE_U32(r11.u32 + 188, ctx.r7.u32);
	// stb r10,200(r11)
	PPC_STORE_U8(r11.u32 + 200, ctx.r10.u8);
	// lwsync 
	// lbz r7,199(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// ori r6,r7,2
	ctx.r6.u64 = ctx.r7.u64 | 2;
	// stb r6,199(r11)
	PPC_STORE_U8(r11.u32 + 199, ctx.r6.u8);
loc_8213C18C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8213C0C0) {
	__imp__sub_8213C0C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213C194) {
	__imp__sub_8213C194(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C198) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,6(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8213c1c0
	if (!cr6.eq) goto loc_8213C1C0;
	// lbz r11,57(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 57);
	// lbz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 56);
	// ori r9,r11,32
	ctx.r9.u64 = r11.u64 | 32;
	// ori r8,r10,8
	ctx.r8.u64 = ctx.r10.u64 | 8;
	// stb r9,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r9.u8);
	// stb r8,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r8.u8);
	// blr 
	return;
loc_8213C1C0:
	// lbz r11,56(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 56);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stb r10,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213C198) {
	__imp__sub_8213C198(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C1D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213c208
	if (cr6.eq) goto loc_8213C208;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213c20c
	goto loc_8213C20C;
loc_8213C208:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213C20C:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82148db0
	sub_82148DB0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213C1D0) {
	__imp__sub_8213C1D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213C214) {
	__imp__sub_8213C214(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C218) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8213c250
	if (cr6.eq) goto loc_8213C250;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r11,r9
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213c254
	goto loc_8213C254;
loc_8213C250:
	// li r11,0
	r11.s64 = 0;
loc_8213C254:
	// lbz r9,200(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// li r10,16256
	ctx.r10.s64 = 16256;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// rlwimi r10,r4,6,25,25
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 6) & 0x40) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFBF);
	// clrlwi r7,r9,26
	ctx.r7.u64 = ctx.r9.u32 & 0x3F;
	// or r6,r10,r7
	ctx.r6.u64 = ctx.r10.u64 | ctx.r7.u64;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// stb r10,200(r11)
	PPC_STORE_U8(r11.u32 + 200, ctx.r10.u8);
	// lwz r9,144(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213c290
	if (cr6.eq) goto loc_8213C290;
	// rlwinm r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213c290
	if (!cr6.eq) goto loc_8213C290;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
loc_8213C290:
	// lbz r10,200(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// ori r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 8;
	// stb r10,200(r11)
	PPC_STORE_U8(r11.u32 + 200, ctx.r10.u8);
	// bne cr6,0x8213c2b0
	if (!cr6.eq) goto loc_8213C2B0;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,200(r11)
	PPC_STORE_U8(r11.u32 + 200, ctx.r9.u8);
loc_8213C2B0:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x82148db0
	sub_82148DB0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213C218) {
	__imp__sub_8213C218(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C2BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213C2BC) {
	__imp__sub_8213C2BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C2C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213c2f8
	if (cr6.eq) goto loc_8213C2F8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213c2fc
	goto loc_8213C2FC;
loc_8213C2F8:
	// li r11,0
	r11.s64 = 0;
loc_8213C2FC:
	// lbz r10,200(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// stb r10,200(r11)
	PPC_STORE_U8(r11.u32 + 200, ctx.r10.u8);
	// lwz r9,144(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213c324
	if (cr6.eq) goto loc_8213C324;
	// rlwinm r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213c324
	if (!cr6.eq) goto loc_8213C324;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
loc_8213C324:
	// lbz r10,200(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// ori r9,r10,24
	ctx.r9.u64 = ctx.r10.u64 | 24;
	// stb r9,200(r11)
	PPC_STORE_U8(r11.u32 + 200, ctx.r9.u8);
	// lbz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 56);
	// ori r7,r8,16
	ctx.r7.u64 = ctx.r8.u64 | 16;
	// stb r7,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r7.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213C2C0) {
	__imp__sub_8213C2C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C340) {
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
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213c388
	if (cr6.eq) goto loc_8213C388;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213c38c
	goto loc_8213C38C;
loc_8213C388:
	// li r31,0
	r31.s64 = 0;
loc_8213C38C:
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213c3ac
	if (cr6.eq) goto loc_8213C3AC;
	// lbz r11,200(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213c3ac
	if (!cr6.eq) goto loc_8213C3AC;
	// bl 0x82148fd8
	ctx.lr = 0x8213C3AC;
	sub_82148FD8(ctx, base);
loc_8213C3AC:
	// lbz r11,200(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stb r10,200(r31)
	PPC_STORE_U8(r31.u32 + 200, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213C340) {
	__imp__sub_8213C340(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213C3CC) {
	__imp__sub_8213C3CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C3D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,140(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// lwz r10,136(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// lfs f13,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// bgt cr6,0x8213c3f8
	if (cr6.gt) goto loc_8213C3F8;
	// li r9,1
	ctx.r9.s64 = 1;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x8213c440
	goto loc_8213C440;
loc_8213C3F8:
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x8213c40c
	if (cr6.lt) goto loc_8213C40C;
	// li r9,1
	ctx.r9.s64 = 1;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
	// b 0x8213c440
	goto loc_8213C440;
loc_8213C40C:
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// subf r8,r4,r11
	ctx.r8.s64 = r11.s64 - ctx.r4.s64;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// clrldi r6,r8,32
	ctx.r6.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f0,f9,f8
	f0.f64 = double(float(ctx.f9.f64 / ctx.f8.f64));
loc_8213C440:
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// stfs f13,-8(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// addi r7,r10,11040
	ctx.r7.s64 = ctx.r10.s64 + 11040;
	// lfs f11,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lfs f13,-24(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11368(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11368);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,-28(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -28);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	v62.f32[0] = log2f(v63.f32[0]);
	v62.f32[1] = log2f(v63.f32[1]);
	v62.f32[2] = log2f(v63.f32[2]);
	v62.f32[3] = log2f(v63.f32[3]);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v62,v63
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fsel f7,f10,f8,f0
	ctx.f7.f64 = ctx.f10.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fadds f6,f7,f11
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f11.f64));
	// stfs f6,40(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// beq cr6,0x8213c4bc
	if (cr6.eq) goto loc_8213C4BC;
	// lbz r11,58(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 58);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_8213C4BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213C3D0) {
	__imp__sub_8213C3D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213C4C4) {
	__imp__sub_8213C4C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C4C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r8,68(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8213c5c4
	if (cr6.eq) goto loc_8213C5C4;
	// lwz r11,108(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// lwz r10,88(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// subf. r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble 0x8213c4ec
	if (!cr0.gt) goto loc_8213C4EC;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bgt cr6,0x8213c5c4
	if (cr6.gt) goto loc_8213C5C4;
loc_8213C4EC:
	// lwz r11,96(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// lwz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// subf r7,r9,r11
	ctx.r7.s64 = r11.s64 - ctx.r9.s64;
	// subf r10,r10,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r10.s64;
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bge cr6,0x8213c5c4
	if (!cr6.lt) goto loc_8213C5C4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8213c5bc
	if (cr6.lt) goto loc_8213C5BC;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// lfs f9,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f9.f64 = double(temp.f32);
	// clrldi r10,r8,32
	ctx.r10.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// clrldi r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f6,-16(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r5,r1,-16
	ctx.r5.s64 = ctx.r1.s64 + -16;
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// addi r4,r1,-16
	ctx.r4.s64 = ctx.r1.s64 + -16;
	// stfs f0,-8(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r11,11040
	ctx.r9.s64 = r11.s64 + 11040;
	// lfs f11,11368(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11368);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f2,f4,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 / ctx.f3.f64));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,-28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28);
	ctx.f10.f64 = double(temp.f32);
	// fsel f1,f2,f2,f0
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// fsubs f0,f1,f13
	f0.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fsel f13,f0,f13,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f13.f64 : ctx.f1.f64;
	// stfs f13,-16(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	v61.f32[0] = log2f(v62.f32[0]);
	v61.f32[1] = log2f(v62.f32[1]);
	v61.f32[2] = log2f(v62.f32[2]);
	v61.f32[3] = log2f(v62.f32[3]);
	// vmulfp128 v60,v61,v63
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// fsubs f12,f13,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fsel f6,f12,f7,f10
	ctx.f6.f64 = ctx.f12.f64 >= 0.0 ? ctx.f7.f64 : ctx.f10.f64;
	// fadds f5,f6,f9
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f9.f64));
	// stfs f5,40(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
loc_8213C5BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8213C5C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213C4C8) {
	__imp__sub_8213C4C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213C5CC) {
	__imp__sub_8213C5CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C5D0) {
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
	ctx.lr = 0x8213C5D8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r27,r30,72
	r27.s64 = r30.s64 + 72;
	// li r26,8
	r26.s64 = 8;
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r29,r10,6280
	r29.s64 = ctx.r10.s64 + 6280;
loc_8213C600:
	// lbz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8213c668
	if (cr6.eq) goto loc_8213C668;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8213c668
	if (cr6.eq) goto loc_8213C668;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8213c644
	if (cr6.eq) goto loc_8213C644;
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8213c648
	goto loc_8213C648;
loc_8213C644:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213C648:
	// lbz r11,59(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 59);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8213C664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_8213C668:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// bne 0x8213c600
	if (!cr0.eq) goto loc_8213C600;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8213C5D0) {
	__imp__sub_8213C5D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213C67C) {
	__imp__sub_8213C67C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C680) {
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
	ctx.lr = 0x8213C688;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213c750
	if (cr6.eq) goto loc_8213C750;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r7,116(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// addi r6,r11,7216
	ctx.r6.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r11,232(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 232);
	// lwz r10,200(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 200);
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// mullw r11,r10,r8
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8213c704
	if (cr6.eq) goto loc_8213C704;
	// lbz r11,200(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 200);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213c704
	if (!cr6.eq) goto loc_8213C704;
	// rotlwi r3,r7,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213C6F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b860
	ctx.lr = 0x8213C704;
	sub_8213B860(ctx, base);
loc_8213C704:
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213c748
	if (cr6.eq) goto loc_8213C748;
	// lbz r11,200(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 200);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213c748
	if (cr6.eq) goto loc_8213C748;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213c748
	if (!cr6.eq) goto loc_8213C748;
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213C748;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213C748:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82148c18
	ctx.lr = 0x8213C750;
	sub_82148C18(ctx, base);
loc_8213C750:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8213C680) {
	__imp__sub_8213C680(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C758) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r11,r9,6904
	r11.s64 = ctx.r9.s64 + 6904;
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8213C78C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,112(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// clrlwi r11,r6,30
	r11.u64 = ctx.r6.u32 & 0x3;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8213c7a4
	if (!cr6.eq) goto loc_8213C7A4;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8213c7b0
	goto loc_8213C7B0;
loc_8213C7A4:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r10,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_8213C7B0:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,11412(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11412);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8213c800
	if (cr6.eq) goto loc_8213C800;
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8213c7f0
	if (!cr6.eq) goto loc_8213C7F0;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// b 0x8213c800
	goto loc_8213C800;
loc_8213C7F0:
	// fctidz f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_8213C800:
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213c828
	if (cr6.eq) goto loc_8213C828;
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
loc_8213C828:
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x8213c844
	if (!cr6.eq) goto loc_8213C844;
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
loc_8213C844:
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213c8bc
	if (cr6.eq) goto loc_8213C8BC;
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrldi r7,r11,32
	ctx.r7.u64 = r11.u64 & 0xFFFFFFFF;
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f0,11360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * f0.f64));
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// fmadds f3,f6,f5,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
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
loc_8213C8BC:
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bgt cr6,0x8213c8dc
	if (cr6.gt) goto loc_8213C8DC;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
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
loc_8213C8DC:
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
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

PPC_WEAK_FUNC(sub_8213C758) {
	__imp__sub_8213C758(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C8F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r11,7212(r9)
	PPC_STORE_U32(ctx.r9.u32 + 7212, r11.u32);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// rlwinm r3,r10,30,30,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// lwz r8,232(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r7,196(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
loc_8213C924:
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r6,r11,r8
	ctx.r6.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,7212(r9)
	PPC_STORE_U32(ctx.r9.u32 + 7212, r11.u32);
	// lwz r5,112(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// rlwinm r3,r5,30,30,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x8213c924
	if (cr6.eq) goto loc_8213C924;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213C8F8) {
	__imp__sub_8213C8F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C960) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
loc_8213C960:
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rlwinm r11,r11,26,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x3;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8213c9b0
	if (!cr6.eq) goto loc_8213C9B0;
	// lbz r8,5(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213c9a8
	if (cr6.eq) goto loc_8213C9A8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8213c960
	goto loc_8213C960;
loc_8213C9A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8213C9B0:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213C960) {
	__imp__sub_8213C960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213C9C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
loc_8213C9C0:
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rlwinm r11,r11,24,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0x3;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8213ca10
	if (!cr6.eq) goto loc_8213CA10;
	// lbz r8,5(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213ca08
	if (cr6.eq) goto loc_8213CA08;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8213c9c0
	goto loc_8213C9C0;
loc_8213CA08:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8213CA10:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213C9C0) {
	__imp__sub_8213C9C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213CA20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213ca7c
	if (cr6.eq) goto loc_8213CA7C;
	// lbz r8,5(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213ca6c
	if (cr6.eq) goto loc_8213CA6C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// lwzx r5,r11,r10
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,20(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8213CA6C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// addi r3,r11,380
	ctx.r3.s64 = r11.s64 + 380;
	// b 0x82149078
	sub_82149078(ctx, base);
	return;
loc_8213CA7C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213CA20) {
	__imp__sub_8213CA20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213CA84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213CA84) {
	__imp__sub_8213CA84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213CA88) {
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
	ctx.lr = 0x8213CA90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lbz r11,57(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213cab8
	if (cr6.eq) goto loc_8213CAB8;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x8213cb34
	if (cr6.eq) goto loc_8213CB34;
loc_8213CAB8:
	// lbz r11,58(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 58);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213cb34
	if (!cr6.eq) goto loc_8213CB34;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r30,72
	r28.s64 = r30.s64 + 72;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_8213CAD8:
	// lbzx r9,r28,r29
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8213cb28
	if (cr6.eq) goto loc_8213CB28;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213cb28
	if (cr6.eq) goto loc_8213CB28;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213CB20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8213cb38
	if (!cr6.eq) goto loc_8213CB38;
loc_8213CB28:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// blt cr6,0x8213cad8
	if (cr6.lt) goto loc_8213CAD8;
loc_8213CB34:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213CB38:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8213CA88) {
	__imp__sub_8213CA88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213CB40) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823db918
	ctx.lr = 0x8213CB58;
	sub_823DB918(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// lfs f0,11332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11332);
	f0.f64 = double(temp.f32);
	// lfs f13,11328(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11328);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x8213cbb8
	if (cr6.eq) goto loc_8213CBB8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8213cbbc
	goto loc_8213CBBC;
loc_8213CBB8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213CBBC:
	// bl 0x82148c60
	ctx.lr = 0x8213CBC0;
	sub_82148C60(ctx, base);
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

PPC_WEAK_FUNC(sub_8213CB40) {
	__imp__sub_8213CB40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213CBD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213CBD4) {
	__imp__sub_8213CBD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213CBD8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8213CBE0;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r28,88(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lfs f0,11412(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11412);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213cc1c
	if (cr6.eq) goto loc_8213CC1C;
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r28,r11,r28
	r28.s64 = r28.s64 - r11.s64;
loc_8213CC1C:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r29,104(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213cc44
	if (cr6.eq) goto loc_8213CC44;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r29,r11,r29
	r29.s64 = r29.s64 - r11.s64;
loc_8213CC44:
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// li r25,0
	r25.s64 = 0;
	// lwz r27,96(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// lwz r30,108(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8213cc68
	if (!cr6.eq) goto loc_8213CC68;
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x8213cc74
	goto loc_8213CC74;
loc_8213CC68:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_8213CC74:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r26,r11,6904
	r26.s64 = r11.s64 + 6904;
	// lfs f31,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
	// beq cr6,0x8213cd20
	if (cr6.eq) goto loc_8213CD20;
	// lbz r11,59(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r10,r11,r26
	ctx.r10.u64 = r11.u64 + r26.u64;
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8213CCB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrldi r8,r29,32
	ctx.r8.u64 = r29.u64 & 0xFFFFFFFF;
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f0,f12
	f0.f64 = double(float(ctx.f12.f64));
	// frsp f13,f11
	ctx.f13.f64 = double(float(ctx.f11.f64));
	// bne cr6,0x8213cd0c
	if (!cr6.eq) goto loc_8213CD0C;
loc_8213CCE0:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// add r10,r27,r28
	ctx.r10.u64 = r27.u64 + r28.u64;
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213ccfc
	if (cr6.eq) goto loc_8213CCFC;
	// stw r28,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r28.u32);
loc_8213CCFC:
	// stw r25,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r25.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_8213CD0C:
	// fmuls f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8213CD20:
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213cd78
	if (cr6.eq) goto loc_8213CD78;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213c758
	ctx.lr = 0x8213CD3C;
	sub_8213C758(ctx, base);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// clrldi r10,r30,32
	ctx.r10.u64 = r30.u64 & 0xFFFFFFFF;
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
	// fmuls f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8213CD78:
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// blt cr6,0x8213cd94
	if (cr6.lt) goto loc_8213CD94;
	// subf r11,r28,r30
	r11.s64 = r30.s64 - r28.s64;
	// stw r27,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r27.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// b 0x8213cda4
	goto loc_8213CDA4;
loc_8213CD94:
	// subf r11,r30,r27
	r11.s64 = r27.s64 - r30.s64;
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
loc_8213CDA4:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213cdb8
	if (cr6.eq) goto loc_8213CDB8;
	// stw r28,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r28.u32);
loc_8213CDB8:
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213ce5c
	if (cr6.eq) goto loc_8213CE5C;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8213cddc
	if (!cr6.eq) goto loc_8213CDDC;
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x8213cde8
	goto loc_8213CDE8;
loc_8213CDDC:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_8213CDE8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213ce58
	if (cr6.eq) goto loc_8213CE58;
	// lbz r11,59(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r10,r11,r26
	ctx.r10.u64 = r11.u64 + r26.u64;
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8213CE14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrldi r8,r29,32
	ctx.r8.u64 = r29.u64 & 0xFFFFFFFF;
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f0,f13
	f0.f64 = double(float(ctx.f13.f64));
	// frsp f13,f11
	ctx.f13.f64 = double(float(ctx.f11.f64));
	// beq cr6,0x8213cce0
	if (cr6.eq) goto loc_8213CCE0;
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8213CE58:
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
loc_8213CE5C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8213CBD8) {
	__imp__sub_8213CBD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213CE68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,7216
	ctx.r10.s64 = r11.s64 + 7216;
	// addi r6,r3,72
	ctx.r6.s64 = ctx.r3.s64 + 72;
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
loc_8213CE80:
	// lbzx r11,r6,r7
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r7.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213ceb8
	if (cr6.eq) goto loc_8213CEB8;
	// lbz r5,64(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// mulli r11,r5,11488
	r11.s64 = ctx.r5.s64 * 11488;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213ceb8
	if (cr6.eq) goto loc_8213CEB8;
	// lhz r11,6(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x8213cecc
	if (cr6.eq) goto loc_8213CECC;
loc_8213CEB8:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpwi cr6,r7,8
	cr6.compare<int32_t>(ctx.r7.s32, 8, xer);
	// blt cr6,0x8213ce80
	if (cr6.lt) goto loc_8213CE80;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8213CECC:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213CE68) {
	__imp__sub_8213CE68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213CED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213CED4) {
	__imp__sub_8213CED4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213CED8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r7,r3,73
	ctx.r7.s64 = ctx.r3.s64 + 73;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r11,r11,7216
	r11.s64 = r11.s64 + 7216;
loc_8213CEE8:
	// lbz r8,-1(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + -1);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213cf40
	if (cr6.eq) goto loc_8213CF40;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lwz r9,232(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r5,196(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r5,r8
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 11440);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213cf40
	if (cr6.eq) goto loc_8213CF40;
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x8213cf40
	if (!cr6.eq) goto loc_8213CF40;
	// lbz r9,57(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 57);
	// lbz r8,56(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 56);
	// ori r5,r9,32
	ctx.r5.u64 = ctx.r9.u64 | 32;
	// ori r4,r8,8
	ctx.r4.u64 = ctx.r8.u64 | 8;
	// stb r5,57(r10)
	PPC_STORE_U8(ctx.r10.u32 + 57, ctx.r5.u8);
	// stb r4,56(r10)
	PPC_STORE_U8(ctx.r10.u32 + 56, ctx.r4.u8);
loc_8213CF40:
	// lbz r8,0(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213cf98
	if (cr6.eq) goto loc_8213CF98;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lwz r9,232(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r5,196(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r5,r8
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 11440);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213cf98
	if (cr6.eq) goto loc_8213CF98;
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x8213cf98
	if (!cr6.eq) goto loc_8213CF98;
	// lbz r9,57(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 57);
	// ori r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 | 32;
	// stb r8,57(r10)
	PPC_STORE_U8(ctx.r10.u32 + 57, ctx.r8.u8);
	// lbz r5,56(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 56);
	// ori r4,r5,8
	ctx.r4.u64 = ctx.r5.u64 | 8;
	// stb r4,56(r10)
	PPC_STORE_U8(ctx.r10.u32 + 56, ctx.r4.u8);
loc_8213CF98:
	// lbz r8,1(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213cff0
	if (cr6.eq) goto loc_8213CFF0;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lwz r9,232(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r5,196(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r5,r8
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 11440);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213cff0
	if (cr6.eq) goto loc_8213CFF0;
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x8213cff0
	if (!cr6.eq) goto loc_8213CFF0;
	// lbz r9,57(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 57);
	// ori r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 | 32;
	// stb r8,57(r10)
	PPC_STORE_U8(ctx.r10.u32 + 57, ctx.r8.u8);
	// lbz r5,56(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 56);
	// ori r4,r5,8
	ctx.r4.u64 = ctx.r5.u64 | 8;
	// stb r4,56(r10)
	PPC_STORE_U8(ctx.r10.u32 + 56, ctx.r4.u8);
loc_8213CFF0:
	// lbz r8,2(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + 2);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213d048
	if (cr6.eq) goto loc_8213D048;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lwz r9,232(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r5,196(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r5,r8
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 11440);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213d048
	if (cr6.eq) goto loc_8213D048;
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x8213d048
	if (!cr6.eq) goto loc_8213D048;
	// lbz r9,57(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 57);
	// ori r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 | 32;
	// stb r8,57(r10)
	PPC_STORE_U8(ctx.r10.u32 + 57, ctx.r8.u8);
	// lbz r5,56(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 56);
	// ori r4,r5,8
	ctx.r4.u64 = ctx.r5.u64 | 8;
	// stb r4,56(r10)
	PPC_STORE_U8(ctx.r10.u32 + 56, ctx.r4.u8);
loc_8213D048:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x8213cee8
	if (!cr0.eq) goto loc_8213CEE8;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213CED8) {
	__imp__sub_8213CED8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D058) {
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
	ctx.lr = 0x8213D060;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// lbz r11,57(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213d094
	if (cr6.eq) goto loc_8213D094;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x8213d160
	if (cr6.eq) goto loc_8213D160;
loc_8213D094:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8213d160
	if (cr6.eq) goto loc_8213D160;
	// lbz r11,59(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 59);
	// cmplw cr6,r11,r25
	cr6.compare<uint32_t>(r11.u32, r25.u32, xer);
	// bne cr6,0x8213d0e0
	if (!cr6.eq) goto loc_8213D0E0;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8213d0e0
	if (!cr6.gt) goto loc_8213D0E0;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_8213D0B8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213d0d8
	if (cr6.eq) goto loc_8213D0D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// blt cr6,0x8213d0b8
	if (cr6.lt) goto loc_8213D0B8;
	// b 0x8213d0e0
	goto loc_8213D0E0;
loc_8213D0D8:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r11,r26
	PPC_STORE_U32(r11.u32 + r26.u32, r30.u32);
loc_8213D0E0:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213d0fc
	if (!cr6.eq) goto loc_8213D0FC;
	// lbz r11,58(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 58);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213d160
	if (!cr6.eq) goto loc_8213D160;
loc_8213D0FC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r30,72
	r28.s64 = r30.s64 + 72;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_8213D10C:
	// lbzx r9,r28,r29
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8213d154
	if (cr6.eq) goto loc_8213D154;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213d154
	if (cr6.eq) goto loc_8213D154;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x8213d058
	ctx.lr = 0x8213D154;
	sub_8213D058(ctx, base);
loc_8213D154:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// blt cr6,0x8213d10c
	if (cr6.lt) goto loc_8213D10C;
loc_8213D160:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8213D058) {
	__imp__sub_8213D058(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D168) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,7216
	ctx.r10.s64 = r11.s64 + 7216;
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// lwz r8,200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// lwz r7,196(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
loc_8213D17C:
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213d1b0
	if (cr6.eq) goto loc_8213D1B0;
	// lbz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// mulli r11,r6,11488
	r11.s64 = ctx.r6.s64 * 11488;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11444(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r4,199(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// rlwinm r11,r4,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213d1d8
	if (!cr6.eq) goto loc_8213D1D8;
loc_8213D1B0:
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213d1d8
	if (cr6.eq) goto loc_8213D1D8;
	// lbz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r7,r11
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// mulli r11,r6,11488
	r11.s64 = ctx.r6.s64 * 11488;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d17c
	goto loc_8213D17C;
loc_8213D1D8:
	// lbz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D168) {
	__imp__sub_8213D168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D1E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,7216
	ctx.r10.s64 = r11.s64 + 7216;
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// lwz r8,200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// lwz r7,196(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
loc_8213D1F4:
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213d228
	if (cr6.eq) goto loc_8213D228;
	// lbz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// mulli r11,r6,11488
	r11.s64 = ctx.r6.s64 * 11488;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11444(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r4,199(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// rlwinm r11,r4,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213d250
	if (!cr6.eq) goto loc_8213D250;
loc_8213D228:
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213d250
	if (cr6.eq) goto loc_8213D250;
	// lbz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r7,r11
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// mulli r11,r6,11488
	r11.s64 = ctx.r6.s64 * 11488;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d1f4
	goto loc_8213D1F4;
loc_8213D250:
	// lbz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D1E0) {
	__imp__sub_8213D1E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D258) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213d290
	if (cr6.eq) goto loc_8213D290;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d294
	goto loc_8213D294;
loc_8213D290:
	// li r11,0
	r11.s64 = 0;
loc_8213D294:
	// lbz r11,200(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213d2ac
	if (cr6.eq) goto loc_8213D2AC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8213D2AC:
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D258) {
	__imp__sub_8213D258(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D2B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213D2B4) {
	__imp__sub_8213D2B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D2B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213d2f0
	if (cr6.eq) goto loc_8213D2F0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d2f4
	goto loc_8213D2F4;
loc_8213D2F0:
	// li r11,0
	r11.s64 = 0;
loc_8213D2F4:
	// lbz r11,200(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213d30c
	if (cr6.eq) goto loc_8213D30C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8213D30C:
	// lwz r3,120(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D2B8) {
	__imp__sub_8213D2B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213D314) {
	__imp__sub_8213D314(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D318) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213d350
	if (cr6.eq) goto loc_8213D350;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d354
	goto loc_8213D354;
loc_8213D350:
	// li r11,0
	r11.s64 = 0;
loc_8213D354:
	// lbz r11,200(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213d36c
	if (cr6.eq) goto loc_8213D36C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8213D36C:
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D318) {
	__imp__sub_8213D318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213D374) {
	__imp__sub_8213D374(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D378) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
loc_8213D398:
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// rlwinm r11,r11,28,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x3;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8213d3b0
	if (!cr6.eq) goto loc_8213D3B0;
	// li r11,0
	r11.s64 = 0;
	// b 0x8213d3bc
	goto loc_8213D3BC;
loc_8213D3B0:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_8213D3BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213d3ec
	if (cr6.eq) goto loc_8213D3EC;
	// lhz r3,126(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 126);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8213d3f0
	if (!cr6.eq) goto loc_8213D3F0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213ed00
	ctx.lr = 0x8213D3E0;
	sub_8213ED00(ctx, base);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,126(r31)
	PPC_STORE_U16(r31.u32 + 126, ctx.r3.u16);
	// b 0x8213d3f0
	goto loc_8213D3F0;
loc_8213D3EC:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
loc_8213D3F0:
	// lbz r9,5(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8213d424
	if (cr6.eq) goto loc_8213D424;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d398
	goto loc_8213D398;
loc_8213D424:
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

PPC_WEAK_FUNC(sub_8213D378) {
	__imp__sub_8213D378(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213D43C) {
	__imp__sub_8213D43C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D440) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// addi r8,r10,7216
	ctx.r8.s64 = ctx.r10.s64 + 7216;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r9,232(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// lwz r8,196(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// beq cr6,0x8213d478
	if (cr6.eq) goto loc_8213D478;
	// lbz r7,64(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// mulli r11,r7,11488
	r11.s64 = ctx.r7.s64 * 11488;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d47c
	goto loc_8213D47C;
loc_8213D478:
	// li r11,0
	r11.s64 = 0;
loc_8213D47C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_8213D484:
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8213d484
	if (!cr0.eq) goto loc_8213D484;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D440) {
	__imp__sub_8213D440(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213D4B4) {
	__imp__sub_8213D4B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D4B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// addi r9,r10,7216
	ctx.r9.s64 = ctx.r10.s64 + 7216;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r8,232(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 232);
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// beq cr6,0x8213d4f0
	if (cr6.eq) goto loc_8213D4F0;
	// lbz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r7,r11
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// mulli r11,r6,11488
	r11.s64 = ctx.r6.s64 * 11488;
	// add r5,r11,r8
	ctx.r5.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d4f4
	goto loc_8213D4F4;
loc_8213D4F0:
	// li r11,0
	r11.s64 = 0;
loc_8213D4F4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r6,200(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 200);
loc_8213D500:
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8213d534
	if (cr6.eq) goto loc_8213D534;
	// lbz r5,64(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// mullw r9,r6,r10
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// mulli r10,r5,11488
	ctx.r10.s64 = ctx.r5.s64 * 11488;
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r10,11444(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 11444);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r3,199(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 199);
	// rlwinm r10,r3,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213d564
	if (!cr6.eq) goto loc_8213D564;
loc_8213D534:
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r9,r11,r8
	ctx.r9.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8213d500
	if (!cr0.eq) goto loc_8213D500;
	// blr 
	return;
loc_8213D564:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D4B8) {
	__imp__sub_8213D4B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D56C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213D56C) {
	__imp__sub_8213D56C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D570) {
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
	// bl 0x8213d440
	ctx.lr = 0x8213D580;
	sub_8213D440(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213d59c
	if (cr6.eq) goto loc_8213D59C;
	// lbz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8213D59C:
	// li r3,255
	ctx.r3.s64 = 255;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D570) {
	__imp__sub_8213D570(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D5B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r9,232(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// beq cr6,0x8213d5f0
	if (cr6.eq) goto loc_8213D5F0;
	// lwz r8,196(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
loc_8213D5CC:
	// lbz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// mulli r11,r6,11488
	r11.s64 = ctx.r6.s64 * 11488;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bne cr6,0x8213d5cc
	if (!cr6.eq) goto loc_8213D5CC;
loc_8213D5F0:
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213d61c
	if (cr6.eq) goto loc_8213D61C;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d620
	goto loc_8213D620;
loc_8213D61C:
	// li r11,0
	r11.s64 = 0;
loc_8213D620:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// b 0x821ce100
	sub_821CE100(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213D5B0) {
	__imp__sub_8213D5B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D634) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D634) {
	__imp__sub_8213D634(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D638) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r9,232(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// beq cr6,0x8213d678
	if (cr6.eq) goto loc_8213D678;
	// lwz r8,196(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
loc_8213D654:
	// lbz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// mulli r11,r6,11488
	r11.s64 = ctx.r6.s64 * 11488;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bne cr6,0x8213d654
	if (!cr6.eq) goto loc_8213D654;
loc_8213D678:
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213d6a4
	if (cr6.eq) goto loc_8213D6A4;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d6a8
	goto loc_8213D6A8;
loc_8213D6A4:
	// li r11,0
	r11.s64 = 0;
loc_8213D6A8:
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// b 0x821ce0d8
	sub_821CE0D8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213D638) {
	__imp__sub_8213D638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D6B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,5(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213d6e8
	if (cr6.eq) goto loc_8213D6E8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d6ec
	goto loc_8213D6EC;
loc_8213D6E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213D6EC:
	// lbz r11,59(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 59);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r10,r10,7008
	ctx.r10.s64 = ctx.r10.s64 + 7008;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8213D6B0) {
	__imp__sub_8213D6B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213D70C) {
	__imp__sub_8213D70C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r11,7216
	ctx.r10.s64 = r11.s64 + 7216;
	// addi r6,r3,72
	ctx.r6.s64 = ctx.r3.s64 + 72;
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
loc_8213D72C:
	// lbzx r11,r6,r7
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r7.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213d754
	if (cr6.eq) goto loc_8213D754;
	// lbz r31,64(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// mulli r11,r31,11488
	r11.s64 = r31.s64 * 11488;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213d758
	goto loc_8213D758;
loc_8213D754:
	// li r11,0
	r11.s64 = 0;
loc_8213D758:
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x8213d774
	if (cr6.eq) goto loc_8213D774;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r7,8
	cr6.compare<uint32_t>(ctx.r7.u32, 8, xer);
	// blt cr6,0x8213d72c
	if (cr6.lt) goto loc_8213D72C;
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8213D774:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8213d7ac
	if (cr6.eq) goto loc_8213D7AC;
	// lbz r11,64(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// twllei r8,0
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,11440(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r10,r7,r3
	ctx.r10.u64 = ctx.r7.u64 + ctx.r3.u64;
	// subf r6,r9,r5
	ctx.r6.s64 = ctx.r5.s64 - ctx.r9.s64;
	// divwu r5,r6,r8
	ctx.r5.u32 = ctx.r6.u32 / ctx.r8.u32;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// stb r11,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, r11.u8);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8213D7AC:
	// add r10,r7,r3
	ctx.r10.u64 = ctx.r7.u64 + ctx.r3.u64;
	// li r11,255
	r11.s64 = 255;
	// stb r11,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, r11.u8);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D710) {
	__imp__sub_8213D710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D7C0) {
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
	// bl 0x8213ba48
	ctx.lr = 0x8213D7E0;
	sub_8213BA48(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213d808
	if (cr6.eq) goto loc_8213D808;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8213d808
	if (cr6.eq) goto loc_8213D808;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x8213D808;
	sub_8213F7A8(ctx, base);
loc_8213D808:
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

PPC_WEAK_FUNC(sub_8213D7C0) {
	__imp__sub_8213D7C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213D824) {
	__imp__sub_8213D824(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D828) {
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
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r3,r10,7216
	ctx.r3.s64 = ctx.r10.s64 + 7216;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// bl 0x8213f178
	ctx.lr = 0x8213D85C;
	sub_8213F178(ctx, base);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r7,r9,7456
	ctx.r7.s64 = ctx.r9.s64 + 7456;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// stb r11,6204(r8)
	PPC_STORE_U8(ctx.r8.u32 + 6204, r11.u8);
	// bl 0x8213bb68
	ctx.lr = 0x8213D880;
	sub_8213BB68(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D828) {
	__imp__sub_8213D828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D890) {
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
	ctx.lr = 0x8213D898;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8213bc50
	ctx.lr = 0x8213D8A8;
	sub_8213BC50(ctx, base);
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// bl 0x8213cbd8
	ctx.lr = 0x8213D8B0;
	sub_8213CBD8(ctx, base);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// li r28,2
	r28.s64 = 2;
	// rlwinm r11,r11,26,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x3;
	// sth r28,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r28.u16);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// lwz r29,80(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bne cr6,0x8213d910
	if (!cr6.eq) goto loc_8213D910;
	// lbz r8,5(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213d908
	if (cr6.eq) goto loc_8213D908;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x8213c960
	ctx.lr = 0x8213D904;
	sub_8213C960(ctx, base);
	// b 0x8213d91c
	goto loc_8213D91C;
loc_8213D908:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8213d91c
	goto loc_8213D91C;
loc_8213D910:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_8213D91C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213d97c
	if (cr6.eq) goto loc_8213D97C;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x8213D934;
	sub_821374B0(ctx, base);
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// rotlwi r11,r10,2
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r10,r9,6384
	ctx.r10.s64 = ctx.r9.s64 + 6384;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8213D960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8213d97c
	if (cr6.eq) goto loc_8213D97C;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stb r10,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8213D97C:
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213c4c8
	ctx.lr = 0x8213D98C;
	sub_8213C4C8(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8213d9c8
	if (!cr6.eq) goto loc_8213D9C8;
	// lbz r11,59(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// sth r28,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r28.u16);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r10,6592
	ctx.r10.s64 = ctx.r10.s64 + 6592;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213D9C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8213D9C8:
	// li r11,1
	r11.s64 = 1;
	// sth r11,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8213D890) {
	__imp__sub_8213D890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213D9D8) {
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
	// lbz r11,56(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 56);
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// ori r10,r11,6
	ctx.r10.u64 = r11.u64 | 6;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// stb r10,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r10.u8);
	// beq cr6,0x8213da34
	if (cr6.eq) goto loc_8213DA34;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,192(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8213da34
	if (cr6.eq) goto loc_8213DA34;
	// stw r11,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, r11.u32);
loc_8213DA34:
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8213da68
	if (!cr6.eq) goto loc_8213DA68;
	// li r11,0
	r11.s64 = 0;
	// stw r11,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, r11.u32);
	// bl 0x8213ced8
	ctx.lr = 0x8213DA4C;
	sub_8213CED8(ctx, base);
	// lbz r10,57(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 57);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r9.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8213DA68:
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stw r4,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, ctx.r4.u32);
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213D9D8) {
	__imp__sub_8213D9D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DA84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213DA84) {
	__imp__sub_8213DA84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DA88) {
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
	ctx.lr = 0x8213DA90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213dac0
	if (cr6.eq) goto loc_8213DAC0;
loc_8213DAB4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8213DAC0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8213dad8
	if (!cr6.eq) goto loc_8213DAD8;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x8213DAD4;
	sub_821374B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8213DAD8:
	// clrlwi r29,r28,24
	r29.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8213db08
	if (!cr6.eq) goto loc_8213DB08;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// clrlwi r10,r27,24
	ctx.r10.u64 = r27.u32 & 0xFF;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r10,2,29,29
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 2) & 0x4) | (r11.u64 & 0xFFFFFFFFFFFFFFFB);
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r11,57(r31)
	PPC_STORE_U8(r31.u32 + 57, r11.u8);
	// bl 0x82137488
	ctx.lr = 0x8213DB04;
	sub_82137488(ctx, base);
	// sth r3,60(r31)
	PPC_STORE_U16(r31.u32 + 60, ctx.r3.u16);
loc_8213DB08:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213c960
	ctx.lr = 0x8213DB10;
	sub_8213C960(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213dab4
	if (!cr6.eq) goto loc_8213DAB4;
	// lbz r11,59(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r10,r10,6384
	ctx.r10.s64 = ctx.r10.s64 + 6384;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213DB48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8213dbb0
	if (!cr6.eq) goto loc_8213DBB0;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bne cr6,0x8213db84
	if (!cr6.eq) goto loc_8213DB84;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// bl 0x8213cbd8
	ctx.lr = 0x8213DB6C;
	sub_8213CBD8(ctx, base);
	// lbz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stb r9,56(r31)
	PPC_STORE_U8(r31.u32 + 56, ctx.r9.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8213DB84:
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x8213dba4
	if (!cr6.eq) goto loc_8213DBA4;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8213DBA4:
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,56(r31)
	PPC_STORE_U8(r31.u32 + 56, ctx.r10.u8);
loc_8213DBB0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8213DA88) {
	__imp__sub_8213DA88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DBBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213DBBC) {
	__imp__sub_8213DBBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DBC0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lhz r4,17(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 17);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x8213dbf0
	if (!cr6.eq) goto loc_8213DBF0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8213dbf8
	goto loc_8213DBF8;
loc_8213DBF0:
	// neg r3,r4
	ctx.r3.s64 = -ctx.r4.s64;
	// bl 0x82145020
	ctx.lr = 0x8213DBF8;
	sub_82145020(ctx, base);
loc_8213DBF8:
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// lhz r10,15(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 15);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmadds f7,f9,f0,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f8.f64));
	// stfs f7,28(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r30.u32 + 28, temp.u32);
	// lhz r4,21(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 21);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x8213dc4c
	if (!cr6.eq) goto loc_8213DC4C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8213dc54
	goto loc_8213DC54;
loc_8213DC4C:
	// neg r3,r4
	ctx.r3.s64 = -ctx.r4.s64;
	// bl 0x82145020
	ctx.lr = 0x8213DC54;
	sub_82145020(ctx, base);
loc_8213DC54:
	// lhz r11,19(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 19);
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// sth r10,32(r30)
	PPC_STORE_U16(r30.u32 + 32, ctx.r10.u16);
	// lhz r8,23(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 23);
	// cmplwi cr6,r8,65535
	cr6.compare<uint32_t>(ctx.r8.u32, 65535, xer);
	// beq cr6,0x8213dccc
	if (cr6.eq) goto loc_8213DCCC;
	// lhz r4,25(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 25);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x8213dc80
	if (!cr6.eq) goto loc_8213DC80;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8213dc88
	goto loc_8213DC88;
loc_8213DC80:
	// neg r3,r4
	ctx.r3.s64 = -ctx.r4.s64;
	// bl 0x82145020
	ctx.lr = 0x8213DC88;
	sub_82145020(ctx, base);
loc_8213DC88:
	// lhz r11,23(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 23);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// lis r9,-18933
	ctx.r9.s64 = -1240793088;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// ori r8,r9,24759
	ctx.r8.u64 = ctx.r9.u64 | 24759;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r11,360
	ctx.r7.s64 = r11.s64 + 360;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// mulhw r10,r11,r8
	ctx.r10.s64 = (int64_t(r11.s32) * int64_t(ctx.r8.s32)) >> 32;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// srawi r11,r6,8
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	r11.s64 = ctx.r6.s32 >> 8;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mulli r4,r5,360
	ctx.r4.s64 = ctx.r5.s64 * 360;
	// subf r3,r4,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r4.s64;
	// sth r3,10(r30)
	PPC_STORE_U16(r30.u32 + 10, ctx.r3.u16);
	// b 0x8213dcd4
	goto loc_8213DCD4;
loc_8213DCCC:
	// li r11,-1
	r11.s64 = -1;
	// sth r11,10(r30)
	PPC_STORE_U16(r30.u32 + 10, r11.u16);
loc_8213DCD4:
	// lhz r4,29(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 29);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x8213dce8
	if (!cr6.eq) goto loc_8213DCE8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8213dcf0
	goto loc_8213DCF0;
loc_8213DCE8:
	// neg r3,r4
	ctx.r3.s64 = -ctx.r4.s64;
	// bl 0x82145020
	ctx.lr = 0x8213DCF0;
	sub_82145020(ctx, base);
loc_8213DCF0:
	// lhz r11,27(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 27);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stw r11,88(r30)
	PPC_STORE_U32(r30.u32 + 88, r11.u32);
	// lwz r4,35(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 35);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x8213dd10
	if (!cr6.eq) goto loc_8213DD10;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8213dd18
	goto loc_8213DD18;
loc_8213DD10:
	// neg r3,r4
	ctx.r3.s64 = -ctx.r4.s64;
	// bl 0x82145020
	ctx.lr = 0x8213DD18;
	sub_82145020(ctx, base);
loc_8213DD18:
	// lwz r11,31(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 31);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stw r11,104(r30)
	PPC_STORE_U32(r30.u32 + 104, r11.u32);
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

PPC_WEAK_FUNC(sub_8213DBC0) {
	__imp__sub_8213DBC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213DD3C) {
	__imp__sub_8213DD3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DD40) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213c758
	sub_8213C758(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213DD40) {
	__imp__sub_8213DD40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DD44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213DD44) {
	__imp__sub_8213DD44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DD48) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// lbz r11,72(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213dd94
	if (cr6.eq) goto loc_8213DD94;
	// lbz r10,64(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213dd98
	goto loc_8213DD98;
loc_8213DD94:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8213DD98:
	// lbz r9,5(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// lfs f0,28(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	f0.f64 = double(temp.f32);
	// lhz r10,32(r5)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + 32);
	// lhz r7,10(r5)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r5.u32 + 10);
	// extsh r11,r7
	r11.s64 = ctx.r7.s16;
	// stb r9,5(r5)
	PPC_STORE_U8(ctx.r5.u32 + 5, ctx.r9.u8);
	// lfs f13,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lhz r6,32(r4)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r4.u32 + 32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// add r9,r10,r6
	ctx.r9.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lhz r3,10(r4)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r4.u32 + 10);
	// lwz r8,136(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// stfs f12,28(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 28, temp.u32);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// sth r9,32(r5)
	PPC_STORE_U16(ctx.r5.u32 + 32, ctx.r9.u16);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8213ddec
	if (cr6.eq) goto loc_8213DDEC;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x8213ddf0
	if (cr6.eq) goto loc_8213DDF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213ddf0
	goto loc_8213DDF0;
loc_8213DDEC:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8213DDF0:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// sth r11,10(r5)
	PPC_STORE_U16(ctx.r5.u32 + 10, r11.u16);
	// beq cr6,0x8213de00
	if (cr6.eq) goto loc_8213DE00;
	// stw r8,136(r5)
	PPC_STORE_U32(ctx.r5.u32 + 136, ctx.r8.u32);
loc_8213DE00:
	// lhz r10,34(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 34);
	// lfs f0,36(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	f0.f64 = double(temp.f32);
	// lhz r9,34(r5)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r5.u32 + 34);
	// lfs f13,36(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lhz r8,124(r5)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r5.u32 + 124);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lhz r7,124(r4)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r4.u32 + 124);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// stfs f12,36(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 36, temp.u32);
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// sth r6,34(r5)
	PPC_STORE_U16(ctx.r5.u32 + 34, ctx.r6.u16);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8213de48
	if (cr6.eq) goto loc_8213DE48;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x8213de4c
	if (cr6.eq) goto loc_8213DE4C;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213de4c
	goto loc_8213DE4C;
loc_8213DE48:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8213DE4C:
	// sth r11,124(r5)
	PPC_STORE_U16(ctx.r5.u32 + 124, r11.u16);
	// lbz r11,4(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213de68
	if (cr6.eq) goto loc_8213DE68;
	// li r10,255
	ctx.r10.s64 = 255;
	// stb r11,4(r5)
	PPC_STORE_U8(ctx.r5.u32 + 4, r11.u8);
	// stb r10,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, ctx.r10.u8);
loc_8213DE68:
	// lbz r8,5(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213de98
	if (cr6.eq) goto loc_8213DE98;
	// lbz r11,64(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213de9c
	goto loc_8213DE9C;
loc_8213DE98:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8213DE9C:
	// bl 0x8213d710
	ctx.lr = 0x8213DEA0;
	sub_8213D710(ctx, base);
	// lbz r11,57(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 57);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r5,64(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 64);
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// stb r10,57(r4)
	PPC_STORE_U8(ctx.r4.u32 + 57, ctx.r10.u8);
	// bl 0x8213f7a8
	ctx.lr = 0x8213DEB8;
	sub_8213F7A8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213DD48) {
	__imp__sub_8213DD48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213DECC) {
	__imp__sub_8213DECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213DED0) {
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
	ctx.lr = 0x8213DED8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r3,9
	ctx.r10.s64 = ctx.r3.s64 + 9;
	// lbz r11,9(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// addi r9,r31,8
	ctx.r9.s64 = r31.s64 + 8;
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// lbz r8,10(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// stb r8,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r8.u8);
	// lwz r7,5(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5);
	// stw r7,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r7.u32);
	// bl 0x8213b2e0
	ctx.lr = 0x8213DF14;
	sub_8213B2E0(ctx, base);
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lwz r4,57(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 57);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213df3c
	if (cr6.eq) goto loc_8213DF3C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213DF38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
loc_8213DF3C:
	// lwz r4,61(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 61);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213df60
	if (cr6.eq) goto loc_8213DF60;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213DF5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
loc_8213DF60:
	// lwz r4,65(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 65);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213df84
	if (cr6.eq) goto loc_8213DF84;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213DF80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_8213DF84:
	// lwz r4,77(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 77);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213dfa8
	if (cr6.eq) goto loc_8213DFA8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213DFA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
loc_8213DFA8:
	// lwz r4,69(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 69);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213dfcc
	if (cr6.eq) goto loc_8213DFCC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213DFC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
loc_8213DFCC:
	// lwz r4,73(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 73);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213dff0
	if (cr6.eq) goto loc_8213DFF0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8213DFEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
loc_8213DFF0:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213dbc0
	ctx.lr = 0x8213E000;
	sub_8213DBC0(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213e038
	if (!cr6.eq) goto loc_8213E038;
	// lhz r11,41(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 41);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8213e020
	if (!cr6.lt) goto loc_8213E020;
	// li r11,-1
	r11.s64 = -1;
loc_8213E020:
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213e038
	if (!cr6.eq) goto loc_8213E038;
	// lhz r11,39(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 39);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
loc_8213E038:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8213DED0) {
	__imp__sub_8213DED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E040) {
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
	ctx.lr = 0x8213E048;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x8213bc50
	ctx.lr = 0x8213E05C;
	sub_8213BC50(ctx, base);
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e09c
	if (cr6.eq) goto loc_8213E09C;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213e09c
	if (!cr6.eq) goto loc_8213E09C;
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r11,r9,6696
	r11.s64 = ctx.r9.s64 + 6696;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8213E09C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213E09C:
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e0f8
	if (cr6.eq) goto loc_8213E0F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ce68
	ctx.lr = 0x8213E0B4;
	sub_8213CE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213e158
	if (!cr6.eq) goto loc_8213E158;
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r9,6488
	r11.s64 = ctx.r9.s64 + 6488;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8213E0E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,3
	ctx.r6.s64 = 3;
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r6,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r6.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8213E0F8:
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e158
	if (cr6.eq) goto loc_8213E158;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213c3d0
	ctx.lr = 0x8213E114;
	sub_8213C3D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213e158
	if (!cr6.eq) goto loc_8213E158;
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r9,6488
	r11.s64 = ctx.r9.s64 + 6488;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8213E144;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,3
	ctx.r6.s64 = 3;
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r6,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r6.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8213E158:
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213e194
	if (!cr6.eq) goto loc_8213E194;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213c4c8
	ctx.lr = 0x8213E174;
	sub_8213C4C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213e194
	if (!cr6.eq) goto loc_8213E194;
	// lbz r11,58(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 58);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e194
	if (cr6.eq) goto loc_8213E194;
	// li r29,1
	r29.s64 = 1;
loc_8213E194:
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e228
	if (cr6.eq) goto loc_8213E228;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213c960
	ctx.lr = 0x8213E1AC;
	sub_8213C960(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213e228
	if (cr6.eq) goto loc_8213E228;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x8213E1C4;
	sub_821374B0(ctx, base);
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r11,r9,6384
	r11.s64 = ctx.r9.s64 + 6384;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8213E1F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8213e278
	if (!cr6.eq) goto loc_8213E278;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r9,r9,0,26,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r9,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r9.u8);
	// beq cr6,0x8213e248
	if (cr6.eq) goto loc_8213E248;
	// li r11,1
	r11.s64 = 1;
	// sth r11,66(r31)
	PPC_STORE_U16(r31.u32 + 66, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8213E228:
	// lhz r11,66(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 66);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8213e284
	if (!cr6.eq) goto loc_8213E284;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bgt cr6,0x8213e278
	if (cr6.gt) goto loc_8213E278;
loc_8213E248:
	// lbz r11,59(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r10,r10,6592
	ctx.r10.s64 = ctx.r10.s64 + 6592;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,66(r31)
	PPC_STORE_U16(r31.u32 + 66, ctx.r9.u16);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8213E278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213E278:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8213E284:
	// lbz r11,59(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r10,6800
	ctx.r10.s64 = ctx.r10.s64 + 6800;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8213E2AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8213e2cc
	if (!cr6.eq) goto loc_8213E2CC;
	// li r11,3
	r11.s64 = 3;
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8213E2CC:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213e2e0
	if (cr6.eq) goto loc_8213E2E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213dd48
	ctx.lr = 0x8213E2E0;
	sub_8213DD48(ctx, base);
loc_8213E2E0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8213E040) {
	__imp__sub_8213E040(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213E2EC) {
	__imp__sub_8213E2EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E2F0) {
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
	ctx.lr = 0x8213E2F8;
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
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e324
	if (cr6.eq) goto loc_8213E324;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8213E324:
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e340
	if (cr6.eq) goto loc_8213E340;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8213E340:
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213da88
	ctx.lr = 0x8213E354;
	sub_8213DA88(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// beq cr6,0x8213e3d4
	if (cr6.eq) goto loc_8213E3D4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137488
	ctx.lr = 0x8213E368;
	sub_82137488(ctx, base);
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// extsh r7,r3
	ctx.r7.s64 = ctx.r3.s16;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8213e3a4
	if (cr6.eq) goto loc_8213E3A4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r6,r11,7216
	ctx.r6.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 232);
	// lwz r11,200(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 200);
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r11,r9
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11444(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213e3a8
	goto loc_8213E3A8;
loc_8213E3A4:
	// li r11,0
	r11.s64 = 0;
loc_8213E3A8:
	// lbz r10,200(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// li r8,-1
	ctx.r8.s64 = -1;
	// sth r7,196(r11)
	PPC_STORE_U16(r11.u32 + 196, ctx.r7.u16);
	// rlwimi r10,r9,5,26,26
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x20) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFDF);
	// stw r8,188(r11)
	PPC_STORE_U32(r11.u32 + 188, ctx.r8.u32);
	// stb r10,200(r11)
	PPC_STORE_U8(r11.u32 + 200, ctx.r10.u8);
	// lwsync 
	// lbz r6,199(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// ori r5,r6,2
	ctx.r5.u64 = ctx.r6.u64 | 2;
	// stb r5,199(r11)
	PPC_STORE_U8(r11.u32 + 199, ctx.r5.u8);
loc_8213E3D4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8213E2F0) {
	__imp__sub_8213E2F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E3E0) {
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
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r10,r10,7216
	ctx.r10.s64 = ctx.r10.s64 + 7216;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213e430
	if (cr6.eq) goto loc_8213E430;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r8,232(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mulli r7,r9,11488
	ctx.r7.s64 = ctx.r9.s64 * 11488;
	// lwz r9,200(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r9,11444(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11444);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// b 0x8213e434
	goto loc_8213E434;
loc_8213E430:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8213E434:
	// lwz r9,188(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 188);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// stw r9,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r9.u32);
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// lwz r10,200(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// beq cr6,0x8213e468
	if (cr6.eq) goto loc_8213E468;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r10,r11
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r8,11444(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// b 0x8213e46c
	goto loc_8213E46C;
loc_8213E468:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8213E46C:
	// lbz r8,200(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 200);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r30,r8,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// beq cr6,0x8213e498
	if (cr6.eq) goto loc_8213E498;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// mulli r11,r8,11488
	r11.s64 = ctx.r8.s64 * 11488;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11444(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213e49c
	goto loc_8213E49C;
loc_8213E498:
	// li r11,0
	r11.s64 = 0;
loc_8213E49C:
	// lhz r11,196(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 196);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x8213E4A8;
	sub_821374B0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x8213da88
	ctx.lr = 0x8213E4BC;
	sub_8213DA88(ctx, base);
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

PPC_WEAK_FUNC(sub_8213E3E0) {
	__imp__sub_8213E3E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E4D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213E4D4) {
	__imp__sub_8213E4D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E4D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r7,72(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// addi r10,r11,7216
	ctx.r10.s64 = r11.s64 + 7216;
	// cmplwi cr6,r7,255
	cr6.compare<uint32_t>(ctx.r7.u32, 255, xer);
	// lwz r11,232(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// lwz r6,196(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// beq cr6,0x8213e510
	if (cr6.eq) goto loc_8213E510;
	// lbz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r8,r6,r7
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// lwz r9,11440(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// b 0x8213e514
	goto loc_8213E514;
loc_8213E510:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8213E514:
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lbz r8,6204(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 6204);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// bne cr6,0x8213e538
	if (!cr6.eq) goto loc_8213E538;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8213e55c
	goto loc_8213E55C;
loc_8213E538:
	// lbz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lwz r10,200(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + r11.u64;
	// mullw r9,r10,r8
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 11444);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r10,200(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 200);
	// rlwinm r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
loc_8213E55C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lbz r10,5(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213e5b0
	if (cr6.eq) goto loc_8213E5B0;
	// cmplwi cr6,r7,255
	cr6.compare<uint32_t>(ctx.r7.u32, 255, xer);
	// beq cr6,0x8213e5a0
	if (cr6.eq) goto loc_8213E5A0;
	// lbz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r6,r7
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + r11.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8213e5a4
	goto loc_8213E5A4;
loc_8213E5A0:
	// li r11,0
	r11.s64 = 0;
loc_8213E5A4:
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_8213E5B0:
	// lbz r11,57(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 57);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213e5d8
	if (cr6.eq) goto loc_8213E5D8;
	// lwz r10,12(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_8213E5D8:
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e5f0
	if (cr6.eq) goto loc_8213E5F0;
	// lwz r10,16(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_8213E5F0:
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e608
	if (cr6.eq) goto loc_8213E608;
	// lwz r10,20(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_8213E608:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213e620
	if (cr6.eq) goto loc_8213E620;
	// lwz r10,24(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_8213E620:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213e62c
	if (cr6.eq) goto loc_8213E62C;
	// stw r11,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, r11.u32);
loc_8213E62C:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213e63c
	if (cr6.eq) goto loc_8213E63C;
	// stw r11,16(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16, r11.u32);
loc_8213E63C:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213e64c
	if (cr6.eq) goto loc_8213E64C;
	// stw r11,20(r5)
	PPC_STORE_U32(ctx.r5.u32 + 20, r11.u32);
loc_8213E64C:
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213e65c
	if (cr6.eq) goto loc_8213E65C;
	// stw r11,24(r5)
	PPC_STORE_U32(ctx.r5.u32 + 24, r11.u32);
loc_8213E65C:
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213e66c
	if (!cr6.eq) goto loc_8213E66C;
	// b 0x8213dd48
	sub_8213DD48(ctx, base);
	return;
loc_8213E66C:
	// lbz r11,58(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 58);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,58(r3)
	PPC_STORE_U8(ctx.r3.u32 + 58, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213E4D8) {
	__imp__sub_8213E4D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213E67C) {
	__imp__sub_8213E67C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E680) {
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
	ctx.lr = 0x8213E688;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8213e844
	if (cr6.eq) goto loc_8213E844;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8213e844
	if (cr6.eq) goto loc_8213E844;
	// stw r30,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lhz r11,0(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// sth r11,60(r31)
	PPC_STORE_U16(r31.u32 + 60, r11.u16);
	// lhz r10,2(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 2);
	// sth r10,62(r31)
	PPC_STORE_U16(r31.u32 + 62, ctx.r10.u16);
	// lhz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// sth r9,64(r31)
	PPC_STORE_U16(r31.u32 + 64, ctx.r9.u16);
	// bl 0x8213af28
	ctx.lr = 0x8213E6D0;
	sub_8213AF28(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ded0
	ctx.lr = 0x8213E6E4;
	sub_8213DED0(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b0f0
	ctx.lr = 0x8213E6F4;
	sub_8213B0F0(ctx, base);
	// lbz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// stb r8,59(r31)
	PPC_STORE_U8(r31.u32 + 59, ctx.r8.u8);
	// bne cr6,0x8213e7f0
	if (!cr6.eq) goto loc_8213E7F0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b000
	ctx.lr = 0x8213E710;
	sub_8213B000(ctx, base);
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8213e844
	if (cr6.eq) goto loc_8213E844;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r5,199(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// ori r4,r5,28
	ctx.r4.u64 = ctx.r5.u64 | 28;
	// stb r4,199(r11)
	PPC_STORE_U8(r11.u32 + 199, ctx.r4.u8);
	// lbz r3,65(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// rlwinm r11,r3,0,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFC;
	// cmplwi cr6,r11,252
	cr6.compare<uint32_t>(r11.u32, 252, xer);
	// bne cr6,0x8213e828
	if (!cr6.eq) goto loc_8213E828;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8213e7a8
	if (!cr6.eq) goto loc_8213E7A8;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r11,7488(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 7488);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8213e7a0
	if (!cr6.eq) goto loc_8213E7A0;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r11,7488(r10)
	PPC_STORE_U32(ctx.r10.u32 + 7488, r11.u32);
	// addi r3,r9,11416
	ctx.r3.s64 = ctx.r9.s64 + 11416;
	// bl 0x821c9790
	ctx.lr = 0x8213E798;
	sub_821C9790(ctx, base);
	// stw r3,7484(r30)
	PPC_STORE_U32(r30.u32 + 7484, ctx.r3.u32);
	// b 0x8213e7a4
	goto loc_8213E7A4;
loc_8213E7A0:
	// lwz r3,7484(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 7484);
loc_8213E7A4:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8213E7A8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x8214a200
	ctx.lr = 0x8213E7B4;
	sub_8214A200(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213e828
	if (cr6.eq) goto loc_8213E828;
	// bl 0x82149530
	ctx.lr = 0x8213E7C0;
	sub_82149530(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213e7e0
	if (cr6.eq) goto loc_8213E7E0;
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,2,0,29
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 2) & 0xFFFFFFFC) | (r11.u64 & 0xFFFFFFFF00000003);
	// stb r11,65(r31)
	PPC_STORE_U8(r31.u32 + 65, r11.u8);
	// b 0x8213e828
	goto loc_8213E828;
loc_8213E7E0:
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// clrlwi r10,r11,30
	ctx.r10.u64 = r11.u32 & 0x3;
	// stb r10,65(r31)
	PPC_STORE_U8(r31.u32 + 65, ctx.r10.u8);
	// b 0x8213e828
	goto loc_8213E828;
loc_8213E7F0:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r7,65(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// addi r6,r10,7216
	ctx.r6.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 232);
	// lwz r10,196(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 196);
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r4,65(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 65);
	// rlwimi r4,r7,0,30,31
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r7.u32, 0) & 0x3) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFFC);
	// stb r4,65(r31)
	PPC_STORE_U8(r31.u32 + 65, ctx.r4.u8);
loc_8213E828:
	// lbz r11,5(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 5);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwimi r11,r10,0,24,30
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFE) | (r11.u64 & 0xFFFFFFFFFFFFFF01);
	// stb r11,57(r31)
	PPC_STORE_U8(r31.u32 + 57, r11.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_8213E844:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8213E680) {
	__imp__sub_8213E680(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E850) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r11,r11,11488
	r11.s64 = r11.s64 + 11488;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8213e874
	if (!cr6.lt) goto loc_8213E874;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,11776(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11776);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x8213e87c
	if (cr6.gt) goto loc_8213E87C;
loc_8213E874:
	// fcmpu cr6,f1,f1
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, ctx.f1.f64);
	// beq cr6,0x8213e894
	if (cr6.eq) goto loc_8213E894;
loc_8213E87C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r10,-16(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// sth r10,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r10.u16);
	// blr 
	return;
loc_8213E894:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x8213e8b0
	if (cr6.gt) goto loc_8213E8B0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,11772(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11772);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8213e8b4
	if (!cr6.lt) goto loc_8213E8B4;
loc_8213E8B0:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
loc_8213E8B4:
	// stfs f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r11,-16(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// rlwinm r10,r11,9,23,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1FF;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// rlwinm r9,r11,19,22,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x3FF;
	// rlwinm r8,r10,10,0,21
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0xFFFFFC00;
	// rlwinm r7,r11,16,16,16
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x8000;
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// sth r5,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r5.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213E850) {
	__imp__sub_8213E850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E8E0) {
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
	ctx.lr = 0x8213E8E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,236(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// bl 0x82144a78
	ctx.lr = 0x8213E904;
	sub_82144A78(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// lwz r4,232(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r31,236(r30)
	PPC_STORE_U32(r30.u32 + 236, r31.u32);
	// bl 0x82144a78
	ctx.lr = 0x8213E918;
	sub_82144A78(ctx, base);
	// stw r31,232(r30)
	PPC_STORE_U32(r30.u32 + 232, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8213E8E0) {
	__imp__sub_8213E8E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213E924) {
	__imp__sub_8213E924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213E928) {
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
	ctx.lr = 0x8213E930;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mulli r31,r5,11488
	r31.s64 = ctx.r5.s64 * 11488;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,11452
	ctx.r4.s64 = r11.s64 + 11452;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8213E954;
	sub_821C8FE0(ctx, base);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r10,212(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r5,196(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lbz r9,11437(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 11437);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213ea10
	if (cr6.eq) goto loc_8213EA10;
	// rlwinm r30,r10,27,5,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8213ea10
	if (cr6.eq) goto loc_8213EA10;
	// addi r8,r11,11328
	ctx.r8.s64 = r11.s64 + 11328;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r31,255
	r31.s64 = 255;
	// lis r4,255
	ctx.r4.s64 = 16711680;
loc_8213E990:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bge cr6,0x8213ea00
	if (!cr6.lt) goto loc_8213EA00;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// bge cr6,0x8213e9c0
	if (!cr6.lt) goto loc_8213E9C0;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// subfc r6,r31,r9
	xer.ca = ctx.r9.u32 >= r31.u32;
	ctx.r6.s64 = ctx.r9.s64 - r31.s64;
	// subfe r9,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r9,r9,0,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r6,r9,8
	ctx.r6.s64 = ctx.r9.s64 + 8;
	// b 0x8213e9d4
	goto loc_8213E9D4;
loc_8213E9C0:
	// rlwinm r9,r10,0,8,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFF0000;
	// subfc r6,r4,r9
	xer.ca = ctx.r9.u32 >= ctx.r4.u32;
	ctx.r6.s64 = ctx.r9.s64 - ctx.r4.s64;
	// subfe r9,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r9,r9,0,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r6,r9,24
	ctx.r6.s64 = ctx.r9.s64 + 24;
loc_8213E9D4:
	// srw r10,r10,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r6.u8 & 0x3F));
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8213E9E0:
	// clrlwi r28,r10,24
	r28.u64 = ctx.r10.u32 & 0xFF;
	// srw r28,r9,r28
	r28.u64 = r28.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (r28.u8 & 0x3F));
	// clrlwi r28,r28,31
	r28.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8213ea24
	if (cr6.eq) goto loc_8213EA24;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// blt cr6,0x8213e9e0
	if (cr6.lt) goto loc_8213E9E0;
loc_8213EA00:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// blt cr6,0x8213e990
	if (cr6.lt) goto loc_8213E990;
loc_8213EA10:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8213EA18;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8213EA24:
	// addi r9,r3,2832
	ctx.r9.s64 = ctx.r3.s64 + 2832;
	// addi r8,r3,2840
	ctx.r8.s64 = ctx.r3.s64 + 2840;
	// addi r4,r3,2848
	ctx.r4.s64 = ctx.r3.s64 + 2848;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r10,r10,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r6.u8 & 0x3F));
	// lwzx r4,r7,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// lwzx r30,r9,r11
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// clrlwi r31,r29,24
	r31.u64 = r29.u32 & 0xFF;
	// not r28,r10
	r28.u64 = ~ctx.r10.u64;
	// lwzx r29,r8,r11
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// or r27,r10,r4
	r27.u64 = ctx.r10.u64 | ctx.r4.u64;
	// and r4,r30,r28
	ctx.r4.u64 = r30.u64 & r28.u64;
	// and r30,r28,r29
	r30.u64 = r28.u64 & r29.u64;
	// stwx r27,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, r27.u32);
	// stwx r4,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r4.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stwx r30,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, r30.u32);
	// beq cr6,0x8213ea84
	if (cr6.eq) goto loc_8213EA84;
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// stwx r10,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r10.u32);
loc_8213EA84:
	// lbz r8,11437(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 11437);
	// rlwinm r10,r3,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r9,11440(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r8,r8,255
	ctx.r8.s64 = ctx.r8.s64 + 255;
	// add r7,r10,r6
	ctx.r7.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stb r8,11437(r11)
	PPC_STORE_U8(r11.u32 + 11437, ctx.r8.u8);
	// mullw r10,r7,r5
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// add r31,r10,r9
	r31.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244d150
	ctx.lr = 0x8213EAB0;
	sub_8244D150(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8213EAB8;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8213E928) {
	__imp__sub_8213E928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213EAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213EAC4) {
	__imp__sub_8213EAC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213EAC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r9,r4,2872
	ctx.r9.s64 = ctx.r4.s64 * 2872;
	// lwz r10,232(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// rlwinm r11,r5,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// li r6,1
	ctx.r6.s64 = 1;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r9,r5,0,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFE0;
	// addi r8,r11,2848
	ctx.r8.s64 = r11.s64 + 2848;
	// subf r7,r9,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r9.s64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r5,r6,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r7.u8 & 0x3F));
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stwx r3,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213EAC8) {
	__imp__sub_8213EAC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213EB00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x8213EB08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mulli r31,r5,11488
	r31.s64 = ctx.r5.s64 * 11488;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,11452
	ctx.r4.s64 = r11.s64 + 11452;
	// bl 0x821c8fe0
	ctx.lr = 0x8213EB28;
	sub_821C8FE0(ctx, base);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r10,216(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// lwz r5,200(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lbz r11,11438(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 11438);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213ebe4
	if (cr6.eq) goto loc_8213EBE4;
	// rlwinm r30,r10,27,5,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8213ebe4
	if (cr6.eq) goto loc_8213EBE4;
	// addi r6,r8,11424
	ctx.r6.s64 = ctx.r8.s64 + 11424;
	// li r4,-1
	ctx.r4.s64 = -1;
	// li r31,255
	r31.s64 = 255;
	// lis r3,255
	ctx.r3.s64 = 16711680;
loc_8213EB64:
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bge cr6,0x8213ebd4
	if (!cr6.lt) goto loc_8213EBD4;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// bge cr6,0x8213eb94
	if (!cr6.lt) goto loc_8213EB94;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// subfc r9,r31,r10
	xer.ca = ctx.r10.u32 >= r31.u32;
	ctx.r9.s64 = ctx.r10.s64 - r31.s64;
	// subfe r10,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r10,r10,0,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// b 0x8213eba8
	goto loc_8213EBA8;
loc_8213EB94:
	// rlwinm r10,r11,0,8,15
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFF0000;
	// subfc r9,r3,r10
	xer.ca = ctx.r10.u32 >= ctx.r3.u32;
	ctx.r9.s64 = ctx.r10.s64 - ctx.r3.s64;
	// subfe r10,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r10,r10,0,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
loc_8213EBA8:
	// srw r11,r11,r10
	r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (r11.u32 >> (ctx.r10.u8 & 0x3F));
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
loc_8213EBB4:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// srw r29,r9,r29
	r29.u64 = r29.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (r29.u8 & 0x3F));
	// clrlwi r29,r29,31
	r29.u64 = r29.u32 & 0x1;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8213ebf8
	if (cr6.eq) goto loc_8213EBF8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// blt cr6,0x8213ebb4
	if (cr6.lt) goto loc_8213EBB4;
loc_8213EBD4:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r7,r30
	cr6.compare<uint32_t>(ctx.r7.u32, r30.u32, xer);
	// blt cr6,0x8213eb64
	if (cr6.lt) goto loc_8213EB64;
loc_8213EBE4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8213EBEC;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8213EBF8:
	// addi r9,r7,2856
	ctx.r9.s64 = ctx.r7.s64 + 2856;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,1
	ctx.r6.s64 = 1;
	// rlwinm r9,r7,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// slw r4,r6,r11
	ctx.r4.u64 = r11.u8 & 0x20 ? 0 : (ctx.r6.u32 << (r11.u8 & 0x3F));
	// lwzx r3,r10,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// or r9,r4,r3
	ctx.r9.u64 = ctx.r4.u64 | ctx.r3.u64;
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// stwx r9,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r9.u32);
	// lwz r10,11444(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11444);
	// lbz r9,11438(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 11438);
	// addi r7,r9,255
	ctx.r7.s64 = ctx.r9.s64 + 255;
	// stb r7,11438(r8)
	PPC_STORE_U8(ctx.r8.u32 + 11438, ctx.r7.u8);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244d150
	ctx.lr = 0x8213EC44;
	sub_8244D150(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8213EC4C;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8213EB00) {
	__imp__sub_8213EB00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213EC58) {
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
	// lwz r11,232(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// mulli r10,r4,11488
	ctx.r10.s64 = ctx.r4.s64 * 11488;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,11452
	ctx.r4.s64 = r31.s64 + 11452;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8213EC88;
	sub_821C8FE0(ctx, base);
	// rlwinm r11,r30,27,5,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r10,r30,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFE0;
	// addi r9,r11,2856
	ctx.r9.s64 = r11.s64 + 2856;
	// subf r8,r10,r30
	ctx.r8.s64 = r30.s64 - ctx.r10.s64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// slw r6,r7,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r8.u8 & 0x3F));
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// andc r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 & ~ctx.r6.u64;
	// stwx r4,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r4.u32);
	// lbz r11,11438(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11438);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r11,11438(r31)
	PPC_STORE_U8(r31.u32 + 11438, r11.u8);
	// bl 0x821c9030
	ctx.lr = 0x8213ECC4;
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

PPC_WEAK_FUNC(sub_8213EC58) {
	__imp__sub_8213EC58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213ECDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213ECDC) {
	__imp__sub_8213ECDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213ECE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,232(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// mulli r10,r4,11488
	ctx.r10.s64 = ctx.r4.s64 * 11488;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r10,r11,r5
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r5.u32);
	// ori r9,r10,4
	ctx.r9.u64 = ctx.r10.u64 | 4;
	// stbx r9,r11,r5
	PPC_STORE_U8(r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213ECE0) {
	__imp__sub_8213ECE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213ECFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213ECFC) {
	__imp__sub_8213ECFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213ED00) {
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
	ctx.lr = 0x8213ED08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mulli r31,r30,11488
	r31.s64 = r30.s64 * 11488;
	// lwz r11,232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 232);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,11452
	ctx.r3.s64 = r11.s64 + 11452;
	// bl 0x821c8f08
	ctx.lr = 0x8213ED28;
	sub_821C8F08(ctx, base);
	// lwz r11,232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 232);
	// rlwinm r9,r30,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lbz r10,11448(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11448);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stb r8,11448(r11)
	PPC_STORE_U8(r11.u32 + 11448, ctx.r8.u8);
	// addi r30,r10,1
	r30.s64 = ctx.r10.s64 + 1;
	// lwz r11,232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 232);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,11452
	ctx.r3.s64 = r11.s64 + 11452;
	// bl 0x821c8f70
	ctx.lr = 0x8213ED58;
	sub_821C8F70(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8213ED00) {
	__imp__sub_8213ED00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213ED64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213ED64) {
	__imp__sub_8213ED64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213ED68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,192(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 192);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stbx r4,r11,r3
	PPC_STORE_U8(r11.u32 + ctx.r3.u32, ctx.r4.u8);
	// lbz r11,192(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 192);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// stb r5,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r5.u8);
	// lbz r11,192(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 192);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// stb r6,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, ctx.r6.u8);
	// lbz r11,192(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 192);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stb r8,192(r3)
	PPC_STORE_U8(ctx.r3.u32 + 192, ctx.r8.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213ED68) {
	__imp__sub_8213ED68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213EDB0) {
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
	ctx.lr = 0x8213EDB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213ee2c
	if (cr6.eq) goto loc_8213EE2C;
	// addi r30,r31,1
	r30.s64 = r31.s64 + 1;
loc_8213EDD8:
	// lbz r11,-1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -1);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213ee18
	if (cr6.eq) goto loc_8213EE18;
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213ee18
	if (cr6.eq) goto loc_8213EE18;
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r28,11488
	r11.s64 = r28.s64 * 11488;
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8214ab58
	ctx.lr = 0x8213EE18;
	sub_8214AB58(ctx, base);
loc_8213EE18:
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,3
	r30.s64 = r30.s64 + 3;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8213edd8
	if (cr6.lt) goto loc_8213EDD8;
loc_8213EE2C:
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213ee90
	if (cr6.eq) goto loc_8213EE90;
	// addi r30,r31,1
	r30.s64 = r31.s64 + 1;
loc_8213EE40:
	// lbz r11,-1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -1);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213ee7c
	if (cr6.eq) goto loc_8213EE7C;
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213ee7c
	if (!cr6.eq) goto loc_8213EE7C;
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r28,11488
	r11.s64 = r28.s64 * 11488;
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8214a700
	ctx.lr = 0x8213EE7C;
	sub_8214A700(ctx, base);
loc_8213EE7C:
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,3
	r30.s64 = r30.s64 + 3;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8213ee40
	if (cr6.lt) goto loc_8213EE40;
loc_8213EE90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8213EDB0) {
	__imp__sub_8213EDB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213EE98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// lwz r9,204(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 204);
	// lwz r7,224(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	// subf. r7,r7,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// lwz r10,232(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// addi r9,r10,11437
	ctx.r9.s64 = ctx.r10.s64 + 11437;
loc_8213EEC0:
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x8213eed4
	if (!cr6.gt) goto loc_8213EED4;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_8213EED4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 + 11488;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x8213eec0
	if (cr6.lt) goto loc_8213EEC0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213EE98) {
	__imp__sub_8213EE98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213EEE8) {
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
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8213EEF0;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9d8
	ctx.lr = 0x8213EEF8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r23,0
	r23.s64 = 0;
	// mulli r29,r4,11488
	r29.s64 = ctx.r4.s64 * 11488;
	// lfs f28,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f28.f64 = double(temp.f32);
	// lfs f29,8876(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8876);
	f29.f64 = double(temp.f32);
	// lfs f30,8880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8880);
	f30.f64 = double(temp.f32);
	// lfs f31,8884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8884);
	f31.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r24,r29,7776
	r24.s64 = r29.s64 + 7776;
	// mr r31,r23
	r31.u64 = r23.u64;
	// mr r25,r23
	r25.u64 = r23.u64;
	// li r20,-1
	r20.s64 = -1;
	// li r21,-8
	r21.s64 = -8;
	// addi r22,r11,11780
	r22.s64 = r11.s64 + 11780;
loc_8213EF44:
	// lwz r10,232(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 232);
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// add r26,r24,r10
	r26.u64 = r24.u64 + ctx.r10.u64;
	// add r10,r25,r11
	ctx.r10.u64 = r25.u64 + r11.u64;
	// addi r30,r10,96
	r30.s64 = ctx.r10.s64 + 96;
	// lbzx r11,r11,r31
	r11.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213efd8
	if (cr6.eq) goto loc_8213EFD8;
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// stb r10,24(r30)
	PPC_STORE_U8(r30.u32 + 24, ctx.r10.u8);
	// lwz r9,16(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// rlwinm r8,r9,0,0,1
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC0000000;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8213f134
	if (!cr6.eq) goto loc_8213F134;
	// lwz r11,232(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 232);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8213efb0
	if (!cr6.eq) goto loc_8213EFB0;
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// lhz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 116);
	// extsh r3,r10
	ctx.r3.s64 = ctx.r10.s16;
	// bl 0x821374b0
	ctx.lr = 0x8213EFAC;
	sub_821374B0(ctx, base);
	// bl 0x821377e0
	ctx.lr = 0x8213EFB0;
	sub_821377E0(ctx, base);
loc_8213EFB0:
	// lwz r11,232(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 232);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stbx r23,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, r23.u8);
	// lwz r11,232(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 232);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r10,r11,11439
	ctx.r10.s64 = r11.s64 + 11439;
	// lbz r10,11439(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11439);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r10,11439(r11)
	PPC_STORE_U8(r11.u32 + 11439, ctx.r10.u8);
	// b 0x8213f134
	goto loc_8213F134;
loc_8213EFD8:
	// lwz r11,232(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 232);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213f134
	if (cr6.eq) goto loc_8213F134;
	// lwz r11,232(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 232);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r31.u32);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,31,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stbx r9,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r9.u8);
	// lhz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 20);
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// bl 0x821374b0
	ctx.lr = 0x8213F014;
	sub_821374B0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82137798
	ctx.lr = 0x8213F01C;
	sub_82137798(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x821380c8
	ctx.lr = 0x8213F028;
	sub_821380C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213f118
	if (cr6.eq) goto loc_8213F118;
	// lhz r11,26(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 26);
	// sth r11,22(r30)
	PPC_STORE_U16(r30.u32 + 22, r11.u16);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lhz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f10,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fdivs f7,f8,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 / ctx.f11.f64));
	// fsel f6,f7,f30,f29
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f30.f64 : f29.f64;
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fadds f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// fsubs f3,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 - ctx.f4.f64));
	// fsubs f2,f4,f28
	ctx.f2.f64 = double(float(ctx.f4.f64 - f28.f64));
	// fsel f1,f3,f4,f2
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f2.f64;
	// fctidz f0,f1
	f0.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfiwx f0,0,r26
	PPC_STORE_U32(r26.u32, f0.u32);
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8213f0a0
	if (!cr6.eq) goto loc_8213F0A0;
	// mr r11,r20
	r11.u64 = r20.u64;
	// b 0x8213f0f8
	goto loc_8213F0F8;
loc_8213F0A0:
	// lhz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// std r8,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// lfd f12,104(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fdivs f7,f10,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 / ctx.f8.f64));
	// fsel f6,f7,f30,f29
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f30.f64 : f29.f64;
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fadds f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// fsubs f3,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 - ctx.f4.f64));
	// fsubs f2,f4,f28
	ctx.f2.f64 = double(float(ctx.f4.f64 - f28.f64));
	// fsel f1,f3,f4,f2
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f2.f64;
	// fctidz f0,f1
	f0.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, f0.u64);
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
loc_8213F0F8:
	// stw r11,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r11.u32);
	// lbz r11,72(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213f134
	if (cr6.eq) goto loc_8213F134;
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// stb r10,24(r30)
	PPC_STORE_U8(r30.u32 + 24, ctx.r10.u8);
	// b 0x8213f134
	goto loc_8213F134;
loc_8213F118:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x82130000
	ctx.lr = 0x8213F128;
	sub_82130000(ctx, base);
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// or r10,r11,r21
	ctx.r10.u64 = r11.u64 | r21.u64;
	// stw r10,8(r26)
	PPC_STORE_U32(r26.u32 + 8, ctx.r10.u32);
loc_8213F134:
	// addi r25,r25,80
	r25.s64 = r25.s64 + 80;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r24,r24,32
	r24.s64 = r24.s64 + 32;
	// cmplwi cr6,r25,7680
	cr6.compare<uint32_t>(r25.u32, 7680, xer);
	// blt cr6,0x8213ef44
	if (cr6.lt) goto loc_8213EF44;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba24
	ctx.lr = 0x8213F154;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_8213EEE8) {
	__imp__sub_8213EEE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F158) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,232(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// mulli r10,r4,-11488
	ctx.r10.s64 = ctx.r4.s64 * -11488;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// li r9,80
	ctx.r9.s64 = 80;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r8,r11,-96
	ctx.r8.s64 = r11.s64 + -96;
	// divw r3,r8,r9
	ctx.r3.s32 = ctx.r8.s32 / ctx.r9.s32;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213F158) {
	__imp__sub_8213F158(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F178) {
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
	ctx.lr = 0x8213F180;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r6,127
	ctx.r3.s64 = ctx.r6.s64 + 127;
	// addi r11,r5,31
	r11.s64 = ctx.r5.s64 + 31;
	// addi r10,r4,127
	ctx.r10.s64 = ctx.r4.s64 + 127;
	// addi r4,r7,31
	ctx.r4.s64 = ctx.r7.s64 + 31;
	// rlwinm r6,r3,0,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFF80;
	// stw r9,224(r31)
	PPC_STORE_U32(r31.u32 + 224, ctx.r9.u32);
	// rlwinm r3,r11,0,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// stw r5,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r5.u32);
	// rlwinm r11,r4,0,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFE0;
	// stw r7,216(r31)
	PPC_STORE_U32(r31.u32 + 216, ctx.r7.u32);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// stw r3,212(r31)
	PPC_STORE_U32(r31.u32 + 212, ctx.r3.u32);
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// stw r11,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r11.u32);
	// li r28,0
	r28.s64 = 0;
	// stw r8,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r8.u32);
	// stw r10,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r10.u32);
	// mullw r11,r6,r7
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// stw r6,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r6.u32);
	// stw r28,236(r31)
	PPC_STORE_U32(r31.u32 + 236, r28.u32);
	// stw r9,228(r31)
	PPC_STORE_U32(r31.u32 + 228, ctx.r9.u32);
	// mullw r25,r10,r5
	r25.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// add r26,r11,r25
	r26.u64 = r11.u64 + r25.u64;
	// addi r30,r7,19856
	r30.s64 = ctx.r7.s64 + 19856;
	// mullw r4,r26,r8
	ctx.r4.s64 = int64_t(r26.s32) * int64_t(ctx.r8.s32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// bl 0x82144a60
	ctx.lr = 0x8213F1FC;
	sub_82144A60(ctx, base);
	// stw r3,236(r31)
	PPC_STORE_U32(r31.u32 + 236, ctx.r3.u32);
	// lwz r6,204(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// mulli r4,r6,11488
	ctx.r4.s64 = ctx.r6.s64 * 11488;
	// bl 0x82144a60
	ctx.lr = 0x8213F214;
	sub_82144A60(ctx, base);
	// lwz r5,204(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// stw r3,232(r31)
	PPC_STORE_U32(r31.u32 + 232, ctx.r3.u32);
	// mr r27,r28
	r27.u64 = r28.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// ble cr6,0x8213f34c
	if (!cr6.gt) goto loc_8213F34C;
	// mr r30,r28
	r30.u64 = r28.u64;
	// mr r29,r28
	r29.u64 = r28.u64;
	// li r24,96
	r24.s64 = 96;
loc_8213F234:
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lwz r10,236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// stw r10,11440(r11)
	PPC_STORE_U32(r11.u32 + 11440, ctx.r10.u32);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,11440(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// add r9,r10,r25
	ctx.r9.u64 = ctx.r10.u64 + r25.u64;
	// stw r9,11444(r11)
	PPC_STORE_U32(r11.u32 + 11444, ctx.r9.u32);
	// lwz r8,208(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r7,r11,r30
	ctx.r7.u64 = r11.u64 + r30.u64;
	// stb r8,11437(r7)
	PPC_STORE_U8(ctx.r7.u32 + 11437, ctx.r8.u8);
	// lwz r5,216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// stb r5,11438(r4)
	PPC_STORE_U8(ctx.r4.u32 + 11438, ctx.r5.u8);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stb r24,11439(r11)
	PPC_STORE_U8(r11.u32 + 11439, r24.u8);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// addic. r3,r10,11452
	xer.ca = ctx.r10.u32 > 4294955843;
	ctx.r3.s64 = ctx.r10.s64 + 11452;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8213f29c
	if (cr0.eq) goto loc_8213F29C;
	// bl 0x821c8ed8
	ctx.lr = 0x8213F29C;
	sub_821C8ED8(ctx, base);
loc_8213F29C:
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stb r28,11448(r11)
	PPC_STORE_U8(r11.u32 + 11448, r28.u8);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r3,r11,11328
	ctx.r3.s64 = r11.s64 + 11328;
	// bl 0x8244d150
	ctx.lr = 0x8213F2C0;
	sub_8244D150(ctx, base);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// li r5,32
	ctx.r5.s64 = 32;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,11360
	ctx.r3.s64 = r11.s64 + 11360;
	// bl 0x8244d150
	ctx.lr = 0x8213F2D8;
	sub_8244D150(ctx, base);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// li r5,32
	ctx.r5.s64 = 32;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,11392
	ctx.r3.s64 = r11.s64 + 11392;
	// bl 0x8244d150
	ctx.lr = 0x8213F2F0;
	sub_8244D150(ctx, base);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// li r5,12
	ctx.r5.s64 = 12;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,11424
	ctx.r3.s64 = r11.s64 + 11424;
	// bl 0x8244d150
	ctx.lr = 0x8213F308;
	sub_8244D150(ctx, base);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// li r5,96
	ctx.r5.s64 = 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8244d150
	ctx.lr = 0x8213F31C;
	sub_8244D150(ctx, base);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// add r29,r29,r26
	r29.u64 = r29.u64 + r26.u64;
	// stb r28,11436(r10)
	PPC_STORE_U8(ctx.r10.u32 + 11436, r28.u8);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// addi r30,r30,11488
	r30.s64 = r30.s64 + 11488;
	// stb r28,11449(r9)
	PPC_STORE_U8(ctx.r9.u32 + 11449, r28.u8);
	// lwz r8,204(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// cmplw cr6,r27,r8
	cr6.compare<uint32_t>(r27.u32, ctx.r8.u32, xer);
	// blt cr6,0x8213f234
	if (cr6.lt) goto loc_8213F234;
loc_8213F34C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8213F178) {
	__imp__sub_8213F178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213F354) {
	__imp__sub_8213F354(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8213F360;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mulli r27,r4,11488
	r27.s64 = ctx.r4.s64 * 11488;
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,11452
	ctx.r4.s64 = r11.s64 + 11452;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// li r23,0
	r23.s64 = 0;
	// bl 0x821c8fe0
	ctx.lr = 0x8213F38C;
	sub_821C8FE0(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// li r21,0
	r21.s64 = 0;
	// rlwinm r10,r11,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213f4a0
	if (cr6.eq) goto loc_8213F4A0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r28,0
	r28.s64 = 0;
	// addi r26,r27,11360
	r26.s64 = r27.s64 + 11360;
	// addi r29,r11,7216
	r29.s64 = r11.s64 + 7216;
loc_8213F3B0:
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r10,r26,r11
	ctx.r10.u64 = r26.u64 + r11.u64;
	// add r9,r26,r11
	ctx.r9.u64 = r26.u64 + r11.u64;
	// lwzx r22,r26,r11
	r22.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// lwz r25,-32(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32);
	// lwz r24,32(r9)
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// and r8,r24,r25
	ctx.r8.u64 = r24.u64 & r25.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8213f484
	if (cr6.eq) goto loc_8213F484;
	// li r30,0
	r30.s64 = 0;
loc_8213F3D8:
	// srw r11,r25,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r25.u32 >> (r30.u8 & 0x3F));
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213f478
	if (cr6.eq) goto loc_8213F478;
	// srw r11,r24,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r24.u32 >> (r30.u8 & 0x3F));
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213f478
	if (cr6.eq) goto loc_8213F478;
	// srw r11,r22,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r22.u32 >> (r30.u8 & 0x3F));
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213f478
	if (!cr6.eq) goto loc_8213F478;
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r10,r28,r30
	ctx.r10.u64 = r28.u64 + r30.u64;
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r8,r11,r27
	ctx.r8.u64 = r11.u64 + r27.u64;
	// mullw r11,r10,r9
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lbz r7,56(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 56);
	// rlwinm r6,r7,0,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8213f478
	if (cr6.eq) goto loc_8213F478;
	// lbz r9,5(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8213f468
	if (cr6.eq) goto loc_8213F468;
	// lbz r11,64(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 64);
	// lwz r10,232(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r8,196(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213f478
	if (!cr6.eq) goto loc_8213F478;
loc_8213F468:
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r20
	ctr.u64 = r20.u64;
	// bctrl 
	ctx.lr = 0x8213F474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
loc_8213F478:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r30,32
	cr6.compare<uint32_t>(r30.u32, 32, xer);
	// blt cr6,0x8213f3d8
	if (cr6.lt) goto loc_8213F3D8;
loc_8213F484:
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// addi r28,r28,32
	r28.s64 = r28.s64 + 32;
	// cmplw cr6,r21,r10
	cr6.compare<uint32_t>(r21.u32, ctx.r10.u32, xer);
	// blt cr6,0x8213f3b0
	if (cr6.lt) goto loc_8213F3B0;
loc_8213F4A0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8213F4A8;
	sub_821C9030(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_8213F358) {
	__imp__sub_8213F358(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213F4B4) {
	__imp__sub_8213F4B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F4B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,232(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// mulli r10,r4,11488
	ctx.r10.s64 = ctx.r4.s64 * 11488;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r10,11436(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11436);
	// cmplwi cr6,r10,12
	cr6.compare<uint32_t>(ctx.r10.u32, 12, xer);
	// bge cr6,0x8213f594
	if (!cr6.lt) goto loc_8213F594;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// stb r3,10884(r10)
	PPC_STORE_U8(ctx.r10.u32 + 10884, ctx.r3.u8);
	// lbz r10,11436(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11436);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// stb r4,10885(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10885, ctx.r4.u8);
	// lbz r10,11436(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11436);
	// addi r10,r10,272
	ctx.r10.s64 = ctx.r10.s64 + 272;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stwx r6,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r6.u32);
	// lhz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// lbz r10,11436(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11436);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r3,r10,10848
	ctx.r3.s64 = ctx.r10.s64 + 10848;
	// sth r6,10848(r10)
	PPC_STORE_U16(ctx.r10.u32 + 10848, ctx.r6.u16);
	// lhz r8,2(r7)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// sth r8,10850(r10)
	PPC_STORE_U16(ctx.r10.u32 + 10850, ctx.r8.u16);
	// lhz r7,4(r7)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// sth r7,10852(r10)
	PPC_STORE_U16(ctx.r10.u32 + 10852, ctx.r7.u16);
	// lbz r10,11436(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11436);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r10,10856
	ctx.r10.s64 = ctx.r10.s64 + 10856;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8213F570:
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8213f570
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8213F570;
	// lbz r10,11436(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11436);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r10,11436(r11)
	PPC_STORE_U8(r11.u32 + 11436, ctx.r10.u8);
	// blr 
	return;
loc_8213F594:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,11816
	ctx.r3.s64 = r11.s64 + 11816;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8213F4B8) {
	__imp__sub_8213F4B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F5A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r9,23900
	ctx.r9.s64 = 23900;
	// li r8,-1
	ctx.r8.s64 = -1;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r3,r31,26
	ctx.r3.s64 = r31.s64 + 26;
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// stfs f30,0(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// sth r9,16(r31)
	PPC_STORE_U16(r31.u32 + 16, ctx.r9.u16);
	// sth r30,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r30.u16);
	// sth r8,20(r31)
	PPC_STORE_U16(r31.u32 + 20, ctx.r8.u16);
	// sth r30,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r30.u16);
	// bl 0x8213e850
	ctx.lr = 0x8213F608;
	sub_8213E850(ctx, base);
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8213e850
	ctx.lr = 0x8213F614;
	sub_8213E850(ctx, base);
	// addi r3,r31,30
	ctx.r3.s64 = r31.s64 + 30;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213e850
	ctx.lr = 0x8213F620;
	sub_8213E850(ctx, base);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213e850
	ctx.lr = 0x8213F62C;
	sub_8213E850(ctx, base);
	// addi r8,r31,34
	ctx.r8.s64 = r31.s64 + 34;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,5
	r11.s64 = 5;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// clrlwi r9,r7,16
	ctx.r9.u64 = ctx.r7.u32 & 0xFFFF;
loc_8213F644:
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bge 0x8213f644
	if (!cr0.lt) goto loc_8213F644;
	// addi r7,r31,46
	ctx.r7.s64 = r31.s64 + 46;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,11
	r11.s64 = 11;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
loc_8213F66C:
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bge 0x8213f66c
	if (!cr0.lt) goto loc_8213F66C;
	// li r11,255
	r11.s64 = 255;
	// stb r30,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r30.u8);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stb r11,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r11.u8);
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// li r11,6
	r11.s64 = 6;
loc_8213F694:
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bne 0x8213f694
	if (!cr0.eq) goto loc_8213F694;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// li r8,3
	ctx.r8.s64 = 3;
loc_8213F6B4:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// li r11,4
	r11.s64 = 4;
loc_8213F6BC:
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r7,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r7.u16);
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// bne 0x8213f6bc
	if (!cr0.eq) goto loc_8213F6BC;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bne 0x8213f6b4
	if (!cr0.eq) goto loc_8213F6B4;
	// li r11,129
	r11.s64 = 129;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
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

PPC_WEAK_FUNC(sub_8213F5A0) {
	__imp__sub_8213F5A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213F70C) {
	__imp__sub_8213F70C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// addi r8,r10,7216
	ctx.r8.s64 = ctx.r10.s64 + 7216;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r9,232(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// lwz r8,200(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 200);
	// bne cr6,0x8213f734
	if (!cr6.eq) goto loc_8213F734;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8213f754
	goto loc_8213F754;
loc_8213F734:
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lbz r5,200(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 200);
	// rlwinm r10,r5,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x1;
loc_8213F754:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213f798
	if (!cr6.eq) goto loc_8213F798;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8213f78c
	if (cr6.eq) goto loc_8213F78C;
	// lbz r7,64(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// mulli r11,r7,11488
	r11.s64 = ctx.r7.s64 * 11488;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11444(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r5,184(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8213f798
	if (!cr6.eq) goto loc_8213F798;
loc_8213F78C:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_8213F798:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213F710) {
	__imp__sub_8213F710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F7A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213F7A4) {
	__imp__sub_8213F7A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F7A8) {
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
	ctx.lr = 0x8213F7B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mulli r28,r26,11488
	r28.s64 = r26.s64 * 11488;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,11452
	ctx.r4.s64 = r11.s64 + 11452;
	// bl 0x821c8fe0
	ctx.lr = 0x8213F7D8;
	sub_821C8FE0(ctx, base);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r7,196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// li r9,1
	ctx.r9.s64 = 1;
	// add r31,r28,r11
	r31.u64 = r28.u64 + r11.u64;
	// twllei r7,0
	// lwz r8,11440(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 11440);
	// subf r6,r8,r24
	ctx.r6.s64 = r24.s64 - ctx.r8.s64;
	// divwu r29,r6,r7
	r29.u32 = ctx.r6.u32 / ctx.r7.u32;
	// rlwinm r11,r29,27,5,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r5,r29,0,0,26
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFFFE0;
	// addi r4,r11,2832
	ctx.r4.s64 = r11.s64 + 2832;
	// subf r27,r5,r29
	r27.s64 = r29.s64 - ctx.r5.s64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r3,r9,r27
	ctx.r3.u64 = r27.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r27.u8 & 0x3F));
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// addi r8,r11,2840
	ctx.r8.s64 = r11.s64 + 2840;
	// andc r7,r9,r3
	ctx.r7.u64 = ctx.r9.u64 & ~ctx.r3.u64;
	// rlwinm r25,r8,2,0,29
	r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r7.u32);
	// lbz r11,11437(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11437);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stb r6,11437(r31)
	PPC_STORE_U8(r31.u32 + 11437, ctx.r6.u8);
	// lwzx r4,r25,r31
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + r31.u32);
	// srw r3,r4,r27
	ctx.r3.u64 = r27.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (r27.u8 & 0x3F));
	// clrlwi r11,r3,31
	r11.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213f870
	if (!cr6.eq) goto loc_8213F870;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8213f710
	ctx.lr = 0x8213F84C;
	sub_8213F710(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213f870
	if (cr6.eq) goto loc_8213F870;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// addi r3,r10,11964
	ctx.r3.s64 = ctx.r10.s64 + 11964;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82130000
	ctx.lr = 0x8213F870;
	sub_82130000(ctx, base);
loc_8213F870:
	// lwzx r11,r25,r31
	r11.u64 = PPC_LOAD_U32(r25.u32 + r31.u32);
	// srw r10,r11,r27
	ctx.r10.u64 = r27.u8 & 0x20 ? 0 : (r11.u32 >> (r27.u8 & 0x3F));
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8213f908
	if (!cr6.eq) goto loc_8213F908;
	// lbz r11,58(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 58);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213f908
	if (cr6.eq) goto loc_8213F908;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r6,r28,r11
	ctx.r6.u64 = r28.u64 + r11.u64;
	// mullw r11,r8,r29
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r29.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r7,11880
	ctx.r3.s64 = ctx.r7.s64 + 11880;
	// addi r4,r9,11872
	ctx.r4.s64 = ctx.r9.s64 + 11872;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// lbz r5,59(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 59);
	// bl 0x82130000
	ctx.lr = 0x8213F8CC;
	sub_82130000(ctx, base);
	// lbz r4,11436(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 11436);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8213f908
	if (cr6.eq) goto loc_8213F908;
	// addi r11,r31,10884
	r11.s64 = r31.s64 + 10884;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8213F8E4:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplw cr6,r8,r29
	cr6.compare<uint32_t>(ctx.r8.u32, r29.u32, xer);
	// bne cr6,0x8213f8f4
	if (!cr6.eq) goto loc_8213F8F4;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
loc_8213F8F4:
	// lbz r8,11436(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 11436);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,40
	r11.s64 = r11.s64 + 40;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x8213f8e4
	if (cr6.lt) goto loc_8213F8E4;
loc_8213F908:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8213F910;
	sub_821C9030(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8213F7A8) {
	__imp__sub_8213F7A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213F918) {
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
	// lwz r11,232(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// mulli r10,r4,11488
	ctx.r10.s64 = ctx.r4.s64 * 11488;
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// lbz r11,11439(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 11439);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213f9e0
	if (cr6.eq) goto loc_8213F9E0;
	// li r31,0
	r31.s64 = 0;
	// li r11,0
	r11.s64 = 0;
loc_8213F94C:
	// lbzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213f974
	if (cr6.eq) goto loc_8213F974;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmplwi cr6,r31,96
	cr6.compare<uint32_t>(r31.u32, 96, xer);
	// blt cr6,0x8213f94c
	if (cr6.lt) goto loc_8213F94C;
	// b 0x8213f9ec
	goto loc_8213F9EC;
loc_8213F974:
	// rlwinm r11,r31,5,19,26
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0x1FE0;
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// li r8,3
	ctx.r8.s64 = 3;
	// rlwinm r9,r31,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0x3FC;
	// li r7,-8
	ctx.r7.s64 = -8;
	// stbx r8,r10,r30
	PPC_STORE_U8(ctx.r10.u32 + r30.u32, ctx.r8.u8);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r5,7788(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 7788);
	// lwz r4,7784(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 7784);
	// rlwinm r10,r6,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r3,7792(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 7792);
	// clrlwi r9,r3,2
	ctx.r9.u64 = ctx.r3.u32 & 0x3FFFFFFF;
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + r30.u64;
	// stw r9,7792(r11)
	PPC_STORE_U32(r11.u32 + 7792, ctx.r9.u32);
	// or r7,r4,r7
	ctx.r7.u64 = ctx.r4.u64 | ctx.r7.u64;
	// clrlwi r6,r5,25
	ctx.r6.u64 = ctx.r5.u32 & 0x7F;
	// addic. r3,r8,96
	xer.ca = ctx.r8.u32 > 4294967199;
	ctx.r3.s64 = ctx.r8.s64 + 96;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r7,7784(r11)
	PPC_STORE_U32(r11.u32 + 7784, ctx.r7.u32);
	// stb r6,7788(r11)
	PPC_STORE_U8(r11.u32 + 7788, ctx.r6.u8);
	// beq 0x8213f9cc
	if (cr0.eq) goto loc_8213F9CC;
	// bl 0x8213f5a0
	ctx.lr = 0x8213F9CC;
	sub_8213F5A0(ctx, base);
loc_8213F9CC:
	// lbz r11,11439(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 11439);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,255
	r11.s64 = r11.s64 + 255;
	// stb r11,11439(r30)
	PPC_STORE_U8(r30.u32 + 11439, r11.u8);
	// b 0x8213f9f0
	goto loc_8213F9F0;
loc_8213F9E0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,12016
	ctx.r3.s64 = r11.s64 + 12016;
	// bl 0x82130000
	ctx.lr = 0x8213F9EC;
	sub_82130000(ctx, base);
loc_8213F9EC:
	// li r3,255
	ctx.r3.s64 = 255;
loc_8213F9F0:
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

PPC_WEAK_FUNC(sub_8213F918) {
	__imp__sub_8213F918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FA08) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8213FA10;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mulli r29,r5,11488
	r29.s64 = ctx.r5.s64 * 11488;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r20,0
	r20.s64 = 0;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r24,r20
	r24.u64 = r20.u64;
	// stb r10,11449(r11)
	PPC_STORE_U8(r11.u32 + 11449, ctx.r10.u8);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lbz r9,11436(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 11436);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213fbcc
	if (cr6.eq) goto loc_8213FBCC;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r28,r20
	r28.u64 = r20.u64;
	// addi r27,r29,10880
	r27.s64 = r29.s64 + 10880;
	// lfs f31,11364(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11364);
	f31.f64 = double(temp.f32);
	// li r21,-1
	r21.s64 = -1;
	// addi r22,r10,7216
	r22.s64 = ctx.r10.s64 + 7216;
	// addi r25,r9,19856
	r25.s64 = ctx.r9.s64 + 19856;
loc_8213FA74:
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// lbz r10,10884(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10884);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8213fbac
	if (cr6.eq) goto loc_8213FBAC;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// add r8,r28,r11
	ctx.r8.u64 = r28.u64 + r11.u64;
	// lwzx r7,r27,r10
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// lwz r10,11440(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// cmpwi cr6,r7,-1
	cr6.compare<int32_t>(ctx.r7.s32, -1, xer);
	// lbz r6,10884(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 10884);
	// mullw r11,r6,r9
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// lbz r5,65(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// rlwinm r11,r5,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r23
	ctx.r3.u64 = r11.u64 + r23.u64;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r26,84(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x8213fb80
	if (cr6.eq) goto loc_8213FB80;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r25,608
	ctx.r3.s64 = r25.s64 + 608;
	// add r11,r28,r10
	r11.u64 = r28.u64 + ctx.r10.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwzx r4,r27,r10
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// addi r7,r11,10856
	ctx.r7.s64 = r11.s64 + 10856;
	// addi r6,r11,10848
	ctx.r6.s64 = r11.s64 + 10848;
	// bl 0x82144720
	ctx.lr = 0x8213FB00;
	sub_82144720(ctx, base);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// add r11,r28,r29
	r11.u64 = r28.u64 + r29.u64;
	// lbz r9,58(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 58);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r7,r7,0,30,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// lbz r5,10885(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + 10885);
	// stb r7,58(r31)
	PPC_STORE_U8(r31.u32 + 58, ctx.r7.u8);
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// beq cr6,0x8213fb68
	if (cr6.eq) goto loc_8213FB68;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213fb5c
	if (cr6.eq) goto loc_8213FB5C;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// b 0x8213fb60
	goto loc_8213FB60;
loc_8213FB5C:
	// li r11,255
	r11.s64 = 255;
loc_8213FB60:
	// add r10,r5,r31
	ctx.r10.u64 = ctx.r5.u64 + r31.u64;
	// stb r11,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, r11.u8);
loc_8213FB68:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x8213fba8
	goto loc_8213FBA8;
loc_8213FB80:
	// lbz r11,58(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 58);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r9,0,30,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// lwz r8,32(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// stb r9,58(r31)
	PPC_STORE_U8(r31.u32 + 58, ctx.r9.u8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8213FBA8:
	// bctrl 
	ctx.lr = 0x8213FBAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8213FBAC:
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r28,r28,40
	r28.s64 = r28.s64 + 40;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// addi r27,r27,40
	r27.s64 = r27.s64 + 40;
	// lbz r10,11436(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11436);
	// cmplw cr6,r24,r10
	cr6.compare<uint32_t>(r24.u32, ctx.r10.u32, xer);
	// blt cr6,0x8213fa74
	if (cr6.lt) goto loc_8213FA74;
loc_8213FBCC:
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// stb r20,11436(r11)
	PPC_STORE_U8(r11.u32 + 11436, r20.u8);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// add r10,r29,r11
	ctx.r10.u64 = r29.u64 + r11.u64;
	// stb r20,11449(r10)
	PPC_STORE_U8(ctx.r10.u32 + 11449, r20.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_8213FA08) {
	__imp__sub_8213FA08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FBF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,12380
	ctx.r9.s64 = ctx.r10.s64 + 12380;
	// stw r11,316(r3)
	PPC_STORE_U32(ctx.r3.u32 + 316, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,320(r3)
	PPC_STORE_U32(ctx.r3.u32 + 320, r11.u32);
	// stw r11,336(r3)
	PPC_STORE_U32(ctx.r3.u32 + 336, r11.u32);
	// stb r11,344(r3)
	PPC_STORE_U8(ctx.r3.u32 + 344, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213FBF0) {
	__imp__sub_8213FBF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FC14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213FC14) {
	__imp__sub_8213FC14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FC18) {
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
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213fc44
	if (cr6.eq) goto loc_8213FC44;
	// bl 0x823ea140
	ctx.lr = 0x8213FC3C;
	sub_823EA140(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r11.u32);
loc_8213FC44:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x8213FC4C;
	sub_82130000(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213FC18) {
	__imp__sub_8213FC18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FC60) {
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
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213fc88
	if (cr6.eq) goto loc_8213FC88;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ea420
	ctx.lr = 0x8213FC88;
	sub_823EA420(ctx, base);
loc_8213FC88:
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213fca4
	if (!cr6.eq) goto loc_8213FCA4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a18
	ctx.lr = 0x8213FCA0;
	sub_82144A18(ctx, base);
	// stw r3,332(r31)
	PPC_STORE_U32(r31.u32 + 332, ctx.r3.u32);
loc_8213FCA4:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213FC60) {
	__imp__sub_8213FC60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FCC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,346(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 346);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213fd30
	if (!cr6.eq) goto loc_8213FD30;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213fd30
	if (!cr6.eq) goto loc_8213FD30;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213fd30
	if (!cr6.eq) goto loc_8213FD30;
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213fd30
	if (!cr6.eq) goto loc_8213FD30;
	// lbz r11,136(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 136);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213fd18
	if (cr6.eq) goto loc_8213FD18;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213fd30
	if (!cr6.eq) goto loc_8213FD30;
loc_8213FD18:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// li r11,0
	r11.s64 = 0;
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8213fd34
	if (cr6.eq) goto loc_8213FD34;
loc_8213FD30:
	// li r11,1
	r11.s64 = 1;
loc_8213FD34:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213FCC8) {
	__imp__sub_8213FCC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213FD3C) {
	__imp__sub_8213FD3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FD40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,346(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 346);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213fd74
	if (cr6.eq) goto loc_8213FD74;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8213fd68
	if (!cr6.eq) goto loc_8213FD68;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8213fd74
	if (cr6.eq) goto loc_8213FD74;
loc_8213FD68:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_8213FD74:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8213FD40) {
	__imp__sub_8213FD40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FD80) {
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
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8213fdd0
	if (cr6.eq) goto loc_8213FDD0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823ea5e8
	ctx.lr = 0x8213FDB0;
	sub_823EA5E8(ctx, base);
	// lwz r11,328(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
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
loc_8213FDD0:
	// lwz r10,328(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
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

PPC_WEAK_FUNC(sub_8213FD80) {
	__imp__sub_8213FD80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FDEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8213FDEC) {
	__imp__sub_8213FDEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8213FDF0) {
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
	ctx.lr = 0x8213FDF8;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823db9d8
	ctx.lr = 0x8213FE00;
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 948, r30.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lbz r11,24(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 24);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8213fe48
	if (cr6.eq) goto loc_8213FE48;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,5628
	ctx.r10.s64 = r11.s64 + 5628;
	// lbz r8,40(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8213fe48
	if (cr6.eq) goto loc_8213FE48;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,3796
	ctx.r10.s64 = r11.s64 + 3796;
	// lfs f29,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fmr f31,f29
	f31.f64 = f29.f64;
	// b 0x8213fe94
	goto loc_8213FE94;
loc_8213FE48:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,26(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 26);
	// addi r10,r10,3796
	ctx.r10.s64 = ctx.r10.s64 + 3796;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f29,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f29.f64 = double(temp.f32);
	// bne cr6,0x8213fe68
	if (!cr6.eq) goto loc_8213FE68;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x8213fe90
	goto loc_8213FE90;
loc_8213FE68:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r8,r11,22
	ctx.r8.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r7,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8213FE90:
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
loc_8213FE94:
	// lhz r11,32(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213fea8
	if (!cr6.eq) goto loc_8213FEA8;
	// fmr f13,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f29.f64;
	// b 0x8213fed0
	goto loc_8213FED0;
loc_8213FEA8:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r8,r11,22
	ctx.r8.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r7,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_8213FED0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,30(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 30);
	// addi r10,r10,12052
	ctx.r10.s64 = ctx.r10.s64 + 12052;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bne cr6,0x8213fef4
	if (!cr6.eq) goto loc_8213FEF4;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x8213ff1c
	goto loc_8213FF1C;
loc_8213FEF4:
	// rlwinm r8,r11,3,0,13
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r7,r11,22
	ctx.r7.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// addi r5,r11,112
	ctx.r5.s64 = r11.s64 + 112;
	// rlwinm r4,r6,13,0,18
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r3,r5,23,0,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 23) & 0xFF800000;
	// or r11,r4,r3
	r11.u64 = ctx.r4.u64 | ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8213FF1C:
	// lhz r11,28(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 28);
	// fmuls f30,f0,f12
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(f0.f64 * ctx.f12.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213ff34
	if (!cr6.eq) goto loc_8213FF34;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x8213ff5c
	goto loc_8213FF5C;
loc_8213FF34:
	// rlwinm r8,r11,3,0,13
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r7,r11,22
	ctx.r7.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// addi r5,r11,112
	ctx.r5.s64 = r11.s64 + 112;
	// rlwinm r4,r6,13,0,18
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r3,r5,23,0,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 23) & 0xFF800000;
	// or r11,r4,r3
	r11.u64 = ctx.r4.u64 | ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8213FF5C:
	// lhz r11,16(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f30,f31
	ctx.f11.f64 = double(float(f30.f64 * f31.f64));
	// li r29,0
	r29.s64 = 0;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// fmuls f28,f0,f12
	f28.f64 = double(float(f0.f64 * ctx.f12.f64));
	// li r9,1
	ctx.r9.s64 = 1;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f0,f9
	f0.f64 = double(float(ctx.f9.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// ble cr6,0x8213ff94
	if (!cr6.gt) goto loc_8213FF94;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
loc_8213FF94:
	// fmuls f12,f28,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f28.f64 * f31.f64));
	// li r10,1
	ctx.r10.s64 = 1;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x8213ffa8
	if (!cr6.gt) goto loc_8213FFA8;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8213FFA8:
	// lbz r11,346(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 346);
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8213fff4
	if (!cr6.eq) goto loc_8213FFF4;
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8213fff4
	if (!cr6.eq) goto loc_8213FFF4;
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213fff4
	if (!cr6.eq) goto loc_8213FFF4;
	// lbz r11,136(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 136);
	// rlwinm r8,r11,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8213ffec
	if (cr6.eq) goto loc_8213FFEC;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8213fff4
	if (!cr6.eq) goto loc_8213FFF4;
loc_8213FFEC:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x8213fff8
	goto loc_8213FFF8;
loc_8213FFF4:
	// li r11,1
	r11.s64 = 1;
loc_8213FFF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82140028
	if (cr6.eq) goto loc_82140028;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82140020
	if (cr6.eq) goto loc_82140020;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82140028
	if (!cr6.eq) goto loc_82140028;
loc_82140020:
	// li r11,1
	r11.s64 = 1;
	// b 0x8214002c
	goto loc_8214002C;
loc_82140028:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8214002C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lfs f13,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214006c
	if (cr6.eq) goto loc_8214006C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f12,5584(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5584);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,5672(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5672);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmuls f8,f13,f11
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fsubs f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsubs f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fsel f5,f7,f0,f9
	ctx.f5.f64 = ctx.f7.f64 >= 0.0 ? f0.f64 : ctx.f9.f64;
	// fsel f4,f6,f8,f0
	ctx.f4.f64 = ctx.f6.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsel f0,f10,f5,f4
	f0.f64 = ctx.f10.f64 >= 0.0 ? ctx.f5.f64 : ctx.f4.f64;
loc_8214006C:
	// stfs f0,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 28, temp.u32);
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,316(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 316);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ea1a8
	ctx.lr = 0x8214008C;
	sub_823EA1A8(ctx, base);
	// addi r6,r30,32
	ctx.r6.s64 = r30.s64 + 32;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r8,34
	ctx.r8.s64 = 34;
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r9,r30,60
	ctx.r9.s64 = r30.s64 + 60;
	// lis r4,-32131
	ctx.r4.s64 = -2105737216;
loc_821400A4:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lhzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + r11.u32);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// bne cr6,0x821400cc
	if (!cr6.eq) goto loc_821400CC;
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = f29.f64;
	// b 0x821400f4
	goto loc_821400F4;
loc_821400CC:
	// rlwinm r3,r10,3,0,13
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r28,r10,22
	r28.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// or r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 | r28.u64;
	// addi r10,r10,112
	ctx.r10.s64 = ctx.r10.s64 + 112;
	// rlwinm r3,r3,13,0,18
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r10,r10,23,0,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0xFF800000;
	// or r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 | ctx.r10.u64;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
loc_821400F4:
	// fmuls f11,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f0.f64 * f31.f64));
	// cmplwi cr6,r5,2
	cr6.compare<uint32_t>(ctx.r5.u32, 2, xer);
	// beq cr6,0x821401f0
	if (cr6.eq) goto loc_821401F0;
	// cmplwi cr6,r5,3
	cr6.compare<uint32_t>(ctx.r5.u32, 3, xer);
	// beq cr6,0x821401f0
	if (cr6.eq) goto loc_821401F0;
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + r11.u64;
	// lhz r10,-2(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82140120
	if (!cr6.eq) goto loc_82140120;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x82140148
	goto loc_82140148;
loc_82140120:
	// rlwinm r3,r10,3,0,13
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r28,r10,22
	r28.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// or r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 | r28.u64;
	// addi r10,r10,112
	ctx.r10.s64 = ctx.r10.s64 + 112;
	// rlwinm r3,r3,13,0,18
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r10,r10,23,0,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0xFF800000;
	// or r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 | ctx.r10.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_82140148:
	// lhzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + r11.u32);
	// fmuls f12,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 * f31.f64));
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82140164
	if (!cr6.eq) goto loc_82140164;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x8214018c
	goto loc_8214018C;
loc_82140164:
	// rlwinm r3,r10,3,0,13
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r28,r10,22
	r28.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// or r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 | r28.u64;
	// addi r10,r10,112
	ctx.r10.s64 = ctx.r10.s64 + 112;
	// rlwinm r3,r3,13,0,18
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r10,r10,23,0,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0xFF800000;
	// or r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 | ctx.r10.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_8214018C:
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// fmuls f10,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(f0.f64 * f31.f64));
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lhz r11,2(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821401b8
	if (!cr6.eq) goto loc_821401B8;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// addi r7,r7,6
	ctx.r7.s64 = ctx.r7.s64 + 6;
	// fmuls f9,f0,f31
	ctx.f9.f64 = double(float(f0.f64 * f31.f64));
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// b 0x821401fc
	goto loc_821401FC;
loc_821401B8:
	// clrlwi r3,r11,22
	ctx.r3.u64 = r11.u32 & 0x3FF;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 | ctx.r3.u64;
	// addi r3,r11,112
	ctx.r3.s64 = r11.s64 + 112;
	// rlwinm r11,r10,13,0,18
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r10,r3,23,0,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 23) & 0xFF800000;
	// addi r7,r7,6
	ctx.r7.s64 = ctx.r7.s64 + 6;
	// or r3,r11,r10
	ctx.r3.u64 = r11.u64 | ctx.r10.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmuls f9,f0,f31
	ctx.f9.f64 = double(float(f0.f64 * f31.f64));
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// b 0x821401fc
	goto loc_821401FC;
loc_821401F0:
	// lfs f9,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
loc_821401FC:
	// lfs f13,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82140210
	if (!cr6.eq) goto loc_82140210;
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
	// b 0x82140230
	goto loc_82140230;
loc_82140210:
	// fsubs f8,f11,f13
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f0,5580(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 5580);
	f0.f64 = double(temp.f32);
	// fadds f7,f13,f0
	ctx.f7.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fsubs f6,f13,f0
	ctx.f6.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f5,f8
	ctx.f5.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// fsel f4,f8,f7,f6
	ctx.f4.f64 = ctx.f8.f64 >= 0.0 ? ctx.f7.f64 : ctx.f6.f64;
	// fsubs f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsel f0,f3,f4,f11
	f0.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f11.f64;
loc_82140230:
	// stfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lfs f13,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// bne cr6,0x82140248
	if (!cr6.eq) goto loc_82140248;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
	// b 0x82140268
	goto loc_82140268;
loc_82140248:
	// fsubs f11,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f0,5580(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 5580);
	f0.f64 = double(temp.f32);
	// fadds f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fsubs f7,f13,f0
	ctx.f7.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f6,f11
	ctx.f6.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fsel f5,f11,f8,f7
	ctx.f5.f64 = ctx.f11.f64 >= 0.0 ? ctx.f8.f64 : ctx.f7.f64;
	// fsubs f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsel f0,f4,f5,f12
	f0.f64 = ctx.f4.f64 >= 0.0 ? ctx.f5.f64 : ctx.f12.f64;
loc_82140268:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stfs f0,-4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// bne cr6,0x82140280
	if (!cr6.eq) goto loc_82140280;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// b 0x821402a0
	goto loc_821402A0;
loc_82140280:
	// fsubs f12,f10,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f0,5580(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 5580);
	f0.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fsubs f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f7,f12
	ctx.f7.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fsel f6,f12,f11,f8
	ctx.f6.f64 = ctx.f12.f64 >= 0.0 ? ctx.f11.f64 : ctx.f8.f64;
	// fsubs f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 - f0.f64));
	// fsel f0,f5,f6,f10
	f0.f64 = ctx.f5.f64 >= 0.0 ? ctx.f6.f64 : ctx.f10.f64;
loc_821402A0:
	// lfs f13,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// bne cr6,0x821402b8
	if (!cr6.eq) goto loc_821402B8;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x821402d8
	goto loc_821402D8;
loc_821402B8:
	// fsubs f12,f9,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f0,5580(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 5580);
	f0.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f8,f12
	ctx.f8.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fsel f7,f12,f11,f10
	ctx.f7.f64 = ctx.f12.f64 >= 0.0 ? ctx.f11.f64 : ctx.f10.f64;
	// fsubs f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fsel f0,f6,f7,f9
	f0.f64 = ctx.f6.f64 >= 0.0 ? ctx.f7.f64 : ctx.f9.f64;
loc_821402D8:
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// stfs f0,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmplwi cr6,r8,46
	cr6.compare<uint32_t>(ctx.r8.u32, 46, xer);
	// blt cr6,0x821400a4
	if (cr6.lt) goto loc_821400A4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,6048(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6048);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82140350
	if (cr6.eq) goto loc_82140350;
	// addi r11,r30,68
	r11.s64 = r30.s64 + 68;
	// li r10,3
	ctx.r10.s64 = 3;
loc_8214030C:
	// lfs f0,-12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// stfs f29,36(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// stfs f29,48(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 48, temp.u32);
	// fmadds f8,f10,f10,f12
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f7,f9,f9,f11
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fsqrts f6,f8
	ctx.f6.f64 = double(float(sqrt(ctx.f8.f64)));
	// stfs f6,-12(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + -12, temp.u32);
	// fsqrts f5,f7
	ctx.f5.f64 = double(float(sqrt(ctx.f7.f64)));
	// stfs f5,0(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8214030c
	if (!cr0.eq) goto loc_8214030C;
loc_82140350:
	// addi r11,r1,752
	r11.s64 = ctx.r1.s64 + 752;
	// addi r10,r1,656
	ctx.r10.s64 = ctx.r1.s64 + 656;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r30,6
	r30.s64 = 6;
loc_82140378:
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,384
	ctx.r6.s64 = ctx.r1.s64 + 384;
	// li r29,2
	r29.s64 = 2;
	// addi r5,r1,152
	ctx.r5.s64 = ctx.r1.s64 + 152;
	// addi r3,r1,392
	ctx.r3.s64 = ctx.r1.s64 + 392;
	// stbx r29,r11,r7
	PPC_STORE_U8(r11.u32 + ctx.r7.u32, r29.u8);
	// addi r23,r1,408
	r23.s64 = ctx.r1.s64 + 408;
	// stbx r29,r11,r6
	PPC_STORE_U8(r11.u32 + ctx.r6.u32, r29.u8);
	// li r29,3
	r29.s64 = 3;
	// addi r31,r1,136
	r31.s64 = ctx.r1.s64 + 136;
	// stbx r29,r11,r5
	PPC_STORE_U8(r11.u32 + ctx.r5.u32, r29.u8);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stbx r29,r11,r3
	PPC_STORE_U8(r11.u32 + ctx.r3.u32, r29.u8);
	// addi r25,r1,376
	r25.s64 = ctx.r1.s64 + 376;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// addi r24,r1,168
	r24.s64 = ctx.r1.s64 + 168;
	// li r29,5
	r29.s64 = 5;
	// addi r27,r1,128
	r27.s64 = ctx.r1.s64 + 128;
	// stbx r4,r11,r5
	PPC_STORE_U8(r11.u32 + ctx.r5.u32, ctx.r4.u8);
	// li r28,1
	r28.s64 = 1;
	// stbx r29,r11,r23
	PPC_STORE_U8(r11.u32 + r23.u32, r29.u8);
	// addi r26,r1,368
	r26.s64 = ctx.r1.s64 + 368;
	// stbx r4,r11,r3
	PPC_STORE_U8(r11.u32 + ctx.r3.u32, ctx.r4.u8);
	// addi r7,r1,756
	ctx.r7.s64 = ctx.r1.s64 + 756;
	// stbx r28,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, r28.u8);
	// addi r6,r1,608
	ctx.r6.s64 = ctx.r1.s64 + 608;
	// stbx r29,r11,r24
	PPC_STORE_U8(r11.u32 + r24.u32, r29.u8);
	// addi r5,r1,704
	ctx.r5.s64 = ctx.r1.s64 + 704;
	// stbx r28,r11,r25
	PPC_STORE_U8(r11.u32 + r25.u32, r28.u8);
	// li r23,0
	r23.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r22,r1,612
	r22.s64 = ctx.r1.s64 + 612;
	// stbx r23,r11,r27
	PPC_STORE_U8(r11.u32 + r27.u32, r23.u8);
	// addi r25,r1,656
	r25.s64 = ctx.r1.s64 + 656;
	// addi r24,r1,660
	r24.s64 = ctx.r1.s64 + 660;
	// addi r31,r1,368
	r31.s64 = ctx.r1.s64 + 368;
	// addi r29,r1,708
	r29.s64 = ctx.r1.s64 + 708;
	// li r21,0
	r21.s64 = 0;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stbx r21,r11,r26
	PPC_STORE_U8(r11.u32 + r26.u32, r21.u8);
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// clrlwi r27,r8,24
	r27.u64 = ctx.r8.u32 & 0xFF;
	// add r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 + ctx.r3.u64;
	// stwx r5,r10,r24
	PPC_STORE_U32(ctx.r10.u32 + r24.u32, ctx.r5.u32);
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// stbx r27,r10,r25
	PPC_STORE_U8(ctx.r10.u32 + r25.u32, r27.u8);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// stwx r3,r10,r22
	PPC_STORE_U32(ctx.r10.u32 + r22.u32, ctx.r3.u32);
	// stwx r31,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + r29.u32, r31.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stb r27,-4(r7)
	PPC_STORE_U8(ctx.r7.u32 + -4, r27.u8);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stb r30,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, r30.u8);
	// cmplwi cr6,r11,240
	cr6.compare<uint32_t>(r11.u32, 240, xer);
	// stb r30,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r30.u8);
	// blt cr6,0x82140378
	if (cr6.lt) goto loc_82140378;
	// lwz r31,948(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 948);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	f0.f64 = double(temp.f32);
	// lfs f13,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lbz r11,70(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 70);
	// stfs f0,372(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// stfs f13,380(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82140598
	if (cr6.eq) goto loc_82140598;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// beq cr6,0x8214059c
	if (cr6.eq) goto loc_8214059C;
	// lfs f12,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f0,f30
	ctx.f11.f64 = double(float(f0.f64 * f30.f64));
	// lfs f10,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f13,f30
	ctx.f9.f64 = double(float(ctx.f13.f64 * f30.f64));
	// lfs f8,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f12,f30
	ctx.f7.f64 = double(float(ctx.f12.f64 * f30.f64));
	// lfs f6,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f10,f30
	ctx.f5.f64 = double(float(ctx.f10.f64 * f30.f64));
	// fmuls f4,f8,f30
	ctx.f4.f64 = double(float(ctx.f8.f64 * f30.f64));
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmuls f3,f6,f30
	ctx.f3.f64 = double(float(ctx.f6.f64 * f30.f64));
	// stfs f9,140(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f7,148(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stb r4,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r4.u8);
	// stfs f12,388(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stb r4,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r4.u8);
	// stfs f5,156(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r10,r31,68
	ctx.r10.s64 = r31.s64 + 68;
	// stfs f10,396(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// li r11,48
	r11.s64 = 48;
	// stfs f4,164(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f8,404(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f3,172(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f6,412(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 412, temp.u32);
loc_821404F4:
	// addi r8,r1,132
	ctx.r8.s64 = ctx.r1.s64 + 132;
	// lfs f0,-12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	f0.f64 = double(temp.f32);
	// addi r7,r1,372
	ctx.r7.s64 = ctx.r1.s64 + 372;
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,140
	ctx.r6.s64 = ctx.r1.s64 + 140;
	// lfs f12,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r1,380
	ctx.r5.s64 = ctx.r1.s64 + 380;
	// lfs f11,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// addi r3,r1,148
	ctx.r3.s64 = ctx.r1.s64 + 148;
	// lfs f10,36(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// addi r30,r1,388
	r30.s64 = ctx.r1.s64 + 388;
	// lfs f9,48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// addi r29,r1,156
	r29.s64 = ctx.r1.s64 + 156;
	// fmuls f8,f0,f30
	ctx.f8.f64 = double(float(f0.f64 * f30.f64));
	// addi r27,r1,396
	r27.s64 = ctx.r1.s64 + 396;
	// fmuls f7,f13,f30
	ctx.f7.f64 = double(float(ctx.f13.f64 * f30.f64));
	// addi r26,r1,164
	r26.s64 = ctx.r1.s64 + 164;
	// fmuls f6,f12,f30
	ctx.f6.f64 = double(float(ctx.f12.f64 * f30.f64));
	// addi r25,r1,404
	r25.s64 = ctx.r1.s64 + 404;
	// fmuls f5,f11,f30
	ctx.f5.f64 = double(float(ctx.f11.f64 * f30.f64));
	// addi r24,r1,172
	r24.s64 = ctx.r1.s64 + 172;
	// fmuls f4,f10,f30
	ctx.f4.f64 = double(float(ctx.f10.f64 * f30.f64));
	// addi r23,r1,412
	r23.s64 = ctx.r1.s64 + 412;
	// fmuls f3,f9,f30
	ctx.f3.f64 = double(float(ctx.f9.f64 * f30.f64));
	// stfsx f8,r11,r8
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stfsx f0,r11,r7
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, temp.u32);
	// stfsx f7,r11,r6
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, temp.u32);
	// stfsx f13,r11,r5
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, temp.u32);
	// stfsx f6,r11,r3
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, temp.u32);
	// stfsx f12,r11,r30
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + r30.u32, temp.u32);
	// stfsx f5,r11,r29
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + r29.u32, temp.u32);
	// stfsx f11,r11,r27
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + r27.u32, temp.u32);
	// stfsx f4,r11,r26
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + r26.u32, temp.u32);
	// stfsx f10,r11,r25
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + r25.u32, temp.u32);
	// stfsx f3,r11,r24
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + r24.u32, temp.u32);
	// stfsx f9,r11,r23
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + r23.u32, temp.u32);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// cmplwi cr6,r11,192
	cr6.compare<uint32_t>(r11.u32, 192, xer);
	// blt cr6,0x821404f4
	if (cr6.lt) goto loc_821404F4;
	// b 0x821405f8
	goto loc_821405F8;
loc_82140598:
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
loc_8214059C:
	// lfs f5,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f5.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lfs f7,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f3,f5,f30
	ctx.f3.f64 = double(float(ctx.f5.f64 * f30.f64));
	// lfs f9,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f4,f7,f30
	ctx.f4.f64 = double(float(ctx.f7.f64 * f30.f64));
	// lfs f11,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f9,f30
	ctx.f6.f64 = double(float(ctx.f9.f64 * f30.f64));
	// fmuls f8,f11,f30
	ctx.f8.f64 = double(float(ctx.f11.f64 * f30.f64));
	// stfs f5,412(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// fmuls f10,f13,f30
	ctx.f10.f64 = double(float(ctx.f13.f64 * f30.f64));
	// stfs f3,172(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// fmuls f12,f0,f30
	ctx.f12.f64 = double(float(f0.f64 * f30.f64));
	// stfs f7,404(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f4,164(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stb r28,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r28.u8);
	// stfs f9,396(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stb r4,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r4.u8);
	// stfs f6,156(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f11,388(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stfs f8,148(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f10,140(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
loc_821405F8:
	// lwz r3,320(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214064c
	if (cr6.eq) goto loc_8214064C;
	// lbz r11,24(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 24);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82140620
	if (cr6.eq) goto loc_82140620;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823ea270
	ctx.lr = 0x8214061C;
	sub_823EA270(ctx, base);
	// lbz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
loc_82140620:
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r10,r4,1,23,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FE;
	// rlwinm r9,r4,3,21,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0x7F8;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// addi r7,r1,608
	ctx.r7.s64 = ctx.r1.s64 + 608;
	// rlwinm r6,r8,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r5,r1,132
	ctx.r5.s64 = ctx.r1.s64 + 132;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stbx r28,r9,r7
	PPC_STORE_U8(ctx.r9.u32 + ctx.r7.u32, r28.u8);
	// stb r4,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r4.u8);
	// stfsx f28,r6,r5
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r5.u32, temp.u32);
loc_8214064C:
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82140660
	if (cr6.eq) goto loc_82140660;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x823ea270
	ctx.lr = 0x82140660;
	sub_823EA270(ctx, base);
loc_82140660:
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dba24
	ctx.lr = 0x8214066C;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_8213FDF0) {
	__imp__sub_8213FDF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140670) {
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
	ctx.lr = 0x82140678;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// stw r27,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r27.u32);
	// stw r11,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r11.u32);
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplw cr6,r25,r10
	cr6.compare<uint32_t>(r25.u32, ctx.r10.u32, xer);
	// bge cr6,0x82140804
	if (!cr6.lt) goto loc_82140804;
	// lwz r6,32(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bge cr6,0x821406d4
	if (!cr6.lt) goto loc_821406D4;
	// li r11,32
	r11.s64 = 32;
	// stw r11,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r11.u32);
	// stw r27,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r27.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_821406D4:
	// lwz r11,52(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addic. r7,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r7.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// beq 0x8214071c
	if (cr0.eq) goto loc_8214071C;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_821406EC:
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r25,r5
	cr6.compare<uint32_t>(r25.u32, ctx.r5.u32, xer);
	// blt cr6,0x82140704
	if (cr6.lt) goto loc_82140704;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r25,r5
	cr6.compare<uint32_t>(r25.u32, ctx.r5.u32, xer);
	// blt cr6,0x82140718
	if (cr6.lt) goto loc_82140718;
loc_82140704:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// blt cr6,0x821406ec
	if (cr6.lt) goto loc_821406EC;
	// b 0x8214071c
	goto loc_8214071C;
loc_82140718:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8214071C:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// rlwinm r29,r10,11,0,20
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0xFFFFF800;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r26,r11,r29
	r26.u64 = r11.u64 + r29.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwzx r7,r11,r29
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwzx r30,r8,r6
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// rlwinm r11,r7,21,17,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 21) & 0x7FFF;
	// lfs f31,12424(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12424);
	f31.f64 = double(temp.f32);
	// addi r31,r11,32
	r31.s64 = r11.s64 + 32;
	// clrldi r6,r31,32
	ctx.r6.u64 = r31.u64 & 0xFFFFFFFF;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x823dba38
	ctx.lr = 0x82140760;
	sub_823DBA38(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// mr r28,r30
	r28.u64 = r30.u64;
	// subf r30,r30,r25
	r30.s64 = r25.s64 - r30.s64;
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_82140778:
	// clrlwi r11,r31,29
	r11.u64 = r31.u32 & 0x7;
	// lwzx r9,r10,r26
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// subfic r8,r11,17
	xer.ca = r11.u32 <= 17;
	ctx.r8.s64 = 17 - r11.s64;
	// srw r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// clrlwi r11,r7,17
	r11.u64 = ctx.r7.u32 & 0x7FFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82140804
	if (cr6.eq) goto loc_82140804;
	// cmplw cr6,r25,r28
	cr6.compare<uint32_t>(r25.u32, r28.u32, xer);
	// blt cr6,0x821407c0
	if (cr6.lt) goto loc_821407C0;
	// addi r9,r28,512
	ctx.r9.s64 = r28.s64 + 512;
	// cmplw cr6,r25,r9
	cr6.compare<uint32_t>(r25.u32, ctx.r9.u32, xer);
	// bge cr6,0x821407c0
	if (!cr6.lt) goto loc_821407C0;
	// rlwinm r11,r29,3,0,28
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// li r27,1
	r27.s64 = 1;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stw r11,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r11.u32);
	// stw r30,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r30.u32);
	// b 0x821407f8
	goto loc_821407F8;
loc_821407C0:
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// clrldi r11,r31,32
	r11.u64 = r31.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x823dba38
	ctx.lr = 0x821407E0;
	sub_823DBA38(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// addi r30,r30,-512
	r30.s64 = r30.s64 + -512;
	// addi r28,r28,512
	r28.s64 = r28.s64 + 512;
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f10.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_821407F8:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82140778
	if (cr6.eq) goto loc_82140778;
loc_82140804:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82140670) {
	__imp__sub_82140670(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140810) {
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82140854
	if (cr6.eq) goto loc_82140854;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823ea2c8
	ctx.lr = 0x82140844;
	sub_823EA2C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82140854
	if (cr6.lt) goto loc_82140854;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// stb r11,346(r31)
	PPC_STORE_U8(r31.u32 + 346, r11.u8);
loc_82140854:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f12,f31,f31,f0
	ctx.f12.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// lfs f13,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f13,f11,f13,f12
	ctx.f13.f64 = ctx.f11.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x821408fc
	if (!cr6.eq) goto loc_821408FC;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821409cc
	if (!cr6.eq) goto loc_821409CC;
	// lbz r10,346(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 346);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821408b4
	if (!cr6.eq) goto loc_821408B4;
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821408b4
	if (!cr6.eq) goto loc_821408B4;
	// rlwinm r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x821408b8
	if (cr6.eq) goto loc_821408B8;
loc_821408B4:
	// li r10,1
	ctx.r10.s64 = 1;
loc_821408B8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// rlwimi r11,r10,1,30,30
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0x2) | (r11.u64 & 0xFFFFFFFFFFFFFFFD);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwinm r8,r9,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// stb r9,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r9.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821408f0
	if (cr6.eq) goto loc_821408F0;
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821408f0
	if (cr6.eq) goto loc_821408F0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ea420
	ctx.lr = 0x821408E8;
	sub_823EA420(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x821409cc
	if (cr6.lt) goto loc_821409CC;
loc_821408F0:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// b 0x821409c8
	goto loc_821409C8;
loc_821408FC:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,316(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f9.u64);
	// lwz r30,92(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// beq cr6,0x82140970
	if (cr6.eq) goto loc_82140970;
	// clrldi r10,r30,32
	ctx.r10.u64 = r30.u64 & 0xFFFFFFFF;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fdiv f1,f11,f12
	ctx.f1.f64 = ctx.f11.f64 / ctx.f12.f64;
	// bl 0x823db788
	ctx.lr = 0x82140958;
	sub_823DB788(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lfd f0,12368(r8)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r8.u32 + 12368);
	// fmul f10,f1,f0
	ctx.f10.f64 = ctx.f1.f64 * f0.f64;
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x823ea6b8
	ctx.lr = 0x82140970;
	sub_823EA6B8(ctx, base);
loc_82140970:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// stw r30,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r30.u32);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821409cc
	if (cr6.eq) goto loc_821409CC;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821409cc
	if (cr6.eq) goto loc_821409CC;
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821409cc
	if (cr6.eq) goto loc_821409CC;
	// lbz r11,346(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 346);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821409cc
	if (!cr6.eq) goto loc_821409CC;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x823ea3d8
	ctx.lr = 0x821409B8;
	sub_823EA3D8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x821409cc
	if (cr6.lt) goto loc_821409CC;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
loc_821409C8:
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
loc_821409CC:
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

PPC_WEAK_FUNC(sub_82140810) {
	__imp__sub_82140810(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821409E8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82140a24
	if (!cr6.eq) goto loc_82140A24;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82140A24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82140A24:
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82140810
	ctx.lr = 0x82140A38;
	sub_82140810(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82140a60
	if (!cr6.eq) goto loc_82140A60;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// ori r10,r11,130
	ctx.r10.u64 = r11.u64 | 130;
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
	// b 0x82140a74
	goto loc_82140A74;
loc_82140A60:
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82140a74
	if (cr6.eq) goto loc_82140A74;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x823ea3d8
	ctx.lr = 0x82140A74;
	sub_823EA3D8(ctx, base);
loc_82140A74:
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

PPC_WEAK_FUNC(sub_821409E8) {
	__imp__sub_821409E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140A8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82140A8C) {
	__imp__sub_82140A8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140A90) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82140c9c
	if (!cr6.gt) goto loc_82140C9C;
	// lbz r10,345(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 345);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulli r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 * 88;
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + r31.u64;
	// stw r9,140(r8)
	PPC_STORE_U32(ctx.r8.u32 + 140, ctx.r9.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lbz r6,345(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 345);
	// mulli r10,r6,88
	ctx.r10.s64 = ctx.r6.s64 * 88;
	// add r5,r10,r31
	ctx.r5.u64 = ctx.r10.u64 + r31.u64;
	// stw r7,144(r5)
	PPC_STORE_U32(ctx.r5.u32 + 144, ctx.r7.u32);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82140b5c
	if (cr6.lt) goto loc_82140B5C;
	// lbz r10,345(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 345);
	// li r9,-1
	ctx.r9.s64 = -1;
	// mulli r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 * 88;
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + r31.u64;
	// stw r9,148(r8)
	PPC_STORE_U32(ctx.r8.u32 + 148, ctx.r9.u32);
	// lbz r6,345(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 345);
	// lwz r7,40(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mulli r10,r6,88
	ctx.r10.s64 = ctx.r6.s64 * 88;
	// add r5,r10,r31
	ctx.r5.u64 = ctx.r10.u64 + r31.u64;
	// stw r7,152(r5)
	PPC_STORE_U32(ctx.r5.u32 + 152, ctx.r7.u32);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lbz r4,345(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 345);
	// mulli r10,r4,88
	ctx.r10.s64 = ctx.r4.s64 * 88;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// stw r3,156(r10)
	PPC_STORE_U32(ctx.r10.u32 + 156, ctx.r3.u32);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbz r8,345(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 345);
	// mulli r10,r8,88
	ctx.r10.s64 = ctx.r8.s64 * 88;
	// add r7,r10,r31
	ctx.r7.u64 = ctx.r10.u64 + r31.u64;
	// clrlwi r6,r9,28
	ctx.r6.u64 = ctx.r9.u32 & 0xF;
	// stb r6,161(r7)
	PPC_STORE_U8(ctx.r7.u32 + 161, ctx.r6.u8);
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// rlwinm r4,r5,28,28,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xF;
	// lbz r3,345(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 345);
	// mulli r11,r3,88
	r11.s64 = ctx.r3.s64 * 88;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stb r4,160(r11)
	PPC_STORE_U8(r11.u32 + 160, ctx.r4.u8);
loc_82140B5C:
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82140b80
	if (cr6.eq) goto loc_82140B80;
	// lbz r11,345(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 345);
	// li r5,1
	ctx.r5.s64 = 1;
	// mulli r11,r11,88
	r11.s64 = r11.s64 * 88;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r11,140
	ctx.r4.s64 = r11.s64 + 140;
	// bl 0x823ea320
	ctx.lr = 0x82140B80;
	sub_823EA320(ctx, base);
loc_82140B80:
	// lbz r11,345(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 345);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// stb r10,345(r31)
	PPC_STORE_U8(r31.u32 + 345, ctx.r10.u8);
	// beq cr6,0x82140c9c
	if (cr6.eq) goto loc_82140C9C;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// clrldi r10,r30,32
	ctx.r10.u64 = r30.u64 & 0xFFFFFFFF;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,8884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f0.f64 = double(temp.f32);
	// frsp f9,f13
	ctx.f9.f64 = double(float(ctx.f13.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// lfs f13,8880(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f12,8876(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,12432(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12432);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fsel f5,f6,f13,f12
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fadds f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// fsubs f2,f3,f11
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f11.f64));
	// fsubs f1,f6,f3
	ctx.f1.f64 = double(float(ctx.f6.f64 - ctx.f3.f64));
	// fsel f0,f1,f3,f2
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f3.f64 : ctx.f2.f64;
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// stw r3,328(r31)
	PPC_STORE_U32(r31.u32 + 328, ctx.r3.u32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fmuls f1,f9,f10
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// bl 0x823dba38
	ctx.lr = 0x82140C34;
	sub_823DBA38(ctx, base);
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// li r10,0
	ctx.r10.s64 = 0;
	// li r5,44
	ctx.r5.s64 = 44;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f7.u64);
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r30,r9,7,0,24
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// stw r30,328(r31)
	PPC_STORE_U32(r31.u32 + 328, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x82140C64;
	sub_823D9890(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82140670
	ctx.lr = 0x82140C78;
	sub_82140670(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82140c9c
	if (cr6.lt) goto loc_82140C9C;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// sth r11,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r11.u16);
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x823ea538
	ctx.lr = 0x82140C9C;
	sub_823EA538(ctx, base);
loc_82140C9C:
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

PPC_WEAK_FUNC(sub_82140A90) {
	__imp__sub_82140A90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82140CB4) {
	__imp__sub_82140CB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140CB8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82140CC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r29,20(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82140CDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82140da4
	if (cr6.eq) goto loc_82140DA4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x8213fd80
	ctx.lr = 0x82140CF4;
	sub_8213FD80(ctx, base);
	// clrldi r11,r3,32
	r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,8884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8884);
	f0.f64 = double(temp.f32);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,8880(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// lfs f12,8876(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fdivs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// fsel f5,f6,f13,f12
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fadds f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// fsubs f2,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 - ctx.f3.f64));
	// fsubs f1,f3,f11
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f11.f64));
	// fsel f10,f2,f3,f1
	ctx.f10.f64 = ctx.f2.f64 >= 0.0 ? ctx.f3.f64 : ctx.f1.f64;
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// ble cr6,0x82140e4c
	if (!cr6.gt) goto loc_82140E4C;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82140dc0
	if (!cr6.eq) goto loc_82140DC0;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82140e4c
	if (!cr6.eq) goto loc_82140E4C;
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82140da4
	if (cr6.eq) goto loc_82140DA4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ea420
	ctx.lr = 0x82140DA4;
	sub_823EA420(ctx, base);
loc_82140DA4:
	// li r30,-1
	r30.s64 = -1;
loc_82140DA8:
	// li r11,0
	r11.s64 = 0;
	// stb r11,344(r31)
	PPC_STORE_U8(r31.u32 + 344, r11.u8);
loc_82140DB0:
	// stw r30,336(r31)
	PPC_STORE_U32(r31.u32 + 336, r30.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82140DC0:
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// clrldi r8,r11,32
	ctx.r8.u64 = r11.u64 & 0xFFFFFFFF;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f10,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fsubs f12,f0,f11
	ctx.f12.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsel f11,f13,f0,f12
	ctx.f11.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r11,r10,r9
	r11.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x82140e24
	if (!cr6.lt) goto loc_82140E24;
	// li r11,1
	r11.s64 = 1;
loc_82140E24:
	// subf r8,r10,r30
	ctx.r8.s64 = r30.s64 - ctx.r10.s64;
	// twllei r11,0
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r7,r8,r11
	ctx.r7.s32 = ctx.r8.s32 / r11.s32;
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// mullw r5,r7,r11
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// subf r9,r5,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r5.s64;
	// andc r4,r11,r6
	ctx.r4.u64 = r11.u64 & ~ctx.r6.u64;
	// add r30,r9,r10
	r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// twlgei r4,-1
loc_82140E4C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82140da8
	if (!cr6.gt) goto loc_82140DA8;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82140da8
	if (!cr6.eq) goto loc_82140DA8;
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x82140da8
	if (!cr6.eq) goto loc_82140DA8;
	// lbz r11,344(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 344);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// stb r10,344(r31)
	PPC_STORE_U8(r31.u32 + 344, ctx.r10.u8);
	// cmplwi cr6,r10,100
	cr6.compare<uint32_t>(ctx.r10.u32, 100, xer);
	// blt cr6,0x82140db0
	if (cr6.lt) goto loc_82140DB0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82140e9c
	if (cr6.eq) goto loc_82140E9C;
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x82140ea0
	goto loc_82140EA0;
loc_82140E9C:
	// li r29,0
	r29.s64 = 0;
loc_82140EA0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137030
	ctx.lr = 0x82140EA8;
	sub_82137030(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82140ebc
	if (!cr6.eq) goto loc_82140EBC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r11,12540
	ctx.r5.s64 = r11.s64 + 12540;
loc_82140EBC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,340(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r3,r11,12440
	ctx.r3.s64 = r11.s64 + 12440;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x82140ED4;
	sub_82130000(ctx, base);
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82140ee8
	if (cr6.eq) goto loc_82140EE8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ea420
	ctx.lr = 0x82140EE8;
	sub_823EA420(ctx, base);
loc_82140EE8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82140CB8) {
	__imp__sub_82140CB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82140EF4) {
	__imp__sub_82140EF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140EF8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82140f88
	if (cr6.eq) goto loc_82140F88;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x823ea1a8
	ctx.lr = 0x82140F4C;
	sub_823EA1A8(ctx, base);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82140810
	ctx.lr = 0x82140F5C;
	sub_82140810(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213fdf0
	ctx.lr = 0x82140F64;
	sub_8213FDF0(ctx, base);
	// lwz r3,316(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82140f88
	if (cr6.eq) goto loc_82140F88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823ea2c8
	ctx.lr = 0x82140F78;
	sub_823EA2C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82140f88
	if (cr6.lt) goto loc_82140F88;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// stb r11,346(r31)
	PPC_STORE_U8(r31.u32 + 346, r11.u8);
loc_82140F88:
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

PPC_WEAK_FUNC(sub_82140EF8) {
	__imp__sub_82140EF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82140F9C) {
	__imp__sub_82140F9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140FA0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,12380
	ctx.r10.s64 = r11.s64 + 12380;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82136f18
	ctx.lr = 0x82140FCC;
	sub_82136F18(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82140fe4
	if (cr6.eq) goto loc_82140FE4;
	// bl 0x821370f0
	ctx.lr = 0x82140FE0;
	sub_821370F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82140FE4:
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

PPC_WEAK_FUNC(sub_82140FA0) {
	__imp__sub_82140FA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82140FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82140FFC) {
	__imp__sub_82140FFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141000) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82141008;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82136f28
	ctx.lr = 0x82141014;
	sub_82136F28(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// li r30,1
	r30.s64 = 1;
	// stb r29,346(r31)
	PPC_STORE_U8(r31.u32 + 346, r29.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// stb r30,137(r31)
	PPC_STORE_U8(r31.u32 + 137, r30.u8);
	// lfs f12,8876(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r7,8
	ctx.r7.s64 = 8;
	// li r5,88
	ctx.r5.s64 = 88;
	// lfs f13,8880(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,180
	ctx.r3.s64 = ctx.r1.s64 + 180;
	// lfs f11,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lwz r24,12(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,16(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// mr r11,r24
	r11.u64 = r24.u64;
	// stb r29,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r29.u8);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// stw r24,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r24.u32);
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f13,f0,f11
	ctx.f13.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfiwx f10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.f10.u32);
	// bl 0x823d9890
	ctx.lr = 0x821410B8;
	sub_823D9890(ctx, base);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r28,6
	r28.s64 = 6;
	// li r26,5
	r26.s64 = 5;
	// stb r28,234(r1)
	PPC_STORE_U8(ctx.r1.u32 + 234, r28.u8);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stb r26,233(r1)
	PPC_STORE_U8(ctx.r1.u32 + 233, r26.u8);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lbz r11,72(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 72);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lfs f0,3732(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// stfs f0,236(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stb r29,232(r1)
	PPC_STORE_U8(ctx.r1.u32 + 232, r29.u8);
	// addi r10,r5,0
	ctx.r10.s64 = ctx.r5.s64 + 0;
	// stb r30,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r30.u8);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r11,6092(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6092);
	// li r27,4
	r27.s64 = 4;
	// stb r30,188(r1)
	PPC_STORE_U8(ctx.r1.u32 + 188, r30.u8);
	// addi r25,r31,316
	r25.s64 = r31.s64 + 316;
	// stw r24,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r24.u32);
	// addi r9,r1,120
	ctx.r9.s64 = ctx.r1.s64 + 120;
	// stb r27,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r27.u8);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// stb r8,235(r1)
	PPC_STORE_U8(ctx.r1.u32 + 235, ctx.r8.u8);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stw r10,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r10.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stw r31,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r31.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r29.u32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stb r30,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r30.u8);
	// stw r6,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r6.u32);
	// stw r5,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r5.u32);
	// stb r11,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r11.u8);
	// bl 0x823eaa90
	ctx.lr = 0x82141154;
	sub_823EAA90(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82141318
	if (cr6.lt) goto loc_82141318;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r28,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r28.u8);
	// addi r11,r1,272
	r11.s64 = ctx.r1.s64 + 272;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// addi r11,r1,273
	r11.s64 = ctx.r1.s64 + 273;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82141178:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stfs f0,3(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 3, temp.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r29,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r29.u8);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r10,6
	cr6.compare<uint32_t>(ctx.r10.u32, 6, xer);
	// blt cr6,0x82141178
	if (cr6.lt) goto loc_82141178;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r8,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r8.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r7,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r7.u32);
	// stw r6,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r6.u32);
	// stw r5,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821411e0
	if (cr6.eq) goto loc_821411E0;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// stw r11,320(r31)
	PPC_STORE_U32(r31.u32 + 320, r11.u32);
loc_821411E0:
	// lbz r11,70(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 70);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82141260
	if (cr6.eq) goto loc_82141260;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82141258
	if (cr6.eq) goto loc_82141258;
	// li r11,2
	r11.s64 = 2;
	// stb r30,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, r30.u8);
	// stb r27,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r27.u8);
	// mr r30,r29
	r30.u64 = r29.u64;
	// stb r11,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, r11.u8);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stb r26,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r26.u8);
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// stb r29,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r29.u8);
	// addi r27,r11,19856
	r27.s64 = r11.s64 + 19856;
loc_8214121C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r3,r27,172
	ctx.r3.s64 = r27.s64 + 172;
	// lbzx r4,r30,r11
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + r11.u32);
	// bl 0x8214d0c0
	ctx.lr = 0x8214122C;
	sub_8214D0C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82141240
	if (cr6.eq) goto loc_82141240;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x82141244
	goto loc_82141244;
loc_82141240:
	// stw r29,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r29.u32);
loc_82141244:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmplwi cr6,r30,4
	cr6.compare<uint32_t>(r30.u32, 4, xer);
	// blt cr6,0x8214121c
	if (cr6.lt) goto loc_8214121C;
	// b 0x82141290
	goto loc_82141290;
loc_82141258:
	// li r4,4
	ctx.r4.s64 = 4;
	// b 0x82141264
	goto loc_82141264;
loc_82141260:
	// li r4,3
	ctx.r4.s64 = 3;
loc_82141264:
	// stb r30,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r30.u8);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// addi r3,r11,172
	ctx.r3.s64 = r11.s64 + 172;
	// bl 0x8214d0c0
	ctx.lr = 0x82141278;
	sub_8214D0C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214128c
	if (cr6.eq) goto loc_8214128C;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// b 0x82141290
	goto loc_82141290;
loc_8214128C:
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r29.u32);
loc_82141290:
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821412b8
	if (cr6.eq) goto loc_821412B8;
	// lbz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rotlwi r7,r10,3
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stb r6,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r6.u8);
	// stwx r11,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, r11.u32);
loc_821412B8:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,0(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// bl 0x823ea218
	ctx.lr = 0x821412C4;
	sub_823EA218(ctx, base);
	// li r5,176
	ctx.r5.s64 = 176;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// bl 0x8244d150
	ctx.lr = 0x821412D4;
	sub_8244D150(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r29,328(r31)
	PPC_STORE_U32(r31.u32 + 328, r29.u32);
	// stb r29,345(r31)
	PPC_STORE_U8(r31.u32 + 345, r29.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82141304
	if (cr6.lt) goto loc_82141304;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// stw r29,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r29.u32);
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
loc_82141304:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// stw r29,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r29.u32);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,26,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
loc_82141318:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82141000) {
	__imp__sub_82141000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,12888
	ctx.r7.s64 = r11.s64 + 12888;
	// li r11,0
	r11.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,336(r3)
	PPC_STORE_U8(ctx.r3.u32 + 336, r11.u8);
	// lfs f13,8488(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8488);
	ctx.f13.f64 = double(temp.f32);
	// stw r6,332(r3)
	PPC_STORE_U32(ctx.r3.u32 + 332, ctx.r6.u32);
	// lfs f12,12880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12880);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,316(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 316, temp.u32);
	// stfs f0,320(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 320, temp.u32);
	// stfs f12,324(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 324, temp.u32);
	// stfs f0,328(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 328, temp.u32);
	// stw r11,340(r3)
	PPC_STORE_U32(ctx.r3.u32 + 340, r11.u32);
	// stw r11,344(r3)
	PPC_STORE_U32(ctx.r3.u32 + 344, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82141320) {
	__imp__sub_82141320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141370) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82141378;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82136f28
	ctx.lr = 0x82141384;
	sub_82136F28(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// li r30,1
	r30.s64 = 1;
	// stb r29,364(r31)
	PPC_STORE_U8(r31.u32 + 364, r29.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// stb r30,137(r31)
	PPC_STORE_U8(r31.u32 + 137, r30.u8);
	// lfs f12,8876(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r7,8
	ctx.r7.s64 = 8;
	// li r5,88
	ctx.r5.s64 = 88;
	// lfs f13,8880(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,180
	ctx.r3.s64 = ctx.r1.s64 + 180;
	// lfs f11,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lwz r25,12(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,16(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// mr r11,r25
	r11.u64 = r25.u64;
	// stb r29,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r29.u8);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// stw r25,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r25.u32);
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f13,f0,f11
	ctx.f13.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfiwx f10,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.f10.u32);
	// bl 0x823d9890
	ctx.lr = 0x82141428;
	sub_823D9890(ctx, base);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r28,6
	r28.s64 = 6;
	// li r27,5
	r27.s64 = 5;
	// stb r28,234(r1)
	PPC_STORE_U8(ctx.r1.u32 + 234, r28.u8);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stb r27,233(r1)
	PPC_STORE_U8(ctx.r1.u32 + 233, r27.u8);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// lwz r9,6092(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6092);
	// addi r10,r1,120
	ctx.r10.s64 = ctx.r1.s64 + 120;
	// addi r26,r31,340
	r26.s64 = r31.s64 + 340;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lbz r8,72(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 72);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r29,232(r1)
	PPC_STORE_U8(ctx.r1.u32 + 232, r29.u8);
	// stb r30,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r30.u8);
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stb r30,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r30.u8);
	// stw r25,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r25.u32);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stb r9,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, ctx.r9.u8);
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r29.u32);
	// stb r8,235(r1)
	PPC_STORE_U8(ctx.r1.u32 + 235, ctx.r8.u8);
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// stb r30,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r30.u8);
	// stw r5,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r5.u32);
	// stw r10,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r10.u32);
	// bl 0x823eaa90
	ctx.lr = 0x821414A0;
	sub_823EAA90(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82141660
	if (cr6.lt) goto loc_82141660;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r28,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r28.u8);
	// addi r11,r1,272
	r11.s64 = ctx.r1.s64 + 272;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// addi r11,r1,273
	r11.s64 = ctx.r1.s64 + 273;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_821414C4:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stfs f0,3(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 3, temp.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r29,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r29.u8);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r10,6
	cr6.compare<uint32_t>(ctx.r10.u32, 6, xer);
	// blt cr6,0x821414c4
	if (cr6.lt) goto loc_821414C4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r8,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r8.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r7,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r7.u32);
	// stw r6,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r6.u32);
	// stw r5,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214152c
	if (cr6.eq) goto loc_8214152C;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// stw r11,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r11.u32);
loc_8214152C:
	// lbz r11,70(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 70);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x821415b0
	if (cr6.eq) goto loc_821415B0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x821415a8
	if (cr6.eq) goto loc_821415A8;
	// li r11,4
	r11.s64 = 4;
	// stb r30,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, r30.u8);
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r27,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r27.u8);
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r30,r29
	r30.u64 = r29.u64;
	// stb r29,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r29.u8);
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// stb r10,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// addi r27,r11,19856
	r27.s64 = r11.s64 + 19856;
loc_8214156C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r3,r27,172
	ctx.r3.s64 = r27.s64 + 172;
	// lbzx r4,r30,r11
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + r11.u32);
	// bl 0x8214d0c0
	ctx.lr = 0x8214157C;
	sub_8214D0C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82141590
	if (cr6.eq) goto loc_82141590;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x82141594
	goto loc_82141594;
loc_82141590:
	// stw r29,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r29.u32);
loc_82141594:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmplwi cr6,r30,4
	cr6.compare<uint32_t>(r30.u32, 4, xer);
	// blt cr6,0x8214156c
	if (cr6.lt) goto loc_8214156C;
	// b 0x821415e0
	goto loc_821415E0;
loc_821415A8:
	// li r4,4
	ctx.r4.s64 = 4;
	// b 0x821415b4
	goto loc_821415B4;
loc_821415B0:
	// li r4,3
	ctx.r4.s64 = 3;
loc_821415B4:
	// stb r30,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r30.u8);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// addi r3,r11,172
	ctx.r3.s64 = r11.s64 + 172;
	// bl 0x8214d0c0
	ctx.lr = 0x821415C8;
	sub_8214D0C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821415dc
	if (cr6.eq) goto loc_821415DC;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// b 0x821415e0
	goto loc_821415E0;
loc_821415DC:
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r29.u32);
loc_821415E0:
	// lwz r11,344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 344);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82141608
	if (cr6.eq) goto loc_82141608;
	// lbz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rotlwi r7,r10,3
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stb r6,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r6.u8);
	// stwx r11,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, r11.u32);
loc_82141608:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x823ea218
	ctx.lr = 0x82141614;
	sub_823EA218(ctx, base);
	// li r5,176
	ctx.r5.s64 = 176;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// bl 0x8244d150
	ctx.lr = 0x82141624;
	sub_8244D150(ctx, base);
	// stw r29,360(r31)
	PPC_STORE_U32(r31.u32 + 360, r29.u32);
	// stw r29,352(r31)
	PPC_STORE_U32(r31.u32 + 352, r29.u32);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82141650
	if (cr6.lt) goto loc_82141650;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d923c
	return;
loc_82141650:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,26,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
loc_82141660:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82141370) {
	__imp__sub_82141370(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141668) {
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
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82141694
	if (cr6.eq) goto loc_82141694;
	// bl 0x823ea140
	ctx.lr = 0x8214168C;
	sub_823EA140(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r11.u32);
loc_82141694:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x8214169C;
	sub_82130000(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82141668) {
	__imp__sub_82141668(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821416B0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f12,f1,f1,f0
	ctx.f12.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// lfs f13,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f13,f11,f13,f12
	ctx.f13.f64 = ctx.f11.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x8214175c
	if (!cr6.eq) goto loc_8214175C;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82141814
	if (!cr6.eq) goto loc_82141814;
	// lbz r10,364(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 364);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8214171c
	if (!cr6.eq) goto loc_8214171C;
	// rlwinm r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x82141720
	if (cr6.eq) goto loc_82141720;
loc_8214171C:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82141720:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// rlwimi r11,r10,1,30,30
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0x2) | (r11.u64 & 0xFFFFFFFFFFFFFFFD);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwinm r8,r9,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// stb r9,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r9.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82141750
	if (cr6.eq) goto loc_82141750;
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82141750
	if (cr6.eq) goto loc_82141750;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ea420
	ctx.lr = 0x82141750;
	sub_823EA420(ctx, base);
loc_82141750:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// b 0x82141810
	goto loc_82141810;
loc_8214175C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,340(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x821417d0
	if (cr6.eq) goto loc_821417D0;
	// clrldi r10,r30,32
	ctx.r10.u64 = r30.u64 & 0xFFFFFFFF;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fdiv f1,f11,f12
	ctx.f1.f64 = ctx.f11.f64 / ctx.f12.f64;
	// bl 0x823db788
	ctx.lr = 0x821417B8;
	sub_823DB788(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lfd f0,12368(r8)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r8.u32 + 12368);
	// fmul f10,f1,f0
	ctx.f10.f64 = ctx.f1.f64 * f0.f64;
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x823ea6b8
	ctx.lr = 0x821417D0;
	sub_823EA6B8(ctx, base);
loc_821417D0:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// stw r30,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r30.u32);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82141814
	if (cr6.eq) goto loc_82141814;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82141808
	if (cr6.eq) goto loc_82141808;
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82141808
	if (cr6.eq) goto loc_82141808;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x823ea3d8
	ctx.lr = 0x82141808;
	sub_823EA3D8(ctx, base);
loc_82141808:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
loc_82141810:
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
loc_82141814:
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

PPC_WEAK_FUNC(sub_821416B0) {
	__imp__sub_821416B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8214182C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8214182C) {
	__imp__sub_8214182C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82141864
	if (!cr6.eq) goto loc_82141864;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82141864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82141864:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821416b0
	ctx.lr = 0x82141874;
	sub_821416B0(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x821418ac
	if (!cr6.eq) goto loc_821418AC;
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// ori r10,r11,130
	ctx.r10.u64 = r11.u64 | 130;
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821418AC:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821418c0
	if (cr6.eq) goto loc_821418C0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x823ea3d8
	ctx.lr = 0x821418C0;
	sub_823EA3D8(ctx, base);
loc_821418C0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82141830) {
	__imp__sub_82141830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821418D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821418D4) {
	__imp__sub_821418D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821418D8) {
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
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82141900
	if (cr6.eq) goto loc_82141900;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ea420
	ctx.lr = 0x82141900;
	sub_823EA420(ctx, base);
loc_82141900:
	// lbz r11,136(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stb r10,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821418D8) {
	__imp__sub_821418D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82141924) {
	__imp__sub_82141924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141928) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,364(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 364);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82141984
	if (!cr6.eq) goto loc_82141984;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82141984
	if (!cr6.eq) goto loc_82141984;
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82141984
	if (!cr6.eq) goto loc_82141984;
	// lbz r11,136(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 136);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214196c
	if (cr6.eq) goto loc_8214196C;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82141984
	if (!cr6.eq) goto loc_82141984;
loc_8214196C:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// li r11,0
	r11.s64 = 0;
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82141988
	if (cr6.eq) goto loc_82141988;
loc_82141984:
	// li r11,1
	r11.s64 = 1;
loc_82141988:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82141928) {
	__imp__sub_82141928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141990) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,364(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 364);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821419b0
	if (!cr6.eq) goto loc_821419B0;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x821419b4
	if (cr6.eq) goto loc_821419B4;
loc_821419B0:
	// li r11,1
	r11.s64 = 1;
loc_821419B4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82141990) {
	__imp__sub_82141990(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821419BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821419BC) {
	__imp__sub_821419BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821419C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x821419D8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82141bc0
	if (!cr6.gt) goto loc_82141BC0;
	// lwz r10,360(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulli r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 * 88;
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + r31.u64;
	// stw r9,140(r8)
	PPC_STORE_U32(ctx.r8.u32 + 140, ctx.r9.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r6,360(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// mulli r10,r6,88
	ctx.r10.s64 = ctx.r6.s64 * 88;
	// add r5,r10,r31
	ctx.r5.u64 = ctx.r10.u64 + r31.u64;
	// stw r7,144(r5)
	PPC_STORE_U32(ctx.r5.u32 + 144, ctx.r7.u32);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82141a70
	if (cr6.lt) goto loc_82141A70;
	// lwz r10,360(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// li r9,-1
	ctx.r9.s64 = -1;
	// mulli r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 * 88;
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + r31.u64;
	// stw r9,148(r8)
	PPC_STORE_U32(ctx.r8.u32 + 148, ctx.r9.u32);
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r7,360(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// mulli r10,r7,88
	ctx.r10.s64 = ctx.r7.s64 * 88;
	// add r5,r10,r31
	ctx.r5.u64 = ctx.r10.u64 + r31.u64;
	// stw r4,152(r5)
	PPC_STORE_U32(ctx.r5.u32 + 152, ctx.r4.u32);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// mulli r10,r11,88
	ctx.r10.s64 = r11.s64 * 88;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// lwz r9,152(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 152);
	// subf r8,r9,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r9.s64;
	// stw r8,156(r10)
	PPC_STORE_U32(ctx.r10.u32 + 156, ctx.r8.u32);
loc_82141A70:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82141a94
	if (cr6.eq) goto loc_82141A94;
	// lwz r11,360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// li r5,1
	ctx.r5.s64 = 1;
	// mulli r11,r11,88
	r11.s64 = r11.s64 * 88;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r11,140
	ctx.r4.s64 = r11.s64 + 140;
	// bl 0x823ea320
	ctx.lr = 0x82141A94;
	sub_823EA320(ctx, base);
loc_82141A94:
	// lwz r11,360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 360);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// stw r10,360(r31)
	PPC_STORE_U32(r31.u32 + 360, ctx.r10.u32);
	// beq cr6,0x82141bc0
	if (cr6.eq) goto loc_82141BC0;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// clrldi r10,r30,32
	ctx.r10.u64 = r30.u64 & 0xFFFFFFFF;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbz r8,136(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// frsp f9,f13
	ctx.f9.f64 = double(float(ctx.f13.f64));
	// lfs f31,8884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f31.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f30,8880(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8880);
	f30.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r3,352
	ctx.r3.s64 = 352;
	// rlwinm r11,r8,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8;
	// lfs f29,8876(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8876);
	f29.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f28,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	f28.f64 = double(temp.f32);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// fsel f6,f7,f30,f29
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f30.f64 : f29.f64;
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fadds f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// fsubs f3,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 - ctx.f4.f64));
	// fsubs f2,f4,f28
	ctx.f2.f64 = double(float(ctx.f4.f64 - f28.f64));
	// fsel f1,f3,f4,f2
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f2.f64;
	// fctidz f0,f1
	f0.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfiwx f0,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, f0.u32);
	// beq cr6,0x82141b48
	if (cr6.eq) goto loc_82141B48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82145c50
	ctx.lr = 0x82141B3C;
	sub_82145C50(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82141b48
	if (cr6.lt) goto loc_82141B48;
	// subf r30,r3,r30
	r30.s64 = r30.s64 - ctx.r3.s64;
loc_82141B48:
	// li r5,44
	ctx.r5.s64 = 44;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x823d9890
	ctx.lr = 0x82141B58;
	sub_823D9890(ctx, base);
	// clrldi r10,r30,32
	ctx.r10.u64 = r30.u64 & 0xFFFFFFFF;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fmuls f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// fsel f6,f7,f30,f29
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f30.f64 : f29.f64;
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fadds f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// fsubs f3,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 - ctx.f4.f64));
	// fsubs f2,f4,f28
	ctx.f2.f64 = double(float(ctx.f4.f64 - f28.f64));
	// fsel f1,f3,f4,f2
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f2.f64;
	// fctidz f0,f1
	f0.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x823ea538
	ctx.lr = 0x82141BC0;
	sub_823EA538(ctx, base);
loc_82141BC0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x82141BCC;
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

PPC_WEAK_FUNC(sub_821419C0) {
	__imp__sub_821419C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141BE0) {
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
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82141c30
	if (cr6.eq) goto loc_82141C30;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823ea5e8
	ctx.lr = 0x82141C10;
	sub_823EA5E8(ctx, base);
	// lwz r11,352(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
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
loc_82141C30:
	// lwz r10,352(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
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

PPC_WEAK_FUNC(sub_82141BE0) {
	__imp__sub_82141BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82141C4C) {
	__imp__sub_82141C4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82141C50) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82141C58;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823db9d8
	ctx.lr = 0x82141C60;
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 948, r30.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lbz r11,24(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 24);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82141ca8
	if (cr6.eq) goto loc_82141CA8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,5628
	ctx.r10.s64 = r11.s64 + 5628;
	// lbz r8,40(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82141ca8
	if (cr6.eq) goto loc_82141CA8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,3796
	ctx.r10.s64 = r11.s64 + 3796;
	// lfs f29,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fmr f31,f29
	f31.f64 = f29.f64;
	// b 0x82141cf4
	goto loc_82141CF4;
loc_82141CA8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,26(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 26);
	// addi r10,r10,3796
	ctx.r10.s64 = ctx.r10.s64 + 3796;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f29,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f29.f64 = double(temp.f32);
	// bne cr6,0x82141cc8
	if (!cr6.eq) goto loc_82141CC8;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x82141cf0
	goto loc_82141CF0;
loc_82141CC8:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r8,r11,22
	ctx.r8.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r7,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_82141CF0:
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
loc_82141CF4:
	// lhz r11,32(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82141d08
	if (!cr6.eq) goto loc_82141D08;
	// fmr f13,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f29.f64;
	// b 0x82141d30
	goto loc_82141D30;
loc_82141D08:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r8,r11,22
	ctx.r8.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// addi r6,r11,112
	ctx.r6.s64 = r11.s64 + 112;
	// rlwinm r5,r7,13,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r4,r6,23,0,8
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0xFF800000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_82141D30:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,30(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 30);
	// addi r10,r10,12580
	ctx.r10.s64 = ctx.r10.s64 + 12580;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bne cr6,0x82141d54
	if (!cr6.eq) goto loc_82141D54;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x82141d7c
	goto loc_82141D7C;
loc_82141D54:
	// rlwinm r8,r11,3,0,13
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r7,r11,22
	ctx.r7.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// addi r5,r11,112
	ctx.r5.s64 = r11.s64 + 112;
	// rlwinm r4,r6,13,0,18
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r3,r5,23,0,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 23) & 0xFF800000;
	// or r11,r4,r3
	r11.u64 = ctx.r4.u64 | ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_82141D7C:
	// lhz r11,28(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 28);
	// fmuls f30,f0,f13
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(f0.f64 * ctx.f13.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82141d94
	if (!cr6.eq) goto loc_82141D94;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x82141dbc
	goto loc_82141DBC;
loc_82141D94:
	// rlwinm r8,r11,3,0,13
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r7,r11,22
	ctx.r7.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// addi r5,r11,112
	ctx.r5.s64 = r11.s64 + 112;
	// rlwinm r4,r6,13,0,18
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r3,r5,23,0,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 23) & 0xFF800000;
	// or r11,r4,r3
	r11.u64 = ctx.r4.u64 | ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_82141DBC:
	// lhz r9,16(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// fmuls f28,f0,f13
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lbz r11,364(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 364);
	// li r29,0
	r29.s64 = 0;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// rlwinm r7,r11,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// frsp f0,f13
	f0.f64 = double(float(ctx.f13.f64));
	// bne cr6,0x82141e28
	if (!cr6.eq) goto loc_82141E28;
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82141e28
	if (!cr6.eq) goto loc_82141E28;
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82141e28
	if (!cr6.eq) goto loc_82141E28;
	// lbz r11,136(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 136);
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82141e20
	if (cr6.eq) goto loc_82141E20;
	// rlwinm r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82141e28
	if (!cr6.eq) goto loc_82141E28;
loc_82141E20:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x82141e2c
	goto loc_82141E2C;
loc_82141E28:
	// li r11,1
	r11.s64 = 1;
loc_82141E2C:
	// fmuls f12,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f30.f64 * f31.f64));
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// li r10,1
	ctx.r10.s64 = 1;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x82141e48
	if (!cr6.gt) goto loc_82141E48;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82141E48:
	// fmuls f12,f28,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f28.f64 * f31.f64));
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x82141e5c
	if (!cr6.gt) goto loc_82141E5C;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82141E5C:
	// clrlwi r31,r9,24
	r31.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82141e88
	if (cr6.eq) goto loc_82141E88;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82141e80
	if (cr6.eq) goto loc_82141E80;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82141e88
	if (!cr6.eq) goto loc_82141E88;
loc_82141E80:
	// li r11,1
	r11.s64 = 1;
	// b 0x82141e8c
	goto loc_82141E8C;
loc_82141E88:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82141E8C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lfs f13,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82141ecc
	if (cr6.eq) goto loc_82141ECC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f12,5584(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5584);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,5672(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5672);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmuls f8,f13,f11
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fsubs f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsubs f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fsel f5,f7,f0,f9
	ctx.f5.f64 = ctx.f7.f64 >= 0.0 ? f0.f64 : ctx.f9.f64;
	// fsel f4,f6,f8,f0
	ctx.f4.f64 = ctx.f6.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsel f0,f10,f5,f4
	f0.f64 = ctx.f10.f64 >= 0.0 ? ctx.f5.f64 : ctx.f4.f64;
loc_82141ECC:
	// stfs f0,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 28, temp.u32);
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,340(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 340);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ea1a8
	ctx.lr = 0x82141EEC;
	sub_823EA1A8(ctx, base);
	// addi r6,r30,32
	ctx.r6.s64 = r30.s64 + 32;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r8,34
	ctx.r8.s64 = 34;
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r9,r30,60
	ctx.r9.s64 = r30.s64 + 60;
	// lis r4,-32131
	ctx.r4.s64 = -2105737216;
loc_82141F04:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lhzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + r11.u32);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// bne cr6,0x82141f2c
	if (!cr6.eq) goto loc_82141F2C;
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = f29.f64;
	// b 0x82141f54
	goto loc_82141F54;
loc_82141F2C:
	// rlwinm r3,r10,3,0,13
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r28,r10,22
	r28.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// or r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 | r28.u64;
	// addi r10,r10,112
	ctx.r10.s64 = ctx.r10.s64 + 112;
	// rlwinm r3,r3,13,0,18
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r10,r10,23,0,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0xFF800000;
	// or r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 | ctx.r10.u64;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
loc_82141F54:
	// fmuls f11,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f0.f64 * f31.f64));
	// cmplwi cr6,r5,2
	cr6.compare<uint32_t>(ctx.r5.u32, 2, xer);
	// beq cr6,0x82142050
	if (cr6.eq) goto loc_82142050;
	// cmplwi cr6,r5,3
	cr6.compare<uint32_t>(ctx.r5.u32, 3, xer);
	// beq cr6,0x82142050
	if (cr6.eq) goto loc_82142050;
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + r11.u64;
	// lhz r10,-2(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82141f80
	if (!cr6.eq) goto loc_82141F80;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x82141fa8
	goto loc_82141FA8;
loc_82141F80:
	// rlwinm r3,r10,3,0,13
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r28,r10,22
	r28.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// or r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 | r28.u64;
	// addi r10,r10,112
	ctx.r10.s64 = ctx.r10.s64 + 112;
	// rlwinm r3,r3,13,0,18
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r10,r10,23,0,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0xFF800000;
	// or r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 | ctx.r10.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_82141FA8:
	// lhzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + r11.u32);
	// fmuls f12,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 * f31.f64));
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82141fc4
	if (!cr6.eq) goto loc_82141FC4;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x82141fec
	goto loc_82141FEC;
loc_82141FC4:
	// rlwinm r3,r10,3,0,13
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r28,r10,22
	r28.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// or r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 | r28.u64;
	// addi r10,r10,112
	ctx.r10.s64 = ctx.r10.s64 + 112;
	// rlwinm r3,r3,13,0,18
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r10,r10,23,0,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0xFF800000;
	// or r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 | ctx.r10.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_82141FEC:
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// fmuls f10,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(f0.f64 * f31.f64));
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lhz r11,2(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82142018
	if (!cr6.eq) goto loc_82142018;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// addi r7,r7,6
	ctx.r7.s64 = ctx.r7.s64 + 6;
	// fmuls f9,f0,f31
	ctx.f9.f64 = double(float(f0.f64 * f31.f64));
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// b 0x8214205c
	goto loc_8214205C;
loc_82142018:
	// clrlwi r3,r11,22
	ctx.r3.u64 = r11.u32 & 0x3FF;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 | ctx.r3.u64;
	// addi r3,r11,112
	ctx.r3.s64 = r11.s64 + 112;
	// rlwinm r11,r10,13,0,18
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r10,r3,23,0,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 23) & 0xFF800000;
	// addi r7,r7,6
	ctx.r7.s64 = ctx.r7.s64 + 6;
	// or r3,r11,r10
	ctx.r3.u64 = r11.u64 | ctx.r10.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmuls f9,f0,f31
	ctx.f9.f64 = double(float(f0.f64 * f31.f64));
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// b 0x8214205c
	goto loc_8214205C;
loc_82142050:
	// lfs f9,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
loc_8214205C:
	// lfs f13,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82142070
	if (!cr6.eq) goto loc_82142070;
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
	// b 0x82142090
	goto loc_82142090;
loc_82142070:
	// fsubs f8,f11,f13
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f0,5580(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 5580);
	f0.f64 = double(temp.f32);
	// fadds f7,f13,f0
	ctx.f7.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fsubs f6,f13,f0
	ctx.f6.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f5,f8
	ctx.f5.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// fsel f4,f8,f7,f6
	ctx.f4.f64 = ctx.f8.f64 >= 0.0 ? ctx.f7.f64 : ctx.f6.f64;
	// fsubs f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsel f0,f3,f4,f11
	f0.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f11.f64;
loc_82142090:
	// stfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lfs f13,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// bne cr6,0x821420a8
	if (!cr6.eq) goto loc_821420A8;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
	// b 0x821420c8
	goto loc_821420C8;
loc_821420A8:
	// fsubs f11,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f0,5580(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 5580);
	f0.f64 = double(temp.f32);
	// fadds f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fsubs f7,f13,f0
	ctx.f7.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f6,f11
	ctx.f6.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fsel f5,f11,f8,f7
	ctx.f5.f64 = ctx.f11.f64 >= 0.0 ? ctx.f8.f64 : ctx.f7.f64;
	// fsubs f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsel f0,f4,f5,f12
	f0.f64 = ctx.f4.f64 >= 0.0 ? ctx.f5.f64 : ctx.f12.f64;
loc_821420C8:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stfs f0,-4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// bne cr6,0x821420e0
	if (!cr6.eq) goto loc_821420E0;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// b 0x82142100
	goto loc_82142100;
loc_821420E0:
	// fsubs f12,f10,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f0,5580(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 5580);
	f0.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fsubs f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f7,f12
	ctx.f7.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fsel f6,f12,f11,f8
	ctx.f6.f64 = ctx.f12.f64 >= 0.0 ? ctx.f11.f64 : ctx.f8.f64;
	// fsubs f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 - f0.f64));
	// fsel f0,f5,f6,f10
	f0.f64 = ctx.f5.f64 >= 0.0 ? ctx.f6.f64 : ctx.f10.f64;
loc_82142100:
	// lfs f13,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// bne cr6,0x82142118
	if (!cr6.eq) goto loc_82142118;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// b 0x82142138
	goto loc_82142138;
loc_82142118:
	// fsubs f12,f9,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f0,5580(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 5580);
	f0.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fabs f8,f12
	ctx.f8.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fsel f7,f12,f11,f10
	ctx.f7.f64 = ctx.f12.f64 >= 0.0 ? ctx.f11.f64 : ctx.f10.f64;
	// fsubs f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fsel f0,f6,f7,f9
	f0.f64 = ctx.f6.f64 >= 0.0 ? ctx.f7.f64 : ctx.f9.f64;
loc_82142138:
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// stfs f0,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmplwi cr6,r8,46
	cr6.compare<uint32_t>(ctx.r8.u32, 46, xer);
	// blt cr6,0x82141f04
	if (cr6.lt) goto loc_82141F04;
	// addi r11,r1,752
	r11.s64 = ctx.r1.s64 + 752;
	// addi r10,r1,656
	ctx.r10.s64 = ctx.r1.s64 + 656;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r30,6
	r30.s64 = 6;
loc_8214217C:
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,384
	ctx.r7.s64 = ctx.r1.s64 + 384;
	// li r29,2
	r29.s64 = 2;
	// addi r6,r1,152
	ctx.r6.s64 = ctx.r1.s64 + 152;
	// addi r3,r1,392
	ctx.r3.s64 = ctx.r1.s64 + 392;
	// stbx r29,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, r29.u8);
	// addi r23,r1,408
	r23.s64 = ctx.r1.s64 + 408;
	// stbx r29,r11,r7
	PPC_STORE_U8(r11.u32 + ctx.r7.u32, r29.u8);
	// li r29,3
	r29.s64 = 3;
	// addi r31,r1,136
	r31.s64 = ctx.r1.s64 + 136;
	// stbx r29,r11,r6
	PPC_STORE_U8(r11.u32 + ctx.r6.u32, r29.u8);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stbx r29,r11,r3
	PPC_STORE_U8(r11.u32 + ctx.r3.u32, r29.u8);
	// addi r25,r1,376
	r25.s64 = ctx.r1.s64 + 376;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// addi r24,r1,168
	r24.s64 = ctx.r1.s64 + 168;
	// li r29,5
	r29.s64 = 5;
	// addi r27,r1,128
	r27.s64 = ctx.r1.s64 + 128;
	// stbx r4,r11,r6
	PPC_STORE_U8(r11.u32 + ctx.r6.u32, ctx.r4.u8);
	// li r28,1
	r28.s64 = 1;
	// stbx r29,r11,r23
	PPC_STORE_U8(r11.u32 + r23.u32, r29.u8);
	// addi r26,r1,368
	r26.s64 = ctx.r1.s64 + 368;
	// stbx r4,r11,r3
	PPC_STORE_U8(r11.u32 + ctx.r3.u32, ctx.r4.u8);
	// addi r8,r1,756
	ctx.r8.s64 = ctx.r1.s64 + 756;
	// stbx r28,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, r28.u8);
	// addi r7,r1,608
	ctx.r7.s64 = ctx.r1.s64 + 608;
	// stbx r29,r11,r24
	PPC_STORE_U8(r11.u32 + r24.u32, r29.u8);
	// addi r6,r1,704
	ctx.r6.s64 = ctx.r1.s64 + 704;
	// stbx r28,r11,r25
	PPC_STORE_U8(r11.u32 + r25.u32, r28.u8);
	// li r23,0
	r23.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r22,r1,612
	r22.s64 = ctx.r1.s64 + 612;
	// stbx r23,r11,r27
	PPC_STORE_U8(r11.u32 + r27.u32, r23.u8);
	// addi r25,r1,656
	r25.s64 = ctx.r1.s64 + 656;
	// addi r24,r1,660
	r24.s64 = ctx.r1.s64 + 660;
	// addi r31,r1,368
	r31.s64 = ctx.r1.s64 + 368;
	// addi r29,r1,708
	r29.s64 = ctx.r1.s64 + 708;
	// li r21,0
	r21.s64 = 0;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stbx r21,r11,r26
	PPC_STORE_U8(r11.u32 + r26.u32, r21.u8);
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// clrlwi r27,r5,24
	r27.u64 = ctx.r5.u32 & 0xFF;
	// add r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 + ctx.r3.u64;
	// stwx r6,r10,r24
	PPC_STORE_U32(ctx.r10.u32 + r24.u32, ctx.r6.u32);
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// stbx r27,r10,r25
	PPC_STORE_U8(ctx.r10.u32 + r25.u32, r27.u8);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// stwx r3,r10,r22
	PPC_STORE_U32(ctx.r10.u32 + r22.u32, ctx.r3.u32);
	// stwx r31,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + r29.u32, r31.u32);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// stb r27,-4(r8)
	PPC_STORE_U8(ctx.r8.u32 + -4, r27.u8);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stb r30,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, r30.u8);
	// cmplwi cr6,r11,240
	cr6.compare<uint32_t>(r11.u32, 240, xer);
	// stb r30,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, r30.u8);
	// blt cr6,0x8214217c
	if (cr6.lt) goto loc_8214217C;
	// lwz r31,948(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 948);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	f0.f64 = double(temp.f32);
	// lfs f13,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lbz r11,70(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 70);
	// stfs f0,372(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// stfs f13,380(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8214239c
	if (cr6.eq) goto loc_8214239C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// beq cr6,0x821423a0
	if (cr6.eq) goto loc_821423A0;
	// lfs f12,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f0,f30
	ctx.f11.f64 = double(float(f0.f64 * f30.f64));
	// lfs f10,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f13,f30
	ctx.f9.f64 = double(float(ctx.f13.f64 * f30.f64));
	// lfs f8,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f12,f30
	ctx.f7.f64 = double(float(ctx.f12.f64 * f30.f64));
	// lfs f6,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f10,f30
	ctx.f5.f64 = double(float(ctx.f10.f64 * f30.f64));
	// fmuls f4,f8,f30
	ctx.f4.f64 = double(float(ctx.f8.f64 * f30.f64));
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmuls f3,f6,f30
	ctx.f3.f64 = double(float(ctx.f6.f64 * f30.f64));
	// stfs f9,140(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f7,148(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stb r4,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r4.u8);
	// stfs f12,388(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stb r4,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r4.u8);
	// stfs f5,156(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r10,r31,68
	ctx.r10.s64 = r31.s64 + 68;
	// stfs f10,396(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// li r11,48
	r11.s64 = 48;
	// stfs f4,164(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f8,404(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f3,172(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f6,412(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 412, temp.u32);
loc_821422F8:
	// addi r8,r1,132
	ctx.r8.s64 = ctx.r1.s64 + 132;
	// lfs f0,-12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	f0.f64 = double(temp.f32);
	// addi r7,r1,372
	ctx.r7.s64 = ctx.r1.s64 + 372;
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,140
	ctx.r6.s64 = ctx.r1.s64 + 140;
	// lfs f12,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r1,380
	ctx.r5.s64 = ctx.r1.s64 + 380;
	// lfs f11,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// addi r3,r1,148
	ctx.r3.s64 = ctx.r1.s64 + 148;
	// lfs f10,36(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// addi r30,r1,388
	r30.s64 = ctx.r1.s64 + 388;
	// lfs f9,48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// addi r29,r1,156
	r29.s64 = ctx.r1.s64 + 156;
	// fmuls f8,f0,f30
	ctx.f8.f64 = double(float(f0.f64 * f30.f64));
	// addi r27,r1,396
	r27.s64 = ctx.r1.s64 + 396;
	// fmuls f7,f13,f30
	ctx.f7.f64 = double(float(ctx.f13.f64 * f30.f64));
	// addi r26,r1,164
	r26.s64 = ctx.r1.s64 + 164;
	// fmuls f6,f12,f30
	ctx.f6.f64 = double(float(ctx.f12.f64 * f30.f64));
	// addi r25,r1,404
	r25.s64 = ctx.r1.s64 + 404;
	// fmuls f5,f11,f30
	ctx.f5.f64 = double(float(ctx.f11.f64 * f30.f64));
	// addi r24,r1,172
	r24.s64 = ctx.r1.s64 + 172;
	// fmuls f4,f10,f30
	ctx.f4.f64 = double(float(ctx.f10.f64 * f30.f64));
	// addi r23,r1,412
	r23.s64 = ctx.r1.s64 + 412;
	// fmuls f3,f9,f30
	ctx.f3.f64 = double(float(ctx.f9.f64 * f30.f64));
	// stfsx f8,r11,r8
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stfsx f0,r11,r7
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, temp.u32);
	// stfsx f7,r11,r6
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, temp.u32);
	// stfsx f13,r11,r5
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, temp.u32);
	// stfsx f6,r11,r3
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, temp.u32);
	// stfsx f12,r11,r30
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + r30.u32, temp.u32);
	// stfsx f5,r11,r29
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + r29.u32, temp.u32);
	// stfsx f11,r11,r27
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + r27.u32, temp.u32);
	// stfsx f4,r11,r26
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + r26.u32, temp.u32);
	// stfsx f10,r11,r25
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + r25.u32, temp.u32);
	// stfsx f3,r11,r24
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + r24.u32, temp.u32);
	// stfsx f9,r11,r23
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + r23.u32, temp.u32);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// cmplwi cr6,r11,192
	cr6.compare<uint32_t>(r11.u32, 192, xer);
	// blt cr6,0x821422f8
	if (cr6.lt) goto loc_821422F8;
	// b 0x821423fc
	goto loc_821423FC;
loc_8214239C:
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
loc_821423A0:
	// lfs f5,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f5.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lfs f7,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f3,f5,f30
	ctx.f3.f64 = double(float(ctx.f5.f64 * f30.f64));
	// lfs f9,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f4,f7,f30
	ctx.f4.f64 = double(float(ctx.f7.f64 * f30.f64));
	// lfs f11,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f9,f30
	ctx.f6.f64 = double(float(ctx.f9.f64 * f30.f64));
	// fmuls f8,f11,f30
	ctx.f8.f64 = double(float(ctx.f11.f64 * f30.f64));
	// stfs f5,412(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// fmuls f10,f13,f30
	ctx.f10.f64 = double(float(ctx.f13.f64 * f30.f64));
	// stfs f3,172(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// fmuls f12,f0,f30
	ctx.f12.f64 = double(float(f0.f64 * f30.f64));
	// stfs f7,404(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f4,164(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stb r28,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r28.u8);
	// stfs f9,396(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stb r4,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r4.u8);
	// stfs f6,156(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f11,388(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stfs f8,148(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f10,140(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
loc_821423FC:
	// lwz r3,344(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 344);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82142450
	if (cr6.eq) goto loc_82142450;
	// lbz r11,24(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 24);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82142424
	if (cr6.eq) goto loc_82142424;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823ea270
	ctx.lr = 0x82142420;
	sub_823EA270(ctx, base);
	// lbz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
loc_82142424:
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r10,r4,1,23,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FE;
	// rlwinm r9,r4,3,21,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0x7F8;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// addi r7,r1,608
	ctx.r7.s64 = ctx.r1.s64 + 608;
	// rlwinm r6,r8,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r5,r1,132
	ctx.r5.s64 = ctx.r1.s64 + 132;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stbx r28,r9,r7
	PPC_STORE_U8(ctx.r9.u32 + ctx.r7.u32, r28.u8);
	// stb r4,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r4.u8);
	// stfsx f28,r6,r5
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r5.u32, temp.u32);
loc_82142450:
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82142464
	if (cr6.eq) goto loc_82142464;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x823ea270
	ctx.lr = 0x82142464;
	sub_823EA270(ctx, base);
loc_82142464:
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dba24
	ctx.lr = 0x82142470;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82141C50) {
	__imp__sub_82141C50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82142474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82142474) {
	__imp__sub_82142474(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82142478) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821424A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8214256c
	if (cr6.eq) goto loc_8214256C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82141be0
	ctx.lr = 0x821424B8;
	sub_82141BE0(ctx, base);
	// clrldi r10,r3,32
	ctx.r10.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,8884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8884);
	f0.f64 = double(temp.f32);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,8880(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// lfs f12,8876(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fdivs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// fsel f5,f6,f13,f12
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fadds f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// fsubs f2,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 - ctx.f3.f64));
	// fsubs f1,f3,f11
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f11.f64));
	// fsel f10,f2,f3,f1
	ctx.f10.f64 = ctx.f2.f64 >= 0.0 ? ctx.f3.f64 : ctx.f1.f64;
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82142570
	if (!cr6.gt) goto loc_82142570;
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82142588
	if (!cr6.eq) goto loc_82142588;
	// lbz r9,136(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// rlwinm r8,r9,0,28,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82142588
	if (!cr6.eq) goto loc_82142588;
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214256c
	if (cr6.eq) goto loc_8214256C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ea420
	ctx.lr = 0x8214256C;
	sub_823EA420(ctx, base);
loc_8214256C:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82142570:
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
loc_82142588:
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f10,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fdivs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// fsel f2,f3,f13,f12
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fsubs f12,f0,f11
	ctx.f12.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsel f11,f13,f0,f12
	ctx.f11.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x821425ec
	if (!cr6.lt) goto loc_821425EC;
	// li r11,1
	r11.s64 = 1;
loc_821425EC:
	// subf r8,r10,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r10.s64;
	// twllei r11,0
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r7,r8,r11
	ctx.r7.s32 = ctx.r8.s32 / r11.s32;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// mullw r6,r7,r11
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// subf r9,r6,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r6.s64;
	// andc r4,r11,r5
	ctx.r4.u64 = r11.u64 & ~ctx.r5.u64;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// twlgei r4,-1
	// b 0x82142570
	goto loc_82142570;
}

PPC_WEAK_FUNC(sub_82142478) {
	__imp__sub_82142478(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82142618) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821426a8
	if (cr6.eq) goto loc_821426A8;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x823ea1a8
	ctx.lr = 0x8214266C;
	sub_823EA1A8(ctx, base);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821416b0
	ctx.lr = 0x8214267C;
	sub_821416B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82141c50
	ctx.lr = 0x82142684;
	sub_82141C50(ctx, base);
	// lwz r3,340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821426a8
	if (cr6.eq) goto loc_821426A8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823ea2c8
	ctx.lr = 0x82142698;
	sub_823EA2C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x821426a8
	if (cr6.lt) goto loc_821426A8;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// stb r11,364(r31)
	PPC_STORE_U8(r31.u32 + 364, r11.u8);
loc_821426A8:
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

PPC_WEAK_FUNC(sub_82142618) {
	__imp__sub_82142618(ctx, base);
}

