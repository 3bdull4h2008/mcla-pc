#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_821E552C"))) PPC_WEAK_FUNC(sub_821E552C);
PPC_FUNC_IMPL(__imp__sub_821E552C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E5530"))) PPC_WEAK_FUNC(sub_821E5530);
PPC_FUNC_IMPL(__imp__sub_821E5530) {
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
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne cr6,0x821e5570
	if (!cr6.eq) goto loc_821E5570;
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
loc_821E5570:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x821bc7a0
	ctx.lr = 0x821E5578;
	sub_821BC7A0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_821E5598"))) PPC_WEAK_FUNC(sub_821E5598);
PPC_FUNC_IMPL(__imp__sub_821E5598) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x821E55A0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r10,2(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 2);
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// add. r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x821e5638
	if (cr0.eq) goto loc_821E5638;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,28
	r28.s64 = 28;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
loc_821E55D4:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r30,r30,-12
	r30.s64 = r30.s64 + -12;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x821e55f0
	if (!cr6.lt) goto loc_821E55F0;
	// li r11,0
	r11.s64 = 0;
loc_821E55F0:
	// lwzx r3,r28,r27
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r26,0(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r11,r9,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821E561C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r5,12(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821E5630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x821e55d4
	if (!cr6.eq) goto loc_821E55D4;
loc_821E5638:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821E5640"))) PPC_WEAK_FUNC(sub_821E5640);
PPC_FUNC_IMPL(__imp__sub_821E5640) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bne cr6,0x821e5684
	if (!cr6.eq) goto loc_821E5684;
	// bl 0x821c9078
	ctx.lr = 0x821E5670;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e5688
	if (!cr6.eq) goto loc_821E5688;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821e56bc
	goto loc_821E56BC;
loc_821E5684:
	// bl 0x821c90c0
	ctx.lr = 0x821E5688;
	sub_821C90C0(ctx, base);
loc_821E5688:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821c9158
	ctx.lr = 0x821E5690;
	sub_821C9158(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e56b8
	if (cr6.eq) goto loc_821E56B8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821bd220
	ctx.lr = 0x821E56B0;
	sub_821BD220(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_821E56B8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_821E56BC:
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

__attribute__((alias("__imp__sub_821E56D4"))) PPC_WEAK_FUNC(sub_821E56D4);
PPC_FUNC_IMPL(__imp__sub_821E56D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E56D8"))) PPC_WEAK_FUNC(sub_821E56D8);
PPC_FUNC_IMPL(__imp__sub_821E56D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,256
	ctx.r10.s64 = 256;
	// li r9,4096
	ctx.r9.s64 = 4096;
	// rlwinm r8,r11,21,28,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0xF;
	// clrlwi r7,r11,21
	ctx.r7.u64 = r11.u32 & 0x7FF;
	// slw r6,r10,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// slw r11,r9,r8
	r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// mullw r5,r6,r7
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// divwu r4,r5,r11
	ctx.r4.u32 = ctx.r5.u32 / r11.u32;
	// twllei r11,0
	// mullw r3,r4,r11
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(r11.s32);
	// divwu r9,r5,r11
	ctx.r9.u32 = ctx.r5.u32 / r11.u32;
	// twllei r11,0
	// subf r10,r3,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r3.s64;
	// cmplwi cr6,r11,4096
	cr6.compare<uint32_t>(r11.u32, 4096, xer);
	// ble cr6,0x821e5734
	if (!cr6.gt) goto loc_821E5734;
loc_821E5718:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x821e5728
	if (cr6.lt) goto loc_821E5728;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
loc_821E5728:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,4096
	cr6.compare<uint32_t>(r11.u32, 4096, xer);
	// bgt cr6,0x821e5718
	if (cr6.gt) goto loc_821E5718;
loc_821E5734:
	// subfic r11,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	r11.s64 = 0 - ctx.r10.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E5748"))) PPC_WEAK_FUNC(sub_821E5748);
PPC_FUNC_IMPL(__imp__sub_821E5748) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,256
	ctx.r10.s64 = 256;
	// li r9,4096
	ctx.r9.s64 = 4096;
	// rlwinm r8,r11,6,28,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xF;
	// rlwinm r7,r11,17,21,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0x7FF;
	// slw r6,r10,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// slw r11,r9,r8
	r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// mullw r5,r7,r6
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// divwu r4,r5,r11
	ctx.r4.u32 = ctx.r5.u32 / r11.u32;
	// twllei r11,0
	// mullw r3,r4,r11
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(r11.s32);
	// divwu r9,r5,r11
	ctx.r9.u32 = ctx.r5.u32 / r11.u32;
	// twllei r11,0
	// subf r10,r3,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r3.s64;
	// cmplwi cr6,r11,4096
	cr6.compare<uint32_t>(r11.u32, 4096, xer);
	// ble cr6,0x821e57a4
	if (!cr6.gt) goto loc_821E57A4;
loc_821E5788:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x821e5798
	if (cr6.lt) goto loc_821E5798;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
loc_821E5798:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,4096
	cr6.compare<uint32_t>(r11.u32, 4096, xer);
	// bgt cr6,0x821e5788
	if (cr6.gt) goto loc_821E5788;
loc_821E57A4:
	// subfic r11,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	r11.s64 = 0 - ctx.r10.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E57B8"))) PPC_WEAK_FUNC(sub_821E57B8);
PPC_FUNC_IMPL(__imp__sub_821E57B8) {
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
	ctx.lr = 0x821E57C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,132
	ctx.r3.s64 = ctx.r1.s64 + 132;
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r29.u32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x821e56d8
	ctx.lr = 0x821E57D8;
	sub_821E56D8(ctx, base);
	// clrlwi r30,r3,16
	r30.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r3,r1,132
	ctx.r3.s64 = ctx.r1.s64 + 132;
	// sth r30,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r30.u16);
	// bl 0x821e5748
	ctx.lr = 0x821E57E8;
	sub_821E5748(ctx, base);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r6,4096
	ctx.r6.s64 = 4096;
	// sth r3,2(r31)
	PPC_STORE_U16(r31.u32 + 2, ctx.r3.u16);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821e5860
	if (cr6.eq) goto loc_821E5860;
	// rlwinm r11,r29,21,28,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 21) & 0xF;
	// clrlwi r10,r29,21
	ctx.r10.u64 = r29.u32 & 0x7FF;
	// slw r8,r5,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (r11.u8 & 0x3F));
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// slw r11,r6,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r6.u32 << (r11.u8 & 0x3F));
	// lis r7,20480
	ctx.r7.s64 = 1342177280;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e5860
	if (cr6.eq) goto loc_821E5860;
	// addi r9,r31,4
	ctx.r9.s64 = r31.s64 + 4;
loc_821E5828:
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x821e583c
	if (!cr6.lt) goto loc_821E583C;
loc_821E5830:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x821e5830
	if (cr6.lt) goto loc_821E5830;
loc_821E583C:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// lhz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + r11.u64;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// blt cr6,0x821e5828
	if (cr6.lt) goto loc_821E5828;
loc_821E5860:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e58e8
	if (cr6.eq) goto loc_821E58E8;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// rlwinm r9,r29,6,28,31
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 6) & 0xF;
	// rlwinm r8,r29,17,21,31
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 17) & 0x7FF;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// slw r3,r5,r9
	ctx.r3.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r9.u8 & 0x3F));
	// slw r11,r6,r9
	r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r9.u8 & 0x3F));
	// mullw r8,r8,r3
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r3.s32);
	// lis r7,24576
	ctx.r7.s64 = 1610612736;
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bge cr6,0x821e58e8
	if (!cr6.lt) goto loc_821E58E8;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
loc_821E58A8:
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// bge cr6,0x821e58bc
	if (!cr6.lt) goto loc_821E58BC;
loc_821E58B0:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// blt cr6,0x821e58b0
	if (cr6.lt) goto loc_821E58B0;
loc_821E58BC:
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - r11.s64;
	// lhz r6,2(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + r11.u64;
	// lhz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// blt cr6,0x821e58a8
	if (cr6.lt) goto loc_821E58A8;
loc_821E58E8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E58F0"))) PPC_WEAK_FUNC(sub_821E58F0);
PPC_FUNC_IMPL(__imp__sub_821E58F0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x821E58F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x821e57b8
	ctx.lr = 0x821E5908;
	sub_821E57B8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-12671(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -12671);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// beq cr6,0x821e5aa4
	if (cr6.eq) goto loc_821E5AA4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e59b8
	if (cr6.eq) goto loc_821E59B8;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
loc_821E5930:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r4,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r4.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// addi r9,r9,127
	ctx.r9.s64 = ctx.r9.s64 + 127;
	// lhz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// rlwinm r9,r9,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// blt cr6,0x821e5930
	if (cr6.lt) goto loc_821E5930;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821E597C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e5be4
	if (cr6.eq) goto loc_821E5BE4;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e59b8
	if (cr6.eq) goto loc_821E59B8;
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
loc_821E5998:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r9,r3,r9
	ctx.r9.u64 = ctx.r3.u64 + ctx.r9.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// lhz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x821e5998
	if (cr6.lt) goto loc_821E5998;
loc_821E59B8:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e5a98
	if (cr6.eq) goto loc_821E5A98;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x821e5a1c
	if (!cr6.lt) goto loc_821E5A1C;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
loc_821E59EC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r4,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r4.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// addi r9,r9,127
	ctx.r9.s64 = ctx.r9.s64 + 127;
	// lhz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// rlwinm r9,r9,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lhz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x821e59ec
	if (cr6.lt) goto loc_821E59EC;
loc_821E5A1C:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821E5A40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e5be4
	if (cr6.eq) goto loc_821E5BE4;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x821e5a98
	if (!cr6.lt) goto loc_821E5A98;
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
loc_821E5A70:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// lhz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x821e5a70
	if (cr6.lt) goto loc_821E5A70;
loc_821E5A98:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821E5AA4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e5afc
	if (cr6.eq) goto loc_821E5AFC;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// li r27,28
	r27.s64 = 28;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
loc_821E5ABC:
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E5ADC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e5b88
	if (cr6.eq) goto loc_821E5B88;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x821e5abc
	if (cr6.lt) goto loc_821E5ABC;
loc_821E5AFC:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e5a98
	if (cr6.eq) goto loc_821E5A98;
	// lhz r30,0(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bge cr6,0x821e5a98
	if (!cr6.lt) goto loc_821E5A98;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,28
	r28.s64 = 28;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r29,r11,8
	r29.s64 = r11.s64 + 8;
loc_821E5B34:
	// lwzx r3,r28,r27
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// li r6,3
	ctx.r6.s64 = 3;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E5B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e5bf0
	if (cr6.eq) goto loc_821E5BF0;
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x821e5b34
	if (cr6.lt) goto loc_821E5B34;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821E5B88:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821e5be4
	if (cr6.eq) goto loc_821E5BE4;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
loc_821E5BA4:
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// addi r31,r31,-12
	r31.s64 = r31.s64 + -12;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E5BC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821E5BDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821e5ba4
	if (!cr6.eq) goto loc_821E5BA4;
loc_821E5BE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821E5BF0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821e5c6c
	if (cr6.eq) goto loc_821E5C6C;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r29,r11,8
	r29.s64 = r11.s64 + 8;
loc_821E5C0C:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// lwzx r3,r28,r27
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// addi r29,r29,-12
	r29.s64 = r29.s64 + -12;
	// subfc r10,r11,r30
	xer.ca = r30.u32 >= r11.u32;
	ctx.r10.s64 = r30.s64 - r11.s64;
	// subfe r11,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r26,0(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// subfic r7,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// lwz r6,20(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r5,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821E5C50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E5C64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821e5c0c
	if (!cr6.eq) goto loc_821E5C0C;
loc_821E5C6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821E5C78"))) PPC_WEAK_FUNC(sub_821E5C78);
PPC_FUNC_IMPL(__imp__sub_821E5C78) {
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
	ctx.lr = 0x821E5C80;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// addi r31,r1,112
	r31.s64 = ctx.r1.s64 + 112;
	// li r29,120
	r29.s64 = 120;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x821e5cd8
	if (cr6.eq) goto loc_821E5CD8;
loc_821E5CAC:
	// cmpwi cr6,r10,35
	cr6.compare<int32_t>(ctx.r10.s32, 35, xer);
	// bne cr6,0x821e5cbc
	if (!cr6.eq) goto loc_821E5CBC;
	// stb r29,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r29.u8);
	// b 0x821e5cc0
	goto loc_821E5CC0;
loc_821E5CBC:
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
loc_821E5CC0:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x821e5cac
	if (!cr6.eq) goto loc_821E5CAC;
loc_821E5CD8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// stb r28,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r28.u8);
	// lbz r10,-12672(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -12672);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e5d24
	if (cr6.eq) goto loc_821E5D24;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x821E5D08;
	sub_82137A08(ctx, base);
	// li r10,46
	ctx.r10.s64 = 46;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stb r28,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r28.u8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c3410
	ctx.lr = 0x821E5D24;
	sub_821C3410(ctx, base);
loc_821E5D24:
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// stb r29,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r29.u8);
	// addi r11,r1,81
	r11.s64 = ctx.r1.s64 + 81;
	// li r8,14
	ctx.r8.s64 = 14;
loc_821E5D34:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e5d70
	if (cr6.eq) goto loc_821E5D70;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e5d6c
	if (cr6.eq) goto loc_821E5D6C;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addic. r8,r8,-2
	xer.ca = ctx.r8.u32 > 1;
	ctx.r8.s64 = ctx.r8.s64 + -2;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bgt 0x821e5d34
	if (cr0.gt) goto loc_821E5D34;
	// b 0x821e5d70
	goto loc_821E5D70;
loc_821E5D6C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_821E5D70:
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// beq cr6,0x821e5db0
	if (cr6.eq) goto loc_821E5DB0;
	// addi r10,r11,30576
	ctx.r10.s64 = r11.s64 + 30576;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r8,3080(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3080);
	// bl 0x821ca2f8
	ctx.lr = 0x821E5DA4;
	sub_821CA2F8(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x823d923c
	return;
loc_821E5DB0:
	// addi r3,r11,30576
	ctx.r3.s64 = r11.s64 + 30576;
	// bl 0x821ca100
	ctx.lr = 0x821E5DB8;
	sub_821CA100(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821E5DC4"))) PPC_WEAK_FUNC(sub_821E5DC4);
PPC_FUNC_IMPL(__imp__sub_821E5DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E5DC8"))) PPC_WEAK_FUNC(sub_821E5DC8);
PPC_FUNC_IMPL(__imp__sub_821E5DC8) {
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
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e5c78
	ctx.lr = 0x821E5E00;
	sub_821E5C78(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821bce68
	ctx.lr = 0x821E5E10;
	sub_821BCE68(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne cr6,0x821e5e2c
	if (!cr6.eq) goto loc_821E5E2C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821e5e3c
	goto loc_821E5E3C;
loc_821E5E2C:
	// bl 0x821bc7a0
	ctx.lr = 0x821E5E30;
	sub_821BC7A0(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_821E5E3C:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
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

__attribute__((alias("__imp__sub_821E5E54"))) PPC_WEAK_FUNC(sub_821E5E54);
PPC_FUNC_IMPL(__imp__sub_821E5E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E5E58"))) PPC_WEAK_FUNC(sub_821E5E58);
PPC_FUNC_IMPL(__imp__sub_821E5E58) {
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
	ctx.lr = 0x821E5E60;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x821e5e9c
	if (!cr6.eq) goto loc_821E5E9C;
	// lis r11,-32228
	r11.s64 = -2112094208;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r29,r11,-15032
	r29.s64 = r11.s64 + -15032;
	// bl 0x821c9060
	ctx.lr = 0x821E5E90;
	sub_821C9060(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// b 0x821e5ea0
	goto loc_821E5EA0;
loc_821E5E9C:
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
loc_821E5EA0:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// lwz r25,12(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r27,r10,27,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821bc6b8
	ctx.lr = 0x821E5EB8;
	sub_821BC6B8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x821e58f0
	ctx.lr = 0x821E5EC4;
	sub_821E58F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e5f1c
	if (cr6.eq) goto loc_821E5F1C;
	// lhz r11,2(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// li r10,0
	ctx.r10.s64 = 0;
	// lhz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,12
	ctx.r6.s64 = 12;
	// add r5,r11,r5
	ctx.r5.u64 = r11.u64 + ctx.r5.u64;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// bl 0x821bcb10
	ctx.lr = 0x821E5EFC;
	sub_821BCB10(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821e5f3c
	if (!cr6.eq) goto loc_821E5F3C;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e5f1c
	if (cr6.eq) goto loc_821E5F1C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e5598
	ctx.lr = 0x821E5F1C;
	sub_821E5598(ctx, base);
loc_821E5F1C:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e5f30
	if (cr6.eq) goto loc_821E5F30;
	// bl 0x821c9158
	ctx.lr = 0x821E5F2C;
	sub_821C9158(ctx, base);
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
loc_821E5F30:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_821E5F3C:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821E5F48"))) PPC_WEAK_FUNC(sub_821E5F48);
PPC_FUNC_IMPL(__imp__sub_821E5F48) {
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
	ctx.lr = 0x821E5F50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x821e5dc8
	ctx.lr = 0x821E5F68;
	sub_821E5DC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e5f80
	if (!cr6.eq) goto loc_821E5F80;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821E5F80:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e5e58
	ctx.lr = 0x821E5F94;
	sub_821E5E58(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x821e5fc4
	if (!cr6.eq) goto loc_821E5FC4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821bd220
	ctx.lr = 0x821E5FA8;
	sub_821BD220(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r10,-32720
	ctx.r3.s64 = ctx.r10.s64 + -32720;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x821E5FC4;
	sub_82130000(ctx, base);
loc_821E5FC4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821E5FD0"))) PPC_WEAK_FUNC(sub_821E5FD0);
PPC_FUNC_IMPL(__imp__sub_821E5FD0) {
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
	ctx.lr = 0x821E5FD8;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821e5c78
	ctx.lr = 0x821E600C;
	sub_821E5C78(ctx, base);
	// bl 0x821bc5d0
	ctx.lr = 0x821E6010;
	sub_821BC5D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r26,r11
	r26.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e6038
	if (cr6.eq) goto loc_821E6038;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x821bd3c8
	ctx.lr = 0x821E6038;
	sub_821BD3C8(ctx, base);
loc_821E6038:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x821e5f48
	ctx.lr = 0x821E6054;
	sub_821E5F48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e6078
	if (cr6.eq) goto loc_821E6078;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e5640
	ctx.lr = 0x821E606C;
	sub_821E5640(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// lwz r31,8(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 8);
loc_821E6078:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821e6084
	if (cr6.eq) goto loc_821E6084;
	// bl 0x821bd520
	ctx.lr = 0x821E6084;
	sub_821BD520(ctx, base);
loc_821E6084:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lbz r10,1852(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1852);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e60a4
	if (cr6.eq) goto loc_821E60A4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,-32664
	ctx.r3.s64 = r11.s64 + -32664;
	// bl 0x821bd618
	ctx.lr = 0x821E60A4;
	sub_821BD618(ctx, base);
loc_821E60A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821E60B0"))) PPC_WEAK_FUNC(sub_821E60B0);
PPC_FUNC_IMPL(__imp__sub_821E60B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stw r3,-23572(r11)
	PPC_STORE_U32(r11.u32 + -23572, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E60BC"))) PPC_WEAK_FUNC(sub_821E60BC);
PPC_FUNC_IMPL(__imp__sub_821E60BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E60C0"))) PPC_WEAK_FUNC(sub_821E60C0);
PPC_FUNC_IMPL(__imp__sub_821E60C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12560(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12560);
	// b 0x821f6238
	sub_821F6238(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E60CC"))) PPC_WEAK_FUNC(sub_821E60CC);
PPC_FUNC_IMPL(__imp__sub_821E60CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E60D0"))) PPC_WEAK_FUNC(sub_821E60D0);
PPC_FUNC_IMPL(__imp__sub_821E60D0) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// addi r4,r10,-31796
	ctx.r4.s64 = ctx.r10.s64 + -31796;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E60FC;
	sub_8215E490(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r9,-31820
	ctx.r4.s64 = ctx.r9.s64 + -31820;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E6110;
	sub_8215E490(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r8,-31844
	ctx.r4.s64 = ctx.r8.s64 + -31844;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E6124;
	sub_8215E490(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r7,-31868
	ctx.r4.s64 = ctx.r7.s64 + -31868;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E6138;
	sub_8215E490(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r6,-31892
	ctx.r4.s64 = ctx.r6.s64 + -31892;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E614C;
	sub_8215E490(ctx, base);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r4,-31916
	ctx.r4.s64 = ctx.r4.s64 + -31916;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E6160;
	sub_8215E490(ctx, base);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r3,-31936
	ctx.r4.s64 = ctx.r3.s64 + -31936;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E6174;
	sub_8215E490(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r11,-31956
	ctx.r4.s64 = r11.s64 + -31956;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E6188;
	sub_8215E490(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,9
	ctx.r5.s64 = 9;
	// addi r4,r10,-31984
	ctx.r4.s64 = ctx.r10.s64 + -31984;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E619C;
	sub_8215E490(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r4,r9,-32004
	ctx.r4.s64 = ctx.r9.s64 + -32004;
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e490
	ctx.lr = 0x821E61B0;
	sub_8215E490(ctx, base);
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

__attribute__((alias("__imp__sub_821E61C4"))) PPC_WEAK_FUNC(sub_821E61C4);
PPC_FUNC_IMPL(__imp__sub_821E61C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E61C8"))) PPC_WEAK_FUNC(sub_821E61C8);
PPC_FUNC_IMPL(__imp__sub_821E61C8) {
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x821E61D0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r10,-12500(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -12500);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e6348
	if (cr6.eq) goto loc_821E6348;
	// lis r28,-32130
	r28.s64 = -2105671680;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f8,-23528(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + -23528);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// fcmpu cr6,f8,f7
	cr6.compare(ctx.f8.f64, ctx.f7.f64);
	// ble cr6,0x821e6348
	if (!cr6.gt) goto loc_821E6348;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f11,24(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,40(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,-12352
	r31.s64 = r11.s64 + -12352;
	// lfs f6,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,36(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 36);
	ctx.f5.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f4,16(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f3,32(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f3.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r29,r11,29952
	r29.s64 = r11.s64 + 29952;
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f2,f11,f13
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f1,f10,f12
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// lfs f12,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f6,f12,f2
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f12.f64 + ctx.f2.f64));
	// fmadds f11,f5,f11,f1
	ctx.f11.f64 = double(float(ctx.f5.f64 * ctx.f11.f64 + ctx.f1.f64));
	// fmadds f10,f4,f10,f12
	ctx.f10.f64 = double(float(ctx.f4.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f9,f3,f9,f11
	ctx.f9.f64 = double(float(ctx.f3.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fsubs f6,f0,f10
	ctx.f6.f64 = double(float(f0.f64 - ctx.f10.f64));
	// fsubs f5,f0,f9
	ctx.f5.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fmuls f4,f6,f13
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fmuls f3,f5,f13
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fsubs f2,f4,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 - ctx.f3.f64));
	// fsel f1,f2,f4,f3
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f4.f64 : ctx.f3.f64;
	// fmuls f13,f1,f8
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f8.f64));
	// fcmpu cr6,f13,f7
	cr6.compare(ctx.f13.f64, ctx.f7.f64);
	// ble cr6,0x821e629c
	if (!cr6.gt) goto loc_821E629C;
	// lfs f12,92(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f13.f64));
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f0,f12,f13,f0
	f0.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
loc_821E629C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1f40
	ctx.lr = 0x821E62B0;
	sub_821D1F40(ctx, base);
	// lfs f0,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f11,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f9,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f7.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,-23528(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -23528);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f12,12(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f2,92(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 92);
	ctx.f2.f64 = double(temp.f32);
	// li r6,32
	ctx.r6.s64 = 32;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r30,48
	ctx.r4.s64 = r30.s64 + 48;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// stvx128 v62,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	f0.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// lfs f0,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	f0.f64 = double(temp.f32);
	// fsubs f6,f0,f7
	ctx.f6.f64 = double(float(f0.f64 - ctx.f7.f64));
	// lfs f0,-23524(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -23524);
	f0.f64 = double(temp.f32);
	// fdivs f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f0,f3
	f0.f64 = double(float(sqrt(ctx.f3.f64)));
	// fmuls f0,f0,f12
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
	// stfs f0,-12496(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + -12496, temp.u32);
	// bl 0x821ce7a0
	ctx.lr = 0x821E6340;
	sub_821CE7A0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
loc_821E6348:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f13,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,56(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r9,r11,-12352
	ctx.r9.s64 = r11.s64 + -12352;
	// lfs f11,48(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,16
	ctx.r5.s64 = 16;
	// lfs f0,52(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	f0.f64 = double(temp.f32);
	// li r4,32
	ctx.r4.s64 = 32;
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	f0.f64 = double(temp.f32);
	// fsubs f9,f0,f12
	ctx.f9.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lfs f0,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	f0.f64 = double(temp.f32);
	// fsubs f8,f0,f11
	ctx.f8.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f0,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	f0.f64 = double(temp.f32);
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// li r10,48
	ctx.r10.s64 = 48;
	// fmuls f7,f10,f10
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f6,f9,f9,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fmadds f5,f8,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fsqrts f4,f5
	ctx.f4.f64 = double(float(sqrt(ctx.f5.f64)));
	// fmuls f0,f4,f0
	f0.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f0,-12496(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + -12496, temp.u32);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r30,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r30,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821E63DC"))) PPC_WEAK_FUNC(sub_821E63DC);
PPC_FUNC_IMPL(__imp__sub_821E63DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E63E0"))) PPC_WEAK_FUNC(sub_821E63E0);
PPC_FUNC_IMPL(__imp__sub_821E63E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// b 0x821eebd0
	sub_821EEBD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E63EC"))) PPC_WEAK_FUNC(sub_821E63EC);
PPC_FUNC_IMPL(__imp__sub_821E63EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E63F0"))) PPC_WEAK_FUNC(sub_821E63F0);
PPC_FUNC_IMPL(__imp__sub_821E63F0) {
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
	ctx.lr = 0x821E63F8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e6548
	if (cr6.eq) goto loc_821E6548;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-12460(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12460);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e64a8
	if (cr6.eq) goto loc_821E64A8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r9,-12456(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -12456);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821e64a8
	if (!cr6.eq) goto loc_821E64A8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,580(r31)
	PPC_STORE_U8(r31.u32 + 580, r11.u8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r11,-12252
	r30.s64 = r11.s64 + -12252;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r11,1740(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// bne cr6,0x821e6568
	if (!cr6.eq) goto loc_821E6568;
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// rlwinm r11,r11,0,22,22
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821e650c
	if (!cr6.eq) goto loc_821E650C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e6524
	if (!cr6.eq) goto loc_821E6524;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x821ed368
	ctx.lr = 0x821E64A4;
	sub_821ED368(ctx, base);
	// b 0x821e6520
	goto loc_821E6520;
loc_821E64A8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r30,r10,-12252
	r30.s64 = ctx.r10.s64 + -12252;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// li r11,1
	r11.s64 = 1;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// stb r11,580(r31)
	PPC_STORE_U8(r31.u32 + 580, r11.u8);
	// lwz r11,1740(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r11,r11,0,22,22
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// bne cr6,0x821e650c
	if (!cr6.eq) goto loc_821E650C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e6524
	if (!cr6.eq) goto loc_821E6524;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x821ed368
	ctx.lr = 0x821E6508;
	sub_821ED368(ctx, base);
	// b 0x821e6520
	goto loc_821E6520;
loc_821E650C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e6524
	if (cr6.eq) goto loc_821E6524;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x821ec468
	ctx.lr = 0x821E6520;
	sub_821EC468(ctx, base);
loc_821E6520:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_821E6524:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r10,-12564(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12564);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,1748(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1748, temp.u32);
	// stfs f0,1752(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1752, temp.u32);
	// stfs f0,1024(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 1024, temp.u32);
	// b 0x821e6580
	goto loc_821E6580;
loc_821E6548:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r30,r10,-12252
	r30.s64 = ctx.r10.s64 + -12252;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// li r11,0
	r11.s64 = 0;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// stb r11,580(r31)
	PPC_STORE_U8(r31.u32 + 580, r11.u8);
	// lwz r11,1740(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
loc_821E6568:
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e6580
	if (cr6.eq) goto loc_821E6580;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x821ec468
	ctx.lr = 0x821E6580;
	sub_821EC468(ctx, base);
loc_821E6580:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a30
	ctx.lr = 0x821E6588;
	sub_82144A30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// beq cr6,0x821e65c0
	if (cr6.eq) goto loc_821E65C0;
	// addi r5,r11,-12452
	ctx.r5.s64 = r11.s64 + -12452;
	// lwz r11,-12452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e65d4
	if (!cr6.eq) goto loc_821E65D4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r11,-31772
	ctx.r4.s64 = r11.s64 + -31772;
	// bl 0x821ee720
	ctx.lr = 0x821E65BC;
	sub_821EE720(ctx, base);
	// b 0x821e65d4
	goto loc_821E65D4;
loc_821E65C0:
	// lwz r3,-12452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12452);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e65d4
	if (cr6.eq) goto loc_821E65D4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x821E65D4;
	sub_821EC060(ctx, base);
loc_821E65D4:
	// bl 0x822c55b0
	ctx.lr = 0x821E65D8;
	sub_822C55B0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r29,r11,-12352
	r29.s64 = r11.s64 + -12352;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821449e8
	ctx.lr = 0x821E65F4;
	sub_821449E8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821449f0
	ctx.lr = 0x821E6608;
	sub_821449F0(ctx, base);
	// bl 0x822c6480
	ctx.lr = 0x821E660C;
	sub_822C6480(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r29,r10,29952
	r29.s64 = ctx.r10.s64 + 29952;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lfs f13,-12492(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12492);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 96);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f12,11364(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11364);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,-12492(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -12492, temp.u32);
	// lwz r3,-12572(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12572);
	// fmuls f0,f0,f12
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r4,-12488(r28)
	PPC_STORE_U32(r28.u32 + -12488, ctx.r4.u32);
	// bl 0x82161120
	ctx.lr = 0x821E6654;
	sub_82161120(ctx, base);
	// lwz r4,-12488(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -12488);
	// lwz r3,-12572(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12572);
	// bl 0x82161210
	ctx.lr = 0x821E6660;
	sub_82161210(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r3,-12548(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12548);
	// bl 0x821f5570
	ctx.lr = 0x821E666C;
	sub_821F5570(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,-12544(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12544);
	// bl 0x821f5570
	ctx.lr = 0x821E6678;
	sub_821F5570(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lwz r3,-12540(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -12540);
	// bl 0x821f5570
	ctx.lr = 0x821E6684;
	sub_821F5570(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r3,-12536(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -12536);
	// bl 0x821f5570
	ctx.lr = 0x821E6690;
	sub_821F5570(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lwz r3,-12532(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -12532);
	// bl 0x821f5570
	ctx.lr = 0x821E669C;
	sub_821F5570(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,-12488(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -12488);
	// bl 0x821449f8
	ctx.lr = 0x821E66A8;
	sub_821449F8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12560(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12560);
	// bl 0x821f5dd8
	ctx.lr = 0x821E66B4;
	sub_821F5DD8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12552(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12552);
	// bl 0x821f5620
	ctx.lr = 0x821E66C0;
	sub_821F5620(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lfs f1,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,-12216(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12216);
	// bl 0x821ef548
	ctx.lr = 0x821E66D0;
	sub_821EF548(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821ee4d8
	ctx.lr = 0x821E66D8;
	sub_821EE4D8(ctx, base);
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// lwz r3,-32456(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32456);
	// bl 0x82547140
	ctx.lr = 0x821E66E4;
	sub_82547140(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a18
	ctx.lr = 0x821E66EC;
	sub_82144A18(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r11,-12480(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12480);
	// stw r3,-12480(r7)
	PPC_STORE_U32(ctx.r7.u32 + -12480, ctx.r3.u32);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// stw r11,-12484(r6)
	PPC_STORE_U32(ctx.r6.u32 + -12484, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821E6710"))) PPC_WEAK_FUNC(sub_821E6710);
PPC_FUNC_IMPL(__imp__sub_821E6710) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,-12488(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -12488);
	// lwz r3,-12572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12572);
	// bl 0x82161120
	ctx.lr = 0x821E6738;
	sub_82161120(ctx, base);
	// lwz r4,-12488(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -12488);
	// lwz r3,-12572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12572);
	// bl 0x82161210
	ctx.lr = 0x821E6744;
	sub_82161210(ctx, base);
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

__attribute__((alias("__imp__sub_821E675C"))) PPC_WEAK_FUNC(sub_821E675C);
PPC_FUNC_IMPL(__imp__sub_821E675C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E6760"))) PPC_WEAK_FUNC(sub_821E6760);
PPC_FUNC_IMPL(__imp__sub_821E6760) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-32456(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -32456);
	// bl 0x825471b8
	ctx.lr = 0x821E677C;
	sub_825471B8(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r31,r10,19856
	r31.s64 = ctx.r10.s64 + 19856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214a368
	ctx.lr = 0x821E678C;
	sub_8214A368(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a18
	ctx.lr = 0x821E6794;
	sub_82144A18(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-12556(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12556);
	// bl 0x821f6490
	ctx.lr = 0x821E67A4;
	sub_821F6490(ctx, base);
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

__attribute__((alias("__imp__sub_821E67B8"))) PPC_WEAK_FUNC(sub_821E67B8);
PPC_FUNC_IMPL(__imp__sub_821E67B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-12499(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -12499);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821e67f0
	if (!cr6.eq) goto loc_821E67F0;
	// lis r11,-32123
	r11.s64 = -2105212928;
	// lwz r11,24076(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24076);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e67e4
	if (cr6.eq) goto loc_821E67E4;
	// lbz r11,568(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 568);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e67f0
	if (!cr6.eq) goto loc_821E67F0;
loc_821E67E4:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_821E67F0:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E67FC"))) PPC_WEAK_FUNC(sub_821E67FC);
PPC_FUNC_IMPL(__imp__sub_821E67FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E6800"))) PPC_WEAK_FUNC(sub_821E6800);
PPC_FUNC_IMPL(__imp__sub_821E6800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-12568(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12568);
	// b 0x821f65f8
	sub_821F65F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E6810"))) PPC_WEAK_FUNC(sub_821E6810);
PPC_FUNC_IMPL(__imp__sub_821E6810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-12568(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12568);
	// b 0x821f66a8
	sub_821F66A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E6824"))) PPC_WEAK_FUNC(sub_821E6824);
PPC_FUNC_IMPL(__imp__sub_821E6824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E6828"))) PPC_WEAK_FUNC(sub_821E6828);
PPC_FUNC_IMPL(__imp__sub_821E6828) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// beq cr6,0x821e689c
	if (cr6.eq) goto loc_821E689C;
	// addi r5,r11,-12448
	ctx.r5.s64 = r11.s64 + -12448;
	// lwz r11,-12448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12448);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e6888
	if (!cr6.eq) goto loc_821E6888;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e686c
	if (cr6.eq) goto loc_821E686C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-31720
	ctx.r4.s64 = r11.s64 + -31720;
	// b 0x821e6874
	goto loc_821E6874;
loc_821E686C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-31744
	ctx.r4.s64 = r11.s64 + -31744;
loc_821E6874:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee720
	ctx.lr = 0x821E6888;
	sub_821EE720(ctx, base);
loc_821E6888:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x821E6894;
	sub_821F15C8(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// b 0x821e68b4
	goto loc_821E68B4;
loc_821E689C:
	// lwz r3,-12448(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12448);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e68bc
	if (cr6.eq) goto loc_821E68BC;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x821E68B0;
	sub_821EC060(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_821E68B4:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stb r11,-12456(r10)
	PPC_STORE_U8(ctx.r10.u32 + -12456, r11.u8);
loc_821E68BC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E68CC"))) PPC_WEAK_FUNC(sub_821E68CC);
PPC_FUNC_IMPL(__imp__sub_821E68CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E68D0"))) PPC_WEAK_FUNC(sub_821E68D0);
PPC_FUNC_IMPL(__imp__sub_821E68D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,15,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10000;
	// beq cr6,0x821e6948
	if (cr6.eq) goto loc_821E6948;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821e6928
	if (!cr6.eq) goto loc_821E6928;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// addi r8,r10,0
	ctx.r8.s64 = ctx.r10.s64 + 0;
	// addi r7,r7,0
	ctx.r7.s64 = ctx.r7.s64 + 0;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x821ed368
	ctx.lr = 0x821E6928;
	sub_821ED368(ctx, base);
loc_821E6928:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821E6948:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e695c
	if (cr6.eq) goto loc_821E695C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x821ec468
	ctx.lr = 0x821E695C;
	sub_821EC468(ctx, base);
loc_821E695C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// rlwinm r11,r11,0,31,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E697C"))) PPC_WEAK_FUNC(sub_821E697C);
PPC_FUNC_IMPL(__imp__sub_821E697C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E6980"))) PPC_WEAK_FUNC(sub_821E6980);
PPC_FUNC_IMPL(__imp__sub_821E6980) {
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
	ctx.lr = 0x821E6988;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r11,-12592
	r30.s64 = r11.s64 + -12592;
	// mr r31,r30
	r31.u64 = r30.u64;
	// subf r29,r30,r3
	r29.s64 = ctx.r3.s64 - r30.s64;
loc_821E699C:
	// lfsx f1,r29,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + r31.u32);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82547cb0
	ctx.lr = 0x821E69A8;
	sub_82547CB0(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r30,20
	r11.s64 = r30.s64 + 20;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x821e699c
	if (cr6.lt) goto loc_821E699C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E69C0"))) PPC_WEAK_FUNC(sub_821E69C0);
PPC_FUNC_IMPL(__imp__sub_821E69C0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-12497(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -12497);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e6a14
	if (cr6.eq) goto loc_821E6A14;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// stb r9,-12498(r10)
	PPC_STORE_U8(ctx.r10.u32 + -12498, ctx.r9.u8);
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// beq cr6,0x821e6a20
	if (cr6.eq) goto loc_821E6A20;
	// bl 0x821eeb48
	ctx.lr = 0x821E6A00;
	sub_821EEB48(ctx, base);
	// bl 0x821e6710
	ctx.lr = 0x821E6A04;
	sub_821E6710(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821E6A14:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,-12498(r11)
	PPC_STORE_U8(r11.u32 + -12498, ctx.r10.u8);
loc_821E6A20:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E6A30"))) PPC_WEAK_FUNC(sub_821E6A30);
PPC_FUNC_IMPL(__imp__sub_821E6A30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32226
	r11.s64 = -2111963136;
	// addi r10,r11,26464
	ctx.r10.s64 = r11.s64 + 26464;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r9,r10,19856
	ctx.r9.s64 = ctx.r10.s64 + 19856;
	// bne cr6,0x821e6a58
	if (!cr6.eq) goto loc_821E6A58;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// addi r11,r11,0
	r11.s64 = r11.s64 + 0;
	// stw r11,6464(r9)
	PPC_STORE_U32(ctx.r9.u32 + 6464, r11.u32);
	// blr 
	return;
loc_821E6A58:
	// lis r11,-32226
	r11.s64 = -2111963136;
	// addi r11,r11,26464
	r11.s64 = r11.s64 + 26464;
	// stw r11,6464(r9)
	PPC_STORE_U32(ctx.r9.u32 + 6464, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E6A68"))) PPC_WEAK_FUNC(sub_821E6A68);
PPC_FUNC_IMPL(__imp__sub_821E6A68) {
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
	ctx.lr = 0x821E6A70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lbz r11,-12497(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + -12497);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e6d18
	if (cr6.eq) goto loc_821E6D18;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r28,r11,19856
	r28.s64 = r11.s64 + 19856;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r11,r10,0
	r11.s64 = ctx.r10.s64 + 0;
	// lwz r3,-12556(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12556);
	// li r29,0
	r29.s64 = 0;
	// stb r8,-12497(r9)
	PPC_STORE_U8(ctx.r9.u32 + -12497, ctx.r8.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,6464(r28)
	PPC_STORE_U32(r28.u32 + 6464, r11.u32);
	// beq cr6,0x821e6ad0
	if (cr6.eq) goto loc_821E6AD0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E6AC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12556(r31)
	PPC_STORE_U32(r31.u32 + -12556, r11.u32);
loc_821E6AD0:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-12560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12560);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e6afc
	if (cr6.eq) goto loc_821E6AFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E6AF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12560(r31)
	PPC_STORE_U32(r31.u32 + -12560, r11.u32);
loc_821E6AFC:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-12564(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12564);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e6b28
	if (cr6.eq) goto loc_821E6B28;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E6B20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12564(r31)
	PPC_STORE_U32(r31.u32 + -12564, r11.u32);
loc_821E6B28:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-12568(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12568);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e6b54
	if (cr6.eq) goto loc_821E6B54;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E6B4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12568(r31)
	PPC_STORE_U32(r31.u32 + -12568, r11.u32);
loc_821E6B54:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-12592
	ctx.r10.s64 = r11.s64 + -12592;
	// stw r29,-12592(r11)
	PPC_STORE_U32(r11.u32 + -12592, r29.u32);
	// stw r29,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r29.u32);
	// stw r29,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r29.u32);
	// stw r29,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r29.u32);
	// stw r29,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r29.u32);
	// bl 0x821ec418
	ctx.lr = 0x821E6B74;
	sub_821EC418(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-12216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12216);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e6b98
	if (cr6.eq) goto loc_821E6B98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E6B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821E6B98:
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12216(r31)
	PPC_STORE_U32(r31.u32 + -12216, r11.u32);
	// bl 0x82547a28
	ctx.lr = 0x821E6BA4;
	sub_82547A28(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,-12532(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -12532);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821e6bcc
	if (cr6.eq) goto loc_821E6BCC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268bf78
	ctx.lr = 0x821E6BBC;
	sub_8268BF78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821E6BC4;
	sub_82130588(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12532(r30)
	PPC_STORE_U32(r30.u32 + -12532, r11.u32);
loc_821E6BCC:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,-12536(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -12536);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821e6bf4
	if (cr6.eq) goto loc_821E6BF4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268bf78
	ctx.lr = 0x821E6BE4;
	sub_8268BF78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821E6BEC;
	sub_82130588(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12536(r30)
	PPC_STORE_U32(r30.u32 + -12536, r11.u32);
loc_821E6BF4:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,-12540(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -12540);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821e6c1c
	if (cr6.eq) goto loc_821E6C1C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268bf78
	ctx.lr = 0x821E6C0C;
	sub_8268BF78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821E6C14;
	sub_82130588(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12540(r30)
	PPC_STORE_U32(r30.u32 + -12540, r11.u32);
loc_821E6C1C:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,-12544(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -12544);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821e6c44
	if (cr6.eq) goto loc_821E6C44;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268bf78
	ctx.lr = 0x821E6C34;
	sub_8268BF78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821E6C3C;
	sub_82130588(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12544(r30)
	PPC_STORE_U32(r30.u32 + -12544, r11.u32);
loc_821E6C44:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,-12548(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -12548);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821e6c6c
	if (cr6.eq) goto loc_821E6C6C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268bf78
	ctx.lr = 0x821E6C5C;
	sub_8268BF78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821E6C64;
	sub_82130588(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12548(r30)
	PPC_STORE_U32(r30.u32 + -12548, r11.u32);
loc_821E6C6C:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,-12552(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -12552);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821e6c94
	if (cr6.eq) goto loc_821E6C94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f5a08
	ctx.lr = 0x821E6C84;
	sub_821F5A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821E6C8C;
	sub_82130588(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12552(r30)
	PPC_STORE_U32(r30.u32 + -12552, r11.u32);
loc_821E6C94:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r11,-12476(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12476, r11.u32);
	// bl 0x82144a90
	ctx.lr = 0x821E6CA8;
	sub_82144A90(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,-12572(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -12572);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821e6cd0
	if (cr6.eq) goto loc_821E6CD0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82160538
	ctx.lr = 0x821E6CC0;
	sub_82160538(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821E6CC8;
	sub_82130588(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12572(r30)
	PPC_STORE_U32(r30.u32 + -12572, r11.u32);
loc_821E6CD0:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-12464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12464);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e6cfc
	if (cr6.eq) goto loc_821E6CFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E6CF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12464(r31)
	PPC_STORE_U32(r31.u32 + -12464, r11.u32);
loc_821E6CFC:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-12468(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12468);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e6d18
	if (cr6.eq) goto loc_821E6D18;
	// bl 0x821bc120
	ctx.lr = 0x821E6D10;
	sub_821BC120(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-12468(r31)
	PPC_STORE_U32(r31.u32 + -12468, r11.u32);
loc_821E6D18:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821E6D20"))) PPC_WEAK_FUNC(sub_821E6D20);
PPC_FUNC_IMPL(__imp__sub_821E6D20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x821E6D28;
	// stfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f29.u64);
	// stfd f30,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f30.u64);
	// stfd f31,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r23,r11,-12444
	r23.s64 = r11.s64 + -12444;
	// li r22,0
	r22.s64 = 0;
	// mr r24,r22
	r24.u64 = r22.u64;
	// lfs f31,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
	// lwz r11,36(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e7198
	if (cr6.eq) goto loc_821E7198;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r26,r23
	r26.u64 = r23.u64;
	// lfs f29,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lfs f30,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
loc_821E6D70:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r11,r22
	r11.u64 = r22.u64;
	// lwz r25,10(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10);
	// lbz r9,14(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 14);
	// mr r28,r25
	r28.u64 = r25.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e7170
	if (cr6.eq) goto loc_821E7170;
loc_821E6D8C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821e7170
	if (cr6.eq) goto loc_821E7170;
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// rlwinm r11,r11,3,21,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x7F8;
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,15(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 15);
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bgt cr6,0x821e7154
	if (cr6.gt) goto loc_821E7154;
	// lis r12,-32226
	r12.s64 = -2111963136;
	// addi r12,r12,28108
	r12.s64 = r12.s64 + 28108;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_821E6DDC;
	case 1:
		goto loc_821E6E78;
	case 2:
		goto loc_821E6F60;
	case 3:
		goto loc_821E7054;
	default:
		__builtin_unreachable();
	}
	// lwz r16,28124(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 28124);
	// lwz r16,28280(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 28280);
	// lwz r16,28512(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 28512);
	// lwz r16,28756(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 28756);
loc_821E6DDC:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E6DF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,10(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stb r7,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r7.u8);
	// lbz r6,11(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 11);
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// lhz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// extsh r11,r5
	r11.s64 = ctx.r5.s16;
	// std r11,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, r11.u64);
	// lfd f0,136(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,0(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lhz r10,14(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// std r8,216(r1)
	PPC_STORE_U64(ctx.r1.u32 + 216, ctx.r8.u64);
	// lfd f11,216(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 216);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64));
	// stfs f8,4(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r7,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r7.u32);
	// lfs f7,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,8(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lhz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// std r4,208(r1)
	PPC_STORE_U64(ctx.r1.u32 + 208, ctx.r4.u64);
	// lfd f6,208(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 208);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64));
	// stfs f3,12(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// b 0x821e7154
	goto loc_821E7154;
loc_821E6E78:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E6E90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r11,10(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821e6eb4
	if (cr6.eq) goto loc_821E6EB4;
	// stfs f30,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stb r22,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r22.u8);
	// stfs f30,4(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f29,8(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// b 0x821e7154
	goto loc_821E7154;
loc_821E6EB4:
	// rlwinm r11,r11,31,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// stb r11,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r11.u8);
	// lhz r10,11(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 11);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// std r8,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r8.u64);
	// lfd f0,160(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lhz r7,13(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 13);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// std r5,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r5.u64);
	// lfd f10,192(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 192);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f7,4(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lwz r4,15(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 15);
	// stw r4,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// lfs f6,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,8(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lwz r11,19(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 19);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// lfs f5,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,12(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lwz r10,23(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 23);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lfs f4,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,16(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lwz r9,27(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 27);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// lfs f3,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,20(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lwz r8,31(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 31);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lfs f2,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,24(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lwz r7,35(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 35);
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// lfs f1,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,28(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// b 0x821e7154
	goto loc_821E7154;
loc_821E6F60:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E6F78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,10(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stb r7,17(r30)
	PPC_STORE_U8(r30.u32 + 17, ctx.r7.u8);
	// lhz r6,11(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 11);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// std r4,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r4.u64);
	// lfd f0,176(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stfs f11,0(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lhz r3,13(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 13);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// std r10,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r10.u64);
	// lfd f10,144(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f7,4(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// lwz r9,15(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 15);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// lfs f6,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,8(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// lbz r8,10(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// rlwinm r7,r8,31,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x1;
	// stb r7,16(r30)
	PPC_STORE_U8(r30.u32 + 16, ctx.r7.u8);
	// lwz r6,23(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 23);
	// lwz r29,27(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 27);
	// lwz r5,19(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 19);
	// cmplw cr6,r5,r6
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, xer);
	// bne cr6,0x821e7004
	if (!cr6.eq) goto loc_821E7004;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x821e704c
	if (!cr6.eq) goto loc_821E704C;
	// b 0x821e7014
	goto loc_821E7014;
loc_821E7004:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821e7014
	if (cr6.eq) goto loc_821E7014;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x821E7014;
	sub_82130588(ctx, base);
loc_821E7014:
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x821E701C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7030
	if (cr6.eq) goto loc_821E7030;
	// bl 0x82163ee8
	ctx.lr = 0x821E7028;
	sub_82163EE8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x821e7034
	goto loc_821E7034;
loc_821E7030:
	// mr r29,r22
	r29.u64 = r22.u64;
loc_821E7034:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,19(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 19);
	// bl 0x82164840
	ctx.lr = 0x821E7040;
	sub_82164840(ctx, base);
	// lwz r11,19(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 19);
	// stw r29,27(r31)
	PPC_STORE_U32(r31.u32 + 27, r29.u32);
	// stw r11,23(r31)
	PPC_STORE_U32(r31.u32 + 23, r11.u32);
loc_821E704C:
	// stw r29,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r29.u32);
	// b 0x821e7154
	goto loc_821E7154;
loc_821E7054:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E706C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,10(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stb r7,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, ctx.r7.u8);
	// lhz r6,11(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 11);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// std r4,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r4.u64);
	// lfd f0,152(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stfs f11,28(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lhz r11,13(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 13);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// std r9,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r9.u64);
	// lfd f10,168(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f7,0(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lhz r8,15(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 15);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.r6.u64);
	// lfd f6,184(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 184);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64));
	// stfs f3,4(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lwz r5,17(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 17);
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// lfs f2,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,8(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lwz r4,22(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 22);
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,12(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lwz r11,26(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 26);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lhz r10,30(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// std r8,200(r1)
	PPC_STORE_U64(ctx.r1.u32 + 200, ctx.r8.u64);
	// lfd f13,200(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 200);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64));
	// stfs f10,20(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lhz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f31
	ctx.f6.f64 = double(float(ctx.f7.f64 * f31.f64));
	// stfs f6,24(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lbz r4,21(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 21);
	// clrlwi r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	// stb r11,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r11.u8);
loc_821E7154:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r9,r27,1
	ctx.r9.s64 = r27.s64 + 1;
	// lwz r28,8(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// lbz r8,14(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 14);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x821e6d8c
	if (cr6.lt) goto loc_821E6D8C;
loc_821E7170:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E7184;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 36);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmplw cr6,r24,r11
	cr6.compare<uint32_t>(r24.u32, r11.u32, xer);
	// blt cr6,0x821e6d70
	if (cr6.lt) goto loc_821E6D70;
loc_821E7198:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// lwz r11,-12524(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e7264
	if (cr6.eq) goto loc_821E7264;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// mr r30,r11
	r30.u64 = r11.u64;
	// bl 0x8214d0c0
	ctx.lr = 0x821E71C0;
	sub_8214D0C0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E71D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lbz r8,10(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stb r7,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r7.u8);
	// lhz r6,12(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lhz r11,20(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 20);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f7,12(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lbz r8,11(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 11);
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// lhz r7,14(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 14);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,4(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821E7264;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821E7264:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12520(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12520);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e7328
	if (cr6.eq) goto loc_821E7328;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// mr r30,r11
	r30.u64 = r11.u64;
	// bl 0x8214d0c0
	ctx.lr = 0x821E7284;
	sub_8214D0C0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E7298;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lbz r8,10(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stb r7,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r7.u8);
	// lhz r6,12(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lhz r11,20(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 20);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f7,12(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lbz r8,11(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 11);
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// lhz r7,14(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 14);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,4(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821E7328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821E7328:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12516(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e73ec
	if (cr6.eq) goto loc_821E73EC;
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r11
	r31.u64 = r11.u64;
	// bl 0x8214d0c0
	ctx.lr = 0x821E7348;
	sub_8214D0C0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E735C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lbz r8,10(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stb r7,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r7.u8);
	// lhz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f7,12(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lbz r8,11(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 11);
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// lhz r7,14(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,4(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821E73EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821E73EC:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821E7400"))) PPC_WEAK_FUNC(sub_821E7400);
PPC_FUNC_IMPL(__imp__sub_821E7400) {
	PPC_FUNC_PROLOGUE();
	// b 0x821e69c0
	sub_821E69C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E7404"))) PPC_WEAK_FUNC(sub_821E7404);
PPC_FUNC_IMPL(__imp__sub_821E7404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E7408"))) PPC_WEAK_FUNC(sub_821E7408);
PPC_FUNC_IMPL(__imp__sub_821E7408) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-12288(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12288);
	// stw r9,236(r11)
	PPC_STORE_U32(r11.u32 + 236, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E7420"))) PPC_WEAK_FUNC(sub_821E7420);
PPC_FUNC_IMPL(__imp__sub_821E7420) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// b 0x821ebcf0
	sub_821EBCF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E7430"))) PPC_WEAK_FUNC(sub_821E7430);
PPC_FUNC_IMPL(__imp__sub_821E7430) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// b 0x821ebc70
	sub_821EBC70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E7440"))) PPC_WEAK_FUNC(sub_821E7440);
PPC_FUNC_IMPL(__imp__sub_821E7440) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r3,r4,24
	ctx.r3.u64 = ctx.r4.u32 & 0xFF;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// b 0x821e6828
	sub_821E6828(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E7470"))) PPC_WEAK_FUNC(sub_821E7470);
PPC_FUNC_IMPL(__imp__sub_821E7470) {
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
	// b 0x821e68d0
	sub_821E68D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E748C"))) PPC_WEAK_FUNC(sub_821E748C);
PPC_FUNC_IMPL(__imp__sub_821E748C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E7490"))) PPC_WEAK_FUNC(sub_821E7490);
PPC_FUNC_IMPL(__imp__sub_821E7490) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// rlwinm r9,r10,0,14,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000;
	// beq cr6,0x821e74f0
	if (cr6.eq) goto loc_821E74F0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// addi r8,r10,0
	ctx.r8.s64 = ctx.r10.s64 + 0;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r7,r7,0
	ctx.r7.s64 = ctx.r7.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,17
	ctx.r4.s64 = 17;
	// b 0x821ed368
	sub_821ED368(ctx, base);
	return;
loc_821E74F0:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,17
	ctx.r4.s64 = 17;
	// b 0x821ec468
	sub_821EC468(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E7504"))) PPC_WEAK_FUNC(sub_821E7504);
PPC_FUNC_IMPL(__imp__sub_821E7504) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E7508"))) PPC_WEAK_FUNC(sub_821E7508);
PPC_FUNC_IMPL(__imp__sub_821E7508) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// rlwinm r9,r10,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// beq cr6,0x821e7568
	if (cr6.eq) goto loc_821E7568;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// addi r8,r10,0
	ctx.r8.s64 = ctx.r10.s64 + 0;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r7,r7,0
	ctx.r7.s64 = ctx.r7.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,12
	ctx.r4.s64 = 12;
	// b 0x821ed368
	sub_821ED368(ctx, base);
	return;
loc_821E7568:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,12
	ctx.r4.s64 = 12;
	// b 0x821ec468
	sub_821EC468(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E757C"))) PPC_WEAK_FUNC(sub_821E757C);
PPC_FUNC_IMPL(__imp__sub_821E757C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E7580"))) PPC_WEAK_FUNC(sub_821E7580);
PPC_FUNC_IMPL(__imp__sub_821E7580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,-12492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12492);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E7594"))) PPC_WEAK_FUNC(sub_821E7594);
PPC_FUNC_IMPL(__imp__sub_821E7594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E7598"))) PPC_WEAK_FUNC(sub_821E7598);
PPC_FUNC_IMPL(__imp__sub_821E7598) {
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
	ctx.lr = 0x821E75A0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-31424
	ctx.r3.s64 = r11.s64 + -31424;
	// bl 0x82130000
	ctx.lr = 0x821E75B0;
	sub_82130000(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r25,r11,-12408
	r25.s64 = r11.s64 + -12408;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r25,-36
	ctx.r3.s64 = r25.s64 + -36;
	// bl 0x8244d150
	ctx.lr = 0x821E75C8;
	sub_8244D150(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r21,0
	r21.s64 = 0;
	// li r23,0
	r23.s64 = 0;
	// addi r22,r11,-23564
	r22.s64 = r11.s64 + -23564;
	// addi r24,r10,-31504
	r24.s64 = ctx.r10.s64 + -31504;
	// addi r20,r9,-31568
	r20.s64 = ctx.r9.s64 + -31568;
	// addi r19,r8,-31624
	r19.s64 = ctx.r8.s64 + -31624;
	// addi r30,r7,19856
	r30.s64 = ctx.r7.s64 + 19856;
loc_821E75F8:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r3,r30,172
	ctx.r3.s64 = r30.s64 + 172;
	// bl 0x8214d0c0
	ctx.lr = 0x821E7604;
	sub_8214D0C0(ctx, base);
	// addi r29,r22,48
	r29.s64 = r22.s64 + 48;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r23,r29
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + r29.u32);
	// bl 0x82144a20
	ctx.lr = 0x821E7618;
	sub_82144A20(ctx, base);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r10,r25,-36
	ctx.r10.s64 = r25.s64 + -36;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r3.u32);
	// bne cr6,0x821e7640
	if (!cr6.eq) goto loc_821E7640;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwzx r4,r23,r22
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + r22.u32);
	// bl 0x82130000
	ctx.lr = 0x821E763C;
	sub_82130000(ctx, base);
	// b 0x821e7704
	goto loc_821E7704;
loc_821E7640:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821e7658
	if (!cr6.eq) goto loc_821E7658;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwzx r4,r23,r29
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + r29.u32);
	// bl 0x82130000
	ctx.lr = 0x821E7654;
	sub_82130000(ctx, base);
	// b 0x821e7704
	goto loc_821E7704;
loc_821E7658:
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r25,-36
	r29.s64 = r25.s64 + -36;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r11.u32);
	// li r11,0
	r11.s64 = 0;
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// stw r31,10(r10)
	PPC_STORE_U32(ctx.r10.u32 + 10, r31.u32);
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// lbz r9,14(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 14);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e7704
	if (cr6.eq) goto loc_821E7704;
loc_821E7684:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821e7704
	if (cr6.eq) goto loc_821E7704;
	// clrlwi r26,r11,24
	r26.u64 = r11.u32 & 0xFF;
	// rlwinm r11,r11,3,21,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x7F8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r27,r26,r11
	r27.u64 = r26.u64 + r11.u64;
	// add r11,r27,r10
	r11.u64 = r27.u64 + ctx.r10.u64;
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x82144a28
	ctx.lr = 0x821E76A8;
	sub_82144A28(ctx, base);
	// lwzx r11,r28,r29
	r11.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// addi r3,r30,308
	ctx.r3.s64 = r30.s64 + 308;
	// add r10,r27,r11
	ctx.r10.u64 = r27.u64 + r11.u64;
	// stw r18,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r18.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,1(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1);
	// bl 0x8214d8f8
	ctx.lr = 0x821E76C8;
	sub_8214D8F8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r30,700
	ctx.r3.s64 = r30.s64 + 700;
	// lwz r4,1(r18)
	ctx.r4.u64 = PPC_LOAD_U32(r18.u32 + 1);
	// bl 0x8214d8f8
	ctx.lr = 0x821E76D8;
	sub_8214D8F8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82130000
	ctx.lr = 0x821E76E8;
	sub_82130000(ctx, base);
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// addi r8,r26,1
	ctx.r8.s64 = r26.s64 + 1;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// lbz r7,14(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 14);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// blt cr6,0x821e7684
	if (cr6.lt) goto loc_821E7684;
loc_821E7704:
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// cmpwi cr6,r23,36
	cr6.compare<int32_t>(r23.s32, 36, xer);
	// blt cr6,0x821e75f8
	if (cr6.lt) goto loc_821E75F8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-31644
	ctx.r4.s64 = r11.s64 + -31644;
	// bl 0x82144a20
	ctx.lr = 0x821E7724;
	sub_82144A20(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,-31664
	ctx.r4.s64 = ctx.r9.s64 + -31664;
	// stw r11,-12524(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12524, r11.u32);
	// bl 0x82144a20
	ctx.lr = 0x821E7740;
	sub_82144A20(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r7,-31684
	ctx.r4.s64 = ctx.r7.s64 + -31684;
	// stw r11,-12520(r8)
	PPC_STORE_U32(ctx.r8.u32 + -12520, r11.u32);
	// bl 0x82144a20
	ctx.lr = 0x821E775C;
	sub_82144A20(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stw r3,-12516(r6)
	PPC_STORE_U32(ctx.r6.u32 + -12516, ctx.r3.u32);
	// bl 0x821e6d20
	ctx.lr = 0x821E7768;
	sub_821E6D20(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_821E7770"))) PPC_WEAK_FUNC(sub_821E7770);
PPC_FUNC_IMPL(__imp__sub_821E7770) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x821E7778;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r11,-12497(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + -12497);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e77b8
	if (cr6.eq) goto loc_821E77B8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-31080
	ctx.r3.s64 = r11.s64 + -31080;
	// bl 0x82130000
	ctx.lr = 0x821E77A4;
	sub_82130000(ctx, base);
loc_821E77A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821E77B8:
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r11,56
	r11.s64 = 56;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r11,r29,r11
	r11.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// stw r11,-23520(r10)
	PPC_STORE_U32(ctx.r10.u32 + -23520, r11.u32);
	// bl 0x821bc0f0
	ctx.lr = 0x821E77D4;
	sub_821BC0F0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,2308
	ctx.r3.s64 = 2308;
	// stw r11,-12468(r31)
	PPC_STORE_U32(r31.u32 + -12468, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x821E77E8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7814
	if (cr6.eq) goto loc_821E7814;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r4,-12468(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -12468);
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x821c2d88
	ctx.lr = 0x821E7804;
	sub_821C2D88(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r11,-12464
	r30.s64 = r11.s64 + -12464;
	// stw r3,-12464(r11)
	PPC_STORE_U32(r11.u32 + -12464, ctx.r3.u32);
	// b 0x821e7824
	goto loc_821E7824;
loc_821E7814:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// addi r30,r10,-12464
	r30.s64 = ctx.r10.s64 + -12464;
	// stw r11,-12464(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12464, r11.u32);
loc_821E7824:
	// li r3,12052
	ctx.r3.s64 = 12052;
	// bl 0x82130528
	ctx.lr = 0x821E782C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7848
	if (cr6.eq) goto loc_821E7848;
	// bl 0x821604b8
	ctx.lr = 0x821E7838;
	sub_821604B8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r28,r11,-12572
	r28.s64 = r11.s64 + -12572;
	// stw r3,-12572(r11)
	PPC_STORE_U32(r11.u32 + -12572, ctx.r3.u32);
	// b 0x821e7858
	goto loc_821E7858;
loc_821E7848:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// addi r28,r10,-12572
	r28.s64 = ctx.r10.s64 + -12572;
	// stw r11,-12572(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12572, r11.u32);
loc_821E7858:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r10,r11,-12384
	ctx.r10.s64 = r11.s64 + -12384;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e7884
	if (!cr6.eq) goto loc_821E7884;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r11,r11,-31100
	r11.s64 = r11.s64 + -31100;
	// addi r31,r10,-31124
	r31.s64 = ctx.r10.s64 + -31124;
	// b 0x821e7894
	goto loc_821E7894;
loc_821E7884:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r11,r11,-31160
	r11.s64 = r11.s64 + -31160;
	// addi r31,r10,-31196
	r31.s64 = ctx.r10.s64 + -31196;
loc_821E7894:
	// stw r11,-12472(r9)
	PPC_STORE_U32(ctx.r9.u32 + -12472, r11.u32);
	// li r11,32
	r11.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E78B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,22
	ctx.r7.s64 = 22;
	// bl 0x82144eb0
	ctx.lr = 0x821E78D0;
	sub_82144EB0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821e77a4
	if (cr6.eq) goto loc_821E77A4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r11,7216
	ctx.r8.s64 = r11.s64 + 7216;
	// lwz r11,228(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 228);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,228(r8)
	PPC_STORE_U32(ctx.r8.u32 + 228, ctx.r10.u32);
	// stw r11,-22968(r9)
	PPC_STORE_U32(ctx.r9.u32 + -22968, r11.u32);
	// bl 0x821e60d0
	ctx.lr = 0x821E78FC;
	sub_821E60D0(ctx, base);
	// bl 0x825475f8
	ctx.lr = 0x821E7900;
	sub_825475F8(ctx, base);
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82130528
	ctx.lr = 0x821E7908;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7918
	if (cr6.eq) goto loc_821E7918;
	// bl 0x821f4c00
	ctx.lr = 0x821E7914;
	sub_821F4C00(ctx, base);
	// b 0x821e791c
	goto loc_821E791C;
loc_821E7918:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E791C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-12548
	r11.s64 = r11.s64 + -12548;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-31212
	ctx.r4.s64 = r11.s64 + -31212;
	// bl 0x821f4d08
	ctx.lr = 0x821E7934;
	sub_821F4D08(ctx, base);
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82130528
	ctx.lr = 0x821E793C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e794c
	if (cr6.eq) goto loc_821E794C;
	// bl 0x821f4c00
	ctx.lr = 0x821E7948;
	sub_821F4C00(ctx, base);
	// b 0x821e7950
	goto loc_821E7950;
loc_821E794C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E7950:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-12544
	r11.s64 = r11.s64 + -12544;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-31224
	ctx.r4.s64 = r11.s64 + -31224;
	// bl 0x821f4d08
	ctx.lr = 0x821E7968;
	sub_821F4D08(ctx, base);
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82130528
	ctx.lr = 0x821E7970;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7980
	if (cr6.eq) goto loc_821E7980;
	// bl 0x821f4c00
	ctx.lr = 0x821E797C;
	sub_821F4C00(ctx, base);
	// b 0x821e7984
	goto loc_821E7984;
loc_821E7980:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E7984:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-12540
	r11.s64 = r11.s64 + -12540;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-31244
	ctx.r4.s64 = r11.s64 + -31244;
	// bl 0x821f4d08
	ctx.lr = 0x821E799C;
	sub_821F4D08(ctx, base);
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82130528
	ctx.lr = 0x821E79A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e79b4
	if (cr6.eq) goto loc_821E79B4;
	// bl 0x821f4c00
	ctx.lr = 0x821E79B0;
	sub_821F4C00(ctx, base);
	// b 0x821e79b8
	goto loc_821E79B8;
loc_821E79B4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E79B8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-12536
	r11.s64 = r11.s64 + -12536;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-31264
	ctx.r4.s64 = r11.s64 + -31264;
	// bl 0x821f4d08
	ctx.lr = 0x821E79D0;
	sub_821F4D08(ctx, base);
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82130528
	ctx.lr = 0x821E79D8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e79e8
	if (cr6.eq) goto loc_821E79E8;
	// bl 0x821f4c00
	ctx.lr = 0x821E79E4;
	sub_821F4C00(ctx, base);
	// b 0x821e79ec
	goto loc_821E79EC;
loc_821E79E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E79EC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-12532
	r11.s64 = r11.s64 + -12532;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-31280
	ctx.r4.s64 = r11.s64 + -31280;
	// bl 0x821f4d08
	ctx.lr = 0x821E7A04;
	sub_821F4D08(ctx, base);
	// li r3,536
	ctx.r3.s64 = 536;
	// bl 0x82130528
	ctx.lr = 0x821E7A0C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7a24
	if (cr6.eq) goto loc_821E7A24;
	// bl 0x821efb98
	ctx.lr = 0x821E7A18;
	sub_821EFB98(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-12216(r11)
	PPC_STORE_U32(r11.u32 + -12216, ctx.r3.u32);
	// b 0x821e7a30
	goto loc_821E7A30;
loc_821E7A24:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12216(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12216, r11.u32);
loc_821E7A30:
	// bl 0x821ee430
	ctx.lr = 0x821E7A34;
	sub_821EE430(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821E7A4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r4,r8,17516
	ctx.r4.s64 = ctx.r8.s64 + 17516;
	// lwz r3,-32456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32456);
	// bl 0x82547a80
	ctx.lr = 0x821E7A60;
	sub_82547A80(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-32456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32456);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r30,r7,-12592
	r30.s64 = ctx.r7.s64 + -12592;
	// addi r4,r6,17508
	ctx.r4.s64 = ctx.r6.s64 + 17508;
	// stw r11,-12592(r7)
	PPC_STORE_U32(ctx.r7.u32 + -12592, r11.u32);
	// bl 0x82547a80
	ctx.lr = 0x821E7A80;
	sub_82547A80(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-32456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32456);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// addi r4,r5,-31288
	ctx.r4.s64 = ctx.r5.s64 + -31288;
	// bl 0x82547a80
	ctx.lr = 0x821E7A98;
	sub_82547A80(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lwz r3,-32456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32456);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// addi r4,r4,-31304
	ctx.r4.s64 = ctx.r4.s64 + -31304;
	// bl 0x82547a80
	ctx.lr = 0x821E7AB0;
	sub_82547A80(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-32456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32456);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// addi r4,r10,-31316
	ctx.r4.s64 = ctx.r10.s64 + -31316;
	// bl 0x82547a80
	ctx.lr = 0x821E7AC8;
	sub_82547A80(ctx, base);
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// lfs f2,-31320(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31320);
	ctx.f2.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f1,-31324(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31324);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8215f558
	ctx.lr = 0x821E7AF8;
	sub_8215F558(ctx, base);
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// bl 0x8215e450
	ctx.lr = 0x821E7B00;
	sub_8215E450(ctx, base);
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x821E7B08;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7b1c
	if (cr6.eq) goto loc_821E7B1C;
	// bl 0x821f6530
	ctx.lr = 0x821E7B14;
	sub_821F6530(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x821e7b20
	goto loc_821E7B20;
loc_821E7B1C:
	// li r11,0
	r11.s64 = 0;
loc_821E7B20:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r10,r10,-12556
	ctx.r10.s64 = ctx.r10.s64 + -12556;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r11,12008(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12008, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x821E7B3C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7b4c
	if (cr6.eq) goto loc_821E7B4C;
	// bl 0x821f6758
	ctx.lr = 0x821E7B48;
	sub_821F6758(ctx, base);
	// b 0x821e7b50
	goto loc_821E7B50;
loc_821E7B4C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E7B50:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-12568
	r11.s64 = r11.s64 + -12568;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E7B70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1080
	ctx.r3.s64 = 1080;
	// bl 0x82130528
	ctx.lr = 0x821E7B78;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7b88
	if (cr6.eq) goto loc_821E7B88;
	// bl 0x821eb940
	ctx.lr = 0x821E7B84;
	sub_821EB940(ctx, base);
	// b 0x821e7b8c
	goto loc_821E7B8C;
loc_821E7B88:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E7B8C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-12564
	r11.s64 = r11.s64 + -12564;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E7BA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x821E7BB0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7bc0
	if (cr6.eq) goto loc_821E7BC0;
	// bl 0x821f5d10
	ctx.lr = 0x821E7BBC;
	sub_821F5D10(ctx, base);
	// b 0x821e7bc4
	goto loc_821E7BC4;
loc_821E7BC0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E7BC4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-12560
	r11.s64 = r11.s64 + -12560;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821E7BE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r3,r9,-31340
	ctx.r3.s64 = ctx.r9.s64 + -31340;
	// bl 0x821380e0
	ctx.lr = 0x821E7BEC;
	sub_821380E0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,144
	ctx.r3.s64 = 144;
	// stw r11,-12476(r8)
	PPC_STORE_U32(ctx.r8.u32 + -12476, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x821E7C00;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e7c20
	if (cr6.eq) goto loc_821E7C20;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-31352
	ctx.r4.s64 = r11.s64 + -31352;
	// bl 0x821f57b8
	ctx.lr = 0x821E7C14;
	sub_821F57B8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r3,-12552(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12552, ctx.r3.u32);
	// b 0x821e7c2c
	goto loc_821E7C2C;
loc_821E7C20:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12552(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12552, r11.u32);
loc_821E7C2C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-31368
	ctx.r4.s64 = r11.s64 + -31368;
	// bl 0x82144a20
	ctx.lr = 0x821E7C3C;
	sub_82144A20(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-31388
	ctx.r4.s64 = ctx.r9.s64 + -31388;
	// stw r11,-12528(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12528, r11.u32);
	// bl 0x82144a20
	ctx.lr = 0x821E7C58;
	sub_82144A20(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stw r3,-12512(r8)
	PPC_STORE_U32(ctx.r8.u32 + -12512, ctx.r3.u32);
	// bl 0x8214d040
	ctx.lr = 0x821E7C64;
	sub_8214D040(ctx, base);
	// bl 0x821e7598
	ctx.lr = 0x821E7C68;
	sub_821E7598(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r29,r11,-12352
	r29.s64 = r11.s64 + -12352;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f30,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x821449e8
	ctx.lr = 0x821E7C8C;
	sub_821449E8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821449f0
	ctx.lr = 0x821E7CA0;
	sub_821449F0(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_821E7CA4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x821449e8
	ctx.lr = 0x821E7CB8;
	sub_821449E8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x821449f0
	ctx.lr = 0x821E7CCC;
	sub_821449F0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// blt cr6,0x821e7ca4
	if (cr6.lt) goto loc_821E7CA4;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r4,-12488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -12488);
	// bl 0x82161120
	ctx.lr = 0x821E7CE8;
	sub_82161120(ctx, base);
	// lwz r4,-12488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -12488);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82161210
	ctx.lr = 0x821E7CF4;
	sub_82161210(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,-12488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -12488);
	// bl 0x821449f8
	ctx.lr = 0x821E7D00;
	sub_821449F8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,-12497(r27)
	PPC_STORE_U8(r27.u32 + -12497, ctx.r10.u8);
	// lbz r9,-12498(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -12498);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e7d1c
	if (cr6.eq) goto loc_821E7D1C;
	// bl 0x821e69c0
	ctx.lr = 0x821E7D1C;
	sub_821E69C0(ctx, base);
loc_821E7D1C:
	// lis r11,-32226
	r11.s64 = -2111963136;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r11,r11,26624
	r11.s64 = r11.s64 + 26624;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,14060(r10)
	PPC_STORE_U32(ctx.r10.u32 + 14060, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821E7D40"))) PPC_WEAK_FUNC(sub_821E7D40);
PPC_FUNC_IMPL(__imp__sub_821E7D40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12568(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12568);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821f65f8
	sub_821F65F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E7D54"))) PPC_WEAK_FUNC(sub_821E7D54);
PPC_FUNC_IMPL(__imp__sub_821E7D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E7D58"))) PPC_WEAK_FUNC(sub_821E7D58);
PPC_FUNC_IMPL(__imp__sub_821E7D58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821ebda0
	sub_821EBDA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E7D6C"))) PPC_WEAK_FUNC(sub_821E7D6C);
PPC_FUNC_IMPL(__imp__sub_821E7D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E7D70"))) PPC_WEAK_FUNC(sub_821E7D70);
PPC_FUNC_IMPL(__imp__sub_821E7D70) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-12288(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12288);
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
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
	// bl 0x821eb448
	ctx.lr = 0x821E7DB4;
	sub_821EB448(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E7DC4"))) PPC_WEAK_FUNC(sub_821E7DC4);
PPC_FUNC_IMPL(__imp__sub_821E7DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E7DC8"))) PPC_WEAK_FUNC(sub_821E7DC8);
PPC_FUNC_IMPL(__imp__sub_821E7DC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821eb708
	sub_821EB708(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E7DDC"))) PPC_WEAK_FUNC(sub_821E7DDC);
PPC_FUNC_IMPL(__imp__sub_821E7DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E7DE0"))) PPC_WEAK_FUNC(sub_821E7DE0);
PPC_FUNC_IMPL(__imp__sub_821E7DE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-12288(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12288);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// b 0x821ea068
	sub_821EA068(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821E7E08"))) PPC_WEAK_FUNC(sub_821E7E08);
PPC_FUNC_IMPL(__imp__sub_821E7E08) {
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
	// lis r11,-32226
	r11.s64 = -2111963136;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,29696
	ctx.r4.s64 = r11.s64 + 29696;
	// addi r3,r10,-30556
	ctx.r3.s64 = ctx.r10.s64 + -30556;
	// bl 0x82554798
	ctx.lr = 0x821E7E28;
	sub_82554798(ctx, base);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,25568
	ctx.r4.s64 = ctx.r9.s64 + 25568;
	// addi r3,r8,-30588
	ctx.r3.s64 = ctx.r8.s64 + -30588;
	// bl 0x82554798
	ctx.lr = 0x821E7E3C;
	sub_82554798(ctx, base);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,32064
	ctx.r4.s64 = ctx.r7.s64 + 32064;
	// addi r3,r6,-30620
	ctx.r3.s64 = ctx.r6.s64 + -30620;
	// bl 0x82554798
	ctx.lr = 0x821E7E50;
	sub_82554798(ctx, base);
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,32088
	ctx.r4.s64 = ctx.r5.s64 + 32088;
	// addi r3,r3,-30652
	ctx.r3.s64 = ctx.r3.s64 + -30652;
	// bl 0x82554798
	ctx.lr = 0x821E7E64;
	sub_82554798(ctx, base);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,16256
	ctx.r4.s64 = r11.s64 + 16256;
	// addi r3,r10,-30684
	ctx.r3.s64 = ctx.r10.s64 + -30684;
	// bl 0x82554798
	ctx.lr = 0x821E7E78;
	sub_82554798(ctx, base);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,32112
	ctx.r4.s64 = ctx.r9.s64 + 32112;
	// addi r3,r8,-30712
	ctx.r3.s64 = ctx.r8.s64 + -30712;
	// bl 0x82554798
	ctx.lr = 0x821E7E8C;
	sub_82554798(ctx, base);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,32200
	ctx.r4.s64 = ctx.r7.s64 + 32200;
	// addi r3,r6,-30740
	ctx.r3.s64 = ctx.r6.s64 + -30740;
	// bl 0x82554798
	ctx.lr = 0x821E7EA0;
	sub_82554798(ctx, base);
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,32224
	ctx.r4.s64 = ctx.r5.s64 + 32224;
	// addi r3,r3,-30768
	ctx.r3.s64 = ctx.r3.s64 + -30768;
	// bl 0x82554798
	ctx.lr = 0x821E7EB4;
	sub_82554798(ctx, base);
	// lis r11,-32226
	r11.s64 = -2111963136;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,29704
	ctx.r4.s64 = r11.s64 + 29704;
	// addi r3,r10,-30800
	ctx.r3.s64 = ctx.r10.s64 + -30800;
	// bl 0x82554798
	ctx.lr = 0x821E7EC8;
	sub_82554798(ctx, base);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,29728
	ctx.r4.s64 = ctx.r9.s64 + 29728;
	// addi r3,r8,-30836
	ctx.r3.s64 = ctx.r8.s64 + -30836;
	// bl 0x82554798
	ctx.lr = 0x821E7EDC;
	sub_82554798(ctx, base);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,29744
	ctx.r4.s64 = ctx.r7.s64 + 29744;
	// addi r3,r6,-30872
	ctx.r3.s64 = ctx.r6.s64 + -30872;
	// bl 0x82554798
	ctx.lr = 0x821E7EF0;
	sub_82554798(ctx, base);
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,29760
	ctx.r4.s64 = ctx.r5.s64 + 29760;
	// addi r3,r3,-30904
	ctx.r3.s64 = ctx.r3.s64 + -30904;
	// bl 0x82554798
	ctx.lr = 0x821E7F04;
	sub_82554798(ctx, base);
	// lis r11,-32226
	r11.s64 = -2111963136;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,29808
	ctx.r4.s64 = r11.s64 + 29808;
	// addi r3,r10,-30936
	ctx.r3.s64 = ctx.r10.s64 + -30936;
	// bl 0x82554798
	ctx.lr = 0x821E7F18;
	sub_82554798(ctx, base);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,29840
	ctx.r4.s64 = ctx.r9.s64 + 29840;
	// addi r3,r8,-30976
	ctx.r3.s64 = ctx.r8.s64 + -30976;
	// bl 0x82554798
	ctx.lr = 0x821E7F2C;
	sub_82554798(ctx, base);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,29960
	ctx.r4.s64 = ctx.r7.s64 + 29960;
	// addi r3,r6,-31012
	ctx.r3.s64 = ctx.r6.s64 + -31012;
	// bl 0x82554798
	ctx.lr = 0x821E7F40;
	sub_82554798(ctx, base);
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,30080
	ctx.r4.s64 = ctx.r5.s64 + 30080;
	// addi r3,r3,-31040
	ctx.r3.s64 = ctx.r3.s64 + -31040;
	// bl 0x82554798
	ctx.lr = 0x821E7F54;
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

__attribute__((alias("__imp__sub_821E7F64"))) PPC_WEAK_FUNC(sub_821E7F64);
PPC_FUNC_IMPL(__imp__sub_821E7F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E7F68"))) PPC_WEAK_FUNC(sub_821E7F68);
PPC_FUNC_IMPL(__imp__sub_821E7F68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,292(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 292);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x821e7f9c
	if (!cr6.gt) goto loc_821E7F9C;
	// lwz r8,288(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_821E7F80:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821e7fa4
	if (cr6.eq) goto loc_821E7FA4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x821e7f80
	if (cr6.lt) goto loc_821E7F80;
loc_821E7F9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821E7FA4:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E7FB0"))) PPC_WEAK_FUNC(sub_821E7FB0);
PPC_FUNC_IMPL(__imp__sub_821E7FB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 300);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x821e7fe4
	if (!cr6.gt) goto loc_821E7FE4;
	// lwz r8,296(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_821E7FC8:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821e7fec
	if (cr6.eq) goto loc_821E7FEC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x821e7fc8
	if (cr6.lt) goto loc_821E7FC8;
loc_821E7FE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821E7FEC:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E7FF8"))) PPC_WEAK_FUNC(sub_821E7FF8);
PPC_FUNC_IMPL(__imp__sub_821E7FF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f2,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x821E8028;
	sub_823DCDD8(ctx, base);
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// frsp f31,f1
	f31.f64 = double(float(ctx.f1.f64));
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// bl 0x823dca68
	ctx.lr = 0x821E8038;
	sub_823DCA68(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// lfs f2,40(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,24(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x821E8048;
	sub_823DCDD8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stfs f13,0(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f30,4(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f31,8(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
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

__attribute__((alias("__imp__sub_821E807C"))) PPC_WEAK_FUNC(sub_821E807C);
PPC_FUNC_IMPL(__imp__sub_821E807C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E8080"))) PPC_WEAK_FUNC(sub_821E8080);
PPC_FUNC_IMPL(__imp__sub_821E8080) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// li r6,255
	ctx.r6.s64 = 255;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r5,4
	ctx.r5.s64 = 4;
	// lfs f13,-30464(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30464);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f13,60(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// stw r7,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r7.u32);
	// stb r6,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, ctx.r6.u8);
	// stb r11,69(r3)
	PPC_STORE_U8(ctx.r3.u32 + 69, r11.u8);
	// stb r5,70(r3)
	PPC_STORE_U8(ctx.r3.u32 + 70, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E80F8"))) PPC_WEAK_FUNC(sub_821E80F8);
PPC_FUNC_IMPL(__imp__sub_821E80F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e8140
	if (cr6.eq) goto loc_821E8140;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x821e816c
	if (cr6.lt) goto loc_821E816C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x821e816c
	if (!cr6.lt) goto loc_821E816C;
	// addi r11,r4,34
	r11.s64 = ctx.r4.s64 + 34;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e816c
	if (cr6.eq) goto loc_821E816C;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_821E8140:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x821e816c
	if (cr6.lt) goto loc_821E816C;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x821e816c
	if (!cr6.lt) goto loc_821E816C;
	// addi r11,r4,2
	r11.s64 = ctx.r4.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821e8170
	if (!cr6.eq) goto loc_821E8170;
loc_821E816C:
	// li r11,0
	r11.s64 = 0;
loc_821E8170:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E8178"))) PPC_WEAK_FUNC(sub_821E8178);
PPC_FUNC_IMPL(__imp__sub_821E8178) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x821E8180;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// lfs f31,-12492(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12492);
	f31.f64 = double(temp.f32);
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lbz r29,-1(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821e81f4
	if (cr6.eq) goto loc_821E81F4;
	// li r30,0
	r30.s64 = 0;
loc_821E81B4:
	// lwz r11,244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// mulli r10,r30,19
	ctx.r10.s64 = r30.s64 * 19;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,15(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 15);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82145080
	ctx.lr = 0x821E81D4;
	sub_82145080(ctx, base);
	// addi r9,r30,78
	ctx.r9.s64 = r30.s64 + 78;
	// addi r8,r30,1
	ctx.r8.s64 = r30.s64 + 1;
	// fadds f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f31.f64));
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r30,r8,24
	r30.u64 = ctx.r8.u32 & 0xFF;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// stfsx f0,r7,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, temp.u32);
	// blt cr6,0x821e81b4
	if (cr6.lt) goto loc_821E81B4;
loc_821E81F4:
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lbz r29,-1(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821e8248
	if (cr6.eq) goto loc_821E8248;
	// li r30,0
	r30.s64 = 0;
loc_821E8208:
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// mulli r10,r30,19
	ctx.r10.s64 = r30.s64 * 19;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,15(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 15);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82145080
	ctx.lr = 0x821E8228;
	sub_82145080(ctx, base);
	// addi r9,r30,142
	ctx.r9.s64 = r30.s64 + 142;
	// fadds f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f31.f64));
	// addi r8,r30,1
	ctx.r8.s64 = r30.s64 + 1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r30,r8,24
	r30.u64 = ctx.r8.u32 & 0xFF;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// stfsx f0,r7,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, temp.u32);
	// blt cr6,0x821e8208
	if (cr6.lt) goto loc_821E8208;
loc_821E8248:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E8258"))) PPC_WEAK_FUNC(sub_821E8258);
PPC_FUNC_IMPL(__imp__sub_821E8258) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// addi r9,r3,156
	ctx.r9.s64 = ctx.r3.s64 + 156;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_821E8264:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r4,r8
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, xer);
	// beq cr6,0x821e82f0
	if (cr6.eq) goto loc_821E82F0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blt cr6,0x821e8264
	if (cr6.lt) goto loc_821E8264;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_821E8288:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821e82f0
	if (cr6.eq) goto loc_821E82F0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blt cr6,0x821e8288
	if (cr6.lt) goto loc_821E8288;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f0,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x821e82c4
	if (cr6.lt) goto loc_821E82C4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_821E82C4:
	// lfs f13,188(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r3,176
	ctx.r10.s64 = ctx.r3.s64 + 176;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x821e82d8
	if (cr6.lt) goto loc_821E82D8;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_821E82D8:
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x821e82ec
	if (cr6.lt) goto loc_821E82EC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_821E82EC:
	// blr 
	return;
loc_821E82F0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E82F8"))) PPC_WEAK_FUNC(sub_821E82F8);
PPC_FUNC_IMPL(__imp__sub_821E82F8) {
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
	ctx.lr = 0x821E8300;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r31,r3,164
	r31.s64 = ctx.r3.s64 + 164;
	// li r30,2
	r30.s64 = 2;
	// li r27,0
	r27.s64 = 0;
loc_821E8318:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// beq cr6,0x821e8374
	if (cr6.eq) goto loc_821E8374;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// beq cr6,0x821e8374
	if (cr6.eq) goto loc_821E8374;
	// lwz r3,-8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e8340
	if (cr6.eq) goto loc_821E8340;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821E8340;
	sub_821F4C18(ctx, base);
loc_821E8340:
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e8354
	if (cr6.eq) goto loc_821E8354;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821E8354;
	sub_8213C218(ctx, base);
loc_821E8354:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e8374
	if (cr6.eq) goto loc_821E8374;
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e8374
	if (!cr6.eq) goto loc_821E8374;
	// bl 0x821f6c50
	ctx.lr = 0x821E8374;
	sub_821F6C50(ctx, base);
loc_821E8374:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x821e8318
	if (!cr0.eq) goto loc_821E8318;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821E8388"))) PPC_WEAK_FUNC(sub_821E8388);
PPC_FUNC_IMPL(__imp__sub_821E8388) {
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
	ctx.lr = 0x821E8390;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r3,164
	r31.s64 = ctx.r3.s64 + 164;
	// li r30,2
	r30.s64 = 2;
	// li r29,0
	r29.s64 = 0;
loc_821E83A4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// beq cr6,0x821e83f8
	if (cr6.eq) goto loc_821E83F8;
	// lwz r3,-8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e83c4
	if (cr6.eq) goto loc_821E83C4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821E83C4;
	sub_821F4C18(ctx, base);
loc_821E83C4:
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e83d8
	if (cr6.eq) goto loc_821E83D8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821E83D8;
	sub_8213C218(ctx, base);
loc_821E83D8:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e83f8
	if (cr6.eq) goto loc_821E83F8;
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e83f8
	if (!cr6.eq) goto loc_821E83F8;
	// bl 0x821f6c50
	ctx.lr = 0x821E83F8;
	sub_821F6C50(ctx, base);
loc_821E83F8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x821e83a4
	if (!cr0.eq) goto loc_821E83A4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821E840C"))) PPC_WEAK_FUNC(sub_821E840C);
PPC_FUNC_IMPL(__imp__sub_821E840C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E8410"))) PPC_WEAK_FUNC(sub_821E8410);
PPC_FUNC_IMPL(__imp__sub_821E8410) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x821E8418;
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,1044(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1044);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x821e8448
	if (!cr6.eq) goto loc_821E8448;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821E8448:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e849c
	if (!cr6.eq) goto loc_821E849C;
	// lwz r3,836(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 836);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e8468
	if (cr6.eq) goto loc_821E8468;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821E8468;
	sub_8213C218(ctx, base);
loc_821E8468:
	// lbz r11,1074(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1074);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e8488
	if (cr6.eq) goto loc_821E8488;
	// lwz r3,280(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e8488
	if (cr6.eq) goto loc_821E8488;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821E8488;
	sub_821F4C18(ctx, base);
loc_821E8488:
	// stb r27,1074(r31)
	PPC_STORE_U8(r31.u32 + 1074, r27.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_821E849C:
	// lbz r11,1074(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1074);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e84d8
	if (!cr6.eq) goto loc_821E84D8;
	// lwz r3,836(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 836);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e84bc
	if (cr6.eq) goto loc_821E84BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821E84BC;
	sub_8213C218(ctx, base);
loc_821E84BC:
	// lwz r3,280(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e84d0
	if (cr6.eq) goto loc_821E84D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821E84D0;
	sub_821F4C18(ctx, base);
loc_821E84D0:
	// li r11,1
	r11.s64 = 1;
	// stb r11,1074(r31)
	PPC_STORE_U8(r31.u32 + 1074, r11.u8);
loc_821E84D8:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// addi r28,r31,280
	r28.s64 = r31.s64 + 280;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e8520
	if (!cr6.eq) goto loc_821E8520;
	// lwz r11,-12512(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -12512);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-12548(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -12548);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lbz r11,11(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// lwz r4,26(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// bl 0x821f4e78
	ctx.lr = 0x821E8520;
	sub_821F4E78(ctx, base);
loc_821E8520:
	// lwz r10,836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 836);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r31,836
	r29.s64 = r31.s64 + 836;
	// addi r26,r11,-30496
	r26.s64 = r11.s64 + -30496;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821e85b8
	if (!cr6.eq) goto loc_821E85B8;
	// li r11,-1
	r11.s64 = -1;
	// lfs f0,32(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 32);
	f0.f64 = double(temp.f32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lfs f13,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r9,255
	ctx.r9.s64 = 255;
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r27.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stw r27,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r27.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r27,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r27.u32);
	// stw r27,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r27.u32);
	// stw r27,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r27.u32);
	// stw r27,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r27.u32);
	// stw r27,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r27.u32);
	// stw r27,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r27.u32);
	// stw r27,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r27.u32);
	// stw r27,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r27.u32);
	// stw r27,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r27.u32);
	// stw r27,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r27.u32);
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r11.u32);
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// stb r9,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r9.u8);
	// stb r27,181(r1)
	PPC_STORE_U8(ctx.r1.u32 + 181, r27.u8);
	// stb r8,182(r1)
	PPC_STORE_U8(ctx.r1.u32 + 182, ctx.r8.u8);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,22(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 22);
	// bl 0x825491f0
	ctx.lr = 0x821E85B8;
	sub_825491F0(ctx, base);
loc_821E85B8:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r30,r27
	r30.u64 = r27.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x821e85ec
	if (cr6.eq) goto loc_821E85EC;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821e8608
	if (!cr6.gt) goto loc_821E8608;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x821e85fc
	goto loc_821E85FC;
loc_821E85EC:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821e8608
	if (!cr6.gt) goto loc_821E8608;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_821E85FC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x821e860c
	if (!cr6.eq) goto loc_821E860C;
loc_821E8608:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_821E860C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e8630
	if (cr6.eq) goto loc_821E8630;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12252(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r11,1744(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1744);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
loc_821E8630:
	// lwz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821e8650
	if (!cr6.eq) goto loc_821E8650;
	// lbz r10,1076(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1076);
	// lbz r9,1075(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1075);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x821e8890
	if (cr6.eq) goto loc_821E8890;
loc_821E8650:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e8740
	if (cr6.eq) goto loc_821E8740;
	// lbz r10,30(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 30);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e8740
	if (cr6.eq) goto loc_821E8740;
	// lhz r11,31(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 31);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// extsh r7,r11
	ctx.r7.s64 = r11.s16;
	// lwz r3,844(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 844);
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f31,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r6,58(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 58);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547f00
	ctx.lr = 0x821E86A4;
	sub_82547F00(ctx, base);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,844(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 844);
	// lhz r11,33(r5)
	r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 33);
	// lwz r10,58(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 58);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfd f11,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547fe8
	ctx.lr = 0x821E86D8;
	sub_82547FE8(ctx, base);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r7,144(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r3,848(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lwz r6,58(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 58);
	// lhz r5,35(r7)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + 35);
	// extsh r11,r5
	r11.s64 = ctx.r5.s16;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f9,96(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f1,f7,f31
	ctx.f1.f64 = double(float(ctx.f7.f64 * f31.f64));
	// bl 0x82547f00
	ctx.lr = 0x821E8710;
	sub_82547F00(ctx, base);
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lhz r7,37(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 37);
	// lwz r8,58(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 58);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f6,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// frsp f1,f5
	ctx.f1.f64 = double(float(ctx.f5.f64));
	// b 0x821e8878
	goto loc_821E8878;
loc_821E8740:
	// lbz r11,1075(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1075);
	// lwz r3,844(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 844);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// beq cr6,0x821e8818
	if (cr6.eq) goto loc_821E8818;
	// lwz r9,58(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 58);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r8,62(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 62);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f31,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547f00
	ctx.lr = 0x821E8788;
	sub_82547F00(ctx, base);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,844(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 844);
	// lhz r4,64(r5)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + 64);
	// lwz r11,58(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 58);
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfd f11,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547fe8
	ctx.lr = 0x821E87B8;
	sub_82547FE8(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,848(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lwz r8,58(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 58);
	// lhz r7,66(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 66);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f9,96(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f1,f7,f31
	ctx.f1.f64 = double(float(ctx.f7.f64 * f31.f64));
	// bl 0x82547f00
	ctx.lr = 0x821E87EC;
	sub_82547F00(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lhz r10,68(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 68);
	// lwz r11,58(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 58);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f6,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// frsp f1,f5
	ctx.f1.f64 = double(float(ctx.f5.f64));
	// b 0x821e8878
	goto loc_821E8878;
loc_821E8818:
	// lwz r10,58(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 58);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82547f00
	ctx.lr = 0x821E882C;
	sub_82547F00(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,58(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 58);
	// lfs f1,32(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,844(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 844);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82547fe8
	ctx.lr = 0x821E8848;
	sub_82547FE8(ctx, base);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,58(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 58);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwz r3,848(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82547f00
	ctx.lr = 0x821E8864;
	sub_82547F00(ctx, base);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,58(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 58);
	// lfs f1,32(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
loc_821E8878:
	// lwz r3,848(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// bl 0x82547fe8
	ctx.lr = 0x821E8880;
	sub_82547FE8(ctx, base);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lbz r10,1075(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1075);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// stb r10,1076(r31)
	PPC_STORE_U8(r31.u32 + 1076, ctx.r10.u8);
loc_821E8890:
	// lfs f0,1048(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1048);
	f0.f64 = double(temp.f32);
	// lfs f13,1052(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1052);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x821e88c0
	if (!cr6.lt) goto loc_821E88C0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f12,92(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f13,1052(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1052, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x821e88e8
	if (!cr6.gt) goto loc_821E88E8;
	// b 0x821e88e4
	goto loc_821E88E4;
loc_821E88C0:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x821e88e8
	if (!cr6.gt) goto loc_821E88E8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f12,92(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stfs f13,1052(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1052, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x821e88e8
	if (!cr6.lt) goto loc_821E88E8;
loc_821E88E4:
	// stfs f0,1052(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1052, temp.u32);
loc_821E88E8:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// beq cr6,0x821e89f8
	if (cr6.eq) goto loc_821E89F8;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e8948
	if (cr6.eq) goto loc_821E8948;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e893c
	if (cr6.eq) goto loc_821E893C;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821e8940
	goto loc_821E8940;
loc_821E893C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_821E8940:
	// lfs f1,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82148cb0
	ctx.lr = 0x821E8948;
	sub_82148CB0(ctx, base);
loc_821E8948:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e8a8c
	if (cr6.eq) goto loc_821E8A8C;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,1052(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1052);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f30,100(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f30,104(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r6,16
	ctx.r6.s64 = 16;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	v61.f32[0] = log2f(v62.f32[0]);
	v61.f32[1] = log2f(v62.f32[1]);
	v61.f32[2] = log2f(v62.f32[2]);
	v61.f32[3] = log2f(v62.f32[3]);
	// lvx128 v63,r26,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v61,v63
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// lfs f13,11368(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// beq cr6,0x821e89e0
	if (cr6.eq) goto loc_821E89E0;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lfs f12,4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 - ctx.f12.f64));
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lfs f0,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// fsel f1,f12,f13,f0
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821e8a88
	goto loc_821E8A88;
loc_821E89E0:
	// lfs f12,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lfs f0,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsel f1,f12,f13,f0
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// b 0x821e8a88
	goto loc_821E8A88;
loc_821E89F8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e8a40
	if (cr6.eq) goto loc_821E8A40;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e8a34
	if (cr6.eq) goto loc_821E8A34;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821e8a38
	goto loc_821E8A38;
loc_821E8A34:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_821E8A38:
	// lfs f1,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82148cb0
	ctx.lr = 0x821E8A40;
	sub_82148CB0(ctx, base);
loc_821E8A40:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e8a8c
	if (cr6.eq) goto loc_821E8A8C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e8a80
	if (cr6.eq) goto loc_821E8A80;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821e8a84
	goto loc_821E8A84;
loc_821E8A80:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_821E8A84:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
loc_821E8A88:
	// bl 0x82148cb0
	ctx.lr = 0x821E8A8C;
	sub_82148CB0(ctx, base);
loc_821E8A8C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f0,824(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 824);
	f0.f64 = double(temp.f32);
	// lfs f31,-12492(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12492);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// blt cr6,0x821e8b04
	if (cr6.lt) goto loc_821E8B04;
	// lwz r11,284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// addi r5,r31,284
	ctx.r5.s64 = r31.s64 + 284;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e8b04
	if (!cr6.eq) goto loc_821E8B04;
	// lwz r11,-12512(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -12512);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-12548(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -12548);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// lwz r4,30(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 30);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// bl 0x821f4e78
	ctx.lr = 0x821E8ADC;
	sub_821F4E78(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,34(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 34);
	// lwz r8,38(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 38);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82145080
	ctx.lr = 0x821E8AFC;
	sub_82145080(ctx, base);
	// fadds f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f31.f64));
	// stfs f0,824(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 824, temp.u32);
loc_821E8B04:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821E8B14"))) PPC_WEAK_FUNC(sub_821E8B14);
PPC_FUNC_IMPL(__imp__sub_821E8B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E8B18"))) PPC_WEAK_FUNC(sub_821E8B18);
PPC_FUNC_IMPL(__imp__sub_821E8B18) {
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
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
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
	// bl 0x823d91d4
	ctx.lr = 0x821E8B20;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823db9c4
	ctx.lr = 0x821E8B28;
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x821e67b8
	ctx.lr = 0x821E8B34;
	sub_821E67B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e9054
	if (!cr6.eq) goto loc_821E9054;
	// lwz r11,244(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 244);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lbz r24,-1(r11)
	r24.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// lfs f25,-12492(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12492);
	f25.f64 = double(temp.f32);
	// li r31,0
	r31.s64 = 0;
	// lfs f29,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	f29.f64 = double(temp.f32);
	// li r23,-1
	r23.s64 = -1;
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r19,-1
	r19.s64 = -1;
	// lfs f26,14980(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14980);
	f26.f64 = double(temp.f32);
	// li r20,255
	r20.s64 = 255;
	// lfs f27,2432(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 2432);
	f27.f64 = double(temp.f32);
	// li r21,4
	r21.s64 = 4;
	// lfs f24,27644(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27644);
	f24.f64 = double(temp.f32);
	// lis r22,-32254
	r22.s64 = -2113798144;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x821e8e44
	if (cr6.eq) goto loc_821E8E44;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r26,r31
	r26.u64 = r31.u64;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// addi r27,r11,7216
	r27.s64 = r11.s64 + 7216;
	// lfs f28,-30172(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -30172);
	f28.f64 = double(temp.f32);
loc_821E8BB0:
	// addi r11,r26,78
	r11.s64 = r26.s64 + 78;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r28,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + r29.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f25,f0
	cr6.compare(f25.f64, f0.f64);
	// blt cr6,0x821e8e30
	if (cr6.lt) goto loc_821E8E30;
	// lwz r11,244(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 244);
	// mulli r10,r26,19
	ctx.r10.s64 = r26.s64 * 19;
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,15(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 15);
	// lwz r10,11(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 11);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lfs f1,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82145080
	ctx.lr = 0x821E8BEC;
	sub_82145080(ctx, base);
	// fadds f0,f1,f25
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f25.f64));
	// stfsx f0,r28,r29
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + r29.u32, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e7f68
	ctx.lr = 0x821E8BFC;
	sub_821E7F68(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821e8e30
	if (cr6.eq) goto loc_821E8E30;
	// lhz r11,7(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 7);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821e8c70
	if (cr6.eq) goto loc_821E8C70;
	// lhz r11,9(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 9);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// std r8,320(r1)
	PPC_STORE_U64(ctx.r1.u32 + 320, ctx.r8.u64);
	// lfd f0,320(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 320);
	// std r7,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r7.u64);
	// lfd f13,136(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f2,f12
	ctx.f2.f64 = double(float(ctx.f12.f64));
	// frsp f1,f11
	ctx.f1.f64 = double(float(ctx.f11.f64));
	// bl 0x82145080
	ctx.lr = 0x821E8C4C;
	sub_82145080(ctx, base);
	// lhz r6,7(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 7);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// lfd f10,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fadds f7,f1,f8
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f8.f64));
	// fmuls f30,f7,f24
	f30.f64 = double(float(ctx.f7.f64 * f24.f64));
	// b 0x821e8c80
	goto loc_821E8C80;
loc_821E8C70:
	// fmr f2,f26
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f26.f64;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x82145080
	ctx.lr = 0x821E8C7C;
	sub_82145080(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
loc_821E8C80:
	// stfs f31,304(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// stfs f31,308(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// stfs f28,312(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// bl 0x8216c890
	ctx.lr = 0x821E8C98;
	sub_8216C890(ctx, base);
	// stfs f31,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f0,-30464(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -30464);
	f0.f64 = double(temp.f32);
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r31.u32);
	// stfs f0,204(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stw r31,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r31.u32);
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r31.u32);
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r31.u32);
	// stw r31,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r31.u32);
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r31.u32);
	// stw r31,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r31.u32);
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r31.u32);
	// stw r31,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r31.u32);
	// stw r31,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r31.u32);
	// stw r31,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r31.u32);
	// stw r31,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r31.u32);
	// stw r23,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r23.u32);
	// stw r19,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r19.u32);
	// stb r20,212(r1)
	PPC_STORE_U8(ctx.r1.u32 + 212, r20.u8);
	// stb r31,213(r1)
	PPC_STORE_U8(ctx.r1.u32 + 213, r31.u8);
	// stb r21,214(r1)
	PPC_STORE_U8(ctx.r1.u32 + 214, r21.u8);
	// lbz r8,1079(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 1079);
	// lhz r11,5(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 5);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f29
	ctx.f11.f64 = double(float(ctx.f12.f64 * f29.f64));
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// beq cr6,0x821e8d24
	if (cr6.eq) goto loc_821E8D24;
	// addi r11,r1,304
	r11.s64 = ctx.r1.s64 + 304;
	// stw r11,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r11.u32);
	// b 0x821e8d34
	goto loc_821E8D34;
loc_821E8D24:
	// fctiwz f0,f30
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f30.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f30.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r11,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r11.u32);
loc_821E8D34:
	// lbz r11,1072(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 1072);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// beq cr6,0x821e8db4
	if (cr6.eq) goto loc_821E8DB4;
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e8e30
	if (cr6.eq) goto loc_821E8E30;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-12540(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -12540);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,1(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 1);
	// li r8,5
	ctx.r8.s64 = 5;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x821f4e78
	ctx.lr = 0x821E8D74;
	sub_821F4E78(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e8e30
	if (cr6.eq) goto loc_821E8E30;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e8e24
	if (cr6.eq) goto loc_821E8E24;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821e8e28
	goto loc_821E8E28;
loc_821E8DB4:
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e8e30
	if (cr6.eq) goto loc_821E8E30;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-12540(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -12540);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,1(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 1);
	// li r8,5
	ctx.r8.s64 = 5;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x821f4e78
	ctx.lr = 0x821E8DE4;
	sub_821F4E78(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e8e30
	if (cr6.eq) goto loc_821E8E30;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e8e24
	if (cr6.eq) goto loc_821E8E24;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821e8e28
	goto loc_821E8E28;
loc_821E8E24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821E8E28:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82148de0
	ctx.lr = 0x821E8E30;
	sub_82148DE0(ctx, base);
loc_821E8E30:
	// addi r11,r26,1
	r11.s64 = r26.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r26,r11
	r26.u64 = r11.u64;
	// cmplw cr6,r11,r24
	cr6.compare<uint32_t>(r11.u32, r24.u32, xer);
	// blt cr6,0x821e8bb0
	if (cr6.lt) goto loc_821E8BB0;
loc_821E8E44:
	// lwz r11,248(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 248);
	// lbz r24,-1(r11)
	r24.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x821e9054
	if (cr6.eq) goto loc_821E9054;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r27,r31
	r27.u64 = r31.u64;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lfs f30,-30176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30176);
	f30.f64 = double(temp.f32);
loc_821E8E68:
	// addi r11,r27,142
	r11.s64 = r27.s64 + 142;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r28,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + r29.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f25,f0
	cr6.compare(f25.f64, f0.f64);
	// blt cr6,0x821e9040
	if (cr6.lt) goto loc_821E9040;
	// lwz r10,248(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 248);
	// mulli r11,r27,19
	r11.s64 = r27.s64 * 19;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,15(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 15);
	// lwz r10,11(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 11);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lfs f1,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82145080
	ctx.lr = 0x821E8EA4;
	sub_82145080(ctx, base);
	// fadds f0,f1,f25
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f25.f64));
	// stfsx f0,r28,r29
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + r29.u32, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e7fb0
	ctx.lr = 0x821E8EB4;
	sub_821E7FB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821e9040
	if (cr6.eq) goto loc_821E9040;
	// lhz r11,7(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 7);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x821e8f28
	if (cr6.eq) goto loc_821E8F28;
	// lhz r11,9(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 9);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f12,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// frsp f1,f11
	ctx.f1.f64 = double(float(ctx.f11.f64));
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f2,f13
	ctx.f2.f64 = double(float(ctx.f13.f64));
	// bl 0x82145080
	ctx.lr = 0x821E8F04;
	sub_82145080(ctx, base);
	// lhz r6,7(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 7);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// lfd f10,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fadds f7,f1,f8
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f8.f64));
	// fmuls f1,f7,f24
	ctx.f1.f64 = double(float(ctx.f7.f64 * f24.f64));
	// b 0x821e8f34
	goto loc_821E8F34;
loc_821E8F28:
	// fmr f2,f26
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f26.f64;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x82145080
	ctx.lr = 0x821E8F34;
	sub_82145080(ctx, base);
loc_821E8F34:
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmr f28,f1
	f28.f64 = ctx.f1.f64;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f30,120(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x823dbae8
	ctx.lr = 0x821E8F48;
	sub_823DBAE8(ctx, base);
	// frsp f23,f1
	ctx.fpscr.disableFlushMode();
	f23.f64 = double(float(ctx.f1.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x821E8F54;
	sub_823DBBC8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f13,-30464(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -30464);
	ctx.f13.f64 = double(temp.f32);
	// stfs f31,224(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stw r31,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r31.u32);
	// stfs f13,284(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stw r31,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r31.u32);
	// stw r31,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r31.u32);
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// stb r21,294(r1)
	PPC_STORE_U8(ctx.r1.u32 + 294, r21.u8);
	// fmuls f10,f0,f23
	ctx.f10.f64 = double(float(f0.f64 * f23.f64));
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// stw r31,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, r31.u32);
	// stw r31,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r31.u32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stw r31,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, r31.u32);
	// stw r31,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, r31.u32);
	// stw r31,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, r31.u32);
	// fmuls f9,f0,f11
	ctx.f9.f64 = double(float(f0.f64 * ctx.f11.f64));
	// stw r31,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, r31.u32);
	// stw r31,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r31.u32);
	// stw r31,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, r31.u32);
	// stw r31,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r31.u32);
	// fmsubs f8,f12,f11,f10
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 - ctx.f10.f64));
	// stfs f8,120(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r31,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, r31.u32);
	// stw r23,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, r23.u32);
	// stw r19,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, r19.u32);
	// stb r20,292(r1)
	PPC_STORE_U8(ctx.r1.u32 + 292, r20.u8);
	// stb r31,293(r1)
	PPC_STORE_U8(ctx.r1.u32 + 293, r31.u8);
	// fmadds f7,f12,f23,f9
	ctx.f7.f64 = double(float(ctx.f12.f64 * f23.f64 + ctx.f9.f64));
	// stfs f7,112(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lbz r10,1072(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 1072);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lhz r9,5(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 5);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// std r7,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r7.u64);
	// lfd f6,136(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// stw r11,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r11.u32);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f29
	ctx.f3.f64 = double(float(ctx.f4.f64 * f29.f64));
	// stfs f3,224(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// bne cr6,0x821e900c
	if (!cr6.eq) goto loc_821E900C;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
loc_821E900C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e9040
	if (cr6.eq) goto loc_821E9040;
	// lwz r11,-12512(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -12512);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,1(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 1);
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// lwz r3,-12548(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -12548);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lbz r11,12(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// bl 0x821f4e78
	ctx.lr = 0x821E9040;
	sub_821F4E78(ctx, base);
loc_821E9040:
	// addi r11,r27,1
	r11.s64 = r27.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r27,r11
	r27.u64 = r11.u64;
	// cmplw cr6,r11,r24
	cr6.compare<uint32_t>(r11.u32, r24.u32, xer);
	// blt cr6,0x821e8e68
	if (cr6.lt) goto loc_821E8E68;
loc_821E9054:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dba10
	ctx.lr = 0x821E9060;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_821E9064"))) PPC_WEAK_FUNC(sub_821E9064);
PPC_FUNC_IMPL(__imp__sub_821E9064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E9068"))) PPC_WEAK_FUNC(sub_821E9068);
PPC_FUNC_IMPL(__imp__sub_821E9068) {
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
	// bl 0x823d91fc
	ctx.lr = 0x821E9070;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821e67b8
	ctx.lr = 0x821E9080;
	sub_821E67B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e9380
	if (!cr6.eq) goto loc_821E9380;
	// lwz r29,140(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821e9380
	if (cr6.eq) goto loc_821E9380;
	// lwz r11,39(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 39);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x821e9380
	if (cr6.eq) goto loc_821E9380;
	// lwz r9,256(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// lbz r8,-1(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + -1);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// blt cr6,0x821e9380
	if (cr6.lt) goto loc_821E9380;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// addi r11,r11,-12352
	r11.s64 = r11.s64 + -12352;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v58,v63,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// stvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f12,56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f7,f8,f8
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f6,f11,f12
	ctx.f6.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lfs f11,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f5,f10,f11
	ctx.f5.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fmadds f4,f6,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f7.f64));
	// fmadds f31,f5,f5,f4
	f31.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// ble cr6,0x821e9274
	if (!cr6.gt) goto loc_821E9274;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r10,-23776
	ctx.r6.s64 = ctx.r10.s64 + -23776;
	// li r10,1
	ctx.r10.s64 = 1;
	// lvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_821E9164:
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// vsubfp128 v12,v63,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lfs f10,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// lfs f9,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v0,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmsum3fp128 v57,v0,v12
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32), 0xEF));
	// vsubfp128 v63,v61,v57
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v57.f32)));
	// vcmpgefp128. v56,v60,v63
	simde_mm_store_ps(v56.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v56.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r7,r11,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x821e9218
	if (!cr6.eq) goto loc_821E9218;
	// vmsum3fp128 v55,v0,v0
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// vsubfp128 v62,v55,v63
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgefp128. v54,v60,v62
	simde_mm_store_ps(v54.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	cr6.setFromMask(simde_mm_load_ps(v54.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r7,r11,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821e91f4
	if (cr6.eq) goto loc_821E91F4;
	// vaddfp v12,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)));
	// b 0x821e9218
	goto loc_821E9218;
loc_821E91F4:
	// vaddfp128 v53,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// vupkd3d128 v52,v61,4
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v52 = vTemp;
	// vspltw128 v11,v52,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0x0));
	// vrefp128 v13,v53
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v53.f32)));
	// vor128 v10,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vnmsubfp v8,v13,v10,v11
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v13,v8,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v6,v63,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v12,v0,v6,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
loc_821E9218:
	// vaddfp128 v63,v12,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v59.f32)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f8,f9,f9
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fsubs f6,f0,f12
	ctx.f6.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f5,f7,f11
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f11.f64));
	// fmadds f4,f6,f6,f8
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f8.f64));
	// fmadds f0,f5,f5,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x821e9260
	if (!cr6.lt) goto loc_821E9260;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// vor128 v58,v63,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// fmr f31,f0
	f31.f64 = f0.f64;
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_821E9260:
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// vor128 v63,v58,v58
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x821e9164
	if (cr6.lt) goto loc_821E9164;
loc_821E9274:
	// lwz r11,39(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 39);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// fcmpu cr6,f31,f13
	cr6.compare(f31.f64, ctx.f13.f64);
	// bgt cr6,0x821e9380
	if (cr6.gt) goto loc_821E9380;
	// lwz r31,260(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821e9304
	if (!cr6.eq) goto loc_821E9304;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e8258
	ctx.lr = 0x821E92A8;
	sub_821E8258(ctx, base);
	// stw r3,260(r30)
	PPC_STORE_U32(r30.u32 + 260, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e9380
	if (cr6.eq) goto loc_821E9380;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e92cc
	if (cr6.eq) goto loc_821E92CC;
	// li r4,0
	ctx.r4.s64 = 0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821f4c18
	ctx.lr = 0x821E92CC;
	sub_821F4C18(ctx, base);
loc_821E92CC:
	// lwz r11,260(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e92e4
	if (cr6.eq) goto loc_821E92E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821E92E4;
	sub_8213C218(ctx, base);
loc_821E92E4:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821e8080
	ctx.lr = 0x821E92EC;
	sub_821E8080(ctx, base);
	// lwz r4,140(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lwz r5,260(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// lwz r4,43(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 43);
	// b 0x821e933c
	goto loc_821E933C;
loc_821E9304:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9324
	if (cr6.eq) goto loc_821E9324;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8213b860
	ctx.lr = 0x821E9320;
	sub_8213B860(ctx, base);
	// b 0x821e935c
	goto loc_821E935C;
loc_821E9324:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821e8080
	ctx.lr = 0x821E932C;
	sub_821E8080(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// lwz r4,43(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 43);
loc_821E933C:
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,5
	ctx.r8.s64 = 5;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lwz r3,-12536(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12536);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x821f4e78
	ctx.lr = 0x821E935C;
	sub_821F4E78(ctx, base);
loc_821E935C:
	// lwz r11,260(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,140(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r9,260(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// stfs f31,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_821E9380:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E9390"))) PPC_WEAK_FUNC(sub_821E9390);
PPC_FUNC_IMPL(__imp__sub_821E9390) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x821E9398;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d8
	ctx.lr = 0x821E93A0;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f1.f64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r28,r11,-30496
	r28.s64 = r11.s64 + -30496;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// clrlwi r8,r6,24
	ctx.r8.u64 = ctx.r6.u32 & 0xFF;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r11,-1
	r11.s64 = -1;
	// lfs f0,32(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 32);
	f0.f64 = double(temp.f32);
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r7,9(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 9);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lwz r4,5(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5);
	// mr r26,r30
	r26.u64 = r30.u64;
	// lwz r3,1(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1);
	// li r10,255
	ctx.r10.s64 = 255;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// stfs f1,112(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// stw r30,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r30.u32);
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r30.u32);
	// stw r30,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r30.u32);
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r30.u32);
	// stw r30,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r30.u32);
	// stw r30,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r30.u32);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r30,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r30.u32);
	// stw r5,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r5.u32);
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r11.u32);
	// stb r10,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r10.u8);
	// stb r30,181(r1)
	PPC_STORE_U8(ctx.r1.u32 + 181, r30.u8);
	// stb r9,182(r1)
	PPC_STORE_U8(ctx.r1.u32 + 182, ctx.r9.u8);
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// stw r7,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,192(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// bne cr6,0x821e94e0
	if (!cr6.eq) goto loc_821E94E0;
	// lwz r11,860(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 860);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lhz r8,82(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// lfs f10,-30128(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30128);
	ctx.f10.f64 = double(temp.f32);
	// lwz r10,26652(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26652);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f9,r5,r10
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f9,f10
	cr6.compare(ctx.f9.f64, ctx.f10.f64);
	// bgt cr6,0x821e94e0
	if (cr6.gt) goto loc_821E94E0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e94bc
	if (cr6.eq) goto loc_821E94BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821E94BC;
	sub_821F4C18(ctx, base);
loc_821E94BC:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821E94D0;
	sub_8213C218(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x821E94DC;
	// b 0x823d9240
	return;
loc_821E94E0:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e9550
	if (cr6.eq) goto loc_821E9550;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9550
	if (cr6.eq) goto loc_821E9550;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f0,88(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 88, temp.u32);
	// stfs f12,80(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 80, temp.u32);
	// mr r26,r11
	r26.u64 = r11.u64;
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f0,84(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 84, temp.u32);
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// lbz r9,119(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 119);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821e9544
	if (!cr6.eq) goto loc_821E9544;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,112(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x821e9548
	if (cr6.lt) goto loc_821E9548;
loc_821E9544:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_821E9548:
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
loc_821E9550:
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9684
	if (cr6.eq) goto loc_821E9684;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// addi r3,r27,944
	ctx.r3.s64 = r27.s64 + 944;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r8,17(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 17);
	// lwz r9,21(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 21);
	// lwz r7,17(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17);
	// lwz r6,21(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// lfs f10,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fsubs f13,f11,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 - f0.f64));
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// fsel f11,f13,f11,f0
	ctx.f11.f64 = ctx.f13.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f5,f12,f9
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f9.f64));
	// fsubs f8,f11,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fsel f7,f8,f10,f11
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f10.f64 : ctx.f11.f64;
	// fsubs f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// fdivs f30,f6,f5
	f30.f64 = double(float(ctx.f6.f64 / ctx.f5.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82164db8
	ctx.lr = 0x821E95BC;
	sub_82164DB8(ctx, base);
	// addi r3,r27,984
	ctx.r3.s64 = r27.s64 + 984;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82164db8
	ctx.lr = 0x821E95CC;
	sub_82164DB8(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// lwz r31,-12252(r5)
	r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + -12252);
	// lfs f30,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fsubs f29,f30,f29
	f29.f64 = double(float(f30.f64 - f29.f64));
	// lwz r3,1740(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1740);
	// rlwinm r11,r3,0,20,20
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e9620
	if (!cr6.eq) goto loc_821E9620;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ed368
	ctx.lr = 0x821E9620;
	sub_821ED368(ctx, base);
loc_821E9620:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fsel f12,f29,f29,f31
	ctx.f12.f64 = f29.f64 >= 0.0 ? f29.f64 : f31.f64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fsubs f11,f28,f0
	ctx.f11.f64 = double(float(f28.f64 - f0.f64));
	// lfs f13,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r28,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	f0.f64 = double(temp.f32);
	// fsubs f10,f12,f30
	ctx.f10.f64 = double(float(ctx.f12.f64 - f30.f64));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	v61.f32[0] = log2f(v62.f32[0]);
	v61.f32[1] = log2f(v62.f32[1]);
	v61.f32[2] = log2f(v62.f32[2]);
	v61.f32[3] = log2f(v62.f32[3]);
	// vmulfp128 v60,v61,v63
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// fsel f9,f10,f30,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f30.f64 : ctx.f12.f64;
	// stfs f9,940(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 940, temp.u32);
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fsel f1,f11,f7,f13
	ctx.f1.f64 = ctx.f11.f64 >= 0.0 ? ctx.f7.f64 : ctx.f13.f64;
	// stfs f1,112(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// b 0x821e96ac
	goto loc_821E96AC;
loc_821E9684:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e96ac
	if (cr6.eq) goto loc_821E96AC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x821ec468
	ctx.lr = 0x821E96A8;
	sub_821EC468(ctx, base);
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
loc_821E96AC:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e9830
	if (cr6.eq) goto loc_821E9830;
	// lfs f0,1032(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 1032);
	f0.f64 = double(temp.f32);
	// lfs f13,1028(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 1028);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x821e9830
	if (cr6.eq) goto loc_821E9830;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e9a24
	if (!cr6.eq) goto loc_821E9A24;
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f0,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fcmpu cr6,f8,f0
	cr6.compare(ctx.f8.f64, f0.f64);
	// bgt cr6,0x821e97cc
	if (cr6.gt) goto loc_821E97CC;
	// lis r10,10922
	ctx.r10.s64 = 715784192;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// ori r8,r10,43691
	ctx.r8.u64 = ctx.r10.u64 | 43691;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mulhw r6,r9,r8
	ctx.r6.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32)) >> 32;
	// srawi r11,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	r11.s64 = ctx.r6.s32 >> 1;
	// addi r5,r7,-30168
	ctx.r5.s64 = ctx.r7.s64 + -30168;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// li r4,64
	ctx.r4.s64 = 64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r10,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r10.s64;
	// bl 0x82137a08
	ctx.lr = 0x821E9750;
	sub_82137A08(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r30,r1,112
	r30.s64 = ctx.r1.s64 + 112;
	// lwz r31,-12536(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12536);
	// bl 0x821c9790
	ctx.lr = 0x821E9768;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,5
	ctx.r8.s64 = 5;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x821f4e78
	ctx.lr = 0x821E978C;
	sub_821F4E78(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// lbz r11,119(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821f7208
	ctx.lr = 0x821E97BC;
	sub_821F7208(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x821E97C8;
	// b 0x823d9240
	return;
loc_821E97CC:
	// lwz r11,4(0)
	r11.u64 = PPC_LOAD_U32(4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9818
	if (cr6.eq) goto loc_821E9818;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82148cb0
	ctx.lr = 0x821E9808;
	sub_82148CB0(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x821E9814;
	// b 0x823d9240
	return;
loc_821E9818:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82148cb0
	ctx.lr = 0x821E9820;
	sub_82148CB0(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x821E982C;
	// b 0x823d9240
	return;
loc_821E9830:
	// lbz r11,1072(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 1072);
	// addi r5,r29,4
	ctx.r5.s64 = r29.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// beq cr6,0x821e9918
	if (cr6.eq) goto loc_821E9918;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e9868
	if (!cr6.eq) goto loc_821E9868;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r4,37(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 37);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x825491f0
	ctx.lr = 0x821E9864;
	sub_825491F0(ctx, base);
	// b 0x821e98a0
	goto loc_821E98A0;
loc_821E9868:
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9898
	if (cr6.eq) goto loc_821E9898;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821e989c
	goto loc_821E989C;
loc_821E9898:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821E989C:
	// bl 0x82148cb0
	ctx.lr = 0x821E98A0;
	sub_82148CB0(ctx, base);
loc_821E98A0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e99e4
	if (!cr6.eq) goto loc_821E99E4;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,5
	ctx.r8.s64 = 5;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwz r3,-12536(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12536);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,33(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 33);
	// bl 0x821f4e78
	ctx.lr = 0x821E98D8;
	sub_821F4E78(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// lbz r11,119(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821f7208
	ctx.lr = 0x821E9908;
	sub_821F7208(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x821E9914;
	// b 0x823d9240
	return;
loc_821E9918:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e9934
	if (!cr6.eq) goto loc_821E9934;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r4,29(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 29);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x825491f0
	ctx.lr = 0x821E9930;
	sub_825491F0(ctx, base);
	// b 0x821e996c
	goto loc_821E996C;
loc_821E9934:
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9964
	if (cr6.eq) goto loc_821E9964;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821e9968
	goto loc_821E9968;
loc_821E9964:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821E9968:
	// bl 0x82148cb0
	ctx.lr = 0x821E996C;
	sub_82148CB0(ctx, base);
loc_821E996C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e99e4
	if (!cr6.eq) goto loc_821E99E4;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,5
	ctx.r8.s64 = 5;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwz r3,-12536(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12536);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,25(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 25);
	// bl 0x821f4e78
	ctx.lr = 0x821E99A4;
	sub_821F4E78(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// lbz r11,119(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9a24
	if (cr6.eq) goto loc_821E9A24;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821f7208
	ctx.lr = 0x821E99D4;
	sub_821F7208(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x821E99E0;
	// b 0x823d9240
	return;
loc_821E99E4:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9a18
	if (cr6.eq) goto loc_821E9A18;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821e9a1c
	goto loc_821E9A1C;
loc_821E9A18:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821E9A1C:
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82148cb0
	ctx.lr = 0x821E9A24;
	sub_82148CB0(ctx, base);
loc_821E9A24:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x821E9A30;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821E9A34"))) PPC_WEAK_FUNC(sub_821E9A34);
PPC_FUNC_IMPL(__imp__sub_821E9A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E9A38"))) PPC_WEAK_FUNC(sub_821E9A38);
PPC_FUNC_IMPL(__imp__sub_821E9A38) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,832(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 832);
	// addi r5,r3,832
	ctx.r5.s64 = ctx.r3.s64 + 832;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9ae0
	if (cr6.eq) goto loc_821E9AE0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,-30496(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -30496);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x821e9ac4
	if (!cr6.gt) goto loc_821E9AC4;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9aac
	if (cr6.eq) goto loc_821E9AAC;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
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
	// bl 0x82148cb0
	ctx.lr = 0x821E9A9C;
	sub_82148CB0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821E9AAC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82148cb0
	ctx.lr = 0x821E9AB4;
	sub_82148CB0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821E9AC4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213c218
	ctx.lr = 0x821E9AD0;
	sub_8213C218(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821E9AE0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r11,-30496
	ctx.r10.s64 = r11.s64 + -30496;
	// lfs f0,-30496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30496);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x821e9b6c
	if (!cr6.gt) goto loc_821E9B6C;
	// lfs f0,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,255
	ctx.r8.s64 = 255;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// stw r9,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// stb r8,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r8.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stb r7,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r7.u8);
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,18(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 18);
	// bl 0x825491f0
	ctx.lr = 0x821E9B6C;
	sub_825491F0(ctx, base);
loc_821E9B6C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821E9B7C"))) PPC_WEAK_FUNC(sub_821E9B7C);
PPC_FUNC_IMPL(__imp__sub_821E9B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E9B80"))) PPC_WEAK_FUNC(sub_821E9B80);
PPC_FUNC_IMPL(__imp__sub_821E9B80) {
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
	ctx.lr = 0x821E9B88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// lwz r11,264(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9bf0
	if (cr6.eq) goto loc_821E9BF0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9bdc
	if (cr6.eq) goto loc_821E9BDC;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821e9be0
	goto loc_821E9BE0;
loc_821E9BDC:
	// li r11,0
	r11.s64 = 0;
loc_821E9BE0:
	// stw r29,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,264(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// bl 0x821f4c18
	ctx.lr = 0x821E9BF0;
	sub_821F4C18(ctx, base);
loc_821E9BF0:
	// lwz r11,268(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9c44
	if (cr6.eq) goto loc_821E9C44;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9c30
	if (cr6.eq) goto loc_821E9C30;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821e9c34
	goto loc_821E9C34;
loc_821E9C30:
	// li r11,0
	r11.s64 = 0;
loc_821E9C34:
	// stw r29,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 268);
	// bl 0x821f4c18
	ctx.lr = 0x821E9C44;
	sub_821F4C18(ctx, base);
loc_821E9C44:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E9C4C"))) PPC_WEAK_FUNC(sub_821E9C4C);
PPC_FUNC_IMPL(__imp__sub_821E9C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E9C50"))) PPC_WEAK_FUNC(sub_821E9C50);
PPC_FUNC_IMPL(__imp__sub_821E9C50) {
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
	ctx.lr = 0x821E9C58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// lwz r11,280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9cc0
	if (cr6.eq) goto loc_821E9CC0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9cac
	if (cr6.eq) goto loc_821E9CAC;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821e9cb0
	goto loc_821E9CB0;
loc_821E9CAC:
	// li r11,0
	r11.s64 = 0;
loc_821E9CB0:
	// stw r29,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,280(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// bl 0x821f4c18
	ctx.lr = 0x821E9CC0;
	sub_821F4C18(ctx, base);
loc_821E9CC0:
	// lwz r11,284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9d14
	if (cr6.eq) goto loc_821E9D14;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9d00
	if (cr6.eq) goto loc_821E9D00;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821e9d04
	goto loc_821E9D04;
loc_821E9D00:
	// li r11,0
	r11.s64 = 0;
loc_821E9D04:
	// stw r29,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,284(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// bl 0x821f4c18
	ctx.lr = 0x821E9D14;
	sub_821F4C18(ctx, base);
loc_821E9D14:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821E9D1C"))) PPC_WEAK_FUNC(sub_821E9D1C);
PPC_FUNC_IMPL(__imp__sub_821E9D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E9D20"))) PPC_WEAK_FUNC(sub_821E9D20);
PPC_FUNC_IMPL(__imp__sub_821E9D20) {
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
	ctx.lr = 0x821E9D28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lwz r10,292(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 292);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821e9dc4
	if (!cr6.gt) goto loc_821E9DC4;
	// li r31,0
	r31.s64 = 0;
loc_821E9D50:
	// lwz r11,288(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 288);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e9db0
	if (cr6.eq) goto loc_821E9DB0;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9d98
	if (cr6.eq) goto loc_821E9D98;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821e9d9c
	goto loc_821E9D9C;
loc_821E9D98:
	// li r11,0
	r11.s64 = 0;
loc_821E9D9C:
	// stw r27,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r27.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,288(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 288);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x821f4c18
	ctx.lr = 0x821E9DB0;
	sub_821F4C18(ctx, base);
loc_821E9DB0:
	// lwz r11,292(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 292);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x821e9d50
	if (cr6.lt) goto loc_821E9D50;
loc_821E9DC4:
	// lwz r11,300(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 300);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821e9e4c
	if (!cr6.gt) goto loc_821E9E4C;
	// li r31,0
	r31.s64 = 0;
loc_821E9DD8:
	// lwz r11,296(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 296);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821e9e38
	if (cr6.eq) goto loc_821E9E38;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9e20
	if (cr6.eq) goto loc_821E9E20;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821e9e24
	goto loc_821E9E24;
loc_821E9E20:
	// li r11,0
	r11.s64 = 0;
loc_821E9E24:
	// stw r27,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r27.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,296(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 296);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x821f4c18
	ctx.lr = 0x821E9E38;
	sub_821F4C18(ctx, base);
loc_821E9E38:
	// lwz r11,300(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 300);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x821e9dd8
	if (cr6.lt) goto loc_821E9DD8;
loc_821E9E4C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821E9E54"))) PPC_WEAK_FUNC(sub_821E9E54);
PPC_FUNC_IMPL(__imp__sub_821E9E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E9E58"))) PPC_WEAK_FUNC(sub_821E9E58);
PPC_FUNC_IMPL(__imp__sub_821E9E58) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x821E9E60;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r3,160
	r30.s64 = ctx.r3.s64 + 160;
	// li r27,2
	r27.s64 = 2;
	// lfs f31,-31400(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	f31.f64 = double(temp.f32);
	// li r28,0
	r28.s64 = 0;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_821E9E88:
	// lwz r11,-4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9ee4
	if (cr6.eq) goto loc_821E9EE4;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// ble cr6,0x821e9ed8
	if (!cr6.gt) goto loc_821E9ED8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9ed0
	if (cr6.eq) goto loc_821E9ED0;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821e9ed4
	goto loc_821E9ED4;
loc_821E9ED0:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_821E9ED4:
	// stw r29,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r29.u32);
loc_821E9ED8:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// bl 0x821f4c18
	ctx.lr = 0x821E9EE4;
	sub_821F4C18(ctx, base);
loc_821E9EE4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821e9f3c
	if (cr6.eq) goto loc_821E9F3C;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// ble cr6,0x821e9f30
	if (!cr6.gt) goto loc_821E9F30;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821e9f28
	if (cr6.eq) goto loc_821E9F28;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821e9f2c
	goto loc_821E9F2C;
loc_821E9F28:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_821E9F2C:
	// stw r29,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r29.u32);
loc_821E9F30:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8213c218
	ctx.lr = 0x821E9F3C;
	sub_8213C218(ctx, base);
loc_821E9F3C:
	// stfs f31,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821e9f60
	if (cr6.eq) goto loc_821E9F60;
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821e9f60
	if (!cr6.eq) goto loc_821E9F60;
	// bl 0x821f6c50
	ctx.lr = 0x821E9F60;
	sub_821F6C50(ctx, base);
loc_821E9F60:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// bne 0x821e9e88
	if (!cr0.eq) goto loc_821E9E88;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821e9f90
	if (cr6.eq) goto loc_821E9F90;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x821ec468
	ctx.lr = 0x821E9F90;
	sub_821EC468(ctx, base);
loc_821E9F90:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821E9F9C"))) PPC_WEAK_FUNC(sub_821E9F9C);
PPC_FUNC_IMPL(__imp__sub_821E9F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821E9FA0"))) PPC_WEAK_FUNC(sub_821E9FA0);
PPC_FUNC_IMPL(__imp__sub_821E9FA0) {
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
	ctx.lr = 0x821E9FA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// mr r30,r28
	r30.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c8f08
	ctx.lr = 0x821E9FC4;
	sub_821C8F08(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
loc_821E9FC8:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x821e9ff0
	if (!cr6.eq) goto loc_821E9FF0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// stw r28,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ea050
	if (!cr6.eq) goto loc_821EA050;
	// li r30,1
	r30.s64 = 1;
loc_821E9FF0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821e9fc8
	if (cr6.eq) goto loc_821E9FC8;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stbx r8,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r8.u8);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// stw r7,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r7.u32);
	// lwz r30,48(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821c8f70
	ctx.lr = 0x821EA034;
	sub_821C8F70(ctx, base);
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r30,r11
	ctx.r6.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r6,7,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821EA050:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c8f70
	ctx.lr = 0x821EA058;
	sub_821C8F70(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821EA064"))) PPC_WEAK_FUNC(sub_821EA064);
PPC_FUNC_IMPL(__imp__sub_821EA064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EA068"))) PPC_WEAK_FUNC(sub_821EA068);
PPC_FUNC_IMPL(__imp__sub_821EA068) {
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
	ctx.lr = 0x821EA070;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r31,204
	r29.s64 = r31.s64 + 204;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c8f08
	ctx.lr = 0x821EA08C;
	sub_821C8F08(ctx, base);
	// lhz r5,200(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 200);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x821ea0fc
	if (!cr6.gt) goto loc_821EA0FC;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_821EA0A0:
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_821EA0AC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r4,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r4.s64;
	// beq cr6,0x821ea0d0
	if (cr6.eq) goto loc_821EA0D0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821ea0ac
	if (cr6.eq) goto loc_821EA0AC;
loc_821EA0D0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821ea0f8
	if (cr6.eq) goto loc_821EA0F8;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// blt cr6,0x821ea0a0
	if (cr6.lt) goto loc_821EA0A0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c8f70
	ctx.lr = 0x821EA0F0;
	sub_821C8F70(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821EA0F8:
	// stb r28,264(r7)
	PPC_STORE_U8(ctx.r7.u32 + 264, r28.u8);
loc_821EA0FC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c8f70
	ctx.lr = 0x821EA104;
	sub_821C8F70(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821EA10C"))) PPC_WEAK_FUNC(sub_821EA10C);
PPC_FUNC_IMPL(__imp__sub_821EA10C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EA110"))) PPC_WEAK_FUNC(sub_821EA110);
PPC_FUNC_IMPL(__imp__sub_821EA110) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x821EA118;
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,1024(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1024);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lwz r9,10(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x821ea160
	if (cr6.gt) goto loc_821EA160;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// b 0x821ea1cc
	goto loc_821EA1CC;
loc_821EA160:
	// lwz r11,14(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x821ea184
	if (cr6.lt) goto loc_821EA184;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f30,f31
	f30.f64 = f31.f64;
	// lfs f29,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f29.f64 = double(temp.f32);
	// b 0x821ea1cc
	goto loc_821EA1CC;
loc_821EA184:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r31,864
	ctx.r3.s64 = r31.s64 + 864;
	// lwz r10,14(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// lwz r9,10(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lfs f11,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fdivs f29,f12,f10
	f29.f64 = double(float(ctx.f12.f64 / ctx.f10.f64));
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x82164db8
	ctx.lr = 0x821EA1B8;
	sub_82164DB8(ctx, base);
	// addi r3,r31,904
	ctx.r3.s64 = r31.s64 + 904;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x82164db8
	ctx.lr = 0x821EA1C8;
	sub_82164DB8(ctx, base);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
loc_821EA1CC:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f30,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r30,-32254
	r30.s64 = -2113798144;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r29,r30,-30496
	r29.s64 = r30.s64 + -30496;
	// lwz r3,840(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 840);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	v62.f32[0] = log2f(v63.f32[0]);
	v62.f32[1] = log2f(v63.f32[1]);
	v62.f32[2] = log2f(v63.f32[2]);
	v62.f32[3] = log2f(v63.f32[3]);
	// lvx128 v63,r29,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vmulfp128 v61,v62,v63
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsubs f13,f30,f0
	ctx.f13.f64 = double(float(f30.f64 - f0.f64));
	// lfs f0,-30496(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -30496);
	f0.f64 = double(temp.f32);
	// lfs f30,11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	f30.f64 = double(temp.f32);
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fsel f1,f13,f11,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// bl 0x82547c58
	ctx.lr = 0x821EA228;
	sub_82547C58(ctx, base);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f29,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r6,16
	ctx.r6.s64 = 16;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsubs f10,f29,f0
	ctx.f10.f64 = double(float(f29.f64 - f0.f64));
	// lfs f0,-30496(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -30496);
	f0.f64 = double(temp.f32);
	// lvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	v59.f32[0] = log2f(v60.f32[0]);
	v59.f32[1] = log2f(v60.f32[1]);
	v59.f32[2] = log2f(v60.f32[2]);
	v59.f32[3] = log2f(v60.f32[3]);
	// lvx128 v63,r29,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v59,v63
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f30
	ctx.f8.f64 = double(float(ctx.f9.f64 * f30.f64));
	// fsel f1,f10,f8,f0
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// bl 0x821e9a38
	ctx.lr = 0x821EA274;
	sub_821E9A38(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

__attribute__((alias("__imp__sub_821EA288"))) PPC_WEAK_FUNC(sub_821EA288);
PPC_FUNC_IMPL(__imp__sub_821EA288) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x821EA290;
	// stfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f29.u64);
	// stfd f30,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, f30.u64);
	// stfd f31,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x821e67b8
	ctx.lr = 0x821EA2A8;
	sub_821E67B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ea7dc
	if (!cr6.eq) goto loc_821EA7DC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r25,r28,204
	r25.s64 = r28.s64 + 204;
	// li r24,0
	r24.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r23,r24
	r23.u64 = r24.u64;
	// lfs f29,-31400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f29.f64 = double(temp.f32);
	// mr r21,r24
	r21.u64 = r24.u64;
	// fmr f30,f29
	f30.f64 = f29.f64;
	// mr r20,r24
	r20.u64 = r24.u64;
	// fmr f31,f29
	f31.f64 = f29.f64;
	// bl 0x821c8f08
	ctx.lr = 0x821EA2E0;
	sub_821C8F08(ctx, base);
	// lhz r10,200(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 200);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r19,-32114
	r19.s64 = -2104623104;
	// mr r26,r24
	r26.u64 = r24.u64;
	// addi r22,r11,-12352
	r22.s64 = r11.s64 + -12352;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ea540
	if (cr6.eq) goto loc_821EA540;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_821EA300:
	// lwz r11,196(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// lwzx r11,r29,r11
	r11.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lbz r10,264(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 264);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ea52c
	if (!cr6.eq) goto loc_821EA52C;
	// lhz r11,260(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 260);
	// mr r27,r24
	r27.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ea52c
	if (cr6.eq) goto loc_821EA52C;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_821EA328:
	// lwz r11,196(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// lbz r10,1077(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1077);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwzx r9,r29,r11
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lwz r8,256(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 256);
	// lwzx r11,r8,r30
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,10
	ctx.r10.s64 = ctx.r10.s64 + 10;
	// beq cr6,0x821ea35c
	if (cr6.eq) goto loc_821EA35C;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rlwinm r8,r9,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821ea510
	if (cr6.eq) goto loc_821EA510;
loc_821EA35C:
	// lbz r9,1072(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 1072);
	// lwz r8,-32452(r19)
	ctx.r8.u64 = PPC_LOAD_U32(r19.u32 + -32452);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821ea3d4
	if (cr6.eq) goto loc_821EA3D4;
	// lwz r9,33(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 33);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x821ea43c
	if (!cr6.eq) goto loc_821EA43C;
	// mr r11,r24
	r11.u64 = r24.u64;
	// addi r31,r28,156
	r31.s64 = r28.s64 + 156;
loc_821EA380:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x821ea3a0
	if (cr6.eq) goto loc_821EA3A0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x821ea380
	if (cr6.lt) goto loc_821EA380;
	// b 0x821ea510
	goto loc_821EA510;
loc_821EA3A0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea3b4
	if (cr6.eq) goto loc_821EA3B4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EA3B4;
	sub_821F4C18(ctx, base);
loc_821EA3B4:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea3c8
	if (cr6.eq) goto loc_821EA3C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EA3C8;
	sub_8213C218(ctx, base);
loc_821EA3C8:
	// stfs f29,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// b 0x821ea510
	goto loc_821EA510;
loc_821EA3D4:
	// lwz r9,25(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 25);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x821ea43c
	if (!cr6.eq) goto loc_821EA43C;
	// mr r11,r24
	r11.u64 = r24.u64;
	// addi r31,r28,156
	r31.s64 = r28.s64 + 156;
loc_821EA3E8:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x821ea408
	if (cr6.eq) goto loc_821EA408;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x821ea3e8
	if (cr6.lt) goto loc_821EA3E8;
	// b 0x821ea510
	goto loc_821EA510;
loc_821EA408:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea41c
	if (cr6.eq) goto loc_821EA41C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EA41C;
	sub_821F4C18(ctx, base);
loc_821EA41C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea3c8
	if (cr6.eq) goto loc_821EA3C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EA430;
	sub_8213C218(ctx, base);
	// stfs f29,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// b 0x821ea510
	goto loc_821EA510;
loc_821EA43C:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r9,17(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17);
	// lfs f13,52(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,56(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,48(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 48);
	ctx.f7.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// lfs f5,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f5
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fmuls f3,f12,f12
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f2,f9,f9,f3
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f3.f64));
	// fmadds f0,f6,f6,f2
	f0.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f2.f64));
	// fcmpu cr6,f0,f4
	cr6.compare(f0.f64, ctx.f4.f64);
	// ble cr6,0x821ea4e0
	if (!cr6.gt) goto loc_821EA4E0;
	// mr r11,r24
	r11.u64 = r24.u64;
	// addi r31,r28,156
	r31.s64 = r28.s64 + 156;
loc_821EA48C:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x821ea4ac
	if (cr6.eq) goto loc_821EA4AC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x821ea48c
	if (cr6.lt) goto loc_821EA48C;
	// b 0x821ea510
	goto loc_821EA510;
loc_821EA4AC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea4c0
	if (cr6.eq) goto loc_821EA4C0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EA4C0;
	sub_821F4C18(ctx, base);
loc_821EA4C0:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea3c8
	if (cr6.eq) goto loc_821EA3C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EA4D4;
	sub_8213C218(ctx, base);
	// stfs f29,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// b 0x821ea510
	goto loc_821EA510;
loc_821EA4E0:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x821ea500
	if (!cr6.lt) goto loc_821EA500;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// mr r21,r23
	r21.u64 = r23.u64;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// li r20,1
	r20.s64 = 1;
	// b 0x821ea510
	goto loc_821EA510;
loc_821EA500:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x821ea510
	if (!cr6.lt) goto loc_821EA510;
	// fmr f31,f0
	f31.f64 = f0.f64;
	// mr r21,r10
	r21.u64 = ctx.r10.u64;
loc_821EA510:
	// lwz r11,196(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lhz r9,260(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 260);
	// cmpw cr6,r27,r9
	cr6.compare<int32_t>(r27.s32, ctx.r9.s32, xer);
	// blt cr6,0x821ea328
	if (cr6.lt) goto loc_821EA328;
loc_821EA52C:
	// lhz r11,200(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 200);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x821ea300
	if (cr6.lt) goto loc_821EA300;
loc_821EA540:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c8f70
	ctx.lr = 0x821EA548;
	sub_821C8F70(ctx, base);
	// lwz r11,252(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 252);
	// lbz r29,-1(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821ea768
	if (cr6.eq) goto loc_821EA768;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_821EA55C:
	// lwz r11,252(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 252);
	// mulli r10,r30,41
	ctx.r10.s64 = r30.s64 * 41;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821ea610
	if (cr6.eq) goto loc_821EA610;
	// lfs f0,1028(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 1028);
	f0.f64 = double(temp.f32);
	// lfs f13,1032(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 1032);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x821ea754
	if (cr6.eq) goto loc_821EA754;
loc_821EA588:
	// lwz r7,9(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 9);
	// lfs f0,52(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r22.u32 + 52);
	f0.f64 = double(temp.f32);
	// lwz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 1);
	// lfs f13,56(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,17(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 17);
	// lfs f12,48(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 5);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lfs f9,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// lfs f7,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f5,f0,f7
	ctx.f5.f64 = double(float(f0.f64 - ctx.f7.f64));
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fmuls f3,f5,f5
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fsubs f6,f12,f11
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fmuls f4,f10,f10
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f2,f8,f8,f3
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f3.f64));
	// fmadds f0,f6,f6,f2
	f0.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f2.f64));
	// fcmpu cr6,f0,f4
	cr6.compare(f0.f64, ctx.f4.f64);
	// ble cr6,0x821ea724
	if (!cr6.gt) goto loc_821EA724;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// addi r31,r28,156
	r31.s64 = r28.s64 + 156;
loc_821EA5F0:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x821ea6f0
	if (cr6.eq) goto loc_821EA6F0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blt cr6,0x821ea5f0
	if (cr6.lt) goto loc_821EA5F0;
	// b 0x821ea754
	goto loc_821EA754;
loc_821EA610:
	// lbz r10,1072(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1072);
	// lwz r9,-32452(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + -32452);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ea688
	if (cr6.eq) goto loc_821EA688;
	// lwz r10,33(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 33);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x821ea588
	if (!cr6.eq) goto loc_821EA588;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// addi r31,r28,156
	r31.s64 = r28.s64 + 156;
loc_821EA634:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x821ea654
	if (cr6.eq) goto loc_821EA654;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blt cr6,0x821ea634
	if (cr6.lt) goto loc_821EA634;
	// b 0x821ea754
	goto loc_821EA754;
loc_821EA654:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea668
	if (cr6.eq) goto loc_821EA668;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EA668;
	sub_821F4C18(ctx, base);
loc_821EA668:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea67c
	if (cr6.eq) goto loc_821EA67C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EA67C;
	sub_8213C218(ctx, base);
loc_821EA67C:
	// stfs f29,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// b 0x821ea754
	goto loc_821EA754;
loc_821EA688:
	// lwz r10,25(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x821ea588
	if (!cr6.eq) goto loc_821EA588;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// addi r31,r28,156
	r31.s64 = r28.s64 + 156;
loc_821EA69C:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x821ea6bc
	if (cr6.eq) goto loc_821EA6BC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blt cr6,0x821ea69c
	if (cr6.lt) goto loc_821EA69C;
	// b 0x821ea754
	goto loc_821EA754;
loc_821EA6BC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea6d0
	if (cr6.eq) goto loc_821EA6D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EA6D0;
	sub_821F4C18(ctx, base);
loc_821EA6D0:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea67c
	if (cr6.eq) goto loc_821EA67C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EA6E4;
	sub_8213C218(ctx, base);
	// stfs f29,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// b 0x821ea754
	goto loc_821EA754;
loc_821EA6F0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea704
	if (cr6.eq) goto loc_821EA704;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EA704;
	sub_821F4C18(ctx, base);
loc_821EA704:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea67c
	if (cr6.eq) goto loc_821EA67C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EA718;
	sub_8213C218(ctx, base);
	// stfs f29,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// b 0x821ea754
	goto loc_821EA754;
loc_821EA724:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x821ea744
	if (!cr6.lt) goto loc_821EA744;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// mr r21,r23
	r21.u64 = r23.u64;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// mr r23,r11
	r23.u64 = r11.u64;
	// mr r20,r24
	r20.u64 = r24.u64;
	// b 0x821ea754
	goto loc_821EA754;
loc_821EA744:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x821ea754
	if (!cr6.lt) goto loc_821EA754;
	// fmr f31,f0
	f31.f64 = f0.f64;
	// mr r21,r11
	r21.u64 = r11.u64;
loc_821EA754:
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x821ea55c
	if (cr6.lt) goto loc_821EA55C;
loc_821EA768:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,17,17
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821ea798
	if (!cr6.eq) goto loc_821EA798;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,1748(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1748);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-30124(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30124);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x821ea79c
	if (cr6.lt) goto loc_821EA79C;
loc_821EA798:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_821EA79C:
	// clrlwi r9,r20,24
	ctx.r9.u64 = r20.u32 & 0xFF;
	// and r30,r9,r11
	r30.u64 = ctx.r9.u64 & r11.u64;
	// clrlwi r8,r30,24
	ctx.r8.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821ea7c8
	if (!cr6.eq) goto loc_821EA7C8;
	// rlwinm r11,r10,0,20,20
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ea7c8
	if (cr6.eq) goto loc_821EA7C8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x821ec468
	ctx.lr = 0x821EA7C8;
	sub_821EC468(ctx, base);
loc_821EA7C8:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x821ea7fc
	if (!cr6.eq) goto loc_821EA7FC;
	// lwz r11,260(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ea954
	if (!cr6.eq) goto loc_821EA954;
loc_821EA7DC:
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821e9e58
	ctx.lr = 0x821EA7E8;
	sub_821E9E58(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_821EA7FC:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bne cr6,0x821ea814
	if (!cr6.eq) goto loc_821EA814;
	// bl 0x821e8388
	ctx.lr = 0x821EA810;
	sub_821E8388(ctx, base);
	// b 0x821ea81c
	goto loc_821EA81C;
loc_821EA814:
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// bl 0x821e82f8
	ctx.lr = 0x821EA81C;
	sub_821E82F8(ctx, base);
loc_821EA81C:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821e8258
	ctx.lr = 0x821EA82C;
	sub_821E8258(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821ea954
	if (cr6.eq) goto loc_821EA954;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stfs f30,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// cmplw cr6,r11,r23
	cr6.compare<uint32_t>(r11.u32, r23.u32, xer);
	// bne cr6,0x821ea864
	if (!cr6.eq) goto loc_821EA864;
	// lbz r10,1073(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1073);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ea88c
	if (cr6.eq) goto loc_821EA88C;
	// lwz r10,25(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25);
	// lwz r9,33(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 33);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x821ea88c
	if (cr6.eq) goto loc_821EA88C;
loc_821EA864:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea878
	if (cr6.eq) goto loc_821EA878;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EA878;
	sub_821F4C18(ctx, base);
loc_821EA878:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea88c
	if (cr6.eq) goto loc_821EA88C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EA88C;
	sub_8213C218(ctx, base);
loc_821EA88C:
	// stw r23,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r23.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fsqrts f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(sqrt(f30.f64)));
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821e9390
	ctx.lr = 0x821EA8A4;
	sub_821E9390(ctx, base);
	// lwz r11,260(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 260);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x821ea8b4
	if (!cr6.eq) goto loc_821EA8B4;
	// stw r24,260(r28)
	PPC_STORE_U32(r28.u32 + 260, r24.u32);
loc_821EA8B4:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x821ea954
	if (cr6.eq) goto loc_821EA954;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821e8258
	ctx.lr = 0x821EA8CC;
	sub_821E8258(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821ea954
	if (cr6.eq) goto loc_821EA954;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stfs f31,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// cmplw cr6,r11,r21
	cr6.compare<uint32_t>(r11.u32, r21.u32, xer);
	// bne cr6,0x821ea904
	if (!cr6.eq) goto loc_821EA904;
	// lbz r10,1073(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1073);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ea92c
	if (cr6.eq) goto loc_821EA92C;
	// lwz r10,25(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25);
	// lwz r9,33(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 33);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x821ea92c
	if (cr6.eq) goto loc_821EA92C;
loc_821EA904:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea918
	if (cr6.eq) goto loc_821EA918;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EA918;
	sub_821F4C18(ctx, base);
loc_821EA918:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ea92c
	if (cr6.eq) goto loc_821EA92C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EA92C;
	sub_8213C218(ctx, base);
loc_821EA92C:
	// stw r21,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r21.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fsqrts f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(sqrt(f31.f64)));
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821e9390
	ctx.lr = 0x821EA944;
	sub_821E9390(ctx, base);
	// lwz r11,260(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 260);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x821ea954
	if (!cr6.eq) goto loc_821EA954;
	// stw r24,260(r28)
	PPC_STORE_U32(r28.u32 + 260, r24.u32);
loc_821EA954:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f29,-136(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f30,-128(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_821EA968"))) PPC_WEAK_FUNC(sub_821EA968);
PPC_FUNC_IMPL(__imp__sub_821EA968) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x821EA970;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821eacc4
	if (cr6.eq) goto loc_821EACC4;
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x821ea9a0
	if (!cr6.eq) goto loc_821EA9A0;
	// lbz r11,1073(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1073);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eacc4
	if (cr6.eq) goto loc_821EACC4;
loc_821EA9A0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r24,r11,19856
	r24.s64 = r11.s64 + 19856;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82144a18
	ctx.lr = 0x821EA9B0;
	sub_82144A18(ctx, base);
	// lwz r11,828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 828);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x821eacc4
	if (cr6.lt) goto loc_821EACC4;
	// addi r11,r30,60
	r11.s64 = r30.s64 + 60;
	// lwz r8,140(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
	// clrlwi r7,r29,24
	ctx.r7.u64 = r29.u32 & 0xFF;
	// stw r11,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r11.u32);
	// lbz r10,59(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 59);
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,244(r31)
	PPC_STORE_U32(r31.u32 + 244, ctx.r10.u32);
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// mulli r11,r5,19
	r11.s64 = ctx.r5.s64 * 19;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,248(r31)
	PPC_STORE_U32(r31.u32 + 248, ctx.r10.u32);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// mulli r11,r4,19
	r11.s64 = ctx.r4.s64 * 19;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// lbz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// mulli r11,r3,41
	r11.s64 = ctx.r3.s64 * 41;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// beq cr6,0x821eacbc
	if (cr6.eq) goto loc_821EACBC;
	// lwz r3,304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// addi r29,r31,304
	r29.s64 = r31.s64 + 304;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821eaa60
	if (cr6.eq) goto loc_821EAA60;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821eaa60
	if (cr6.eq) goto loc_821EAA60;
	// lwz r11,26(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 26);
	// lwz r10,26(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 26);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x821eaa60
	if (cr6.eq) goto loc_821EAA60;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x821EAA60;
	sub_821EC060(ctx, base);
loc_821EAA60:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eaa90
	if (!cr6.eq) goto loc_821EAA90;
	// lwz r4,26(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 26);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821eaa90
	if (cr6.eq) goto loc_821EAA90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee790
	ctx.lr = 0x821EAA90;
	sub_821EE790(ctx, base);
loc_821EAA90:
	// lbz r11,1072(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1072);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eaaa4
	if (cr6.eq) goto loc_821EAAA4;
	// lwz r29,14(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 14);
	// b 0x821eaaa8
	goto loc_821EAAA8;
loc_821EAAA4:
	// lwz r29,10(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 10);
loc_821EAAA8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eaab8
	if (cr6.eq) goto loc_821EAAB8;
	// lwz r26,22(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 22);
	// b 0x821eaabc
	goto loc_821EAABC;
loc_821EAAB8:
	// lwz r26,18(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 18);
loc_821EAABC:
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r25,-32114
	r25.s64 = -2104623104;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// beq cr6,0x821eac08
	if (cr6.eq) goto loc_821EAC08;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821e8080
	ctx.lr = 0x821EAADC;
	sub_821E8080(ctx, base);
	// lbz r10,166(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 166);
	// li r12,219
	r12.s64 = 219;
	// li r11,1
	r11.s64 = 1;
	// and r9,r10,r12
	ctx.r9.u64 = ctx.r10.u64 & r12.u64;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// li r4,90
	ctx.r4.s64 = 90;
	// ori r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 | 32;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r8,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r8.u8);
	// bl 0x82145020
	ctx.lr = 0x821EAB04;
	sub_82145020(ctx, base);
	// lbz r6,166(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 166);
	// lwz r11,264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// addi r30,r31,264
	r30.s64 = r31.s64 + 264;
	// ori r5,r6,64
	ctx.r5.u64 = ctx.r6.u64 | 64;
	// stw r3,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r5,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r5.u8);
	// beq cr6,0x821eaba4
	if (cr6.eq) goto loc_821EABA4;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,58(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 58);
	// lfs f0,11364(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11364);
	f0.f64 = double(temp.f32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r7,r10,1000
	ctx.r7.s64 = ctx.r10.s64 + 1000;
	// stw r10,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r10.u32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821eab90
	if (cr6.eq) goto loc_821EAB90;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lbz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r6,r9,7216
	ctx.r6.s64 = ctx.r9.s64 + 7216;
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// lwz r9,232(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 232);
	// lwz r11,200(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 200);
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11444(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821eab94
	goto loc_821EAB94;
loc_821EAB90:
	// li r11,0
	r11.s64 = 0;
loc_821EAB94:
	// stw r7,192(r11)
	PPC_STORE_U32(r11.u32 + 192, ctx.r7.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821f4c18
	ctx.lr = 0x821EABA4;
	sub_821F4C18(ctx, base);
loc_821EABA4:
	// lwz r11,-12512(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -12512);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-12548(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12548);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// bl 0x821f4e78
	ctx.lr = 0x821EABD0;
	sub_821F4E78(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eac00
	if (cr6.eq) goto loc_821EAC00;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821EABF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r29.u32);
	// b 0x821eac08
	goto loc_821EAC08;
loc_821EAC00:
	// lwz r11,-32452(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -32452);
	// stw r11,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r11.u32);
loc_821EAC08:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// beq cr6,0x821eaca0
	if (cr6.eq) goto loc_821EACA0;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// li r3,0
	ctx.r3.s64 = 0;
	// ori r4,r4,24464
	ctx.r4.u64 = ctx.r4.u64 | 24464;
	// bl 0x82145020
	ctx.lr = 0x821EAC24;
	sub_82145020(ctx, base);
	// lwz r3,268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// addi r30,r31,268
	r30.s64 = r31.s64 + 268;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821eac3c
	if (cr6.eq) goto loc_821EAC3C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821f4c18
	ctx.lr = 0x821EAC3C;
	sub_821F4C18(ctx, base);
loc_821EAC3C:
	// lwz r11,-12512(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -12512);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-12548(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12548);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// bl 0x821f4e78
	ctx.lr = 0x821EAC68;
	sub_821F4E78(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eac98
	if (cr6.eq) goto loc_821EAC98;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821EAC90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r26,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r26.u32);
	// b 0x821eaca0
	goto loc_821EACA0;
loc_821EAC98:
	// lwz r11,-32452(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -32452);
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
loc_821EACA0:
	// li r4,750
	ctx.r4.s64 = 750;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e9d20
	ctx.lr = 0x821EACAC;
	sub_821E9D20(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82144a18
	ctx.lr = 0x821EACB4;
	sub_82144A18(ctx, base);
	// addi r11,r3,4000
	r11.s64 = ctx.r3.s64 + 4000;
	// stw r11,828(r31)
	PPC_STORE_U32(r31.u32 + 828, r11.u32);
loc_821EACBC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e8178
	ctx.lr = 0x821EACC4;
	sub_821E8178(ctx, base);
loc_821EACC4:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821EACCC"))) PPC_WEAK_FUNC(sub_821EACCC);
PPC_FUNC_IMPL(__imp__sub_821EACCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EACD0"))) PPC_WEAK_FUNC(sub_821EACD0);
PPC_FUNC_IMPL(__imp__sub_821EACD0) {
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
	ctx.lr = 0x821EACD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// stw r30,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r30.u32);
	// addi r11,r31,256
	r11.s64 = r31.s64 + 256;
	// sth r30,260(r31)
	PPC_STORE_U16(r31.u32 + 260, r30.u16);
	// sth r30,262(r31)
	PPC_STORE_U16(r31.u32 + 262, r30.u16);
	// bl 0x82137a08
	ctx.lr = 0x821EAD04;
	sub_82137A08(ctx, base);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x82137a08
	ctx.lr = 0x821EAD14;
	sub_82137A08(ctx, base);
	// stb r30,264(r31)
	PPC_STORE_U8(r31.u32 + 264, r30.u8);
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x821EAD20;
	sub_82130528(ctx, base);
	// li r11,10
	r11.s64 = 10;
	// stw r3,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,262(r31)
	PPC_STORE_U16(r31.u32 + 262, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821EAD38"))) PPC_WEAK_FUNC(sub_821EAD38);
PPC_FUNC_IMPL(__imp__sub_821EAD38) {
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
	ctx.lr = 0x821EAD40;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,260(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ead7c
	if (cr6.eq) goto loc_821EAD7C;
	// li r31,0
	r31.s64 = 0;
loc_821EAD5C:
	// lwz r11,256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 256);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82130588
	ctx.lr = 0x821EAD68;
	sub_82130588(ctx, base);
	// lhz r10,260(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 260);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x821ead5c
	if (cr6.lt) goto loc_821EAD5C;
loc_821EAD7C:
	// lhz r11,262(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 262);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ead90
	if (cr6.eq) goto loc_821EAD90;
	// lwz r3,256(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 256);
	// bl 0x82130588
	ctx.lr = 0x821EAD90;
	sub_82130588(ctx, base);
loc_821EAD90:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821EAD98"))) PPC_WEAK_FUNC(sub_821EAD98);
PPC_FUNC_IMPL(__imp__sub_821EAD98) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x821EADA0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82548ba8
	ctx.lr = 0x821EADAC;
	sub_82548BA8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// addi r4,r10,-29956
	ctx.r4.s64 = ctx.r10.s64 + -29956;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82144a20
	ctx.lr = 0x821EADC4;
	sub_82144A20(ctx, base);
	// addi r24,r31,12
	r24.s64 = r31.s64 + 12;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823d9890
	ctx.lr = 0x821EADDC;
	sub_823D9890(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r25,0
	r25.s64 = 0;
	// lbz r8,70(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 70);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821eae30
	if (cr6.eq) goto loc_821EAE30;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_821EADF4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r4,71(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 71);
	// bl 0x82144a28
	ctx.lr = 0x821EAE0C;
	sub_82144A28(ctx, base);
	// addi r10,r30,3
	ctx.r10.s64 = r30.s64 + 3;
	// addi r9,r30,1
	ctx.r9.s64 = r30.s64 + 1;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r30,r9,24
	r30.u64 = ctx.r9.u32 & 0xFF;
	// stwx r3,r8,r31
	PPC_STORE_U32(ctx.r8.u32 + r31.u32, ctx.r3.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lbz r6,70(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 70);
	// cmplw cr6,r30,r6
	cr6.compare<uint32_t>(r30.u32, ctx.r6.u32, xer);
	// blt cr6,0x821eadf4
	if (cr6.lt) goto loc_821EADF4;
loc_821EAE30:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r31,864
	ctx.r3.s64 = r31.s64 + 864;
	// lwz r4,50(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 50);
	// bl 0x82164840
	ctx.lr = 0x821EAE40;
	sub_82164840(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r31,904
	ctx.r3.s64 = r31.s64 + 904;
	// lwz r4,54(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 54);
	// bl 0x82164840
	ctx.lr = 0x821EAE50;
	sub_82164840(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r3,r31,984
	ctx.r3.s64 = r31.s64 + 984;
	// addi r4,r9,-29984
	ctx.r4.s64 = ctx.r9.s64 + -29984;
	// bl 0x82164d78
	ctx.lr = 0x821EAE60;
	sub_82164D78(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r3,r31,944
	ctx.r3.s64 = r31.s64 + 944;
	// addi r4,r8,-30012
	ctx.r4.s64 = ctx.r8.s64 + -30012;
	// bl 0x82164d78
	ctx.lr = 0x821EAE70;
	sub_82164D78(ctx, base);
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-30024
	ctx.r4.s64 = ctx.r7.s64 + -30024;
	// lwz r3,-32456(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -32456);
	// bl 0x82547a80
	ctx.lr = 0x821EAE84;
	sub_82547A80(ctx, base);
	// stw r3,840(r31)
	PPC_STORE_U32(r31.u32 + 840, ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,-32456(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -32456);
	// addi r4,r6,-30052
	ctx.r4.s64 = ctx.r6.s64 + -30052;
	// bl 0x82547a80
	ctx.lr = 0x821EAE98;
	sub_82547A80(ctx, base);
	// stw r3,844(r31)
	PPC_STORE_U32(r31.u32 + 844, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-32456(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -32456);
	// addi r4,r5,-30084
	ctx.r4.s64 = ctx.r5.s64 + -30084;
	// bl 0x82547a80
	ctx.lr = 0x821EAEAC;
	sub_82547A80(ctx, base);
	// stw r3,848(r31)
	PPC_STORE_U32(r31.u32 + 848, ctx.r3.u32);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,-30100
	ctx.r3.s64 = ctx.r3.s64 + -30100;
	// bl 0x821c9790
	ctx.lr = 0x821EAEC0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8214a200
	ctx.lr = 0x821EAECC;
	sub_8214A200(ctx, base);
	// stw r3,852(r31)
	PPC_STORE_U32(r31.u32 + 852, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-30120
	ctx.r3.s64 = r11.s64 + -30120;
	// bl 0x821c9790
	ctx.lr = 0x821EAEE0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8214a200
	ctx.lr = 0x821EAEEC;
	sub_8214A200(ctx, base);
	// stw r3,856(r31)
	PPC_STORE_U32(r31.u32 + 856, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-31264
	ctx.r3.s64 = ctx.r10.s64 + -31264;
	// bl 0x821c9790
	ctx.lr = 0x821EAF00;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8214a200
	ctx.lr = 0x821EAF0C;
	sub_8214A200(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r3,860(r31)
	PPC_STORE_U32(r31.u32 + 860, ctx.r3.u32);
	// addi r30,r31,172
	r30.s64 = r31.s64 + 172;
	// li r29,2
	r29.s64 = 2;
	// li r27,1
	r27.s64 = 1;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// addi r26,r11,27108
	r26.s64 = r11.s64 + 27108;
loc_821EAF28:
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eaf68
	if (!cr6.eq) goto loc_821EAF68;
	// lwz r3,27136(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 27136);
	// bl 0x821e9fa0
	ctx.lr = 0x821EAF3C;
	sub_821E9FA0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821eaf50
	if (cr6.eq) goto loc_821EAF50;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f6cd8
	ctx.lr = 0x821EAF4C;
	sub_821F6CD8(ctx, base);
	// b 0x821eaf54
	goto loc_821EAF54;
loc_821EAF50:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_821EAF54:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821624d0
	ctx.lr = 0x821EAF60;
	sub_821624D0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r27,116(r11)
	PPC_STORE_U8(r11.u32 + 116, r27.u8);
loc_821EAF68:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// bne 0x821eaf28
	if (!cr0.eq) goto loc_821EAF28;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,38(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 38);
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82145080
	ctx.lr = 0x821EAF90;
	sub_82145080(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stfs f1,824(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 824, temp.u32);
	// stw r25,828(r31)
	PPC_STORE_U32(r31.u32 + 828, r25.u32);
	// lwz r11,-12548(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12548);
	// lis r7,16383
	ctx.r7.s64 = 1073676288;
	// li r29,-1
	r29.s64 = -1;
	// ori r30,r7,65535
	r30.u64 = ctx.r7.u64 | 65535;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r11.u32);
	// ble cr6,0x821eb004
	if (!cr6.gt) goto loc_821EB004;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x821eafcc
	if (!cr6.gt) goto loc_821EAFCC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_821EAFCC:
	// bl 0x82130528
	ctx.lr = 0x821EAFD0;
	sub_82130528(ctx, base);
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// stw r3,296(r31)
	PPC_STORE_U32(r31.u32 + 296, ctx.r3.u32);
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821eb004
	if (!cr6.gt) goto loc_821EB004;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_821EAFE8:
	// lwz r9,296(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,300(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x821eafe8
	if (cr6.lt) goto loc_821EAFE8;
loc_821EB004:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12540(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12540);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r11.u32);
	// ble cr6,0x821eb064
	if (!cr6.gt) goto loc_821EB064;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x821eb02c
	if (!cr6.gt) goto loc_821EB02C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_821EB02C:
	// bl 0x82130528
	ctx.lr = 0x821EB030;
	sub_82130528(ctx, base);
	// lwz r10,292(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// stw r3,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r3.u32);
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821eb064
	if (!cr6.gt) goto loc_821EB064;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_821EB048:
	// lwz r9,288(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,292(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x821eb048
	if (cr6.lt) goto loc_821EB048;
loc_821EB064:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,0(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ea968
	ctx.lr = 0x821EB074;
	sub_821EA968(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821EB07C"))) PPC_WEAK_FUNC(sub_821EB07C);
PPC_FUNC_IMPL(__imp__sub_821EB07C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EB080"))) PPC_WEAK_FUNC(sub_821EB080);
PPC_FUNC_IMPL(__imp__sub_821EB080) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x821EB088;
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,1028(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1028);
	f0.f64 = double(temp.f32);
	// stfs f0,1032(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1032, temp.u32);
	// stfs f1,1028(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1028, temp.u32);
	// stfs f2,1036(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 1036, temp.u32);
	// stfs f3,1040(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 1040, temp.u32);
	// stfs f4,1044(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 1044, temp.u32);
	// lwz r10,46(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 46);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f3
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f3.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// bgt cr6,0x821eb0ec
	if (cr6.gt) goto loc_821EB0EC;
	// lwz r11,42(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 42);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f2
	ctx.f13.f64 = double(float(f0.f64 + ctx.f2.f64));
	// li r11,0
	r11.s64 = 0;
	// fcmpu cr6,f1,f13
	cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bge cr6,0x821eb0f0
	if (!cr6.lt) goto loc_821EB0F0;
loc_821EB0EC:
	// li r11,1
	r11.s64 = 1;
loc_821EB0F0:
	// lbz r10,1072(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1072);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// stb r9,1072(r31)
	PPC_STORE_U8(r31.u32 + 1072, ctx.r9.u8);
	// addi r30,r8,-12352
	r30.s64 = ctx.r8.s64 + -12352;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// stb r11,1073(r31)
	PPC_STORE_U8(r31.u32 + 1073, r11.u8);
	// bl 0x821e7ff8
	ctx.lr = 0x821EB124;
	sub_821E7FF8(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f12,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f13,40(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f0,-29920(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29920);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f0,-29924(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29924);
	f0.f64 = double(temp.f32);
	// lfs f31,30284(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30284);
	f31.f64 = double(temp.f32);
	// lfs f30,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f12,-29928(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29928);
	ctx.f12.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsel f29,f13,f10,f11
	f29.f64 = ctx.f13.f64 >= 0.0 ? ctx.f10.f64 : ctx.f11.f64;
	// fsubs f1,f12,f29
	ctx.f1.f64 = double(float(ctx.f12.f64 - f29.f64));
	// bl 0x82151fe0
	ctx.lr = 0x821EB170;
	sub_82151FE0(ctx, base);
	// stfs f1,1056(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1056, temp.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f0,-29932(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29932);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f29
	ctx.f1.f64 = double(float(f0.f64 - f29.f64));
	// bl 0x82151fe0
	ctx.lr = 0x821EB18C;
	sub_82151FE0(ctx, base);
	// stfs f1,1060(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1060, temp.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f0,-29936(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29936);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f29
	ctx.f1.f64 = double(float(f0.f64 - f29.f64));
	// bl 0x82151fe0
	ctx.lr = 0x821EB1A8;
	sub_82151FE0(ctx, base);
	// stfs f1,1064(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1064, temp.u32);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f0,-29940(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -29940);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f29
	ctx.f1.f64 = double(float(f0.f64 - f29.f64));
	// bl 0x82151fe0
	ctx.lr = 0x821EB1C4;
	sub_82151FE0(ctx, base);
	// lwz r11,308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// stfs f1,1068(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1068, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821EB1DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,840(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 840);
	// bl 0x825482a8
	ctx.lr = 0x821EB1E4;
	sub_825482A8(ctx, base);
	// lhz r10,82(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// lis r25,-32125
	r25.s64 = -2105344000;
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,26652(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 26652);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f31,-30128(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30128);
	f31.f64 = double(temp.f32);
	// lfsx f9,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f9,f31
	cr6.compare(ctx.f9.f64, f31.f64);
	// bgt cr6,0x821eb248
	if (cr6.gt) goto loc_821EB248;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821e9e58
	ctx.lr = 0x821EB220;
	sub_821E9E58(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e9b80
	ctx.lr = 0x821EB22C;
	sub_821E9B80(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e9c50
	ctx.lr = 0x821EB238;
	sub_821E9C50(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e9d20
	ctx.lr = 0x821EB244;
	sub_821E9D20(ctx, base);
	// b 0x821eb428
	goto loc_821EB428;
loc_821EB248:
	// lwz r10,852(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 852);
	// lhz r9,82(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 82);
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r7,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x821eb3c4
	if (!cr6.gt) goto loc_821EB3C4;
	// bl 0x821e8410
	ctx.lr = 0x821EB270;
	sub_821E8410(ctx, base);
	// lwz r11,264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// addi r30,r31,264
	r30.s64 = r31.s64 + 264;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r26,-32114
	r26.s64 = -2104623104;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eb330
	if (!cr6.eq) goto loc_821EB330;
	// lbz r11,1072(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1072);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// beq cr6,0x821eb2a4
	if (cr6.eq) goto loc_821EB2A4;
	// lwz r29,14(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// b 0x821eb2a8
	goto loc_821EB2A8;
loc_821EB2A4:
	// lwz r29,10(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 10);
loc_821EB2A8:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821e8080
	ctx.lr = 0x821EB2B0;
	sub_821E8080(ctx, base);
	// lbz r8,182(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 182);
	// li r12,219
	r12.s64 = 219;
	// lwz r11,-12512(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -12512);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r3,-12548(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12548);
	// and r8,r8,r12
	ctx.r8.u64 = ctx.r8.u64 & r12.u64;
	// stw r9,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 | 32;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r8,182(r1)
	PPC_STORE_U8(ctx.r1.u32 + 182, ctx.r8.u8);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// bl 0x821f4e78
	ctx.lr = 0x821EB2F8;
	sub_821F4E78(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eb328
	if (cr6.eq) goto loc_821EB328;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821EB320;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r29.u32);
	// b 0x821eb330
	goto loc_821EB330;
loc_821EB328:
	// lwz r11,-32452(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -32452);
	// stw r11,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r11.u32);
loc_821EB330:
	// lwz r11,268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// addi r29,r31,268
	r29.s64 = r31.s64 + 268;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eb3cc
	if (!cr6.eq) goto loc_821EB3CC;
	// lbz r11,1072(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1072);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// beq cr6,0x821eb358
	if (cr6.eq) goto loc_821EB358;
	// lwz r30,22(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 22);
	// b 0x821eb35c
	goto loc_821EB35C;
loc_821EB358:
	// lwz r30,18(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 18);
loc_821EB35C:
	// lwz r11,-12512(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -12512);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-12548(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12548);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// bl 0x821f4e78
	ctx.lr = 0x821EB388;
	sub_821F4E78(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eb3b8
	if (cr6.eq) goto loc_821EB3B8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821EB3B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r30.u32);
	// b 0x821eb3cc
	goto loc_821EB3CC;
loc_821EB3B8:
	// lwz r11,-32452(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -32452);
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
	// b 0x821eb3cc
	goto loc_821EB3CC;
loc_821EB3C4:
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821e9b80
	ctx.lr = 0x821EB3CC;
	sub_821E9B80(ctx, base);
loc_821EB3CC:
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,26652(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 26652);
	// lhz r9,82(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r11,r9
	ctx.r8.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r7,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x821eb400
	if (!cr6.gt) goto loc_821EB400;
	// bl 0x821e8b18
	ctx.lr = 0x821EB3FC;
	sub_821E8B18(ctx, base);
	// b 0x821eb408
	goto loc_821EB408;
loc_821EB400:
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821e9d20
	ctx.lr = 0x821EB408;
	sub_821E9D20(ctx, base);
loc_821EB408:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e9068
	ctx.lr = 0x821EB410;
	sub_821E9068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eb420
	if (!cr6.eq) goto loc_821EB420;
	// stw r11,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r11.u32);
loc_821EB420:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ea288
	ctx.lr = 0x821EB428;
	sub_821EA288(ctx, base);
loc_821EB428:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ea110
	ctx.lr = 0x821EB430;
	sub_821EA110(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
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

__attribute__((alias("__imp__sub_821EB444"))) PPC_WEAK_FUNC(sub_821EB444);
PPC_FUNC_IMPL(__imp__sub_821EB444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EB448"))) PPC_WEAK_FUNC(sub_821EB448);
PPC_FUNC_IMPL(__imp__sub_821EB448) {
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
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x821EB450;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// addi r5,r11,-29900
	ctx.r5.s64 = r11.s64 + -29900;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x821EB480;
	sub_82137A08(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r25,r11,19856
	r25.s64 = r11.s64 + 19856;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82144a20
	ctx.lr = 0x821EB494;
	sub_82144A20(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821eb6fc
	if (cr6.eq) goto loc_821EB6FC;
	// li r3,268
	ctx.r3.s64 = 268;
	// bl 0x82130528
	ctx.lr = 0x821EB4A8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821eb4c4
	if (cr6.eq) goto loc_821EB4C4;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821eacd0
	ctx.lr = 0x821EB4BC;
	sub_821EACD0(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// b 0x821eb4c8
	goto loc_821EB4C8;
loc_821EB4C4:
	// li r24,0
	r24.s64 = 0;
loc_821EB4C8:
	// lwz r11,11(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x821eb54c
	if (!cr6.eq) goto loc_821EB54C;
	// lwz r11,15(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 15);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x821eb54c
	if (!cr6.eq) goto loc_821EB54C;
	// lwz r11,19(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 19);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x821eb54c
	if (!cr6.eq) goto loc_821EB54C;
	// lfs f0,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,11(r31)
	PPC_STORE_U32(r31.u32 + 11, r11.u32);
	// lfs f13,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,15(r31)
	PPC_STORE_U32(r31.u32 + 15, ctx.r10.u32);
	// lfs f12,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,19(r31)
	PPC_STORE_U32(r31.u32 + 19, ctx.r9.u32);
	// b 0x821eb570
	goto loc_821EB570;
loc_821EB54C:
	// lwz r11,15(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 15);
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r10,19(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 19);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_821EB570:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x821EB578;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821eb598
	if (cr6.eq) goto loc_821EB598;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r31.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x821eb59c
	goto loc_821EB59C;
loc_821EB598:
	// li r31,0
	r31.s64 = 0;
loc_821EB59C:
	// addi r28,r24,256
	r28.s64 = r24.s64 + 256;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x821EB5AC;
	sub_8262E420(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r30,0
	r30.s64 = 0;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// addi r29,r11,-29916
	r29.s64 = r11.s64 + -29916;
loc_821EB5BC:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x821EB5D4;
	sub_82137A08(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// bl 0x82144a20
	ctx.lr = 0x821EB5E0;
	sub_82144A20(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821eb6d4
	if (cr6.eq) goto loc_821EB6D4;
	// lwz r11,11(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x821eb668
	if (!cr6.eq) goto loc_821EB668;
	// lwz r11,15(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 15);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x821eb668
	if (!cr6.eq) goto loc_821EB668;
	// lwz r11,19(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 19);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// lfs f13,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x821eb668
	if (!cr6.eq) goto loc_821EB668;
	// lfs f0,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,11(r31)
	PPC_STORE_U32(r31.u32 + 11, r11.u32);
	// lfs f13,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,15(r31)
	PPC_STORE_U32(r31.u32 + 15, ctx.r10.u32);
	// lfs f12,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r9,19(r31)
	PPC_STORE_U32(r31.u32 + 19, ctx.r9.u32);
	// b 0x821eb68c
	goto loc_821EB68C;
loc_821EB668:
	// lwz r11,15(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 15);
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r10,19(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 19);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_821EB68C:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x821EB694;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821eb6b4
	if (cr6.eq) goto loc_821EB6B4;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r31.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x821eb6b8
	goto loc_821EB6B8;
loc_821EB6B4:
	// li r31,0
	r31.s64 = 0;
loc_821EB6B8:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x821EB6C4;
	sub_8262E420(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// cmpwi cr6,r30,10
	cr6.compare<int32_t>(r30.s32, 10, xer);
	// blt cr6,0x821eb5bc
	if (cr6.lt) goto loc_821EB5BC;
loc_821EB6D4:
	// addi r31,r23,204
	r31.s64 = r23.s64 + 204;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c8f08
	ctx.lr = 0x821EB6E0;
	sub_821C8F08(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r23,196
	ctx.r3.s64 = r23.s64 + 196;
	// bl 0x8262e420
	ctx.lr = 0x821EB6EC;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r24,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r24.u32);
	// bl 0x821c8f70
	ctx.lr = 0x821EB6FC;
	sub_821C8F70(ctx, base);
loc_821EB6FC:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821EB708"))) PPC_WEAK_FUNC(sub_821EB708);
PPC_FUNC_IMPL(__imp__sub_821EB708) {
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
	ctx.lr = 0x821EB710;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r27,r31,204
	r27.s64 = r31.s64 + 204;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c8f08
	ctx.lr = 0x821EB728;
	sub_821C8F08(ctx, base);
	// lhz r7,200(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 200);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x821eb800
	if (!cr6.gt) goto loc_821EB800;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r30,r31,196
	r30.s64 = r31.s64 + 196;
loc_821EB740:
	// lwz r31,0(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r28
	r11.u64 = r28.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_821EB74C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x821eb770
	if (cr6.eq) goto loc_821EB770;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821eb74c
	if (cr6.eq) goto loc_821EB74C;
loc_821EB770:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821eb798
	if (cr6.eq) goto loc_821EB798;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r29,r7
	cr6.compare<int32_t>(r29.s32, ctx.r7.s32, xer);
	// blt cr6,0x821eb740
	if (cr6.lt) goto loc_821EB740;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c8f70
	ctx.lr = 0x821EB790;
	sub_821C8F70(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_821EB798:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821eb7b0
	if (cr6.eq) goto loc_821EB7B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ead38
	ctx.lr = 0x821EB7A8;
	sub_821EAD38(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821EB7B0;
	sub_82130588(ctx, base);
loc_821EB7B0:
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821eb7f0
	if (!cr6.lt) goto loc_821EB7F0;
loc_821EB7C4:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x821eb7c4
	if (cr6.lt) goto loc_821EB7C4;
loc_821EB7F0:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
loc_821EB800:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c8f70
	ctx.lr = 0x821EB808;
	sub_821C8F70(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821EB810"))) PPC_WEAK_FUNC(sub_821EB810);
PPC_FUNC_IMPL(__imp__sub_821EB810) {
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
	// lwz r11,144(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eb83c
	if (cr6.eq) goto loc_821EB83C;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x821eb910
	goto loc_821EB910;
loc_821EB83C:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// lbz r31,70(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 70);
	// lfs f13,-31400(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821eb914
	if (cr6.eq) goto loc_821EB914;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r10,r11,-12352
	ctx.r10.s64 = r11.s64 + -12352;
	// lfs f12,56(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
loc_821EB86C:
	// addi r11,r6,3
	r11.s64 = ctx.r6.s64 + 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lbz r7,59(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 59);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821eb8f4
	if (cr6.eq) goto loc_821EB8F4;
	// li r9,0
	ctx.r9.s64 = 0;
loc_821EB888:
	// addi r11,r9,5
	r11.s64 = ctx.r9.s64 + 5;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lfs f9,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f7,f0,f12
	ctx.f7.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f5,f7,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fdivs f0,f5,f10
	f0.f64 = double(float(ctx.f5.f64 / ctx.f10.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x821eb8e4
	if (!cr6.lt) goto loc_821EB8E4;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
loc_821EB8E4:
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// blt cr6,0x821eb888
	if (cr6.lt) goto loc_821EB888;
loc_821EB8F4:
	// addi r11,r6,1
	r11.s64 = ctx.r6.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x821eb86c
	if (cr6.lt) goto loc_821EB86C;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821eb914
	if (cr6.eq) goto loc_821EB914;
loc_821EB910:
	// bl 0x821ea968
	ctx.lr = 0x821EB914;
	sub_821EA968(ctx, base);
loc_821EB914:
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

__attribute__((alias("__imp__sub_821EB92C"))) PPC_WEAK_FUNC(sub_821EB92C);
PPC_FUNC_IMPL(__imp__sub_821EB92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EB930"))) PPC_WEAK_FUNC(sub_821EB930);
PPC_FUNC_IMPL(__imp__sub_821EB930) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r4,152(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// b 0x821ea968
	sub_821EA968(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821EB93C"))) PPC_WEAK_FUNC(sub_821EB93C);
PPC_FUNC_IMPL(__imp__sub_821EB93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EB940"))) PPC_WEAK_FUNC(sub_821EB940);
PPC_FUNC_IMPL(__imp__sub_821EB940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x82548ac0
	ctx.lr = 0x821EB95C;
	sub_82548AC0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,-29884
	ctx.r9.s64 = r11.s64 + -29884;
	// li r30,0
	r30.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,204
	ctx.r3.s64 = r31.s64 + 204;
	// stw r30,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r30.u32);
	// lfs f0,-31400(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	f0.f64 = double(temp.f32);
	// stw r30,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r30.u32);
	// stfs f0,168(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stw r30,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r30.u32);
	// stfs f0,188(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// stw r30,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r30.u32);
	// stw r30,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r30.u32);
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// stw r30,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r30.u32);
	// stw r30,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r30.u32);
	// stw r30,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r30.u32);
	// sth r30,200(r31)
	PPC_STORE_U16(r31.u32 + 200, r30.u16);
	// sth r30,202(r31)
	PPC_STORE_U16(r31.u32 + 202, r30.u16);
	// bl 0x821c8ed8
	ctx.lr = 0x821EB9B0;
	sub_821C8ED8(ctx, base);
	// addi r3,r31,864
	ctx.r3.s64 = r31.s64 + 864;
	// bl 0x82163ee8
	ctx.lr = 0x821EB9B8;
	sub_82163EE8(ctx, base);
	// addi r3,r31,904
	ctx.r3.s64 = r31.s64 + 904;
	// bl 0x82163ee8
	ctx.lr = 0x821EB9C0;
	sub_82163EE8(ctx, base);
	// addi r3,r31,944
	ctx.r3.s64 = r31.s64 + 944;
	// bl 0x82163ee8
	ctx.lr = 0x821EB9C8;
	sub_82163EE8(ctx, base);
	// addi r3,r31,984
	ctx.r3.s64 = r31.s64 + 984;
	// bl 0x82163ee8
	ctx.lr = 0x821EB9D0;
	sub_82163EE8(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32114
	ctx.r7.s64 = -2104623104;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r31,-12288(r8)
	PPC_STORE_U32(ctx.r8.u32 + -12288, r31.u32);
	// lis r4,-32225
	ctx.r4.s64 = -2111897600;
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// lis r8,32639
	ctx.r8.s64 = 2139029504;
	// stw r30,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r30.u32);
	// addi r3,r4,-18416
	ctx.r3.s64 = ctx.r4.s64 + -18416;
	// stw r30,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r30.u32);
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r9,236(r31)
	PPC_STORE_U32(r31.u32 + 236, ctx.r9.u32);
	// lfs f13,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,832(r31)
	PPC_STORE_U32(r31.u32 + 832, r30.u32);
	// ori r8,r8,65535
	ctx.r8.u64 = ctx.r8.u64 | 65535;
	// stw r30,840(r31)
	PPC_STORE_U32(r31.u32 + 840, r30.u32);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r30,852(r31)
	PPC_STORE_U32(r31.u32 + 852, r30.u32);
	// stw r30,856(r31)
	PPC_STORE_U32(r31.u32 + 856, r30.u32);
	// stw r30,860(r31)
	PPC_STORE_U32(r31.u32 + 860, r30.u32);
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// stw r30,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r30.u32);
	// lwz r11,-32452(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -32452);
	// stw r11,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r11.u32);
	// lwz r11,-32452(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -32452);
	// stfs f0,1024(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1024, temp.u32);
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
	// stfs f0,1028(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1028, temp.u32);
	// stfs f0,1032(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1032, temp.u32);
	// addi r11,r31,312
	r11.s64 = r31.s64 + 312;
	// stfs f0,1036(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1036, temp.u32);
	// stw r30,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r30.u32);
	// stfs f0,1040(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1040, temp.u32);
	// stw r30,284(r31)
	PPC_STORE_U32(r31.u32 + 284, r30.u32);
	// stfs f0,1044(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1044, temp.u32);
	// stw r30,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r30.u32);
	// stfs f13,1048(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1048, temp.u32);
	// stw r30,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r30.u32);
	// stfs f13,1052(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1052, temp.u32);
	// stw r30,296(r31)
	PPC_STORE_U32(r31.u32 + 296, r30.u32);
	// stw r30,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r30.u32);
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
	// stw r30,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r30.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
	// stw r30,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r30.u32);
	// stw r30,244(r31)
	PPC_STORE_U32(r31.u32 + 244, r30.u32);
	// stw r30,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r30.u32);
	// stw r30,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r30.u32);
	// stw r30,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r30.u32);
	// stw r30,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r30.u32);
	// stw r3,308(r31)
	PPC_STORE_U32(r31.u32 + 308, ctx.r3.u32);
	// stb r30,1072(r31)
	PPC_STORE_U8(r31.u32 + 1072, r30.u8);
	// stb r30,1073(r31)
	PPC_STORE_U8(r31.u32 + 1073, r30.u8);
	// stb r30,1074(r31)
	PPC_STORE_U8(r31.u32 + 1074, r30.u8);
	// stb r30,1075(r31)
	PPC_STORE_U8(r31.u32 + 1075, r30.u8);
	// stb r30,1076(r31)
	PPC_STORE_U8(r31.u32 + 1076, r30.u8);
	// stb r30,1077(r31)
	PPC_STORE_U8(r31.u32 + 1077, r30.u8);
	// stb r30,1078(r31)
	PPC_STORE_U8(r31.u32 + 1078, r30.u8);
	// stb r9,1079(r31)
	PPC_STORE_U8(r31.u32 + 1079, ctx.r9.u8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_821EBAC8:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x821ebac8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_821EBAC8;
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

__attribute__((alias("__imp__sub_821EBAF0"))) PPC_WEAK_FUNC(sub_821EBAF0);
PPC_FUNC_IMPL(__imp__sub_821EBAF0) {
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
	ctx.lr = 0x821EBAF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-29884
	ctx.r9.s64 = r11.s64 + -29884;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r11,-12288(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12288, r11.u32);
	// bl 0x821e9d20
	ctx.lr = 0x821EBB20;
	sub_821E9D20(ctx, base);
	// lwz r3,296(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 296);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ebb30
	if (cr6.eq) goto loc_821EBB30;
	// bl 0x82130588
	ctx.lr = 0x821EBB30;
	sub_82130588(ctx, base);
loc_821EBB30:
	// lwz r3,288(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 288);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ebb40
	if (cr6.eq) goto loc_821EBB40;
	// bl 0x82130588
	ctx.lr = 0x821EBB40;
	sub_82130588(ctx, base);
loc_821EBB40:
	// lhz r11,200(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 200);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ebbc8
	if (cr6.eq) goto loc_821EBBC8;
	// li r27,0
	r27.s64 = 0;
loc_821EBB54:
	// lwz r11,196(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// lwzx r31,r11,r27
	r31.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821ebbb4
	if (cr6.eq) goto loc_821EBBB4;
	// lhz r11,260(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 260);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ebb98
	if (cr6.eq) goto loc_821EBB98;
	// li r30,0
	r30.s64 = 0;
loc_821EBB78:
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82130588
	ctx.lr = 0x821EBB84;
	sub_82130588(ctx, base);
	// lhz r10,260(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 260);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x821ebb78
	if (cr6.lt) goto loc_821EBB78;
loc_821EBB98:
	// lhz r11,262(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 262);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ebbac
	if (cr6.eq) goto loc_821EBBAC;
	// lwz r3,256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// bl 0x82130588
	ctx.lr = 0x821EBBAC;
	sub_82130588(ctx, base);
loc_821EBBAC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821EBBB4;
	sub_82130588(ctx, base);
loc_821EBBB4:
	// lhz r11,200(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 200);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x821ebb54
	if (cr6.lt) goto loc_821EBB54;
loc_821EBBC8:
	// lhz r11,200(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 200);
	// addi r31,r28,196
	r31.s64 = r28.s64 + 196;
	// lwz r9,196(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x821ebc00
	if (cr6.eq) goto loc_821EBC00;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_821EBBEC:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x821ebbec
	if (!cr6.eq) goto loc_821EBBEC;
loc_821EBC00:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r3,r28,204
	ctx.r3.s64 = r28.s64 + 204;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// bl 0x82130000
	ctx.lr = 0x821EBC1C;
	sub_82130000(ctx, base);
	// lhz r6,6(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821ebc30
	if (cr6.eq) goto loc_821EBC30;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821EBC30;
	sub_82130588(ctx, base);
loc_821EBC30:
	// addi r11,r28,196
	r11.s64 = r28.s64 + 196;
	// li r30,1
	r30.s64 = 1;
	// addi r31,r11,16
	r31.s64 = r11.s64 + 16;
loc_821EBC3C:
	// addi r31,r31,-20
	r31.s64 = r31.s64 + -20;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ebc54
	if (cr6.eq) goto loc_821EBC54;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825ae378
	ctx.lr = 0x821EBC54;
	sub_825AE378(ctx, base);
loc_821EBC54:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x821ebc3c
	if (!cr0.lt) goto loc_821EBC3C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82548b50
	ctx.lr = 0x821EBC64;
	sub_82548B50(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821EBC6C"))) PPC_WEAK_FUNC(sub_821EBC6C);
PPC_FUNC_IMPL(__imp__sub_821EBC6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EBC70"))) PPC_WEAK_FUNC(sub_821EBC70);
PPC_FUNC_IMPL(__imp__sub_821EBC70) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ebca8
	if (cr6.eq) goto loc_821EBCA8;
	// lbz r11,1078(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1078);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ebcd4
	if (!cr6.eq) goto loc_821EBCD4;
	// b 0x821ebcac
	goto loc_821EBCAC;
loc_821EBCA8:
	// stb r30,1078(r31)
	PPC_STORE_U8(r31.u32 + 1078, r30.u8);
loc_821EBCAC:
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ebcd4
	if (cr6.eq) goto loc_821EBCD4;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e9e58
	ctx.lr = 0x821EBCC4;
	sub_821E9E58(ctx, base);
	// lis r11,-32225
	r11.s64 = -2111897600;
	// stw r30,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r30.u32);
	// addi r10,r11,-18416
	ctx.r10.s64 = r11.s64 + -18416;
	// stw r10,308(r31)
	PPC_STORE_U32(r31.u32 + 308, ctx.r10.u32);
loc_821EBCD4:
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

__attribute__((alias("__imp__sub_821EBCEC"))) PPC_WEAK_FUNC(sub_821EBCEC);
PPC_FUNC_IMPL(__imp__sub_821EBCEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EBCF0"))) PPC_WEAK_FUNC(sub_821EBCF0);
PPC_FUNC_IMPL(__imp__sub_821EBCF0) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lbz r9,1078(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1078);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r11,-12264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12264);
	// or r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 | ctx.r9.u64;
	// clrlwi r5,r11,31
	ctx.r5.u64 = r11.u32 & 0x1;
	// stb r6,1078(r31)
	PPC_STORE_U8(r31.u32 + 1078, ctx.r6.u8);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x821ebd5c
	if (!cr6.eq) goto loc_821EBD5C;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r11,-12264(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12264, r11.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r4,r9,-29856
	ctx.r4.s64 = ctx.r9.s64 + -29856;
	// addi r3,r8,19856
	ctx.r3.s64 = ctx.r8.s64 + 19856;
	// bl 0x82144a20
	ctx.lr = 0x821EBD54;
	sub_82144A20(ctx, base);
	// stw r3,-12268(r30)
	PPC_STORE_U32(r30.u32 + -12268, ctx.r3.u32);
	// b 0x821ebd60
	goto loc_821EBD60;
loc_821EBD5C:
	// lwz r3,-12268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12268);
loc_821EBD60:
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// beq cr6,0x821ebd88
	if (cr6.eq) goto loc_821EBD88;
	// stw r3,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r3.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e9e58
	ctx.lr = 0x821EBD7C;
	sub_821E9E58(ctx, base);
	// lis r11,-32225
	r11.s64 = -2111897600;
	// addi r10,r11,-18128
	ctx.r10.s64 = r11.s64 + -18128;
	// stw r10,308(r31)
	PPC_STORE_U32(r31.u32 + 308, ctx.r10.u32);
loc_821EBD88:
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

__attribute__((alias("__imp__sub_821EBDA0"))) PPC_WEAK_FUNC(sub_821EBDA0);
PPC_FUNC_IMPL(__imp__sub_821EBDA0) {
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
	ctx.lr = 0x821EBDA8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,-12256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12256);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821ebdf0
	if (!cr6.eq) goto loc_821EBDF0;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r11,-12256(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12256, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-29828
	ctx.r4.s64 = ctx.r9.s64 + -29828;
	// bl 0x82144a20
	ctx.lr = 0x821EBDEC;
	sub_82144A20(ctx, base);
	// stw r3,-12260(r30)
	PPC_STORE_U32(r30.u32 + -12260, ctx.r3.u32);
loc_821EBDF0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r11,-29840
	ctx.r5.s64 = r11.s64 + -29840;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x821EBE08;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82144a20
	ctx.lr = 0x821EBE14;
	sub_82144A20(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821ebe20
	if (!cr6.eq) goto loc_821EBE20;
	// lwz r3,-12260(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12260);
loc_821EBE20:
	// lis r11,-32225
	r11.s64 = -2111897600;
	// stw r3,152(r29)
	PPC_STORE_U32(r29.u32 + 152, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-18128
	ctx.r9.s64 = r11.s64 + -18128;
	// stb r10,1077(r29)
	PPC_STORE_U8(r29.u32 + 1077, ctx.r10.u8);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stw r9,308(r29)
	PPC_STORE_U32(r29.u32 + 308, ctx.r9.u32);
	// lwz r3,-12012(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x821EBE44;
	sub_821F15C8(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821EBE4C"))) PPC_WEAK_FUNC(sub_821EBE4C);
PPC_FUNC_IMPL(__imp__sub_821EBE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EBE50"))) PPC_WEAK_FUNC(sub_821EBE50);
PPC_FUNC_IMPL(__imp__sub_821EBE50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-18416
	ctx.r9.s64 = ctx.r10.s64 + -18416;
	// stb r11,1077(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1077, r11.u8);
	// stw r11,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, r11.u32);
	// stw r9,308(r3)
	PPC_STORE_U32(ctx.r3.u32 + 308, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EBE6C"))) PPC_WEAK_FUNC(sub_821EBE6C);
PPC_FUNC_IMPL(__imp__sub_821EBE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EBE70"))) PPC_WEAK_FUNC(sub_821EBE70);
PPC_FUNC_IMPL(__imp__sub_821EBE70) {
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
	// bl 0x821ebaf0
	ctx.lr = 0x821EBE90;
	sub_821EBAF0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ebea8
	if (cr6.eq) goto loc_821EBEA8;
	// bl 0x82130588
	ctx.lr = 0x821EBEA4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821EBEA8:
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

__attribute__((alias("__imp__sub_821EBEC0"))) PPC_WEAK_FUNC(sub_821EBEC0);
PPC_FUNC_IMPL(__imp__sub_821EBEC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// li r11,0
	r11.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r5,r8,0
	ctx.r5.s64 = ctx.r8.s64 + 0;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r7,0
	ctx.r4.s64 = ctx.r7.s64 + 0;
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// stw r5,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r5.u32);
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// std r11,64(r3)
	PPC_STORE_U64(ctx.r3.u32 + 64, r11.u64);
	// stb r11,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, r11.u8);
	// stb r11,73(r3)
	PPC_STORE_U8(ctx.r3.u32 + 73, r11.u8);
	// stb r11,74(r3)
	PPC_STORE_U8(ctx.r3.u32 + 74, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EBF38"))) PPC_WEAK_FUNC(sub_821EBF38);
PPC_FUNC_IMPL(__imp__sub_821EBF38) {
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
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ebfd0
	if (!cr6.eq) goto loc_821EBFD0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// lbz r11,47(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 47);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// ble cr6,0x821ebf80
	if (!cr6.gt) goto loc_821EBF80;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_821EBF80:
	// bl 0x82130528
	ctx.lr = 0x821EBF84;
	sub_82130528(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r7,14
	ctx.r7.s64 = 14;
	// addi r5,r11,48
	ctx.r5.s64 = r11.s64 + 48;
	// lwz r3,-32456(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32456);
	// bl 0x82547ac0
	ctx.lr = 0x821EBFA8;
	sub_82547AC0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821ebfc8
	if (!cr6.eq) goto loc_821EBFC8;
	// li r30,0
	r30.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// bl 0x82130588
	ctx.lr = 0x821EBFC4;
	sub_82130588(ctx, base);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
loc_821EBFC8:
	// li r11,1
	r11.s64 = 1;
	// stb r11,74(r31)
	PPC_STORE_U8(r31.u32 + 74, r11.u8);
loc_821EBFD0:
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

__attribute__((alias("__imp__sub_821EBFE8"))) PPC_WEAK_FUNC(sub_821EBFE8);
PPC_FUNC_IMPL(__imp__sub_821EBFE8) {
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
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ec04c
	if (cr6.eq) goto loc_821EC04C;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821ec02c
	if (cr6.eq) goto loc_821EC02C;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,-32456(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -32456);
	// bl 0x825478b0
	ctx.lr = 0x821EC024;
	sub_825478B0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x821EC02C;
	sub_82130588(ctx, base);
loc_821EC02C:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ec040
	if (cr6.eq) goto loc_821EC040;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_821EC040:
	// std r10,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r10.u64);
	// stb r10,73(r31)
	PPC_STORE_U8(r31.u32 + 73, ctx.r10.u8);
	// stb r10,74(r31)
	PPC_STORE_U8(r31.u32 + 74, ctx.r10.u8);
loc_821EC04C:
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

__attribute__((alias("__imp__sub_821EC060"))) PPC_WEAK_FUNC(sub_821EC060);
PPC_FUNC_IMPL(__imp__sub_821EC060) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x821EC068;
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r26,0
	r26.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r26,64(r31)
	PPC_STORE_U64(r31.u32 + 64, r26.u64);
	// lfs f30,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lwz r9,10(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x821ec2f4
	if (!cr6.gt) goto loc_821EC2F4;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,10(r11)
	PPC_STORE_U32(r11.u32 + 10, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,10(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 10);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x821ec2f4
	if (!cr6.eq) goto loc_821EC2F4;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ec0d0
	if (cr6.eq) goto loc_821EC0D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EC0D0;
	sub_8213C218(ctx, base);
loc_821EC0D0:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ec0e4
	if (cr6.eq) goto loc_821EC0E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EC0E4;
	sub_8213C218(ctx, base);
loc_821EC0E4:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ec130
	if (cr6.eq) goto loc_821EC130;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-12252(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -12252);
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r26,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r26.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r26,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r26.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,18(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 18);
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r26.u32);
	// bl 0x82549428
	ctx.lr = 0x821EC130;
	sub_82549428(ctx, base);
loc_821EC130:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ec144
	if (cr6.eq) goto loc_821EC144;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EC144;
	sub_821F4C18(ctx, base);
loc_821EC144:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r27,1
	r27.s64 = 1;
	// lbz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 38);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821ec270
	if (!cr6.eq) goto loc_821EC270;
	// lwz r11,34(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// mr r30,r26
	r30.u64 = r26.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// lfs f31,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f31.f64 = double(temp.f32);
	// ble cr6,0x821ec2dc
	if (!cr6.gt) goto loc_821EC2DC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r26
	r29.u64 = r26.u64;
	// lis r28,-32254
	r28.s64 = -2113798144;
	// lfs f29,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f29.f64 = double(temp.f32);
loc_821EC188:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x82547f00
	ctx.lr = 0x821EC19C;
	sub_82547F00(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ec1bc
	if (!cr6.eq) goto loc_821EC1BC;
	// extsw r11,r30
	r11.s64 = r30.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r27,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r27.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821EC1BC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x82547fa0
	ctx.lr = 0x821EC1D0;
	sub_82547FA0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ec1f0
	if (!cr6.eq) goto loc_821EC1F0;
	// extsw r11,r30
	r11.s64 = r30.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r27,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r27.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821EC1F0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f1,-29732(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + -29732);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x82547fe8
	ctx.lr = 0x821EC204;
	sub_82547FE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ec224
	if (!cr6.eq) goto loc_821EC224;
	// extsw r11,r30
	r11.s64 = r30.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r27,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r27.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821EC224:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x82548088
	ctx.lr = 0x821EC238;
	sub_82548088(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ec258
	if (!cr6.eq) goto loc_821EC258;
	// extsw r11,r30
	r11.s64 = r30.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r27,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r27.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821EC258:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x821ec188
	if (cr6.lt) goto loc_821EC188;
	// b 0x821ec2dc
	goto loc_821EC2DC;
loc_821EC270:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r29,r26
	r29.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ec2dc
	if (!cr6.gt) goto loc_821EC2DC;
	// mr r30,r26
	r30.u64 = r26.u64;
	// lis r28,-32254
	r28.s64 = -2113798144;
loc_821EC288:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82547c58
	ctx.lr = 0x821EC298;
	sub_82547C58(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwzx r3,r30,r10
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// bl 0x82547cf8
	ctx.lr = 0x821EC2A8;
	sub_82547CF8(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f1,-29732(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + -29732);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r30,r9
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// bl 0x82547dd0
	ctx.lr = 0x821EC2B8;
	sub_82547DD0(ctx, base);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwzx r3,r30,r8
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	// bl 0x82547e68
	ctx.lr = 0x821EC2C8;
	sub_82547E68(ctx, base);
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r7
	cr6.compare<int32_t>(r29.s32, ctx.r7.s32, xer);
	// blt cr6,0x821ec288
	if (cr6.lt) goto loc_821EC288;
loc_821EC2DC:
	// stb r27,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r27.u8);
	// lwz r11,-12252(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -12252);
	// lwz r10,1724(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1724);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x821ec2f4
	if (!cr6.eq) goto loc_821EC2F4;
	// stw r26,1724(r11)
	PPC_STORE_U32(r11.u32 + 1724, r26.u32);
loc_821EC2F4:
	// stfs f30,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stb r26,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r26.u8);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a18
	ctx.lr = 0x821EC308;
	sub_82144A18(ctx, base);
	// addi r10,r3,250
	ctx.r10.s64 = ctx.r3.s64 + 250;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r6,24
	ctx.r6.s64 = 24;
	// std r7,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r5,34(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 34);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// stw r5,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,11364(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11364);
	f0.f64 = double(temp.f32);
	// lfs f11,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmadds f10,f11,f0,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f9,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.f9.u32);
	// beq cr6,0x821ec35c
	if (cr6.eq) goto loc_821EC35C;
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
	// stw r26,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r26.u32);
loc_821EC35C:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821EC36C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

__attribute__((alias("__imp__sub_821EC380"))) PPC_WEAK_FUNC(sub_821EC380);
PPC_FUNC_IMPL(__imp__sub_821EC380) {
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
	ctx.lr = 0x821EC388;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r11,74(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ec40c
	if (cr6.eq) goto loc_821EC40C;
	// lbz r11,72(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ec40c
	if (!cr6.eq) goto loc_821EC40C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a18
	ctx.lr = 0x821EC3B4;
	sub_82144A18(ctx, base);
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// bge cr6,0x821ec400
	if (!cr6.lt) goto loc_821EC400;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ec400
	if (!cr6.gt) goto loc_821EC400;
	// li r31,0
	r31.s64 = 0;
loc_821EC3D4:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82547b90
	ctx.lr = 0x821EC3E0;
	sub_82547B90(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ec40c
	if (cr6.eq) goto loc_821EC40C;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x821ec3d4
	if (cr6.lt) goto loc_821EC3D4;
loc_821EC400:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821EC40C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821EC418"))) PPC_WEAK_FUNC(sub_821EC418);
PPC_FUNC_IMPL(__imp__sub_821EC418) {
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
	// lwz r3,-12252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12252);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ec44c
	if (cr6.eq) goto loc_821EC44C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EC44C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821EC44C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12252(r31)
	PPC_STORE_U32(r31.u32 + -12252, r11.u32);
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

__attribute__((alias("__imp__sub_821EC468"))) PPC_WEAK_FUNC(sub_821EC468);
PPC_FUNC_IMPL(__imp__sub_821EC468) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r3,r9,40
	ctx.r3.s64 = ctx.r9.s64 + 40;
	// lwz r9,40(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// lbz r8,38(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 38);
	// rlwinm r7,r8,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821ec4bc
	if (cr6.eq) goto loc_821EC4BC;
	// lwz r9,39(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 39);
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x821ec4d8
	if (cr6.lt) goto loc_821EC4D8;
loc_821EC4BC:
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r8,1740(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1740);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// slw r7,r9,r11
	ctx.r7.u64 = r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r11.u8 & 0x3F));
	// andc r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ~ctx.r7.u64;
	// stw r6,1740(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1740, ctx.r6.u32);
	// bl 0x821ec060
	ctx.lr = 0x821EC4D8;
	sub_821EC060(ctx, base);
loc_821EC4D8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EC4E8"))) PPC_WEAK_FUNC(sub_821EC4E8);
PPC_FUNC_IMPL(__imp__sub_821EC4E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r11,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r11.u8);
	// lfs f1,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,10(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 10);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82549428
	ctx.lr = 0x821EC534;
	sub_82549428(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EC544"))) PPC_WEAK_FUNC(sub_821EC544);
PPC_FUNC_IMPL(__imp__sub_821EC544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EC548"))) PPC_WEAK_FUNC(sub_821EC548);
PPC_FUNC_IMPL(__imp__sub_821EC548) {
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
	ctx.lr = 0x821EC550;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a20
	ctx.lr = 0x821EC564;
	sub_82144A20(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821ec614
	if (cr6.eq) goto loc_821EC614;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-12252(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12252);
	// lwz r31,1720(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1720);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821ec5b8
	if (cr6.eq) goto loc_821EC5B8;
loc_821EC584:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bne cr6,0x821ec5a8
	if (!cr6.eq) goto loc_821EC5A8;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ec5a8
	if (cr6.eq) goto loc_821EC5A8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ec060
	ctx.lr = 0x821EC5A8;
	sub_821EC060(ctx, base);
loc_821EC5A8:
	// lwz r31,52(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821ec584
	if (!cr6.eq) goto loc_821EC584;
	// lwz r3,-12252(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12252);
loc_821EC5B8:
	// lwz r11,1740(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ec614
	if (cr6.eq) goto loc_821EC614;
	// li r30,0
	r30.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// li r31,0
	r31.s64 = 0;
loc_821EC5D0:
	// add r11,r31,r3
	r11.u64 = r31.u64 + ctx.r3.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// cmplw cr6,r10,r27
	cr6.compare<uint32_t>(ctx.r10.u32, r27.u32, xer);
	// bne cr6,0x821ec600
	if (!cr6.eq) goto loc_821EC600;
	// lwz r11,1740(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// and r10,r11,r29
	ctx.r10.u64 = r11.u64 & r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ec600
	if (cr6.eq) goto loc_821EC600;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ec468
	ctx.lr = 0x821EC5FC;
	sub_821EC468(ctx, base);
	// lwz r3,-12252(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12252);
loc_821EC600:
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// rotlwi r29,r29,1
	r29.u64 = __builtin_rotateleft32(r29.u32, 1);
	// cmpwi cr6,r31,1680
	cr6.compare<int32_t>(r31.s32, 1680, xer);
	// blt cr6,0x821ec5d0
	if (cr6.lt) goto loc_821EC5D0;
loc_821EC614:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821EC61C"))) PPC_WEAK_FUNC(sub_821EC61C);
PPC_FUNC_IMPL(__imp__sub_821EC61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EC620"))) PPC_WEAK_FUNC(sub_821EC620);
PPC_FUNC_IMPL(__imp__sub_821EC620) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x821EC628;
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// lwz r4,43(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 43);
	// bl 0x82144a28
	ctx.lr = 0x821EC664;
	sub_82144A28(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ec694
	if (cr6.eq) goto loc_821EC694;
	// lwz r11,10(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821ec694
	if (cr6.eq) goto loc_821EC694;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_821EC694:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r27,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r27.u32);
	// li r26,1
	r26.s64 = 1;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r26,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r26.u8);
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fsel f0,f31,f31,f30
	f0.f64 = f31.f64 >= 0.0 ? f31.f64 : f30.f64;
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// stfs f30,16(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// fsel f12,f13,f31,f0
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f31.f64 : f0.f64;
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// mtctr r29
	ctr.u64 = r29.u64;
	// bctrl 
	ctx.lr = 0x821EC6D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// std r28,64(r31)
	PPC_STORE_U64(r31.u32 + 64, r28.u64);
	// lwz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,10(r11)
	PPC_STORE_U32(r11.u32 + 10, ctx.r9.u32);
	// bne cr6,0x821ec9f0
	if (!cr6.eq) goto loc_821EC9F0;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r27,r31,40
	r27.s64 = r31.s64 + 40;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ec710
	if (cr6.eq) goto loc_821EC710;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EC710;
	sub_8213C218(ctx, base);
loc_821EC710:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r29,r31,44
	r29.s64 = r31.s64 + 44;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ec728
	if (cr6.eq) goto loc_821EC728;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EC728;
	sub_8213C218(ctx, base);
loc_821EC728:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r28,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r28.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r26,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r26.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r28,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r28.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-12252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12252);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r4,14(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// bl 0x825495a8
	ctx.lr = 0x821EC770;
	sub_825495A8(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-12252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12252);
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r28,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r28.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r28,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r28.u8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// stb r26,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r26.u8);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// lwz r4,22(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 22);
	// bl 0x825495a8
	ctx.lr = 0x821EC7B4;
	sub_825495A8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32114
	ctx.r3.s64 = -2104623104;
	// lwz r11,-32452(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -32452);
	// lwz r4,26(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x821ec808
	if (cr6.eq) goto loc_821EC808;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ec808
	if (!cr6.eq) goto loc_821EC808;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r6,-12252(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -12252);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-12512(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12512);
	// lwz r3,-12548(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12548);
	// lbz r11,16(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// bl 0x821f4e78
	ctx.lr = 0x821EC808;
	sub_821F4E78(ctx, base);
loc_821EC808:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 38);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821ec824
	if (cr6.eq) goto loc_821EC824;
	// lwz r11,-12252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12252);
	// stw r31,1724(r11)
	PPC_STORE_U32(r11.u32 + 1724, r31.u32);
loc_821EC824:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,30(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 30);
	// lbz r9,38(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 38);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// lfs f30,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821ec9ec
	if (!cr6.eq) goto loc_821EC9EC;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r27,r28
	r27.u64 = r28.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ec9ec
	if (!cr6.gt) goto loc_821EC9EC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r28
	r29.u64 = r28.u64;
	// mr r30,r28
	r30.u64 = r28.u64;
	// lis r25,-32254
	r25.s64 = -2113798144;
	// lfs f29,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f29.f64 = double(temp.f32);
loc_821EC868:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lhz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 52);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// std r8,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r8.u64);
	// lfd f0,152(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f29
	ctx.f1.f64 = double(float(ctx.f12.f64 * f29.f64));
	// bl 0x821493f8
	ctx.lr = 0x821EC890;
	sub_821493F8(ctx, base);
	// fsubs f11,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64 - f31.f64));
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f10,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lwzx r3,r29,r7
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r7.u32);
	// fmadds f1,f11,f10,f31
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + f31.f64));
	// bl 0x82547f60
	ctx.lr = 0x821EC8AC;
	sub_82547F60(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x821ec8cc
	if (!cr6.eq) goto loc_821EC8CC;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r26,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r26.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821EC8CC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	f0.f64 = double(temp.f32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// lwzx r3,r29,r10
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// lwz r8,54(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 54);
	// stw r8,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fmadds f1,f12,f0,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64 + f31.f64));
	// bl 0x82547fa0
	ctx.lr = 0x821EC8FC;
	sub_82547FA0(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x821ec91c
	if (!cr6.eq) goto loc_821EC91C;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r26,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r26.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821EC91C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,-29732(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + -29732);
	f0.f64 = double(temp.f32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f13,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lwzx r3,r29,r10
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// lhz r8,58(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 58);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r7.u64);
	// lfd f12,160(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fmadds f1,f9,f13,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + f0.f64));
	// bl 0x82547fe8
	ctx.lr = 0x821EC95C;
	sub_82547FE8(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x821ec97c
	if (!cr6.eq) goto loc_821EC97C;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r26,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r26.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821EC97C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	f0.f64 = double(temp.f32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// lwzx r3,r29,r10
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// lhz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 60);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r7.u64);
	// lfd f13,168(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bl 0x82548088
	ctx.lr = 0x821EC9B4;
	sub_82548088(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x821ec9d4
	if (!cr6.eq) goto loc_821EC9D4;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r26,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r26.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821EC9D4:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,14
	r30.s64 = r30.s64 + 14;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x821ec868
	if (cr6.lt) goto loc_821EC868;
loc_821EC9EC:
	// stb r28,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r28.u8);
loc_821EC9F0:
	// li r11,-1
	r11.s64 = -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
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

__attribute__((alias("__imp__sub_821ECA10"))) PPC_WEAK_FUNC(sub_821ECA10);
PPC_FUNC_IMPL(__imp__sub_821ECA10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f25{};
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
	// bl 0x823d91dc
	ctx.lr = 0x821ECA18;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823db9cc
	ctx.lr = 0x821ECA20;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// li r30,0
	r30.s64 = 0;
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r21,r11,-29756
	r21.s64 = r11.s64 + -29756;
	// lfs f26,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f26.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f25,11360(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	f25.f64 = double(temp.f32);
	// beq cr6,0x821ecd10
	if (cr6.eq) goto loc_821ECD10;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r22,1
	r22.s64 = 1;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// addi r5,r31,44
	ctx.r5.s64 = r31.s64 + 44;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,88(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,16(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// bne cr6,0x821ecac8
	if (!cr6.eq) goto loc_821ECAC8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-12252(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12252);
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r30,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r30.u8);
	// lwz r4,22(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 22);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stb r22,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r22.u8);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x825495a8
	ctx.lr = 0x821ECAC8;
	sub_825495A8(ctx, base);
loc_821ECAC8:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821ecb1c
	if (!cr6.eq) goto loc_821ECB1C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lwz r4,26(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 26);
	// lwz r11,-32452(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32452);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x821ecb1c
	if (cr6.eq) goto loc_821ECB1C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r6,-12252(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -12252);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-12512(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12512);
	// lwz r3,-12548(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12548);
	// lbz r11,16(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// bl 0x821f4e78
	ctx.lr = 0x821ECB1C;
	sub_821F4E78(ctx, base);
loc_821ECB1C:
	// ld r11,64(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x821ed034
	if (cr6.eq) goto loc_821ED034;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r24,r30
	r24.u64 = r30.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,30(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 30);
	// stw r9,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// lfs f27,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f27.f64 = double(temp.f32);
	// ble cr6,0x821ed034
	if (!cr6.gt) goto loc_821ED034;
	// mr r27,r30
	r27.u64 = r30.u64;
	// mr r25,r30
	r25.u64 = r30.u64;
	// lis r23,-32114
	r23.s64 = -2104623104;
loc_821ECB54:
	// extsw r11,r24
	r11.s64 = r24.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r22,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r22.u64 << (r11.u8 & 0x7F));
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpldi cr6,r8,0
	cr6.compare<uint64_t>(ctx.r8.u64, 0, xer);
	// beq cr6,0x821eccf4
	if (cr6.eq) goto loc_821ECCF4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-32456(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -32456);
	// lwzx r4,r11,r27
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x825479f8
	ctx.lr = 0x821ECB7C;
	sub_825479F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821eccf4
	if (!cr6.eq) goto loc_821ECCF4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// lhz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 52);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// std r8,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r8.u64);
	// lfd f0,160(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f25
	ctx.f1.f64 = double(float(ctx.f12.f64 * f25.f64));
	// bl 0x821493f8
	ctx.lr = 0x821ECBB0;
	sub_821493F8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fsubs f11,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64 - f31.f64));
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f10,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// lfs f0,24(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 24);
	f0.f64 = double(temp.f32);
	// mr r26,r22
	r26.u64 = r22.u64;
	// lwzx r3,r7,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + r27.u32);
	// lwz r5,54(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 54);
	// lhz r6,60(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 60);
	// lhz r11,58(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 58);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// fmadds f1,f11,f10,f31
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + f31.f64));
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// lfs f8,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// stw r5,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r5.u32);
	// lfs f7,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f7.f64 = double(temp.f32);
	// std r10,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r10.u64);
	// lfd f6,168(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// std r4,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r4.u64);
	// lfd f9,152(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fcfid f3,f9
	ctx.f3.f64 = double(ctx.f9.s64);
	// fsubs f2,f7,f31
	ctx.f2.f64 = double(float(ctx.f7.f64 - f31.f64));
	// fsubs f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 - f0.f64));
	// frsp f12,f3
	ctx.f12.f64 = double(float(ctx.f3.f64));
	// fcmpu cr6,f8,f1
	cr6.compare(ctx.f8.f64, ctx.f1.f64);
	// fmadds f30,f2,f10,f31
	f30.f64 = double(float(ctx.f2.f64 * ctx.f10.f64 + f31.f64));
	// fmadds f29,f13,f10,f0
	f29.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + f0.f64));
	// fmuls f28,f12,f10
	f28.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// beq cr6,0x821ecc3c
	if (cr6.eq) goto loc_821ECC3C;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// bl 0x82547f60
	ctx.lr = 0x821ECC38;
	sub_82547F60(ctx, base);
	// clrlwi r26,r3,31
	r26.u64 = ctx.r3.u32 & 0x1;
loc_821ECC3C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x821ecc68
	if (cr6.eq) goto loc_821ECC68;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82547fa0
	ctx.lr = 0x821ECC5C;
	sub_82547FA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// and r26,r11,r10
	r26.u64 = r11.u64 & ctx.r10.u64;
loc_821ECC68:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82548128
	ctx.lr = 0x821ECC74;
	sub_82548128(ctx, base);
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// beq cr6,0x821ecc9c
	if (cr6.eq) goto loc_821ECC9C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82547fe8
	ctx.lr = 0x821ECC90;
	sub_82547FE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r26,24
	ctx.r9.u64 = r26.u32 & 0xFF;
	// and r26,r10,r9
	r26.u64 = ctx.r10.u64 & ctx.r9.u64;
loc_821ECC9C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x825481b8
	ctx.lr = 0x821ECCA8;
	sub_825481B8(ctx, base);
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f28.f64);
	// beq cr6,0x821eccd0
	if (cr6.eq) goto loc_821ECCD0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82548088
	ctx.lr = 0x821ECCC4;
	sub_82548088(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r26,24
	ctx.r9.u64 = r26.u32 & 0xFF;
	// and r26,r10,r9
	r26.u64 = ctx.r10.u64 & ctx.r9.u64;
loc_821ECCD0:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eccf4
	if (cr6.eq) goto loc_821ECCF4;
	// slw r11,r22,r24
	r11.u64 = r24.u8 & 0x20 ? 0 : (r22.u32 << (r24.u8 & 0x3F));
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// and r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ctx.r10.u64;
	// std r7,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r7.u64);
loc_821ECCF4:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,14
	r25.s64 = r25.s64 + 14;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x821ecb54
	if (cr6.lt) goto loc_821ECB54;
	// b 0x821ed034
	goto loc_821ED034;
loc_821ECD10:
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eced4
	if (!cr6.eq) goto loc_821ECED4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x821eced4
	if (!cr6.eq) goto loc_821ECED4;
	// lbz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 38);
	// li r22,1
	r22.s64 = 1;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821ece64
	if (!cr6.eq) goto loc_821ECE64;
	// lwz r11,34(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// mr r27,r30
	r27.u64 = r30.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// lfs f30,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f30.f64 = double(temp.f32);
	// ble cr6,0x821ececc
	if (!cr6.gt) goto loc_821ECECC;
	// mr r26,r30
	r26.u64 = r30.u64;
loc_821ECD60:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r11,r26
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// bl 0x82547b90
	ctx.lr = 0x821ECD6C;
	sub_82547B90(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ece48
	if (!cr6.eq) goto loc_821ECE48;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// bl 0x82547f00
	ctx.lr = 0x821ECD8C;
	sub_82547F00(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ecdac
	if (!cr6.eq) goto loc_821ECDAC;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r22,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r22.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821ECDAC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// bl 0x82547fa0
	ctx.lr = 0x821ECDC0;
	sub_82547FA0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ecde0
	if (!cr6.eq) goto loc_821ECDE0;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r22,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r22.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821ECDE0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f1,24(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// bl 0x82547fe8
	ctx.lr = 0x821ECDF4;
	sub_82547FE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ece14
	if (!cr6.eq) goto loc_821ECE14;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r22,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r22.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821ECE14:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// lwzx r3,r11,r26
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// bl 0x82548088
	ctx.lr = 0x821ECE28;
	sub_82548088(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ece48
	if (!cr6.eq) goto loc_821ECE48;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r9,r22,r11
	ctx.r9.u64 = r11.u8 & 0x40 ? 0 : (r22.u64 << (r11.u8 & 0x7F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r8.u64);
loc_821ECE48:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x821ecd60
	if (cr6.lt) goto loc_821ECD60;
	// stb r22,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r22.u8);
	// b 0x821ed034
	goto loc_821ED034;
loc_821ECE64:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r26,r30
	r26.u64 = r30.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ececc
	if (!cr6.gt) goto loc_821ECECC;
	// mr r27,r30
	r27.u64 = r30.u64;
loc_821ECE78:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f1,f26
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f26.f64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82547c58
	ctx.lr = 0x821ECE88;
	sub_82547C58(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f1,f26
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f26.f64;
	// lwzx r3,r10,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// bl 0x82547cf8
	ctx.lr = 0x821ECE98;
	sub_82547CF8(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f1,24(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r9,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// bl 0x82547dd0
	ctx.lr = 0x821ECEA8;
	sub_82547DD0(ctx, base);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f1,f26
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f26.f64;
	// lwzx r3,r8,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r27.u32);
	// bl 0x82547e68
	ctx.lr = 0x821ECEB8;
	sub_82547E68(ctx, base);
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r26,r7
	cr6.compare<int32_t>(r26.s32, ctx.r7.s32, xer);
	// blt cr6,0x821ece78
	if (cr6.lt) goto loc_821ECE78;
loc_821ECECC:
	// stb r22,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r22.u8);
	// b 0x821ed034
	goto loc_821ED034;
loc_821ECED4:
	// ld r11,64(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x821ed034
	if (cr6.eq) goto loc_821ED034;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r25,r30
	r25.u64 = r30.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,34(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// stw r9,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// lfs f30,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f30.f64 = double(temp.f32);
	// ble cr6,0x821ed034
	if (!cr6.gt) goto loc_821ED034;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r27,r30
	r27.u64 = r30.u64;
	// li r22,1
	r22.s64 = 1;
	// lis r23,-32114
	r23.s64 = -2104623104;
	// lfs f29,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	f29.f64 = double(temp.f32);
loc_821ECF14:
	// extsw r11,r25
	r11.s64 = r25.s32;
	// ld r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// sld r24,r22,r11
	r24.u64 = r11.u8 & 0x40 ? 0 : (r22.u64 << (r11.u8 & 0x7F));
	// and r9,r10,r24
	ctx.r9.u64 = ctx.r10.u64 & r24.u64;
	// cmpldi cr6,r9,0
	cr6.compare<uint64_t>(ctx.r9.u64, 0, xer);
	// beq cr6,0x821ed020
	if (cr6.eq) goto loc_821ED020;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-32456(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -32456);
	// lwzx r4,r11,r27
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x825479f8
	ctx.lr = 0x821ECF3C;
	sub_825479F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821ed020
	if (!cr6.eq) goto loc_821ED020;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r26,r22
	r26.u64 = r22.u64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x821ecf70
	if (cr6.eq) goto loc_821ECF70;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82547f60
	ctx.lr = 0x821ECF6C;
	sub_82547F60(ctx, base);
	// clrlwi r26,r3,31
	r26.u64 = ctx.r3.u32 & 0x1;
loc_821ECF70:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x821ecf9c
	if (cr6.eq) goto loc_821ECF9C;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82547fa0
	ctx.lr = 0x821ECF90;
	sub_82547FA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// and r26,r11,r10
	r26.u64 = r11.u64 & ctx.r10.u64;
loc_821ECF9C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82548128
	ctx.lr = 0x821ECFA8;
	sub_82548128(ctx, base);
	// lfs f0,24(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x821ecfd4
	if (cr6.eq) goto loc_821ECFD4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82547fe8
	ctx.lr = 0x821ECFC8;
	sub_82547FE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r26,24
	ctx.r9.u64 = r26.u32 & 0xFF;
	// and r26,r10,r9
	r26.u64 = ctx.r10.u64 & ctx.r9.u64;
loc_821ECFD4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x825481b8
	ctx.lr = 0x821ECFE0;
	sub_825481B8(ctx, base);
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// ble cr6,0x821ed008
	if (!cr6.gt) goto loc_821ED008;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// bl 0x82548088
	ctx.lr = 0x821ECFFC;
	sub_82548088(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r26,24
	ctx.r9.u64 = r26.u32 & 0xFF;
	// and r26,r10,r9
	r26.u64 = ctx.r10.u64 & ctx.r9.u64;
loc_821ED008:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ed020
	if (cr6.eq) goto loc_821ED020;
	// ld r11,64(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 64);
	// and r10,r11,r24
	ctx.r10.u64 = r11.u64 & r24.u64;
	// std r10,64(r31)
	PPC_STORE_U64(r31.u32 + 64, ctx.r10.u64);
loc_821ED020:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x821ecf14
	if (cr6.lt) goto loc_821ECF14;
loc_821ED034:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 38);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821ed194
	if (cr6.eq) goto loc_821ED194;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r28,r30
	r28.u64 = r30.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ed194
	if (!cr6.gt) goto loc_821ED194;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r30
	r29.u64 = r30.u64;
	// lfs f0,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f30,14992(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14992);
	f30.f64 = double(temp.f32);
loc_821ED070:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r1,152
	ctx.r10.s64 = ctx.r1.s64 + 152;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// add r8,r30,r11
	ctx.r8.u64 = r30.u64 + r11.u64;
	// lvlx v1,0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lhz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 52);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// std r5,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r5.u64);
	// lfd f0,168(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f29,f12,f25
	f29.f64 = double(float(ctx.f12.f64 * f25.f64));
	// fmuls f11,f29,f30
	ctx.f11.f64 = double(float(f29.f64 * f30.f64));
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvlx v2,0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// bl 0x821476b0
	ctx.lr = 0x821ED0B0;
	sub_821476B0(ctx, base);
	// lfs f0,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// fsubs f10,f29,f0
	ctx.f10.f64 = double(float(f29.f64 - f0.f64));
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f9,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// stvx128 v1,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f8.f64 = double(temp.f32);
	// lwzx r3,r3,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r29.u32);
	// fsel f7,f10,f8,f26
	ctx.f7.f64 = ctx.f10.f64 >= 0.0 ? ctx.f8.f64 : f26.f64;
	// fsubs f6,f7,f31
	ctx.f6.f64 = double(float(ctx.f7.f64 - f31.f64));
	// fmadds f1,f6,f9,f31
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f9.f64 + f31.f64));
	// bl 0x82547cb0
	ctx.lr = 0x821ED0E0;
	sub_82547CB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f5,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwzx r3,r9,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// lwz r10,54(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 54);
	// stw r10,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// lfs f4,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f3,f4,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 - f31.f64));
	// fmadds f1,f3,f5,f31
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f5.f64 + f31.f64));
	// bl 0x82547d88
	ctx.lr = 0x821ED10C;
	sub_82547D88(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,24(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 24);
	f0.f64 = double(temp.f32);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f2,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// add r8,r30,r11
	ctx.r8.u64 = r30.u64 + r11.u64;
	// lwzx r3,r6,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + r29.u32);
	// lhz r7,58(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 58);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// std r5,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r5.u64);
	// lfd f1,176(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// fcfid f13,f1
	ctx.f13.f64 = double(ctx.f1.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fmadds f1,f11,f2,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f2.f64 + f0.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821ED148;
	sub_82547DD0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f10,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// add r4,r30,r11
	ctx.r4.u64 = r30.u64 + r11.u64;
	// lhz r3,60(r4)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r4.u32 + 60);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r10,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.r10.u64);
	// lfd f9,184(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 184);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// fmuls f1,f7,f10
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// bl 0x82547e68
	ctx.lr = 0x821ED17C;
	sub_82547E68(ctx, base);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,14
	r30.s64 = r30.s64 + 14;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r9
	cr6.compare<int32_t>(r28.s32, ctx.r9.s32, xer);
	// blt cr6,0x821ed070
	if (cr6.lt) goto loc_821ED070;
loc_821ED194:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821ED1A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ed1c8
	if (cr6.eq) goto loc_821ED1C8;
	// lwz r11,10(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821ed1c8
	if (cr6.eq) goto loc_821ED1C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ec060
	ctx.lr = 0x821ED1C8;
	sub_821EC060(ctx, base);
loc_821ED1C8:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dba18
	ctx.lr = 0x821ED1D4;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_821ED1D8"))) PPC_WEAK_FUNC(sub_821ED1D8);
PPC_FUNC_IMPL(__imp__sub_821ED1D8) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82548ac0
	ctx.lr = 0x821ED1F0;
	sub_82548AC0(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r8,r10,-29452
	ctx.r8.s64 = ctx.r10.s64 + -29452;
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r9,20
	ctx.r9.s64 = 20;
	// lfs f13,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r8,-1
	ctx.r8.s64 = -1;
loc_821ED21C:
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// stfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// stfs f13,20(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// addi r5,r7,0
	ctx.r5.s64 = ctx.r7.s64 + 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r4,r6,0
	ctx.r4.s64 = ctx.r6.s64 + 0;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// stw r4,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r4.u32);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// stw r10,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r10.u32);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r10.u32);
	// std r10,64(r11)
	PPC_STORE_U64(r11.u32 + 64, ctx.r10.u64);
	// stb r10,72(r11)
	PPC_STORE_U8(r11.u32 + 72, ctx.r10.u8);
	// stb r10,73(r11)
	PPC_STORE_U8(r11.u32 + 73, ctx.r10.u8);
	// stb r10,74(r11)
	PPC_STORE_U8(r11.u32 + 74, ctx.r10.u8);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// bge 0x821ed21c
	if (!cr0.lt) goto loc_821ED21C;
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

__attribute__((alias("__imp__sub_821ED29C"))) PPC_WEAK_FUNC(sub_821ED29C);
PPC_FUNC_IMPL(__imp__sub_821ED29C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821ED2A0"))) PPC_WEAK_FUNC(sub_821ED2A0);
PPC_FUNC_IMPL(__imp__sub_821ED2A0) {
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
	ctx.lr = 0x821ED2A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r11,-29452
	ctx.r10.s64 = r11.s64 + -29452;
	// lwz r3,1728(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 1728);
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ed2cc
	if (cr6.eq) goto loc_821ED2CC;
	// bl 0x82130588
	ctx.lr = 0x821ED2CC;
	sub_82130588(ctx, base);
loc_821ED2CC:
	// lwz r3,1732(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 1732);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ed2dc
	if (cr6.eq) goto loc_821ED2DC;
	// bl 0x82130588
	ctx.lr = 0x821ED2DC;
	sub_82130588(ctx, base);
loc_821ED2DC:
	// lwz r3,1736(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 1736);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ed2ec
	if (cr6.eq) goto loc_821ED2EC;
	// bl 0x82130588
	ctx.lr = 0x821ED2EC;
	sub_82130588(ctx, base);
loc_821ED2EC:
	// addi r11,r27,1720
	r11.s64 = r27.s64 + 1720;
	// li r28,20
	r28.s64 = 20;
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// li r30,0
	r30.s64 = 0;
	// lis r29,-32114
	r29.s64 = -2104623104;
loc_821ED300:
	// addi r31,r31,-80
	r31.s64 = r31.s64 + -80;
	// lbz r11,66(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 66);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ed34c
	if (cr6.eq) goto loc_821ED34C;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821ed330
	if (cr6.eq) goto loc_821ED330;
	// lwz r3,-32456(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -32456);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x825478b0
	ctx.lr = 0x821ED328;
	sub_825478B0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821ED330;
	sub_82130588(ctx, base);
loc_821ED330:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ed340
	if (cr6.eq) goto loc_821ED340;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_821ED340:
	// std r30,56(r31)
	PPC_STORE_U64(r31.u32 + 56, r30.u64);
	// stb r30,65(r31)
	PPC_STORE_U8(r31.u32 + 65, r30.u8);
	// stb r30,66(r31)
	PPC_STORE_U8(r31.u32 + 66, r30.u8);
loc_821ED34C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x821ed300
	if (!cr0.lt) goto loc_821ED300;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82548b50
	ctx.lr = 0x821ED35C;
	sub_82548B50(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821ED364"))) PPC_WEAK_FUNC(sub_821ED364);
PPC_FUNC_IMPL(__imp__sub_821ED364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821ED368"))) PPC_WEAK_FUNC(sub_821ED368);
PPC_FUNC_IMPL(__imp__sub_821ED368) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x821ED370;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,1724(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1724);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r29,r11,40
	r29.s64 = r11.s64 + 40;
	// beq cr6,0x821ed3c8
	if (cr6.eq) goto loc_821ED3C8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 38);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821ed40c
	if (cr6.eq) goto loc_821ED40C;
loc_821ED3C8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ebf38
	ctx.lr = 0x821ED3D0;
	sub_821EBF38(ctx, base);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ec620
	ctx.lr = 0x821ED3EC;
	sub_821EC620(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ed40c
	if (cr6.eq) goto loc_821ED40C;
	// li r11,1
	r11.s64 = 1;
	// lwz r10,1740(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1740);
	// slw r9,r11,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 << (r30.u8 & 0x3F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,1740(r31)
	PPC_STORE_U32(r31.u32 + 1740, ctx.r8.u32);
loc_821ED40C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821ED418"))) PPC_WEAK_FUNC(sub_821ED418);
PPC_FUNC_IMPL(__imp__sub_821ED418) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	ctx.lr = 0x821ED420;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r28,7
	cr6.compare<uint32_t>(r28.u32, 7, xer);
	// stb r29,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, r29.u8);
	// bgt cr6,0x821ee038
	if (cr6.gt) goto loc_821EE038;
	// lis r12,-32225
	r12.s64 = -2111897600;
	// addi r12,r12,-11176
	r12.s64 = r12.s64 + -11176;
	// rlwinm r0,r28,2,0,29
	r0.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r28.u64) {
	case 0:
		goto loc_821ED478;
	case 1:
		goto loc_821ED6C8;
	case 2:
		goto loc_821ED918;
	case 3:
		goto loc_821EDA5C;
	case 4:
		goto loc_821EDBA0;
	case 5:
		goto loc_821EDCE4;
	case 6:
		goto loc_821EDE28;
	case 7:
		goto loc_821EDF3C;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-11144(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + -11144);
	// lwz r16,-10552(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + -10552);
	// lwz r16,-9960(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + -9960);
	// lwz r16,-9636(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + -9636);
	// lwz r16,-9312(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + -9312);
	// lwz r16,-8988(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + -8988);
	// lwz r16,-8664(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + -8664);
	// lwz r16,-8388(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + -8388);
loc_821ED478:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// lwz r3,-12252(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12252);
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// lwz r8,1740(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821ed4ac
	if (cr6.eq) goto loc_821ED4AC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x821ED4AC;
	sub_821EC468(ctx, base);
loc_821ED4AC:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x821ED4B8;
	sub_821E6828(ctx, base);
	// lbz r11,1756(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1756);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// beq cr6,0x821ed5c8
	if (cr6.eq) goto loc_821ED5C8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_821ED4D8:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mulli r10,r29,58
	ctx.r10.s64 = r29.s64 * 58;
	// lwz r9,1728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r30,29
	r11.s64 = r30.s64 + 29;
	// lhz r8,29(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 29);
	// lwzx r3,r9,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547c58
	ctx.lr = 0x821ED514;
	sub_82547C58(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lhz r8,31(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 31);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821ED550;
	sub_82547DD0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lhz r8,33(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 33);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f9,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// bl 0x82547e68
	ctx.lr = 0x821ED58C;
	sub_82547E68(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x821ed4d8
	if (cr6.lt) goto loc_821ED4D8;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821ED5C8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_821ED5D8:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mulli r10,r29,58
	ctx.r10.s64 = r29.s64 * 58;
	// lwz r9,1728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r30,23
	r11.s64 = r30.s64 + 23;
	// lhz r8,23(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 23);
	// lwzx r3,r9,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547c58
	ctx.lr = 0x821ED614;
	sub_82547C58(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lhz r8,25(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 25);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821ED650;
	sub_82547DD0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lhz r8,27(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 27);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// bl 0x82547e68
	ctx.lr = 0x821ED68C;
	sub_82547E68(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x821ed5d8
	if (cr6.lt) goto loc_821ED5D8;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821ED6C8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// lwz r3,-12252(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12252);
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// lwz r8,1740(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821ed6fc
	if (cr6.eq) goto loc_821ED6FC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x821ED6FC;
	sub_821EC468(ctx, base);
loc_821ED6FC:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x821ED708;
	sub_821E6828(ctx, base);
	// lbz r11,1756(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1756);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// beq cr6,0x821ed818
	if (cr6.eq) goto loc_821ED818;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_821ED728:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mulli r10,r29,58
	ctx.r10.s64 = r29.s64 * 58;
	// lwz r9,1728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r30,41
	r11.s64 = r30.s64 + 41;
	// lhz r8,41(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 41);
	// lwzx r3,r9,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547c58
	ctx.lr = 0x821ED764;
	sub_82547C58(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lhz r8,43(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 43);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821ED7A0;
	sub_82547DD0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lhz r8,45(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 45);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// bl 0x82547e68
	ctx.lr = 0x821ED7DC;
	sub_82547E68(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x821ed728
	if (cr6.lt) goto loc_821ED728;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821ED818:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_821ED828:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mulli r10,r29,58
	ctx.r10.s64 = r29.s64 * 58;
	// lwz r9,1728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r30,35
	r11.s64 = r30.s64 + 35;
	// lhz r8,35(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 35);
	// lwzx r3,r9,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547c58
	ctx.lr = 0x821ED864;
	sub_82547C58(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lhz r8,37(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 37);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821ED8A0;
	sub_82547DD0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lhz r8,39(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 39);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// bl 0x82547e68
	ctx.lr = 0x821ED8DC;
	sub_82547E68(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x821ed828
	if (cr6.lt) goto loc_821ED828;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821ED918:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// lwz r3,-12252(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12252);
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// lwz r8,1740(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821ed94c
	if (cr6.eq) goto loc_821ED94C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x821ED94C;
	sub_821EC468(ctx, base);
loc_821ED94C:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x821ED958;
	sub_821E6828(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_821ED96C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mulli r10,r29,58
	ctx.r10.s64 = r29.s64 * 58;
	// lwz r9,1728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r30,47
	r11.s64 = r30.s64 + 47;
	// lhz r8,47(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 47);
	// lwzx r3,r9,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547c58
	ctx.lr = 0x821ED9A8;
	sub_82547C58(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lhz r8,49(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 49);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821ED9E4;
	sub_82547DD0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lhz r8,51(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 51);
	// lwzx r3,r3,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// bl 0x82547e68
	ctx.lr = 0x821EDA20;
	sub_82547E68(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x821ed96c
	if (cr6.lt) goto loc_821ED96C;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821EDA5C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// lwz r3,-12252(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12252);
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// lwz r8,1740(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821eda90
	if (cr6.eq) goto loc_821EDA90;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x821EDA90;
	sub_821EC468(ctx, base);
loc_821EDA90:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x821EDA9C;
	sub_821E6828(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_821EDAB0:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mulli r10,r29,58
	ctx.r10.s64 = r29.s64 * 58;
	// lwz r9,1728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r30,53
	r11.s64 = r30.s64 + 53;
	// lhz r8,53(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 53);
	// lwzx r3,r27,r9
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r9.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547c58
	ctx.lr = 0x821EDAEC;
	sub_82547C58(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lhz r8,55(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 55);
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821EDB28;
	sub_82547DD0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lhz r8,57(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 57);
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// bl 0x82547e68
	ctx.lr = 0x821EDB64;
	sub_82547E68(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x821edab0
	if (cr6.lt) goto loc_821EDAB0;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821EDBA0:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// lwz r3,-12252(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12252);
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// lwz r8,1740(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821edbd4
	if (cr6.eq) goto loc_821EDBD4;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x821EDBD4;
	sub_821EC468(ctx, base);
loc_821EDBD4:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x821EDBE0;
	sub_821E6828(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_821EDBF4:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mulli r10,r29,58
	ctx.r10.s64 = r29.s64 * 58;
	// lwz r9,1728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r30,59
	r11.s64 = r30.s64 + 59;
	// lhz r8,59(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 59);
	// lwzx r3,r27,r9
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r9.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547c58
	ctx.lr = 0x821EDC30;
	sub_82547C58(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lhz r8,61(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 61);
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821EDC6C;
	sub_82547DD0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lhz r8,63(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 63);
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// bl 0x82547e68
	ctx.lr = 0x821EDCA8;
	sub_82547E68(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x821edbf4
	if (cr6.lt) goto loc_821EDBF4;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821EDCE4:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// lwz r3,-12252(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12252);
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// lwz r8,1740(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821edd18
	if (cr6.eq) goto loc_821EDD18;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x821EDD18;
	sub_821EC468(ctx, base);
loc_821EDD18:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x821EDD24;
	sub_821E6828(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_821EDD38:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mulli r10,r29,58
	ctx.r10.s64 = r29.s64 * 58;
	// lwz r9,1728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r30,65
	r11.s64 = r30.s64 + 65;
	// lhz r8,65(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 65);
	// lwzx r3,r27,r9
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r9.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547c58
	ctx.lr = 0x821EDD74;
	sub_82547C58(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// lhz r8,67(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 67);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821EDDB0;
	sub_82547DD0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// lhz r8,69(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 69);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// bl 0x82547e68
	ctx.lr = 0x821EDDEC;
	sub_82547E68(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x821edd38
	if (cr6.lt) goto loc_821EDD38;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821EDE28:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_821EDE4C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mulli r10,r29,58
	ctx.r10.s64 = r29.s64 * 58;
	// lwz r9,1728(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r30,71
	r11.s64 = r30.s64 + 71;
	// lhz r8,71(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 71);
	// lwzx r3,r27,r9
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r9.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x82547c58
	ctx.lr = 0x821EDE88;
	sub_82547C58(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lhz r8,73(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 73);
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f1,f10
	ctx.f1.f64 = double(float(ctx.f10.f64));
	// bl 0x82547dd0
	ctx.lr = 0x821EDEC4;
	sub_82547DD0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lhz r8,75(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 75);
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// bl 0x82547e68
	ctx.lr = 0x821EDF00;
	sub_82547E68(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lbz r4,1757(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 | ctx.r4.u64;
	// stb r9,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r9.u8);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x821ede4c
	if (cr6.lt) goto loc_821EDE4C;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821EDF3C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// lwz r3,-12252(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12252);
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// lwz r8,1740(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821edf70
	if (cr6.eq) goto loc_821EDF70;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x821EDF70;
	sub_821EC468(ctx, base);
loc_821EDF70:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x821EDF7C;
	sub_821E6828(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r29
	r30.u64 = r29.u64;
	// lis r29,-32254
	r29.s64 = -2113798144;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_821EDF98:
	// lwz r11,1728(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// rlwinm r27,r30,2,0,29
	r27.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r3,r27,r11
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// bl 0x82547c58
	ctx.lr = 0x821EDFAC;
	sub_82547C58(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lbz r9,1757(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r8,1728(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// lfs f1,-29732(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -29732);
	ctx.f1.f64 = double(temp.f32);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// or r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 | ctx.r9.u64;
	// stb r5,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r5.u8);
	// lwzx r3,r27,r8
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r8.u32);
	// bl 0x82547dd0
	ctx.lr = 0x821EDFD4;
	sub_82547DD0(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// lbz r11,1757(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r10,1728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// rlwinm r9,r3,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | r11.u64;
	// stb r8,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r8.u8);
	// lwzx r3,r27,r10
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// bl 0x82547e68
	ctx.lr = 0x821EDFFC;
	sub_82547E68(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lbz r6,1757(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r5,r30,1
	ctx.r5.s64 = r30.s64 + 1;
	// cntlzw r4,r7
	ctx.r4.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// clrlwi r30,r5,24
	r30.u64 = ctx.r5.u32 & 0xFF;
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// or r11,r3,r6
	r11.u64 = ctx.r3.u64 | ctx.r6.u64;
	// stb r11,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, r11.u8);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x821edf98
	if (cr6.lt) goto loc_821EDF98;
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_821EE038:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// bl 0x821e6828
	ctx.lr = 0x821EE054;
	sub_821E6828(ctx, base);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x821ee100
	if (!cr6.gt) goto loc_821EE100;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r29
	r30.u64 = r29.u64;
	// lis r29,-32254
	r29.s64 = -2113798144;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_821EE070:
	// lwz r11,1728(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// rlwinm r27,r30,2,0,29
	r27.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r3,r27,r11
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// bl 0x82547c58
	ctx.lr = 0x821EE084;
	sub_82547C58(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lbz r9,1757(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r8,1728(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// lfs f1,-29732(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -29732);
	ctx.f1.f64 = double(temp.f32);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// or r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 | ctx.r9.u64;
	// stb r5,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r5.u8);
	// lwzx r3,r27,r8
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r8.u32);
	// bl 0x82547dd0
	ctx.lr = 0x821EE0AC;
	sub_82547DD0(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// lbz r11,1757(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// lwz r10,1728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// rlwinm r9,r3,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | r11.u64;
	// stb r8,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, ctx.r8.u8);
	// lwzx r3,r27,r10
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// bl 0x82547e68
	ctx.lr = 0x821EE0D4;
	sub_82547E68(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lbz r5,1757(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 1757);
	// addi r4,r30,1
	ctx.r4.s64 = r30.s64 + 1;
	// rlwinm r3,r6,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// clrlwi r30,r4,24
	r30.u64 = ctx.r4.u32 & 0xFF;
	// or r11,r3,r5
	r11.u64 = ctx.r3.u64 | ctx.r5.u64;
	// stb r11,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, r11.u8);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x821ee070
	if (cr6.lt) goto loc_821EE070;
loc_821EE100:
	// stw r28,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821EE110"))) PPC_WEAK_FUNC(sub_821EE110);
PPC_FUNC_IMPL(__imp__sub_821EE110) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x821EE118;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d4
	ctx.lr = 0x821EE120;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,1744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1744);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x821ee148
	if (!cr6.eq) goto loc_821EE148;
	// fmr f28,f31
	f28.f64 = f31.f64;
	// fmr f27,f31
	f27.f64 = f31.f64;
	// b 0x821ee150
	goto loc_821EE150;
loc_821EE148:
	// lfs f28,1748(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1748);
	f28.f64 = double(temp.f32);
	// lfs f27,1752(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1752);
	f27.f64 = double(temp.f32);
loc_821EE150:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821ee35c
	if (!cr6.gt) goto loc_821EE35C;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r30,0
	r30.s64 = 0;
	// lfs f29,11368(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11368);
	f29.f64 = double(temp.f32);
	// addi r28,r11,29952
	r28.s64 = r11.s64 + 29952;
	// lfs f30,11360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11360);
	f30.f64 = double(temp.f32);
	// addi r29,r10,-29776
	r29.s64 = ctx.r10.s64 + -29776;
loc_821EE180:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mulli r10,r30,28
	ctx.r10.s64 = r30.s64 * 28;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,15(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 15);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f28,f0
	cr6.compare(f28.f64, f0.f64);
	// bgt cr6,0x821ee1c8
	if (cr6.gt) goto loc_821EE1C8;
	// lwz r11,23(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 23);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f27,f0
	cr6.compare(f27.f64, f0.f64);
	// bgt cr6,0x821ee1c8
	if (cr6.gt) goto loc_821EE1C8;
	// lhz r11,31(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 31);
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// std r8,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// lfd f0,120(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// b 0x821ee2a0
	goto loc_821EE2A0;
loc_821EE1C8:
	// lwz r11,19(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 19);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f28,f0
	cr6.compare(f28.f64, f0.f64);
	// bge cr6,0x821ee290
	if (!cr6.lt) goto loc_821EE290;
	// lwz r11,27(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 27);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// lfs f0,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f27,f0
	cr6.compare(f27.f64, f0.f64);
	// bge cr6,0x821ee290
	if (!cr6.lt) goto loc_821EE290;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r8,19(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 19);
	// lwz r3,23(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 23);
	// lwz r7,15(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 15);
	// lhz r6,31(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 31);
	// lhz r5,33(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 33);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lwz r8,27(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 27);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// extsh r7,r6
	ctx.r7.s64 = ctx.r6.s16;
	// extsh r6,r5
	ctx.r6.s64 = ctx.r5.s16;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// std r7,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// lfd f12,128(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// lfs f9,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// std r6,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r6.u64);
	// lfd f11,136(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fsubs f5,f0,f13
	ctx.f5.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsubs f6,f28,f13
	ctx.f6.f64 = double(float(f28.f64 - ctx.f13.f64));
	// fdivs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// fcfid f4,f12
	ctx.f4.f64 = double(ctx.f12.s64);
	// fcfid f3,f11
	ctx.f3.f64 = double(ctx.f11.s64);
	// fdivs f1,f6,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 / ctx.f5.f64));
	// fsubs f7,f27,f8
	ctx.f7.f64 = double(float(f27.f64 - ctx.f8.f64));
	// frsp f0,f4
	f0.f64 = double(float(ctx.f4.f64));
	// frsp f13,f3
	ctx.f13.f64 = double(float(ctx.f3.f64));
	// fsubs f2,f7,f10
	ctx.f2.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f12,f1,f2
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fsel f10,f12,f1,f2
	ctx.f10.f64 = ctx.f12.f64 >= 0.0 ? ctx.f1.f64 : ctx.f2.f64;
	// fmadds f9,f10,f11,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + f0.f64));
	// fmuls f0,f9,f30
	f0.f64 = double(float(ctx.f9.f64 * f30.f64));
	// b 0x821ee2ac
	goto loc_821EE2AC;
loc_821EE290:
	// lhz r11,33(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 33);
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// std r8,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r8.u64);
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
loc_821EE2A0:
	// fcfid f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f12,f30
	f0.f64 = double(float(ctx.f12.f64 * f30.f64));
loc_821EE2AC:
	// lwz r10,1732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1732);
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stfs f31,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f31,168(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,35(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 35);
	// lfs f13,24(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lfs f12,20(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,160(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	v61.f32[0] = log2f(v62.f32[0]);
	v61.f32[1] = log2f(v62.f32[1]);
	v61.f32[2] = log2f(v62.f32[2]);
	v61.f32[3] = log2f(v62.f32[3]);
	// vmulfp128 v60,v61,v63
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// lfs f11,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f29
	ctx.f8.f64 = double(float(ctx.f9.f64 * f29.f64));
	// fsel f1,f10,f8,f12
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f8.f64 : ctx.f12.f64;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x821ee324
	if (!cr6.lt) goto loc_821EE324;
	// lfs f13,92(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f13,f11,f1
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f1.f64));
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x821ee340
	if (!cr6.gt) goto loc_821EE340;
	// b 0x821ee33c
	goto loc_821EE33C;
loc_821EE324:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x821ee340
	if (!cr6.gt) goto loc_821EE340;
	// lfs f13,92(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f1,f13,f11,f1
	ctx.f1.f64 = double(float(-(ctx.f13.f64 * ctx.f11.f64 - ctx.f1.f64)));
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x821ee340
	if (!cr6.lt) goto loc_821EE340;
loc_821EE33C:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
loc_821EE340:
	// bl 0x82547c58
	ctx.lr = 0x821EE344;
	sub_82547C58(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x821ee180
	if (cr6.lt) goto loc_821EE180;
loc_821EE35C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x821EE368;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821EE36C"))) PPC_WEAK_FUNC(sub_821EE36C);
PPC_FUNC_IMPL(__imp__sub_821EE36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EE370"))) PPC_WEAK_FUNC(sub_821EE370);
PPC_FUNC_IMPL(__imp__sub_821EE370) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x821EE378;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821ee424
	if (cr6.eq) goto loc_821EE424;
	// lwz r11,1724(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1724);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee3b4
	if (cr6.eq) goto loc_821EE3B4;
	// lbz r11,38(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 38);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ee424
	if (cr6.eq) goto loc_821EE424;
loc_821EE3B4:
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x821EE3BC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ee3d0
	if (cr6.eq) goto loc_821EE3D0;
	// bl 0x821ebec0
	ctx.lr = 0x821EE3C8;
	sub_821EBEC0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x821ee3d4
	goto loc_821EE3D4;
loc_821EE3D0:
	// li r31,0
	r31.s64 = 0;
loc_821EE3D4:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ebf38
	ctx.lr = 0x821EE3E0;
	sub_821EBF38(ctx, base);
	// lwz r11,1720(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1720);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r31,1720(r30)
	PPC_STORE_U32(r30.u32 + 1720, r31.u32);
	// beq cr6,0x821ee3fc
	if (cr6.eq) goto loc_821EE3FC;
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// stw r28,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r28.u32);
loc_821EE3FC:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r11,0
	ctx.r7.s64 = r11.s64 + 0;
	// addi r6,r10,0
	ctx.r6.s64 = ctx.r10.s64 + 0;
	// addi r5,r9,0
	ctx.r5.s64 = ctx.r9.s64 + 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ec620
	ctx.lr = 0x821EE424;
	sub_821EC620(ctx, base);
loc_821EE424:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821EE430"))) PPC_WEAK_FUNC(sub_821EE430);
PPC_FUNC_IMPL(__imp__sub_821EE430) {
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
	// li r3,1760
	ctx.r3.s64 = 1760;
	// bl 0x82130528
	ctx.lr = 0x821EE444;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ee468
	if (cr6.eq) goto loc_821EE468;
	// bl 0x821ed1d8
	ctx.lr = 0x821EE450;
	sub_821ED1D8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-12252(r11)
	PPC_STORE_U32(r11.u32 + -12252, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821EE468:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12252(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12252, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EE484"))) PPC_WEAK_FUNC(sub_821EE484);
PPC_FUNC_IMPL(__imp__sub_821EE484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EE488"))) PPC_WEAK_FUNC(sub_821EE488);
PPC_FUNC_IMPL(__imp__sub_821EE488) {
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
	// bl 0x821ed2a0
	ctx.lr = 0x821EE4A8;
	sub_821ED2A0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee4c0
	if (cr6.eq) goto loc_821EE4C0;
	// bl 0x82130588
	ctx.lr = 0x821EE4BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821EE4C0:
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

__attribute__((alias("__imp__sub_821EE4D8"))) PPC_WEAK_FUNC(sub_821EE4D8);
PPC_FUNC_IMPL(__imp__sub_821EE4D8) {
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
	ctx.lr = 0x821EE4E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// addi r31,r27,40
	r31.s64 = r27.s64 + 40;
	// mr r29,r26
	r29.u64 = r26.u64;
	// li r28,1
	r28.s64 = 1;
loc_821EE4F8:
	// lwz r11,1740(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1740);
	// slw r30,r28,r29
	r30.u64 = r29.u8 & 0x20 ? 0 : (r28.u32 << (r29.u8 & 0x3F));
	// and r10,r30,r11
	ctx.r10.u64 = r30.u64 & r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ee588
	if (cr6.eq) goto loc_821EE588;
	// lwz r11,1724(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1724);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee520
	if (cr6.eq) goto loc_821EE520;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x821ee54c
	if (!cr6.eq) goto loc_821EE54C;
loc_821EE520:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 38);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821ee560
	if (cr6.eq) goto loc_821EE560;
	// lwz r11,39(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 39);
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x821ee560
	if (cr6.lt) goto loc_821EE560;
loc_821EE54C:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ec468
	ctx.lr = 0x821EE55C;
	sub_821EC468(ctx, base);
	// b 0x821ee5a4
	goto loc_821EE5A4;
loc_821EE560:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821eca10
	ctx.lr = 0x821EE568;
	sub_821ECA10(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x821ee5a4
	if (cr6.gt) goto loc_821EE5A4;
	// lwz r11,1740(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1740);
	// andc r10,r11,r30
	ctx.r10.u64 = r11.u64 & ~r30.u64;
	// stw r10,1740(r27)
	PPC_STORE_U32(r27.u32 + 1740, ctx.r10.u32);
	// b 0x821ee5a4
	goto loc_821EE5A4;
loc_821EE588:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ec380
	ctx.lr = 0x821EE590;
	sub_821EC380(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee5a4
	if (cr6.eq) goto loc_821EE5A4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ebfe8
	ctx.lr = 0x821EE5A4;
	sub_821EBFE8(ctx, base);
loc_821EE5A4:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// cmpwi cr6,r29,21
	cr6.compare<int32_t>(r29.s32, 21, xer);
	// blt cr6,0x821ee4f8
	if (cr6.lt) goto loc_821EE4F8;
	// lwz r31,1720(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 1720);
	// mr r29,r26
	r29.u64 = r26.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821ee638
	if (cr6.eq) goto loc_821EE638;
	// lis r28,-32114
	r28.s64 = -2104623104;
loc_821EE5C8:
	// lwz r11,1724(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1724);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee5dc
	if (cr6.eq) goto loc_821EE5DC;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x821ee608
	if (!cr6.eq) goto loc_821EE608;
loc_821EE5DC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 38);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821ee614
	if (cr6.eq) goto loc_821EE614;
	// lwz r11,39(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 39);
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x821ee614
	if (cr6.lt) goto loc_821EE614;
loc_821EE608:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ec060
	ctx.lr = 0x821EE614;
	sub_821EC060(ctx, base);
loc_821EE614:
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee648
	if (cr6.eq) goto loc_821EE648;
	// bl 0x821eca10
	ctx.lr = 0x821EE628;
	sub_821ECA10(ctx, base);
loc_821EE628:
	// mr r29,r31
	r29.u64 = r31.u64;
	// lwz r31,52(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 52);
loc_821EE630:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821ee5c8
	if (!cr6.eq) goto loc_821EE5C8;
loc_821EE638:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ee110
	ctx.lr = 0x821EE640;
	sub_821EE110(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821EE648:
	// bl 0x821ec380
	ctx.lr = 0x821EE64C;
	sub_821EC380(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee628
	if (cr6.eq) goto loc_821EE628;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821ee6c0
	if (cr6.eq) goto loc_821EE6C0;
	// lwz r30,52(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stw r30,52(r29)
	PPC_STORE_U32(r29.u32 + 52, r30.u32);
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee6b0
	if (cr6.eq) goto loc_821EE6B0;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821ee694
	if (cr6.eq) goto loc_821EE694;
	// lwz r3,-32456(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -32456);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x825478b0
	ctx.lr = 0x821EE68C;
	sub_825478B0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x821EE694;
	sub_82130588(ctx, base);
loc_821EE694:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee6a4
	if (cr6.eq) goto loc_821EE6A4;
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
loc_821EE6A4:
	// std r26,64(r31)
	PPC_STORE_U64(r31.u32 + 64, r26.u64);
	// stb r26,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r26.u8);
	// stb r26,74(r31)
	PPC_STORE_U8(r31.u32 + 74, r26.u8);
loc_821EE6B0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821EE6B8;
	sub_82130588(ctx, base);
	// mr r31,r30
	r31.u64 = r30.u64;
	// b 0x821ee630
	goto loc_821EE630;
loc_821EE6C0:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stw r11,1720(r27)
	PPC_STORE_U32(r27.u32 + 1720, r11.u32);
	// lbz r10,74(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821ee710
	if (cr6.eq) goto loc_821EE710;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821ee6f4
	if (cr6.eq) goto loc_821EE6F4;
	// lwz r3,-32456(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -32456);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x825478b0
	ctx.lr = 0x821EE6EC;
	sub_825478B0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x821EE6F4;
	sub_82130588(ctx, base);
loc_821EE6F4:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ee704
	if (cr6.eq) goto loc_821EE704;
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
loc_821EE704:
	// std r26,64(r31)
	PPC_STORE_U64(r31.u32 + 64, r26.u64);
	// stb r26,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r26.u8);
	// stb r26,74(r31)
	PPC_STORE_U8(r31.u32 + 74, r26.u8);
loc_821EE710:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821EE718;
	sub_82130588(ctx, base);
	// lwz r31,1720(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 1720);
	// b 0x821ee630
	goto loc_821EE630;
}

__attribute__((alias("__imp__sub_821EE720"))) PPC_WEAK_FUNC(sub_821EE720);
PPC_FUNC_IMPL(__imp__sub_821EE720) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x821EE750;
	sub_821C9790(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a28
	ctx.lr = 0x821EE760;
	sub_82144A28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x821ee370
	ctx.lr = 0x821EE774;
	sub_821EE370(ctx, base);
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

__attribute__((alias("__imp__sub_821EE790"))) PPC_WEAK_FUNC(sub_821EE790);
PPC_FUNC_IMPL(__imp__sub_821EE790) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x82144a28
	ctx.lr = 0x821EE7C0;
	sub_82144A28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x821ee370
	ctx.lr = 0x821EE7D4;
	sub_821EE370(ctx, base);
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

__attribute__((alias("__imp__sub_821EE7F0"))) PPC_WEAK_FUNC(sub_821EE7F0);
PPC_FUNC_IMPL(__imp__sub_821EE7F0) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,-12252(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x821c9790
	ctx.lr = 0x821EE818;
	sub_821C9790(ctx, base);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,19856
	ctx.r3.s64 = ctx.r9.s64 + 19856;
	// bl 0x82144a28
	ctx.lr = 0x821EE828;
	sub_82144A28(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee370
	ctx.lr = 0x821EE840;
	sub_821EE370(ctx, base);
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

__attribute__((alias("__imp__sub_821EE854"))) PPC_WEAK_FUNC(sub_821EE854);
PPC_FUNC_IMPL(__imp__sub_821EE854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EE858"))) PPC_WEAK_FUNC(sub_821EE858);
PPC_FUNC_IMPL(__imp__sub_821EE858) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x821ec548
	sub_821EC548(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821EE864"))) PPC_WEAK_FUNC(sub_821EE864);
PPC_FUNC_IMPL(__imp__sub_821EE864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EE868"))) PPC_WEAK_FUNC(sub_821EE868);
PPC_FUNC_IMPL(__imp__sub_821EE868) {
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
	ctx.lr = 0x821EE870;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82548ba8
	ctx.lr = 0x821EE87C;
	sub_82548BA8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r27,0
	r27.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r27,1728(r31)
	PPC_STORE_U32(r31.u32 + 1728, r27.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r27,1732(r31)
	PPC_STORE_U32(r31.u32 + 1732, r27.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r27,1736(r31)
	PPC_STORE_U32(r31.u32 + 1736, r27.u32);
	// stfs f0,1748(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1748, temp.u32);
	// stw r27,1740(r31)
	PPC_STORE_U32(r31.u32 + 1740, r27.u32);
	// stfs f0,1752(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1752, temp.u32);
	// stb r27,1756(r31)
	PPC_STORE_U8(r31.u32 + 1756, r27.u8);
	// stb r27,1757(r31)
	PPC_STORE_U8(r31.u32 + 1757, r27.u8);
	// addi r28,r11,19856
	r28.s64 = r11.s64 + 19856;
	// stw r9,1744(r31)
	PPC_STORE_U32(r31.u32 + 1744, ctx.r9.u32);
	// addi r4,r8,-29304
	ctx.r4.s64 = ctx.r8.s64 + -29304;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82144a20
	ctx.lr = 0x821EE8C8;
	sub_82144A20(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r7,-29320
	ctx.r4.s64 = ctx.r7.s64 + -29320;
	// bl 0x82144a20
	ctx.lr = 0x821EE8DC;
	sub_82144A20(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r6,-29344
	ctx.r4.s64 = ctx.r6.s64 + -29344;
	// bl 0x82144a20
	ctx.lr = 0x821EE8F0;
	sub_82144A20(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r5,-29368
	ctx.r4.s64 = ctx.r5.s64 + -29368;
	// bl 0x82144a20
	ctx.lr = 0x821EE904;
	sub_82144A20(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// mr r30,r27
	r30.u64 = r27.u64;
	// addi r29,r31,40
	r29.s64 = r31.s64 + 40;
loc_821EE910:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r10,r11,10
	ctx.r10.s64 = r11.s64 + 10;
	// lwz r4,10(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// bl 0x82144a28
	ctx.lr = 0x821EE928;
	sub_82144A28(ctx, base);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// cmpwi cr6,r30,84
	cr6.compare<int32_t>(r30.s32, 84, xer);
	// blt cr6,0x821ee910
	if (cr6.lt) goto loc_821EE910;
	// stw r27,1720(r31)
	PPC_STORE_U32(r31.u32 + 1720, r27.u32);
	// stw r27,1724(r31)
	PPC_STORE_U32(r31.u32 + 1724, r27.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lbz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 18);
	// rotlwi r3,r10,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// bl 0x82130528
	ctx.lr = 0x821EE954;
	sub_82130528(ctx, base);
	// stw r3,1728(r31)
	PPC_STORE_U32(r31.u32 + 1728, ctx.r3.u32);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lbz r8,10(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 10);
	// rotlwi r3,r8,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// bl 0x82130528
	ctx.lr = 0x821EE968;
	sub_82130528(ctx, base);
	// stw r3,1732(r31)
	PPC_STORE_U32(r31.u32 + 1732, ctx.r3.u32);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lbz r6,18(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 18);
	// rotlwi r3,r6,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// bl 0x82130528
	ctx.lr = 0x821EE97C;
	sub_82130528(ctx, base);
	// stw r3,1736(r31)
	PPC_STORE_U32(r31.u32 + 1736, ctx.r3.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r30,-32114
	r30.s64 = -2104623104;
	// li r7,58
	ctx.r7.s64 = 58;
	// lwz r4,1728(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// addi r5,r11,19
	ctx.r5.s64 = r11.s64 + 19;
	// lbz r6,18(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 18);
	// lwz r3,-32456(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -32456);
	// bl 0x82547ac0
	ctx.lr = 0x821EE9A0;
	sub_82547AC0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x821ee9c0
	if (!cr6.eq) goto loc_821EE9C0;
	// stw r27,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r27.u32);
	// lwz r3,1728(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// bl 0x82130588
	ctx.lr = 0x821EE9B8;
	sub_82130588(ctx, base);
	// stw r27,1728(r31)
	PPC_STORE_U32(r31.u32 + 1728, r27.u32);
	// b 0x821ee9cc
	goto loc_821EE9CC;
loc_821EE9C0:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lbz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 18);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
loc_821EE9CC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r7,28
	ctx.r7.s64 = 28;
	// lwz r3,-32456(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -32456);
	// addi r5,r11,11
	ctx.r5.s64 = r11.s64 + 11;
	// lwz r4,1732(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1732);
	// lbz r6,10(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// bl 0x82547ac0
	ctx.lr = 0x821EE9E8;
	sub_82547AC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eea08
	if (!cr6.eq) goto loc_821EEA08;
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// lwz r3,1732(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1732);
	// bl 0x82130588
	ctx.lr = 0x821EEA00;
	sub_82130588(ctx, base);
	// stw r27,1732(r31)
	PPC_STORE_U32(r31.u32 + 1732, r27.u32);
	// b 0x821eea14
	goto loc_821EEA14;
loc_821EEA08:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lbz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
loc_821EEA14:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,6
	ctx.r7.s64 = 6;
	// lwz r3,-32456(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -32456);
	// addi r5,r11,19
	ctx.r5.s64 = r11.s64 + 19;
	// lwz r4,1736(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1736);
	// lbz r6,18(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 18);
	// bl 0x82547ac0
	ctx.lr = 0x821EEA30;
	sub_82547AC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eea50
	if (!cr6.eq) goto loc_821EEA50;
	// stw r27,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r27.u32);
	// lwz r3,1736(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1736);
	// bl 0x82130588
	ctx.lr = 0x821EEA48;
	sub_82130588(ctx, base);
	// stw r27,1736(r31)
	PPC_STORE_U32(r31.u32 + 1736, r27.u32);
	// b 0x821eea5c
	goto loc_821EEA5C;
loc_821EEA50:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lbz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 18);
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
loc_821EEA5C:
	// lis r11,-32225
	r11.s64 = -2111897600;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-6160
	ctx.r4.s64 = r11.s64 + -6160;
	// addi r3,r10,-29396
	ctx.r3.s64 = ctx.r10.s64 + -29396;
	// bl 0x82554798
	ctx.lr = 0x821EEA70;
	sub_82554798(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-6056
	ctx.r4.s64 = ctx.r9.s64 + -6056;
	// addi r3,r8,-29424
	ctx.r3.s64 = ctx.r8.s64 + -29424;
	// bl 0x82554798
	ctx.lr = 0x821EEA84;
	sub_82554798(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821EEA8C"))) PPC_WEAK_FUNC(sub_821EEA8C);
PPC_FUNC_IMPL(__imp__sub_821EEA8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EEA90"))) PPC_WEAK_FUNC(sub_821EEA90);
PPC_FUNC_IMPL(__imp__sub_821EEA90) {
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
	ctx.lr = 0x821EEA98;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r4,524(r31)
	PPC_STORE_U8(r31.u32 + 524, ctx.r4.u8);
	// stb r4,525(r31)
	PPC_STORE_U8(r31.u32 + 525, ctx.r4.u8);
	// beq cr6,0x821eeaf8
	if (cr6.eq) goto loc_821EEAF8;
	// addi r29,r31,160
	r29.s64 = r31.s64 + 160;
	// li r30,9
	r30.s64 = 9;
loc_821EEABC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821f73b0
	ctx.lr = 0x821EEAC4;
	sub_821F73B0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,24
	r29.s64 = r29.s64 + 24;
	// bne 0x821eeabc
	if (!cr0.eq) goto loc_821EEABC;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821EEAF8:
	// addi r30,r31,160
	r30.s64 = r31.s64 + 160;
	// li r31,9
	r31.s64 = 9;
loc_821EEB00:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f7378
	ctx.lr = 0x821EEB08;
	sub_821F7378(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// bne 0x821eeb00
	if (!cr0.eq) goto loc_821EEB00;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821EEB1C"))) PPC_WEAK_FUNC(sub_821EEB1C);
PPC_FUNC_IMPL(__imp__sub_821EEB1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EEB20"))) PPC_WEAK_FUNC(sub_821EEB20);
PPC_FUNC_IMPL(__imp__sub_821EEB20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-28756
	ctx.r5.s64 = ctx.r10.s64 + -28756;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,40
	ctx.r6.s64 = r11.s64 + 40;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821EEB44"))) PPC_WEAK_FUNC(sub_821EEB44);
PPC_FUNC_IMPL(__imp__sub_821EEB44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EEB48"))) PPC_WEAK_FUNC(sub_821EEB48);
PPC_FUNC_IMPL(__imp__sub_821EEB48) {
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
	ctx.lr = 0x821EEB50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lbz r11,527(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 527);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eebc4
	if (!cr6.eq) goto loc_821EEBC4;
	// lwz r11,388(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 388);
	// addi r30,r10,388
	r30.s64 = ctx.r10.s64 + 388;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eebc4
	if (!cr6.eq) goto loc_821EEBC4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r8,-28732
	ctx.r3.s64 = ctx.r8.s64 + -28732;
	// lwz r11,-12512(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12512);
	// addi r29,r10,12
	r29.s64 = ctx.r10.s64 + 12;
	// lwz r31,-12548(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12548);
	// lbz r7,15(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 15);
	// extsb r28,r7
	r28.s64 = ctx.r7.s8;
	// bl 0x821c9790
	ctx.lr = 0x821EEBA0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x821f4e78
	ctx.lr = 0x821EEBC4;
	sub_821F4E78(ctx, base);
loc_821EEBC4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821EEBCC"))) PPC_WEAK_FUNC(sub_821EEBCC);
PPC_FUNC_IMPL(__imp__sub_821EEBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EEBD0"))) PPC_WEAK_FUNC(sub_821EEBD0);
PPC_FUNC_IMPL(__imp__sub_821EEBD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,388(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821f4c18
	sub_821F4C18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821EEBE4"))) PPC_WEAK_FUNC(sub_821EEBE4);
PPC_FUNC_IMPL(__imp__sub_821EEBE4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EEBE8"))) PPC_WEAK_FUNC(sub_821EEBE8);
PPC_FUNC_IMPL(__imp__sub_821EEBE8) {
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
	ctx.lr = 0x821EEBF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,388
	r30.s64 = r31.s64 + 388;
	// lwz r3,388(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821eec14
	if (cr6.eq) goto loc_821EEC14;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EEC14;
	sub_821F4C18(ctx, base);
loc_821EEC14:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
	// lwz r11,-12512(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12512);
	// lwz r31,-12548(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12548);
	// lbz r9,15(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 15);
	// extsb r28,r9
	r28.s64 = ctx.r9.s8;
	// bl 0x821c9790
	ctx.lr = 0x821EEC3C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x821f4e78
	ctx.lr = 0x821EEC60;
	sub_821F4E78(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821EEC68"))) PPC_WEAK_FUNC(sub_821EEC68);
PPC_FUNC_IMPL(__imp__sub_821EEC68) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// bge cr6,0x821eec94
	if (!cr6.lt) goto loc_821EEC94;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x821eeca4
	if (!cr6.lt) goto loc_821EECA4;
loc_821EEC94:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-28656
	ctx.r3.s64 = r11.s64 + -28656;
	// bl 0x821bd618
	ctx.lr = 0x821EECA4;
	sub_821BD618(ctx, base);
loc_821EECA4:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// lwz r5,164(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 164);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bgt cr6,0x821eecd0
	if (cr6.gt) goto loc_821EECD0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-28712
	ctx.r3.s64 = r11.s64 + -28712;
	// bl 0x821bd618
	ctx.lr = 0x821EECD0;
	sub_821BD618(ctx, base);
loc_821EECD0:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// beq cr6,0x821eece4
	if (cr6.eq) goto loc_821EECE4;
	// stw r11,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r11.u32);
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
loc_821EECE4:
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

__attribute__((alias("__imp__sub_821EECFC"))) PPC_WEAK_FUNC(sub_821EECFC);
PPC_FUNC_IMPL(__imp__sub_821EECFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EED00"))) PPC_WEAK_FUNC(sub_821EED00);
PPC_FUNC_IMPL(__imp__sub_821EED00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821EED18"))) PPC_WEAK_FUNC(sub_821EED18);
PPC_FUNC_IMPL(__imp__sub_821EED18) {
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
	ctx.lr = 0x821EED20;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
loc_821EED2C:
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// li r11,7
	r11.s64 = 7;
	// beq cr6,0x821eed3c
	if (cr6.eq) goto loc_821EED3C;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_821EED3C:
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r31,r10
	ctx.r10.u64 = r31.u64 + ctx.r10.u64;
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// li r5,1
	ctx.r5.s64 = 1;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r30,r11,160
	r30.s64 = r11.s64 + 160;
	// lhz r4,92(r9)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r9.u32 + 92);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f7558
	ctx.lr = 0x821EED68;
	sub_821F7558(ctx, base);
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// lhz r4,92(r8)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + 92);
	// bl 0x821f74b8
	ctx.lr = 0x821EED7C;
	sub_821F74B8(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// blt cr6,0x821eed2c
	if (cr6.lt) goto loc_821EED2C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821EED90"))) PPC_WEAK_FUNC(sub_821EED90);
PPC_FUNC_IMPL(__imp__sub_821EED90) {
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
	// lwz r11,384(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eeec8
	if (cr6.eq) goto loc_821EEEC8;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821eee14
	if (!cr6.eq) goto loc_821EEE14;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r31,-12252(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwz r9,1740(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1740);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821eee0c
	if (!cr6.eq) goto loc_821EEE0C;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ed368
	ctx.lr = 0x821EEE0C;
	sub_821ED368(ctx, base);
loc_821EEE0C:
	// stfs f31,540(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 540, temp.u32);
	// b 0x821eeeec
	goto loc_821EEEEC;
loc_821EEE14:
	// lwz r31,408(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 408);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lhz r8,82(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// lwz r10,26652(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 26652);
	// lfs f0,-28476(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28476);
	f0.f64 = double(temp.f32);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r6,r10
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x821eeecc
	if (!cr6.gt) goto loc_821EEECC;
	// lwz r3,404(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// lwz r30,-12252(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// bl 0x82149480
	ctx.lr = 0x821EEE58;
	sub_82149480(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x82149480
	ctx.lr = 0x821EEE64;
	sub_82149480(ctx, base);
	// fadds f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 + ctx.f1.f64));
	// bl 0x821493f8
	ctx.lr = 0x821EEE6C;
	sub_821493F8(ctx, base);
	// lwz r10,1740(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1740);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821eeea4
	if (!cr6.eq) goto loc_821EEEA4;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ed368
	ctx.lr = 0x821EEEA4;
	sub_821ED368(ctx, base);
loc_821EEEA4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f13,f31,f31,f0
	ctx.f13.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,540(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 540, temp.u32);
	// b 0x821eeeec
	goto loc_821EEEEC;
loc_821EEEC8:
	// lis r11,-32121
	r11.s64 = -2105081856;
loc_821EEECC:
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821eeeec
	if (cr6.eq) goto loc_821EEEEC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x821ec468
	ctx.lr = 0x821EEEEC;
	sub_821EC468(ctx, base);
loc_821EEEEC:
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

__attribute__((alias("__imp__sub_821EEF08"))) PPC_WEAK_FUNC(sub_821EEF08);
PPC_FUNC_IMPL(__imp__sub_821EEF08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821eef20
	if (cr6.eq) goto loc_821EEF20;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,11(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 11);
	// blr 
	return;
loc_821EEF20:
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lhz r9,92(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 92);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x821eef48
	if (cr6.lt) goto loc_821EEF48;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821eef64
	if (cr6.eq) goto loc_821EEF64;
loc_821EEF48:
	// addi r10,r10,11
	ctx.r10.s64 = ctx.r10.s64 + 11;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r7,r8,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// lwzx r11,r7,r9
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blr 
	return;
loc_821EEF64:
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EEF74"))) PPC_WEAK_FUNC(sub_821EEF74);
PPC_FUNC_IMPL(__imp__sub_821EEF74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EEF78"))) PPC_WEAK_FUNC(sub_821EEF78);
PPC_FUNC_IMPL(__imp__sub_821EEF78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821eefd0
	if (!cr6.eq) goto loc_821EEFD0;
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lhz r9,92(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 92);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x821eefac
	if (cr6.lt) goto loc_821EEFAC;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821eefc8
	if (cr6.eq) goto loc_821EEFC8;
loc_821EEFAC:
	// addi r10,r10,11
	ctx.r10.s64 = ctx.r10.s64 + 11;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r7,r8,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// lwzx r11,r7,r9
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// blr 
	return;
loc_821EEFC8:
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_821EEFD0:
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EEFD8"))) PPC_WEAK_FUNC(sub_821EEFD8);
PPC_FUNC_IMPL(__imp__sub_821EEFD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,156(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 156);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x821ef008
	if (!cr6.gt) goto loc_821EF008;
	// lwz r10,152(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
loc_821EEFEC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x821ef00c
	if (cr6.eq) goto loc_821EF00C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x821eefec
	if (cr6.lt) goto loc_821EEFEC;
loc_821EF008:
	// li r11,-1
	r11.s64 = -1;
loc_821EF00C:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EF020"))) PPC_WEAK_FUNC(sub_821EF020);
PPC_FUNC_IMPL(__imp__sub_821EF020) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r3,88
	ctx.r8.s64 = ctx.r3.s64 + 88;
loc_821EF028:
	// lhz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x821ef05c
	if (!cr6.gt) goto loc_821EF05C;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
loc_821EF03C:
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// beq cr6,0x821ef07c
	if (cr6.eq) goto loc_821EF07C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x821ef03c
	if (cr6.lt) goto loc_821EF03C;
loc_821EF05C:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// cmpwi cr6,r7,8
	cr6.compare<int32_t>(ctx.r7.s32, 8, xer);
	// blt cr6,0x821ef028
	if (cr6.lt) goto loc_821EF028;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// blr 
	return;
loc_821EF07C:
	// stw r7,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r7.u32);
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EF088"))) PPC_WEAK_FUNC(sub_821EF088);
PPC_FUNC_IMPL(__imp__sub_821EF088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-12216(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12216);
	// stw r9,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EF0A0"))) PPC_WEAK_FUNC(sub_821EF0A0);
PPC_FUNC_IMPL(__imp__sub_821EF0A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12216(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// lwz r3,388(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 388);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821f4c18
	sub_821F4C18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821EF0BC"))) PPC_WEAK_FUNC(sub_821EF0BC);
PPC_FUNC_IMPL(__imp__sub_821EF0BC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EF0C0"))) PPC_WEAK_FUNC(sub_821EF0C0);
PPC_FUNC_IMPL(__imp__sub_821EF0C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-12216(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12216);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,528(r11)
	PPC_STORE_U8(r11.u32 + 528, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EF0E4"))) PPC_WEAK_FUNC(sub_821EF0E4);
PPC_FUNC_IMPL(__imp__sub_821EF0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EF0E8"))) PPC_WEAK_FUNC(sub_821EF0E8);
PPC_FUNC_IMPL(__imp__sub_821EF0E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r11,-12216(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821ef13c
	if (cr6.eq) goto loc_821EF13C;
	// lwz r10,516(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 516);
	// addi r5,r11,516
	ctx.r5.s64 = r11.s64 + 516;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-28504
	ctx.r4.s64 = ctx.r9.s64 + -28504;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// b 0x821ee720
	sub_821EE720(ctx, base);
	return;
loc_821EF13C:
	// lwz r3,516(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 516);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821ec060
	sub_821EC060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821EF150"))) PPC_WEAK_FUNC(sub_821EF150);
PPC_FUNC_IMPL(__imp__sub_821EF150) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EF154"))) PPC_WEAK_FUNC(sub_821EF154);
PPC_FUNC_IMPL(__imp__sub_821EF154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EF158"))) PPC_WEAK_FUNC(sub_821EF158);
PPC_FUNC_IMPL(__imp__sub_821EF158) {
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
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// lwz r3,384(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// std r8,376(r31)
	PPC_STORE_U64(r31.u32 + 376, ctx.r8.u64);
	// beq cr6,0x821ef1e0
	if (cr6.eq) goto loc_821EF1E0;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821ef1d4
	if (!cr6.eq) goto loc_821EF1D4;
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EF1D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821ef1e0
	goto loc_821EF1E0;
loc_821EF1D4:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EF1DC;
	sub_821F4C18(ctx, base);
	// stb r30,526(r31)
	PPC_STORE_U8(r31.u32 + 526, r30.u8);
loc_821EF1E0:
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

__attribute__((alias("__imp__sub_821EF1F8"))) PPC_WEAK_FUNC(sub_821EF1F8);
PPC_FUNC_IMPL(__imp__sub_821EF1F8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ef2bc
	if (cr6.eq) goto loc_821EF2BC;
	// lbz r11,526(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 526);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ef244
	if (cr6.eq) goto loc_821EF244;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// addi r6,r31,60
	ctx.r6.s64 = r31.s64 + 60;
	// addi r5,r31,64
	ctx.r5.s64 = r31.s64 + 64;
	// lwz r4,11(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 11);
	// bl 0x821ef020
	ctx.lr = 0x821EF240;
	sub_821EF020(ctx, base);
	// b 0x821ef254
	goto loc_821EF254;
loc_821EF244:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
loc_821EF254:
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,172(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// stw r9,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r9.u32);
	// beq cr6,0x821ef2b0
	if (cr6.eq) goto loc_821EF2B0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821ef2a8
	if (cr6.eq) goto loc_821EF2A8;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
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
	// b 0x821ef2ac
	goto loc_821EF2AC;
loc_821EF2A8:
	// li r11,0
	r11.s64 = 0;
loc_821EF2AC:
	// stw r30,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r30.u32);
loc_821EF2B0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,384(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// bl 0x821f4c18
	ctx.lr = 0x821EF2BC;
	sub_821F4C18(ctx, base);
loc_821EF2BC:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821ef2dc
	if (!cr6.eq) goto loc_821EF2DC;
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EF2DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821EF2DC:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,376(r31)
	PPC_STORE_U64(r31.u32 + 376, ctx.r8.u64);
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

__attribute__((alias("__imp__sub_821EF310"))) PPC_WEAK_FUNC(sub_821EF310);
PPC_FUNC_IMPL(__imp__sub_821EF310) {
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
	ctx.lr = 0x821EF318;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a28
	ctx.lr = 0x821EF32C;
	sub_82144A28(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821ef444
	if (cr6.eq) goto loc_821EF444;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r31,r30,20
	r31.s64 = r30.s64 + 20;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,-28412
	ctx.r4.s64 = r11.s64 + -28412;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823de430
	ctx.lr = 0x821EF350;
	sub_823DE430(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821ef370
	if (!cr6.eq) goto loc_821EF370;
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
	// beq cr6,0x821ef444
	if (cr6.eq) goto loc_821EF444;
loc_821EF370:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x821EF388;
	sub_82137A08(ctx, base);
	// lbz r9,19(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 19);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r29,0
	r29.s64 = 0;
	// li r3,12
	ctx.r3.s64 = 12;
	// stbx r29,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, r29.u8);
	// bl 0x82130528
	ctx.lr = 0x821EF3A0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ef3bc
	if (cr6.eq) goto loc_821EF3BC;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// b 0x821ef3c0
	goto loc_821EF3C0;
loc_821EF3BC:
	// mr r31,r29
	r31.u64 = r29.u64;
loc_821EF3C0:
	// lwz r11,11(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x821378b8
	ctx.lr = 0x821EF3D0;
	sub_821378B8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// lbz r11,10(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// addi r10,r11,11
	ctx.r10.s64 = r11.s64 + 11;
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x821EF3F0;
	sub_8262E420(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r28,144
	ctx.r3.s64 = r28.s64 + 144;
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r31.u32);
	// bl 0x8262e420
	ctx.lr = 0x821EF404;
	sub_8262E420(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// addi r7,r8,-12192
	ctx.r7.s64 = ctx.r8.s64 + -12192;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ef444
	if (cr6.eq) goto loc_821EF444;
	// lbz r11,10(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r6,11(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 11);
	// addi r8,r10,-23232
	ctx.r8.s64 = ctx.r10.s64 + -23232;
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r9,-28472
	ctx.r3.s64 = ctx.r9.s64 + -28472;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwzx r4,r7,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x821EF444;
	sub_82130000(ctx, base);
loc_821EF444:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821EF44C"))) PPC_WEAK_FUNC(sub_821EF44C);
PPC_FUNC_IMPL(__imp__sub_821EF44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EF450"))) PPC_WEAK_FUNC(sub_821EF450);
PPC_FUNC_IMPL(__imp__sub_821EF450) {
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
	ctx.lr = 0x821EF458;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r30,42(r4)
	r30.u64 = PPC_LOAD_U8(ctx.r4.u32 + 42);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r29,r4,43
	r29.s64 = ctx.r4.s64 + 43;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821ef494
	if (cr6.eq) goto loc_821EF494;
	// li r31,0
	r31.s64 = 0;
loc_821EF474:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r4,r11,r29
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x821ef310
	ctx.lr = 0x821EF484;
	sub_821EF310(ctx, base);
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// clrlwi r31,r10,24
	r31.u64 = ctx.r10.u32 & 0xFF;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x821ef474
	if (cr6.lt) goto loc_821EF474;
loc_821EF494:
	// li r27,6
	r27.s64 = 6;
loc_821EF498:
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// lbz r30,0(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821ef4d4
	if (cr6.eq) goto loc_821EF4D4;
	// li r31,0
	r31.s64 = 0;
loc_821EF4B4:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r4,r11,r29
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x821ef310
	ctx.lr = 0x821EF4C4;
	sub_821EF310(ctx, base);
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// clrlwi r31,r10,24
	r31.u64 = ctx.r10.u32 & 0xFF;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x821ef4b4
	if (cr6.lt) goto loc_821EF4B4;
loc_821EF4D4:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// bne 0x821ef498
	if (!cr0.eq) goto loc_821EF498;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821EF4E4"))) PPC_WEAK_FUNC(sub_821EF4E4);
PPC_FUNC_IMPL(__imp__sub_821EF4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EF4E8"))) PPC_WEAK_FUNC(sub_821EF4E8);
PPC_FUNC_IMPL(__imp__sub_821EF4E8) {
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
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ef530
	if (cr6.eq) goto loc_821EF530;
	// lwz r6,520(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 520);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821ef530
	if (cr6.eq) goto loc_821EF530;
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x821eef78
	ctx.lr = 0x821EF520;
	sub_821EEF78(ctx, base);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821EF528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	f0.f64 = double(temp.f32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
loc_821EF530:
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

__attribute__((alias("__imp__sub_821EF544"))) PPC_WEAK_FUNC(sub_821EF544);
PPC_FUNC_IMPL(__imp__sub_821EF544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EF548"))) PPC_WEAK_FUNC(sub_821EF548);
PPC_FUNC_IMPL(__imp__sub_821EF548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EF578;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x821ef588
	if (cr6.eq) goto loc_821EF588;
	// li r11,0
	r11.s64 = 0;
loc_821EF588:
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ef5a8
	if (cr6.eq) goto loc_821EF5A8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EF5A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821EF5A8:
	// lwz r11,380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r10,376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EF5C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821eed90
	ctx.lr = 0x821EF5C8;
	sub_821EED90(ctx, base);
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

__attribute__((alias("__imp__sub_821EF5E0"))) PPC_WEAK_FUNC(sub_821EF5E0);
PPC_FUNC_IMPL(__imp__sub_821EF5E0) {
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
	// addi r11,r4,11
	r11.s64 = ctx.r4.s64 + 11;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// li r11,0
	r11.s64 = 0;
	// lhz r9,156(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 156);
	// lwzx r7,r10,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwzx r30,r7,r8
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// ble cr6,0x821ef64c
	if (!cr6.gt) goto loc_821EF64C;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_821EF624:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// beq cr6,0x821ef644
	if (cr6.eq) goto loc_821EF644;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x821ef624
	if (cr6.lt) goto loc_821EF624;
	// b 0x821ef64c
	goto loc_821EF64C;
loc_821EF644:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x821ef670
	if (!cr6.lt) goto loc_821EF670;
loc_821EF64C:
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8262e420
	ctx.lr = 0x821EF654;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r31,352
	ctx.r3.s64 = r31.s64 + 352;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lhz r4,156(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 156);
	// bl 0x821f74b8
	ctx.lr = 0x821EF668;
	sub_821F74B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x821ef674
	goto loc_821EF674;
loc_821EF670:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821EF674:
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

__attribute__((alias("__imp__sub_821EF68C"))) PPC_WEAK_FUNC(sub_821EF68C);
PPC_FUNC_IMPL(__imp__sub_821EF68C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EF690"))) PPC_WEAK_FUNC(sub_821EF690);
PPC_FUNC_IMPL(__imp__sub_821EF690) {
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
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821ef020
	ctx.lr = 0x821EF6B0;
	sub_821EF020(ctx, base);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x821ef6e4
	if (cr6.eq) goto loc_821EF6E4;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// beq cr6,0x821ef6e4
	if (cr6.eq) goto loc_821EF6E4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef5e0
	ctx.lr = 0x821EF6D0;
	sub_821EF5E0(ctx, base);
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
loc_821EF6E4:
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

__attribute__((alias("__imp__sub_821EF6FC"))) PPC_WEAK_FUNC(sub_821EF6FC);
PPC_FUNC_IMPL(__imp__sub_821EF6FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EF700"))) PPC_WEAK_FUNC(sub_821EF700);
PPC_FUNC_IMPL(__imp__sub_821EF700) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,156(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 156);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,152(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// addi r9,r3,152
	ctx.r9.s64 = ctx.r3.s64 + 152;
loc_821EF718:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplw cr6,r7,r4
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, xer);
	// beq cr6,0x821ef740
	if (cr6.eq) goto loc_821EF740;
	// lhz r8,156(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 156);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x821ef718
	if (cr6.lt) goto loc_821EF718;
	// blr 
	return;
loc_821EF740:
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x821ef780
	if (!cr6.lt) goto loc_821EF780;
loc_821EF754:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x821ef754
	if (cr6.lt) goto loc_821EF754;
loc_821EF780:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r10.u16);
	// lhz r7,156(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 156);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EF7A8"))) PPC_WEAK_FUNC(sub_821EF7A8);
PPC_FUNC_IMPL(__imp__sub_821EF7A8) {
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
	ctx.lr = 0x821EF7B0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,1
	r29.s64 = 1;
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ef860
	if (cr6.eq) goto loc_821EF860;
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lhz r8,82(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// lfs f0,-28476(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28476);
	f0.f64 = double(temp.f32);
	// lwz r10,26652(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26652);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r6,r10
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x821ef860
	if (!cr6.gt) goto loc_821EF860;
	// lwz r3,504(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 504);
	// addi r30,r31,504
	r30.s64 = r31.s64 + 504;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ef814
	if (cr6.eq) goto loc_821EF814;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EF814;
	sub_8213C218(ctx, base);
loc_821EF814:
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stb r29,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r29.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r11,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r11.u8);
	// lfs f1,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,16(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x825495a8
	ctx.lr = 0x821EF860;
	sub_825495A8(ctx, base);
loc_821EF860:
	// stw r29,496(r31)
	PPC_STORE_U32(r31.u32 + 496, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef158
	ctx.lr = 0x821EF86C;
	sub_821EF158(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821EF874"))) PPC_WEAK_FUNC(sub_821EF874);
PPC_FUNC_IMPL(__imp__sub_821EF874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EF878"))) PPC_WEAK_FUNC(sub_821EF878);
PPC_FUNC_IMPL(__imp__sub_821EF878) {
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
	ctx.lr = 0x821EF880;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ef934
	if (cr6.eq) goto loc_821EF934;
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lhz r8,82(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// lfs f0,-28476(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28476);
	f0.f64 = double(temp.f32);
	// lwz r10,26652(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26652);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r6,r10
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x821ef934
	if (!cr6.gt) goto loc_821EF934;
	// lwz r3,504(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 504);
	// addi r30,r31,504
	r30.s64 = r31.s64 + 504;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ef8e4
	if (cr6.eq) goto loc_821EF8E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821EF8E4;
	sub_8213C218(ctx, base);
loc_821EF8E4:
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r11.u8);
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,16(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r28,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r28.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x825495a8
	ctx.lr = 0x821EF934;
	sub_825495A8(ctx, base);
loc_821EF934:
	// li r11,2
	r11.s64 = 2;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r11,496(r31)
	PPC_STORE_U32(r31.u32 + 496, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef1f8
	ctx.lr = 0x821EF948;
	sub_821EF1F8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821EF950"))) PPC_WEAK_FUNC(sub_821EF950);
PPC_FUNC_IMPL(__imp__sub_821EF950) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x821EF958;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r3,388(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// stb r11,527(r31)
	PPC_STORE_U8(r31.u32 + 527, r11.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821ef980
	if (cr6.eq) goto loc_821EF980;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821EF980;
	sub_821F4C18(ctx, base);
loc_821EF980:
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// addi r29,r31,384
	r29.s64 = r31.s64 + 384;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821ef9a4
	if (cr6.eq) goto loc_821EF9A4;
	// lbz r11,526(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 526);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821efb90
	if (cr6.eq) goto loc_821EFB90;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef158
	ctx.lr = 0x821EF9A4;
	sub_821EF158(ctx, base);
loc_821EF9A4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821efa1c
	if (!cr6.eq) goto loc_821EFA1C;
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EF9C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821ef9f8
	if (cr6.eq) goto loc_821EF9F8;
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,396(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// mulli r10,r10,820
	ctx.r10.s64 = ctx.r10.s64 * 820;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821EF9F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef4e8
	ctx.lr = 0x821EF9F8;
	sub_821EF4E8(ctx, base);
loc_821EF9F8:
	// lis r11,-32225
	r11.s64 = -2111897600;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,2104
	ctx.r9.s64 = r11.s64 + 2104;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,376(r31)
	PPC_STORE_U64(r31.u32 + 376, ctx.r8.u64);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_821EFA1C:
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r30,0
	r30.s64 = 0;
	// lhz r8,82(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// lfs f0,-28476(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28476);
	f0.f64 = double(temp.f32);
	// lwz r10,26652(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26652);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r6,r10
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x821efa60
	if (cr6.gt) goto loc_821EFA60;
	// lbz r11,528(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 528);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821efb78
	if (cr6.eq) goto loc_821EFB78;
loc_821EFA60:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r8,500(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 500);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r28,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r28.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// li r5,255
	ctx.r5.s64 = 255;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// li r4,134
	ctx.r4.s64 = 134;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,-29056(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29056);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// stw r30,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r30.u32);
	// stw r30,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r30.u32);
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r30.u32);
	// stw r7,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r7.u32);
	// stw r6,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r6.u32);
	// stb r5,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r5.u8);
	// stb r30,165(r1)
	PPC_STORE_U8(ctx.r1.u32 + 165, r30.u8);
	// stb r4,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r4.u8);
	// beq cr6,0x821efaec
	if (cr6.eq) goto loc_821EFAEC;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lhz r10,14(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// b 0x821efb18
	goto loc_821EFB18;
loc_821EFAEC:
	// lwz r11,508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 508);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821efb04
	if (cr6.eq) goto loc_821EFB04;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// b 0x821efb18
	goto loc_821EFB18;
loc_821EFB04:
	// lwz r11,512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 512);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821efb1c
	if (cr6.eq) goto loc_821EFB1C;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
loc_821EFB18:
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
loc_821EFB1C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r1,96
	r28.s64 = ctx.r1.s64 + 96;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r11,-12512(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12512);
	// lbz r10,15(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 15);
	// extsb r27,r10
	r27.s64 = ctx.r10.s8;
	// bl 0x821eef08
	ctx.lr = 0x821EFB40;
	sub_821EEF08(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-12548(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12548);
	// bl 0x821f4e78
	ctx.lr = 0x821EFB60;
	sub_821F4E78(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821efb90
	if (cr6.eq) goto loc_821EFB90;
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef4e8
	ctx.lr = 0x821EFB78;
	sub_821EF4E8(ctx, base);
loc_821EFB78:
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// lis r11,-32225
	r11.s64 = -2111897600;
	// addi r10,r11,2104
	ctx.r10.s64 = r11.s64 + 2104;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,376(r31)
	PPC_STORE_U64(r31.u32 + 376, ctx.r9.u64);
loc_821EFB90:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821EFB98"))) PPC_WEAK_FUNC(sub_821EFB98);
PPC_FUNC_IMPL(__imp__sub_821EFB98) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x821EFBA0;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x821EFBB0;
	sub_824E0648(ctx, base);
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82548ac0
	ctx.lr = 0x821EFBBC;
	sub_82548AC0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r6,r8,-28256
	ctx.r6.s64 = ctx.r8.s64 + -28256;
	// lfs f13,32668(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32668);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r7,-28288
	ctx.r5.s64 = ctx.r7.s64 + -28288;
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f31,36(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// stb r30,44(r31)
	PPC_STORE_U8(r31.u32 + 44, r30.u8);
	// addi r27,r31,160
	r27.s64 = r31.s64 + 160;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// li r28,8
	r28.s64 = 8;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// sth r30,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r30.u16);
	// sth r30,94(r31)
	PPC_STORE_U16(r31.u32 + 94, r30.u16);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// sth r30,100(r31)
	PPC_STORE_U16(r31.u32 + 100, r30.u16);
	// sth r30,102(r31)
	PPC_STORE_U16(r31.u32 + 102, r30.u16);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// sth r30,108(r31)
	PPC_STORE_U16(r31.u32 + 108, r30.u16);
	// sth r30,110(r31)
	PPC_STORE_U16(r31.u32 + 110, r30.u16);
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// sth r30,116(r31)
	PPC_STORE_U16(r31.u32 + 116, r30.u16);
	// sth r30,118(r31)
	PPC_STORE_U16(r31.u32 + 118, r30.u16);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// sth r30,124(r31)
	PPC_STORE_U16(r31.u32 + 124, r30.u16);
	// sth r30,126(r31)
	PPC_STORE_U16(r31.u32 + 126, r30.u16);
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
	// sth r30,132(r31)
	PPC_STORE_U16(r31.u32 + 132, r30.u16);
	// sth r30,134(r31)
	PPC_STORE_U16(r31.u32 + 134, r30.u16);
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// sth r30,140(r31)
	PPC_STORE_U16(r31.u32 + 140, r30.u16);
	// sth r30,142(r31)
	PPC_STORE_U16(r31.u32 + 142, r30.u16);
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// sth r30,148(r31)
	PPC_STORE_U16(r31.u32 + 148, r30.u16);
	// sth r30,150(r31)
	PPC_STORE_U16(r31.u32 + 150, r30.u16);
	// stw r30,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r30.u32);
	// sth r30,156(r31)
	PPC_STORE_U16(r31.u32 + 156, r30.u16);
	// sth r30,158(r31)
	PPC_STORE_U16(r31.u32 + 158, r30.u16);
loc_821EFC84:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821f7308
	ctx.lr = 0x821EFC8C;
	sub_821F7308(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,24
	r27.s64 = r27.s64 + 24;
	// bge 0x821efc84
	if (!cr0.lt) goto loc_821EFC84;
	// stw r30,400(r31)
	PPC_STORE_U32(r31.u32 + 400, r30.u32);
	// addi r25,r31,412
	r25.s64 = r31.s64 + 412;
	// stw r30,404(r31)
	PPC_STORE_U32(r31.u32 + 404, r30.u32);
	// stw r30,408(r31)
	PPC_STORE_U32(r31.u32 + 408, r30.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82163ee8
	ctx.lr = 0x821EFCB0;
	sub_82163EE8(ctx, base);
	// addi r24,r31,452
	r24.s64 = r31.s64 + 452;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82163ee8
	ctx.lr = 0x821EFCBC;
	sub_82163EE8(ctx, base);
	// li r23,1
	r23.s64 = 1;
	// stw r30,500(r31)
	PPC_STORE_U32(r31.u32 + 500, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r23,496(r31)
	PPC_STORE_U32(r31.u32 + 496, r23.u32);
	// stw r30,504(r31)
	PPC_STORE_U32(r31.u32 + 504, r30.u32);
	// stw r30,508(r31)
	PPC_STORE_U32(r31.u32 + 508, r30.u32);
	// stw r30,512(r31)
	PPC_STORE_U32(r31.u32 + 512, r30.u32);
	// stw r30,516(r31)
	PPC_STORE_U32(r31.u32 + 516, r30.u32);
	// stw r30,520(r31)
	PPC_STORE_U32(r31.u32 + 520, r30.u32);
	// stb r30,524(r31)
	PPC_STORE_U8(r31.u32 + 524, r30.u8);
	// stb r30,525(r31)
	PPC_STORE_U8(r31.u32 + 525, r30.u8);
	// stb r30,526(r31)
	PPC_STORE_U8(r31.u32 + 526, r30.u8);
	// stb r30,527(r31)
	PPC_STORE_U8(r31.u32 + 527, r30.u8);
	// stb r30,528(r31)
	PPC_STORE_U8(r31.u32 + 528, r30.u8);
	// bl 0x82548ba8
	ctx.lr = 0x821EFCF8;
	sub_82548BA8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// addi r4,r10,-28308
	ctx.r4.s64 = ctx.r10.s64 + -28308;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82144a20
	ctx.lr = 0x821EFD10;
	sub_82144A20(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r9,-28332
	ctx.r4.s64 = ctx.r9.s64 + -28332;
	// bl 0x82144a20
	ctx.lr = 0x821EFD24;
	sub_82144A20(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r8,-28352
	ctx.r4.s64 = ctx.r8.s64 + -28352;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82144a20
	ctx.lr = 0x821EFD38;
	sub_82144A20(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// addi r6,r7,-13760
	ctx.r6.s64 = ctx.r7.s64 + -13760;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821efd5c
	if (cr6.eq) goto loc_821EFD5C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821efd5c
	if (cr6.eq) goto loc_821EFD5C;
	// mr r28,r27
	r28.u64 = r27.u64;
loc_821EFD5C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
	// mr r26,r30
	r26.u64 = r30.u64;
	// addi r10,r11,-12032
	ctx.r10.s64 = r11.s64 + -12032;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821efd84
	if (cr6.eq) goto loc_821EFD84;
	// mr r26,r11
	r26.u64 = r11.u64;
	// mr r11,r23
	r11.u64 = r23.u64;
	// b 0x821efd88
	goto loc_821EFD88;
loc_821EFD84:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_821EFD88:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821efdb4
	if (cr6.eq) goto loc_821EFDB4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82144a20
	ctx.lr = 0x821EFDA0;
	sub_82144A20(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r11,-28396
	ctx.r3.s64 = r11.s64 + -28396;
	// bl 0x82130000
	ctx.lr = 0x821EFDB4;
	sub_82130000(ctx, base);
loc_821EFDB4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,17508
	ctx.r3.s64 = r11.s64 + 17508;
	// bl 0x821c9790
	ctx.lr = 0x821EFDC4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8214a200
	ctx.lr = 0x821EFDD0;
	sub_8214A200(ctx, base);
	// stw r3,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-28408
	ctx.r3.s64 = ctx.r10.s64 + -28408;
	// bl 0x821c9790
	ctx.lr = 0x821EFDE4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8214a200
	ctx.lr = 0x821EFDF0;
	sub_8214A200(ctx, base);
	// stw r3,408(r31)
	PPC_STORE_U32(r31.u32 + 408, ctx.r3.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r4,34(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 34);
	// bl 0x82164840
	ctx.lr = 0x821EFE04;
	sub_82164840(ctx, base);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,38(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 38);
	// bl 0x82164840
	ctx.lr = 0x821EFE14;
	sub_82164840(ctx, base);
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// li r11,7
	r11.s64 = 7;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// addi r6,r7,8
	ctx.r6.s64 = ctx.r7.s64 + 8;
	// stfs f31,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stw r30,384(r31)
	PPC_STORE_U32(r31.u32 + 384, r30.u32);
	// li r3,120
	ctx.r3.s64 = 120;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stw r30,388(r31)
	PPC_STORE_U32(r31.u32 + 388, r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r30,392(r31)
	PPC_STORE_U32(r31.u32 + 392, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// std r5,376(r31)
	PPC_STORE_U64(r31.u32 + 376, ctx.r5.u64);
	// bl 0x82130528
	ctx.lr = 0x821EFE68;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821efe78
	if (cr6.eq) goto loc_821EFE78;
	// bl 0x82475ac8
	ctx.lr = 0x821EFE74;
	sub_82475AC8(ctx, base);
	// b 0x821efe7c
	goto loc_821EFE7C;
loc_821EFE78:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821EFE7C:
	// lis r11,-32225
	r11.s64 = -2111897600;
	// stw r3,392(r31)
	PPC_STORE_U32(r31.u32 + 392, ctx.r3.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r10,r11,-2840
	ctx.r10.s64 = r11.s64 + -2840;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d4268
	ctx.lr = 0x821EFEA8;
	sub_821D4268(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r10,392(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// addi r7,r9,-4864
	ctx.r7.s64 = ctx.r9.s64 + -4864;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r5,4(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r9,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// stw r3,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r3.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r11,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, r11.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821EFEF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,52(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821EFF0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821eff18
	if (!cr6.eq) goto loc_821EFF18;
	// stw r23,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r23.u32);
loc_821EFF18:
	// li r3,8200
	ctx.r3.s64 = 8200;
	// bl 0x82130528
	ctx.lr = 0x821EFF20;
	sub_82130528(ctx, base);
	// stw r3,396(r31)
	PPC_STORE_U32(r31.u32 + 396, ctx.r3.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821ef450
	ctx.lr = 0x821EFF34;
	sub_821EF450(ctx, base);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x821eff48
	if (cr6.eq) goto loc_821EFF48;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef450
	ctx.lr = 0x821EFF48;
	sub_821EF450(ctx, base);
loc_821EFF48:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821eed18
	ctx.lr = 0x821EFF50;
	sub_821EED18(ctx, base);
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821eff7c
	if (cr6.eq) goto loc_821EFF7C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r7,r31,492
	ctx.r7.s64 = r31.s64 + 492;
	// lwz r6,396(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EFF7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821EFF7C:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821eea90
	ctx.lr = 0x821EFF88;
	sub_821EEA90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821EFF98"))) PPC_WEAK_FUNC(sub_821EFF98);
PPC_FUNC_IMPL(__imp__sub_821EFF98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-28224
	ctx.r3.s64 = r11.s64 + -28224;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EFFA4"))) PPC_WEAK_FUNC(sub_821EFFA4);
PPC_FUNC_IMPL(__imp__sub_821EFFA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EFFA8"))) PPC_WEAK_FUNC(sub_821EFFA8);
PPC_FUNC_IMPL(__imp__sub_821EFFA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-28208
	ctx.r3.s64 = r11.s64 + -28208;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821EFFB4"))) PPC_WEAK_FUNC(sub_821EFFB4);
PPC_FUNC_IMPL(__imp__sub_821EFFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821EFFB8"))) PPC_WEAK_FUNC(sub_821EFFB8);
PPC_FUNC_IMPL(__imp__sub_821EFFB8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x821f0ad8
	sub_821F0AD8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821EFFC0"))) PPC_WEAK_FUNC(sub_821EFFC0);
PPC_FUNC_IMPL(__imp__sub_821EFFC0) {
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
	ctx.lr = 0x821EFFC8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-28256
	ctx.r9.s64 = r11.s64 + -28256;
	// addi r8,r10,-28288
	ctx.r8.s64 = ctx.r10.s64 + -28288;
	// lwz r3,384(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 384);
	// addi r26,r28,12
	r26.s64 = r28.s64 + 12;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r8,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r8.u32);
	// beq cr6,0x821f0000
	if (cr6.eq) goto loc_821F0000;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F0000;
	sub_821F4C18(ctx, base);
loc_821F0000:
	// lwz r3,388(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 388);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f0014
	if (cr6.eq) goto loc_821F0014;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F0014;
	sub_821F4C18(ctx, base);
loc_821F0014:
	// lwz r3,392(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 392);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f0034
	if (cr6.eq) goto loc_821F0034;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F0034;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F0034:
	// lwz r3,396(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 396);
	// bl 0x82130588
	ctx.lr = 0x821F003C;
	sub_82130588(ctx, base);
	// addi r27,r28,160
	r27.s64 = r28.s64 + 160;
	// addi r31,r28,88
	r31.s64 = r28.s64 + 88;
	// mr r29,r27
	r29.u64 = r27.u64;
	// li r30,9
	r30.s64 = 9;
loc_821F004C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x821f0080
	if (cr6.eq) goto loc_821F0080;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_821F006C:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x821f006c
	if (!cr6.eq) goto loc_821F006C;
loc_821F0080:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// bl 0x821f7338
	ctx.lr = 0x821F009C;
	sub_821F7338(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// addi r29,r29,24
	r29.s64 = r29.s64 + 24;
	// bne 0x821f004c
	if (!cr0.eq) goto loc_821F004C;
	// addi r31,r28,376
	r31.s64 = r28.s64 + 376;
	// li r30,8
	r30.s64 = 8;
loc_821F00B4:
	// addi r31,r31,-24
	r31.s64 = r31.s64 + -24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f7338
	ctx.lr = 0x821F00C0;
	sub_821F7338(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x821f00b4
	if (!cr0.lt) goto loc_821F00B4;
	// mr r31,r27
	r31.u64 = r27.u64;
	// li r30,8
	r30.s64 = 8;
loc_821F00D0:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f00e8
	if (cr6.eq) goto loc_821F00E8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821F00E8;
	sub_82130588(ctx, base);
loc_821F00E8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x821f00d0
	if (!cr0.lt) goto loc_821F00D0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82548b50
	ctx.lr = 0x821F00F8;
	sub_82548B50(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0430
	ctx.lr = 0x821F0100;
	sub_824E0430(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821F0108"))) PPC_WEAK_FUNC(sub_821F0108);
PPC_FUNC_IMPL(__imp__sub_821F0108) {
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
	ctx.lr = 0x821F0110;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f0168
	if (!cr6.eq) goto loc_821F0168;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x821f0168
	if (!cr6.eq) goto loc_821F0168;
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lhz r8,82(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// lfs f0,-28476(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28476);
	f0.f64 = double(temp.f32);
	// lwz r10,26652(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26652);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r6,r10
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x821f0174
	if (cr6.gt) goto loc_821F0174;
loc_821F0168:
	// lwz r11,516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f01ec
	if (cr6.eq) goto loc_821F01EC;
loc_821F0174:
	// lwz r3,516(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f0188
	if (cr6.eq) goto loc_821F0188;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x821F0188;
	sub_821EC060(ctx, base);
loc_821F0188:
	// lwz r3,500(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 500);
	// addi r30,r31,500
	r30.s64 = r31.s64 + 500;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f01a0
	if (cr6.eq) goto loc_821F01A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821F01A0;
	sub_8213C218(ctx, base);
loc_821F01A0:
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r4,1
	ctx.r4.s64 = 1;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r29.u32);
	// stb r4,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, ctx.r4.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r29,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r29.u8);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r29.u32);
	// lwz r4,10(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 10);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// bl 0x825495a8
	ctx.lr = 0x821F01EC;
	sub_825495A8(ctx, base);
loc_821F01EC:
	// stw r29,496(r31)
	PPC_STORE_U32(r31.u32 + 496, r29.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef950
	ctx.lr = 0x821F01FC;
	sub_821EF950(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F0204"))) PPC_WEAK_FUNC(sub_821F0204);
PPC_FUNC_IMPL(__imp__sub_821F0204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F0208"))) PPC_WEAK_FUNC(sub_821F0208);
PPC_FUNC_IMPL(__imp__sub_821F0208) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r5,r31,516
	ctx.r5.s64 = r31.s64 + 516;
	// lwz r11,516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f0248
	if (!cr6.eq) goto loc_821F0248;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-28504
	ctx.r4.s64 = ctx.r9.s64 + -28504;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee720
	ctx.lr = 0x821F0248;
	sub_821EE720(ctx, base);
loc_821F0248:
	// li r11,1
	r11.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,528(r31)
	PPC_STORE_U8(r31.u32 + 528, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef950
	ctx.lr = 0x821F025C;
	sub_821EF950(ctx, base);
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

__attribute__((alias("__imp__sub_821F0270"))) PPC_WEAK_FUNC(sub_821F0270);
PPC_FUNC_IMPL(__imp__sub_821F0270) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x821F0278;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lfs f0,-28476(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28476);
	f0.f64 = double(temp.f32);
	// lwz r10,26652(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26652);
	// lhz r8,82(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r6,r10
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x821f03f4
	if (!cr6.gt) goto loc_821F03F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// stb r30,526(r31)
	PPC_STORE_U8(r31.u32 + 526, r30.u8);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stfs f31,72(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// bne cr6,0x821f0310
	if (!cr6.eq) goto loc_821F0310;
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F02FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef4e8
	ctx.lr = 0x821F0304;
	sub_821EF4E8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_821F0310:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,160
	ctx.r3.s64 = r11.s64 + 160;
	// bl 0x821f7448
	ctx.lr = 0x821F032C;
	sub_821F7448(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,384(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r7,r9,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r6,r7,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// lwzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// stw r5,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r5.u32);
	// beq cr6,0x821f03dc
	if (cr6.eq) goto loc_821F03DC;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f03c4
	if (cr6.eq) goto loc_821F03C4;
	// lwz r3,508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 508);
	// addi r29,r31,508
	r29.s64 = r31.s64 + 508;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f037c
	if (cr6.eq) goto loc_821F037C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821F037C;
	sub_8213C218(ctx, base);
loc_821F037C:
	// li r11,1
	r11.s64 = 1;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r30,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r30.u8);
	// stb r11,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r11.u8);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,22(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 22);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x825495a8
	ctx.lr = 0x821F03C4;
	sub_825495A8(ctx, base);
loc_821F03C4:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,384(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// bl 0x821f4c18
	ctx.lr = 0x821F03D0;
	sub_821F4C18(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef950
	ctx.lr = 0x821F03DC;
	sub_821EF950(ctx, base);
loc_821F03DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821eef78
	ctx.lr = 0x821F03E4;
	sub_821EEF78(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-28196
	ctx.r3.s64 = r11.s64 + -28196;
	// bl 0x82130000
	ctx.lr = 0x821F03F4;
	sub_82130000(ctx, base);
loc_821F03F4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F0400"))) PPC_WEAK_FUNC(sub_821F0400);
PPC_FUNC_IMPL(__imp__sub_821F0400) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x821F0408;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lfs f0,-28476(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28476);
	f0.f64 = double(temp.f32);
	// lwz r10,26652(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26652);
	// lhz r8,82(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r6,r10
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x821f0584
	if (!cr6.gt) goto loc_821F0584;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// stb r30,526(r31)
	PPC_STORE_U8(r31.u32 + 526, r30.u8);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stfs f31,72(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// bne cr6,0x821f04a0
	if (!cr6.eq) goto loc_821F04A0;
	// lwz r3,392(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F048C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef4e8
	ctx.lr = 0x821F0494;
	sub_821EF4E8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_821F04A0:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,160
	ctx.r3.s64 = r11.s64 + 160;
	// bl 0x821f7488
	ctx.lr = 0x821F04BC;
	sub_821F7488(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,384(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r7,r9,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r6,r7,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// lwzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// stw r5,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r5.u32);
	// beq cr6,0x821f056c
	if (cr6.eq) goto loc_821F056C;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f0554
	if (cr6.eq) goto loc_821F0554;
	// lwz r3,512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 512);
	// addi r29,r31,512
	r29.s64 = r31.s64 + 512;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f050c
	if (cr6.eq) goto loc_821F050C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821F050C;
	sub_8213C218(ctx, base);
loc_821F050C:
	// li r11,1
	r11.s64 = 1;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r30,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r30.u8);
	// stb r11,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r11.u8);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r30.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,28(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x825495a8
	ctx.lr = 0x821F0554;
	sub_825495A8(ctx, base);
loc_821F0554:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,384(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// bl 0x821f4c18
	ctx.lr = 0x821F0560;
	sub_821F4C18(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef950
	ctx.lr = 0x821F056C;
	sub_821EF950(ctx, base);
loc_821F056C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821eef78
	ctx.lr = 0x821F0574;
	sub_821EEF78(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-28196
	ctx.r3.s64 = r11.s64 + -28196;
	// bl 0x82130000
	ctx.lr = 0x821F0584;
	sub_82130000(ctx, base);
loc_821F0584:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F0590"))) PPC_WEAK_FUNC(sub_821F0590);
PPC_FUNC_IMPL(__imp__sub_821F0590) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,496(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 496);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,526(r3)
	PPC_STORE_U8(ctx.r3.u32 + 526, ctx.r10.u8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821f05bc
	if (cr6.lt) goto loc_821F05BC;
	// beq cr6,0x821f05b8
	if (cr6.eq) goto loc_821F05B8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x821ef1f8
	sub_821EF1F8(ctx, base);
	return;
loc_821F05B8:
	// b 0x821ef158
	sub_821EF158(ctx, base);
	return;
loc_821F05BC:
	// b 0x821ef950
	sub_821EF950(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F05C0"))) PPC_WEAK_FUNC(sub_821F05C0);
PPC_FUNC_IMPL(__imp__sub_821F05C0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F05C4"))) PPC_WEAK_FUNC(sub_821F05C4);
PPC_FUNC_IMPL(__imp__sub_821F05C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F05C8"))) PPC_WEAK_FUNC(sub_821F05C8);
PPC_FUNC_IMPL(__imp__sub_821F05C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// b 0x821ef7a8
	sub_821EF7A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F05D4"))) PPC_WEAK_FUNC(sub_821F05D4);
PPC_FUNC_IMPL(__imp__sub_821F05D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F05D8"))) PPC_WEAK_FUNC(sub_821F05D8);
PPC_FUNC_IMPL(__imp__sub_821F05D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// b 0x821ef878
	sub_821EF878(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F05E8"))) PPC_WEAK_FUNC(sub_821F05E8);
PPC_FUNC_IMPL(__imp__sub_821F05E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821eebe8
	sub_821EEBE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F05FC"))) PPC_WEAK_FUNC(sub_821F05FC);
PPC_FUNC_IMPL(__imp__sub_821F05FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F0600"))) PPC_WEAK_FUNC(sub_821F0600);
PPC_FUNC_IMPL(__imp__sub_821F0600) {
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
	ctx.lr = 0x821F0608;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stb r30,526(r31)
	PPC_STORE_U8(r31.u32 + 526, r30.u8);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,160
	ctx.r3.s64 = r11.s64 + 160;
	// bl 0x821f7518
	ctx.lr = 0x821F0650;
	sub_821F7518(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,384(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// addi r6,r11,11
	ctx.r6.s64 = r11.s64 + 11;
	// stw r29,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r5,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + r31.u32);
	// lwzx r11,r4,r7
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// beq cr6,0x821f0690
	if (cr6.eq) goto loc_821F0690;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F0684;
	sub_821F4C18(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef950
	ctx.lr = 0x821F0690;
	sub_821EF950(ctx, base);
loc_821F0690:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f06e4
	if (!cr6.eq) goto loc_821F06E4;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// lhz r10,92(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 92);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x821f06c4
	if (cr6.lt) goto loc_821F06C4;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f06dc
	if (cr6.eq) goto loc_821F06DC;
loc_821F06C4:
	// addi r10,r9,11
	ctx.r10.s64 = ctx.r9.s64 + 11;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwzx r11,r7,r9
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// b 0x821f06e4
	goto loc_821F06E4;
loc_821F06DC:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_821F06E4:
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-28196
	ctx.r3.s64 = r11.s64 + -28196;
	// bl 0x82130000
	ctx.lr = 0x821F06F4;
	sub_82130000(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F06FC"))) PPC_WEAK_FUNC(sub_821F06FC);
PPC_FUNC_IMPL(__imp__sub_821F06FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F0700"))) PPC_WEAK_FUNC(sub_821F0700);
PPC_FUNC_IMPL(__imp__sub_821F0700) {
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
	ctx.lr = 0x821F0708;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a20
	ctx.lr = 0x821F0720;
	sub_82144A20(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821f0740
	if (!cr6.eq) goto loc_821F0740;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-28088
	ctx.r3.s64 = r11.s64 + -28088;
	// bl 0x82130000
	ctx.lr = 0x821F0738;
	sub_82130000(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821F0740:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r30,0
	r30.s64 = 0;
	// lwz r31,-12216(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// lhz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 148);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f07a0
	if (cr6.eq) goto loc_821F07A0;
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
loc_821F075C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r3
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r3.u32, xer);
	// beq cr6,0x821f0798
	if (cr6.eq) goto loc_821F0798;
	// lhz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 148);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x821f075c
	if (cr6.lt) goto loc_821F075C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-28160
	ctx.r3.s64 = r11.s64 + -28160;
	// bl 0x82130000
	ctx.lr = 0x821F0790;
	sub_82130000(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821F0798:
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x821f07b8
	if (!cr6.eq) goto loc_821F07B8;
loc_821F07A0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-28160
	ctx.r3.s64 = r11.s64 + -28160;
	// bl 0x82130000
	ctx.lr = 0x821F07B0;
	sub_82130000(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821F07B8:
	// lwz r5,332(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bgt cr6,0x821f07d4
	if (cr6.gt) goto loc_821F07D4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r11,-28712
	ctx.r3.s64 = r11.s64 + -28712;
	// bl 0x821bd618
	ctx.lr = 0x821F07D4;
	sub_821BD618(ctx, base);
loc_821F07D4:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// beq cr6,0x821f07ec
	if (cr6.eq) goto loc_821F07EC;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
loc_821F07EC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f0600
	ctx.lr = 0x821F07F8;
	sub_821F0600(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F0800"))) PPC_WEAK_FUNC(sub_821F0800);
PPC_FUNC_IMPL(__imp__sub_821F0800) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,496(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 496);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,526(r3)
	PPC_STORE_U8(ctx.r3.u32 + 526, ctx.r10.u8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821f082c
	if (cr6.lt) goto loc_821F082C;
	// beq cr6,0x821f0828
	if (cr6.eq) goto loc_821F0828;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x821ef1f8
	sub_821EF1F8(ctx, base);
	return;
loc_821F0828:
	// b 0x821ef158
	sub_821EF158(ctx, base);
	return;
loc_821F082C:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821ef950
	sub_821EF950(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F0834"))) PPC_WEAK_FUNC(sub_821F0834);
PPC_FUNC_IMPL(__imp__sub_821F0834) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F0838"))) PPC_WEAK_FUNC(sub_821F0838);
PPC_FUNC_IMPL(__imp__sub_821F0838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r3,388(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f0868
	if (cr6.eq) goto loc_821F0868;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F0868;
	sub_821F4C18(ctx, base);
loc_821F0868:
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lhz r8,82(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// lfs f0,-28476(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28476);
	f0.f64 = double(temp.f32);
	// lwz r10,26652(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26652);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r6,r10
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x821f09d8
	if (!cr6.gt) goto loc_821F09D8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a30
	ctx.lr = 0x821F08A8;
	sub_82144A30(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f09d8
	if (!cr6.eq) goto loc_821F09D8;
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f0940
	if (!cr6.eq) goto loc_821F0940;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x821f0a4c
	if (cr6.eq) goto loc_821F0A4C;
	// lbz r11,526(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 526);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f0910
	if (cr6.eq) goto loc_821F0910;
	// lwz r11,496(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// stb r10,526(r31)
	PPC_STORE_U8(r31.u32 + 526, ctx.r10.u8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821f0930
	if (cr6.lt) goto loc_821F0930;
	// beq cr6,0x821f0904
	if (cr6.eq) goto loc_821F0904;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x821f0a4c
	if (!cr6.lt) goto loc_821F0A4C;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef1f8
	ctx.lr = 0x821F0900;
	sub_821EF1F8(ctx, base);
	// b 0x821f0a4c
	goto loc_821F0A4C;
loc_821F0904:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef158
	ctx.lr = 0x821F090C;
	sub_821EF158(ctx, base);
	// b 0x821f0a4c
	goto loc_821F0A4C;
loc_821F0910:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-28012(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28012);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x821f0930
	if (cr6.lt) goto loc_821F0930;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f0270
	ctx.lr = 0x821F0930;
	sub_821F0270(ctx, base);
loc_821F0930:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef950
	ctx.lr = 0x821F093C;
	sub_821EF950(ctx, base);
	// b 0x821f0a4c
	goto loc_821F0A4C;
loc_821F0940:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x821f0a4c
	if (!cr6.eq) goto loc_821F0A4C;
	// lwz r10,172(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82157178
	ctx.lr = 0x821F0964;
	sub_82157178(ctx, base);
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lbz r7,44(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 44);
	// extsw r5,r8
	ctx.r5.s64 = ctx.r8.s32;
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// li r6,0
	ctx.r6.s64 = 0;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stw r6,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r6.u32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fdivs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// stfs f8,72(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// bne cr6,0x821f0a4c
	if (!cr6.eq) goto loc_821F0A4C;
	// lfs f0,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x821f0a4c
	if (!cr6.lt) goto loc_821F0A4C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef4e8
	ctx.lr = 0x821F09D4;
	sub_821EF4E8(ctx, base);
	// b 0x821f0a4c
	goto loc_821F0A4C;
loc_821F09D8:
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f0a4c
	if (cr6.eq) goto loc_821F0A4C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x821f0a44
	if (!cr6.eq) goto loc_821F0A44;
	// lwz r10,172(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82157178
	ctx.lr = 0x821F0A0C;
	sub_82157178(ctx, base);
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
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
	// fdivs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// stfs f8,72(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
loc_821F0A44:
	// lwz r3,384(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// bl 0x821f4c98
	ctx.lr = 0x821F0A4C;
	sub_821F4C98(ctx, base);
loc_821F0A4C:
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_821F0A68"))) PPC_WEAK_FUNC(sub_821F0A68);
PPC_FUNC_IMPL(__imp__sub_821F0A68) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,-12216(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// addi r5,r31,516
	ctx.r5.s64 = r31.s64 + 516;
	// lwz r10,516(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 516);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f0aac
	if (!cr6.eq) goto loc_821F0AAC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-28504
	ctx.r4.s64 = ctx.r9.s64 + -28504;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee720
	ctx.lr = 0x821F0AAC;
	sub_821EE720(ctx, base);
loc_821F0AAC:
	// li r11,1
	r11.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,528(r31)
	PPC_STORE_U8(r31.u32 + 528, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ef950
	ctx.lr = 0x821F0AC0;
	sub_821EF950(ctx, base);
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

__attribute__((alias("__imp__sub_821F0AD4"))) PPC_WEAK_FUNC(sub_821F0AD4);
PPC_FUNC_IMPL(__imp__sub_821F0AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F0AD8"))) PPC_WEAK_FUNC(sub_821F0AD8);
PPC_FUNC_IMPL(__imp__sub_821F0AD8) {
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
	// bl 0x821effc0
	ctx.lr = 0x821F0AF8;
	sub_821EFFC0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f0b10
	if (cr6.eq) goto loc_821F0B10;
	// bl 0x82130588
	ctx.lr = 0x821F0B0C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F0B10:
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

__attribute__((alias("__imp__sub_821F0B28"))) PPC_WEAK_FUNC(sub_821F0B28);
PPC_FUNC_IMPL(__imp__sub_821F0B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821f0108
	sub_821F0108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F0B3C"))) PPC_WEAK_FUNC(sub_821F0B3C);
PPC_FUNC_IMPL(__imp__sub_821F0B3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F0B40"))) PPC_WEAK_FUNC(sub_821F0B40);
PPC_FUNC_IMPL(__imp__sub_821F0B40) {
	PPC_FUNC_PROLOGUE();
	// b 0x821f0a68
	sub_821F0A68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F0B44"))) PPC_WEAK_FUNC(sub_821F0B44);
PPC_FUNC_IMPL(__imp__sub_821F0B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F0B48"))) PPC_WEAK_FUNC(sub_821F0B48);
PPC_FUNC_IMPL(__imp__sub_821F0B48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// b 0x821f0270
	sub_821F0270(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F0B58"))) PPC_WEAK_FUNC(sub_821F0B58);
PPC_FUNC_IMPL(__imp__sub_821F0B58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// b 0x821f0400
	sub_821F0400(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F0B68"))) PPC_WEAK_FUNC(sub_821F0B68);
PPC_FUNC_IMPL(__imp__sub_821F0B68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32225
	r11.s64 = -2111897600;
	// addi r10,r11,2104
	ctx.r10.s64 = r11.s64 + 2104;
	// lwz r3,-12216(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12216);
	// lwz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821f0ba8
	if (!cr6.eq) goto loc_821F0BA8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f0ba0
	if (cr6.eq) goto loc_821F0BA0;
	// lwz r11,380(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821f0ba8
	if (!cr6.eq) goto loc_821F0BA8;
loc_821F0BA0:
	// li r11,1
	r11.s64 = 1;
	// b 0x821f0bac
	goto loc_821F0BAC;
loc_821F0BA8:
	// li r11,0
	r11.s64 = 0;
loc_821F0BAC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x821ef1f8
	sub_821EF1F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F0BBC"))) PPC_WEAK_FUNC(sub_821F0BBC);
PPC_FUNC_IMPL(__imp__sub_821F0BBC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F0BC0"))) PPC_WEAK_FUNC(sub_821F0BC0);
PPC_FUNC_IMPL(__imp__sub_821F0BC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// lwz r11,496(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 496);
	// stb r10,526(r3)
	PPC_STORE_U8(ctx.r3.u32 + 526, ctx.r10.u8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821f0bf4
	if (cr6.lt) goto loc_821F0BF4;
	// beq cr6,0x821f0bf0
	if (cr6.eq) goto loc_821F0BF0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x821ef1f8
	sub_821EF1F8(ctx, base);
	return;
loc_821F0BF0:
	// b 0x821ef158
	sub_821EF158(ctx, base);
	return;
loc_821F0BF4:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821ef950
	sub_821EF950(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F0BFC"))) PPC_WEAK_FUNC(sub_821F0BFC);
PPC_FUNC_IMPL(__imp__sub_821F0BFC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F0C00"))) PPC_WEAK_FUNC(sub_821F0C00);
PPC_FUNC_IMPL(__imp__sub_821F0C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x821f0700
	sub_821F0700(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F0C0C"))) PPC_WEAK_FUNC(sub_821F0C0C);
PPC_FUNC_IMPL(__imp__sub_821F0C0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F0C10"))) PPC_WEAK_FUNC(sub_821F0C10);
PPC_FUNC_IMPL(__imp__sub_821F0C10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// addi r10,r10,2104
	ctx.r10.s64 = ctx.r10.s64 + 2104;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821f0c40
	if (!cr6.eq) goto loc_821F0C40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f0c38
	if (cr6.eq) goto loc_821F0C38;
	// lwz r11,380(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821f0c40
	if (!cr6.eq) goto loc_821F0C40;
loc_821F0C38:
	// li r11,1
	r11.s64 = 1;
	// b 0x821f0c44
	goto loc_821F0C44;
loc_821F0C40:
	// li r11,0
	r11.s64 = 0;
loc_821F0C44:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x821ef1f8
	sub_821EF1F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F0C58"))) PPC_WEAK_FUNC(sub_821F0C58);
PPC_FUNC_IMPL(__imp__sub_821F0C58) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F0C5C"))) PPC_WEAK_FUNC(sub_821F0C5C);
PPC_FUNC_IMPL(__imp__sub_821F0C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F0C60"))) PPC_WEAK_FUNC(sub_821F0C60);
PPC_FUNC_IMPL(__imp__sub_821F0C60) {
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
	// lis r11,-32225
	r11.s64 = -2111897600;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,2856
	ctx.r4.s64 = r11.s64 + 2856;
	// addi r3,r10,-27624
	ctx.r3.s64 = ctx.r10.s64 + -27624;
	// bl 0x82554798
	ctx.lr = 0x821F0C80;
	sub_82554798(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,2880
	ctx.r4.s64 = ctx.r9.s64 + 2880;
	// addi r3,r8,-27652
	ctx.r3.s64 = ctx.r8.s64 + -27652;
	// bl 0x82554798
	ctx.lr = 0x821F0C94;
	sub_82554798(ctx, base);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,1480
	ctx.r4.s64 = ctx.r7.s64 + 1480;
	// addi r3,r6,-27672
	ctx.r3.s64 = ctx.r6.s64 + -27672;
	// bl 0x82554798
	ctx.lr = 0x821F0CA8;
	sub_82554798(ctx, base);
	// lis r5,-32225
	ctx.r5.s64 = -2111897600;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,1496
	ctx.r4.s64 = ctx.r5.s64 + 1496;
	// addi r3,r3,-27696
	ctx.r3.s64 = ctx.r3.s64 + -27696;
	// bl 0x82554798
	ctx.lr = 0x821F0CBC;
	sub_82554798(ctx, base);
	// lis r11,-32225
	r11.s64 = -2111897600;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,2888
	ctx.r4.s64 = r11.s64 + 2888;
	// addi r3,r10,-27716
	ctx.r3.s64 = ctx.r10.s64 + -27716;
	// bl 0x82554798
	ctx.lr = 0x821F0CD0;
	sub_82554798(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,2904
	ctx.r4.s64 = ctx.r9.s64 + 2904;
	// addi r3,r8,-27736
	ctx.r3.s64 = ctx.r8.s64 + -27736;
	// bl 0x82554798
	ctx.lr = 0x821F0CE4;
	sub_82554798(ctx, base);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-3960
	ctx.r4.s64 = ctx.r7.s64 + -3960;
	// addi r3,r6,-27768
	ctx.r3.s64 = ctx.r6.s64 + -27768;
	// bl 0x82554798
	ctx.lr = 0x821F0CF8;
	sub_82554798(ctx, base);
	// lis r5,-32225
	ctx.r5.s64 = -2111897600;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,2920
	ctx.r4.s64 = ctx.r5.s64 + 2920;
	// addi r3,r3,-27800
	ctx.r3.s64 = ctx.r3.s64 + -27800;
	// bl 0x82554798
	ctx.lr = 0x821F0D0C;
	sub_82554798(ctx, base);
	// lis r11,-32225
	r11.s64 = -2111897600;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,3008
	ctx.r4.s64 = r11.s64 + 3008;
	// addi r3,r10,-27832
	ctx.r3.s64 = ctx.r10.s64 + -27832;
	// bl 0x82554798
	ctx.lr = 0x821F0D20;
	sub_82554798(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,3072
	ctx.r4.s64 = ctx.r9.s64 + 3072;
	// addi r3,r8,-27864
	ctx.r3.s64 = ctx.r8.s64 + -27864;
	// bl 0x82554798
	ctx.lr = 0x821F0D34;
	sub_82554798(ctx, base);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,1512
	ctx.r4.s64 = ctx.r7.s64 + 1512;
	// addi r3,r6,-27896
	ctx.r3.s64 = ctx.r6.s64 + -27896;
	// bl 0x82554798
	ctx.lr = 0x821F0D48;
	sub_82554798(ctx, base);
	// lis r5,-32225
	ctx.r5.s64 = -2111897600;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r4,r5,-3936
	ctx.r4.s64 = ctx.r5.s64 + -3936;
	// addi r3,r3,-27928
	ctx.r3.s64 = ctx.r3.s64 + -27928;
	// bl 0x82554798
	ctx.lr = 0x821F0D5C;
	sub_82554798(ctx, base);
	// lis r11,-32225
	r11.s64 = -2111897600;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-3904
	ctx.r4.s64 = r11.s64 + -3904;
	// addi r3,r10,-27968
	ctx.r3.s64 = ctx.r10.s64 + -27968;
	// bl 0x82554798
	ctx.lr = 0x821F0D70;
	sub_82554798(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-3864
	ctx.r4.s64 = ctx.r9.s64 + -3864;
	// addi r3,r8,-28008
	ctx.r3.s64 = ctx.r8.s64 + -28008;
	// bl 0x82554798
	ctx.lr = 0x821F0D84;
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

__attribute__((alias("__imp__sub_821F0D94"))) PPC_WEAK_FUNC(sub_821F0D94);
PPC_FUNC_IMPL(__imp__sub_821F0D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F0D98"))) PPC_WEAK_FUNC(sub_821F0D98);
PPC_FUNC_IMPL(__imp__sub_821F0D98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821f0db0
	if (!cr6.eq) goto loc_821F0DB0;
	// li r11,1
	r11.s64 = 1;
	// b 0x821f0df4
	goto loc_821F0DF4;
loc_821F0DB0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f0df0
	if (cr6.eq) goto loc_821F0DF0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f0df0
	if (cr6.eq) goto loc_821F0DF0;
loc_821F0DC0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821f0de4
	if (cr6.eq) goto loc_821F0DE4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821f0dc0
	if (cr6.eq) goto loc_821F0DC0;
loc_821F0DE4:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x821f0df4
	goto loc_821F0DF4;
loc_821F0DF0:
	// li r11,0
	r11.s64 = 0;
loc_821F0DF4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f0e6c
	if (cr6.eq) goto loc_821F0E6C;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821f0e18
	if (!cr6.eq) goto loc_821F0E18;
	// li r11,1
	r11.s64 = 1;
	// b 0x821f0e5c
	goto loc_821F0E5C;
loc_821F0E18:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f0e58
	if (cr6.eq) goto loc_821F0E58;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f0e58
	if (cr6.eq) goto loc_821F0E58;
loc_821F0E28:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821f0e4c
	if (cr6.eq) goto loc_821F0E4C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821f0e28
	if (cr6.eq) goto loc_821F0E28;
loc_821F0E4C:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x821f0e5c
	goto loc_821F0E5C;
loc_821F0E58:
	// li r11,0
	r11.s64 = 0;
loc_821F0E5C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x821f0e70
	if (!cr6.eq) goto loc_821F0E70;
loc_821F0E6C:
	// li r11,0
	r11.s64 = 0;
loc_821F0E70:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

