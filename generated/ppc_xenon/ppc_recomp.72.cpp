#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_823E65BC"))) PPC_WEAK_FUNC(sub_823E65BC);
PPC_FUNC_IMPL(__imp__sub_823E65BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E65C0"))) PPC_WEAK_FUNC(sub_823E65C0);
PPC_FUNC_IMPL(__imp__sub_823E65C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi. r10,r3,30
	ctx.r10.u64 = ctx.r3.u32 & 0x3;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq 0x823e65f8
	if (cr0.eq) goto loc_823E65F8;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x823e65dc
	if (!cr6.eq) goto loc_823E65DC;
	// li r11,768
	r11.s64 = 768;
	// b 0x823e65f8
	goto loc_823E65F8;
loc_823E65DC:
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x823e65ec
	if (!cr6.eq) goto loc_823E65EC;
	// li r11,512
	r11.s64 = 512;
	// b 0x823e65f8
	goto loc_823E65F8;
loc_823E65EC:
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x823e65f8
	if (!cr6.eq) goto loc_823E65F8;
	// li r11,256
	r11.s64 = 256;
loc_823E65F8:
	// rlwinm. r10,r3,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e6604
	if (cr0.eq) goto loc_823E6604;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
loc_823E6604:
	// rlwinm. r10,r3,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e6610
	if (cr0.eq) goto loc_823E6610;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
loc_823E6610:
	// rlwinm. r10,r3,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e661c
	if (cr0.eq) goto loc_823E661C;
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
loc_823E661C:
	// rlwinm. r10,r3,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e6628
	if (cr0.eq) goto loc_823E6628;
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
loc_823E6628:
	// rlwinm. r10,r3,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x80;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e6634
	if (cr0.eq) goto loc_823E6634;
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
loc_823E6634:
	// oris r3,r11,8
	ctx.r3.u64 = r11.u64 | 524288;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E663C"))) PPC_WEAK_FUNC(sub_823E663C);
PPC_FUNC_IMPL(__imp__sub_823E663C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E6640"))) PPC_WEAK_FUNC(sub_823E6640);
PPC_FUNC_IMPL(__imp__sub_823E6640) {
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
	// lis r4,-8
	ctx.r4.s64 = -524288;
	// li r3,0
	ctx.r3.s64 = 0;
	// ori r4,r4,1792
	ctx.r4.u64 = ctx.r4.u64 | 1792;
	// bl 0x823e39c0
	ctx.lr = 0x823E665C;
	sub_823E39C0(ctx, base);
	// bl 0x823e65c0
	ctx.lr = 0x823E6660;
	sub_823E65C0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E6670"))) PPC_WEAK_FUNC(sub_823E6670);
PPC_FUNC_IMPL(__imp__sub_823E6670) {
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
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x823e93e0
	ctx.lr = 0x823E6694;
	sub_823E93E0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x823e66b4
	if (!cr6.eq) goto loc_823E66B4;
	// bl 0x823e1000
	ctx.lr = 0x823E66A0;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e671c
	goto loc_823E671C;
loc_823E66B4:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8244f120
	ctx.lr = 0x823E66C4;
	sub_8244F120(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x823e66e8
	if (!cr6.eq) goto loc_823E66E8;
	// bl 0x82135db0
	ctx.lr = 0x823E66D4;
	sub_82135DB0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x823e66e8
	if (cr0.eq) goto loc_823E66E8;
	// bl 0x823e1070
	ctx.lr = 0x823E66E0;
	sub_823E1070(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e671c
	goto loc_823E671C;
loc_823E66E8:
	// srawi r11,r31,5
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1F) != 0);
	r11.s64 = r31.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23104
	ctx.r10.s64 = ctx.r10.s64 + -23104;
	// rlwinm r11,r31,6,21,25
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 6) & 0x7C0;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_823E671C:
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

__attribute__((alias("__imp__sub_823E6734"))) PPC_WEAK_FUNC(sub_823E6734);
PPC_FUNC_IMPL(__imp__sub_823E6734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E6738"))) PPC_WEAK_FUNC(sub_823E6738);
PPC_FUNC_IMPL(__imp__sub_823E6738) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9840(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9840);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x823E6748;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// li r24,-1
	r24.s64 = -1;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// std r24,80(r31)
	PPC_STORE_U64(r31.u32 + 80, r24.u64);
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x823e6794
	if (!cr6.eq) goto loc_823E6794;
	// bl 0x823e1038
	ctx.lr = 0x823E6774;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E6780;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e6870
	goto loc_823E6870;
loc_823E6794:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823e67ac
	if (cr6.lt) goto loc_823E67AC;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823e67e4
	if (cr6.lt) goto loc_823E67E4;
loc_823E67AC:
	// bl 0x823e1038
	ctx.lr = 0x823E67B0;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E67BC;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E67DC;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e6870
	goto loc_823E6870;
loc_823E67E4:
	// srawi r11,r30,5
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1F) != 0);
	r11.s64 = r30.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23104
	r28.s64 = ctx.r10.s64 + -23104;
	// rlwinm r29,r30,6,21,25
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e67ac
	if (cr0.eq) goto loc_823E67AC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E6814;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e6844
	if (cr0.eq) goto loc_823E6844;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e6670
	ctx.lr = 0x823E683C;
	sub_823E6670(ctx, base);
	// std r3,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.r3.u64);
	// b 0x823e6860
	goto loc_823E6860;
loc_823E6844:
	// bl 0x823e1000
	ctx.lr = 0x823E6848;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E6854;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// std r24,80(r31)
	PPC_STORE_U64(r31.u32 + 80, r24.u64);
loc_823E6860:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x823e6898
	ctx.lr = 0x823E686C;
	sub_823E6898(ctx, base);
	// ld r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U64(r31.u32 + 80);
loc_823E6870:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823E6740"))) PPC_WEAK_FUNC(sub_823E6740);
PPC_FUNC_IMPL(__imp__sub_823E6740) {
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
	ctx.lr = 0x823E6748;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// li r24,-1
	r24.s64 = -1;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// std r24,80(r31)
	PPC_STORE_U64(r31.u32 + 80, r24.u64);
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x823e6794
	if (!cr6.eq) goto loc_823E6794;
	// bl 0x823e1038
	ctx.lr = 0x823E6774;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E6780;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e6870
	goto loc_823E6870;
loc_823E6794:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823e67ac
	if (cr6.lt) goto loc_823E67AC;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823e67e4
	if (cr6.lt) goto loc_823E67E4;
loc_823E67AC:
	// bl 0x823e1038
	ctx.lr = 0x823E67B0;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E67BC;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E67DC;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e6870
	goto loc_823E6870;
loc_823E67E4:
	// srawi r11,r30,5
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1F) != 0);
	r11.s64 = r30.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23104
	r28.s64 = ctx.r10.s64 + -23104;
	// rlwinm r29,r30,6,21,25
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e67ac
	if (cr0.eq) goto loc_823E67AC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E6814;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e6844
	if (cr0.eq) goto loc_823E6844;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e6670
	ctx.lr = 0x823E683C;
	sub_823E6670(ctx, base);
	// std r3,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.r3.u64);
	// b 0x823e6860
	goto loc_823E6860;
loc_823E6844:
	// bl 0x823e1000
	ctx.lr = 0x823E6848;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E6854;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// std r24,80(r31)
	PPC_STORE_U64(r31.u32 + 80, r24.u64);
loc_823E6860:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x823e6898
	ctx.lr = 0x823E686C;
	sub_823E6898(ctx, base);
	// ld r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U64(r31.u32 + 80);
loc_823E6870:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823E6878"))) PPC_WEAK_FUNC(sub_823E6878);
PPC_FUNC_IMPL(__imp__sub_823E6878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,180(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// b 0x823e68b0
	goto loc_823E68B0;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_823E68B0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823E68B8;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E6898"))) PPC_WEAK_FUNC(sub_823E6898);
PPC_FUNC_IMPL(__imp__sub_823E6898) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823E68B8;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E68D0"))) PPC_WEAK_FUNC(sub_823E68D0);
PPC_FUNC_IMPL(__imp__sub_823E68D0) {
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
	ctx.lr = 0x823E68D8;
	// stwu r1,-1232(r1)
	ea = -1232 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r21,0
	r21.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// mr r23,r21
	r23.u64 = r21.u64;
	// mr r22,r21
	r22.u64 = r21.u64;
	// bne cr6,0x823e6900
	if (!cr6.eq) goto loc_823E6900;
loc_823E68F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823e6b14
	goto loc_823E6B14;
loc_823E6900:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x823e693c
	if (!cr6.eq) goto loc_823E693C;
loc_823E6908:
	// bl 0x823e1038
	ctx.lr = 0x823E690C;
	sub_823E1038(ctx, base);
	// stw r21,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r21.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E6914;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E6934;
	sub_823E02A8(ctx, base);
loc_823E6934:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e6b14
	goto loc_823E6B14;
loc_823E693C:
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r26,r11,2,0,29
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r10,-23104
	r27.s64 = ctx.r10.s64 + -23104;
	// rlwinm r28,r3,6,21,25
	r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r26,r27
	r11.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// add r10,r11,r28
	ctx.r10.u64 = r11.u64 + r28.u64;
	// lbz r11,40(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rotlwi r11,r11,24
	r11.u64 = __builtin_rotateleft32(r11.u32, 24);
	// srawi r11,r11,25
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFFFF) != 0);
	r11.s64 = r11.s32 >> 25;
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823e6978
	if (cr6.eq) goto loc_823E6978;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x823e6984
	if (!cr6.eq) goto loc_823E6984;
loc_823E6978:
	// not r11,r29
	r11.u64 = ~r29.u64;
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e6908
	if (cr0.eq) goto loc_823E6908;
loc_823E6984:
	// lbz r11,4(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e699c
	if (cr0.eq) goto loc_823E699C;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823e6670
	ctx.lr = 0x823E699C;
	sub_823E6670(ctx, base);
loc_823E699C:
	// lwzx r11,r26,r27
	r11.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// rlwinm. r10,r10,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e6a5c
	if (cr0.eq) goto loc_823E6A5C;
	// mr r25,r21
	r25.u64 = r21.u64;
	// mr r30,r24
	r30.u64 = r24.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823e6ad0
	if (cr6.eq) goto loc_823E6AD0;
loc_823E69C0:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// subf r9,r24,r30
	ctx.r9.s64 = r30.s64 - r24.s64;
loc_823E69CC:
	// cmplw cr6,r9,r29
	cr6.compare<uint32_t>(ctx.r9.u32, r29.u32, xer);
	// bge cr6,0x823e6a10
	if (!cr6.lt) goto loc_823E6A10;
	// lbz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r8,10
	cr6.compare<uint32_t>(ctx.r8.u32, 10, xer);
	// bne cr6,0x823e69fc
	if (!cr6.eq) goto loc_823E69FC;
	// li r7,13
	ctx.r7.s64 = 13;
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_823E69FC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,1024
	cr6.compare<uint32_t>(ctx.r10.u32, 1024, xer);
	// blt cr6,0x823e69cc
	if (cr6.lt) goto loc_823E69CC;
loc_823E6A10:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwzx r9,r26,r27
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// subf r31,r10,r11
	r31.s64 = r11.s64 - ctx.r10.s64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwzx r3,r9,r28
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r28.u32);
	// bl 0x8244f398
	ctx.lr = 0x823E6A34;
	sub_8244F398(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e6a88
	if (cr0.eq) goto loc_823E6A88;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r23,r11,r23
	r23.u64 = r11.u64 + r23.u64;
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// blt cr6,0x823e6a90
	if (cr6.lt) goto loc_823E6A90;
	// subf r11,r24,r30
	r11.s64 = r30.s64 - r24.s64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x823e69c0
	if (cr6.lt) goto loc_823E69C0;
	// b 0x823e6a90
	goto loc_823E6A90;
loc_823E6A5C:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x8244f398
	ctx.lr = 0x823E6A74;
	sub_8244F398(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e6a88
	if (cr0.eq) goto loc_823E6A88;
	// lwz r23,80(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r25,r21
	r25.u64 = r21.u64;
	// b 0x823e6a90
	goto loc_823E6A90;
loc_823E6A88:
	// bl 0x82135db0
	ctx.lr = 0x823E6A8C;
	sub_82135DB0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
loc_823E6A90:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// bne cr6,0x823e6b10
	if (!cr6.eq) goto loc_823E6B10;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x823e6ad0
	if (cr6.eq) goto loc_823E6AD0;
	// cmplwi cr6,r25,5
	cr6.compare<uint32_t>(r25.u32, 5, xer);
	// bne cr6,0x823e6ac4
	if (!cr6.eq) goto loc_823E6AC4;
	// bl 0x823e1000
	ctx.lr = 0x823E6AAC;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E6AB8;
	sub_823E1038(ctx, base);
	// li r11,5
	r11.s64 = 5;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// b 0x823e6934
	goto loc_823E6934;
loc_823E6AC4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823e1070
	ctx.lr = 0x823E6ACC;
	sub_823E1070(ctx, base);
	// b 0x823e6934
	goto loc_823E6934;
loc_823E6AD0:
	// lwzx r11,r26,r27
	r11.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e6af0
	if (cr0.eq) goto loc_823E6AF0;
	// lbz r11,0(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 0);
	// cmplwi cr6,r11,26
	cr6.compare<uint32_t>(r11.u32, 26, xer);
	// beq cr6,0x823e68f8
	if (cr6.eq) goto loc_823E68F8;
loc_823E6AF0:
	// bl 0x823e1000
	ctx.lr = 0x823E6AF4;
	sub_823E1000(ctx, base);
	// li r11,28
	r11.s64 = 28;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E6B00;
	sub_823E1038(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r21,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r21.u32);
	// b 0x823e6b14
	goto loc_823E6B14;
loc_823E6B10:
	// subf r3,r22,r23
	ctx.r3.s64 = r23.s64 - r22.s64;
loc_823E6B14:
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_823E6B1C"))) PPC_WEAK_FUNC(sub_823E6B1C);
PPC_FUNC_IMPL(__imp__sub_823E6B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E6B20"))) PPC_WEAK_FUNC(sub_823E6B20);
PPC_FUNC_IMPL(__imp__sub_823E6B20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9864(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9864);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823E6B30;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x823e6b74
	if (!cr6.eq) goto loc_823E6B74;
	// bl 0x823e1038
	ctx.lr = 0x823E6B54;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E6B60;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e6c54
	goto loc_823E6C54;
loc_823E6B74:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823e6b8c
	if (cr6.lt) goto loc_823E6B8C;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823e6bc4
	if (cr6.lt) goto loc_823E6BC4;
loc_823E6B8C:
	// bl 0x823e1038
	ctx.lr = 0x823E6B90;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E6B9C;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E6BBC;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e6c54
	goto loc_823E6C54;
loc_823E6BC4:
	// srawi r11,r30,5
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1F) != 0);
	r11.s64 = r30.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23104
	r28.s64 = ctx.r10.s64 + -23104;
	// rlwinm r29,r30,6,21,25
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e6b8c
	if (cr0.eq) goto loc_823E6B8C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E6BF4;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e6c24
	if (cr0.eq) goto loc_823E6C24;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e68d0
	ctx.lr = 0x823E6C1C;
	sub_823E68D0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// b 0x823e6c44
	goto loc_823E6C44;
loc_823E6C24:
	// bl 0x823e1000
	ctx.lr = 0x823E6C28;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E6C34;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
loc_823E6C44:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x823e6c7c
	ctx.lr = 0x823E6C50;
	sub_823E6C7C(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E6C54:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823E6B28"))) PPC_WEAK_FUNC(sub_823E6B28);
PPC_FUNC_IMPL(__imp__sub_823E6B28) {
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
	ctx.lr = 0x823E6B30;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x823e6b74
	if (!cr6.eq) goto loc_823E6B74;
	// bl 0x823e1038
	ctx.lr = 0x823E6B54;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E6B60;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e6c54
	goto loc_823E6C54;
loc_823E6B74:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823e6b8c
	if (cr6.lt) goto loc_823E6B8C;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823e6bc4
	if (cr6.lt) goto loc_823E6BC4;
loc_823E6B8C:
	// bl 0x823e1038
	ctx.lr = 0x823E6B90;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E6B9C;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E6BBC;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e6c54
	goto loc_823E6C54;
loc_823E6BC4:
	// srawi r11,r30,5
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1F) != 0);
	r11.s64 = r30.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23104
	r28.s64 = ctx.r10.s64 + -23104;
	// rlwinm r29,r30,6,21,25
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e6b8c
	if (cr0.eq) goto loc_823E6B8C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E6BF4;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e6c24
	if (cr0.eq) goto loc_823E6C24;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e68d0
	ctx.lr = 0x823E6C1C;
	sub_823E68D0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// b 0x823e6c44
	goto loc_823E6C44;
loc_823E6C24:
	// bl 0x823e1000
	ctx.lr = 0x823E6C28;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E6C34;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
loc_823E6C44:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x823e6c7c
	ctx.lr = 0x823E6C50;
	sub_823E6C7C(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E6C54:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823E6C5C"))) PPC_WEAK_FUNC(sub_823E6C5C);
PPC_FUNC_IMPL(__imp__sub_823E6C5C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,180(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// b 0x823e6c94
	goto loc_823E6C94;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_823E6C94:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823E6C9C;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E6C7C"))) PPC_WEAK_FUNC(sub_823E6C7C);
PPC_FUNC_IMPL(__imp__sub_823E6C7C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823E6C9C;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E6CB4"))) PPC_WEAK_FUNC(sub_823E6CB4);
PPC_FUNC_IMPL(__imp__sub_823E6CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E6CB8"))) PPC_WEAK_FUNC(sub_823E6CB8);
PPC_FUNC_IMPL(__imp__sub_823E6CB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// lwz r11,-10456(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10456);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-10456(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10456, r11.u32);
	// bl 0x823e2610
	ctx.lr = 0x823E6CE4;
	sub_823E2610(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// beq 0x823e6d04
	if (cr0.eq) goto loc_823E6D04;
	// li r10,4096
	ctx.r10.s64 = 4096;
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// b 0x823e6d18
	goto loc_823E6D18;
loc_823E6D04:
	// addi r10,r31,20
	ctx.r10.s64 = r31.s64 + 20;
	// li r9,2
	ctx.r9.s64 = 2;
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
loc_823E6D18:
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_823E6D40"))) PPC_WEAK_FUNC(sub_823E6D40);
PPC_FUNC_IMPL(__imp__sub_823E6D40) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823E6D48;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-16377
	r11.s64 = -1073283072;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stfd f31,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, f31.u64);
	// ori r29,r11,65279
	r29.u64 = r11.u64 | 65279;
	// li r3,248
	ctx.r3.s64 = 248;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823e39c0
	ctx.lr = 0x823E6D74;
	sub_823E39C0(ctx, base);
	// lhz r11,160(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 160);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r11,r11,0,17,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7FF0;
	// cmplwi cr6,r11,32752
	cr6.compare<uint32_t>(r11.u32, 32752, xer);
	// bne cr6,0x823e6e00
	if (!cr6.eq) goto loc_823E6E00;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823e2d78
	ctx.lr = 0x823E6D90;
	sub_823E2D78(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble 0x823e6dcc
	if (!cr0.gt) goto loc_823E6DCC;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// ble cr6,0x823e6ef4
	if (!cr6.gt) goto loc_823E6EF4;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x823e6dcc
	if (!cr6.eq) goto loc_823E6DCC;
	// extsw r11,r31
	r11.s64 = r31.s32;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r3,25
	ctx.r3.s64 = 25;
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f0
	ctx.f2.f64 = double(f0.s64);
	// bl 0x823e3778
	ctx.lr = 0x823E6DC8;
	sub_823E3778(ctx, base);
	// b 0x823e6f04
	goto loc_823E6F04;
loc_823E6DCC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// extsw r10,r31
	ctx.r10.s64 = r31.s32;
	// li r3,8
	ctx.r3.s64 = 8;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f13
	ctx.f2.f64 = double(ctx.f13.s64);
	// lfd f0,21560(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + 21560);
	// fadd f3,f31,f0
	ctx.f3.f64 = f31.f64 + f0.f64;
loc_823E6DEC:
	// li r4,25
	ctx.r4.s64 = 25;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// bl 0x823e38d0
	ctx.lr = 0x823E6DFC;
	sub_823E38D0(ctx, base);
	// b 0x823e6f04
	goto loc_823E6F04;
loc_823E6E00:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f30,-17600(r11)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// beq cr6,0x823e6ef4
	if (cr6.eq) goto loc_823E6EF4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823e2e00
	ctx.lr = 0x823E6E1C;
	sub_823E2E00(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x823e6e3c
	if (!cr6.lt) goto loc_823E6E3C;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - r31.s64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x823e6eb0
	if (cr6.lt) goto loc_823E6EB0;
	// b 0x823e6e50
	goto loc_823E6E50;
loc_823E6E3C:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - r31.s64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x823e6e5c
	if (cr6.gt) goto loc_823E6E5C;
loc_823E6E50:
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// cmpwi cr6,r4,2560
	cr6.compare<int32_t>(ctx.r4.s32, 2560, xer);
	// ble cr6,0x823e6e88
	if (!cr6.gt) goto loc_823E6E88;
loc_823E6E5C:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfd f1,-17736(r11)
	ctx.f1.u64 = PPC_LOAD_U64(r11.u32 + -17736);
	// bl 0x823e3c38
	ctx.lr = 0x823E6E6C;
	sub_823E3C38(ctx, base);
	// extsw r11,r31
	r11.s64 = r31.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
loc_823E6E78:
	// li r3,17
	ctx.r3.s64 = 17;
loc_823E6E7C:
	// fmr f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64;
loc_823E6E80:
	// fcfid f2,f0
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(f0.s64);
	// b 0x823e6dec
	goto loc_823E6DEC;
loc_823E6E88:
	// cmpwi cr6,r4,1024
	cr6.compare<int32_t>(ctx.r4.s32, 1024, xer);
	// ble cr6,0x823e6ea8
	if (!cr6.gt) goto loc_823E6EA8;
	// addi r4,r4,-1536
	ctx.r4.s64 = ctx.r4.s64 + -1536;
	// bl 0x823e2d00
	ctx.lr = 0x823E6E98;
	sub_823E2D00(ctx, base);
	// extsw r11,r31
	r11.s64 = r31.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x823e6e78
	goto loc_823E6E78;
loc_823E6EA8:
	// cmpwi cr6,r4,-2557
	cr6.compare<int32_t>(ctx.r4.s32, -2557, xer);
	// bge cr6,0x823e6ec8
	if (!cr6.lt) goto loc_823E6EC8;
loc_823E6EB0:
	// extsw r11,r31
	r11.s64 = r31.s32;
	// fmul f3,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64 * f30.f64;
	// li r3,18
	ctx.r3.s64 = 18;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x823e6e80
	goto loc_823E6E80;
loc_823E6EC8:
	// cmpwi cr6,r4,-1021
	cr6.compare<int32_t>(ctx.r4.s32, -1021, xer);
	// bge cr6,0x823e6eec
	if (!cr6.lt) goto loc_823E6EEC;
	// addi r4,r4,1536
	ctx.r4.s64 = ctx.r4.s64 + 1536;
	// bl 0x823e2d00
	ctx.lr = 0x823E6ED8;
	sub_823E2D00(ctx, base);
	// extsw r11,r31
	r11.s64 = r31.s32;
	// li r3,18
	ctx.r3.s64 = 18;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x823e6e7c
	goto loc_823E6E7C;
loc_823E6EEC:
	// bl 0x823e2d00
	ctx.lr = 0x823E6EF0;
	sub_823E2D00(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
loc_823E6EF4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e39c0
	ctx.lr = 0x823E6F00;
	sub_823E39C0(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_823E6F04:
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

__attribute__((alias("__imp__sub_823E6F14"))) PPC_WEAK_FUNC(sub_823E6F14);
PPC_FUNC_IMPL(__imp__sub_823E6F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E6F18"))) PPC_WEAK_FUNC(sub_823E6F18);
PPC_FUNC_IMPL(__imp__sub_823E6F18) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823E6F20;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823e6f58
	if (!cr6.eq) goto loc_823E6F58;
	// bl 0x823e1000
	ctx.lr = 0x823E6F34;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E6F54;
	sub_823E02A8(ctx, base);
	// b 0x823e70c8
	goto loc_823E70C8;
loc_823E6F58:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// andi. r10,r11,131
	ctx.r10.u64 = r11.u64 & 131;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// cmpwi r10,0
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e70c8
	if (cr0.eq) goto loc_823E70C8;
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e70c8
	if (!cr0.eq) goto loc_823E70C8;
	// rlwinm. r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e6f80
	if (cr0.eq) goto loc_823E6F80;
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// b 0x823e70c4
	goto loc_823E70C4;
loc_823E6F80:
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// andi. r10,r11,268
	ctx.r10.u64 = r11.u64 & 268;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// cmpwi r10,0
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e6fa0
	if (!cr0.eq) goto loc_823E6FA0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e6cb8
	ctx.lr = 0x823E6F9C;
	sub_823E6CB8(ctx, base);
	// b 0x823e6fa8
	goto loc_823E6FA8;
loc_823E6FA0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E6FA8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r29,24(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823e3de0
	ctx.lr = 0x823E6FB8;
	sub_823E3DE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823e9c10
	ctx.lr = 0x823E6FC4;
	sub_823E9C10(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// beq 0x823e70a4
	if (cr0.eq) goto loc_823E70A4;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823e70a4
	if (cr6.eq) goto loc_823E70A4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// andi. r11,r11,130
	r11.u64 = r11.u64 & 130;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi r11,0
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e705c
	if (!cr0.eq) goto loc_823E705C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E6FF0;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823e7038
	if (cr6.eq) goto loc_823E7038;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E7000;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x823e7038
	if (cr6.eq) goto loc_823E7038;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E7010;
	sub_823E3DE0(ctx, base);
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r10,-23104
	r30.s64 = ctx.r10.s64 + -23104;
	// bl 0x823e3de0
	ctx.lr = 0x823E7028;
	sub_823E3DE0(ctx, base);
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x823e7040
	goto loc_823E7040;
loc_823E7038:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-17448
	r11.s64 = r11.s64 + -17448;
loc_823E7040:
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// andi. r11,r11,130
	r11.u64 = r11.u64 & 130;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmplwi cr6,r11,130
	cr6.compare<uint32_t>(r11.u32, 130, xer);
	// bne cr6,0x823e705c
	if (!cr6.eq) goto loc_823E705C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_823E705C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,512
	cr6.compare<int32_t>(r11.s32, 512, xer);
	// bne cr6,0x823e7084
	if (!cr6.eq) goto loc_823E7084;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e7084
	if (cr0.eq) goto loc_823E7084;
	// rlwinm. r11,r11,0,21,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x400;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e7084
	if (!cr0.eq) goto loc_823E7084;
	// li r11,4096
	r11.s64 = 4096;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
loc_823E7084:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lbz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// b 0x823e70cc
	goto loc_823E70CC;
loc_823E70A4:
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
loc_823E70C4:
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_823E70C8:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_823E70CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E70D4"))) PPC_WEAK_FUNC(sub_823E70D4);
PPC_FUNC_IMPL(__imp__sub_823E70D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E70D8"))) PPC_WEAK_FUNC(sub_823E70D8);
PPC_FUNC_IMPL(__imp__sub_823E70D8) {
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
	ctx.lr = 0x823E70E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e71e8
	if (!cr0.eq) goto loc_823E71E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E7100;
	sub_823E3DE0(ctx, base);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// addi r29,r11,-23104
	r29.s64 = r11.s64 + -23104;
	// addi r28,r10,-17448
	r28.s64 = ctx.r10.s64 + -17448;
	// beq cr6,0x823e7150
	if (cr6.eq) goto loc_823E7150;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E7120;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x823e7150
	if (cr6.eq) goto loc_823E7150;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E7130;
	sub_823E3DE0(ctx, base);
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823e3de0
	ctx.lr = 0x823E7140;
	sub_823E3DE0(ctx, base);
	// lwzx r10,r30,r29
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r29.u32);
	// rlwinm r11,r3,6,21,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x823e7154
	goto loc_823E7154;
loc_823E7150:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823E7154:
	// lbz r11,40(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// rlwinm. r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e71b8
	if (!cr0.eq) goto loc_823E71B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E7168;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823e71a8
	if (cr6.eq) goto loc_823E71A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E7178;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x823e71a8
	if (cr6.eq) goto loc_823E71A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E7188;
	sub_823E3DE0(ctx, base);
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823e3de0
	ctx.lr = 0x823E7198;
	sub_823E3DE0(ctx, base);
	// lwzx r10,r30,r29
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r29.u32);
	// rlwinm r11,r3,6,21,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x823e71ac
	goto loc_823E71AC;
loc_823E71A8:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823E71AC:
	// lbz r11,40(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e71e8
	if (cr0.eq) goto loc_823E71E8;
loc_823E71B8:
	// bl 0x823e1000
	ctx.lr = 0x823E71BC;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E71DC;
	sub_823E02A8(ctx, base);
loc_823E71DC:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_823E71E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823E71E8:
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// beq cr6,0x823e71dc
	if (cr6.eq) goto loc_823E71DC;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e720c
	if (!cr0.eq) goto loc_823E720C;
	// rlwinm. r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e71dc
	if (cr0.eq) goto loc_823E71DC;
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e71dc
	if (!cr0.eq) goto loc_823E71DC;
loc_823E720C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e7220
	if (!cr6.eq) goto loc_823E7220;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e6cb8
	ctx.lr = 0x823E7220;
	sub_823E6CB8(ctx, base);
loc_823E7220:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823e7244
	if (!cr6.eq) goto loc_823E7244;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823e71dc
	if (!cr6.eq) goto loc_823E71DC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E7244:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// beq 0x823e727c
	if (cr0.eq) goto loc_823E727C;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r10,r27
	ctx.r10.s64 = r27.s8;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823e7280
	if (cr6.eq) goto loc_823E7280;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x823e71dc
	goto loc_823E71DC;
loc_823E727C:
	// stb r27,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r27.u8);
loc_823E7280:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r3,r27,24
	ctx.r3.u64 = r27.u32 & 0xFF;
	// rlwimi r10,r9,0,31,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x1) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFE);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwimi r10,r9,0,27,27
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x10) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFEF);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// b 0x823e71e0
	goto loc_823E71E0;
}

__attribute__((alias("__imp__sub_823E72A8"))) PPC_WEAK_FUNC(sub_823E72A8);
PPC_FUNC_IMPL(__imp__sub_823E72A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823e72d4
	if (cr6.eq) goto loc_823E72D4;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823e72d4
	if (cr6.eq) goto loc_823E72D4;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x823e72dc
	if (!cr0.eq) goto loc_823E72DC;
	// beq cr6,0x823e72d4
	if (cr6.eq) goto loc_823E72D4;
	// li r11,0
	r11.s64 = 0;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r11.u16);
loc_823E72D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_823E72DC:
	// beq cr6,0x823e72e8
	if (cr6.eq) goto loc_823E72E8;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r11.u16);
loc_823E72E8:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E72F0"))) PPC_WEAK_FUNC(sub_823E72F0);
PPC_FUNC_IMPL(__imp__sub_823E72F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x823E72F8;
	// lhz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lhz r8,10(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// li r22,0
	r22.s64 = 0;
	// clrlwi r11,r9,17
	r11.u64 = ctx.r9.u32 & 0x7FFF;
	// lwz r7,2(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2);
	// lwz r6,6(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 6);
	// addi r20,r10,-16680
	r20.s64 = ctx.r10.s64 + -16680;
	// addi r27,r11,-16383
	r27.s64 = r11.s64 + -16383;
	// rotlwi r11,r8,16
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 16);
	// rlwinm r19,r9,0,0,16
	r19.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFF8000;
	// stw r7,-152(r1)
	PPC_STORE_U32(ctx.r1.u32 + -152, ctx.r7.u32);
	// cmpwi cr6,r27,-16383
	cr6.compare<int32_t>(r27.s32, -16383, xer);
	// lwz r21,12(r20)
	r21.u64 = PPC_LOAD_U32(r20.u32 + 12);
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// stw r6,-148(r1)
	PPC_STORE_U32(ctx.r1.u32 + -148, ctx.r6.u32);
	// stw r11,-144(r1)
	PPC_STORE_U32(ctx.r1.u32 + -144, r11.u32);
	// bne cr6,0x823e7380
	if (!cr6.eq) goto loc_823E7380;
	// mr r31,r22
	r31.u64 = r22.u64;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_823E7348:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e7368
	if (!cr6.eq) goto loc_823E7368;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x823e7348
	if (cr6.lt) goto loc_823E7348;
	// b 0x823e7998
	goto loc_823E7998;
loc_823E7368:
	// addi r11,r1,-152
	r11.s64 = ctx.r1.s64 + -152;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r22.u32);
	// stw r22,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r22.u32);
	// b 0x823e799c
	goto loc_823E799C;
loc_823E7380:
	// lwz r25,8(r20)
	r25.u64 = PPC_LOAD_U32(r20.u32 + 8);
	// addi r8,r1,-136
	ctx.r8.s64 = ctx.r1.s64 + -136;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r29,r1,-152
	r29.s64 = ctx.r1.s64 + -152;
	// addi r26,r25,-1
	r26.s64 = r25.s64 + -1;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r26,1
	r11.s64 = r26.s64 + 1;
	// li r23,-1
	r23.s64 = -1;
	// srawi r7,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r7.s64 = r11.s32 >> 5;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r6,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// mr r24,r27
	r24.u64 = r27.u64;
	// addze r31,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	r31.s64 = temp.s64;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// srawi r7,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r7.s64 = r11.s32 >> 5;
	// rlwinm r28,r31,2,0,29
	r28.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r9,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r9.s64 = temp.s64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// subfic r30,r11,31
	xer.ca = r11.u32 <= 31;
	r30.s64 = 31 - r11.s64;
	// slw r11,r3,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (ctx.r3.u32 << (r30.u8 & 0x3F));
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e74d4
	if (cr0.eq) goto loc_823E74D4;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// slw r9,r23,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r23.u32 << (r30.u8 & 0x3F));
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// andc. r11,r11,r9
	r11.u64 = r11.u64 & ~ctx.r9.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e743c
	if (!cr0.eq) goto loc_823E743C;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bge cr6,0x823e74d4
	if (!cr6.lt) goto loc_823E74D4;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823E741C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e743c
	if (!cr6.eq) goto loc_823E743C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x823e741c
	if (cr6.lt) goto loc_823E741C;
	// b 0x823e74d4
	goto loc_823E74D4;
loc_823E743C:
	// srawi r11,r26,5
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1F) != 0);
	r11.s64 = r26.s32 >> 5;
	// addi r8,r1,-152
	ctx.r8.s64 = ctx.r1.s64 + -152;
	// addze r9,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r11,r26,5
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1F) != 0);
	r11.s64 = r26.s32 >> 5;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r11,r26
	ctx.r10.s64 = r26.s64 - r11.s64;
	// lwzx r11,r7,r8
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// subfic r10,r10,31
	xer.ca = ctx.r10.u32 <= 31;
	ctx.r10.s64 = 31 - ctx.r10.s64;
	// slw r6,r3,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r10.u8 & 0x3F));
	// add r10,r11,r6
	ctx.r10.u64 = r11.u64 + ctx.r6.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823e7480
	if (cr6.lt) goto loc_823E7480;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// bge cr6,0x823e7484
	if (!cr6.lt) goto loc_823E7484;
loc_823E7480:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823E7484:
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r10,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r10.u32);
	// blt 0x823e74d4
	if (cr0.lt) goto loc_823E74D4;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823E749C:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x823e74d4
	if (cr6.eq) goto loc_823E74D4;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// blt cr6,0x823e74c0
	if (cr6.lt) goto loc_823E74C0;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bge cr6,0x823e74c4
	if (!cr6.lt) goto loc_823E74C4;
loc_823E74C0:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823E74C4:
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x823e749c
	if (!cr0.lt) goto loc_823E749C;
loc_823E74D4:
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// slw r9,r23,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r23.u32 << (r30.u8 & 0x3F));
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// stwx r10,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, ctx.r10.u32);
	// bge cr6,0x823e751c
	if (!cr6.lt) goto loc_823E751C;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// subfic r11,r11,3
	xer.ca = r11.u32 <= 3;
	r11.s64 = 3 - r11.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e751c
	if (cr6.eq) goto loc_823E751C;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_823E7510:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823e7510
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823E7510;
loc_823E751C:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x823e7528
	if (cr6.eq) goto loc_823E7528;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_823E7528:
	// lwz r11,4(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// subf r10,r25,r11
	ctx.r10.s64 = r11.s64 - r25.s64;
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// bge cr6,0x823e7554
	if (!cr6.lt) goto loc_823E7554;
	// addi r11,r1,-152
	r11.s64 = ctx.r1.s64 + -152;
	// mr r31,r22
	r31.u64 = r22.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r22.u32);
	// stw r22,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r22.u32);
	// b 0x823e799c
	goto loc_823E799C;
loc_823E7554:
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// bgt cr6,0x823e7830
	if (cr6.gt) goto loc_823E7830;
	// subf r11,r24,r11
	r11.s64 = r11.s64 - r24.s64;
	// addi r10,r1,-136
	ctx.r10.s64 = ctx.r1.s64 + -136;
	// srawi r9,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r9.s64 = r11.s32 >> 5;
	// addi r7,r1,-152
	ctx.r7.s64 = ctx.r1.s64 + -152;
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r9,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r9.s64 = r11.s32 >> 5;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// li r27,-1
	r27.s64 = -1;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,8(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// rlwinm r9,r9,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r31,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r31.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// slw r6,r27,r11
	ctx.r6.u64 = r11.u8 & 0x20 ? 0 : (r27.u32 << (r11.u8 & 0x3F));
	// stw r30,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r30.u32);
	// not r7,r6
	ctx.r7.u64 = ~ctx.r6.u64;
	// subfic r6,r11,32
	xer.ca = r11.u32 <= 32;
	ctx.r6.s64 = 32 - r11.s64;
loc_823E75B4:
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// and r30,r31,r7
	r30.u64 = r31.u64 & ctx.r7.u64;
	// stw r30,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, r30.u32);
	// srw r31,r31,r11
	r31.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 >> (r11.u8 & 0x3F));
	// or r8,r31,r8
	ctx.r8.u64 = r31.u64 | ctx.r8.u64;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,-160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// slw r8,r8,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// bne 0x823e75b4
	if (!cr0.eq) goto loc_823E75B4;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-144
	ctx.r8.s64 = ctx.r1.s64 + -144;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_823E75F4:
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x823e7608
	if (cr6.lt) goto loc_823E7608;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x823e760c
	goto loc_823E760C;
loc_823E7608:
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
loc_823E760C:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x823e75f4
	if (!cr0.lt) goto loc_823E75F4;
	// addi r11,r26,1
	r11.s64 = r26.s64 + 1;
	// addi r29,r1,-152
	r29.s64 = ctx.r1.s64 + -152;
	// srawi r10,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = r11.s32 >> 5;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r31.s64 = temp.s64;
	// srawi r10,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = r11.s32 >> 5;
	// rlwinm r28,r31,2,0,29
	r28.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// subfic r30,r11,31
	xer.ca = r11.u32 <= 31;
	r30.s64 = 31 - r11.s64;
	// slw r11,r3,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (ctx.r3.u32 << (r30.u8 & 0x3F));
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e7740
	if (cr0.eq) goto loc_823E7740;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// slw r9,r23,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r23.u32 << (r30.u8 & 0x3F));
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// andc. r11,r11,r9
	r11.u64 = r11.u64 & ~ctx.r9.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e76a4
	if (!cr0.eq) goto loc_823E76A4;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bge cr6,0x823e7740
	if (!cr6.lt) goto loc_823E7740;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823E7684:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e76a4
	if (!cr6.eq) goto loc_823E76A4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x823e7684
	if (cr6.lt) goto loc_823E7684;
	// b 0x823e7740
	goto loc_823E7740;
loc_823E76A4:
	// srawi r11,r26,5
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1F) != 0);
	r11.s64 = r26.s32 >> 5;
	// addi r7,r1,-152
	ctx.r7.s64 = ctx.r1.s64 + -152;
	// addze r9,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r11,r26,5
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1F) != 0);
	r11.s64 = r26.s32 >> 5;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r11,r26
	ctx.r10.s64 = r26.s64 - r11.s64;
	// lwzx r11,r8,r7
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// subfic r10,r10,31
	xer.ca = ctx.r10.u32 <= 31;
	ctx.r10.s64 = 31 - ctx.r10.s64;
	// slw r6,r3,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r10.u8 & 0x3F));
	// add r10,r11,r6
	ctx.r10.u64 = r11.u64 + ctx.r6.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823e76e8
	if (cr6.lt) goto loc_823E76E8;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// bge cr6,0x823e76ec
	if (!cr6.lt) goto loc_823E76EC;
loc_823E76E8:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823E76EC:
	// stwx r10,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r10.u32);
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// blt 0x823e7740
	if (cr0.lt) goto loc_823E7740;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-152
	ctx.r9.s64 = ctx.r1.s64 + -152;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_823E7708:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x823e7740
	if (cr6.eq) goto loc_823E7740;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// blt cr6,0x823e772c
	if (cr6.lt) goto loc_823E772C;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bge cr6,0x823e7730
	if (!cr6.lt) goto loc_823E7730;
loc_823E772C:
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
loc_823E7730:
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x823e7708
	if (!cr0.lt) goto loc_823E7708;
loc_823E7740:
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// slw r9,r23,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r23.u32 << (r30.u8 & 0x3F));
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// stwx r10,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, ctx.r10.u32);
	// bge cr6,0x823e7788
	if (!cr6.lt) goto loc_823E7788;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-152
	ctx.r9.s64 = ctx.r1.s64 + -152;
	// subfic r11,r11,3
	xer.ca = r11.u32 <= 3;
	r11.s64 = 3 - r11.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e7788
	if (cr6.eq) goto loc_823E7788;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_823E777C:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823e777c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823E777C;
loc_823E7788:
	// addi r11,r21,1
	r11.s64 = r21.s64 + 1;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// srawi r9,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r9.s64 = r11.s32 >> 5;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r7,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r7.s64 = r11.s32 >> 5;
	// li r9,3
	ctx.r9.s64 = 3;
	// addze r7,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r7,r7,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
	// slw r7,r27,r11
	ctx.r7.u64 = r11.u8 & 0x20 ? 0 : (r27.u32 << (r11.u8 & 0x3F));
	// not r7,r7
	ctx.r7.u64 = ~ctx.r7.u64;
	// subfic r6,r11,32
	xer.ca = r11.u32 <= 32;
	ctx.r6.s64 = 32 - r11.s64;
loc_823E77BC:
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// and r31,r3,r7
	r31.u64 = ctx.r3.u64 & ctx.r7.u64;
	// stw r31,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, r31.u32);
	// srw r3,r3,r11
	ctx.r3.u64 = r11.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (r11.u8 & 0x3F));
	// or r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 | ctx.r8.u64;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,-160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// slw r8,r8,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// bne 0x823e77bc
	if (!cr0.eq) goto loc_823E77BC;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-144
	ctx.r8.s64 = ctx.r1.s64 + -144;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_823E77FC:
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x823e7810
	if (cr6.lt) goto loc_823E7810;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x823e7814
	goto loc_823E7814;
loc_823E7810:
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
loc_823E7814:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x823e77fc
	if (!cr0.lt) goto loc_823E77FC;
	// mr r31,r22
	r31.u64 = r22.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x823e799c
	goto loc_823E799C;
loc_823E7830:
	// srawi r10,r21,5
	xer.ca = (r21.s32 < 0) & ((r21.u32 & 0x1F) != 0);
	ctx.r10.s64 = r21.s32 >> 5;
	// lwz r31,0(r20)
	r31.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// li r7,-1
	ctx.r7.s64 = -1;
	// addze r5,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r5.s64 = temp.s64;
	// cmpw cr6,r27,r31
	cr6.compare<int32_t>(r27.s32, r31.s32, xer);
	// srawi r10,r21,5
	xer.ca = (r21.s32 < 0) & ((r21.u32 & 0x1F) != 0);
	ctx.r10.s64 = r21.s32 >> 5;
	// blt cr6,0x823e78fc
	if (cr6.lt) goto loc_823E78FC;
	// addi r11,r1,-152
	r11.s64 = ctx.r1.s64 + -152;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r22.u32);
	// stw r22,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r22.u32);
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// li r9,3
	ctx.r9.s64 = 3;
	// subf r11,r11,r21
	r11.s64 = r21.s64 - r11.s64;
	// slw r7,r7,r11
	ctx.r7.u64 = r11.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r11.u8 & 0x3F));
	// lwz r30,-152(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -152);
	// not r7,r7
	ctx.r7.u64 = ~ctx.r7.u64;
	// subfic r6,r11,32
	xer.ca = r11.u32 <= 32;
	ctx.r6.s64 = 32 - r11.s64;
	// oris r30,r30,32768
	r30.u64 = r30.u64 | 2147483648;
	// stw r30,-152(r1)
	PPC_STORE_U32(ctx.r1.u32 + -152, r30.u32);
