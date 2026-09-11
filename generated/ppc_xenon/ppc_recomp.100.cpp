#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_824E5440"))) PPC_WEAK_FUNC(sub_824E5440);
PPC_FUNC_IMPL(__imp__sub_824E5440) {
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
	ctx.lr = 0x824E5448;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x824e3a08
	ctx.lr = 0x824E5458;
	sub_824E3A08(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5498
	if (!cr6.eq) goto loc_824E5498;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5474;
	sub_821C8FE0(ctx, base);
	// lbz r11,21(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 21);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,744(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// bne cr6,0x824e548c
	if (!cr6.eq) goto loc_824E548C;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_824E548C:
	// stw r10,744(r31)
	PPC_STORE_U32(r31.u32 + 744, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E5498;
	sub_821C9030(ctx, base);
loc_824E5498:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E54A4"))) PPC_WEAK_FUNC(sub_824E54A4);
PPC_FUNC_IMPL(__imp__sub_824E54A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E54A8"))) PPC_WEAK_FUNC(sub_824E54A8);
PPC_FUNC_IMPL(__imp__sub_824E54A8) {
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
	ctx.lr = 0x824E54B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x824e3b68
	ctx.lr = 0x824E54C0;
	sub_824E3B68(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E54D0;
	sub_821C8FE0(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e55ec
	if (cr6.eq) goto loc_824E55EC;
	// lwz r11,1804(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1804);
	// lwz r10,212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x824e5564
	if (!cr6.lt) goto loc_824E5564;
	// lwz r11,1800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824e5548
	if (!cr6.gt) goto loc_824E5548;
	// addi r11,r31,800
	r11.s64 = r31.s64 + 800;
	// li r7,1
	ctx.r7.s64 = 1;
loc_824E5508:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x824e5534
	if (!cr6.eq) goto loc_824E5534;
	// lwz r10,212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// ble cr6,0x824e5534
	if (!cr6.gt) goto loc_824E5534;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// lwz r10,1808(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, ctx.r10.u32);
loc_824E5534:
	// lwz r10,1800(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x824e5508
	if (cr6.lt) goto loc_824E5508;
loc_824E5548:
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,1804(r31)
	PPC_STORE_U32(r31.u32 + 1804, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E5558;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824E5564:
	// lwz r11,1808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x824e55fc
	if (!cr6.lt) goto loc_824E55FC;
	// lwz r11,1800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824e55d0
	if (!cr6.gt) goto loc_824E55D0;
	// addi r11,r31,800
	r11.s64 = r31.s64 + 800;
loc_824E558C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x824e55bc
	if (!cr6.eq) goto loc_824E55BC;
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// ble cr6,0x824e55bc
	if (!cr6.gt) goto loc_824E55BC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r10,1804(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1804);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,1804(r31)
	PPC_STORE_U32(r31.u32 + 1804, ctx.r7.u32);
loc_824E55BC:
	// lwz r10,1800(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x824e558c
	if (cr6.lt) goto loc_824E558C;
loc_824E55D0:
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E55E0;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824E55EC:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// stw r10,216(r31)
	PPC_STORE_U32(r31.u32 + 216, ctx.r10.u32);
loc_824E55FC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E5604;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E5610"))) PPC_WEAK_FUNC(sub_824E5610);
PPC_FUNC_IMPL(__imp__sub_824E5610) {
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
	ctx.lr = 0x824E5618;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x824e3db0
	ctx.lr = 0x824E5628;
	sub_824E3DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5684
	if (cr6.eq) goto loc_824E5684;
	// addi r29,r30,20
	r29.s64 = r30.s64 + 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82618f10
	ctx.lr = 0x824E5644;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5684
	if (cr6.eq) goto loc_824E5684;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e566c
	if (cr6.eq) goto loc_824E566C;
	// addi r4,r30,21
	ctx.r4.s64 = r30.s64 + 21;
	// bl 0x824fa458
	ctx.lr = 0x824E5668;
	sub_824FA458(ctx, base);
	// b 0x824e5674
	goto loc_824E5674;
loc_824E566C:
	// addi r4,r30,534
	ctx.r4.s64 = r30.s64 + 534;
	// bl 0x824fa548
	ctx.lr = 0x824E5674;
	sub_824FA548(ctx, base);
loc_824E5674:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e5688
	if (!cr6.eq) goto loc_824E5688;
loc_824E5684:
	// li r11,0
	r11.s64 = 0;
loc_824E5688:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E5694"))) PPC_WEAK_FUNC(sub_824E5694);
PPC_FUNC_IMPL(__imp__sub_824E5694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E5698"))) PPC_WEAK_FUNC(sub_824E5698);
PPC_FUNC_IMPL(__imp__sub_824E5698) {
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
	// bl 0x824e3e38
	ctx.lr = 0x824E56B8;
	sub_824E3E38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e56e0
	if (cr6.eq) goto loc_824E56E0;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa558
	ctx.lr = 0x824E56D0;
	sub_824FA558(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e56e4
	if (!cr6.eq) goto loc_824E56E4;
loc_824E56E0:
	// li r11,0
	r11.s64 = 0;
loc_824E56E4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E5700"))) PPC_WEAK_FUNC(sub_824E5700);
PPC_FUNC_IMPL(__imp__sub_824E5700) {
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
	ctx.lr = 0x824E5708;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x824E5738;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824E5744;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824E5754;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e5784
	if (cr6.eq) goto loc_824E5784;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824e5784
	if (!cr6.eq) goto loc_824E5784;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e5610
	ctx.lr = 0x824E5774;
	sub_824E5610(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5788
	if (!cr6.eq) goto loc_824E5788;
loc_824E5784:
	// li r31,0
	r31.s64 = 0;
loc_824E5788:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e57b4
	if (cr6.eq) goto loc_824E57B4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e57ac
	if (cr6.eq) goto loc_824E57AC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824E57A4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824e57b0
	goto loc_824E57B0;
loc_824E57AC:
	// li r11,0
	r11.s64 = 0;
loc_824E57B0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824E57B4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e57d8
	if (cr6.eq) goto loc_824E57D8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824E57C8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e57dc
	if (cr6.eq) goto loc_824E57DC;
loc_824E57D8:
	// li r11,0
	r11.s64 = 0;
loc_824E57DC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E57E8"))) PPC_WEAK_FUNC(sub_824E57E8);
PPC_FUNC_IMPL(__imp__sub_824E57E8) {
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
	ctx.lr = 0x824E57F0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x824E5814;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824E5820;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824E5830;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e5854
	if (cr6.eq) goto loc_824E5854;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e5698
	ctx.lr = 0x824E5844;
	sub_824E5698(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5858
	if (!cr6.eq) goto loc_824E5858;
loc_824E5854:
	// li r30,0
	r30.s64 = 0;
loc_824E5858:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e5890
	if (cr6.eq) goto loc_824E5890;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5888
	if (cr6.eq) goto loc_824E5888;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824E5874;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_824E5888:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824E5890:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E589C"))) PPC_WEAK_FUNC(sub_824E589C);
PPC_FUNC_IMPL(__imp__sub_824E589C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E58A0"))) PPC_WEAK_FUNC(sub_824E58A0);
PPC_FUNC_IMPL(__imp__sub_824E58A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x824E58A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// addi r10,r11,26008
	ctx.r10.s64 = r11.s64 + 26008;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e71c8
	ctx.lr = 0x824E58C8;
	sub_824E71C8(ctx, base);
	// addi r3,r30,104
	ctx.r3.s64 = r30.s64 + 104;
	// bl 0x824e6400
	ctx.lr = 0x824E58D0;
	sub_824E6400(ctx, base);
	// addi r3,r30,164
	ctx.r3.s64 = r30.s64 + 164;
	// bl 0x82501b00
	ctx.lr = 0x824E58D8;
	sub_82501B00(ctx, base);
	// addi r3,r30,200
	ctx.r3.s64 = r30.s64 + 200;
	// bl 0x824e1c10
	ctx.lr = 0x824E58E0;
	sub_824E1C10(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,768(r31)
	PPC_STORE_U32(r31.u32 + 768, r28.u32);
	// bl 0x824e0b08
	ctx.lr = 0x824E58F0;
	sub_824E0B08(ctx, base);
	// addi r29,r31,776
	r29.s64 = r31.s64 + 776;
	// li r27,31
	r27.s64 = 31;
	// addi r30,r29,8
	r30.s64 = r29.s64 + 8;
	// li r26,-1
	r26.s64 = -1;
loc_824E5900:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E5908;
	sub_824F0498(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9438
	ctx.lr = 0x824E5910;
	sub_824F9438(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E5918;
	sub_824F0498(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9230
	ctx.lr = 0x824E5920;
	sub_824F9230(ctx, base);
	// stw r26,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r26.u32);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,32
	r29.s64 = r29.s64 + 32;
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// bge 0x824e5900
	if (!cr0.lt) goto loc_824E5900;
	// stw r28,1800(r31)
	PPC_STORE_U32(r31.u32 + 1800, r28.u32);
	// addi r3,r31,1816
	ctx.r3.s64 = r31.s64 + 1816;
	// stw r28,1804(r31)
	PPC_STORE_U32(r31.u32 + 1804, r28.u32);
	// stw r28,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, r28.u32);
	// stw r28,1812(r31)
	PPC_STORE_U32(r31.u32 + 1812, r28.u32);
	// bl 0x824f9150
	ctx.lr = 0x824E594C;
	sub_824F9150(ctx, base);
	// stw r28,1968(r31)
	PPC_STORE_U32(r31.u32 + 1968, r28.u32);
	// stw r28,1972(r31)
	PPC_STORE_U32(r31.u32 + 1972, r28.u32);
	// addi r3,r31,1976
	ctx.r3.s64 = r31.s64 + 1976;
	// bl 0x824e6928
	ctx.lr = 0x824E595C;
	sub_824E6928(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r28,2028(r31)
	PPC_STORE_U32(r31.u32 + 2028, r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,25868
	r30.s64 = r11.s64 + 25868;
	// stw r30,1976(r31)
	PPC_STORE_U32(r31.u32 + 1976, r30.u32);
	// bl 0x821c9060
	ctx.lr = 0x824E5974;
	sub_821C9060(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,2032(r31)
	PPC_STORE_U32(r31.u32 + 2032, ctx.r3.u32);
	// addi r3,r31,2036
	ctx.r3.s64 = r31.s64 + 2036;
	// addi r9,r10,25888
	ctx.r9.s64 = ctx.r10.s64 + 25888;
	// stw r9,1976(r31)
	PPC_STORE_U32(r31.u32 + 1976, ctx.r9.u32);
	// bl 0x824e6928
	ctx.lr = 0x824E598C;
	sub_824E6928(ctx, base);
	// stw r30,2036(r31)
	PPC_STORE_U32(r31.u32 + 2036, r30.u32);
	// stw r28,2088(r31)
	PPC_STORE_U32(r31.u32 + 2088, r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x824E599C;
	sub_821C9060(ctx, base);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// stw r3,2092(r31)
	PPC_STORE_U32(r31.u32 + 2092, ctx.r3.u32);
	// addi r3,r31,2100
	ctx.r3.s64 = r31.s64 + 2100;
	// addi r7,r8,25908
	ctx.r7.s64 = ctx.r8.s64 + 25908;
	// stw r7,2036(r31)
	PPC_STORE_U32(r31.u32 + 2036, ctx.r7.u32);
	// stw r28,2096(r31)
	PPC_STORE_U32(r31.u32 + 2096, r28.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824E59B8;
	sub_821C8ED8(ctx, base);
	// lbz r6,2132(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r5,r6,25
	ctx.r5.u64 = ctx.r6.u32 & 0x7F;
	// stb r5,2132(r31)
	PPC_STORE_U8(r31.u32 + 2132, ctx.r5.u8);
	// bl 0x824e4d20
	ctx.lr = 0x824E59CC;
	sub_824E4D20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E59D8"))) PPC_WEAK_FUNC(sub_824E59D8);
PPC_FUNC_IMPL(__imp__sub_824E59D8) {
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
	ctx.lr = 0x824E59E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r11,2132(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e5a54
	if (!cr6.eq) goto loc_824E5A54;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4d20
	ctx.lr = 0x824E5A08;
	sub_824E4D20(ctx, base);
	// stw r31,2028(r31)
	PPC_STORE_U32(r31.u32 + 2028, r31.u32);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,1976
	r30.s64 = r31.s64 + 1976;
	// lis r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,26012
	ctx.r4.s64 = r11.s64 + 26012;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b98
	ctx.lr = 0x824E5A2C;
	sub_824E6B98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5a40
	if (!cr6.eq) goto loc_824E5A40;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,52(r30)
	PPC_STORE_U32(r30.u32 + 52, ctx.r10.u32);
loc_824E5A40:
	// lbz r10,2132(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// rlwimi r10,r11,7,0,24
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0xFFFFFF80) | (ctx.r10.u64 & 0xFFFFFFFF0000007F);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r3,r9,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1;
	// stb r9,2132(r31)
	PPC_STORE_U8(r31.u32 + 2132, ctx.r9.u8);
loc_824E5A54:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E5A5C"))) PPC_WEAK_FUNC(sub_824E5A5C);
PPC_FUNC_IMPL(__imp__sub_824E5A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E5A60"))) PPC_WEAK_FUNC(sub_824E5A60);
PPC_FUNC_IMPL(__imp__sub_824E5A60) {
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
	// lbz r11,2132(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e5aac
	if (cr6.eq) goto loc_824E5AAC;
	// lwz r11,1976(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1976);
	// addi r3,r31,1976
	ctx.r3.s64 = r31.s64 + 1976;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E5A98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4d20
	ctx.lr = 0x824E5AA0;
	sub_824E4D20(ctx, base);
	// lbz r9,2132(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stb r8,2132(r31)
	PPC_STORE_U8(r31.u32 + 2132, ctx.r8.u8);
loc_824E5AAC:
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

__attribute__((alias("__imp__sub_824E5AC0"))) PPC_WEAK_FUNC(sub_824E5AC0);
PPC_FUNC_IMPL(__imp__sub_824E5AC0) {
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
	ctx.lr = 0x824E5AC8;
	// stwu r1,-944(r1)
	ea = -944 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2100
	r28.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5AE8;
	sub_821C8FE0(ctx, base);
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0b08
	ctx.lr = 0x824E5AF4;
	sub_824E0B08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E5AFC;
	sub_821C9030(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e2e30
	ctx.lr = 0x824E5B08;
	sub_824E2E30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5bc8
	if (cr6.eq) goto loc_824E5BC8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5B20;
	sub_821C8FE0(ctx, base);
	// addi r4,r30,24
	ctx.r4.s64 = r30.s64 + 24;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e2d40
	ctx.lr = 0x824E5B2C;
	sub_824E2D40(ctx, base);
	// li r27,2
	r27.s64 = 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// lwz r11,792(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 792);
	// stw r11,1812(r31)
	PPC_STORE_U32(r31.u32 + 1812, r11.u32);
	// lwz r10,796(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 796);
	// stw r10,1968(r31)
	PPC_STORE_U32(r31.u32 + 1968, ctx.r10.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E5B4C;
	sub_821C9030(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5B58;
	sub_821C8FE0(ctx, base);
	// lwz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r8,r27,r9
	ctx.r8.s64 = ctx.r9.s64 - r27.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r30,r7,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E5B70;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e5bd4
	if (cr6.eq) goto loc_824E5BD4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1808
	ctx.lr = 0x824E5B80;
	sub_824E1808(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5bd4
	if (!cr6.eq) goto loc_824E5BD4;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r26,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r26.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r26.u32);
	// addi r9,r11,26000
	ctx.r9.s64 = r11.s64 + 26000;
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x824e1b78
	ctx.lr = 0x824E5BBC;
	sub_824E1B78(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4f78
	ctx.lr = 0x824E5BC8;
	sub_824E4F78(ctx, base);
loc_824E5BC8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9240
	return;
loc_824E5BD4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E5BE0"))) PPC_WEAK_FUNC(sub_824E5BE0);
PPC_FUNC_IMPL(__imp__sub_824E5BE0) {
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
	ctx.lr = 0x824E5BE8;
	// stwu r1,-2592(r1)
	ea = -2592 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e6310
	ctx.lr = 0x824E5BF8;
	sub_824E6310(ctx, base);
	// lis r11,8
	r11.s64 = 524288;
	// li r21,0
	r21.s64 = 0;
	// ori r10,r11,44613
	ctx.r10.u64 = r11.u64 | 44613;
	// std r21,200(r1)
	PPC_STORE_U64(ctx.r1.u32 + 200, r21.u64);
	// addi r3,r1,213
	ctx.r3.s64 = ctx.r1.s64 + 213;
	// stw r10,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r10.u32);
	// bl 0x824e8de8
	ctx.lr = 0x824E5C14;
	sub_824E8DE8(ctx, base);
	// addi r3,r1,726
	ctx.r3.s64 = ctx.r1.s64 + 726;
	// bl 0x824e6400
	ctx.lr = 0x824E5C1C;
	sub_824E6400(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r25,-1
	r25.s64 = -1;
	// ori r24,r9,32779
	r24.u64 = ctx.r9.u64 | 32779;
	// addi r23,r11,32300
	r23.s64 = r11.s64 + 32300;
	// addi r20,r10,32332
	r20.s64 = ctx.r10.s64 + 32332;
loc_824E5C38:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// addi r5,r1,1440
	ctx.r5.s64 = ctx.r1.s64 + 1440;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r11,1816
	ctx.r3.s64 = r11.s64 + 1816;
	// bl 0x824f8f38
	ctx.lr = 0x824E5C54;
	sub_824F8F38(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// cmpwi cr6,r22,2
	cr6.compare<int32_t>(r22.s32, 2, xer);
	// blt cr6,0x824e5eb4
	if (cr6.lt) goto loc_824E5EB4;
	// lwz r30,52(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r30,2100
	ctx.r4.s64 = r30.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5C70;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// subf r10,r21,r11
	ctx.r10.s64 = r11.s64 - r21.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E5C88;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e5eb4
	if (!cr6.eq) goto loc_824E5EB4;
	// lwz r30,52(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// addi r4,r30,2100
	ctx.r4.s64 = r30.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5CA0;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// lwz r30,208(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// bl 0x821c9030
	ctx.lr = 0x824E5CAC;
	sub_821C9030(ctx, base);
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x824e5eb4
	if (!cr6.eq) goto loc_824E5EB4;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// lwz r4,8(r20)
	ctx.r4.u64 = PPC_LOAD_U32(r20.u32 + 8);
	// addi r6,r22,-2
	ctx.r6.s64 = r22.s64 + -2;
	// addi r5,r1,1442
	ctx.r5.s64 = ctx.r1.s64 + 1442;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x824e5700
	ctx.lr = 0x824E5CCC;
	sub_824E5700(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5eb4
	if (cr6.eq) goto loc_824E5EB4;
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// cmpw cr6,r10,r22
	cr6.compare<int32_t>(ctx.r10.s32, r22.s32, xer);
	// bne cr6,0x824e5eb4
	if (!cr6.eq) goto loc_824E5EB4;
	// lwz r30,52(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// addi r4,r30,2100
	ctx.r4.s64 = r30.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5CF8;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x821c9030
	ctx.lr = 0x824E5D00;
	sub_821C9030(ctx, base);
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r25.u32);
	// stw r25,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r25.u32);
	// addi r30,r30,208
	r30.s64 = r30.s64 + 208;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r29,r30,12
	r29.s64 = r30.s64 + 12;
	// mr r26,r21
	r26.u64 = r21.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9038
	ctx.lr = 0x824E5D20;
	sub_824E9038(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,213
	ctx.r3.s64 = ctx.r1.s64 + 213;
	// bl 0x824e9038
	ctx.lr = 0x824E5D30;
	sub_824E9038(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x824e5d80
	if (cr6.lt) goto loc_824E5D80;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x824e5d80
	if (cr6.lt) goto loc_824E5D80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9690
	ctx.lr = 0x824E5D58;
	sub_824E9690(ctx, base);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,213
	ctx.r3.s64 = ctx.r1.s64 + 213;
	// bl 0x824e9690
	ctx.lr = 0x824E5D6C;
	sub_824E9690(ctx, base);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r26,r8,27,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
loc_824E5D80:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5eb4
	if (cr6.eq) goto loc_824E5EB4;
	// addi r3,r1,800
	ctx.r3.s64 = ctx.r1.s64 + 800;
	// bl 0x824e0d78
	ctx.lr = 0x824E5D94;
	sub_824E0D78(ctx, base);
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// lwz r28,52(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r28,2100
	ctx.r4.s64 = r28.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5DA4;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// lwz r26,1808(r28)
	r26.u64 = PPC_LOAD_U32(r28.u32 + 1808);
	// bl 0x821c9030
	ctx.lr = 0x824E5DB0;
	sub_821C9030(ctx, base);
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// lwz r28,52(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r28,2100
	ctx.r4.s64 = r28.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5DC0;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// lwz r19,1804(r28)
	r19.u64 = PPC_LOAD_U32(r28.u32 + 1804);
	// bl 0x821c9030
	ctx.lr = 0x824E5DCC;
	sub_821C9030(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r28,52(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r28,2100
	ctx.r4.s64 = r28.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5DDC;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c9030
	ctx.lr = 0x824E5DE4;
	sub_821C9030(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r27,52(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r27,2100
	ctx.r4.s64 = r27.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5DF4;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821c9030
	ctx.lr = 0x824E5DFC;
	sub_821C9030(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r28,r28,112
	r28.s64 = r28.s64 + 112;
	// addi r3,r11,1816
	ctx.r3.s64 = r11.s64 + 1816;
	// lwz r18,8(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r30,4(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x824f8900
	ctx.lr = 0x824E5E14;
	sub_824F8900(ctx, base);
	// bl 0x82618670
	ctx.lr = 0x824E5E18;
	sub_82618670(ctx, base);
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x824E5E24;
	sub_824E7118(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,816
	ctx.r3.s64 = ctx.r1.s64 + 816;
	// stw r19,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r19.u32);
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// stw r18,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r18.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// bl 0x824fc0b8
	ctx.lr = 0x824E5E54;
	sub_824FC0B8(ctx, base);
	// ld r11,200(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 200);
	// addi r7,r1,124
	ctx.r7.s64 = ctx.r1.s64 + 124;
	// lwz r4,8(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// li r6,1022
	ctx.r6.s64 = 1022;
	// addi r5,r1,1442
	ctx.r5.s64 = ctx.r1.s64 + 1442;
	// addi r3,r1,800
	ctx.r3.s64 = ctx.r1.s64 + 800;
	// std r11,808(r1)
	PPC_STORE_U64(ctx.r1.u32 + 808, r11.u64);
	// bl 0x824e57e8
	ctx.lr = 0x824E5E74;
	sub_824E57E8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e5eb4
	if (cr6.eq) goto loc_824E5EB4;
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r29,r1,1440
	r29.s64 = ctx.r1.s64 + 1440;
	// addi r30,r11,2
	r30.s64 = r11.s64 + 2;
	// sth r30,1440(r1)
	PPC_STORE_U16(ctx.r1.u32 + 1440, r30.u16);
	// bl 0x824e6270
	ctx.lr = 0x824E5E98;
	sub_824E6270(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,1816
	ctx.r3.s64 = r11.s64 + 1816;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x824f8ea0
	ctx.lr = 0x824E5EB4;
	sub_824F8EA0(ctx, base);
loc_824E5EB4:
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// bgt cr6,0x824e5c38
	if (cr6.gt) goto loc_824E5C38;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x824E5EC4;
	sub_821C91B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6a10
	ctx.lr = 0x824E5ECC;
	sub_824E6A10(ctx, base);
	// addi r1,r1,2592
	ctx.r1.s64 = ctx.r1.s64 + 2592;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_824E5ED4"))) PPC_WEAK_FUNC(sub_824E5ED4);
PPC_FUNC_IMPL(__imp__sub_824E5ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E5ED8"))) PPC_WEAK_FUNC(sub_824E5ED8);
PPC_FUNC_IMPL(__imp__sub_824E5ED8) {
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
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r10,26008
	ctx.r9.s64 = ctx.r10.s64 + 26008;
	// lbz r11,2132(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// rlwinm r8,r11,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e5f30
	if (cr6.eq) goto loc_824E5F30;
	// lwz r11,1976(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1976);
	// addi r3,r31,1976
	ctx.r3.s64 = r31.s64 + 1976;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E5F1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4d20
	ctx.lr = 0x824E5F24;
	sub_824E4D20(ctx, base);
	// lbz r9,2132(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stb r8,2132(r31)
	PPC_STORE_U8(r31.u32 + 2132, ctx.r8.u8);
loc_824E5F30:
	// addi r3,r31,2100
	ctx.r3.s64 = r31.s64 + 2100;
	// bl 0x82130000
	ctx.lr = 0x824E5F38;
	sub_82130000(ctx, base);
	// addi r3,r31,2036
	ctx.r3.s64 = r31.s64 + 2036;
	// bl 0x824e6b58
	ctx.lr = 0x824E5F40;
	sub_824E6B58(ctx, base);
	// addi r3,r31,1976
	ctx.r3.s64 = r31.s64 + 1976;
	// bl 0x824e6b58
	ctx.lr = 0x824E5F48;
	sub_824E6B58(ctx, base);
	// addi r3,r31,1816
	ctx.r3.s64 = r31.s64 + 1816;
	// bl 0x824f91e0
	ctx.lr = 0x824E5F50;
	sub_824F91E0(ctx, base);
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

__attribute__((alias("__imp__sub_824E5F64"))) PPC_WEAK_FUNC(sub_824E5F64);
PPC_FUNC_IMPL(__imp__sub_824E5F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E5F68"))) PPC_WEAK_FUNC(sub_824E5F68);
PPC_FUNC_IMPL(__imp__sub_824E5F68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824E5F70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lwz r30,1972(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1972);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,11
	cr6.compare<uint32_t>(r11.u32, 11, xer);
	// bgt cr6,0x824e6088
	if (cr6.gt) goto loc_824E6088;
	// lis r12,-32178
	r12.s64 = -2108817408;
	// addi r12,r12,24488
	r12.s64 = r12.s64 + 24488;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E5FD8;
	case 1:
		goto loc_824E5FD8;
	case 2:
		goto loc_824E5FE8;
	case 3:
		goto loc_824E5FF8;
	case 4:
		goto loc_824E6008;
	case 5:
		goto loc_824E6018;
	case 6:
		goto loc_824E6028;
	case 7:
		goto loc_824E6038;
	case 8:
		goto loc_824E6048;
	case 9:
		goto loc_824E6058;
	case 10:
		goto loc_824E6068;
	case 11:
		goto loc_824E6078;
	default:
		__builtin_unreachable();
	}
	// lwz r18,24536(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24536);
	// lwz r18,24536(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24536);
	// lwz r18,24552(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24552);
	// lwz r18,24568(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24568);
	// lwz r18,24584(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24584);
	// lwz r18,24600(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24600);
	// lwz r18,24616(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24616);
	// lwz r18,24632(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24632);
	// lwz r18,24648(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24648);
	// lwz r18,24664(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24664);
	// lwz r18,24680(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24680);
	// lwz r18,24696(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24696);
loc_824E5FD8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e5ac0
	ctx.lr = 0x824E5FE4;
	sub_824E5AC0(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E5FE8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4dd8
	ctx.lr = 0x824E5FF4;
	sub_824E4DD8(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E5FF8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4ee8
	ctx.lr = 0x824E6004;
	sub_824E4EE8(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6008:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4f78
	ctx.lr = 0x824E6014;
	sub_824E4F78(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6018:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4fe0
	ctx.lr = 0x824E6024;
	sub_824E4FE0(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6028:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e51b0
	ctx.lr = 0x824E6034;
	sub_824E51B0(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6038:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e2dd8
	ctx.lr = 0x824E6044;
	sub_824E2DD8(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6048:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e3690
	ctx.lr = 0x824E6054;
	sub_824E3690(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6058:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e5350
	ctx.lr = 0x824E6064;
	sub_824E5350(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6068:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e5440
	ctx.lr = 0x824E6074;
	sub_824E5440(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6078:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e54a8
	ctx.lr = 0x824E6084;
	sub_824E54A8(ctx, base);
loc_824E6084:
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_824E6088:
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E6094;
	sub_821C8FE0(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// stw r28,1972(r31)
	PPC_STORE_U32(r31.u32 + 1972, r28.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r31,8(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824e60c0
	if (cr6.eq) goto loc_824E60C0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824E60B8;
	sub_821CE0A0(ctx, base);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// b 0x824e60d0
	goto loc_824E60D0;
loc_824E60C0:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824E60C8;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_824E60D0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,32268(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// bl 0x824e1948
	ctx.lr = 0x824E60E0;
	sub_824E1948(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E60E8;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E60F0"))) PPC_WEAK_FUNC(sub_824E60F0);
PPC_FUNC_IMPL(__imp__sub_824E60F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// b 0x824e5f68
	sub_824E5F68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E60F8"))) PPC_WEAK_FUNC(sub_824E60F8);
PPC_FUNC_IMPL(__imp__sub_824E60F8) {
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
	// bl 0x824e5ed8
	ctx.lr = 0x824E6118;
	sub_824E5ED8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6130
	if (cr6.eq) goto loc_824E6130;
	// bl 0x82130588
	ctx.lr = 0x824E612C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E6130:
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

__attribute__((alias("__imp__sub_824E6148"))) PPC_WEAK_FUNC(sub_824E6148);
PPC_FUNC_IMPL(__imp__sub_824E6148) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,30108
	r31.s64 = r11.s64 + 30108;
	// lbz r11,6(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6188
	if (cr6.eq) goto loc_824E6188;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// bl 0x8244d5c0
	ctx.lr = 0x824E6180;
	sub_8244D5C0(ctx, base);
	// lbz r3,6(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 6);
	// b 0x824e61d8
	goto loc_824E61D8;
loc_824E6188:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244a670
	ctx.lr = 0x824E6190;
	sub_8244A670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e61b0
	if (!cr6.eq) goto loc_824E61B0;
loc_824E6198:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244fec0
	ctx.lr = 0x824E61A0;
	sub_8244FEC0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244a670
	ctx.lr = 0x824E61A8;
	sub_8244A670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e6198
	if (cr6.eq) goto loc_824E6198;
loc_824E61B0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,90
	ctx.r4.s64 = ctx.r1.s64 + 90;
	// bl 0x8244d5c0
	ctx.lr = 0x824E61C0;
	sub_8244D5C0(ctx, base);
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,90
	ctx.r4.s64 = ctx.r1.s64 + 90;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824E61D0;
	sub_8244D5C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r3,6(r31)
	PPC_STORE_U8(r31.u32 + 6, ctx.r3.u8);
loc_824E61D8:
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

__attribute__((alias("__imp__sub_824E61F0"))) PPC_WEAK_FUNC(sub_824E61F0);
PPC_FUNC_IMPL(__imp__sub_824E61F0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r30,0
	r30.s64 = 0;
	// bl 0x8244a670
	ctx.lr = 0x824E6214;
	sub_8244A670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6234
	if (!cr6.eq) goto loc_824E6234;
loc_824E621C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244fec0
	ctx.lr = 0x824E6224;
	sub_8244FEC0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244a670
	ctx.lr = 0x824E622C;
	sub_8244A670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e621c
	if (cr6.eq) goto loc_824E621C;
loc_824E6234:
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// rlwinm r11,r11,0,31,16
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFF8001;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e6254
	if (!cr6.eq) goto loc_824E6254;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x824e6258
	goto loc_824E6258;
loc_824E6254:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824E6258:
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

__attribute__((alias("__imp__sub_824E6270"))) PPC_WEAK_FUNC(sub_824E6270);
PPC_FUNC_IMPL(__imp__sub_824E6270) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6278"))) PPC_WEAK_FUNC(sub_824E6278);
PPC_FUNC_IMPL(__imp__sub_824E6278) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6294
	if (cr6.eq) goto loc_824E6294;
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e6298
	if (!cr6.eq) goto loc_824E6298;
loc_824E6294:
	// li r11,0
	r11.s64 = 0;
loc_824E6298:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E62A0"))) PPC_WEAK_FUNC(sub_824E62A0);
PPC_FUNC_IMPL(__imp__sub_824E62A0) {
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
	// blt cr6,0x824e62d0
	if (cr6.lt) goto loc_824E62D0;
	// bne cr6,0x824e62c4
	if (!cr6.eq) goto loc_824E62C4;
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x824e62d0
	if (cr6.lt) goto loc_824E62D0;
loc_824E62C4:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_824E62D0:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E62DC"))) PPC_WEAK_FUNC(sub_824E62DC);
PPC_FUNC_IMPL(__imp__sub_824E62DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E62E0"))) PPC_WEAK_FUNC(sub_824E62E0);
PPC_FUNC_IMPL(__imp__sub_824E62E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824e6304
	if (!cr6.eq) goto loc_824E6304;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6308
	if (cr6.eq) goto loc_824E6308;
loc_824E6304:
	// li r11,0
	r11.s64 = 0;
loc_824E6308:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6310"))) PPC_WEAK_FUNC(sub_824E6310);
PPC_FUNC_IMPL(__imp__sub_824E6310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6320"))) PPC_WEAK_FUNC(sub_824E6320);
PPC_FUNC_IMPL(__imp__sub_824E6320) {
	PPC_FUNC_PROLOGUE();
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// sth r5,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r5.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E632C"))) PPC_WEAK_FUNC(sub_824E632C);
PPC_FUNC_IMPL(__imp__sub_824E632C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6330"))) PPC_WEAK_FUNC(sub_824E6330);
PPC_FUNC_IMPL(__imp__sub_824E6330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6344"))) PPC_WEAK_FUNC(sub_824E6344);
PPC_FUNC_IMPL(__imp__sub_824E6344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6348"))) PPC_WEAK_FUNC(sub_824E6348);
PPC_FUNC_IMPL(__imp__sub_824E6348) {
	PPC_FUNC_PROLOGUE();
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823d9890
	sub_823D9890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E6354"))) PPC_WEAK_FUNC(sub_824E6354);
PPC_FUNC_IMPL(__imp__sub_824E6354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6358"))) PPC_WEAK_FUNC(sub_824E6358);
PPC_FUNC_IMPL(__imp__sub_824E6358) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r11,60
	ctx.r9.s64 = r11.s64 + 60;
loc_824E6360:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// subf. r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x824e6380
	if (!cr0.eq) goto loc_824E6380;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x824e6360
	if (!cr6.eq) goto loc_824E6360;
loc_824E6380:
	// addi r11,r10,0
	r11.s64 = ctx.r10.s64 + 0;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6390"))) PPC_WEAK_FUNC(sub_824E6390);
PPC_FUNC_IMPL(__imp__sub_824E6390) {
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
	ctx.lr = 0x824E6398;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824E63B4;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e63f4
	if (cr6.eq) goto loc_824E63F4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824E63DC;
	sub_82618390(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x824E63E8;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E63F4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E6400"))) PPC_WEAK_FUNC(sub_824E6400);
PPC_FUNC_IMPL(__imp__sub_824E6400) {
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
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823d9890
	ctx.lr = 0x824E6420;
	sub_823D9890(ctx, base);
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

__attribute__((alias("__imp__sub_824E6438"))) PPC_WEAK_FUNC(sub_824E6438);
PPC_FUNC_IMPL(__imp__sub_824E6438) {
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
	ctx.lr = 0x824E6440;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x82618750
	ctx.lr = 0x824E6460;
	sub_82618750(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824E6470;
	sub_82618640(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r30,0
	r30.s64 = 0;
	// lwz r29,8(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x826186c0
	ctx.lr = 0x824E6484;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e64bc
	if (cr6.eq) goto loc_824E64BC;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82618390
	ctx.lr = 0x824E64AC;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E64B8;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_824E64BC:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6678
	if (cr6.eq) goto loc_824E6678;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6390
	ctx.lr = 0x824E64D8;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6678
	if (cr6.eq) goto loc_824E6678;
	// li r5,16
	ctx.r5.s64 = 16;
	// lhz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U16(r28.u32 + 16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82275660
	ctx.lr = 0x824E64F4;
	sub_82275660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6678
	if (cr6.eq) goto loc_824E6678;
	// li r31,1
	r31.s64 = 1;
	// li r30,0
	r30.s64 = 0;
loc_824E6508:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6538
	if (cr6.eq) goto loc_824E6538;
	// add r11,r30,r28
	r11.u64 = r30.u64 + r28.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lbz r4,18(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 18);
	// bl 0x82251078
	ctx.lr = 0x824E6528;
	sub_82251078(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,6
	cr6.compare<uint32_t>(r30.u32, 6, xer);
	// blt cr6,0x824e6508
	if (cr6.lt) goto loc_824E6508;
loc_824E6538:
	// li r29,0
	r29.s64 = 0;
loc_824E653C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e65a4
	if (cr6.eq) goto loc_824E65A4;
	// add r11,r29,r28
	r11.u64 = r29.u64 + r28.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// lbz r30,24(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// bl 0x826186c0
	ctx.lr = 0x824E6560;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e6598
	if (cr6.eq) goto loc_824E6598;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824E6588;
	sub_82618390(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E6594;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824E6598:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,20
	cr6.compare<uint32_t>(r29.u32, 20, xer);
	// blt cr6,0x824e653c
	if (cr6.lt) goto loc_824E653C;
loc_824E65A4:
	// li r29,0
	r29.s64 = 0;
loc_824E65A8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e660c
	if (cr6.eq) goto loc_824E660C;
	// li r4,8
	ctx.r4.s64 = 8;
	// lbzx r30,r29,r28
	r30.u64 = PPC_LOAD_U8(r29.u32 + r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824E65C8;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6600
	if (cr6.eq) goto loc_824E6600;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824E65F0;
	sub_82618390(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E65FC;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824E6600:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,8
	cr6.compare<uint32_t>(r29.u32, 8, xer);
	// blt cr6,0x824e65a8
	if (cr6.lt) goto loc_824E65A8;
loc_824E660C:
	// li r29,0
	r29.s64 = 0;
loc_824E6610:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6678
	if (cr6.eq) goto loc_824E6678;
	// add r11,r29,r28
	r11.u64 = r29.u64 + r28.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// lbz r30,44(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 44);
	// bl 0x826186c0
	ctx.lr = 0x824E6634;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e666c
	if (cr6.eq) goto loc_824E666C;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824E665C;
	sub_82618390(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E6668;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824E666C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,16
	cr6.compare<uint32_t>(r29.u32, 16, xer);
	// blt cr6,0x824e6610
	if (cr6.lt) goto loc_824E6610;
loc_824E6678:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e66ac
	if (cr6.eq) goto loc_824E66AC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e66a4
	if (cr6.eq) goto loc_824E66A4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824E6694;
	sub_826186A0(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_824E66A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
loc_824E66AC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E66B8"))) PPC_WEAK_FUNC(sub_824E66B8);
PPC_FUNC_IMPL(__imp__sub_824E66B8) {
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
	ctx.lr = 0x824E66C0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// bl 0x82618750
	ctx.lr = 0x824E66E4;
	sub_82618750(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824E66F4;
	sub_826185E0(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r28,8
	ctx.r4.s64 = r28.s64 + 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E6704;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68e4
	if (cr6.eq) goto loc_824E68E4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r28,12
	ctx.r4.s64 = r28.s64 + 12;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E6720;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68e4
	if (cr6.eq) goto loc_824E68E4;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r28,16
	ctx.r4.s64 = r28.s64 + 16;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822756d0
	ctx.lr = 0x824E673C;
	sub_822756D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68e4
	if (cr6.eq) goto loc_824E68E4;
	// li r31,1
	r31.s64 = 1;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_824E6750:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6780
	if (cr6.eq) goto loc_824E6780;
	// add r11,r30,r28
	r11.u64 = r30.u64 + r28.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r11,18
	ctx.r4.s64 = r11.s64 + 18;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822510e8
	ctx.lr = 0x824E6770;
	sub_822510E8(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,6
	cr6.compare<uint32_t>(r30.u32, 6, xer);
	// blt cr6,0x824e6750
	if (cr6.lt) goto loc_824E6750;
loc_824E6780:
	// mr r29,r27
	r29.u64 = r27.u64;
loc_824E6784:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e67f8
	if (cr6.eq) goto loc_824E67F8;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r30,r29,r28
	r30.u64 = r29.u64 + r28.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// bl 0x826187f0
	ctx.lr = 0x824E67A4;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e67e8
	if (cr6.eq) goto loc_824E67E8;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824E67CC;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r11,24(r30)
	PPC_STORE_U8(r30.u32 + 24, r11.u8);
	// bl 0x826188d8
	ctx.lr = 0x824E67E0;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824e67ec
	goto loc_824E67EC;
loc_824E67E8:
	// stb r27,24(r30)
	PPC_STORE_U8(r30.u32 + 24, r27.u8);
loc_824E67EC:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,20
	cr6.compare<uint32_t>(r29.u32, 20, xer);
	// blt cr6,0x824e6784
	if (cr6.lt) goto loc_824E6784;
loc_824E67F8:
	// mr r30,r27
	r30.u64 = r27.u64;
loc_824E67FC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e686c
	if (cr6.eq) goto loc_824E686C;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r27
	r31.u64 = r27.u64;
	// bl 0x826187f0
	ctx.lr = 0x824E6818;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e685c
	if (cr6.eq) goto loc_824E685C;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824E6840;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stbx r11,r30,r28
	PPC_STORE_U8(r30.u32 + r28.u32, r11.u8);
	// bl 0x826188d8
	ctx.lr = 0x824E6854;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824e6860
	goto loc_824E6860;
loc_824E685C:
	// stbx r27,r30,r28
	PPC_STORE_U8(r30.u32 + r28.u32, r27.u8);
loc_824E6860:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r30,8
	cr6.compare<uint32_t>(r30.u32, 8, xer);
	// blt cr6,0x824e67fc
	if (cr6.lt) goto loc_824E67FC;
loc_824E686C:
	// mr r29,r27
	r29.u64 = r27.u64;
loc_824E6870:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68e4
	if (cr6.eq) goto loc_824E68E4;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r30,r29,r28
	r30.u64 = r29.u64 + r28.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// bl 0x826187f0
	ctx.lr = 0x824E6890;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68d4
	if (cr6.eq) goto loc_824E68D4;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824E68B8;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r11,44(r30)
	PPC_STORE_U8(r30.u32 + 44, r11.u8);
	// bl 0x826188d8
	ctx.lr = 0x824E68CC;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824e68d8
	goto loc_824E68D8;
loc_824E68D4:
	// stb r27,44(r30)
	PPC_STORE_U8(r30.u32 + 44, r27.u8);
loc_824E68D8:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,16
	cr6.compare<uint32_t>(r29.u32, 16, xer);
	// blt cr6,0x824e6870
	if (cr6.lt) goto loc_824E6870;
loc_824E68E4:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e6918
	if (cr6.eq) goto loc_824E6918;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6910
	if (cr6.eq) goto loc_824E6910;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824E6900;
	sub_826186B0(ctx, base);
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
loc_824E6910:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
loc_824E6918:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E6924"))) PPC_WEAK_FUNC(sub_824E6924);
PPC_FUNC_IMPL(__imp__sub_824E6924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6928"))) PPC_WEAK_FUNC(sub_824E6928);
PPC_FUNC_IMPL(__imp__sub_824E6928) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,26072
	ctx.r10.s64 = r11.s64 + 26072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824E6950;
	sub_821C8ED8(ctx, base);
	// lbz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// rlwimi r7,r9,7,0,25
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 7) & 0xFFFFFFC0) | (ctx.r7.u64 & 0xFFFFFFFF0000003F);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r8.u32);
	// stb r7,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_824E698C"))) PPC_WEAK_FUNC(sub_824E698C);
PPC_FUNC_IMPL(__imp__sub_824E698C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6990"))) PPC_WEAK_FUNC(sub_824E6990);
PPC_FUNC_IMPL(__imp__sub_824E6990) {
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
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x824e69f8
	if (cr6.eq) goto loc_824E69F8;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r10.u8);
	// bl 0x821c9108
	ctx.lr = 0x824E69C4;
	sub_821C9108(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c90c0
	ctx.lr = 0x824E69CC;
	sub_821C90C0(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x821c9168
	ctx.lr = 0x824E69D4;
	sub_821C9168(ctx, base);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
	// bl 0x821c9158
	ctx.lr = 0x824E69E4;
	sub_821C9158(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c9158
	ctx.lr = 0x824E69EC;
	sub_821C9158(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
loc_824E69F8:
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

__attribute__((alias("__imp__sub_824E6A10"))) PPC_WEAK_FUNC(sub_824E6A10);
PPC_FUNC_IMPL(__imp__sub_824E6A10) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// b 0x821c9108
	sub_821C9108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E6A18"))) PPC_WEAK_FUNC(sub_824E6A18);
PPC_FUNC_IMPL(__imp__sub_824E6A18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// li r10,-1
	ctx.r10.s64 = -1;
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r3,r7,1
	ctx.r3.u64 = ctx.r7.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6A34"))) PPC_WEAK_FUNC(sub_824E6A34);
PPC_FUNC_IMPL(__imp__sub_824E6A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6A38"))) PPC_WEAK_FUNC(sub_824E6A38);
PPC_FUNC_IMPL(__imp__sub_824E6A38) {
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
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x821c8fe0
	ctx.lr = 0x824E6A58;
	sub_821C8FE0(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r31,r11,26,31,31
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E6A68;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_824E6A80"))) PPC_WEAK_FUNC(sub_824E6A80);
PPC_FUNC_IMPL(__imp__sub_824E6A80) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c9108
	ctx.lr = 0x824E6AA0;
	sub_821C9108(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e6b34
	if (!cr6.eq) goto loc_824E6B34;
loc_824E6AB0:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x821c90c0
	ctx.lr = 0x824E6AB8;
	sub_821C90C0(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e6b34
	if (!cr6.eq) goto loc_824E6B34;
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E6AD8;
	sub_821C8FE0(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stb r10,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r10.u8);
	// bl 0x821c9030
	ctx.lr = 0x824E6AEC;
	sub_821C9030(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E6B00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x824E6B0C;
	sub_821C8FE0(ctx, base);
	// lbz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// rlwinm r6,r6,0,26,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r6,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r6.u8);
	// bl 0x821c9030
	ctx.lr = 0x824E6B24;
	sub_821C9030(ctx, base);
	// lbz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r4,r5,0,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824e6ab0
	if (cr6.eq) goto loc_824E6AB0;
loc_824E6B34:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c9108
	ctx.lr = 0x824E6B3C;
	sub_821C9108(ctx, base);
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

__attribute__((alias("__imp__sub_824E6B54"))) PPC_WEAK_FUNC(sub_824E6B54);
PPC_FUNC_IMPL(__imp__sub_824E6B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6B58"))) PPC_WEAK_FUNC(sub_824E6B58);
PPC_FUNC_IMPL(__imp__sub_824E6B58) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,26072
	ctx.r10.s64 = r11.s64 + 26072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e6990
	ctx.lr = 0x824E6B7C;
	sub_824E6990(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82130000
	ctx.lr = 0x824E6B84;
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

__attribute__((alias("__imp__sub_824E6B98"))) PPC_WEAK_FUNC(sub_824E6B98);
PPC_FUNC_IMPL(__imp__sub_824E6B98) {
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
	ctx.lr = 0x824E6BA0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// bl 0x821c9060
	ctx.lr = 0x824E6BC4;
	sub_821C9060(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x824E6BD0;
	sub_821C9060(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6c30
	if (cr6.eq) goto loc_824E6C30;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e6c30
	if (cr6.eq) goto loc_824E6C30;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// lis r10,-32178
	ctx.r10.s64 = -2108817408;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// clrlwi r7,r11,25
	ctx.r7.u64 = r11.u32 & 0x7F;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r7,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r7.u8);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r10,27264
	ctx.r3.s64 = ctx.r10.s64 + 27264;
	// bl 0x821c9308
	ctx.lr = 0x824E6C18;
	sub_821C9308(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824e6c30
	if (cr6.eq) goto loc_824E6C30;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c90c0
	ctx.lr = 0x824E6C2C;
	sub_821C90C0(ctx, base);
	// li r27,1
	r27.s64 = 1;
loc_824E6C30:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e6c64
	if (!cr6.eq) goto loc_824E6C64;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e6c50
	if (cr6.eq) goto loc_824E6C50;
	// bl 0x821c9158
	ctx.lr = 0x824E6C4C;
	sub_821C9158(ctx, base);
	// stw r26,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r26.u32);
loc_824E6C50:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e6c64
	if (cr6.eq) goto loc_824E6C64;
	// bl 0x821c9158
	ctx.lr = 0x824E6C60;
	sub_821C9158(ctx, base);
	// stw r26,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r26.u32);
loc_824E6C64:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E6C70"))) PPC_WEAK_FUNC(sub_824E6C70);
PPC_FUNC_IMPL(__imp__sub_824E6C70) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,26072
	ctx.r10.s64 = r11.s64 + 26072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e6990
	ctx.lr = 0x824E6C9C;
	sub_824E6990(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82130000
	ctx.lr = 0x824E6CA4;
	sub_82130000(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824e6cbc
	if (cr6.eq) goto loc_824E6CBC;
	// bl 0x82130588
	ctx.lr = 0x824E6CB8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E6CBC:
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

__attribute__((alias("__imp__sub_824E6CD4"))) PPC_WEAK_FUNC(sub_824E6CD4);
PPC_FUNC_IMPL(__imp__sub_824E6CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6CD8"))) PPC_WEAK_FUNC(sub_824E6CD8);
PPC_FUNC_IMPL(__imp__sub_824E6CD8) {
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
	// bl 0x824575f8
	ctx.lr = 0x824E6CE8;
	sub_824575F8(ctx, base);
	// addi r10,r3,0
	ctx.r10.s64 = ctx.r3.s64 + 0;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r3,r8,1
	ctx.r3.u64 = ctx.r8.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6D08"))) PPC_WEAK_FUNC(sub_824E6D08);
PPC_FUNC_IMPL(__imp__sub_824E6D08) {
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
	// bl 0x825019b0
	ctx.lr = 0x824E6D28;
	sub_825019B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6d4c
	if (cr6.eq) goto loc_824E6D4C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824575f8
	ctx.lr = 0x824E6D3C;
	sub_824575F8(ctx, base);
	// addi r11,r3,-2
	r11.s64 = ctx.r3.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x824e6d50
	goto loc_824E6D50;
loc_824E6D4C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824E6D50:
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

__attribute__((alias("__imp__sub_824E6D68"))) PPC_WEAK_FUNC(sub_824E6D68);
PPC_FUNC_IMPL(__imp__sub_824E6D68) {
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,254
	ctx.r4.s64 = 254;
	// bl 0x82457608
	ctx.lr = 0x824E6D80;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6d98
	if (!cr6.eq) goto loc_824E6D98;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6d9c
	if (cr6.eq) goto loc_824E6D9C;
loc_824E6D98:
	// li r11,0
	r11.s64 = 0;
loc_824E6D9C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6DB0"))) PPC_WEAK_FUNC(sub_824E6DB0);
PPC_FUNC_IMPL(__imp__sub_824E6DB0) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r4,251
	ctx.r4.s64 = 251;
	// bne cr6,0x824e6dd4
	if (!cr6.eq) goto loc_824E6DD4;
	// li r4,252
	ctx.r4.s64 = 252;
loc_824E6DD4:
	// bl 0x82457608
	ctx.lr = 0x824E6DD8;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6df0
	if (!cr6.eq) goto loc_824E6DF0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6df4
	if (cr6.eq) goto loc_824E6DF4;
loc_824E6DF0:
	// li r11,0
	r11.s64 = 0;
loc_824E6DF4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6E08"))) PPC_WEAK_FUNC(sub_824E6E08);
PPC_FUNC_IMPL(__imp__sub_824E6E08) {
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,247
	ctx.r4.s64 = 247;
	// bl 0x82457608
	ctx.lr = 0x824E6E20;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6e38
	if (!cr6.eq) goto loc_824E6E38;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6e3c
	if (cr6.eq) goto loc_824E6E3C;
loc_824E6E38:
	// li r11,0
	r11.s64 = 0;
loc_824E6E3C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6E50"))) PPC_WEAK_FUNC(sub_824E6E50);
PPC_FUNC_IMPL(__imp__sub_824E6E50) {
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,246
	ctx.r4.s64 = 246;
	// bl 0x82457608
	ctx.lr = 0x824E6E68;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6e80
	if (!cr6.eq) goto loc_824E6E80;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6e84
	if (cr6.eq) goto loc_824E6E84;
loc_824E6E80:
	// li r11,0
	r11.s64 = 0;
loc_824E6E84:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6E98"))) PPC_WEAK_FUNC(sub_824E6E98);
PPC_FUNC_IMPL(__imp__sub_824E6E98) {
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
	ctx.lr = 0x824E6EA0;
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
	// li r29,0
	r29.s64 = 0;
	// bl 0x824f9270
	ctx.lr = 0x824E6EB8;
	sub_824F9270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6f14
	if (cr6.eq) goto loc_824E6F14;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x824E6ED0;
	sub_824F92F0(ctx, base);
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82457600
	ctx.lr = 0x824E6EEC;
	sub_82457600(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6f04
	if (!cr6.eq) goto loc_824E6F04;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6f08
	if (cr6.eq) goto loc_824E6F08;
loc_824E6F04:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_824E6F08:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824E6F14:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E6F20"))) PPC_WEAK_FUNC(sub_824E6F20);
PPC_FUNC_IMPL(__imp__sub_824E6F20) {
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
	// bl 0x824f9788
	ctx.lr = 0x824E6F38;
	sub_824F9788(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x824f0498
	ctx.lr = 0x824E6F40;
	sub_824F0498(ctx, base);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// bl 0x824f9230
	ctx.lr = 0x824E6F48;
	sub_824F9230(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,76
	ctx.r3.s64 = r31.s64 + 76;
	// bl 0x8244d150
	ctx.lr = 0x824E6F60;
	sub_8244D150(ctx, base);
	// lbz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// stb r9,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_824E6F80"))) PPC_WEAK_FUNC(sub_824E6F80);
PPC_FUNC_IMPL(__imp__sub_824E6F80) {
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
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x824f04a8
	ctx.lr = 0x824E6F9C;
	sub_824F04A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6fe8
	if (cr6.eq) goto loc_824E6FE8;
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// bl 0x824f9270
	ctx.lr = 0x824E6FB0;
	sub_824F9270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6fe8
	if (cr6.eq) goto loc_824E6FE8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9a00
	ctx.lr = 0x824E6FC4;
	sub_824F9A00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6fe8
	if (cr6.eq) goto loc_824E6FE8;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x824e6fe8
	if (cr6.lt) goto loc_824E6FE8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824e6fec
	if (cr6.lt) goto loc_824E6FEC;
loc_824E6FE8:
	// li r11,0
	r11.s64 = 0;
loc_824E6FEC:
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

__attribute__((alias("__imp__sub_824E7004"))) PPC_WEAK_FUNC(sub_824E7004);
PPC_FUNC_IMPL(__imp__sub_824E7004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7008"))) PPC_WEAK_FUNC(sub_824E7008);
PPC_FUNC_IMPL(__imp__sub_824E7008) {
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
	// bl 0x824e6f80
	ctx.lr = 0x824E7020;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7044
	if (cr6.eq) goto loc_824E7044;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9a20
	ctx.lr = 0x824E7034;
	sub_824F9A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e7048
	if (!cr6.eq) goto loc_824E7048;
loc_824E7044:
	// li r11,0
	r11.s64 = 0;
loc_824E7048:
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

__attribute__((alias("__imp__sub_824E7060"))) PPC_WEAK_FUNC(sub_824E7060);
PPC_FUNC_IMPL(__imp__sub_824E7060) {
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
	// bl 0x824e6f80
	ctx.lr = 0x824E7078;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e70c4
	if (cr6.eq) goto loc_824E70C4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6f80
	ctx.lr = 0x824E708C;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e70b0
	if (cr6.eq) goto loc_824E70B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9a20
	ctx.lr = 0x824E70A0;
	sub_824F9A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e70b4
	if (!cr6.eq) goto loc_824E70B4;
loc_824E70B0:
	// li r11,0
	r11.s64 = 0;
loc_824E70B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e70c8
	if (cr6.eq) goto loc_824E70C8;
loc_824E70C4:
	// li r11,0
	r11.s64 = 0;
loc_824E70C8:
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

__attribute__((alias("__imp__sub_824E70E0"))) PPC_WEAK_FUNC(sub_824E70E0);
PPC_FUNC_IMPL(__imp__sub_824E70E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r3,r11,25,7,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E70EC"))) PPC_WEAK_FUNC(sub_824E70EC);
PPC_FUNC_IMPL(__imp__sub_824E70EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E70F0"))) PPC_WEAK_FUNC(sub_824E70F0);
PPC_FUNC_IMPL(__imp__sub_824E70F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r3,r11,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E70FC"))) PPC_WEAK_FUNC(sub_824E70FC);
PPC_FUNC_IMPL(__imp__sub_824E70FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7100"))) PPC_WEAK_FUNC(sub_824E7100);
PPC_FUNC_IMPL(__imp__sub_824E7100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E710C"))) PPC_WEAK_FUNC(sub_824E710C);
PPC_FUNC_IMPL(__imp__sub_824E710C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7110"))) PPC_WEAK_FUNC(sub_824E7110);
PPC_FUNC_IMPL(__imp__sub_824E7110) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,56
	ctx.r3.s64 = ctx.r3.s64 + 56;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7118"))) PPC_WEAK_FUNC(sub_824E7118);
PPC_FUNC_IMPL(__imp__sub_824E7118) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,76
	ctx.r3.s64 = ctx.r3.s64 + 76;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7120"))) PPC_WEAK_FUNC(sub_824E7120);
PPC_FUNC_IMPL(__imp__sub_824E7120) {
	PPC_FUNC_PROLOGUE();
	// addi r4,r4,48
	ctx.r4.s64 = ctx.r4.s64 + 48;
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// b 0x824f0550
	sub_824F0550(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E712C"))) PPC_WEAK_FUNC(sub_824E712C);
PPC_FUNC_IMPL(__imp__sub_824E712C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7130"))) PPC_WEAK_FUNC(sub_824E7130);
PPC_FUNC_IMPL(__imp__sub_824E7130) {
	PPC_FUNC_PROLOGUE();
	// addi r4,r4,48
	ctx.r4.s64 = ctx.r4.s64 + 48;
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// b 0x824f0570
	sub_824F0570(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E713C"))) PPC_WEAK_FUNC(sub_824E713C);
PPC_FUNC_IMPL(__imp__sub_824E713C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7140"))) PPC_WEAK_FUNC(sub_824E7140);
PPC_FUNC_IMPL(__imp__sub_824E7140) {
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
	ctx.lr = 0x824E7148;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stb r28,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r28.u8);
	// bl 0x824575f8
	ctx.lr = 0x824E7164;
	sub_824575F8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824e71bc
	if (cr6.eq) goto loc_824E71BC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824579e0
	ctx.lr = 0x824E7178;
	sub_824579E0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e7198
	if (!cr6.eq) goto loc_824E7198;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824575f0
	ctx.lr = 0x824E7190;
	sub_824575F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e71b0
	if (cr6.eq) goto loc_824E71B0;
loc_824E7198:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,26104
	ctx.r5.s64 = r11.s64 + 26104;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x824E71B0;
	sub_82137A08(ctx, base);
loc_824E71B0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E71BC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E71C8"))) PPC_WEAK_FUNC(sub_824E71C8);
PPC_FUNC_IMPL(__imp__sub_824E71C8) {
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
	ctx.lr = 0x824E71D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824f99c0
	ctx.lr = 0x824E71DC;
	sub_824F99C0(ctx, base);
	// addi r30,r31,48
	r30.s64 = r31.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E71E8;
	sub_824F0498(ctx, base);
	// addi r29,r31,56
	r29.s64 = r31.s64 + 56;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f9438
	ctx.lr = 0x824E71F4;
	sub_824F9438(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9788
	ctx.lr = 0x824E71FC;
	sub_824F9788(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E7204;
	sub_824F0498(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f9230
	ctx.lr = 0x824E720C;
	sub_824F9230(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r31,76
	ctx.r3.s64 = r31.s64 + 76;
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x824E7224;
	sub_8244D150(ctx, base);
	// lbz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// stb r9,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r9.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E723C"))) PPC_WEAK_FUNC(sub_824E723C);
PPC_FUNC_IMPL(__imp__sub_824E723C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7240"))) PPC_WEAK_FUNC(sub_824E7240);
PPC_FUNC_IMPL(__imp__sub_824E7240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// b 0x824e7140
	sub_824E7140(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E724C"))) PPC_WEAK_FUNC(sub_824E724C);
PPC_FUNC_IMPL(__imp__sub_824E724C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7250"))) PPC_WEAK_FUNC(sub_824E7250);
PPC_FUNC_IMPL(__imp__sub_824E7250) {
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
	ctx.lr = 0x824E7258;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x824f9788
	ctx.lr = 0x824E7270;
	sub_824F9788(ctx, base);
	// addi r28,r31,48
	r28.s64 = r31.s64 + 48;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E727C;
	sub_824F0498(ctx, base);
	// addi r27,r31,56
	r27.s64 = r31.s64 + 56;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f9230
	ctx.lr = 0x824E7288;
	sub_824F9230(ctx, base);
	// li r25,-1
	r25.s64 = -1;
	// addi r29,r31,76
	r29.s64 = r31.s64 + 76;
	// stw r25,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r25.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8244d150
	ctx.lr = 0x824E72A4;
	sub_8244D150(ctx, base);
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
	// bl 0x824575f8
	ctx.lr = 0x824E72B8;
	sub_824575F8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9970
	ctx.lr = 0x824E72C8;
	sub_824F9970(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f05b0
	ctx.lr = 0x824E72E0;
	sub_824F05B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f93b8
	ctx.lr = 0x824E72F8;
	sub_824F93B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// stb r26,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r26.u8);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7140
	ctx.lr = 0x824E7318;
	sub_824E7140(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
	// bl 0x824e6d08
	ctx.lr = 0x824E733C;
	sub_824E6D08(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lbz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// rlwimi r8,r7,6,25,25
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 6) & 0x40) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r8,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r8.u8);
	// bl 0x824e6d08
	ctx.lr = 0x824E7358;
	sub_824E6D08(ctx, base);
	// lbz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwimi r5,r4,5,26,26
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 5) & 0x20) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r5,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r5.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_824E7374:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9788
	ctx.lr = 0x824E737C;
	sub_824F9788(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E7384;
	sub_824F0498(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f9230
	ctx.lr = 0x824E738C;
	sub_824F9230(ctx, base);
	// stw r25,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r25.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8244d150
	ctx.lr = 0x824E73A0;
	sub_8244D150(ctx, base);
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824E73B8"))) PPC_WEAK_FUNC(sub_824E73B8);
PPC_FUNC_IMPL(__imp__sub_824E73B8) {
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
	ctx.lr = 0x824E73C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x8252a660
	ctx.lr = 0x824E73E4;
	sub_8252A660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e74bc
	if (cr6.eq) goto loc_824E74BC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r5,r11,r29
	ctx.r5.s64 = r29.s64 - r11.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824f97c8
	ctx.lr = 0x824E7408;
	sub_824F97C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e74bc
	if (cr6.eq) goto loc_824E74BC;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// subf r9,r11,r29
	ctx.r9.s64 = r29.s64 - r11.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r5,r10,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r10.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824f94e0
	ctx.lr = 0x824E7438;
	sub_824F94E0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e74bc
	if (cr6.eq) goto loc_824E74BC;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618750
	ctx.lr = 0x824E7460;
	sub_82618750(ctx, base);
	// subf r5,r28,r29
	ctx.r5.s64 = r29.s64 - r28.s64;
	// add r4,r28,r30
	ctx.r4.u64 = r28.u64 + r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618640
	ctx.lr = 0x824E7470;
	sub_82618640(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r31,76
	ctx.r4.s64 = r31.s64 + 76;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82619080
	ctx.lr = 0x824E7480;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e74b8
	if (cr6.eq) goto loc_824E74B8;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8226b338
	ctx.lr = 0x824E749C;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e74b8
	if (cr6.eq) goto loc_824E74B8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186a0
	ctx.lr = 0x824E74B0;
	sub_826186A0(ctx, base);
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// b 0x824e74bc
	goto loc_824E74BC;
loc_824E74B8:
	// li r28,0
	r28.s64 = 0;
loc_824E74BC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e74c8
	if (cr6.eq) goto loc_824E74C8;
	// stw r28,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r28.u32);
loc_824E74C8:
	// subfic r11,r28,0
	xer.ca = r28.u32 <= 0;
	r11.s64 = 0 - r28.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E74DC"))) PPC_WEAK_FUNC(sub_824E74DC);
PPC_FUNC_IMPL(__imp__sub_824E74DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E74E0"))) PPC_WEAK_FUNC(sub_824E74E0);
PPC_FUNC_IMPL(__imp__sub_824E74E0) {
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
	ctx.lr = 0x824E74E8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x824f04c8
	ctx.lr = 0x824E750C;
	sub_824F04C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e75e4
	if (cr6.eq) goto loc_824E75E4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r5,r11,r29
	ctx.r5.s64 = r29.s64 - r11.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824f9888
	ctx.lr = 0x824E7530;
	sub_824F9888(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e75e4
	if (cr6.eq) goto loc_824E75E4;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// subf r9,r11,r29
	ctx.r9.s64 = r29.s64 - r11.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r5,r10,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r10.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824f95d0
	ctx.lr = 0x824E7560;
	sub_824F95D0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e75e4
	if (cr6.eq) goto loc_824E75E4;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618750
	ctx.lr = 0x824E7588;
	sub_82618750(ctx, base);
	// subf r5,r28,r29
	ctx.r5.s64 = r29.s64 - r28.s64;
	// add r4,r28,r30
	ctx.r4.u64 = r28.u64 + r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824E7598;
	sub_826185E0(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r31,76
	ctx.r4.s64 = r31.s64 + 76;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618fa0
	ctx.lr = 0x824E75A8;
	sub_82618FA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e75e0
	if (cr6.eq) goto loc_824E75E0;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,72
	ctx.r4.s64 = r31.s64 + 72;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82275750
	ctx.lr = 0x824E75C4;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e75e0
	if (cr6.eq) goto loc_824E75E0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824E75D8;
	sub_826186B0(ctx, base);
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// b 0x824e75e4
	goto loc_824E75E4;
loc_824E75E0:
	// li r28,0
	r28.s64 = 0;
loc_824E75E4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e75f0
	if (cr6.eq) goto loc_824E75F0;
	// stw r28,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r28.u32);
loc_824E75F0:
	// subfic r11,r28,0
	xer.ca = r28.u32 <= 0;
	r11.s64 = 0 - r28.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E7604"))) PPC_WEAK_FUNC(sub_824E7604);
PPC_FUNC_IMPL(__imp__sub_824E7604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7608"))) PPC_WEAK_FUNC(sub_824E7608);
PPC_FUNC_IMPL(__imp__sub_824E7608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30340
	ctx.r10.s64 = r11.s64 + 30340;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7618"))) PPC_WEAK_FUNC(sub_824E7618);
PPC_FUNC_IMPL(__imp__sub_824E7618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30404
	ctx.r10.s64 = r11.s64 + 30404;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7628"))) PPC_WEAK_FUNC(sub_824E7628);
PPC_FUNC_IMPL(__imp__sub_824E7628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30180
	ctx.r10.s64 = r11.s64 + 30180;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7638"))) PPC_WEAK_FUNC(sub_824E7638);
PPC_FUNC_IMPL(__imp__sub_824E7638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30212
	ctx.r10.s64 = r11.s64 + 30212;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7648"))) PPC_WEAK_FUNC(sub_824E7648);
PPC_FUNC_IMPL(__imp__sub_824E7648) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30244
	ctx.r10.s64 = r11.s64 + 30244;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7658"))) PPC_WEAK_FUNC(sub_824E7658);
PPC_FUNC_IMPL(__imp__sub_824E7658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30308
	ctx.r10.s64 = r11.s64 + 30308;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7668"))) PPC_WEAK_FUNC(sub_824E7668);
PPC_FUNC_IMPL(__imp__sub_824E7668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30148
	ctx.r10.s64 = r11.s64 + 30148;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7678"))) PPC_WEAK_FUNC(sub_824E7678);
PPC_FUNC_IMPL(__imp__sub_824E7678) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824e7698
	if (cr6.lt) goto loc_824E7698;
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// bge cr6,0x824e7698
	if (!cr6.lt) goto loc_824E7698;
	// mulli r11,r4,104
	r11.s64 = ctx.r4.s64 * 104;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
loc_824E7698:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E76A0"))) PPC_WEAK_FUNC(sub_824E76A0);
PPC_FUNC_IMPL(__imp__sub_824E76A0) {
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
	ctx.lr = 0x824E76A8;
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
	// lwz r11,432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e7718
	if (!cr6.eq) goto loc_824E7718;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x824501e0
	ctx.lr = 0x824E76CC;
	sub_824501E0(ctx, base);
	// stw r3,432(r31)
	PPC_STORE_U32(r31.u32 + 432, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7718
	if (cr6.eq) goto loc_824E7718;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824e7718
	if (cr6.eq) goto loc_824E7718;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,3032
	r30.s64 = r31.s64 + 3032;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r4,r11,26236
	ctx.r4.s64 = r11.s64 + 26236;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b98
	ctx.lr = 0x824E76FC;
	sub_824E6B98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7718
	if (cr6.eq) goto loc_824E7718;
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E7718:
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e772c
	if (cr6.eq) goto loc_824E772C;
	// bl 0x8275cc90
	ctx.lr = 0x824E7728;
	sub_8275CC90(ctx, base);
	// stw r28,432(r31)
	PPC_STORE_U32(r31.u32 + 432, r28.u32);
loc_824E772C:
	// lwz r11,3032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3032);
	// addi r3,r31,3032
	ctx.r3.s64 = r31.s64 + 3032;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E7740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E774C"))) PPC_WEAK_FUNC(sub_824E774C);
PPC_FUNC_IMPL(__imp__sub_824E774C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7750"))) PPC_WEAK_FUNC(sub_824E7750);
PPC_FUNC_IMPL(__imp__sub_824E7750) {
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
	ctx.lr = 0x824E7758;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// li r25,0
	r25.s64 = 0;
	// bl 0x821f8730
	ctx.lr = 0x824E777C;
	sub_821F8730(ctx, base);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,7,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r31,r11,472
	r31.s64 = r11.s64 + 472;
	// lwz r10,472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 472);
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x824e780c
	if (!cr6.eq) goto loc_824E780C;
	// addi r4,r29,436
	ctx.r4.s64 = r29.s64 + 436;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E77A8;
	sub_821C8FE0(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823da950
	ctx.lr = 0x824E77B8;
	sub_823DA950(ctx, base);
	// stw r27,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r27.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r31,108
	ctx.r3.s64 = r31.s64 + 108;
	// bl 0x824ea350
	ctx.lr = 0x824E77C8;
	sub_824EA350(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e77d4
	if (!cr6.eq) goto loc_824E77D4;
	// addi r30,r31,628
	r30.s64 = r31.s64 + 628;
loc_824E77D4:
	// stw r30,624(r31)
	PPC_STORE_U32(r31.u32 + 624, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E77E8;
	sub_821CE080(ctx, base);
	// stw r25,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r25.u32);
	// addi r3,r29,3032
	ctx.r3.s64 = r29.s64 + 3032;
	// bl 0x824e6a10
	ctx.lr = 0x824E77F4;
	sub_824E6A10(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,1
	r31.s64 = 1;
	// bl 0x821c9030
	ctx.lr = 0x824E7800;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_824E780C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e783c
	if (cr6.eq) goto loc_824E783C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E7820;
	sub_821CE080(ctx, base);
	// stw r25,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r25.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7834;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_824E783C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824E7848"))) PPC_WEAK_FUNC(sub_824E7848);
PPC_FUNC_IMPL(__imp__sub_824E7848) {
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
	ctx.lr = 0x824E7850;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x821f8730
	ctx.lr = 0x824E7864;
	sub_821F8730(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8e58
	ctx.lr = 0x824E7870;
	sub_824E8E58(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824e7890
	if (!cr6.gt) goto loc_824E7890;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e9240
	ctx.lr = 0x824E7888;
	sub_824E9240(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x824e7894
	goto loc_824E7894;
loc_824E7890:
	// li r31,1
	r31.s64 = 1;
loc_824E7894:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7920
	if (cr6.eq) goto loc_824E7920;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E78B4:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e78b4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E78B4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E78D4;
	sub_8244EE40(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// ori r4,r4,32769
	ctx.r4.u64 = ctx.r4.u64 | 32769;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824574c8
	ctx.lr = 0x824E78F0;
	sub_824574C8(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e7904
	if (!cr6.eq) goto loc_824E7904;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82135db8
	ctx.lr = 0x824E7904;
	sub_82135DB8(ctx, base);
loc_824E7904:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x8244eee0
	ctx.lr = 0x824E790C;
	sub_8244EEE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82450030
	ctx.lr = 0x824E7914;
	sub_82450030(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x824e7924
	if (!cr6.eq) goto loc_824E7924;
loc_824E7920:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E7924:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E792C"))) PPC_WEAK_FUNC(sub_824E792C);
PPC_FUNC_IMPL(__imp__sub_824E792C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7930"))) PPC_WEAK_FUNC(sub_824E7930);
PPC_FUNC_IMPL(__imp__sub_824E7930) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824e7974
	if (!cr6.eq) goto loc_824E7974;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7968
	if (cr6.eq) goto loc_824E7968;
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824e79ac
	if (!cr6.eq) goto loc_824E79AC;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824e79ac
	goto loc_824E79AC;
loc_824E7968:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824e79ac
	goto loc_824E79AC;
loc_824E7974:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824e7994
	if (!cr6.eq) goto loc_824E7994;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824e79ac
	goto loc_824E79AC;
loc_824E7994:
	// stw r5,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r5.u32);
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// stw r11,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, r11.u32);
	// lwz r10,12(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// stw r6,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r6.u32);
loc_824E79AC:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E79C4"))) PPC_WEAK_FUNC(sub_824E79C4);
PPC_FUNC_IMPL(__imp__sub_824E79C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E79C8"))) PPC_WEAK_FUNC(sub_824E79C8);
PPC_FUNC_IMPL(__imp__sub_824E79C8) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,26136
	ctx.r9.s64 = r11.s64 + 26136;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x824e79fc
	if (cr6.eq) goto loc_824E79FC;
	// bl 0x82130588
	ctx.lr = 0x824E79F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E79FC:
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

__attribute__((alias("__imp__sub_824E7A10"))) PPC_WEAK_FUNC(sub_824E7A10);
PPC_FUNC_IMPL(__imp__sub_824E7A10) {
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
	// bl 0x824e6b58
	ctx.lr = 0x824E7A30;
	sub_824E6B58(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7a48
	if (cr6.eq) goto loc_824E7A48;
	// bl 0x82130588
	ctx.lr = 0x824E7A44;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E7A48:
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

__attribute__((alias("__imp__sub_824E7A60"))) PPC_WEAK_FUNC(sub_824E7A60);
PPC_FUNC_IMPL(__imp__sub_824E7A60) {
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
	ctx.lr = 0x824E7A68;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r25,0
	r25.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r25
	r29.u64 = r25.u64;
	// li r28,1
	r28.s64 = 1;
	// li r26,-1
	r26.s64 = -1;
	// li r27,2
	r27.s64 = 2;
loc_824E7A84:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r31,r11,472
	r31.s64 = r11.s64 + 472;
	// lwz r11,472(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 472);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e7b08
	if (!cr6.eq) goto loc_824E7B08;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// addi r6,r31,108
	ctx.r6.s64 = r31.s64 + 108;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// lwz r5,104(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r3,52(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// bl 0x824e7848
	ctx.lr = 0x824E7AB4;
	sub_824E7848(ctx, base);
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// addi r4,r11,436
	ctx.r4.s64 = r11.s64 + 436;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E7AC8;
	sub_821C8FE0(ctx, base);
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r24,624(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// beq cr6,0x824e7af0
	if (cr6.eq) goto loc_824E7AF0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7AE8;
	sub_821CE0A0(ctx, base);
	// stw r25,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r25.u32);
	// b 0x824e7afc
	goto loc_824E7AFC;
loc_824E7AF0:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7AF8;
	sub_821CE0A0(ctx, base);
	// stw r26,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r26.u32);
loc_824E7AFC:
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E7B08;
	sub_821C9030(ctx, base);
loc_824E7B08:
	// addi r29,r29,640
	r29.s64 = r29.s64 + 640;
	// cmpwi cr6,r29,2560
	cr6.compare<int32_t>(r29.s32, 2560, xer);
	// blt cr6,0x824e7a84
	if (cr6.lt) goto loc_824E7A84;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824E7B1C"))) PPC_WEAK_FUNC(sub_824E7B1C);
PPC_FUNC_IMPL(__imp__sub_824E7B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7B20"))) PPC_WEAK_FUNC(sub_824E7B20);
PPC_FUNC_IMPL(__imp__sub_824E7B20) {
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
	ctx.lr = 0x824E7B28;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x824e70e0
	ctx.lr = 0x824E7B4C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7b8c
	if (cr6.eq) goto loc_824E7B8C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7008
	ctx.lr = 0x824E7B60;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7b8c
	if (cr6.eq) goto loc_824E7B8C;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e7750
	ctx.lr = 0x824E7B84;
	sub_824E7750(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_824E7B8C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e7bbc
	if (cr6.eq) goto loc_824E7BBC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E7BA0;
	sub_821CE080(ctx, base);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7BB4;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_824E7BBC:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E7BC8"))) PPC_WEAK_FUNC(sub_824E7BC8);
PPC_FUNC_IMPL(__imp__sub_824E7BC8) {
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
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,30144(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30144);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824e7c28
	if (!cr6.eq) goto loc_824E7C28;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// stw r11,30144(r10)
	PPC_STORE_U32(ctx.r10.u32 + 30144, r11.u32);
	// addi r31,r9,30120
	r31.s64 = ctx.r9.s64 + 30120;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa970
	ctx.lr = 0x824E7C04;
	sub_824FA970(ctx, base);
	// lis r8,-32132
	ctx.r8.s64 = -2105802752;
	// addi r3,r8,-19424
	ctx.r3.s64 = ctx.r8.s64 + -19424;
	// bl 0x823d9a98
	ctx.lr = 0x824E7C10;
	sub_823D9A98(ctx, base);
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
loc_824E7C28:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,30120
	ctx.r3.s64 = r11.s64 + 30120;
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

__attribute__((alias("__imp__sub_824E7C44"))) PPC_WEAK_FUNC(sub_824E7C44);
PPC_FUNC_IMPL(__imp__sub_824E7C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7C48"))) PPC_WEAK_FUNC(sub_824E7C48);
PPC_FUNC_IMPL(__imp__sub_824E7C48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7c70
	if (cr6.eq) goto loc_824E7C70;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
loc_824E7C70:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7c90
	if (cr6.eq) goto loc_824E7C90;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824e7c94
	if (!cr6.eq) goto loc_824E7C94;
loc_824E7C90:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824E7C94:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7cb0
	if (cr6.eq) goto loc_824E7CB0;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_824E7CB0:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7CC4"))) PPC_WEAK_FUNC(sub_824E7CC4);
PPC_FUNC_IMPL(__imp__sub_824E7CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7CC8"))) PPC_WEAK_FUNC(sub_824E7CC8);
PPC_FUNC_IMPL(__imp__sub_824E7CC8) {
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
	// beq cr6,0x824e7d08
	if (cr6.eq) goto loc_824E7D08;
loc_824E7CE8:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824e7cfc
	if (cr6.eq) goto loc_824E7CFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x824E7CFC;
	sub_825D7AA0(ctx, base);
loc_824E7CFC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e7ce8
	if (!cr6.eq) goto loc_824E7CE8;
loc_824E7D08:
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

__attribute__((alias("__imp__sub_824E7D1C"))) PPC_WEAK_FUNC(sub_824E7D1C);
PPC_FUNC_IMPL(__imp__sub_824E7D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7D20"))) PPC_WEAK_FUNC(sub_824E7D20);
PPC_FUNC_IMPL(__imp__sub_824E7D20) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7da0
	if (cr6.eq) goto loc_824E7DA0;
loc_824E7D44:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// beq cr6,0x824e7d94
	if (cr6.eq) goto loc_824E7D94;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7D64;
	sub_821CE0A0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7d94
	if (cr6.eq) goto loc_824E7D94;
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x824e7d94
	if (!cr6.eq) goto loc_824E7D94;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7d88
	if (cr6.eq) goto loc_824E7D88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82278948
	ctx.lr = 0x824E7D88;
	sub_82278948(ctx, base);
loc_824E7D88:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x824E7D94;
	sub_825D7AA0(ctx, base);
loc_824E7D94:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e7d44
	if (!cr6.eq) goto loc_824E7D44;
loc_824E7DA0:
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

__attribute__((alias("__imp__sub_824E7DB8"))) PPC_WEAK_FUNC(sub_824E7DB8);
PPC_FUNC_IMPL(__imp__sub_824E7DB8) {
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
	ctx.lr = 0x824E7DC0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r7,116(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 116);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// ori r4,r7,128
	ctx.r4.u64 = ctx.r7.u64 | 128;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r8.u32);
	// stb r4,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r4.u8);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,100(r1)
	PPC_STORE_U64(ctx.r1.u32 + 100, ctx.r3.u64);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// std r6,108(r1)
	PPC_STORE_U64(ctx.r1.u32 + 108, ctx.r6.u64);
	// beq cr6,0x824e7edc
	if (cr6.eq) goto loc_824E7EDC;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_824E7E20:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7e44
	if (cr6.eq) goto loc_824E7E44;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824E7E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e7e54
	goto loc_824E7E54;
loc_824E7E44:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824E7E54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E7E54:
	// lbz r11,116(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 116);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7ec0
	if (cr6.eq) goto loc_824E7EC0;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7e7c
	if (cr6.eq) goto loc_824E7E7C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// b 0x824e7ed0
	goto loc_824E7ED0;
loc_824E7E7C:
	// lwz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r10,r9,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7e9c
	if (cr6.eq) goto loc_824E7E9C;
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824e7ea0
	if (!cr6.eq) goto loc_824E7EA0;
loc_824E7E9C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824E7EA0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7ed0
	if (cr6.eq) goto loc_824E7ED0;
	// rlwinm r11,r9,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// b 0x824e7ed0
	goto loc_824E7ED0;
loc_824E7EC0:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r9.u8);
loc_824E7ED0:
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x824e7e20
	if (!cr6.eq) goto loc_824E7E20;
loc_824E7EDC:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E7EF0"))) PPC_WEAK_FUNC(sub_824E7EF0);
PPC_FUNC_IMPL(__imp__sub_824E7EF0) {
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
	ctx.lr = 0x824E7EF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r11,3088(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7f7c
	if (cr6.eq) goto loc_824E7F7C;
	// lwz r11,3032(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3032);
	// addi r3,r29,3032
	ctx.r3.s64 = r29.s64 + 3032;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E7F24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,432(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 432);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7f3c
	if (cr6.eq) goto loc_824E7F3C;
	// bl 0x8275cc90
	ctx.lr = 0x824E7F38;
	sub_8275CC90(ctx, base);
	// stw r28,432(r29)
	PPC_STORE_U32(r29.u32 + 432, r28.u32);
loc_824E7F3C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e7d20
	ctx.lr = 0x824E7F44;
	sub_824E7D20(ctx, base);
	// addi r31,r29,116
	r31.s64 = r29.s64 + 116;
	// li r30,4
	r30.s64 = 4;
loc_824E7F4C:
	// addi r3,r31,-100
	ctx.r3.s64 = r31.s64 + -100;
	// bl 0x824e6f20
	ctx.lr = 0x824E7F54;
	sub_824E6F20(ctx, base);
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stw r28,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r28.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// bne 0x824e7f4c
	if (!cr0.eq) goto loc_824E7F4C;
	// lbz r11,3088(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r10,3088(r29)
	PPC_STORE_U8(r29.u32 + 3088, ctx.r10.u8);
loc_824E7F7C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E7F84"))) PPC_WEAK_FUNC(sub_824E7F84);
PPC_FUNC_IMPL(__imp__sub_824E7F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7F88"))) PPC_WEAK_FUNC(sub_824E7F88);
PPC_FUNC_IMPL(__imp__sub_824E7F88) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7FB4;
	sub_821CE0A0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e7fd0
	if (!cr6.eq) goto loc_824E7FD0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e7930
	ctx.lr = 0x824E7FD0;
	sub_824E7930(ctx, base);
loc_824E7FD0:
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

__attribute__((alias("__imp__sub_824E7FE8"))) PPC_WEAK_FUNC(sub_824E7FE8);
PPC_FUNC_IMPL(__imp__sub_824E7FE8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82279e20
	sub_82279E20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E7FEC"))) PPC_WEAK_FUNC(sub_824E7FEC);
PPC_FUNC_IMPL(__imp__sub_824E7FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7FF0"))) PPC_WEAK_FUNC(sub_824E7FF0);
PPC_FUNC_IMPL(__imp__sub_824E7FF0) {
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
	ctx.lr = 0x824E7FF8;
	// stwu r1,-1344(r1)
	ea = -1344 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mulli r11,r31,104
	r11.s64 = r31.s64 * 104;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// bl 0x824e6cd8
	ctx.lr = 0x824E8018;
	sub_824E6CD8(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6d08
	ctx.lr = 0x824E8024;
	sub_824E6D08(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6d08
	ctx.lr = 0x824E8030;
	sub_824E6D08(ctx, base);
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70e0
	ctx.lr = 0x824E803C;
	sub_824E70E0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70f0
	ctx.lr = 0x824E8048;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r22,r30,24
	r22.u64 = r30.u32 & 0xFF;
	// clrlwi r23,r19,24
	r23.u64 = r19.u32 & 0xFF;
	// clrlwi r26,r18,24
	r26.u64 = r18.u32 & 0xFF;
	// subf r10,r23,r22
	ctx.r10.s64 = r22.s64 - r23.s64;
	// subf r9,r26,r11
	ctx.r9.s64 = r11.s64 - r26.s64;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// xori r30,r6,1
	r30.u64 = ctx.r6.u64 ^ 1;
	// xori r24,r5,1
	r24.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r25,r17,24
	r25.u64 = r17.u32 & 0xFF;
	// bl 0x824e7100
	ctx.lr = 0x824E8084;
	sub_824E7100(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// lbz r11,100(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 100);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// subf r10,r25,r4
	ctx.r10.s64 = ctx.r4.s64 - r25.s64;
	// rlwinm r20,r11,28,31,31
	r20.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r21,r8,1
	r21.u64 = ctx.r8.u64 ^ 1;
	// bl 0x824f9438
	ctx.lr = 0x824E80A8;
	sub_824F9438(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f93b8
	ctx.lr = 0x824E80B4;
	sub_824F93B8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e80c8
	if (!cr6.eq) goto loc_824E80C8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f9230
	ctx.lr = 0x824E80C8;
	sub_824F9230(ctx, base);
loc_824E80C8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// bl 0x824e7110
	ctx.lr = 0x824E80D4;
	sub_824E7110(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x824f9388
	ctx.lr = 0x824E80DC;
	sub_824F9388(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824E80F0;
	sub_823DA950(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e71c8
	ctx.lr = 0x824E80F8;
	sub_824E71C8(ctx, base);
	// clrlwi r27,r30,24
	r27.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x824e8134
	if (!cr6.eq) goto loc_824E8134;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e8134
	if (!cr6.eq) goto loc_824E8134;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e8134
	if (!cr6.eq) goto loc_824E8134;
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e8134
	if (!cr6.eq) goto loc_824E8134;
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8188
	if (cr6.eq) goto loc_824E8188;
loc_824E8134:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7250
	ctx.lr = 0x824E8140;
	sub_824E7250(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e817c
	if (!cr6.eq) goto loc_824E817C;
	// bl 0x824e6f20
	ctx.lr = 0x824E8154;
	sub_824E6F20(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,1088
	ctx.r4.s64 = ctx.r1.s64 + 1088;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8164;
	sub_823DA950(ctx, base);
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// bl 0x824f9230
	ctx.lr = 0x824E816C;
	sub_824F9230(ctx, base);
	// lbz r11,204(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 204);
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r10,204(r1)
	PPC_STORE_U8(ctx.r1.u32 + 204, ctx.r10.u8);
	// b 0x824e8188
	goto loc_824E8188;
loc_824E817C:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8188;
	sub_823DA950(ctx, base);
loc_824E8188:
	// li r16,0
	r16.s64 = 0;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r15,r16
	r15.u64 = r16.u64;
	// stb r16,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, r16.u8);
	// stb r16,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r16.u8);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// stb r16,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r16.u8);
	// addi r30,r11,26136
	r30.s64 = r11.s64 + 26136;
	// stb r16,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, r16.u8);
	// bne cr6,0x824e81dc
	if (!cr6.eq) goto loc_824E81DC;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e81d4
	if (!cr6.eq) goto loc_824E81D4;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e81d4
	if (!cr6.eq) goto loc_824E81D4;
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e828c
	if (cr6.eq) goto loc_824E828C;
loc_824E81D4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e81f4
	if (cr6.eq) goto loc_824E81F4;
loc_824E81DC:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x824e81ec
	if (cr6.eq) goto loc_824E81EC;
	// li r15,1
	r15.s64 = 1;
	// b 0x824e81f4
	goto loc_824E81F4;
loc_824E81EC:
	// li r11,1
	r11.s64 = 1;
	// stb r11,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, r11.u8);
loc_824E81F4:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8218
	if (cr6.eq) goto loc_824E8218;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e8214
	if (cr6.eq) goto loc_824E8214;
	// li r11,1
	r11.s64 = 1;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x824e8218
	goto loc_824E8218;
loc_824E8214:
	// li r16,1
	r16.s64 = 1;
loc_824E8218:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e823c
	if (cr6.eq) goto loc_824E823C;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e8238
	if (cr6.eq) goto loc_824E8238;
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
	// b 0x824e823c
	goto loc_824E823C;
loc_824E8238:
	// stb r11,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, r11.u8);
loc_824E823C:
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e828c
	if (cr6.eq) goto loc_824E828C;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// addi r3,r1,992
	ctx.r3.s64 = ctx.r1.s64 + 992;
	// stw r30,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, r30.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824E8264;
	sub_823DA950(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r1,976
	ctx.r10.s64 = ctx.r1.s64 + 976;
	// addi r9,r11,26172
	ctx.r9.s64 = r11.s64 + 26172;
	// stw r10,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r10.u32);
	// addi r5,r1,976
	ctx.r5.s64 = ctx.r1.s64 + 976;
	// stw r9,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, ctx.r9.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8288;
	sub_824E7DB8(ctx, base);
	// stw r30,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, r30.u32);
loc_824E828C:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e7118
	ctx.lr = 0x824E82B0;
	sub_824E7118(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// bl 0x824e7118
	ctx.lr = 0x824E82BC;
	sub_824E7118(ctx, base);
loc_824E82BC:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x824e82e0
	if (cr6.eq) goto loc_824E82E0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824e82bc
	if (cr6.eq) goto loc_824E82BC;
loc_824E82E0:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// mr r15,r19
	r15.u64 = r19.u64;
	// stb r18,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r18.u8);
	// stb r17,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r17.u8);
loc_824E82F4:
	// clrlwi r10,r16,24
	ctx.r10.u64 = r16.u32 & 0xFF;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r31,r11,26160
	r31.s64 = r11.s64 + 26160;
	// beq cr6,0x824e8354
	if (cr6.eq) goto loc_824E8354;
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// stw r30,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E831C;
	sub_823DA950(ctx, base);
	// lbz r8,708(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 708);
	// lbz r11,100(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 100);
	// addi r10,r1,592
	ctx.r10.s64 = ctx.r1.s64 + 592;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r31,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, r31.u32);
	// rlwimi r8,r11,4,20,24
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xF80) | (ctx.r8.u64 & 0xFFFFFFFFFFFFF07F);
	// stw r10,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r10.u32);
	// stw r9,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, ctx.r9.u32);
	// addi r5,r1,592
	ctx.r5.s64 = ctx.r1.s64 + 592;
	// stb r8,708(r1)
	PPC_STORE_U8(ctx.r1.u32 + 708, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8350;
	sub_824E7DB8(ctx, base);
	// stw r30,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, r30.u32);
loc_824E8354:
	// lbz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e83ac
	if (cr6.eq) goto loc_824E83AC;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stw r30,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8374;
	sub_823DA950(ctx, base);
	// lbz r8,324(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 324);
	// lbz r11,100(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 100);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r31.u32);
	// rlwimi r8,r11,4,20,24
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xF80) | (ctx.r8.u64 & 0xFFFFFFFFFFFFF07F);
	// stw r10,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r10.u32);
	// stw r9,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r9.u32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stb r8,324(r1)
	PPC_STORE_U8(ctx.r1.u32 + 324, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E83A8;
	sub_824E7DB8(ctx, base);
	// stw r30,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r30.u32);
loc_824E83AC:
	// lbz r10,83(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8400
	if (cr6.eq) goto loc_824E8400;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// stw r30,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E83CC;
	sub_823DA950(ctx, base);
	// lbz r9,580(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 580);
	// addi r11,r1,464
	r11.s64 = ctx.r1.s64 + 464;
	// stw r31,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, r11.u32);
	// stw r10,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, ctx.r10.u32);
	// addi r5,r1,464
	ctx.r5.s64 = ctx.r1.s64 + 464;
	// stb r8,580(r1)
	PPC_STORE_U8(ctx.r1.u32 + 580, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E83FC;
	sub_824E7DB8(ctx, base);
	// stw r30,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, r30.u32);
loc_824E8400:
	// clrlwi r11,r15,24
	r11.u64 = r15.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8454
	if (cr6.eq) goto loc_824E8454;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// stw r30,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8420;
	sub_823DA950(ctx, base);
	// lbz r9,836(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 836);
	// addi r11,r1,720
	r11.s64 = ctx.r1.s64 + 720;
	// stw r31,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r31.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, r11.u32);
	// stw r10,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, ctx.r10.u32);
	// addi r5,r1,720
	ctx.r5.s64 = ctx.r1.s64 + 720;
	// stb r8,836(r1)
	PPC_STORE_U8(ctx.r1.u32 + 836, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8450;
	sub_824E7DB8(ctx, base);
	// stw r30,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r30.u32);
loc_824E8454:
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e84a8
	if (cr6.eq) goto loc_824E84A8;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// stw r30,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8474;
	sub_823DA950(ctx, base);
	// lbz r9,452(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 452);
	// addi r11,r1,336
	r11.s64 = ctx.r1.s64 + 336;
	// stw r31,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r31.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, r11.u32);
	// stw r10,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r10.u32);
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// stb r8,452(r1)
	PPC_STORE_U8(ctx.r1.u32 + 452, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E84A4;
	sub_824E7DB8(ctx, base);
	// stw r30,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r30.u32);
loc_824E84A8:
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e84f8
	if (cr6.eq) goto loc_824E84F8;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// stw r30,848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 848, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E84C8;
	sub_823DA950(ctx, base);
	// lbz r9,964(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 964);
	// addi r11,r1,848
	r11.s64 = ctx.r1.s64 + 848;
	// stw r31,848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 848, r31.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 856, r11.u32);
	// stw r10,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, ctx.r10.u32);
	// addi r5,r1,848
	ctx.r5.s64 = ctx.r1.s64 + 848;
	// stb r8,964(r1)
	PPC_STORE_U8(ctx.r1.u32 + 964, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E84F8;
	sub_824E7DB8(ctx, base);
loc_824E84F8:
	// lbz r11,100(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 100);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stb r10,100(r29)
	PPC_STORE_U8(r29.u32 + 100, ctx.r10.u8);
	// addi r1,r1,1344
	ctx.r1.s64 = ctx.r1.s64 + 1344;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_824E8510"))) PPC_WEAK_FUNC(sub_824E8510);
PPC_FUNC_IMPL(__imp__sub_824E8510) {
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
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mulli r11,r10,104
	r11.s64 = ctx.r10.s64 * 104;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
	// bl 0x8244a9c0
	ctx.lr = 0x824E8544;
	sub_8244A9C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e864c
	if (!cr6.eq) goto loc_824E864C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7110
	ctx.lr = 0x824E8554;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x824E8558;
	sub_824F92F0(ctx, base);
	// ld r11,96(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// bne cr6,0x824e864c
	if (!cr6.eq) goto loc_824E864C;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x824e6400
	ctx.lr = 0x824E856C;
	sub_824E6400(ctx, base);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E857C;
	sub_823DA950(ctx, base);
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824e85fc
	if (cr6.eq) goto loc_824E85FC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f9438
	ctx.lr = 0x824E8590;
	sub_824F9438(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x824f92a0
	ctx.lr = 0x824E859C;
	sub_824F92A0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// addi r10,r11,26136
	ctx.r10.s64 = r11.s64 + 26136;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r10,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r10.u32);
	// bl 0x823da950
	ctx.lr = 0x824E85B8;
	sub_823DA950(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// addi r7,r9,26196
	ctx.r7.s64 = ctx.r9.s64 + 26196;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// stw r8,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r8.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stw r7,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r7.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E85DC;
	sub_823DA950(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,432
	r11.s64 = ctx.r1.s64 + 432;
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// ld r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r6.u32 + 0);
	// ld r9,8(r6)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// std r9,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r9.u64);
	// b 0x824e8640
	goto loc_824E8640;
loc_824E85FC:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// addi r10,r11,26136
	ctx.r10.s64 = r11.s64 + 26136;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r10,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r10.u32);
	// bl 0x823da950
	ctx.lr = 0x824E8618;
	sub_823DA950(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r1,448
	ctx.r8.s64 = ctx.r1.s64 + 448;
	// addi r7,r9,26208
	ctx.r7.s64 = ctx.r9.s64 + 26208;
	// addi r3,r1,560
	ctx.r3.s64 = ctx.r1.s64 + 560;
	// stw r8,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r8.u32);
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// stw r7,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r7.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E863C;
	sub_823DA950(ctx, base);
	// addi r5,r1,448
	ctx.r5.s64 = ctx.r1.s64 + 448;
loc_824E8640:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E864C;
	sub_824E7DB8(ctx, base);
loc_824E864C:
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

__attribute__((alias("__imp__sub_824E8664"))) PPC_WEAK_FUNC(sub_824E8664);
PPC_FUNC_IMPL(__imp__sub_824E8664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8668"))) PPC_WEAK_FUNC(sub_824E8668);
PPC_FUNC_IMPL(__imp__sub_824E8668) {
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
	ctx.lr = 0x824E8670;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mulli r11,r4,104
	r11.s64 = ctx.r4.s64 * 104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r10,r11,26136
	ctx.r10.s64 = r11.s64 + 26136;
	// beq cr6,0x824e86fc
	if (cr6.eq) goto loc_824E86FC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x823da950
	ctx.lr = 0x824E86AC;
	sub_823DA950(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r9,26196
	ctx.r7.s64 = ctx.r9.s64 + 26196;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824E86D0;
	sub_823DA950(ctx, base);
	// ld r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// ld r11,8(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r6,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r6.u64);
	// std r11,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r11.u64);
	// bl 0x824e7db8
	ctx.lr = 0x824E86F4;
	sub_824E7DB8(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d924c
	return;
loc_824E86FC:
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// stw r10,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r10.u32);
	// bl 0x823da950
	ctx.lr = 0x824E8708;
	sub_823DA950(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// addi r7,r9,26208
	ctx.r7.s64 = ctx.r9.s64 + 26208;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// stw r8,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r8.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r7,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r7.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824E872C;
	sub_823DA950(ctx, base);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E873C;
	sub_824E7DB8(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E8744"))) PPC_WEAK_FUNC(sub_824E8744);
PPC_FUNC_IMPL(__imp__sub_824E8744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8748"))) PPC_WEAK_FUNC(sub_824E8748);
PPC_FUNC_IMPL(__imp__sub_824E8748) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,26268
	ctx.r10.s64 = r11.s64 + 26268;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x824E8774;
	sub_824E7BC8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824fa710
	ctx.lr = 0x824E877C;
	sub_824FA710(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,-1028
	ctx.r7.s64 = ctx.r9.s64 + -1028;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824e87a0
	if (cr6.eq) goto loc_824E87A0;
	// bl 0x82130588
	ctx.lr = 0x824E879C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E87A0:
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

__attribute__((alias("__imp__sub_824E87B8"))) PPC_WEAK_FUNC(sub_824E87B8);
PPC_FUNC_IMPL(__imp__sub_824E87B8) {
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
	// bl 0x824e7ef0
	ctx.lr = 0x824E87D0;
	sub_824E7EF0(ctx, base);
	// addi r3,r31,3032
	ctx.r3.s64 = r31.s64 + 3032;
	// bl 0x824e6b58
	ctx.lr = 0x824E87D8;
	sub_824E6B58(ctx, base);
	// addi r3,r31,436
	ctx.r3.s64 = r31.s64 + 436;
	// bl 0x82130000
	ctx.lr = 0x824E87E0;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7d20
	ctx.lr = 0x824E87E8;
	sub_824E7D20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7cc8
	ctx.lr = 0x824E87F0;
	sub_824E7CC8(ctx, base);
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

__attribute__((alias("__imp__sub_824E8804"))) PPC_WEAK_FUNC(sub_824E8804);
PPC_FUNC_IMPL(__imp__sub_824E8804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8808"))) PPC_WEAK_FUNC(sub_824E8808);
PPC_FUNC_IMPL(__imp__sub_824E8808) {
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
	ctx.lr = 0x824E8810;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r31,r28
	r31.u64 = r28.u64;
	// lbz r11,3088(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e8894
	if (!cr6.eq) goto loc_824E8894;
	// bl 0x824e76a0
	ctx.lr = 0x824E8834;
	sub_824E76A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8894
	if (cr6.eq) goto loc_824E8894;
	// mr r30,r28
	r30.u64 = r28.u64;
	// addi r31,r29,116
	r31.s64 = r29.s64 + 116;
loc_824E8848:
	// addi r3,r31,-100
	ctx.r3.s64 = r31.s64 + -100;
	// bl 0x824e6f20
	ctx.lr = 0x824E8850;
	sub_824E6F20(ctx, base);
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stw r28,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r28.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// bl 0x824e7ff0
	ctx.lr = 0x824E886C;
	sub_824E7FF0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x824e8848
	if (cr6.lt) goto loc_824E8848;
	// lbz r11,3088(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,3088(r29)
	PPC_STORE_U8(r29.u32 + 3088, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E8894:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E88A0"))) PPC_WEAK_FUNC(sub_824E88A0);
PPC_FUNC_IMPL(__imp__sub_824E88A0) {
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
	ctx.lr = 0x824E88A8;
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,432(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 432);
	// bl 0x827bd054
	ctx.lr = 0x824E88C4;
	__imp__XNotifyGetNext(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r18,r11,26136
	r18.s64 = r11.s64 + 26136;
	// beq cr6,0x824e8b78
	if (cr6.eq) goto loc_824E8B78;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,512
	ctx.r10.s64 = 33554432;
	// lis r9,512
	ctx.r9.s64 = 33554432;
	// lis r8,-32747
	ctx.r8.s64 = -2146107392;
	// lis r7,512
	ctx.r7.s64 = 33554432;
	// lis r6,1024
	ctx.r6.s64 = 67108864;
	// ori r23,r10,2
	r23.u64 = ctx.r10.u64 | 2;
	// ori r20,r9,1
	r20.u64 = ctx.r9.u64 | 1;
	// ori r17,r8,4101
	r17.u64 = ctx.r8.u64 | 4101;
	// li r25,1
	r25.s64 = 1;
	// ori r21,r7,7
	r21.u64 = ctx.r7.u64 | 7;
	// addi r24,r11,26148
	r24.s64 = r11.s64 + 26148;
	// lis r19,1024
	r19.s64 = 67108864;
	// ori r22,r6,3
	r22.u64 = ctx.r6.u64 | 3;
loc_824E890C:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r23
	cr6.compare<uint32_t>(r11.u32, r23.u32, xer);
	// bgt cr6,0x824e8ae4
	if (cr6.gt) goto loc_824E8AE4;
	// beq cr6,0x824e8ac4
	if (cr6.eq) goto loc_824E8AC4;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x824e89ec
	if (cr6.eq) goto loc_824E89EC;
	// cmplwi cr6,r11,14
	cr6.compare<uint32_t>(r11.u32, 14, xer);
	// beq cr6,0x824e8974
	if (cr6.eq) goto loc_824E8974;
	// cmplw cr6,r11,r20
	cr6.compare<uint32_t>(r11.u32, r20.u32, xer);
	// bne cr6,0x824e8b5c
	if (!cr6.eq) goto loc_824E8B5C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r17
	cr6.compare<uint32_t>(r11.u32, r17.u32, xer);
	// bne cr6,0x824e8b5c
	if (!cr6.eq) goto loc_824E8B5C;
	// lbz r11,116(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 116);
	// lbz r10,220(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 220);
	// lbz r9,324(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 324);
	// ori r8,r11,136
	ctx.r8.u64 = r11.u64 | 136;
	// lbz r7,428(r28)
	ctx.r7.u64 = PPC_LOAD_U8(r28.u32 + 428);
	// ori r6,r10,136
	ctx.r6.u64 = ctx.r10.u64 | 136;
	// ori r5,r9,136
	ctx.r5.u64 = ctx.r9.u64 | 136;
	// stb r8,116(r28)
	PPC_STORE_U8(r28.u32 + 116, ctx.r8.u8);
	// ori r4,r7,136
	ctx.r4.u64 = ctx.r7.u64 | 136;
	// stb r6,220(r28)
	PPC_STORE_U8(r28.u32 + 220, ctx.r6.u8);
	// stb r5,324(r28)
	PPC_STORE_U8(r28.u32 + 324, ctx.r5.u8);
	// stb r4,428(r28)
	PPC_STORE_U8(r28.u32 + 428, ctx.r4.u8);
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E8974:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8994
	if (cr6.eq) goto loc_824E8994;
	// lbz r9,116(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 116);
	// addi r11,r28,16
	r11.s64 = r28.s64 + 16;
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
	// stb r8,116(r28)
	PPC_STORE_U8(r28.u32 + 116, ctx.r8.u8);
loc_824E8994:
	// rlwinm r11,r10,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e89b0
	if (cr6.eq) goto loc_824E89B0;
	// lbz r9,220(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 220);
	// addi r11,r28,120
	r11.s64 = r28.s64 + 120;
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
	// stb r8,220(r28)
	PPC_STORE_U8(r28.u32 + 220, ctx.r8.u8);
loc_824E89B0:
	// rlwinm r11,r10,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e89cc
	if (cr6.eq) goto loc_824E89CC;
	// lbz r9,324(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 324);
	// addi r11,r28,224
	r11.s64 = r28.s64 + 224;
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
	// stb r8,324(r28)
	PPC_STORE_U8(r28.u32 + 324, ctx.r8.u8);
loc_824E89CC:
	// rlwinm r11,r10,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8b5c
	if (cr6.eq) goto loc_824E8B5C;
	// lbz r10,428(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 428);
	// addi r11,r28,328
	r11.s64 = r28.s64 + 328;
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,428(r28)
	PPC_STORE_U8(r28.u32 + 428, ctx.r9.u8);
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E89EC:
	// li r27,0
	r27.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r25
	r29.u64 = r25.u64;
	// addi r30,r28,16
	r30.s64 = r28.s64 + 16;
loc_824E8A00:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// and r10,r29,r11
	ctx.r10.u64 = r29.u64 & r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8a3c
	if (cr6.eq) goto loc_824E8A3C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x824E8A18;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8a3c
	if (cr6.eq) goto loc_824E8A3C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x824E8A2C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e8a3c
	if (!cr6.eq) goto loc_824E8A3C;
	// mr r27,r25
	r27.u64 = r25.u64;
loc_824E8A3C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824575f8
	ctx.lr = 0x824E8A44;
	sub_824575F8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824e8a50
	if (cr6.eq) goto loc_824E8A50;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
loc_824E8A50:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,104
	r30.s64 = r30.s64 + 104;
	// rotlwi r29,r29,1
	r29.u64 = __builtin_rotateleft32(r29.u32, 1);
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x824e8a00
	if (cr6.lt) goto loc_824E8A00;
	// addi r31,r28,112
	r31.s64 = r28.s64 + 112;
	// li r30,4
	r30.s64 = 4;
loc_824E8A6C:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8a88
	if (cr6.eq) goto loc_824E8A88;
	// bl 0x821c9788
	ctx.lr = 0x824E8A80;
	sub_821C9788(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x824e8ab4
	goto loc_824E8AB4;
loc_824E8A88:
	// rlwimi r11,r25,7,0,24
	r11.u64 = (__builtin_rotateleft32(r25.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// bl 0x821c9788
	ctx.lr = 0x824E8A94;
	sub_821C9788(ctx, base);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8ab4
	if (cr6.eq) goto loc_824E8AB4;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x824e8ab4
	if (!cr6.eq) goto loc_824E8AB4;
	// addi r11,r3,1500
	r11.s64 = ctx.r3.s64 + 1500;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_824E8AB4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// bne 0x824e8a6c
	if (!cr0.eq) goto loc_824E8A6C;
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E8AC4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mulli r11,r11,104
	r11.s64 = r11.s64 * 104;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lbz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 116);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,116(r11)
	PPC_STORE_U8(r11.u32 + 116, ctx.r9.u8);
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E8AE4:
	// cmplw cr6,r11,r21
	cr6.compare<uint32_t>(r11.u32, r21.u32, xer);
	// beq cr6,0x824e8b1c
	if (cr6.eq) goto loc_824E8B1C;
	// cmplw cr6,r11,r19
	cr6.compare<uint32_t>(r11.u32, r19.u32, xer);
	// ble cr6,0x824e8b5c
	if (!cr6.gt) goto loc_824E8B5C;
	// cmplw cr6,r11,r22
	cr6.compare<uint32_t>(r11.u32, r22.u32, xer);
	// bgt cr6,0x824e8b5c
	if (cr6.gt) goto loc_824E8B5C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mulli r11,r11,104
	r11.s64 = r11.s64 * 104;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lbz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 116);
	// ori r9,r10,64
	ctx.r9.u64 = ctx.r10.u64 | 64;
	// stb r9,116(r11)
	PPC_STORE_U8(r11.u32 + 116, ctx.r9.u8);
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E8B1C:
	// stw r18,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r18.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,96
	ctx.r5.s64 = 96;
	// mulli r11,r11,104
	r11.s64 = r11.s64 * 104;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x823da950
	ctx.lr = 0x824E8B3C;
	sub_823DA950(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8B58;
	sub_824E7DB8(ctx, base);
	// stw r18,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r18.u32);
loc_824E8B5C:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,432(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 432);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd054
	ctx.lr = 0x824E8B70;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824e890c
	if (!cr6.eq) goto loc_824E890C;
loc_824E8B78:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r29,0
	r29.s64 = 0;
	// addi r31,r28,116
	r31.s64 = r28.s64 + 116;
	// addi r27,r11,26184
	r27.s64 = r11.s64 + 26184;
loc_824E8B88:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8bc0
	if (cr6.eq) goto loc_824E8BC0;
	// bl 0x821c9788
	ctx.lr = 0x824E8B9C;
	sub_821C9788(ctx, base);
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// subf. r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x824e8bc0
	if (cr0.lt) goto loc_824E8BC0;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// bl 0x824e7ff0
	ctx.lr = 0x824E8BC0;
	sub_824E7FF0(ctx, base);
loc_824E8BC0:
	// addi r30,r31,-100
	r30.s64 = r31.s64 + -100;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x824E8BCC;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8c7c
	if (cr6.eq) goto loc_824E8C7C;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8c28
	if (cr6.eq) goto loc_824E8C28;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stw r18,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r18.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// rlwinm r11,r11,0,26,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// bl 0x823da950
	ctx.lr = 0x824E8C08;
	sub_823DA950(ctx, base);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// stw r27,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r27.u32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stw r10,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r10.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8C24;
	sub_824E7DB8(ctx, base);
	// stw r18,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r18.u32);
loc_824E8C28:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8c50
	if (cr6.eq) goto loc_824E8C50;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// rlwinm r11,r11,0,27,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// bl 0x824e8510
	ctx.lr = 0x824E8C50;
	sub_824E8510(ctx, base);
loc_824E8C50:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8c7c
	if (cr6.eq) goto loc_824E8C7C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7ff0
	ctx.lr = 0x824E8C6C;
	sub_824E7FF0(ctx, base);
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
loc_824E8C7C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x824e8b88
	if (cr6.lt) goto loc_824E8B88;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_824E8C94"))) PPC_WEAK_FUNC(sub_824E8C94);
PPC_FUNC_IMPL(__imp__sub_824E8C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8C98"))) PPC_WEAK_FUNC(sub_824E8C98);
PPC_FUNC_IMPL(__imp__sub_824E8C98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x824E8CA0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r29,16
	r31.s64 = r29.s64 + 16;
	// li r28,3
	r28.s64 = 3;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// stw r30,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r30.u32);
loc_824E8CC4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824E8CCC;
	sub_824E71C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6f20
	ctx.lr = 0x824E8CD4;
	sub_824E6F20(ctx, base);
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// stb r10,100(r31)
	PPC_STORE_U8(r31.u32 + 100, ctx.r10.u8);
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// bge 0x824e8cc4
	if (!cr0.lt) goto loc_824E8CC4;
	// addi r3,r29,436
	ctx.r3.s64 = r29.s64 + 436;
	// bl 0x821c8ed8
	ctx.lr = 0x824E8CF8;
	sub_821C8ED8(ctx, base);
	// addi r31,r29,472
	r31.s64 = r29.s64 + 472;
	// li r28,3
	r28.s64 = 3;
	// li r26,2
	r26.s64 = 2;
	// li r27,-1
	r27.s64 = -1;
loc_824E8D08:
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824e71c8
	ctx.lr = 0x824E8D14;
	sub_824E71C8(ctx, base);
	// stw r27,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r27.u32);
	// addi r3,r31,108
	ctx.r3.s64 = r31.s64 + 108;
	// bl 0x824e8de8
	ctx.lr = 0x824E8D20;
	sub_824E8DE8(ctx, base);
	// stw r30,624(r31)
	PPC_STORE_U32(r31.u32 + 624, r30.u32);
	// stw r30,628(r31)
	PPC_STORE_U32(r31.u32 + 628, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stw r30,632(r31)
	PPC_STORE_U32(r31.u32 + 632, r30.u32);
	// addi r31,r31,640
	r31.s64 = r31.s64 + 640;
	// bge 0x824e8d08
	if (!cr0.lt) goto loc_824E8D08;
	// addi r3,r29,3032
	ctx.r3.s64 = r29.s64 + 3032;
	// bl 0x824e6928
	ctx.lr = 0x824E8D40;
	sub_824E6928(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r30,3084(r29)
	PPC_STORE_U32(r29.u32 + 3084, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r10,r11,26220
	ctx.r10.s64 = r11.s64 + 26220;
	// stw r10,3032(r29)
	PPC_STORE_U32(r29.u32 + 3032, ctx.r10.u32);
	// lbz r9,3088(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// clrlwi r8,r9,26
	ctx.r8.u64 = ctx.r9.u32 & 0x3F;
	// stw r30,432(r29)
	PPC_STORE_U32(r29.u32 + 432, r30.u32);
	// stb r8,3088(r29)
	PPC_STORE_U8(r29.u32 + 3088, ctx.r8.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E8D6C"))) PPC_WEAK_FUNC(sub_824E8D6C);
PPC_FUNC_IMPL(__imp__sub_824E8D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8D70"))) PPC_WEAK_FUNC(sub_824E8D70);
PPC_FUNC_IMPL(__imp__sub_824E8D70) {
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
	// bl 0x824e88a0
	ctx.lr = 0x824E8D8C;
	sub_824E88A0(ctx, base);
	// bl 0x825019b0
	ctx.lr = 0x824E8D90;
	sub_825019B0(ctx, base);
	// lbz r11,3088(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 3088);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r9,r11,26,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x824e8dd0
	if (cr6.eq) goto loc_824E8DD0;
	// rlwimi r11,r10,6,25,25
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,3088(r30)
	PPC_STORE_U8(r30.u32 + 3088, r11.u8);
	// bne cr6,0x824e8dd0
	if (!cr6.eq) goto loc_824E8DD0;
	// li r31,0
	r31.s64 = 0;
loc_824E8DB8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7ff0
	ctx.lr = 0x824E8DC4;
	sub_824E7FF0(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x824e8db8
	if (cr6.lt) goto loc_824E8DB8;
loc_824E8DD0:
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

__attribute__((alias("__imp__sub_824E8DE8"))) PPC_WEAK_FUNC(sub_824E8DE8);
PPC_FUNC_IMPL(__imp__sub_824E8DE8) {
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
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// lbz r11,512(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 512);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,512(r31)
	PPC_STORE_U8(r31.u32 + 512, ctx.r10.u8);
	// bl 0x8244d150
	ctx.lr = 0x824E8E14;
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

__attribute__((alias("__imp__sub_824E8E2C"))) PPC_WEAK_FUNC(sub_824E8E2C);
PPC_FUNC_IMPL(__imp__sub_824E8E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8E30"))) PPC_WEAK_FUNC(sub_824E8E30);
PPC_FUNC_IMPL(__imp__sub_824E8E30) {
	PPC_FUNC_PROLOGUE();
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8244d150
	sub_8244D150(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E8E3C"))) PPC_WEAK_FUNC(sub_824E8E3C);
PPC_FUNC_IMPL(__imp__sub_824E8E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8E40"))) PPC_WEAK_FUNC(sub_824E8E40);
PPC_FUNC_IMPL(__imp__sub_824E8E40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,0
	r11.s64 = 0;
	// std r11,4(r3)
	PPC_STORE_U64(ctx.r3.u32 + 4, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8E54"))) PPC_WEAK_FUNC(sub_824E8E54);
PPC_FUNC_IMPL(__imp__sub_824E8E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8E58"))) PPC_WEAK_FUNC(sub_824E8E58);
PPC_FUNC_IMPL(__imp__sub_824E8E58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e8e68
	if (cr6.eq) goto loc_824E8E68;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// blr 
	return;
loc_824E8E68:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8E70"))) PPC_WEAK_FUNC(sub_824E8E70);
PPC_FUNC_IMPL(__imp__sub_824E8E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// rlwinm r11,r3,4,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xF;
	// li r3,-1
	ctx.r3.s64 = -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-29032
	r12.s64 = r12.s64 + -29032;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		// ERROR: 0x824E8EB8
		return;
	case 1:
		// ERROR: 0x824E8EB8
		return;
	case 2:
		// ERROR: 0x824E8EC0
		return;
	case 3:
		// ERROR: 0x824E8EC0
		return;
	case 4:
		// ERROR: 0x824E8EC4
		return;
	case 5:
		// ERROR: 0x824E8EB8
		return;
	case 6:
		// ERROR: 0x824E8EC4
		return;
	case 7:
		// ERROR: 0x824E8EC0
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_824E8E98"))) PPC_WEAK_FUNC(sub_824E8E98);
PPC_FUNC_IMPL(__imp__sub_824E8E98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r14{};
	PPCRegister r18{};
	// lwz r18,-29000(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -29000);
	// lwz r18,-29000(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -29000);
	// lwz r18,-28992(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28992);
	// lwz r18,-28992(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28992);
	// lwz r18,-28988(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28988);
	// lwz r18,-29000(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -29000);
	// lwz r18,-28988(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28988);
	// lwz r18,-28992(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28992);
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8EC0"))) PPC_WEAK_FUNC(sub_824E8EC0);
PPC_FUNC_IMPL(__imp__sub_824E8EC0) {
	PPC_FUNC_PROLOGUE();
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8EC8"))) PPC_WEAK_FUNC(sub_824E8EC8);
PPC_FUNC_IMPL(__imp__sub_824E8EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,-1
	ctx.r3.s64 = -1;
	// rlwinm r11,r11,4,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-28940
	r12.s64 = r12.s64 + -28940;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		// ERROR: 0x824E8F14
		return;
	case 1:
		// ERROR: 0x824E8F14
		return;
	case 2:
		// ERROR: 0x824E8F1C
		return;
	case 3:
		// ERROR: 0x824E8F1C
		return;
	case 4:
		// ERROR: 0x824E8F20
		return;
	case 5:
		// ERROR: 0x824E8F14
		return;
	case 6:
		// ERROR: 0x824E8F20
		return;
	case 7:
		// ERROR: 0x824E8F1C
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_824E8EF4"))) PPC_WEAK_FUNC(sub_824E8EF4);
PPC_FUNC_IMPL(__imp__sub_824E8EF4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r14{};
	PPCRegister r18{};
	// lwz r18,-28908(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28908);
	// lwz r18,-28908(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28908);
	// lwz r18,-28900(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28900);
	// lwz r18,-28900(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28900);
	// lwz r18,-28896(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28896);
	// lwz r18,-28908(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28908);
	// lwz r18,-28896(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28896);
	// lwz r18,-28900(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28900);
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8F1C"))) PPC_WEAK_FUNC(sub_824E8F1C);
PPC_FUNC_IMPL(__imp__sub_824E8F1C) {
	PPC_FUNC_PROLOGUE();
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8F24"))) PPC_WEAK_FUNC(sub_824E8F24);
PPC_FUNC_IMPL(__imp__sub_824E8F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8F28"))) PPC_WEAK_FUNC(sub_824E8F28);
PPC_FUNC_IMPL(__imp__sub_824E8F28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824e8f7c
	if (cr6.lt) goto loc_824E8F7C;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e8f40
	if (cr6.eq) goto loc_824E8F40;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e8f44
	goto loc_824E8F44;
loc_824E8F40:
	// li r11,0
	r11.s64 = 0;
loc_824E8F44:
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x824e8f7c
	if (!cr6.lt) goto loc_824E8F7C;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e8f5c
	if (cr6.eq) goto loc_824E8F5C;
	// ld r11,4(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 4);
	// b 0x824e8f60
	goto loc_824E8F60;
loc_824E8F5C:
	// li r11,0
	r11.s64 = 0;
loc_824E8F60:
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// li r9,1
	ctx.r9.s64 = 1;
	// sld r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & r11.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x824e8f80
	if (cr6.eq) goto loc_824E8F80;
loc_824E8F7C:
	// li r11,0
	r11.s64 = 0;
loc_824E8F80:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8F88"))) PPC_WEAK_FUNC(sub_824E8F88);
PPC_FUNC_IMPL(__imp__sub_824E8F88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e8f98
	if (cr6.eq) goto loc_824E8F98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e8f9c
	goto loc_824E8F9C;
loc_824E8F98:
	// li r11,0
	r11.s64 = 0;
loc_824E8F9C:
	// li r10,1
	ctx.r10.s64 = 1;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// sld r11,r10,r11
	r11.u64 = r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (r11.u8 & 0x7F));
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// beq cr6,0x824e8fbc
	if (cr6.eq) goto loc_824E8FBC;
	// ld r11,4(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 4);
	// b 0x824e8fc0
	goto loc_824E8FC0;
loc_824E8FBC:
	// li r11,0
	r11.s64 = 0;
loc_824E8FC0:
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e8fd4
	if (!cr6.eq) goto loc_824E8FD4;
	// li r11,0
	r11.s64 = 0;
loc_824E8FD4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8FDC"))) PPC_WEAK_FUNC(sub_824E8FDC);
PPC_FUNC_IMPL(__imp__sub_824E8FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8FE0"))) PPC_WEAK_FUNC(sub_824E8FE0);
PPC_FUNC_IMPL(__imp__sub_824E8FE0) {
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
	ctx.lr = 0x824E8FE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x824e9030
	if (cr6.lt) goto loc_824E9030;
	// addi r29,r30,512
	r29.s64 = r30.s64 + 512;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bge cr6,0x824e9030
	if (!cr6.lt) goto loc_824E9030;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8ec8
	ctx.lr = 0x824E9014;
	sub_824E8EC8(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// blt cr6,0x824e902c
	if (cr6.lt) goto loc_824E902C;
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// blt cr6,0x824e9030
	if (cr6.lt) goto loc_824E9030;
loc_824E902C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824E9030:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E9038"))) PPC_WEAK_FUNC(sub_824E9038);
PPC_FUNC_IMPL(__imp__sub_824E9038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 + 12;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e9054
	if (cr6.eq) goto loc_824E9054;
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x824e9058
	goto loc_824E9058;
loc_824E9054:
	// li r5,0
	ctx.r5.s64 = 0;
loc_824E9058:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beq cr6,0x824e910c
	if (cr6.eq) {
		// ERROR 824E910C
		return;
	}
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// li r11,0
	r11.s64 = 0;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x824e90fc
	if (cr6.lt) {
		// ERROR 824E90FC
		return;
	}
	// addi r7,r8,512
	ctx.r7.s64 = ctx.r8.s64 + 512;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// bge cr6,0x824e90fc
	if (!cr6.lt) {
		// ERROR 824E90FC
		return;
	}
	// rlwinm r10,r10,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// li r11,-1
	r11.s64 = -1;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// bgt cr6,0x824e90e0
	if (cr6.gt) {
		// ERROR 824E90E0
		return;
	}
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-28492
	r12.s64 = r12.s64 + -28492;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		// ERROR: 0x824E90D4
		return;
	case 1:
		// ERROR: 0x824E90D4
		return;
	case 2:
		// ERROR: 0x824E90DC
		return;
	case 3:
		// ERROR: 0x824E90DC
		return;
	case 4:
		// ERROR: 0x824E90E0
		return;
	case 5:
		// ERROR: 0x824E90D4
		return;
	case 6:
		// ERROR: 0x824E90E0
		return;
	case 7:
		// ERROR: 0x824E90DC
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_824E90B4"))) PPC_WEAK_FUNC(sub_824E90B4);
PPC_FUNC_IMPL(__imp__sub_824E90B4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r14{};
	PPCRegister r18{};
	// lwz r18,-28460(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28460);
	// lwz r18,-28460(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28460);
	// lwz r18,-28452(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28452);
	// lwz r18,-28452(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28452);
	// lwz r18,-28448(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28448);
	// lwz r18,-28460(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28460);
	// lwz r18,-28448(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28448);
	// lwz r18,-28452(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28452);
	// li r11,4
	r11.s64 = 4;
	// b 0x824e90e0
	// ERROR 824E90E0
	return;
}

__attribute__((alias("__imp__sub_824E90DC"))) PPC_WEAK_FUNC(sub_824E90DC);
PPC_FUNC_IMPL(__imp__sub_824E90DC) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,8
	r11.s64 = 8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x824e90f8
	if (cr6.lt) goto loc_824E90F8;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x824e90fc
	if (cr6.lt) goto loc_824E90FC;
loc_824E90F8:
	// li r11,0
	r11.s64 = 0;
loc_824E90FC:
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// blt cr6,0x824e9064
	if (cr6.lt) {
		// ERROR 824E9064
		return;
	}
	// blr 
	return;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E9114"))) PPC_WEAK_FUNC(sub_824E9114);
PPC_FUNC_IMPL(__imp__sub_824E9114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9118"))) PPC_WEAK_FUNC(sub_824E9118);
PPC_FUNC_IMPL(__imp__sub_824E9118) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824e9234
	if (cr6.eq) {
		sub_824E9234(ctx, base);
		return;
	}
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// li r3,12
	ctx.r3.s64 = 12;
	// addi r9,r7,12
	ctx.r9.s64 = ctx.r7.s64 + 12;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// rlwinm r8,r10,4,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r8,7
	cr6.compare<uint32_t>(ctx.r8.u32, 7, xer);
	// bgt cr6,0x824e9198
	if (cr6.gt) {
		// ERROR 824E9198
		return;
	}
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-28308
	r12.s64 = r12.s64 + -28308;
	// rlwinm r0,r8,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r8.u64) {
	case 0:
		// ERROR: 0x824E918C
		return;
	case 1:
		// ERROR: 0x824E918C
		return;
	case 2:
		// ERROR: 0x824E9194
		return;
	case 3:
		// ERROR: 0x824E9194
		return;
	case 4:
		// ERROR: 0x824E9198
		return;
	case 5:
		// ERROR: 0x824E918C
		return;
	case 6:
		// ERROR: 0x824E9198
		return;
	case 7:
		// ERROR: 0x824E9194
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_824E916C"))) PPC_WEAK_FUNC(sub_824E916C);
PPC_FUNC_IMPL(__imp__sub_824E916C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r14{};
	PPCRegister r18{};
	// lwz r18,-28276(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28276);
	// lwz r18,-28276(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28276);
	// lwz r18,-28268(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28268);
	// lwz r18,-28268(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28268);
	// lwz r18,-28264(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28264);
	// lwz r18,-28276(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28276);
	// lwz r18,-28264(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28264);
	// lwz r18,-28268(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28268);
	// li r11,4
	r11.s64 = 4;
	// b 0x824e9198
	// ERROR 824E9198
	return;
}

__attribute__((alias("__imp__sub_824E9194"))) PPC_WEAK_FUNC(sub_824E9194);
PPC_FUNC_IMPL(__imp__sub_824E9194) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// li r11,8
	r11.s64 = 8;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// blt cr6,0x824e9224
	if (cr6.lt) {
		// ERROR 824E9224
		return;
	}
	// addi r10,r7,512
	ctx.r10.s64 = ctx.r7.s64 + 512;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x824e9224
	if (!cr6.lt) {
		// ERROR 824E9224
		return;
	}
	// li r11,-1
	r11.s64 = -1;
	// cmplwi cr6,r8,7
	cr6.compare<uint32_t>(ctx.r8.u32, 7, xer);
	// bgt cr6,0x824e9208
	if (cr6.gt) {
		// ERROR 824E9208
		return;
	}
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-28196
	r12.s64 = r12.s64 + -28196;
	// rlwinm r0,r8,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r8.u64) {
	case 0:
		// ERROR: 0x824E91FC
		return;
	case 1:
		// ERROR: 0x824E91FC
		return;
	case 2:
		// ERROR: 0x824E9204
		return;
	case 3:
		// ERROR: 0x824E9204
		return;
	case 4:
		// ERROR: 0x824E9208
		return;
	case 5:
		// ERROR: 0x824E91FC
		return;
	case 6:
		// ERROR: 0x824E9208
		return;
	case 7:
		// ERROR: 0x824E9204
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_824E91DC"))) PPC_WEAK_FUNC(sub_824E91DC);
PPC_FUNC_IMPL(__imp__sub_824E91DC) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r14{};
	PPCRegister r18{};
	// lwz r18,-28164(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28164);
	// lwz r18,-28164(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28164);
	// lwz r18,-28156(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28156);
	// lwz r18,-28156(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28156);
	// lwz r18,-28152(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28152);
	// lwz r18,-28164(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28164);
	// lwz r18,-28152(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28152);
	// lwz r18,-28156(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28156);
	// li r11,4
	r11.s64 = 4;
	// b 0x824e9208
	// ERROR 824E9208
	return;
}

__attribute__((alias("__imp__sub_824E9204"))) PPC_WEAK_FUNC(sub_824E9204);
PPC_FUNC_IMPL(__imp__sub_824E9204) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,8
	r11.s64 = 8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x824e9220
	if (cr6.lt) goto loc_824E9220;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x824e9224
	if (cr6.lt) goto loc_824E9224;
loc_824E9220:
	// li r11,0
	r11.s64 = 0;
loc_824E9224:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// bne 0x824e9140
	if (!cr0.eq) {
		// ERROR 824E9140
		return;
	}
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E9234"))) PPC_WEAK_FUNC(sub_824E9234);
PPC_FUNC_IMPL(__imp__sub_824E9234) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E923C"))) PPC_WEAK_FUNC(sub_824E923C);
PPC_FUNC_IMPL(__imp__sub_824E923C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9240"))) PPC_WEAK_FUNC(sub_824E9240);
PPC_FUNC_IMPL(__imp__sub_824E9240) {
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
	ctx.lr = 0x824E9248;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x824e9398
	if (cr6.lt) goto loc_824E9398;
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// bge cr6,0x824e9398
	if (!cr6.lt) goto loc_824E9398;
	// addi r30,r29,12
	r30.s64 = r29.s64 + 12;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e9280
	if (cr6.eq) goto loc_824E9280;
	// lwz r26,0(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x824e9284
	goto loc_824E9284;
loc_824E9280:
	// li r26,0
	r26.s64 = 0;
loc_824E9284:
	// li r28,0
	r28.s64 = 0;
	// li r25,1
	r25.s64 = 1;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x824e9394
	if (!cr6.gt) goto loc_824E9394;
loc_824E9294:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x824e92e4
	if (cr6.lt) goto loc_824E92E4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e92ac
	if (cr6.eq) goto loc_824E92AC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x824e92b0
	goto loc_824E92B0;
loc_824E92AC:
	// li r11,0
	r11.s64 = 0;
loc_824E92B0:
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x824e92e4
	if (!cr6.lt) goto loc_824E92E4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e92c8
	if (cr6.eq) goto loc_824E92C8;
	// ld r11,4(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 4);
	// b 0x824e92cc
	goto loc_824E92CC;
loc_824E92C8:
	// li r11,0
	r11.s64 = 0;
loc_824E92CC:
	// extsw r10,r28
	ctx.r10.s64 = r28.s32;
	// sld r9,r25,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x40 ? 0 : (r25.u64 << (ctx.r10.u8 & 0x7F));
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & r11.u64;
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmpldi cr6,r8,0
	cr6.compare<uint64_t>(ctx.r8.u64, 0, xer);
	// beq cr6,0x824e92e8
	if (cr6.eq) goto loc_824E92E8;
loc_824E92E4:
	// li r11,0
	r11.s64 = 0;
loc_824E92E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9304
	if (cr6.eq) goto loc_824E9304;
	// clrlwi r11,r23,31
	r11.u64 = r23.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e9398
	if (!cr6.eq) goto loc_824E9398;
	// b 0x824e9348
	goto loc_824E9348;
loc_824E9304:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r11,r31,0,0,3
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xF0000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e9328
	if (!cr6.eq) goto loc_824E9328;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82457550
	ctx.lr = 0x824E9324;
	sub_82457550(ctx, base);
	// b 0x824e9348
	goto loc_824E9348;
loc_824E9328:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r22,r30,4
	r22.s64 = r30.s64 + 4;
	// bl 0x824e8ec8
	ctx.lr = 0x824E9334;
	sub_824E8EC8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// bl 0x824575e8
	ctx.lr = 0x824E9348;
	sub_824575E8(ctx, base);
loc_824E9348:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// li r11,0
	r11.s64 = 0;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x824e9388
	if (cr6.lt) goto loc_824E9388;
	// addi r31,r29,512
	r31.s64 = r29.s64 + 512;
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// bge cr6,0x824e9388
	if (!cr6.lt) goto loc_824E9388;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e8ec8
	ctx.lr = 0x824E936C;
	sub_824E8EC8(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x824e9384
	if (cr6.lt) goto loc_824E9384;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x824e9388
	if (cr6.lt) goto loc_824E9388;
loc_824E9384:
	// li r11,0
	r11.s64 = 0;
loc_824E9388:
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// blt cr6,0x824e9294
	if (cr6.lt) goto loc_824E9294;
loc_824E9394:
	// mr r24,r25
	r24.u64 = r25.u64;
loc_824E9398:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E93A4"))) PPC_WEAK_FUNC(sub_824E93A4);
PPC_FUNC_IMPL(__imp__sub_824E93A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E93A8"))) PPC_WEAK_FUNC(sub_824E93A8);
PPC_FUNC_IMPL(__imp__sub_824E93A8) {
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
	ctx.lr = 0x824E93B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824e943c
	if (cr6.lt) goto loc_824E943C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e93d4
	if (cr6.eq) goto loc_824E93D4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x824e93d8
	goto loc_824E93D8;
loc_824E93D4:
	// li r11,0
	r11.s64 = 0;
loc_824E93D8:
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x824e943c
	if (!cr6.lt) goto loc_824E943C;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x824e9438
	if (!cr6.gt) goto loc_824E9438;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
loc_824E93F0:
	// li r11,0
	r11.s64 = 0;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x824e942c
	if (cr6.lt) goto loc_824E942C;
	// addi r29,r30,512
	r29.s64 = r30.s64 + 512;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bge cr6,0x824e942c
	if (!cr6.lt) goto loc_824E942C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8ec8
	ctx.lr = 0x824E9410;
	sub_824E8EC8(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// blt cr6,0x824e9428
	if (cr6.lt) goto loc_824E9428;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x824e942c
	if (cr6.lt) goto loc_824E942C;
loc_824E9428:
	// li r11,0
	r11.s64 = 0;
loc_824E942C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// mr r31,r11
	r31.u64 = r11.u64;
	// bne 0x824e93f0
	if (!cr0.eq) goto loc_824E93F0;
loc_824E9438:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E943C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E9444"))) PPC_WEAK_FUNC(sub_824E9444);
PPC_FUNC_IMPL(__imp__sub_824E9444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9448"))) PPC_WEAK_FUNC(sub_824E9448);
PPC_FUNC_IMPL(__imp__sub_824E9448) {
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
	ctx.lr = 0x824E9450;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824e9038
	ctx.lr = 0x824E9460;
	sub_824E9038(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bge cr6,0x824e94e0
	if (!cr6.lt) goto loc_824E94E0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e94b4
	if (cr6.eq) goto loc_824E94B4;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r30,64
	cr6.compare<int32_t>(r30.s32, 64, xer);
	// bge cr6,0x824e94e0
	if (!cr6.lt) goto loc_824E94E0;
loc_824E9480:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e8e70
	ctx.lr = 0x824E9488;
	sub_824E8E70(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824e94e0
	if (!cr6.gt) goto loc_824E94E0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x824e94bc
	if (!cr6.gt) goto loc_824E94BC;
	// addi r4,r30,-1
	ctx.r4.s64 = r30.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824E94A4;
	sub_824E93A8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8fe0
	ctx.lr = 0x824E94B0;
	sub_824E8FE0(ctx, base);
	// b 0x824e94c0
	goto loc_824E94C0;
loc_824E94B4:
	// li r30,0
	r30.s64 = 0;
	// b 0x824e9480
	goto loc_824E9480;
loc_824E94BC:
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
loc_824E94C0:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e94e0
	if (cr6.eq) goto loc_824E94E0;
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E94E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E94EC"))) PPC_WEAK_FUNC(sub_824E94EC);
PPC_FUNC_IMPL(__imp__sub_824E94EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E94F0"))) PPC_WEAK_FUNC(sub_824E94F0);
PPC_FUNC_IMPL(__imp__sub_824E94F0) {
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
	// bl 0x824e93a8
	ctx.lr = 0x824E9500;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e951c
	if (cr6.eq) goto loc_824E951C;
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
loc_824E951C:
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
}

__attribute__((alias("__imp__sub_824E9530"))) PPC_WEAK_FUNC(sub_824E9530);
PPC_FUNC_IMPL(__imp__sub_824E9530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824E9538;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x824e93a8
	ctx.lr = 0x824E9554;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e95ec
	if (cr6.eq) goto loc_824E95EC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// rlwinm r10,r10,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// bgt cr6,0x824e95b4
	if (cr6.gt) goto loc_824E95B4;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-27256
	r12.s64 = r12.s64 + -27256;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_824E95A8;
	case 1:
		goto loc_824E95A8;
	case 2:
		goto loc_824E95B0;
	case 3:
		goto loc_824E95B0;
	case 4:
		goto loc_824E95B4;
	case 5:
		goto loc_824E95A8;
	case 6:
		goto loc_824E95B4;
	case 7:
		goto loc_824E95B0;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-27224(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27224);
	// lwz r18,-27224(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27224);
	// lwz r18,-27216(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27216);
	// lwz r18,-27216(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27216);
	// lwz r18,-27212(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27212);
	// lwz r18,-27224(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27224);
	// lwz r18,-27212(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27212);
	// lwz r18,-27216(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27216);
loc_824E95A8:
	// li r11,4
	r11.s64 = 4;
	// b 0x824e95b4
	goto loc_824E95B4;
loc_824E95B0:
	// li r11,8
	r11.s64 = 8;
loc_824E95B4:
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// bne cr6,0x824e95ec
	if (!cr6.eq) goto loc_824E95EC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bl 0x8244d5c0
	ctx.lr = 0x824E95CC;
	sub_8244D5C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// extsw r11,r30
	r11.s64 = r30.s32;
	// ld r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 4);
	// sld r10,r3,r11
	ctx.r10.u64 = r11.u8 & 0x40 ? 0 : (ctx.r3.u64 << (r11.u8 & 0x7F));
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// std r8,4(r31)
	PPC_STORE_U64(r31.u32 + 4, ctx.r8.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824E95EC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E95F8"))) PPC_WEAK_FUNC(sub_824E95F8);
PPC_FUNC_IMPL(__imp__sub_824E95F8) {
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
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824e9658
	if (cr6.lt) goto loc_824E9658;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e961c
	if (cr6.eq) goto loc_824E961C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e9620
	goto loc_824E9620;
loc_824E961C:
	// li r11,0
	r11.s64 = 0;
loc_824E9620:
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x824e9658
	if (!cr6.lt) goto loc_824E9658;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9638
	if (cr6.eq) goto loc_824E9638;
	// ld r11,4(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 4);
	// b 0x824e963c
	goto loc_824E963C;
loc_824E9638:
	// li r11,0
	r11.s64 = 0;
loc_824E963C:
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// li r9,1
	ctx.r9.s64 = 1;
	// sld r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & r11.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x824e965c
	if (cr6.eq) goto loc_824E965C;
loc_824E9658:
	// li r11,0
	r11.s64 = 0;
loc_824E965C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e9678
	if (!cr6.eq) goto loc_824E9678;
	// bl 0x824e93a8
	ctx.lr = 0x824E966C;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x824e967c
	if (!cr6.eq) goto loc_824E967C;
loc_824E9678:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824E967C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E968C"))) PPC_WEAK_FUNC(sub_824E968C);
PPC_FUNC_IMPL(__imp__sub_824E968C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9690"))) PPC_WEAK_FUNC(sub_824E9690);
PPC_FUNC_IMPL(__imp__sub_824E9690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x824E9698;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x824e93a8
	ctx.lr = 0x824E96AC;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9730
	if (cr6.eq) goto loc_824E9730;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// rlwinm r10,r10,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// bgt cr6,0x824e970c
	if (cr6.gt) goto loc_824E970C;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-26912
	r12.s64 = r12.s64 + -26912;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_824E9700;
	case 1:
		goto loc_824E9700;
	case 2:
		goto loc_824E9708;
	case 3:
		goto loc_824E9708;
	case 4:
		goto loc_824E970C;
	case 5:
		goto loc_824E9700;
	case 6:
		goto loc_824E970C;
	case 7:
		goto loc_824E9708;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-26880(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26880);
	// lwz r18,-26880(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26880);
	// lwz r18,-26872(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26872);
	// lwz r18,-26872(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26872);
	// lwz r18,-26868(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26868);
	// lwz r18,-26880(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26880);
	// lwz r18,-26868(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26868);
	// lwz r18,-26872(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26872);
loc_824E9700:
	// li r11,4
	r11.s64 = 4;
	// b 0x824e970c
	goto loc_824E970C;
loc_824E9708:
	// li r11,8
	r11.s64 = 8;
loc_824E970C:
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// bgt cr6,0x824e9730
	if (cr6.gt) goto loc_824E9730;
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824E9724;
	sub_8244D5C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824E9730:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E973C"))) PPC_WEAK_FUNC(sub_824E973C);
PPC_FUNC_IMPL(__imp__sub_824E973C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9740"))) PPC_WEAK_FUNC(sub_824E9740);
PPC_FUNC_IMPL(__imp__sub_824E9740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x824e93a8
	ctx.lr = 0x824E9750;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e97cc
	if (cr6.eq) goto loc_824E97CC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,-1
	ctx.r3.s64 = -1;
	// rlwinm r11,r11,4,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x824e97d0
	if (cr6.gt) goto loc_824E97D0;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-26748
	r12.s64 = r12.s64 + -26748;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E97A4;
	case 1:
		goto loc_824E97A4;
	case 2:
		goto loc_824E97B8;
	case 3:
		goto loc_824E97B8;
	case 4:
		goto loc_824E97D0;
	case 5:
		goto loc_824E97A4;
	case 6:
		goto loc_824E97D0;
	case 7:
		goto loc_824E97B8;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-26716(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26716);
	// lwz r18,-26716(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26716);
	// lwz r18,-26696(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26696);
	// lwz r18,-26696(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26696);
	// lwz r18,-26672(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26672);
	// lwz r18,-26716(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26716);
	// lwz r18,-26672(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26672);
	// lwz r18,-26696(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26696);
loc_824E97A4:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824E97B8:
	// li r3,8
	ctx.r3.s64 = 8;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824E97CC:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_824E97D0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E97E0"))) PPC_WEAK_FUNC(sub_824E97E0);
PPC_FUNC_IMPL(__imp__sub_824E97E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	ctx.lr = 0x824E97E8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e9808
	if (cr6.eq) goto loc_824E9808;
	// lwz r23,0(r28)
	r23.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x824e980c
	goto loc_824E980C;
loc_824E9808:
	// li r23,0
	r23.s64 = 0;
loc_824E980C:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x824e993c
	if (!cr6.gt) goto loc_824E993C;
	// li r26,0
	r26.s64 = 0;
	// li r24,1
	r24.s64 = 1;
	// li r22,-1
	r22.s64 = -1;
loc_824E9824:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x824e9870
	if (cr6.lt) goto loc_824E9870;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e983c
	if (cr6.eq) goto loc_824E983C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x824e9840
	goto loc_824E9840;
loc_824E983C:
	// li r11,0
	r11.s64 = 0;
loc_824E9840:
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x824e9870
	if (!cr6.lt) goto loc_824E9870;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e9858
	if (cr6.eq) goto loc_824E9858;
	// ld r11,4(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 4);
	// b 0x824e985c
	goto loc_824E985C;
loc_824E9858:
	// li r11,0
	r11.s64 = 0;
loc_824E985C:
	// sld r10,r24,r26
	ctx.r10.u64 = r26.u8 & 0x40 ? 0 : (r24.u64 << (r26.u8 & 0x7F));
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & r11.u64;
	// mr r11,r24
	r11.u64 = r24.u64;
	// cmpldi cr6,r9,0
	cr6.compare<uint64_t>(ctx.r9.u64, 0, xer);
	// beq cr6,0x824e9874
	if (cr6.eq) goto loc_824E9874;
loc_824E9870:
	// li r11,0
	r11.s64 = 0;
loc_824E9874:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e992c
	if (!cr6.eq) goto loc_824E992C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824E988C;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e989c
	if (cr6.eq) goto loc_824E989C;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e98a0
	goto loc_824E98A0;
loc_824E989C:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
loc_824E98A0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9038
	ctx.lr = 0x824E98A8;
	sub_824E9038(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824e992c
	if (cr6.lt) goto loc_824E992C;
	// rlwinm r11,r4,4,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xF;
	// li r31,-1
	r31.s64 = -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x824e9908
	if (cr6.gt) goto loc_824E9908;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-26404
	r12.s64 = r12.s64 + -26404;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E98FC;
	case 1:
		goto loc_824E98FC;
	case 2:
		goto loc_824E9904;
	case 3:
		goto loc_824E9904;
	case 4:
		goto loc_824E9908;
	case 5:
		goto loc_824E98FC;
	case 6:
		goto loc_824E9908;
	case 7:
		goto loc_824E9904;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-26372(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26372);
	// lwz r18,-26372(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26372);
	// lwz r18,-26364(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26364);
	// lwz r18,-26364(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26364);
	// lwz r18,-26360(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26360);
	// lwz r18,-26372(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26372);
	// lwz r18,-26360(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26360);
	// lwz r18,-26364(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26364);
loc_824E98FC:
	// li r31,4
	r31.s64 = 4;
	// b 0x824e9908
	goto loc_824E9908;
loc_824E9904:
	// li r31,8
	r31.s64 = 8;
loc_824E9908:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9914;
	sub_824E95F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x824e9530
	ctx.lr = 0x824E9928;
	sub_824E9530(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_824E992C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpw cr6,r29,r23
	cr6.compare<int32_t>(r29.s32, r23.s32, xer);
	// blt cr6,0x824e9824
	if (cr6.lt) goto loc_824E9824;
loc_824E993C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E9948"))) PPC_WEAK_FUNC(sub_824E9948);
PPC_FUNC_IMPL(__imp__sub_824E9948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	ctx.lr = 0x824E9950;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// li r23,0
	r23.s64 = 0;
	// bl 0x82618750
	ctx.lr = 0x824E9970;
	sub_82618750(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824E9980;
	sub_82618640(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e9990
	if (cr6.eq) goto loc_824E9990;
	// lwz r24,0(r27)
	r24.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// b 0x824e9994
	goto loc_824E9994;
loc_824E9990:
	// li r24,0
	r24.s64 = 0;
loc_824E9994:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9118
	ctx.lr = 0x824E999C;
	sub_824E9118(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824E99B0;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r26,1
	r26.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e99ec
	if (cr6.eq) goto loc_824E99EC;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82618390
	ctx.lr = 0x824E99DC;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E99E8;
	sub_826188B8(ctx, base);
	// mr r31,r26
	r31.u64 = r26.u64;
loc_824E99EC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c04
	if (cr6.eq) goto loc_824E9C04;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6390
	ctx.lr = 0x824E9A08;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c04
	if (cr6.eq) goto loc_824E9C04;
	// mr r23,r26
	r23.u64 = r26.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x824e9c04
	if (!cr6.gt) goto loc_824E9C04;
	// li r25,-1
	r25.s64 = -1;
loc_824E9A28:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x824e9a78
	if (cr6.lt) goto loc_824E9A78;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e9a40
	if (cr6.eq) goto loc_824E9A40;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// b 0x824e9a44
	goto loc_824E9A44;
loc_824E9A40:
	// li r11,0
	r11.s64 = 0;
loc_824E9A44:
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x824e9a78
	if (!cr6.lt) goto loc_824E9A78;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e9a5c
	if (cr6.eq) goto loc_824E9A5C;
	// ld r11,4(r27)
	r11.u64 = PPC_LOAD_U64(r27.u32 + 4);
	// b 0x824e9a60
	goto loc_824E9A60;
loc_824E9A5C:
	// li r11,0
	r11.s64 = 0;
loc_824E9A60:
	// extsw r10,r29
	ctx.r10.s64 = r29.s32;
	// sld r9,r26,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x40 ? 0 : (r26.u64 << (ctx.r10.u8 & 0x7F));
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & r11.u64;
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmpldi cr6,r8,0
	cr6.compare<uint64_t>(ctx.r8.u64, 0, xer);
	// beq cr6,0x824e9a7c
	if (cr6.eq) goto loc_824E9A7C;
loc_824E9A78:
	// li r11,0
	r11.s64 = 0;
loc_824E9A7C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// bl 0x824e93a8
	ctx.lr = 0x824E9A8C;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9a9c
	if (cr6.eq) goto loc_824E9A9C;
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e9aa0
	goto loc_824E9AA0;
loc_824E9A9C:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824E9AA0:
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824E9AB0;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9ae8
	if (cr6.eq) goto loc_824E9AE8;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82618390
	ctx.lr = 0x824E9AD8;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E9AE4;
	sub_826188B8(ctx, base);
	// mr r31,r26
	r31.u64 = r26.u64;
loc_824E9AE8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c00
	if (cr6.eq) goto loc_824E9C00;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618f70
	ctx.lr = 0x824E9B00;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c00
	if (cr6.eq) goto loc_824E9C00;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e9bf0
	if (!cr6.eq) goto loc_824E9BF0;
	// rlwinm r11,r30,4,28,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x824e9be4
	if (cr6.gt) goto loc_824E9BE4;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-25792
	r12.s64 = r12.s64 + -25792;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E9B60;
	case 1:
		goto loc_824E9B60;
	case 2:
		goto loc_824E9B84;
	case 3:
		goto loc_824E9BC8;
	case 4:
		goto loc_824E9BE4;
	case 5:
		goto loc_824E9BA8;
	case 6:
		goto loc_824E9BE4;
	case 7:
		goto loc_824E9B84;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-25760(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25760);
	// lwz r18,-25760(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25760);
	// lwz r18,-25724(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25724);
	// lwz r18,-25656(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25656);
	// lwz r18,-25628(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25628);
	// lwz r18,-25688(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25688);
	// lwz r18,-25628(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25628);
	// lwz r18,-25724(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25724);
loc_824E9B60:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9B6C;
	sub_824E95F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x824e6390
	ctx.lr = 0x824E9B80;
	sub_824E6390(ctx, base);
	// b 0x824e9be4
	goto loc_824E9BE4;
loc_824E9B84:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9B90;
	sub_824E95F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// bl 0x82618d38
	ctx.lr = 0x824E9BA4;
	sub_82618D38(ctx, base);
	// b 0x824e9be4
	goto loc_824E9BE4;
loc_824E9BA8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9BB4;
	sub_824E95F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82618df0
	ctx.lr = 0x824E9BC4;
	sub_82618DF0(ctx, base);
	// b 0x824e9be4
	goto loc_824E9BE4;
loc_824E9BC8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9BD4;
	sub_824E95F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfd f1,0(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// bl 0x82618e98
	ctx.lr = 0x824E9BE4;
	sub_82618E98(ctx, base);
loc_824E9BE4:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c00
	if (cr6.eq) goto loc_824E9C00;
loc_824E9BF0:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r24
	cr6.compare<int32_t>(r29.s32, r24.s32, xer);
	// blt cr6,0x824e9a28
	if (cr6.lt) goto loc_824E9A28;
	// b 0x824e9c04
	goto loc_824E9C04;
loc_824E9C00:
	// li r23,0
	r23.s64 = 0;
loc_824E9C04:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824e9c38
	if (cr6.eq) goto loc_824E9C38;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c30
	if (cr6.eq) goto loc_824E9C30;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824E9C20;
	sub_826186A0(ctx, base);
	// stw r3,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r3.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
loc_824E9C30:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r3.u32);
loc_824E9C38:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E9C44"))) PPC_WEAK_FUNC(sub_824E9C44);
PPC_FUNC_IMPL(__imp__sub_824E9C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9C48"))) PPC_WEAK_FUNC(sub_824E9C48);
PPC_FUNC_IMPL(__imp__sub_824E9C48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	ctx.lr = 0x824E9C50;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x82618750
	ctx.lr = 0x824E9C70;
	sub_82618750(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x826185e0
	ctx.lr = 0x824E9C80;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e9c90
	if (cr6.eq) goto loc_824E9C90;
	// li r11,0
	r11.s64 = 0;
	// std r11,4(r29)
	PPC_STORE_U64(r29.u32 + 4, r11.u64);
loc_824E9C90:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82257568
	ctx.lr = 0x824E9CA0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e74
	if (cr6.eq) goto loc_824E9E74;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,512
	cr6.compare<uint32_t>(r11.u32, 512, xer);
	// bgt cr6,0x824e9e74
	if (cr6.gt) goto loc_824E9E74;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82257568
	ctx.lr = 0x824E9CC8;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e74
	if (cr6.eq) goto loc_824E9E74;
	// lwz r28,84(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r28,64
	cr6.compare<uint32_t>(r28.u32, 64, xer);
	// bgt cr6,0x824e9e74
	if (cr6.gt) goto loc_824E9E74;
	// li r27,1
	r27.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x824e9e74
	if (!cr6.gt) goto loc_824E9E74;
loc_824E9CF0:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82257568
	ctx.lr = 0x824E9D00;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e70
	if (cr6.eq) goto loc_824E9E70;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618f10
	ctx.lr = 0x824E9D18;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e70
	if (cr6.eq) goto loc_824E9E70;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e8e58
	ctx.lr = 0x824E9D2C;
	sub_824E8E58(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x824e9d4c
	if (cr6.lt) goto loc_824E9D4C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9448
	ctx.lr = 0x824E9D44;
	sub_824E9448(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x824e9e70
	if (!cr6.eq) goto loc_824E9E70;
loc_824E9D4C:
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e9e60
	if (!cr6.eq) goto loc_824E9E60;
	// rlwinm r10,r31,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// bgt cr6,0x824e9e54
	if (cr6.gt) goto loc_824E9E54;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-25216
	r12.s64 = r12.s64 + -25216;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_824E9DA0;
	case 1:
		goto loc_824E9DA0;
	case 2:
		goto loc_824E9DC8;
	case 3:
		goto loc_824E9E10;
	case 4:
		goto loc_824E9E54;
	case 5:
		goto loc_824E9DEC;
	case 6:
		goto loc_824E9E54;
	case 7:
		goto loc_824E9DC8;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-25184(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25184);
	// lwz r18,-25184(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25184);
	// lwz r18,-25144(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25144);
	// lwz r18,-25072(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25072);
	// lwz r18,-25004(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25004);
	// lwz r18,-25108(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25108);
	// lwz r18,-25004(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25004);
	// lwz r18,-25144(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25144);
loc_824E9DA0:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82257568
	ctx.lr = 0x824E9DB0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e4c
	if (cr6.eq) goto loc_824E9E4C;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// b 0x824e9e30
	goto loc_824E9E30;
loc_824E9DC8:
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618c90
	ctx.lr = 0x824E9DD8;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e4c
	if (cr6.eq) goto loc_824E9E4C;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// b 0x824e9e2c
	goto loc_824E9E2C;
loc_824E9DEC:
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618db0
	ctx.lr = 0x824E9DF8;
	sub_82618DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e4c
	if (cr6.eq) goto loc_824E9E4C;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// b 0x824e9e30
	goto loc_824E9E30;
loc_824E9E10:
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618e20
	ctx.lr = 0x824E9E1C;
	sub_82618E20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e4c
	if (cr6.eq) goto loc_824E9E4C;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
loc_824E9E2C:
	// li r6,8
	ctx.r6.s64 = 8;
loc_824E9E30:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9530
	ctx.lr = 0x824E9E3C;
	sub_824E9530(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e9e50
	if (!cr6.eq) goto loc_824E9E50;
loc_824E9E4C:
	// li r11,0
	r11.s64 = 0;
loc_824E9E50:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_824E9E54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e70
	if (cr6.eq) goto loc_824E9E70;
loc_824E9E60:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x824e9cf0
	if (cr6.lt) goto loc_824E9CF0;
	// b 0x824e9e74
	goto loc_824E9E74;
loc_824E9E70:
	// li r27,0
	r27.s64 = 0;
loc_824E9E74:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e9ea8
	if (cr6.eq) goto loc_824E9EA8;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9ea0
	if (cr6.eq) goto loc_824E9EA0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x826186b0
	ctx.lr = 0x824E9E90;
	sub_826186B0(ctx, base);
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
loc_824E9EA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
loc_824E9EA8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E9EB4"))) PPC_WEAK_FUNC(sub_824E9EB4);
PPC_FUNC_IMPL(__imp__sub_824E9EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9EB8"))) PPC_WEAK_FUNC(sub_824E9EB8);
PPC_FUNC_IMPL(__imp__sub_824E9EB8) {
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
	// bl 0x824e93a8
	ctx.lr = 0x824E9EC8;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9efc
	if (cr6.eq) goto loc_824E9EFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000000;
	// addi r9,r10,0
	ctx.r9.s64 = ctx.r10.s64 + 0;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r3,r6,24
	ctx.r3.u64 = ctx.r6.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824E9EFC:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E9F14"))) PPC_WEAK_FUNC(sub_824E9F14);
PPC_FUNC_IMPL(__imp__sub_824E9F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9F18"))) PPC_WEAK_FUNC(sub_824E9F18);
PPC_FUNC_IMPL(__imp__sub_824E9F18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	ctx.lr = 0x824E9F20;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x824e9f88
	if (cr6.lt) goto loc_824E9F88;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e9f4c
	if (cr6.eq) goto loc_824E9F4C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x824e9f50
	goto loc_824E9F50;
loc_824E9F4C:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824E9F50:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x824e9f88
	if (!cr6.lt) goto loc_824E9F88;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e9f68
	if (cr6.eq) goto loc_824E9F68;
	// ld r11,4(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 4);
	// b 0x824e9f6c
	goto loc_824E9F6C;
loc_824E9F68:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824E9F6C:
	// extsw r10,r31
	ctx.r10.s64 = r31.s32;
	// li r9,1
	ctx.r9.s64 = 1;
	// sld r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & r11.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x824e9f8c
	if (cr6.eq) goto loc_824E9F8C;
loc_824E9F88:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824E9F8C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ea0a8
	if (!cr6.eq) goto loc_824EA0A8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824E9FA4;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9fc8
	if (cr6.eq) goto loc_824E9FC8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000000;
	// subf r9,r28,r10
	ctx.r9.s64 = ctx.r10.s64 - r28.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// b 0x824e9fcc
	goto loc_824E9FCC;
loc_824E9FC8:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824E9FCC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ea0a8
	if (cr6.eq) goto loc_824EA0A8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r31,1
	r31.s64 = 1;
	// bl 0x824e93a8
	ctx.lr = 0x824E9FE8;
	sub_824E93A8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r10,r8,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xF;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stb r10,8(r30)
	PPC_STORE_U8(r30.u32 + 8, ctx.r10.u8);
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r9,6
	cr6.compare<uint32_t>(ctx.r9.u32, 6, xer);
	// bgt cr6,0x824ea0a8
	if (cr6.gt) goto loc_824EA0A8;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-24544
	r12.s64 = r12.s64 + -24544;
	// rlwinm r0,r9,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r9.u64) {
	case 0:
		goto loc_824EA03C;
	case 1:
		goto loc_824EA050;
	case 2:
		goto loc_824EA078;
	case 3:
		goto loc_824EA0A8;
	case 4:
		goto loc_824EA064;
	case 5:
		goto loc_824EA0A8;
	case 6:
		goto loc_824EA08C;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-24516(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24516);
	// lwz r18,-24496(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24496);
	// lwz r18,-24456(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24456);
	// lwz r18,-24408(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24408);
	// lwz r18,-24476(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24476);
	// lwz r18,-24408(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24408);
	// lwz r18,-24436(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24436);
loc_824EA03C:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA050:
	// ld r11,4(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r11,16(r30)
	PPC_STORE_U64(r30.u32 + 16, r11.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA064:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,16(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA078:
	// lfd f0,4(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfd f0,16(r30)
	PPC_STORE_U64(r30.u32 + 16, f0.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA08C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r10.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA0A8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EA0B4"))) PPC_WEAK_FUNC(sub_824EA0B4);
PPC_FUNC_IMPL(__imp__sub_824EA0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA0B8"))) PPC_WEAK_FUNC(sub_824EA0B8);
PPC_FUNC_IMPL(__imp__sub_824EA0B8) {
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
	ctx.lr = 0x824EA0C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x824ea128
	if (cr6.lt) goto loc_824EA128;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ea0ec
	if (cr6.eq) goto loc_824EA0EC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x824ea0f0
	goto loc_824EA0F0;
loc_824EA0EC:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EA0F0:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x824ea128
	if (!cr6.lt) goto loc_824EA128;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ea108
	if (cr6.eq) goto loc_824EA108;
	// ld r11,4(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 4);
	// b 0x824ea10c
	goto loc_824EA10C;
loc_824EA108:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EA10C:
	// extsw r10,r31
	ctx.r10.s64 = r31.s32;
	// li r9,1
	ctx.r9.s64 = 1;
	// sld r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & r11.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x824ea12c
	if (cr6.eq) goto loc_824EA12C;
loc_824EA128:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EA12C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ea1a4
	if (!cr6.eq) goto loc_824EA1A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824EA144;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea164
	if (cr6.eq) goto loc_824EA164;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000000;
	// subf r9,r28,r10
	ctx.r9.s64 = ctx.r10.s64 - r28.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// b 0x824ea168
	goto loc_824EA168;
loc_824EA164:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EA168:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ea1a4
	if (cr6.eq) goto loc_824EA1A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r31,1
	r31.s64 = 1;
	// bl 0x824e93a8
	ctx.lr = 0x824EA184;
	sub_824E93A8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA1A4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EA1B0"))) PPC_WEAK_FUNC(sub_824EA1B0);
PPC_FUNC_IMPL(__imp__sub_824EA1B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	ctx.lr = 0x824EA1B8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r25,0
	r25.s64 = 0;
	// lbz r11,512(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 512);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ea1e4
	if (cr6.eq) goto loc_824EA1E4;
	// bl 0x824e97e0
	ctx.lr = 0x824EA1DC;
	sub_824E97E0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_824EA1E4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ea1f4
	if (cr6.eq) goto loc_824EA1F4;
	// lwz r23,0(r28)
	r23.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x824ea1f8
	goto loc_824EA1F8;
loc_824EA1F4:
	// li r23,0
	r23.s64 = 0;
loc_824EA1F8:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x824ea340
	if (!cr6.gt) goto loc_824EA340;
	// li r26,0
	r26.s64 = 0;
	// li r22,-1
	r22.s64 = -1;
	// li r24,1
	r24.s64 = 1;
loc_824EA210:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824EA21C;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea22c
	if (cr6.eq) goto loc_824EA22C;
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824ea230
	goto loc_824EA230;
loc_824EA22C:
	// mr r31,r22
	r31.u64 = r22.u64;
loc_824EA230:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9038
	ctx.lr = 0x824EA23C;
	sub_824E9038(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x824ea254
	if (!cr6.lt) goto loc_824EA254;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9448
	ctx.lr = 0x824EA250;
	sub_824E9448(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_824EA254:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x824ea2a0
	if (cr6.lt) goto loc_824EA2A0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ea26c
	if (cr6.eq) goto loc_824EA26C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x824ea270
	goto loc_824EA270;
loc_824EA26C:
	// li r11,0
	r11.s64 = 0;
loc_824EA270:
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x824ea2a0
	if (!cr6.lt) goto loc_824EA2A0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ea288
	if (cr6.eq) goto loc_824EA288;
	// ld r11,4(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 4);
	// b 0x824ea28c
	goto loc_824EA28C;
loc_824EA288:
	// li r11,0
	r11.s64 = 0;
loc_824EA28C:
	// sld r10,r24,r26
	ctx.r10.u64 = r26.u8 & 0x40 ? 0 : (r24.u64 << (r26.u8 & 0x7F));
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & r11.u64;
	// mr r11,r24
	r11.u64 = r24.u64;
	// cmpldi cr6,r9,0
	cr6.compare<uint64_t>(ctx.r9.u64, 0, xer);
	// beq cr6,0x824ea2a4
	if (cr6.eq) goto loc_824EA2A4;
loc_824EA2A0:
	// li r11,0
	r11.s64 = 0;
loc_824EA2A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ea330
	if (!cr6.eq) goto loc_824EA330;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824ea330
	if (cr6.lt) goto loc_824EA330;
	// rlwinm r11,r31,4,28,31
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xF;
	// li r31,-1
	r31.s64 = -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x824ea30c
	if (cr6.gt) goto loc_824EA30C;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-23840
	r12.s64 = r12.s64 + -23840;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824EA300;
	case 1:
		goto loc_824EA300;
	case 2:
		goto loc_824EA308;
	case 3:
		goto loc_824EA308;
	case 4:
		goto loc_824EA30C;
	case 5:
		goto loc_824EA300;
	case 6:
		goto loc_824EA30C;
	case 7:
		goto loc_824EA308;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-23808(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23808);
	// lwz r18,-23808(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23808);
	// lwz r18,-23800(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23800);
	// lwz r18,-23800(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23800);
	// lwz r18,-23796(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23796);
	// lwz r18,-23808(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23808);
	// lwz r18,-23796(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23796);
	// lwz r18,-23800(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23800);
loc_824EA300:
	// li r31,4
	r31.s64 = 4;
	// b 0x824ea30c
	goto loc_824EA30C;
loc_824EA308:
	// li r31,8
	r31.s64 = 8;
loc_824EA30C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824EA318;
	sub_824E95F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x824e9530
	ctx.lr = 0x824EA32C;
	sub_824E9530(ctx, base);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
loc_824EA330:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpw cr6,r29,r23
	cr6.compare<int32_t>(r29.s32, r23.s32, xer);
	// blt cr6,0x824ea210
	if (cr6.lt) goto loc_824EA210;
loc_824EA340:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824EA34C"))) PPC_WEAK_FUNC(sub_824EA34C);
PPC_FUNC_IMPL(__imp__sub_824EA34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA350"))) PPC_WEAK_FUNC(sub_824EA350);
PPC_FUNC_IMPL(__imp__sub_824EA350) {
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
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// beq cr6,0x824ea39c
	if (cr6.eq) goto loc_824EA39C;
	// lbz r11,512(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 512);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ea390
	if (!cr6.eq) goto loc_824EA390;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x824EA390;
	sub_8244D150(ctx, base);
loc_824EA390:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ea1b0
	ctx.lr = 0x824EA39C;
	sub_824EA1B0(ctx, base);
loc_824EA39C:
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

__attribute__((alias("__imp__sub_824EA3B8"))) PPC_WEAK_FUNC(sub_824EA3B8);
PPC_FUNC_IMPL(__imp__sub_824EA3B8) {
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
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// lbz r11,512(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 512);
	// clrlwi r11,r11,25
	r11.u64 = r11.u32 & 0x7F;
	// stb r11,512(r31)
	PPC_STORE_U8(r31.u32 + 512, r11.u8);
	// beq cr6,0x824ea40c
	if (cr6.eq) goto loc_824EA40C;
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ea400
	if (!cr6.eq) goto loc_824EA400;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x824EA400;
	sub_8244D150(ctx, base);
loc_824EA400:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ea1b0
	ctx.lr = 0x824EA40C;
	sub_824EA1B0(ctx, base);
loc_824EA40C:
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

__attribute__((alias("__imp__sub_824EA428"))) PPC_WEAK_FUNC(sub_824EA428);
PPC_FUNC_IMPL(__imp__sub_824EA428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA438"))) PPC_WEAK_FUNC(sub_824EA438);
PPC_FUNC_IMPL(__imp__sub_824EA438) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r3,21380(r9)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + 21380);
	// lbz r8,30436(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 30436);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplw cr6,r7,r8
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r3,30436(r11)
	PPC_STORE_U8(r11.u32 + 30436, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA45C"))) PPC_WEAK_FUNC(sub_824EA45C);
PPC_FUNC_IMPL(__imp__sub_824EA45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA460"))) PPC_WEAK_FUNC(sub_824EA460);
PPC_FUNC_IMPL(__imp__sub_824EA460) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwimi r10,r3,7,0,24
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r3.u32, 7) & 0xFFFFFF80) | (ctx.r10.u64 & 0xFFFFFFFF0000007F);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA488"))) PPC_WEAK_FUNC(sub_824EA488);
PPC_FUNC_IMPL(__imp__sub_824EA488) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,21380(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// lbz r9,30436(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 30436);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// beq cr6,0x824ea4bc
	if (cr6.eq) goto loc_824EA4BC;
	// stb r11,30436(r10)
	PPC_STORE_U8(ctx.r10.u32 + 30436, r11.u8);
loc_824EA4BC:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824ea4e4
	if (!cr6.eq) goto loc_824EA4E4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x824f92f0
	ctx.lr = 0x824EA4CC;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82131c28
	ctx.lr = 0x824EA4D8;
	sub_82131C28(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ea4e8
	if (cr6.eq) goto loc_824EA4E8;
loc_824EA4E4:
	// li r11,0
	r11.s64 = 0;
loc_824EA4E8:
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

__attribute__((alias("__imp__sub_824EA500"))) PPC_WEAK_FUNC(sub_824EA500);
PPC_FUNC_IMPL(__imp__sub_824EA500) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,21380(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// lbz r9,30436(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 30436);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// beq cr6,0x824ea534
	if (cr6.eq) goto loc_824EA534;
	// stb r11,30436(r10)
	PPC_STORE_U8(ctx.r10.u32 + 30436, r11.u8);
loc_824EA534:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824ea55c
	if (!cr6.eq) goto loc_824EA55C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x824f92f0
	ctx.lr = 0x824EA544;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82131c38
	ctx.lr = 0x824EA550;
	sub_82131C38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ea560
	if (cr6.eq) goto loc_824EA560;
loc_824EA55C:
	// li r11,0
	r11.s64 = 0;
loc_824EA560:
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

__attribute__((alias("__imp__sub_824EA578"))) PPC_WEAK_FUNC(sub_824EA578);
PPC_FUNC_IMPL(__imp__sub_824EA578) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r11,r8,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lbz r11,21380(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// lbz r9,30436(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 30436);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// cmplw cr6,r7,r9
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, xer);
	// beq cr6,0x824ea5a8
	if (cr6.eq) goto loc_824EA5A8;
	// stb r11,30436(r10)
	PPC_STORE_U8(ctx.r10.u32 + 30436, r11.u8);
loc_824EA5A8:
	// clrlwi r11,r8,25
	r11.u64 = ctx.r8.u32 & 0x7F;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA5B4"))) PPC_WEAK_FUNC(sub_824EA5B4);
PPC_FUNC_IMPL(__imp__sub_824EA5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA5B8"))) PPC_WEAK_FUNC(sub_824EA5B8);
PPC_FUNC_IMPL(__imp__sub_824EA5B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,32724
	ctx.r10.s64 = r11.s64 + 32724;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA5C8"))) PPC_WEAK_FUNC(sub_824EA5C8);
PPC_FUNC_IMPL(__imp__sub_824EA5C8) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,26932
	ctx.r10.s64 = r11.s64 + 26932;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ea61c
	if (cr6.eq) goto loc_824EA61C;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea61c
	if (cr6.eq) goto loc_824EA61C;
	// addi r11,r31,52
	r11.s64 = r31.s64 + 52;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x824ea61c
	if (cr6.eq) goto loc_824EA61C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EA61C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824EA61C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82530228
	ctx.lr = 0x824EA624;
	sub_82530228(ctx, base);
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

__attribute__((alias("__imp__sub_824EA638"))) PPC_WEAK_FUNC(sub_824EA638);
PPC_FUNC_IMPL(__imp__sub_824EA638) {
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
	// bl 0x824ea5c8
	ctx.lr = 0x824EA658;
	sub_824EA5C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ea670
	if (cr6.eq) goto loc_824EA670;
	// bl 0x82130588
	ctx.lr = 0x824EA66C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824EA670:
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

__attribute__((alias("__imp__sub_824EA688"))) PPC_WEAK_FUNC(sub_824EA688);
PPC_FUNC_IMPL(__imp__sub_824EA688) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r10,r11,-32716
	ctx.r10.s64 = r11.s64 + -32716;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA698"))) PPC_WEAK_FUNC(sub_824EA698);
PPC_FUNC_IMPL(__imp__sub_824EA698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,32692
	ctx.r10.s64 = r11.s64 + 32692;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA6A8"))) PPC_WEAK_FUNC(sub_824EA6A8);
PPC_FUNC_IMPL(__imp__sub_824EA6A8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824EA6B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// bl 0x825301e0
	ctx.lr = 0x824EA6D4;
	sub_825301E0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r10,212(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r11,26968
	ctx.r9.s64 = r11.s64 + 26968;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// stw r29,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r29.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// sth r27,52(r31)
	PPC_STORE_U16(r31.u32 + 52, r27.u16);
	// stw r7,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824EA710"))) PPC_WEAK_FUNC(sub_824EA710);
PPC_FUNC_IMPL(__imp__sub_824EA710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,32596
	ctx.r10.s64 = r11.s64 + 32596;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA720"))) PPC_WEAK_FUNC(sub_824EA720);
PPC_FUNC_IMPL(__imp__sub_824EA720) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,26968
	ctx.r10.s64 = r11.s64 + 26968;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ea774
	if (cr6.eq) goto loc_824EA774;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea774
	if (cr6.eq) goto loc_824EA774;
	// addi r11,r31,56
	r11.s64 = r31.s64 + 56;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x824ea774
	if (cr6.eq) goto loc_824EA774;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EA774;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824EA774:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82530228
	ctx.lr = 0x824EA77C;
	sub_82530228(ctx, base);
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

__attribute__((alias("__imp__sub_824EA790"))) PPC_WEAK_FUNC(sub_824EA790);
PPC_FUNC_IMPL(__imp__sub_824EA790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r10,r11,-32684
	ctx.r10.s64 = r11.s64 + -32684;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA7A0"))) PPC_WEAK_FUNC(sub_824EA7A0);
PPC_FUNC_IMPL(__imp__sub_824EA7A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r10,r11,-32748
	ctx.r10.s64 = r11.s64 + -32748;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA7B0"))) PPC_WEAK_FUNC(sub_824EA7B0);
PPC_FUNC_IMPL(__imp__sub_824EA7B0) {
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
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ea7f8
	if (!cr6.eq) goto loc_824EA7F8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwimi r11,r10,7,0,24
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821c90c0
	ctx.lr = 0x824EA7E8;
	sub_821C90C0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821c9168
	ctx.lr = 0x824EA7F0;
	sub_821C9168(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821c9158
	ctx.lr = 0x824EA7F8;
	sub_821C9158(ctx, base);
loc_824EA7F8:
	// lbz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// rlwinm r8,r8,0,26,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r8,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_824EA834"))) PPC_WEAK_FUNC(sub_824EA834);
PPC_FUNC_IMPL(__imp__sub_824EA834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA838"))) PPC_WEAK_FUNC(sub_824EA838);
PPC_FUNC_IMPL(__imp__sub_824EA838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea84c
	if (cr6.eq) goto loc_824EA84C;
	// b 0x823eaef8
	sub_823EAEF8(ctx, base);
	return;
loc_824EA84C:
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA854"))) PPC_WEAK_FUNC(sub_824EA854);
PPC_FUNC_IMPL(__imp__sub_824EA854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA858"))) PPC_WEAK_FUNC(sub_824EA858);
PPC_FUNC_IMPL(__imp__sub_824EA858) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,1336(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1336);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// rlwimi r11,r10,6,25,25
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r11,1336(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1336, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA86C"))) PPC_WEAK_FUNC(sub_824EA86C);
PPC_FUNC_IMPL(__imp__sub_824EA86C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA870"))) PPC_WEAK_FUNC(sub_824EA870);
PPC_FUNC_IMPL(__imp__sub_824EA870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,1336(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1336);
	// rlwinm r3,r11,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA87C"))) PPC_WEAK_FUNC(sub_824EA87C);
PPC_FUNC_IMPL(__imp__sub_824EA87C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA880"))) PPC_WEAK_FUNC(sub_824EA880);
PPC_FUNC_IMPL(__imp__sub_824EA880) {
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
	ctx.lr = 0x824EA888;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EA8A4;
	sub_821C8FE0(ctx, base);
	// mulli r11,r30,68
	r11.s64 = r30.s64 * 68;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,192(r11)
	PPC_STORE_U32(r11.u32 + 192, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mulli r8,r9,1000
	ctx.r8.s64 = ctx.r9.s64 * 1000;
	// stw r8,188(r11)
	PPC_STORE_U32(r11.u32 + 188, ctx.r8.u32);
	// bl 0x821c9030
	ctx.lr = 0x824EA8C8;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EA8D0"))) PPC_WEAK_FUNC(sub_824EA8D0);
PPC_FUNC_IMPL(__imp__sub_824EA8D0) {
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
	ctx.lr = 0x824EA8D8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,1292
	r30.s64 = r31.s64 + 1292;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EA8F4;
	sub_821C8FE0(ctx, base);
	// addi r31,r31,196
	r31.s64 = r31.s64 + 196;
	// li r28,16
	r28.s64 = 16;
loc_824EA8FC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EA908;
	sub_821C8FE0(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824EA918:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824ea918
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824EA918;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EA934;
	sub_821C9030(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,68
	r31.s64 = r31.s64 + 68;
	// bne 0x824ea8fc
	if (!cr0.eq) goto loc_824EA8FC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824EA948;
	sub_821C9030(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EA950"))) PPC_WEAK_FUNC(sub_824EA950);
PPC_FUNC_IMPL(__imp__sub_824EA950) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824EA958;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x82533f20
	ctx.lr = 0x824EA970;
	sub_82533F20(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533fc0
	ctx.lr = 0x824EA97C;
	sub_82533FC0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r29,-3
	ctx.r4.s64 = r29.s64 + -3;
	// addi r3,r30,3
	ctx.r3.s64 = r30.s64 + 3;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x821d2e28
	ctx.lr = 0x824EA990;
	sub_821D2E28(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824ea9c0
	if (cr6.eq) goto loc_824EA9C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533f58
	ctx.lr = 0x824EA9A4;
	sub_82533F58(ctx, base);
	// rlwinm r5,r3,0,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFE;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82533e98
	ctx.lr = 0x824EA9B4;
	sub_82533E98(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA9C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EA9CC"))) PPC_WEAK_FUNC(sub_824EA9CC);
PPC_FUNC_IMPL(__imp__sub_824EA9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA9D0"))) PPC_WEAK_FUNC(sub_824EA9D0);
PPC_FUNC_IMPL(__imp__sub_824EA9D0) {
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
	ctx.lr = 0x824EA9D8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x82533ef0
	ctx.lr = 0x824EA9F4;
	sub_82533EF0(ctx, base);
	// add r29,r3,r31
	r29.u64 = ctx.r3.u64 + r31.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r29,3
	cr6.compare<uint32_t>(r29.u32, 3, xer);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ble cr6,0x824eaaf8
	if (!cr6.gt) goto loc_824EAAF8;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824eaa4c
	if (cr6.eq) goto loc_824EAA4C;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824f8db8
	ctx.lr = 0x824EAA28;
	sub_824F8DB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eaaf4
	if (!cr6.eq) goto loc_824EAAF4;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x824eaaf8
	if (!cr6.eq) goto loc_824EAAF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824EAA4C:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824eaa90
	if (cr6.eq) goto loc_824EAA90;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82533c68
	ctx.lr = 0x824EAA6C;
	sub_82533C68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eaaf4
	if (!cr6.eq) goto loc_824EAAF4;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x824eaaf8
	if (!cr6.eq) goto loc_824EAAF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824EAA90:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EAAB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eab00
	if (cr6.eq) goto loc_824EAB00;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// bl 0x8244d5c0
	ctx.lr = 0x824EAAE8;
	sub_8244D5C0(ctx, base);
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// stw r31,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r31.u32);
loc_824EAAF4:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_824EAAF8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824EAB00:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824EAB0C"))) PPC_WEAK_FUNC(sub_824EAB0C);
PPC_FUNC_IMPL(__imp__sub_824EAB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EAB10"))) PPC_WEAK_FUNC(sub_824EAB10);
PPC_FUNC_IMPL(__imp__sub_824EAB10) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824EAB18;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r5,20(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// srw. r30,r11,r5
	r30.u64 = ctx.r5.u8 & 0x20 ? 0 : (r11.u32 >> (ctx.r5.u8 & 0x3F));
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x824eab94
	if (cr0.eq) goto loc_824EAB94;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// li r31,148
	r31.s64 = 148;
loc_824EAB3C:
	// lwz r7,0(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplw cr6,r4,r7
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, xer);
	// blt cr6,0x824eab7c
	if (cr6.lt) goto loc_824EAB7C;
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// mulli r11,r11,148
	r11.s64 = r11.s64 * 148;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bge cr6,0x824eab7c
	if (!cr6.lt) goto loc_824EAB7C;
	// subf r10,r7,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r7.s64;
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// slw r11,r8,r5
	r11.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r5.u8 & 0x3F));
	// divw r10,r10,r31
	ctx.r10.s32 = ctx.r10.s32 / r31.s32;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r29,r7
	cr6.compare<uint32_t>(r29.u32, ctx.r7.u32, xer);
	// blt cr6,0x824eab90
	if (cr6.lt) goto loc_824EAB90;
loc_824EAB7C:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// blt cr6,0x824eab3c
	if (cr6.lt) goto loc_824EAB3C;
	// b 0x823d924c
	return;
loc_824EAB90:
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
loc_824EAB94:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EAB98"))) PPC_WEAK_FUNC(sub_824EAB98);
PPC_FUNC_IMPL(__imp__sub_824EAB98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824eabdc
	if (!cr6.eq) goto loc_824EABDC;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eabd0
	if (cr6.eq) goto loc_824EABD0;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824eac14
	if (!cr6.eq) goto loc_824EAC14;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eac14
	goto loc_824EAC14;
loc_824EABD0:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eac14
	goto loc_824EAC14;
loc_824EABDC:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824eabfc
	if (!cr6.eq) goto loc_824EABFC;
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eac14
	goto loc_824EAC14;
loc_824EABFC:
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lwz r10,8(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stw r6,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r6.u32);
loc_824EAC14:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EAC2C"))) PPC_WEAK_FUNC(sub_824EAC2C);
PPC_FUNC_IMPL(__imp__sub_824EAC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EAC30"))) PPC_WEAK_FUNC(sub_824EAC30);
PPC_FUNC_IMPL(__imp__sub_824EAC30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824eac74
	if (!cr6.eq) goto loc_824EAC74;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eac68
	if (cr6.eq) goto loc_824EAC68;
	// stw r6,128(r11)
	PPC_STORE_U32(r11.u32 + 128, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,132(r6)
	PPC_STORE_U32(ctx.r6.u32 + 132, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824eacac
	if (!cr6.eq) goto loc_824EACAC;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eacac
	goto loc_824EACAC;
loc_824EAC68:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eacac
	goto loc_824EACAC;
loc_824EAC74:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824eac94
	if (!cr6.eq) goto loc_824EAC94;
	// stw r11,128(r6)
	PPC_STORE_U32(ctx.r6.u32 + 128, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,132(r11)
	PPC_STORE_U32(r11.u32 + 132, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eacac
	goto loc_824EACAC;
loc_824EAC94:
	// stw r5,128(r6)
	PPC_STORE_U32(ctx.r6.u32 + 128, ctx.r5.u32);
	// lwz r11,132(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 132);
	// stw r11,132(r6)
	PPC_STORE_U32(ctx.r6.u32 + 132, r11.u32);
	// lwz r10,132(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 132);
	// stw r6,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, ctx.r6.u32);
	// stw r6,132(r5)
	PPC_STORE_U32(ctx.r5.u32 + 132, ctx.r6.u32);
loc_824EACAC:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EACC4"))) PPC_WEAK_FUNC(sub_824EACC4);
PPC_FUNC_IMPL(__imp__sub_824EACC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EACC8"))) PPC_WEAK_FUNC(sub_824EACC8);
PPC_FUNC_IMPL(__imp__sub_824EACC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824ead0c
	if (!cr6.eq) goto loc_824EAD0C;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ead00
	if (cr6.eq) goto loc_824EAD00;
	// stw r6,124(r11)
	PPC_STORE_U32(r11.u32 + 124, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,128(r6)
	PPC_STORE_U32(ctx.r6.u32 + 128, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824ead44
	if (!cr6.eq) goto loc_824EAD44;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824ead44
	goto loc_824EAD44;
loc_824EAD00:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824ead44
	goto loc_824EAD44;
loc_824EAD0C:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824ead2c
	if (!cr6.eq) goto loc_824EAD2C;
	// stw r11,124(r6)
	PPC_STORE_U32(ctx.r6.u32 + 124, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,128(r11)
	PPC_STORE_U32(r11.u32 + 128, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824ead44
	goto loc_824EAD44;
loc_824EAD2C:
	// stw r5,124(r6)
	PPC_STORE_U32(ctx.r6.u32 + 124, ctx.r5.u32);
	// lwz r11,128(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// stw r11,128(r6)
	PPC_STORE_U32(ctx.r6.u32 + 128, r11.u32);
	// lwz r10,128(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// stw r6,124(r10)
	PPC_STORE_U32(ctx.r10.u32 + 124, ctx.r6.u32);
	// stw r6,128(r5)
	PPC_STORE_U32(ctx.r5.u32 + 128, ctx.r6.u32);
loc_824EAD44:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EAD5C"))) PPC_WEAK_FUNC(sub_824EAD5C);
PPC_FUNC_IMPL(__imp__sub_824EAD5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EAD60"))) PPC_WEAK_FUNC(sub_824EAD60);
PPC_FUNC_IMPL(__imp__sub_824EAD60) {
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
	// bl 0x82530228
	ctx.lr = 0x824EAD80;
	sub_82530228(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ead98
	if (cr6.eq) goto loc_824EAD98;
	// bl 0x82130588
	ctx.lr = 0x824EAD94;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824EAD98:
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

__attribute__((alias("__imp__sub_824EADB0"))) PPC_WEAK_FUNC(sub_824EADB0);
PPC_FUNC_IMPL(__imp__sub_824EADB0) {
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
	// bl 0x825337a8
	ctx.lr = 0x824EADD0;
	sub_825337A8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eade8
	if (cr6.eq) goto loc_824EADE8;
	// bl 0x82130588
	ctx.lr = 0x824EADE4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824EADE8:
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

__attribute__((alias("__imp__sub_824EAE00"))) PPC_WEAK_FUNC(sub_824EAE00);
PPC_FUNC_IMPL(__imp__sub_824EAE00) {
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
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824eae34
	if (!cr6.eq) goto loc_824EAE34;
	// bl 0x8218f5b0
	ctx.lr = 0x824EAE28;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824eae38
	if (cr6.eq) goto loc_824EAE38;
loc_824EAE34:
	// li r11,0
	r11.s64 = 0;
loc_824EAE38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eae50
	if (cr6.eq) goto loc_824EAE50;
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,144(r31)
	PPC_STORE_U8(r31.u32 + 144, ctx.r10.u8);
loc_824EAE50:
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

__attribute__((alias("__imp__sub_824EAE64"))) PPC_WEAK_FUNC(sub_824EAE64);
PPC_FUNC_IMPL(__imp__sub_824EAE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EAE68"))) PPC_WEAK_FUNC(sub_824EAE68);
PPC_FUNC_IMPL(__imp__sub_824EAE68) {
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
	// bl 0x825303e8
	ctx.lr = 0x824EAE88;
	sub_825303E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eaec8
	if (!cr6.eq) goto loc_824EAEC8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825305b0
	ctx.lr = 0x824EAE9C;
	sub_825305B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824eaec4
	if (cr6.eq) goto loc_824EAEC4;
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eaec8
	if (cr6.eq) goto loc_824EAEC8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82531b80
	ctx.lr = 0x824EAEBC;
	sub_82531B80(ctx, base);
	// cmplwi cr6,r3,20
	cr6.compare<uint32_t>(ctx.r3.u32, 20, xer);
	// ble cr6,0x824eaec8
	if (!cr6.gt) goto loc_824EAEC8;
loc_824EAEC4:
	// li r30,1
	r30.s64 = 1;
loc_824EAEC8:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eaee8
	if (!cr6.eq) goto loc_824EAEE8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263b728
	ctx.lr = 0x824EAEDC;
	sub_8263B728(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x824eaeec
	if (cr6.eq) goto loc_824EAEEC;
loc_824EAEE8:
	// li r11,1
	r11.s64 = 1;
loc_824EAEEC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824EAF08"))) PPC_WEAK_FUNC(sub_824EAF08);
PPC_FUNC_IMPL(__imp__sub_824EAF08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x824EAF10;
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// bl 0x82533fc0
	ctx.lr = 0x824EAF30;
	sub_82533FC0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82533fc8
	ctx.lr = 0x824EAF50;
	sub_82533FC8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eaf6c
	if (cr6.eq) goto loc_824EAF6C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534248
	ctx.lr = 0x824EAF60;
	sub_82534248(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EAF6C;
	sub_8244D5C0(ctx, base);
loc_824EAF6C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534318
	ctx.lr = 0x824EAF74;
	sub_82534318(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82533e98
	ctx.lr = 0x824EAF84;
	sub_82533E98(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824ea9d0
	ctx.lr = 0x824EAF98;
	sub_824EA9D0(ctx, base);
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824EAFA0"))) PPC_WEAK_FUNC(sub_824EAFA0);
PPC_FUNC_IMPL(__imp__sub_824EAFA0) {
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
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EAFC8;
	sub_821C8FE0(ctx, base);
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824eb01c
	if (cr6.lt) goto loc_824EB01C;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x824eb01c
	if (!cr6.lt) goto loc_824EB01C;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// srw r8,r11,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (r11.u32 >> (ctx.r10.u8 & 0x3F));
	// lwz r7,108(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// and r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 & r11.u64;
	// mulli r10,r5,148
	ctx.r10.s64 = ctx.r5.s64 * 148;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eb01c
	if (cr6.eq) goto loc_824EB01C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EB014;
	sub_82656BF8(ctx, base);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// beq cr6,0x824eb020
	if (cr6.eq) goto loc_824EB020;
loc_824EB01C:
	// li r31,0
	r31.s64 = 0;
loc_824EB020:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EB028;
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

__attribute__((alias("__imp__sub_824EB044"))) PPC_WEAK_FUNC(sub_824EB044);
PPC_FUNC_IMPL(__imp__sub_824EB044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB048"))) PPC_WEAK_FUNC(sub_824EB048);
PPC_FUNC_IMPL(__imp__sub_824EB048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb098
	if (!cr6.eq) goto loc_824EB098;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb084
	if (cr6.eq) goto loc_824EB084;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB084:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB098:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb0d4
	if (!cr6.eq) goto loc_824EB0D4;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb0f8
	if (cr6.eq) goto loc_824EB0F8;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB0D4:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r7,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
loc_824EB0F8:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB108"))) PPC_WEAK_FUNC(sub_824EB108);
PPC_FUNC_IMPL(__imp__sub_824EB108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb158
	if (!cr6.eq) goto loc_824EB158;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,128(r4)
	PPC_STORE_U32(ctx.r4.u32 + 128, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb144
	if (cr6.eq) goto loc_824EB144;
	// stw r11,132(r10)
	PPC_STORE_U32(ctx.r10.u32 + 132, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB144:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB158:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb194
	if (!cr6.eq) goto loc_824EB194;
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,132(r4)
	PPC_STORE_U32(ctx.r4.u32 + 132, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb1b8
	if (cr6.eq) goto loc_824EB1B8;
	// stw r11,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB194:
	// lwz r10,132(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 132);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,128(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// stw r9,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, ctx.r9.u32);
	// lwz r8,128(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lwz r7,132(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 132);
	// stw r7,132(r8)
	PPC_STORE_U32(ctx.r8.u32 + 132, ctx.r7.u32);
	// stw r11,128(r4)
	PPC_STORE_U32(ctx.r4.u32 + 128, r11.u32);
	// stw r11,132(r4)
	PPC_STORE_U32(ctx.r4.u32 + 132, r11.u32);
loc_824EB1B8:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB1C8"))) PPC_WEAK_FUNC(sub_824EB1C8);
PPC_FUNC_IMPL(__imp__sub_824EB1C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb1f0
	if (cr6.eq) goto loc_824EB1F0;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
loc_824EB1F0:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb210
	if (cr6.eq) goto loc_824EB210;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824eb214
	if (!cr6.eq) goto loc_824EB214;
loc_824EB210:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824EB214:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb230
	if (cr6.eq) goto loc_824EB230;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_824EB230:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB244"))) PPC_WEAK_FUNC(sub_824EB244);
PPC_FUNC_IMPL(__imp__sub_824EB244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB248"))) PPC_WEAK_FUNC(sub_824EB248);
PPC_FUNC_IMPL(__imp__sub_824EB248) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb298
	if (!cr6.eq) goto loc_824EB298;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb284
	if (cr6.eq) goto loc_824EB284;
	// stw r11,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB284:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB298:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb2d4
	if (!cr6.eq) goto loc_824EB2D4;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb2f8
	if (cr6.eq) goto loc_824EB2F8;
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB2D4:
	// lwz r10,24(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,20(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r7,24(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
	// stw r11,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r11.u32);
loc_824EB2F8:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB308"))) PPC_WEAK_FUNC(sub_824EB308);
PPC_FUNC_IMPL(__imp__sub_824EB308) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb358
	if (!cr6.eq) goto loc_824EB358;
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,124(r4)
	PPC_STORE_U32(ctx.r4.u32 + 124, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb344
	if (cr6.eq) goto loc_824EB344;
	// stw r11,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB344:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB358:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb394
	if (!cr6.eq) goto loc_824EB394;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,128(r4)
	PPC_STORE_U32(ctx.r4.u32 + 128, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb3b8
	if (cr6.eq) goto loc_824EB3B8;
	// stw r11,124(r10)
	PPC_STORE_U32(ctx.r10.u32 + 124, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB394:
	// lwz r10,128(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,124(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 124);
	// stw r9,124(r10)
	PPC_STORE_U32(ctx.r10.u32 + 124, ctx.r9.u32);
	// lwz r8,124(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 124);
	// lwz r7,128(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// stw r7,128(r8)
	PPC_STORE_U32(ctx.r8.u32 + 128, ctx.r7.u32);
	// stw r11,124(r4)
	PPC_STORE_U32(ctx.r4.u32 + 124, r11.u32);
	// stw r11,128(r4)
	PPC_STORE_U32(ctx.r4.u32 + 128, r11.u32);
loc_824EB3B8:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB3C8"))) PPC_WEAK_FUNC(sub_824EB3C8);
PPC_FUNC_IMPL(__imp__sub_824EB3C8) {
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
	ctx.lr = 0x824EB3D0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r22,r24
	r22.u64 = r24.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r10,r11,r21
	ctx.r10.u64 = r11.u64 + r21.u64;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// srw r30,r9,r7
	r30.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r7.u8 & 0x3F));
	// andc r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r8.u64;
	// srw r23,r10,r7
	r23.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x824eb5a0
	if (!cr6.gt) goto loc_824EB5A0;
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// bgt cr6,0x824eb6c8
	if (cr6.gt) goto loc_824EB6C8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r29,r23,2,0,29
	r29.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// blt cr6,0x824eb6c8
	if (cr6.lt) goto loc_824EB6C8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB458;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824eb6c8
	if (cr6.eq) goto loc_824EB6C8;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r22,1
	r22.s64 = 1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824eb494
	if (cr6.eq) goto loc_824EB494;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8244d5c0
	ctx.lr = 0x824EB47C;
	sub_8244D5C0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824EB494:
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// mr r26,r30
	r26.u64 = r30.u64;
	// cmplw cr6,r30,r23
	cr6.compare<uint32_t>(r30.u32, r23.u32, xer);
	// bge cr6,0x824eb6c8
	if (!cr6.lt) goto loc_824EB6C8;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// rlwinm r28,r30,2,0,29
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,27004
	r25.s64 = r11.s64 + 27004;
loc_824EB4B0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stwx r24,r28,r11
	PPC_STORE_U32(r28.u32 + r11.u32, r24.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mulli r30,r10,148
	r30.s64 = ctx.r10.s64 * 148;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824EB4D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// blt cr6,0x824eb504
	if (cr6.lt) goto loc_824EB504;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB4FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stwx r3,r28,r9
	PPC_STORE_U32(r28.u32 + ctx.r9.u32, ctx.r3.u32);
loc_824EB504:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r10,r28,r11
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb598
	if (cr6.eq) goto loc_824EB598;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r27,r24
	r27.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824eb574
	if (!cr6.gt) goto loc_824EB574;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_824EB528:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r11,r28,r11
	r11.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// add. r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x824eb560
	if (cr0.eq) goto loc_824EB560;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82531aa8
	ctx.lr = 0x824EB540;
	sub_82531AA8(ctx, base);
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// stw r24,128(r30)
	PPC_STORE_U32(r30.u32 + 128, r24.u32);
	// stw r24,132(r30)
	PPC_STORE_U32(r30.u32 + 132, r24.u32);
	// lbz r11,144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 144);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r24,136(r30)
	PPC_STORE_U32(r30.u32 + 136, r24.u32);
	// stw r24,140(r30)
	PPC_STORE_U32(r30.u32 + 140, r24.u32);
	// stb r10,144(r30)
	PPC_STORE_U8(r30.u32 + 144, ctx.r10.u8);
loc_824EB560:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,148
	r29.s64 = r29.s64 + 148;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x824eb528
	if (cr6.lt) goto loc_824EB528;
loc_824EB574:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r26,r23
	cr6.compare<uint32_t>(r26.u32, r23.u32, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// blt cr6,0x824eb4b0
	if (cr6.lt) goto loc_824EB4B0;
	// b 0x824eb6c8
	goto loc_824EB6C8;
loc_824EB598:
	// mr r22,r24
	r22.u64 = r24.u64;
	// b 0x824eb6c8
	goto loc_824EB6C8;
loc_824EB5A0:
	// bge cr6,0x824eb6c4
	if (!cr6.lt) goto loc_824EB6C4;
	// cmplw cr6,r23,r30
	cr6.compare<uint32_t>(r23.u32, r30.u32, xer);
	// bge cr6,0x824eb630
	if (!cr6.lt) goto loc_824EB630;
	// rlwinm r28,r23,2,0,29
	r28.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r27,r23,r30
	r27.s64 = r30.s64 - r23.s64;
loc_824EB5B4:
	// mr r29,r24
	r29.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb5f8
	if (cr6.eq) goto loc_824EB5F8;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_824EB5C4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r11,r28,r11
	r11.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EB5E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,148
	r30.s64 = r30.s64 + 148;
	// cmplw cr6,r29,r8
	cr6.compare<uint32_t>(r29.u32, ctx.r8.u32, xer);
	// blt cr6,0x824eb5c4
	if (cr6.lt) goto loc_824EB5C4;
loc_824EB5F8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r4,r28,r11
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EB614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// bne 0x824eb5b4
	if (!cr0.eq) goto loc_824EB5B4;
loc_824EB630:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// beq cr6,0x824eb6b0
	if (cr6.eq) goto loc_824EB6B0;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r29,r23,2,0,29
	r29.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// blt cr6,0x824eb6c8
	if (cr6.lt) goto loc_824EB6C8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB678;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eb6c8
	if (cr6.eq) goto loc_824EB6C8;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8244d5c0
	ctx.lr = 0x824EB690;
	sub_8244D5C0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB6A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// b 0x824eb6c4
	goto loc_824EB6C4;
loc_824EB6B0:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB6C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r24,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r24.u32);
loc_824EB6C4:
	// li r22,1
	r22.s64 = 1;
loc_824EB6C8:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb6e4
	if (cr6.eq) goto loc_824EB6E4;
	// stw r21,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r21.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_824EB6E4:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// ble cr6,0x824eb6f8
	if (!cr6.gt) goto loc_824EB6F8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_824EB6F8:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824EB704"))) PPC_WEAK_FUNC(sub_824EB704);
PPC_FUNC_IMPL(__imp__sub_824EB704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB708"))) PPC_WEAK_FUNC(sub_824EB708);
PPC_FUNC_IMPL(__imp__sub_824EB708) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824eb74c
	if (!cr6.eq) goto loc_824EB74C;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb740
	if (cr6.eq) goto loc_824EB740;
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824eb784
	if (!cr6.eq) goto loc_824EB784;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eb784
	goto loc_824EB784;
loc_824EB740:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eb784
	goto loc_824EB784;
loc_824EB74C:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824eb76c
	if (!cr6.eq) goto loc_824EB76C;
	// stw r11,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eb784
	goto loc_824EB784;
loc_824EB76C:
	// stw r5,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r5.u32);
	// lwz r11,24(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// stw r11,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, r11.u32);
	// lwz r10,24(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// stw r6,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r6.u32);
	// stw r6,24(r5)
	PPC_STORE_U32(ctx.r5.u32 + 24, ctx.r6.u32);
loc_824EB784:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB79C"))) PPC_WEAK_FUNC(sub_824EB79C);
PPC_FUNC_IMPL(__imp__sub_824EB79C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB7A0"))) PPC_WEAK_FUNC(sub_824EB7A0);
PPC_FUNC_IMPL(__imp__sub_824EB7A0) {
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
	ctx.lr = 0x824EB7A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb7f0
	if (cr6.eq) goto loc_824EB7F0;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eb7f0
	if (cr6.eq) goto loc_824EB7F0;
loc_824EB7CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB7E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,4(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824eb7cc
	if (!cr6.eq) goto loc_824EB7CC;
loc_824EB7F0:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// ori r8,r29,1
	ctx.r8.u64 = r29.u64 | 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb840
	if (cr6.eq) goto loc_824EB840;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// mulli r9,r10,1000
	ctx.r9.s64 = ctx.r10.s64 * 1000;
	// cmpwi cr6,r11,1000
	cr6.compare<int32_t>(r11.s32, 1000, xer);
	// ble cr6,0x824eb818
	if (!cr6.gt) goto loc_824EB818;
	// li r11,1000
	r11.s64 = 1000;
loc_824EB818:
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r8,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r8.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x824eb850
	if (!cr6.gt) goto loc_824EB850;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824EB840:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r8,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r8.u32);
	// mulli r10,r11,1000
	ctx.r10.s64 = r11.s64 * 1000;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_824EB850:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EB858"))) PPC_WEAK_FUNC(sub_824EB858);
PPC_FUNC_IMPL(__imp__sub_824EB858) {
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
	ctx.lr = 0x824EB860;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,40(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb8b8
	if (cr6.eq) goto loc_824EB8B8;
	// lwz r31,32(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eb8b8
	if (cr6.eq) goto loc_824EB8B8;
loc_824EB88C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB8AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824eb88c
	if (!cr6.eq) goto loc_824EB88C;
loc_824EB8B8:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb8d4
	if (cr6.eq) goto loc_824EB8D4;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mulli r10,r30,1000
	ctx.r10.s64 = r30.s64 * 1000;
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// stw r9,4(r27)
	PPC_STORE_U32(r27.u32 + 4, ctx.r9.u32);
loc_824EB8D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824EB8DC"))) PPC_WEAK_FUNC(sub_824EB8DC);
PPC_FUNC_IMPL(__imp__sub_824EB8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB8E0"))) PPC_WEAK_FUNC(sub_824EB8E0);
PPC_FUNC_IMPL(__imp__sub_824EB8E0) {
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
	ctx.lr = 0x824EB8E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb93c
	if (cr6.eq) goto loc_824EB93C;
	// lwz r31,32(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eb93c
	if (cr6.eq) goto loc_824EB93C;
loc_824EB910:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB930;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824eb910
	if (!cr6.eq) goto loc_824EB910;
loc_824EB93C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EB944"))) PPC_WEAK_FUNC(sub_824EB944);
PPC_FUNC_IMPL(__imp__sub_824EB944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB948"))) PPC_WEAK_FUNC(sub_824EB948);
PPC_FUNC_IMPL(__imp__sub_824EB948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r4,27
	ctx.r10.u64 = ctx.r4.u32 & 0x1F;
	// addi r9,r11,333
	ctx.r9.s64 = r11.s64 + 333;
	// li r8,1
	ctx.r8.s64 = 1;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r7,r8,r10
	ctx.r7.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// lwzx r6,r11,r3
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// stwx r5,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB970"))) PPC_WEAK_FUNC(sub_824EB970);
PPC_FUNC_IMPL(__imp__sub_824EB970) {
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
	ctx.lr = 0x824EB978;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EB994;
	sub_821C8FE0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x824eafa0
	ctx.lr = 0x824EB9A4;
	sub_824EAFA0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eb9ec
	if (cr6.eq) goto loc_824EB9EC;
	// bl 0x8218f5b0
	ctx.lr = 0x824EB9B4;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// beq cr6,0x824eb9ec
	if (cr6.eq) goto loc_824EB9EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825303e0
	ctx.lr = 0x824EB9C4;
	sub_825303E0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824EB9D4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824eb9d4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824EB9D4;
	// li r29,1
	r29.s64 = 1;
loc_824EB9EC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EB9F4;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EBA00"))) PPC_WEAK_FUNC(sub_824EBA00);
PPC_FUNC_IMPL(__imp__sub_824EBA00) {
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
	ctx.lr = 0x824EBA08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EBA24;
	sub_821C8FE0(ctx, base);
	// mulli r11,r30,68
	r11.s64 = r30.s64 * 68;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,216
	ctx.r3.s64 = r11.s64 + 216;
	// bl 0x824eb048
	ctx.lr = 0x824EBA38;
	sub_824EB048(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EBA40;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

