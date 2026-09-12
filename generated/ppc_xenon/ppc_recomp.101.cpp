#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_824FF810"))) PPC_WEAK_FUNC(sub_824FF810);
PPC_FUNC_IMPL(__imp__sub_824FF810) {
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
	// lbz r11,116(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 116);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ff850
	if (cr6.eq) goto loc_824FF850;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FF844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,116(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 116);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stb r8,116(r31)
	PPC_STORE_U8(r31.u32 + 116, ctx.r8.u8);
loc_824FF850:
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// bl 0x82130000
	ctx.lr = 0x824FF858;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6b58
	ctx.lr = 0x824FF860;
	sub_824E6B58(ctx, base);
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

__attribute__((alias("__imp__sub_824FF874"))) PPC_WEAK_FUNC(sub_824FF874);
PPC_FUNC_IMPL(__imp__sub_824FF874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FF878"))) PPC_WEAK_FUNC(sub_824FF878);
PPC_FUNC_IMPL(__imp__sub_824FF878) {
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
	ctx.lr = 0x824FF880;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// stw r24,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r24.u32);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// mr r31,r9
	r31.u64 = ctx.r9.u64;
	// mr r28,r24
	r28.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ff8e0
	if (!cr6.eq) goto loc_824FF8E0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x821f8730
	ctx.lr = 0x824FF8BC;
	sub_821F8730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ff398
	ctx.lr = 0x824FF8DC;
	sub_824FF398(ctx, base);
	// li r28,1
	r28.s64 = 1;
loc_824FF8E0:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ff91c
	if (!cr6.eq) goto loc_824FF91C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ff91c
	if (cr6.eq) goto loc_824FF91C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce080
	ctx.lr = 0x824FF900;
	sub_821CE080(ctx, base);
	// stw r24,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r24.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FF914;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_824FF91C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824FF928"))) PPC_WEAK_FUNC(sub_824FF928);
PPC_FUNC_IMPL(__imp__sub_824FF928) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,216
	ctx.r3.s64 = r31.s64 + 216;
	// stw r30,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r30.u32);
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
	// bl 0x824e6928
	ctx.lr = 0x824FF954;
	sub_824E6928(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r30,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r30.u32);
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// addi r10,r11,30200
	ctx.r10.s64 = r11.s64 + 30200;
	// stw r10,216(r31)
	PPC_STORE_U32(r31.u32 + 216, ctx.r10.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824FF96C;
	sub_821C8ED8(ctx, base);
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
	// stw r30,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r30.u32);
	// lbz r9,316(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 316);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stb r8,316(r31)
	PPC_STORE_U8(r31.u32 + 316, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_824FF9A0"))) PPC_WEAK_FUNC(sub_824FF9A0);
PPC_FUNC_IMPL(__imp__sub_824FF9A0) {
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
	ctx.lr = 0x824FF9A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lbz r11,316(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 316);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ffa0c
	if (!cr6.eq) goto loc_824FFA0C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,216
	r30.s64 = r31.s64 + 216;
	// addi r4,r11,30216
	ctx.r4.s64 = r11.s64 + 30216;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b98
	ctx.lr = 0x824FF9E0;
	sub_824E6B98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ffa0c
	if (cr6.eq) goto loc_824FFA0C;
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r11,316(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 316);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stw r29,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r29.u32);
	// stb r10,316(r31)
	PPC_STORE_U8(r31.u32 + 316, ctx.r10.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824FFA0C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FFA18"))) PPC_WEAK_FUNC(sub_824FFA18);
PPC_FUNC_IMPL(__imp__sub_824FFA18) {
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
	// lbz r11,316(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 316);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ffa64
	if (cr6.eq) goto loc_824FFA64;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r3,r31,216
	ctx.r3.s64 = r31.s64 + 216;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FFA50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,316(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 316);
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r7,r8,25
	ctx.r7.u64 = ctx.r8.u32 & 0x7F;
	// stw r9,304(r31)
	PPC_STORE_U32(r31.u32 + 304, ctx.r9.u32);
	// stb r7,316(r31)
	PPC_STORE_U8(r31.u32 + 316, ctx.r7.u8);
loc_824FFA64:
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

__attribute__((alias("__imp__sub_824FFA78"))) PPC_WEAK_FUNC(sub_824FFA78);
PPC_FUNC_IMPL(__imp__sub_824FFA78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,304(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 304);
	// addi r9,r11,0
	ctx.r9.s64 = r11.s64 + 0;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r3,r7,1
	ctx.r3.u64 = ctx.r7.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FFA90"))) PPC_WEAK_FUNC(sub_824FFA90);
PPC_FUNC_IMPL(__imp__sub_824FFA90) {
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
	ctx.lr = 0x824FFA98;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r29,212(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824FFAB8:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824ffab8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824FFAB8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824FFAD8;
	sub_8244EE40(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ffb3c
	if (cr6.eq) goto loc_824FFB3C;
	// lwz r11,96(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x821f8730
	ctx.lr = 0x824FFAF8;
	sub_821F8730(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82457450
	ctx.lr = 0x824FFB0C;
	sub_82457450(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824ffb20
	if (!cr6.eq) goto loc_824FFB20;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82135db8
	ctx.lr = 0x824FFB20;
	sub_82135DB8(ctx, base);
loc_824FFB20:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82450030
	ctx.lr = 0x824FFB28;
	sub_82450030(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824ffb34
	if (!cr6.eq) goto loc_824FFB34;
	// li r30,1
	r30.s64 = 1;
loc_824FFB34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824FFB3C;
	sub_8244EEE0(ctx, base);
loc_824FFB3C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FFB48"))) PPC_WEAK_FUNC(sub_824FFB48);
PPC_FUNC_IMPL(__imp__sub_824FFB48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// li r9,31
	ctx.r9.s64 = 31;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// subf r6,r11,r6
	ctx.r6.s64 = ctx.r6.s64 - r11.s64;
loc_824FFB64:
	// lbzx r9,r6,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ffb7c
	if (cr6.eq) goto loc_824FFB7C;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824ffb64
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824FFB64;
loc_824FFB7C:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,99
	ctx.r7.s64 = 99;
	// stb r6,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r6.u8);
	// addi r11,r3,40
	r11.s64 = ctx.r3.s64 + 40;
loc_824FFB8C:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ffc04
	if (cr6.eq) goto loc_824FFC04;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ffbe8
	if (cr6.eq) goto loc_824FFBE8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ffc00
	if (cr6.eq) goto loc_824FFC00;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r7,r7,-3
	xer.ca = ctx.r7.u32 > 2;
	ctx.r7.s64 = ctx.r7.s64 + -3;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x824ffb8c
	if (cr0.gt) goto loc_824FFB8C;
	// stb r6,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r6.u8);
	// lbz r11,140(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 140);
	// rlwimi r11,r8,7,17,24
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 7) & 0x7F80) | (r11.u64 & 0xFFFFFFFFFFFF807F);
	// stb r11,140(r3)
	PPC_STORE_U8(ctx.r3.u32 + 140, r11.u8);
	// blr 
	return;
loc_824FFBE8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r6,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r6.u8);
	// lbz r11,140(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 140);
	// rlwimi r11,r8,7,17,24
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 7) & 0x7F80) | (r11.u64 & 0xFFFFFFFFFFFF807F);
	// stb r11,140(r3)
	PPC_STORE_U8(ctx.r3.u32 + 140, r11.u8);
	// blr 
	return;
loc_824FFC00:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_824FFC04:
	// stb r6,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r6.u8);
	// lbz r11,140(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 140);
	// rlwimi r11,r8,7,17,24
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 7) & 0x7F80) | (r11.u64 & 0xFFFFFFFFFFFF807F);
	// stb r11,140(r3)
	PPC_STORE_U8(ctx.r3.u32 + 140, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FFC18"))) PPC_WEAK_FUNC(sub_824FFC18);
PPC_FUNC_IMPL(__imp__sub_824FFC18) {
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
	// lbz r11,316(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 316);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ffc64
	if (cr6.eq) goto loc_824FFC64;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r3,r31,216
	ctx.r3.s64 = r31.s64 + 216;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FFC50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,316(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 316);
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r7,r8,25
	ctx.r7.u64 = ctx.r8.u32 & 0x7F;
	// stw r9,304(r31)
	PPC_STORE_U32(r31.u32 + 304, ctx.r9.u32);
	// stb r7,316(r31)
	PPC_STORE_U8(r31.u32 + 316, ctx.r7.u8);
loc_824FFC64:
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// bl 0x82130000
	ctx.lr = 0x824FFC6C;
	sub_82130000(ctx, base);
	// addi r3,r31,216
	ctx.r3.s64 = r31.s64 + 216;
	// bl 0x824e6b58
	ctx.lr = 0x824FFC74;
	sub_824E6B58(ctx, base);
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

__attribute__((alias("__imp__sub_824FFC88"))) PPC_WEAK_FUNC(sub_824FFC88);
PPC_FUNC_IMPL(__imp__sub_824FFC88) {
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
	ctx.lr = 0x824FFC90;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,272
	ctx.r4.s64 = r31.s64 + 272;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824FFCB0;
	sub_821C8FE0(ctx, base);
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ffd24
	if (!cr6.eq) goto loc_824FFD24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824FFCC8;
	sub_824E71C8(ctx, base);
	// stw r31,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r31.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x824FFCDC;
	sub_823DA950(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r28,96(r11)
	PPC_STORE_U32(r11.u32 + 96, r28.u32);
	// bne cr6,0x824ffcf0
	if (!cr6.eq) goto loc_824FFCF0;
	// addi r30,r31,308
	r30.s64 = r31.s64 + 308;
loc_824FFCF0:
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824FFD00;
	sub_821CE080(ctx, base);
	// stw r27,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r27.u32);
	// addi r3,r31,216
	ctx.r3.s64 = r31.s64 + 216;
	// bl 0x824e6a10
	ctx.lr = 0x824FFD0C;
	sub_824E6A10(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r27,1
	r27.s64 = 1;
	// bl 0x821c9030
	ctx.lr = 0x824FFD18;
	sub_821C9030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824FFD24:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ffd54
	if (cr6.eq) goto loc_824FFD54;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824FFD38;
	sub_821CE080(ctx, base);
	// stw r27,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r27.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FFD4C;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_824FFD54:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824FFD5C;
	sub_821C9030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FFD68"))) PPC_WEAK_FUNC(sub_824FFD68);
PPC_FUNC_IMPL(__imp__sub_824FFD68) {
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
	ctx.lr = 0x824FFD70;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// lwz r27,208(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r31,r27,96
	r31.s64 = r27.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82502300
	ctx.lr = 0x824FFD8C;
	sub_82502300(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82502300
	ctx.lr = 0x824FFD98;
	sub_82502300(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824f0550
	ctx.lr = 0x824FFDA0;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ffdb4
	if (cr6.eq) goto loc_824FFDB4;
	// mr r31,r30
	r31.u64 = r30.u64;
	// b 0x824ffdc4
	goto loc_824FFDC4;
loc_824FFDB4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7110
	ctx.lr = 0x824FFDBC;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x824FFDC0;
	sub_824F92F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_824FFDC4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r29,196(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// addi r28,r1,88
	r28.s64 = ctx.r1.s64 + 88;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// bl 0x821f8730
	ctx.lr = 0x824FFDD8;
	sub_821F8730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// bl 0x82457958
	ctx.lr = 0x824FFDFC;
	sub_82457958(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824fffc4
	if (!cr6.eq) goto loc_824FFFC4;
	// lis r24,-32115
	r24.s64 = -2104688640;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FFE28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824fffc4
	if (cr6.eq) goto loc_824FFFC4;
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824FFE48:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824ffe48
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824FFE48;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824FFE68;
	sub_8244EE40(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r25.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824fffac
	if (cr6.eq) goto loc_824FFFAC;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x824501c8
	ctx.lr = 0x824FFE90;
	sub_824501C8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821326a8
	ctx.lr = 0x824FFEA0;
	sub_821326A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824fffa4
	if (!cr6.eq) goto loc_824FFFA4;
	// lwz r11,200(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 200);
	// mr r28,r30
	r28.u64 = r30.u64;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fffa0
	if (cr6.eq) goto loc_824FFFA0;
	// mr r29,r30
	r29.u64 = r30.u64;
	// mr r31,r26
	r31.u64 = r26.u64;
loc_824FFECC:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// li r11,31
	r11.s64 = 31;
loc_824FFED8:
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ffef8
	if (cr6.eq) goto loc_824FFEF8;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bgt 0x824ffed8
	if (cr0.gt) goto loc_824FFED8;
loc_824FFEF8:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stb r30,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r30.u8);
	// li r7,99
	ctx.r7.s64 = 99;
loc_824FFF08:
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824fff60
	if (cr6.eq) goto loc_824FFF60;
	// addi r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 2;
	// lhz r9,2(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fff54
	if (cr6.eq) goto loc_824FFF54;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fff5c
	if (cr6.eq) goto loc_824FFF5C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r7,r7,-3
	xer.ca = ctx.r7.u32 > 2;
	ctx.r7.s64 = ctx.r7.s64 + -3;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x824fff08
	if (cr0.gt) goto loc_824FFF08;
	// b 0x824fff60
	goto loc_824FFF60;
loc_824FFF54:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x824fff60
	goto loc_824FFF60;
loc_824FFF5C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_824FFF60:
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lwz r10,192(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 192);
	// rlwinm r8,r11,15,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r3,r10,r29
	ctx.r3.u64 = ctx.r10.u64 + r29.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824ffb48
	ctx.lr = 0x824FFF88;
	sub_824FFB48(ctx, base);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,36
	r31.s64 = r31.s64 + 36;
	// addi r29,r29,144
	r29.s64 = r29.s64 + 144;
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// blt cr6,0x824ffecc
	if (cr6.lt) goto loc_824FFECC;
loc_824FFFA0:
	// li r30,1
	r30.s64 = 1;
loc_824FFFA4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824FFFAC;
	sub_8244EEE0(ctx, base);
loc_824FFFAC:
	// lwz r3,32268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 32268);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FFFC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824FFFC4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824FFFD0"))) PPC_WEAK_FUNC(sub_824FFFD0);
PPC_FUNC_IMPL(__imp__sub_824FFFD0) {
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
	ctx.lr = 0x824FFFD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r30,r29
	r30.u64 = r29.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82500000
	if (cr6.eq) goto loc_82500000;
	// bl 0x824ffd68
	ctx.lr = 0x824FFFFC;
	sub_824FFD68(ctx, base);
	// b 0x82500010
	goto loc_82500010;
loc_82500000:
	// lwz r11,212(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82500014
	if (cr6.eq) goto loc_82500014;
	// bl 0x824ffa90
	ctx.lr = 0x82500010;
	sub_824FFA90(ctx, base);
loc_82500010:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82500014:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,272
	ctx.r4.s64 = r11.s64 + 272;
	// bl 0x821c8fe0
	ctx.lr = 0x82500024;
	sub_821C8FE0(ctx, base);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r29,208(r10)
	PPC_STORE_U32(ctx.r10.u32 + 208, r29.u32);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stw r29,212(r9)
	PPC_STORE_U32(ctx.r9.u32 + 212, r29.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r30,304(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 304);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x82500060
	if (cr6.eq) goto loc_82500060;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x82500058;
	sub_821CE0A0(ctx, base);
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
	// b 0x82500070
	goto loc_82500070;
loc_82500060:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x82500068;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
loc_82500070:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r29,304(r11)
	PPC_STORE_U32(r11.u32 + 304, r29.u32);
	// bl 0x821c9030
	ctx.lr = 0x82500080;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82500088"))) PPC_WEAK_FUNC(sub_82500088);
PPC_FUNC_IMPL(__imp__sub_82500088) {
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
	// lwz r30,116(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825000d0
	if (cr6.eq) goto loc_825000D0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x825000d0
	if (!cr6.eq) goto loc_825000D0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x825000C8;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_825000D0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
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

__attribute__((alias("__imp__sub_825000FC"))) PPC_WEAK_FUNC(sub_825000FC);
PPC_FUNC_IMPL(__imp__sub_825000FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500100"))) PPC_WEAK_FUNC(sub_82500100);
PPC_FUNC_IMPL(__imp__sub_82500100) {
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
	// bl 0x824e6990
	ctx.lr = 0x82500118;
	sub_824E6990(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
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

__attribute__((alias("__imp__sub_82500134"))) PPC_WEAK_FUNC(sub_82500134);
PPC_FUNC_IMPL(__imp__sub_82500134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500138"))) PPC_WEAK_FUNC(sub_82500138);
PPC_FUNC_IMPL(__imp__sub_82500138) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82500200
	if (cr6.eq) goto loc_82500200;
loc_8250014C:
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// bge cr6,0x82500200
	if (!cr6.lt) goto loc_82500200;
	// lbzx r10,r7,r4
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r4.u32);
	// add r9,r7,r4
	ctx.r9.u64 = ctx.r7.u64 + ctx.r4.u64;
	// rlwinm r6,r10,0,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8250017c
	if (!cr6.eq) goto loc_8250017C;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r9,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r9.u16);
	// b 0x825001ec
	goto loc_825001EC;
loc_8250017C:
	// rlwinm r6,r8,0,24,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r6,192
	cr6.compare<uint32_t>(ctx.r6.u32, 192, xer);
	// bne cr6,0x825001a8
	if (!cr6.eq) goto loc_825001A8;
	// rlwinm r8,r10,6,21,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0x7C0;
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r8,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r8.u16);
	// lbz r6,1(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// clrlwi r9,r6,26
	ctx.r9.u64 = ctx.r6.u32 & 0x3F;
	// or r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 | ctx.r8.u64;
	// sth r8,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r8.u16);
	// b 0x825001ec
	goto loc_825001EC;
loc_825001A8:
	// rlwinm r8,r8,0,24,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xF0;
	// cmplwi cr6,r8,224
	cr6.compare<uint32_t>(ctx.r8.u32, 224, xer);
	// bne cr6,0x825001e8
	if (!cr6.eq) goto loc_825001E8;
	// rlwinm r8,r10,12,16,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xF000;
	// li r10,3
	ctx.r10.s64 = 3;
	// sth r8,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r8.u16);
	// lbz r6,1(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// rlwinm r6,r6,6,18,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0x3000;
	// or r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 | ctx.r8.u64;
	// clrlwi r6,r8,16
	ctx.r6.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r6,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r6.u16);
	// lbz r9,2(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// rlwinm r8,r9,0,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFC0;
	// or r6,r8,r6
	ctx.r6.u64 = ctx.r8.u64 | ctx.r6.u64;
	// sth r6,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r6.u16);
	// b 0x825001ec
	goto loc_825001EC;
loc_825001E8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_825001EC:
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// lbzx r10,r7,r4
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r4.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8250014c
	if (!cr6.eq) goto loc_8250014C;
loc_82500200:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8250020C"))) PPC_WEAK_FUNC(sub_8250020C);
PPC_FUNC_IMPL(__imp__sub_8250020C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500210"))) PPC_WEAK_FUNC(sub_82500210);
PPC_FUNC_IMPL(__imp__sub_82500210) {
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
	ctx.lr = 0x82500218;
	// stwu r1,-960(r1)
	ea = -960 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,52(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// li r29,0
	r29.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8250022C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82500350
	if (cr6.eq) goto loc_82500350;
	// li r11,510
	r11.s64 = 510;
	// li r5,128
	ctx.r5.s64 = 128;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82500138
	ctx.lr = 0x82500250;
	sub_82500138(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82500350
	if (cr6.eq) goto loc_82500350;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r28,r1,384
	r28.s64 = ctx.r1.s64 + 384;
	// addi r27,r1,128
	r27.s64 = ctx.r1.s64 + 128;
	// bl 0x821f8730
	ctx.lr = 0x8250026C;
	sub_821F8730(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// bl 0x8274c0e8
	ctx.lr = 0x82500288;
	sub_8274C0E8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82500350
	if (!cr6.eq) goto loc_82500350;
	// li r3,587
	ctx.r3.s64 = 587;
	// bl 0x82130528
	ctx.lr = 0x82500298;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82500350
	if (cr6.eq) goto loc_82500350;
	// li r5,587
	ctx.r5.s64 = 587;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x825002B0;
	sub_823D9890(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r1,384
	r28.s64 = ctx.r1.s64 + 384;
	// bl 0x821f8730
	ctx.lr = 0x825002BC;
	sub_821F8730(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r7,587
	ctx.r7.s64 = 587;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x8244b0c8
	ctx.lr = 0x825002D8;
	sub_8244B0C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82500348
	if (!cr6.eq) goto loc_82500348;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825002f8
	if (!cr6.eq) goto loc_825002F8;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// b 0x82500344
	goto loc_82500344;
loc_825002F8:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r28,100(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// lwz r26,104(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r25,57(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 57);
	// bl 0x821f8730
	ctx.lr = 0x82500314;
	sub_821F8730(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,20
	ctx.r7.s64 = 20;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x8244adf0
	ctx.lr = 0x82500330;
	sub_8244ADF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82500348
	if (!cr6.eq) goto loc_82500348;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_82500344:
	// li r29,1
	r29.s64 = 1;
loc_82500348:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82500350;
	sub_82130588(ctx, base);
loc_82500350:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,960
	ctx.r1.s64 = ctx.r1.s64 + 960;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8250035C"))) PPC_WEAK_FUNC(sub_8250035C);
PPC_FUNC_IMPL(__imp__sub_8250035C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500360"))) PPC_WEAK_FUNC(sub_82500360);
PPC_FUNC_IMPL(__imp__sub_82500360) {
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
	// addi r30,r31,120
	r30.s64 = r31.s64 + 120;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// addi r4,r11,30280
	ctx.r4.s64 = r11.s64 + 30280;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b98
	ctx.lr = 0x82500394;
	sub_824E6B98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825003a4
	if (cr6.eq) goto loc_825003A4;
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
loc_825003A4:
	// lbz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// rlwimi r10,r11,7,0,24
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0xFFFFFF80) | (ctx.r10.u64 & 0xFFFFFFFF0000007F);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stb r9,208(r31)
	PPC_STORE_U8(r31.u32 + 208, ctx.r9.u8);
	// rlwinm r3,r9,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1;
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

__attribute__((alias("__imp__sub_825003D0"))) PPC_WEAK_FUNC(sub_825003D0);
PPC_FUNC_IMPL(__imp__sub_825003D0) {
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
	// lbz r11,208(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82500414
	if (cr6.eq) goto loc_82500414;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r3,r31,120
	ctx.r3.s64 = r31.s64 + 120;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82500408;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stb r8,208(r31)
	PPC_STORE_U8(r31.u32 + 208, ctx.r8.u8);
loc_82500414:
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

__attribute__((alias("__imp__sub_82500428"))) PPC_WEAK_FUNC(sub_82500428);
PPC_FUNC_IMPL(__imp__sub_82500428) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,120
	ctx.r3.s64 = ctx.r3.s64 + 120;
	// b 0x824e6a38
	sub_824E6A38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82500430"))) PPC_WEAK_FUNC(sub_82500430);
PPC_FUNC_IMPL(__imp__sub_82500430) {
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
	ctx.lr = 0x82500438;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// addi r4,r11,176
	ctx.r4.s64 = r11.s64 + 176;
	// bl 0x821c8fe0
	ctx.lr = 0x82500450;
	sub_821C8FE0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r31,52(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// lwz r28,116(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ce080
	ctx.lr = 0x82500464;
	sub_821CE080(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r30.u32);
	// bl 0x82500210
	ctx.lr = 0x82500474;
	sub_82500210(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8250049c
	if (cr6.eq) goto loc_8250049C;
	// lwz r29,116(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x82500494;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// b 0x825004b4
	goto loc_825004B4;
loc_8250049C:
	// lwz r30,116(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x825004AC;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_825004B4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82500088
	ctx.lr = 0x825004BC;
	sub_82500088(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x825004C4;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_825004CC"))) PPC_WEAK_FUNC(sub_825004CC);
PPC_FUNC_IMPL(__imp__sub_825004CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825004D0"))) PPC_WEAK_FUNC(sub_825004D0);
PPC_FUNC_IMPL(__imp__sub_825004D0) {
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
	// bl 0x824e71c8
	ctx.lr = 0x825004EC;
	sub_824E71C8(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
	// bl 0x82500088
	ctx.lr = 0x82500504;
	sub_82500088(ctx, base);
	// addi r3,r31,120
	ctx.r3.s64 = r31.s64 + 120;
	// bl 0x824e6928
	ctx.lr = 0x8250050C;
	sub_824E6928(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r30,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r30.u32);
	// addi r3,r31,176
	ctx.r3.s64 = r31.s64 + 176;
	// addi r10,r11,30264
	ctx.r10.s64 = r11.s64 + 30264;
	// stw r10,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r10.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x82500524;
	sub_821C8ED8(ctx, base);
	// lbz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stb r8,208(r31)
	PPC_STORE_U8(r31.u32 + 208, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_8250054C"))) PPC_WEAK_FUNC(sub_8250054C);
PPC_FUNC_IMPL(__imp__sub_8250054C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500550"))) PPC_WEAK_FUNC(sub_82500550);
PPC_FUNC_IMPL(__imp__sub_82500550) {
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
	// lbz r11,208(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82500594
	if (cr6.eq) goto loc_82500594;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r3,r31,120
	ctx.r3.s64 = r31.s64 + 120;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82500588;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stb r8,208(r31)
	PPC_STORE_U8(r31.u32 + 208, ctx.r8.u8);
loc_82500594:
	// addi r3,r31,176
	ctx.r3.s64 = r31.s64 + 176;
	// bl 0x82130000
	ctx.lr = 0x8250059C;
	sub_82130000(ctx, base);
	// addi r3,r31,120
	ctx.r3.s64 = r31.s64 + 120;
	// bl 0x824e6b58
	ctx.lr = 0x825005A4;
	sub_824E6B58(ctx, base);
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

__attribute__((alias("__imp__sub_825005B8"))) PPC_WEAK_FUNC(sub_825005B8);
PPC_FUNC_IMPL(__imp__sub_825005B8) {
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
	ctx.lr = 0x825005C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,120
	r30.s64 = r31.s64 + 120;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// bl 0x824e6a38
	ctx.lr = 0x825005F0;
	sub_824E6A38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8250064c
	if (!cr6.eq) goto loc_8250064C;
	// addi r4,r31,176
	ctx.r4.s64 = r31.s64 + 176;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x82500608;
	sub_821C8FE0(ctx, base);
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x82500618;
	sub_823DA950(ctx, base);
	// stw r28,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r28.u32);
	// stw r27,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r26.u32);
	// stw r25,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r25.u32);
	// stw r24,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r24.u32);
	// stw r23,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r23.u32);
	// bl 0x824e6a10
	ctx.lr = 0x82500638;
	sub_824E6A10(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82500640;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
loc_8250064C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82500658"))) PPC_WEAK_FUNC(sub_82500658);
PPC_FUNC_IMPL(__imp__sub_82500658) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9230
	ctx.lr = 0x8250067C;
	sub_824F9230(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// bl 0x824f92a0
	ctx.lr = 0x82500688;
	sub_824F92A0(ctx, base);
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

__attribute__((alias("__imp__sub_825006A0"))) PPC_WEAK_FUNC(sub_825006A0);
PPC_FUNC_IMPL(__imp__sub_825006A0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825006A8"))) PPC_WEAK_FUNC(sub_825006A8);
PPC_FUNC_IMPL(__imp__sub_825006A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825006B4"))) PPC_WEAK_FUNC(sub_825006B4);
PPC_FUNC_IMPL(__imp__sub_825006B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825006B8"))) PPC_WEAK_FUNC(sub_825006B8);
PPC_FUNC_IMPL(__imp__sub_825006B8) {
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
	// li r5,196
	ctx.r5.s64 = 196;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823d9890
	ctx.lr = 0x825006D8;
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

__attribute__((alias("__imp__sub_825006F0"))) PPC_WEAK_FUNC(sub_825006F0);
PPC_FUNC_IMPL(__imp__sub_825006F0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,32464
	r31.s64 = r11.s64 + 32464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0d8
	ctx.lr = 0x82500710;
	sub_821CE0D8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x82500728
	if (!cr6.eq) goto loc_82500728;
loc_82500718:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0d8
	ctx.lr = 0x82500720;
	sub_821CE0D8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82500718
	if (cr6.eq) goto loc_82500718;
loc_82500728:
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

__attribute__((alias("__imp__sub_8250073C"))) PPC_WEAK_FUNC(sub_8250073C);
PPC_FUNC_IMPL(__imp__sub_8250073C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500740"))) PPC_WEAK_FUNC(sub_82500740);
PPC_FUNC_IMPL(__imp__sub_82500740) {
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
	ctx.lr = 0x82500748;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-10
	r11.s64 = -655360;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r10,r11,45523
	ctx.r10.u64 = r11.u64 | 45523;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r4,11
	cr6.compare<uint32_t>(ctx.r4.u32, 11, xer);
	// ble cr6,0x825007c0
	if (!cr6.gt) goto loc_825007C0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82618318
	ctx.lr = 0x82500780;
	sub_82618318(ctx, base);
	// li r6,20
	ctx.r6.s64 = 20;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618318
	ctx.lr = 0x82500794;
	sub_82618318(ctx, base);
	// li r6,52
	ctx.r6.s64 = 52;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618318
	ctx.lr = 0x825007A8;
	sub_82618318(ctx, base);
	// lis r11,9
	r11.s64 = 589824;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r10,r11,20012
	ctx.r10.u64 = r11.u64 | 20012;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x825007c4
	if (cr6.eq) goto loc_825007C4;
loc_825007C0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_825007C4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_825007CC"))) PPC_WEAK_FUNC(sub_825007CC);
PPC_FUNC_IMPL(__imp__sub_825007CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825007D0"))) PPC_WEAK_FUNC(sub_825007D0);
PPC_FUNC_IMPL(__imp__sub_825007D0) {
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
	ctx.lr = 0x825007D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x82500740
	ctx.lr = 0x825007F8;
	sub_82500740(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82500820
	if (cr6.eq) goto loc_82500820;
	// cmplwi cr6,r31,11
	cr6.compare<uint32_t>(r31.u32, 11, xer);
	// ble cr6,0x82500820
	if (!cr6.gt) goto loc_82500820;
	// addi r11,r31,-11
	r11.s64 = r31.s64 + -11;
	// addi r3,r30,11
	ctx.r3.s64 = r30.s64 + 11;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82500820:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8250082C"))) PPC_WEAK_FUNC(sub_8250082C);
PPC_FUNC_IMPL(__imp__sub_8250082C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500830"))) PPC_WEAK_FUNC(sub_82500830);
PPC_FUNC_IMPL(__imp__sub_82500830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r9,r11,-3
	ctx.r9.s64 = r11.s64 + -3;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82500844"))) PPC_WEAK_FUNC(sub_82500844);
PPC_FUNC_IMPL(__imp__sub_82500844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500848"))) PPC_WEAK_FUNC(sub_82500848);
PPC_FUNC_IMPL(__imp__sub_82500848) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82500860
	if (cr6.eq) goto loc_82500860;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82500864
	if (!cr6.eq) goto loc_82500864;
loc_82500860:
	// li r11,1
	r11.s64 = 1;
loc_82500864:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8250086C"))) PPC_WEAK_FUNC(sub_8250086C);
PPC_FUNC_IMPL(__imp__sub_8250086C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500870"))) PPC_WEAK_FUNC(sub_82500870);
PPC_FUNC_IMPL(__imp__sub_82500870) {
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
	ctx.lr = 0x82500878;
	// stwu r1,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// subf r30,r10,r11
	r30.s64 = r11.s64 - ctx.r10.s64;
	// cmplwi cr6,r30,995
	cr6.compare<uint32_t>(r30.u32, 995, xer);
	// ble cr6,0x8250089c
	if (!cr6.gt) goto loc_8250089C;
	// li r30,995
	r30.s64 = 995;
loc_8250089C:
	// lis r4,9
	ctx.r4.s64 = 589824;
	// lwz r28,44(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r27,48(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r5,20
	ctx.r5.s64 = 20;
	// ori r4,r4,20012
	ctx.r4.u64 = ctx.r4.u64 | 20012;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618390
	ctx.lr = 0x825008BC;
	sub_82618390(ctx, base);
	// li r6,20
	ctx.r6.s64 = 20;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618390
	ctx.lr = 0x825008D0;
	sub_82618390(ctx, base);
	// li r6,52
	ctx.r6.s64 = 52;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618390
	ctx.lr = 0x825008E4;
	sub_82618390(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,91
	ctx.r3.s64 = ctx.r1.s64 + 91;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x8244d5c0
	ctx.lr = 0x825008F4;
	sub_8244D5C0(ctx, base);
	// addi r8,r31,56
	ctx.r8.s64 = r31.s64 + 56;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r6,r30,11
	ctx.r6.s64 = r30.s64 + 11;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x824edfe8
	ctx.lr = 0x82500910;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82500934
	if (cr6.eq) goto loc_82500934;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r3,1
	ctx.r3.s64 = 1;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d9244
	return;
loc_82500934:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82500940"))) PPC_WEAK_FUNC(sub_82500940);
PPC_FUNC_IMPL(__imp__sub_82500940) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8250098c
	if (cr6.gt) goto loc_8250098C;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x8250097C;
	sub_8244D5C0(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r3,1
	ctx.r3.s64 = 1;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
loc_8250098C:
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

__attribute__((alias("__imp__sub_825009A4"))) PPC_WEAK_FUNC(sub_825009A4);
PPC_FUNC_IMPL(__imp__sub_825009A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825009A8"))) PPC_WEAK_FUNC(sub_825009A8);
PPC_FUNC_IMPL(__imp__sub_825009A8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x825009e0
	if (cr6.eq) goto loc_825009E0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// bne cr6,0x825009e4
	if (!cr6.eq) goto loc_825009E4;
loc_825009E0:
	// li r11,1
	r11.s64 = 1;
loc_825009E4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82500a08
	if (!cr6.eq) goto loc_82500A08;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// bl 0x825006f0
	ctx.lr = 0x825009F8;
	sub_825006F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_82500A08:
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

__attribute__((alias("__imp__sub_82500A20"))) PPC_WEAK_FUNC(sub_82500A20);
PPC_FUNC_IMPL(__imp__sub_82500A20) {
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
	ctx.lr = 0x82500A28;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82500a60
	if (cr6.eq) goto loc_82500A60;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82500a64
	if (!cr6.eq) goto loc_82500A64;
loc_82500A60:
	// li r11,1
	r11.s64 = 1;
loc_82500A64:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82500ac4
	if (!cr6.eq) goto loc_82500AC4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ebac0
	ctx.lr = 0x82500A7C;
	sub_824EBAC0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// beq cr6,0x82500ac4
	if (cr6.eq) goto loc_82500AC4;
	// add r11,r29,r28
	r11.u64 = r29.u64 + r28.u64;
	// stw r26,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r26.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// stw r28,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r28.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r27,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r27.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x824ec120
	ctx.lr = 0x82500AB8;
	sub_824EC120(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82500AC4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82500AD0"))) PPC_WEAK_FUNC(sub_82500AD0);
PPC_FUNC_IMPL(__imp__sub_82500AD0) {
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
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824ebfa0
	ctx.lr = 0x82500AEC;
	sub_824EBFA0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// stw r9,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_82500B2C"))) PPC_WEAK_FUNC(sub_82500B2C);
PPC_FUNC_IMPL(__imp__sub_82500B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500B30"))) PPC_WEAK_FUNC(sub_82500B30);
PPC_FUNC_IMPL(__imp__sub_82500B30) {
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
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824ebfa0
	ctx.lr = 0x82500B4C;
	sub_824EBFA0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// stw r9,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_82500B8C"))) PPC_WEAK_FUNC(sub_82500B8C);
PPC_FUNC_IMPL(__imp__sub_82500B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500B90"))) PPC_WEAK_FUNC(sub_82500B90);
PPC_FUNC_IMPL(__imp__sub_82500B90) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82500cdc
	if (!cr6.eq) goto loc_82500CDC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82500BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,5
	cr6.compare<uint32_t>(ctx.r3.u32, 5, xer);
	// bne cr6,0x82500c1c
	if (!cr6.eq) goto loc_82500C1C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82500cdc
	if (!cr6.eq) goto loc_82500CDC;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lhz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// lhz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82500cdc
	if (!cr6.eq) goto loc_82500CDC;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82500cbc
	if (cr6.eq) goto loc_82500CBC;
	// bl 0x82500870
	ctx.lr = 0x82500C10;
	sub_82500870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// b 0x82500cd0
	goto loc_82500CD0;
loc_82500C1C:
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82500cc4
	if (!cr6.eq) goto loc_82500CC4;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r30,12(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82500cdc
	if (!cr6.eq) goto loc_82500CDC;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lwz r4,40(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lwz r3,44(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// bl 0x82500740
	ctx.lr = 0x82500C48;
	sub_82500740(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82500cdc
	if (cr6.eq) goto loc_82500CDC;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82500cdc
	if (!cr6.eq) goto loc_82500CDC;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82500cd4
	if (!cr6.eq) goto loc_82500CD4;
	// li r11,0
	r11.s64 = 0;
	// lwz r4,40(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,44(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x825007d0
	ctx.lr = 0x82500C8C;
	sub_825007D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82500940
	ctx.lr = 0x82500C9C;
	sub_82500940(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82500cd4
	if (cr6.eq) goto loc_82500CD4;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82500cdc
	if (!cr6.eq) goto loc_82500CDC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82500CBC:
	// bl 0x82500ad0
	ctx.lr = 0x82500CC0;
	sub_82500AD0(ctx, base);
	// b 0x82500cdc
	goto loc_82500CDC;
loc_82500CC4:
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x82500cd4
	if (cr6.eq) goto loc_82500CD4;
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
loc_82500CD0:
	// bne cr6,0x82500cdc
	if (!cr6.eq) goto loc_82500CDC;
loc_82500CD4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82500b30
	ctx.lr = 0x82500CDC;
	sub_82500B30(ctx, base);
loc_82500CDC:
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

__attribute__((alias("__imp__sub_82500CF4"))) PPC_WEAK_FUNC(sub_82500CF4);
PPC_FUNC_IMPL(__imp__sub_82500CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500CF8"))) PPC_WEAK_FUNC(sub_82500CF8);
PPC_FUNC_IMPL(__imp__sub_82500CF8) {
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
	ctx.lr = 0x82500D00;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r29,-1
	r29.s64 = -1;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// bl 0x824ebf78
	ctx.lr = 0x82500D20;
	sub_824EBF78(ctx, base);
	// lis r11,-32176
	r11.s64 = -2108686336;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// addi r9,r11,2960
	ctx.r9.s64 = r11.s64 + 2960;
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// stw r29,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r29.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x82500D50;
	sub_82130000(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82500D60"))) PPC_WEAK_FUNC(sub_82500D60);
PPC_FUNC_IMPL(__imp__sub_82500D60) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82500d94
	if (cr6.eq) goto loc_82500D94;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// bne cr6,0x82500d98
	if (!cr6.eq) goto loc_82500D98;
loc_82500D94:
	// li r11,1
	r11.s64 = 1;
loc_82500D98:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82500dd4
	if (cr6.eq) goto loc_82500DD4;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824ebfa0
	ctx.lr = 0x82500DAC;
	sub_824EBFA0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
loc_82500DD4:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82130000
	ctx.lr = 0x82500DDC;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_82500DF4"))) PPC_WEAK_FUNC(sub_82500DF4);
PPC_FUNC_IMPL(__imp__sub_82500DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500DF8"))) PPC_WEAK_FUNC(sub_82500DF8);
PPC_FUNC_IMPL(__imp__sub_82500DF8) {
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
	ctx.lr = 0x82500E00;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82500e94
	if (!cr6.eq) goto loc_82500E94;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ebac0
	ctx.lr = 0x82500E34;
	sub_824EBAC0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// beq cr6,0x82500e94
	if (cr6.eq) goto loc_82500E94;
	// add r11,r29,r28
	r11.u64 = r29.u64 + r28.u64;
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r28.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r27,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r27.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x824ec120
	ctx.lr = 0x82500E6C;
	sub_824EC120(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82500870
	ctx.lr = 0x82500E74;
	sub_82500870(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82500e8c
	if (cr6.eq) goto loc_82500E8C;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82500E8C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82500b30
	ctx.lr = 0x82500E94;
	sub_82500B30(ctx, base);
loc_82500E94:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82500EA0"))) PPC_WEAK_FUNC(sub_82500EA0);
PPC_FUNC_IMPL(__imp__sub_82500EA0) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// bl 0x821c8fe0
	ctx.lr = 0x82500EC0;
	sub_821C8FE0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82500ed8
	if (cr6.eq) goto loc_82500ED8;
	// bl 0x821e4568
	ctx.lr = 0x82500ED0;
	sub_821E4568(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_82500ED8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82500EE0;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_82500EF8"))) PPC_WEAK_FUNC(sub_82500EF8);
PPC_FUNC_IMPL(__imp__sub_82500EF8) {
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
	// bl 0x8244a680
	ctx.lr = 0x82500F08;
	sub_8244A680(ctx, base);
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

__attribute__((alias("__imp__sub_82500F24"))) PPC_WEAK_FUNC(sub_82500F24);
PPC_FUNC_IMPL(__imp__sub_82500F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82500F28"))) PPC_WEAK_FUNC(sub_82500F28);
PPC_FUNC_IMPL(__imp__sub_82500F28) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// bl 0x821c8fe0
	ctx.lr = 0x82500F4C;
	sub_821C8FE0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82500f74
	if (!cr6.eq) goto loc_82500F74;
	// bl 0x8244a680
	ctx.lr = 0x82500F60;
	sub_8244A680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82500f74
	if (cr6.eq) goto loc_82500F74;
	// li r30,1
	r30.s64 = 1;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// bl 0x821e44a0
	ctx.lr = 0x82500F74;
	sub_821E44A0(ctx, base);
loc_82500F74:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82500F7C;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_82500F98"))) PPC_WEAK_FUNC(sub_82500F98);
PPC_FUNC_IMPL(__imp__sub_82500F98) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// bl 0x821c8fe0
	ctx.lr = 0x82500FB8;
	sub_821C8FE0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82500fdc
	if (cr6.eq) goto loc_82500FDC;
	// bl 0x8244a680
	ctx.lr = 0x82500FC8;
	sub_8244A680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82500fdc
	if (!cr6.eq) goto loc_82500FDC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82500ea0
	ctx.lr = 0x82500FD8;
	sub_82500EA0(ctx, base);
	// b 0x82501014
	goto loc_82501014;
loc_82500FDC:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82501000
	if (!cr6.eq) goto loc_82501000;
	// bl 0x8244a680
	ctx.lr = 0x82500FEC;
	sub_8244A680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82501000
	if (cr6.eq) goto loc_82501000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82500f28
	ctx.lr = 0x82500FFC;
	sub_82500F28(ctx, base);
	// b 0x82501014
	goto loc_82501014;
loc_82501000:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82501014
	if (!cr6.eq) goto loc_82501014;
	// li r11,2
	r11.s64 = 2;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_82501014:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8250101C;
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

__attribute__((alias("__imp__sub_82501030"))) PPC_WEAK_FUNC(sub_82501030);
PPC_FUNC_IMPL(__imp__sub_82501030) {
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
	ctx.lr = 0x82501038;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82501110
	if (!cr6.eq) goto loc_82501110;
	// rlwinm r28,r29,0,30,30
	r28.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x2;
	// stw r24,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r24.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8250108c
	if (cr6.eq) goto loc_8250108C;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
loc_8250108C:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x825010b4
	if (cr6.eq) goto loc_825010B4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825010A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// subf r11,r3,r9
	r11.s64 = ctx.r9.s64 - ctx.r3.s64;
	// b 0x825010b8
	goto loc_825010B8;
loc_825010B4:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_825010B8:
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r26,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r26.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r25,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r25.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r29,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r29.u32);
	// stw r27,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r27.u32);
	// beq cr6,0x825010ec
	if (cr6.eq) goto loc_825010EC;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x825010f0
	if (cr6.eq) goto loc_825010F0;
loc_825010EC:
	// li r30,1
	r30.s64 = 1;
loc_825010F0:
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// rlwimi r11,r30,7,17,24
	r11.u64 = (__builtin_rotateleft32(r30.u32, 7) & 0x7F80) | (r11.u64 & 0xFFFFFFFFFFFF807F);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stb r11,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r11.u8);
	// bl 0x824ec120
	ctx.lr = 0x8250110C;
	sub_824EC120(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_82501110:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82501118"))) PPC_WEAK_FUNC(sub_82501118);
PPC_FUNC_IMPL(__imp__sub_82501118) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rlwinm r10,r4,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82501148
	if (cr6.eq) goto loc_82501148;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
loc_82501148:
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82501154"))) PPC_WEAK_FUNC(sub_82501154);
PPC_FUNC_IMPL(__imp__sub_82501154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82501158"))) PPC_WEAK_FUNC(sub_82501158);
PPC_FUNC_IMPL(__imp__sub_82501158) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82501188
	if (cr6.eq) goto loc_82501188;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// bl 0x824ebcc8
	ctx.lr = 0x82501180;
	sub_824EBCC8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_82501188:
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

__attribute__((alias("__imp__sub_825011A0"))) PPC_WEAK_FUNC(sub_825011A0);
PPC_FUNC_IMPL(__imp__sub_825011A0) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825011C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 + ctx.r9.u64;
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

__attribute__((alias("__imp__sub_825011E0"))) PPC_WEAK_FUNC(sub_825011E0);
PPC_FUNC_IMPL(__imp__sub_825011E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x821c9788
	sub_821C9788(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_825011E4"))) PPC_WEAK_FUNC(sub_825011E4);
PPC_FUNC_IMPL(__imp__sub_825011E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825011E8"))) PPC_WEAK_FUNC(sub_825011E8);
PPC_FUNC_IMPL(__imp__sub_825011E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,80(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 80);
	// rlwinm r3,r11,25,7,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825011F4"))) PPC_WEAK_FUNC(sub_825011F4);
PPC_FUNC_IMPL(__imp__sub_825011F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825011F8"))) PPC_WEAK_FUNC(sub_825011F8);
PPC_FUNC_IMPL(__imp__sub_825011F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82501204"))) PPC_WEAK_FUNC(sub_82501204);
PPC_FUNC_IMPL(__imp__sub_82501204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82501208"))) PPC_WEAK_FUNC(sub_82501208);
PPC_FUNC_IMPL(__imp__sub_82501208) {
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
	// addi r10,r11,31132
	ctx.r10.s64 = r11.s64 + 31132;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82501244
	if (cr6.eq) goto loc_82501244;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// bl 0x824ebcc8
	ctx.lr = 0x8250123C;
	sub_824EBCC8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_82501244:
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82130000
	ctx.lr = 0x8250124C;
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

__attribute__((alias("__imp__sub_82501260"))) PPC_WEAK_FUNC(sub_82501260);
PPC_FUNC_IMPL(__imp__sub_82501260) {
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
	ctx.lr = 0x82501268;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x82501284;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825012bc
	if (cr6.eq) goto loc_825012BC;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x825012AC;
	sub_82618390(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x825012B8;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_825012BC:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501338
	if (cr6.eq) goto loc_82501338;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r29,4
	ctx.r4.s64 = r29.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x825012D8;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501338
	if (cr6.eq) goto loc_82501338;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r29,8
	ctx.r4.s64 = r29.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x825012F4;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501338
	if (cr6.eq) goto loc_82501338;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82501328
	if (!cr6.eq) goto loc_82501328;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r29,12
	ctx.r4.s64 = r29.s64 + 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x8250131C;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501338
	if (cr6.eq) goto loc_82501338;
loc_82501328:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82501338:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82501348"))) PPC_WEAK_FUNC(sub_82501348);
PPC_FUNC_IMPL(__imp__sub_82501348) {
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
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82257568
	ctx.lr = 0x8250136C;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825013e0
	if (cr6.eq) goto loc_825013E0;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x82501388;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825013e0
	if (cr6.eq) goto loc_825013E0;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x825013A4;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825013e0
	if (cr6.eq) goto loc_825013E0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x825013d8
	if (!cr6.eq) goto loc_825013D8;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x825013CC;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825013e0
	if (cr6.eq) goto loc_825013E0;
loc_825013D8:
	// li r11,1
	r11.s64 = 1;
	// b 0x825013e4
	goto loc_825013E4;
loc_825013E0:
	// li r11,0
	r11.s64 = 0;
loc_825013E4:
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

__attribute__((alias("__imp__sub_82501400"))) PPC_WEAK_FUNC(sub_82501400);
PPC_FUNC_IMPL(__imp__sub_82501400) {
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
	ctx.lr = 0x82501408;
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
	ctx.lr = 0x8250142C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82501438;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82501448;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8250146c
	if (cr6.eq) goto loc_8250146C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82501260
	ctx.lr = 0x8250145C;
	sub_82501260(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82501470
	if (!cr6.eq) goto loc_82501470;
loc_8250146C:
	// li r30,0
	r30.s64 = 0;
loc_82501470:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x825014a8
	if (cr6.eq) goto loc_825014A8;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825014a0
	if (cr6.eq) goto loc_825014A0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8250148C;
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
loc_825014A0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_825014A8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_825014B4"))) PPC_WEAK_FUNC(sub_825014B4);
PPC_FUNC_IMPL(__imp__sub_825014B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825014B8"))) PPC_WEAK_FUNC(sub_825014B8);
PPC_FUNC_IMPL(__imp__sub_825014B8) {
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
	ctx.lr = 0x825014C0;
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
	ctx.lr = 0x825014F0;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x825014FC;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x8250150C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8250153c
	if (cr6.eq) goto loc_8250153C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x8250153c
	if (!cr6.eq) goto loc_8250153C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82501348
	ctx.lr = 0x8250152C;
	sub_82501348(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82501540
	if (!cr6.eq) goto loc_82501540;
loc_8250153C:
	// li r31,0
	r31.s64 = 0;
loc_82501540:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8250156c
	if (cr6.eq) goto loc_8250156C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501564
	if (cr6.eq) goto loc_82501564;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x8250155C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82501568
	goto loc_82501568;
loc_82501564:
	// li r11,0
	r11.s64 = 0;
loc_82501568:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8250156C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501590
	if (cr6.eq) goto loc_82501590;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82501580;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82501594
	if (cr6.eq) goto loc_82501594;
loc_82501590:
	// li r11,0
	r11.s64 = 0;
loc_82501594:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_825015A0"))) PPC_WEAK_FUNC(sub_825015A0);
PPC_FUNC_IMPL(__imp__sub_825015A0) {
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
	// addi r10,r11,31132
	ctx.r10.s64 = r11.s64 + 31132;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825015e4
	if (cr6.eq) goto loc_825015E4;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// bl 0x824ebcc8
	ctx.lr = 0x825015DC;
	sub_824EBCC8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_825015E4:
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82130000
	ctx.lr = 0x825015EC;
	sub_82130000(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501604
	if (cr6.eq) goto loc_82501604;
	// bl 0x82130588
	ctx.lr = 0x82501600;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82501604:
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

__attribute__((alias("__imp__sub_8250161C"))) PPC_WEAK_FUNC(sub_8250161C);
PPC_FUNC_IMPL(__imp__sub_8250161C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82501620"))) PPC_WEAK_FUNC(sub_82501620);
PPC_FUNC_IMPL(__imp__sub_82501620) {
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
	ctx.lr = 0x82501628;
	// stwu r1,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,32468
	ctx.r10.s64 = r11.s64 + 32468;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,1006
	ctx.r6.s64 = 1006;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82501400
	ctx.lr = 0x82501658;
	sub_82501400(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8250168c
	if (cr6.eq) goto loc_8250168C;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ef298
	ctx.lr = 0x8250167C;
	sub_824EF298(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82501690
	if (!cr6.eq) goto loc_82501690;
loc_8250168C:
	// li r11,0
	r11.s64 = 0;
loc_82501690:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8250169C"))) PPC_WEAK_FUNC(sub_8250169C);
PPC_FUNC_IMPL(__imp__sub_8250169C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825016A0"))) PPC_WEAK_FUNC(sub_825016A0);
PPC_FUNC_IMPL(__imp__sub_825016A0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8250173c
	if (cr6.eq) goto loc_8250173C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8250173c
	if (cr6.eq) goto loc_8250173C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825016E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825016fc
	if (cr6.eq) goto loc_825016FC;
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8250173c
	if (cr0.lt) goto loc_8250173C;
loc_825016FC:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82501620
	ctx.lr = 0x8250172C;
	sub_82501620(ctx, base);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stw r8,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r8.u32);
loc_8250173C:
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

__attribute__((alias("__imp__sub_82501754"))) PPC_WEAK_FUNC(sub_82501754);
PPC_FUNC_IMPL(__imp__sub_82501754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82501758"))) PPC_WEAK_FUNC(sub_82501758);
PPC_FUNC_IMPL(__imp__sub_82501758) {
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
	ctx.lr = 0x82501760;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8250178C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x825018ec
	if (!cr6.eq) goto loc_825018EC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r9,r11,32468
	ctx.r9.s64 = r11.s64 + 32468;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,40(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// lwz r5,44(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x825014b8
	ctx.lr = 0x825017B8;
	sub_825014B8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x825018ec
	if (cr6.eq) goto loc_825018EC;
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82501838
	if (!cr6.eq) goto loc_82501838;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82501838
	if (cr6.eq) goto loc_82501838;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8250180C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 + ctx.r5.u64;
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r4,r11,32
	ctx.r4.s64 = r11.s64 + 32;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82501620
	ctx.lr = 0x82501830;
	sub_82501620(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82501838:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8250184C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,1
	cr6.compare<uint32_t>(r29.u32, 1, xer);
	// bne cr6,0x825018ec
	if (!cr6.eq) goto loc_825018EC;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825018ec
	if (cr6.eq) goto loc_825018EC;
	// lwz r27,84(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// subf. r10,r11,r27
	ctx.r10.s64 = r27.s64 - r11.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x825018ec
	if (!cr0.gt) goto loc_825018EC;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// subf. r29,r11,r30
	r29.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// ble 0x825018ec
	if (!cr0.gt) goto loc_825018EC;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// bl 0x824e62e0
	ctx.lr = 0x82501894;
	sub_824E62E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825018ec
	if (cr6.eq) goto loc_825018EC;
	// rlwinm r9,r29,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// subf r9,r30,r9
	ctx.r9.s64 = ctx.r9.s64 - r30.s64;
	// stw r27,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r27.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x825018e0
	if (!cr6.lt) goto loc_825018E0;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r10.u32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// ble cr6,0x825018e0
	if (!cr6.gt) goto loc_825018E0;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
loc_825018E0:
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r10.u8);
loc_825018EC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_825018F4"))) PPC_WEAK_FUNC(sub_825018F4);
PPC_FUNC_IMPL(__imp__sub_825018F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825018F8"))) PPC_WEAK_FUNC(sub_825018F8);
PPC_FUNC_IMPL(__imp__sub_825018F8) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,31132
	ctx.r10.s64 = r11.s64 + 31132;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e6310
	ctx.lr = 0x8250192C;
	sub_824E6310(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x824ebf78
	ctx.lr = 0x82501938;
	sub_824EBF78(ctx, base);
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// lis r8,-32176
	ctx.r8.s64 = -2108686336;
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// li r7,2000
	ctx.r7.s64 = 2000;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// ori r6,r9,60000
	ctx.r6.u64 = ctx.r9.u64 | 60000;
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// li r5,-1
	ctx.r5.s64 = -1;
	// stw r7,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r7.u32);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r6,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r6.u32);
	// addi r4,r8,5976
	ctx.r4.s64 = ctx.r8.s64 + 5976;
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r5,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r10.u8);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r4,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x8250198C;
	sub_82130000(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_825019AC"))) PPC_WEAK_FUNC(sub_825019AC);
PPC_FUNC_IMPL(__imp__sub_825019AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825019B0"))) PPC_WEAK_FUNC(sub_825019B0);
PPC_FUNC_IMPL(__imp__sub_825019B0) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// bl 0x8244a680
	ctx.lr = 0x825019C8;
	sub_8244A680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82501a10
	if (cr6.eq) goto loc_82501A10;
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x825019E0;
	sub_8244D150(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244a670
	ctx.lr = 0x825019E8;
	sub_8244A670(ctx, base);
	// rlwinm r11,r3,0,16,16
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82501a10
	if (!cr6.eq) goto loc_82501A10;
	// clrlwi r11,r3,31
	r11.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82501a10
	if (!cr6.eq) goto loc_82501A10;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82501a14
	if (!cr6.eq) goto loc_82501A14;
loc_82501A10:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82501A14:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82501A28"))) PPC_WEAK_FUNC(sub_82501A28);
PPC_FUNC_IMPL(__imp__sub_82501A28) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// bl 0x8244a670
	ctx.lr = 0x82501A44;
	sub_8244A670(ctx, base);
	// rlwinm r11,r3,0,16,16
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82501a60
	if (!cr6.eq) goto loc_82501A60;
	// rlwinm r11,r3,0,24,24
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x80;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82501a64
	if (!cr6.eq) goto loc_82501A64;
loc_82501A60:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82501A64:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82501A78"))) PPC_WEAK_FUNC(sub_82501A78);
PPC_FUNC_IMPL(__imp__sub_82501A78) {
	PPC_FUNC_PROLOGUE();
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8244d150
	sub_8244D150(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82501A84"))) PPC_WEAK_FUNC(sub_82501A84);
PPC_FUNC_IMPL(__imp__sub_82501A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82501A88"))) PPC_WEAK_FUNC(sub_82501A88);
PPC_FUNC_IMPL(__imp__sub_82501A88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
loc_82501A90:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// subf. r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82501ab0
	if (!cr0.eq) goto loc_82501AB0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x82501a90
	if (!cr6.eq) goto loc_82501A90;
loc_82501AB0:
	// addi r11,r10,0
	r11.s64 = ctx.r10.s64 + 0;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82501AC0"))) PPC_WEAK_FUNC(sub_82501AC0);
PPC_FUNC_IMPL(__imp__sub_82501AC0) {
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
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x82501AE0;
	sub_8244D150(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244a670
	ctx.lr = 0x82501AE8;
	sub_8244A670(ctx, base);
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

__attribute__((alias("__imp__sub_82501B00"))) PPC_WEAK_FUNC(sub_82501B00);
PPC_FUNC_IMPL(__imp__sub_82501B00) {
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
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x82501B20;
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

__attribute__((alias("__imp__sub_82501B38"))) PPC_WEAK_FUNC(sub_82501B38);
PPC_FUNC_IMPL(__imp__sub_82501B38) {
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
	ctx.lr = 0x82501B40;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x82618750
	ctx.lr = 0x82501B5C;
	sub_82618750(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82501B6C;
	sub_82618640(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x82501B80;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501bb8
	if (cr6.eq) goto loc_82501BB8;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82618390
	ctx.lr = 0x82501BA8;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x82501BB4;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_82501BB8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501c38
	if (cr6.eq) goto loc_82501C38;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6390
	ctx.lr = 0x82501BD4;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501c38
	if (cr6.eq) goto loc_82501C38;
	// li r5,16
	ctx.r5.s64 = 16;
	// lhz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82275660
	ctx.lr = 0x82501BF0;
	sub_82275660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501c38
	if (cr6.eq) goto loc_82501C38;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r29,10
	ctx.r4.s64 = r29.s64 + 10;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618f90
	ctx.lr = 0x82501C0C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501c38
	if (cr6.eq) goto loc_82501C38;
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618f90
	ctx.lr = 0x82501C28;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82501c3c
	if (!cr6.eq) goto loc_82501C3C;
loc_82501C38:
	// li r11,0
	r11.s64 = 0;
loc_82501C3C:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82501c74
	if (cr6.eq) goto loc_82501C74;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501c6c
	if (cr6.eq) goto loc_82501C6C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82501C5C;
	sub_826186A0(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_82501C6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
loc_82501C74:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82501C80"))) PPC_WEAK_FUNC(sub_82501C80);
PPC_FUNC_IMPL(__imp__sub_82501C80) {
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
	ctx.lr = 0x82501C88;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x82618750
	ctx.lr = 0x82501CA4;
	sub_82618750(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826185e0
	ctx.lr = 0x82501CB4;
	sub_826185E0(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82257568
	ctx.lr = 0x82501CC4;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501d44
	if (cr6.eq) goto loc_82501D44;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82257568
	ctx.lr = 0x82501CE0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501d44
	if (cr6.eq) goto loc_82501D44;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822756d0
	ctx.lr = 0x82501CFC;
	sub_822756D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501d44
	if (cr6.eq) goto loc_82501D44;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r31,10
	ctx.r4.s64 = r31.s64 + 10;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618f80
	ctx.lr = 0x82501D18;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501d44
	if (cr6.eq) goto loc_82501D44;
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618f80
	ctx.lr = 0x82501D34;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82501d48
	if (!cr6.eq) goto loc_82501D48;
loc_82501D44:
	// li r11,0
	r11.s64 = 0;
loc_82501D48:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82501d80
	if (cr6.eq) goto loc_82501D80;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82501d78
	if (cr6.eq) goto loc_82501D78;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186b0
	ctx.lr = 0x82501D68;
	sub_826186B0(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_82501D78:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_82501D80:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82501D8C"))) PPC_WEAK_FUNC(sub_82501D8C);
PPC_FUNC_IMPL(__imp__sub_82501D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82501D90"))) PPC_WEAK_FUNC(sub_82501D90);
PPC_FUNC_IMPL(__imp__sub_82501D90) {
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
	// addi r9,r11,31476
	ctx.r9.s64 = r11.s64 + 31476;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82501dc4
	if (cr6.eq) goto loc_82501DC4;
	// bl 0x82130588
	ctx.lr = 0x82501DC0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82501DC4:
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

__attribute__((alias("__imp__sub_82501DD8"))) PPC_WEAK_FUNC(sub_82501DD8);
PPC_FUNC_IMPL(__imp__sub_82501DD8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82501DE0;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d8
	ctx.lr = 0x82501DE8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r11,r29,8,24,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 8) & 0xFF;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r31,-25824(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + -25824);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// fcmpu cr6,f12,f30
	cr6.compare(ctx.f12.f64, f30.f64);
	// ble cr6,0x82501ea8
	if (!cr6.gt) goto loc_82501EA8;
	// extsw r10,r28
	ctx.r10.s64 = r28.s32;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
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
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// frsp f28,f11
	f28.f64 = double(float(ctx.f11.f64));
	// lfs f31,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f31.f64 = double(temp.f32);
	// rlwinm r7,r11,24,0,7
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF000000;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	f0.f64 = double(temp.f32);
	// frsp f29,f12
	f29.f64 = double(float(ctx.f12.f64));
	// fadds f2,f28,f0
	ctx.f2.f64 = double(float(f28.f64 + f0.f64));
	// fadds f1,f29,f31
	ctx.f1.f64 = double(float(f29.f64 + f31.f64));
	// bl 0x8217f148
	ctx.lr = 0x82501E84;
	sub_8217F148(ctx, base);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// fmr f5,f31
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = f31.f64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x8217f148
	ctx.lr = 0x82501EA8;
	sub_8217F148(ctx, base);
loc_82501EA8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
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
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r3,r11,2
	ctx.r3.s64 = r11.s64 + 2;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba24
	ctx.lr = 0x82501EE8;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82501EEC"))) PPC_WEAK_FUNC(sub_82501EEC);
PPC_FUNC_IMPL(__imp__sub_82501EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82501EF0"))) PPC_WEAK_FUNC(sub_82501EF0);
PPC_FUNC_IMPL(__imp__sub_82501EF0) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r10,31476
	ctx.r7.s64 = ctx.r10.s64 + 31476;
	// li r6,0
	ctx.r6.s64 = 0;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stb r6,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r6.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r5,31532
	ctx.r4.s64 = ctx.r5.s64 + 31532;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// bl 0x82535010
	ctx.lr = 0x82501F3C;
	sub_82535010(ctx, base);
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

__attribute__((alias("__imp__sub_82501F54"))) PPC_WEAK_FUNC(sub_82501F54);
PPC_FUNC_IMPL(__imp__sub_82501F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82501F58"))) PPC_WEAK_FUNC(sub_82501F58);
PPC_FUNC_IMPL(__imp__sub_82501F58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,31584
	ctx.r3.s64 = r11.s64 + 31584;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82501F64"))) PPC_WEAK_FUNC(sub_82501F64);
PPC_FUNC_IMPL(__imp__sub_82501F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82501F68"))) PPC_WEAK_FUNC(sub_82501F68);
PPC_FUNC_IMPL(__imp__sub_82501F68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r10,31476
	ctx.r7.s64 = ctx.r10.s64 + 31476;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// li r30,0
	r30.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r5,r6,31600
	ctx.r5.s64 = ctx.r6.s64 + 31600;
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// bl 0x8260b730
	ctx.lr = 0x82501FBC;
	sub_8260B730(ctx, base);
	// stb r30,1048(r31)
	PPC_STORE_U8(r31.u32 + 1048, r30.u8);
	// stb r30,1049(r31)
	PPC_STORE_U8(r31.u32 + 1049, r30.u8);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stb r30,1050(r31)
	PPC_STORE_U8(r31.u32 + 1050, r30.u8);
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// stb r30,1051(r31)
	PPC_STORE_U8(r31.u32 + 1051, r30.u8);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r30,1052(r31)
	PPC_STORE_U8(r31.u32 + 1052, r30.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, r30.u32);
	// addi r9,r3,2256
	ctx.r9.s64 = ctx.r3.s64 + 2256;
	// stb r30,1060(r31)
	PPC_STORE_U8(r31.u32 + 1060, r30.u8);
	// lfs f3,17032(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17032);
	ctx.f3.f64 = double(temp.f32);
	// stb r30,1061(r31)
	PPC_STORE_U8(r31.u32 + 1061, r30.u8);
	// stb r30,1062(r31)
	PPC_STORE_U8(r31.u32 + 1062, r30.u8);
	// stb r30,1063(r31)
	PPC_STORE_U8(r31.u32 + 1063, r30.u8);
	// stb r30,1064(r31)
	PPC_STORE_U8(r31.u32 + 1064, r30.u8);
	// stw r30,1068(r31)
	PPC_STORE_U32(r31.u32 + 1068, r30.u32);
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
	// stw r30,1080(r31)
	PPC_STORE_U32(r31.u32 + 1080, r30.u32);
	// stb r30,1084(r31)
	PPC_STORE_U8(r31.u32 + 1084, r30.u8);
	// stb r30,1085(r31)
	PPC_STORE_U8(r31.u32 + 1085, r30.u8);
	// stb r30,1086(r31)
	PPC_STORE_U8(r31.u32 + 1086, r30.u8);
	// stb r30,1087(r31)
	PPC_STORE_U8(r31.u32 + 1087, r30.u8);
	// stb r30,1088(r31)
	PPC_STORE_U8(r31.u32 + 1088, r30.u8);
	// stw r30,1092(r31)
	PPC_STORE_U32(r31.u32 + 1092, r30.u32);
	// stb r30,1096(r31)
	PPC_STORE_U8(r31.u32 + 1096, r30.u8);
	// stb r30,1097(r31)
	PPC_STORE_U8(r31.u32 + 1097, r30.u8);
	// stb r30,1098(r31)
	PPC_STORE_U8(r31.u32 + 1098, r30.u8);
	// stb r30,1099(r31)
	PPC_STORE_U8(r31.u32 + 1099, r30.u8);
	// stb r30,1100(r31)
	PPC_STORE_U8(r31.u32 + 1100, r30.u8);
	// stw r30,1104(r31)
	PPC_STORE_U32(r31.u32 + 1104, r30.u32);
	// stb r30,1108(r31)
	PPC_STORE_U8(r31.u32 + 1108, r30.u8);
	// stb r30,1109(r31)
	PPC_STORE_U8(r31.u32 + 1109, r30.u8);
	// stb r30,1110(r31)
	PPC_STORE_U8(r31.u32 + 1110, r30.u8);
	// stb r30,1111(r31)
	PPC_STORE_U8(r31.u32 + 1111, r30.u8);
	// stb r30,1112(r31)
	PPC_STORE_U8(r31.u32 + 1112, r30.u8);
	// stw r30,1116(r31)
	PPC_STORE_U32(r31.u32 + 1116, r30.u32);
	// stb r30,1120(r31)
	PPC_STORE_U8(r31.u32 + 1120, r30.u8);
	// stb r30,1121(r31)
	PPC_STORE_U8(r31.u32 + 1121, r30.u8);
	// stb r30,1122(r31)
	PPC_STORE_U8(r31.u32 + 1122, r30.u8);
	// stb r30,1123(r31)
	PPC_STORE_U8(r31.u32 + 1123, r30.u8);
	// stb r30,1124(r31)
	PPC_STORE_U8(r31.u32 + 1124, r30.u8);
	// stw r30,1128(r31)
	PPC_STORE_U32(r31.u32 + 1128, r30.u32);
	// stb r30,1132(r31)
	PPC_STORE_U8(r31.u32 + 1132, r30.u8);
	// stb r30,1133(r31)
	PPC_STORE_U8(r31.u32 + 1133, r30.u8);
	// stb r30,1134(r31)
	PPC_STORE_U8(r31.u32 + 1134, r30.u8);
	// stb r30,1135(r31)
	PPC_STORE_U8(r31.u32 + 1135, r30.u8);
	// stb r30,1136(r31)
	PPC_STORE_U8(r31.u32 + 1136, r30.u8);
	// stw r30,1140(r31)
	PPC_STORE_U32(r31.u32 + 1140, r30.u32);
	// stb r30,1144(r31)
	PPC_STORE_U8(r31.u32 + 1144, r30.u8);
	// stb r30,1145(r31)
	PPC_STORE_U8(r31.u32 + 1145, r30.u8);
	// stb r30,1146(r31)
	PPC_STORE_U8(r31.u32 + 1146, r30.u8);
	// stb r30,1147(r31)
	PPC_STORE_U8(r31.u32 + 1147, r30.u8);
	// stb r30,1148(r31)
	PPC_STORE_U8(r31.u32 + 1148, r30.u8);
	// stw r30,1152(r31)
	PPC_STORE_U32(r31.u32 + 1152, r30.u32);
	// stb r30,1156(r31)
	PPC_STORE_U8(r31.u32 + 1156, r30.u8);
	// stb r30,1157(r31)
	PPC_STORE_U8(r31.u32 + 1157, r30.u8);
	// stb r30,1158(r31)
	PPC_STORE_U8(r31.u32 + 1158, r30.u8);
	// stb r30,1159(r31)
	PPC_STORE_U8(r31.u32 + 1159, r30.u8);
	// stb r30,1160(r31)
	PPC_STORE_U8(r31.u32 + 1160, r30.u8);
	// stw r30,1164(r31)
	PPC_STORE_U32(r31.u32 + 1164, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,1172(r31)
	PPC_STORE_U8(r31.u32 + 1172, r30.u8);
	// lfs f2,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// stb r30,1168(r31)
	PPC_STORE_U8(r31.u32 + 1168, r30.u8);
	// lfs f1,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// stb r30,1171(r31)
	PPC_STORE_U8(r31.u32 + 1171, r30.u8);
	// stb r30,1169(r31)
	PPC_STORE_U8(r31.u32 + 1169, r30.u8);
	// stb r30,1170(r31)
	PPC_STORE_U8(r31.u32 + 1170, r30.u8);
	// stw r30,1176(r31)
	PPC_STORE_U32(r31.u32 + 1176, r30.u32);
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82535ea8
	ctx.lr = 0x825020F0;
	sub_82535EA8(ctx, base);
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

__attribute__((alias("__imp__sub_8250210C"))) PPC_WEAK_FUNC(sub_8250210C);
PPC_FUNC_IMPL(__imp__sub_8250210C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82502110"))) PPC_WEAK_FUNC(sub_82502110);
PPC_FUNC_IMPL(__imp__sub_82502110) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x8250216c
	if (!cr6.gt) goto loc_8250216C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x82502154
	if (!cr6.lt) goto loc_82502154;
	// bl 0x823dcb30
	ctx.lr = 0x82502140;
	sub_823DCB30(ctx, base);
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
loc_82502154:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8250216C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14980(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14980);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82502184"))) PPC_WEAK_FUNC(sub_82502184);
PPC_FUNC_IMPL(__imp__sub_82502184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82502188"))) PPC_WEAK_FUNC(sub_82502188);
PPC_FUNC_IMPL(__imp__sub_82502188) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,31652
	ctx.r3.s64 = r11.s64 + 31652;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82502194"))) PPC_WEAK_FUNC(sub_82502194);
PPC_FUNC_IMPL(__imp__sub_82502194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82502198"))) PPC_WEAK_FUNC(sub_82502198);
PPC_FUNC_IMPL(__imp__sub_82502198) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,208
	ctx.r3.s64 = ctx.r3.s64 + 208;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825021A0"))) PPC_WEAK_FUNC(sub_825021A0);
PPC_FUNC_IMPL(__imp__sub_825021A0) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r10,31476
	ctx.r7.s64 = ctx.r10.s64 + 31476;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// li r30,0
	r30.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r5,r6,31668
	ctx.r5.s64 = ctx.r6.s64 + 31668;
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x8260b730
	ctx.lr = 0x825021F4;
	sub_8260B730(ctx, base);
	// stb r30,904(r31)
	PPC_STORE_U8(r31.u32 + 904, r30.u8);
	// stb r30,905(r31)
	PPC_STORE_U8(r31.u32 + 905, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,906(r31)
	PPC_STORE_U8(r31.u32 + 906, r30.u8);
	// stb r30,907(r31)
	PPC_STORE_U8(r31.u32 + 907, r30.u8);
	// stb r30,908(r31)
	PPC_STORE_U8(r31.u32 + 908, r30.u8);
	// stw r30,912(r31)
	PPC_STORE_U32(r31.u32 + 912, r30.u32);
	// stb r30,916(r31)
	PPC_STORE_U8(r31.u32 + 916, r30.u8);
	// stb r30,917(r31)
	PPC_STORE_U8(r31.u32 + 917, r30.u8);
	// stb r30,918(r31)
	PPC_STORE_U8(r31.u32 + 918, r30.u8);
	// stb r30,919(r31)
	PPC_STORE_U8(r31.u32 + 919, r30.u8);
	// stb r30,920(r31)
	PPC_STORE_U8(r31.u32 + 920, r30.u8);
	// stw r30,924(r31)
	PPC_STORE_U32(r31.u32 + 924, r30.u32);
	// stb r30,928(r31)
	PPC_STORE_U8(r31.u32 + 928, r30.u8);
	// stb r30,929(r31)
	PPC_STORE_U8(r31.u32 + 929, r30.u8);
	// stb r30,930(r31)
	PPC_STORE_U8(r31.u32 + 930, r30.u8);
	// stb r30,931(r31)
	PPC_STORE_U8(r31.u32 + 931, r30.u8);
	// stb r30,932(r31)
	PPC_STORE_U8(r31.u32 + 932, r30.u8);
	// stw r30,936(r31)
	PPC_STORE_U32(r31.u32 + 936, r30.u32);
	// stb r30,940(r31)
	PPC_STORE_U8(r31.u32 + 940, r30.u8);
	// stb r30,941(r31)
	PPC_STORE_U8(r31.u32 + 941, r30.u8);
	// stb r30,942(r31)
	PPC_STORE_U8(r31.u32 + 942, r30.u8);
	// stb r30,943(r31)
	PPC_STORE_U8(r31.u32 + 943, r30.u8);
	// stb r30,944(r31)
	PPC_STORE_U8(r31.u32 + 944, r30.u8);
	// stw r30,948(r31)
	PPC_STORE_U32(r31.u32 + 948, r30.u32);
	// stb r30,952(r31)
	PPC_STORE_U8(r31.u32 + 952, r30.u8);
	// stb r30,953(r31)
	PPC_STORE_U8(r31.u32 + 953, r30.u8);
	// stb r30,954(r31)
	PPC_STORE_U8(r31.u32 + 954, r30.u8);
	// stb r30,955(r31)
	PPC_STORE_U8(r31.u32 + 955, r30.u8);
	// stb r30,956(r31)
	PPC_STORE_U8(r31.u32 + 956, r30.u8);
	// stw r30,960(r31)
	PPC_STORE_U32(r31.u32 + 960, r30.u32);
	// stb r30,964(r31)
	PPC_STORE_U8(r31.u32 + 964, r30.u8);
	// stb r30,965(r31)
	PPC_STORE_U8(r31.u32 + 965, r30.u8);
	// stb r30,966(r31)
	PPC_STORE_U8(r31.u32 + 966, r30.u8);
	// stb r30,967(r31)
	PPC_STORE_U8(r31.u32 + 967, r30.u8);
	// stb r30,968(r31)
	PPC_STORE_U8(r31.u32 + 968, r30.u8);
	// stw r30,972(r31)
	PPC_STORE_U32(r31.u32 + 972, r30.u32);
	// stb r30,976(r31)
	PPC_STORE_U8(r31.u32 + 976, r30.u8);
	// stb r30,977(r31)
	PPC_STORE_U8(r31.u32 + 977, r30.u8);
	// stb r30,978(r31)
	PPC_STORE_U8(r31.u32 + 978, r30.u8);
	// stb r30,979(r31)
	PPC_STORE_U8(r31.u32 + 979, r30.u8);
	// stb r30,980(r31)
	PPC_STORE_U8(r31.u32 + 980, r30.u8);
	// stw r30,984(r31)
	PPC_STORE_U32(r31.u32 + 984, r30.u32);
	// stb r30,988(r31)
	PPC_STORE_U8(r31.u32 + 988, r30.u8);
	// stb r30,989(r31)
	PPC_STORE_U8(r31.u32 + 989, r30.u8);
	// stb r30,990(r31)
	PPC_STORE_U8(r31.u32 + 990, r30.u8);
	// stb r30,991(r31)
	PPC_STORE_U8(r31.u32 + 991, r30.u8);
	// stb r30,992(r31)
	PPC_STORE_U8(r31.u32 + 992, r30.u8);
	// stw r30,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r30.u32);
	// stb r30,1000(r31)
	PPC_STORE_U8(r31.u32 + 1000, r30.u8);
	// stb r30,1001(r31)
	PPC_STORE_U8(r31.u32 + 1001, r30.u8);
	// stb r30,1002(r31)
	PPC_STORE_U8(r31.u32 + 1002, r30.u8);
	// stb r30,1003(r31)
	PPC_STORE_U8(r31.u32 + 1003, r30.u8);
	// stb r30,1004(r31)
	PPC_STORE_U8(r31.u32 + 1004, r30.u8);
	// stw r30,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, r30.u32);
	// bl 0x82536358
	ctx.lr = 0x825022D4;
	sub_82536358(ctx, base);
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

__attribute__((alias("__imp__sub_825022F0"))) PPC_WEAK_FUNC(sub_825022F0);
PPC_FUNC_IMPL(__imp__sub_825022F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,31720
	ctx.r3.s64 = r11.s64 + 31720;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825022FC"))) PPC_WEAK_FUNC(sub_825022FC);
PPC_FUNC_IMPL(__imp__sub_825022FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82502300"))) PPC_WEAK_FUNC(sub_82502300);
PPC_FUNC_IMPL(__imp__sub_82502300) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82502308"))) PPC_WEAK_FUNC(sub_82502308);
PPC_FUNC_IMPL(__imp__sub_82502308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,96
	ctx.r7.s64 = 96;
	// lvx128 v62,r4,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,80
	ctx.r6.s64 = 80;
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,112
	r31.s64 = 112;
	// lfs f0,-12524(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -12524);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v59,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r3,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r3,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82502378"))) PPC_WEAK_FUNC(sub_82502378);
PPC_FUNC_IMPL(__imp__sub_82502378) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v63{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r10,31476
	ctx.r7.s64 = ctx.r10.s64 + 31476;
	// li r6,0
	ctx.r6.s64 = 0;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stb r6,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r6.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r5,31736
	ctx.r4.s64 = ctx.r5.s64 + 31736;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f2,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f4.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// lfs f3,27552(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27552);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x82536e48
	ctx.lr = 0x825023E0;
	sub_82536E48(ctx, base);
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

__attribute__((alias("__imp__sub_825023F8"))) PPC_WEAK_FUNC(sub_825023F8);
PPC_FUNC_IMPL(__imp__sub_825023F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,31788
	ctx.r3.s64 = r11.s64 + 31788;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82502404"))) PPC_WEAK_FUNC(sub_82502404);
PPC_FUNC_IMPL(__imp__sub_82502404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82502408"))) PPC_WEAK_FUNC(sub_82502408);
PPC_FUNC_IMPL(__imp__sub_82502408) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,176
	ctx.r3.s64 = ctx.r3.s64 + 176;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82502410"))) PPC_WEAK_FUNC(sub_82502410);
PPC_FUNC_IMPL(__imp__sub_82502410) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r10,31476
	ctx.r7.s64 = ctx.r10.s64 + 31476;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// li r30,0
	r30.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r5,r6,31804
	ctx.r5.s64 = ctx.r6.s64 + 31804;
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// bl 0x8260b730
	ctx.lr = 0x82502464;
	sub_8260B730(ctx, base);
	// stb r30,1048(r31)
	PPC_STORE_U8(r31.u32 + 1048, r30.u8);
	// stb r30,1049(r31)
	PPC_STORE_U8(r31.u32 + 1049, r30.u8);
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// stb r30,1050(r31)
	PPC_STORE_U8(r31.u32 + 1050, r30.u8);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r30,1051(r31)
	PPC_STORE_U8(r31.u32 + 1051, r30.u8);
	// addi r10,r4,2256
	ctx.r10.s64 = ctx.r4.s64 + 2256;
	// stb r30,1052(r31)
	PPC_STORE_U8(r31.u32 + 1052, r30.u8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, r30.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r30,1060(r31)
	PPC_STORE_U8(r31.u32 + 1060, r30.u8);
	// stb r30,1061(r31)
	PPC_STORE_U8(r31.u32 + 1061, r30.u8);
	// stb r30,1062(r31)
	PPC_STORE_U8(r31.u32 + 1062, r30.u8);
	// stb r30,1063(r31)
	PPC_STORE_U8(r31.u32 + 1063, r30.u8);
	// stb r30,1064(r31)
	PPC_STORE_U8(r31.u32 + 1064, r30.u8);
	// stw r30,1068(r31)
	PPC_STORE_U32(r31.u32 + 1068, r30.u32);
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
	// stw r30,1080(r31)
	PPC_STORE_U32(r31.u32 + 1080, r30.u32);
	// stb r30,1084(r31)
	PPC_STORE_U8(r31.u32 + 1084, r30.u8);
	// stb r30,1085(r31)
	PPC_STORE_U8(r31.u32 + 1085, r30.u8);
	// stb r30,1086(r31)
	PPC_STORE_U8(r31.u32 + 1086, r30.u8);
	// stb r30,1087(r31)
	PPC_STORE_U8(r31.u32 + 1087, r30.u8);
	// stb r30,1088(r31)
	PPC_STORE_U8(r31.u32 + 1088, r30.u8);
	// stw r30,1092(r31)
	PPC_STORE_U32(r31.u32 + 1092, r30.u32);
	// stb r30,1096(r31)
	PPC_STORE_U8(r31.u32 + 1096, r30.u8);
	// stb r30,1097(r31)
	PPC_STORE_U8(r31.u32 + 1097, r30.u8);
	// stb r30,1098(r31)
	PPC_STORE_U8(r31.u32 + 1098, r30.u8);
	// stb r30,1099(r31)
	PPC_STORE_U8(r31.u32 + 1099, r30.u8);
	// stb r30,1100(r31)
	PPC_STORE_U8(r31.u32 + 1100, r30.u8);
	// stw r30,1104(r31)
	PPC_STORE_U32(r31.u32 + 1104, r30.u32);
	// stb r30,1108(r31)
	PPC_STORE_U8(r31.u32 + 1108, r30.u8);
	// stb r30,1109(r31)
	PPC_STORE_U8(r31.u32 + 1109, r30.u8);
	// stb r30,1110(r31)
	PPC_STORE_U8(r31.u32 + 1110, r30.u8);
	// stb r30,1111(r31)
	PPC_STORE_U8(r31.u32 + 1111, r30.u8);
	// stb r30,1112(r31)
	PPC_STORE_U8(r31.u32 + 1112, r30.u8);
	// stw r30,1116(r31)
	PPC_STORE_U32(r31.u32 + 1116, r30.u32);
	// stb r30,1120(r31)
	PPC_STORE_U8(r31.u32 + 1120, r30.u8);
	// stb r30,1121(r31)
	PPC_STORE_U8(r31.u32 + 1121, r30.u8);
	// stb r30,1122(r31)
	PPC_STORE_U8(r31.u32 + 1122, r30.u8);
	// stb r30,1123(r31)
	PPC_STORE_U8(r31.u32 + 1123, r30.u8);
	// stb r30,1124(r31)
	PPC_STORE_U8(r31.u32 + 1124, r30.u8);
	// stw r30,1128(r31)
	PPC_STORE_U32(r31.u32 + 1128, r30.u32);
	// stb r30,1132(r31)
	PPC_STORE_U8(r31.u32 + 1132, r30.u8);
	// stb r30,1133(r31)
	PPC_STORE_U8(r31.u32 + 1133, r30.u8);
	// stb r30,1134(r31)
	PPC_STORE_U8(r31.u32 + 1134, r30.u8);
	// stb r30,1135(r31)
	PPC_STORE_U8(r31.u32 + 1135, r30.u8);
	// stb r30,1136(r31)
	PPC_STORE_U8(r31.u32 + 1136, r30.u8);
	// stw r30,1140(r31)
	PPC_STORE_U32(r31.u32 + 1140, r30.u32);
	// stb r30,1144(r31)
	PPC_STORE_U8(r31.u32 + 1144, r30.u8);
	// stb r30,1145(r31)
	PPC_STORE_U8(r31.u32 + 1145, r30.u8);
	// stb r30,1146(r31)
	PPC_STORE_U8(r31.u32 + 1146, r30.u8);
	// stb r30,1147(r31)
	PPC_STORE_U8(r31.u32 + 1147, r30.u8);
	// stb r30,1148(r31)
	PPC_STORE_U8(r31.u32 + 1148, r30.u8);
	// stw r30,1152(r31)
	PPC_STORE_U32(r31.u32 + 1152, r30.u32);
	// stb r30,1156(r31)
	PPC_STORE_U8(r31.u32 + 1156, r30.u8);
	// stb r30,1157(r31)
	PPC_STORE_U8(r31.u32 + 1157, r30.u8);
	// stb r30,1158(r31)
	PPC_STORE_U8(r31.u32 + 1158, r30.u8);
	// stb r30,1159(r31)
	PPC_STORE_U8(r31.u32 + 1159, r30.u8);
	// stb r30,1160(r31)
	PPC_STORE_U8(r31.u32 + 1160, r30.u8);
	// stw r30,1164(r31)
	PPC_STORE_U32(r31.u32 + 1164, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,17032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825375c0
	ctx.lr = 0x82502580;
	sub_825375C0(ctx, base);
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

__attribute__((alias("__imp__sub_8250259C"))) PPC_WEAK_FUNC(sub_8250259C);
PPC_FUNC_IMPL(__imp__sub_8250259C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825025A0"))) PPC_WEAK_FUNC(sub_825025A0);
PPC_FUNC_IMPL(__imp__sub_825025A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,31856
	ctx.r3.s64 = r11.s64 + 31856;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825025AC"))) PPC_WEAK_FUNC(sub_825025AC);
PPC_FUNC_IMPL(__imp__sub_825025AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825025B0"))) PPC_WEAK_FUNC(sub_825025B0);
PPC_FUNC_IMPL(__imp__sub_825025B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r10,r30,32
	ctx.r10.s64 = r30.s64 + 32;
	// li r7,32
	ctx.r7.s64 = 32;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r30,48
	ctx.r9.s64 = r30.s64 + 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,48
	ctx.r6.s64 = 48;
	// lvx128 v62,r30,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stb r5,100(r31)
	PPC_STORE_U8(r31.u32 + 100, ctx.r5.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82502630
	if (cr6.eq) goto loc_82502630;
	// addi r8,r31,256
	ctx.r8.s64 = r31.s64 + 256;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82502630:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	f0.f64 = double(temp.f32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r7,80
	ctx.r7.s64 = 80;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,60(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v56,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82502110
	ctx.lr = 0x82502674;
	sub_82502110(ctx, base);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// stfs f1,56(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82502694
	if (cr6.eq) goto loc_82502694;
	// lfs f0,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x825026a8
	if (!cr6.lt) goto loc_825026A8;
	// b 0x825026a0
	goto loc_825026A0;
loc_82502694:
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x825026a8
	if (!cr6.gt) goto loc_825026A8;
loc_825026A0:
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
loc_825026A8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825026c0
	if (cr6.eq) goto loc_825026C0;
	// lfs f1,40(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82502110
	ctx.lr = 0x825026B8;
	sub_82502110(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// b 0x825026e0
	goto loc_825026E0;
loc_825026C0:
	// lfs f1,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82502110
	ctx.lr = 0x825026C8;
	sub_82502110(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// lfs f13,36(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x825026e4
	if (!cr6.gt) goto loc_825026E4;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
loc_825026E0:
	// stfs f0,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
loc_825026E4:
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

__attribute__((alias("__imp__sub_82502700"))) PPC_WEAK_FUNC(sub_82502700);
PPC_FUNC_IMPL(__imp__sub_82502700) {
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
	ctx.lr = 0x82502708;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lfs f0,15360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.f13.u64);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// rlwinm r7,r8,24,0,7
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF000000;
	// oris r30,r7,255
	r30.u64 = ctx.r7.u64 | 16711680;
	// ori r30,r30,65535
	r30.u64 = r30.u64 | 65535;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82502750;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82502764;
	sub_82501DD8(ctx, base);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r5,40(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8250277C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825027a8
	if (cr6.eq) goto loc_825027A8;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82502788:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82502788
	if (!cr6.eq) goto loc_82502788;
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// b 0x825027ac
	goto loc_825027AC;
loc_825027A8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_825027AC:
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// neg r9,r11
	ctx.r9.s64 = -r11.s64;
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825027BC;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x825027f0
	if (!cr6.gt) goto loc_825027F0;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// li r9,45
	ctx.r9.s64 = 45;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825027f0
	if (cr6.eq) goto loc_825027F0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_825027E4:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x825027e4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_825027E4;
loc_825027F0:
	// li r11,0
	r11.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stbx r11,r5,r10
	PPC_STORE_U8(ctx.r5.u32 + ctx.r10.u32, r11.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82502808;
	sub_82501DD8(ctx, base);
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82502810"))) PPC_WEAK_FUNC(sub_82502810);
PPC_FUNC_IMPL(__imp__sub_82502810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// addi r11,r3,112
	r11.s64 = ctx.r3.s64 + 112;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// li r9,32
	ctx.r9.s64 = 32;
	// li r6,48
	ctx.r6.s64 = 48;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lvx128 v60,r4,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,2384
	ctx.r3.s64 = ctx.r5.s64 + 2384;
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r11,48
	ctx.r7.s64 = r11.s64 + 48;
	// lvx128 v59,r4,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// stvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r4,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r5,2352
	ctx.r4.s64 = ctx.r5.s64 + 2352;
	// stvx128 v58,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v51,v57,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v52,v53,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vor128 v55,v56,v56
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vmrglw128 v49,v53,v54
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrglw128 v47,v57,v56
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v45,v52,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmsum3fp128 v50,v54,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmrglw128 v44,v52,v51
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmsum3fp128 v48,v53,v55
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmrghw128 v43,v49,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmsum3fp128 v46,v57,v55
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vand128 v42,v45,v63
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v42,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v41,v44,v63
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v41,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v40,v48,v50
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v39,v43,v63
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v39,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v38,v46,v40
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v37,v40,v38
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vsubfp128 v36,v61,v37
	simde_mm_store_ps(v36.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v37.f32)));
	// vand128 v35,v36,v63
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v34,v62,v35
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v35.u8)));
	// stvx128 v34,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825028E4"))) PPC_WEAK_FUNC(sub_825028E4);
PPC_FUNC_IMPL(__imp__sub_825028E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825028E8"))) PPC_WEAK_FUNC(sub_825028E8);
PPC_FUNC_IMPL(__imp__sub_825028E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
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
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r3,176
	r11.s64 = ctx.r3.s64 + 176;
	// li r4,16
	ctx.r4.s64 = 16;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r11,48
	ctx.r8.s64 = r11.s64 + 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r11,16
	ctx.r6.s64 = r11.s64 + 16;
	// lvx128 v61,r31,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r11,32
	ctx.r7.s64 = r11.s64 + 32;
	// stvx128 v61,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lvx128 v60,r31,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r31,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r10,48
	ctx.r9.s64 = ctx.r10.s64 + 48;
	// lvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v53,v57,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v54,v55,v56
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrglw128 v52,v57,v58
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v51,v55,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v50,v53,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrglw128 v49,v53,v54
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v48,v52,v51
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// stvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r10,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r0,r7
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r6
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v42,v47,v45
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// vmsum3fp128 v43,v44,v45
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// vmsum3fp128 v41,v46,v45
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// vmrghw128 v40,v42,v43
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v39,v41,v40
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v38,v40,v39
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vor128 v37,v38,v38
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
	// stvx128 v38,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v36,v62,v37
	simde_mm_store_ps(v36.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v37.f32)));
	// stvx128 v36,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825029B0"))) PPC_WEAK_FUNC(sub_825029B0);
PPC_FUNC_IMPL(__imp__sub_825029B0) {
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
	ctx.lr = 0x825029B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// addi r26,r30,44
	r26.s64 = r30.s64 + 44;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// bl 0x8260b730
	ctx.lr = 0x825029D8;
	sub_8260B730(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r31,820(r30)
	PPC_STORE_U8(r30.u32 + 820, r31.u8);
	// li r11,1
	r11.s64 = 1;
	// stb r31,821(r30)
	PPC_STORE_U8(r30.u32 + 821, r31.u8);
	// li r3,1072
	ctx.r3.s64 = 1072;
	// stb r31,822(r30)
	PPC_STORE_U8(r30.u32 + 822, r31.u8);
	// addi r29,r30,820
	r29.s64 = r30.s64 + 820;
	// stb r31,823(r30)
	PPC_STORE_U8(r30.u32 + 823, r31.u8);
	// addi r28,r30,832
	r28.s64 = r30.s64 + 832;
	// stb r31,824(r30)
	PPC_STORE_U8(r30.u32 + 824, r31.u8);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r31,828(r30)
	PPC_STORE_U32(r30.u32 + 828, r31.u32);
	// addi r27,r30,844
	r27.s64 = r30.s64 + 844;
	// stb r31,832(r30)
	PPC_STORE_U8(r30.u32 + 832, r31.u8);
	// stb r31,833(r30)
	PPC_STORE_U8(r30.u32 + 833, r31.u8);
	// stb r31,834(r30)
	PPC_STORE_U8(r30.u32 + 834, r31.u8);
	// stb r31,835(r30)
	PPC_STORE_U8(r30.u32 + 835, r31.u8);
	// stb r31,836(r30)
	PPC_STORE_U8(r30.u32 + 836, r31.u8);
	// stw r31,840(r30)
	PPC_STORE_U32(r30.u32 + 840, r31.u32);
	// stb r31,844(r30)
	PPC_STORE_U8(r30.u32 + 844, r31.u8);
	// stb r31,845(r30)
	PPC_STORE_U8(r30.u32 + 845, r31.u8);
	// stb r31,846(r30)
	PPC_STORE_U8(r30.u32 + 846, r31.u8);
	// stb r31,847(r30)
	PPC_STORE_U8(r30.u32 + 847, r31.u8);
	// stb r31,848(r30)
	PPC_STORE_U8(r30.u32 + 848, r31.u8);
	// stw r31,852(r30)
	PPC_STORE_U32(r30.u32 + 852, r31.u32);
	// stfs f0,860(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 860, temp.u32);
	// stb r11,856(r30)
	PPC_STORE_U8(r30.u32 + 856, r11.u8);
	// stb r11,857(r30)
	PPC_STORE_U8(r30.u32 + 857, r11.u8);
	// stb r31,864(r30)
	PPC_STORE_U8(r30.u32 + 864, r31.u8);
	// bl 0x82130528
	ctx.lr = 0x82502A50;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502a60
	if (cr6.eq) goto loc_82502A60;
	// bl 0x8253a398
	ctx.lr = 0x82502A5C;
	sub_8253A398(ctx, base);
	// b 0x82502a64
	goto loc_82502A64;
loc_82502A60:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82502A64:
	// stw r3,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r3.u32);
	// li r3,224
	ctx.r3.s64 = 224;
	// bl 0x82130528
	ctx.lr = 0x82502A70;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502a80
	if (cr6.eq) goto loc_82502A80;
	// bl 0x82539bb8
	ctx.lr = 0x82502A7C;
	sub_82539BB8(ctx, base);
	// b 0x82502a84
	goto loc_82502A84;
loc_82502A80:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82502A84:
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82502A90;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502aa0
	if (cr6.eq) goto loc_82502AA0;
	// bl 0x82501ef0
	ctx.lr = 0x82502A9C;
	sub_82501EF0(ctx, base);
	// b 0x82502aa4
	goto loc_82502AA4;
loc_82502AA0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82502AA4:
	// stw r3,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r3.u32);
	// li r3,1168
	ctx.r3.s64 = 1168;
	// bl 0x82130528
	ctx.lr = 0x82502AB0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502ac0
	if (cr6.eq) goto loc_82502AC0;
	// bl 0x82538df0
	ctx.lr = 0x82502ABC;
	sub_82538DF0(ctx, base);
	// b 0x82502ac4
	goto loc_82502AC4;
loc_82502AC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82502AC4:
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// li r3,1184
	ctx.r3.s64 = 1184;
	// bl 0x82130528
	ctx.lr = 0x82502AD0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502ae0
	if (cr6.eq) goto loc_82502AE0;
	// bl 0x82501f68
	ctx.lr = 0x82502ADC;
	sub_82501F68(ctx, base);
	// b 0x82502ae4
	goto loc_82502AE4;
loc_82502AE0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82502AE4:
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// li r3,1056
	ctx.r3.s64 = 1056;
	// bl 0x82130528
	ctx.lr = 0x82502AF0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502b00
	if (cr6.eq) goto loc_82502B00;
	// bl 0x825021a0
	ctx.lr = 0x82502AFC;
	sub_825021A0(ctx, base);
	// b 0x82502b04
	goto loc_82502B04;
loc_82502B00:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82502B04:
	// stw r3,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r3.u32);
	// li r3,416
	ctx.r3.s64 = 416;
	// bl 0x82130528
	ctx.lr = 0x82502B10;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502b20
	if (cr6.eq) goto loc_82502B20;
	// bl 0x82502378
	ctx.lr = 0x82502B1C;
	sub_82502378(ctx, base);
	// b 0x82502b24
	goto loc_82502B24;
loc_82502B20:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82502B24:
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
	// li r3,1184
	ctx.r3.s64 = 1184;
	// bl 0x82130528
	ctx.lr = 0x82502B30;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502b40
	if (cr6.eq) goto loc_82502B40;
	// bl 0x82502410
	ctx.lr = 0x82502B3C;
	sub_82502410(ctx, base);
	// b 0x82502b44
	goto loc_82502B44;
loc_82502B40:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82502B44:
	// stw r3,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r3.u32);
	// li r3,1168
	ctx.r3.s64 = 1168;
	// bl 0x82130528
	ctx.lr = 0x82502B50;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502b60
	if (cr6.eq) goto loc_82502B60;
	// bl 0x82537998
	ctx.lr = 0x82502B5C;
	sub_82537998(ctx, base);
	// b 0x82502b64
	goto loc_82502B64;
loc_82502B60:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82502B64:
	// stw r3,40(r30)
	PPC_STORE_U32(r30.u32 + 40, ctx.r3.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r31,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r31.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8260b740
	ctx.lr = 0x82502B84;
	sub_8260B740(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8260b740
	ctx.lr = 0x82502B9C;
	sub_8260B740(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,59
	ctx.r5.s64 = 59;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8260b740
	ctx.lr = 0x82502BB4;
	sub_8260B740(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,41
	ctx.r5.s64 = 41;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8260b740
	ctx.lr = 0x82502BCC;
	sub_8260B740(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8260b740
	ctx.lr = 0x82502BE4;
	sub_8260B740(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8260b740
	ctx.lr = 0x82502BFC;
	sub_8260B740(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82502C08"))) PPC_WEAK_FUNC(sub_82502C08);
PPC_FUNC_IMPL(__imp__sub_82502C08) {
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
	ctx.lr = 0x82502C10;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,8
	r31.s64 = ctx.r3.s64 + 8;
	// li r30,9
	r30.s64 = 9;
	// li r29,0
	r29.s64 = 0;
loc_82502C20:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82502c40
	if (cr6.eq) goto loc_82502C40;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82502C40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82502C40:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82502c20
	if (!cr0.eq) goto loc_82502C20;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82502C58"))) PPC_WEAK_FUNC(sub_82502C58);
PPC_FUNC_IMPL(__imp__sub_82502C58) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82502C60;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r10,32540
	ctx.r3.s64 = ctx.r10.s64 + 32540;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c0828
	ctx.lr = 0x82502C90;
	sub_821C0828(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82502cb0
	if (!cr6.eq) goto loc_82502CB0;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
loc_82502CB0:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r31,r11,32520
	r31.s64 = r11.s64 + 32520;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c0828
	ctx.lr = 0x82502CD4;
	sub_821C0828(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82502d04
	if (!cr6.eq) goto loc_82502D04;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821c0828
	ctx.lr = 0x82502CEC;
	sub_821C0828(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_82502D04:
	// addi r30,r29,8
	r30.s64 = r29.s64 + 8;
	// li r31,9
	r31.s64 = 9;
loc_82502D0C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82502D28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82502d0c
	if (!cr0.eq) goto loc_82502D0C;
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82502D44"))) PPC_WEAK_FUNC(sub_82502D44);
PPC_FUNC_IMPL(__imp__sub_82502D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82502D48"))) PPC_WEAK_FUNC(sub_82502D48);
PPC_FUNC_IMPL(__imp__sub_82502D48) {
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
	ctx.lr = 0x82502D50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,860(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x82502e0c
	if (cr6.eq) goto loc_82502E0C;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82502D90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,48(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82502DB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r3,-32115
	ctx.r3.s64 = -2104688640;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// addi r11,r3,32500
	r11.s64 = ctx.r3.s64 + 32500;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82502dec
	if (!cr6.eq) goto loc_82502DEC;
	// addi r11,r30,2
	r11.s64 = r30.s64 + 2;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82502DEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82502DEC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82502E0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82502E0C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82502E14"))) PPC_WEAK_FUNC(sub_82502E14);
PPC_FUNC_IMPL(__imp__sub_82502E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82502E18"))) PPC_WEAK_FUNC(sub_82502E18);
PPC_FUNC_IMPL(__imp__sub_82502E18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// lfs f31,92(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	f31.f64 = double(temp.f32);
	// bl 0x8260b990
	ctx.lr = 0x82502E4C;
	sub_8260B990(ctx, base);
	// lbz r9,856(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 856);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82502eb8
	if (!cr6.eq) goto loc_82502EB8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,860(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 860);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fnmsubs f0,f31,f0,f13
	f0.f64 = double(float(-(f31.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f0,860(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
	// lbz r10,822(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 822);
	// lbz r9,820(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 820);
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// subfic r6,r7,127
	xer.ca = ctx.r7.u32 <= 127;
	ctx.r6.s64 = 127 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82502ea0
	if (cr6.eq) goto loc_82502EA0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,860(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
	// b 0x8250305c
	goto loc_8250305C;
loc_82502EA0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8250305c
	if (!cr6.lt) goto loc_8250305C;
	// stfs f13,860(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
	// b 0x8250305c
	goto loc_8250305C;
loc_82502EB8:
	// lbz r11,844(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 844);
	// lbz r10,846(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 846);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82502f00
	if (cr6.eq) goto loc_82502F00;
	// lbz r10,847(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 847);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82502f04
	if (cr6.eq) goto loc_82502F04;
loc_82502F00:
	// li r11,0
	r11.s64 = 0;
loc_82502F04:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f30,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// beq cr6,0x82502f3c
	if (cr6.eq) goto loc_82502F3C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f30,860(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82502F3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82502F3C:
	// lbz r11,832(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 832);
	// lbz r10,834(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 834);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82502f84
	if (cr6.eq) goto loc_82502F84;
	// lbz r10,835(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 835);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82502f88
	if (cr6.eq) goto loc_82502F88;
loc_82502F84:
	// li r11,0
	r11.s64 = 0;
loc_82502F88:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82502fc8
	if (cr6.eq) goto loc_82502FC8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,14563
	ctx.r10.s64 = 954400768;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// ori r8,r10,36409
	ctx.r8.u64 = ctx.r10.u64 | 36409;
	// mulhw r7,r9,r8
	ctx.r7.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32)) >> 32;
	// srawi r11,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r11.s64 = ctx.r7.s32 >> 1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// subf r4,r6,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r6.s64;
	// bl 0x82502d48
	ctx.lr = 0x82502FC8;
	sub_82502D48(ctx, base);
loc_82502FC8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,860(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 860);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fnmsubs f0,f31,f0,f13
	f0.f64 = double(float(-(f31.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f0,860(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
	// lbz r10,822(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 822);
	// lbz r9,820(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 820);
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// subfic r6,r7,127
	xer.ca = ctx.r7.u32 <= 127;
	ctx.r6.s64 = 127 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82503008
	if (cr6.eq) goto loc_82503008;
	// stfs f30,860(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
	// b 0x8250301c
	goto loc_8250301C;
loc_82503008:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8250301c
	if (!cr6.lt) goto loc_8250301C;
	// stfs f13,860(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
loc_8250301C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82503040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8250305c
	if (cr6.eq) goto loc_8250305C;
	// lbz r11,857(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 857);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8250305c
	if (cr6.eq) goto loc_8250305C;
	// stfs f30,860(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
loc_8250305C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82503078"))) PPC_WEAK_FUNC(sub_82503078);
PPC_FUNC_IMPL(__imp__sub_82503078) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x825030c0
	if (cr6.eq) goto loc_825030C0;
	// bl 0x821be710
	ctx.lr = 0x825030BC;
	sub_821BE710(ctx, base);
	// b 0x825030c4
	goto loc_825030C4;
loc_825030C0:
	// bl 0x821be7e8
	ctx.lr = 0x825030C4;
	sub_821BE7E8(ctx, base);
loc_825030C4:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x825030f4
	if (cr6.eq) goto loc_825030F4;
	// bl 0x821be710
	ctx.lr = 0x825030F0;
	sub_821BE710(ctx, base);
	// b 0x825030f8
	goto loc_825030F8;
loc_825030F4:
	// bl 0x821be7e8
	ctx.lr = 0x825030F8;
	sub_821BE7E8(ctx, base);
loc_825030F8:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82503128
	if (cr6.eq) goto loc_82503128;
	// bl 0x821be710
	ctx.lr = 0x82503124;
	sub_821BE710(ctx, base);
	// b 0x8250312c
	goto loc_8250312C;
loc_82503128:
	// bl 0x821be7e8
	ctx.lr = 0x8250312C;
	sub_821BE7E8(ctx, base);
loc_8250312C:
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

__attribute__((alias("__imp__sub_82503144"))) PPC_WEAK_FUNC(sub_82503144);
PPC_FUNC_IMPL(__imp__sub_82503144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503148"))) PPC_WEAK_FUNC(sub_82503148);
PPC_FUNC_IMPL(__imp__sub_82503148) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lwz r3,-32560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32560);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82503190
	if (!cr6.eq) goto loc_82503190;
	// li r3,52
	ctx.r3.s64 = 52;
	// bl 0x82130528
	ctx.lr = 0x82503170;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82503188
	if (cr6.eq) goto loc_82503188;
	// li r5,4
	ctx.r5.s64 = 4;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// bl 0x8253b0d8
	ctx.lr = 0x82503184;
	sub_8253B0D8(ctx, base);
	// b 0x8250318c
	goto loc_8250318C;
loc_82503188:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8250318C:
	// stw r3,-32560(r31)
	PPC_STORE_U32(r31.u32 + -32560, ctx.r3.u32);
loc_82503190:
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

__attribute__((alias("__imp__sub_825031A4"))) PPC_WEAK_FUNC(sub_825031A4);
PPC_FUNC_IMPL(__imp__sub_825031A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825031A8"))) PPC_WEAK_FUNC(sub_825031A8);
PPC_FUNC_IMPL(__imp__sub_825031A8) {
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
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// beq cr6,0x82503228
	if (cr6.eq) goto loc_82503228;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fdivs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 / ctx.f13.f64));
	// fmadds f8,f9,f1,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f1.f64 + f0.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f31,f5
	f31.f64 = double(float(ctx.f5.f64));
	// b 0x8250324c
	goto loc_8250324C;
loc_82503228:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
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
	// fdivs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 / f0.f64));
	// fmuls f31,f10,f1
	f31.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
loc_8250324C:
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82503264
	if (cr6.eq) goto loc_82503264;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825284d0
	ctx.lr = 0x82503264;
	sub_825284D0(ctx, base);
loc_82503264:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fdivs f1,f13,f10
	ctx.f1.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// bl 0x82528508
	ctx.lr = 0x8250329C;
	sub_82528508(ctx, base);
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

__attribute__((alias("__imp__sub_825032B8"))) PPC_WEAK_FUNC(sub_825032B8);
PPC_FUNC_IMPL(__imp__sub_825032B8) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lbz r11,32560(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 32560);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825032e4
	if (!cr6.eq) goto loc_825032E4;
	// bl 0x8253c440
	ctx.lr = 0x825032DC;
	sub_8253C440(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,32560(r31)
	PPC_STORE_U8(r31.u32 + 32560, r11.u8);
loc_825032E4:
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

__attribute__((alias("__imp__sub_825032F8"))) PPC_WEAK_FUNC(sub_825032F8);
PPC_FUNC_IMPL(__imp__sub_825032F8) {
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
	// bl 0x8253c3a0
	ctx.lr = 0x82503308;
	sub_8253C3A0(ctx, base);
	// bl 0x8253b278
	ctx.lr = 0x8250330C;
	sub_8253B278(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8250331C"))) PPC_WEAK_FUNC(sub_8250331C);
PPC_FUNC_IMPL(__imp__sub_8250331C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503320"))) PPC_WEAK_FUNC(sub_82503320);
PPC_FUNC_IMPL(__imp__sub_82503320) {
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
	// li r9,84
	ctx.r9.s64 = 84;
	// lwzx r10,r11,r9
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82503388
	if (cr6.eq) goto loc_82503388;
	// cmplwi cr6,r4,8
	cr6.compare<uint32_t>(ctx.r4.u32, 8, xer);
	// ble cr6,0x8250335c
	if (!cr6.gt) goto loc_8250335C;
	// li r8,88
	ctx.r8.s64 = 88;
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82503388
	if (cr6.eq) goto loc_82503388;
loc_8250335C:
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// li r8,100
	ctx.r8.s64 = 100;
	// rlwinm r31,r10,0,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// add r10,r31,r4
	ctx.r10.u64 = r31.u64 + ctx.r4.u64;
	// lwzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// stwx r10,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r10.u32);
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// ble cr6,0x825034c0
	if (!cr6.gt) goto loc_825034C0;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,32224
	ctx.r3.s64 = r11.s64 + 32224;
	// b 0x825034bc
	goto loc_825034BC;
loc_82503388:
	// cmplwi cr6,r4,8
	cr6.compare<uint32_t>(ctx.r4.u32, 8, xer);
	// bgt cr6,0x8250340c
	if (cr6.gt) goto loc_8250340C;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x825033c4
	if (cr6.gt) goto loc_825033C4;
	// li r10,92
	ctx.r10.s64 = 92;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825033c4
	if (cr6.eq) goto loc_825033C4;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
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
loc_825033C4:
	// li r8,96
	ctx.r8.s64 = 96;
	// lwzx r3,r11,r8
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8250340c
	if (cr6.eq) goto loc_8250340C;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x825033f0
	if (cr6.gt) goto loc_825033F0;
	// li r10,92
	ctx.r10.s64 = 92;
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// lwzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
loc_825033F0:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
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
loc_8250340C:
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x8250341c
	if (cr6.gt) goto loc_8250341C;
	// li r9,3
	ctx.r9.s64 = 3;
	// b 0x8250342c
	goto loc_8250342C;
loc_8250341C:
	// cmplwi cr6,r4,8
	cr6.compare<uint32_t>(ctx.r4.u32, 8, xer);
	// li r9,7
	ctx.r9.s64 = 7;
	// ble cr6,0x8250342c
	if (!cr6.gt) goto loc_8250342C;
	// addi r9,r5,-1
	ctx.r9.s64 = ctx.r5.s64 + -1;
loc_8250342C:
	// li r7,80
	ctx.r7.s64 = 80;
	// lwzx r10,r11,r7
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// andc r31,r8,r9
	r31.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// subf r9,r10,r31
	ctx.r9.s64 = r31.s64 - ctx.r10.s64;
	// stwx r31,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, r31.u32);
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// blt cr6,0x8250349c
	if (cr6.lt) goto loc_8250349C;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// cmplwi cr6,r9,12
	cr6.compare<uint32_t>(ctx.r9.u32, 12, xer);
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// blt cr6,0x82503480
	if (cr6.lt) goto loc_82503480;
	// li r8,92
	ctx.r8.s64 = 92;
	// li r9,96
	ctx.r9.s64 = 96;
	// lwzx r6,r11,r8
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// lwzx r5,r11,r9
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// b 0x82503498
	goto loc_82503498;
loc_82503480:
	// cmplwi cr6,r9,8
	cr6.compare<uint32_t>(ctx.r9.u32, 8, xer);
	// li r9,96
	ctx.r9.s64 = 96;
	// bge cr6,0x82503490
	if (!cr6.lt) goto loc_82503490;
	// li r9,92
	ctx.r9.s64 = 92;
loc_82503490:
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_82503498:
	// stwx r10,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r10.u32);
loc_8250349C:
	// li r9,104
	ctx.r9.s64 = 104;
	// add r10,r31,r4
	ctx.r10.u64 = r31.u64 + ctx.r4.u64;
	// stwx r10,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, ctx.r10.u32);
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// ble cr6,0x825034c0
	if (!cr6.gt) goto loc_825034C0;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,32204
	ctx.r3.s64 = r11.s64 + 32204;
loc_825034BC:
	// bl 0x821bd618
	ctx.lr = 0x825034C0;
	sub_821BD618(ctx, base);
loc_825034C0:
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

__attribute__((alias("__imp__sub_825034D8"))) PPC_WEAK_FUNC(sub_825034D8);
PPC_FUNC_IMPL(__imp__sub_825034D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,108
	ctx.r10.s64 = 108;
	// li r9,80
	ctx.r9.s64 = 80;
	// lwzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// subf r3,r8,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r8.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825034F4"))) PPC_WEAK_FUNC(sub_825034F4);
PPC_FUNC_IMPL(__imp__sub_825034F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825034F8"))) PPC_WEAK_FUNC(sub_825034F8);
PPC_FUNC_IMPL(__imp__sub_825034F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,80
	ctx.r10.s64 = 80;
	// li r9,104
	ctx.r9.s64 = 104;
	// lwzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// subf r3,r8,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r8.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82503514"))) PPC_WEAK_FUNC(sub_82503514);
PPC_FUNC_IMPL(__imp__sub_82503514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503518"))) PPC_WEAK_FUNC(sub_82503518);
PPC_FUNC_IMPL(__imp__sub_82503518) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,108
	ctx.r10.s64 = 108;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// blt cr6,0x82503540
	if (cr6.lt) goto loc_82503540;
	// li r10,80
	ctx.r10.s64 = 80;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// li r11,1
	r11.s64 = 1;
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// blt cr6,0x82503544
	if (cr6.lt) goto loc_82503544;
loc_82503540:
	// li r11,0
	r11.s64 = 0;
loc_82503544:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8250354C"))) PPC_WEAK_FUNC(sub_8250354C);
PPC_FUNC_IMPL(__imp__sub_8250354C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503550"))) PPC_WEAK_FUNC(sub_82503550);
PPC_FUNC_IMPL(__imp__sub_82503550) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,108
	ctx.r8.s64 = 108;
	// li r7,80
	ctx.r7.s64 = 80;
	// li r9,104
	ctx.r9.s64 = 104;
	// li r6,96
	ctx.r6.s64 = 96;
	// li r31,92
	r31.s64 = 92;
	// li r10,0
	ctx.r10.s64 = 0;
	// stwx r3,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r3.u32);
	// add r4,r3,r4
	ctx.r4.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stwx r3,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, ctx.r3.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stwx r4,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r4.u32);
	// stwx r10,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, ctx.r10.u32);
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// beq cr6,0x825035c4
	if (cr6.eq) goto loc_825035C4;
	// li r6,84
	ctx.r6.s64 = 84;
	// li r4,112
	ctx.r4.s64 = 112;
	// li r31,100
	r31.s64 = 100;
	// li r30,88
	r30.s64 = 88;
	// add r9,r3,r5
	ctx.r9.u64 = ctx.r3.u64 + ctx.r5.u64;
	// stwx r3,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, ctx.r3.u32);
	// stwx r3,r11,r4
	PPC_STORE_U32(r11.u32 + ctx.r4.u32, ctx.r3.u32);
	// stwx r9,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r9.u32);
	// stbx r10,r11,r30
	PPC_STORE_U8(r11.u32 + r30.u32, ctx.r10.u8);
	// stwx r9,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r9.u32);
	// stwx r9,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, ctx.r9.u32);
	// b 0x825035e4
	goto loc_825035E4;
loc_825035C4:
	// li r9,84
	ctx.r9.s64 = 84;
	// li r8,112
	ctx.r8.s64 = 112;
	// li r7,100
	ctx.r7.s64 = 100;
	// li r6,88
	ctx.r6.s64 = 88;
	// stwx r10,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r10.u32);
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// stwx r10,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, ctx.r10.u32);
	// stbx r10,r11,r6
	PPC_STORE_U8(r11.u32 + ctx.r6.u32, ctx.r10.u8);
loc_825035E4:
	// li r10,28
	ctx.r10.s64 = 28;
	// li r9,116
	ctx.r9.s64 = 116;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r7,r8,-992
	ctx.r7.s64 = ctx.r8.s64 + -992;
	// lwzx r6,r11,r10
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// stwx r6,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r6.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8250360C"))) PPC_WEAK_FUNC(sub_8250360C);
PPC_FUNC_IMPL(__imp__sub_8250360C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503610"))) PPC_WEAK_FUNC(sub_82503610);
PPC_FUNC_IMPL(__imp__sub_82503610) {
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
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r11,80
	r11.s64 = 80;
	// li r8,104
	ctx.r8.s64 = 104;
	// li r7,96
	ctx.r7.s64 = 96;
	// li r6,92
	ctx.r6.s64 = 92;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwzx r5,r31,r8
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// addi r4,r10,15
	ctx.r4.s64 = ctx.r10.s64 + 15;
	// stwx r9,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r9.u32);
	// stwx r9,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r9.u32);
	// rlwinm r3,r4,0,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFF0;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// cmplw cr6,r3,r5
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, xer);
	// ble cr6,0x82503668
	if (!cr6.gt) goto loc_82503668;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,32204
	ctx.r3.s64 = r11.s64 + 32204;
	// bl 0x821bd618
	ctx.lr = 0x82503668;
	sub_821BD618(ctx, base);
loc_82503668:
	// li r10,84
	ctx.r10.s64 = 84;
	// lwzx r11,r31,r10
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825036a0
	if (cr6.eq) goto loc_825036A0;
	// li r9,100
	ctx.r9.s64 = 100;
	// addi r8,r11,15
	ctx.r8.s64 = r11.s64 + 15;
	// rlwinm r7,r8,0,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// lwzx r6,r31,r9
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// stwx r7,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r7.u32);
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// ble cr6,0x825036a0
	if (!cr6.gt) goto loc_825036A0;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,32224
	ctx.r3.s64 = r11.s64 + 32224;
	// bl 0x821bd618
	ctx.lr = 0x825036A0;
	sub_821BD618(ctx, base);
loc_825036A0:
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

__attribute__((alias("__imp__sub_825036B4"))) PPC_WEAK_FUNC(sub_825036B4);
PPC_FUNC_IMPL(__imp__sub_825036B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825036B8"))) PPC_WEAK_FUNC(sub_825036B8);
PPC_FUNC_IMPL(__imp__sub_825036B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,88
	ctx.r10.s64 = 88;
	// stbx r3,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825036C8"))) PPC_WEAK_FUNC(sub_825036C8);
PPC_FUNC_IMPL(__imp__sub_825036C8) {
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
	ctx.lr = 0x825036D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,48
	r31.s64 = 48;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82503748
	if (cr6.eq) goto loc_82503748;
	// lhz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 24);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82503730
	if (!cr6.gt) goto loc_82503730;
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_82503700:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lhz r7,18(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8250371c
	if (cr6.eq) goto loc_8250371C;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// b 0x82503720
	goto loc_82503720;
loc_8250371C:
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
loc_82503720:
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82503700
	if (!cr0.eq) goto loc_82503700;
loc_82503730:
	// lhz r11,36(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 36);
	// addi r10,r8,5
	ctx.r10.s64 = ctx.r8.s64 + 5;
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// b 0x825037c0
	goto loc_825037C0;
loc_82503748:
	// lhz r11,36(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 36);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82503784
	if (cr6.eq) goto loc_82503784;
	// li r29,0
	r29.s64 = 0;
loc_8250375C:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8253b358
	ctx.lr = 0x82503768;
	sub_8253B358(ctx, base);
	// lhz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 36);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x8250375c
	if (cr6.lt) goto loc_8250375C;
loc_82503784:
	// lhz r11,24(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 24);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825037c0
	if (cr6.eq) goto loc_825037C0;
	// li r29,0
	r29.s64 = 0;
loc_82503798:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x8253a978
	ctx.lr = 0x825037A4;
	sub_8253A978(ctx, base);
	// lhz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 24);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x82503798
	if (cr6.lt) goto loc_82503798;
loc_825037C0:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825037fc
	if (cr6.eq) goto loc_825037FC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_825037D0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825037d0
	if (!cr6.eq) goto loc_825037D0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_825037FC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82503808"))) PPC_WEAK_FUNC(sub_82503808);
PPC_FUNC_IMPL(__imp__sub_82503808) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,36(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// li r7,0
	ctx.r7.s64 = 0;
	// addic. r8,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r8.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt 0x82503868
	if (cr0.lt) goto loc_82503868;
	// rlwimi r5,r4,16,8,15
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 16) & 0xFF0000) | (ctx.r5.u64 & 0xFFFFFFFFFF00FFFF);
	// clrlwi r5,r5,8
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFFFF;
loc_82503820:
	// add r11,r8,r7
	r11.u64 = ctx.r8.u64 + ctx.r7.u64;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,32(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lhz r4,2(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r9,r9,16
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 16);
	// or r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 | ctx.r4.u64;
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// beq cr6,0x82503874
	if (cr6.eq) goto loc_82503874;
	// ble cr6,0x8250385c
	if (!cr6.gt) goto loc_8250385C;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// b 0x82503860
	goto loc_82503860;
loc_8250385C:
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
loc_82503860:
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// ble cr6,0x82503820
	if (!cr6.gt) goto loc_82503820;
loc_82503868:
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82503874:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8250387C"))) PPC_WEAK_FUNC(sub_8250387C);
PPC_FUNC_IMPL(__imp__sub_8250387C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503880"))) PPC_WEAK_FUNC(sub_82503880);
PPC_FUNC_IMPL(__imp__sub_82503880) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8250393c
	if (cr6.eq) goto loc_8250393C;
	// lis r11,0
	r11.s64 = 0;
	// lwz r5,32(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// li r8,0
	ctx.r8.s64 = 0;
	// ori r9,r11,65535
	ctx.r9.u64 = r11.u64 | 65535;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_825038A4:
	// cmplwi cr6,r4,180
	cr6.compare<uint32_t>(ctx.r4.u32, 180, xer);
	// li r10,180
	ctx.r10.s64 = 180;
	// bgt cr6,0x825038b4
	if (cr6.gt) goto loc_825038B4;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_825038B4:
	// subf r4,r10,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r10.s64;
loc_825038B8:
	// rlwinm r7,r8,2,14,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r7,r7,r5
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// lbz r6,1(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// lbz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// ori r6,r6,128
	ctx.r6.u64 = ctx.r6.u64 | 128;
	// lhz r7,2(r7)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// rotlwi r3,r3,8
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 8);
	// or r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 | ctx.r3.u64;
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// bne 0x825038b8
	if (!cr0.eq) goto loc_825038B8;
	// rlwinm r7,r11,16,16,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// rlwinm r10,r9,16,16,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x825038a4
	if (!cr6.eq) goto loc_825038A4;
	// rlwinm r8,r9,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r11,16,16,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// rlwinm r9,r9,0,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFF0000;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// or r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 | ctx.r8.u64;
	// blr 
	return;
loc_8250393C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82503944"))) PPC_WEAK_FUNC(sub_82503944);
PPC_FUNC_IMPL(__imp__sub_82503944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503948"))) PPC_WEAK_FUNC(sub_82503948);
PPC_FUNC_IMPL(__imp__sub_82503948) {
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
	ctx.lr = 0x82503950;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82503a18
	if (cr6.eq) goto loc_82503A18;
	// lhz r25,24(r30)
	r25.u64 = PPC_LOAD_U16(r30.u32 + 24);
	// li r26,0
	r26.s64 = 0;
	// lhz r11,36(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 36);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82503a04
	if (cr6.eq) goto loc_82503A04;
	// clrlwi r28,r11,16
	r28.u64 = r11.u32 & 0xFFFF;
	// mr r27,r26
	r27.u64 = r26.u64;
loc_82503984:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// rlwinm r31,r27,2,0,29
	r31.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x8253acc8
	ctx.lr = 0x82503998;
	sub_8253ACC8(ctx, base);
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82130588
	ctx.lr = 0x825039A8;
	sub_82130588(ctx, base);
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stwx r26,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, r26.u32);
	// beq cr6,0x825039e8
	if (cr6.eq) goto loc_825039E8;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_825039BC:
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// lwzx r6,r10,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// lwzx r5,r9,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwz r4,8(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stwx r5,r4,r31
	PPC_STORE_U32(ctx.r4.u32 + r31.u32, ctx.r5.u32);
	// blt cr6,0x825039bc
	if (cr6.lt) goto loc_825039BC;
loc_825039E8:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r9,r27,1
	ctx.r9.s64 = r27.s64 + 1;
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r27,r11
	r27.u64 = r11.u64;
	// stwx r29,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r29.u32);
	// cmplw cr6,r11,r25
	cr6.compare<uint32_t>(r11.u32, r25.u32, xer);
	// blt cr6,0x82503984
	if (cr6.lt) goto loc_82503984;
loc_82503A04:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// stw r26,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r26.u32);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// rlwinm r10,r10,0,24,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
loc_82503A18:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82503A20"))) PPC_WEAK_FUNC(sub_82503A20);
PPC_FUNC_IMPL(__imp__sub_82503A20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	// lhz r11,10(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// lhz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// addis r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 65536;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// fdivs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 / ctx.f12.f64));
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lhz r3,-10(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82503A6C"))) PPC_WEAK_FUNC(sub_82503A6C);
PPC_FUNC_IMPL(__imp__sub_82503A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503A70"))) PPC_WEAK_FUNC(sub_82503A70);
PPC_FUNC_IMPL(__imp__sub_82503A70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,10(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// lhz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// addis r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 65536;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// fdivs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 / ctx.f12.f64));
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lhz r10,-10(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// bgt cr6,0x82503ab8
	if (cr6.gt) goto loc_82503AB8;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82503AB8:
	// clrlwi r8,r11,16
	ctx.r8.u64 = r11.u32 & 0xFFFF;
	// lhz r11,10(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// extsw r6,r11
	ctx.r6.s64 = r11.s32;
	// std r8,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r8.u64);
	// lfd f11,-8(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f0,-16(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fnmsubs f5,f10,f7,f1
	ctx.f5.f64 = double(float(-(ctx.f10.f64 * ctx.f7.f64 - ctx.f1.f64)));
	// fsel f4,f5,f5,f0
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f5.f64 : f0.f64;
	// fsubs f3,f4,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f6.f64));
	// fsel f1,f3,f6,f4
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f6.f64 : ctx.f4.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82503B18"))) PPC_WEAK_FUNC(sub_82503B18);
PPC_FUNC_IMPL(__imp__sub_82503B18) {
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
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82503b60
	if (!cr6.eq) goto loc_82503B60;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// beq cr6,0x82503b58
	if (cr6.eq) goto loc_82503B58;
	// rlwinm r3,r31,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x82503B54;
	sub_82130528(ctx, base);
	// b 0x82503b5c
	goto loc_82503B5C;
loc_82503B58:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82503B5C:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_82503B60:
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
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

__attribute__((alias("__imp__sub_82503B7C"))) PPC_WEAK_FUNC(sub_82503B7C);
PPC_FUNC_IMPL(__imp__sub_82503B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503B80"))) PPC_WEAK_FUNC(sub_82503B80);
PPC_FUNC_IMPL(__imp__sub_82503B80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,32388
	ctx.r8.s64 = ctx.r9.s64 + 32388;
	// li r7,127
	ctx.r7.s64 = 127;
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// li r6,1
	ctx.r6.s64 = 1;
	// sth r7,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, ctx.r7.u16);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, r11.u16);
	// sth r11,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, r11.u16);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r6,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82503BE0"))) PPC_WEAK_FUNC(sub_82503BE0);
PPC_FUNC_IMPL(__imp__sub_82503BE0) {
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
	ctx.lr = 0x82503BE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r27,36(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 36);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82503c64
	if (!cr6.gt) goto loc_82503C64;
	// mr r28,r30
	r28.u64 = r30.u64;
loc_82503C04:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82503c30
	if (cr6.eq) goto loc_82503C30;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwzx r29,r28,r11
	r29.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82503C24;
	sub_82130588(ctx, base);
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// sth r30,12(r29)
	PPC_STORE_U16(r29.u32 + 12, r30.u16);
	// sth r30,14(r29)
	PPC_STORE_U16(r29.u32 + 14, r30.u16);
loc_82503C30:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwzx r29,r28,r11
	r29.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82503c50
	if (cr6.eq) goto loc_82503C50;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8253b538
	ctx.lr = 0x82503C48;
	sub_8253B538(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82503C50;
	sub_82130588(ctx, base);
loc_82503C50:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// stwx r30,r28,r11
	PPC_STORE_U32(r28.u32 + r11.u32, r30.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x82503c04
	if (!cr0.eq) goto loc_82503C04;
loc_82503C64:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x82503C6C;
	sub_82130588(ctx, base);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// sth r30,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r30.u16);
	// sth r30,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r30.u16);
	// lhz r27,24(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82503cd8
	if (!cr6.gt) goto loc_82503CD8;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_82503C88:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82503ca8
	if (cr6.eq) goto loc_82503CA8;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x82130588
	ctx.lr = 0x82503CA4;
	sub_82130588(ctx, base);
	// b 0x82503cc4
	goto loc_82503CC4;
loc_82503CA8:
	// lwzx r28,r29,r11
	r28.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82503cc4
	if (cr6.eq) goto loc_82503CC4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8253ac68
	ctx.lr = 0x82503CBC;
	sub_8253AC68(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x82503CC4;
	sub_82130588(ctx, base);
loc_82503CC4:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// stwx r30,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, r30.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82503c88
	if (!cr0.eq) goto loc_82503C88;
loc_82503CD8:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82503CE0;
	sub_82130588(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// sth r30,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r30.u16);
	// sth r30,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r30.u16);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x82503CF4;
	sub_82130588(ctx, base);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82503D10"))) PPC_WEAK_FUNC(sub_82503D10);
PPC_FUNC_IMPL(__imp__sub_82503D10) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82503d74
	if (cr6.eq) goto loc_82503D74;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x821c8fe0
	ctx.lr = 0x82503D44;
	sub_821C8FE0(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82503d64
	if (cr6.eq) goto loc_82503D64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_82503D64:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82503D6C;
	sub_821C9030(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// b 0x82503d7c
	goto loc_82503D7C;
loc_82503D74:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82503D7C:
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

__attribute__((alias("__imp__sub_82503D94"))) PPC_WEAK_FUNC(sub_82503D94);
PPC_FUNC_IMPL(__imp__sub_82503D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82503D98"))) PPC_WEAK_FUNC(sub_82503D98);
PPC_FUNC_IMPL(__imp__sub_82503D98) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82503DA0;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// beq cr6,0x82503e1c
	if (cr6.eq) goto loc_82503E1C;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lfs f12,12(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f0,f10
	f0.f64 = double(float(ctx.f10.f64));
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f9,f0,f12
	ctx.f9.f64 = double(float(f0.f64 / ctx.f12.f64));
	// fmadds f8,f9,f1,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f1.f64 + ctx.f13.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f7.u64);
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f6,88(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f13,f5
	ctx.f13.f64 = double(float(ctx.f5.f64));
	// b 0x82503e40
	goto loc_82503E40;
loc_82503E1C:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lfs f13,12(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f0,f11
	f0.f64 = double(float(ctx.f11.f64));
	// fdivs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fmuls f13,f10,f1
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
loc_82503E40:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,10(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 10);
	// lhz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 24);
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// addis r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 65536;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfs f29,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fsel f13,f13,f13,f29
	ctx.f13.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f29.f64;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f31,f12,f0,f13
	f31.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fdivs f8,f31,f9
	ctx.f8.f64 = double(float(f31.f64 / ctx.f9.f64));
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f7.u64);
	// lhz r10,94(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// bgt cr6,0x82503e9c
	if (cr6.gt) goto loc_82503E9C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82503E9C:
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// rlwinm r9,r11,2,14,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FFFC;
	// li r31,0
	r31.s64 = 0;
	// lwzx r30,r9,r10
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// lhz r8,18(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82503ef4
	if (cr6.eq) goto loc_82503EF4;
	// addi r27,r1,88
	r27.s64 = ctx.r1.s64 + 88;
	// bl 0x82503148
	ctx.lr = 0x82503ECC;
	sub_82503148(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8253b1b0
	ctx.lr = 0x82503EDC;
	sub_8253B1B0(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82503ef0
	if (cr6.eq) goto loc_82503EF0;
	// lwz r30,12(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x82503ef4
	goto loc_82503EF4;
loc_82503EF0:
	// mr r30,r31
	r30.u64 = r31.u64;
loc_82503EF4:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lhz r5,6(r26)
	ctx.r5.u64 = PPC_LOAD_U16(r26.u32 + 6);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,5(r26)
	ctx.r4.u64 = PPC_LOAD_U8(r26.u32 + 5);
	// bl 0x8253a8f8
	ctx.lr = 0x82503F08;
	sub_8253A8F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825044c4
	if (cr6.eq) goto loc_825044C4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82503a70
	ctx.lr = 0x82503F20;
	sub_82503A70(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x823dba38
	ctx.lr = 0x82503F28;
	sub_823DBA38(ctx, base);
	// lhz r11,16(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 16);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r8,r11,-2
	ctx.r8.s64 = r11.s64 + -2;
	// lbz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 4);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// clrlwi r11,r9,28
	r11.u64 = ctx.r9.u32 & 0xF;
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fsel f11,f0,f0,f29
	ctx.f11.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fsel f8,f9,f10,f11
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f11.f64;
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f7.u64);
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f6,96(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fsubs f3,f31,f4
	ctx.f3.f64 = double(float(f31.f64 - ctx.f4.f64));
	// fsel f2,f3,f3,f29
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f3.f64 : f29.f64;
	// fsubs f1,f2,f30
	ctx.f1.f64 = double(float(ctx.f2.f64 - f30.f64));
	// fsel f31,f1,f30,f2
	f31.f64 = ctx.f1.f64 >= 0.0 ? f30.f64 : ctx.f2.f64;
	// bne cr6,0x825042e4
	if (!cr6.eq) goto loc_825042E4;
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r29,r26,16
	r29.s64 = r26.s64 + 16;
	// rlwinm r11,r11,0,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bne cr6,0x82504188
	if (!cr6.eq) goto loc_82504188;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// dcbt r0,r11
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// dcbt r0,r10
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// dcbt r0,r9
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// dcbt r0,r8
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,48(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82503FF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82504010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82504030;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,48(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82504050;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82504070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82504094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 4, temp.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,52(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x825040B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 8, temp.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825040DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f12,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// lfs f9,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fmadds f8,f10,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f11.f64));
	// lfd f0,32224(r9)
	f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + 32224);
	// lfd f13,21560(r8)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r8.u32 + 21560);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fmadds f6,f1,f1,f7
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f1.f64 + ctx.f7.f64));
	// frsqrte f5,f6
	// fneg f4,f6
	ctx.f4.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// fmul f3,f5,f5
	ctx.f3.f64 = ctx.f5.f64 * ctx.f5.f64;
	// fmul f2,f5,f0
	ctx.f2.f64 = ctx.f5.f64 * f0.f64;
	// fnmsub f11,f3,f6,f13
	ctx.f11.f64 = -(ctx.f3.f64 * ctx.f6.f64 - ctx.f13.f64);
	// fmadd f8,f11,f2,f5
	ctx.f8.f64 = ctx.f11.f64 * ctx.f2.f64 + ctx.f5.f64;
	// fmul f7,f8,f8
	ctx.f7.f64 = ctx.f8.f64 * ctx.f8.f64;
	// fmul f5,f8,f0
	ctx.f5.f64 = ctx.f8.f64 * f0.f64;
	// fnmsub f3,f7,f6,f13
	ctx.f3.f64 = -(ctx.f7.f64 * ctx.f6.f64 - ctx.f13.f64);
	// fmadd f2,f3,f5,f8
	ctx.f2.f64 = ctx.f3.f64 * ctx.f5.f64 + ctx.f8.f64;
	// frsp f0,f2
	f0.f64 = double(float(ctx.f2.f64));
	// fsel f13,f4,f29,f0
	ctx.f13.f64 = ctx.f4.f64 >= 0.0 ? f29.f64 : f0.f64;
	// fmuls f11,f13,f10
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// stfs f11,0(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// fmuls f10,f13,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f10,4(r29)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r29.u32 + 4, temp.u32);
	// fmuls f9,f13,f9
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// stfs f9,8(r29)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r29.u32 + 8, temp.u32);
	// fmuls f8,f1,f13
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// stfs f8,12(r29)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r29.u32 + 12, temp.u32);
	// lbz r11,4(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r26)
	PPC_STORE_U8(r26.u32 + 4, ctx.r10.u8);
	// bl 0x82503d10
	ctx.lr = 0x82504170;
	sub_82503D10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_82504188:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bne cr6,0x825041e0
	if (!cr6.eq) goto loc_825041E0;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825041B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r11,4(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 4);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r26)
	PPC_STORE_U8(r26.u32 + 4, ctx.r10.u8);
	// bl 0x82503d10
	ctx.lr = 0x825041C8;
	sub_82503D10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_825041E0:
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825041EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r28,r29,4
	r28.s64 = r29.s64 + 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82504210;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r27,r29,8
	r27.s64 = r29.s64 + 8;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,36(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82504234;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fmadds f11,f12,f12,f10
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f10.f64));
	// fcmpu cr6,f11,f30
	cr6.compare(ctx.f11.f64, f30.f64);
	// ble cr6,0x825042a8
	if (!cr6.gt) goto loc_825042A8;
	// fsqrts f11,f11
	ctx.f11.f64 = double(float(sqrt(ctx.f11.f64)));
	// stfs f29,12(r29)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r29.u32 + 12, temp.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// fdivs f10,f30,f11
	ctx.f10.f64 = double(float(f30.f64 / ctx.f11.f64));
	// fmuls f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// stfs f9,0(r29)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// fmuls f8,f0,f10
	ctx.f8.f64 = double(float(f0.f64 * ctx.f10.f64));
	// stfs f8,0(r28)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// fmuls f7,f12,f10
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// stfs f7,0(r27)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// lbz r11,4(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r26)
	PPC_STORE_U8(r26.u32 + 4, ctx.r10.u8);
	// bl 0x82503d10
	ctx.lr = 0x82504290;
	sub_82503D10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_825042A8:
	// fsubs f0,f30,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - ctx.f11.f64));
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// fsqrts f13,f0
	ctx.f13.f64 = double(float(sqrt(f0.f64)));
	// stfs f13,12(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 12, temp.u32);
	// lbz r11,4(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r26)
	PPC_STORE_U8(r26.u32 + 4, ctx.r10.u8);
	// bl 0x82503d10
	ctx.lr = 0x825042CC;
	sub_82503D10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_825042E4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82504464
	if (!cr6.eq) goto loc_82504464;
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r29,r26,16
	r29.s64 = r26.s64 + 16;
	// rlwinm r10,r11,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// bne cr6,0x82504414
	if (!cr6.eq) goto loc_82504414;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// dcbt r0,r11
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// dcbt r0,r10
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// dcbt r0,r9
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82504338;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82504358;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82504378;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82504398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,52(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 52);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825043BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 4, temp.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825043E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 8, temp.u32);
	// lbz r11,4(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stb r10,4(r26)
	PPC_STORE_U8(r26.u32 + 4, ctx.r10.u8);
	// bl 0x82503d10
	ctx.lr = 0x825043FC;
	sub_82503D10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_82504414:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82504434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r11,4(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 4);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r26)
	PPC_STORE_U8(r26.u32 + 4, ctx.r10.u8);
	// bl 0x82503d10
	ctx.lr = 0x8250444C;
	sub_82503D10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_82504464:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// addi r6,r26,16
	ctx.r6.s64 = r26.s64 + 16;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bne cr6,0x82504488
	if (!cr6.eq) goto loc_82504488;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// b 0x8250448c
	goto loc_8250448C;
loc_82504488:
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
loc_8250448C:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82504494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 4);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r8,0,28,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r8,4(r26)
	PPC_STORE_U8(r26.u32 + 4, ctx.r8.u8);
	// bl 0x82503d10
	ctx.lr = 0x825044AC;
	sub_82503D10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_825044C4:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825044e4
	if (cr6.eq) goto loc_825044E4;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825044E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825044E4:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82503d10
	ctx.lr = 0x825044EC;
	sub_82503D10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
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

__attribute__((alias("__imp__sub_82504504"))) PPC_WEAK_FUNC(sub_82504504);
PPC_FUNC_IMPL(__imp__sub_82504504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504508"))) PPC_WEAK_FUNC(sub_82504508);
PPC_FUNC_IMPL(__imp__sub_82504508) {
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
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82504510;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// li r26,16
	r26.s64 = 16;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82504594
	if (cr6.eq) goto loc_82504594;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x82503d98
	ctx.lr = 0x82504570;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8250458c
	if (!cr6.eq) goto loc_8250458C;
loc_8250457C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8250458C:
	// lvx128 v62,r30,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82504594:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x825045c8
	if (cr6.eq) goto loc_825045C8;
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82503d98
	ctx.lr = 0x825045B4;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8250457c
	if (cr6.eq) goto loc_8250457C;
	// lvx128 v61,r29,r26
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_825045C8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_825045D8"))) PPC_WEAK_FUNC(sub_825045D8);
PPC_FUNC_IMPL(__imp__sub_825045D8) {
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
	ctx.lr = 0x825045E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82504608
	if (cr6.eq) goto loc_82504608;
	// bl 0x8217d890
	ctx.lr = 0x825045FC;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82504608:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82504698
	if (cr6.eq) goto loc_82504698;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_82504628:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82504680
	if (cr6.eq) goto loc_82504680;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82504680
	if (cr6.eq) goto loc_82504680;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82504654;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82504680
	if (cr6.eq) goto loc_82504680;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82504668;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x8253aac8
	ctx.lr = 0x8250467C;
	sub_8253AAC8(ctx, base);
	// b 0x82504684
	goto loc_82504684;
loc_82504680:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_82504684:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82504628
	if (cr6.lt) goto loc_82504628;
loc_82504698:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_825046A4"))) PPC_WEAK_FUNC(sub_825046A4);
PPC_FUNC_IMPL(__imp__sub_825046A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825046A8"))) PPC_WEAK_FUNC(sub_825046A8);
PPC_FUNC_IMPL(__imp__sub_825046A8) {
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
	ctx.lr = 0x825046B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825046d8
	if (cr6.eq) goto loc_825046D8;
	// bl 0x8217d890
	ctx.lr = 0x825046CC;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_825046D8:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82504768
	if (cr6.eq) goto loc_82504768;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_825046F8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82504750
	if (cr6.eq) goto loc_82504750;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82504750
	if (cr6.eq) goto loc_82504750;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82504724;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82504750
	if (cr6.eq) goto loc_82504750;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82504738;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x8253b578
	ctx.lr = 0x8250474C;
	sub_8253B578(ctx, base);
	// b 0x82504754
	goto loc_82504754;
loc_82504750:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_82504754:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x825046f8
	if (cr6.lt) goto loc_825046F8;
loc_82504768:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82504774"))) PPC_WEAK_FUNC(sub_82504774);
PPC_FUNC_IMPL(__imp__sub_82504774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504778"))) PPC_WEAK_FUNC(sub_82504778);
PPC_FUNC_IMPL(__imp__sub_82504778) {
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
	ctx.lr = 0x82504780;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82504790;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8250480c
	if (!cr6.gt) goto loc_8250480C;
	// mr r31,r27
	r31.u64 = r27.u64;
	// mr r29,r30
	r29.u64 = r30.u64;
	// li r28,0
	r28.s64 = 0;
loc_825047A8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82504800
	if (cr6.eq) goto loc_82504800;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,60
	ctx.r10.s64 = 60;
	// lwzx r30,r10,r11
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825047fc
	if (cr6.eq) goto loc_825047FC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x825047D0;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x825047fc
	if (cr6.eq) goto loc_825047FC;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82504800
	if (cr6.eq) goto loc_82504800;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x825047EC;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x82504800
	goto loc_82504800;
loc_825047FC:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_82504800:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x825047a8
	if (!cr0.eq) goto loc_825047A8;
loc_8250480C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82504818"))) PPC_WEAK_FUNC(sub_82504818);
PPC_FUNC_IMPL(__imp__sub_82504818) {
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
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82504870
	if (cr6.eq) goto loc_82504870;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82504868
	if (cr6.eq) goto loc_82504868;
	// bl 0x82504778
	ctx.lr = 0x82504860;
	sub_82504778(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x82504870
	goto loc_82504870;
loc_82504868:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82504870:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825048a8
	if (cr6.eq) goto loc_825048A8;
	// li r11,0
	r11.s64 = 0;
loc_82504880:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r6,r10,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stwx r6,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r6.u32);
	// lhz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// blt cr6,0x82504880
	if (cr6.lt) goto loc_82504880;
loc_825048A8:
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

__attribute__((alias("__imp__sub_825048C0"))) PPC_WEAK_FUNC(sub_825048C0);
PPC_FUNC_IMPL(__imp__sub_825048C0) {
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
	ctx.lr = 0x825048C8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x825048D8;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82504960
	if (!cr6.gt) goto loc_82504960;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_825048F0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82504954
	if (cr6.eq) goto loc_82504954;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82504950
	if (cr6.eq) goto loc_82504950;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82504950
	if (cr6.eq) goto loc_82504950;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82504924;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82504950
	if (cr6.eq) goto loc_82504950;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82504938;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x8253d998
	ctx.lr = 0x8250494C;
	sub_8253D998(ctx, base);
	// b 0x82504954
	goto loc_82504954;
loc_82504950:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_82504954:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x825048f0
	if (!cr0.eq) goto loc_825048F0;
loc_82504960:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8250496C"))) PPC_WEAK_FUNC(sub_8250496C);
PPC_FUNC_IMPL(__imp__sub_8250496C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504970"))) PPC_WEAK_FUNC(sub_82504970);
PPC_FUNC_IMPL(__imp__sub_82504970) {
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
	ctx.lr = 0x82504978;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82504988;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82504a10
	if (!cr6.gt) goto loc_82504A10;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_825049A0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82504a04
	if (cr6.eq) goto loc_82504A04;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82504a00
	if (cr6.eq) goto loc_82504A00;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82504a00
	if (cr6.eq) goto loc_82504A00;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x825049D4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82504a00
	if (cr6.eq) goto loc_82504A00;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x825049E8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x8253aac8
	ctx.lr = 0x825049FC;
	sub_8253AAC8(ctx, base);
	// b 0x82504a04
	goto loc_82504A04;
loc_82504A00:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_82504A04:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x825049a0
	if (!cr0.eq) goto loc_825049A0;
loc_82504A10:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82504A1C"))) PPC_WEAK_FUNC(sub_82504A1C);
PPC_FUNC_IMPL(__imp__sub_82504A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504A20"))) PPC_WEAK_FUNC(sub_82504A20);
PPC_FUNC_IMPL(__imp__sub_82504A20) {
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
	ctx.lr = 0x82504A28;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82504A38;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82504ac0
	if (!cr6.gt) goto loc_82504AC0;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_82504A50:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82504ab4
	if (cr6.eq) goto loc_82504AB4;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82504ab0
	if (cr6.eq) goto loc_82504AB0;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82504ab0
	if (cr6.eq) goto loc_82504AB0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82504A84;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82504ab0
	if (cr6.eq) goto loc_82504AB0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82504A98;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x8253b578
	ctx.lr = 0x82504AAC;
	sub_8253B578(ctx, base);
	// b 0x82504ab4
	goto loc_82504AB4;
loc_82504AB0:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_82504AB4:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82504a50
	if (!cr0.eq) goto loc_82504A50;
loc_82504AC0:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82504ACC"))) PPC_WEAK_FUNC(sub_82504ACC);
PPC_FUNC_IMPL(__imp__sub_82504ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504AD0"))) PPC_WEAK_FUNC(sub_82504AD0);
PPC_FUNC_IMPL(__imp__sub_82504AD0) {
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
	// addi r10,r11,32388
	ctx.r10.s64 = r11.s64 + 32388;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82503be0
	ctx.lr = 0x82504AFC;
	sub_82503BE0(ctx, base);
	// lhz r9,38(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82504b10
	if (cr6.eq) goto loc_82504B10;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x82504B10;
	sub_82130588(ctx, base);
loc_82504B10:
	// lhz r11,26(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82504b24
	if (cr6.eq) goto loc_82504B24;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82504B24;
	sub_82130588(ctx, base);
loc_82504B24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82504B2C;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82504b44
	if (cr6.eq) goto loc_82504B44;
	// bl 0x82130588
	ctx.lr = 0x82504B40;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82504B44:
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

__attribute__((alias("__imp__sub_82504B5C"))) PPC_WEAK_FUNC(sub_82504B5C);
PPC_FUNC_IMPL(__imp__sub_82504B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504B60"))) PPC_WEAK_FUNC(sub_82504B60);
PPC_FUNC_IMPL(__imp__sub_82504B60) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r10,r11,32388
	ctx.r10.s64 = r11.s64 + 32388;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x825045d8
	ctx.lr = 0x82504B94;
	sub_825045D8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x825046a8
	ctx.lr = 0x82504BA4;
	sub_825046A8(ctx, base);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82504bc4
	if (cr6.eq) goto loc_82504BC4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82504BB8;
	sub_8217D890(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
loc_82504BC4:
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

__attribute__((alias("__imp__sub_82504BE0"))) PPC_WEAK_FUNC(sub_82504BE0);
PPC_FUNC_IMPL(__imp__sub_82504BE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82504b60
	sub_82504B60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82504BEC"))) PPC_WEAK_FUNC(sub_82504BEC);
PPC_FUNC_IMPL(__imp__sub_82504BEC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82504BF0"))) PPC_WEAK_FUNC(sub_82504BF0);
PPC_FUNC_IMPL(__imp__sub_82504BF0) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91f4
	ctx.lr = 0x82504BF8;
	// stfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f29.u64);
	// stfd f30,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stvx128 v127,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82504dac
	if (cr6.eq) goto loc_82504DAC;
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// ble cr6,0x82504c70
	if (!cr6.gt) goto loc_82504C70;
	// fsubs f0,f31,f2
	f0.f64 = double(float(f31.f64 - ctx.f2.f64));
	// fsel f13,f0,f2,f31
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f2.f64 : f31.f64;
	// fsubs f1,f31,f13
	ctx.f1.f64 = double(float(f31.f64 - ctx.f13.f64));
	// b 0x82504c84
	goto loc_82504C84;
loc_82504C70:
	// lfs f0,12(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// fsubs f12,f13,f2
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f2.f64));
	// fsel f11,f12,f13,f2
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : ctx.f2.f64;
	// fsubs f1,f31,f11
	ctx.f1.f64 = double(float(f31.f64 - ctx.f11.f64));
loc_82504C84:
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82504508
	ctx.lr = 0x82504C9C;
	sub_82504508(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82504dcc
	if (cr6.eq) goto loc_82504DCC;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82504508
	ctx.lr = 0x82504CC4;
	sub_82504508(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82504dcc
	if (cr6.eq) goto loc_82504DCC;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fneg f31,f0
	f31.u64 = f0.u64 ^ 0x8000000000000000;
	// fneg f30,f13
	f30.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fneg f29,f12
	f29.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f30,84(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f29,88(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821bb520
	ctx.lr = 0x82504D14;
	sub_821BB520(ctx, base);
	// lfs f11,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f29
	ctx.f9.f64 = double(float(ctx.f11.f64 * f29.f64));
	// lfs f8,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f31
	ctx.f7.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lfs f6,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f8,f29
	ctx.f5.f64 = double(float(ctx.f8.f64 * f29.f64));
	// fmuls f4,f6,f31
	ctx.f4.f64 = double(float(ctx.f6.f64 * f31.f64));
	// lfs f0,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmadds f3,f6,f0,f9
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f9.f64));
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmsubs f2,f11,f0,f7
	ctx.f2.f64 = double(float(ctx.f11.f64 * f0.f64 - ctx.f7.f64));
	// vsubfp128 v127,v127,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v62.f32)));
	// fmadds f1,f10,f0,f5
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f5.f64));
	// fmadds f0,f8,f0,f4
	f0.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f4.f64));
	// fmadds f13,f10,f30,f3
	ctx.f13.f64 = double(float(ctx.f10.f64 * f30.f64 + ctx.f3.f64));
	// fnmsubs f12,f8,f30,f2
	ctx.f12.f64 = double(float(-(ctx.f8.f64 * f30.f64 - ctx.f2.f64)));
	// fmadds f9,f11,f31,f1
	ctx.f9.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f1.f64));
	// fmadds f7,f11,f30,f0
	ctx.f7.f64 = double(float(ctx.f11.f64 * f30.f64 + f0.f64));
	// fnmsubs f5,f8,f31,f13
	ctx.f5.f64 = double(float(-(ctx.f8.f64 * f31.f64 - ctx.f13.f64)));
	// stfs f5,8(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// fnmsubs f4,f6,f29,f12
	ctx.f4.f64 = double(float(-(ctx.f6.f64 * f29.f64 - ctx.f12.f64)));
	// stfs f4,12(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fnmsubs f3,f6,f30,f9
	ctx.f3.f64 = double(float(-(ctx.f6.f64 * f30.f64 - ctx.f9.f64)));
	// stfs f3,0(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fnmsubs f2,f10,f29,f7
	ctx.f2.f64 = double(float(-(ctx.f10.f64 * f29.f64 - ctx.f7.f64)));
	// stfs f2,4(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821bb520
	ctx.lr = 0x82504DA0;
	sub_821BB520(ctx, base);
	// lvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v60,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v59,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82504DAC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82504DB0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f30,-64(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82504DCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82504db0
	goto loc_82504DB0;
}

__attribute__((alias("__imp__sub_82504DD4"))) PPC_WEAK_FUNC(sub_82504DD4);
PPC_FUNC_IMPL(__imp__sub_82504DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504DD8"))) PPC_WEAK_FUNC(sub_82504DD8);
PPC_FUNC_IMPL(__imp__sub_82504DD8) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82504e54
	if (!cr6.eq) goto loc_82504E54;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x82504778
	ctx.lr = 0x82504E10;
	sub_82504778(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82504e48
	if (cr6.eq) goto loc_82504E48;
	// li r11,0
	r11.s64 = 0;
loc_82504E24:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stwx r7,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, ctx.r7.u32);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// blt cr6,0x82504e24
	if (cr6.lt) goto loc_82504E24;
loc_82504E48:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82504E50;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_82504E54:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
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

__attribute__((alias("__imp__sub_82504E84"))) PPC_WEAK_FUNC(sub_82504E84);
PPC_FUNC_IMPL(__imp__sub_82504E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504E88"))) PPC_WEAK_FUNC(sub_82504E88);
PPC_FUNC_IMPL(__imp__sub_82504E88) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82504f04
	if (!cr6.eq) goto loc_82504F04;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x82504970
	ctx.lr = 0x82504EC0;
	sub_82504970(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82504ef8
	if (cr6.eq) goto loc_82504EF8;
	// li r11,0
	r11.s64 = 0;
loc_82504ED4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stwx r7,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, ctx.r7.u32);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// blt cr6,0x82504ed4
	if (cr6.lt) goto loc_82504ED4;
loc_82504EF8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82504F00;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_82504F04:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
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

__attribute__((alias("__imp__sub_82504F34"))) PPC_WEAK_FUNC(sub_82504F34);
PPC_FUNC_IMPL(__imp__sub_82504F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504F38"))) PPC_WEAK_FUNC(sub_82504F38);
PPC_FUNC_IMPL(__imp__sub_82504F38) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82504fb4
	if (!cr6.eq) goto loc_82504FB4;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x82504a20
	ctx.lr = 0x82504F70;
	sub_82504A20(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82504fa8
	if (cr6.eq) goto loc_82504FA8;
	// li r11,0
	r11.s64 = 0;
loc_82504F84:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stwx r7,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, ctx.r7.u32);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// blt cr6,0x82504f84
	if (cr6.lt) goto loc_82504F84;
loc_82504FA8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82504FB0;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_82504FB4:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
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

__attribute__((alias("__imp__sub_82504FE4"))) PPC_WEAK_FUNC(sub_82504FE4);
PPC_FUNC_IMPL(__imp__sub_82504FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82504FE8"))) PPC_WEAK_FUNC(sub_82504FE8);
PPC_FUNC_IMPL(__imp__sub_82504FE8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// bl 0x82504818
	ctx.lr = 0x82505028;
	sub_82504818(ctx, base);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// lhz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 16);
	// sth r8,16(r31)
	PPC_STORE_U16(r31.u32 + 16, ctx.r8.u16);
	// lhz r7,18(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// sth r7,18(r31)
	PPC_STORE_U16(r31.u32 + 18, ctx.r7.u16);
	// lwz r6,20(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// lwz r5,24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
	// lbz r4,28(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 28);
	// stb r4,28(r31)
	PPC_STORE_U8(r31.u32 + 28, ctx.r4.u8);
	// lbz r11,29(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 29);
	// stb r11,29(r31)
	PPC_STORE_U8(r31.u32 + 29, r11.u8);
	// lbz r10,30(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 30);
	// stb r10,30(r31)
	PPC_STORE_U8(r31.u32 + 30, ctx.r10.u8);
	// lbz r9,31(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 31);
	// stb r9,31(r31)
	PPC_STORE_U8(r31.u32 + 31, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_8250508C"))) PPC_WEAK_FUNC(sub_8250508C);
PPC_FUNC_IMPL(__imp__sub_8250508C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82505090"))) PPC_WEAK_FUNC(sub_82505090);
PPC_FUNC_IMPL(__imp__sub_82505090) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82505098;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9cc
	ctx.lr = 0x825050A0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f26,f2
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f2.f64;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// fmr f25,f1
	f25.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f31,4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f31,8(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// fcmpu cr6,f26,f31
	cr6.compare(f26.f64, f31.f64);
	// stfs f30,12(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fsubs f27,f25,f26
	f27.f64 = double(float(f25.f64 - f26.f64));
	// stvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x82505330
	if (!cr6.gt) goto loc_82505330;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// bge cr6,0x8250524c
	if (!cr6.lt) goto loc_8250524C;
	// fneg f31,f27
	f31.u64 = f27.u64 ^ 0x8000000000000000;
	// lfs f2,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dc100
	ctx.lr = 0x8250510C;
	sub_823DC100(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// frsp f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f1.f64));
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// lfs f1,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504bf0
	ctx.lr = 0x8250512C;
	sub_82504BF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8250514c
	if (!cr6.eq) goto loc_8250514C;
loc_82505138:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba18
	ctx.lr = 0x82505148;
	// b 0x823d9240
	return;
loc_8250514C:
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x8250524c
	if (!cr6.gt) goto loc_8250524C;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f2,f1
	ctx.f2.f64 = ctx.f1.f64;
	// bl 0x82504bf0
	ctx.lr = 0x82505178;
	sub_82504BF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82505138
	if (cr6.eq) goto loc_82505138;
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// fdivs f13,f27,f0
	ctx.f13.f64 = double(float(f27.f64 / f0.f64));
	// fneg f1,f13
	ctx.f1.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// bl 0x823dba38
	ctx.lr = 0x82505194;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r28,84(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8250524c
	if (cr6.eq) goto loc_8250524C;
	// lfs f31,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f31.f64 = double(temp.f32);
	// lfs f30,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f30.f64 = double(temp.f32);
	// lfs f29,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f29.f64 = double(temp.f32);
	// lfs f28,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f28.f64 = double(temp.f32);
loc_825051BC:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// bl 0x821bb520
	ctx.lr = 0x825051D0;
	sub_821BB520(ctx, base);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f29
	ctx.f12.f64 = double(float(f0.f64 * f29.f64));
	// lfs f11,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f7,f0,f30
	ctx.f7.f64 = double(float(f0.f64 * f30.f64));
	// fmuls f10,f13,f28
	ctx.f10.f64 = double(float(ctx.f13.f64 * f28.f64));
	// lfs f8,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f9,f11,f29
	ctx.f9.f64 = double(float(ctx.f11.f64 * f29.f64));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f6,f13,f30,f12
	ctx.f6.f64 = double(float(ctx.f13.f64 * f30.f64 + ctx.f12.f64));
	// fmadds f3,f8,f28,f7
	ctx.f3.f64 = double(float(ctx.f8.f64 * f28.f64 + ctx.f7.f64));
	// fmsubs f5,f0,f31,f10
	ctx.f5.f64 = double(float(f0.f64 * f31.f64 - ctx.f10.f64));
	// fmadds f4,f0,f28,f9
	ctx.f4.f64 = double(float(f0.f64 * f28.f64 + ctx.f9.f64));
	// fmadds f2,f8,f31,f6
	ctx.f2.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f6.f64));
	// fmadds f12,f11,f31,f3
	ctx.f12.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f3.f64));
	// fnmsubs f1,f8,f29,f5
	ctx.f1.f64 = double(float(-(ctx.f8.f64 * f29.f64 - ctx.f5.f64)));
	// fmadds f0,f13,f31,f4
	f0.f64 = double(float(ctx.f13.f64 * f31.f64 + ctx.f4.f64));
	// fnmsubs f10,f11,f28,f2
	ctx.f10.f64 = double(float(-(ctx.f11.f64 * f28.f64 - ctx.f2.f64)));
	// stfs f10,4(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// fnmsubs f7,f13,f29,f12
	ctx.f7.f64 = double(float(-(ctx.f13.f64 * f29.f64 - ctx.f12.f64)));
	// stfs f7,8(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// fnmsubs f9,f11,f30,f1
	ctx.f9.f64 = double(float(-(ctx.f11.f64 * f30.f64 - ctx.f1.f64)));
	// stfs f9,12(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fnmsubs f8,f8,f30,f0
	ctx.f8.f64 = double(float(-(ctx.f8.f64 * f30.f64 - f0.f64)));
	// stfs f8,0(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x825051bc
	if (!cr6.eq) goto loc_825051BC;
loc_8250524C:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fsel f2,f27,f26,f25
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f27.f64 >= 0.0 ? f26.f64 : f25.f64;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504bf0
	ctx.lr = 0x8250526C;
	sub_82504BF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82505138
	if (cr6.eq) goto loc_82505138;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821bb520
	ctx.lr = 0x82505298;
	sub_821BB520(ctx, base);
	// lfs f10,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmuls f6,f9,f12
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// lfs f3,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f4,f9,f0
	ctx.f4.f64 = double(float(ctx.f9.f64 * f0.f64));
	// lfs f5,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f2,f3,f12,f8
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fmsubs f1,f10,f12,f7
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 - ctx.f7.f64));
	// fmadds f8,f3,f11,f6
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + ctx.f6.f64));
	// fmadds f7,f5,f12,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + ctx.f4.f64));
	// fmadds f6,f5,f13,f2
	ctx.f6.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f2.f64));
	// fnmsubs f4,f5,f11,f1
	ctx.f4.f64 = double(float(-(ctx.f5.f64 * ctx.f11.f64 - ctx.f1.f64)));
	// fmadds f2,f10,f13,f8
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fmadds f1,f10,f11,f7
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f7.f64));
	// fnmsubs f12,f9,f11,f6
	ctx.f12.f64 = double(float(-(ctx.f9.f64 * ctx.f11.f64 - ctx.f6.f64)));
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// fnmsubs f11,f3,f0,f4
	ctx.f11.f64 = double(float(-(ctx.f3.f64 * f0.f64 - ctx.f4.f64)));
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fnmsubs f10,f5,f0,f2
	ctx.f10.f64 = double(float(-(ctx.f5.f64 * f0.f64 - ctx.f2.f64)));
	// stfs f10,0(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fnmsubs f9,f3,f13,f1
	ctx.f9.f64 = double(float(-(ctx.f3.f64 * ctx.f13.f64 - ctx.f1.f64)));
	// stfs f9,4(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lvx128 v57,r0,r29
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v56,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba18
	ctx.lr = 0x8250532C;
	// b 0x823d9240
	return;
loc_82505330:
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// bge cr6,0x8250555c
	if (!cr6.lt) goto loc_8250555C;
	// lfs f2,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f27,f2
	cr6.compare(f27.f64, ctx.f2.f64);
	// ble cr6,0x82505480
	if (!cr6.gt) goto loc_82505480;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x823dc100
	ctx.lr = 0x8250534C;
	sub_823DC100(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fneg f2,f0
	ctx.f2.u64 = f0.u64 ^ 0x8000000000000000;
	// bl 0x82504bf0
	ctx.lr = 0x82505370;
	sub_82504BF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82505138
	if (cr6.eq) goto loc_82505138;
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// fsubs f13,f27,f0
	ctx.f13.f64 = double(float(f27.f64 - f0.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82505480
	if (!cr6.gt) goto loc_82505480;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fneg f2,f0
	ctx.f2.u64 = f0.u64 ^ 0x8000000000000000;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504bf0
	ctx.lr = 0x825053AC;
	sub_82504BF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82505138
	if (cr6.eq) goto loc_82505138;
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// fdivs f1,f27,f0
	ctx.f1.f64 = double(float(f27.f64 / f0.f64));
	// bl 0x823dba38
	ctx.lr = 0x825053C4;
	sub_823DBA38(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fsubs f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 - f30.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r28,84(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x82505480
	if (cr6.eq) goto loc_82505480;
	// lfs f31,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f31.f64 = double(temp.f32);
	// lfs f30,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f30.f64 = double(temp.f32);
	// lfs f29,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f29.f64 = double(temp.f32);
	// lfs f28,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f28.f64 = double(temp.f32);
loc_825053F0:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// bl 0x821bb520
	ctx.lr = 0x82505404;
	sub_821BB520(ctx, base);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f30
	ctx.f12.f64 = double(float(f0.f64 * f30.f64));
	// fmuls f11,f13,f28
	ctx.f11.f64 = double(float(ctx.f13.f64 * f28.f64));
	// lfs f10,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f13,f31
	ctx.f9.f64 = double(float(ctx.f13.f64 * f31.f64));
	// lfs f8,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f13,f30
	ctx.f7.f64 = double(float(ctx.f13.f64 * f30.f64));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f6,f10,f31,f12
	ctx.f6.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f12.f64));
	// fmsubs f5,f0,f31,f11
	ctx.f5.f64 = double(float(f0.f64 * f31.f64 - ctx.f11.f64));
	// fmadds f4,f10,f29,f9
	ctx.f4.f64 = double(float(ctx.f10.f64 * f29.f64 + ctx.f9.f64));
	// fmadds f3,f8,f31,f7
	ctx.f3.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f7.f64));
	// fmadds f2,f8,f28,f6
	ctx.f2.f64 = double(float(ctx.f8.f64 * f28.f64 + ctx.f6.f64));
	// fnmsubs f1,f8,f29,f5
	ctx.f1.f64 = double(float(-(ctx.f8.f64 * f29.f64 - ctx.f5.f64)));
	// fmadds f12,f0,f28,f4
	ctx.f12.f64 = double(float(f0.f64 * f28.f64 + ctx.f4.f64));
	// fmadds f11,f0,f29,f3
	ctx.f11.f64 = double(float(f0.f64 * f29.f64 + ctx.f3.f64));
	// fnmsubs f9,f13,f29,f2
	ctx.f9.f64 = double(float(-(ctx.f13.f64 * f29.f64 - ctx.f2.f64)));
	// stfs f9,8(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// fnmsubs f7,f10,f30,f1
	ctx.f7.f64 = double(float(-(ctx.f10.f64 * f30.f64 - ctx.f1.f64)));
	// stfs f7,12(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fnmsubs f6,f8,f30,f12
	ctx.f6.f64 = double(float(-(ctx.f8.f64 * f30.f64 - ctx.f12.f64)));
	// stfs f6,0(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fnmsubs f5,f10,f28,f11
	ctx.f5.f64 = double(float(-(ctx.f10.f64 * f28.f64 - ctx.f11.f64)));
	// stfs f5,4(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lvx128 v54,r0,r29
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v53,v54,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v53,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x825053f0
	if (!cr6.eq) goto loc_825053F0;
loc_82505480:
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fsubs f13,f25,f0
	ctx.f13.f64 = double(float(f25.f64 - f0.f64));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fsubs f12,f13,f26
	ctx.f12.f64 = double(float(ctx.f13.f64 - f26.f64));
	// fsel f2,f12,f13,f26
	ctx.f2.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f26.f64;
	// bl 0x82504bf0
	ctx.lr = 0x825054AC;
	sub_82504BF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82505138
	if (cr6.eq) goto loc_82505138;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821bb520
	ctx.lr = 0x825054D8;
	sub_821BB520(ctx, base);
	// lfs f10,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f9,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f12,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f4,f9,f0
	ctx.f4.f64 = double(float(ctx.f9.f64 * f0.f64));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f6,f9,f12
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fmuls f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// lfs f3,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lfs f5,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// lvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f2,f3,f12,f8
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fmadds f8,f3,f11,f6
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + ctx.f6.f64));
	// fmsubs f1,f10,f12,f7
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 - ctx.f7.f64));
	// fmadds f7,f5,f12,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + ctx.f4.f64));
	// fmadds f6,f5,f13,f2
	ctx.f6.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f2.f64));
	// fmadds f2,f10,f13,f8
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fnmsubs f4,f5,f11,f1
	ctx.f4.f64 = double(float(-(ctx.f5.f64 * ctx.f11.f64 - ctx.f1.f64)));
	// fmadds f1,f10,f11,f7
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f7.f64));
	// fnmsubs f12,f9,f11,f6
	ctx.f12.f64 = double(float(-(ctx.f9.f64 * ctx.f11.f64 - ctx.f6.f64)));
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// fnmsubs f10,f5,f0,f2
	ctx.f10.f64 = double(float(-(ctx.f5.f64 * f0.f64 - ctx.f2.f64)));
	// stfs f10,0(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fnmsubs f11,f3,f0,f4
	ctx.f11.f64 = double(float(-(ctx.f3.f64 * f0.f64 - ctx.f4.f64)));
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fnmsubs f9,f3,f13,f1
	ctx.f9.f64 = double(float(-(ctx.f3.f64 * ctx.f13.f64 - ctx.f1.f64)));
	// stfs f9,4(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lvx128 v50,r0,r29
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v49,v50,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_add_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// stvx128 v49,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8250555C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba18
	ctx.lr = 0x8250556C;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82505570"))) PPC_WEAK_FUNC(sub_82505570);
PPC_FUNC_IMPL(__imp__sub_82505570) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82505578;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// lhz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// rlwinm r8,r8,0,24,20
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFF8FF;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// sth r8,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r8.u16);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// li r5,1
	ctx.r5.s64 = 1;
	// beq cr6,0x825055c4
	if (cr6.eq) goto loc_825055C4;
	// bl 0x821be6a8
	ctx.lr = 0x825055C0;
	sub_821BE6A8(ctx, base);
	// b 0x825055c8
	goto loc_825055C8;
loc_825055C4:
	// bl 0x821be780
	ctx.lr = 0x825055C8;
	sub_821BE780(ctx, base);
loc_825055C8:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x825055f4
	if (cr6.eq) goto loc_825055F4;
	// lhz r11,82(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// rlwinm r10,r10,0,24,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFF8FF;
	// sth r10,4(r25)
	PPC_STORE_U16(r25.u32 + 4, ctx.r10.u16);
loc_825055F4:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// addi r4,r25,6
	ctx.r4.s64 = r25.s64 + 6;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82505624
	if (cr6.eq) goto loc_82505624;
	// bl 0x821be6a8
	ctx.lr = 0x82505620;
	sub_821BE6A8(ctx, base);
	// b 0x82505628
	goto loc_82505628;
loc_82505624:
	// bl 0x821be780
	ctx.lr = 0x82505628;
	sub_821BE780(ctx, base);
loc_82505628:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// addi r23,r25,8
	r23.s64 = r25.s64 + 8;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8250565c
	if (cr6.eq) goto loc_8250565C;
	// bl 0x821be6a8
	ctx.lr = 0x82505658;
	sub_821BE6A8(ctx, base);
	// b 0x82505660
	goto loc_82505660;
loc_8250565C:
	// bl 0x821be780
	ctx.lr = 0x82505660;
	sub_821BE780(ctx, base);
loc_82505660:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// addi r4,r25,12
	ctx.r4.s64 = r25.s64 + 12;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82505690
	if (cr6.eq) goto loc_82505690;
	// bl 0x821be710
	ctx.lr = 0x8250568C;
	sub_821BE710(ctx, base);
	// b 0x82505694
	goto loc_82505694;
loc_82505690:
	// bl 0x821be7e8
	ctx.lr = 0x82505694;
	sub_821BE7E8(ctx, base);
loc_82505694:
	// lhz r11,2(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 2);
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// bge cr6,0x825056c0
	if (!cr6.lt) goto loc_825056C0;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r11,2272
	ctx.r9.s64 = r11.s64 + 2272;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82503078
	ctx.lr = 0x825056C0;
	sub_82503078(ctx, base);
loc_825056C0:
	// lhz r11,2(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 2);
	// addi r24,r25,10
	r24.s64 = r25.s64 + 10;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bge cr6,0x825056dc
	if (!cr6.lt) goto loc_825056DC;
	// li r11,-1
	r11.s64 = -1;
	// sth r11,10(r25)
	PPC_STORE_U16(r25.u32 + 10, r11.u16);
	// b 0x82505710
	goto loc_82505710;
loc_825056DC:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8250570c
	if (cr6.eq) goto loc_8250570C;
	// bl 0x821be6a8
	ctx.lr = 0x82505708;
	sub_821BE6A8(ctx, base);
	// b 0x82505710
	goto loc_82505710;
loc_8250570C:
	// bl 0x821be780
	ctx.lr = 0x82505710;
	sub_821BE780(ctx, base);
loc_82505710:
	// lhz r11,0(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x82505748
	if (!cr6.gt) goto loc_82505748;
	// addi r9,r11,-2
	ctx.r9.s64 = r11.s64 + -2;
	// lhz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U16(r24.u32 + 0);
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r10,r9,r8
	ctx.r10.s32 = ctx.r9.s32 / ctx.r8.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// andc r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 & ~ctx.r7.u64;
	// twllei r8,0
	// clrlwi r26,r6,16
	r26.u64 = ctx.r6.u32 & 0xFFFF;
	// twlgei r5,-1
	// b 0x8250574c
	goto loc_8250574C;
loc_82505748:
	// li r26,1
	r26.s64 = 1;
loc_8250574C:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lhz r10,36(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 36);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// subfic r8,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// sth r10,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82505784
	if (cr6.eq) goto loc_82505784;
	// bl 0x821be6a8
	ctx.lr = 0x82505780;
	sub_821BE6A8(ctx, base);
	// b 0x82505788
	goto loc_82505788;
loc_82505784:
	// bl 0x821be780
	ctx.lr = 0x82505788;
	sub_821BE780(ctx, base);
loc_82505788:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x825057d0
	if (cr6.eq) goto loc_825057D0;
	// lhz r31,80(r1)
	r31.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r30,r25,32
	r30.s64 = r25.s64 + 32;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825057c4
	if (cr6.eq) goto loc_825057C4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504a20
	ctx.lr = 0x825057C0;
	sub_82504A20(ctx, base);
	// b 0x825057c8
	goto loc_825057C8;
loc_825057C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825057C8:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
loc_825057D0:
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8250589c
	if (cr6.eq) goto loc_8250589C;
	// li r28,0
	r28.s64 = 0;
loc_825057E0:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8250586c
	if (cr6.eq) goto loc_8250586C;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82505804;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82505818
	if (cr6.eq) goto loc_82505818;
	// bl 0x8253b3b8
	ctx.lr = 0x82505810;
	sub_8253B3B8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8250581c
	goto loc_8250581C;
loc_82505818:
	// li r30,0
	r30.s64 = 0;
loc_8250581C:
	// lhz r11,36(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 36);
	// clrlwi r31,r26,16
	r31.u64 = r26.u32 & 0xFFFF;
	// lwz r10,32(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// addi r29,r30,8
	r29.s64 = r30.s64 + 8;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// sth r8,36(r25)
	PPC_STORE_U16(r25.u32 + 36, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// beq cr6,0x8250585c
	if (cr6.eq) goto loc_8250585C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825048c0
	ctx.lr = 0x82505850;
	sub_825048C0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// sth r31,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r31.u16);
	// b 0x82505878
	goto loc_82505878;
loc_8250585C:
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r31,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r31.u16);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// b 0x82505878
	goto loc_82505878;
loc_8250586C:
	// lwz r11,32(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r11
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_82505878:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8253b5f0
	ctx.lr = 0x82505884;
	sub_8253B5F0(ctx, base);
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// lhz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// mr r28,r11
	r28.u64 = r11.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x825057e0
	if (cr6.lt) goto loc_825057E0;
loc_8250589C:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82505a64
	if (cr6.eq) goto loc_82505A64;
	// lhz r11,26(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 26);
	// addi r28,r25,20
	r28.s64 = r25.s64 + 20;
	// clrlwi r26,r26,16
	r26.u64 = r26.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825058f0
	if (!cr6.eq) goto loc_825058F0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r26,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r26.u16);
	// beq cr6,0x825058e8
	if (cr6.eq) goto loc_825058E8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82504970
	ctx.lr = 0x825058E4;
	sub_82504970(ctx, base);
	// b 0x825058ec
	goto loc_825058EC;
loc_825058E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825058EC:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
loc_825058F0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r26,4(r28)
	PPC_STORE_U16(r28.u32 + 4, r26.u16);
	// beq cr6,0x82505a64
	if (cr6.eq) goto loc_82505A64;
	// li r27,0
	r27.s64 = 0;
loc_82505900:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x82505908;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82505918
	if (cr6.eq) goto loc_82505918;
	// bl 0x8253a998
	ctx.lr = 0x82505914;
	sub_8253A998(ctx, base);
	// b 0x8250591c
	goto loc_8250591C;
loc_82505918:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8250591C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rlwinm r29,r27,2,0,29
	r29.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r3.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lhz r30,80(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// lwzx r11,r10,r29
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lhz r8,10(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 10);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82505968
	if (!cr6.eq) goto loc_82505968;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x82505960
	if (cr6.eq) goto loc_82505960;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82504778
	ctx.lr = 0x8250595C;
	sub_82504778(ctx, base);
	// b 0x82505964
	goto loc_82505964;
loc_82505960:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82505964:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_82505968:
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// lhz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U16(r23.u32 + 0);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// ble cr6,0x825059a4
	if (!cr6.gt) goto loc_825059A4;
	// addi r9,r10,-2
	ctx.r9.s64 = ctx.r10.s64 + -2;
	// lhz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U16(r24.u32 + 0);
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r9,r9,r8
	ctx.r9.s32 = ctx.r9.s32 / ctx.r8.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// andc r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 & ~ctx.r7.u64;
	// twllei r8,0
	// clrlwi r11,r6,16
	r11.u64 = ctx.r6.u32 & 0xFFFF;
	// twlgei r5,-1
	// b 0x825059a8
	goto loc_825059A8;
loc_825059A4:
	// li r11,1
	r11.s64 = 1;
loc_825059A8:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// lhz r11,0(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 0);
	// blt cr6,0x825059f4
	if (cr6.lt) goto loc_825059F4;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// twllei r11,0
	// divw r8,r9,r11
	ctx.r8.s32 = ctx.r9.s32 / r11.s32;
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// andc r4,r11,r5
	ctx.r4.u64 = r11.u64 & ~ctx.r5.u64;
	// clrlwi r10,r6,16
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFF;
	// twlgei r4,-1
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825059f4
	if (cr6.eq) goto loc_825059F4;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// b 0x825059f8
	goto loc_825059F8;
loc_825059F4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_825059F8:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// sth r11,16(r9)
	PPC_STORE_U16(ctx.r9.u32 + 16, r11.u16);
	// lhz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82505a50
	if (cr6.eq) goto loc_82505A50;
	// li r11,0
	r11.s64 = 0;
loc_82505A18:
	// lwz r10,32(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// lwzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r5,r8,r29
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	// lwz r4,8(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r3,4(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwzx r10,r4,r29
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + r29.u32);
	// stwx r10,r3,r9
	PPC_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.r10.u32);
	// lhz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x82505a18
	if (cr6.lt) goto loc_82505A18;
loc_82505A50:
	// addi r11,r27,1
	r11.s64 = r27.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// mr r27,r11
	r27.u64 = r11.u64;
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// blt cr6,0x82505900
	if (cr6.lt) goto loc_82505900;
loc_82505A64:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82505A6C"))) PPC_WEAK_FUNC(sub_82505A6C);
PPC_FUNC_IMPL(__imp__sub_82505A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82505A70"))) PPC_WEAK_FUNC(sub_82505A70);
PPC_FUNC_IMPL(__imp__sub_82505A70) {
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
	ctx.lr = 0x82505A78;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r5,2(r27)
	ctx.r5.u64 = PPC_LOAD_U16(r27.u32 + 2);
	// lbz r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// bl 0x82503808
	ctx.lr = 0x82505A94;
	sub_82503808(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82505aa8
	if (cr6.eq) goto loc_82505AA8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82505AA8:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82505ac0
	if (cr6.eq) goto loc_82505AC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82503948
	ctx.lr = 0x82505AC0;
	sub_82503948(ctx, base);
loc_82505AC0:
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504f38
	ctx.lr = 0x82505AD0;
	sub_82504F38(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lhz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r29,r10,65535
	r29.u64 = ctx.r10.u64 | 65535;
	// lhz r11,36(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 36);
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// add r6,r8,r29
	ctx.r6.u64 = ctx.r8.u64 + r29.u64;
	// lwz r28,80(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r5,2,14,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FFFC;
	// sth r5,36(r31)
	PPC_STORE_U16(r31.u32 + 36, ctx.r5.u16);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r10,r11,r7
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// stwx r10,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r10.u32);
	// bl 0x825087d8
	ctx.lr = 0x82505B14;
	sub_825087D8(ctx, base);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// lhz r26,24(r31)
	r26.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82505be8
	if (cr6.eq) goto loc_82505BE8;
	// rlwinm r25,r28,2,0,29
	r25.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r30,0
	r30.s64 = 0;
loc_82505B2C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r24,r30,2,0,29
	r24.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r11,r11,r24
	r11.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82504dd8
	ctx.lr = 0x82505B44;
	sub_82504DD8(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwzx r11,r10,r24
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r24.u32);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lhz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r8,r9,r29
	ctx.r8.u64 = ctx.r9.u64 + r29.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// clrlwi r6,r8,16
	ctx.r6.u64 = ctx.r8.u32 & 0xFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r4,r6,2,14,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FFFC;
	// sth r6,8(r11)
	PPC_STORE_U16(r11.u32 + 8, ctx.r6.u16);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// stwx r3,r5,r7
	PPC_STORE_U32(ctx.r5.u32 + ctx.r7.u32, ctx.r3.u32);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r9,8(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwzx r11,r11,r24
	r11.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpw cr6,r10,r28
	cr6.compare<int32_t>(ctx.r10.s32, r28.s32, xer);
	// lwzx r7,r9,r24
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r24.u32);
	// ble cr6,0x82505bc0
	if (!cr6.gt) goto loc_82505BC0;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r28,r10
	ctx.r10.s64 = ctx.r10.s64 - r28.s64;
loc_82505BA4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// lwz r6,-4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// bne 0x82505ba4
	if (!cr0.eq) goto loc_82505BA4;
loc_82505BC0:
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r9,r30,1
	ctx.r9.s64 = r30.s64 + 1;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r26
	cr6.compare<uint32_t>(ctx.r10.u32, r26.u32, xer);
	// stwx r7,r8,r25
	PPC_STORE_U32(ctx.r8.u32 + r25.u32, ctx.r7.u32);
	// blt cr6,0x82505b2c
	if (cr6.lt) goto loc_82505B2C;
loc_82505BE8:
	// li r11,0
	r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82505BFC"))) PPC_WEAK_FUNC(sub_82505BFC);
PPC_FUNC_IMPL(__imp__sub_82505BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82505C00"))) PPC_WEAK_FUNC(sub_82505C00);
PPC_FUNC_IMPL(__imp__sub_82505C00) {
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
	ctx.lr = 0x82505C08;
	// addi r31,r1,-240
	r31.s64 = ctx.r1.s64 + -240;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// stw r19,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r19.u32);
	// lbz r11,4(r19)
	r11.u64 = PPC_LOAD_U8(r19.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82506138
	if (!cr6.eq) goto loc_82506138;
	// bl 0x825036c8
	ctx.lr = 0x82505C2C;
	sub_825036C8(ctx, base);
	// lhz r11,36(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 36);
	// lhz r10,24(r19)
	ctx.r10.u64 = PPC_LOAD_U16(r19.u32 + 24);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// mr r14,r11
	r14.u64 = r11.u64;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x82505C4C;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// rotlwi r22,r10,2
	r22.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// mr r15,r10
	r15.u64 = ctx.r10.u64;
	// neg r6,r22
	ctx.r6.s64 = -r22.s64;
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r6,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r25,r1,80
	r25.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x82505C6C;
	sub_823DBFF4(ctx, base);
	// lwz r5,0(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// stwux r5,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r1.u32 = ea;
	// addi r24,r1,80
	r24.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x82505ca8
	if (cr6.eq) goto loc_82505CA8;
	// lwz r10,32(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 32);
	// mr r11,r23
	r11.u64 = r23.u64;
loc_82505C8C:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplw cr6,r11,r14
	cr6.compare<uint32_t>(r11.u32, r14.u32, xer);
	// stwx r7,r9,r25
	PPC_STORE_U32(ctx.r9.u32 + r25.u32, ctx.r7.u32);
	// blt cr6,0x82505c8c
	if (cr6.lt) goto loc_82505C8C;
loc_82505CA8:
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x82505cd4
	if (cr6.eq) goto loc_82505CD4;
	// lwz r10,20(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 20);
	// mr r11,r23
	r11.u64 = r23.u64;
loc_82505CB8:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplw cr6,r11,r15
	cr6.compare<uint32_t>(r11.u32, r15.u32, xer);
	// stwx r7,r9,r24
	PPC_STORE_U32(ctx.r9.u32 + r24.u32, ctx.r7.u32);
	// blt cr6,0x82505cb8
	if (cr6.lt) goto loc_82505CB8;
loc_82505CD4:
	// bl 0x821bbea8
	ctx.lr = 0x82505CD8;
	sub_821BBEA8(ctx, base);
	// lwz r3,32(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 32);
	// addi r30,r19,32
	r30.s64 = r19.s64 + 32;
	// bl 0x82130588
	ctx.lr = 0x82505CE4;
	sub_82130588(ctx, base);
	// stw r23,32(r19)
	PPC_STORE_U32(r19.u32 + 32, r23.u32);
	// addi r27,r19,20
	r27.s64 = r19.s64 + 20;
	// sth r23,36(r19)
	PPC_STORE_U16(r19.u32 + 36, r23.u16);
	// sth r23,38(r19)
	PPC_STORE_U16(r19.u32 + 38, r23.u16);
	// lwz r3,20(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82505CFC;
	sub_82130588(ctx, base);
	// stw r23,20(r19)
	PPC_STORE_U32(r19.u32 + 20, r23.u32);
	// sth r23,24(r19)
	PPC_STORE_U16(r19.u32 + 24, r23.u16);
	// sth r23,26(r19)
	PPC_STORE_U16(r19.u32 + 26, r23.u16);
	// bl 0x821bbf00
	ctx.lr = 0x82505D0C;
	sub_821BBF00(ctx, base);
	// lhz r11,38(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 38);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82505d3c
	if (!cr6.eq) goto loc_82505D3C;
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// sth r14,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r14.u16);
	// beq cr6,0x82505d34
	if (cr6.eq) goto loc_82505D34;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504a20
	ctx.lr = 0x82505D30;
	sub_82504A20(ctx, base);
	// b 0x82505d38
	goto loc_82505D38;
loc_82505D34:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_82505D38:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_82505D3C:
	// sth r14,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r14.u16);
	// lhz r10,6(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82505d70
	if (!cr6.eq) goto loc_82505D70;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// sth r15,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r15.u16);
	// beq cr6,0x82505d68
	if (cr6.eq) goto loc_82505D68;
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82504970
	ctx.lr = 0x82505D64;
	sub_82504970(ctx, base);
	// b 0x82505d6c
	goto loc_82505D6C;
loc_82505D68:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_82505D6C:
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
loc_82505D70:
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// sth r15,4(r27)
	PPC_STORE_U16(r27.u32 + 4, r15.u16);
	// beq cr6,0x82505dfc
	if (cr6.eq) goto loc_82505DFC;
	// mr r26,r23
	r26.u64 = r23.u64;
loc_82505D80:
	// rlwinm r29,r26,2,0,29
	r29.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r28,32(r19)
	r28.u64 = PPC_LOAD_U32(r19.u32 + 32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r19,32
	r11.s64 = r19.s64 + 32;
	// lwzx r30,r29,r25
	r30.u64 = PPC_LOAD_U32(r29.u32 + r25.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8253bf50
	ctx.lr = 0x82505D9C;
	sub_8253BF50(ctx, base);
	// stwx r3,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, ctx.r3.u32);
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x82505dc8
	if (cr6.eq) goto loc_82505DC8;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_82505DAC:
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// stwx r23,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r23.u32);
	// cmplw cr6,r11,r15
	cr6.compare<uint32_t>(r11.u32, r15.u32, xer);
	// blt cr6,0x82505dac
	if (cr6.lt) goto loc_82505DAC;
loc_82505DC8:
	// bl 0x821bbea8
	ctx.lr = 0x82505DCC;
	sub_821BBEA8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82505de4
	if (cr6.eq) goto loc_82505DE4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8253b538
	ctx.lr = 0x82505DDC;
	sub_8253B538(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82505DE4;
	sub_82130588(ctx, base);
loc_82505DE4:
	// bl 0x821bbf00
	ctx.lr = 0x82505DE8;
	sub_821BBF00(ctx, base);
	// addi r11,r26,1
	r11.s64 = r26.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// mr r26,r11
	r26.u64 = r11.u64;
	// cmplw cr6,r11,r14
	cr6.compare<uint32_t>(r11.u32, r14.u32, xer);
	// blt cr6,0x82505d80
	if (cr6.lt) goto loc_82505D80;
loc_82505DFC:
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x82505e28
	if (cr6.eq) goto loc_82505E28;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_82505E08:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r7,r10,r24
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r24.u32);
	// cmplw cr6,r11,r15
	cr6.compare<uint32_t>(r11.u32, r15.u32, xer);
	// stwx r7,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u32);
	// blt cr6,0x82505e08
	if (cr6.lt) goto loc_82505E08;
loc_82505E28:
	// rlwinm r29,r21,2,0,29
	r29.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x821bbea8
	ctx.lr = 0x82505E30;
	sub_821BBEA8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130528
	ctx.lr = 0x82505E38;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// bl 0x8244d150
	ctx.lr = 0x82505E4C;
	sub_8244D150(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x82505E50;
	sub_821BBF00(ctx, base);
	// neg r11,r22
	r11.s64 = -r22.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x82505E5C;
	sub_823DBFF4(ctx, base);
	// lwz r10,0(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// neg r9,r22
	ctx.r9.s64 = -r22.s64;
	// stwux r10,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r17,r1,80
	r17.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x82505E74;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// rlwinm r5,r21,1,1,30
	ctx.r5.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 1) & 0x7FFFFFFE;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// addi r16,r1,80
	r16.s64 = ctx.r1.s64 + 80;
	// bl 0x82503550
	ctx.lr = 0x82505E90;
	sub_82503550(ctx, base);
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r11,88
	r11.s64 = 88;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// stbx r7,r29,r11
	PPC_STORE_U8(r29.u32 + r11.u32, ctx.r7.u8);
	// beq cr6,0x82505fb8
	if (cr6.eq) goto loc_82505FB8;
	// li r21,112
	r21.s64 = 112;
	// li r20,84
	r20.s64 = 84;
	// li r19,108
	r19.s64 = 108;
	// li r18,80
	r18.s64 = 80;
	// mr r24,r23
	r24.u64 = r23.u64;
loc_82505EC0:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r30,r24,2,0,29
	r30.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x8253acc8
	ctx.lr = 0x82505ED4;
	sub_8253ACC8(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// bl 0x821bbea8
	ctx.lr = 0x82505EDC;
	sub_821BBEA8(ctx, base);
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// beq cr6,0x82505f38
	if (cr6.eq) goto loc_82505F38;
	// mr r28,r23
	r28.u64 = r23.u64;
loc_82505EE8:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r26,r28,2,0,29
	r26.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwzx r25,r9,r26
	r25.u64 = PPC_LOAD_U32(ctx.r9.u32 + r26.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82505f14
	if (cr6.eq) goto loc_82505F14;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8253d020
	ctx.lr = 0x82505F0C;
	sub_8253D020(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x82505F14;
	sub_82130588(ctx, base);
loc_82505F14:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r9,r28,1
	ctx.r9.s64 = r28.s64 + 1;
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r28,r11
	r28.u64 = r11.u64;
	// lwzx r8,r10,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// cmplw cr6,r11,r14
	cr6.compare<uint32_t>(r11.u32, r14.u32, xer);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stwx r23,r7,r26
	PPC_STORE_U32(ctx.r7.u32 + r26.u32, r23.u32);
	// blt cr6,0x82505ee8
	if (cr6.lt) goto loc_82505EE8;
loc_82505F38:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r28,r11,r30
	r28.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82505f58
	if (cr6.eq) goto loc_82505F58;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8253ac68
	ctx.lr = 0x82505F50;
	sub_8253AC68(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x82505F58;
	sub_82130588(ctx, base);
loc_82505F58:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stwx r23,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, r23.u32);
	// bl 0x821bbf00
	ctx.lr = 0x82505F64;
	sub_821BBF00(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r9,r29,r20
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r20.u32);
	// lwzx r8,r29,r21
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + r21.u32);
	// lwzx r7,r29,r18
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + r18.u32);
	// lwzx r6,r29,r19
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r19.u32);
	// subf r11,r8,r9
	r11.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stwx r22,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, r22.u32);
	// subf r10,r6,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r6.s64;
	// addi r5,r11,15
	ctx.r5.s64 = r11.s64 + 15;
	// addi r4,r10,15
	ctx.r4.s64 = ctx.r10.s64 + 15;
	// rlwinm r3,r5,0,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF0;
	// rlwinm r11,r4,0,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFF0;
	// stwx r3,r30,r17
	PPC_STORE_U32(r30.u32 + r17.u32, ctx.r3.u32);
	// stwx r11,r30,r16
	PPC_STORE_U32(r30.u32 + r16.u32, r11.u32);
	// bl 0x82503610
	ctx.lr = 0x82505FA0;
	sub_82503610(ctx, base);
	// addi r10,r24,1
	ctx.r10.s64 = r24.s64 + 1;
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r24,r11
	r24.u64 = r11.u64;
	// cmplw cr6,r11,r15
	cr6.compare<uint32_t>(r11.u32, r15.u32, xer);
	// blt cr6,0x82505ec0
	if (cr6.lt) goto loc_82505EC0;
	// lwz r19,260(r31)
	r19.u64 = PPC_LOAD_U32(r31.u32 + 260);
loc_82505FB8:
	// lis r11,0
	r11.s64 = 0;
	// li r24,116
	r24.s64 = 116;
	// ori r9,r11,65535
	ctx.r9.u64 = r11.u64 | 65535;
	// li r22,96
	r22.s64 = 96;
	// add r10,r15,r9
	ctx.r10.u64 = r15.u64 + ctx.r9.u64;
	// li r21,92
	r21.s64 = 92;
	// lwzx r8,r29,r24
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + r24.u32);
	// li r20,28
	r20.s64 = 28;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// stwx r23,r29,r22
	PPC_STORE_U32(r29.u32 + r22.u32, r23.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stwx r23,r29,r21
	PPC_STORE_U32(r29.u32 + r21.u32, r23.u32);
	// stwx r8,r29,r20
	PPC_STORE_U32(r29.u32 + r20.u32, ctx.r8.u32);
	// beq cr6,0x8250602c
	if (cr6.eq) goto loc_8250602C;
loc_82505FF0:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r8,r11,r17
	ctx.r8.u64 = r11.u64 + r17.u64;
	// add r7,r11,r16
	ctx.r7.u64 = r11.u64 + r16.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// lwzx r6,r11,r17
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r17.u32);
	// lwzx r5,r11,r16
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r16.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r4,-4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// lwz r3,-4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	// subf r8,r4,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r4.s64;
	// subf r7,r3,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r3.s64;
	// stwx r8,r11,r17
	PPC_STORE_U32(r11.u32 + r17.u32, ctx.r8.u32);
	// stwx r7,r11,r16
	PPC_STORE_U32(r11.u32 + r16.u32, ctx.r7.u32);
	// bne cr6,0x82505ff0
	if (!cr6.eq) goto loc_82505FF0;
loc_8250602C:
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// stw r23,40(r19)
	PPC_STORE_U32(r19.u32 + 40, r23.u32);
	// beq cr6,0x8250611c
	if (cr6.eq) goto loc_8250611C;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_8250603C:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r28,r25,2,0,29
	r28.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r28,r16
	r11.u64 = PPC_LOAD_U32(r28.u32 + r16.u32);
	// lwzx r26,r28,r17
	r26.u64 = PPC_LOAD_U32(r28.u32 + r17.u32);
	// lwzx r9,r10,r28
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
	// stw r30,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r30.u32);
	// lwz r11,40(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 40);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x82506068
	if (!cr6.gt) goto loc_82506068;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82506068:
	// stw r11,40(r19)
	PPC_STORE_U32(r19.u32 + 40, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130528
	ctx.lr = 0x82506074;
	sub_82130528(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x82506084;
	sub_8244D150(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x82503550
	ctx.lr = 0x82506094;
	sub_82503550(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// stbx r10,r29,r11
	PPC_STORE_U8(r29.u32 + r11.u32, ctx.r10.u8);
	// lwzx r3,r9,r28
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r28.u32);
	// bl 0x8253acc8
	ctx.lr = 0x825060B0;
	sub_8253ACC8(ctx, base);
	// lwzx r8,r29,r24
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + r24.u32);
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r30.u32);
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// stwx r23,r29,r22
	PPC_STORE_U32(r29.u32 + r22.u32, r23.u32);
	// stwx r23,r29,r21
	PPC_STORE_U32(r29.u32 + r21.u32, r23.u32);
	// stwx r8,r29,r20
	PPC_STORE_U32(r29.u32 + r20.u32, ctx.r8.u32);
	// beq cr6,0x82506100
	if (cr6.eq) goto loc_82506100;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_825060D0:
	// lwz r9,32(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 32);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r10,r19,32
	ctx.r10.s64 = r19.s64 + 32;
	// clrlwi r11,r6,16
	r11.u64 = ctx.r6.u32 & 0xFFFF;
	// lwzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// cmplw cr6,r11,r14
	cr6.compare<uint32_t>(r11.u32, r14.u32, xer);
	// lwzx r4,r8,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// lwz r9,8(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stwx r4,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, ctx.r4.u32);
	// blt cr6,0x825060d0
	if (cr6.lt) goto loc_825060D0;
loc_82506100:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r9,r25,1
	ctx.r9.s64 = r25.s64 + 1;
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r25,r11
	r25.u64 = r11.u64;
	// stwx r3,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, ctx.r3.u32);
	// cmplw cr6,r11,r15
	cr6.compare<uint32_t>(r11.u32, r15.u32, xer);
	// blt cr6,0x8250603c
	if (cr6.lt) goto loc_8250603C;
loc_8250611C:
	// bl 0x821bbea8
	ctx.lr = 0x82506120;
	sub_821BBEA8(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82130588
	ctx.lr = 0x82506128;
	sub_82130588(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x8250612C;
	sub_821BBF00(ctx, base);
	// lhz r11,4(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 4);
	// ori r10,r11,256
	ctx.r10.u64 = r11.u64 | 256;
	// sth r10,4(r19)
	PPC_STORE_U16(r19.u32 + 4, ctx.r10.u16);
loc_82506138:
	// addi r1,r31,240
	ctx.r1.s64 = r31.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82506140"))) PPC_WEAK_FUNC(sub_82506140);
PPC_FUNC_IMPL(__imp__sub_82506140) {
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
	ctx.lr = 0x82506148;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,1
	r11.s64 = 1;
	// li r24,0
	r24.s64 = 0;
	// stw r11,44(r27)
	PPC_STORE_U32(r27.u32 + 44, r11.u32);
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r9,r9,0,24,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// sth r9,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r9.u16);
	// lhz r8,6(r28)
	ctx.r8.u64 = PPC_LOAD_U16(r28.u32 + 6);
	// sth r8,6(r27)
	PPC_STORE_U16(r27.u32 + 6, ctx.r8.u16);
	// lfs f0,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 12, temp.u32);
	// lhz r7,8(r28)
	ctx.r7.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// sth r7,8(r27)
	PPC_STORE_U16(r27.u32 + 8, ctx.r7.u16);
	// lwz r6,16(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// stw r6,16(r27)
	PPC_STORE_U32(r27.u32 + 16, ctx.r6.u32);
	// lwz r3,28(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825061a8
	if (cr6.eq) goto loc_825061A8;
	// bl 0x821378b8
	ctx.lr = 0x825061A0;
	sub_821378B8(ctx, base);
	// stw r3,28(r27)
	PPC_STORE_U32(r27.u32 + 28, ctx.r3.u32);
	// b 0x825061ac
	goto loc_825061AC;
loc_825061A8:
	// stw r24,28(r27)
	PPC_STORE_U32(r27.u32 + 28, r24.u32);
loc_825061AC:
	// lhz r11,10(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 10);
	// addi r26,r27,32
	r26.s64 = r27.s64 + 32;
	// sth r11,10(r27)
	PPC_STORE_U16(r27.u32 + 10, r11.u16);
	// lhz r31,36(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825061d4
	if (cr6.eq) goto loc_825061D4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82504a20
	ctx.lr = 0x825061D0;
	sub_82504A20(ctx, base);
	// b 0x825061d8
	goto loc_825061D8;
loc_825061D4:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_825061D8:
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// mr r29,r24
	r29.u64 = r24.u64;
	// sth r31,6(r26)
	PPC_STORE_U16(r26.u32 + 6, r31.u16);
	// lhz r10,36(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 36);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82506240
	if (cr6.eq) goto loc_82506240;
	// mr r31,r24
	r31.u64 = r24.u64;
loc_825061F4:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x825061FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82506218
	if (cr6.eq) goto loc_82506218;
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x8253bf08
	ctx.lr = 0x82506210;
	sub_8253BF08(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8250621c
	goto loc_8250621C;
loc_82506218:
	// mr r30,r24
	r30.u64 = r24.u64;
loc_8250621C:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82504f38
	ctx.lr = 0x82506228;
	sub_82504F38(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lhz r11,36(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 36);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x825061f4
	if (cr6.lt) goto loc_825061F4;
loc_82506240:
	// lhz r31,24(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 24);
	// addi r30,r27,20
	r30.s64 = r27.s64 + 20;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82506260
	if (cr6.eq) goto loc_82506260;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504970
	ctx.lr = 0x8250625C;
	sub_82504970(ctx, base);
	// b 0x82506264
	goto loc_82506264;
loc_82506260:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82506264:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r25,r24
	r25.u64 = r24.u64;
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// lhz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82506314
	if (cr6.eq) goto loc_82506314;
	// mr r31,r24
	r31.u64 = r24.u64;
loc_82506280:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x82506288;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825062a4
	if (cr6.eq) goto loc_825062A4;
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82504fe8
	ctx.lr = 0x8250629C;
	sub_82504FE8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x825062a8
	goto loc_825062A8;
loc_825062A4:
	// mr r29,r24
	r29.u64 = r24.u64;
loc_825062A8:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504e88
	ctx.lr = 0x825062B4;
	sub_82504E88(ctx, base);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// lhz r11,36(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 36);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82506300
	if (cr6.eq) goto loc_82506300;
	// mr r11,r24
	r11.u64 = r24.u64;
loc_825062CC:
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwzx r3,r5,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + r31.u32);
	// stwx r3,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r3.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r9,36(r27)
	ctx.r9.u64 = PPC_LOAD_U16(r27.u32 + 36);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x825062cc
	if (cr6.lt) goto loc_825062CC;
loc_82506300:
	// lhz r11,24(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 24);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x82506280
	if (cr6.lt) goto loc_82506280;
loc_82506314:
	// stw r24,40(r27)
	PPC_STORE_U32(r27.u32 + 40, r24.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82506320"))) PPC_WEAK_FUNC(sub_82506320);
PPC_FUNC_IMPL(__imp__sub_82506320) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// sth r6,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, ctx.r6.u16);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// sth r6,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, ctx.r6.u16);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lfs f13,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// addi r7,r9,18800
	ctx.r7.s64 = ctx.r9.s64 + 18800;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r8,r10,-17052
	ctx.r8.s64 = ctx.r10.s64 + -17052;
	// li r6,1
	ctx.r6.s64 = 1;
	// fsel f12,f1,f1,f0
	ctx.f12.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// li r5,6
	ctx.r5.s64 = 6;
	// stw r8,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r6,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r6.u8);
	// li r11,5
	r11.s64 = 5;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// stb r5,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, ctx.r5.u8);
	// fsel f11,f1,f1,f0
	ctx.f11.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// stb r4,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r4.u8);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stb r11,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r11.u8);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f1,f10,f13,f11
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// bl 0x82505090
	ctx.lr = 0x825063A4;
	sub_82505090(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825063f8
	if (cr6.eq) goto loc_825063F8;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// li r10,16
	ctx.r10.s64 = 16;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f11,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_825063F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82506410"))) PPC_WEAK_FUNC(sub_82506410);
PPC_FUNC_IMPL(__imp__sub_82506410) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82506418;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82506440
	if (cr6.eq) goto loc_82506440;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82506444
	if (!cr6.eq) goto loc_82506444;
loc_82506440:
	// li r11,0
	r11.s64 = 0;
loc_82506444:
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82506464
	if (cr6.eq) goto loc_82506464;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82506468
	if (!cr6.eq) goto loc_82506468;
loc_82506464:
	// li r11,0
	r11.s64 = 0;
loc_82506468:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// bl 0x82505090
	ctx.lr = 0x82506480;
	sub_82505090(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82506524
	if (cr6.eq) goto loc_82506524;
	// li r11,16
	r11.s64 = 16;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825064d0
	if (cr6.eq) goto loc_825064D0;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825064b4
	if (cr6.eq) goto loc_825064B4;
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r9.u8);
	// b 0x825064d0
	goto loc_825064D0;
loc_825064B4:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r8,0,28,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r8,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r8.u8);
loc_825064D0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82506518
	if (cr6.eq) goto loc_82506518;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825064fc
	if (cr6.eq) goto loc_825064FC;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stb r10,4(r30)
	PPC_STORE_U8(r30.u32 + 4, ctx.r10.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_825064FC:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r8,0,28,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r8,4(r30)
	PPC_STORE_U8(r30.u32 + 4, ctx.r8.u8);
loc_82506518:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_82506524:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82506530"))) PPC_WEAK_FUNC(sub_82506530);
PPC_FUNC_IMPL(__imp__sub_82506530) {
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
	ctx.lr = 0x82506538;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x821be250
	ctx.lr = 0x82506568;
	sub_821BE250(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82506578
	if (cr6.eq) goto loc_82506578;
	// stb r11,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r11.u8);
loc_82506578:
	// clrlwi r30,r29,24
	r30.u64 = r29.u32 & 0xFF;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,90(r1)
	PPC_STORE_U16(ctx.r1.u32 + 90, r11.u16);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r10,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, ctx.r10.u16);
	// beq cr6,0x8250659c
	if (cr6.eq) goto loc_8250659C;
	// bl 0x821bbea8
	ctx.lr = 0x8250659C;
	sub_821BBEA8(ctx, base);
loc_8250659C:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82505570
	ctx.lr = 0x825065A8;
	sub_82505570(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825065b4
	if (cr6.eq) goto loc_825065B4;
	// bl 0x821bbf00
	ctx.lr = 0x825065B4;
	sub_821BBF00(ctx, base);
loc_825065B4:
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bge cr6,0x825065cc
	if (!cr6.lt) goto loc_825065CC;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// ori r10,r11,512
	ctx.r10.u64 = r11.u64 | 512;
	// sth r10,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r10.u16);
loc_825065CC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825065e0
	if (cr6.eq) goto loc_825065E0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82505c00
	ctx.lr = 0x825065E0;
	sub_82505C00(ctx, base);
loc_825065E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82503880
	ctx.lr = 0x825065E8;
	sub_82503880(ctx, base);
	// stw r3,16(r28)
	PPC_STORE_U32(r28.u32 + 16, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_825065F8"))) PPC_WEAK_FUNC(sub_825065F8);
PPC_FUNC_IMPL(__imp__sub_825065F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82506600;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// li r22,1
	r22.s64 = 1;
	// li r27,0
	r27.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r28,r24,32
	r28.s64 = r24.s64 + 32;
	// lhz r11,36(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 36);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lhz r29,16(r9)
	r29.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// add. r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x82506644
	if (cr0.eq) goto loc_82506644;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82504a20
	ctx.lr = 0x82506640;
	sub_82504A20(ctx, base);
	// b 0x82506648
	goto loc_82506648;
loc_82506644:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82506648:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// sth r30,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r30.u16);
	// ble cr6,0x825069d8
	if (!cr6.gt) goto loc_825069D8;
	// mr r28,r27
	r28.u64 = r27.u64;
	// li r25,16
	r25.s64 = 16;
loc_82506660:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwzx r30,r9,r28
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + r28.u32);
	// lbz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// clrlwi r11,r8,28
	r11.u64 = ctx.r8.u32 & 0xF;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x825069c8
	if (cr6.gt) goto loc_825069C8;
	// lis r12,-32176
	r12.s64 = -2108686336;
	// addi r12,r12,26264
	r12.s64 = r12.s64 + 26264;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_825066A8;
	case 1:
		goto loc_82506768;
	case 2:
		goto loc_82506828;
	case 3:
		goto loc_825068E0;
	default:
		__builtin_unreachable();
	}
	// lwz r18,26280(r16)
	r18.u64 = PPC_LOAD_U32(r16.u32 + 26280);
	// lwz r18,26472(r16)
	r18.u64 = PPC_LOAD_U32(r16.u32 + 26472);
	// lwz r18,26664(r16)
	r18.u64 = PPC_LOAD_U32(r16.u32 + 26664);
	// lwz r18,26848(r16)
	r18.u64 = PPC_LOAD_U32(r16.u32 + 26848);
loc_825066A8:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x825066B0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825066c4
	if (cr6.eq) goto loc_825066C4;
	// bl 0x8253b3b8
	ctx.lr = 0x825066BC;
	sub_8253B3B8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x825066c8
	goto loc_825066C8;
loc_825066C4:
	// mr r26,r27
	r26.u64 = r27.u64;
loc_825066C8:
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// sth r27,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r27.u16);
	// sth r27,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r27.u16);
	// lhz r4,8(r24)
	ctx.r4.u64 = PPC_LOAD_U16(r24.u32 + 8);
	// bl 0x82503b18
	ctx.lr = 0x825066E0;
	sub_82503B18(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lvx128 v63,r30,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,1
	ctx.r9.s64 = 1;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// ble cr6,0x82506738
	if (!cr6.gt) goto loc_82506738;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// li r11,4
	r11.s64 = 4;
loc_82506704:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwzx r6,r11,r8
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r5,12(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lwzx r4,r5,r28
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + r28.u32);
	// lvx128 v62,r4,r25
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r9,r3
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, xer);
	// blt cr6,0x82506704
	if (cr6.lt) goto loc_82506704;
loc_82506738:
	// li r8,127
	ctx.r8.s64 = 127;
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8253b8b8
	ctx.lr = 0x82506754;
	sub_8253B8B8(ctx, base);
	// lhz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82506998
	if (cr6.eq) goto loc_82506998;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x82506994
	goto loc_82506994;
loc_82506768:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82506770;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82506784
	if (cr6.eq) goto loc_82506784;
	// bl 0x8253b3b8
	ctx.lr = 0x8250677C;
	sub_8253B3B8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x82506788
	goto loc_82506788;
loc_82506784:
	// mr r26,r27
	r26.u64 = r27.u64;
loc_82506788:
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// sth r27,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r27.u16);
	// sth r27,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r27.u16);
	// lhz r4,8(r24)
	ctx.r4.u64 = PPC_LOAD_U16(r24.u32 + 8);
	// bl 0x82503b18
	ctx.lr = 0x825067A0;
	sub_82503B18(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lvx128 v61,r30,r25
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,1
	ctx.r9.s64 = 1;
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// ble cr6,0x825067f8
	if (!cr6.gt) goto loc_825067F8;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// li r11,4
	r11.s64 = 4;
loc_825067C4:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwzx r6,r11,r8
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r5,12(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lwzx r4,r5,r28
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + r28.u32);
	// lvx128 v60,r4,r25
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r9,r3
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, xer);
	// blt cr6,0x825067c4
	if (cr6.lt) goto loc_825067C4;
loc_825067F8:
	// li r8,127
	ctx.r8.s64 = 127;
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8253ba18
	ctx.lr = 0x82506814;
	sub_8253BA18(ctx, base);
	// lhz r10,94(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82506998
	if (cr6.eq) goto loc_82506998;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// b 0x82506994
	goto loc_82506994;
loc_82506828:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82506830;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82506844
	if (cr6.eq) goto loc_82506844;
	// bl 0x8253b3b8
	ctx.lr = 0x8250683C;
	sub_8253B3B8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x82506848
	goto loc_82506848;
loc_82506844:
	// mr r26,r27
	r26.u64 = r27.u64;
loc_82506848:
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// sth r27,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r27.u16);
	// sth r27,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, r27.u16);
	// lhz r4,8(r24)
	ctx.r4.u64 = PPC_LOAD_U16(r24.u32 + 8);
	// bl 0x8247bb70
	ctx.lr = 0x82506860;
	sub_8247BB70(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// ble cr6,0x825068b0
	if (!cr6.gt) goto loc_825068B0;
	// li r11,4
	r11.s64 = 4;
loc_82506880:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,96(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r5,r6,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + r28.u32);
	// lfs f0,16(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfsx f0,r11,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r4
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, xer);
	// blt cr6,0x82506880
	if (cr6.lt) goto loc_82506880;
loc_825068B0:
	// li r8,127
	ctx.r8.s64 = 127;
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8253bb70
	ctx.lr = 0x825068CC;
	sub_8253BB70(ctx, base);
	// lhz r10,102(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82506998
	if (cr6.eq) goto loc_82506998;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x82506994
	goto loc_82506994;
loc_825068E0:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x825068E8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825068fc
	if (cr6.eq) goto loc_825068FC;
	// bl 0x8253b3b8
	ctx.lr = 0x825068F4;
	sub_8253B3B8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x82506900
	goto loc_82506900;
loc_825068FC:
	// mr r26,r27
	r26.u64 = r27.u64;
loc_82506900:
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// sth r27,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, r27.u16);
	// sth r27,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, r27.u16);
	// lhz r4,8(r24)
	ctx.r4.u64 = PPC_LOAD_U16(r24.u32 + 8);
	// bl 0x8247bb70
	ctx.lr = 0x82506918;
	sub_8247BB70(ctx, base);
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// ble cr6,0x82506968
	if (!cr6.gt) goto loc_82506968;
	// li r11,4
	r11.s64 = 4;
loc_82506938:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r5,r6,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + r28.u32);
	// lwz r4,16(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// stwx r4,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r4.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// blt cr6,0x82506938
	if (cr6.lt) goto loc_82506938;
loc_82506968:
	// li r8,127
	ctx.r8.s64 = 127;
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8253bcd0
	ctx.lr = 0x82506984;
	sub_8253BCD0(ctx, base);
	// lhz r10,110(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 110);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82506998
	if (cr6.eq) goto loc_82506998;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_82506994:
	// bl 0x82130588
	ctx.lr = 0x82506998;
	sub_82130588(ctx, base);
loc_82506998:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x825069cc
	if (cr6.eq) goto loc_825069CC;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82505a70
	ctx.lr = 0x825069AC;
	sub_82505A70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825069cc
	if (!cr6.eq) goto loc_825069CC;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8253b538
	ctx.lr = 0x825069C0;
	sub_8253B538(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x825069C8;
	sub_82130588(ctx, base);
loc_825069C8:
	// mr r22,r27
	r22.u64 = r27.u64;
loc_825069CC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x82506660
	if (!cr0.eq) goto loc_82506660;
loc_825069D8:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82503880
	ctx.lr = 0x825069E0;
	sub_82503880(ctx, base);
	// stw r3,16(r24)
	PPC_STORE_U32(r24.u32 + 16, ctx.r3.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_825069F0"))) PPC_WEAK_FUNC(sub_825069F0);
PPC_FUNC_IMPL(__imp__sub_825069F0) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x825069F8;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825031a8
	ctx.lr = 0x82506A2C;
	sub_825031A8(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82506bb8
	if (cr6.eq) goto loc_82506BB8;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825095c8
	ctx.lr = 0x82506A58;
	sub_825095C8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825095c8
	ctx.lr = 0x82506A6C;
	sub_825095C8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82506bb4
	if (cr6.eq) goto loc_82506BB4;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82506bb4
	if (cr6.eq) goto loc_82506BB4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f11,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f11.f64 = double(temp.f32);
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// beq cr6,0x82506aec
	if (cr6.eq) goto loc_82506AEC;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// frsp f13,f10
	ctx.f13.f64 = double(float(ctx.f10.f64));
	// fmuls f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmadds f8,f9,f31,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64 + ctx.f11.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f12,f5
	ctx.f12.f64 = double(float(ctx.f5.f64));
	// b 0x82506b04
	goto loc_82506B04;
loc_82506AEC:
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// frsp f13,f10
	ctx.f13.f64 = double(float(ctx.f10.f64));
	// fmuls f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmuls f12,f9,f31
	ctx.f12.f64 = double(float(ctx.f9.f64 * f31.f64));
loc_82506B04:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// fmuls f13,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fsel f7,f12,f12,f0
	ctx.f7.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fmuls f0,f13,f30
	f0.f64 = double(float(ctx.f13.f64 * f30.f64));
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fsel f13,f6,f8,f7
	ctx.f13.f64 = ctx.f6.f64 >= 0.0 ? ctx.f8.f64 : ctx.f7.f64;
	// beq cr6,0x82506b68
	if (cr6.eq) goto loc_82506B68;
	// fadds f12,f0,f11
	ctx.f12.f64 = double(float(f0.f64 + ctx.f11.f64));
	// fsubs f11,f0,f11
	ctx.f11.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsel f10,f30,f12,f11
	ctx.f10.f64 = f30.f64 >= 0.0 ? ctx.f12.f64 : ctx.f11.f64;
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f0,f7
	f0.f64 = double(float(ctx.f7.f64));
loc_82506B68:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lfs f12,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// fmuls f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fdivs f2,f11,f7
	ctx.f2.f64 = double(float(ctx.f11.f64 / ctx.f7.f64));
	// fdivs f1,f10,f7
	ctx.f1.f64 = double(float(ctx.f10.f64 / ctx.f7.f64));
	// bl 0x82506410
	ctx.lr = 0x82506BA4;
	sub_82506410(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82506BB4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82506BB8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82506BC8"))) PPC_WEAK_FUNC(sub_82506BC8);
PPC_FUNC_IMPL(__imp__sub_82506BC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82506BD0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// li r24,0
	r24.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82506c28
	if (!cr6.gt) goto loc_82506C28;
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
loc_82506C08:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// beq cr6,0x82506c1c
	if (cr6.eq) goto loc_82506C1C;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
loc_82506C1C:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82506c08
	if (!cr0.eq) goto loc_82506C08;
loc_82506C28:
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82506c4c
	if (cr6.eq) goto loc_82506C4C;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x825065f8
	ctx.lr = 0x82506C44;
	sub_825065F8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9224
	return;
loc_82506C4C:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// li r19,1
	r19.s64 = 1;
	// lhz r11,36(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 36);
	// addi r30,r23,32
	r30.s64 = r23.s64 + 32;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lhz r21,16(r9)
	r21.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// add. r31,r11,r21
	r31.u64 = r11.u64 + r21.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82506c7c
	if (cr0.eq) goto loc_82506C7C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504a20
	ctx.lr = 0x82506C78;
	sub_82504A20(ctx, base);
	// b 0x82506c80
	goto loc_82506C80;
loc_82506C7C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82506C80:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r22,r24
	r22.u64 = r24.u64;
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x825070d8
	if (!cr6.gt) goto loc_825070D8;
loc_82506C94:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// rlwinm r10,r22,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwzx r30,r8,r10
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lbz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// clrlwi r11,r7,28
	r11.u64 = ctx.r7.u32 & 0xF;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x825070c8
	if (cr6.gt) goto loc_825070C8;
	// lis r12,-32176
	r12.s64 = -2108686336;
	// addi r12,r12,27856
	r12.s64 = r12.s64 + 27856;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82506CE0;
	case 1:
		goto loc_82506DD4;
	case 2:
		goto loc_82506EC8;
	case 3:
		goto loc_82506FB0;
	default:
		__builtin_unreachable();
	}
	// lwz r18,27872(r16)
	r18.u64 = PPC_LOAD_U32(r16.u32 + 27872);
	// lwz r18,28116(r16)
	r18.u64 = PPC_LOAD_U32(r16.u32 + 28116);
	// lwz r18,28360(r16)
	r18.u64 = PPC_LOAD_U32(r16.u32 + 28360);
	// lwz r18,28592(r16)
	r18.u64 = PPC_LOAD_U32(r16.u32 + 28592);
loc_82506CE0:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82506CE8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82506cfc
	if (cr6.eq) goto loc_82506CFC;
	// bl 0x8253b3b8
	ctx.lr = 0x82506CF4;
	sub_8253B3B8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// b 0x82506d00
	goto loc_82506D00;
loc_82506CFC:
	// mr r25,r24
	r25.u64 = r24.u64;
loc_82506D00:
	// lhz r11,8(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 8);
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// mr r31,r11
	r31.u64 = r11.u64;
	// sth r24,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r24.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r31,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r31.u16);
	// beq cr6,0x82506d2c
	if (cr6.eq) goto loc_82506D2C;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x82506D24;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82506d30
	goto loc_82506D30;
loc_82506D2C:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_82506D30:
	// addi r27,r30,16
	r27.s64 = r30.s64 + 16;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// sth r31,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r31.u16);
	// li r28,1
	r28.s64 = 1;
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x82506da4
	if (!cr6.gt) goto loc_82506DA4;
	// li r29,16
	r29.s64 = 16;
	// li r31,4
	r31.s64 = 4;
loc_82506D5C:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x825095c8
	ctx.lr = 0x82506D70;
	sub_825095C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// bne cr6,0x82506d80
	if (!cr6.eq) goto loc_82506D80;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82506D80:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stvx128 v62,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// lhz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmpw cr6,r28,r9
	cr6.compare<int32_t>(r28.s32, ctx.r9.s32, xer);
	// blt cr6,0x82506d5c
	if (cr6.lt) goto loc_82506D5C;
loc_82506DA4:
	// li r8,127
	ctx.r8.s64 = 127;
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8253b8b8
	ctx.lr = 0x82506DC0;
	sub_8253B8B8(ctx, base);
	// lhz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82507098
	if (cr6.eq) goto loc_82507098;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x82507094
	goto loc_82507094;
loc_82506DD4:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82506DDC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82506df0
	if (cr6.eq) goto loc_82506DF0;
	// bl 0x8253b3b8
	ctx.lr = 0x82506DE8;
	sub_8253B3B8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// b 0x82506df4
	goto loc_82506DF4;
loc_82506DF0:
	// mr r25,r24
	r25.u64 = r24.u64;
loc_82506DF4:
	// lhz r11,8(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 8);
	// stw r24,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r24.u32);
	// mr r31,r11
	r31.u64 = r11.u64;
	// sth r24,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r24.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r31,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r31.u16);
	// beq cr6,0x82506e20
	if (cr6.eq) goto loc_82506E20;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x82506E18;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82506e24
	goto loc_82506E24;
loc_82506E20:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_82506E24:
	// sth r31,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r31.u16);
	// addi r27,r30,16
	r27.s64 = r30.s64 + 16;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// li r28,1
	r28.s64 = 1;
	// lvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x82506e98
	if (!cr6.gt) goto loc_82506E98;
	// li r29,16
	r29.s64 = 16;
	// li r31,4
	r31.s64 = 4;
loc_82506E50:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x825095c8
	ctx.lr = 0x82506E64;
	sub_825095C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// bne cr6,0x82506e74
	if (!cr6.eq) goto loc_82506E74;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82506E74:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stvx128 v60,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// lhz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmpw cr6,r28,r9
	cr6.compare<int32_t>(r28.s32, ctx.r9.s32, xer);
	// blt cr6,0x82506e50
	if (cr6.lt) goto loc_82506E50;
loc_82506E98:
	// li r8,127
	ctx.r8.s64 = 127;
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8253ba18
	ctx.lr = 0x82506EB4;
	sub_8253BA18(ctx, base);
	// lhz r10,94(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82507098
	if (cr6.eq) goto loc_82507098;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// b 0x82507094
	goto loc_82507094;
loc_82506EC8:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82506ED0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82506ee4
	if (cr6.eq) goto loc_82506EE4;
	// bl 0x8253b3b8
	ctx.lr = 0x82506EDC;
	sub_8253B3B8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// b 0x82506ee8
	goto loc_82506EE8;
loc_82506EE4:
	// mr r25,r24
	r25.u64 = r24.u64;
loc_82506EE8:
	// lhz r11,8(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 8);
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
	// mr r31,r11
	r31.u64 = r11.u64;
	// sth r24,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r24.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r31,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, r31.u16);
	// beq cr6,0x82506f14
	if (cr6.eq) goto loc_82506F14;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82506F0C;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82506f18
	goto loc_82506F18;
loc_82506F14:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_82506F18:
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r29,1
	r29.s64 = 1;
	// sth r31,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r31.u16);
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x82506f80
	if (!cr6.gt) goto loc_82506F80;
	// li r31,4
	r31.s64 = 4;
loc_82506F3C:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x825095c8
	ctx.lr = 0x82506F50;
	sub_825095C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82506f60
	if (cr6.eq) goto loc_82506F60;
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// b 0x82506f64
	goto loc_82506F64;
loc_82506F60:
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	f0.f64 = double(temp.f32);
loc_82506F64:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stfsx f0,r11,r31
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lhz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x82506f3c
	if (cr6.lt) goto loc_82506F3C;
loc_82506F80:
	// li r8,127
	ctx.r8.s64 = 127;
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8253bb70
	ctx.lr = 0x82506F9C;
	sub_8253BB70(ctx, base);
	// lhz r10,102(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82507098
	if (cr6.eq) goto loc_82507098;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x82507094
	goto loc_82507094;
loc_82506FB0:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82506FB8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82506fcc
	if (cr6.eq) goto loc_82506FCC;
	// bl 0x8253b3b8
	ctx.lr = 0x82506FC4;
	sub_8253B3B8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// b 0x82506fd0
	goto loc_82506FD0;
loc_82506FCC:
	// mr r25,r24
	r25.u64 = r24.u64;
loc_82506FD0:
	// lhz r11,8(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 8);
	// stw r24,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r24.u32);
	// mr r31,r11
	r31.u64 = r11.u64;
	// sth r24,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, r24.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r31,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, r31.u16);
	// beq cr6,0x82506ffc
	if (cr6.eq) goto loc_82506FFC;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82506FF4;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82507000
	goto loc_82507000;
loc_82506FFC:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_82507000:
	// sth r31,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, r31.u16);
	// li r29,1
	r29.s64 = 1;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lhz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// ble cr6,0x82507068
	if (!cr6.gt) goto loc_82507068;
	// li r31,4
	r31.s64 = 4;
loc_82507024:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x825095c8
	ctx.lr = 0x82507038;
	sub_825095C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82507048
	if (cr6.eq) goto loc_82507048;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// b 0x8250704c
	goto loc_8250704C;
loc_82507048:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
loc_8250704C:
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stwx r11,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r11.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lhz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x82507024
	if (cr6.lt) goto loc_82507024;
loc_82507068:
	// li r8,127
	ctx.r8.s64 = 127;
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// lbz r4,5(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8253bcd0
	ctx.lr = 0x82507084;
	sub_8253BCD0(ctx, base);
	// lhz r10,110(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 110);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82507098
	if (cr6.eq) goto loc_82507098;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_82507094:
	// bl 0x82130588
	ctx.lr = 0x82507098;
	sub_82130588(ctx, base);
loc_82507098:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x825070cc
	if (cr6.eq) goto loc_825070CC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82505a70
	ctx.lr = 0x825070AC;
	sub_82505A70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825070cc
	if (!cr6.eq) goto loc_825070CC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8253b538
	ctx.lr = 0x825070C0;
	sub_8253B538(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x825070C8;
	sub_82130588(ctx, base);
loc_825070C8:
	// mr r19,r24
	r19.u64 = r24.u64;
loc_825070CC:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// cmpw cr6,r22,r21
	cr6.compare<int32_t>(r22.s32, r21.s32, xer);
	// blt cr6,0x82506c94
	if (cr6.lt) goto loc_82506C94;
loc_825070D8:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82503880
	ctx.lr = 0x825070E0;
	sub_82503880(ctx, base);
	// stw r3,16(r23)
	PPC_STORE_U32(r23.u32 + 16, ctx.r3.u32);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_825070F0"))) PPC_WEAK_FUNC(sub_825070F0);
PPC_FUNC_IMPL(__imp__sub_825070F0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x825070F8;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x821be710
	ctx.lr = 0x82507118;
	sub_821BE710(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,6,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0x20;
	// rlwinm r9,r11,29,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x10;
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// or r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 | ctx.r9.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// or r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 | ctx.r8.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r6,4(r25)
	PPC_STORE_U16(r25.u32 + 4, ctx.r6.u16);
	// bl 0x821be710
	ctx.lr = 0x82507144;
	sub_821BE710(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f0,3804(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3804);
	f0.f64 = double(temp.f32);
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// sth r11,8(r25)
	PPC_STORE_U16(r25.u32 + 8, r11.u16);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,12(r25)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r25.u32 + 12, temp.u32);
	// bl 0x821be710
	ctx.lr = 0x82507188;
	sub_821BE710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x821be710
	ctx.lr = 0x82507198;
	sub_821BE710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// bl 0x821be710
	ctx.lr = 0x825071A8;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x825071B8;
	sub_821BE710(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r29,r11,16
	r29.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r29,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r29.u16);
	// beq cr6,0x825071e0
	if (cr6.eq) goto loc_825071E0;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x825071D4;
	sub_82130528(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// b 0x825071e4
	goto loc_825071E4;
loc_825071E0:
	// li r24,0
	r24.s64 = 0;
loc_825071E4:
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r30,0
	r30.s64 = 0;
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// stw r24,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r24.u32);
	// sth r29,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r29.u16);
	// subfic r7,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r6,0,29,30
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x6;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// ble cr6,0x82507260
	if (!cr6.gt) goto loc_82507260;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_82507218:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x82507220;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82507230
	if (cr6.eq) goto loc_82507230;
	// bl 0x82519b70
	ctx.lr = 0x8250722C;
	sub_82519B70(ctx, base);
	// b 0x82507234
	goto loc_82507234;
loc_82507230:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82507234:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82526380
	ctx.lr = 0x8250724C;
	sub_82526380(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82507218
	if (cr6.lt) goto loc_82507218;
loc_82507260:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82507408
	if (cr6.eq) goto loc_82507408;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x825095c8
	ctx.lr = 0x82507280;
	sub_825095C8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// bl 0x825095c8
	ctx.lr = 0x82507294;
	sub_825095C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82507408
	if (cr6.eq) goto loc_82507408;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82507408
	if (cr6.eq) goto loc_82507408;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d1d30
	ctx.lr = 0x825072B4;
	sub_821D1D30(ctx, base);
	// li r11,16
	r11.s64 = 16;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r26,1
	r26.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x82507408
	if (!cr6.gt) goto loc_82507408;
	// addi r27,r24,4
	r27.s64 = r24.s64 + 4;
loc_825072D8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82507408
	if (cr6.eq) goto loc_82507408;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82507408
	if (cr6.eq) goto loc_82507408;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x825095c8
	ctx.lr = 0x825072F8;
	sub_825095C8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x825095c8
	ctx.lr = 0x8250730C;
	sub_825095C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825073f4
	if (cr6.eq) goto loc_825073F4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825073f4
	if (cr6.eq) goto loc_825073F4;
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v59,v62,v63
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v58,v62,v63
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v57,v61,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v56,r0,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v55,v61,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// vmrghw128 v54,v57,v59
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v53,v55,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrglw128 v52,v57,v59
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmsum3fp128 v51,v56,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v50,v56,v53
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v49,v56,v52
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmrghw128 v48,v51,v50
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v47,v49,v48
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v46,v48,v47
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vaddfp128 v45,v63,v46
	simde_mm_store_ps(v45.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v46.f32)));
	// stvx128 v45,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821d1d30
	ctx.lr = 0x82507398;
	sub_821D1D30(ctx, base);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821b9e58
	ctx.lr = 0x825073A4;
	sub_821B9E58(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f1,212(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82204cb8
	ctx.lr = 0x825073B0;
	sub_82204CB8(ctx, base);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d1f30
	ctx.lr = 0x825073BC;
	sub_821D1F30(ctx, base);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v44,r0,r6
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r3,r4,24
	ctx.r3.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r3,r3,0,28,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r3,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r3.u8);
	// lvx128 v43,r0,r5
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r30)
	PPC_STORE_U8(r30.u32 + 4, ctx.r10.u8);
loc_825073F4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x825072d8
	if (cr6.lt) goto loc_825072D8;
loc_82507408:
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r5,r11,584
	ctx.r5.s64 = r11.s64 + 584;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82506bc8
	ctx.lr = 0x8250741C;
	sub_82506BC8(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82507468
	if (!cr6.gt) goto loc_82507468;
	// mr r31,r24
	r31.u64 = r24.u64;
loc_82507434:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82507454
	if (cr6.eq) goto loc_82507454;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82507454;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82507454:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82507434
	if (cr6.lt) goto loc_82507434;
loc_82507468:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82130588
	ctx.lr = 0x82507470;
	sub_82130588(ctx, base);
	// lhz r11,8(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82507488
	if (!cr6.eq) goto loc_82507488;
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// sth r10,4(r25)
	PPC_STORE_U16(r25.u32 + 4, ctx.r10.u16);
loc_82507488:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82503880
	ctx.lr = 0x82507490;
	sub_82503880(ctx, base);
	// stw r3,16(r25)
	PPC_STORE_U32(r25.u32 + 16, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_825074A0"))) PPC_WEAK_FUNC(sub_825074A0);
PPC_FUNC_IMPL(__imp__sub_825074A0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x825074A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// addi r5,r11,3664
	ctx.r5.s64 = r11.s64 + 3664;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x825074DC;
	sub_821CA6A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82507504
	if (!cr6.eq) goto loc_82507504;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-32560
	ctx.r3.s64 = r11.s64 + -32560;
	// bl 0x82130000
	ctx.lr = 0x825074F8;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82507504:
	// li r30,0
	r30.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be710
	ctx.lr = 0x8250751C;
	sub_821BE710(ctx, base);
	// lis r11,12617
	r11.s64 = 826867712;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ori r11,r11,20033
	r11.u64 = r11.u64 | 20033;
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// bgt cr6,0x8250767c
	if (cr6.gt) goto loc_8250767C;
	// beq cr6,0x82507578
	if (cr6.eq) goto loc_82507578;
	// lis r11,105
	r11.s64 = 6881280;
	// ori r10,r11,28257
	ctx.r10.u64 = r11.u64 | 28257;
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// beq cr6,0x82507554
	if (cr6.eq) goto loc_82507554;
	// lis r11,112
	r11.s64 = 7340032;
	// ori r10,r11,28003
	ctx.r10.u64 = r11.u64 | 28003;
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// bne cr6,0x8250769c
	if (!cr6.eq) goto loc_8250769C;
loc_82507554:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,-32720
	ctx.r3.s64 = r11.s64 + -32720;
loc_8250755C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x82507564;
	sub_82130000(ctx, base);
loc_82507564:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be610
	ctx.lr = 0x8250756C;
	sub_821BE610(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82507578:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,32552
	ctx.r3.s64 = r11.s64 + 32552;
	// bl 0x82130000
	ctx.lr = 0x82507588;
	sub_82130000(ctx, base);
	// bl 0x821bbea8
	ctx.lr = 0x8250758C;
	sub_821BBEA8(ctx, base);
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x82507594;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825075fc
	if (cr6.eq) goto loc_825075FC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// sth r30,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r30.u16);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// sth r30,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r30.u16);
	// li r9,127
	ctx.r9.s64 = 127;
	// sth r30,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r30.u16);
	// addi r8,r10,32388
	ctx.r8.s64 = ctx.r10.s64 + 32388;
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r30.u32);
	// sth r9,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, ctx.r9.u16);
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r30.u32);
	// sth r30,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r30.u16);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// sth r30,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r30.u16);
	// stw r30,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r30.u32);
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r30.u32);
	// sth r30,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, r30.u16);
	// sth r30,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, r30.u16);
	// stw r30,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r30.u32);
	// stw r7,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r7.u32);
	// b 0x82507600
	goto loc_82507600;
loc_825075FC:
	// mr r31,r30
	r31.u64 = r30.u64;
loc_82507600:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821378b8
	ctx.lr = 0x82507608;
	sub_821378B8(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825070f0
	ctx.lr = 0x8250761C;
	sub_825070F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821bbf00
	ctx.lr = 0x82507624;
	sub_821BBF00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82506140
	ctx.lr = 0x82507630;
	sub_82506140(ctx, base);
	// bl 0x821bbea8
	ctx.lr = 0x82507634;
	sub_821BBEA8(ctx, base);
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
	ctx.lr = 0x8250764C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x821bbf00
	ctx.lr = 0x82507650;
	sub_821BBF00(ctx, base);
	// clrlwi r9,r26,24
	ctx.r9.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82507564
	if (cr6.eq) goto loc_82507564;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,32496
	ctx.r3.s64 = r11.s64 + 32496;
	// bl 0x82130000
	ctx.lr = 0x82507668;
	sub_82130000(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be610
	ctx.lr = 0x82507670;
	sub_821BE610(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_8250767C:
	// lis r11,13641
	r11.s64 = 893976576;
	// ori r10,r11,20033
	ctx.r10.u64 = r11.u64 | 20033;
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// beq cr6,0x82507554
	if (cr6.eq) goto loc_82507554;
	// lis r11,14409
	r11.s64 = 944308224;
	// ori r10,r11,20033
	ctx.r10.u64 = r11.u64 | 20033;
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// beq cr6,0x825076a8
	if (cr6.eq) goto loc_825076A8;
loc_8250769C:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,32392
	ctx.r3.s64 = r11.s64 + 32392;
	// b 0x8250755c
	goto loc_8250755C;
loc_825076A8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821378b8
	ctx.lr = 0x825076B0;
	sub_821378B8(ctx, base);
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// stw r3,28(r27)
	PPC_STORE_U32(r27.u32 + 28, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825076ec
	if (!cr6.eq) goto loc_825076EC;
	// bl 0x821a5cc0
	ctx.lr = 0x825076C4;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825076f0
	if (cr6.eq) goto loc_825076F0;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,28
	ctx.r9.s64 = 28;
	// lwzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// beq cr6,0x825076f0
	if (cr6.eq) goto loc_825076F0;
loc_825076EC:
	// li r30,1
	r30.s64 = 1;
loc_825076F0:
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// clrlwi r6,r30,24
	ctx.r6.u64 = r30.u32 & 0xFF;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82506530
	ctx.lr = 0x82507708;
	sub_82506530(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be610
	ctx.lr = 0x82507714;
	sub_821BE610(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82507720"))) PPC_WEAK_FUNC(sub_82507720);
PPC_FUNC_IMPL(__imp__sub_82507720) {
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
	ctx.lr = 0x82507728;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x82130528
	ctx.lr = 0x82507744;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825077b0
	if (cr6.eq) goto loc_825077B0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,32388
	ctx.r8.s64 = ctx.r9.s64 + 32388;
	// li r7,127
	ctx.r7.s64 = 127;
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// li r6,1
	ctx.r6.s64 = 1;
	// sth r7,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, ctx.r7.u16);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, r11.u16);
	// sth r11,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, r11.u16);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r6,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r6.u32);
	// b 0x825077b4
	goto loc_825077B4;
loc_825077B0:
	// li r31,0
	r31.s64 = 0;
loc_825077B4:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825074a0
	ctx.lr = 0x825077CC;
	sub_825074A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82507814
	if (!cr6.eq) goto loc_82507814;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-32512
	ctx.r3.s64 = r11.s64 + -32512;
	// bl 0x82130000
	ctx.lr = 0x825077E8;
	sub_82130000(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82507808
	if (cr6.eq) goto loc_82507808;
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
	ctx.lr = 0x82507808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82507808:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82507814:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82507820"))) PPC_WEAK_FUNC(sub_82507820);
PPC_FUNC_IMPL(__imp__sub_82507820) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lbz r11,32561(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 32561);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8250784c
	if (!cr6.eq) goto loc_8250784C;
	// bl 0x8253dbd0
	ctx.lr = 0x82507844;
	sub_8253DBD0(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,32561(r31)
	PPC_STORE_U8(r31.u32 + 32561, r11.u8);
loc_8250784C:
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

__attribute__((alias("__imp__sub_82507860"))) PPC_WEAK_FUNC(sub_82507860);
PPC_FUNC_IMPL(__imp__sub_82507860) {
	PPC_FUNC_PROLOGUE();
	// b 0x8253dc78
	sub_8253DC78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82507864"))) PPC_WEAK_FUNC(sub_82507864);
PPC_FUNC_IMPL(__imp__sub_82507864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507868"))) PPC_WEAK_FUNC(sub_82507868);
PPC_FUNC_IMPL(__imp__sub_82507868) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82507870;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x825078b8
	if (!cr6.gt) goto loc_825078B8;
	// li r30,0
	r30.s64 = 0;
loc_82507890:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825078AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82507890
	if (!cr0.eq) goto loc_82507890;
loc_825078B8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_825078C4"))) PPC_WEAK_FUNC(sub_825078C4);
PPC_FUNC_IMPL(__imp__sub_825078C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825078C8"))) PPC_WEAK_FUNC(sub_825078C8);
PPC_FUNC_IMPL(__imp__sub_825078C8) {
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
	ctx.lr = 0x825078D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8250791c
	if (!cr6.gt) goto loc_8250791C;
	// li r30,0
	r30.s64 = 0;
loc_825078F0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82507910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x825078f0
	if (!cr0.eq) goto loc_825078F0;
loc_8250791C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82507924"))) PPC_WEAK_FUNC(sub_82507924);
PPC_FUNC_IMPL(__imp__sub_82507924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507928"))) PPC_WEAK_FUNC(sub_82507928);
PPC_FUNC_IMPL(__imp__sub_82507928) {
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
	ctx.lr = 0x82507930;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8250797c
	if (!cr6.gt) goto loc_8250797C;
	// li r30,0
	r30.s64 = 0;
loc_82507950:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82507970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82507950
	if (!cr0.eq) goto loc_82507950;
loc_8250797C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82507984"))) PPC_WEAK_FUNC(sub_82507984);
PPC_FUNC_IMPL(__imp__sub_82507984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507988"))) PPC_WEAK_FUNC(sub_82507988);
PPC_FUNC_IMPL(__imp__sub_82507988) {
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
	ctx.lr = 0x82507990;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x825079dc
	if (!cr6.gt) goto loc_825079DC;
	// li r30,0
	r30.s64 = 0;
loc_825079B0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825079D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x825079b0
	if (!cr0.eq) goto loc_825079B0;
loc_825079DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_825079E4"))) PPC_WEAK_FUNC(sub_825079E4);
PPC_FUNC_IMPL(__imp__sub_825079E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825079E8"))) PPC_WEAK_FUNC(sub_825079E8);
PPC_FUNC_IMPL(__imp__sub_825079E8) {
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
	ctx.lr = 0x825079F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82507a2c
	if (!cr6.gt) goto loc_82507A2C;
	// li r30,0
	r30.s64 = 0;
loc_82507A08:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82507A20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82507a08
	if (!cr0.eq) goto loc_82507A08;
loc_82507A2C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82507A34"))) PPC_WEAK_FUNC(sub_82507A34);
PPC_FUNC_IMPL(__imp__sub_82507A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507A38"))) PPC_WEAK_FUNC(sub_82507A38);
PPC_FUNC_IMPL(__imp__sub_82507A38) {
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
	ctx.lr = 0x82507A40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x821789d8
	ctx.lr = 0x82507A50;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82507a94
	if (cr6.eq) goto loc_82507A94;
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82507a94
	if (!cr6.gt) goto loc_82507A94;
	// li r30,0
	r30.s64 = 0;
loc_82507A6C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82507A88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82507a6c
	if (!cr0.eq) goto loc_82507A6C;
loc_82507A94:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82507A9C"))) PPC_WEAK_FUNC(sub_82507A9C);
PPC_FUNC_IMPL(__imp__sub_82507A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507AA0"))) PPC_WEAK_FUNC(sub_82507AA0);
PPC_FUNC_IMPL(__imp__sub_82507AA0) {
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
	ctx.lr = 0x82507AA8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x821789d8
	ctx.lr = 0x82507AB4;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82507af4
	if (cr6.eq) goto loc_82507AF4;
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82507af4
	if (!cr6.gt) goto loc_82507AF4;
	// li r30,0
	r30.s64 = 0;
loc_82507AD0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82507AE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82507ad0
	if (!cr0.eq) goto loc_82507AD0;
loc_82507AF4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82507AFC"))) PPC_WEAK_FUNC(sub_82507AFC);
PPC_FUNC_IMPL(__imp__sub_82507AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507B00"))) PPC_WEAK_FUNC(sub_82507B00);
PPC_FUNC_IMPL(__imp__sub_82507B00) {
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
	ctx.lr = 0x82507B08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82507b44
	if (!cr6.gt) goto loc_82507B44;
	// li r30,0
	r30.s64 = 0;
loc_82507B20:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82507B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82507b20
	if (!cr0.eq) goto loc_82507B20;
loc_82507B44:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82507B4C"))) PPC_WEAK_FUNC(sub_82507B4C);
PPC_FUNC_IMPL(__imp__sub_82507B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507B50"))) PPC_WEAK_FUNC(sub_82507B50);
PPC_FUNC_IMPL(__imp__sub_82507B50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82507B80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82507B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// subfc r6,r30,r3
	xer.ca = ctx.r3.u32 >= r30.u32;
	ctx.r6.s64 = ctx.r3.s64 - r30.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r5,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
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

__attribute__((alias("__imp__sub_82507BC0"))) PPC_WEAK_FUNC(sub_82507BC0);
PPC_FUNC_IMPL(__imp__sub_82507BC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// stb r11,17(r3)
	PPC_STORE_U8(ctx.r3.u32 + 17, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82507BE4"))) PPC_WEAK_FUNC(sub_82507BE4);
PPC_FUNC_IMPL(__imp__sub_82507BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507BE8"))) PPC_WEAK_FUNC(sub_82507BE8);
PPC_FUNC_IMPL(__imp__sub_82507BE8) {
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
	ctx.lr = 0x82507BF0;
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82507c48
	if (cr6.eq) goto loc_82507C48;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_82507C10:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82507c34
	if (cr6.eq) goto loc_82507C34;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82507C34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82507C34:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82507c10
	if (cr6.lt) goto loc_82507C10;
loc_82507C48:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82507C50;
	sub_82130588(ctx, base);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// sth r28,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r28.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r28,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r28.u16);
	// beq cr6,0x82507c8c
	if (cr6.eq) goto loc_82507C8C;
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82507c8c
	if (cr6.eq) goto loc_82507C8C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b6018
	ctx.lr = 0x82507C7C;
	sub_821B6018(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82507C84;
	sub_82130588(ctx, base);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// stb r28,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r28.u8);
loc_82507C8C:
	// lbz r11,17(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82507cb0
	if (cr6.eq) goto loc_82507CB0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82507cb0
	if (cr6.eq) goto loc_82507CB0;
	// bl 0x82130588
	ctx.lr = 0x82507CA8;
	sub_82130588(ctx, base);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stb r28,17(r31)
	PPC_STORE_U8(r31.u32 + 17, r28.u8);
loc_82507CB0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82507CB8"))) PPC_WEAK_FUNC(sub_82507CB8);
PPC_FUNC_IMPL(__imp__sub_82507CB8) {
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
	// bl 0x82507be8
	ctx.lr = 0x82507CD0;
	sub_82507BE8(ctx, base);
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82507ce4
	if (cr6.eq) goto loc_82507CE4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82507CE4;
	sub_82130588(ctx, base);
loc_82507CE4:
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

__attribute__((alias("__imp__sub_82507CF8"))) PPC_WEAK_FUNC(sub_82507CF8);
PPC_FUNC_IMPL(__imp__sub_82507CF8) {
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
	ctx.lr = 0x82507D00;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82507d28
	if (cr6.eq) goto loc_82507D28;
	// bl 0x8217d890
	ctx.lr = 0x82507D1C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82507D28:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82507db8
	if (cr6.eq) goto loc_82507DB8;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_82507D48:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82507da0
	if (cr6.eq) goto loc_82507DA0;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82507da0
	if (cr6.eq) goto loc_82507DA0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82507D74;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82507da0
	if (cr6.eq) goto loc_82507DA0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82507D88;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x8253db80
	ctx.lr = 0x82507D9C;
	sub_8253DB80(ctx, base);
	// b 0x82507da4
	goto loc_82507DA4;
loc_82507DA0:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_82507DA4:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82507d48
	if (cr6.lt) goto loc_82507D48;
loc_82507DB8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82507DC4"))) PPC_WEAK_FUNC(sub_82507DC4);
PPC_FUNC_IMPL(__imp__sub_82507DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507DC8"))) PPC_WEAK_FUNC(sub_82507DC8);
PPC_FUNC_IMPL(__imp__sub_82507DC8) {
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
	ctx.lr = 0x82507DD0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82507DE0;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82507e68
	if (!cr6.gt) goto loc_82507E68;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_82507DF8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82507e5c
	if (cr6.eq) goto loc_82507E5C;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82507e58
	if (cr6.eq) goto loc_82507E58;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82507e58
	if (cr6.eq) goto loc_82507E58;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82507E2C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82507e58
	if (cr6.eq) goto loc_82507E58;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82507E40;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x8253db80
	ctx.lr = 0x82507E54;
	sub_8253DB80(ctx, base);
	// b 0x82507e5c
	goto loc_82507E5C;
loc_82507E58:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_82507E5C:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82507df8
	if (!cr0.eq) goto loc_82507DF8;
loc_82507E68:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82507E74"))) PPC_WEAK_FUNC(sub_82507E74);
PPC_FUNC_IMPL(__imp__sub_82507E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507E78"))) PPC_WEAK_FUNC(sub_82507E78);
PPC_FUNC_IMPL(__imp__sub_82507E78) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82507ef4
	if (!cr6.eq) goto loc_82507EF4;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x82507dc8
	ctx.lr = 0x82507EB0;
	sub_82507DC8(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82507ee8
	if (cr6.eq) goto loc_82507EE8;
	// li r11,0
	r11.s64 = 0;
loc_82507EC4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stwx r7,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, ctx.r7.u32);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// blt cr6,0x82507ec4
	if (cr6.lt) goto loc_82507EC4;
loc_82507EE8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82507EF0;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_82507EF4:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
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

__attribute__((alias("__imp__sub_82507F24"))) PPC_WEAK_FUNC(sub_82507F24);
PPC_FUNC_IMPL(__imp__sub_82507F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82507F28"))) PPC_WEAK_FUNC(sub_82507F28);
PPC_FUNC_IMPL(__imp__sub_82507F28) {
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
	ctx.lr = 0x82507F30;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82507f80
	if (cr6.eq) goto loc_82507F80;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82507cf8
	ctx.lr = 0x82507F4C;
	sub_82507CF8(ctx, base);
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b5a60
	ctx.lr = 0x82507F58;
	sub_821B5A60(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821b5a60
	ctx.lr = 0x82507F60;
	sub_821B5A60(ctx, base);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82507f80
	if (cr6.eq) goto loc_82507F80;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82507f80
	if (cr6.eq) goto loc_82507F80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821b5f20
	ctx.lr = 0x82507F80;
	sub_821B5F20(ctx, base);
loc_82507F80:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82507F88"))) PPC_WEAK_FUNC(sub_82507F88);
PPC_FUNC_IMPL(__imp__sub_82507F88) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82507e78
	ctx.lr = 0x82507FAC;
	sub_82507E78(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lis r11,-32176
	r11.s64 = -2108686336;
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r11,31568
	ctx.r6.s64 = r11.s64 + 31568;
	// bl 0x823dcf08
	ctx.lr = 0x82507FC8;
	sub_823DCF08(ctx, base);
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

__attribute__((alias("__imp__sub_82507FE0"))) PPC_WEAK_FUNC(sub_82507FE0);
PPC_FUNC_IMPL(__imp__sub_82507FE0) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82507FE8;
	// addi r31,r1,-192
	r31.s64 = ctx.r1.s64 + -192;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r20,r9
	r20.u64 = ctx.r9.u64;
	// mr r21,r10
	r21.u64 = ctx.r10.u64;
	// bl 0x82507dc8
	ctx.lr = 0x82508018;
	sub_82507DC8(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// sth r11,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r11.u16);
	// lwz r29,12(r23)
	r29.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x825081ac
	if (cr6.eq) goto loc_825081AC;
	// li r25,1
	r25.s64 = 1;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8250804c
	if (cr6.eq) goto loc_8250804C;
	// li r11,0
	r11.s64 = 0;
	// stw r28,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r28.u32);
	// stb r11,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r11.u8);
	// b 0x82508084
	goto loc_82508084;
loc_8250804C:
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x82508054;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82508064
	if (cr6.eq) goto loc_82508064;
	// bl 0x821b5e08
	ctx.lr = 0x82508060;
	sub_821B5E08(ctx, base);
	// b 0x82508068
	goto loc_82508068;
loc_82508064:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82508068:
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821b5c60
	ctx.lr = 0x82508080;
	sub_821B5C60(ctx, base);
	// stb r25,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r25.u8);
loc_82508084:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8250815c
	if (cr6.eq) goto loc_8250815C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x825080a0
	if (cr6.eq) goto loc_825080A0;
	// stw r27,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r27.u32);
	// b 0x8250812c
	goto loc_8250812C;
loc_825080A0:
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x825080A8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825080f8
	if (cr6.eq) goto loc_825080F8;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r11,-31280
	ctx.r9.s64 = r11.s64 + -31280;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,48
	ctx.r5.s64 = 48;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lvx128 v63,r9,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x825080fc
	goto loc_825080FC;
loc_825080F8:
	// li r11,0
	r11.s64 = 0;
loc_825080FC:
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r25,17(r30)
	PPC_STORE_U8(r30.u32 + 17, r25.u8);
	// bne cr6,0x82508120
	if (!cr6.eq) goto loc_82508120;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8250812c
	if (!cr6.eq) goto loc_8250812C;
loc_82508120:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8250812C:
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x82508134;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82508150
	if (cr6.eq) goto loc_82508150;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x825403b0
	ctx.lr = 0x82508148;
	sub_825403B0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82508154
	goto loc_82508154;
loc_82508150:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82508154:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82507f88
	ctx.lr = 0x8250815C;
	sub_82507F88(ctx, base);
loc_8250815C:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x82508164;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82508180
	if (cr6.eq) goto loc_82508180;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x8253fd28
	ctx.lr = 0x82508178;
	sub_8253FD28(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x82508184
	goto loc_82508184;
loc_82508180:
	// li r29,0
	r29.s64 = 0;
loc_82508184:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82507e78
	ctx.lr = 0x82508190;
	sub_82507E78(ctx, base);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// lis r11,-32176
	r11.s64 = -2108686336;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,4
	ctx.r5.s64 = 4;
	// lhz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r6,r11,31568
	ctx.r6.s64 = r11.s64 + 31568;
	// bl 0x823dcf08
	ctx.lr = 0x825081AC;
	sub_823DCF08(ctx, base);
loc_825081AC:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x825081f8
	if (cr6.eq) goto loc_825081F8;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82613f08
	ctx.lr = 0x825081BC;
	sub_82613F08(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825081f8
	if (cr6.eq) goto loc_825081F8;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x825081CC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825081ec
	if (cr6.eq) goto loc_825081EC;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8253f7e0
	ctx.lr = 0x825081E4;
	sub_8253F7E0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x825081f0
	goto loc_825081F0;
loc_825081EC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_825081F0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82507f88
	ctx.lr = 0x825081F8;
	sub_82507F88(ctx, base);
loc_825081F8:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x825083fc
	if (cr6.eq) goto loc_825083FC;
	// addi r11,r20,3
	r11.s64 = r20.s64 + 3;
	// lwz r22,8(r23)
	r22.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r24,r11,30,2,31
	r24.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x825083fc
	if (cr6.eq) goto loc_825083FC;
	// mr r28,r21
	r28.u64 = r21.u64;
loc_82508220:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82508258
	if (!cr6.eq) goto loc_82508258;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82508240
	if (cr6.eq) goto loc_82508240;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82193af8
	ctx.lr = 0x82508240;
	sub_82193AF8(ctx, base);
loc_82508240:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r29,r24
	cr6.compare<uint32_t>(r29.u32, r24.u32, xer);
	// blt cr6,0x82508220
	if (cr6.lt) goto loc_82508220;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x825083fc
	if (cr6.eq) goto loc_825083FC;
loc_82508258:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x82508260;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8250827c
	if (cr6.eq) goto loc_8250827C;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8253e990
	ctx.lr = 0x82508274;
	sub_8253E990(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82508280
	goto loc_82508280;
loc_8250827C:
	// li r23,0
	r23.s64 = 0;
loc_82508280:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82507e78
	ctx.lr = 0x8250828C;
	sub_82507E78(ctx, base);
	// stw r23,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r23.u32);
	// lis r11,-32176
	r11.s64 = -2108686336;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,4
	ctx.r5.s64 = 4;
	// lhz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r6,r11,31568
	ctx.r6.s64 = r11.s64 + 31568;
	// bl 0x823dcf08
	ctx.lr = 0x825082A8;
	sub_823DCF08(ctx, base);
	// lwz r29,276(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8250839c
	if (cr6.eq) goto loc_8250839C;
	// neg r11,r20
	r11.s64 = -r20.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x825082C0;
	sub_823DBFF4(ctx, base);
	// lwz r10,0(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// rlwinm r9,r20,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 1) & 0xFFFFFFFE;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stwux r10,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x825082DC;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r25,r1,80
	r25.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x82508320
	if (cr6.eq) goto loc_82508320;
	// mr r28,r25
	r28.u64 = r25.u64;
	// li r26,23
	r26.s64 = 23;
loc_825082FC:
	// stbx r26,r30,r27
	PPC_STORE_U8(r30.u32 + r27.u32, r26.u8);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8253b2c0
	ctx.lr = 0x82508308;
	sub_8253B2C0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// sth r3,0(r28)
	PPC_STORE_U16(r28.u32 + 0, ctx.r3.u16);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// cmplw cr6,r30,r20
	cr6.compare<uint32_t>(r30.u32, r20.u32, xer);
	// blt cr6,0x825082fc
	if (cr6.lt) goto loc_825082FC;
loc_82508320:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x825083fc
	if (cr6.eq) goto loc_825083FC;
	// subf r26,r21,r27
	r26.s64 = r27.s64 - r21.s64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r25
	r29.u64 = r25.u64;
	// mr r30,r21
	r30.u64 = r21.u64;
	// mr r27,r24
	r27.u64 = r24.u64;
loc_8250833C:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82508380
	if (cr6.eq) goto loc_82508380;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82193af8
	ctx.lr = 0x82508354;
	sub_82193AF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82508380
	if (cr6.eq) goto loc_82508380;
	// subf r5,r28,r20
	ctx.r5.s64 = r20.s64 - r28.s64;
	// cmplwi cr6,r5,4
	cr6.compare<uint32_t>(ctx.r5.u32, 4, xer);
	// blt cr6,0x82508370
	if (cr6.lt) goto loc_82508370;
	// li r5,4
	ctx.r5.s64 = 4;
loc_82508370:
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// add r6,r26,r30
	ctx.r6.u64 = r26.u64 + r30.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8253ec38
	ctx.lr = 0x82508380;
	sub_8253EC38(ctx, base);
loc_82508380:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8250833c
	if (!cr0.eq) goto loc_8250833C;
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d9228
	return;
loc_8250839C:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x825083fc
	if (cr6.eq) goto loc_825083FC;
	// li r30,0
	r30.s64 = 0;
loc_825083A8:
	// lwzx r4,r30,r21
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + r21.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825083f0
	if (cr6.eq) goto loc_825083F0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82193af8
	ctx.lr = 0x825083C0;
	sub_82193AF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x825083f0
	if (cr6.eq) goto loc_825083F0;
	// subf r11,r30,r20
	r11.s64 = r20.s64 - r30.s64;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// blt cr6,0x825083dc
	if (cr6.lt) goto loc_825083DC;
	// li r11,4
	r11.s64 = 4;
loc_825083DC:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,23
	ctx.r6.s64 = 23;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8253ebe8
	ctx.lr = 0x825083F0;
	sub_8253EBE8(ctx, base);
loc_825083F0:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x825083a8
	if (!cr0.eq) goto loc_825083A8;
loc_825083FC:
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82508404"))) PPC_WEAK_FUNC(sub_82508404);
PPC_FUNC_IMPL(__imp__sub_82508404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