loc_823E7888:
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// and r29,r30,r7
	r29.u64 = r30.u64 & ctx.r7.u64;
	// stw r29,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, r29.u32);
	// srw r30,r30,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 >> (r11.u8 & 0x3F));
	// or r8,r30,r8
	ctx.r8.u64 = r30.u64 | ctx.r8.u64;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,-160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// slw r8,r8,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// bne 0x823e7888
	if (!cr0.eq) goto loc_823E7888;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-144
	ctx.r8.s64 = ctx.r1.s64 + -144;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_823E78C8:
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x823e78dc
	if (cr6.lt) goto loc_823E78DC;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x823e78e0
	goto loc_823E78E0;
loc_823E78DC:
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
loc_823E78E0:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x823e78c8
	if (!cr0.lt) goto loc_823E78C8;
	// lwz r11,20(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 20);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// b 0x823e799c
	goto loc_823E799C;
loc_823E78FC:
	// lwz r11,20(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 20);
	// lwz r9,-152(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -152);
	// add r31,r11,r27
	r31.u64 = r11.u64 + r27.u64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// clrlwi r10,r9,1
	ctx.r10.u64 = ctx.r9.u32 & 0x7FFFFFFF;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r10,-152(r1)
	PPC_STORE_U32(ctx.r1.u32 + -152, ctx.r10.u32);
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// subf r11,r11,r21
	r11.s64 = r21.s64 - r11.s64;
	// slw r9,r7,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r11.u8 & 0x3F));
	// not r7,r9
	ctx.r7.u64 = ~ctx.r9.u64;
	// subfic r6,r11,32
	xer.ca = r11.u32 <= 32;
	ctx.r6.s64 = 32 - r11.s64;
	// li r9,3
	ctx.r9.s64 = 3;
loc_823E7930:
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// and r30,r3,r7
	r30.u64 = ctx.r3.u64 & ctx.r7.u64;
	// stw r30,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, r30.u32);
	// srw r3,r3,r11
	ctx.r3.u64 = r11.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (r11.u8 & 0x3F));
	// or r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 | ctx.r8.u64;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,-160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// slw r8,r8,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// bne 0x823e7930
	if (!cr0.eq) goto loc_823E7930;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-144
	ctx.r8.s64 = ctx.r1.s64 + -144;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_823E7970:
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x823e7984
	if (cr6.lt) goto loc_823E7984;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x823e7988
	goto loc_823E7988;
loc_823E7984:
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
loc_823E7988:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x823e7970
	if (!cr0.lt) goto loc_823E7970;
loc_823E7998:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_823E799C:
	// subfic r11,r21,31
	xer.ca = r21.u32 <= 31;
	r11.s64 = 31 - r21.s64;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// bne cr6,0x823e79b0
	if (!cr6.eq) goto loc_823E79B0;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
loc_823E79B0:
	// slw r9,r31,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 << (r11.u8 & 0x3F));
	// lwz r11,16(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 16);
	// lwz r8,-152(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -152);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// bne cr6,0x823e79d8
	if (!cr6.eq) goto loc_823E79D8;
	// lwz r11,-148(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -148);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// b 0x823e79e0
	goto loc_823E79E0;
loc_823E79D8:
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// bne cr6,0x823e79e4
	if (!cr6.eq) goto loc_823E79E4;
loc_823E79E0:
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_823E79E4:
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_823E79E8"))) PPC_WEAK_FUNC(sub_823E79E8);
PPC_FUNC_IMPL(__imp__sub_823E79E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x823E79F0;
	// lhz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lhz r8,10(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// li r22,0
	r22.s64 = 0;
	// clrlwi r11,r9,17
	r11.u64 = ctx.r9.u32 & 0x7FFF;
	// lwz r7,2(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2);
	// lwz r6,6(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 6);
	// addi r20,r10,-16656
	r20.s64 = ctx.r10.s64 + -16656;
	// addi r27,r11,-16383
	r27.s64 = r11.s64 + -16383;
	// rotlwi r11,r8,16
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 16);
	// rlwinm r19,r9,0,0,16
	r19.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFF8000;
	// stw r7,-152(r1)
	PPC_STORE_U32(ctx.r1.u32 + -152, ctx.r7.u32);
	// cmpwi cr6,r27,-16383
	cr6.compare<int32_t>(r27.s32, -16383, xer);
	// lwz r21,12(r20)
	r21.u64 = PPC_LOAD_U32(r20.u32 + 12);
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// stw r6,-148(r1)
	PPC_STORE_U32(ctx.r1.u32 + -148, ctx.r6.u32);
	// stw r11,-144(r1)
	PPC_STORE_U32(ctx.r1.u32 + -144, r11.u32);
	// bne cr6,0x823e7a78
	if (!cr6.eq) goto loc_823E7A78;
	// mr r31,r22
	r31.u64 = r22.u64;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_823E7A40:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e7a60
	if (!cr6.eq) goto loc_823E7A60;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x823e7a40
	if (cr6.lt) goto loc_823E7A40;
	// b 0x823e8090
	goto loc_823E8090;
loc_823E7A60:
	// addi r11,r1,-152
	r11.s64 = ctx.r1.s64 + -152;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r22.u32);
	// stw r22,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r22.u32);
	// b 0x823e8094
	goto loc_823E8094;
loc_823E7A78:
	// lwz r25,8(r20)
	r25.u64 = PPC_LOAD_U32(r20.u32 + 8);
	// addi r8,r1,-136
	ctx.r8.s64 = ctx.r1.s64 + -136;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r29,r1,-152
	r29.s64 = ctx.r1.s64 + -152;
	// addi r26,r25,-1
	r26.s64 = r25.s64 + -1;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r26,1
	r11.s64 = r26.s64 + 1;
	// li r23,-1
	r23.s64 = -1;
	// srawi r7,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r7.s64 = r11.s32 >> 5;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r6,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// mr r24,r27
	r24.u64 = r27.u64;
	// addze r31,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	r31.s64 = temp.s64;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// srawi r7,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r7.s64 = r11.s32 >> 5;
	// rlwinm r28,r31,2,0,29
	r28.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r9,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r9.s64 = temp.s64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// subfic r30,r11,31
	xer.ca = r11.u32 <= 31;
	r30.s64 = 31 - r11.s64;
	// slw r11,r3,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (ctx.r3.u32 << (r30.u8 & 0x3F));
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e7bcc
	if (cr0.eq) goto loc_823E7BCC;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// slw r9,r23,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r23.u32 << (r30.u8 & 0x3F));
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// andc. r11,r11,r9
	r11.u64 = r11.u64 & ~ctx.r9.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e7b34
	if (!cr0.eq) goto loc_823E7B34;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bge cr6,0x823e7bcc
	if (!cr6.lt) goto loc_823E7BCC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823E7B14:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e7b34
	if (!cr6.eq) goto loc_823E7B34;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x823e7b14
	if (cr6.lt) goto loc_823E7B14;
	// b 0x823e7bcc
	goto loc_823E7BCC;
loc_823E7B34:
	// srawi r11,r26,5
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1F) != 0);
	r11.s64 = r26.s32 >> 5;
	// addi r8,r1,-152
	ctx.r8.s64 = ctx.r1.s64 + -152;
	// addze r9,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r11,r26,5
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1F) != 0);
	r11.s64 = r26.s32 >> 5;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r11,r26
	ctx.r10.s64 = r26.s64 - r11.s64;
	// lwzx r11,r7,r8
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// subfic r10,r10,31
	xer.ca = ctx.r10.u32 <= 31;
	ctx.r10.s64 = 31 - ctx.r10.s64;
	// slw r6,r3,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r10.u8 & 0x3F));
	// add r10,r11,r6
	ctx.r10.u64 = r11.u64 + ctx.r6.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823e7b78
	if (cr6.lt) goto loc_823E7B78;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// bge cr6,0x823e7b7c
	if (!cr6.lt) goto loc_823E7B7C;
loc_823E7B78:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823E7B7C:
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r10,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r10.u32);
	// blt 0x823e7bcc
	if (cr0.lt) goto loc_823E7BCC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823E7B94:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x823e7bcc
	if (cr6.eq) goto loc_823E7BCC;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// blt cr6,0x823e7bb8
	if (cr6.lt) goto loc_823E7BB8;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bge cr6,0x823e7bbc
	if (!cr6.lt) goto loc_823E7BBC;
loc_823E7BB8:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823E7BBC:
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x823e7b94
	if (!cr0.lt) goto loc_823E7B94;
loc_823E7BCC:
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// slw r9,r23,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r23.u32 << (r30.u8 & 0x3F));
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// stwx r10,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, ctx.r10.u32);
	// bge cr6,0x823e7c14
	if (!cr6.lt) goto loc_823E7C14;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// subfic r11,r11,3
	xer.ca = r11.u32 <= 3;
	r11.s64 = 3 - r11.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e7c14
	if (cr6.eq) goto loc_823E7C14;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_823E7C08:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823e7c08
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823E7C08;
loc_823E7C14:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x823e7c20
	if (cr6.eq) goto loc_823E7C20;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_823E7C20:
	// lwz r11,4(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// subf r10,r25,r11
	ctx.r10.s64 = r11.s64 - r25.s64;
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// bge cr6,0x823e7c4c
	if (!cr6.lt) goto loc_823E7C4C;
	// addi r11,r1,-152
	r11.s64 = ctx.r1.s64 + -152;
	// mr r31,r22
	r31.u64 = r22.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r22.u32);
	// stw r22,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r22.u32);
	// b 0x823e8094
	goto loc_823E8094;
loc_823E7C4C:
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// bgt cr6,0x823e7f28
	if (cr6.gt) goto loc_823E7F28;
	// subf r11,r24,r11
	r11.s64 = r11.s64 - r24.s64;
	// addi r10,r1,-136
	ctx.r10.s64 = ctx.r1.s64 + -136;
	// srawi r9,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r9.s64 = r11.s32 >> 5;
	// addi r7,r1,-152
	ctx.r7.s64 = ctx.r1.s64 + -152;
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r9,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r9.s64 = r11.s32 >> 5;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// li r27,-1
	r27.s64 = -1;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,8(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// rlwinm r9,r9,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r31,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r31.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// slw r6,r27,r11
	ctx.r6.u64 = r11.u8 & 0x20 ? 0 : (r27.u32 << (r11.u8 & 0x3F));
	// stw r30,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r30.u32);
	// not r7,r6
	ctx.r7.u64 = ~ctx.r6.u64;
	// subfic r6,r11,32
	xer.ca = r11.u32 <= 32;
	ctx.r6.s64 = 32 - r11.s64;
loc_823E7CAC:
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// and r30,r31,r7
	r30.u64 = r31.u64 & ctx.r7.u64;
	// stw r30,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, r30.u32);
	// srw r31,r31,r11
	r31.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 >> (r11.u8 & 0x3F));
	// or r8,r31,r8
	ctx.r8.u64 = r31.u64 | ctx.r8.u64;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,-160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// slw r8,r8,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// bne 0x823e7cac
	if (!cr0.eq) goto loc_823E7CAC;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-144
	ctx.r8.s64 = ctx.r1.s64 + -144;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_823E7CEC:
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x823e7d00
	if (cr6.lt) goto loc_823E7D00;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x823e7d04
	goto loc_823E7D04;
loc_823E7D00:
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
loc_823E7D04:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x823e7cec
	if (!cr0.lt) goto loc_823E7CEC;
	// addi r11,r26,1
	r11.s64 = r26.s64 + 1;
	// addi r29,r1,-152
	r29.s64 = ctx.r1.s64 + -152;
	// srawi r10,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = r11.s32 >> 5;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r31.s64 = temp.s64;
	// srawi r10,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = r11.s32 >> 5;
	// rlwinm r28,r31,2,0,29
	r28.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// subfic r30,r11,31
	xer.ca = r11.u32 <= 31;
	r30.s64 = 31 - r11.s64;
	// slw r11,r3,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (ctx.r3.u32 << (r30.u8 & 0x3F));
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e7e38
	if (cr0.eq) goto loc_823E7E38;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// slw r9,r23,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r23.u32 << (r30.u8 & 0x3F));
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// andc. r11,r11,r9
	r11.u64 = r11.u64 & ~ctx.r9.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e7d9c
	if (!cr0.eq) goto loc_823E7D9C;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bge cr6,0x823e7e38
	if (!cr6.lt) goto loc_823E7E38;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823E7D7C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e7d9c
	if (!cr6.eq) goto loc_823E7D9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x823e7d7c
	if (cr6.lt) goto loc_823E7D7C;
	// b 0x823e7e38
	goto loc_823E7E38;
loc_823E7D9C:
	// srawi r11,r26,5
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1F) != 0);
	r11.s64 = r26.s32 >> 5;
	// addi r7,r1,-152
	ctx.r7.s64 = ctx.r1.s64 + -152;
	// addze r9,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r11,r26,5
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1F) != 0);
	r11.s64 = r26.s32 >> 5;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r11,r26
	ctx.r10.s64 = r26.s64 - r11.s64;
	// lwzx r11,r8,r7
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// subfic r10,r10,31
	xer.ca = ctx.r10.u32 <= 31;
	ctx.r10.s64 = 31 - ctx.r10.s64;
	// slw r6,r3,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r10.u8 & 0x3F));
	// add r10,r11,r6
	ctx.r10.u64 = r11.u64 + ctx.r6.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823e7de0
	if (cr6.lt) goto loc_823E7DE0;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// bge cr6,0x823e7de4
	if (!cr6.lt) goto loc_823E7DE4;
loc_823E7DE0:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823E7DE4:
	// stwx r10,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r10.u32);
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// blt 0x823e7e38
	if (cr0.lt) goto loc_823E7E38;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-152
	ctx.r9.s64 = ctx.r1.s64 + -152;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_823E7E00:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x823e7e38
	if (cr6.eq) goto loc_823E7E38;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// blt cr6,0x823e7e24
	if (cr6.lt) goto loc_823E7E24;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bge cr6,0x823e7e28
	if (!cr6.lt) goto loc_823E7E28;
loc_823E7E24:
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
loc_823E7E28:
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x823e7e00
	if (!cr0.lt) goto loc_823E7E00;
loc_823E7E38:
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// slw r9,r23,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r23.u32 << (r30.u8 & 0x3F));
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// stwx r10,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, ctx.r10.u32);
	// bge cr6,0x823e7e80
	if (!cr6.lt) goto loc_823E7E80;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,-152
	ctx.r9.s64 = ctx.r1.s64 + -152;
	// subfic r11,r11,3
	xer.ca = r11.u32 <= 3;
	r11.s64 = 3 - r11.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e7e80
	if (cr6.eq) goto loc_823E7E80;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_823E7E74:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823e7e74
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823E7E74;
loc_823E7E80:
	// addi r11,r21,1
	r11.s64 = r21.s64 + 1;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// srawi r9,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r9.s64 = r11.s32 >> 5;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r7,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r7.s64 = r11.s32 >> 5;
	// li r9,3
	ctx.r9.s64 = 3;
	// addze r7,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r7,r7,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
	// slw r7,r27,r11
	ctx.r7.u64 = r11.u8 & 0x20 ? 0 : (r27.u32 << (r11.u8 & 0x3F));
	// not r7,r7
	ctx.r7.u64 = ~ctx.r7.u64;
	// subfic r6,r11,32
	xer.ca = r11.u32 <= 32;
	ctx.r6.s64 = 32 - r11.s64;
loc_823E7EB4:
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// and r31,r3,r7
	r31.u64 = ctx.r3.u64 & ctx.r7.u64;
	// stw r31,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, r31.u32);
	// srw r3,r3,r11
	ctx.r3.u64 = r11.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (r11.u8 & 0x3F));
	// or r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 | ctx.r8.u64;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,-160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// slw r8,r8,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// bne 0x823e7eb4
	if (!cr0.eq) goto loc_823E7EB4;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-144
	ctx.r8.s64 = ctx.r1.s64 + -144;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_823E7EF4:
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x823e7f08
	if (cr6.lt) goto loc_823E7F08;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x823e7f0c
	goto loc_823E7F0C;
loc_823E7F08:
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
loc_823E7F0C:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x823e7ef4
	if (!cr0.lt) goto loc_823E7EF4;
	// mr r31,r22
	r31.u64 = r22.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x823e8094
	goto loc_823E8094;
loc_823E7F28:
	// srawi r10,r21,5
	xer.ca = (r21.s32 < 0) & ((r21.u32 & 0x1F) != 0);
	ctx.r10.s64 = r21.s32 >> 5;
	// lwz r31,0(r20)
	r31.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// li r7,-1
	ctx.r7.s64 = -1;
	// addze r5,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r5.s64 = temp.s64;
	// cmpw cr6,r27,r31
	cr6.compare<int32_t>(r27.s32, r31.s32, xer);
	// srawi r10,r21,5
	xer.ca = (r21.s32 < 0) & ((r21.u32 & 0x1F) != 0);
	ctx.r10.s64 = r21.s32 >> 5;
	// blt cr6,0x823e7ff4
	if (cr6.lt) goto loc_823E7FF4;
	// addi r11,r1,-152
	r11.s64 = ctx.r1.s64 + -152;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
	// stw r22,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r22.u32);
	// stw r22,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r22.u32);
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// li r9,3
	ctx.r9.s64 = 3;
	// subf r11,r11,r21
	r11.s64 = r21.s64 - r11.s64;
	// slw r7,r7,r11
	ctx.r7.u64 = r11.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r11.u8 & 0x3F));
	// lwz r30,-152(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -152);
	// not r7,r7
	ctx.r7.u64 = ~ctx.r7.u64;
	// subfic r6,r11,32
	xer.ca = r11.u32 <= 32;
	ctx.r6.s64 = 32 - r11.s64;
	// oris r30,r30,32768
	r30.u64 = r30.u64 | 2147483648;
	// stw r30,-152(r1)
	PPC_STORE_U32(ctx.r1.u32 + -152, r30.u32);
loc_823E7F80:
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// and r29,r30,r7
	r29.u64 = r30.u64 & ctx.r7.u64;
	// stw r29,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, r29.u32);
	// srw r30,r30,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (r30.u32 >> (r11.u8 & 0x3F));
	// or r8,r30,r8
	ctx.r8.u64 = r30.u64 | ctx.r8.u64;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,-160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// slw r8,r8,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// bne 0x823e7f80
	if (!cr0.eq) goto loc_823E7F80;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-144
	ctx.r8.s64 = ctx.r1.s64 + -144;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_823E7FC0:
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x823e7fd4
	if (cr6.lt) goto loc_823E7FD4;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x823e7fd8
	goto loc_823E7FD8;
loc_823E7FD4:
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
loc_823E7FD8:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x823e7fc0
	if (!cr0.lt) goto loc_823E7FC0;
	// lwz r11,20(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 20);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// b 0x823e8094
	goto loc_823E8094;
loc_823E7FF4:
	// lwz r11,20(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 20);
	// lwz r9,-152(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -152);
	// add r31,r11,r27
	r31.u64 = r11.u64 + r27.u64;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// clrlwi r10,r9,1
	ctx.r10.u64 = ctx.r9.u32 & 0x7FFFFFFF;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r10,-152(r1)
	PPC_STORE_U32(ctx.r1.u32 + -152, ctx.r10.u32);
	// addi r10,r1,-152
	ctx.r10.s64 = ctx.r1.s64 + -152;
	// subf r11,r11,r21
	r11.s64 = r21.s64 - r11.s64;
	// slw r9,r7,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r11.u8 & 0x3F));
	// not r7,r9
	ctx.r7.u64 = ~ctx.r9.u64;
	// subfic r6,r11,32
	xer.ca = r11.u32 <= 32;
	ctx.r6.s64 = 32 - r11.s64;
	// li r9,3
	ctx.r9.s64 = 3;
loc_823E8028:
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// and r30,r3,r7
	r30.u64 = ctx.r3.u64 & ctx.r7.u64;
	// stw r30,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, r30.u32);
	// srw r3,r3,r11
	ctx.r3.u64 = r11.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (r11.u8 & 0x3F));
	// or r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 | ctx.r8.u64;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,-160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// slw r8,r8,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r6.u8 & 0x3F));
	// bne 0x823e8028
	if (!cr0.eq) goto loc_823E8028;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,-144
	ctx.r8.s64 = ctx.r1.s64 + -144;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r1,-144
	r11.s64 = ctx.r1.s64 + -144;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_823E8068:
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x823e807c
	if (cr6.lt) goto loc_823E807C;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x823e8080
	goto loc_823E8080;
loc_823E807C:
	// stw r22,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r22.u32);
loc_823E8080:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x823e8068
	if (!cr0.lt) goto loc_823E8068;
loc_823E8090:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_823E8094:
	// subfic r11,r21,31
	xer.ca = r21.u32 <= 31;
	r11.s64 = 31 - r21.s64;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// bne cr6,0x823e80a8
	if (!cr6.eq) goto loc_823E80A8;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
loc_823E80A8:
	// slw r9,r31,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 << (r11.u8 & 0x3F));
	// lwz r11,16(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 16);
	// lwz r8,-152(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -152);
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// bne cr6,0x823e80d0
	if (!cr6.eq) goto loc_823E80D0;
	// lwz r11,-148(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -148);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// b 0x823e80d8
	goto loc_823E80D8;
loc_823E80D0:
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// bne cr6,0x823e80dc
	if (!cr6.eq) goto loc_823E80DC;
loc_823E80D8:
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_823E80DC:
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_823E80E0"))) PPC_WEAK_FUNC(sub_823E80E0);
PPC_FUNC_IMPL(__imp__sub_823E80E0) {
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
	ctx.lr = 0x823E80E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r27,16462
	r27.s64 = 16462;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// beq cr6,0x823e82d0
	if (cr6.eq) goto loc_823E82D0;
loc_823E8114:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x823E8124;
	sub_823DA950(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r6,r10,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,1,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// or r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 | ctx.r6.u64;
	// or r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 | r11.u64;
	// rotlwi r5,r6,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r6,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r10,2,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x1;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// or r6,r7,r6
	ctx.r6.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// add r7,r11,r8
	ctx.r7.u64 = r11.u64 + ctx.r8.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blt cr6,0x823e81a0
	if (cr6.lt) goto loc_823E81A0;
	// cmplw cr6,r7,r8
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, xer);
	// bge cr6,0x823e81a4
	if (!cr6.lt) goto loc_823E81A4;
loc_823E81A0:
	// li r9,1
	ctx.r9.s64 = 1;
loc_823E81A4:
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823e81e0
	if (cr6.eq) goto loc_823E81E0;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823e81c8
	if (cr6.lt) goto loc_823E81C8;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bge cr6,0x823e81cc
	if (!cr6.lt) goto loc_823E81CC;
loc_823E81C8:
	// li r9,1
	ctx.r9.s64 = 1;
loc_823E81CC:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823e81e0
	if (cr6.eq) goto loc_823E81E0;
	// addi r11,r6,1
	r11.s64 = ctx.r6.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E81E0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r10,r11,r8
	ctx.r10.u64 = r11.u64 + ctx.r8.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823e8200
	if (cr6.lt) goto loc_823E8200;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bge cr6,0x823e8204
	if (!cr6.lt) goto loc_823E8204;
loc_823E8200:
	// li r9,1
	ctx.r9.s64 = 1;
loc_823E8204:
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823e821c
	if (cr6.eq) goto loc_823E821C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E821C:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r6,r7,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r10,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r11,r7,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// or r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 | ctx.r6.u64;
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823e8278
	if (cr6.lt) goto loc_823E8278;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x823e827c
	if (!cr6.lt) goto loc_823E827C;
loc_823E8278:
	// li r7,1
	ctx.r7.s64 = 1;
loc_823E827C:
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x823e82b8
	if (cr6.eq) goto loc_823E82B8;
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x823e82a0
	if (cr6.lt) goto loc_823E82A0;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bge cr6,0x823e82a4
	if (!cr6.lt) goto loc_823E82A4;
loc_823E82A0:
	// li r10,1
	ctx.r10.s64 = 1;
loc_823E82A4:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823e82b8
	if (cr6.eq) goto loc_823E82B8;
	// addi r11,r6,1
	r11.s64 = ctx.r6.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E82B8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x823e8114
	if (!cr0.eq) goto loc_823E8114;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e835c
	if (!cr6.eq) goto loc_823E835C;
loc_823E82D0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// clrlwi r10,r27,16
	ctx.r10.u64 = r27.u32 & 0xFFFF;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r8,r11,16,16,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// rlwinm r11,r11,16,0,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r9,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// rlwinm r9,r9,16,16,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF;
	// addis r11,r10,1
	r11.s64 = ctx.r10.s64 + 65536;
	// or r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 | ctx.r8.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// clrlwi r27,r11,16
	r27.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823e82d0
	if (cr6.eq) goto loc_823E82D0;
	// b 0x823e835c
	goto loc_823E835C;
loc_823E8318:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r10,r27,16
	ctx.r10.u64 = r27.u32 & 0xFFFF;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r7,r11,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r8,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addis r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 65536;
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// clrlwi r27,r10,16
	r27.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_823E835C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm. r11,r11,0,16,16
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e8318
	if (cr0.eq) goto loc_823E8318;
	// sth r27,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r27.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823E8374"))) PPC_WEAK_FUNC(sub_823E8374);
PPC_FUNC_IMPL(__imp__sub_823E8374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E8378"))) PPC_WEAK_FUNC(sub_823E8378);
PPC_FUNC_IMPL(__imp__sub_823E8378) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x823E8380;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r3,336(r1)
	PPC_STORE_U64(ctx.r1.u32 + 336, ctx.r3.u64);
	// li r11,204
	r11.s64 = 204;
	// lhz r9,336(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 336);
	// rlwinm. r10,r9,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFF8000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// stw r5,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r5.u32);
	// stw r6,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r6.u32);
	// clrlwi r8,r9,17
	ctx.r8.u64 = ctx.r9.u32 & 0x7FFF;
	// li r6,1
	ctx.r6.s64 = 1;
	// stb r11,138(r1)
	PPC_STORE_U8(ctx.r1.u32 + 138, r11.u8);
	// li r7,63
	ctx.r7.s64 = 63;
	// stb r11,139(r1)
	PPC_STORE_U8(ctx.r1.u32 + 139, r11.u8);
	// li r5,251
	ctx.r5.s64 = 251;
	// stb r11,140(r1)
	PPC_STORE_U8(ctx.r1.u32 + 140, r11.u8);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stb r11,141(r1)
	PPC_STORE_U8(ctx.r1.u32 + 141, r11.u8);
	// stb r11,142(r1)
	PPC_STORE_U8(ctx.r1.u32 + 142, r11.u8);
	// stb r11,143(r1)
	PPC_STORE_U8(ctx.r1.u32 + 143, r11.u8);
	// stb r11,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, r11.u8);
	// stb r11,145(r1)
	PPC_STORE_U8(ctx.r1.u32 + 145, r11.u8);
	// stb r11,146(r1)
	PPC_STORE_U8(ctx.r1.u32 + 146, r11.u8);
	// stb r11,147(r1)
	PPC_STORE_U8(ctx.r1.u32 + 147, r11.u8);
	// li r11,45
	r11.s64 = 45;
	// std r4,344(r1)
	PPC_STORE_U64(ctx.r1.u32 + 344, ctx.r4.u64);
	// stw r31,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, r31.u32);
	// stb r7,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, ctx.r7.u8);
	// stb r5,137(r1)
	PPC_STORE_U8(ctx.r1.u32 + 137, ctx.r5.u8);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bne 0x823e8400
	if (!cr0.eq) goto loc_823E8400;
	// li r11,32
	r11.s64 = 32;
loc_823E8400:
	// stb r11,2(r31)
	PPC_STORE_U8(r31.u32 + 2, r11.u8);
	// clrlwi. r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r7,342(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 342);
	// lwz r10,338(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 338);
	// bne 0x823e8458
	if (!cr0.eq) goto loc_823E8458;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823e8458
	if (!cr6.eq) goto loc_823E8458;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x823e8458
	if (!cr6.eq) goto loc_823E8458;
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r9,32768
	cr6.compare<uint32_t>(ctx.r9.u32, 32768, xer);
	// sth r22,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r22.u16);
	// li r11,45
	r11.s64 = 45;
	// beq cr6,0x823e843c
	if (cr6.eq) goto loc_823E843C;
	// li r11,32
	r11.s64 = 32;
loc_823E843C:
	// li r10,48
	ctx.r10.s64 = 48;
	// stb r6,3(r31)
	PPC_STORE_U8(r31.u32 + 3, ctx.r6.u8);
	// stb r22,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r22.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,2(r31)
	PPC_STORE_U8(r31.u32 + 2, r11.u8);
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
	// b 0x823e8fe8
	goto loc_823E8FE8;
loc_823E8458:
	// cmplwi cr6,r11,32767
	cr6.compare<uint32_t>(r11.u32, 32767, xer);
	// lis r14,-32768
	r14.s64 = -2147483648;
	// bne cr6,0x823e8544
	if (!cr6.eq) goto loc_823E8544;
	// sth r6,0(r31)
	PPC_STORE_U16(r31.u32 + 0, ctx.r6.u16);
	// cmplw cr6,r10,r14
	cr6.compare<uint32_t>(ctx.r10.u32, r14.u32, xer);
	// bne cr6,0x823e8478
	if (!cr6.eq) goto loc_823E8478;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823e848c
	if (cr6.eq) goto loc_823E848C;
loc_823E8478:
	// rlwinm. r11,r10,0,1,1
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e848c
	if (!cr0.eq) goto loc_823E848C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r5,r11,-4608
	ctx.r5.s64 = r11.s64 + -4608;
	// b 0x823e8508
	goto loc_823E8508;
loc_823E848C:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823e84b4
	if (cr6.eq) goto loc_823E84B4;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823e84b4
	if (!cr6.eq) goto loc_823E84B4;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x823e8500
	if (!cr6.eq) goto loc_823E8500;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r5,r11,-4616
	ctx.r5.s64 = r11.s64 + -4616;
	// b 0x823e84cc
	goto loc_823E84CC;
loc_823E84B4:
	// cmplw cr6,r10,r14
	cr6.compare<uint32_t>(ctx.r10.u32, r14.u32, xer);
	// bne cr6,0x823e8500
	if (!cr6.eq) goto loc_823E8500;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x823e8500
	if (!cr6.eq) goto loc_823E8500;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r5,r11,-4624
	ctx.r5.s64 = r11.s64 + -4624;
loc_823E84CC:
	// li r4,22
	ctx.r4.s64 = 22;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x823e2530
	ctx.lr = 0x823E84D8;
	sub_823E2530(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e84f8
	if (cr0.eq) goto loc_823E84F8;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02f0
	ctx.lr = 0x823E84F8;
	sub_823E02F0(ctx, base);
loc_823E84F8:
	// li r11,5
	r11.s64 = 5;
	// b 0x823e8538
	goto loc_823E8538;
loc_823E8500:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r5,r11,-4632
	ctx.r5.s64 = r11.s64 + -4632;
loc_823E8508:
	// li r4,22
	ctx.r4.s64 = 22;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x823e2530
	ctx.lr = 0x823E8514;
	sub_823E2530(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e8534
	if (cr0.eq) goto loc_823E8534;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02f0
	ctx.lr = 0x823E8534;
	sub_823E02F0(ctx, base);
loc_823E8534:
	// li r11,6
	r11.s64 = 6;
loc_823E8538:
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,3(r31)
	PPC_STORE_U8(r31.u32 + 3, r11.u8);
	// b 0x823e8fe8
	goto loc_823E8FE8;
loc_823E8544:
	// rlwinm r9,r10,9,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FE;
	// stw r10,90(r1)
	PPC_STORE_U32(ctx.r1.u32 + 90, ctx.r10.u32);
	// rlwinm r10,r11,24,8,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFFFFFF;
	// stw r7,94(r1)
	PPC_STORE_U32(ctx.r1.u32 + 94, ctx.r7.u32);
	// mulli r11,r11,19728
	r11.s64 = r11.s64 * 19728;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// mulli r10,r10,77
	ctx.r10.s64 = ctx.r10.s64 * 77;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// li r22,0
	r22.s64 = 0;
	// addis r11,r11,-4931
	r11.s64 = r11.s64 + -323158016;
	// lis r10,0
	ctx.r10.s64 = 0;
	// sth r22,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, r22.u16);
	// addi r11,r11,-4852
	r11.s64 = r11.s64 + -4852;
	// lis r7,0
	ctx.r7.s64 = 0;
	// srawi r11,r11,16
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFF) != 0);
	r11.s64 = r11.s32 >> 16;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// extsh r19,r11
	r19.s64 = r11.s16;
	// lis r5,0
	ctx.r5.s64 = 0;
	// mr r24,r19
	r24.u64 = r19.u64;
	// lis r4,32767
	ctx.r4.s64 = 2147418112;
	// addi r11,r9,-16632
	r11.s64 = ctx.r9.s64 + -16632;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// neg. r25,r24
	r25.s64 = -r24.s64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// sth r30,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, r30.u16);
	// ori r20,r10,49154
	r20.u64 = ctx.r10.u64 | 49154;
	// ori r21,r7,65535
	r21.u64 = ctx.r7.u64 | 65535;
	// ori r17,r6,32768
	r17.u64 = ctx.r6.u64 | 32768;
	// ori r18,r5,32768
	r18.u64 = ctx.r5.u64 | 32768;
	// li r15,-32768
	r15.s64 = -32768;
	// ori r16,r4,32768
	r16.u64 = ctx.r4.u64 | 32768;
	// addi r23,r11,-96
	r23.s64 = r11.s64 + -96;
	// beq 0x823e8988
	if (cr0.eq) goto loc_823E8988;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bge cr6,0x823e85e4
	if (!cr6.lt) goto loc_823E85E4;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// neg r25,r25
	r25.s64 = -r25.s64;
	// addi r11,r11,-16280
	r11.s64 = r11.s64 + -16280;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// addi r23,r11,-96
	r23.s64 = r11.s64 + -96;
loc_823E85E4:
	// beq cr6,0x823e8988
	if (cr6.eq) goto loc_823E8988;
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r28,92(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_823E85F0:
	// clrlwi. r11,r25,29
	r11.u64 = r25.u32 & 0x7;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r23,r23,84
	r23.s64 = r23.s64 + 84;
	// srawi r25,r25,3
	xer.ca = (r25.s32 < 0) & ((r25.u32 & 0x7) != 0);
	r25.s64 = r25.s32 >> 3;
	// beq 0x823e8978
	if (cr0.eq) goto loc_823E8978;
	// mulli r11,r11,12
	r11.s64 = r11.s64 * 12;
	// add r4,r11,r23
	ctx.r4.u64 = r11.u64 + r23.u64;
	// lhz r11,10(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 10);
	// cmplwi cr6,r11,32768
	cr6.compare<uint32_t>(r11.u32, 32768, xer);
	// blt cr6,0x823e8630
	if (cr6.lt) goto loc_823E8630;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x823da950
	ctx.lr = 0x823E8620;
	sub_823DA950(ctx, base);
	// lwz r11,158(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 158);
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,158(r1)
	PPC_STORE_U32(ctx.r1.u32 + 158, r11.u32);
loc_823E8630:
	// stw r22,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r22.u32);
	// clrlwi r11,r30,17
	r11.u64 = r30.u32 & 0x7FFF;
	// stw r22,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r22.u32);
	// clrlwi r9,r30,16
	ctx.r9.u64 = r30.u32 & 0xFFFF;
	// stw r22,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r22.u32);
	// mr r29,r22
	r29.u64 = r22.u64;
	// cmplwi cr6,r11,32767
	cr6.compare<uint32_t>(r11.u32, 32767, xer);
	// lhz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// clrlwi r10,r8,17
	ctx.r10.u64 = ctx.r8.u32 & 0x7FFF;
	// xor r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rlwinm r26,r8,0,16,16
	r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8000;
	// clrlwi r30,r7,16
	r30.u64 = ctx.r7.u32 & 0xFFFF;
	// bge cr6,0x823e8958
	if (!cr6.lt) goto loc_823E8958;
	// cmplwi cr6,r10,32767
	cr6.compare<uint32_t>(ctx.r10.u32, 32767, xer);
	// bge cr6,0x823e8958
	if (!cr6.lt) goto loc_823E8958;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// cmplwi cr6,r11,49149
	cr6.compare<uint32_t>(r11.u32, 49149, xer);
	// bgt cr6,0x823e8958
	if (cr6.gt) goto loc_823E8958;
	// cmplwi cr6,r11,16319
	cr6.compare<uint32_t>(r11.u32, 16319, xer);
	// bgt cr6,0x823e8690
	if (cr6.gt) goto loc_823E8690;
loc_823E8688:
	// stw r22,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r22.u32);
	// b 0x823e8968
	goto loc_823E8968;
loc_823E8690:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e86c4
	if (!cr6.eq) goto loc_823E86C4;
	// lwz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi. r9,r9,1
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFFFFFF;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// bne 0x823e86c4
	if (!cr0.eq) goto loc_823E86C4;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823e86c4
	if (!cr6.eq) goto loc_823E86C4;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x823e86c4
	if (!cr6.eq) goto loc_823E86C4;
	// sth r22,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, r22.u16);
	// b 0x823e8978
	goto loc_823E8978;
loc_823E86C4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823e86fc
	if (!cr6.eq) goto loc_823E86FC;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi. r10,r10,1
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// bne 0x823e86fc
	if (!cr0.eq) goto loc_823E86FC;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e86fc
	if (!cr6.eq) goto loc_823E86FC;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e8688
	if (cr6.eq) goto loc_823E8688;
loc_823E86FC:
	// mr r31,r22
	r31.u64 = r22.u64;
	// addi r8,r1,110
	ctx.r8.s64 = ctx.r1.s64 + 110;
	// li r3,5
	ctx.r3.s64 = 5;
loc_823E8708:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mtctr r3
	ctr.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x823e8774
	if (!cr6.gt) goto loc_823E8774;
	// addi r10,r1,98
	ctx.r10.s64 = ctx.r1.s64 + 98;
	// addi r5,r4,2
	ctx.r5.s64 = ctx.r4.s64 + 2;
	// subf r6,r11,r10
	ctx.r6.s64 = ctx.r10.s64 - r11.s64;
loc_823E8724:
	// lhz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + 0);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// lhz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// lwz r11,2(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823e874c
	if (cr6.lt) goto loc_823E874C;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x823e8750
	if (!cr6.lt) goto loc_823E8750;
loc_823E874C:
	// li r7,1
	ctx.r7.s64 = 1;
loc_823E8750:
	// stw r10,2(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2, ctx.r10.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x823e8768
	if (cr6.eq) goto loc_823E8768;
	// lhz r11,0(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, r11.u16);
loc_823E8768:
	// addi r6,r6,-2
	ctx.r6.s64 = ctx.r6.s64 + -2;
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// bdnz 0x823e8724
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823E8724;
loc_823E8774:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r8,r8,-2
	ctx.r8.s64 = ctx.r8.s64 + -2;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bgt 0x823e8708
	if (cr0.gt) goto loc_823E8708;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// extsh. r10,r11
	ctx.r10.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// ble 0x823e87e8
	if (!cr0.gt) goto loc_823E87E8;
loc_823E879C:
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm. r9,r8,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x823e87e8
	if (!cr0.eq) goto loc_823E87E8;
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// rlwinm r7,r10,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r6,r9,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// add r11,r11,r21
	r11.u64 = r11.u64 + r21.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 | ctx.r6.u64;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// extsh. r5,r11
	ctx.r5.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// bgt 0x823e879c
	if (cr0.gt) goto loc_823E879C;
loc_823E87E8:
	// extsh. r9,r11
	ctx.r9.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x823e8888
	if (cr0.gt) goto loc_823E8888;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// add r11,r11,r21
	r11.u64 = r11.u64 + r21.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// extsh. r9,r11
	ctx.r9.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge 0x823e8888
	if (!cr0.lt) goto loc_823E8888;
	// lwz r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_823E880C:
	// lhz r9,114(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 114);
	// clrlwi. r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823e881c
	if (cr0.eq) goto loc_823E881C;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_823E881C:
	// clrlwi. r9,r6,31
	ctx.r9.u64 = ctx.r6.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r8,r14
	ctx.r8.u64 = r14.u64;
	// bne 0x823e882c
	if (!cr0.eq) goto loc_823E882C;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
loc_823E882C:
	// clrlwi. r9,r7,31
	ctx.r9.u64 = ctx.r7.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r9,r14
	ctx.r9.u64 = r14.u64;
	// bne 0x823e883c
	if (!cr0.eq) goto loc_823E883C;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
loc_823E883C:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// rlwinm r6,r6,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// extsh. r9,r11
	ctx.r9.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// or r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 | ctx.r8.u64;
	// blt 0x823e880c
	if (cr0.lt) goto loc_823E880C;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// beq cr6,0x823e8888
	if (cr6.eq) goto loc_823E8888;
	// lhz r10,114(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 114);
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// sth r10,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, ctx.r10.u16);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
loc_823E8888:
	// lhz r9,114(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 114);
	// cmplwi cr6,r9,32768
	cr6.compare<uint32_t>(ctx.r9.u32, 32768, xer);
	// bgt cr6,0x823e88a0
	if (cr6.gt) goto loc_823E88A0;
	// clrlwi r10,r10,15
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFF;
	// cmplw cr6,r10,r17
	cr6.compare<uint32_t>(ctx.r10.u32, r17.u32, xer);
	// bne cr6,0x823e8900
	if (!cr6.eq) goto loc_823E8900;
loc_823E88A0:
	// lwz r10,110(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 110);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x823e88f8
	if (!cr6.eq) goto loc_823E88F8;
	// lwz r10,106(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 106);
	// stw r22,110(r1)
	PPC_STORE_U32(ctx.r1.u32 + 110, r22.u32);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x823e88ec
	if (!cr6.eq) goto loc_823E88EC;
	// lhz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// stw r22,106(r1)
	PPC_STORE_U32(ctx.r1.u32 + 106, r22.u32);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// bne cr6,0x823e88e0
	if (!cr6.eq) goto loc_823E88E0;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sth r18,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, r18.u16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// b 0x823e8900
	goto loc_823E8900;
loc_823E88E0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, ctx.r10.u16);
	// b 0x823e8900
	goto loc_823E8900;
loc_823E88EC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,106(r1)
	PPC_STORE_U32(ctx.r1.u32 + 106, ctx.r10.u32);
	// b 0x823e8900
	goto loc_823E8900;
loc_823E88F8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,110(r1)
	PPC_STORE_U32(ctx.r1.u32 + 110, ctx.r10.u32);
loc_823E8900:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,32767
	cr6.compare<uint32_t>(r11.u32, 32767, xer);
	// blt cr6,0x823e8924
	if (cr6.lt) goto loc_823E8924;
	// clrlwi. r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r15,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r15.u32);
	// bne 0x823e891c
	if (!cr0.eq) goto loc_823E891C;
	// stw r16,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r16.u32);
loc_823E891C:
	// lwz r31,372(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// b 0x823e8968
	goto loc_823E8968;
loc_823E8924:
	// lhz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 112);
	// clrlwi r10,r26,16
	ctx.r10.u64 = r26.u32 & 0xFFFF;
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r7,104(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// lwz r31,372(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// sth r11,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, r11.u16);
	// sth r9,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, ctx.r9.u16);
	// stw r8,94(r1)
	PPC_STORE_U32(ctx.r1.u32 + 94, ctx.r8.u32);
	// stw r7,90(r1)
	PPC_STORE_U32(ctx.r1.u32 + 90, ctx.r7.u32);
	// lwz r28,92(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x823e8978
	goto loc_823E8978;
loc_823E8958:
	// clrlwi. r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r15,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r15.u32);
	// bne 0x823e8968
	if (!cr0.eq) goto loc_823E8968;
	// stw r16,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r16.u32);
loc_823E8968:
	// mr r28,r22
	r28.u64 = r22.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
loc_823E8978:
	// lhz r30,88(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bne cr6,0x823e85f0
	if (!cr6.eq) goto loc_823E85F0;
	// b 0x823e8990
	goto loc_823E8990;
loc_823E8988:
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r28,92(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_823E8990:
	// clrlwi r9,r30,16
	ctx.r9.u64 = r30.u32 & 0xFFFF;
	// cmplwi cr6,r9,16383
	cr6.compare<uint32_t>(ctx.r9.u32, 16383, xer);
	// blt cr6,0x823e8ce0
	if (cr6.lt) goto loc_823E8CE0;
	// lhz r8,136(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 136);
	// clrlwi r11,r9,17
	r11.u64 = ctx.r9.u32 & 0x7FFF;
	// addi r7,r24,1
	ctx.r7.s64 = r24.s64 + 1;
	// stw r22,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r22.u32);
	// clrlwi r10,r8,17
	ctx.r10.u64 = ctx.r8.u32 & 0x7FFF;
	// stw r22,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r22.u32);
	// xor r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// stw r22,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r22.u32);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// extsh r19,r7
	r19.s64 = ctx.r7.s16;
	// mr r29,r22
	r29.u64 = r22.u64;
	// rlwinm r26,r9,0,16,16
	r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8000;
	// clrlwi r30,r6,16
	r30.u64 = ctx.r6.u32 & 0xFFFF;
	// cmplwi cr6,r11,32767
	cr6.compare<uint32_t>(r11.u32, 32767, xer);
	// bge cr6,0x823e8cc8
	if (!cr6.lt) goto loc_823E8CC8;
	// cmplwi cr6,r10,32767
	cr6.compare<uint32_t>(ctx.r10.u32, 32767, xer);
	// bge cr6,0x823e8cc8
	if (!cr6.lt) goto loc_823E8CC8;
	// clrlwi r9,r30,16
	ctx.r9.u64 = r30.u32 & 0xFFFF;
	// cmplwi cr6,r9,49149
	cr6.compare<uint32_t>(ctx.r9.u32, 49149, xer);
	// bgt cr6,0x823e8cc8
	if (cr6.gt) goto loc_823E8CC8;
	// cmplwi cr6,r9,16319
	cr6.compare<uint32_t>(ctx.r9.u32, 16319, xer);
	// bgt cr6,0x823e89fc
	if (cr6.gt) goto loc_823E89FC;
loc_823E89F4:
	// stw r22,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r22.u32);
	// b 0x823e8cd8
	goto loc_823E8CD8;
loc_823E89FC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e8a30
	if (!cr6.eq) goto loc_823E8A30;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// clrlwi. r11,r11,1
	r11.u64 = r11.u32 & 0x7FFFFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// clrlwi r30,r9,16
	r30.u64 = ctx.r9.u32 & 0xFFFF;
	// bne 0x823e8a30
	if (!cr0.eq) goto loc_823E8A30;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823e8a30
	if (!cr6.eq) goto loc_823E8A30;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x823e8a30
	if (!cr6.eq) goto loc_823E8A30;
	// sth r22,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, r22.u16);
	// b 0x823e8ce0
	goto loc_823E8CE0;
loc_823E8A30:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823e8a68
	if (!cr6.eq) goto loc_823E8A68;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// lwz r10,136(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi. r10,r10,1
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// bne 0x823e8a68
	if (!cr0.eq) goto loc_823E8A68;
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e8a68
	if (!cr6.eq) goto loc_823E8A68;
	// lwz r11,144(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e89f4
	if (cr6.eq) goto loc_823E89F4;
loc_823E8A68:
	// mr r31,r22
	r31.u64 = r22.u64;
	// addi r8,r1,126
	ctx.r8.s64 = ctx.r1.s64 + 126;
	// li r4,5
	ctx.r4.s64 = 5;
loc_823E8A74:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x823e8ae4
	if (!cr6.gt) goto loc_823E8AE4;
	// addi r10,r1,98
	ctx.r10.s64 = ctx.r1.s64 + 98;
	// addi r5,r1,138
	ctx.r5.s64 = ctx.r1.s64 + 138;
	// subf r6,r11,r10
	ctx.r6.s64 = ctx.r10.s64 - r11.s64;
loc_823E8A90:
	// lhz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r5.u32 + 0);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// lhz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// lwz r11,2(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2);
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823e8ab8
	if (cr6.lt) goto loc_823E8AB8;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x823e8abc
	if (!cr6.lt) goto loc_823E8ABC;
loc_823E8AB8:
	// li r7,1
	ctx.r7.s64 = 1;
loc_823E8ABC:
	// stw r10,2(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2, ctx.r10.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x823e8ad4
	if (cr6.eq) goto loc_823E8AD4;
	// lhz r11,0(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, r11.u16);
loc_823E8AD4:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r6,r6,-2
	ctx.r6.s64 = ctx.r6.s64 + -2;
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// bgt 0x823e8a90
	if (cr0.gt) goto loc_823E8A90;
loc_823E8AE4:
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// addi r8,r8,-2
	ctx.r8.s64 = ctx.r8.s64 + -2;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bgt 0x823e8a74
	if (cr0.gt) goto loc_823E8A74;
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// extsh. r10,r11
	ctx.r10.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ble 0x823e8b58
	if (!cr0.gt) goto loc_823E8B58;
loc_823E8B0C:
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// rlwinm. r9,r8,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x823e8b58
	if (!cr0.eq) goto loc_823E8B58;
	// lwz r9,124(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// rlwinm r7,r10,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r6,r9,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// add r11,r11,r21
	r11.u64 = r11.u64 + r21.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 | ctx.r6.u64;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// extsh. r5,r11
	ctx.r5.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// bgt 0x823e8b0c
	if (cr0.gt) goto loc_823E8B0C;
loc_823E8B58:
	// extsh. r9,r11
	ctx.r9.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x823e8bf8
	if (cr0.gt) goto loc_823E8BF8;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// add r11,r11,r21
	r11.u64 = r11.u64 + r21.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// extsh. r9,r11
	ctx.r9.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge 0x823e8bf8
	if (!cr0.lt) goto loc_823E8BF8;
	// lwz r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r7,124(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
loc_823E8B7C:
	// lhz r9,130(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 130);
	// clrlwi. r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823e8b8c
	if (cr0.eq) goto loc_823E8B8C;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_823E8B8C:
	// clrlwi. r9,r6,31
	ctx.r9.u64 = ctx.r6.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r8,r14
	ctx.r8.u64 = r14.u64;
	// bne 0x823e8b9c
	if (!cr0.eq) goto loc_823E8B9C;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
loc_823E8B9C:
	// clrlwi. r9,r7,31
	ctx.r9.u64 = ctx.r7.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r9,r14
	ctx.r9.u64 = r14.u64;
	// bne 0x823e8bac
	if (!cr0.eq) goto loc_823E8BAC;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
loc_823E8BAC:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// rlwinm r6,r6,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// extsh. r9,r11
	ctx.r9.s64 = r11.s16;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// or r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 | ctx.r8.u64;
	// blt 0x823e8b7c
	if (cr0.lt) goto loc_823E8B7C;
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// beq cr6,0x823e8bf8
	if (cr6.eq) goto loc_823E8BF8;
	// lhz r10,130(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 130);
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// sth r10,130(r1)
	PPC_STORE_U16(ctx.r1.u32 + 130, ctx.r10.u16);
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
loc_823E8BF8:
	// lhz r9,130(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 130);
	// cmplwi cr6,r9,32768
	cr6.compare<uint32_t>(ctx.r9.u32, 32768, xer);
	// bgt cr6,0x823e8c10
	if (cr6.gt) goto loc_823E8C10;
	// clrlwi r10,r10,15
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFF;
	// cmplw cr6,r10,r17
	cr6.compare<uint32_t>(ctx.r10.u32, r17.u32, xer);
	// bne cr6,0x823e8c70
	if (!cr6.eq) goto loc_823E8C70;
loc_823E8C10:
	// lwz r10,126(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 126);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x823e8c68
	if (!cr6.eq) goto loc_823E8C68;
	// lwz r10,122(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 122);
	// stw r22,126(r1)
	PPC_STORE_U32(ctx.r1.u32 + 126, r22.u32);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x823e8c5c
	if (!cr6.eq) goto loc_823E8C5C;
	// lhz r10,120(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 120);
	// stw r22,122(r1)
	PPC_STORE_U32(ctx.r1.u32 + 122, r22.u32);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// bne cr6,0x823e8c50
	if (!cr6.eq) goto loc_823E8C50;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sth r18,120(r1)
	PPC_STORE_U16(ctx.r1.u32 + 120, r18.u16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// b 0x823e8c70
	goto loc_823E8C70;
loc_823E8C50:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,120(r1)
	PPC_STORE_U16(ctx.r1.u32 + 120, ctx.r10.u16);
	// b 0x823e8c70
	goto loc_823E8C70;
loc_823E8C5C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,122(r1)
	PPC_STORE_U32(ctx.r1.u32 + 122, ctx.r10.u32);
	// b 0x823e8c70
	goto loc_823E8C70;
loc_823E8C68:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,126(r1)
	PPC_STORE_U32(ctx.r1.u32 + 126, ctx.r10.u32);
loc_823E8C70:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,32767
	cr6.compare<uint32_t>(r11.u32, 32767, xer);
	// blt cr6,0x823e8c94
	if (cr6.lt) goto loc_823E8C94;
	// clrlwi. r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r15,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r15.u32);
	// bne 0x823e8c8c
	if (!cr0.eq) goto loc_823E8C8C;
	// stw r16,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r16.u32);
loc_823E8C8C:
	// lwz r31,372(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// b 0x823e8cd8
	goto loc_823E8CD8;
loc_823E8C94:
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r9,r26,16
	ctx.r9.u64 = r26.u32 & 0xFFFF;
	// lhz r7,128(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 128);
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// or r11,r9,r11
	r11.u64 = ctx.r9.u64 | r11.u64;
	// lwz r31,372(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// sth r11,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, r11.u16);
	// stw r10,94(r1)
	PPC_STORE_U32(ctx.r1.u32 + 94, ctx.r10.u32);
	// sth r7,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, ctx.r7.u16);
	// stw r8,90(r1)
	PPC_STORE_U32(ctx.r1.u32 + 90, ctx.r8.u32);
	// lwz r28,92(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x823e8ce0
	goto loc_823E8CE0;
loc_823E8CC8:
	// clrlwi. r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r15,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r15.u32);
	// bne 0x823e8cd8
	if (!cr0.eq) goto loc_823E8CD8;
	// stw r16,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r16.u32);
loc_823E8CD8:
	// mr r28,r22
	r28.u64 = r22.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
loc_823E8CE0:
	// lwz r11,364(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// sth r19,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r19.u16);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e8d3c
	if (cr0.eq) goto loc_823E8D3C;
	// lwz r10,356(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// extsh r11,r19
	r11.s64 = r19.s16;
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r11.u32);
	// bgt 0x823e8d40
	if (cr0.gt) goto loc_823E8D40;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// sth r22,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r22.u16);
	// cmplwi cr6,r11,32768
	cr6.compare<uint32_t>(r11.u32, 32768, xer);
	// li r11,45
	r11.s64 = 45;
	// beq cr6,0x823e8d1c
	if (cr6.eq) goto loc_823E8D1C;
	// li r11,32
	r11.s64 = 32;
loc_823E8D1C:
	// li r10,48
	ctx.r10.s64 = 48;
	// stb r22,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r22.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r11,2(r31)
	PPC_STORE_U8(r31.u32 + 2, r11.u8);
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r9,3(r31)
	PPC_STORE_U8(r31.u32 + 3, ctx.r9.u8);
	// b 0x823e8fe8
	goto loc_823E8FE8;
loc_823E8D3C:
	// lwz r11,356(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
loc_823E8D40:
	// cmpwi cr6,r11,21
	cr6.compare<int32_t>(r11.s32, 21, xer);
	// ble cr6,0x823e8d50
	if (!cr6.gt) goto loc_823E8D50;
	// li r11,21
	r11.s64 = 21;
	// stw r11,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r11.u32);
loc_823E8D50:
	// lhz r11,88(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// sth r22,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, r22.u16);
	// addi r10,r11,-16382
	ctx.r10.s64 = r11.s64 + -16382;
	// li r11,8
	r11.s64 = 8;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_823E8D64:
	// rlwinm r9,r27,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0x1;
	// rlwinm r8,r28,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0x1;
	// rlwinm r7,r28,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r29,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r27,r27,1,0,30
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// or r28,r7,r9
	r28.u64 = ctx.r7.u64 | ctx.r9.u64;
	// or r29,r6,r8
	r29.u64 = ctx.r6.u64 | ctx.r8.u64;
	// bne 0x823e8d64
	if (!cr0.eq) goto loc_823E8D64;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// bge cr6,0x823e8df0
	if (!cr6.lt) goto loc_823E8DF0;
	// neg r11,r10
	r11.s64 = -ctx.r10.s64;
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x823e8df0
	if (!cr0.gt) goto loc_823E8DF0;
loc_823E8DA8:
	// clrlwi. r10,r29,31
	ctx.r10.u64 = r29.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r9,r14
	ctx.r9.u64 = r14.u64;
	// bne 0x823e8db8
	if (!cr0.eq) goto loc_823E8DB8;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
loc_823E8DB8:
	// clrlwi. r10,r28,31
	ctx.r10.u64 = r28.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
	// bne 0x823e8dc8
	if (!cr0.eq) goto loc_823E8DC8;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
loc_823E8DC8:
	// rlwinm r8,r28,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r7,r27,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 31) & 0x7FFFFFFF;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r29,r29,31,1,31
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 31) & 0x7FFFFFFF;
	// or r28,r8,r9
	r28.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r27,r7,r10
	r27.u64 = ctx.r7.u64 | ctx.r10.u64;
	// bgt 0x823e8da8
	if (cr0.gt) goto loc_823E8DA8;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
loc_823E8DF0:
	// lwz r11,372(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r10,356(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// addi r26,r11,4
	r26.s64 = r11.s64 + 4;
	// addic. r31,r10,1
	xer.ca = ctx.r10.u32 > 4294967294;
	r31.s64 = ctx.r10.s64 + 1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// mr r30,r26
	r30.u64 = r26.u64;
	// ble 0x823e8f04
	if (!cr0.gt) goto loc_823E8F04;
	// b 0x823e8e10
	goto loc_823E8E10;
loc_823E8E0C:
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_823E8E10:
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x823da950
	ctx.lr = 0x823E8E20;
	sub_823DA950(ctx, base);
	// rlwinm r5,r27,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0x1;
	// rlwinm r7,r28,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// rlwinm r10,r27,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r29,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r28,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0x1;
	// or r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 | ctx.r5.u64;
	// or r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 | ctx.r9.u64;
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r7,1,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// rlwinm r6,r10,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r9,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + r11.u64;
	// or r9,r7,r6
	ctx.r9.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r7,r4,r5
	ctx.r7.u64 = ctx.r4.u64 | ctx.r5.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823e8e70
	if (cr6.lt) goto loc_823E8E70;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bge cr6,0x823e8e9c
	if (!cr6.lt) goto loc_823E8E9C;
loc_823E8E70:
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x823e8e88
	if (cr6.lt) goto loc_823E8E88;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bge cr6,0x823e8e8c
	if (!cr6.lt) goto loc_823E8E8C;
loc_823E8E88:
	// li r8,1
	ctx.r8.s64 = 1;
loc_823E8E8C:
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x823e8e9c
	if (cr6.eq) goto loc_823E8E9C;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
loc_823E8E9C:
	// lwz r8,156(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// add r11,r8,r9
	r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x823e8eb4
	if (cr6.lt) goto loc_823E8EB4;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bge cr6,0x823e8eb8
	if (!cr6.lt) goto loc_823E8EB8;
loc_823E8EB4:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
loc_823E8EB8:
	// lwz r9,152(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// rlwinm r7,r10,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// or r28,r11,r7
	r28.u64 = r11.u64 | ctx.r7.u64;
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwinm r27,r10,1,0,30
	r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// lbz r11,88(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// stb r11,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r11.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// stb r22,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r22.u8);
	// bgt 0x823e8e0c
	if (cr0.gt) goto loc_823E8E0C;
loc_823E8F04:
	// lbz r10,-1(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + -1);
	// addi r11,r30,-1
	r11.s64 = r30.s64 + -1;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpwi cr6,r10,53
	cr6.compare<int32_t>(ctx.r10.s32, 53, xer);
	// blt cr6,0x823e8f7c
	if (cr6.lt) goto loc_823E8F7C;
	// b 0x823e8f38
	goto loc_823E8F38;
loc_823E8F20:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,57
	cr6.compare<uint32_t>(ctx.r10.u32, 57, xer);
	// bne cr6,0x823e8f40
	if (!cr6.eq) goto loc_823E8F40;
	// li r10,48
	ctx.r10.s64 = 48;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_823E8F38:
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// bge cr6,0x823e8f20
	if (!cr6.lt) goto loc_823E8F20;
loc_823E8F40:
	// lwz r9,372(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// bge cr6,0x823e8f5c
	if (!cr6.lt) goto loc_823E8F5C;
	// lhz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r10.u16);
loc_823E8F5C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// b 0x823e8fcc
	goto loc_823E8FCC;
loc_823E8F6C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,48
	cr6.compare<uint32_t>(ctx.r10.u32, 48, xer);
	// bne cr6,0x823e8f84
	if (!cr6.eq) goto loc_823E8F84;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_823E8F7C:
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// bge cr6,0x823e8f6c
	if (!cr6.lt) goto loc_823E8F6C;
loc_823E8F84:
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// bge cr6,0x823e8fc8
	if (!cr6.lt) goto loc_823E8FC8;
	// lwz r10,372(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,32768
	cr6.compare<uint32_t>(r11.u32, 32768, xer);
	// li r11,45
	r11.s64 = 45;
	// sth r22,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r22.u16);
	// beq cr6,0x823e8fa8
	if (cr6.eq) goto loc_823E8FA8;
	// li r11,32
	r11.s64 = 32;
loc_823E8FA8:
	// li r9,48
	ctx.r9.s64 = 48;
	// stb r22,5(r10)
	PPC_STORE_U8(ctx.r10.u32 + 5, r22.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r11,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, r11.u8);
	// stb r9,0(r26)
	PPC_STORE_U8(r26.u32 + 0, ctx.r9.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r8,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r8.u8);
	// b 0x823e8fe8
	goto loc_823E8FE8;
loc_823E8FC8:
	// lwz r9,372(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
loc_823E8FCC:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stb r10,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, ctx.r10.u8);
	// stb r22,4(r11)
	PPC_STORE_U8(r11.u32 + 4, r22.u8);
loc_823E8FE8:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_823E8FF0"))) PPC_WEAK_FUNC(sub_823E8FF0);
PPC_FUNC_IMPL(__imp__sub_823E8FF0) {
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
	ctx.lr = 0x823E8FF8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,-1
	r30.s64 = -1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823e9038
	if (!cr6.eq) goto loc_823E9038;
	// bl 0x823e1000
	ctx.lr = 0x823E9010;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E9030;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9098
	goto loc_823E9098;
loc_823E9038:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r29,0
	r29.s64 = 0;
	// andi. r11,r11,131
	r11.u64 = r11.u64 & 131;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi r11,0
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9090
	if (cr0.eq) goto loc_823E9090;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e6170
	ctx.lr = 0x823E9054;
	sub_823E6170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ea020
	ctx.lr = 0x823E9060;
	sub_823EA020(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E9068;
	sub_823E3DE0(ctx, base);
	// bl 0x823e9eb0
	ctx.lr = 0x823E906C;
	sub_823E9EB0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x823e907c
	if (!cr0.lt) goto loc_823E907C;
	// li r30,-1
	r30.s64 = -1;
	// b 0x823e9090
	goto loc_823E9090;
loc_823E907C:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823e9090
	if (cr6.eq) goto loc_823E9090;
	// bl 0x823e2c38
	ctx.lr = 0x823E908C;
	sub_823E2C38(ctx, base);
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
loc_823E9090:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
loc_823E9098:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E90A0"))) PPC_WEAK_FUNC(sub_823E90A0);
PPC_FUNC_IMPL(__imp__sub_823E90A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9888(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9888);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e9110
	if (!cr6.eq) goto loc_823E9110;
	// bl 0x823e1000
	ctx.lr = 0x823E90E8;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E9108;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9150
	goto loc_823E9150;
loc_823E9110:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9128
	if (cr0.eq) goto loc_823E9128;
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// b 0x823e914c
	goto loc_823E914C;
loc_823E9128:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e12d0
	ctx.lr = 0x823E9130;
	sub_823E12D0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e8ff0
	ctx.lr = 0x823E913C;
	sub_823E8FF0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	r12.s64 = r31.s64 + 112;
	// bl 0x823e9188
	ctx.lr = 0x823E914C;
	sub_823E9188(ctx, base);
loc_823E914C:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E9150:
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
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

__attribute__((alias("__imp__sub_823E90A8"))) PPC_WEAK_FUNC(sub_823E90A8);
PPC_FUNC_IMPL(__imp__sub_823E90A8) {
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
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e9110
	if (!cr6.eq) goto loc_823E9110;
	// bl 0x823e1000
	ctx.lr = 0x823E90E8;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E9108;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9150
	goto loc_823E9150;
loc_823E9110:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9128
	if (cr0.eq) goto loc_823E9128;
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// b 0x823e914c
	goto loc_823E914C;
loc_823E9128:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e12d0
	ctx.lr = 0x823E9130;
	sub_823E12D0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e8ff0
	ctx.lr = 0x823E913C;
	sub_823E8FF0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	r12.s64 = r31.s64 + 112;
	// bl 0x823e9188
	ctx.lr = 0x823E914C;
	sub_823E9188(ctx, base);
loc_823E914C:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E9150:
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
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

__attribute__((alias("__imp__sub_823E9168"))) PPC_WEAK_FUNC(sub_823E9168);
PPC_FUNC_IMPL(__imp__sub_823E9168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-112
	r31.s64 = r12.s64 + -112;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,132(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// b 0x823e91a0
	goto loc_823E91A0;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-112
	r31.s64 = r12.s64 + -112;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_823E91A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e1390
	ctx.lr = 0x823E91A8;
	sub_823E1390(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E9188"))) PPC_WEAK_FUNC(sub_823E9188);
PPC_FUNC_IMPL(__imp__sub_823E9188) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-112
	r31.s64 = r12.s64 + -112;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e1390
	ctx.lr = 0x823E91A8;
	sub_823E1390(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E91C0"))) PPC_WEAK_FUNC(sub_823E91C0);
PPC_FUNC_IMPL(__imp__sub_823E91C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9912(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9912);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823E91D0;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r27,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r27.u32);
	// cmpwi cr6,r27,-2
	cr6.compare<int32_t>(r27.s32, -2, xer);
	// bne cr6,0x823e9200
	if (!cr6.eq) goto loc_823E9200;
	// bl 0x823e1000
	ctx.lr = 0x823E91EC;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e92e8
	goto loc_823E92E8;
loc_823E9200:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x823e9218
	if (cr6.lt) goto loc_823E9218;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x823e9244
	if (cr6.lt) goto loc_823E9244;
loc_823E9218:
	// bl 0x823e1000
	ctx.lr = 0x823E921C;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E923C;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e92e8
	goto loc_823E92E8;
loc_823E9244:
	// srawi r11,r27,5
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x1F) != 0);
	r11.s64 = r27.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r10,-23104
	r29.s64 = ctx.r10.s64 + -23104;
	// rlwinm r30,r27,6,21,25
	r30.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r28,r29
	r11.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9218
	if (cr0.eq) goto loc_823E9218;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E9274;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r28,r29
	r11.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e92c4
	if (cr0.eq) goto loc_823E92C4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823e93e0
	ctx.lr = 0x823E9294;
	sub_823E93E0(ctx, base);
	// bl 0x82457d90
	ctx.lr = 0x823E9298;
	sub_82457D90(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e92ac
	if (!cr0.eq) goto loc_823E92AC;
	// bl 0x82135db0
	ctx.lr = 0x823E92A4;
	sub_82135DB0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823e92b0
	goto loc_823E92B0;
loc_823E92AC:
	// li r30,0
	r30.s64 = 0;
loc_823E92B0:
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823e92d8
	if (cr6.eq) goto loc_823E92D8;
	// bl 0x823e1038
	ctx.lr = 0x823E92C0;
	sub_823E1038(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
loc_823E92C4:
	// bl 0x823e1000
	ctx.lr = 0x823E92C8;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
loc_823E92D8:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	r12.s64 = r31.s64 + 144;
	// bl 0x823e9310
	ctx.lr = 0x823E92E4;
	sub_823E9310(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E92E8:
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823E91C8"))) PPC_WEAK_FUNC(sub_823E91C8);
PPC_FUNC_IMPL(__imp__sub_823E91C8) {
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
	ctx.lr = 0x823E91D0;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r27,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r27.u32);
	// cmpwi cr6,r27,-2
	cr6.compare<int32_t>(r27.s32, -2, xer);
	// bne cr6,0x823e9200
	if (!cr6.eq) goto loc_823E9200;
	// bl 0x823e1000
	ctx.lr = 0x823E91EC;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e92e8
	goto loc_823E92E8;
loc_823E9200:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x823e9218
	if (cr6.lt) goto loc_823E9218;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x823e9244
	if (cr6.lt) goto loc_823E9244;
loc_823E9218:
	// bl 0x823e1000
	ctx.lr = 0x823E921C;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E923C;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e92e8
	goto loc_823E92E8;
loc_823E9244:
	// srawi r11,r27,5
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x1F) != 0);
	r11.s64 = r27.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r10,-23104
	r29.s64 = ctx.r10.s64 + -23104;
	// rlwinm r30,r27,6,21,25
	r30.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r28,r29
	r11.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9218
	if (cr0.eq) goto loc_823E9218;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E9274;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r28,r29
	r11.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e92c4
	if (cr0.eq) goto loc_823E92C4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823e93e0
	ctx.lr = 0x823E9294;
	sub_823E93E0(ctx, base);
	// bl 0x82457d90
	ctx.lr = 0x823E9298;
	sub_82457D90(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e92ac
	if (!cr0.eq) goto loc_823E92AC;
	// bl 0x82135db0
	ctx.lr = 0x823E92A4;
	sub_82135DB0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823e92b0
	goto loc_823E92B0;
loc_823E92AC:
	// li r30,0
	r30.s64 = 0;
loc_823E92B0:
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823e92d8
	if (cr6.eq) goto loc_823E92D8;
	// bl 0x823e1038
	ctx.lr = 0x823E92C0;
	sub_823E1038(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
loc_823E92C4:
	// bl 0x823e1000
	ctx.lr = 0x823E92C8;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
loc_823E92D8:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	r12.s64 = r31.s64 + 144;
	// bl 0x823e9310
	ctx.lr = 0x823E92E4;
	sub_823E9310(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E92E8:
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823E92F0"))) PPC_WEAK_FUNC(sub_823E92F0);
PPC_FUNC_IMPL(__imp__sub_823E92F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-144
	r31.s64 = r12.s64 + -144;
	// std r27,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r27.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,164(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// b 0x823e9328
	goto loc_823E9328;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-144
	r31.s64 = r12.s64 + -144;
	// std r27,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r27.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_823E9328:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823E9330;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r27,-16(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E9310"))) PPC_WEAK_FUNC(sub_823E9310);
PPC_FUNC_IMPL(__imp__sub_823E9310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-144
	r31.s64 = r12.s64 + -144;
	// std r27,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r27.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823E9330;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r27,-16(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E9348"))) PPC_WEAK_FUNC(sub_823E9348);
PPC_FUNC_IMPL(__imp__sub_823E9348) {
	PPC_FUNC_PROLOGUE();
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
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823e93ac
	if (cr6.lt) goto loc_823E93AC;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x823e93ac
	if (!cr6.lt) goto loc_823E93AC;
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23104
	ctx.r10.s64 = ctx.r10.s64 + -23104;
	// rlwinm r11,r3,6,21,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e93ac
	if (cr0.eq) goto loc_823E93AC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x823e93ac
	if (cr6.eq) goto loc_823E93AC;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823e93c8
	goto loc_823E93C8;
loc_823E93AC:
	// bl 0x823e1000
	ctx.lr = 0x823E93B0;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E93BC;
	sub_823E1038(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_823E93C8:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E93DC"))) PPC_WEAK_FUNC(sub_823E93DC);
PPC_FUNC_IMPL(__imp__sub_823E93DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E93E0"))) PPC_WEAK_FUNC(sub_823E93E0);
PPC_FUNC_IMPL(__imp__sub_823E93E0) {
	PPC_FUNC_PROLOGUE();
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
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// bne cr6,0x823e9418
	if (!cr6.eq) goto loc_823E9418;
	// bl 0x823e1038
	ctx.lr = 0x823E93F8;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9404;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e9494
	goto loc_823E9494;
loc_823E9418:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823e9430
	if (cr6.lt) goto loc_823E9430;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x823e9468
	if (cr6.lt) goto loc_823E9468;
loc_823E9430:
	// bl 0x823e1038
	ctx.lr = 0x823E9434;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9440;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E9460;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9494
	goto loc_823E9494;
loc_823E9468:
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23104
	ctx.r10.s64 = ctx.r10.s64 + -23104;
	// rlwinm r11,r3,6,21,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e9430
	if (cr0.eq) goto loc_823E9430;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_823E9494:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E94A4"))) PPC_WEAK_FUNC(sub_823E94A4);
PPC_FUNC_IMPL(__imp__sub_823E94A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E94A8"))) PPC_WEAK_FUNC(sub_823E94A8);
PPC_FUNC_IMPL(__imp__sub_823E94A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9936(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9936);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823E94B8;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// srawi r10,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// addi r11,r11,-23104
	r11.s64 = r11.s64 + -23104;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r3,6,21,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// li r29,1
	r29.s64 = 1;
	// stw r29,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r29.u32);
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r30,r10,r9
	r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823e9540
	if (!cr6.eq) goto loc_823E9540;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x823e2a08
	ctx.lr = 0x823E94FC;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e9534
	if (!cr6.eq) goto loc_823E9534;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r30,12
	ctx.r3.s64 = r30.s64 + 12;
	// bl 0x823e2b30
	ctx.lr = 0x823E9518;
	sub_823E2B30(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e9528
	if (!cr0.eq) goto loc_823E9528;
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
loc_823E9528:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
loc_823E9534:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823e9570
	ctx.lr = 0x823E9540;
	sub_823E9570(ctx, base);
loc_823E9540:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x823e9564
	if (cr6.eq) goto loc_823E9564;
	// srawi r9,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 5;
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x827bcf64
	ctx.lr = 0x823E9564;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_823E9564:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E94B0"))) PPC_WEAK_FUNC(sub_823E94B0);
PPC_FUNC_IMPL(__imp__sub_823E94B0) {
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
	ctx.lr = 0x823E94B8;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// srawi r10,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// addi r11,r11,-23104
	r11.s64 = r11.s64 + -23104;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r3,6,21,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// li r29,1
	r29.s64 = 1;
	// stw r29,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r29.u32);
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r30,r10,r9
	r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823e9540
	if (!cr6.eq) goto loc_823E9540;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x823e2a08
	ctx.lr = 0x823E94FC;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e9534
	if (!cr6.eq) goto loc_823E9534;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r3,r30,12
	ctx.r3.s64 = r30.s64 + 12;
	// bl 0x823e2b30
	ctx.lr = 0x823E9518;
	sub_823E2B30(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e9528
	if (!cr0.eq) goto loc_823E9528;
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
loc_823E9528:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
loc_823E9534:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823e9570
	ctx.lr = 0x823E9540;
	sub_823E9570(ctx, base);
loc_823E9540:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x823e9564
	if (cr6.eq) goto loc_823E9564;
	// srawi r9,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 5;
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x827bcf64
	ctx.lr = 0x823E9564;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_823E9564:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E9570"))) PPC_WEAK_FUNC(sub_823E9570);
PPC_FUNC_IMPL(__imp__sub_823E9570) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x823e28a8
	ctx.lr = 0x823E9584;
	sub_823E28A8(ctx, base);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r29,80(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-23104
	r11.s64 = r11.s64 + -23104;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E95A4"))) PPC_WEAK_FUNC(sub_823E95A4);
PPC_FUNC_IMPL(__imp__sub_823E95A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E95A8"))) PPC_WEAK_FUNC(sub_823E95A8);
PPC_FUNC_IMPL(__imp__sub_823E95A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23104
	ctx.r10.s64 = ctx.r10.s64 + -23104;
	// rlwinm r11,r3,6,21,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// b 0x827bcf54
	__imp__RtlLeaveCriticalSection(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823E95CC"))) PPC_WEAK_FUNC(sub_823E95CC);
PPC_FUNC_IMPL(__imp__sub_823E95CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E95D0"))) PPC_WEAK_FUNC(sub_823E95D0);
PPC_FUNC_IMPL(__imp__sub_823E95D0) {
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
	ctx.lr = 0x823E95D8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// li r18,-2
	r18.s64 = -2;
	// mr r20,r31
	r20.u64 = r31.u64;
	// cmpwi cr6,r21,-2
	cr6.compare<int32_t>(r21.s32, -2, xer);
	// bne cr6,0x823e961c
	if (!cr6.eq) goto loc_823E961C;
	// bl 0x823e1038
	ctx.lr = 0x823E95FC;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9608;
	sub_823E1000(ctx, base);
	// li r10,9
	ctx.r10.s64 = 9;
loc_823E960C:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e9c00
	goto loc_823E9C00;
loc_823E961C:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// blt cr6,0x823e9634
	if (cr6.lt) goto loc_823E9634;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r21,r11
	cr6.compare<uint32_t>(r21.u32, r11.u32, xer);
	// blt cr6,0x823e966c
	if (cr6.lt) goto loc_823E966C;
loc_823E9634:
	// bl 0x823e1038
	ctx.lr = 0x823E9638;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9644;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
loc_823E9648:
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E9664;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9c00
	goto loc_823E9C00;
loc_823E966C:
	// srawi r11,r21,5
	xer.ca = (r21.s32 < 0) & ((r21.u32 & 0x1F) != 0);
	r11.s64 = r21.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23104
	r28.s64 = ctx.r10.s64 + -23104;
	// rlwinm r29,r21,6,21,25
	r29.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r10,r29,r11
	ctx.r10.u64 = r29.u64 + r11.u64;
	// lbz r11,4(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// clrlwi. r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823e9634
	if (cr0.eq) goto loc_823E9634;
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// ble cr6,0x823e96c0
	if (!cr6.gt) goto loc_823E96C0;
	// bl 0x823e1038
	ctx.lr = 0x823E96AC;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_823E96B4:
	// bl 0x823e1000
	ctx.lr = 0x823E96B8;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// b 0x823e9648
	goto loc_823E9648;
loc_823E96C0:
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mr r30,r26
	r30.u64 = r26.u64;
	// beq cr6,0x823e9bfc
	if (cr6.eq) goto loc_823E9BFC;
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e9bfc
	if (!cr0.eq) goto loc_823E9BFC;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x823e96ec
	if (!cr6.eq) goto loc_823E96EC;
loc_823E96E0:
	// bl 0x823e1038
	ctx.lr = 0x823E96E4;
	sub_823E1038(ctx, base);
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// b 0x823e96b4
	goto loc_823E96B4;
loc_823E96EC:
	// lbz r11,40(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rotlwi r11,r11,24
	r11.u64 = __builtin_rotateleft32(r11.u32, 24);
	// srawi r11,r11,25
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1FFFFFF) != 0);
	r11.s64 = r11.s32 >> 25;
	// extsb r22,r11
	r22.s64 = r11.s8;
	// cmpwi cr6,r22,1
	cr6.compare<int32_t>(r22.s32, 1, xer);
	// beq cr6,0x823e9724
	if (cr6.eq) goto loc_823E9724;
	// cmpwi cr6,r22,2
	cr6.compare<int32_t>(r22.s32, 2, xer);
	// bne cr6,0x823e971c
	if (!cr6.eq) goto loc_823E971C;
	// not r11,r31
	r11.u64 = ~r31.u64;
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e96e0
	if (cr0.eq) goto loc_823E96E0;
	// rlwinm r31,r31,0,0,30
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFFE;
loc_823E971C:
	// mr r23,r19
	r23.u64 = r19.u64;
	// b 0x823e9784
	goto loc_823E9784;
loc_823E9724:
	// not r11,r31
	r11.u64 = ~r31.u64;
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e96e0
	if (cr0.eq) goto loc_823E96E0;
	// rlwinm r31,r31,31,1,31
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// bge cr6,0x823e9740
	if (!cr6.lt) goto loc_823E9740;
	// li r31,4
	r31.s64 = 4;
loc_823E9740:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2610
	ctx.lr = 0x823E9748;
	sub_823E2610(ctx, base);
	// mr. r23,r3
	r23.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// bne 0x823e9768
	if (!cr0.eq) goto loc_823E9768;
	// bl 0x823e1000
	ctx.lr = 0x823E9754;
	sub_823E1000(ctx, base);
	// li r11,12
	r11.s64 = 12;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E9760;
	sub_823E1038(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// b 0x823e960c
	goto loc_823E960C;
loc_823E9768:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823e6670
	ctx.lr = 0x823E9778;
	sub_823E6670(ctx, base);
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// std r3,48(r11)
	PPC_STORE_U64(r11.u32 + 48, ctx.r3.u64);
loc_823E9784:
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r24,10
	r24.s64 = 10;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// andi. r10,r10,72
	ctx.r10.u64 = ctx.r10.u64 & 72;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// cmpwi r10,0
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e9854
	if (cr0.eq) goto loc_823E9854;
	// lbz r11,5(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x823e9854
	if (cr6.eq) goto loc_823E9854;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823e9854
	if (cr6.eq) goto loc_823E9854;
	// stb r11,0(r23)
	PPC_STORE_U8(r23.u32 + 0, r11.u8);
	// addi r4,r23,1
	ctx.r4.s64 = r23.s64 + 1;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// li r30,1
	r30.s64 = 1;
	// stb r24,5(r11)
	PPC_STORE_U8(r11.u32 + 5, r24.u8);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// beq cr6,0x823e9854
	if (cr6.eq) goto loc_823E9854;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lbz r11,41(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 41);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x823e9854
	if (cr6.eq) goto loc_823E9854;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823e9854
	if (cr6.eq) goto loc_823E9854;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// li r30,2
	r30.s64 = 2;
	// stb r24,41(r11)
	PPC_STORE_U8(r11.u32 + 41, r24.u8);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// cmpwi cr6,r22,1
	cr6.compare<int32_t>(r22.s32, 1, xer);
	// bne cr6,0x823e9854
	if (!cr6.eq) goto loc_823E9854;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lbz r11,42(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 42);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x823e9854
	if (cr6.eq) goto loc_823E9854;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823e9854
	if (cr6.eq) goto loc_823E9854;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// li r30,3
	r30.s64 = 3;
	// stb r24,42(r11)
	PPC_STORE_U8(r11.u32 + 42, r24.u8);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_823E9854:
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x8244f4c0
	ctx.lr = 0x823E986C;
	sub_8244F4C0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e9bc8
	if (cr0.eq) goto loc_823E9BC8;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x823e9bc8
	if (cr6.lt) goto loc_823E9BC8;
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bgt cr6,0x823e9bc8
	if (cr6.gt) goto loc_823E9BC8;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// rlwinm. r9,r9,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823e9b80
	if (cr0.eq) goto loc_823E9B80;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823e98c0
	if (cr6.eq) goto loc_823E98C0;
	// lbz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// cmplwi cr6,r10,10
	cr6.compare<uint32_t>(ctx.r10.u32, 10, xer);
	// bne cr6,0x823e98c0
	if (!cr6.eq) goto loc_823E98C0;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// b 0x823e98cc
	goto loc_823E98CC;
loc_823E98C0:
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r10,r10,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
loc_823E98CC:
	// add r25,r23,r30
	r25.u64 = r23.u64 + r30.u64;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// mr r31,r23
	r31.u64 = r23.u64;
	// mr r30,r23
	r30.u64 = r23.u64;
	// cmplw cr6,r23,r25
	cr6.compare<uint32_t>(r23.u32, r25.u32, xer);
	// bge cr6,0x823e9a38
	if (!cr6.lt) goto loc_823E9A38;
	// li r26,13
	r26.s64 = 13;
loc_823E98E8:
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// extsb r11,r10
	r11.s64 = ctx.r10.s8;
	// cmpwi cr6,r11,26
	cr6.compare<int32_t>(r11.s32, 26, xer);
	// beq cr6,0x823e9a08
	if (cr6.eq) goto loc_823E9A08;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x823e990c
	if (cr6.eq) goto loc_823E990C;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// b 0x823e99f8
	goto loc_823E99F8;
loc_823E990C:
	// addi r11,r25,-1
	r11.s64 = r25.s64 + -1;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bge cr6,0x823e9940
	if (!cr6.lt) goto loc_823E9940;
	// lbz r9,1(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// cmplwi cr6,r9,10
	cr6.compare<uint32_t>(ctx.r9.u32, 10, xer);
	// bne cr6,0x823e9934
	if (!cr6.eq) goto loc_823E9934;
	// stb r24,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r24.u8);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// b 0x823e99f8
	goto loc_823E99F8;
loc_823E9934:
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// b 0x823e99f8
	goto loc_823E99F8;
loc_823E9940:
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x8244f4c0
	ctx.lr = 0x823E9960;
	sub_8244F4C0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e9974
	if (!cr0.eq) goto loc_823E9974;
	// bl 0x82135db0
	ctx.lr = 0x823E996C;
	sub_82135DB0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e99f4
	if (!cr0.eq) goto loc_823E99F4;
loc_823E9974:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823e99f4
	if (cr6.eq) goto loc_823E99F4;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// andi. r11,r11,72
	r11.u64 = r11.u64 & 72;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi r11,0
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e99c4
	if (cr0.eq) goto loc_823E99C4;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// bne cr6,0x823e99ac
	if (!cr6.eq) goto loc_823E99AC;
loc_823E99A4:
	// stb r24,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r24.u8);
	// b 0x823e99f8
	goto loc_823E99F8;
loc_823E99AC:
	// stb r26,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r26.u8);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
	// b 0x823e99f8
	goto loc_823E99F8;
loc_823E99C4:
	// cmplw cr6,r31,r23
	cr6.compare<uint32_t>(r31.u32, r23.u32, xer);
	// bne cr6,0x823e99d8
	if (!cr6.eq) goto loc_823E99D8;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x823e99a4
	if (cr6.eq) goto loc_823E99A4;
loc_823E99D8:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823e6670
	ctx.lr = 0x823E99E8;
	sub_823E6670(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x823e99fc
	if (cr6.eq) goto loc_823E99FC;
loc_823E99F4:
	// stb r26,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r26.u8);
loc_823E99F8:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_823E99FC:
	// cmplw cr6,r30,r25
	cr6.compare<uint32_t>(r30.u32, r25.u32, xer);
	// blt cr6,0x823e98e8
	if (cr6.lt) goto loc_823E98E8;
	// b 0x823e9a38
	goto loc_823E9A38;
loc_823E9A08:
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e9a2c
	if (!cr0.eq) goto loc_823E9A2C;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// b 0x823e9a38
	goto loc_823E9A38;
loc_823E9A2C:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_823E9A38:
	// subf r30,r23,r31
	r30.s64 = r31.s64 - r23.s64;
	// cmpwi cr6,r22,1
	cr6.compare<int32_t>(r22.s32, 1, xer);
	// bne cr6,0x823e9b80
	if (!cr6.eq) goto loc_823E9B80;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823e9b80
	if (cr6.eq) goto loc_823E9B80;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm. r11,r10,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e9a64
	if (!cr0.eq) goto loc_823E9A64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// b 0x823e9b48
	goto loc_823E9B48;
loc_823E9A64:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r11,-15928
	r11.s64 = r11.s64 + -15928;
	// b 0x823e9a90
	goto loc_823E9A90;
loc_823E9A74:
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x823e9a9c
	if (cr6.gt) goto loc_823E9A9C;
	// cmplw cr6,r31,r23
	cr6.compare<uint32_t>(r31.u32, r23.u32, xer);
	// blt cr6,0x823e9a9c
	if (cr6.lt) goto loc_823E9A9C;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
loc_823E9A90:
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823e9a74
	if (cr6.eq) goto loc_823E9A74;
loc_823E9A9C:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lbzx r11,r8,r11
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// extsb. r11,r11
	r11.s64 = r11.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e9ac0
	if (!cr0.eq) goto loc_823E9AC0;
	// bl 0x823e1000
	ctx.lr = 0x823E9AB4;
	sub_823E1000(ctx, base);
	// li r11,42
	r11.s64 = 42;
loc_823E9AB8:
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// b 0x823e9b7c
	goto loc_823E9B7C;
loc_823E9AC0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x823e9ad4
	if (!cr6.eq) goto loc_823E9AD4;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// b 0x823e9b48
	goto loc_823E9B48;
loc_823E9AD4:
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// andi. r8,r8,72
	ctx.r8.u64 = ctx.r8.u64 & 72;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// cmpwi r8,0
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x823e9b34
	if (cr0.eq) goto loc_823E9B34;
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// blt cr6,0x823e9b10
	if (cr6.lt) goto loc_823E9B10;
	// lwzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r29,r10
	ctx.r10.u64 = r29.u64 + ctx.r10.u64;
	// stb r8,41(r10)
	PPC_STORE_U8(ctx.r10.u32 + 41, ctx.r8.u8);
loc_823E9B10:
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x823e9b2c
	if (!cr6.eq) goto loc_823E9B2C;
	// lwzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r29,r10
	ctx.r10.u64 = r29.u64 + ctx.r10.u64;
	// stb r8,42(r10)
	PPC_STORE_U8(ctx.r10.u32 + 42, ctx.r8.u8);
loc_823E9B2C:
	// subf r31,r9,r11
	r31.s64 = r11.s64 - ctx.r9.s64;
	// b 0x823e9b48
	goto loc_823E9B48;
loc_823E9B34:
	// neg r11,r9
	r11.s64 = -ctx.r9.s64;
	// li r5,1
	ctx.r5.s64 = 1;
	// extsw r4,r11
	ctx.r4.s64 = r11.s32;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823e6670
	ctx.lr = 0x823E9B48;
	sub_823E6670(ctx, base);
loc_823E9B48:
	// subf r31,r23,r31
	r31.s64 = r31.s64 - r23.s64;
	// lis r3,0
	ctx.r3.s64 = 0;
	// rlwinm r8,r20,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r7,r19
	ctx.r7.u64 = r19.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,65001
	ctx.r3.u64 = ctx.r3.u64 | 65001;
	// bl 0x82457dd0
	ctx.lr = 0x823E9B6C;
	sub_82457DD0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823e9ba4
	if (!cr0.eq) goto loc_823E9BA4;
	// bl 0x82135db0
	ctx.lr = 0x823E9B78;
	sub_82135DB0(ctx, base);
loc_823E9B78:
	// bl 0x823e1070
	ctx.lr = 0x823E9B7C;
	sub_823E1070(ctx, base);
loc_823E9B7C:
	// li r18,-1
	r18.s64 = -1;
loc_823E9B80:
	// cmplw cr6,r23,r19
	cr6.compare<uint32_t>(r23.u32, r19.u32, xer);
	// beq cr6,0x823e9b90
	if (cr6.eq) goto loc_823E9B90;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823e2c38
	ctx.lr = 0x823E9B90;
	sub_823E2C38(ctx, base);
loc_823E9B90:
	// cmpwi cr6,r18,-2
	cr6.compare<int32_t>(r18.s32, -2, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x823e9c00
	if (cr6.eq) goto loc_823E9C00;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// b 0x823e9c00
	goto loc_823E9C00;
loc_823E9BA4:
	// subf r10,r30,r31
	ctx.r10.s64 = r31.s64 - r30.s64;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// rlwinm r30,r30,1,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// stw r10,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r10.u32);
	// b 0x823e9b80
	goto loc_823E9B80;
loc_823E9BC8:
	// bl 0x82135db0
	ctx.lr = 0x823E9BCC;
	sub_82135DB0(ctx, base);
	// cmplwi cr6,r3,5
	cr6.compare<uint32_t>(ctx.r3.u32, 5, xer);
	// bne cr6,0x823e9bec
	if (!cr6.eq) goto loc_823E9BEC;
	// bl 0x823e1000
	ctx.lr = 0x823E9BD8;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E9BE4;
	sub_823E1038(ctx, base);
	// li r11,5
	r11.s64 = 5;
	// b 0x823e9ab8
	goto loc_823E9AB8;
loc_823E9BEC:
	// cmplwi cr6,r3,109
	cr6.compare<uint32_t>(ctx.r3.u32, 109, xer);
	// bne cr6,0x823e9b78
	if (!cr6.eq) goto loc_823E9B78;
	// mr r18,r26
	r18.u64 = r26.u64;
	// b 0x823e9b80
	goto loc_823E9B80;
loc_823E9BFC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823E9C00:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_823E9C08"))) PPC_WEAK_FUNC(sub_823E9C08);
PPC_FUNC_IMPL(__imp__sub_823E9C08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9960(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9960);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823E9C18;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x823e9c5c
	if (!cr6.eq) goto loc_823E9C5C;
	// bl 0x823e1038
	ctx.lr = 0x823E9C3C;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9C48;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e9d6c
	goto loc_823E9D6C;
loc_823E9C5C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823e9c74
	if (cr6.lt) goto loc_823E9C74;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823e9cac
	if (cr6.lt) goto loc_823E9CAC;
loc_823E9C74:
	// bl 0x823e1038
	ctx.lr = 0x823E9C78;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9C84;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
loc_823E9C88:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E9CA4;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9d6c
	goto loc_823E9D6C;
loc_823E9CAC:
	// srawi r11,r30,5
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1F) != 0);
	r11.s64 = r30.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23104
	r28.s64 = ctx.r10.s64 + -23104;
	// rlwinm r29,r30,6,21,25
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9c74
	if (cr0.eq) goto loc_823E9C74;
	// lis r11,32767
	r11.s64 = 2147418112;
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// subfc r11,r26,r11
	xer.ca = r11.u32 >= r26.u32;
	r11.s64 = r11.s64 - r26.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// addic. r11,r11,1
	xer.ca = r11.u32 > 4294967294;
	r11.s64 = r11.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e9d04
	if (!cr0.eq) goto loc_823E9D04;
	// bl 0x823e1038
	ctx.lr = 0x823E9CF0;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9CFC;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// b 0x823e9c88
	goto loc_823E9C88;
loc_823E9D04:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E9D0C;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9d3c
	if (cr0.eq) goto loc_823E9D3C;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95d0
	ctx.lr = 0x823E9D34;
	sub_823E95D0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// b 0x823e9d5c
	goto loc_823E9D5C;
loc_823E9D3C:
	// bl 0x823e1000
	ctx.lr = 0x823E9D40;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E9D4C;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
loc_823E9D5C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x823e9d94
	ctx.lr = 0x823E9D68;
	sub_823E9D94(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E9D6C:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823E9C10"))) PPC_WEAK_FUNC(sub_823E9C10);
PPC_FUNC_IMPL(__imp__sub_823E9C10) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823E9C18;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x823e9c5c
	if (!cr6.eq) goto loc_823E9C5C;
	// bl 0x823e1038
	ctx.lr = 0x823E9C3C;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9C48;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e9d6c
	goto loc_823E9D6C;
loc_823E9C5C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823e9c74
	if (cr6.lt) goto loc_823E9C74;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823e9cac
	if (cr6.lt) goto loc_823E9CAC;
loc_823E9C74:
	// bl 0x823e1038
	ctx.lr = 0x823E9C78;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9C84;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
loc_823E9C88:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E9CA4;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9d6c
	goto loc_823E9D6C;
loc_823E9CAC:
	// srawi r11,r30,5
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1F) != 0);
	r11.s64 = r30.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23104
	r28.s64 = ctx.r10.s64 + -23104;
	// rlwinm r29,r30,6,21,25
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9c74
	if (cr0.eq) goto loc_823E9C74;
	// lis r11,32767
	r11.s64 = 2147418112;
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// subfc r11,r26,r11
	xer.ca = r11.u32 >= r26.u32;
	r11.s64 = r11.s64 - r26.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// addic. r11,r11,1
	xer.ca = r11.u32 > 4294967294;
	r11.s64 = r11.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e9d04
	if (!cr0.eq) goto loc_823E9D04;
	// bl 0x823e1038
	ctx.lr = 0x823E9CF0;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9CFC;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// b 0x823e9c88
	goto loc_823E9C88;
loc_823E9D04:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E9D0C;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9d3c
	if (cr0.eq) goto loc_823E9D3C;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95d0
	ctx.lr = 0x823E9D34;
	sub_823E95D0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// b 0x823e9d5c
	goto loc_823E9D5C;
loc_823E9D3C:
	// bl 0x823e1000
	ctx.lr = 0x823E9D40;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1038
	ctx.lr = 0x823E9D4C;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
loc_823E9D5C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x823e9d94
	ctx.lr = 0x823E9D68;
	sub_823E9D94(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E9D6C:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823E9D74"))) PPC_WEAK_FUNC(sub_823E9D74);
PPC_FUNC_IMPL(__imp__sub_823E9D74) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,180(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// b 0x823e9dac
	goto loc_823E9DAC;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_823E9DAC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823E9DB4;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E9D94"))) PPC_WEAK_FUNC(sub_823E9D94);
PPC_FUNC_IMPL(__imp__sub_823E9D94) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823E9DB4;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E9DCC"))) PPC_WEAK_FUNC(sub_823E9DCC);
PPC_FUNC_IMPL(__imp__sub_823E9DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E9DD0"))) PPC_WEAK_FUNC(sub_823E9DD0);
PPC_FUNC_IMPL(__imp__sub_823E9DD0) {
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
	ctx.lr = 0x823E9DD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823e93e0
	ctx.lr = 0x823E9DE4;
	sub_823E93E0(ctx, base);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// addi r29,r11,-23104
	r29.s64 = r11.s64 + -23104;
	// beq cr6,0x823e9e5c
	if (cr6.eq) goto loc_823E9E5C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// bne cr6,0x823e9e0c
	if (!cr6.eq) goto loc_823E9E0C;
	// lbz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 132);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e9e20
	if (!cr0.eq) goto loc_823E9E20;
loc_823E9E0C:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x823e9e3c
	if (!cr6.eq) goto loc_823E9E3C;
	// lbz r11,68(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 68);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9e3c
	if (cr0.eq) goto loc_823E9E3C;
loc_823E9E20:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823e93e0
	ctx.lr = 0x823E9E28;
	sub_823E93E0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e93e0
	ctx.lr = 0x823E9E34;
	sub_823E93E0(ctx, base);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// beq cr6,0x823e9e5c
	if (cr6.eq) goto loc_823E9E5C;
loc_823E9E3C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e93e0
	ctx.lr = 0x823E9E44;
	sub_823E93E0(ctx, base);
	// bl 0x8244eee0
	ctx.lr = 0x823E9E48;
	sub_8244EEE0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e9e5c
	if (!cr0.eq) goto loc_823E9E5C;
	// bl 0x82135db0
	ctx.lr = 0x823E9E54;
	sub_82135DB0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x823e9e60
	goto loc_823E9E60;
loc_823E9E5C:
	// li r30,0
	r30.s64 = 0;
loc_823E9E60:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e9348
	ctx.lr = 0x823E9E68;
	sub_823E9348(ctx, base);
	// srawi r11,r31,5
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1F) != 0);
	r11.s64 = r31.s32 >> 5;
	// rlwinm r10,r31,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 6) & 0x7C0;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwzx r11,r11,r29
	r11.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// beq cr6,0x823e9e9c
	if (cr6.eq) goto loc_823E9E9C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e1070
	ctx.lr = 0x823E9E94;
	sub_823E1070(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9ea0
	goto loc_823E9EA0;
loc_823E9E9C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823E9EA0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E9EA8"))) PPC_WEAK_FUNC(sub_823E9EA8);
PPC_FUNC_IMPL(__imp__sub_823E9EA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9984(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9984);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823E9EB8;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r30.u32);
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x823e9ef4
	if (!cr6.eq) goto loc_823E9EF4;
	// bl 0x823e1038
	ctx.lr = 0x823E9ED4;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9EE0;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e9fc0
	goto loc_823E9FC0;
loc_823E9EF4:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823e9f0c
	if (cr6.lt) goto loc_823E9F0C;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823e9f44
	if (cr6.lt) goto loc_823E9F44;
loc_823E9F0C:
	// bl 0x823e1038
	ctx.lr = 0x823E9F10;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9F1C;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E9F3C;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9fc0
	goto loc_823E9FC0;
loc_823E9F44:
	// srawi r11,r30,5
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1F) != 0);
	r11.s64 = r30.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23104
	r28.s64 = ctx.r10.s64 + -23104;
	// rlwinm r29,r30,6,21,25
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9f0c
	if (cr0.eq) goto loc_823E9F0C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E9F74;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9f9c
	if (cr0.eq) goto loc_823E9F9C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e9dd0
	ctx.lr = 0x823E9F94;
	sub_823E9DD0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// b 0x823e9fb0
	goto loc_823E9FB0;
loc_823E9F9C:
	// bl 0x823e1000
	ctx.lr = 0x823E9FA0;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
loc_823E9FB0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	r12.s64 = r31.s64 + 144;
	// bl 0x823e9fe8
	ctx.lr = 0x823E9FBC;
	sub_823E9FE8(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E9FC0:
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823E9EB0"))) PPC_WEAK_FUNC(sub_823E9EB0);
PPC_FUNC_IMPL(__imp__sub_823E9EB0) {
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
	ctx.lr = 0x823E9EB8;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r30.u32);
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x823e9ef4
	if (!cr6.eq) goto loc_823E9EF4;
	// bl 0x823e1038
	ctx.lr = 0x823E9ED4;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9EE0;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e9fc0
	goto loc_823E9FC0;
loc_823E9EF4:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823e9f0c
	if (cr6.lt) goto loc_823E9F0C;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-23120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23120);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823e9f44
	if (cr6.lt) goto loc_823E9F44;
loc_823E9F0C:
	// bl 0x823e1038
	ctx.lr = 0x823E9F10;
	sub_823E1038(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bl 0x823e1000
	ctx.lr = 0x823E9F1C;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823E9F3C;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e9fc0
	goto loc_823E9FC0;
loc_823E9F44:
	// srawi r11,r30,5
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1F) != 0);
	r11.s64 = r30.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r10,-23104
	r28.s64 = ctx.r10.s64 + -23104;
	// rlwinm r29,r30,6,21,25
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0x7C0;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9f0c
	if (cr0.eq) goto loc_823E9F0C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e94b0
	ctx.lr = 0x823E9F74;
	sub_823E94B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r27,r28
	r11.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e9f9c
	if (cr0.eq) goto loc_823E9F9C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e9dd0
	ctx.lr = 0x823E9F94;
	sub_823E9DD0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// b 0x823e9fb0
	goto loc_823E9FB0;
loc_823E9F9C:
	// bl 0x823e1000
	ctx.lr = 0x823E9FA0;
	sub_823E1000(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
loc_823E9FB0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	r12.s64 = r31.s64 + 144;
	// bl 0x823e9fe8
	ctx.lr = 0x823E9FBC;
	sub_823E9FE8(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E9FC0:
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823E9FC8"))) PPC_WEAK_FUNC(sub_823E9FC8);
PPC_FUNC_IMPL(__imp__sub_823E9FC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-144
	r31.s64 = r12.s64 + -144;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,164(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// b 0x823ea000
	goto loc_823EA000;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-144
	r31.s64 = r12.s64 + -144;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_823EA000:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823EA008;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E9FE8"))) PPC_WEAK_FUNC(sub_823E9FE8);
PPC_FUNC_IMPL(__imp__sub_823E9FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-144
	r31.s64 = r12.s64 + -144;
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e95a8
	ctx.lr = 0x823EA008;
	sub_823E95A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EA020"))) PPC_WEAK_FUNC(sub_823EA020);
PPC_FUNC_IMPL(__imp__sub_823EA020) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// andi. r10,r11,131
	ctx.r10.u64 = r11.u64 & 131;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// cmpwi r10,0
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823ea074
	if (cr0.eq) goto loc_823EA074;
	// rlwinm. r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823ea074
	if (cr0.eq) goto loc_823EA074;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x823e2c38
	ctx.lr = 0x823EA054;
	sub_823E2C38(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r11,r11,0,29,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// rlwinm r11,r11,0,22,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFBFF;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_823EA074:
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

__attribute__((alias("__imp__sub_823EA088"))) PPC_WEAK_FUNC(sub_823EA088);
PPC_FUNC_IMPL(__imp__sub_823EA088) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x823ed100
	ctx.lr = 0x823EA0A8;
	sub_823ED100(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,-9796
	ctx.r5.s64 = r11.s64 + -9796;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ed000
	ctx.lr = 0x823EA0BC;
	sub_823ED000(ctx, base);
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

__attribute__((alias("__imp__sub_823EA0D4"))) PPC_WEAK_FUNC(sub_823EA0D4);
PPC_FUNC_IMPL(__imp__sub_823EA0D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA0D8"))) PPC_WEAK_FUNC(sub_823EA0D8);
PPC_FUNC_IMPL(__imp__sub_823EA0D8) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA100;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA114;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA120;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_823EA13C"))) PPC_WEAK_FUNC(sub_823EA13C);
PPC_FUNC_IMPL(__imp__sub_823EA13C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA140"))) PPC_WEAK_FUNC(sub_823EA140);
PPC_FUNC_IMPL(__imp__sub_823EA140) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA168;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA17C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA188;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_823EA1A4"))) PPC_WEAK_FUNC(sub_823EA1A4);
PPC_FUNC_IMPL(__imp__sub_823EA1A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA1A8"))) PPC_WEAK_FUNC(sub_823EA1A8);
PPC_FUNC_IMPL(__imp__sub_823EA1A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x823EA1B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x827bcf64
	ctx.lr = 0x823EA1D8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA1FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA208;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823EA214"))) PPC_WEAK_FUNC(sub_823EA214);
PPC_FUNC_IMPL(__imp__sub_823EA214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA218"))) PPC_WEAK_FUNC(sub_823EA218);
PPC_FUNC_IMPL(__imp__sub_823EA218) {
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
	ctx.lr = 0x823EA220;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA23C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA260;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA26C"))) PPC_WEAK_FUNC(sub_823EA26C);
PPC_FUNC_IMPL(__imp__sub_823EA26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA270"))) PPC_WEAK_FUNC(sub_823EA270);
PPC_FUNC_IMPL(__imp__sub_823EA270) {
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
	ctx.lr = 0x823EA278;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA294;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA2AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA2B8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA2C4"))) PPC_WEAK_FUNC(sub_823EA2C4);
PPC_FUNC_IMPL(__imp__sub_823EA2C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA2C8"))) PPC_WEAK_FUNC(sub_823EA2C8);
PPC_FUNC_IMPL(__imp__sub_823EA2C8) {
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
	ctx.lr = 0x823EA2D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA2EC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA310;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA31C"))) PPC_WEAK_FUNC(sub_823EA31C);
PPC_FUNC_IMPL(__imp__sub_823EA31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA320"))) PPC_WEAK_FUNC(sub_823EA320);
PPC_FUNC_IMPL(__imp__sub_823EA320) {
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
	ctx.lr = 0x823EA328;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x827bcf64
	ctx.lr = 0x823EA348;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA370;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823EA37C"))) PPC_WEAK_FUNC(sub_823EA37C);
PPC_FUNC_IMPL(__imp__sub_823EA37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA380"))) PPC_WEAK_FUNC(sub_823EA380);
PPC_FUNC_IMPL(__imp__sub_823EA380) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA3A8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ee8b0
	ctx.lr = 0x823EA3B0;
	sub_823EE8B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA3BC;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_823EA3D8"))) PPC_WEAK_FUNC(sub_823EA3D8);
PPC_FUNC_IMPL(__imp__sub_823EA3D8) {
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
	ctx.lr = 0x823EA3E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA3FC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ef718
	ctx.lr = 0x823EA408;
	sub_823EF718(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA414;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA420"))) PPC_WEAK_FUNC(sub_823EA420);
PPC_FUNC_IMPL(__imp__sub_823EA420) {
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
	ctx.lr = 0x823EA428;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA444;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA45C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA468;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA474"))) PPC_WEAK_FUNC(sub_823EA474);
PPC_FUNC_IMPL(__imp__sub_823EA474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA478"))) PPC_WEAK_FUNC(sub_823EA478);
PPC_FUNC_IMPL(__imp__sub_823EA478) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA4A0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA4B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA4C0;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_823EA4DC"))) PPC_WEAK_FUNC(sub_823EA4DC);
PPC_FUNC_IMPL(__imp__sub_823EA4DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA4E0"))) PPC_WEAK_FUNC(sub_823EA4E0);
PPC_FUNC_IMPL(__imp__sub_823EA4E0) {
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
	ctx.lr = 0x823EA4E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA504;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA51C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA528;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA534"))) PPC_WEAK_FUNC(sub_823EA534);
PPC_FUNC_IMPL(__imp__sub_823EA534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA538"))) PPC_WEAK_FUNC(sub_823EA538);
PPC_FUNC_IMPL(__imp__sub_823EA538) {
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
	ctx.lr = 0x823EA540;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA55C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA574;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA580;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA58C"))) PPC_WEAK_FUNC(sub_823EA58C);
PPC_FUNC_IMPL(__imp__sub_823EA58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA590"))) PPC_WEAK_FUNC(sub_823EA590);
PPC_FUNC_IMPL(__imp__sub_823EA590) {
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
	ctx.lr = 0x823EA598;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA5B4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA5CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA5D8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA5E4"))) PPC_WEAK_FUNC(sub_823EA5E4);
PPC_FUNC_IMPL(__imp__sub_823EA5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA5E8"))) PPC_WEAK_FUNC(sub_823EA5E8);
PPC_FUNC_IMPL(__imp__sub_823EA5E8) {
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
	ctx.lr = 0x823EA5F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA60C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA630;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA63C"))) PPC_WEAK_FUNC(sub_823EA63C);
PPC_FUNC_IMPL(__imp__sub_823EA63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA640"))) PPC_WEAK_FUNC(sub_823EA640);
PPC_FUNC_IMPL(__imp__sub_823EA640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA670;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stfs f31,140(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 140, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA688;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA694;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
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

__attribute__((alias("__imp__sub_823EA6B4"))) PPC_WEAK_FUNC(sub_823EA6B4);
PPC_FUNC_IMPL(__imp__sub_823EA6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA6B8"))) PPC_WEAK_FUNC(sub_823EA6B8);
PPC_FUNC_IMPL(__imp__sub_823EA6B8) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA6E8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,96(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EA700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA70C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
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

__attribute__((alias("__imp__sub_823EA72C"))) PPC_WEAK_FUNC(sub_823EA72C);
PPC_FUNC_IMPL(__imp__sub_823EA72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA730"))) PPC_WEAK_FUNC(sub_823EA730);
PPC_FUNC_IMPL(__imp__sub_823EA730) {
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
	ctx.lr = 0x823EA738;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA754;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-9796(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ea788
	if (cr6.eq) goto loc_823EA788;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EA774;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA77C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823EA788:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823ea7a4
	if (!cr6.eq) goto loc_823EA7A4;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,0
	r11.s64 = 0;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r11.u64);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
loc_823EA7A4:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r10,5136
	ctx.r10.s64 = ctx.r10.s64 + 5136;
	// addi r4,r11,5144
	ctx.r4.s64 = r11.s64 + 5144;
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// bge cr6,0x823ea7d8
	if (!cr6.lt) goto loc_823EA7D8;
loc_823EA7C0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ea7d8
	if (!cr6.eq) goto loc_823EA7D8;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// blt cr6,0x823ea7c0
	if (cr6.lt) goto loc_823EA7C0;
loc_823EA7D8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823EA7EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA7F8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EA804"))) PPC_WEAK_FUNC(sub_823EA804);
PPC_FUNC_IMPL(__imp__sub_823EA804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA808"))) PPC_WEAK_FUNC(sub_823EA808);
PPC_FUNC_IMPL(__imp__sub_823EA808) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA82C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-9796(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823ea84c
	if (!cr6.eq) goto loc_823EA84C;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA844;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823ea86c
	goto loc_823EA86C;
loc_823EA84C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EA85C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA868;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823EA86C:
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

__attribute__((alias("__imp__sub_823EA884"))) PPC_WEAK_FUNC(sub_823EA884);
PPC_FUNC_IMPL(__imp__sub_823EA884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA888"))) PPC_WEAK_FUNC(sub_823EA888);
PPC_FUNC_IMPL(__imp__sub_823EA888) {
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
	ctx.lr = 0x823EA890;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x823EA8B4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-9796(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823ea8dc
	if (!cr6.eq) goto loc_823EA8DC;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA8CC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823EA8DC:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823eb5e0
	ctx.lr = 0x823EA8F0;
	sub_823EB5E0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA8FC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EA908"))) PPC_WEAK_FUNC(sub_823EA908);
PPC_FUNC_IMPL(__imp__sub_823EA908) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA930;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-9796(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823ea954
	if (!cr6.eq) goto loc_823EA954;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA948;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x823ea96c
	goto loc_823EA96C;
loc_823EA954:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823ebdd8
	ctx.lr = 0x823EA95C;
	sub_823EBDD8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA968;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823EA96C:
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

__attribute__((alias("__imp__sub_823EA984"))) PPC_WEAK_FUNC(sub_823EA984);
PPC_FUNC_IMPL(__imp__sub_823EA984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EA988"))) PPC_WEAK_FUNC(sub_823EA988);
PPC_FUNC_IMPL(__imp__sub_823EA988) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EA9B0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ea9d4
	if (!cr6.eq) goto loc_823EA9D4;
loc_823EA9C0:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA9C8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x823ea9f8
	goto loc_823EA9F8;
loc_823EA9D4:
	// lwz r3,60(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ea9c0
	if (cr6.eq) goto loc_823EA9C0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823ee1b0
	ctx.lr = 0x823EA9E8;
	sub_823EE1B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EA9F4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823EA9F8:
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

__attribute__((alias("__imp__sub_823EAA10"))) PPC_WEAK_FUNC(sub_823EAA10);
PPC_FUNC_IMPL(__imp__sub_823EAA10) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EAA34;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-9796(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823eaa58
	if (!cr6.eq) goto loc_823EAA58;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EAA4C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x823eaa6c
	goto loc_823EAA6C;
loc_823EAA58:
	// bl 0x823ec078
	ctx.lr = 0x823EAA5C;
	sub_823EC078(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EAA68;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823EAA6C:
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

__attribute__((alias("__imp__sub_823EAA84"))) PPC_WEAK_FUNC(sub_823EAA84);
PPC_FUNC_IMPL(__imp__sub_823EAA84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EAA88"))) PPC_WEAK_FUNC(sub_823EAA88);
PPC_FUNC_IMPL(__imp__sub_823EAA88) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823ea730
	sub_823EA730(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823EAA90"))) PPC_WEAK_FUNC(sub_823EAA90);
PPC_FUNC_IMPL(__imp__sub_823EAA90) {
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
	ctx.lr = 0x823EAA98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EAAB4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ef618
	ctx.lr = 0x823EAAC4;
	sub_823EF618(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823eaad8
	if (cr6.lt) goto loc_823EAAD8;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823EAAD8:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EAAE0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EAAEC"))) PPC_WEAK_FUNC(sub_823EAAEC);
PPC_FUNC_IMPL(__imp__sub_823EAAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EAAF0"))) PPC_WEAK_FUNC(sub_823EAAF0);
PPC_FUNC_IMPL(__imp__sub_823EAAF0) {
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
	ctx.lr = 0x823EAAF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-15640
	r31.s64 = r11.s64 + -15640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EAB14;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823efc20
	ctx.lr = 0x823EAB24;
	sub_823EFC20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823eab38
	if (cr6.lt) goto loc_823EAB38;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823EAB38:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EAB40;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EAB4C"))) PPC_WEAK_FUNC(sub_823EAB4C);
PPC_FUNC_IMPL(__imp__sub_823EAB4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EAB50"))) PPC_WEAK_FUNC(sub_823EAB50);
PPC_FUNC_IMPL(__imp__sub_823EAB50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823eac64
	if (cr6.eq) goto loc_823EAC64;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823eac64
	if (cr6.eq) goto loc_823EAC64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823eab94
	if (!cr6.eq) goto loc_823EAB94;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x823eac64
	if (cr6.gt) goto loc_823EAC64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stb r3,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r3.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r11,r11,-4544
	r11.s64 = r11.s64 + -4544;
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// blr 
	return;
loc_823EAB94:
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x823eabc0
	if (!cr6.eq) goto loc_823EABC0;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x823eac64
	if (cr6.gt) goto loc_823EAC64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stb r3,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r3.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r11,r11,-4544
	r11.s64 = r11.s64 + -4544;
	// addi r10,r11,96
	ctx.r10.s64 = r11.s64 + 96;
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// blr 
	return;
loc_823EABC0:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823eac30
	if (cr6.eq) goto loc_823EAC30;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823eac00
	if (cr6.eq) goto loc_823EAC00;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x823eac64
	if (!cr6.eq) goto loc_823EAC64;
	// cmpwi cr6,r10,6
	cr6.compare<int32_t>(ctx.r10.s32, 6, xer);
	// bne cr6,0x823eac64
	if (!cr6.eq) goto loc_823EAC64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r11,r11,-4544
	r11.s64 = r11.s64 + -4544;
	// stb r10,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r10.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r9,r11,144
	ctx.r9.s64 = r11.s64 + 144;
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// blr 
	return;
loc_823EAC00:
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// beq cr6,0x823eac10
	if (cr6.eq) goto loc_823EAC10;
	// cmpwi cr6,r10,6
	cr6.compare<int32_t>(ctx.r10.s32, 6, xer);
	// bne cr6,0x823eac64
	if (!cr6.eq) goto loc_823EAC64;
loc_823EAC10:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r11,-4544
	r11.s64 = r11.s64 + -4544;
	// stb r10,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r10.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// blr 
	return;
loc_823EAC30:
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// beq cr6,0x823eac48
	if (cr6.eq) goto loc_823EAC48;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// beq cr6,0x823eac48
	if (cr6.eq) goto loc_823EAC48;
	// cmpwi cr6,r10,6
	cr6.compare<int32_t>(ctx.r10.s32, 6, xer);
	// bne cr6,0x823eac64
	if (!cr6.eq) goto loc_823EAC64;
loc_823EAC48:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,-4544
	ctx.r9.s64 = r11.s64 + -4544;
	// stb r10,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r10.u8);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// blr 
	return;
loc_823EAC64:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EAC6C"))) PPC_WEAK_FUNC(sub_823EAC6C);
PPC_FUNC_IMPL(__imp__sub_823EAC6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EAC70"))) PPC_WEAK_FUNC(sub_823EAC70);
PPC_FUNC_IMPL(__imp__sub_823EAC70) {
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
	ctx.lr = 0x823EAC78;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,2
	r11.s64 = 131072;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bgt cr6,0x823eadd0
	if (cr6.gt) goto loc_823EADD0;
	// beq cr6,0x823eadb4
	if (cr6.eq) goto loc_823EADB4;
	// addis r11,r3,-1
	r11.s64 = ctx.r3.s64 + -65536;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823ead60
	if (cr0.eq) goto loc_823EAD60;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x823ead08
	if (cr6.eq) goto loc_823EAD08;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x823eade4
	if (!cr6.eq) goto loc_823EADE4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// addi r3,r11,-9904
	ctx.r3.s64 = r11.s64 + -9904;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eacfc
	if (cr6.eq) goto loc_823EACFC;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823eacfc
	if (!cr6.eq) goto loc_823EACFC;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bne 0x823eacfc
	if (!cr0.eq) goto loc_823EACFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r31,12(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EACF4;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EACFC;
	__imp__KfLowerIrql(ctx, base);
loc_823EACFC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EAD08:
	// bl 0x827bd514
	ctx.lr = 0x823EAD0C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ead34
	if (cr6.eq) goto loc_823EAD34;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823eada0
	if (cr6.eq) goto loc_823EADA0;
loc_823EAD34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd534
	ctx.lr = 0x823EAD3C;
	__imp__KeTryToAcquireSpinLockAtRaisedIrql(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ead94
	if (!cr6.eq) goto loc_823EAD94;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EAD50;
	__imp__KfLowerIrql(ctx, base);
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16388
	ctx.r3.u64 = ctx.r3.u64 | 16388;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EAD60:
	// bl 0x827bd514
	ctx.lr = 0x823EAD64;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ead8c
	if (cr6.eq) goto loc_823EAD8C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823eada0
	if (cr6.eq) goto loc_823EADA0;
loc_823EAD8C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EAD94;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
loc_823EAD94:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EADA0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EADB4:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-15640
	r11.s64 = r11.s64 + -15640;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EADC4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EADD0:
	// addis r11,r3,-2
	r11.s64 = ctx.r3.s64 + -131072;
	// addic. r11,r11,-2
	xer.ca = r11.u32 > 1;
	r11.s64 = r11.s64 + -2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823eae10
	if (cr0.eq) goto loc_823EAE10;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x823eadf4
	if (cr6.eq) goto loc_823EADF4;
loc_823EADE4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EADF4:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-15640
	r11.s64 = r11.s64 + -15640;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EAE04;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EAE10:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-15640
	r11.s64 = r11.s64 + -15640;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x827bd4a4
	ctx.lr = 0x823EAE20;
	__imp__RtlTryEnterCriticalSection(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823eacfc
	if (!cr6.eq) goto loc_823EACFC;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16388
	ctx.r3.u64 = ctx.r3.u64 | 16388;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EAE38"))) PPC_WEAK_FUNC(sub_823EAE38);
PPC_FUNC_IMPL(__imp__sub_823EAE38) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-4368
	ctx.r9.s64 = r11.s64 + -4368;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823eae78
	if (cr6.eq) goto loc_823EAE78;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823EAE78;
	sub_823EF7C8(ctx, base);
loc_823EAE78:
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

__attribute__((alias("__imp__sub_823EAE90"))) PPC_WEAK_FUNC(sub_823EAE90);
PPC_FUNC_IMPL(__imp__sub_823EAE90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// bne cr6,0x823eaea0
	if (!cr6.eq) goto loc_823EAEA0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823EAEA0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823EAEB0"))) PPC_WEAK_FUNC(sub_823EAEB0);
PPC_FUNC_IMPL(__imp__sub_823EAEB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// bne cr6,0x823eaec0
	if (!cr6.eq) goto loc_823EAEC0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823EAEC0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823EAED0"))) PPC_WEAK_FUNC(sub_823EAED0);
PPC_FUNC_IMPL(__imp__sub_823EAED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// stw r8,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EAEF4"))) PPC_WEAK_FUNC(sub_823EAEF4);
PPC_FUNC_IMPL(__imp__sub_823EAEF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EAEF8"))) PPC_WEAK_FUNC(sub_823EAEF8);
PPC_FUNC_IMPL(__imp__sub_823EAEF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EAF00"))) PPC_WEAK_FUNC(sub_823EAF00);
PPC_FUNC_IMPL(__imp__sub_823EAF00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,-8
	r11.s64 = ctx.r3.s64 + -8;
	// bne cr6,0x823eaf10
	if (!cr6.eq) goto loc_823EAF10;
	// li r11,0
	r11.s64 = 0;
loc_823EAF10:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// stw r8,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EAF30"))) PPC_WEAK_FUNC(sub_823EAF30);
PPC_FUNC_IMPL(__imp__sub_823EAF30) {
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
	ctx.lr = 0x823EAF38;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-4344
	ctx.r9.s64 = r11.s64 + -4344;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// li r29,0
	r29.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// ori r11,r8,48000
	r11.u64 = ctx.r8.u64 | 48000;
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// stb r7,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r7.u8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lwz r3,16(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// stb r29,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r29.u8);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// bne cr6,0x823eb018
	if (!cr6.eq) goto loc_823EB018;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r9,256
	ctx.r9.s64 = 256;
	// lwz r6,0(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// divwu r7,r11,r10
	ctx.r7.u32 = r11.u32 / ctx.r10.u32;
	// lbz r8,5(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// addi r30,r4,4
	r30.s64 = ctx.r4.s64 + 4;
	// divwu r5,r9,r7
	ctx.r5.u32 = ctx.r9.u32 / ctx.r7.u32;
	// twllei r10,0
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// lwz r10,20(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// twllei r7,0
	// mullw r11,r4,r8
	r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EAFC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r3,127
	ctx.r8.s64 = ctx.r3.s64 + 127;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// rlwinm r11,r8,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// beq cr6,0x823eaffc
	if (cr6.eq) goto loc_823EAFFC;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stb r29,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r29.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EAFFC:
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stb r29,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r29.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EB018:
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// stb r29,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r29.u8);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EB038"))) PPC_WEAK_FUNC(sub_823EB038);
PPC_FUNC_IMPL(__imp__sub_823EB038) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// bne cr6,0x823eb048
	if (!cr6.eq) goto loc_823EB048;
	// li r11,0
	r11.s64 = 0;
loc_823EB048:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EB050"))) PPC_WEAK_FUNC(sub_823EB050);
PPC_FUNC_IMPL(__imp__sub_823EB050) {
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
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823eb078
	if (!cr6.eq) goto loc_823EB078;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_823EB078:
	// lis r11,0
	r11.s64 = 0;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r10,256
	ctx.r10.s64 = 256;
	// ori r11,r11,48000
	r11.u64 = r11.u64 | 48000;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// twllei r9,0
	// lbz r3,1(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// divwu r4,r11,r9
	ctx.r4.u32 = r11.u32 / ctx.r9.u32;
	// lbz r6,13(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 13);
	// divwu r9,r11,r8
	ctx.r9.u32 = r11.u32 / ctx.r8.u32;
	// twllei r7,0
	// divwu r7,r11,r7
	ctx.r7.u32 = r11.u32 / ctx.r7.u32;
	// twllei r4,0
	// divwu r4,r10,r4
	ctx.r4.u32 = ctx.r10.u32 / ctx.r4.u32;
	// divwu r11,r10,r9
	r11.u32 = ctx.r10.u32 / ctx.r9.u32;
	// divwu r10,r10,r7
	ctx.r10.u32 = ctx.r10.u32 / ctx.r7.u32;
	// twllei r9,0
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// twllei r7,0
	// clrlwi r7,r11,16
	ctx.r7.u64 = r11.u32 & 0xFFFF;
	// clrlwi r4,r10,16
	ctx.r4.u64 = ctx.r10.u32 & 0xFFFF;
	// mullw r10,r9,r3
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// twllei r8,0
	// lbz r8,21(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 21);
	// mullw r3,r7,r6
	ctx.r3.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// mullw r11,r4,r8
	r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// ble cr6,0x823eb0f8
	if (!cr6.gt) goto loc_823EB0F8;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x823eb15c
	goto loc_823EB15C;
loc_823EB0F8:
	// clrlwi r9,r5,31
	ctx.r9.u64 = ctx.r5.u32 & 0x1;
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823eb11c
	if (!cr6.eq) goto loc_823EB11C;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x823eb11c
	if (!cr6.gt) goto loc_823EB11C;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// b 0x823eb15c
	goto loc_823EB15C;
loc_823EB11C:
	// rlwinm r8,r8,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823eb150
	if (cr6.eq) goto loc_823EB150;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823eb134
	if (cr6.eq) goto loc_823EB134;
	// li r11,0
	r11.s64 = 0;
loc_823EB134:
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// bl 0x823d9890
	ctx.lr = 0x823EB150;
	sub_823D9890(ctx, base);
loc_823EB150:
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r11.u8);
loc_823EB15C:
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

__attribute__((alias("__imp__sub_823EB174"))) PPC_WEAK_FUNC(sub_823EB174);
PPC_FUNC_IMPL(__imp__sub_823EB174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EB178"))) PPC_WEAK_FUNC(sub_823EB178);
PPC_FUNC_IMPL(__imp__sub_823EB178) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-4364
	ctx.r9.s64 = r11.s64 + -4364;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823eb1b8
	if (cr6.eq) goto loc_823EB1B8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823EB1B8;
	sub_823EF7C8(ctx, base);
loc_823EB1B8:
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

__attribute__((alias("__imp__sub_823EB1D0"))) PPC_WEAK_FUNC(sub_823EB1D0);
PPC_FUNC_IMPL(__imp__sub_823EB1D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// bne cr6,0x823eb1e0
	if (!cr6.eq) goto loc_823EB1E0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823EB1E0:
	// b 0x823eb050
	sub_823EB050(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823EB1E4"))) PPC_WEAK_FUNC(sub_823EB1E4);
PPC_FUNC_IMPL(__imp__sub_823EB1E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EB1E8"))) PPC_WEAK_FUNC(sub_823EB1E8);
PPC_FUNC_IMPL(__imp__sub_823EB1E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823eb22c
	if (!cr6.eq) goto loc_823EB22C;
	// lis r11,0
	r11.s64 = 0;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,256
	ctx.r9.s64 = 256;
	// lbz r8,5(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// ori r7,r11,48000
	ctx.r7.u64 = r11.u64 | 48000;
	// twllei r10,0
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// divwu r5,r9,r6
	ctx.r5.u32 = ctx.r9.u32 / ctx.r6.u32;
	// twllei r6,0
	// clrlwi r3,r5,16
	ctx.r3.u64 = ctx.r5.u32 & 0xFFFF;
	// mullw r11,r3,r8
	r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_823EB22C:
	// addi r11,r11,36
	r11.s64 = r11.s64 + 36;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EB23C"))) PPC_WEAK_FUNC(sub_823EB23C);
PPC_FUNC_IMPL(__imp__sub_823EB23C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EB240"))) PPC_WEAK_FUNC(sub_823EB240);
PPC_FUNC_IMPL(__imp__sub_823EB240) {
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
	ctx.lr = 0x823EB248;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r4,36
	ctx.r4.s64 = 36;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EB270;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823eb2b0
	if (cr6.eq) goto loc_823EB2B0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823eaf30
	ctx.lr = 0x823EB284;
	sub_823EAF30(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823eb2b0
	if (cr6.eq) goto loc_823EB2B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EB2A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EB2B0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EB2C0"))) PPC_WEAK_FUNC(sub_823EB2C0);
PPC_FUNC_IMPL(__imp__sub_823EB2C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-4364
	ctx.r10.s64 = r11.s64 + -4364;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EB2D0"))) PPC_WEAK_FUNC(sub_823EB2D0);
PPC_FUNC_IMPL(__imp__sub_823EB2D0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// clrlwi r30,r3,26
	r30.u64 = ctx.r3.u32 & 0x3F;
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823EB2FC:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x823eb2fc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823EB2FC;
	// bl 0x827bcfc4
	ctx.lr = 0x823EB30C;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x823eb3b8
	if (!cr6.eq) goto loc_823EB3B8;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823eb324
	if (!cr6.eq) goto loc_823EB324;
	// li r30,16
	r30.s64 = 16;
loc_823EB324:
	// clrlwi r6,r30,24
	ctx.r6.u64 = r30.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// li r7,2
	ctx.r7.s64 = 2;
loc_823EB334:
	// clrlwi r10,r8,31
	ctx.r10.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823eb360
	if (cr6.eq) goto loc_823EB360;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// stb r7,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r7.u8);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// stb r4,1(r31)
	PPC_STORE_U8(r31.u32 + 1, ctx.r4.u8);
	// stb r5,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r5.u8);
loc_823EB360:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// blt cr6,0x823eb334
	if (cr6.lt) goto loc_823EB334;
	// rlwinm r11,r6,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823eb388
	if (cr6.eq) goto loc_823EB388;
	// li r11,1
	r11.s64 = 1;
	// stb r11,6(r31)
	PPC_STORE_U8(r31.u32 + 6, r11.u8);
	// b 0x823eb3c8
	goto loc_823EB3C8;
loc_823EB388:
	// li r11,5
	r11.s64 = 5;
	// addi r10,r31,2
	ctx.r10.s64 = r31.s64 + 2;
loc_823EB390:
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823eb3a8
	if (!cr6.eq) goto loc_823EB3A8;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x823eb390
	if (!cr0.lt) goto loc_823EB390;
	// b 0x823eb3c8
	goto loc_823EB3C8;
loc_823EB3A8:
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// b 0x823eb3c8
	goto loc_823EB3C8;
loc_823EB3B8:
	// li r11,1
	r11.s64 = 1;
	// li r10,4
	ctx.r10.s64 = 4;
	// stb r11,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r11.u8);
	// stb r10,6(r31)
	PPC_STORE_U8(r31.u32 + 6, ctx.r10.u8);
loc_823EB3C8:
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

__attribute__((alias("__imp__sub_823EB3E0"))) PPC_WEAK_FUNC(sub_823EB3E0);
PPC_FUNC_IMPL(__imp__sub_823EB3E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,304(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 304);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,268(r13)
	r11.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// li r10,1
	ctx.r10.s64 = 1;
	// stbx r10,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r10.u8);
	// li r11,1
	r11.s64 = 1;
	// lwz r9,328(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 328);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823eb40c
	if (!cr6.eq) goto loc_823EB40C;
	// li r11,0
	r11.s64 = 0;
loc_823EB40C:
	// lwz r9,324(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 324);
	// rldicr r8,r11,56,7
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 56) & 0xFF00000000000000;
	// li r11,1
	r11.s64 = 1;
	// sradi r10,r8,8
	xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r8.s64 >> 8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823eb428
	if (!cr6.eq) goto loc_823EB428;
	// li r11,0
	r11.s64 = 0;
loc_823EB428:
	// rldicr r11,r11,56,7
	r11.u64 = __builtin_rotateleft64(r11.u64, 56) & 0xFF00000000000000;
	// lwz r9,320(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// sradi r10,r8,8
	xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r8.s64 >> 8;
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x823eb448
	if (!cr6.eq) goto loc_823EB448;
	// li r11,0
	r11.s64 = 0;
loc_823EB448:
	// rldicr r11,r11,56,7
	r11.u64 = __builtin_rotateleft64(r11.u64, 56) & 0xFF00000000000000;
	// lwz r9,316(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 316);
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// sradi r10,r8,8
	xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r8.s64 >> 8;
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x823eb468
	if (!cr6.eq) goto loc_823EB468;
	// li r11,0
	r11.s64 = 0;
loc_823EB468:
	// rldicr r11,r11,56,7
	r11.u64 = __builtin_rotateleft64(r11.u64, 56) & 0xFF00000000000000;
	// lwz r9,312(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 312);
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// sradi r10,r8,8
	xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r8.s64 >> 8;
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x823eb488
	if (!cr6.eq) goto loc_823EB488;
	// li r11,0
	r11.s64 = 0;
loc_823EB488:
	// rldicr r11,r11,56,7
	r11.u64 = __builtin_rotateleft64(r11.u64, 56) & 0xFF00000000000000;
	// lwz r9,308(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// sradi r9,r8,8
	xer.ca = (ctx.r8.s64 < 0) & ((ctx.r8.u64 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r8.s64 >> 8;
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x823eb4a8
	if (!cr6.eq) goto loc_823EB4A8;
	// li r10,0
	ctx.r10.s64 = 0;
loc_823EB4A8:
	// ld r11,0(r4)
	r11.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// rldicr r10,r10,56,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 56) & 0xFF00000000000000;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823EB4BC:
	// cmpd cr6,r10,r11
	cr6.compare<int64_t>(ctx.r10.s64, r11.s64, xer);
	// beq cr6,0x823eb4d8
	if (cr6.eq) goto loc_823EB4D8;
	// db16cyc 
	// ld r11,0(r4)
	r11.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// bne cr6,0x823eb4bc
	if (!cr6.eq) goto loc_823EB4BC;
	// blr 
	return;
loc_823EB4D8:
	// li r11,0
	r11.s64 = 0;
	// std r11,0(r4)
	PPC_STORE_U64(ctx.r4.u32 + 0, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EB4E4"))) PPC_WEAK_FUNC(sub_823EB4E4);
PPC_FUNC_IMPL(__imp__sub_823EB4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EB4E8"))) PPC_WEAK_FUNC(sub_823EB4E8);
PPC_FUNC_IMPL(__imp__sub_823EB4E8) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r30,r11,-15608
	r30.s64 = r11.s64 + -15608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf64
	ctx.lr = 0x823EB50C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,-9880
	r31.s64 = r11.s64 + -9880;
	// lwz r11,-9880(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823eb534
	if (cr6.eq) goto loc_823EB534;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd554
	ctx.lr = 0x823EB52C;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823EB534:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf54
	ctx.lr = 0x823EB53C;
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

__attribute__((alias("__imp__sub_823EB554"))) PPC_WEAK_FUNC(sub_823EB554);
PPC_FUNC_IMPL(__imp__sub_823EB554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EB558"))) PPC_WEAK_FUNC(sub_823EB558);
PPC_FUNC_IMPL(__imp__sub_823EB558) {
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
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823eb590
	if (cr6.eq) goto loc_823EB590;
	// rotlwi r3,r30,0
	ctx.r3.u64 = __builtin_rotateleft32(r30.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EB590;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EB590:
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
	ctx.lr = 0x823EB5A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823eb5c4
	if (cr6.eq) goto loc_823EB5C4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EB5C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EB5C4:
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

__attribute__((alias("__imp__sub_823EB5DC"))) PPC_WEAK_FUNC(sub_823EB5DC);
PPC_FUNC_IMPL(__imp__sub_823EB5DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EB5E0"))) PPC_WEAK_FUNC(sub_823EB5E0);
PPC_FUNC_IMPL(__imp__sub_823EB5E0) {
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
	ctx.lr = 0x823EB5E8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EB604;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eb62c
	if (cr6.eq) goto loc_823EB62C;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r7
	cr6.compare<uint32_t>(r29.u32, ctx.r7.u32, xer);
	// beq cr6,0x823eb648
	if (cr6.eq) goto loc_823EB648;
loc_823EB62C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EB634;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
	// b 0x823eb64c
	goto loc_823EB64C;
loc_823EB648:
	// lbz r28,12(r31)
	r28.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823EB64C:
	// rlwinm r10,r30,6,18,25
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0x3FC0;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + r27.u64;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r8,r30,24
	ctx.r8.u64 = r30.u32 & 0xFF;
	// addi r10,r10,168
	ctx.r10.s64 = ctx.r10.s64 + 168;
loc_823EB668:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823eb688
	if (cr6.eq) goto loc_823EB688;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// blt cr6,0x823eb668
	if (cr6.lt) goto loc_823EB668;
	// b 0x823eb6a0
	goto loc_823EB6A0;
loc_823EB688:
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,21
	r11.s64 = r11.s64 + 21;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add. r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823eb6f0
	if (!cr0.eq) goto loc_823EB6F0;
loc_823EB6A0:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823eb6e0
	if (cr6.eq) goto loc_823EB6E0;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bne cr6,0x823eb6e0
	if (!cr6.eq) goto loc_823EB6E0;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823eb6e0
	if (!cr0.eq) goto loc_823EB6E0;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EB6D8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EB6E0;
	__imp__KfLowerIrql(ctx, base);
loc_823EB6E0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823EB6F0:
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stw r24,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r24.u32);
	// beq cr6,0x823eb704
	if (cr6.eq) goto loc_823EB704;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_823EB704:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823eb750
	if (cr6.eq) goto loc_823EB750;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823eb750
	if (!cr6.eq) goto loc_823EB750;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823eb750
	if (!cr0.eq) goto loc_823EB750;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EB748;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EB750;
	__imp__KfLowerIrql(ctx, base);
loc_823EB750:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823EB75C"))) PPC_WEAK_FUNC(sub_823EB75C);
PPC_FUNC_IMPL(__imp__sub_823EB75C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EB760"))) PPC_WEAK_FUNC(sub_823EB760);
PPC_FUNC_IMPL(__imp__sub_823EB760) {
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
	ctx.lr = 0x823EB768;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EB778;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eb7a0
	if (cr6.eq) goto loc_823EB7A0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823eb7b4
	if (cr6.eq) goto loc_823EB7B4;
loc_823EB7A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EB7A8;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823EB7B4:
	// rlwinm r10,r29,6,18,25
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 6) & 0x3FC0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + r26.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// li r27,8
	r27.s64 = 8;
	// addi r28,r10,168
	r28.s64 = ctx.r10.s64 + 168;
loc_823EB7CC:
	// stw r28,296(r26)
	PPC_STORE_U32(r26.u32 + 296, r28.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823eb878
	if (cr6.eq) goto loc_823EB878;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823eb828
	if (cr6.eq) goto loc_823EB828;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823eb828
	if (!cr6.eq) goto loc_823EB828;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823eb828
	if (!cr0.eq) goto loc_823EB828;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EB820;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EB828;
	__imp__KfLowerIrql(ctx, base);
loc_823EB828:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823EB838;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x827bd514
	ctx.lr = 0x823EB83C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eb85c
	if (cr6.eq) goto loc_823EB85C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823eb870
	if (cr6.eq) goto loc_823EB870;
loc_823EB85C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EB864;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EB870:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_823EB878:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x823eb7cc
	if (!cr0.eq) goto loc_823EB7CC;
	// li r11,0
	r11.s64 = 0;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,296(r26)
	PPC_STORE_U32(r26.u32 + 296, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eb8d8
	if (cr6.eq) goto loc_823EB8D8;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823eb8d8
	if (!cr6.eq) goto loc_823EB8D8;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823eb8d8
	if (!cr0.eq) goto loc_823EB8D8;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EB8D0;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EB8D8;
	__imp__KfLowerIrql(ctx, base);
loc_823EB8D8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823EB8E0"))) PPC_WEAK_FUNC(sub_823EB8E0);
PPC_FUNC_IMPL(__imp__sub_823EB8E0) {
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
	ctx.lr = 0x823EB8E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,256(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r10,300(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 300);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x823eb958
	if (cr6.eq) goto loc_823EB958;
	// lbz r10,268(r13)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// addi r10,r10,83
	ctx.r10.s64 = ctx.r10.s64 + 83;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// beq cr6,0x823eb958
	if (cr6.eq) goto loc_823EB958;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r31,r10,-9904
	r31.s64 = ctx.r10.s64 + -9904;
	// addi r27,r3,144
	r27.s64 = ctx.r3.s64 + 144;
	// addi r28,r11,-15640
	r28.s64 = r11.s64 + -15640;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EB934:
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_823EB93C:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r26,r7
	cr6.compare<uint32_t>(r26.u32, ctx.r7.u32, xer);
	// beq cr6,0x823eb960
	if (cr6.eq) goto loc_823EB960;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,6
	cr6.compare<uint32_t>(ctx.r10.u32, 6, xer);
	// blt cr6,0x823eb93c
	if (cr6.lt) goto loc_823EB93C;
loc_823EB958:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823EB960:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x823eb9a4
	if (cr6.eq) goto loc_823EB9A4;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x823eb9a4
	if (!cr6.eq) goto loc_823EB9A4;
	// addic. r11,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	r11.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823eb9a4
	if (!cr0.eq) goto loc_823EB9A4;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EB99C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EB9A4;
	__imp__KfLowerIrql(ctx, base);
loc_823EB9A4:
	// lwz r30,24(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823eb9d4
	if (cr6.eq) goto loc_823EB9D4;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_823EB9B4:
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EB9BC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x823eb9b4
	if (!cr0.eq) goto loc_823EB9B4;
loc_823EB9C4:
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EB9CC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823eb9c4
	if (!cr0.eq) goto loc_823EB9C4;
loc_823EB9D4:
	// bl 0x827bd514
	ctx.lr = 0x823EB9D8;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eb9f8
	if (cr6.eq) goto loc_823EB9F8;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// beq cr6,0x823eba10
	if (cr6.eq) goto loc_823EBA10;
loc_823EB9F8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EBA00;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_823EBA10:
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// b 0x823eb934
	goto loc_823EB934;
}

__attribute__((alias("__imp__sub_823EBA1C"))) PPC_WEAK_FUNC(sub_823EBA1C);
PPC_FUNC_IMPL(__imp__sub_823EBA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EBA20"))) PPC_WEAK_FUNC(sub_823EBA20);
PPC_FUNC_IMPL(__imp__sub_823EBA20) {
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
	ctx.lr = 0x823EBA28;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,256(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r10,300(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 300);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ebb44
	if (cr6.eq) goto loc_823EBB44;
	// lbz r10,268(r13)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// addi r10,r10,83
	ctx.r10.s64 = ctx.r10.s64 + 83;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// beq cr6,0x823ebb44
	if (cr6.eq) goto loc_823EBB44;
	// lwz r11,296(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 296);
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// bne cr6,0x823ebb44
	if (!cr6.eq) goto loc_823EBB44;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r31,r10,-9904
	r31.s64 = ctx.r10.s64 + -9904;
	// addi r28,r11,-15640
	r28.s64 = r11.s64 + -15640;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EBA80:
	// mr r9,r13
	ctx.r9.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ebac4
	if (cr6.eq) goto loc_823EBAC4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x823ebac4
	if (!cr6.eq) goto loc_823EBAC4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ebac4
	if (!cr0.eq) goto loc_823EBAC4;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EBABC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EBAC4;
	__imp__KfLowerIrql(ctx, base);
loc_823EBAC4:
	// lwz r30,24(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823ebaf4
	if (cr6.eq) goto loc_823EBAF4;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_823EBAD4:
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823EBADC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x823ebad4
	if (!cr0.eq) goto loc_823EBAD4;
loc_823EBAE4:
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823EBAEC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823ebae4
	if (!cr0.eq) goto loc_823EBAE4;
loc_823EBAF4:
	// bl 0x827bd514
	ctx.lr = 0x823EBAF8;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ebb18
	if (cr6.eq) goto loc_823EBB18;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ebb30
	if (cr6.eq) goto loc_823EBB30;
loc_823EBB18:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EBB20;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_823EBB30:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r9,296(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 296);
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// beq cr6,0x823eba80
	if (cr6.eq) goto loc_823EBA80;
loc_823EBB44:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823EBB4C"))) PPC_WEAK_FUNC(sub_823EBB4C);
PPC_FUNC_IMPL(__imp__sub_823EBB4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EBB50"))) PPC_WEAK_FUNC(sub_823EBB50);
PPC_FUNC_IMPL(__imp__sub_823EBB50) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-9880
	ctx.r10.s64 = r11.s64 + -9880;
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// bne cr6,0x823ebb84
	if (!cr6.eq) goto loc_823EBB84;
	// bl 0x823eb4e8
	ctx.lr = 0x823EBB70;
	sub_823EB4E8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,-9864
	ctx.r3.s64 = r11.s64 + -9864;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd564
	ctx.lr = 0x823EBB84;
	__imp__KeSetEvent(ctx, base);
loc_823EBB84:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EBB94"))) PPC_WEAK_FUNC(sub_823EBB94);
PPC_FUNC_IMPL(__imp__sub_823EBB94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EBB98"))) PPC_WEAK_FUNC(sub_823EBB98);
PPC_FUNC_IMPL(__imp__sub_823EBB98) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-4320
	ctx.r10.s64 = r11.s64 + -4320;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ebbe4
	if (cr6.eq) goto loc_823EBBE4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EBBDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_823EBBE4:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// addi r9,r11,-4364
	ctx.r9.s64 = r11.s64 + -4364;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823ebc10
	if (cr6.eq) goto loc_823EBC10;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823EBC10;
	sub_823EF7C8(ctx, base);
loc_823EBC10:
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

__attribute__((alias("__imp__sub_823EBC2C"))) PPC_WEAK_FUNC(sub_823EBC2C);
PPC_FUNC_IMPL(__imp__sub_823EBC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EBC30"))) PPC_WEAK_FUNC(sub_823EBC30);
PPC_FUNC_IMPL(__imp__sub_823EBC30) {
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
	ctx.lr = 0x823EBC38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EBC44;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ebc6c
	if (cr6.eq) goto loc_823EBC6C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ebc80
	if (cr6.eq) goto loc_823EBC80;
loc_823EBC6C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EBC74;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823EBC80:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r9,40(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// stw r11,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r11.u32);
	// stw r9,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r9.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ebce4
	if (cr6.eq) goto loc_823EBCE4;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ebce4
	if (!cr6.eq) goto loc_823EBCE4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ebce4
	if (!cr0.eq) goto loc_823EBCE4;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EBCDC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EBCE4;
	__imp__KfLowerIrql(ctx, base);
loc_823EBCE4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823EBCEC"))) PPC_WEAK_FUNC(sub_823EBCEC);
PPC_FUNC_IMPL(__imp__sub_823EBCEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EBCF0"))) PPC_WEAK_FUNC(sub_823EBCF0);
PPC_FUNC_IMPL(__imp__sub_823EBCF0) {
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
	ctx.lr = 0x823EBCF8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ebd18
	if (cr6.eq) goto loc_823EBD18;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// b 0x823ebd24
	goto loc_823EBD24;
loc_823EBD18:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-4552
	ctx.r10.s64 = r11.s64 + -4552;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_823EBD24:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823ee798
	ctx.lr = 0x823EBD30;
	sub_823EE798(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ebdd0
	if (cr6.lt) goto loc_823EBDD0;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,6
	cr6.compare<uint32_t>(ctx.r10.u32, 6, xer);
	// std r11,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r11.u64);
	// std r11,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, r11.u64);
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, r11.u32);
	// stb r11,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r11.u8);
	// stb r11,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r11.u8);
	// bgt cr6,0x823ebd64
	if (cr6.gt) goto loc_823EBD64;
	// li r10,6
	ctx.r10.s64 = 6;
loc_823EBD64:
	// lis r11,0
	r11.s64 = 0;
	// stb r10,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, ctx.r10.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// ori r9,r11,48000
	ctx.r9.u64 = r11.u64 | 48000;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r9,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// bl 0x823eb1e8
	ctx.lr = 0x823EBD80;
	sub_823EB1E8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823ebdcc
	if (cr6.lt) goto loc_823EBDCC;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lbz r3,2(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// bl 0x823eb2d0
	ctx.lr = 0x823EBD98;
	sub_823EB2D0(ctx, base);
	// lbz r8,97(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r11,r6,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// beq cr6,0x823ebdc8
	if (cr6.eq) goto loc_823EBDC8;
	// mulli r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 * 44;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_823EBDC8:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823EBDCC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823EBDD0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EBDD8"))) PPC_WEAK_FUNC(sub_823EBDD8);
PPC_FUNC_IMPL(__imp__sub_823EBDD8) {
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
	ctx.lr = 0x823EBDE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r11,r27,168
	r11.s64 = r27.s64 + 168;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x823ebe04
	if (cr6.lt) goto loc_823EBE04;
	// addi r11,r27,296
	r11.s64 = r27.s64 + 296;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x823ebe08
	if (cr6.lt) goto loc_823EBE08;
loc_823EBE04:
	// li r29,0
	r29.s64 = 0;
loc_823EBE08:
	// bl 0x827bd514
	ctx.lr = 0x823EBE0C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ebe34
	if (cr6.eq) goto loc_823EBE34;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ebe48
	if (cr6.eq) goto loc_823EBE48;
loc_823EBE34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EBE3C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823EBE48:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823eba20
	ctx.lr = 0x823EBE5C;
	sub_823EBA20(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ebeb0
	if (cr6.eq) goto loc_823EBEB0;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ebeb0
	if (!cr6.eq) goto loc_823EBEB0;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ebeb0
	if (!cr0.eq) goto loc_823EBEB0;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EBEA8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EBEB0;
	__imp__KfLowerIrql(ctx, base);
loc_823EBEB0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EBEBC"))) PPC_WEAK_FUNC(sub_823EBEBC);
PPC_FUNC_IMPL(__imp__sub_823EBEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EBEC0"))) PPC_WEAK_FUNC(sub_823EBEC0);
PPC_FUNC_IMPL(__imp__sub_823EBEC0) {
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
	ctx.lr = 0x823EBEC8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r26,268(r13)
	r26.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
loc_823EBEE0:
	// bl 0x827bd514
	ctx.lr = 0x823EBEE4;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ebf04
	if (cr6.eq) goto loc_823EBF04;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// beq cr6,0x823ebf20
	if (cr6.eq) goto loc_823EBF20;
loc_823EBF04:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EBF0C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// b 0x823ebf24
	goto loc_823EBF24;
loc_823EBF20:
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823EBF24:
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// lwz r11,36(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ec01c
	if (cr6.eq) goto loc_823EC01C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf. r30,r11,r10
	r30.s64 = ctx.r10.s64 - r11.s64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x823ec01c
	if (cr0.eq) goto loc_823EC01C;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x823ebf74
	if (cr6.eq) goto loc_823EBF74;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
loc_823EBF74:
	// lwz r9,40(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// addi r8,r26,36
	ctx.r8.s64 = r26.s64 + 36;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// stwx r30,r7,r27
	PPC_STORE_U32(ctx.r7.u32 + r27.u32, r30.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ebff0
	if (cr6.eq) goto loc_823EBFF0;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ebff0
	if (!cr6.eq) goto loc_823EBFF0;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ebff0
	if (!cr0.eq) goto loc_823EBFF0;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EBFE8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EBFF0;
	__imp__KfLowerIrql(ctx, base);
loc_823EBFF0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EC004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ebee0
	if (cr6.lt) goto loc_823EBEE0;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823efd30
	ctx.lr = 0x823EC018;
	sub_823EFD30(ctx, base);
	// b 0x823ebee0
	goto loc_823EBEE0;
loc_823EC01C:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823ec05c
	if (cr6.eq) goto loc_823EC05C;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823ec05c
	if (!cr6.eq) goto loc_823EC05C;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ec05c
	if (!cr0.eq) goto loc_823EC05C;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EC054;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EC05C;
	__imp__KfLowerIrql(ctx, base);
loc_823EC05C:
	// addi r11,r26,36
	r11.s64 = r26.s64 + 36;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r27
	PPC_STORE_U32(ctx.r9.u32 + r27.u32, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823EC074"))) PPC_WEAK_FUNC(sub_823EC074);
PPC_FUNC_IMPL(__imp__sub_823EC074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EC078"))) PPC_WEAK_FUNC(sub_823EC078);
PPC_FUNC_IMPL(__imp__sub_823EC078) {
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
	ctx.lr = 0x823EC080;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x827bd514
	ctx.lr = 0x823EC090;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ec0b8
	if (cr6.eq) goto loc_823EC0B8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ec0cc
	if (cr6.eq) goto loc_823EC0CC;
loc_823EC0B8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EC0C0;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EC0CC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r30,r28,68
	r30.s64 = r28.s64 + 68;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_823EC0D8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x823ec104
	if (cr6.eq) goto loc_823EC104;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// subf. r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823ec104
	if (cr0.eq) goto loc_823EC104;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ef718
	ctx.lr = 0x823EC0F8;
	sub_823EF718(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bge cr6,0x823ec0d8
	if (!cr6.lt) goto loc_823EC0D8;
loc_823EC104:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823ec150
	if (cr6.eq) goto loc_823EC150;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823ec150
	if (!cr6.eq) goto loc_823EC150;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ec150
	if (!cr0.eq) goto loc_823EC150;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EC148;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EC150;
	__imp__KfLowerIrql(ctx, base);
loc_823EC150:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EC15C"))) PPC_WEAK_FUNC(sub_823EC15C);
PPC_FUNC_IMPL(__imp__sub_823EC15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EC160"))) PPC_WEAK_FUNC(sub_823EC160);
PPC_FUNC_IMPL(__imp__sub_823EC160) {
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
	ctx.lr = 0x823EC168;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EC174;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ec19c
	if (cr6.eq) goto loc_823EC19C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ec1b0
	if (cr6.eq) goto loc_823EC1B0;
loc_823EC19C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EC1A4;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EC1B0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r3,r28,80
	ctx.r3.s64 = r28.s64 + 80;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x823ebc30
	ctx.lr = 0x823EC1C0;
	sub_823EBC30(ctx, base);
	// lbz r11,128(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 128);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ec1f4
	if (cr6.eq) goto loc_823EC1F4;
	// li r29,0
	r29.s64 = 0;
loc_823EC1D4:
	// lwz r11,124(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 124);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x823ebc30
	ctx.lr = 0x823EC1E0;
	sub_823EBC30(ctx, base);
	// lbz r11,128(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 128);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,44
	r29.s64 = r29.s64 + 44;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823ec1d4
	if (cr6.lt) goto loc_823EC1D4;
loc_823EC1F4:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823ec240
	if (cr6.eq) goto loc_823EC240;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823ec240
	if (!cr6.eq) goto loc_823EC240;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ec240
	if (!cr0.eq) goto loc_823EC240;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EC238;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EC240;
	__imp__KfLowerIrql(ctx, base);
loc_823EC240:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823EC248"))) PPC_WEAK_FUNC(sub_823EC248);
PPC_FUNC_IMPL(__imp__sub_823EC248) {
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
	ctx.lr = 0x823EC250;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r26,r4,24
	r26.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x823ec2f4
	if (cr6.eq) goto loc_823EC2F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823eb760
	ctx.lr = 0x823EC26C;
	sub_823EB760(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r27,r31,140
	r27.s64 = r31.s64 + 140;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lwz r3,24(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// bl 0x827bd594
	ctx.lr = 0x823EC284;
	__imp__XAudioGetVoiceCategoryVolumeChangeMask(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// addi r29,r31,132
	r29.s64 = r31.s64 + 132;
loc_823EC290:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ec2c8
	if (cr6.lt) goto loc_823EC2C8;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// and r10,r11,r28
	ctx.r10.u64 = r11.u64 & r28.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ec2b4
	if (cr6.eq) goto loc_823EC2B4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd584
	ctx.lr = 0x823EC2B4;
	__imp__XAudioGetVoiceCategoryVolume(ctx, base);
loc_823EC2B4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// rotlwi r28,r28,1
	r28.u64 = __builtin_rotateleft32(r28.u32, 1);
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// blt cr6,0x823ec290
	if (cr6.lt) goto loc_823EC290;
loc_823EC2C8:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// lwz r11,304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 304);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x823ec2f4
	if (!cr6.gt) goto loc_823EC2F4;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r10,-9848
	ctx.r3.s64 = ctx.r10.s64 + -9848;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd574
	ctx.lr = 0x823EC2F4;
	__imp__KeReleaseSemaphore(ctx, base);
loc_823EC2F4:
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ebec0
	ctx.lr = 0x823EC300;
	sub_823EBEC0(ctx, base);
	// addi r4,r31,356
	ctx.r4.s64 = r31.s64 + 356;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eb3e0
	ctx.lr = 0x823EC30C;
	sub_823EB3E0(ctx, base);
	// lbz r11,128(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 128);
	// li r29,1
	r29.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ec360
	if (cr6.eq) goto loc_823EC360;
	// li r28,0
	r28.s64 = 0;
loc_823EC324:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r4,r28,r11
	ctx.r4.u64 = r28.u64 + r11.u64;
	// bl 0x823ebec0
	ctx.lr = 0x823EC334;
	sub_823EBEC0(ctx, base);
	// rlwinm r11,r29,3,0,28
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r11,356
	ctx.r4.s64 = r11.s64 + 356;
	// bl 0x823eb3e0
	ctx.lr = 0x823EC348;
	sub_823EB3E0(ctx, base);
	// lbz r11,128(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 128);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// xori r29,r29,1
	r29.u64 = r29.u64 ^ 1;
	// addi r28,r28,44
	r28.s64 = r28.s64 + 44;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823ec324
	if (cr6.lt) goto loc_823EC324;
loc_823EC360:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x823ec37c
	if (cr6.eq) goto loc_823EC37C;
	// li r11,0
	r11.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eb760
	ctx.lr = 0x823EC37C;
	sub_823EB760(ctx, base);
loc_823EC37C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823EC384"))) PPC_WEAK_FUNC(sub_823EC384);
PPC_FUNC_IMPL(__imp__sub_823EC384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EC388"))) PPC_WEAK_FUNC(sub_823EC388);
PPC_FUNC_IMPL(__imp__sub_823EC388) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823f4f48
	ctx.lr = 0x823EC3A8;
	sub_823F4F48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ec3f8
	if (cr6.eq) goto loc_823EC3F8;
loc_823EC3B0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x823ec3e0
	if (cr6.eq) goto loc_823EC3E0;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
loc_823EC3E0:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f4f48
	ctx.lr = 0x823EC3F0;
	sub_823F4F48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823ec3b0
	if (!cr6.eq) goto loc_823EC3B0;
loc_823EC3F8:
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

__attribute__((alias("__imp__sub_823EC40C"))) PPC_WEAK_FUNC(sub_823EC40C);
PPC_FUNC_IMPL(__imp__sub_823EC40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EC410"))) PPC_WEAK_FUNC(sub_823EC410);
PPC_FUNC_IMPL(__imp__sub_823EC410) {
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
	ctx.lr = 0x823EC418;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-4300
	ctx.r10.s64 = r11.s64 + -4300;
	// stw r10,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r10.u32);
	// bl 0x821a5cc0
	ctx.lr = 0x823EC430;
	sub_821A5CC0(ctx, base);
	// lwz r11,64(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ec454
	if (cr6.eq) goto loc_823EC454;
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EC454;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EC454:
	// lwz r11,304(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 304);
	// li r22,0
	r22.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ec4b0
	if (cr6.eq) goto loc_823EC4B0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,-9812
	ctx.r3.s64 = r11.s64 + -9812;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd564
	ctx.lr = 0x823EC478;
	__imp__KeSetEvent(ctx, base);
	// addi r31,r23,308
	r31.s64 = r23.s64 + 308;
	// li r30,6
	r30.s64 = 6;
	// li r29,-1
	r29.s64 = -1;
loc_823EC484:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ec4a4
	if (cr6.eq) goto loc_823EC4A4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82135db8
	ctx.lr = 0x823EC498;
	sub_82135DB8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8244eee0
	ctx.lr = 0x823EC4A0;
	sub_8244EEE0(ctx, base);
	// stw r22,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r22.u32);
loc_823EC4A4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823ec484
	if (!cr0.eq) goto loc_823EC484;
loc_823EC4B0:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r30,r11,-15608
	r30.s64 = r11.s64 + -15608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf64
	ctx.lr = 0x823EC4C0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,-9880
	r31.s64 = r11.s64 + -9880;
	// lwz r11,-9880(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ec4e8
	if (cr6.eq) goto loc_823EC4E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd554
	ctx.lr = 0x823EC4E0;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// mr r11,r22
	r11.u64 = r22.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823EC4E8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf54
	ctx.lr = 0x823EC4F0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// bl 0x827bd514
	ctx.lr = 0x823EC4F4;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ec51c
	if (cr6.eq) goto loc_823EC51C;
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x823ec538
	if (cr6.eq) goto loc_823EC538;
loc_823EC51C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EC524;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r29,r30
	r29.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r27,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r27.u8);
	// b 0x823ec53c
	goto loc_823EC53C;
loc_823EC538:
	// lbz r27,12(r31)
	r27.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823EC53C:
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// addi r21,r23,80
	r21.s64 = r23.s64 + 80;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823f4f48
	ctx.lr = 0x823EC558;
	sub_823F4F48(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823ec620
	if (cr6.eq) goto loc_823EC620;
loc_823EC564:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823ec5a4
	if (cr6.eq) goto loc_823EC5A4;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x823ec5a4
	if (!cr6.eq) goto loc_823EC5A4;
	// addic. r11,r30,-1
	xer.ca = r30.u32 > 0;
	r11.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ec5a4
	if (!cr0.eq) goto loc_823EC5A4;
	// mr r11,r22
	r11.u64 = r22.u64;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EC59C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EC5A4;
	__imp__KfLowerIrql(ctx, base);
loc_823EC5A4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EC5B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x827bd514
	ctx.lr = 0x823EC5BC;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ec5dc
	if (cr6.eq) goto loc_823EC5DC;
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x823ec5f8
	if (cr6.eq) goto loc_823EC5F8;
loc_823EC5DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EC5E4;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r29,r30
	r29.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r27,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r27.u8);
	// b 0x823ec5fc
	goto loc_823EC5FC;
loc_823EC5F8:
	// lbz r27,12(r31)
	r27.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823EC5FC:
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823f4f48
	ctx.lr = 0x823EC614;
	sub_823F4F48(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823ec564
	if (!cr6.eq) goto loc_823EC564;
loc_823EC620:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823ec660
	if (cr6.eq) goto loc_823EC660;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x823ec660
	if (!cr6.eq) goto loc_823EC660;
	// addic. r11,r30,-1
	xer.ca = r30.u32 > 0;
	r11.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ec660
	if (!cr0.eq) goto loc_823EC660;
	// mr r11,r22
	r11.u64 = r22.u64;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EC658;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EC660;
	__imp__KfLowerIrql(ctx, base);
loc_823EC660:
	// lbz r11,128(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 128);
	// mr r24,r22
	r24.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ec7f4
	if (cr6.eq) goto loc_823EC7F4;
	// mr r25,r22
	r25.u64 = r22.u64;
loc_823EC674:
	// lwz r11,124(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 124);
	// add r26,r25,r11
	r26.u64 = r25.u64 + r11.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EC680;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ec6a0
	if (cr6.eq) goto loc_823EC6A0;
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x823ec6bc
	if (cr6.eq) goto loc_823EC6BC;
loc_823EC6A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EC6A8;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r29,r30
	r29.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r27,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r27.u8);
	// b 0x823ec6c0
	goto loc_823EC6C0;
loc_823EC6BC:
	// lbz r27,12(r31)
	r27.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823EC6C0:
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823f4f48
	ctx.lr = 0x823EC6D8;
	sub_823F4F48(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823ec7a0
	if (cr6.eq) goto loc_823EC7A0;
loc_823EC6E4:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823ec724
	if (cr6.eq) goto loc_823EC724;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x823ec724
	if (!cr6.eq) goto loc_823EC724;
	// addic. r11,r30,-1
	xer.ca = r30.u32 > 0;
	r11.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ec724
	if (!cr0.eq) goto loc_823EC724;
	// mr r11,r22
	r11.u64 = r22.u64;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EC71C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EC724;
	__imp__KfLowerIrql(ctx, base);
loc_823EC724:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EC738;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x827bd514
	ctx.lr = 0x823EC73C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ec75c
	if (cr6.eq) goto loc_823EC75C;
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x823ec778
	if (cr6.eq) goto loc_823EC778;
loc_823EC75C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EC764;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r29,r30
	r29.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r27,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r27.u8);
	// b 0x823ec77c
	goto loc_823EC77C;
loc_823EC778:
	// lbz r27,12(r31)
	r27.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823EC77C:
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823f4f48
	ctx.lr = 0x823EC794;
	sub_823F4F48(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823ec6e4
	if (!cr6.eq) goto loc_823EC6E4;
loc_823EC7A0:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823ec7e0
	if (cr6.eq) goto loc_823EC7E0;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x823ec7e0
	if (!cr6.eq) goto loc_823EC7E0;
	// addic. r11,r30,-1
	xer.ca = r30.u32 > 0;
	r11.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ec7e0
	if (!cr0.eq) goto loc_823EC7E0;
	// mr r11,r22
	r11.u64 = r22.u64;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EC7D8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EC7E0;
	__imp__KfLowerIrql(ctx, base);
loc_823EC7E0:
	// lbz r11,128(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 128);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,44
	r25.s64 = r25.s64 + 44;
	// cmplw cr6,r24,r11
	cr6.compare<uint32_t>(r24.u32, r11.u32, xer);
	// blt cr6,0x823ec674
	if (cr6.lt) goto loc_823EC674;
loc_823EC7F4:
	// lwz r3,64(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ec814
	if (cr6.eq) goto loc_823EC814;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EC810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r22,64(r23)
	PPC_STORE_U32(r23.u32 + 64, r22.u32);
loc_823EC814:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r11,r22
	r11.u64 = r22.u64;
	// stw r11,-9796(r10)
	PPC_STORE_U32(ctx.r10.u32 + -9796, r11.u32);
	// lwz r3,60(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ec834
	if (cr6.eq) goto loc_823EC834;
	// bl 0x823eaeb0
	ctx.lr = 0x823EC830;
	sub_823EAEB0(ctx, base);
	// stw r22,60(r23)
	PPC_STORE_U32(r23.u32 + 60, r22.u32);
loc_823EC834:
	// addi r31,r23,12
	r31.s64 = r23.s64 + 12;
	// li r29,6
	r29.s64 = 6;
loc_823EC83C:
	// li r30,2
	r30.s64 = 2;
loc_823EC840:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ec854
	if (cr6.eq) goto loc_823EC854;
	// bl 0x823eaeb0
	ctx.lr = 0x823EC850;
	sub_823EAEB0(ctx, base);
	// stw r22,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r22.u32);
loc_823EC854:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823ec840
	if (!cr0.eq) goto loc_823EC840;
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x823ec83c
	if (!cr0.eq) goto loc_823EC83C;
	// addi r3,r21,24
	ctx.r3.s64 = r21.s64 + 24;
	// bl 0x823ec388
	ctx.lr = 0x823EC870;
	sub_823EC388(ctx, base);
	// addi r3,r21,12
	ctx.r3.s64 = r21.s64 + 12;
	// bl 0x823ec388
	ctx.lr = 0x823EC878;
	sub_823EC388(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823ec388
	ctx.lr = 0x823EC880;
	sub_823EC388(ctx, base);
	// addi r3,r23,68
	ctx.r3.s64 = r23.s64 + 68;
	// bl 0x823ec388
	ctx.lr = 0x823EC888;
	sub_823EC388(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r3,8(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// addi r10,r11,-4320
	ctx.r10.s64 = r11.s64 + -4320;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r10.u32);
	// beq cr6,0x823ec8b4
	if (cr6.eq) goto loc_823EC8B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EC8B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r22,8(r23)
	PPC_STORE_U32(r23.u32 + 8, r22.u32);
loc_823EC8B4:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-4364
	ctx.r10.s64 = r11.s64 + -4364;
	// stw r10,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_823EC8C8"))) PPC_WEAK_FUNC(sub_823EC8C8);
PPC_FUNC_IMPL(__imp__sub_823EC8C8) {
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
	ctx.lr = 0x823EC8D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,268(r13)
	r11.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r10,256(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// addi r9,r11,83
	ctx.r9.s64 = r11.s64 + 83;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-9796(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -9796);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r28,r9,-9828
	r28.s64 = ctx.r9.s64 + -9828;
	// stwx r10,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r10.u32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r27,r10,-9848
	r27.s64 = ctx.r10.s64 + -9848;
	// addi r29,r11,-9812
	r29.s64 = r11.s64 + -9812;
loc_823EC908:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x827bd5a4
	ctx.lr = 0x823EC920;
	__imp__KeWaitForSingleObject(ctx, base);
	// lwz r3,-9796(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9796);
	// lwz r11,300(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 300);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ec95c
	if (cr6.eq) goto loc_823EC95C;
	// lwz r11,304(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 304);
	// addic. r5,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r5.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq 0x823ec96c
	if (cr0.eq) goto loc_823EC96C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd574
	ctx.lr = 0x823EC958;
	__imp__KeReleaseSemaphore(ctx, base);
	// b 0x823ec96c
	goto loc_823EC96C;
loc_823EC95C:
	// bl 0x823ec160
	ctx.lr = 0x823EC960;
	sub_823EC160(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-9796(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9796);
	// bl 0x823ec248
	ctx.lr = 0x823EC96C;
	sub_823EC248(ctx, base);
loc_823EC96C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd564
	ctx.lr = 0x823EC97C;
	__imp__KeSetEvent(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823ec908
	if (cr6.eq) goto loc_823EC908;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EC990"))) PPC_WEAK_FUNC(sub_823EC990);
PPC_FUNC_IMPL(__imp__sub_823EC990) {
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
	// lbz r11,268(r13)
	r11.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r9,256(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// addi r8,r11,83
	ctx.r8.s64 = r11.s64 + 83;
	// addi r30,r10,-9848
	r30.s64 = ctx.r10.s64 + -9848;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-9796(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -9796);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
	// bl 0x827bd5a4
	ctx.lr = 0x823EC9E0;
	__imp__KeWaitForSingleObject(ctx, base);
	// lwz r3,-9796(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9796);
	// lwz r9,300(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 300);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823eca20
	if (cr6.eq) goto loc_823ECA20;
loc_823EC9F0:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823ec248
	ctx.lr = 0x823EC9F8;
	sub_823EC248(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x827bd5a4
	ctx.lr = 0x823ECA10;
	__imp__KeWaitForSingleObject(ctx, base);
	// lwz r3,-9796(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9796);
	// lwz r11,300(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 300);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ec9f0
	if (!cr6.eq) goto loc_823EC9F0;
loc_823ECA20:
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

__attribute__((alias("__imp__sub_823ECA3C"))) PPC_WEAK_FUNC(sub_823ECA3C);
PPC_FUNC_IMPL(__imp__sub_823ECA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ECA40"))) PPC_WEAK_FUNC(sub_823ECA40);
PPC_FUNC_IMPL(__imp__sub_823ECA40) {
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
	ctx.lr = 0x823ECA48;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r28
	r29.u64 = r28.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x823ECA5C;
	sub_821A5CC0(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r30,r11,-15672
	r30.s64 = r11.s64 + -15672;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x823ECA6C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,256(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// lwz r10,304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r11.u32);
	// beq cr6,0x823ecaf4
	if (cr6.eq) goto loc_823ECAF4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,-9812
	ctx.r3.s64 = r11.s64 + -9812;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bd564
	ctx.lr = 0x823ECA94;
	__imp__KeSetEvent(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// addi r8,r10,-9828
	ctx.r8.s64 = ctx.r10.s64 + -9828;
	// addi r7,r9,-9864
	ctx.r7.s64 = ctx.r9.s64 + -9864;
	// li r5,44
	ctx.r5.s64 = 44;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x823d9890
	ctx.lr = 0x823ECAC0;
	sub_823D9890(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x827bd5b4
	ctx.lr = 0x823ECAE4;
	__imp__KeWaitForMultipleObjects(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x823ecb08
	if (!cr6.eq) goto loc_823ECB08;
	// li r29,1
	r29.s64 = 1;
	// b 0x823ecb08
	goto loc_823ECB08;
loc_823ECAF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ec160
	ctx.lr = 0x823ECAFC;
	sub_823EC160(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ec248
	ctx.lr = 0x823ECB08;
	sub_823EC248(ctx, base);
loc_823ECB08:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ecb3c
	if (!cr6.eq) goto loc_823ECB3C;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ECB28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ecb3c
	if (cr6.lt) goto loc_823ECB3C;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823efd30
	ctx.lr = 0x823ECB3C;
	sub_823EFD30(ctx, base);
loc_823ECB3C:
	// stw r28,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r28.u32);
	// bl 0x823efd68
	ctx.lr = 0x823ECB44;
	sub_823EFD68(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x823ECB4C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823ECB58"))) PPC_WEAK_FUNC(sub_823ECB58);
PPC_FUNC_IMPL(__imp__sub_823ECB58) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-4320
	ctx.r9.s64 = r11.s64 + -4320;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r4,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r4.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823ecba0
	if (cr6.eq) goto loc_823ECBA0;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ECBA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823ECBA0:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
	// addi r9,r10,-4300
	ctx.r9.s64 = ctx.r10.s64 + -4300;
	// addi r10,r31,68
	ctx.r10.s64 = r31.s64 + 68;
	// li r8,24
	ctx.r8.s64 = 24;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r10,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r10.u32);
	// stw r10,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r10.u32);
	// addi r9,r11,12
	ctx.r9.s64 = r11.s64 + 12;
	// stw r8,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r8.u32);
	// addi r10,r11,24
	ctx.r10.s64 = r11.s64 + 24;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// lis r11,16256
	r11.s64 = 1065353216;
	// stw r7,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r7.u32);
	// addi r7,r31,132
	ctx.r7.s64 = r31.s64 + 132;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r9.u32);
	// stw r9,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r9.u32);
	// stw r8,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r8.u32);
	// stw r10,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r10.u32);
	// stw r10,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r10.u32);
	// stw r9,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r9.u32);
	// stw r10,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r10.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// stw r31,-9796(r6)
	PPC_STORE_U32(ctx.r6.u32 + -9796, r31.u32);
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

__attribute__((alias("__imp__sub_823ECC2C"))) PPC_WEAK_FUNC(sub_823ECC2C);
PPC_FUNC_IMPL(__imp__sub_823ECC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ECC30"))) PPC_WEAK_FUNC(sub_823ECC30);
PPC_FUNC_IMPL(__imp__sub_823ECC30) {
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
	// bl 0x823ec410
	ctx.lr = 0x823ECC48;
	sub_823EC410(ctx, base);
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

__attribute__((alias("__imp__sub_823ECC60"))) PPC_WEAK_FUNC(sub_823ECC60);
PPC_FUNC_IMPL(__imp__sub_823ECC60) {
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
	ctx.lr = 0x823ECC68;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x823ECC78;
	sub_821A5CC0(ctx, base);
	// lbz r11,1(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 1);
	// li r25,0
	r25.s64 = 0;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stb r11,128(r30)
	PPC_STORE_U8(r30.u32 + 128, r11.u8);
	// beq cr6,0x823ecd60
	if (cr6.eq) goto loc_823ECD60;
	// lis r11,1489
	r11.s64 = 97583104;
	// ori r10,r11,29789
	ctx.r10.u64 = r11.u64 | 29789;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bgt cr6,0x823eccb4
	if (cr6.gt) goto loc_823ECCB4;
	// mulli r11,r31,44
	r11.s64 = r31.s64 * 44;
	// li r10,-5
	ctx.r10.s64 = -5;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x823eccb8
	if (!cr6.gt) goto loc_823ECCB8;
loc_823ECCB4:
	// li r4,-1
	ctx.r4.s64 = -1;
loc_823ECCB8:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ECCCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ecd40
	if (cr6.eq) goto loc_823ECD40;
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// addic. r7,r31,-1
	xer.ca = r31.u32 > 0;
	ctx.r7.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// blt 0x823ecd38
	if (cr0.lt) goto loc_823ECD38;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r6,24
	ctx.r6.s64 = 24;
loc_823ECCF4:
	// addi r9,r11,-4
	ctx.r9.s64 = r11.s64 + -4;
	// stw r10,-12(r11)
	PPC_STORE_U32(r11.u32 + -12, ctx.r10.u32);
	// addi r8,r11,8
	ctx.r8.s64 = r11.s64 + 8;
	// stw r10,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r10.u32);
	// stw r5,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r5.u32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stw r9,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r9.u32);
	// addi r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 + 44;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r6,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r6.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// addi r11,r11,44
	r11.s64 = r11.s64 + 44;
	// bge 0x823eccf4
	if (!cr0.lt) goto loc_823ECCF4;
loc_823ECD38:
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// b 0x823ecd44
	goto loc_823ECD44;
loc_823ECD40:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823ECD44:
	// stw r11,124(r30)
	PPC_STORE_U32(r30.u32 + 124, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ecd60
	if (!cr6.eq) goto loc_823ECD60;
loc_823ECD50:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_823ECD60:
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ecd74
	if (cr6.eq) goto loc_823ECD74;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// b 0x823ecd80
	goto loc_823ECD80;
loc_823ECD74:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-4552
	ctx.r10.s64 = r11.s64 + -4552;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
loc_823ECD80:
	// addi r5,r30,60
	ctx.r5.s64 = r30.s64 + 60;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x823ee7d0
	ctx.lr = 0x823ECD90;
	sub_823EE7D0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x823ecff4
	if (cr6.lt) goto loc_823ECFF4;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r27,1
	r27.s64 = 1;
	// addi r11,r10,-9812
	r11.s64 = ctx.r10.s64 + -9812;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// stb r9,-9812(r10)
	PPC_STORE_U8(ctx.r10.u32 + -9812, ctx.r9.u8);
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// addi r10,r6,-9828
	ctx.r10.s64 = ctx.r6.s64 + -9828;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// addi r11,r10,8
	r11.s64 = ctx.r10.s64 + 8;
	// stb r8,-9828(r6)
	PPC_STORE_U8(ctx.r6.u32 + -9828, ctx.r8.u8);
	// addi r9,r10,8
	ctx.r9.s64 = ctx.r10.s64 + 8;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// addi r3,r4,-9848
	ctx.r3.s64 = ctx.r4.s64 + -9848;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd5e4
	ctx.lr = 0x823ECE04;
	__imp__KeInitializeSemaphore(ctx, base);
	// lis r3,-32115
	ctx.r3.s64 = -2104688640;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// addi r11,r3,-9864
	r11.s64 = ctx.r3.s64 + -9864;
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// addi r8,r11,8
	ctx.r8.s64 = r11.s64 + 8;
	// stb r10,-9864(r3)
	PPC_STORE_U8(ctx.r3.u32 + -9864, ctx.r10.u8);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// addi r3,r6,-9880
	ctx.r3.s64 = ctx.r6.s64 + -9880;
	// lis r7,-32193
	ctx.r7.s64 = -2109800448;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// addi r9,r7,-17584
	ctx.r9.s64 = ctx.r7.s64 + -17584;
	// lis r8,32128
	ctx.r8.s64 = 2105540608;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r9,-9880(r6)
	PPC_STORE_U32(ctx.r6.u32 + -9880, ctx.r9.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// bl 0x827bd554
	ctx.lr = 0x823ECE50;
	__imp__ExRegisterTitleTerminateNotification(ctx, base);
	// stw r25,304(r30)
	PPC_STORE_U32(r30.u32 + 304, r25.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lbz r3,2(r24)
	ctx.r3.u64 = PPC_LOAD_U8(r24.u32 + 2);
	// bl 0x823eb2d0
	ctx.lr = 0x823ECE60;
	sub_823EB2D0(ctx, base);
	// mr r31,r25
	r31.u64 = r25.u64;
	// addi r29,r30,308
	r29.s64 = r30.s64 + 308;
	// lis r28,-32256
	r28.s64 = -2113929216;
loc_823ECE6C:
	// addi r11,r1,98
	r11.s64 = ctx.r1.s64 + 98;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// lbzx r11,r31,r11
	r11.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// clrlwi r10,r11,30
	ctx.r10.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ecf00
	if (cr6.eq) goto loc_823ECF00;
	// lis r10,-32193
	ctx.r10.s64 = -2109800448;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// addi r7,r10,-13936
	ctx.r7.s64 = ctx.r10.s64 + -13936;
	// bne cr6,0x823ece9c
	if (!cr6.eq) goto loc_823ECE9C;
	// lis r11,-32193
	r11.s64 = -2109800448;
	// addi r7,r11,-14136
	ctx.r7.s64 = r11.s64 + -14136;
loc_823ECE9C:
	// slw r11,r27,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r27.u32 << (r31.u8 & 0x3F));
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwimi r9,r11,24,0,7
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 24) & 0xFF000000) | (ctx.r9.u64 & 0xFFFFFFFF00FFFFFF);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x827bd5d4
	ctx.lr = 0x823ECEC0;
	__imp__ExCreateThread(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ecd50
	if (cr6.lt) goto loc_823ECD50;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,2532(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 2532);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x827bce84
	ctx.lr = 0x823ECED8;
	__imp__ObReferenceObjectByHandle(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce74
	ctx.lr = 0x823ECEE4;
	__imp__KeSetBasePriorityThread(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bd5c4
	ctx.lr = 0x823ECEEC;
	__imp__KeResumeThread(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x823ECEF4;
	__imp__ObDereferenceObject(ctx, base);
	// lwz r11,304(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 304);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,304(r30)
	PPC_STORE_U32(r30.u32 + 304, r11.u32);
loc_823ECF00:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,6
	cr6.compare<int32_t>(r31.s32, 6, xer);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// blt cr6,0x823ece6c
	if (cr6.lt) goto loc_823ECE6C;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lbz r11,0(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 0);
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// std r25,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r25.u64);
	// std r25,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r25.u64);
	// stw r25,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r25.u32);
	// stb r25,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r25.u8);
	// stb r25,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r25.u8);
	// bgt cr6,0x823ecf40
	if (cr6.gt) goto loc_823ECF40;
	// li r11,6
	r11.s64 = 6;
loc_823ECF40:
	// lis r10,0
	ctx.r10.s64 = 0;
	// stb r11,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r11.u8);
	// mr r28,r25
	r28.u64 = r25.u64;
	// ori r8,r10,48000
	ctx.r8.u64 = ctx.r10.u64 | 48000;
	// li r29,3
	r29.s64 = 3;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
loc_823ECF58:
	// addi r11,r1,98
	r11.s64 = ctx.r1.s64 + 98;
	// lbzx r10,r28,r11
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ecf9c
	if (cr6.eq) goto loc_823ECF9C;
	// mr r31,r25
	r31.u64 = r25.u64;
loc_823ECF6C:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x823ecf9c
	if (cr6.lt) goto loc_823ECF9C;
	// add r11,r29,r31
	r11.u64 = r29.u64 + r31.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r30
	ctx.r5.u64 = r11.u64 + r30.u64;
	// bl 0x823eb240
	ctx.lr = 0x823ECF8C;
	sub_823EB240(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,2
	cr6.compare<uint32_t>(r31.u32, 2, xer);
	// blt cr6,0x823ecf6c
	if (cr6.lt) goto loc_823ECF6C;
loc_823ECF9C:
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmplwi cr6,r29,15
	cr6.compare<uint32_t>(r29.u32, 15, xer);
	// blt cr6,0x823ecf58
	if (cr6.lt) goto loc_823ECF58;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x823ecff4
	if (cr6.lt) goto loc_823ECFF4;
	// addi r31,r30,64
	r31.s64 = r30.s64 + 64;
	// lwz r3,8(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823f5bf0
	ctx.lr = 0x823ECFC4;
	sub_823F5BF0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ecff8
	if (cr6.lt) goto loc_823ECFF8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32193
	ctx.r10.s64 = -2109800448;
	// addi r4,r10,22224
	ctx.r4.s64 = ctx.r10.s64 + 22224;
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823ECFEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_823ECFF4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_823ECFF8:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823ED000"))) PPC_WEAK_FUNC(sub_823ED000);
PPC_FUNC_IMPL(__imp__sub_823ED000) {
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
	ctx.lr = 0x823ED008;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x823ebcf0
	ctx.lr = 0x823ED020;
	sub_823EBCF0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ed034
	if (cr6.lt) goto loc_823ED034;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r4,r11,372
	ctx.r4.s64 = r11.s64 + 372;
	// b 0x823ed038
	goto loc_823ED038;
loc_823ED034:
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_823ED038:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ed0d4
	if (cr6.lt) goto loc_823ED0D4;
	// lis r3,24962
	ctx.r3.s64 = 1635909632;
	// addi r5,r1,156
	ctx.r5.s64 = ctx.r1.s64 + 156;
	// ori r3,r3,5
	ctx.r3.u64 = ctx.r3.u64 | 5;
	// bl 0x823f6188
	ctx.lr = 0x823ED054;
	sub_823F6188(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x823ed0d4
	if (cr6.lt) goto loc_823ED0D4;
	// lwz r3,156(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// li r4,372
	ctx.r4.s64 = 372;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ED078;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ed094
	if (cr6.eq) goto loc_823ED094;
	// lwz r4,156(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// bl 0x823ecb58
	ctx.lr = 0x823ED088;
	sub_823ECB58(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823ed0a0
	if (!cr6.eq) goto loc_823ED0A0;
loc_823ED094:
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,14
	r31.u64 = r31.u64 | 14;
	// b 0x823ed0d4
	goto loc_823ED0D4;
loc_823ED0A0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ecc60
	ctx.lr = 0x823ED0AC;
	sub_823ECC60(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x823ed0c0
	if (cr6.lt) goto loc_823ED0C0;
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// b 0x823ed0d4
	goto loc_823ED0D4;
loc_823ED0C0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ED0D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823ED0D4:
	// lwz r3,156(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ed0f0
	if (cr6.eq) goto loc_823ED0F0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ED0F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823ED0F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823ED0FC"))) PPC_WEAK_FUNC(sub_823ED0FC);
PPC_FUNC_IMPL(__imp__sub_823ED0FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ED100"))) PPC_WEAK_FUNC(sub_823ED100);
PPC_FUNC_IMPL(__imp__sub_823ED100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,32746
	r11.s64 = 2146041856;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// ori r9,r11,6144
	ctx.r9.u64 = r11.u64 | 6144;
	// lwbrx r11,0,r9
	r11.u64 = __builtin_bswap32(PPC_LOAD_U32(ctx.r9.u32));
	// stw r11,-9792(r10)
	PPC_STORE_U32(ctx.r10.u32 + -9792, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED118"))) PPC_WEAK_FUNC(sub_823ED118);
PPC_FUNC_IMPL(__imp__sub_823ED118) {
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
	ctx.lr = 0x823ED120;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x823ed370
	ctx.lr = 0x823ED13C;
	sub_823ED370(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x823ed17c
	if (!cr6.eq) goto loc_823ED17C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,-22654
	ctx.r5.s64 = -1484652544;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// ori r5,r5,7
	ctx.r5.u64 = ctx.r5.u64 | 7;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823ef7b8
	ctx.lr = 0x823ED160;
	sub_823EF7B8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x823ed17c
	if (!cr6.eq) goto loc_823ED17C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_823ED17C:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r10,r11,143
	ctx.r10.s64 = r11.s64 + 143;
	// rlwinm r30,r10,0,0,24
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// subf r28,r30,r29
	r28.s64 = r29.s64 - r30.s64;
	// bl 0x8244d300
	ctx.lr = 0x823ED1A4;
	sub_8244D300(ctx, base);
	// addi r9,r26,16
	ctx.r9.s64 = r26.s64 + 16;
	// stw r31,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r31.u32);
	// add r29,r30,r26
	r29.u64 = r30.u64 + r26.u64;
	// li r11,0
	r11.s64 = 0;
	// stw r9,8(r26)
	PPC_STORE_U32(r26.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823ed1d0
	if (cr6.eq) goto loc_823ED1D0;
loc_823ED1C0:
	// dcbf r11,r29
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// blt cr6,0x823ed1c0
	if (cr6.lt) goto loc_823ED1C0;
loc_823ED1D0:
	// oris r11,r24,3
	r11.u64 = r24.u64 | 196608;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r11.u32);
	// beq cr6,0x823ed2d0
	if (cr6.eq) goto loc_823ED2D0;
	// lis r11,0
	r11.s64 = 0;
	// addi r30,r27,8
	r30.s64 = r27.s64 + 8;
	// li r28,0
	r28.s64 = 0;
	// mr r27,r31
	r27.u64 = r31.u64;
	// ori r25,r11,44100
	r25.u64 = r11.u64 | 44100;
loc_823ED1F4:
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// add r31,r28,r11
	r31.u64 = r28.u64 + r11.u64;
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// lwz r11,-8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// cmplwi cr6,r11,24000
	cr6.compare<uint32_t>(r11.u32, 24000, xer);
	// bgt cr6,0x823ed214
	if (cr6.gt) goto loc_823ED214;
	// li r11,0
	r11.s64 = 0;
	// b 0x823ed234
	goto loc_823ED234;
loc_823ED214:
	// cmplwi cr6,r11,32000
	cr6.compare<uint32_t>(r11.u32, 32000, xer);
	// bgt cr6,0x823ed224
	if (cr6.gt) goto loc_823ED224;
	// li r11,1
	r11.s64 = 1;
	// b 0x823ed234
	goto loc_823ED234;
loc_823ED224:
	// subfc r11,r11,r25
	xer.ca = r25.u32 >= r11.u32;
	r11.s64 = r25.s64 - r11.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_823ED234:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwimi r10,r11,27,3,4
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 27) & 0x18000000) | (ctx.r10.u64 & 0xFFFFFFFFE7FFFFFF);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// rlwimi r10,r9,29,2,2
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 29) & 0x20000000) | (ctx.r10.u64 & 0xFFFFFFFFDFFFFFFF);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lbz r7,1(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// rlwimi r8,r7,20,8,11
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 20) & 0xF00000) | (ctx.r8.u64 & 0xFFFFFFFFFF0FFFFF);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// bl 0x827bd5f4
	ctx.lr = 0x823ED268;
	__imp__MmGetPhysicalAddress(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lbz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// lwz r5,-4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// mullw r4,r6,r5
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// oris r10,r11,32768
	ctx.r10.u64 = r11.u64 | 2147483648;
	// rlwimi r3,r4,15,5,9
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r4.u32, 15) & 0x7C00000) | (ctx.r3.u64 & 0xFFFFFFFFF83FFFFF);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// lwz r8,-4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// mullw r7,r9,r8
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// rlwinm r11,r7,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// stw r29,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r29.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd5f4
	ctx.lr = 0x823ED2B0;
	__imp__MmGetPhysicalAddress(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lbz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rotlwi r11,r6,8
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// addi r28,r28,96
	r28.s64 = r28.s64 + 96;
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// bne 0x823ed1f4
	if (!cr0.eq) goto loc_823ED1F4;
loc_823ED2D0:
	// clrlwi r11,r24,31
	r11.u64 = r24.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ed304
	if (!cr6.eq) goto loc_823ED304;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823edcd8
	ctx.lr = 0x823ED2E4;
	sub_823EDCD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x823ed304
	if (!cr6.lt) goto loc_823ED304;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823ed318
	ctx.lr = 0x823ED2F8;
	sub_823ED318(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_823ED304:
	// stw r26,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r26.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823ED314"))) PPC_WEAK_FUNC(sub_823ED314);
PPC_FUNC_IMPL(__imp__sub_823ED314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ED318"))) PPC_WEAK_FUNC(sub_823ED318);
PPC_FUNC_IMPL(__imp__sub_823ED318) {
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
	// bl 0x823ed3c8
	ctx.lr = 0x823ED330;
	sub_823ED3C8(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ed358
	if (!cr6.eq) goto loc_823ED358;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,-22654
	ctx.r5.s64 = -1484652544;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// ori r5,r5,7
	ctx.r5.u64 = ctx.r5.u64 | 7;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823ED358;
	sub_823EF7C8(ctx, base);
loc_823ED358:
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

__attribute__((alias("__imp__sub_823ED370"))) PPC_WEAK_FUNC(sub_823ED370);
PPC_FUNC_IMPL(__imp__sub_823ED370) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r8,r11,143
	ctx.r8.s64 = r11.s64 + 143;
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// beq cr6,0x823ed3bc
	if (cr6.eq) goto loc_823ED3BC;
	// addi r11,r4,8
	r11.s64 = ctx.r4.s64 + 8;
loc_823ED398:
	// lwz r8,-4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// addi r5,r8,128
	ctx.r5.s64 = ctx.r8.s64 + 128;
	// mullw r4,r5,r6
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bne 0x823ed398
	if (!cr0.eq) goto loc_823ED398;
loc_823ED3BC:
	// add r3,r9,r7
	ctx.r3.u64 = ctx.r9.u64 + ctx.r7.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED3C4"))) PPC_WEAK_FUNC(sub_823ED3C4);
PPC_FUNC_IMPL(__imp__sub_823ED3C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ED3C8"))) PPC_WEAK_FUNC(sub_823ED3C8);
PPC_FUNC_IMPL(__imp__sub_823ED3C8) {
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
	ctx.lr = 0x823ED3D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x823ed428
	if (!cr6.gt) goto loc_823ED428;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_823ED3F0:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r3,64(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ed414
	if (cr6.eq) goto loc_823ED414;
	// bl 0x827bd604
	ctx.lr = 0x823ED408;
	__imp__XMAReleaseContext(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// stw r28,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r28.u32);
loc_823ED414:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,96
	r31.s64 = r31.s64 + 96;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x823ed3f0
	if (cr6.lt) goto loc_823ED3F0;
loc_823ED428:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,0,14,12
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFBFFFF;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823ED440"))) PPC_WEAK_FUNC(sub_823ED440);
PPC_FUNC_IMPL(__imp__sub_823ED440) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r3,r11,14,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 14) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED44C"))) PPC_WEAK_FUNC(sub_823ED44C);
PPC_FUNC_IMPL(__imp__sub_823ED44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ED450"))) PPC_WEAK_FUNC(sub_823ED450);
PPC_FUNC_IMPL(__imp__sub_823ED450) {
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
	ctx.lr = 0x823ED458;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r30,r6,21,11,31
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 21) & 0x1FFFFF;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r28,r10,12,30,31
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3;
	// clrlwi r9,r28,31
	ctx.r9.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823ed4b0
	if (!cr6.eq) goto loc_823ED4B0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd5f4
	ctx.lr = 0x823ED494;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// rlwimi r30,r11,0,0,19
	r30.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFFF000) | (r30.u64 & 0xFFFFFFFF00000FFF);
	// oris r10,r30,16
	ctx.r10.u64 = r30.u64 | 1048576;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// b 0x823ed4e4
	goto loc_823ED4E4;
loc_823ED4B0:
	// rlwinm r11,r28,0,30,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ed514
	if (!cr6.eq) goto loc_823ED514;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd5f4
	ctx.lr = 0x823ED4C4;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwimi r30,r11,0,0,19
	r30.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFFF000) | (r30.u64 & 0xFFFFFFFF00000FFF);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// oris r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 2097152;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r29,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r29.u32);
loc_823ED4E4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823ed508
	if (!cr6.eq) goto loc_823ED508;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x823edcb8
	ctx.lr = 0x823ED4F4;
	sub_823EDCB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ed508
	if (cr6.eq) goto loc_823ED508;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwimi r3,r11,0,0,5
	ctx.r3.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFC000000) | (ctx.r3.u64 & 0xFFFFFFFF03FFFFFF);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
loc_823ED508:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823ED514:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,5
	ctx.r3.u64 = ctx.r3.u64 | 5;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823ED524"))) PPC_WEAK_FUNC(sub_823ED524);
PPC_FUNC_IMPL(__imp__sub_823ED524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ED528"))) PPC_WEAK_FUNC(sub_823ED528);
PPC_FUNC_IMPL(__imp__sub_823ED528) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r8,r4,r11
	ctx.r8.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r7,r9,0,14,14
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20000;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x823ed558
	if (cr6.eq) goto loc_823ED558;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r10,r10,12,30,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3;
	// b 0x823ed564
	goto loc_823ED564;
loc_823ED558:
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r10,r9,12,30,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0x3;
loc_823ED564:
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ed584
	if (cr6.eq) goto loc_823ED584;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// bne cr6,0x823ed584
	if (!cr6.eq) goto loc_823ED584;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_823ED584:
	// rlwinm r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ed5a0
	if (cr6.eq) goto loc_823ED5A0;
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823ED5A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED5A8"))) PPC_WEAK_FUNC(sub_823ED5A8);
PPC_FUNC_IMPL(__imp__sub_823ED5A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// beq cr6,0x823ed5e4
	if (cr6.eq) goto loc_823ED5E4;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r8,r9,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// rlwinm r6,r7,0,10,11
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x300000;
	// addis r5,r6,-48
	ctx.r5.s64 = ctx.r6.s64 + -3145728;
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 ^ 1;
	// blr 
	return;
loc_823ED5E4:
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r7,r8,0,10,11
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x300000;
	// addis r6,r7,-48
	ctx.r6.s64 = ctx.r7.s64 + -3145728;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED610"))) PPC_WEAK_FUNC(sub_823ED610);
PPC_FUNC_IMPL(__imp__sub_823ED610) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// beq cr6,0x823ed648
	if (cr6.eq) goto loc_823ED648;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r8,r9,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// rlwinm r11,r7,12,30,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 12) & 0x3;
	// addi r11,r11,0
	r11.s64 = r11.s64 + 0;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
loc_823ED648:
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r11,r8,12,30,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0x3;
	// addi r11,r11,0
	r11.s64 = r11.s64 + 0;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED670"))) PPC_WEAK_FUNC(sub_823ED670);
PPC_FUNC_IMPL(__imp__sub_823ED670) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// bne cr6,0x823ed69c
	if (!cr6.eq) goto loc_823ED69C;
	// lwz r11,64(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
loc_823ED69C:
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r7,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ed6dc
	if (cr6.eq) goto loc_823ED6DC;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// rlwinm r10,r8,5,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0x1F;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x823ed6cc
	if (cr6.lt) goto loc_823ED6CC;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// b 0x823ed6e4
	goto loc_823ED6E4;
loc_823ED6CC:
	// rlwinm r8,r8,10,27,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 10) & 0x1F;
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x823ed6e4
	goto loc_823ED6E4;
loc_823ED6DC:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r11,r11,10,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1F;
loc_823ED6E4:
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lhz r9,82(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 82);
	// rlwinm r11,r7,3,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0x1;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srw r3,r8,r7
	ctx.r3.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r7.u8 & 0x3F));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED700"))) PPC_WEAK_FUNC(sub_823ED700);
PPC_FUNC_IMPL(__imp__sub_823ED700) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + r11.u64;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r31,r10,5,0,26
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// rlwinm r8,r9,8,19,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0x1F00;
	// lhz r9,82(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r7,3,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0x1;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// slw r10,r5,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// beq cr6,0x823ed7d0
	if (cr6.eq) goto loc_823ED7D0;
	// subfic r8,r9,256
	xer.ca = ctx.r9.u32 <= 256;
	ctx.r8.s64 = 256 - ctx.r9.s64;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bge cr6,0x823ed778
	if (!cr6.lt) goto loc_823ED778;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// add r8,r31,r8
	ctx.r8.u64 = r31.u64 + ctx.r8.u64;
	// sth r9,82(r8)
	PPC_STORE_U16(ctx.r8.u32 + 82, ctx.r9.u16);
	// b 0x823ed7cc
	goto loc_823ED7CC;
loc_823ED778:
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// add r6,r31,r9
	ctx.r6.u64 = r31.u64 + ctx.r9.u64;
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r7,82(r6)
	PPC_STORE_U16(ctx.r6.u32 + 82, ctx.r7.u16);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// clrlwi r9,r8,27
	ctx.r9.u64 = ctx.r8.u32 & 0x1F;
	// rlwinm r7,r5,10,27,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 10) & 0x1F;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// blt cr6,0x823ed7b0
	if (cr6.lt) goto loc_823ED7B0;
	// li r9,0
	ctx.r9.s64 = 0;
loc_823ED7B0:
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwimi r8,r9,0,27,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x1F) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFE0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// oris r6,r7,32768
	ctx.r6.u64 = ctx.r7.u64 | 2147483648;
	// stw r8,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r8.u32);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// bne cr6,0x823ed7d0
	if (!cr6.eq) goto loc_823ED7D0;
loc_823ED7CC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823ED7D0:
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// rlwinm r8,r10,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFFFFFF;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r30,r10,24
	r30.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r10,r5,27
	ctx.r10.u64 = ctx.r5.u32 & 0x1F;
	// rlwinm r7,r6,5,27,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0x1F;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// ble cr6,0x823ed7fc
	if (!cr6.gt) goto loc_823ED7FC;
	// subf r9,r10,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r10.s64;
	// b 0x823ed818
	goto loc_823ED818;
loc_823ED7FC:
	// blt cr6,0x823ed810
	if (cr6.lt) goto loc_823ED810;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r7,r7,0,0,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x823ed818
	if (!cr6.eq) goto loc_823ED818;
loc_823ED810:
	// rlwinm r9,r6,10,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x1F;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
loc_823ED818:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823ed860
	if (cr6.eq) goto loc_823ED860;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// blt cr6,0x823ed82c
	if (cr6.lt) goto loc_823ED82C;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_823ED82C:
	// rlwinm r7,r8,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r6,r6,10,27,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x1F;
	// add r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 + ctx.r4.u64;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// blt cr6,0x823ed84c
	if (cr6.lt) goto loc_823ED84C;
	// li r10,0
	ctx.r10.s64 = 0;
loc_823ED84C:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwimi r5,r10,0,27,31
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x1F) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFE0);
	// oris r7,r8,32768
	ctx.r7.u64 = ctx.r8.u64 | 2147483648;
	// stw r5,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r5.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
loc_823ED860:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823ed880
	if (cr6.eq) goto loc_823ED880;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ed880
	if (cr6.eq) goto loc_823ED880;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r4,r30,r4
	ctx.r4.u64 = r30.u64 + ctx.r4.u64;
	// add r8,r31,r10
	ctx.r8.u64 = r31.u64 + ctx.r10.u64;
	// sth r30,82(r8)
	PPC_STORE_U16(ctx.r8.u32 + 82, r30.u16);
loc_823ED880:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r11,r31,r10
	r11.u64 = r31.u64 + ctx.r10.u64;
	// rlwinm r9,r9,3,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0x1;
	// addi r10,r11,76
	ctx.r10.s64 = r11.s64 + 76;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// srw r3,r4,r8
	ctx.r3.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r8.u8 & 0x3F));
	// add r7,r10,r3
	ctx.r7.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r7,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r7.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED8B4"))) PPC_WEAK_FUNC(sub_823ED8B4);
PPC_FUNC_IMPL(__imp__sub_823ED8B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ED8B8"))) PPC_WEAK_FUNC(sub_823ED8B8);
PPC_FUNC_IMPL(__imp__sub_823ED8B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r8,68(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// rlwinm r9,r10,8,19,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0x1F00;
	// lhz r10,82(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// lwz r7,36(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r9,r6,5,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0x1F;
	// clrlwi r11,r7,27
	r11.u64 = ctx.r7.u32 & 0x1F;
	// rlwinm r6,r6,10,27,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x1F;
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// beq cr6,0x823ed91c
	if (cr6.eq) goto loc_823ED91C;
	// subfic r3,r10,256
	xer.ca = ctx.r10.u32 <= 256;
	ctx.r3.s64 = 256 - ctx.r10.s64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r7,1
	ctx.r7.s64 = 1;
loc_823ED91C:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// ble cr6,0x823ed930
	if (!cr6.gt) goto loc_823ED930;
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - r11.s64;
	// b 0x823ed944
	goto loc_823ED944;
loc_823ED930:
	// blt cr6,0x823ed940
	if (cr6.lt) goto loc_823ED940;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823ed944
	if (!cr6.eq) goto loc_823ED944;
loc_823ED940:
	// subf r10,r11,r6
	ctx.r10.s64 = ctx.r6.s64 - r11.s64;
loc_823ED944:
	// rlwinm r9,r8,3,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0x1;
	// rlwinm r11,r10,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// srw r3,r9,r10
	ctx.r3.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r10.u8 & 0x3F));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED95C"))) PPC_WEAK_FUNC(sub_823ED95C);
PPC_FUNC_IMPL(__imp__sub_823ED95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ED960"))) PPC_WEAK_FUNC(sub_823ED960);
PPC_FUNC_IMPL(__imp__sub_823ED960) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r3,1
	ctx.r3.s64 = 1;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r8,r7,3,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0x1;
	// rlwinm r9,r10,10,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0x1F;
	// subfic r6,r8,7
	xer.ca = ctx.r8.u32 <= 7;
	ctx.r6.s64 = 7 - ctx.r8.s64;
	// srw r8,r5,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r6.u8 & 0x3F));
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bge cr6,0x823ed9c4
	if (!cr6.lt) goto loc_823ED9C4;
	// rlwinm r6,r10,5,27,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0x1F;
	// subf r8,r8,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r8.s64;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// blt cr6,0x823ed9d0
	if (cr6.lt) goto loc_823ED9D0;
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// oris r9,r7,32768
	ctx.r9.u64 = ctx.r7.u64 | 2147483648;
	// rlwimi r10,r8,27,0,4
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r8.u32, 27) & 0xF8000000) | (ctx.r10.u64 & 0xFFFFFFFF07FFFFFF);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
loc_823ED9C4:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// clrlwi r8,r9,6
	ctx.r8.u64 = ctx.r9.u32 & 0x3FFFFFF;
loc_823ED9D0:
	// oris r9,r7,32768
	ctx.r9.u64 = ctx.r7.u64 | 2147483648;
	// rlwimi r10,r8,27,0,4
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r8.u32, 27) & 0xF8000000) | (ctx.r10.u64 & 0xFFFFFFFF07FFFFFF);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ED9E4"))) PPC_WEAK_FUNC(sub_823ED9E4);
PPC_FUNC_IMPL(__imp__sub_823ED9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ED9E8"))) PPC_WEAK_FUNC(sub_823ED9E8);
PPC_FUNC_IMPL(__imp__sub_823ED9E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r9,3,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0x1;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// rlwinm r9,r7,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823eda30
	if (cr6.eq) goto loc_823EDA30;
loc_823EDA1C:
	// lwz r7,72(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// dcbz r10,r7
	memset(base + ((ctx.r10.u32 + ctx.r7.u32) & ~31), 0, 32);
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x823eda1c
	if (cr6.lt) goto loc_823EDA1C;
loc_823EDA30:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// clrlwi r5,r10,1
	ctx.r5.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r7,0,5,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x7FFF000;
	// lwz r6,36(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwimi r4,r9,31,20,0
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r9.u32, 31) & 0xFFFFFFFF80000FFF) | (ctx.r4.u64 & 0x7FFFF000);
	// rlwinm r10,r10,0,12,9
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFCFFFFF;
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// rlwinm r6,r6,0,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFE0;
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// clrlwi r9,r7,6
	ctx.r9.u64 = ctx.r7.u32 & 0x3FFFFFF;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// stw r8,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r8.u32);
	// stw r8,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r8.u32);
	// stw r8,76(r11)
	PPC_STORE_U32(r11.u32 + 76, ctx.r8.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r6.u32);
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// sth r8,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r8.u16);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDA98"))) PPC_WEAK_FUNC(sub_823EDA98);
PPC_FUNC_IMPL(__imp__sub_823EDA98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x823edac8
	if (cr6.eq) goto loc_823EDAC8;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r3,r9,6,27,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0x1F;
	// blr 
	return;
loc_823EDAC8:
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r3,r8,6,27,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDAD8"))) PPC_WEAK_FUNC(sub_823EDAD8);
PPC_FUNC_IMPL(__imp__sub_823EDAD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x823edb08
	if (cr6.eq) goto loc_823EDB08;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r3,r9,6,27,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0x1F;
	// blr 
	return;
loc_823EDB08:
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// rlwinm r3,r8,6,27,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDB18"))) PPC_WEAK_FUNC(sub_823EDB18);
PPC_FUNC_IMPL(__imp__sub_823EDB18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r9,10(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 10);
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rotlwi r8,r9,12
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 12);
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r4,r7,0,20,11
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFF00FFF;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// or r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 | ctx.r4.u64;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lbz r7,8(r5)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + 8);
	// rlwimi r6,r7,12,18,19
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 12) & 0x3000) | (ctx.r6.u64 & 0xFFFFFFFFFFFFCFFF);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lbz r8,9(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 9);
	// rlwimi r4,r8,17,12,14
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 17) & 0xE0000) | (ctx.r4.u64 & 0xFFFFFFFFFFF1FFFF);
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// lwz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwimi r10,r7,0,6,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r7.u32, 0) & 0x3FFFFFF) | (ctx.r10.u64 & 0xFFFFFFFFFC000000);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r6,4(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// rlwimi r6,r9,0,0,5
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFC000000) | (ctx.r6.u64 & 0xFFFFFFFF03FFFFFF);
	// stw r6,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDB8C"))) PPC_WEAK_FUNC(sub_823EDB8C);
PPC_FUNC_IMPL(__imp__sub_823EDB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EDB90"))) PPC_WEAK_FUNC(sub_823EDB90);
PPC_FUNC_IMPL(__imp__sub_823EDB90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// beq cr6,0x823edbbc
	if (cr6.eq) goto loc_823EDBBC;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r8,r9,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// rlwinm r3,r7,20,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 20) & 0xFF;
	// blr 
	return;
loc_823EDBBC:
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r3,r8,20,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 20) & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDBD8"))) PPC_WEAK_FUNC(sub_823EDBD8);
PPC_FUNC_IMPL(__imp__sub_823EDBD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,76(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDBF4"))) PPC_WEAK_FUNC(sub_823EDBF4);
PPC_FUNC_IMPL(__imp__sub_823EDBF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EDBF8"))) PPC_WEAK_FUNC(sub_823EDBF8);
PPC_FUNC_IMPL(__imp__sub_823EDBF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r8,r4,r11
	ctx.r8.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r7,r9,0,14,14
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20000;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// bne cr6,0x823edc24
	if (!cr6.eq) goto loc_823EDC24;
	// lwz r11,64(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
loc_823EDC24:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r8,r9,0,10,11
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x300000;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823edc4c
	if (!cr6.eq) goto loc_823EDC4C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// blr 
	return;
loc_823EDC4C:
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r9,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// addi r8,r9,21
	ctx.r8.s64 = ctx.r9.s64 + 21;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// stw r6,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r6.u32);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// clrlwi r10,r4,6
	ctx.r10.u64 = ctx.r4.u32 & 0x3FFFFFF;
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// stw r8,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDC80"))) PPC_WEAK_FUNC(sub_823EDC80);
PPC_FUNC_IMPL(__imp__sub_823EDC80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwimi r5,r10,0,0,5
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFC000000) | (ctx.r5.u64 & 0xFFFFFFFF03FFFFFF);
	// rlwimi r9,r6,24,5,7
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r6.u32, 24) & 0x7000000) | (ctx.r9.u64 & 0xFFFFFFFFF8FFFFFF);
	// stw r5,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r5.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDCB4"))) PPC_WEAK_FUNC(sub_823EDCB4);
PPC_FUNC_IMPL(__imp__sub_823EDCB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EDCB8"))) PPC_WEAK_FUNC(sub_823EDCB8);
PPC_FUNC_IMPL(__imp__sub_823EDCB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,32767
	cr6.compare<uint32_t>(r11.u32, 32767, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rlwinm r11,r11,21,17,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x7FFF;
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDCD4"))) PPC_WEAK_FUNC(sub_823EDCD4);
PPC_FUNC_IMPL(__imp__sub_823EDCD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EDCD8"))) PPC_WEAK_FUNC(sub_823EDCD8);
PPC_FUNC_IMPL(__imp__sub_823EDCD8) {
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
	ctx.lr = 0x823EDCE0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x823edd88
	if (!cr6.gt) goto loc_823EDD88;
	// lis r11,8186
	r11.s64 = 536477696;
	// li r28,0
	r28.s64 = 0;
	// li r25,1
	r25.s64 = 1;
	// ori r27,r11,34464
	r27.u64 = r11.u64 | 34464;
	// lis r26,-32115
	r26.s64 = -2104688640;
loc_823EDD10:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r30,r28,r11
	r30.u64 = r28.u64 + r11.u64;
	// addi r31,r30,64
	r31.s64 = r30.s64 + 64;
	// lwz r11,64(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823edd74
	if (!cr6.eq) goto loc_823EDD74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd614
	ctx.lr = 0x823EDD30;
	__imp__XMACreateContext(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// blt cr6,0x823edd94
	if (cr6.lt) goto loc_823EDD94;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x827bd5f4
	ctx.lr = 0x823EDD44;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,-9792(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -9792);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// srawi r10,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	ctx.r10.s64 = r11.s32 >> 6;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r8,r9,27,21,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FF;
	// sth r9,80(r30)
	PPC_STORE_U16(r30.u32 + 80, ctx.r9.u16);
	// clrlwi r7,r9,27
	ctx.r7.u64 = ctx.r9.u32 & 0x1F;
	// add r6,r8,r27
	ctx.r6.u64 = ctx.r8.u64 + r27.u64;
	// slw r5,r25,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (r25.u32 << (ctx.r7.u8 & 0x3F));
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwbrx r5,0,r4
	PPC_MM_STORE_U32(ctx.r4.u32, __builtin_bswap32(ctx.r5.u32));
	// eieio 
loc_823EDD74:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r28,r28,96
	r28.s64 = r28.s64 + 96;
	// cmplw cr6,r24,r11
	cr6.compare<uint32_t>(r24.u32, r11.u32, xer);
	// blt cr6,0x823edd10
	if (cr6.lt) goto loc_823EDD10;
loc_823EDD88:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// oris r10,r11,4
	ctx.r10.u64 = r11.u64 | 262144;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
loc_823EDD94:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823EDDA0"))) PPC_WEAK_FUNC(sub_823EDDA0);
PPC_FUNC_IMPL(__imp__sub_823EDDA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r10,r11,0,14,15
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823eddc4
	if (cr6.eq) goto loc_823EDDC4;
	// oris r11,r11,1
	r11.u64 = r11.u64 | 65536;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// blr 
	return;
loc_823EDDC4:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x823ede20
	if (!cr6.gt) goto loc_823EDE20;
	// lis r8,8186
	ctx.r8.s64 = 536477696;
	// li r11,0
	r11.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// ori r7,r8,34448
	ctx.r7.u64 = ctx.r8.u64 | 34448;
loc_823EDDE4:
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// lhz r5,80(r8)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r8.u32 + 80);
	// rlwinm r4,r5,27,5,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r3,r5,27
	ctx.r3.u64 = ctx.r5.u32 & 0x1F;
	// add r8,r4,r7
	ctx.r8.u64 = ctx.r4.u64 + ctx.r7.u64;
	// slw r5,r6,r3
	ctx.r5.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r3.u8 & 0x3F));
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwbrx r5,0,r4
	PPC_MM_STORE_U32(ctx.r4.u32, __builtin_bswap32(ctx.r5.u32));
	// eieio 
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// blt cr6,0x823edde4
	if (cr6.lt) goto loc_823EDDE4;
loc_823EDE20:
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// oris r10,r11,1
	ctx.r10.u64 = r11.u64 | 65536;
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EDE34"))) PPC_WEAK_FUNC(sub_823EDE34);
PPC_FUNC_IMPL(__imp__sub_823EDE34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EDE38"))) PPC_WEAK_FUNC(sub_823EDE38);
PPC_FUNC_IMPL(__imp__sub_823EDE38) {
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
	ctx.lr = 0x823EDE40;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mftb r30
	r30.u64 = __rdtsc();
	// bl 0x823edf00
	ctx.lr = 0x823EDE50;
	sub_823EDF00(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823ede84
	if (!cr6.eq) goto loc_823EDE84;
loc_823EDE58:
	// mftb r11
	r11.u64 = __rdtsc();
	// subf r29,r30,r11
	r29.s64 = r11.s64 - r30.s64;
	// bl 0x827bd624
	ctx.lr = 0x823EDE64;
	__imp__KeQueryPerformanceFrequency(ctx, base);
	// rldicl r10,r3,61,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u64, 61) & 0x1FFFFFFFFFFFFFFF;
	// cmpld cr6,r29,r10
	cr6.compare<uint64_t>(r29.u64, ctx.r10.u64, xer);
	// bgt cr6,0x823ede90
	if (cr6.gt) goto loc_823EDE90;
	// db16cyc 
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823edf00
	ctx.lr = 0x823EDE7C;
	sub_823EDF00(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823ede58
	if (cr6.eq) goto loc_823EDE58;
loc_823EDE84:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EDE90:
	// lis r11,32746
	r11.s64 = 2146041856;
	// li r30,0
	r30.s64 = 0;
	// ori r10,r11,6148
	ctx.r10.u64 = r11.u64 | 6148;
	// stwx r30,0,r10
	PPC_MM_STORE_U32(ctx.r10.u32, r30.u32);
	// eieio 
	// lis r9,32746
	ctx.r9.s64 = 2146041856;
	// lis r8,768
	ctx.r8.s64 = 50331648;
	// ori r7,r9,6148
	ctx.r7.u64 = ctx.r9.u64 | 6148;
	// stwx r8,0,r7
	PPC_MM_STORE_U32(ctx.r7.u32, ctx.r8.u32);
	// eieio 
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823edf00
	ctx.lr = 0x823EDEC0;
	sub_823EDF00(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// ble cr6,0x823edee8
	if (!cr6.gt) goto loc_823EDEE8;
loc_823EDECC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ed9e8
	ctx.lr = 0x823EDED8;
	sub_823ED9E8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823edecc
	if (cr6.lt) goto loc_823EDECC;
loc_823EDEE8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// oris r10,r11,8
	ctx.r10.u64 = r11.u64 | 524288;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EDF00"))) PPC_WEAK_FUNC(sub_823EDF00);
PPC_FUNC_IMPL(__imp__sub_823EDF00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ee030
	if (!cr6.eq) goto loc_823EE030;
	// lis r11,32746
	r11.s64 = 2146041856;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r7,r11,6168
	ctx.r7.u64 = r11.u64 | 6168;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwbrx r6,0,r7
	ctx.r6.u64 = __builtin_bswap32(PPC_LOAD_U32(ctx.r7.u32));
	// xori r7,r6,512
	ctx.r7.u64 = ctx.r6.u64 ^ 512;
	// beq cr6,0x823edf68
	if (cr6.eq) goto loc_823EDF68;
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
loc_823EDF48:
	// lhz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// beq cr6,0x823ee040
	if (cr6.eq) goto loc_823EE040;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// blt cr6,0x823edf48
	if (cr6.lt) goto loc_823EDF48;
loc_823EDF68:
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823ee024
	if (cr6.eq) goto loc_823EE024;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
loc_823EDF80:
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// addi r7,r11,16
	ctx.r7.s64 = r11.s64 + 16;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lvx128 v63,r10,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r30,r10,12,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x1;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r5,r10,12,30,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823edfd4
	if (!cr6.eq) goto loc_823EDFD4;
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// stw r4,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r4.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r4,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r4.u32);
loc_823EDFD4:
	// rlwinm r10,r5,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823edffc
	if (!cr6.eq) goto loc_823EDFFC;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r4,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r4.u32);
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// stw r4,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r4.u32);
loc_823EDFFC:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x823ee010
	if (!cr6.eq) goto loc_823EE010;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// clrlwi r10,r11,1
	ctx.r10.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
loc_823EE010:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r8,r8,96
	ctx.r8.s64 = ctx.r8.s64 + 96;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x823edf80
	if (cr6.lt) goto loc_823EDF80;
loc_823EE024:
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// oris r10,r11,2
	ctx.r10.u64 = r11.u64 | 131072;
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
loc_823EE030:
	// li r3,1
	ctx.r3.s64 = 1;
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_823EE040:
	// li r3,0
	ctx.r3.s64 = 0;
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EE050"))) PPC_WEAK_FUNC(sub_823EE050);
PPC_FUNC_IMPL(__imp__sub_823EE050) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823ee09c
	if (cr6.eq) goto loc_823EE09C;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// rotlwi r6,r5,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
loc_823EE068:
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,68(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// rlwinm r10,r10,18,19,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 18) & 0x1F00;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ee090
	if (cr6.eq) goto loc_823EE090;
loc_823EE080:
	// dcbf r11,r9
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823ee080
	if (cr6.lt) goto loc_823EE080;
loc_823EE090:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r7,r7,96
	ctx.r7.s64 = ctx.r7.s64 + 96;
	// bne 0x823ee068
	if (!cr0.eq) goto loc_823EE068;
loc_823EE09C:
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ee0fc
	if (cr6.eq) goto loc_823EE0FC;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823ee0fc
	if (cr6.eq) goto loc_823EE0FC;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
loc_823EE0C4:
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r10,96
	ctx.r10.s64 = ctx.r10.s64 + 96;
	// lwz r5,64(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r5,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r5,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// blt cr6,0x823ee0c4
	if (cr6.lt) goto loc_823EE0C4;
loc_823EE0FC:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x823ee158
	if (!cr6.gt) goto loc_823EE158;
	// lis r9,8186
	ctx.r9.s64 = 536477696;
	// li r11,0
	r11.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// ori r7,r9,34384
	ctx.r7.u64 = ctx.r9.u64 | 34384;
loc_823EE11C:
	// lwz r9,8(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lhz r5,80(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 80);
	// rlwinm r4,r5,27,5,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r3,r5,27
	ctx.r3.u64 = ctx.r5.u32 & 0x1F;
	// add r9,r4,r7
	ctx.r9.u64 = ctx.r4.u64 + ctx.r7.u64;
	// slw r5,r6,r3
	ctx.r5.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r3.u8 & 0x3F));
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwbrx r5,0,r4
	PPC_MM_STORE_U32(ctx.r4.u32, __builtin_bswap32(ctx.r5.u32));
	// eieio 
	// lwz r3,0(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// blt cr6,0x823ee11c
	if (cr6.lt) goto loc_823EE11C;
loc_823EE158:
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,0,16,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFCFFFF;
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EE16C"))) PPC_WEAK_FUNC(sub_823EE16C);
PPC_FUNC_IMPL(__imp__sub_823EE16C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EE170"))) PPC_WEAK_FUNC(sub_823EE170);
PPC_FUNC_IMPL(__imp__sub_823EE170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// bne cr6,0x823ee180
	if (!cr6.eq) goto loc_823EE180;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823EE180:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823EE190"))) PPC_WEAK_FUNC(sub_823EE190);
PPC_FUNC_IMPL(__imp__sub_823EE190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// bne cr6,0x823ee1a0
	if (!cr6.eq) goto loc_823EE1A0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823EE1A0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823EE1B0"))) PPC_WEAK_FUNC(sub_823EE1B0);
PPC_FUNC_IMPL(__imp__sub_823EE1B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// bne cr6,0x823ee1c0
	if (!cr6.eq) goto loc_823EE1C0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823EE1C0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823EE1D0"))) PPC_WEAK_FUNC(sub_823EE1D0);
PPC_FUNC_IMPL(__imp__sub_823EE1D0) {
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
	// bne 0x823ee210
	if (!cr0.eq) goto loc_823EE210;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EE1FC;
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
loc_823EE210:
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

__attribute__((alias("__imp__sub_823EE224"))) PPC_WEAK_FUNC(sub_823EE224);
PPC_FUNC_IMPL(__imp__sub_823EE224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EE228"))) PPC_WEAK_FUNC(sub_823EE228);
PPC_FUNC_IMPL(__imp__sub_823EE228) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,127
	cr6.compare<uint32_t>(ctx.r10.u32, 127, xer);
	// bgt cr6,0x823ee250
	if (cr6.gt) goto loc_823EE250;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x823ee284
	if (!cr6.lt) goto loc_823EE284;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x823ee264
	goto loc_823EE264;
loc_823EE250:
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x823ee284
	if (!cr6.lt) goto loc_823EE284;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
loc_823EE264:
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ee284
	if (cr6.eq) goto loc_823EE284;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ee288
	if (!cr6.eq) goto loc_823EE288;
loc_823EE284:
	// li r11,0
	r11.s64 = 0;
loc_823EE288:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ee29c
	if (!cr6.eq) goto loc_823EE29C;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// blr 
	return;
loc_823EE29C:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823EE2AC"))) PPC_WEAK_FUNC(sub_823EE2AC);
PPC_FUNC_IMPL(__imp__sub_823EE2AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EE2B0"))) PPC_WEAK_FUNC(sub_823EE2B0);
PPC_FUNC_IMPL(__imp__sub_823EE2B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,127
	cr6.compare<uint32_t>(ctx.r10.u32, 127, xer);
	// bgt cr6,0x823ee2dc
	if (cr6.gt) goto loc_823EE2DC;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x823ee310
	if (!cr6.lt) goto loc_823EE310;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x823ee2f0
	goto loc_823EE2F0;
loc_823EE2DC:
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,-128
	ctx.r10.s64 = ctx.r10.s64 + -128;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x823ee310
	if (!cr6.lt) goto loc_823EE310;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
loc_823EE2F0:
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ee310
	if (cr6.eq) goto loc_823EE310;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ee314
	if (!cr6.eq) goto loc_823EE314;
loc_823EE310:
	// li r11,0
	r11.s64 = 0;
loc_823EE314:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ee328
	if (!cr6.eq) goto loc_823EE328;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// blr 
	return;
loc_823EE328:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823EE338"))) PPC_WEAK_FUNC(sub_823EE338);
PPC_FUNC_IMPL(__imp__sub_823EE338) {
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
	ctx.lr = 0x823EE340;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r25
	r26.u64 = r25.u64;
	// mr r11,r25
	r11.u64 = r25.u64;
	// lbz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ee404
	if (cr6.eq) goto loc_823EE404;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
loc_823EE368:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne cr6,0x823ee378
	if (!cr6.eq) goto loc_823EE378;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
loc_823EE378:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 + ctx.r7.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x823ee404
	if (!cr6.lt) goto loc_823EE404;
loc_823EE390:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ee3a8
	if (!cr6.eq) goto loc_823EE3A8;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ee3c8
	if (cr6.eq) goto loc_823EE3C8;
loc_823EE3A8:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x823ee390
	if (cr6.lt) goto loc_823EE390;
	// b 0x823ee404
	goto loc_823EE404;
loc_823EE3C8:
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// subf r9,r7,r11
	ctx.r9.s64 = r11.s64 - ctx.r7.s64;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// srawi r9,r9,3
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 3;
	// addi r8,r8,12
	ctx.r8.s64 = ctx.r8.s64 + 12;
	// addi r7,r9,128
	ctx.r7.s64 = ctx.r9.s64 + 128;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// lbz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplw cr6,r26,r3
	cr6.compare<uint32_t>(r26.u32, ctx.r3.u32, xer);
	// blt cr6,0x823ee368
	if (cr6.lt) goto loc_823EE368;
loc_823EE404:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// subf. r30,r26,r11
	r30.s64 = r11.s64 - r26.s64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823ee41c
	if (!cr0.eq) goto loc_823EE41C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_823EE41C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// ble cr6,0x823ee43c
	if (!cr6.gt) goto loc_823EE43C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_823EE43C:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r28,r10,-9788
	r28.s64 = ctx.r10.s64 + -9788;
	// ori r5,r5,4
	ctx.r5.u64 = ctx.r5.u64 | 4;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823ef7b8
	ctx.lr = 0x823EE458;
	sub_823EF7B8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x823ee478
	if (!cr6.eq) goto loc_823EE478;
	// lis r25,-32761
	r25.s64 = -2147024896;
	// ori r25,r25,14
	r25.u64 = r25.u64 | 14;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_823EE478:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ee4b4
	if (cr6.eq) goto loc_823EE4B4;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x823EE494;
	sub_823DA950(ctx, base);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823ee4b4
	if (cr6.eq) goto loc_823EE4B4;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// ori r5,r5,4
	ctx.r5.u64 = ctx.r5.u64 | 4;
	// bl 0x823ef7c8
	ctx.lr = 0x823EE4B0;
	sub_823EF7C8(ctx, base);
	// stw r25,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r25.u32);
loc_823EE4B4:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// beq cr6,0x823ee52c
	if (cr6.eq) goto loc_823EE52C;
	// rlwinm r10,r26,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r26,r10
	ctx.r10.u64 = r26.u64 + ctx.r10.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_823EE4DC:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// subf r9,r30,r10
	ctx.r9.s64 = ctx.r10.s64 - r30.s64;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r9,r6,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// addi r8,r8,12
	ctx.r8.s64 = ctx.r8.s64 + 12;
	// subf r5,r7,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r7.s64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// srawi r7,r5,3
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 3;
	// addi r3,r7,128
	ctx.r3.s64 = ctx.r7.s64 + 128;
	// stb r3,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r3.u8);
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r6,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r6.u32);
	// blt cr6,0x823ee4dc
	if (cr6.lt) goto loc_823EE4DC;
loc_823EE52C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823EE538"))) PPC_WEAK_FUNC(sub_823EE538);
PPC_FUNC_IMPL(__imp__sub_823EE538) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ee5a8
	if (cr6.eq) goto loc_823EE5A8;
loc_823EE54C:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbzx r11,r9,r11
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// addi r11,r11,-128
	r11.s64 = r11.s64 + -128;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x823ee598
	if (!cr6.lt) goto loc_823EE598;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ee598
	if (cr6.eq) goto loc_823EE598;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ee598
	if (cr6.eq) goto loc_823EE598;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ee598
	if (cr6.eq) goto loc_823EE598;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_823EE598:
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// blt cr6,0x823ee54c
	if (cr6.lt) goto loc_823EE54C;
loc_823EE5A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EE5B0"))) PPC_WEAK_FUNC(sub_823EE5B0);
PPC_FUNC_IMPL(__imp__sub_823EE5B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ee604
	if (cr6.eq) goto loc_823EE604;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_823EE5E4:
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x823ee5f8
	if (!cr6.gt) goto loc_823EE5F8;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_823EE5F8:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bne 0x823ee5e4
	if (!cr0.eq) goto loc_823EE5E4;
loc_823EE604:
	// rlwinm r3,r9,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EE60C"))) PPC_WEAK_FUNC(sub_823EE60C);
PPC_FUNC_IMPL(__imp__sub_823EE60C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EE610"))) PPC_WEAK_FUNC(sub_823EE610);
PPC_FUNC_IMPL(__imp__sub_823EE610) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r11,-4280
	ctx.r9.s64 = r11.s64 + -4280;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ee678
	if (cr6.eq) goto loc_823EE678;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_823EE658:
	// lbz r11,0(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x823ee66c
	if (!cr6.gt) goto loc_823EE66C;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_823EE66C:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r8,r8,12
	ctx.r8.s64 = ctx.r8.s64 + 12;
	// bne 0x823ee658
	if (!cr0.eq) goto loc_823EE658;
loc_823EE678:
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ee6a0
	if (cr6.eq) goto loc_823EE6A0;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r4,r10,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EE69C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
loc_823EE6A0:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ee708
	if (cr6.eq) goto loc_823EE708;
	// li r11,0
	r11.s64 = 0;
loc_823EE6B8:
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rotlwi r10,r7,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 3);
	// stwx r6,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r6.u32);
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r4,r7,r10
	ctx.r4.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,4(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// add r3,r8,r11
	ctx.r3.u64 = ctx.r8.u64 + r11.u64;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x823ee6b8
	if (cr6.lt) goto loc_823EE6B8;
loc_823EE708:
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

__attribute__((alias("__imp__sub_823EE724"))) PPC_WEAK_FUNC(sub_823EE724);
PPC_FUNC_IMPL(__imp__sub_823EE724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EE728"))) PPC_WEAK_FUNC(sub_823EE728);
PPC_FUNC_IMPL(__imp__sub_823EE728) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-4280
	ctx.r10.s64 = r11.s64 + -4280;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823ee770
	if (cr6.eq) goto loc_823EE770;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// ori r5,r5,4
	ctx.r5.u64 = ctx.r5.u64 | 4;
	// bl 0x823ef7c8
	ctx.lr = 0x823EE768;
	sub_823EF7C8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
loc_823EE770:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-4364
	ctx.r10.s64 = r11.s64 + -4364;
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

__attribute__((alias("__imp__sub_823EE794"))) PPC_WEAK_FUNC(sub_823EE794);
PPC_FUNC_IMPL(__imp__sub_823EE794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EE798"))) PPC_WEAK_FUNC(sub_823EE798);
PPC_FUNC_IMPL(__imp__sub_823EE798) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x823ee5b0
	ctx.lr = 0x823EE7B0;
	sub_823EE5B0(ctx, base);
	// addi r11,r3,24
	r11.s64 = ctx.r3.s64 + 24;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_823EE7D0"))) PPC_WEAK_FUNC(sub_823EE7D0);
PPC_FUNC_IMPL(__imp__sub_823EE7D0) {
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
	ctx.lr = 0x823EE7D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EE800;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ee834
	if (cr6.eq) goto loc_823EE834;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823ee610
	ctx.lr = 0x823EE814;
	sub_823EE610(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ee834
	if (cr6.eq) goto loc_823EE834;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823EE834:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EE844"))) PPC_WEAK_FUNC(sub_823EE844);
PPC_FUNC_IMPL(__imp__sub_823EE844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EE848"))) PPC_WEAK_FUNC(sub_823EE848);
PPC_FUNC_IMPL(__imp__sub_823EE848) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x823ee890
	if (!cr6.eq) goto loc_823EE890;
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823ee888
	if (cr6.eq) goto loc_823EE888;
	// li r11,0
	r11.s64 = 0;
loc_823EE868:
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// lbz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// blt cr6,0x823ee868
	if (cr6.lt) goto loc_823EE868;
loc_823EE888:
	// stb r10,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r10.u8);
	// b 0x823ee898
	goto loc_823EE898;
loc_823EE890:
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// stb r11,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, r11.u8);
loc_823EE898:
	// lis r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r9,r11,48000
	ctx.r9.u64 = r11.u64 | 48000;
	// stb r10,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r10.u8);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EE8B0"))) PPC_WEAK_FUNC(sub_823EE8B0);
PPC_FUNC_IMPL(__imp__sub_823EE8B0) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EE8D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ee900
	if (cr6.lt) goto loc_823EE900;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ee900
	if (cr6.eq) goto loc_823EE900;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EE900;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EE900:
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

__attribute__((alias("__imp__sub_823EE914"))) PPC_WEAK_FUNC(sub_823EE914);
PPC_FUNC_IMPL(__imp__sub_823EE914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EE918"))) PPC_WEAK_FUNC(sub_823EE918);
PPC_FUNC_IMPL(__imp__sub_823EE918) {
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
	ctx.lr = 0x823EE920;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EE930;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ee958
	if (cr6.eq) goto loc_823EE958;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ee96c
	if (cr6.eq) goto loc_823EE96C;
loc_823EE958:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EE960;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EE96C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r3,76(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EE98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823ee9a8
	if (cr6.lt) goto loc_823EE9A8;
	// lbz r10,61(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stb r8,0(r27)
	PPC_STORE_U8(r27.u32 + 0, ctx.r8.u8);
loc_823EE9A8:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823ee9f4
	if (cr6.eq) goto loc_823EE9F4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823ee9f4
	if (!cr6.eq) goto loc_823EE9F4;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ee9f4
	if (!cr0.eq) goto loc_823EE9F4;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EE9EC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EE9F4;
	__imp__KfLowerIrql(ctx, base);
loc_823EE9F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EEA00"))) PPC_WEAK_FUNC(sub_823EEA00);
PPC_FUNC_IMPL(__imp__sub_823EEA00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r10,268(r13)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EEA1C"))) PPC_WEAK_FUNC(sub_823EEA1C);
PPC_FUNC_IMPL(__imp__sub_823EEA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEA20"))) PPC_WEAK_FUNC(sub_823EEA20);
PPC_FUNC_IMPL(__imp__sub_823EEA20) {
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
	ctx.lr = 0x823EEA28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// lbz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// slw r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// lwz r7,140(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x823eea70
	if (cr6.eq) goto loc_823EEA70;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EEA68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eeb08
	if (cr6.lt) goto loc_823EEB08;
loc_823EEA70:
	// addi r29,r31,76
	r29.s64 = r31.s64 + 76;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f7120
	ctx.lr = 0x823EEA84;
	sub_823F7120(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eeb08
	if (cr6.lt) goto loc_823EEB08;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f67b8
	ctx.lr = 0x823EEA98;
	sub_823F67B8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eeb08
	if (cr6.lt) goto loc_823EEB08;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EEAB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823eeb04
	if (cr6.lt) goto loc_823EEB04;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823efd30
	ctx.lr = 0x823EEAD0;
	sub_823EFD30(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823eeb04
	if (!cr6.eq) goto loc_823EEB04;
	// lbz r11,61(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 61);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823eeb04
	if (!cr6.eq) goto loc_823EEB04;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f7468
	ctx.lr = 0x823EEAFC;
	sub_823F7468(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823EEB04:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823EEB08:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EEB10"))) PPC_WEAK_FUNC(sub_823EEB10);
PPC_FUNC_IMPL(__imp__sub_823EEB10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,144(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bge cr6,0x823eeb34
	if (!cr6.lt) goto loc_823EEB34;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r11,33
	ctx.r9.s64 = r11.s64 + 33;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-9796(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -9796);
	// lfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// b 0x823eeb3c
	goto loc_823EEB3C;
loc_823EEB34:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_823EEB3C:
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lfs f13,140(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,88(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823EEB5C"))) PPC_WEAK_FUNC(sub_823EEB5C);
PPC_FUNC_IMPL(__imp__sub_823EEB5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEB60"))) PPC_WEAK_FUNC(sub_823EEB60);
PPC_FUNC_IMPL(__imp__sub_823EEB60) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823EEB7C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x823eeb7c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823EEB7C;
	// bl 0x823ee848
	ctx.lr = 0x823EEB8C;
	sub_823EE848(ctx, base);
	// lwz r9,68(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lwz r9,-9796(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -9796);
	// addi r10,r9,12
	ctx.r10.s64 = ctx.r9.s64 + 12;
loc_823EEBA4:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823eec18
	if (!cr6.eq) goto loc_823EEC18;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// blt cr6,0x823eeba4
	if (cr6.lt) goto loc_823EEBA4;
	// li r11,0
	r11.s64 = 0;
loc_823EEBC4:
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
	// lwz r10,88(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// stw r10,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r10.u32);
	// lbz r11,57(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 57);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823eebe8
	if (!cr6.eq) goto loc_823EEBE8;
	// li r11,1
	r11.s64 = 1;
loc_823EEBE8:
	// stb r11,24(r4)
	PPC_STORE_U8(ctx.r4.u32 + 24, r11.u8);
	// lbz r11,58(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 58);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823eebfc
	if (!cr6.eq) goto loc_823EEBFC;
	// li r11,6
	r11.s64 = 6;
loc_823EEBFC:
	// stb r11,25(r4)
	PPC_STORE_U8(ctx.r4.u32 + 25, r11.u8);
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// stw r10,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823EEC18:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x823eebc4
	goto loc_823EEBC4;
}

__attribute__((alias("__imp__sub_823EEC28"))) PPC_WEAK_FUNC(sub_823EEC28);
PPC_FUNC_IMPL(__imp__sub_823EEC28) {
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
	ctx.lr = 0x823EEC30;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// lwz r30,60(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// bl 0x823eeb60
	ctx.lr = 0x823EEC50;
	sub_823EEB60(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823f62c8
	ctx.lr = 0x823EEC5C;
	sub_823F62C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eecf8
	if (cr6.lt) goto loc_823EECF8;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823EEC74:
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x823eec74
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823EEC74;
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// li r5,56
	ctx.r5.s64 = 56;
	// stb r10,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r10.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x823EEC9C;
	sub_823DA950(ctx, base);
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f0.f64 = double(temp.f32);
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// stfs f0,192(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r10,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, ctx.r10.u8);
	// stb r9,197(r1)
	PPC_STORE_U8(ctx.r1.u32 + 197, ctx.r9.u8);
	// stw r8,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r8.u32);
	// stw r7,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r7.u32);
	// bl 0x823ee170
	ctx.lr = 0x823EECD4;
	sub_823EE170(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// blt cr6,0x823eecfc
	if (cr6.lt) goto loc_823EECFC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
loc_823EECF8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823EECFC:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EED04"))) PPC_WEAK_FUNC(sub_823EED04);
PPC_FUNC_IMPL(__imp__sub_823EED04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EED08"))) PPC_WEAK_FUNC(sub_823EED08);
PPC_FUNC_IMPL(__imp__sub_823EED08) {
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
	ctx.lr = 0x823EED10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r10,r11,-4240
	ctx.r10.s64 = r11.s64 + -4240;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EED34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eed58
	if (cr6.lt) goto loc_823EED58;
	// lwz r3,76(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823eed58
	if (cr6.eq) goto loc_823EED58;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EED58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EED58:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r28,-9796(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// bl 0x827bd514
	ctx.lr = 0x823EED64;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eed8c
	if (cr6.eq) goto loc_823EED8C;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// beq cr6,0x823eeda4
	if (cr6.eq) goto loc_823EEDA4;
loc_823EED8C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EED94;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
loc_823EEDA4:
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r11,88(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 88);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x823eede4
	if (cr6.eq) goto loc_823EEDE4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EEDE4:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823eee28
	if (cr6.eq) goto loc_823EEE28;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823eee28
	if (!cr6.eq) goto loc_823EEE28;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823eee28
	if (!cr0.eq) goto loc_823EEE28;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EEE20;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EEE28;
	__imp__KfLowerIrql(ctx, base);
loc_823EEE28:
	// lwz r3,76(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823eee4c
	if (cr6.eq) goto loc_823EEE4C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EEE44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,76(r27)
	PPC_STORE_U32(r27.u32 + 76, ctx.r9.u32);
loc_823EEE4C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823f6650
	ctx.lr = 0x823EEE54;
	sub_823F6650(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EEE5C"))) PPC_WEAK_FUNC(sub_823EEE5C);
PPC_FUNC_IMPL(__imp__sub_823EEE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEE60"))) PPC_WEAK_FUNC(sub_823EEE60);
PPC_FUNC_IMPL(__imp__sub_823EEE60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EEE70"))) PPC_WEAK_FUNC(sub_823EEE70);
PPC_FUNC_IMPL(__imp__sub_823EEE70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,12(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EEE80"))) PPC_WEAK_FUNC(sub_823EEE80);
PPC_FUNC_IMPL(__imp__sub_823EEE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r3,52
	r11.s64 = ctx.r3.s64 + 52;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EEE9C"))) PPC_WEAK_FUNC(sub_823EEE9C);
PPC_FUNC_IMPL(__imp__sub_823EEE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEEA0"))) PPC_WEAK_FUNC(sub_823EEEA0);
PPC_FUNC_IMPL(__imp__sub_823EEEA0) {
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
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// addi r3,r30,84
	ctx.r3.s64 = r30.s64 + 84;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x823da950
	ctx.lr = 0x823EEEC8;
	sub_823DA950(ctx, base);
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,144(r30)
	PPC_STORE_U8(r30.u32 + 144, r11.u8);
	// bl 0x823eeb60
	ctx.lr = 0x823EEEDC;
	sub_823EEB60(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823f6380
	ctx.lr = 0x823EEEE8;
	sub_823F6380(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eef64
	if (cr6.lt) goto loc_823EEF64;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823EEF00:
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x823eef00
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823EEF00;
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// li r5,56
	ctx.r5.s64 = 56;
	// stb r10,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, ctx.r10.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x823EEF28;
	sub_823DA950(ctx, base);
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f0.f64 = double(temp.f32);
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// stfs f0,176(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r6,255
	ctx.r6.s64 = 255;
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r30,76
	ctx.r4.s64 = r30.s64 + 76;
	// stb r10,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r10.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r9,181(r1)
	PPC_STORE_U8(ctx.r1.u32 + 181, ctx.r9.u8);
	// stw r8,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r8.u32);
	// stw r7,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r7.u32);
	// bl 0x823f6e18
	ctx.lr = 0x823EEF64;
	sub_823F6E18(ctx, base);
loc_823EEF64:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

__attribute__((alias("__imp__sub_823EEF7C"))) PPC_WEAK_FUNC(sub_823EEF7C);
PPC_FUNC_IMPL(__imp__sub_823EEF7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEF80"))) PPC_WEAK_FUNC(sub_823EEF80);
PPC_FUNC_IMPL(__imp__sub_823EEF80) {
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
	ctx.lr = 0x823EEF88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EEF94;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eefbc
	if (cr6.eq) goto loc_823EEFBC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823eefd8
	if (cr6.eq) goto loc_823EEFD8;
loc_823EEFBC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EEFC4;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// b 0x823eefdc
	goto loc_823EEFDC;
loc_823EEFD8:
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823EEFDC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r9,61(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 61);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823ef044
	if (!cr6.eq) goto loc_823EF044;
	// mr r9,r13
	ctx.r9.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef034
	if (cr6.eq) goto loc_823EF034;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x823ef034
	if (!cr6.eq) goto loc_823EF034;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef034
	if (!cr0.eq) goto loc_823EF034;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EF02C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF034;
	__imp__KfLowerIrql(ctx, base);
loc_823EF034:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16388
	ctx.r3.u64 = ctx.r3.u64 | 16388;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823EF044:
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-9796(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -9796);
	// bl 0x823eb8e0
	ctx.lr = 0x823EF054;
	sub_823EB8E0(ctx, base);
	// lwz r28,-9796(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -9796);
	// bl 0x827bd514
	ctx.lr = 0x823EF05C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef07c
	if (cr6.eq) goto loc_823EF07C;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// beq cr6,0x823ef094
	if (cr6.eq) goto loc_823EF094;
loc_823EF07C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF084;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
loc_823EF094:
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r11,76(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x823ef0d4
	if (cr6.eq) goto loc_823EF0D4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EF0D4:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823ef118
	if (cr6.eq) goto loc_823EF118;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823ef118
	if (!cr6.eq) goto loc_823EF118;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef118
	if (!cr0.eq) goto loc_823EF118;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EF110;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF118;
	__imp__KfLowerIrql(ctx, base);
loc_823EF118:
	// bl 0x827bd514
	ctx.lr = 0x823EF11C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef13c
	if (cr6.eq) goto loc_823EF13C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ef150
	if (cr6.eq) goto loc_823EF150;
loc_823EF13C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF144;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EF150:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r11,61(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 61);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwinm r9,r9,0,26,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r9,61(r27)
	PPC_STORE_U8(r27.u32 + 61, ctx.r9.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef1b8
	if (cr6.eq) goto loc_823EF1B8;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ef1b8
	if (!cr6.eq) goto loc_823EF1B8;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef1b8
	if (!cr0.eq) goto loc_823EF1B8;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EF1AC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF1B4;
	__imp__KfLowerIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EF1B8:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef200
	if (cr6.eq) goto loc_823EF200;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ef200
	if (!cr6.eq) goto loc_823EF200;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef200
	if (!cr0.eq) goto loc_823EF200;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EF1F8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF200;
	__imp__KfLowerIrql(ctx, base);
loc_823EF200:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EF20C"))) PPC_WEAK_FUNC(sub_823EF20C);
PPC_FUNC_IMPL(__imp__sub_823EF20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EF210"))) PPC_WEAK_FUNC(sub_823EF210);
PPC_FUNC_IMPL(__imp__sub_823EF210) {
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
	ctx.lr = 0x823EF218;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x823f6238
	ctx.lr = 0x823EF224;
	sub_823F6238(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r8,r10,-4240
	ctx.r8.s64 = ctx.r10.s64 + -4240;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// stfs f0,140(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 140, temp.u32);
	// lwz r11,-9796(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -9796);
	// addi r30,r11,80
	r30.s64 = r11.s64 + 80;
	// bl 0x827bd514
	ctx.lr = 0x823EF24C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r28,r13
	r28.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef274
	if (cr6.eq) goto loc_823EF274;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ef288
	if (cr6.eq) goto loc_823EF288;
loc_823EF274:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF27C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// stb r27,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r27.u8);
loc_823EF288:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef2fc
	if (cr6.eq) goto loc_823EF2FC;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ef2fc
	if (!cr6.eq) goto loc_823EF2FC;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef2fc
	if (!cr0.eq) goto loc_823EF2FC;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EF2F4;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF2FC;
	__imp__KfLowerIrql(ctx, base);
loc_823EF2FC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

